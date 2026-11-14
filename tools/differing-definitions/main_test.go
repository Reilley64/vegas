package main

import (
	"bytes"
	"encoding/binary"
	"fmt"
	"os"
	"path/filepath"
	"strings"
	"testing"
)

// testSection is one section of a synthetic object. Its first symbol is the
// static section symbol. key, when set, is the external symbol defined in it
// and helper a unit-local symbol defined in it.
type testSection struct {
	key, helper string
	flags       uint32
	selection   byte
	data        []byte
	bss         uint32 // the size of an uninitialised section, which has no data
	target      string // an undefined external the section's one relocation names
	local       string // or the helper of another section that it names
	overflow    bool   // store the relocation count in the first relocation record
}

func comdat(key string, selection byte, code bool, data string, target string) testSection {
	flags := uint32(sectionComdat)
	if code {
		flags |= sectionCode
	}
	return testSection{key: key, flags: flags, selection: selection, data: []byte(data), target: target}
}

// objectFile writes a COFF object, ordinary or bigobj, with long names in
// the string table.
func objectFile(big bool, sections ...testSection) []byte {
	le := binary.LittleEndian
	symbolSize, headerSize := 18, 20
	if big {
		symbolSize, headerSize = 20, 56
	}
	stringTable := []byte{0, 0, 0, 0}
	var symbols, raw bytes.Buffer
	count := 0
	index := map[string]int{}
	add := func(name string, section int, class byte, aux []byte) {
		rec := make([]byte, symbolSize)
		le.PutUint32(rec[4:], uint32(len(stringTable)))
		stringTable = append(append(stringTable, name...), 0)
		if big {
			le.PutUint32(rec[12:], uint32(int32(section)))
		} else {
			le.PutUint16(rec[12:], uint16(int16(section)))
		}
		rec[symbolSize-2] = class
		if aux != nil {
			rec[symbolSize-1] = 1
		}
		symbols.Write(rec)
		index[name] = count
		count++
		if aux != nil {
			symbols.Write(append(aux, make([]byte, symbolSize-len(aux))...))
			count++
		}
	}
	for i, s := range sections {
		aux := make([]byte, 18)
		aux[14] = s.selection
		add(".sect", i+1, classStatic, aux)
		if s.key != "" {
			add(s.key, i+1, classExternal, nil)
		}
		if s.helper != "" {
			add(s.helper, i+1, classStatic, nil)
		}
	}
	for _, s := range sections {
		if s.target != "" {
			add(s.target, 0, classExternal, nil)
		}
	}
	dataStart := headerSize + 40*len(sections)
	headers := make([]byte, 40*len(sections))
	for i, s := range sections {
		h := headers[i*40:]
		copy(h, ".sect")
		if s.bss != 0 {
			le.PutUint32(h[16:], s.bss)
			s.flags |= sectionUninitialized
		} else {
			le.PutUint32(h[16:], uint32(len(s.data)))
			le.PutUint32(h[20:], uint32(dataStart+raw.Len()))
			raw.Write(s.data)
		}
		if name := s.target + s.local; name != "" {
			le.PutUint32(h[24:], uint32(dataStart+raw.Len()))
			le.PutUint16(h[32:], 1)
			if s.overflow {
				first := make([]byte, 10)
				le.PutUint32(first, 2)
				raw.Write(first)
				le.PutUint16(h[32:], 0xffff)
				s.flags |= sectionManyRelocs
			}
			reloc := make([]byte, 10)
			le.PutUint32(reloc[4:], uint32(index[name]))
			reloc[8] = 4
			raw.Write(reloc)
		}
		le.PutUint32(h[36:], s.flags)
	}
	le.PutUint32(stringTable, uint32(len(stringTable)))
	header := make([]byte, headerSize)
	symbolOffset := uint32(dataStart + raw.Len())
	if big {
		le.PutUint16(header[2:], 0xffff)
		le.PutUint16(header[4:], 2)
		le.PutUint16(header[6:], machineX64)
		le.PutUint32(header[44:], uint32(len(sections)))
		le.PutUint32(header[48:], symbolOffset)
		le.PutUint32(header[52:], uint32(count))
	} else {
		le.PutUint16(header[0:], machineX64)
		le.PutUint16(header[2:], uint16(len(sections)))
		le.PutUint32(header[8:], symbolOffset)
		le.PutUint32(header[12:], uint32(count))
	}
	out := append(header, headers...)
	out = append(out, raw.Bytes()...)
	out = append(out, symbols.Bytes()...)
	return append(out, stringTable...)
}

