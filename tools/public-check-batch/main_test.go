package main

import (
	"bytes"
	"context"
	"crypto/sha256"
	"encoding/hex"
	"encoding/json"
	"errors"
	"fmt"
	"io"
	"os"
	"os/exec"
	"path/filepath"
	"reflect"
	"strings"
	"testing"
)

func git(t *testing.T, dir string, args ...string) string {
	t.Helper()
	c := exec.Command("git", args...)
	c.Dir = dir
	b, e := c.CombinedOutput()
	if e != nil {
		t.Fatalf("git %v: %v: %s", args, e, b)
	}
	return strings.TrimSpace(string(b))
}
func fixture(t *testing.T) (string, string) {
	t.Helper()
	dir := t.TempDir()
	t.Setenv("GIT_CONFIG_GLOBAL", filepath.Join(dir, "absent-global"))
	t.Setenv("GIT_CONFIG_NOSYSTEM", "1")
	t.Setenv("PUBLIC_ALLOW_EMAILS", "")
	t.Setenv("GITLEAKS_CONFIG", "")
	t.Setenv("GITLEAKS_CONFIG_TOML", "")
	t.Setenv("LC_ALL", "C")
	git(t, dir, "init", "-q")
	git(t, dir, "config", "user.name", "Public")
	git(t, dir, "config", "user.email", "public@users.noreply.github.com")
	if e := os.MkdirAll(filepath.Join(dir, "tools/hooks"), 0700); e != nil {
		t.Fatal(e)
	}
	if e := os.WriteFile(filepath.Join(dir, "tools/hooks/public-allow.txt"), nil, 0600); e != nil {
		t.Fatal(e)
	}
	for _, name := range []string{"public-patterns.txt", "public-content-emails.txt"} {
		data, err := os.ReadFile(filepath.Join("../hooks", name))
		if err != nil {
			t.Fatal(err)
		}
		if err = os.WriteFile(filepath.Join(dir, "tools/hooks", name), data, 0600); err != nil {
			t.Fatal(err)
		}
	}
	patterns := filepath.Join(dir, "tools/hooks/public-patterns.txt")
	return dir, patterns
}
func commit(t *testing.T, dir, msg, text string) string {
	t.Helper()
	if e := os.WriteFile(filepath.Join(dir, "content.txt"), []byte(text), 0600); e != nil {
		t.Fatal(e)
	}
	git(t, dir, "add", "content.txt")
	git(t, dir, "commit", "-q", "--allow-empty", "-m", msg)
	return git(t, dir, "rev-parse", "HEAD")
}
func invoke(t *testing.T, dir, patterns string, revs ...string) (int, string) {
	t.Helper()
	var out bytes.Buffer
	code := run(context.Background(), dir, append([]string{"--patterns", patterns, "range"}, revs...), &out)
	return code, out.String()
}
func TestRangeRetainsDeletedContentAndMessages(t *testing.T) {
	dir, p := fixture(t)
	commit(t, dir, "public root", "ordinary\n")
	base := git(t, dir, "rev-parse", "HEAD")
	commit(t, dir, "private message: "+strings.Join([]string{"app", "plane", "so/example"}, "."), "ordinary\n")
	commit(t, dir, "introduce", strings.Join([]string{"", "home", "private-fixture", "secret\n"}, "/"))
	commit(t, dir, "remove", "ordinary\n")
	code, out := invoke(t, dir, p, base+"..HEAD")
	if code != 1 || !strings.Contains(out, "message") || !strings.Contains(out, "added") {
		t.Fatalf("code %d: %s", code, out)
	}
}

func TestRangeChecksBothIdentitiesIncludingEmptyMerge(t *testing.T) {
	dir, p := fixture(t)
	root := commit(t, dir, "public root", "ordinary\n")
	git(t, dir, "checkout", "-q", "-b", "side")
	commit(t, dir, "side", "side\n")
	git(t, dir, "checkout", "-q", "master")
	git(t, dir, "config", "user.email", "bad-committer@example.invalid")
	// Author remains explicitly public while only the merge committer is bad.
	t.Setenv("GIT_AUTHOR_EMAIL", "public@users.noreply.github.com")
	git(t, dir, "merge", "--no-ff", "-m", "public merge", "side")
	code, out := invoke(t, dir, p, root+"..HEAD")
	if code != 1 || !strings.Contains(out, "committer") {
		t.Fatalf("code %d: %s", code, out)
	}
	git(t, dir, "config", "public.allowEmail", "BAD-COMMITTER@example.invalid")
	code, out = invoke(t, dir, p, root+"..HEAD")
	if code != 0 {
		t.Fatalf("explicit allowlist: %d %s", code, out)
	}
	t.Setenv("GIT_AUTHOR_EMAIL", "bad-author@example.invalid")
	git(t, dir, "config", "user.email", "public@users.noreply.github.com")
	commit(t, dir, "empty", "side\n")
	code, out = invoke(t, dir, p, "HEAD^..HEAD")
	if code != 1 || !strings.Contains(out, "author") {
		t.Fatalf("empty author: %d %s", code, out)
	}
}
func TestValidEmptyRangeAndInvalidSelection(t *testing.T) {
	dir, p := fixture(t)
	commit(t, dir, "root", "ordinary\n")
	for _, tc := range []struct {
		rev  string
		code int
	}{{"HEAD..HEAD", 0}, {"missing-ref..HEAD", 2}} {
		code, out := invoke(t, dir, p, tc.rev)
		if code != tc.code {
			t.Fatalf("%s: %d: %s", tc.rev, code, out)
		}
	}
}

