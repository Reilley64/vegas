package main

import (
	"bytes"
	"crypto/sha256"
	"encoding/binary"
	"errors"
	"fmt"
	"hash"
	"regexp"
	"strconv"
	"strings"
)

// COMDAT selection values of a section definition record.
const (
	selectNone        = 0 // not a COMDAT section
	selectAny         = 2
	selectAssociative = 5
	selectLargest     = 6
	selectNewest      = 7 // the highest value the format defines
)

const (
	machineX64           = 0x8664
	sectionCode          = 0x00000020
	sectionUninitialized = 0x00000080
	sectionComdat        = 0x00001000
	sectionManyRelocs    = 0x01000000
	classExternal        = 2
	classStatic          = 3
)

// definition is one external definition of a name in one archive member.
type definition struct {
	name      string
	member    string
	selection int
	code      bool
	size      int
	content   [sha256.Size]byte
}

type member struct {
	name string
	body []byte
}

var errFormat = errors.New("malformed input")

// anonymous matches the per-file hash clang puts in the names of an
// anonymous namespace, so that two units' spellings of one name compare equal.
var anonymous = regexp.MustCompile(`\?A0x[0-9A-Fa-f]+@`)

// archiveMembers lists the object members of an ar archive in stored order.
// The linker members and the long-name table are not returned. Two members
// may have the same name; both are returned.
func archiveMembers(data []byte) ([]member, error) {
	const magic = "!<arch>\n"
	if !bytes.HasPrefix(data, []byte(magic)) {
		return nil, fmt.Errorf("%w: not an archive", errFormat)
	}
	var out []member
	var longNames []byte
	for pos := len(magic); pos < len(data); {
		if pos+60 > len(data) {
			return nil, fmt.Errorf("%w: truncated member header", errFormat)
		}
		header := data[pos : pos+60]
		size, err := strconv.Atoi(strings.TrimSpace(string(header[48:58])))
		if err != nil || size < 0 || pos+60+size > len(data) {
			return nil, fmt.Errorf("%w: bad member size", errFormat)
		}
		body := data[pos+60 : pos+60+size]
		pos += 60 + size + size&1
		name := strings.TrimRight(string(header[:16]), " ")
		switch {
		case name == "/" || name == "/SYM64/":
			continue
		case name == "//":
			longNames = body
			continue
		case strings.HasPrefix(name, "#1/"):
			return nil, fmt.Errorf("%w: BSD member names are not supported", errFormat)
		case strings.HasPrefix(name, "/"):
			offset, err := strconv.Atoi(name[1:])
			if err != nil || offset >= len(longNames) {
				return nil, fmt.Errorf("%w: bad long member name", errFormat)
			}
			rest := longNames[offset:]
			if end := bytes.IndexAny(rest, "\x00\n"); end >= 0 {
				rest = rest[:end]
			}
			name = strings.TrimRight(string(rest), "/")
		default:
			name = strings.TrimRight(name, "/")
		}
		out = append(out, member{name, body})
	}
	return out, nil
}

type symbol struct {
	name       string
	value      uint32
	section    int
	class      byte
	sectionDef bool // a static symbol with a section definition record
	selection  int  // of that record
}

type section struct {
	rawSize, rawPointer, relocPointer uint32
	relocCount                        uint32
	flags                             uint32
}

// object is one parsed COFF object.
type object struct {
	b        []byte
	symbols  []*symbol // nil at the index of an auxiliary record
	sections []section
}

type reloc struct {
	offset uint32
	kind   uint16
	target *symbol
}

func (o *object) relocs(s section) []reloc {
	le := binary.LittleEndian
	first, count := uint32(0), s.relocCount
	if s.flags&sectionManyRelocs != 0 && count == 0xffff {
		first, count = 1, le.Uint32(o.b[s.relocPointer:])
	}
	out := make([]reloc, 0, count-first)
	for r := first; r < count; r++ {
		at := s.relocPointer + r*10
		target := o.symbols[le.Uint32(o.b[at+4:])]
		if target == nil {
			panic("a relocation names an auxiliary record")
		}
		out = append(out, reloc{le.Uint32(o.b[at:]), le.Uint16(o.b[at+8:]), target})
	}
	return out
}

func targetName(s *symbol) string {
	return anonymous.ReplaceAllString(s.name, "?A0x@")
}

// writeSection hashes the size, the bytes and the relocations of a section,
// each target by name. An uninitialised section has no bytes, so the size is
// what tells two zero-initialised definitions of different size apart.
func (o *object) writeSection(h hash.Hash, s section) {
	fmt.Fprintf(h, "%d\x00", s.rawSize)
	if s.flags&sectionUninitialized == 0 && s.rawPointer != 0 {
		h.Write(o.b[s.rawPointer : s.rawPointer+s.rawSize])
	}
	for _, r := range o.relocs(s) {
		fmt.Fprintf(h, "\x00%d %d %s", r.offset, r.kind, targetName(r.target))
	}
}

// local hashes what a unit-local relocation target holds, so that two
// definitions with equal bytes that refer to same-named unit-local symbols
// with different contents differ. It goes one level deep: the targets of the
// target are compared by name. Only a target in a COMDAT section of its own
// is followed, because such a section holds one object and its extent is the
// section. For any other unit-local target local returns false and the name
// stands for it:
//   - a target in the section that refers to it;
//   - a target in a section that holds several objects, such as .rdata,
//     .data or .bss, where nothing in the object says where the target ends.
func (o *object) local(from int, t *symbol) ([]byte, bool) {
	if t.class != classStatic || t.section <= 0 || t.section == from {
		return nil, false
	}
	s := o.sections[t.section-1]
	if s.flags&sectionComdat == 0 {
		return nil, false
	}
	h := sha256.New()
	fmt.Fprintf(h, "%d\x00", t.value)
	o.writeSection(h, s)
	return h.Sum(nil), true
}

