// Command differing-definitions fails when an external name of the game
// archive has definitions that differ between members and the name is not on
// the recorded list.
package main

import (
	"flag"
	"fmt"
	"io"
	"os"
	"path/filepath"
	"sort"
	"strings"
)

func main() {
	os.Exit(run(os.Args[1:], os.Stdout, os.Stderr))
}

// conflict is a name whose definitions differ in content.
type conflict struct {
	name, kind, selection string
	definitions, contents int
	first                 string // the first member, in archive order, that defines the name
}

// Exit 0: no conflict is unrecorded. Exit 1: a conflict is not recorded, or,
// with --strict, a recorded name no longer conflicts. Exit 2: the check could
// not be completed.
func run(args []string, out, errOut io.Writer) int {
	flags := flag.NewFlagSet("differing-definitions", flag.ContinueOnError)
	flags.SetOutput(io.Discard)
	archive := flags.String("archive", "", "the game archive")
	listPath := flags.String("allowlist", "", "recorded conflicts: one 'kind<TAB>name' per line")
	list := flags.Bool("list", false, "report every conflict of the archive and exit 0")
	prune := flags.Bool("prune", false, "remove from the allowlist the lines whose names no longer conflict")
	strict := flags.Bool("strict", false, "exit 1 when a recorded name no longer conflicts")
	if err := flags.Parse(args); err != nil || *archive == "" || flags.NArg() != 0 || (*listPath == "") == !*list || *list && (*prune || *strict) {
		fmt.Fprintln(errOut, "usage: differing-definitions --archive FILE (--allowlist FILE [--prune] [--strict] | --list)")
		return 2
	}
	data, err := os.ReadFile(*archive)
	if err != nil {
		fmt.Fprintln(errOut, "differing-definitions: incomplete: cannot read the archive")
		return 2
	}
	found, members, err := conflicts(data)
	if err != nil {
		fmt.Fprintln(errOut, "differing-definitions: incomplete:", err)
		return 2
	}
	if *list {
		for _, c := range found {
			fmt.Fprintf(out, "%s\t%s\t%s\t%d definitions, %d contents, first in %s\n",
				c.kind, c.name, c.selection, c.definitions, c.contents, c.first)
		}
		return 0
	}
	text, err := os.ReadFile(*listPath)
	if err != nil {
		fmt.Fprintln(errOut, "differing-definitions: incomplete: cannot read the allowlist")
		return 2
	}
	lines, err := readAllowlist(string(text))
	if err != nil {
		fmt.Fprintln(errOut, "differing-definitions: incomplete:", err)
		return 2
	}
	recorded := map[string]string{}
	for _, l := range lines {
		if l.name != "" {
			recorded[l.name] = l.kind
		}
	}

	added, functions := 0, 0
	differs := map[string]bool{}
	for _, c := range found {
		differs[c.name] = true
		if c.kind == "function" {
			functions++
		}
		kind, known := recorded[c.name]
		if known && kind == c.kind {
			continue
		}
		added++
		reason := "not recorded"
		if known {
			reason = "recorded as " + kind
		}
		fmt.Fprintf(out, "NEW\t%s\t%s\t%s\t%d definitions, %d contents, first in %s\t%s\n",
			c.kind, c.name, c.selection, c.definitions, c.contents, c.first, reason)
	}
	// Stale lines are reported in the order of the allowlist.
	stale := 0
	var kept strings.Builder
	for _, l := range lines {
		if l.name == "" || differs[l.name] {
			kept.WriteString(l.text)
			continue
		}
		stale++
		if *prune {
			fmt.Fprintf(out, "PRUNED\t%s\t%s\tno longer has differing definitions; its line is removed\n", l.kind, l.name)
		} else {
			fmt.Fprintf(out, "STALE\t%s\t%s\tno longer has differing definitions\n", l.kind, l.name)
		}
	}
	if *prune && stale > 0 {
		// Only lines are removed. Nothing is ever added: a NEW name stays a failure.
		if err := replaceFile(*listPath, kept.String()); err != nil {
			fmt.Fprintln(errOut, "differing-definitions: incomplete: cannot rewrite the allowlist")
			return 2
		}
		stale = 0
	}
	fmt.Fprintf(out, "differing-definitions: %d members, %d names with differing definitions, %d of them functions, %d new, %d stale\n",
		members, len(found), functions, added, stale)
	if added > 0 || *strict && stale > 0 {
		return 1
	}
	return 0
}

