// Command table-bounds checks that no relocation of any object addresses a
// generated table at or past its end, or before its start (VEGAS-30). The
// tables are the arrays that the generated vtable units define; each one's
// length is its slot count in the source the build compiles. An allow file
// lists the reads that are known and still open, by the symbol that holds the
// relocation and the table.
package main

import (
	"bufio"
	"bytes"
	"debug/pe"
	"encoding/binary"
	"flag"
	"fmt"
	"io"
	"os"
	"path/filepath"
	"regexp"
	"sort"
	"strings"
)

func main() {
	os.Exit(run(os.Args[1:], os.Stdout, os.Stderr))
}

var (
	labelLine = regexp.MustCompile(`^extern void\* (\w+)\[\](?: __asm__\("([^"]+)"\))?;$`)
	tableLine = regexp.MustCompile(`^void\* (\w+)\[\] = \{$`)
)

// readTables returns each table's symbol name and length in bytes. sources
// are the generated vtable units the build compiles. Each unit's symbol names
// come from the vtables.h beside it, which it includes: a C name declared
// with an asm label is defined under the label, one without under its C name.
func readTables(sources []string) (map[string]int64, error) {
	lengths := map[string]int64{}
	headers := map[string]map[string]string{}
	for _, source := range sources {
		dir := filepath.Dir(source)
		labels, ok := headers[dir]
		if !ok {
			text, err := os.ReadFile(filepath.Join(dir, "vtables.h"))
			if err != nil {
				return nil, err
			}
			labels = map[string]string{}
			for _, line := range strings.Split(string(text), "\n") {
				if m := labelLine.FindStringSubmatch(line); m != nil {
					labels[m[1]] = m[2]
					if m[2] == "" {
						labels[m[1]] = m[1]
					}
				}
			}
			headers[dir] = labels
		}
		text, err := os.ReadFile(source)
		if err != nil {
			return nil, err
		}
		name, slots := "", int64(0)
		for i, line := range strings.Split(string(text), "\n") {
			switch {
			case name == "":
				m := tableLine.FindStringSubmatch(line)
				if m == nil {
					continue
				}
				if name = labels[m[1]]; name == "" {
					return nil, fmt.Errorf("%s:%d: table %s has no declaration in vtables.h", source, i+1, m[1])
				}
				slots = 0
			case line == "};":
				if slots == 0 {
					return nil, fmt.Errorf("%s:%d: table %s has no slot", source, i+1, name)
				}
				if _, dup := lengths[name]; dup {
					return nil, fmt.Errorf("%s: table %s is defined twice", source, name)
				}
				lengths[name] = 8 * slots
				name = ""
			case strings.TrimSpace(line) != "" && !strings.HasPrefix(strings.TrimSpace(line), "//"):
				slots++
			}
		}
		if name != "" {
			return nil, fmt.Errorf("%s: table %s does not end", source, name)
		}
	}
	if len(lengths) == 0 {
		return nil, fmt.Errorf("the sources define no table")
	}
	return lengths, nil
}

// allowed is one known read past a table: the symbol whose section holds the
// relocation, and the table.
type allowed struct{ holder, table string }

// readAllow reads lines of allow<TAB>HOLDER<TAB>TABLE. Blank lines and lines
// that start with '#' are skipped.
func readAllow(text string) (map[allowed]bool, error) {
	allow := map[allowed]bool{}
	for i, line := range strings.Split(text, "\n") {
		line = strings.TrimSuffix(line, "\r")
		if line == "" || strings.HasPrefix(line, "#") {
			continue
		}
		f := strings.Split(line, "\t")
		if len(f) != 3 || f[0] != "allow" || f[1] == "" || f[2] == "" {
			return nil, fmt.Errorf("allow line %d is malformed", i+1)
		}
		allow[allowed{f[1], f[2]}] = true
	}
	return allow, nil
}

// Relocation types of x64 COFF objects whose addend this command reads.
const (
	relAddr64   = 1 // IMAGE_REL_AMD64_ADDR64, 8-byte addend
	relAddr32   = 2 // IMAGE_REL_AMD64_ADDR32
	relAddr32NB = 3 // IMAGE_REL_AMD64_ADDR32NB
	relRel32    = 4 // IMAGE_REL_AMD64_REL32; REL32_1 to REL32_5 are 5 to 9
	relRel32_5  = 9
)

