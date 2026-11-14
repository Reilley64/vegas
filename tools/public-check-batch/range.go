package main

import (
	"bufio"
	"bytes"
	"context"
	"crypto/sha256"
	"encoding/hex"
	"encoding/json"
	"fmt"
	"io"
	"os"
	"os/exec"
	"strconv"
	"strings"
)

type coverage struct {
	SHA    string `json:"sha"`
	Kind   string `json:"kind"`
	Bytes  int64  `json:"bytes"`
	Digest string `json:"sha256"`
}
type result struct {
	Commits  int64 `json:"commits"`
	Records  int64 `json:"records"`
	Bytes    int64 `json:"bytes"`
	Complete bool  `json:"complete"`
	Refused  bool  `json:"refused"`
}
type scanner struct {
	policy   *policy
	secrets  *secrets
	spool    *os.File
	coverage io.Writer
	report   func(string, string)
	result   result
}

func (s *scanner) record(ctx context.Context, sha, kind string, r io.Reader) error {
	size, err := s.policy.normalize(r, s.spool, kind+" of "+sha, s.report)
	if err != nil {
		return fmt.Errorf("record normalization failed")
	}
	hash := sha256.New()
	if _, err = io.Copy(hash, s.spool); err != nil {
		return fmt.Errorf("record digest failed")
	}
	if s.coverage != nil {
		if err = json.NewEncoder(s.coverage).Encode(coverage{sha, kind, size, hex.EncodeToString(hash.Sum(nil))}); err != nil {
			return fmt.Errorf("coverage write failed")
		}
	}
	if _, err = s.spool.Seek(0, 0); err != nil {
		return fmt.Errorf("record seek failed")
	}
	if size > 0 {
		found, err := s.secrets.scan(ctx, s.spool)
		if err != nil {
			return err
		}
		if found {
			s.report(kind+" of "+sha, "gitleaks secret")
		}
	}
	s.result.Records++
	s.result.Bytes += size
	return nil
}
func command(ctx context.Context, dir string, args ...string) *exec.Cmd {
	c := exec.CommandContext(ctx, "git", args...)
	c.Dir = dir
	return c
}
func rootDir(ctx context.Context, dir string) (string, error) {
	data, err := command(ctx, dir, "rev-parse", "--show-toplevel").Output()
	if err != nil {
		return "", fmt.Errorf("cannot resolve repository")
	}
	return strings.TrimRight(string(data), "\n"), nil
}
func (s *scanner) scanRange(ctx context.Context, dir, temp string, revs []string) error {
	manifest, err := os.CreateTemp(temp, "commits-")
	if err != nil {
		return fmt.Errorf("range workspace I/O failed")
	}
	defer manifest.Close()
	selectCmd := command(ctx, dir, append([]string{"rev-list"}, revs...)...)
	selectCmd.Stdout = manifest
	if err = selectCmd.Run(); err != nil {
		return fmt.Errorf("Git selection failed")
	}
	info, err := manifest.Stat()
	if err != nil {
		return fmt.Errorf("range workspace I/O failed")
	}
	if info.Size() == 0 {
		s.result.Complete = true
		return nil
	}
	if _, err = manifest.Seek(0, 0); err != nil {
		return fmt.Errorf("range workspace I/O failed")
	}
	// Two independent file readers avoid bidirectional pipe stalls and an in-memory ID list.
	expected, err := os.Open(manifest.Name())
	if err != nil {
		return fmt.Errorf("range workspace I/O failed")
	}
	defer expected.Close()
	ids := bufio.NewReader(expected)
	cmd := command(ctx, dir, "log", "--no-walk=unsorted", "--stdin", "--log-size", "--format=%H%n%ae%n%ce%n%B", "--root", "--cc", "-p", "-U0", "--no-color", "--no-ext-diff")
	cmd.Stdin = manifest
	stdout, err := cmd.StdoutPipe()
	if err != nil {
		return fmt.Errorf("range workspace I/O failed")
	}
	if err = cmd.Start(); err != nil {
		return fmt.Errorf("cannot start Git reader")
	}
	parseErr := s.parse(ctx, bufio.NewReader(stdout), ids)
	if parseErr != nil {
		_ = cmd.Process.Kill()
	}
	waitErr := cmd.Wait()
	if parseErr != nil {
		return parseErr
	}
	if waitErr != nil {
		return fmt.Errorf("Git reader failed")
	}
	if err = s.scanPacks(ctx, dir, manifest.Name()); err != nil {
		return err
	}
	s.result.Complete = true
	return nil
}

// A data pack, installed or staged, holds data of the original release, so no
// commit adds one, in any folder and in any letter case (VEGAS-13). Git matches
// the names. A deletion or a rename away from such a name is not refused.
var packPathspecs = []string{":(glob,icase)**/*.pack", ":(glob,icase)**/*.pack.staged"}