type testMember struct {
	name string
	body []byte
}

// archiveOf writes an ar archive with a linker member. A name of up to 15
// bytes is stored in the member header. A longer one goes to the long-name
// table, ended by the given terminator: "/\n" as GNU ar writes it, or "\x00"
// as the COFF tools do.
func archiveOf(terminator string, members ...testMember) []byte {
	var out, longNames bytes.Buffer
	out.WriteString("!<arch>\n")
	put := func(name string, body []byte) {
		fmt.Fprintf(&out, "%-16s%-12d%-6d%-6d%-8o%-10d`\n", name, 0, 0, 0, 0, len(body))
		out.Write(body)
		if len(body)&1 == 1 {
			out.WriteByte('\n')
		}
	}
	names := make([]string, len(members))
	for i, m := range members {
		if len(m.name) <= 15 {
			names[i] = m.name + "/"
			continue
		}
		names[i] = fmt.Sprintf("/%d", longNames.Len())
		longNames.WriteString(m.name + terminator)
	}
	put("/", []byte{0, 0, 0, 0})
	if longNames.Len() > 0 {
		put("//", longNames.Bytes())
	}
	for i, m := range members {
		put(names[i], m.body)
	}
	return out.Bytes()
}

// archive names its members as the build does.
func archive(objects ...[]byte) []byte {
	members := make([]testMember, len(objects))
	for i, body := range objects {
		members[i] = testMember{fmt.Sprintf("CMakeFiles/game.dir/src/unit%d.cpp.obj", i), body}
	}
	return archiveOf("\x00", members...)
}

func describe(t *testing.T, data []byte, wantMembers int) []string {
	t.Helper()
	list, members, err := conflicts(data)
	if err != nil || members != wantMembers {
		t.Fatalf("conflicts: %v, %d members", err, members)
	}
	var out []string
	for _, c := range list {
		out = append(out, fmt.Sprintf("%s %s %s %d/%d %s", c.kind, c.name, c.selection, c.definitions, c.contents, c.first))
	}
	return out
}

func found(t *testing.T, objects ...[]byte) []string {
	t.Helper()
	return describe(t, archive(objects...), len(objects))
}

const unit0 = "CMakeFiles/game.dir/src/unit0.cpp.obj"

