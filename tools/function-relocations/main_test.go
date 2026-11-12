package main

import (
	"bytes"
	"encoding/binary"
	"os"
	"path/filepath"
	"strings"
	"testing"
)

// testObject writes an x64 COFF object with one code section that defines
// function and has one relocation to each name of calls. comdat sets the
// section's COMDAT flag.
func testObject(function string, comdat bool, calls ...string) []byte {
	le := binary.LittleEndian
	names := append([]string{function}, calls...)
	stringTable := []byte{0, 0, 0, 0}
	var symbols bytes.Buffer
	for i, n := range names {
		rec := make([]byte, 18)
		le.PutUint32(rec[4:], uint32(len(stringTable)))
		stringTable = append(append(stringTable, n...), 0)
		if i == 0 {
			le.PutUint16(rec[12:], 1) // defined in section 1
		}
		rec[16] = 2 // external
		symbols.Write(rec)
	}
	le.PutUint32(stringTable, uint32(len(stringTable)))

	// debug/pe reads 96 bytes before it knows the file is an object.
	code := bytes.Repeat([]byte{0x90}, 4*len(calls)+96)
	const headerEnd = 20 + 40
	relocAt := headerEnd + len(code)
	symbolAt := relocAt + 10*len(calls)

	b := make([]byte, headerEnd)
	le.PutUint16(b[0:], 0x8664)
	le.PutUint16(b[2:], 1)
	le.PutUint32(b[8:], uint32(symbolAt))
	le.PutUint32(b[12:], uint32(len(names)))
	section := b[20:]
	copy(section, ".text$mn")
	le.PutUint32(section[16:], uint32(len(code)))
	le.PutUint32(section[20:], headerEnd)
	le.PutUint32(section[24:], uint32(relocAt))
	le.PutUint16(section[32:], uint16(len(calls)))
	flags := uint32(0x60000020)
	if comdat {
		flags |= 0x1000
	}
	le.PutUint32(section[36:], flags)
	b = append(b, code...)
	for i := range calls {
		r := make([]byte, 10)
		le.PutUint32(r[0:], uint32(1+4*i))
		le.PutUint32(r[4:], uint32(1+i))
		le.PutUint16(r[8:], 4) // REL32
		b = append(b, r...)
	}
	b = append(b, symbols.Bytes()...)
	return append(b, stringTable...)
}

// withAddends sets the addend stored at each relocation of an object that
// testObject wrote: the i-th addend goes to the i-th relocation.
func withAddends(object []byte, addends ...int32) []byte {
	const codeAt = 20 + 40
	for i, a := range addends {
		binary.LittleEndian.PutUint32(object[codeAt+1+4*i:], uint32(a))
	}
	return object
}

const testTable = "# comment\n\nforbid\t?old@@YAXXZ\n" +
	"function\tone\tsrc/a.cpp\t?f@@YAXXZ\t?new@@YAXXZ\n" +
	"function\ttwo\tsrc/b.cpp\t?g@@YAXXZ\t?new@@YAXXZ\n"

// setup writes the table, the two objects and the object list, and returns
// the arguments that name the table and the list.
func setup(t *testing.T, a, b []byte) []string {
	return setupTable(t, testTable, a, b)
}

// setupTable is setup with another table.
func setupTable(t *testing.T, text string, a, b []byte) []string {
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
	pa := write("game.dir/src/a.cpp.obj", a)
	pb := write("game.dir/src/b.cpp.obj", b)
	list := write("objects.txt", []byte(pa+"\n"+pb+"\n"))
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
	args := setup(t, testObject("?f@@YAXXZ", true, "?new@@YAXXZ", "?other@@YAXXZ"),
		testObject("?g@@YAXXZ", true, "?new@@YAXXZ"))
	check(t, args, 0, "ok\ttwo\t?g@@YAXXZ")
}

func TestForbiddenTargetFails(t *testing.T) {
	args := setup(t, testObject("?f@@YAXXZ", true, "?new@@YAXXZ", "?old@@YAXXZ", "?old@@YAXXZ"),
		testObject("?g@@YAXXZ", true, "?new@@YAXXZ"))
	check(t, args, 1, "FAIL\tone\t?f@@YAXXZ\t2 relocations to ?old@@YAXXZ")
}

func TestMissingRequiredTargetFails(t *testing.T) {
	args := setup(t, testObject("?f@@YAXXZ", true, "?new@@YAXXZ"), testObject("?g@@YAXXZ", true))
	check(t, args, 1, "FAIL\ttwo\t?g@@YAXXZ\tno relocation to ?new@@YAXXZ")
}