func (s *scanner) scanPacks(ctx context.Context, dir, manifest string) error {
	input, err := os.Open(manifest)
	if err != nil {
		return fmt.Errorf("range workspace I/O failed")
	}
	defer input.Close()
	expected, err := os.Open(manifest)
	if err != nil {
		return fmt.Errorf("range workspace I/O failed")
	}
	defer expected.Close()
	ids := bufio.NewReader(expected)
	nextID := func() string { id, _ := ids.ReadString('\n'); return strings.TrimSuffix(id, "\n") }
	// --always names every selected commit, so a missing one is detected. A pack
	// name ends in .pack or .pack.staged and so never equals a commit name.
	cmd := command(ctx, dir, append([]string{"diff-tree", "--stdin", "-r", "--root", "--cc", "--always", "--name-only", "-z", "--diff-filter=ACMRT", "--"}, packPathspecs...)...)
	cmd.Stdin = input
	stdout, err := cmd.StdoutPipe()
	if err != nil {
		return fmt.Errorf("range workspace I/O failed")
	}
	if err = cmd.Start(); err != nil {
		return fmt.Errorf("cannot start Git name reader")
	}
	parseErr := func() error {
		r := bufio.NewReader(stdout)
		current, next := "", nextID()
		for {
			field, e := r.ReadString(0)
			if e == io.EOF && field == "" {
				if next != "" {
					return fmt.Errorf("missing selected commit")
				}
				return nil
			}
			if e != nil {
				return fmt.Errorf("truncated Git name record")
			}
			field = strings.TrimSuffix(field, "\x00")
			switch {
			case field == next:
				current, next = field, nextID()
			case current == "":
				return fmt.Errorf("unexpected selected commit")
			default:
				s.report("files of "+current, "data pack file")
			}
		}
	}()
	if parseErr != nil {
		_ = cmd.Process.Kill()
	}
	waitErr := cmd.Wait()
	if parseErr != nil {
		return parseErr
	}
	if waitErr != nil {
		return fmt.Errorf("Git name reader failed")
	}
	return nil
}
func readLine(r *bufio.Reader) ([]byte, error) { return r.ReadBytes('\n') }
func (s *scanner) parse(ctx context.Context, r, ids *bufio.Reader) error {
	var header []byte
	for {
		if err := ctx.Err(); err != nil {
			return err
		}
		if header == nil {
			for {
				line, err := readLine(r)
				if err == io.EOF && len(line) == 0 {
					id, e := ids.ReadBytes('\n')
					if e != io.EOF || len(id) > 0 {
						return fmt.Errorf("missing selected commit")
					}
					return nil
				}
				if err != nil {
					return fmt.Errorf("truncated Git stream")
				}
				if bytes.Equal(line, []byte{'\n'}) {
					continue
				}
				header = line
				break
			}
		}
		if !bytes.HasPrefix(header, []byte("log size ")) {
			return fmt.Errorf("invalid Git record header")
		}
		n, err := strconv.ParseInt(strings.TrimSuffix(string(header[9:]), "\n"), 10, 64)
		if err != nil || n < 0 {
			return fmt.Errorf("invalid Git record length")
		}
		metadata := &io.LimitedReader{R: r, N: n}
		mr := bufio.NewReader(metadata)
		fields := make([]string, 3)
		for i := range fields {
			line, e := mr.ReadBytes('\n')
			if e != nil {
				return fmt.Errorf("truncated Git metadata")
			}
			fields[i] = string(bytes.TrimSuffix(line, []byte{'\n'}))
		}
		id, e := ids.ReadBytes('\n')
		if e != nil || strings.TrimSuffix(string(id), "\n") != fields[0] {
			return fmt.Errorf("unexpected selected commit")
		}
		sha := fields[0]
		s.policy.ident("author of "+sha, fields[1], s.report)
		s.policy.ident("committer of "+sha, fields[2], s.report)
		if s.coverage != nil {
			for i, kind := range []string{"author", "committer"} {
				h := sha256.Sum256([]byte(fields[i+1]))
				if err = json.NewEncoder(s.coverage).Encode(coverage{sha, kind, int64(len(fields[i+1])), hex.EncodeToString(h[:])}); err != nil {
					return fmt.Errorf("coverage write failed")
				}
			}
		}
		if err = s.record(ctx, sha, "message", mr); err != nil {
			return err
		}
		if metadata.N != 0 {
			return fmt.Errorf("truncated Git message")
		}
		// Read only added lines into the record spool through a bounded pipe.
		pr, pw := io.Pipe()
		done := make(chan error, 1)
		go func() { err := s.record(ctx, sha, "added", pr); _ = pr.CloseWithError(err); done <- err }()
		header = nil
		var patchErr error
		for {
			line, e := readLine(r)
			if len(line) > 0 && line[len(line)-1] != '\n' {
				patchErr = fmt.Errorf("truncated Git patch line")
				break
			}
			if len(line) > 0 {
				if bytes.HasPrefix(line, []byte("log size ")) {
					header = line
					break
				}
				if line[0] == '+' && !bytes.HasPrefix(line, []byte("+++ ")) {
					if _, patchErr = pw.Write(line[1:]); patchErr != nil {
						break
					}
				}
			}
			if e == io.EOF {
				break
			}
			if e != nil {
				patchErr = fmt.Errorf("Git patch read failed")
				break
			}
		}
		_ = pw.CloseWithError(patchErr)
		recordErr := <-done
		if patchErr != nil {
			return patchErr
		}
		if recordErr != nil {
			return recordErr
		}
		s.result.Commits++
	}
}