func coverageEntries(t *testing.T, path string) []coverage {
	t.Helper()
	data, e := os.ReadFile(path)
	if e != nil {
		t.Fatal(e)
	}
	var rows []coverage
	for _, line := range bytes.Split(bytes.TrimSpace(data), []byte{'\n'}) {
		var row coverage
		if e = json.Unmarshal(line, &row); e != nil {
			t.Fatal(e)
		}
		rows = append(rows, row)
	}
	return rows
}
func baselineRecords(t *testing.T, dir string) []coverage {
	t.Helper()
	var rows []coverage
	for _, sha := range strings.Fields(git(t, dir, "rev-list", "HEAD")) {
		for _, field := range []struct{ kind, format string }{{"author", "%ae"}, {"committer", "%ce"}, {"message", "%B"}} {
			c := exec.Command("git", "log", "-1", "--format="+field.format, sha)
			c.Dir = dir
			b, e := c.Output()
			if e != nil {
				t.Fatal(e)
			}
			b = bytes.TrimRight(b, "\n")
			if field.kind == "message" && len(b) > 0 {
				b = append(b, '\n')
			}
			hash := sha256.Sum256(b)
			rows = append(rows, coverage{sha, field.kind, int64(len(b)), hex.EncodeToString(hash[:])})
		}
		c := exec.Command("git", "show", "-U0", "--no-color", "--no-ext-diff", "--format=", sha)
		c.Dir = dir
		b, e := c.Output()
		if e != nil {
			t.Fatal(e)
		}
		var text []byte
		for _, line := range bytes.Split(b, []byte{'\n'}) {
			if bytes.HasPrefix(line, []byte("+")) && !bytes.HasPrefix(line, []byte("+++ ")) {
				text = append(text, line[1:]...)
				text = append(text, '\n')
			}
		}
		text = bytes.TrimRight(text, "\n")
		if len(text) > 0 {
			text = append(text, '\n')
		}
		h := sha256.Sum256(text)
		rows = append(rows, coverage{sha, "added", int64(len(text)), hex.EncodeToString(h[:])})
	}
	return rows
}
func TestRootAndMergeCoverageMatchesOriginalGitExtraction(t *testing.T) {
	dir, p := fixture(t)
	commit(t, dir, "root\n\nlog size 100\nfake header", "common\n")
	git(t, dir, "checkout", "-q", "-b", "side")
	commit(t, dir, "side", "side\n")
	git(t, dir, "checkout", "-q", "master")
	commit(t, dir, "main", "main\n")
	c := exec.Command("git", "merge", "--no-ff", "-m", "resolution", "side")
	c.Dir = dir
	if c.Run() == nil {
		t.Fatal("expected conflict")
	}
	commit(t, dir, "merge resolution", "resolution\n")
	git(t, dir, "checkout", "-q", "-b", "extra")
	commit(t, dir, "extra", "resolution\n")
	git(t, dir, "checkout", "-q", "master")
	git(t, dir, "merge", "--no-ff", "-m", "empty merge", "extra")
	path := filepath.Join(dir, "coverage.jsonl")
	var out bytes.Buffer
	code := run(context.Background(), dir, []string{"--patterns", p, "--coverage", path, "range", "HEAD"}, &out)
	if code != 0 {
		t.Fatalf("%d %s", code, out.String())
	}
	actual := coverageEntries(t, path)
	expected := baselineRecords(t, dir)
	if !reflect.DeepEqual(actual, expected) {
		t.Fatalf("coverage mismatch\nactual=%+v\nexpected=%+v", actual, expected)
	}
}
func fakeKey() string {
	return strings.Join([]string{"-----BEGIN", "RSA", "PRIVATE", "KEY-----"}, " ") + "\n" + strings.Repeat("ABCDEFGH0123456789", 6) + "\n" + strings.Join([]string{"-----END", "RSA", "PRIVATE", "KEY-----"}, " ") + "\n"
}
func TestSecretsRetainMultilineAndRecordIsolation(t *testing.T) {
	// Synthetic rule tests the project's record transport, not provider regex details.
	t.Setenv("GITLEAKS_CONFIG_TOML", "")
	for _, split := range []bool{false, true} {
		t.Run(fmt.Sprint(split), func(t *testing.T) {
			dir, p := fixture(t)
			t.Setenv("GITLEAKS_CONFIG_TOML", `[[rules]]
id = "fixture-multiline"
regex = 'fixture-start\n[A-Z0-9]{80}\nfixture-end'
`)
			token := "fixture-start\n" + strings.Repeat("ABCD0123", 10) + "\nfixture-end\n"
			if split {
				cut := strings.Index(token, "\n") + 1
				commit(t, dir, "public root", token[:cut])
				commit(t, dir, token[cut:], "ordinary\n")
			} else {
				commit(t, dir, "public root", token)
				commit(t, dir, "delete", "ordinary\n")
			}
			code, out := invoke(t, dir, p, "HEAD")
			want := 1
			if split {
				want = 0
			}
			if code != want {
				t.Fatalf("split=%v code=%d %s", split, code, out)
			}
		})
	}
}