// content is the key two definitions are compared by: the section's size,
// bytes and relocations. A relocation target is named, except a unit-local
// one whose extent is known, which is replaced by what it holds.
func (o *object) content(index int) [sha256.Size]byte {
	s := o.sections[index-1]
	h := sha256.New()
	fmt.Fprintf(h, "%d\x00", s.rawSize)
	if s.flags&sectionUninitialized == 0 && s.rawPointer != 0 {
		h.Write(o.b[s.rawPointer : s.rawPointer+s.rawSize])
	}
	for _, r := range o.relocs(s) {
		if held, ok := o.local(index, r.target); ok {
			fmt.Fprintf(h, "\x00%d %d local %x", r.offset, r.kind, held)
		} else {
			fmt.Fprintf(h, "\x00%d %d %s", r.offset, r.kind, targetName(r.target))
		}
	}
	var sum [sha256.Size]byte
	h.Sum(sum[:0])
	return sum
}

// parseObject reads an x64 COFF object, ordinary or bigobj. Anything else,
// such as an import member, a bitcode member or an object for another
// machine, is an error: the check does not pass over what it cannot read.
func parseObject(memberName string, b []byte) (o *object, err error) {
	defer func() {
		if recover() != nil {
			o, err = nil, fmt.Errorf("%w: %s is not a readable COFF object", errFormat, memberName)
		}
	}()
	le := binary.LittleEndian
	var machine uint16
	var sectionCount, symbolOffset, symbolCount, sectionOffset, symbolSize int
	big := len(b) >= 56 && le.Uint16(b[0:]) == 0 && le.Uint16(b[2:]) == 0xffff && le.Uint16(b[4:]) >= 2
	if big {
		machine = le.Uint16(b[6:])
		sectionCount, symbolOffset, symbolCount = int(le.Uint32(b[44:])), int(le.Uint32(b[48:])), int(le.Uint32(b[52:]))
		sectionOffset, symbolSize = 56, 20
	} else {
		machine = le.Uint16(b[0:])
		sectionCount, symbolOffset, symbolCount = int(le.Uint16(b[2:])), int(le.Uint32(b[8:])), int(le.Uint32(b[12:]))
		sectionOffset, symbolSize = 20+int(le.Uint16(b[16:])), 18
	}
	if machine != machineX64 {
		return nil, fmt.Errorf("%w: %s is not an x64 COFF object", errFormat, memberName)
	}
	stringOffset := symbolOffset + symbolCount*symbolSize
	text := func(offset int) string {
		end := bytes.IndexByte(b[offset:], 0)
		return string(b[offset : offset+end])
	}

	o = &object{b: b, symbols: make([]*symbol, symbolCount), sections: make([]section, sectionCount)}
	for i := 0; i < symbolCount; {
		at := symbolOffset + i*symbolSize
		s := &symbol{value: le.Uint32(b[at+8:])}
		if le.Uint32(b[at:]) == 0 {
			s.name = text(stringOffset + int(le.Uint32(b[at+4:])))
		} else {
			s.name = string(bytes.TrimRight(b[at:at+8], "\x00"))
		}
		if big {
			s.section = int(int32(le.Uint32(b[at+12:])))
		} else {
			s.section = int(int16(le.Uint16(b[at+12:])))
		}
		s.class = b[at+symbolSize-2]
		aux := int(b[at+symbolSize-1])
		if s.class == classStatic && aux > 0 && s.section > 0 {
			s.sectionDef, s.selection = true, int(b[at+symbolSize+14])
		}
		if s.section > sectionCount {
			panic("a symbol names a section the object does not have")
		}
		o.symbols[i] = s
		i += 1 + aux
	}
	for i := range o.sections {
		at := sectionOffset + i*40
		o.sections[i] = section{
			rawSize:      le.Uint32(b[at+16:]),
			rawPointer:   le.Uint32(b[at+20:]),
			relocPointer: le.Uint32(b[at+24:]),
			relocCount:   uint32(le.Uint16(b[at+32:])),
			flags:        le.Uint32(b[at+36:]),
		}
	}
	return o, nil
}

// objectDefinitions returns every external definition of one COFF object. A
// COMDAT section is keyed by its first external symbol. A section that is
// associated with another one, such as the unwind records of a function,
// belongs to that definition and is not compared.
func objectDefinitions(memberName string, b []byte) (defs []definition, err error) {
	o, err := parseObject(memberName, b)
	if err != nil {
		return nil, err
	}
	defer func() {
		if recover() != nil {
			defs, err = nil, fmt.Errorf("%w: %s is not a readable COFF object", errFormat, memberName)
		}
	}()
	selection := map[int]int{}
	for _, s := range o.symbols {
		if s != nil && s.sectionDef {
			if _, seen := selection[s.section]; !seen {
				selection[s.section] = s.selection
			}
		}
	}
	keyed := map[int]bool{}
	for _, s := range o.symbols {
		if s == nil || s.class != classExternal || s.section <= 0 {
			continue
		}
		sec := o.sections[s.section-1]
		d := definition{name: s.name, member: memberName, code: sec.flags&sectionCode != 0, size: int(sec.rawSize)}
		if sec.flags&sectionComdat != 0 {
			chosen, known := selection[s.section]
			if !known || chosen <= selectNone || chosen > selectNewest {
				return nil, fmt.Errorf("%w: %s has a COMDAT section without a known selection", errFormat, memberName)
			}
			d.selection = chosen
			if d.selection == selectAssociative || keyed[s.section] {
				continue
			}
			keyed[s.section] = true
		}
		d.content = o.content(s.section)
		defs = append(defs, d)
	}
	return defs, nil
}