func TestNoRequiredName(t *testing.T) {
	text := "forbid\t?old@@YAXXZ\n" +
		"function\tone\tsrc/a.cpp\t?f@@YAXXZ\t-\n" +
		"function\ttwo\tsrc/b.cpp\t?g@@YAXXZ\t-\n"
	pass := setupTable(t, text, testObject("?f@@YAXXZ", true), testObject("?g@@YAXXZ", true, "?other@@YAXXZ"))
	check(t, pass, 0, "ok\ttwo\t?g@@YAXXZ")
	fail := setupTable(t, text, testObject("?f@@YAXXZ", true, "?old@@YAXXZ"), testObject("?g@@YAXXZ", true))
	check(t, fail, 1, "FAIL\tone\t?f@@YAXXZ\t1 relocations to ?old@@YAXXZ")
}

const pastTable = "past\t?table@@3HA\t16\n" +
	"function\tone\tsrc/a.cpp\t?f@@YAXXZ\t-\n" +
	"function\ttwo\tsrc/b.cpp\t?g@@YAXXZ\t-\n"

func TestPastLength(t *testing.T) {
	// Slots 0 and 1 of a 16-byte table pass; the stored addend of a REL32
	// relocation may lie up to 4 bytes below the address used.
	pass := setupTable(t, pastTable,
		withAddends(testObject("?f@@YAXXZ", true, "?table@@3HA", "?table@@3HA", "?other@@YAXXZ"), 0, 8, 64),
		withAddends(testObject("?g@@YAXXZ", true, "?table@@3HA"), 11))
	check(t, pass, 0, "ok\ttwo\t?g@@YAXXZ")
	end := setupTable(t, pastTable,
		withAddends(testObject("?f@@YAXXZ", true, "?table@@3HA", "?table@@3HA"), 8, 16),
		withAddends(testObject("?g@@YAXXZ", true, "?table@@3HA"), 0))
	check(t, end, 1, "FAIL\tone\t?f@@YAXXZ\ta relocation to ?table@@3HA with addend 16 reaches past its 16 bytes")
	immediate := setupTable(t, pastTable,
		withAddends(testObject("?f@@YAXXZ", true, "?table@@3HA"), 0),
		withAddends(testObject("?g@@YAXXZ", true, "?table@@3HA"), 12))
	check(t, immediate, 1, "FAIL\ttwo\t?g@@YAXXZ\ta relocation to ?table@@3HA with addend 12")
	before := setupTable(t, pastTable,
		withAddends(testObject("?f@@YAXXZ", true, "?table@@3HA"), -8),
		withAddends(testObject("?g@@YAXXZ", true, "?table@@3HA"), 0))
	check(t, before, 1, "with addend -8 reaches past")
}

func TestBatchSelectsFunctions(t *testing.T) {
	args := setup(t, testObject("?f@@YAXXZ", true, "?old@@YAXXZ"), testObject("?g@@YAXXZ", true, "?new@@YAXXZ"))
	check(t, append(args, "--batch", "two"), 0, "ok\ttwo")
	check(t, append(args, "--batch", "one"), 1, "FAIL\tone")
	check(t, append(args, "--batch", "three"), 2, "no function of batch")
}

func TestIncompleteInputs(t *testing.T) {
	notComdat := setup(t, testObject("?f@@YAXXZ", false, "?new@@YAXXZ"), testObject("?g@@YAXXZ", true, "?new@@YAXXZ"))
	check(t, notComdat, 2, "not in a COMDAT code section")
	undefined := setup(t, testObject("?h@@YAXXZ", true), testObject("?g@@YAXXZ", true, "?new@@YAXXZ"))
	check(t, undefined, 2, "?f@@YAXXZ is not defined")
	notCoff := setup(t, []byte("not an object"), testObject("?g@@YAXXZ", true, "?new@@YAXXZ"))
	check(t, notCoff, 2, "incomplete")
	check(t, nil, 2, "usage")
}

func TestTableErrors(t *testing.T) {
	for _, text := range []string{
		"forbid\t?old@@YAXXZ\n",
		"function\tone\tsrc/a.cpp\t?f@@YAXXZ\t?new@@YAXXZ\n",
		"forbid\t?old@@YAXXZ\nfunction\tone\tsrc/a.cpp\t?f@@YAXXZ\n",
		"forbid\t?old@@YAXXZ\nother\tline\n",
		"past\t?table@@3HA\t0\nfunction\tone\tsrc/a.cpp\t?f@@YAXXZ\t-\n",
		"past\t?table@@3HA\nfunction\tone\tsrc/a.cpp\t?f@@YAXXZ\t-\n",
	} {
		if _, err := readTable(text); err == nil {
			t.Errorf("table %q was accepted", text)
		}
	}
}

func TestObjectForNeedsExactlyOne(t *testing.T) {
	objects := []string{"x/src/a.cpp.obj", "y/src/a.cpp.obj", "x/src/aa.cpp.obj"}
	if _, err := objectFor(objects, "src/a.cpp"); err == nil {
		t.Error("two objects of one unit were accepted")
	}
	if got, err := objectFor(objects, "src/aa.cpp"); err != nil || got != "x/src/aa.cpp.obj" {
		t.Errorf("got %q, %v", got, err)
	}
}
