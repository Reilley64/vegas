package main

import (
	"bufio"
	"bytes"
	"context"
	"fmt"
	"io"
	"os"
	"os/exec"
	"path/filepath"
	"regexp"
	"strings"
)

type rule struct {
	name string
	re   *regexp.Regexp
}
type policy struct {
	rules         []rule
	allowLines    [][]byte
	emails        map[string]bool
	contentEmails map[string]bool
	deny          []string
}

var emailRE = regexp.MustCompile(`[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}`)

func gitConfig(ctx context.Context, dir, key string) ([]byte, error) {
	c := exec.CommandContext(ctx, "git", "config", "--get-all", key)
	c.Dir = dir
	data, err := c.Output()
	if e, ok := err.(*exec.ExitError); ok && e.ExitCode() == 1 && len(data) == 0 {
		return nil, nil
	}
	if err != nil {
		return nil, fmt.Errorf("cannot read Git policy configuration")
	}
	return data, nil
}
func loadPolicy(ctx context.Context, dir, root, patterns string) (*policy, error) {
	p := &policy{emails: make(map[string]bool), contentEmails: make(map[string]bool)}
	data, err := os.ReadFile(patterns)
	if err != nil {
		return nil, fmt.Errorf("cannot read pattern file")
	}
	for _, line := range bytes.Split(bytes.TrimSuffix(data, []byte{'\n'}), []byte{'\n'}) {
		for _, b := range line {
			if b < 32 || b > 126 {
				return nil, fmt.Errorf("invalid policy pattern")
			}
		}
		name, expression, ok := strings.Cut(string(line), "|")
		if !ok || name == "" || expression == "" || strings.ContainsRune(expression, '\r') {
			return nil, fmt.Errorf("invalid policy pattern")
		}
		re, err := regexp.CompilePOSIX(expression)
		if err != nil {
			return nil, fmt.Errorf("invalid policy expression")
		}
		p.rules = append(p.rules, rule{name, re})
	}
	data, err = os.ReadFile(filepath.Join(root, "tools/hooks/public-allow.txt"))
	if err != nil && !os.IsNotExist(err) {
		return nil, fmt.Errorf("cannot read content allowlist")
	}
	for _, line := range bytes.Split(data, []byte{'\n'}) {
		if len(line) > 0 && line[0] != '#' {
			p.allowLines = append(p.allowLines, line)
		}
	}
	data, err = os.ReadFile(filepath.Join(root, "tools/hooks/public-content-emails.txt"))
	if err != nil {
		return nil, fmt.Errorf("cannot read content email policy")
	}
	for _, line := range bytes.Split(bytes.TrimSuffix(data, []byte{'\n'}), []byte{'\n'}) {
		if len(line) == 0 || !bytes.Equal(emailRE.Find(line), line) {
			return nil, fmt.Errorf("invalid content email policy")
		}
		p.contentEmails[lowerASCII(string(line))] = true
	}
	data, err = gitConfig(ctx, dir, "public.allowEmail")
	if err != nil {
		return nil, err
	}
	for _, e := range strings.Split(strings.TrimRight(string(data), "\n"), "\n") {
		p.emails[lowerASCII(e)] = true
	}
	for _, e := range strings.FieldsFunc(os.Getenv("PUBLIC_ALLOW_EMAILS"), func(r rune) bool { return r == ' ' || r == '\t' || r == '\n' }) {
		p.emails[lowerASCII(e)] = true
	}
	data, err = gitConfig(ctx, dir, "public.deny")
	if err != nil {
		return nil, err
	}
	if s := strings.TrimRight(string(data), "\n"); s != "" {
		for _, word := range strings.Split(s, "\n") {
			p.deny = append(p.deny, lowerASCII(word))
		}
	}
	return p, nil
}
func (p *policy) emailAllowed(e string) bool {
	e = lowerASCII(e)
	return strings.HasSuffix(e, "@users.noreply.github.com") || p.emails[e] && e != ""
}
func (p *policy) ident(label, email string, report func(string, string)) {
	if !p.emailAllowed(email) {
		report(label, "identity email is not allowed")
	}
}

// One private spool holds a normalized record, never the complete range.
func (p *policy) normalize(r io.Reader, f *os.File, label string, report func(string, string)) (int64, error) {
	if err := f.Truncate(0); err != nil {
		return 0, err
	}
	if _, err := f.Seek(0, 0); err != nil {
		return 0, err
	}
	w := bufio.NewWriter(f)
	br := bufio.NewReader(r)
	var size, pending int64
	nulReported := false
	for {
		line, err := br.ReadBytes('\n')
		if len(line) > 0 {
			// NUL is a policy refusal before any content exemption. Keep reading
			// the complete record and range; never remove or replace input bytes.
			if !nulReported && bytes.IndexByte(line, 0) >= 0 {
				report(label, "NUL byte in historical text")
				nulReported = true
			}
			allowed := false
			for _, literal := range p.allowLines {
				if bytes.IndexByte(line, 0) < 0 && bytes.Contains(line, literal) {
					allowed = true
					break
				}
			}
			if !allowed {
				body := bytes.TrimSuffix(line, []byte{'\n'})
				for _, rule := range p.rules {
					if rule.re.Match(body) {
						report(label, rule.name)
					}
				}
				lower := lowerASCII(string(body))
				for _, word := range p.deny {
					if strings.Contains(lower, word) {
						report(label, "public.deny word")
						break
					}
				}
				for _, email := range emailRE.FindAll(body, -1) {
					if !p.emailAllowed(string(email)) && !p.contentEmails[lowerASCII(string(email))] {
						report(label, "text email is not allowed")
					}
				}
				nonLF := bytes.TrimRight(line, "\n")
				if len(nonLF) > 0 {
					for pending > 0 {
						if err := w.WriteByte('\n'); err != nil {
							return 0, err
						}
						pending--
						size++
					}
					if _, e := w.Write(nonLF); e != nil {
						return 0, e
					}
					size += int64(len(nonLF))
				}
				pending += int64(len(line) - len(nonLF))
			}
		}
		if err == io.EOF {
			break
		}
		if err != nil {
			return 0, err
		}
	}
	// Command substitution strips trailing LF, then the here-string adds one.
	if size > 0 {
		if err := w.WriteByte('\n'); err != nil {
			return 0, err
		}
		size++
	}
	if err := w.Flush(); err != nil {
		return 0, err
	}
	if _, err := f.Seek(0, 0); err != nil {
		return 0, err
	}
	return size, nil
}

// Shell policy uses byte-wise case conversion in the C locale.
func lowerASCII(s string) string {
	b := []byte(s)
	for i, c := range b {
		if c >= 'A' && c <= 'Z' {
			b[i] = c + ('a' - 'A')
		}
	}
	return string(b)
}