func TestPolicyAllowlistAndNormalization(t *testing.T) {
	dir, p := fixture(t)
	permitted := "published-example"
	if e := os.WriteFile(filepath.Join(dir, "tools/hooks/public-allow.txt"), []byte("# comment\n\n"+permitted+"\n"), 0600); e != nil {
		t.Fatal(e)
	}
	git(t, dir, "config", "public.deny", "blocked-fixture")
	t.Setenv("PUBLIC_ALLOW_EMAILS", "APPROVED@example.invalid")
	// Force a textual patch so the byte-normalization test includes a NUL.
	if e := os.WriteFile(filepath.Join(dir, ".gitattributes"), []byte("content.txt diff\n"), 0600); e != nil {
		t.Fatal(e)
	}
	commit(t, dir, "public message", permitted+" blocked-fixture hidden@example.invalid\n"+"approved@example.invalid\r\n\n")
	path := filepath.Join(dir, "coverage.jsonl")
	var out bytes.Buffer
	code := run(context.Background(), dir, []string{"--patterns", p, "--coverage", path, "range", "HEAD"}, &out)
	if code != 0 {
		t.Fatalf("%d %s", code, out.String())
	}
	rows := coverageEntries(t, path)
	want := []byte("approved@example.invalid\r\n")
	hash := sha256.Sum256(want)
	if rows[3].Bytes != int64(len(want)) || rows[3].Digest != hex.EncodeToString(hash[:]) {
		t.Fatalf("wrong normalized record: %+v", rows[3])
	}
	commit(t, dir, "ordinary", "blocked-fixture\n")
	code, s := invoke(t, dir, p, "HEAD^..HEAD")
	if code != 1 || !strings.Contains(s, "public.deny") {
		t.Fatalf("%d %s", code, s)
	}
}
func TestDeletedSecretWithDefaultScanner(t *testing.T) {
	dir, p := fixture(t)
	commit(t, dir, "root", "ordinary\n")
	base := git(t, dir, "rev-parse", "HEAD")
	commit(t, dir, "introduce", fakeKey())
	commit(t, dir, "delete", "ordinary\n")
	code, out := invoke(t, dir, p, base+"..HEAD")
	if code != 1 || !strings.Contains(out, "gitleaks secret") {
		t.Fatalf("%d %s", code, out)
	}
}
func TestScannerConfigurationAndIgnoreFailuresRefuse(t *testing.T) {
	dir, p := fixture(t)
	commit(t, dir, "root", "ordinary\n")
	t.Setenv("GITLEAKS_CONFIG_TOML", "this is not TOML")
	code, out := invoke(t, dir, p, "HEAD")
	if code != 2 || !strings.Contains(out, "incomplete") {
		t.Fatalf("%d %s", code, out)
	}
	t.Setenv("GITLEAKS_CONFIG_TOML", "")
	if e := os.Mkdir(filepath.Join(dir, ".gitleaksignore"), 0700); e != nil {
		t.Fatal(e)
	}
	code, out = invoke(t, dir, p, "HEAD")
	if code != 2 {
		t.Fatalf("ignore read failure: %d %s", code, out)
	}
}
func TestPartialGitOutputCannotPass(t *testing.T) {
	dir, p := fixture(t)
	commit(t, dir, "root", "ordinary\n")
	real, e := exec.LookPath("git")
	if e != nil {
		t.Fatal(e)
	}
	shims := t.TempDir()
	shim := filepath.Join(shims, "git")
	script := "#!/bin/sh\nif [ \"$1\" = log ]; then printf 'log size 100\\nshort'; exit 0; fi\nexec \"$REAL_GIT\" \"$@\"\n"
	if e = os.WriteFile(shim, []byte(script), 0700); e != nil {
		t.Fatal(e)
	}
	t.Setenv("REAL_GIT", real)
	t.Setenv("PATH", shims+string(os.PathListSeparator)+os.Getenv("PATH"))
	code, out := invoke(t, dir, p, "HEAD")
	if code != 2 || !strings.Contains(out, "incomplete") {
		t.Fatalf("truncated: %d %s", code, out)
	}
	script = "#!/bin/sh\nif [ \"$1\" = log ]; then \"$REAL_GIT\" \"$@\"; exit 7; fi\nexec \"$REAL_GIT\" \"$@\"\n"
	if e = os.WriteFile(shim, []byte(script), 0700); e != nil {
		t.Fatal(e)
	}
	code, out = invoke(t, dir, p, "HEAD")
	if code != 2 || !strings.Contains(out, "Git reader failed") {
		t.Fatalf("late failure: %d %s", code, out)
	}
}

func TestTextEmailStillRequiresAnExplicitEntry(t *testing.T) {
	dir, p := fixture(t)
	address := strings.Join([]string{"not-approved", "example.invalid"}, "@")
	commit(t, dir, "root", address+"\n")
	code, out := invoke(t, dir, p, "HEAD")
	if code != 1 || !strings.Contains(out, "text email") {
		t.Fatalf("%d %s", code, out)
	}
	t.Setenv("PUBLIC_ALLOW_EMAILS", strings.ToUpper(address))
	code, out = invoke(t, dir, p, "HEAD")
	if code != 0 {
		t.Fatalf("%d %s", code, out)
	}
}
func TestIncompleteSourceReadCannotPass(t *testing.T) {
	dir, _ := fixture(t)
	s, err := loadSecrets(dir)
	if err != nil {
		t.Fatal(err)
	}
	_, err = s.scan(context.Background(), io.MultiReader(strings.NewReader("ordinary"), failedRead{}))
	if err == nil {
		t.Fatal("a partial input read passed")
	}
}

type failedRead struct{}

func (failedRead) Read([]byte) (int, error) { return 0, errors.New("fixture read failure") }

