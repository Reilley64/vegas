package main

import (
	"context"
	"encoding/json"
	"flag"
	"fmt"
	"io"
	"os"
	"os/signal"
	"syscall"
)

func main() {
	ctx, cancel := signal.NotifyContext(context.Background(), os.Interrupt, syscall.SIGTERM)
	defer cancel()
	dir, err := os.Getwd()
	if err != nil {
		os.Exit(2)
	}
	os.Exit(run(ctx, dir, os.Args[1:], os.Stderr))
}
func run(ctx context.Context, dir string, args []string, out io.Writer) int {
	flags := flag.NewFlagSet("public-check-batch", flag.ContinueOnError)
	flags.SetOutput(io.Discard)
	patterns := flags.String("patterns", "", "generated policy pattern file")
	coveragePath := flags.String("coverage", "", "private JSONL record digests")
	if err := flags.Parse(args); err != nil || *patterns == "" || flags.NArg() < 2 || flags.Arg(0) != "range" {
		fmt.Fprintln(out, "usage: public-check-batch --patterns FILE [--coverage FILE] range REVS...")
		return 2
	}
	root, err := rootDir(ctx, dir)
	if err != nil {
		fmt.Fprintln(out, "public-check-batch: incomplete:", err)
		return 2
	}
	p, err := loadPolicy(ctx, dir, root, *patterns)
	if err != nil {
		fmt.Fprintln(out, "public-check-batch: incomplete:", err)
		return 2
	}
	leaks, err := loadSecrets(dir)
	if err != nil {
		fmt.Fprintln(out, "public-check-batch: incomplete:", err)
		return 2
	}
	defer leaks.close()
	temp, err := os.MkdirTemp("", "public-check-batch-")
	if err != nil {
		fmt.Fprintln(out, "public-check-batch: incomplete: cannot create private workspace")
		return 2
	}
	defer os.RemoveAll(temp)
	spool, err := os.CreateTemp(temp, "record-")
	if err != nil {
		fmt.Fprintln(out, "public-check-batch: incomplete: cannot create record")
		return 2
	}
	defer spool.Close()
	s := scanner{policy: p, secrets: leaks, spool: spool}
	s.report = func(label, category string) {
		s.result.Refused = true
		fmt.Fprintf(out, "public-check-batch: %s: %s\n", label, category)
	}
	if *coveragePath != "" {
		f, e := os.OpenFile(*coveragePath, os.O_WRONLY|os.O_CREATE|os.O_EXCL, 0600)
		if e != nil {
			fmt.Fprintln(out, "public-check-batch: incomplete: cannot create coverage file")
			return 2
		}
		defer f.Close()
		s.coverage = f
	}
	err = s.scanRange(ctx, dir, temp, flags.Args()[1:])
	_ = json.NewEncoder(out).Encode(s.result)
	if err != nil {
		fmt.Fprintln(out, "public-check-batch: incomplete:", err)
		return 2
	}
	if s.result.Refused {
		return 1
	}
	return 0
}