func TestConflicts(t *testing.T) {
	const fn, table, zero = "?f@@YAXXZ", "??_7C@@6B@", "?z@@3HA"
	bss := func(size uint32) testSection {
		return testSection{key: zero, flags: sectionComdat, selection: selectAny, bss: size}
	}
	// A function whose one relocation names the unit-local helper, and the helper.
	caller := testSection{key: fn, flags: sectionComdat | sectionCode, selection: selectAny, data: []byte("abc"), local: "helper"}
	helper := func(flags uint32, body string) testSection {
		return testSection{helper: "helper", flags: flags | sectionCode, selection: 1, data: []byte(body)}
	}
	overflow := comdat(fn, selectAny, true, "abc", "?g@@YAXXZ")
	overflow.overflow = true
	overflowOther := comdat(fn, selectAny, true, "abc", "?h@@YAXXZ")
	overflowOther.overflow = true
	cases := []struct {
		name    string
		objects [][]byte
		want    []string
	}{
		{"equal select-any definitions", [][]byte{
			objectFile(false, comdat(fn, selectAny, true, "abc", "?g@@YAXXZ")),
			objectFile(true, comdat(fn, selectAny, true, "abc", "?g@@YAXXZ")),
		}, nil},
		{"differing bytes", [][]byte{
			objectFile(false, comdat(fn, selectAny, true, "abc", "")),
			objectFile(false, comdat(fn, selectAny, true, "abd", "")),
			objectFile(true, comdat(fn, selectAny, true, "abd", "")),
		}, []string{"function " + fn + " any 3/2 " + unit0}},
		{"differing relocation target", [][]byte{
			objectFile(false, comdat(fn, selectAny, true, "abc", "?g@@YAXXZ")),
			objectFile(false, comdat(fn, selectAny, true, "abc", "?h@@YAXXZ")),
		}, []string{"function " + fn + " any 2/2 " + unit0}},
		{"anonymous namespace hash in a target", [][]byte{
			objectFile(false, comdat(fn, selectAny, true, "abc", "?g@?A0x1234abcd@@YAXXZ")),
			objectFile(false, comdat(fn, selectAny, true, "abc", "?g@?A0xFFEE0011@@YAXXZ")),
		}, nil},
		{"largest selection is compared", [][]byte{
			objectFile(false, comdat(table, selectLargest, false, "12345678", "")),
			objectFile(false, comdat(table, selectLargest, false, "1234567812345678", "")),
		}, []string{"vtable " + table + " largest 2/2 " + unit0}},
		{"mixed selections", [][]byte{
			objectFile(false, comdat(table, selectAny, false, "1", "")),
			objectFile(false, comdat(table, selectLargest, false, "2", "")),
		}, []string{"vtable " + table + " mixed 2/2 " + unit0}},
		{"associative sections belong to their function", [][]byte{
			objectFile(false, comdat(fn, selectAny, true, "abc", ""), comdat("$unwind$f", selectAssociative, false, "1", "")),
			objectFile(false, comdat(fn, selectAny, true, "abc", ""), comdat("$unwind$f", selectAssociative, false, "2", "")),
		}, nil},
		{"two definitions outside COMDAT sections", [][]byte{
			objectFile(false, testSection{key: "?v@@3HA", data: []byte("1")}),
			objectFile(false, testSection{key: "?v@@3HA", data: []byte("1")}),
		}, []string{"data ?v@@3HA none 2/2 " + unit0}},
		{"one definition", [][]byte{
			objectFile(false, comdat(fn, selectAny, true, "abc", "")),
			objectFile(false, comdat("", selectAny, true, "abd", fn)),
		}, nil},
		{"uninitialised definitions of one size", [][]byte{
			objectFile(false, bss(4)), objectFile(true, bss(4)),
		}, nil},
		{"uninitialised definitions of two sizes", [][]byte{
			objectFile(false, bss(4)), objectFile(false, bss(8)),
		}, []string{"data " + zero + " any 2/2 " + unit0}},
		{"equal unit-local helpers in sections of their own", [][]byte{
			objectFile(false, caller, helper(sectionComdat, "body")),
			objectFile(true, caller, helper(sectionComdat, "body")),
		}, nil},
		{"same-named unit-local helpers with different bodies", [][]byte{
			objectFile(false, caller, helper(sectionComdat, "body")),
			objectFile(false, caller, helper(sectionComdat, "BODY")),
		}, []string{"function " + fn + " any 2/2 " + unit0}},
		{"unit-local helpers in a shared section are compared by name", [][]byte{
			objectFile(false, caller, helper(0, "body")),
			objectFile(false, caller, helper(0, "BODY")),
		}, nil},
		{"relocation count stored in the first record", [][]byte{
			objectFile(false, overflow),
			objectFile(false, comdat(fn, selectAny, true, "abc", "?g@@YAXXZ")),
		}, nil},
		{"differing target after a stored relocation count", [][]byte{
			objectFile(false, overflow),
			objectFile(false, overflowOther),
		}, []string{"function " + fn + " any 2/2 " + unit0}},
	}
	for _, c := range cases {
		t.Run(c.name, func(t *testing.T) {
			if got := found(t, c.objects...); strings.Join(got, "\n") != strings.Join(c.want, "\n") {
				t.Errorf("got %q, want %q", got, c.want)
			}
		})
	}
}

func TestMemberNames(t *testing.T) {
	const fn = "?f@@YAXXZ"
	a := objectFile(false, comdat(fn, selectAny, true, "abc", ""))
	b := objectFile(false, comdat(fn, selectAny, true, "abd", ""))
	long := "CMakeFiles/game.dir/src/a/unit.cpp.obj"
	cases := []struct {
		name    string
		archive []byte
		want    string
	}{
		{"a short name in the member header", archiveOf("\x00", testMember{"a.obj", a}, testMember{"b.obj", b}), "a.obj"},
		{"GNU long names", archiveOf("/\n", testMember{long, a}, testMember{"CMakeFiles/game.dir/src/b/unit.cpp.obj", b}), long},
		{"COFF long names", archiveOf("\x00", testMember{long, a}, testMember{"b.obj", b}), long},
		{"two members with one name", archiveOf("/\n", testMember{long, a}, testMember{long, b}), long},
		{"two members with one short name", archiveOf("/\n", testMember{"unit.obj", a}, testMember{"unit.obj", b}), "unit.obj"},
	}
	for _, c := range cases {
		t.Run(c.name, func(t *testing.T) {
			want := "function " + fn + " any 2/2 " + c.want
			if got := describe(t, c.archive, 2); len(got) != 1 || got[0] != want {
				t.Errorf("got %q, want %q", got, want)
			}
		})
	}
}