func TestRecordLocalGitleaksIgnoreAndMalformedIgnore(t *testing.T) {
	dir, p := fixture(t)
	t.Setenv("GITLEAKS_CONFIG_TOML", `[[rules]]
id = "fixture-secret"
regex = 'fixture-token-[0-9]{8}'
`)
	commit(t, dir, "root", "fixture-token-01234567\n")
	if e := os.WriteFile(filepath.Join(dir, ".gitleaksignore"), []byte(":fixture-secret:1\n"), 0600); e != nil {
		t.Fatal(e)
	}
	code, out := invoke(t, dir, p, "HEAD")
	if code != 0 {
		t.Fatalf("record-local ignore: %d %s", code, out)
	}
	if e := os.WriteFile(filepath.Join(dir, ".gitleaksignore"), []byte(strings.Repeat("x", 70000)), 0600); e != nil {
		t.Fatal(e)
	}
	code, out = invoke(t, dir, p, "HEAD")
	if code != 2 {
		t.Fatalf("partial ignore read: %d %s", code, out)
	}
}

func TestHistoricalNULRefusesBeforeExemptionAndContinues(t *testing.T) {
	for _, exempt := range []bool{false, true} {
		t.Run(fmt.Sprint(exempt), func(t *testing.T) {
			dir, p := fixture(t)
			if err := os.WriteFile(filepath.Join(dir, ".gitattributes"), []byte("content.txt diff\n"), 0600); err != nil {
				t.Fatal(err)
			}
			if exempt {
				if err := os.WriteFile(filepath.Join(dir, "tools/hooks/public-allow.txt"), []byte("ordinary\n"), 0600); err != nil {
					t.Fatal(err)
				}
			}
			commit(t, dir, "root", "ordinary\x00more\n")
			last := commit(t, dir, "later message", "safe\n")
			path := filepath.Join(dir, "coverage.jsonl")
			var out bytes.Buffer
			code := run(context.Background(), dir, []string{"--patterns", p, "--coverage", path, "range", "HEAD"}, &out)
			if code != 1 || !strings.Contains(out.String(), "NUL byte") {
				t.Fatalf("%d %s", code, out.String())
			}
			var summary result
			lines := strings.Split(strings.TrimSpace(out.String()), "\n")
			if err := json.Unmarshal([]byte(lines[len(lines)-1]), &summary); err != nil {
				t.Fatal(err)
			}
			if !summary.Complete || summary.Commits != 2 {
				t.Fatalf("range shortened: %+v", summary)
			}
			rows := coverageEntries(t, path)
			if rows[0].SHA != last || len(rows) != 8 {
				t.Fatalf("missing coverage: %+v", rows)
			}
		})
	}
}
func TestOrdinaryBinaryFileDoesNotBecomeHistoricalText(t *testing.T) {
	dir, p := fixture(t)
	commit(t, dir, "root", "ordinary\x00binary\n")
	code, out := invoke(t, dir, p, "HEAD")
	if code != 0 {
		t.Fatalf("binary without textual patch: %d %s", code, out)
	}
}

func TestMessageNULRefusesAndConsumesFollowingCommit(t *testing.T) {
	dir, p := fixture(t)
	first := commit(t, dir, "first", "one\n")
	last := commit(t, dir, "last", "two\n")
	// Git's ordinary pretty formatter may stop at embedded NUL in a raw object.
	// This fixture tests bytes that actually enter the framed historical message interface.
	var stream bytes.Buffer
	for _, item := range []struct{ sha, msg string }{{last, "ordinary\x00message\n"}, {first, "following\n"}} {
		body := item.sha + "\npublic@users.noreply.github.com\npublic@users.noreply.github.com\n" + item.msg
		fmt.Fprintf(&stream, "log size %d\n%s\n", len(body), body)
	}
	path := filepath.Join(dir, "stream")
	if err := os.WriteFile(path, stream.Bytes(), 0600); err != nil {
		t.Fatal(err)
	}
	real, err := exec.LookPath("git")
	if err != nil {
		t.Fatal(err)
	}
	shims := t.TempDir()
	script := "#!/bin/sh\nif [ \"$1\" = log ]; then cat \"$STREAM\"; exit 0; fi\nexec \"$REAL_GIT\" \"$@\"\n"
	if err = os.WriteFile(filepath.Join(shims, "git"), []byte(script), 0700); err != nil {
		t.Fatal(err)
	}
	t.Setenv("STREAM", path)
	t.Setenv("REAL_GIT", real)
	t.Setenv("PATH", shims+string(os.PathListSeparator)+os.Getenv("PATH"))
	code, out := invoke(t, dir, p, "HEAD")
	if code != 1 || !strings.Contains(out, "message of "+last+": NUL byte") || !strings.Contains(out, `"commits":2`) {
		t.Fatalf("%d %s", code, out)
	}
}

