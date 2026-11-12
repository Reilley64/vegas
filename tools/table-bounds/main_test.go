package main

import (
	"bytes"
	"encoding/binary"
	"os"
	"path/filepath"
	"strings"
	"testing"
)

// sym is a symbol of a test object: its section (0 for undefined), value and
// storage class (2 external, 3 static).
type sym struct {
	name    string
	section int16
	value   uint32
	class   uint8
}

// rel is a relocation of the test object's code section: its offset in the
// code, the index of its target in the symbols, its type and stored addend.
type rel struct {
	offset uint32
	target int
	kind   uint16
	addend int32
}

// testObject writes an x64 COFF object with a data section of dataSize bytes
// (section 1) and a code section of 64 bytes (section 2) that holds rels.
func testObject(dataSize int, symbols []sym, rels []rel) []byte {
	le := binary.LittleEndian
	stringTable := []byte{0, 0, 0, 0}
	var table bytes.Buffer
	for _, s := range symbols {
		rec := make([]byte, 18)
		le.PutUint32(rec[4:], uint32(len(stringTable)))
		stringTable = append(append(stringTable, s.name...), 0)
		le.PutUint32(rec[8:], s.value)
		le.PutUint16(rec[12:], uint16(s.section))
		rec[16] = s.class
		table.Write(rec)
	}
	le.PutUint32(stringTable, uint32(len(stringTable)))

	// debug/pe reads 96 bytes before it knows the file is an object.
	data := make([]byte, dataSize+96)
	code := make([]byte, 64)
	for _, r := range rels {
		le.PutUint32(code[r.offset:], uint32(r.addend))
	}
	const headerEnd = 20 + 2*40
	dataAt := headerEnd
	codeAt := dataAt + len(data)
	relocAt := codeAt + len(code)
	symbolAt := relocAt + 10*len(rels)

	b := make([]byte, headerEnd)
	le.PutUint16(b[0:], 0x8664)
	le.PutUint16(b[2:], 2)
	le.PutUint32(b[8:], uint32(symbolAt))
	le.PutUint32(b[12:], uint32(len(symbols)))
	s1 := b[20:]
	copy(s1, ".data")
	le.PutUint32(s1[16:], uint32(dataSize))
	le.PutUint32(s1[20:], uint32(dataAt))
	le.PutUint32(s1[36:], 0xc0000040)
	s2 := b[60:]
	copy(s2, ".text$mn")
	le.PutUint32(s2[16:], uint32(len(code)))
	le.PutUint32(s2[20:], uint32(codeAt))
	le.PutUint32(s2[24:], uint32(relocAt))
	le.PutUint16(s2[32:], uint16(len(rels)))
	le.PutUint32(s2[36:], 0x60000020)
	b = append(b, data...)
	b = append(b, code...)
	for _, r := range rels {
		rec := make([]byte, 10)
		le.PutUint32(rec[0:], r.offset)
		le.PutUint32(rec[4:], uint32(r.target))
		le.PutUint16(rec[8:], r.kind)
		b = append(b, rec...)
	}
	b = append(b, table.Bytes()...)
	return append(b, stringTable...)
}

const header = "extern \"C\" {\n" +
	"extern void* fnv_vftable_T[] __asm__(\"?T@@3HA\");\n" +
	"extern void* fnv_vftable_C[];\n" +
	"}\n"

// source defines ?T@@3HA with two slots and fnv_vftable_C with three.
const source = "#include \"vtables.h\"\n\n" +
	"// ?T@@3HA\nvoid* fnv_vftable_T[] = {\n    reinterpret_cast<void*>(&f),\n    nullptr, // no definition\n};\n\n" +
	"void* fnv_vftable_C[] = {\n    reinterpret_cast<void*>(&f),\n\n    reinterpret_cast<void*>(&f),\n    reinterpret_cast<void*>(&f),\n};\n"

// tables is the object that defines both tables: ?T@@3HA at 0, padded to 32
// bytes, then fnv_vftable_C.
func tables() []byte {
	return testObject(56, []sym{{"?T@@3HA", 1, 0, 2}, {"fnv_vftable_C", 1, 32, 2}}, nil)
}

// user is an object whose functions f and g (at code offset 32) refer to
// both tables with the given relocations; targets 2 and 3 are ?T@@3HA and
// fnv_vftable_C.
func user(rels ...rel) []byte {
	return testObject(8, []sym{{"?f@@YAXXZ", 2, 0, 2}, {"?g@@YAXXZ", 2, 32, 3}, {"?T@@3HA", 0, 0, 2}, {"fnv_vftable_C", 0, 0, 2}}, rels)
}

// setup writes the header, the source, the objects and the allow file, and
// returns the arguments of run.
func setup(t *testing.T, allow string, objects ...[]byte) []string {
	dir := t.TempDir()
	write := func(name string, data []byte) string {
		path := filepath.Join(dir, name)
		if err := os.MkdirAll(filepath.Dir(path), 0o755); err != nil {
			t.Fatal(err)
		}
		if err := os.WriteFile(path, data, 0o644); err != nil {
			t.Fatal(err)
		}
		return path
	}
	write("src/vtables.h", []byte(header))
	write("src/vtables_01.cpp", []byte(source))
	sources := write("sources.txt", []byte("src/vtables_01.cpp\n"))
	var list []string
	for i, o := range objects {
		list = append(list, write(filepath.Join("obj", string(rune('a'+i))+".obj"), o))
	}
	objectList := write("objects.txt", []byte(strings.Join(list, "\n")+"\n"))
	allowFile := write("allow.tsv", []byte(allow))
	return []string{"--sources", sources, "--root", dir, "--objects", objectList, "--allow", allowFile}
}

