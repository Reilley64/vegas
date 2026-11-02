# Project instructions

## Scoped guides

Prime Agent does not load descendant guides from a repository-root session.
Before scoped work, read the literal path that applies:

| Work | Read |
| --- | --- |
| GitHub workflows, composite actions or automation YAML | `.github/AGENTS.md` |

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