func TestASCIIIdentityFoldingDoesNotApproveUnicode(t *testing.T) {
	dir, p := fixture(t)
	git(t, dir, "config", "public.allowEmail", "i@example.invalid")
	t.Setenv("GIT_AUTHOR_EMAIL", "I@example.invalid")
	commit(t, dir, "ASCII", "one\n")
	code, out := invoke(t, dir, p, "HEAD")
	if code != 0 {
		t.Fatalf("ASCII: %d %s", code, out)
	}
	t.Setenv("GIT_AUTHOR_EMAIL", "\u0130@example.invalid")
	commit(t, dir, "non-ASCII", "two\n")
	code, out = invoke(t, dir, p, "HEAD^..HEAD")
	if code != 1 || !strings.Contains(out, "author") {
		t.Fatalf("non-ASCII: %d %s", code, out)
	}
}
func TestMalformedRegexCannotLeakConfigOrPanic(t *testing.T) {
	dir, p := fixture(t)
	commit(t, dir, "root", "ordinary\n")
	marker := "CONFIG_MARKER_NOT_FOR_OUTPUT"
	t.Setenv("GITLEAKS_CONFIG_TOML", "[[rules]]\nid = 'fixture'\nregex = '["+marker+"'\n")
	code, out := invoke(t, dir, p, "HEAD")
	if code != 2 || strings.Contains(out, marker) || strings.Contains(out, "panic") || strings.Contains(out, "goroutine") {
		t.Fatalf("%d %s", code, out)
	}
}
func TestIgnoreSnapshotCannotChangeBetweenRecords(t *testing.T) {
	dir, _ := fixture(t)
	t.Setenv("GITLEAKS_CONFIG_TOML", `[[rules]]
id = "fixture-secret"
regex = 'fixture-token-[0-9]{8}'
`)
	path := filepath.Join(dir, ".gitleaksignore")
	if err := os.WriteFile(path, nil, 0600); err != nil {
		t.Fatal(err)
	}
	s, err := loadSecrets(dir)
	if err != nil {
		t.Fatal(err)
	}
	defer s.close()
	if err = os.WriteFile(path, []byte(":fixture-secret:1\n"+strings.Repeat("x", 70000)), 0600); err != nil {
		t.Fatal(err)
	}
	for i := 0; i < 2; i++ {
		found, err := s.scan(context.Background(), strings.NewReader("fixture-token-01234567\n"))
		if err != nil || !found {
			t.Fatalf("snapshot changed: found=%v err=%v", found, err)
		}
	}
}
func TestPartialFinalPatchLineCannotPass(t *testing.T) {
	dir, p := fixture(t)
	commit(t, dir, "root", "ordinary\n")
	real, err := exec.LookPath("git")
	if err != nil {
		t.Fatal(err)
	}
	shims := t.TempDir()
	script := "#!/bin/sh\nif [ \"$1\" = log ]; then \"$REAL_GIT\" \"$@\"; printf '+partial'; exit 0; fi\nexec \"$REAL_GIT\" \"$@\"\n"
	if err = os.WriteFile(filepath.Join(shims, "git"), []byte(script), 0700); err != nil {
		t.Fatal(err)
	}
	t.Setenv("REAL_GIT", real)
	t.Setenv("PATH", shims+string(os.PathListSeparator)+os.Getenv("PATH"))
	code, out := invoke(t, dir, p, "HEAD")
	if code != 2 || !strings.Contains(out, "truncated Git patch line") {
		t.Fatalf("%d %s", code, out)
	}
}

func shell(t *testing.T, dir string, input []byte, args ...string) (int, string) {
	t.Helper()
	path, err := filepath.Abs("../hooks/public-check")
	if err != nil {
		t.Fatal(err)
	}
	cmd := exec.Command(path, args...)
	cmd.Dir = dir
	cmd.Stdin = bytes.NewReader(input)
	out, err := cmd.CombinedOutput()
	if err == nil {
		return 0, string(out)
	}
	if e, ok := err.(*exec.ExitError); ok {
		return e.ExitCode(), string(out)
	}
	t.Fatal(err)
	return 2, ""
}
func TestContentEmailApprovalNeverApprovesIdentityOrOtherText(t *testing.T) {
	for _, suffix := range []string{"", " " + strings.Join([]string{"", "home", "fixture"}, "/"), " blocked-fixture", " " + fakeKey()} {
		t.Run(fmt.Sprintf("length-%d", len(suffix)), func(t *testing.T) {
			dir, p := fixture(t)
			git(t, dir, "config", "public.deny", "blocked-fixture")
			text := "approved@example.invalid" + suffix + "\n"
			commit(t, dir, "root", text)
			want := 0
			if suffix != "" {
				want = 1
			}
			goCode, out := invoke(t, dir, p, "HEAD")
			shCode, shOut := shell(t, dir, nil, "range", "HEAD")
			if goCode != want || shCode != want {
				t.Fatalf("want=%d go=%d shell=%d\n%s\n%s", want, goCode, shCode, out, shOut)
			}
		})
	}
	dir, p := fixture(t)
	t.Setenv("GIT_AUTHOR_EMAIL", "approved@example.invalid")
	commit(t, dir, "root", "ordinary\n")
	goCode, _ := invoke(t, dir, p, "HEAD")
	shCode, _ := shell(t, dir, nil, "range", "HEAD")
	if goCode != 1 || shCode != 1 {
		t.Fatalf("content approved identity: go=%d shell=%d", goCode, shCode)
	}
	// An unlisted address from generated fixture data must not inherit a domain exemption.
	dir, p = fixture(t)
	text := "approved@example.invalid " + filepath.Base(dir) + "@example.invalid\n"
	commit(t, dir, "root", text)
	goCode, _ = invoke(t, dir, p, "HEAD")
	shCode, _ = shell(t, dir, nil, "range", "HEAD")
	if goCode != 1 || shCode != 1 {
		t.Fatalf("unlisted address: go=%d shell=%d", goCode, shCode)
	}
}
func TestSharedPolicyFailuresAreIncompleteInBothCommands(t *testing.T) {
	for _, name := range []string{"public-content-emails.txt", "public-patterns.txt"} {
		for _, damage := range []string{"missing", "malformed", "directory", "empty", "blank-line"} {
			t.Run(name+"/"+damage, func(t *testing.T) {
				dir, p := fixture(t)
				commit(t, dir, "root", "ordinary\n")
				path := filepath.Join(dir, "tools/hooks", name)
				data, err := os.ReadFile(path)
				if err != nil {
					t.Fatal(err)
				}
				if err = os.Remove(path); err != nil {
					t.Fatal(err)
				}
				switch damage {
				case "malformed":
					err = os.WriteFile(path, []byte("not a valid policy\n"), 0600)
				case "directory":
					err = os.Mkdir(path, 0700)
				case "empty":
					err = os.WriteFile(path, nil, 0600)
				case "blank-line":
					err = os.WriteFile(path, append(data, '\n'), 0600)
				}
				if err != nil {
					t.Fatal(err)
				}
				goCode, out := invoke(t, dir, p, "HEAD")
				shCode, shOut := shell(t, dir, []byte("ordinary\n"), "text")
				if goCode != 2 || shCode != 2 {
					t.Fatalf("go=%d shell=%d\n%s\n%s", goCode, shCode, out, shOut)
				}
			})
		}
	}
}
func TestLocalModesKeepContentApprovalAndStagedIdentity(t *testing.T) {
	dir, _ := fixture(t)
	text := []byte("APPROVED@example.invalid\n")
	code, out := shell(t, dir, text, "text")
	if code != 0 {
		t.Fatalf("text %d %s", code, out)
	}
	msg := filepath.Join(dir, "message")
	if err := os.WriteFile(msg, append([]byte("# comment\n"), text...), 0600); err != nil {
		t.Fatal(err)
	}
	code, out = shell(t, dir, nil, "message", msg)
	if code != 0 {
		t.Fatalf("message %d %s", code, out)
	}
	if err := os.WriteFile(filepath.Join(dir, "content.txt"), text, 0600); err != nil {
		t.Fatal(err)
	}
	git(t, dir, "add", "content.txt")
	code, out = shell(t, dir, nil, "staged")
	if code != 0 {
		t.Fatalf("staged %d %s", code, out)
	}
	t.Setenv("GIT_AUTHOR_EMAIL", "approved@example.invalid")
	code, out = shell(t, dir, nil, "staged")
	if code != 1 {
		t.Fatalf("staged identity %d %s", code, out)
	}
}