// outside reports whether a relocation of type kind with the stored addend
// may address a table of length bytes at or past its end, or before it. For
// the REL32 types the stored addend leaves out the bytes of an immediate that
// follows the displacement, up to 4, so the address used lies between the
// addend and the addend plus 4; the check takes the addend plus 4.
func outside(kind uint16, addend, length int64) bool {
	high := addend
	if kind >= relRel32 && kind <= relRel32_5 {
		high += 4
	}
	return high < 0 || high >= length
}

// finding is one relocation to a table that may lie outside it.
type finding struct {
	object, holder, table string
	addend, length        int64
}

// scan reads one object. It returns the relocations to tables that may lie
// outside them, and counts each table's definitions in defined and the
// relocations to tables in refs. A definition must leave room for the
// table's length before the next symbol of its section or the section's end.
func scan(path string, data []byte, lengths map[string]int64, defined map[string]int, refs *int) ([]finding, error) {
	f, err := pe.NewFile(bytes.NewReader(data))
	if err != nil {
		return nil, err
	}
	defer f.Close()
	if f.Machine != pe.IMAGE_FILE_MACHINE_AMD64 {
		return nil, fmt.Errorf("not an x64 COFF object")
	}
	type symbol struct {
		name    string
		value   uint32
		section int
		class   uint8
	}
	// Every symbol table index, with aux records left empty, so that a
	// relocation's index finds its symbol.
	symbols := make([]symbol, len(f.COFFSymbols))
	bySection := map[int][]symbol{}
	for i := 0; i < len(f.COFFSymbols); i += 1 + int(f.COFFSymbols[i].NumberOfAuxSymbols) {
		s := f.COFFSymbols[i]
		n, err := s.FullName(f.StringTable)
		if err != nil {
			return nil, err
		}
		symbols[i] = symbol{n, s.Value, int(s.SectionNumber), s.StorageClass}
		if s.SectionNumber <= 0 || int(s.SectionNumber) > len(f.Sections) {
			continue
		}
		// Section symbols name their section and carry an aux record.
		if s.StorageClass == 3 && s.NumberOfAuxSymbols > 0 && s.Value == 0 {
			continue
		}
		if s.StorageClass == 2 || s.StorageClass == 3 {
			bySection[int(s.SectionNumber)] = append(bySection[int(s.SectionNumber)], symbols[i])
		}
	}
	for k, list := range bySection {
		sort.SliceStable(list, func(a, b int) bool { return list[a].value < list[b].value })
		size := int64(f.Sections[k-1].Size)
		for i, s := range list {
			length, ok := lengths[s.name]
			if !ok || s.class != 2 {
				continue
			}
			defined[s.name]++
			end := size
			for _, next := range list[i+1:] {
				if next.value > s.value {
					end = int64(next.value)
					break
				}
			}
			if int64(s.value)+length > end {
				return nil, fmt.Errorf("table %s has %d bytes in its source but %d in the object", s.name, length, end-int64(s.value))
			}
		}
	}

	var found []finding
	for k, sec := range f.Sections {
		h := sec.SectionHeader
		if h.NumberOfRelocations == 0 {
			continue
		}
		count, at := int(h.NumberOfRelocations), int(h.PointerToRelocations)
		const overflow = 0x01000000 // IMAGE_SCN_LNK_NRELOC_OVFL
		if sec.Characteristics&overflow != 0 && count == 0xffff {
			if at+10 > len(data) {
				return nil, fmt.Errorf("section %d's relocations lie outside the object", k+1)
			}
			count = int(binary.LittleEndian.Uint32(data[at:])) - 1
			at += 10
		}
		if at < 0 || at+10*count > len(data) {
			return nil, fmt.Errorf("section %d's relocations lie outside the object", k+1)
		}
		var code []byte
		for r := 0; r < count; r++ {
			rec := data[at+10*r:]
			offset := binary.LittleEndian.Uint32(rec)
			index := binary.LittleEndian.Uint32(rec[4:])
			kind := binary.LittleEndian.Uint16(rec[8:])
			if int(index) >= len(symbols) {
				return nil, fmt.Errorf("a relocation names symbol %d of %d", index, len(symbols))
			}
			target := symbols[index].name
			length, ok := lengths[target]
			if !ok {
				continue
			}
			*refs++
			size := 4
			switch {
			case kind == relAddr64:
				size = 8
			case kind == relAddr32 || kind == relAddr32NB || (kind >= relRel32 && kind <= relRel32_5):
			default:
				return nil, fmt.Errorf("relocation type %d to %s is not read", kind, target)
			}
			if code == nil {
				if code, err = sec.Data(); err != nil {
					return nil, err
				}
			}
			if int(offset)+size > len(code) {
				return nil, fmt.Errorf("a relocation to %s lies outside its section", target)
			}
			var addend int64
			if size == 8 {
				addend = int64(binary.LittleEndian.Uint64(code[offset:]))
			} else {
				addend = int64(int32(binary.LittleEndian.Uint32(code[offset:])))
			}
			if !outside(kind, addend, length) {
				continue
			}
			// The holder is the last symbol of the section at or before the
			// relocation: the function or data the relocation belongs to.
			holder := fmt.Sprintf("section %d", k+1)
			for _, s := range bySection[k+1] {
				if s.value > offset {
					break
				}
				holder = s.name
			}
			found = append(found, finding{path, holder, target, addend, length})
		}
	}
	return found, nil
}

