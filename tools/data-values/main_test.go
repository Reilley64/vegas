package main

import (
	"bytes"
	"encoding/binary"
	"os"
	"path/filepath"
	"strings"
	"testing"
)

const (
	dataFlags = 0xC0000040 // initialised data, read, write
	bssFlags  = 0xC0000080 // uninitialised data, read, write
)

// testObject writes an x64 COFF object with one section of the given flags
// and contents. It defines name at offset at with the storage class class
// and has one ADDR64 relocation at each offset of relocs.
func testObject(flags uint32, contents []byte, name string, at uint32, class byte, relocs ...uint32) []byte {
	return coffObject(flags, contents, []symbol{{name, at, 1, class}, {"?other@@3HA", 0, 0, 2}}, relocs...)
}

// symbol is one symbol table record of coffObject: a name, a value, a section
// number (0 for an undefined name) and a storage class.
type symbol struct {
	name    string
	value   uint32
	section int16
	class   byte
}

// coffObject writes an x64 COFF object with one section of the given flags
// and contents, the given symbols and one ADDR64 relocation at each offset of
// relocs.
func coffObject(flags uint32, contents []byte, symbols []symbol, relocs ...uint32) []byte {
	le := binary.LittleEndian
	// debug/pe reads 96 bytes before it knows the file is an object.
	if len(contents) < 96 {
		contents = append(contents, make([]byte, 96-len(contents))...)
	}
	const headerEnd = 20 + 40
	relocAt := headerEnd + len(contents)
	symbolAt := relocAt + 10*len(relocs)

	b := make([]byte, headerEnd)
	le.PutUint16(b[0:], 0x8664)
	le.PutUint16(b[2:], 1)
	le.PutUint32(b[8:], uint32(symbolAt))
	le.PutUint32(b[12:], uint32(len(symbols)))
	section := b[20:]
	copy(section, ".data")
	le.PutUint32(section[16:], uint32(len(contents)))
	if flags&0x80 == 0 {
		le.PutUint32(section[20:], headerEnd)
	}
	le.PutUint32(section[24:], uint32(relocAt))
	le.PutUint16(section[32:], uint16(len(relocs)))
	le.PutUint32(section[36:], flags)
	b = append(b, contents...)
	for _, r := range relocs {
		rec := make([]byte, 10)
		le.PutUint32(rec[0:], r)
		le.PutUint32(rec[4:], 1)
		le.PutUint16(rec[8:], 1) // ADDR64
		b = append(b, rec...)
	}
	stringTable := []byte{0, 0, 0, 0}
	for _, sym := range symbols {
		rec := make([]byte, 18)
		le.PutUint32(rec[4:], uint32(len(stringTable)))
		stringTable = append(append(stringTable, sym.name...), 0)
		le.PutUint32(rec[8:], sym.value)
		le.PutUint16(rec[12:], uint16(sym.section))
		rec[16] = sym.class
		b = append(b, rec...)
	}
	le.PutUint32(stringTable, uint32(len(stringTable)))
	return append(b, stringTable...)
}

func contentsWith(at int, value ...byte) []byte {
	c := make([]byte, 16)
	copy(c[at:], value)
	return c
}

const testTable = "# comment\n\nvalue\tsrc/a.cpp\t?g_010173f0@@3IA\tffffffff\n"

// setup writes the table, the object of src/a.cpp and the object list, and
// returns the arguments that name the table and the list.
func setup(t *testing.T, text string, object []byte) []string {
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
	table := write("table.tsv", []byte(text))
	a := write("game.dir/src/a.cpp.obj", object)
	b := write("game.dir/src/b.cpp.obj", []byte("unused"))
	list := write("objects.txt", []byte(a+"\n"+b+"\n"))
	return []string{"--table", table, "--objects", list}
}

func check(t *testing.T, args []string, want int, wantOut string) {
	t.Helper()
	var out, errOut bytes.Buffer
	if got := run(args, &out, &errOut); got != want {
		t.Fatalf("exit %d, want %d; out %q; err %q", got, want, out.String(), errOut.String())
	}
	if !strings.Contains(out.String()+errOut.String(), wantOut) {
		t.Fatalf("output %q lacks %q", out.String()+errOut.String(), wantOut)
	}
}