func TestApprovedContentEmailKeepsEveryOtherCheck(t *testing.T) {
	cases := []struct{ name, text, category string }{
		{"IP", fmt.Sprintf("%d.%d.%d.%d", 10, 12, 34, 56), "private IP address"},
		{"tracker", strings.Join([]string{"app", "plane", "so/fixture"}, "."), "tracker URL"},
		{"private-key", fakeKey(), "private key"},
	}
	for _, tc := range cases {
		t.Run(tc.name, func(t *testing.T) {
			dir, p := fixture(t)
			commit(t, dir, "root", "approved@example.invalid "+tc.text+"\n")
			goCode, out := invoke(t, dir, p, "HEAD")
			shCode, shOut := shell(t, dir, nil, "range", "HEAD")
			if goCode != 1 || shCode != 1 || !strings.Contains(out, tc.category) || !strings.Contains(shOut, tc.category) {
				t.Fatalf("go=%d shell=%d\n%s\n%s", goCode, shCode, out, shOut)
			}
		})
	}
	dir, p := fixture(t)
	t.Setenv("GITLEAKS_CONFIG_TOML", `[[rules]]
id = "same-line-secret"
regex = 'fixture-token-[0-9]{8}'
`)
	commit(t, dir, "root", "approved@example.invalid fixture-token-01234567\n")
	goCode, out := invoke(t, dir, p, "HEAD")
	shCode, shOut := shell(t, dir, nil, "range", "HEAD")
	if goCode != 1 || shCode != 1 || !strings.Contains(out, "gitleaks") || !strings.Contains(shOut, "gitleaks") {
		t.Fatalf("go=%d shell=%d\n%s\n%s", goCode, shCode, out, shOut)
	}
}

func TestGitleaksAllowCommentDoesNotExemptOtherPolicyOrNeighbor(t *testing.T) {
	dir, p := fixture(t)
	t.Setenv("GITLEAKS_CONFIG_TOML", `[[rules]]
id = "annotation-boundary"
regex = 'fixture-token-[0-9]{8}'
`)
	annotation := "fixture-token-01234567 # gitleaks:allow"
	cases := []struct {
		suffix   string
		want     int
		category string
	}{
		{"", 0, ""},
		{"\nfixture-token-98765432", 1, "gitleaks"},
		{" " + strings.Join([]string{"", "home", "fixture"}, "/"), 1, "home path"},
		{" blocked-fixture", 1, "public.deny"},
		{" " + filepath.Base(dir) + "@example.invalid", 1, "email"},
	}
	for i, tc := range cases {
		git(t, dir, "config", "public.deny", "blocked-fixture")
		sha := commit(t, dir, fmt.Sprintf("boundary %d", i), annotation+tc.suffix+"\n")
		goCode, out := invoke(t, dir, p, sha+"^.."+sha)
		// First commit has no parent, so use its object as the selector.
		if i == 0 {
			goCode, out = invoke(t, dir, p, sha)
		}
		shCode, shOut := shell(t, dir, []byte(annotation+tc.suffix+"\n"), "text")
		if goCode != tc.want || shCode != tc.want || tc.category != "" && (!strings.Contains(out, tc.category) || !strings.Contains(shOut, tc.category)) {
			t.Fatalf("case%d go=%d shell=%d\n%s\n%s", i, goCode, shCode, out, shOut)
		}
	}
}

