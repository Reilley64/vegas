# Public-check range scanner

CI builds this command once. Local staged, message, text and pre-push range hooks continue to use Bash and the gitleaks CLI, with no Go build requirement.

```text
go test -race ./...
go vet ./...
go mod verify
go build -trimpath -o public-check-batch .
```

The module pins gitleaks 8.30.1 and requires Go 1.24.11 or newer. CI selects Go 1.27.2.

Invoke from the repository being scanned:

```text
public-check-batch --patterns tools/hooks/public-patterns.txt range BASE..HEAD
```

The shell and range scanner read the same patterns and `tools/hooks/public-content-emails.txt`. The latter approves only entire extracted text-email tokens after ASCII case folding. It does not approve raw author/committer identities or remove surrounding text from any other check. Existing content substring exemptions remain separate and are not expanded for test fixtures. Missing, unreadable or malformed shared policy data fails closed.

The scanner checks every selected commit's raw author/committer emails, message and historical added text. It refuses historical NUL before content exemptions and continues the range. Ordinary binary-file summaries without added text do not trigger that rule. This is explicit policy, not emulation of platform-dependent grep binary summaries.

The scanner also refuses a selected commit that adds, changes, copies, renames to or changes the type of a data pack file (VEGAS-13): a file named `*.pack` or `*.pack.staged`, in any folder and any ASCII letter case (Git's `icase` folds only ASCII), including a symlink. Git matches the names through `git diff-tree` pathspecs, without rename detection, so a rename shows as a deletion and an addition. Deleting a pack, renaming one away and `*.packed` are not refused. A merge is checked by its combined diff. The diagnostic names the commit, not the file.

Each message and added-text record gets an isolated pinned gitleaks stdin reader with empty path/commit metadata. Rules compile once, ignores use a checked private snapshot and no detector state crosses record boundaries. The complete range is never concatenated for secret scanning.

Exit 0 means complete and clear, 1 means complete with policy refusals, and 2 means operationally incomplete. The JSON summary states completion. Diagnostics name a commit/category without private payloads. Ordinary refusals do not shorten history coverage.

Optional `--coverage PRIVATE_NEW_FILE` writes per-record SHA, kind, length and digest with mode 0600. Keep it private. The file must not exist. The command spools one normalized record and one selected-commit manifest, not the full history, but Git and unusually large records can consume substantial memory. A measured 1 GiB representative process-tree target is not a universal bound or runtime cap.

Tests cover actual project policy and stream failures, including deleted secrets, messages, both identities, root/merge extraction, isolated multiline inputs, shared email boundaries and partial producer/scanner failures. They are not an exhaustive test suite for gitleaks provider rules. The shell range command retains its pre-existing invalid-selector producer masking; the new Go command rejects invalid selectors. No history, timeout or range-coverage shortcut is part of this change.
