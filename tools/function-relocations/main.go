// Command function-relocations checks, function by function, what the code
// section of a function in its unit's object refers to. For each function of
// a table it finds the COMDAT code section that defines the function's name in
// the object compiled from the function's unit, and fails when that section
// has a relocation to a forbidden name or none to a required name.
package main

import (
	"bytes"
	"debug/pe"
	"flag"
	"fmt"
	"io"
	"os"
	"strings"
)

func main() {
	os.Exit(run(os.Args[1:], os.Stdout, os.Stderr))
}

// function is one table row: a function, the unit whose object defines it,
// and the names its section must refer to.
type function struct {
	batch, unit, name string
	requires          []string
}

type table struct {
	forbids   []string
	functions []function
}

// readTable reads the tab-separated table. Blank lines and lines that start
// with '#' are skipped. The other lines are one of:
//
//	forbid<TAB>NAME
//	function<TAB>BATCH<TAB>UNIT<TAB>NAME<TAB>REQUIRED NAME[ REQUIRED NAME...]
//
// A REQUIRED field of "-" requires no name.
func readTable(text string) (table, error) {
	var t table
	for i, line := range strings.Split(text, "\n") {
		if line == "" || strings.HasPrefix(line, "#") {
			continue
		}
		f := strings.Split(line, "\t")
		switch {
		case f[0] == "forbid" && len(f) == 2 && f[1] != "":
			t.forbids = append(t.forbids, f[1])
		case f[0] == "function" && len(f) == 5 && f[1] != "" && f[2] != "" && f[3] != "" && f[4] != "":
			requires := strings.Fields(f[4])
			if f[4] == "-" {
				requires = nil
			}
			t.functions = append(t.functions, function{f[1], f[2], f[3], requires})
		default:
			return table{}, fmt.Errorf("table line %d is malformed", i+1)
		}
	}
	if len(t.forbids) == 0 || len(t.functions) == 0 {
		return table{}, fmt.Errorf("the table has no forbid line or no function line")
	}
	return t, nil
}

// objectFor returns the one object path that ends in "/UNIT.obj".
func objectFor(objects []string, unit string) (string, error) {
	var found []string
	for _, o := range objects {
		if strings.HasSuffix(o, "/"+unit+".obj") {
			found = append(found, o)
		}
	}
	if len(found) != 1 {
		return "", fmt.Errorf("%d objects of %s, not 1", len(found), unit)
	}
	return found[0], nil
}

// targets counts the relocation targets, by name, of the COMDAT code section
// that defines name in the object.
func targets(object []byte, name string) (map[string]int, error) {
	f, err := pe.NewFile(bytes.NewReader(object))
	if err != nil {
		return nil, err
	}
	defer f.Close()
	if f.Machine != pe.IMAGE_FILE_MACHINE_AMD64 {
		return nil, fmt.Errorf("not an x64 COFF object")
	}
	symbolName := func(i uint32) (string, error) {
		if int(i) >= len(f.COFFSymbols) {
			return "", fmt.Errorf("a relocation names symbol %d of %d", i, len(f.COFFSymbols))
		}
		return f.COFFSymbols[i].FullName(f.StringTable)
	}
	section := 0
	for i := 0; i < len(f.COFFSymbols); i += 1 + int(f.COFFSymbols[i].NumberOfAuxSymbols) {
		s := f.COFFSymbols[i]
		n, err := s.FullName(f.StringTable)
		if err != nil {
			return nil, err
		}
		if n != name || s.SectionNumber <= 0 {
			continue
		}
		if section != 0 {
			return nil, fmt.Errorf("%s is defined more than once", name)
		}
		section = int(s.SectionNumber)
	}
	if section == 0 || section > len(f.Sections) {
		return nil, fmt.Errorf("%s is not defined", name)
	}
	s := f.Sections[section-1]
	const overflow = 0x01000000 // IMAGE_SCN_LNK_NRELOC_OVFL
	if s.Characteristics&pe.IMAGE_SCN_CNT_CODE == 0 || s.Characteristics&pe.IMAGE_SCN_LNK_COMDAT == 0 {
		return nil, fmt.Errorf("%s is not in a COMDAT code section", name)
	}
	if s.Characteristics&overflow != 0 {
		return nil, fmt.Errorf("the section of %s has more relocations than this command reads", name)
	}
	count := map[string]int{}
	for _, r := range s.Relocs {
		n, err := symbolName(r.SymbolTableIndex)
		if err != nil {
			return nil, err
		}
		count[n]++
	}
	return count, nil
}

// Exit 0: every function of the batch passes. Exit 1: one does not. Exit 2:
// the check could not be completed.
func run(args []string, out, errOut io.Writer) int {
	flags := flag.NewFlagSet("function-relocations", flag.ContinueOnError)
	flags.SetOutput(io.Discard)
	tablePath := flags.String("table", "", "the table of functions")
	objectsPath := flags.String("objects", "", "a file with one object path per line")
	batch := flags.String("batch", "", "check only the functions of this batch")
	if err := flags.Parse(args); err != nil || *tablePath == "" || *objectsPath == "" || flags.NArg() != 0 {
		fmt.Fprintln(errOut, "usage: function-relocations --table FILE --objects FILE [--batch NAME]")
		return 2
	}
	incomplete := func(err error) int {
		fmt.Fprintln(errOut, "function-relocations: incomplete:", err)
		return 2
	}
	text, err := os.ReadFile(*tablePath)
	if err != nil {
		return incomplete(err)
	}
	t, err := readTable(string(text))
	if err != nil {
		return incomplete(err)
	}
	list, err := os.ReadFile(*objectsPath)
	if err != nil {
		return incomplete(err)
	}
	var objects []string
	for _, line := range strings.Split(string(list), "\n") {
		if line = strings.TrimSuffix(line, "\r"); line != "" {
			objects = append(objects, line)
		}
	}

	checked, failed := 0, 0
	for _, fn := range t.functions {
		if *batch != "" && fn.batch != *batch {
			continue
		}
		path, err := objectFor(objects, fn.unit)
		if err != nil {
			return incomplete(err)
		}
		object, err := os.ReadFile(path)
		if err != nil {
			return incomplete(err)
		}
		count, err := targets(object, fn.name)
		if err != nil {
			return incomplete(fmt.Errorf("%s: %w", fn.unit, err))
		}
		var problems []string
		for _, n := range t.forbids {
			if count[n] > 0 {
				problems = append(problems, fmt.Sprintf("%d relocations to %s", count[n], n))
			}
		}
		for _, n := range fn.requires {
			if count[n] == 0 {
				problems = append(problems, "no relocation to "+n)
			}
		}
		checked++
		if len(problems) > 0 {
			failed++
			fmt.Fprintf(out, "FAIL\t%s\t%s\t%s\n", fn.batch, fn.name, strings.Join(problems, "; "))
		} else {
			fmt.Fprintf(out, "ok\t%s\t%s\n", fn.batch, fn.name)
		}
	}
	if checked == 0 {
		return incomplete(fmt.Errorf("no function of batch %q in the table", *batch))
	}
	if failed > 0 {
		return 1
	}
	return 0
}
