# Project instructions

## Scoped guides

Prime Agent does not load descendant guides from a repository-root session.
Before scoped work, read the literal path that applies:

| Work | Read |
| --- | --- |
| GitHub workflows, composite actions or automation YAML | `.github/AGENTS.md` |
| A new CTest check | `tests/checks/README.md` |

## Agent skills

### Issue tracker

Issues live in Plane Cloud, in the workspace that `git config plane.workspace` names, reached through the Plane MCP server. See `docs/agents/issue-tracker.md`.

### Triage labels

The five triage roles are Plane states, not labels: set the state instead of applying a label. See `docs/agents/triage-labels.md`.

### Domain docs

Single-context: one `GLOSSARY.md` at the repo root. ADRs are Plane pages under Architecture decisions. See `docs/agents/domain.md`.

## Workflow

Work moves through these skills in order. Start at the step that matches what you were given:

1. `/grill-with-docs`: shape an idea or feature with the user.
2. `/to-spec`: turn the shared understanding into a spec.
3. `/to-tickets`: break the spec into tickets with blocking links.
4. `/implement-spec`: build the whole spec and its tickets on one integration branch.
5. `/code-review`: review the work against the coding standards and the spec.
6. `/retro`: suggest improvements to the agent environment from the session.

## Public repository

This repository is public and mirrored. Nothing in it may point to a contributor's machines, accounts or private services.

- Commits, pull request titles and bodies, comments and files never contain host or machine names, IP addresses, absolute paths into a home folder, personal email addresses, tracker URLs or credentials.
- Refer to work items by key only, such as `VEGAS-11`, never by link. Tracker workspace and project ids come from `git config plane.workspace` and `git config plane.project`.
- Scripts that generate source never copy tool output into it, such as compiler messages, file paths or timestamps.
- Never commit the original game's files, data extracted from them, saves, or scripts for a contributor's test machines.
- The hooks in `tools/hooks/` enforce this. Turn them on once per clone with `git config core.hooksPath tools/hooks`, and keep personal words to refuse in `git config --global --add public.deny <word>`. Never pass `--no-verify`.
- Push only branches and tags. Never push with `--all` or `--mirror`.