func lines(path string) ([]string, error) {
	text, err := os.ReadFile(path)
	if err != nil {
		return nil, err
	}
	var out []string
	s := bufio.NewScanner(bytes.NewReader(text))
	for s.Scan() {
		if line := strings.TrimSuffix(s.Text(), "\r"); line != "" {
			out = append(out, line)
		}
	}
	return out, s.Err()
}

// Exit 0: no relocation outside a table other than the allowed ones, and each
// allowed one is found. Exit 1: otherwise. Exit 2: the check could not be
// completed.
func run(args []string, out, errOut io.Writer) int {
	flags := flag.NewFlagSet("table-bounds", flag.ContinueOnError)
	flags.SetOutput(io.Discard)
	sourcesPath := flags.String("sources", "", "a file with one generated vtable unit per line")
	root := flags.String("root", "", "the directory that relative source paths start from")
	objectsPath := flags.String("objects", "", "a file with one object path per line")
	allowPath := flags.String("allow", "", "the known reads past a table's end")
	if err := flags.Parse(args); err != nil || *sourcesPath == "" || *objectsPath == "" || *allowPath == "" || flags.NArg() != 0 {
		fmt.Fprintln(errOut, "usage: table-bounds --sources FILE [--root DIR] --objects FILE --allow FILE")
		return 2
	}
	incomplete := func(err error) int {
		fmt.Fprintln(errOut, "table-bounds: incomplete:", err)
		return 2
	}
	sources, err := lines(*sourcesPath)
	if err != nil {
		return incomplete(err)
	}
	for i, s := range sources {
		if !filepath.IsAbs(s) {
			sources[i] = filepath.Join(*root, s)
		}
	}
	lengths, err := readTables(sources)
	if err != nil {
		return incomplete(err)
	}
	text, err := os.ReadFile(*allowPath)
	if err != nil {
		return incomplete(err)
	}
	allow, err := readAllow(string(text))
	if err != nil {
		return incomplete(err)
	}
	objects, err := lines(*objectsPath)
	if err != nil {
		return incomplete(err)
	}
	defined := map[string]int{}
	refs := 0
	var found []finding
	for _, path := range objects {
		data, err := os.ReadFile(path)
		if err != nil {
			return incomplete(err)
		}
		f, err := scan(path, data, lengths, defined, &refs)
		if err != nil {
			return incomplete(fmt.Errorf("%s: %w", path, err))
		}
		found = append(found, f...)
	}
	var names []string
	for n := range lengths {
		names = append(names, n)
	}
	sort.Strings(names)
	for _, n := range names {
		if defined[n] != 1 {
			return incomplete(fmt.Errorf("table %s is defined %d times in the objects", n, defined[n]))
		}
	}

	failed := 0
	seen := map[allowed]bool{}
	for _, f := range found {
		key := allowed{f.holder, f.table}
		status := "FAIL"
		if allow[key] {
			status, seen[key] = "allowed", true
		} else {
			failed++
		}
		fmt.Fprintf(out, "%s\t%s\t%s\t%s\taddend %d\tlength %d\n", status, f.object, f.holder, f.table, f.addend, f.length)
	}
	var stale []string
	for key := range allow {
		if !seen[key] {
			stale = append(stale, fmt.Sprintf("FAIL\tallowed read not found\t%s\t%s", key.holder, key.table))
		}
	}
	sort.Strings(stale)
	for _, s := range stale {
		fmt.Fprintln(out, s)
	}
	fmt.Fprintf(out, "%d tables, %d relocations to them, %d outside, %d allowed\n", len(lengths), refs, len(found), len(found)-failed)
	if failed > 0 || len(stale) > 0 {
		return 1
	}
	return 0
}