// replaceFile writes the text beside the file, with the file's permissions,
// and renames it into place, so that a failed write leaves the file as it was.
func replaceFile(path, text string) error {
	temp, err := os.CreateTemp(filepath.Dir(path), filepath.Base(path)+".*")
	if err != nil {
		return err
	}
	if info, statErr := os.Stat(path); statErr == nil {
		err = temp.Chmod(info.Mode().Perm())
	}
	if err == nil {
		_, err = temp.WriteString(text)
	}
	if closeErr := temp.Close(); err == nil {
		err = closeErr
	}
	if err == nil {
		err = os.Rename(temp.Name(), path)
	}
	if err != nil {
		os.Remove(temp.Name())
	}
	return err
}

// conflicts returns, sorted by name, every external name whose definitions
// differ. Every COMDAT selection is compared. A definition outside a COMDAT
// section differs from every other definition of its name.
func conflicts(archive []byte) ([]conflict, int, error) {
	members, err := archiveMembers(archive)
	if err != nil {
		return nil, 0, err
	}
	byName := map[string][]definition{}
	for _, m := range members {
		defs, err := objectDefinitions(m.name, m.body)
		if err != nil {
			return nil, 0, err
		}
		for _, d := range defs {
			byName[d.name] = append(byName[d.name], d)
		}
	}
	var out []conflict
	for name, defs := range byName {
		if len(defs) < 2 {
			continue
		}
		contents := map[[32]byte]bool{}
		selections := map[int]bool{}
		plain := 0
		for _, d := range defs {
			contents[d.content] = true
			selections[d.selection] = true
			if d.selection == selectNone {
				plain++
			}
		}
		distinct := len(contents)
		if plain > 0 {
			distinct = len(defs)
		}
		if distinct < 2 {
			continue
		}
		selection := "mixed"
		switch {
		case len(selections) > 1:
		case selections[selectAny]:
			selection = "any"
		case selections[selectLargest]:
			selection = "largest"
		case selections[selectNone]:
			selection = "none"
		default:
			selection = "other"
		}
		out = append(out, conflict{name, kindOf(name, defs[0].code), selection, len(defs), distinct, defs[0].member})
	}
	sort.Slice(out, func(i, j int) bool { return out[i].name < out[j].name })
	return out, len(members), nil
}

// kindOf classifies a name by its section and by the compiler's prefix.
func kindOf(name string, code bool) string {
	if code {
		return "function"
	}
	for _, k := range [...]struct{ prefix, kind string }{
		{"??_7", "vtable"},
		{"??_R0", "rtti-type-descriptor"},
		{"??_R1", "rtti-base-class-descriptor"},
		{"??_R2", "rtti-base-class-array"},
		{"??_R3", "rtti-class-hierarchy"},
		{"??_R4", "rtti-complete-object-locator"},
		{"_TI", "throw-info"},
		{"_CTA", "catchable-type-array"},
		{"_CT", "catchable-type"},
		{"??_C@", "string"},
		{"__real@", "constant"},
		{"__xmm@", "constant"},
		{"__ymm@", "constant"},
		{"?$TSS", "guard"},
		{"??_B", "guard"},
	} {
		if strings.HasPrefix(name, k.prefix) {
			return k.kind
		}
	}
	return "data"
}

// allowlistLine is one line of the allowlist with its line ending. name is
// empty for a blank line and for a comment.
type allowlistLine struct {
	text, kind, name string
}

// readAllowlist reads 'kind<TAB>name' lines. Blank lines and lines that start
// with '#' carry no name. A malformed or repeated line is an error.
func readAllowlist(text string) ([]allowlistLine, error) {
	var out []allowlistLine
	seen := map[string]bool{}
	for n, raw := range strings.SplitAfter(text, "\n") {
		if raw == "" {
			continue
		}
		line := strings.TrimRight(raw, "\r\n")
		if line == "" || strings.HasPrefix(line, "#") {
			out = append(out, allowlistLine{text: raw})
			continue
		}
		kind, name, ok := strings.Cut(line, "\t")
		if !ok || kind == "" || name == "" || strings.ContainsAny(name, "\t ") {
			return nil, fmt.Errorf("allowlist line %d is not 'kind<TAB>name'", n+1)
		}
		if seen[name] {
			return nil, fmt.Errorf("allowlist line %d repeats a name", n+1)
		}
		seen[name] = true
		out = append(out, allowlistLine{raw, kind, name})
	}
	return out, nil
}
