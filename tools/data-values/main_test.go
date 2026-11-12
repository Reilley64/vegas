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
	le.PutUint32(b[12:], 2)
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
	for i, n := range []string{name, "?other@@3HA"} {
		rec := make([]byte, 18)
		le.PutUint32(rec[4:], uint32(len(stringTable)))
		stringTable = append(append(stringTable, n...), 0)
		if i == 0 {
			le.PutUint32(rec[8:], at)
			le.PutUint16(rec[12:], 1)
			rec[16] = class
		} else {
			rec[16] = 2
		}
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
