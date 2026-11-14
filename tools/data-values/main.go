// Command data-values checks named data in the objects of their units. For
// each row of a table it finds the one external symbol that defines the name
// in the object compiled from the row's unit. A value row fails when that
// symbol lies in a section without initialised contents, when its bytes
// differ from the row's, or when a relocation of the section patches one of
// them. An extent row fails when the symbol reaches fewer bytes than the
// row's before the next symbol of its section or the section's end.
package main

import (
	"bytes"
	"debug/pe"
	"encoding/hex"
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

// value is one table row: a unit, a name its object defines, and either the
// bytes the name must start with or, for an extent row, the number of bytes
// it must reach.
type value struct {
	unit, name string
	bytes      []byte
	extent     uint64
}

// readTable reads the tab-separated table. Blank lines and lines that start
// with '#' are skipped. The other lines are
//
//	value<TAB>UNIT<TAB>NAME<TAB>HEX
//	extent<TAB>UNIT<TAB>NAME<TAB>BYTES
//
// where HEX is the expected bytes in file order, two hex digits each, and
// BYTES is a decimal count above zero. A line may end in CRLF, as a Windows
// checkout writes it.
func readTable(text string) ([]value, error) {
	var values []value
	for i, line := range strings.Split(text, "\n") {
		line = strings.TrimSuffix(line, "\r")
		if line == "" || strings.HasPrefix(line, "#") {
			continue
		}
		f := strings.Split(line, "\t")
		if len(f) != 4 || (f[0] != "value" && f[0] != "extent") || f[1] == "" || f[2] == "" {
			return nil, fmt.Errorf("table line %d is malformed", i+1)
		}
		if f[0] == "extent" {
			n, err := strconv.ParseUint(f[3], 10, 32)
			if err != nil || n == 0 {
				return nil, fmt.Errorf("table line %d has no byte count", i+1)
			}
			values = append(values, value{unit: f[1], name: f[2], extent: n})
			continue
		}
		b, err := hex.DecodeString(f[3])
		if err != nil || len(b) == 0 {
			return nil, fmt.Errorf("table line %d has no bytes", i+1)
		}
		values = append(values, value{unit: f[1], name: f[2], bytes: b})
	}
	if len(values) == 0 {
		return nil, fmt.Errorf("the table has no value or extent line")
	}
	return values, nil
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

// problems compares the definition of v.name in the object with v.bytes, or
// with v.extent for an extent row. It returns the reasons the definition
// fails, or an error when the object cannot be read or does not define the
// name exactly once.
func problems(object []byte, v value) ([]string, error) {
	f, err := pe.NewFile(bytes.NewReader(object))
	if err != nil {
		return nil, err
	}
	defer f.Close()
	if f.Machine != pe.IMAGE_FILE_MACHINE_AMD64 {
		return nil, fmt.Errorf("not an x64 COFF object")
	}
	const external = 2 // IMAGE_SYM_CLASS_EXTERNAL
	section, offset := 0, uint32(0)
	for i := 0; i < len(f.COFFSymbols); i += 1 + int(f.COFFSymbols[i].NumberOfAuxSymbols) {
		s := f.COFFSymbols[i]
		n, err := s.FullName(f.StringTable)
		if err != nil {
			return nil, err
		}
		if n != v.name || s.SectionNumber <= 0 || s.StorageClass != external {
			continue
		}
		if section != 0 {
			return nil, fmt.Errorf("%s is defined more than once", v.name)
		}
		section, offset = int(s.SectionNumber), s.Value
	}
	if section == 0 || section > len(f.Sections) {
		return nil, fmt.Errorf("%s is not defined", v.name)
	}
	s := f.Sections[section-1]
	if v.extent > 0 {
		return extentProblems(f, section, offset, v)
	}
	const initialised, uninitialised = pe.IMAGE_SCN_CNT_INITIALIZED_DATA, pe.IMAGE_SCN_CNT_UNINITIALIZED_DATA
	if s.Characteristics&initialised == 0 || s.Characteristics&uninitialised != 0 {
		return []string{fmt.Sprintf("in section %s, which has no initialised contents, so the value is zero", s.Name)}, nil
	}
	data, err := s.Data()
	if err != nil {
		return nil, err
	}
	end := uint64(offset) + uint64(len(v.bytes))
	if end > uint64(len(data)) {
		return nil, fmt.Errorf("%s: %d bytes at offset %d lie outside section %s of %d bytes", v.name, len(v.bytes), offset, s.Name, len(data))
	}
	var found []string
	if got := data[offset:end]; !bytes.Equal(got, v.bytes) {
		found = append(found, fmt.Sprintf("bytes %x, not %x", got, v.bytes))
	}
	const overflow = 0x01000000 // IMAGE_SCN_LNK_NRELOC_OVFL
	if s.Characteristics&overflow != 0 {
		return nil, fmt.Errorf("section %s of %s has more relocations than this command reads", s.Name, v.name)
	}
	for _, r := range s.Relocs {
		// No relocation is wider than 8 bytes.
		if uint64(r.VirtualAddress)+8 > uint64(offset) && uint64(r.VirtualAddress) < end {
			found = append(found, fmt.Sprintf("a relocation at section offset %d may patch its bytes", r.VirtualAddress))
		}
	}
	return found, nil
}

// extentProblems measures how far the definition at offset in section
// reaches: to the nearest symbol of the section that lies further on, or to
// the section's end. A COFF symbol has no size, so this distance is the most
// the definition can occupy; padding before the next symbol counts in it.
func extentProblems(f *pe.File, section int, offset uint32, v value) ([]string, error) {
	s := f.Sections[section-1]
	end := uint64(s.Size)
	if uint64(offset) > end {
		return nil, fmt.Errorf("%s: offset %d lies outside section %s of %d bytes", v.name, offset, s.Name, end)
	}
	for i := 0; i < len(f.COFFSymbols); i += 1 + int(f.COFFSymbols[i].NumberOfAuxSymbols) {
		o := f.COFFSymbols[i]
		if int(o.SectionNumber) == section && o.Value > offset && uint64(o.Value) < end {
			end = uint64(o.Value)
		}
	}
	if reach := end - uint64(offset); reach < v.extent {
		return []string{fmt.Sprintf("reaches %d bytes in section %s, not %d", reach, s.Name, v.extent)}, nil
	}
	return nil, nil
}

// Exit 0: every row passes. Exit 1: one does not. Exit 2: the check could
// not be completed.
func run(args []string, out, errOut io.Writer) int {
	flags := flag.NewFlagSet("data-values", flag.ContinueOnError)
	flags.SetOutput(io.Discard)
	tablePath := flags.String("table", "", "the table of values")
	objectsPath := flags.String("objects", "", "a file with one object path per line")
	if err := flags.Parse(args); err != nil || *tablePath == "" || *objectsPath == "" || flags.NArg() != 0 {
		fmt.Fprintln(errOut, "usage: data-values --table FILE --objects FILE")
		return 2
	}
	incomplete := func(err error) int {
		fmt.Fprintln(errOut, "data-values: incomplete:", err)
		return 2
	}
	text, err := os.ReadFile(*tablePath)
	if err != nil {
		return incomplete(err)
	}
	values, err := readTable(string(text))
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

	failed := 0
	for _, v := range values {
		path, err := objectFor(objects, v.unit)
		if err != nil {
			return incomplete(err)
		}
		object, err := os.ReadFile(path)
		if err != nil {
			return incomplete(err)
		}
		found, err := problems(object, v)
		if err != nil {
			return incomplete(fmt.Errorf("%s: %w", v.unit, err))
		}
		if len(found) > 0 {
			failed++
			fmt.Fprintf(out, "FAIL\t%s\t%s\t%s\n", v.unit, v.name, strings.Join(found, "; "))
		} else {
			fmt.Fprintf(out, "ok\t%s\t%s\n", v.unit, v.name)
		}
	}
	if failed > 0 {
		return 1
	}
	return 0
}