func TestRootGitleaksCPPPolicy(t *testing.T) {
	t.Setenv("GITLEAKS_CONFIG", "")
	t.Setenv("GITLEAKS_CONFIG_TOML", "")
	root, err := filepath.Abs("../..")
	if err != nil {
		t.Fatal(err)
	}
	defaults, err := loadSecrets(t.TempDir())
	if err != nil {
		t.Fatal(err)
	}
	defer defaults.close()
	policy, err := loadSecrets(root)
	if err != nil {
		t.Fatal(err)
	}
	defer policy.close()
	check := func(t *testing.T, text string, want bool) {
		t.Helper()
		baseline, err := defaults.scan(context.Background(), strings.NewReader(text+"\n"))
		if err != nil || !baseline {
			t.Fatalf("default control: found=%v err=%v", baseline, err)
		}
		found, err := policy.scan(context.Background(), strings.NewReader(text+"\n"))
		if err != nil || found != want {
			t.Errorf("root batch policy: want=%v found=%v err=%v", want, found, err)
		}
		code, out := shell(t, root, []byte(text+"\n"), "text")
		wantCode := 0
		if want {
			wantCode = 1
		}
		if code != wantCode || want && !strings.Contains(out, "gitleaks") {
			t.Errorf("root shell policy: want=%d code=%d %s", wantCode, code, out)
		}
	}
	// These six source expressions compare integer fields or declare typed map parameters.
	lines := []struct{ name, text string }{
		{"comparison", `        return key0.m_ucLowNibble == key1.m_ucLowNibble && key0.m_ucHighNibble == key1.m_ucHighNibble;`},
		{"handle-declaration", `    void Insert(S_00dc5970_Allocator& alloc, S_00dc5970_Handle key, S_00dc5970_Handle val) throw();  // insert`},
		{"handle-definition", `    void insert(S_00dc5970_Handle key, S_00dc5970_Handle val) throw()`},
		{"uint64", `    S_00db8670_Uint64 FindValueForKey(S_00db8670_Uint64 key, S_00db8670_Uint64 def) const throw()`},
		{"ulong-lookup", `    S_00db8670_Ulong LookupHashEntry(S_00db8670_Ulong key, S_00db8670_Ulong def) const throw();`},
		{"ulong-insert", `    void FUN_00cb1870(S_00db8670_Heap& alloc, S_00db8670_Ulong key, S_00db8670_Ulong value) throw();`},
	}
	// Synthetic assignments are assembled so the test source contains no credential fixture literal.
	assignments := []struct{ name, value string }{
		{"api_key", "7Q2w9E4r" + "8T1y6U3i" + "5O0p"},
		{"password", "9Z3x7C1v" + "5B0n8M2q" + "6W4e"},
		{"token", "4R8t2Y6u" + "0I3o7P1a" + "5S9d"},
	}
	for _, line := range lines {
		t.Run(line.name, func(t *testing.T) {
			check(t, line.text, false)
			for _, assignment := range assignments {
				text := "const char* " + assignment.name + " = \"" + assignment.value + "\";"
				t.Run(assignment.name, func(t *testing.T) {
					check(t, text+" "+line.text, true)
					check(t, line.text+" "+text, true)
				})
			}
		})
	}
	t.Run("altered-comparison", func(t *testing.T) {
		check(t, strings.Join([]string{"key0.m_ucLowNibble", "key2." + "m_ucLowNibble;"}, " == "), true)
	})
	t.Run("quoted-identifier-assignment", func(t *testing.T) {
		check(t, strings.Join([]string{"api_key", "\"S_00dc5970_Handle\";"}, " = "), true)
	})
}

func write(t *testing.T, dir, name, text string) {
	t.Helper()
	path := filepath.Join(dir, name)
	if e := os.MkdirAll(filepath.Dir(path), 0700); e != nil {
		t.Fatal(e)
	}
	if e := os.WriteFile(path, []byte(text), 0600); e != nil {
		t.Fatal(e)
	}
}
func symlink(t *testing.T, dir, target, name string) {
	t.Helper()
	if e := os.Symlink(target, filepath.Join(dir, name)); e != nil {
		t.Fatal(e)
	}
}