func check(t *testing.T, args []string, want int, wantOut ...string) {
	t.Helper()
	var out, errOut bytes.Buffer
	if got := run(args, &out, &errOut); got != want {
		t.Fatalf("exit %d, want %d; out %q; err %q", got, want, out.String(), errOut.String())
	}
	for _, w := range wantOut {
		if !strings.Contains(out.String()+errOut.String(), w) {
			t.Fatalf("output %q lacks %q", out.String()+errOut.String(), w)
		}
	}
}

func TestInsideTables(t *testing.T) {
	// Slots 0 and 1 of ?T@@3HA, slot 2 of fnv_vftable_C, a REL32 read at
	// offset 0 followed by a 4-byte immediate (stored as -4) and an ADDR64.
	args := setup(t, "", tables(), user(
		rel{0, 2, relRel32, 0}, rel{4, 2, relRel32, 8}, rel{8, 3, relRel32, 12},
		rel{12, 2, relRel32, -4}, rel{16, 3, relAddr64, 16}))
	check(t, args, 0, "2 tables, 5 relocations to them, 0 outside, 0 allowed")
}

func TestPastTheEnd(t *testing.T) {
	// The 16 bytes of padding after ?T@@3HA do not count as the table.
	args := setup(t, "", tables(), user(rel{0, 2, relRel32, 16}, rel{36, 3, relAddr64, 24}))
	check(t, args, 1,
		"FAIL\t", "?f@@YAXXZ\t?T@@3HA\taddend 16\tlength 16",
		"?g@@YAXXZ\tfnv_vftable_C\taddend 24\tlength 24",
		"2 outside, 0 allowed")
	// The immediate after a REL32 displacement may move the address up to 4
	// bytes past the stored addend.
	check(t, setup(t, "", tables(), user(rel{0, 2, relRel32, 12})), 1, "addend 12\tlength 16")
}

func TestBeforeTheStart(t *testing.T) {
	check(t, setup(t, "", tables(), user(rel{0, 2, relRel32, -5})), 1, "?f@@YAXXZ\t?T@@3HA\taddend -5")
	check(t, setup(t, "", tables(), user(rel{0, 2, relAddr32NB, -1})), 1, "addend -1")
}

func TestAllowed(t *testing.T) {
	allow := "# known\nallow\t?g@@YAXXZ\t?T@@3HA\n"
	args := setup(t, allow, tables(), user(rel{0, 2, relRel32, 0}, rel{40, 2, relRel32, 16}))
	check(t, args, 0, "allowed\t", "?g@@YAXXZ\t?T@@3HA\taddend 16", "1 outside, 1 allowed")
	// The same read in another function is not allowed.
	check(t, setup(t, allow, tables(), user(rel{0, 2, relRel32, 16}, rel{40, 2, relRel32, 16})), 1,
		"FAIL\t", "?f@@YAXXZ\t?T@@3HA")
	// An allowed read that is no longer found fails, so the line goes with
	// the repair.
	check(t, setup(t, allow, tables(), user(rel{0, 2, relRel32, 0})), 1,
		"FAIL\tallowed read not found\t?g@@YAXXZ\t?T@@3HA")
}

func TestIncomplete(t *testing.T) {
	// A table of the source that no object defines.
	check(t, setup(t, "", testObject(16, []sym{{"?T@@3HA", 1, 0, 2}}, nil)), 2, "fnv_vftable_C is defined 0 times")
	// Two definitions.
	check(t, setup(t, "", tables(), tables()), 2, "is defined 2 times")
	// A source length that does not fit before the next symbol.
	short := testObject(40, []sym{{"?T@@3HA", 1, 0, 2}, {"fnv_vftable_C", 1, 8, 2}}, nil)
	check(t, setup(t, "", short), 2, "table ?T@@3HA has 16 bytes in its source but 8 in the object")
	// A relocation type whose addend is not read.
	check(t, setup(t, "", tables(), user(rel{0, 2, 11, 0})), 2, "relocation type 11 to ?T@@3HA is not read")
	check(t, setup(t, "bad line\n", tables()), 2, "allow line 1 is malformed")
	check(t, []string{"--objects", "x"}, 2, "usage")
}

func TestReadTables(t *testing.T) {
	dir := t.TempDir()
	if err := os.WriteFile(filepath.Join(dir, "vtables.h"), []byte(header), 0o644); err != nil {
		t.Fatal(err)
	}
	for text, want := range map[string]string{
		"void* fnv_vftable_X[] = {\n    nullptr,\n};\n":                              "has no declaration",
		"void* fnv_vftable_T[] = {\n};\n":                                            "has no slot",
		"void* fnv_vftable_T[] = {\n    nullptr,\n":                                  "does not end",
		"void* fnv_vftable_T[] = {\n  0,\n};\nvoid* fnv_vftable_T[] = {\n  0,\n};\n": "defined twice",
		"int x;\n": "no table",
	} {
		path := filepath.Join(dir, "u.cpp")
		if err := os.WriteFile(path, []byte(text), 0o644); err != nil {
			t.Fatal(err)
		}
		if _, err := readTables([]string{path}); err == nil || !strings.Contains(err.Error(), want) {
			t.Errorf("source %q: error %v, want %q", text, err, want)
		}
	}
	path := filepath.Join(dir, "u.cpp")
	if err := os.WriteFile(path, []byte(source), 0o644); err != nil {
		t.Fatal(err)
	}
	lengths, err := readTables([]string{path})
	if err != nil || len(lengths) != 2 || lengths["?T@@3HA"] != 16 || lengths["fnv_vftable_C"] != 24 {
		t.Errorf("lengths %v, error %v", lengths, err)
	}
}