func TestUnreadableInput(t *testing.T) {
	const fn = "?f@@YAXXZ"
	good := objectFile(false, comdat(fn, selectAny, true, "abc", ""))
	otherMachine := bytes.Clone(good)
	binary.LittleEndian.PutUint16(otherMachine, 0x14c)
	importMember := make([]byte, 64)
	binary.LittleEndian.PutUint16(importMember[2:], 0xffff)
	unknownSelection := objectFile(false, comdat(fn, 9, true, "abc", ""))
	danglingTarget := objectFile(false, comdat(fn, selectAny, true, "abc", "?g@@YAXXZ"))
	relocation := 20 + 40 + 3
	binary.LittleEndian.PutUint32(danglingTarget[relocation+4:], 1000)
	bsdName := []byte("!<arch>\n" + fmt.Sprintf("%-16s%-12d%-6d%-6d%-8o%-10d`\n", "#1/20", 0, 0, 0, 0, 0))
	for name, data := range map[string][]byte{
		"not an archive":              []byte("not an archive"),
		"truncated member header":     append(archive(good), "short"...),
		"member that is not COFF":     archive([]byte{1, 2, 3}),
		"object for another machine":  archive(otherMachine),
		"import member":               archive(importMember),
		"bitcode member":              archive(append([]byte("BC\xc0\xde"), make([]byte, 60)...)),
		"COMDAT selection not known":  archive(unknownSelection),
		"relocation without a target": archive(good, danglingTarget),
		"BSD member name":             bsdName,
	} {
		t.Run(name, func(t *testing.T) {
			if _, _, err := conflicts(data); err == nil {
				t.Error("no error")
			}
		})
	}
}

func TestKinds(t *testing.T) {
	for name, want := range map[string]string{
		"??_R0?AVC@@@8": "rtti-type-descriptor", "??_R1A@?0A@EA@C@@8": "rtti-base-class-descriptor",
		"??_R2C@@8": "rtti-base-class-array", "??_R3C@@8": "rtti-class-hierarchy", "??_R4C@@6B@": "rtti-complete-object-locator",
		"_TI1?AVC@@": "throw-info", "_CTA1?AVC@@": "catchable-type-array", "_CT??_R0?AVC@@@8??0C@@QEAA@AEBV0@@Z24": "catchable-type",
		"??_C@_01A@a@": "string", "__real@3f800000": "constant", "?v@@3HA": "data",
	} {
		if got := kindOf(name, false); got != want {
			t.Errorf("%s: got %s, want %s", name, got, want)
		}
	}
	if got := kindOf("??_7C@@6B@", true); got != "function" {
		t.Errorf("a code section is a function, got %s", got)
	}
}

