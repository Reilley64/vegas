// Command function-relocations checks, function by function, what the code
// section of a function in its unit's object refers to. For each function of
// a table it finds the COMDAT code section that defines the function's name in
// the object compiled from the function's unit, and fails when that section
// has a relocation to a forbidden name, none to a required name, or one that
// addresses a name at or past the length the table gives it.
package main

import (
	"bytes"
	"debug/pe"
	"encoding/binary"
	"flag"
	"fmt"
	"io"
	"os"
	"strconv"
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

// past is a name and its length in bytes: no relocation of a function may
// address the name at or past that length.
type past struct {
	name   string
	length int64
}

type table struct {
	forbids   []string
	pasts     []past
	functions []function
}

// readTable reads the tab-separated table. Blank lines and lines that start
// with '#' are skipped. The other lines are one of:
//
//	forbid<TAB>NAME
//	past<TAB>NAME<TAB>LENGTH
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
		case f[0] == "past" && len(f) == 3 && f[1] != "":
			n, err := strconv.ParseInt(f[2], 10, 64)
			if err != nil || n <= 0 {
				return table{}, fmt.Errorf("table line %d has no positive length", i+1)
			}
			t.pasts = append(t.pasts, past{f[1], n})
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
	if len(t.forbids)+len(t.pasts) == 0 || len(t.functions) == 0 {
		return table{}, fmt.Errorf("the table has no forbid or past line, or no function line")
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

// reference is one relocation of a function's code section: the name it
// refers to, its type and, when read is set, the addend stored at its offset
// in the code.
type reference struct {
	name   string
	kind   uint16
	addend int64
	read   bool
}

// Relocation types of x64 COFF objects whose addend this command reads.
const (
	relAddr64   = 1 // IMAGE_REL_AMD64_ADDR64, 8-byte addend
	relAddr32   = 2 // IMAGE_REL_AMD64_ADDR32
	relAddr32NB = 3 // IMAGE_REL_AMD64_ADDR32NB
	relRel32    = 4 // IMAGE_REL_AMD64_REL32; REL32_1 to REL32_5 are 5 to 9
	relRel32_5  = 9
)

// reaches reports whether r may address its name at or past length bytes, or
// before it. For the REL32 types the stored addend excludes the bytes of an
// immediate that follows the displacement in the instruction, up to 4, so the
// address used lies between the addend and the addend plus 4. The check takes
// the larger one as the highest offset, and fails before the name only when
// even the larger one is negative: offset 0 followed by an immediate is stored
// as a negative addend.
func reaches(r reference, length int64) bool {
	high := r.addend
	if r.kind >= relRel32 && r.kind <= relRel32_5 {
		high += 4
	}
	return high < 0 || high >= length
}

// targets lists the relocations of the COMDAT code section that defines name
// in the object.
func targets(object []byte, name string) ([]reference, error) {
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
	code, err := s.Data()
	if err != nil {
		return nil, err
	}
	var refs []reference
	for _, r := range s.Relocs {
		n, err := symbolName(r.SymbolTableIndex)
		if err != nil {
			return nil, err
		}
		size := 4
		switch {
		case r.Type == relAddr64:
			size = 8
		case r.Type == relAddr32 || r.Type == relAddr32NB || (r.Type >= relRel32 && r.Type <= relRel32_5):
		default:
			size = 0
		}
		ref := reference{name: n, kind: r.Type, read: size > 0}
		if ref.read {
			at := int(r.VirtualAddress)
			if at < 0 || at+size > len(code) {
				return nil, fmt.Errorf("a relocation of %s lies outside its section", name)
			}
			if size == 8 {
				ref.addend = int64(binary.LittleEndian.Uint64(code[at:]))
			} else {
				ref.addend = int64(int32(binary.LittleEndian.Uint32(code[at:])))
			}
		}
		refs = append(refs, ref)
	}
	return refs, nil
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
		refs, err := targets(object, fn.name)
		if err != nil {
			return incomplete(fmt.Errorf("%s: %w", fn.unit, err))
		}
		count := map[string]int{}
		for _, r := range refs {
			count[r.name]++
		}
		var problems []string
		for _, n := range t.forbids {
			if count[n] > 0 {
				problems = append(problems, fmt.Sprintf("%d relocations to %s", count[n], n))
			}
		}
		for _, p := range t.pasts {
			for _, r := range refs {
				if r.name != p.name {
					continue
				}
				if !r.read {
					return incomplete(fmt.Errorf("%s: relocation type %d to %s is not read", fn.unit, r.kind, p.name))
				}
				if reaches(r, p.length) {
					problems = append(problems, fmt.Sprintf("a relocation to %s with addend %d reaches past its %d bytes", p.name, r.addend, p.length))
				}
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