func TestPasses(t *testing.T) {
	object := testObject(dataFlags, contentsWith(8, 0xff, 0xff, 0xff, 0xff), "?g_010173f0@@3IA", 8, 2)
	check(t, setup(t, testTable, object), 0, "ok\tsrc/a.cpp\t?g_010173f0@@3IA")
}

func TestZeroInUninitialisedSectionFails(t *testing.T) {
	object := testObject(bssFlags, make([]byte, 16), "?g_010173f0@@3IA", 4, 2)
	check(t, setup(t, testTable, object), 1, "FAIL\tsrc/a.cpp\t?g_010173f0@@3IA\tin section .data, which has no initialised contents")
}

func TestOtherBytesFail(t *testing.T) {
	zero := testObject(dataFlags, make([]byte, 16), "?g_010173f0@@3IA", 0, 2)
	check(t, setup(t, testTable, zero), 1, "bytes 00000000, not ffffffff")
	partial := testObject(dataFlags, contentsWith(0, 0xff, 0xff, 0xff, 0x7f), "?g_010173f0@@3IA", 0, 2)
	check(t, setup(t, testTable, partial), 1, "bytes ffffff7f, not ffffffff")
}

func TestRelocationOverBytesFails(t *testing.T) {
	object := testObject(dataFlags, contentsWith(8, 0xff, 0xff, 0xff, 0xff), "?g_010173f0@@3IA", 8, 2, 4)
	check(t, setup(t, testTable, object), 1, "a relocation at section offset 4 may patch its bytes")
	clear := testObject(dataFlags, contentsWith(8, 0xff, 0xff, 0xff, 0xff), "?g_010173f0@@3IA", 8, 2, 0, 12)
	check(t, setup(t, testTable, clear), 0, "ok")
}

func TestIncompleteInputs(t *testing.T) {
	undefined := testObject(dataFlags, contentsWith(0, 0xff, 0xff, 0xff, 0xff), "?h@@3IA", 0, 2)
	check(t, setup(t, testTable, undefined), 2, "?g_010173f0@@3IA is not defined")
	static := testObject(dataFlags, contentsWith(0, 0xff, 0xff, 0xff, 0xff), "?g_010173f0@@3IA", 0, 3)
	check(t, setup(t, testTable, static), 2, "is not defined")
	outside := testObject(dataFlags, make([]byte, 96), "?g_010173f0@@3IA", 94, 2)
	check(t, setup(t, testTable, outside), 2, "lie outside section")
	check(t, setup(t, testTable, []byte("not an object")), 2, "incomplete")
	check(t, setup(t, "value\tsrc/c.cpp\t?g@@3IA\tff\n", nil), 2, "0 objects of src/c.cpp, not 1")
	check(t, nil, 2, "usage")
}

func TestTableErrors(t *testing.T) {
	object := testObject(dataFlags, contentsWith(0, 0xff, 0xff, 0xff, 0xff), "?g_010173f0@@3IA", 0, 2)
	for _, text := range []string{
		"",
		"# only a comment\n",
		"value\tsrc/a.cpp\t?g_010173f0@@3IA\n",
		"value\tsrc/a.cpp\t?g_010173f0@@3IA\t\n",
		"value\tsrc/a.cpp\t?g_010173f0@@3IA\tfffffff\n",
		"value\tsrc/a.cpp\t?g_010173f0@@3IA\tzz\n",
		"other\tsrc/a.cpp\t?g_010173f0@@3IA\tff\n",
		"value\t\t?g_010173f0@@3IA\tff\n",
	} {
		check(t, setup(t, text, object), 2, "incomplete")
	}
}

