# Startup map generator

`startup_map.py` reads `map.json` and writes two files: the Mermaid diagram
between the `startup-map` markers in the repository's `README.md`, and the
whole of `docs/startup-map.md`. The map runs from the pack that setup
prepares, through the accepted steps of `main`, to the statements of
`WinMain` that `main` skips, the boot bodies and the contracts and gates that
hold them. It is a derived view. The tracker holds tickets and rulings, the
documents under `docs/` hold code relationships, and git and CI hold
accepted commits and checks.

It needs Python 3 and no other package.

```text
python3 tools/startup-map/startup_map.py            # write README.md and docs/startup-map.md
python3 tools/startup-map/startup_map.py --check    # write nothing; exit 1 if either differs
python3 tools/startup-map/test_startup_map.py       # the generator's tests
```

The output depends only on `map.json`. Nodes and edges keep their order in
the file, and the only date and commit are the snapshot's.

## Where it runs

CTest runs the tests as `docs.startup_map.generator` on every host, the
Windows CI job's included. When configuring does not find Python 3, it warns,
and CTest still registers `docs.startup_map.generator`, which then fails with
that reason.

## The input

`map.json` has:

- `snapshot`: the full id of the measured commit, the evidence date and the
  date of the tracker's ticket states;
- `nodes`: `id`, `label`, `kind`, `state`, `tier`, `source`, and optionally
  `vegas`, `tracker_state` and `detail`;
- `edges`: `from`, `to`, `kind`, `provenance`, `basis` (`kind` and `ref`),
  and `estimate` (`value`, `unit`, `basis`) on estimated-unlock edges only;
- `measurements`, `coverage` and `limitations`, which the page lists.

The closed sets of kinds, states, tiers, edge kinds, provenances and basis
kinds are in `startup_map.py`, and `docs/startup-map.md` explains each. The
tiers name distinct kinds of evidence and are not a scale. A `requires` edge
reads "`from` needs `to`", and a `blocks` edge reads "`from` holds `to`".

An edge's provenance is `measured`, `curated` or `modelled`. Every
estimated-unlock edge is `modelled`, and no other edge is. The page prints a
curated edge's reference after the word `curated` and leaves out its basis
kind.

A node's state has one source. A node with `tracker_state` takes it from the
tracker. Its `tracker_state` is the state its `vegas` ticket had on the
ticket-state date, and `TRACKER_STATES` in `startup_map.py` maps it to the
map's state. Give a node `tracker_state` only when the ticket's work is the
node's work. A ticket that a node only belongs to, such as VEGAS-30 for the
boot bodies, stays in `vegas` alone. Every other node takes its state from
the repository at the snapshot commit, as `accepted`, `waiting`, `blocked` or
`unknown`. A gate always does, and its `vegas` key is a reference only.

Refresh the snapshot by hand. Read the ticket states from the tracker, the
CI run with `gh run view`, and the counts from a measurement of the new
commit, then edit `map.json`, set `snapshot`, and run the generator. Cite
documents, commits, CI run ids, test names and dated ticket comments. Never
cite a local path, a host, an address or a tracker link, because the
generator refuses an input that holds one.

## What the generator checks

The generator writes nothing when the input has a problem, and prints one
line for each. It refuses:

- a field outside the schema, or a required field missing;
- a kind, state, tier, edge kind, provenance or basis kind outside its set;
- an edge to a node that does not exist, or to its own source;
- the same edge twice, with the same `from`, `kind` and `to`;
- a cycle through `requires` and `blocks` edges, followed from what needs to
  what is needed (`calls` edges may form cycles);
- an estimated-unlock edge without a positive whole number, a unit and a
  basis, whose basis is not `model`, whose provenance is not `modelled`, or
  whose text uses the word "measured"; an estimate on another kind of edge;
  a `modelled` edge of another kind;
- a `ready` or `accepted` node that needs a node that is not `accepted`;
- a node whose state differs from the one its tracker state gives, a tracker
  state outside the set or without a `vegas` key, a gate with a tracker
  state, a ticket without a tracker state, and a node without a tracker
  state whose state is `ready`, `in-progress` or `in-review`;
- a startup step of `main` that is not `accepted`, or a ticket without a
  `VEGAS-` key;
- a label with a character that Mermaid would read as syntax, and a label
  that starts like a Markdown list item or heading, such as `1. ` or `- `;
- anywhere in the file, a URL, the tracker's host, a home path (`~/`
  included), a temporary path, an e-mail address, an IPv4 address or a
  uuid-like id.

When the generator cannot read the input file, it prints one line and exits
with status 2.

Every edge must name its provenance. The diagram dashes curated edges and
nodes with the `curated` tier, and it dashes estimates and labels them
`estimate`.

## What the generator does not check

- Whether a node, edge or source reference is true. A wrong reference passes.
- Whether the snapshot is current. The input does not change when the
  tracker, CI or the code does.
- Whether GitHub renders the diagram. The tests check the text the
  generator writes, not a rendering.