func TestRun(t *testing.T) {
	const fn, table = "?f@@YAXXZ", "??_7C@@6B@"
	const gone, gone2 = "function\t?gone@@YAXXZ", "data\t?gone2@@3HA"
	dir := t.TempDir()
	lib := filepath.Join(dir, "game.lib")
	write := func(path, text string) {
		t.Helper()
		if err := os.WriteFile(path, []byte(text), 0o600); err != nil {
			t.Fatal(err)
		}
	}
	write(lib, string(archive(
		objectFile(false, comdat(fn, selectAny, true, "abc", ""), comdat(table, selectLargest, false, "1", "")),
		objectFile(true, comdat(fn, selectAny, true, "abd", ""), comdat(table, selectLargest, false, "2", "")),
	)))
	summary := func(names, functions, added, stale int) string {
		return fmt.Sprintf("2 members, %d names with differing definitions, %d of them functions, %d new, %d stale\n", names, functions, added, stale)
	}
	newLine := "NEW\tfunction\t" + fn + "\tany\t2 definitions, 2 contents, first in " + unit0 + "\tnot recorded"
	exact := "# comment\n\nfunction\t" + fn + "\nvtable\t" + table + "\r\n"
	// Stale lines first, in the middle and last, around comments and a blank line.
	withStale := gone + "\n# first\nfunction\t" + fn + "\n\n" + gone2 + "\r\n# second\nvtable\t" + table + "\n"
	pruned := "# first\nfunction\t" + fn + "\n\n# second\nvtable\t" + table + "\n"
	staleAndNew := "# only the table\n" + gone + "\nvtable\t" + table + "\n"
	cases := []struct {
		name, allowlist string
		flags           []string
		exit            int
		want            []string // parts of the output
		after           string   // the allowlist afterwards; empty: unchanged
	}{
		{"recorded exactly", exact, nil, 0, []string{summary(2, 1, 0, 0)}, ""},
		{"recorded exactly, strict", exact, []string{"--strict"}, 0, []string{summary(2, 1, 0, 0)}, ""},
		{"recorded exactly, prune", exact, []string{"--prune"}, 0, []string{summary(2, 1, 0, 0)}, ""},
		{"new name", "vtable\t" + table + "\n", nil, 1, []string{newLine, summary(2, 1, 1, 0)}, ""},
		{"new name, prune adds nothing", "vtable\t" + table + "\n", []string{"--prune"}, 1, []string{newLine, summary(2, 1, 1, 0)}, ""},
		{"recorded under another kind", "data\t" + fn + "\nvtable\t" + table + "\n", nil, 1, []string{"NEW\tfunction\t" + fn, "recorded as data"}, ""},
		{"recorded under another kind, prune keeps the line", "data\t" + fn + "\nvtable\t" + table + "\n", []string{"--prune"}, 1, []string{"recorded as data"}, ""},
		{"stale lines pass by default", withStale, nil, 0, []string{"STALE\t" + gone + "\t", "STALE\t" + gone2 + "\t", summary(2, 1, 0, 2)}, ""},
		{"stale lines fail when strict", withStale, []string{"--strict"}, 1, []string{"STALE\t" + gone + "\t", summary(2, 1, 0, 2)}, ""},
		{"prune removes only stale lines", withStale, []string{"--prune"}, 0, []string{"PRUNED\t" + gone + "\t", "PRUNED\t" + gone2 + "\t", summary(2, 1, 0, 0)}, pruned},
		{"prune then strict in one run", withStale, []string{"--prune", "--strict"}, 0, []string{summary(2, 1, 0, 0)}, pruned},
		{"prune with a new name removes the stale line and fails", staleAndNew, []string{"--prune"}, 1, []string{newLine, "PRUNED\t" + gone + "\t", summary(2, 1, 1, 0)}, "# only the table\nvtable\t" + table + "\n"},
		{"malformed line", "function " + fn + "\n", []string{"--prune"}, 2, []string{"allowlist line 1 is not"}, ""},
		{"repeated name", "function\t" + fn + "\nfunction\t" + fn + "\n", nil, 2, []string{"allowlist line 2 repeats"}, ""},
	}
	for _, c := range cases {
		t.Run(c.name, func(t *testing.T) {
			listDir := t.TempDir()
			list := filepath.Join(listDir, "allowlist.tsv")
			write(list, c.allowlist)
			var out bytes.Buffer
			args := append([]string{"--archive", lib, "--allowlist", list}, c.flags...)
			if exit := run(args, &out, &out); exit != c.exit {
				t.Errorf("exit %d, want %d: %s", exit, c.exit, out.String())
			}
			for _, want := range c.want {
				if !strings.Contains(out.String(), want) {
					t.Errorf("output %q lacks %q", out.String(), want)
				}
			}
			want := c.after
			if want == "" {
				want = c.allowlist
			}
			if got, err := os.ReadFile(list); err != nil || string(got) != want {
				t.Errorf("allowlist afterwards %q, want %q (%v)", got, want, err)
			}
			if left, _ := os.ReadDir(listDir); len(left) != 1 {
				t.Errorf("%d files beside the allowlist, want none", len(left)-1)
			}
		})
	}

	var out bytes.Buffer
	wantList := "vtable\t" + table + "\tlargest\t2 definitions, 2 contents, first in " + unit0 + "\n" +
		"function\t" + fn + "\tany\t2 definitions, 2 contents, first in " + unit0 + "\n"
	if exit := run([]string{"--archive", lib, "--list"}, &out, &out); exit != 0 || out.String() != wantList {
		t.Errorf("--list: exit %d, %q", exit, out.String())
	}
	for _, args := range [][]string{
		{}, {"--archive", lib}, {"--archive", lib, "--list", "--allowlist", lib},
		{"--archive", lib, "--list", "--prune"}, {"--archive", lib, "--list", "--strict"},
		{"--archive", lib, "--prune"}, {"--archive", lib, "--allowlist", lib, "extra"},
		{"--archive", filepath.Join(dir, "absent"), "--list"}, {"--archive", lib, "--allowlist", filepath.Join(dir, "absent")},
	} {
		if exit := run(args, &out, &out); exit != 2 {
			t.Errorf("%v: exit %d, want 2", args, exit)
		}
	}
	write(lib, string(archive([]byte{1, 2, 3})))
	if exit := run([]string{"--archive", lib, "--list"}, &out, &out); exit != 2 {
		t.Errorf("bad object: exit %d, want 2", exit)
	}
}