// A Windows checkout writes the table with CRLF line ends; it must read as it
// does with LF.
func TestCRLFTable(t *testing.T) {
	crlf := strings.ReplaceAll(testTable, "\n", "\r\n")
	object := testObject(dataFlags, contentsWith(8, 0xff, 0xff, 0xff, 0xff), "?g_010173f0@@3IA", 8, 2)
	check(t, setup(t, crlf, object), 0, "ok\tsrc/a.cpp\t?g_010173f0@@3IA")
	zero := testObject(dataFlags, make([]byte, 16), "?g_010173f0@@3IA", 0, 2)
	check(t, setup(t, crlf, zero), 1, "bytes 00000000, not ffffffff")
}

const extentTable = "extent\tsrc/a.cpp\tDAT_01202b48\t260\n"

// bssObject defines DAT_01202b48 at offset 16 of a 600-byte uninitialised
// section, followed by the given other symbols.
func bssObject(others ...symbol) []byte {
	return coffObject(bssFlags, make([]byte, 600), append([]symbol{{"DAT_01202b48", 16, 1, 2}}, others...))
}

func TestExtentPasses(t *testing.T) {
	// The next symbol 260 bytes on, or 264 with padding.
	check(t, setup(t, extentTable, bssObject(symbol{"next", 276, 1, 3})), 0, "ok\tsrc/a.cpp\tDAT_01202b48")
	check(t, setup(t, extentTable, bssObject(symbol{"next", 280, 1, 2})), 0, "ok")
	// No later symbol: the section's end, 584 bytes on.
	check(t, setup(t, extentTable, bssObject()), 0, "ok")
	// A symbol at the same offset, an earlier one, an undefined name and the
	// section symbol do not end the definition.
	check(t, setup(t, extentTable, bssObject(symbol{"alias", 16, 1, 2}, symbol{"before", 8, 1, 3},
		symbol{"?other@@3HA", 20, 0, 2}, symbol{".bss", 0, 1, 3})), 0, "ok")
	// An initialised section is measured the same way.
	data := coffObject(dataFlags, make([]byte, 300), []symbol{{"DAT_01202b48", 0, 1, 2}})
	check(t, setup(t, extentTable, data), 0, "ok")
}

func TestShortExtentFails(t *testing.T) {
	// The one-byte form: the next definition one byte on.
	check(t, setup(t, extentTable, bssObject(symbol{"DAT_01202d55", 17, 1, 2})), 1,
		"FAIL\tsrc/a.cpp\tDAT_01202b48\treaches 1 bytes in section .data, not 260")
	check(t, setup(t, extentTable, bssObject(symbol{"next", 275, 1, 3})), 1, "reaches 259 bytes")
	// The nearest later symbol ends the definition, in either table order.
	check(t, setup(t, extentTable, bssObject(symbol{"near", 17, 1, 2}, symbol{"far", 400, 1, 2})), 1, "reaches 1 bytes")
	check(t, setup(t, extentTable, bssObject(symbol{"far", 400, 1, 2}, symbol{"near", 17, 1, 2})), 1, "reaches 1 bytes")
	end := coffObject(bssFlags, make([]byte, 200), []symbol{{"DAT_01202b48", 16, 1, 2}})
	check(t, setup(t, extentTable, end), 1, "reaches 184 bytes")
}

func TestExtentIncompleteInputs(t *testing.T) {
	check(t, setup(t, extentTable, coffObject(bssFlags, make([]byte, 600), []symbol{{"DAT_01202b48", 16, 1, 3}})), 2, "is not defined")
	check(t, setup(t, extentTable, coffObject(bssFlags, make([]byte, 100), []symbol{{"DAT_01202b48", 120, 1, 2}})), 2, "lies outside section")
	object := bssObject()
	for _, text := range []string{
		"extent\tsrc/a.cpp\tDAT_01202b48\t0\n",
		"extent\tsrc/a.cpp\tDAT_01202b48\t-4\n",
		"extent\tsrc/a.cpp\tDAT_01202b48\t0x104\n",
		"extent\tsrc/a.cpp\tDAT_01202b48\n",
		"extent\t\tDAT_01202b48\t260\n",
	} {
		check(t, setup(t, text, object), 2, "incomplete")
	}
}
