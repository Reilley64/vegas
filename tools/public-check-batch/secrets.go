package main

import (
	"bufio"
	"context"
	"fmt"
	"io"
	"os"
	"path/filepath"
	"strings"

	"github.com/rs/zerolog"
	"github.com/spf13/viper"
	"github.com/zricethezav/gitleaks/v8/config"
	"github.com/zricethezav/gitleaks/v8/detect"
	"github.com/zricethezav/gitleaks/v8/sources"
)

type secrets struct {
	cfg    config.Config
	ignore string
}

func loadSecrets(dir string) (*secrets, error) {
	// The scanner never emits input or upstream configuration errors to logs.
	zerolog.SetGlobalLevel(zerolog.Disabled)
	viper.Reset()
	viper.SetConfigType("toml")
	var err error
	if path := os.Getenv("GITLEAKS_CONFIG"); path != "" {
		viper.SetConfigFile(path)
		err = viper.ReadInConfig()
	} else if text := os.Getenv("GITLEAKS_CONFIG_TOML"); text != "" {
		err = viper.ReadConfig(strings.NewReader(text))
	} else {
		data, e := os.ReadFile(filepath.Join(dir, ".gitleaks.toml"))
		if os.IsNotExist(e) {
			err = viper.ReadConfig(strings.NewReader(config.DefaultConfig))
		} else if e != nil {
			err = e
		} else {
			err = viper.ReadConfig(strings.NewReader(string(data)))
		}
	}
	if err != nil {
		return nil, fmt.Errorf("cannot load gitleaks configuration")
	}
	var vc config.ViperConfig
	if err = viper.Unmarshal(&vc); err != nil {
		return nil, fmt.Errorf("invalid gitleaks configuration")
	}
	cfg, err := translateConfig(&vc)
	if err != nil {
		return nil, fmt.Errorf("invalid gitleaks configuration")
	}
	cfg.Path = ".gitleaks.toml"
	ignore := filepath.Join(dir, ".gitleaksignore")
	var snapshot string
	f, err := os.Open(ignore)
	if os.IsNotExist(err) {
		return &secrets{cfg: cfg}, nil
	}
	if err != nil {
		return nil, fmt.Errorf("cannot read gitleaks ignore file")
	}
	defer f.Close()
	info, err := f.Stat()
	if err != nil || !info.Mode().IsRegular() {
		return nil, fmt.Errorf("cannot read gitleaks ignore file")
	}
	copy, err := os.CreateTemp("", "public-check-ignore-")
	if err != nil {
		return nil, fmt.Errorf("cannot snapshot gitleaks ignore file")
	}
	snapshot = copy.Name()
	ok := false
	defer func() {
		if !ok {
			_ = os.Remove(snapshot)
		}
	}()
	_, readErr := io.Copy(copy, f)
	closeErr := copy.Close()
	if readErr != nil || closeErr != nil {
		return nil, fmt.Errorf("cannot snapshot gitleaks ignore file")
	}
	check, err := os.Open(snapshot)
	if err != nil {
		return nil, fmt.Errorf("cannot validate gitleaks ignore snapshot")
	}
	scan := bufio.NewScanner(check)
	for scan.Scan() {
	}
	err = scan.Err()
	closeErr = check.Close()
	if err != nil || closeErr != nil {
		return nil, fmt.Errorf("cannot validate gitleaks ignore snapshot")
	}
	ok = true
	return &secrets{cfg: cfg, ignore: snapshot}, nil
}

func (s *secrets) close() {
	if s.ignore != "" {
		_ = os.Remove(s.ignore)
	}
}

func translateConfig(vc *config.ViperConfig) (cfg config.Config, err error) {
	defer func() {
		if recover() != nil {
			cfg = config.Config{}
			err = fmt.Errorf("invalid gitleaks configuration")
		}
	}()
	return vc.Translate()
}

func (s *secrets) scan(ctx context.Context, r io.Reader) (bool, error) {
	d := detect.NewDetector(s.cfg)
	d.MaxDecodeDepth = 5
	d.Redact = 100
	if s.ignore != "" {
		if err := d.AddGitleaksIgnore(s.ignore); err != nil {
			return false, fmt.Errorf("cannot load gitleaks ignore file")
		}
	}
	source := sources.File{Content: r}
	err := source.Fragments(ctx, func(f sources.Fragment, err error) error {
		if err != nil {
			return err
		}
		if err = ctx.Err(); err != nil {
			return err
		}
		for _, finding := range d.DetectContext(ctx, detect.Fragment(f)) {
			d.AddFinding(finding)
		}
		return nil
	})
	if err != nil {
		return false, fmt.Errorf("gitleaks input scan failed")
	}
	if err = ctx.Err(); err != nil {
		return false, err
	}
	return len(d.Findings()) > 0, nil
}