// The fixture base, outside the scanned range, holds a pack, a pack-named
// symlink and ordinary files, so changes to each can be scanned.
func TestDataPackNamesRefusedOnlyWhenAddedOrChanged(t *testing.T) {
	for _, tc := range []struct {
		name   string
		change func(t *testing.T, dir string)
		refuse bool
	}{
		{"add-in-folder-any-case", func(t *testing.T, dir string) { write(t, dir, "a/b/Data.PaCk", "pack\x00data") }, true},
		{"add-staged-any-case", func(t *testing.T, dir string) { write(t, dir, "Data.Pack.STAGED", "pack") }, true},
		{"add-symlink", func(t *testing.T, dir string) { symlink(t, dir, "ordinary.bin", "linked.pack") }, true},
		{"modify", func(t *testing.T, dir string) { write(t, dir, "old.pack", "changed") }, true},
		{"copy", func(t *testing.T, dir string) { write(t, dir, "c/copy.pack", "base pack\n") }, true},
		{"rename-to", func(t *testing.T, dir string) { git(t, dir, "mv", "ordinary.bin", "renamed.pack.staged") }, true},
		{"type-change-to-symlink", func(t *testing.T, dir string) {
			git(t, dir, "rm", "-q", "old.pack")
			symlink(t, dir, "ordinary.bin", "old.pack")
		}, true},
		{"type-change-from-symlink", func(t *testing.T, dir string) {
			git(t, dir, "rm", "-q", "link.pack")
			write(t, dir, "link.pack", "pack")
		}, true},
		{"packed", func(t *testing.T, dir string) { write(t, dir, "x/data.packed", "packed") }, false},
		{"other-suffix", func(t *testing.T, dir string) { write(t, dir, "data.pack.bak", "backup") }, false},
		{"folder-named-pack", func(t *testing.T, dir string) { write(t, dir, "d.pack/notes.txt", "notes") }, false},
		{"delete", func(t *testing.T, dir string) { git(t, dir, "rm", "-q", "old.pack", "link.pack") }, false},
		{"rename-away", func(t *testing.T, dir string) { git(t, dir, "mv", "old.pack", "moved.bin") }, false},
	} {
		t.Run(tc.name, func(t *testing.T) {
			dir, p := fixture(t)
			write(t, dir, "old.pack", "base pack\n")
			write(t, dir, "ordinary.bin", "ordinary\n")
			symlink(t, dir, "ordinary.bin", "link.pack")
			git(t, dir, "add", "-A")
			base := commit(t, dir, "base", "ordinary\n")
			tc.change(t, dir)
			git(t, dir, "add", "-A")
			change := commit(t, dir, "change", "ordinary\n")
			after := commit(t, dir, "after", "after\n")
			code, out := invoke(t, dir, p, base+"..HEAD")
			want, label := 0, "files of "+change+": data pack file"
			if tc.refuse {
				want = 1
			}
			if code != want || tc.refuse != strings.Contains(out, label) || strings.Contains(out, after) || strings.Contains(out, base) || !strings.Contains(out, `"complete":true`) {
				t.Fatalf("code %d: %s", code, out)
			}
		})
	}
}
func TestDataPackNamesInRootAndMerges(t *testing.T) {
	dir, p := fixture(t)
	write(t, dir, "root.pack", "pack")
	git(t, dir, "add", "-A")
	root := commit(t, dir, "root", "ordinary\n")
	git(t, dir, "rm", "-q", "root.pack")
	clean := commit(t, dir, "clean", "ordinary\n")
	git(t, dir, "checkout", "-q", "-b", "side")
	commit(t, dir, "side", "side\n")
	git(t, dir, "checkout", "-q", "master")
	git(t, dir, "merge", "-q", "--no-ff", "-m", "ordinary merge", "side")
	ordinary := git(t, dir, "rev-parse", "HEAD")
	git(t, dir, "checkout", "-q", "-b", "other", clean)
	write(t, dir, "other.txt", "other")
	git(t, dir, "add", "-A")
	git(t, dir, "commit", "-q", "-m", "other")
	git(t, dir, "checkout", "-q", "master")
	git(t, dir, "merge", "-q", "--no-ff", "--no-commit", "other")
	write(t, dir, "merged/Merge.PACK", "pack")
	git(t, dir, "add", "-A")
	git(t, dir, "commit", "-q", "-m", "merge adds a pack")
	merge := git(t, dir, "rev-parse", "HEAD")
	code, out := invoke(t, dir, p, "HEAD")
	if code != 1 || strings.Count(out, "data pack file") != 2 || !strings.Contains(out, "files of "+root+": data pack file") || !strings.Contains(out, "files of "+merge+": data pack file") {
		t.Fatalf("code %d: %s", code, out)
	}
	code, out = invoke(t, dir, p, root+".."+ordinary)
	if code != 0 {
		t.Fatalf("ordinary merge: %d %s", code, out)
	}
}
func TestPartialGitNameOutputCannotPass(t *testing.T) {
	dir, p := fixture(t)
	commit(t, dir, "root", "ordinary\n")
	commit(t, dir, "second", "second\n")
	real, err := exec.LookPath("git")
	if err != nil {
		t.Fatal(err)
	}
	shims := t.TempDir()
	t.Setenv("REAL_GIT", real)
	t.Setenv("PATH", shims+string(os.PathListSeparator)+os.Getenv("PATH"))
	for _, tc := range []struct{ name, script, want string }{
		{"missing-commit", "head -n 1 | \"$REAL_GIT\" \"$@\"; exit 0", "missing selected commit"},
		{"unframed", "\"$REAL_GIT\" \"$@\" >/dev/null; printf 'data.pack'; exit 0", "truncated Git name record"},
		{"failure", "\"$REAL_GIT\" \"$@\"; exit 7", "Git name reader failed"},
	} {
		t.Run(tc.name, func(t *testing.T) {
			script := "#!/bin/sh\nif [ \"$1\" = diff-tree ]; then " + tc.script + "; fi\nexec \"$REAL_GIT\" \"$@\"\n"
			if err = os.WriteFile(filepath.Join(shims, "git"), []byte(script), 0700); err != nil {
				t.Fatal(err)
			}
			code, out := invoke(t, dir, p, "HEAD")
			if code != 2 || !strings.Contains(out, tc.want) || !strings.Contains(out, `"complete":false`) {
				t.Fatalf("%d %s", code, out)
			}
		})
	}
}
