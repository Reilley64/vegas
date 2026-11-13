#!/usr/bin/env python3
"""Tests of startup_map.py: python3 test_startup_map.py"""
import copy
import io
import json
import os
import shutil
import sys
import tempfile
import unittest

sys.dont_write_bytecode = True  # leave no cache in the source folder
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import startup_map  # noqa: E402

SHA = "0123456789abcdef0123456789abcdef01234567"


def node(node_id, state="accepted", tier="source", kind="contract", group=None, **extra):
    item = {"id": node_id, "label": "Node " + node_id, "kind": kind, "state": state, "tier": tier,
            "source": "docs/example.md", "group": group}
    item.update(extra)
    return item


def edge(start, end, kind="requires", provenance="measured", basis_kind="source", **extra):
    item = {"from": start, "to": end, "kind": kind, "provenance": provenance,
            "basis": {"kind": basis_kind, "ref": "docs/example.md"}}
    item.update(extra)
    return item


def valid():
    return {
        "snapshot": {"source_commit": SHA, "evidence_date": "2026-11-13", "ticket_states_date": "2026-11-13"},
        "overview": [{"id": "ga", "label": "Group a"}, {"id": "gb", "label": "Group b"}],
        "nodes": [
            node("a", group="ga"),
            node("b", state="waiting", group="gb"),
            node("c", state="ready", tier="curated", kind="ticket", vegas="VEGAS-1", tracker_state="Needs triage"),
        ],
        "edges": [
            edge("b", "a"),
            edge("c", "b", kind="blocks", provenance="curated"),
            edge("a", "b", kind="calls"),
            edge("c", "a", kind="estimated-unlock", provenance="modelled", basis_kind="model",
                 estimate={"value": 12, "unit": "closure names", "basis": "a single-name model count"}),
        ],
        "measurements": [{"label": "Forced link", "value": "1", "command": "forced cell", "commit": "891a44f50",
                          "date": "2026-11-13", "tier": "forced-link"}],
        "coverage": ["Everything in the example."],
        "limitations": ["Nothing is proved."],
    }


class Validation(unittest.TestCase):
    def problems(self, data):
        return startup_map.validate(data)

    def assertRefused(self, data, words):
        found = self.problems(data)
        self.assertTrue(any(words in problem for problem in found), (words, found))

    def test_valid_input_passes(self):
        self.assertEqual(self.problems(valid()), [])

    def test_checked_in_map_passes(self):
        data, found = startup_map.load(os.path.join(startup_map.HERE, "map.json"))
        self.assertEqual(found, [])
        self.assertIsNotNone(data)

    def test_dangling_edge_is_refused(self):
        data = valid()
        data["edges"].append(edge("a", "missing"))
        self.assertRefused(data, "names the unknown node missing")

    def test_unsupported_values_are_refused(self):
        cases = [
            (("nodes", 0, "state"), "done", "unsupported state done"),
            (("nodes", 0, "tier"), "runtime", "unsupported tier runtime"),
            (("nodes", 0, "kind"), "lane", "unsupported kind lane"),
            (("edges", 0, "kind"), "depends", "unsupported kind depends"),
            (("edges", 0, "provenance"), "guessed", "unsupported provenance guessed"),
            (("measurements", 0, "tier"), "estimate", "unsupported tier estimate"),
        ]
        for (group, index, key), value, words in cases:
            data = valid()
            data[group][index][key] = value
            self.assertRefused(data, words)

    def test_unknown_field_is_refused(self):
        data = valid()
        data["nodes"][0]["colour"] = "red"
        self.assertRefused(data, "unsupported field colour")

    def test_requires_cycle_is_refused(self):
        data = valid()
        data["edges"].append(edge("a", "b"))
        self.assertRefused(data, "form a cycle")

    def test_cycle_through_requires_and_blocks_is_refused(self):
        data = valid()
        # b requires a, and b blocks a: a needs b needs a.
        data["edges"].append(edge("b", "a", kind="blocks"))
        self.assertRefused(data, "form a cycle")

    def test_calls_may_cycle(self):
        data = valid()
        data["edges"].append(edge("b", "a", kind="calls"))
        self.assertEqual(self.problems(data), [])

    def test_estimate_needs_its_number_and_basis(self):
        data = valid()
        del data["edges"][3]["estimate"]
        self.assertRefused(data, "lacks estimate")
        data = valid()
        del data["edges"][3]["estimate"]["basis"]
        self.assertRefused(data, "estimate lacks basis")
        data = valid()
        data["edges"][3]["estimate"]["value"] = 0
        self.assertRefused(data, "not a positive whole number")

    def test_estimate_cites_a_model_only(self):
        data = valid()
        data["edges"][3]["basis"]["kind"] = "link"
        self.assertRefused(data, "unsupported kind link")
        data = valid()
        data["edges"][0]["basis"]["kind"] = "model"
        self.assertRefused(data, "unsupported kind model")

    def test_estimate_is_modelled_and_only_an_estimate_is(self):
        for provenance in ("measured", "curated"):
            data = valid()
            data["edges"][3]["provenance"] = provenance
            self.assertRefused(data, "is an estimate whose provenance is not modelled")
        data = valid()
        data["edges"][0]["provenance"] = "modelled"
        self.assertRefused(data, "is modelled but is not an estimated-unlock edge")

    def test_estimate_text_never_says_measured(self):
        data = valid()
        data["edges"][3]["estimate"]["basis"] = "a count measured by a model"
        self.assertRefused(data, "is an estimate that uses the word measured")

    def test_duplicate_edge_is_refused(self):
        data = valid()
        data["edges"].append(edge("b", "a"))
        self.assertRefused(data, "edge 5 (b requires a) is given twice")
        data = valid()
        data["edges"].append(edge("b", "a", kind="calls"))
        self.assertEqual(self.problems(data), [])

    def test_estimate_on_another_kind_is_refused(self):
        data = valid()
        data["edges"][0]["estimate"] = {"value": 1, "unit": "names", "basis": "x"}
        self.assertRefused(data, "carries an estimate")

    def test_provenance_is_required(self):
        data = valid()
        del data["edges"][1]["provenance"]
        self.assertRefused(data, "lacks provenance")

    def test_ready_node_with_an_unfinished_prerequisite_is_refused(self):
        data = valid()
        data["nodes"][1]["state"] = "ready"
        data["nodes"][0]["state"] = "waiting"
        self.assertRefused(data, "node b is ready but needs a")

    def test_startup_step_must_be_accepted(self):
        data = valid()
        data["nodes"][0]["kind"] = "startup-step"
        data["nodes"][0]["state"] = "blocked"
        self.assertRefused(data, "not accepted")

    def test_ticket_needs_a_key(self):
        data = valid()
        del data["nodes"][2]["vegas"]
        self.assertRefused(data, "ticket without a VEGAS key")
        data = valid()
        data["nodes"][2]["vegas"] = "OTHER-1"
        self.assertRefused(data, "not VEGAS-<number>")

    def test_tracker_state_gives_the_state(self):
        data = valid()
        data["nodes"][2]["tracker_state"] = "In progress"
        self.assertRefused(data, "node c has the tracker state In progress, which gives in-progress, but is ready")
        data["nodes"][2]["state"] = "in-progress"
        self.assertEqual(self.problems(data), [])
        data["nodes"][2]["tracker_state"] = "Done"
        self.assertRefused(data, "which gives accepted, but is in-progress")

    def test_open_tracker_state_gives_ready_or_waiting_by_the_edges(self):
        data = valid()
        data["nodes"].append(node("d", state="ready", tier="curated", vegas="VEGAS-2", tracker_state="Ready for agent"))
        data["edges"].append(edge("d", "b"))
        self.assertRefused(data, "node d has the tracker state Ready for agent, which gives waiting, but is ready")
        data["nodes"][3]["state"] = "waiting"
        self.assertEqual(self.problems(data), [])
        data["edges"].pop()
        self.assertRefused(data, "which gives ready, but is waiting")

    def test_curated_edge_makes_an_open_ticket_wait(self):
        data = valid()
        data["nodes"].append(node("d", state="ready", tier="curated", vegas="VEGAS-2", tracker_state="Needs triage"))
        data["edges"].append(edge("d", "b", provenance="curated"))
        self.assertRefused(data, "node d has the tracker state Needs triage, which gives waiting, but is ready")

    def test_gate_takes_no_tracker_state(self):
        data = valid()
        data["nodes"].append(node("g", state="blocked", kind="gate", vegas="VEGAS-2"))
        data["edges"].append(edge("g", "b"))
        self.assertEqual(self.problems(data), [])
        data["nodes"][3].update(state="in-progress", tracker_state="In progress")
        self.assertRefused(data, "node g is a gate with a tracker state")

    def test_unsupported_tracker_state_is_refused(self):
        data = valid()
        data["nodes"][2]["tracker_state"] = "Won't fix"
        self.assertRefused(data, "unsupported tracker state Won't fix")

    def test_tracker_state_needs_a_key(self):
        data = valid()
        data["nodes"][0]["tracker_state"] = "Done"
        self.assertRefused(data, "has a tracker state but no VEGAS key")

    def test_ticket_needs_a_tracker_state(self):
        data = valid()
        del data["nodes"][2]["tracker_state"]
        self.assertRefused(data, "ticket without a tracker state")

    def test_repository_node_shows_only_repository_states(self):
        for state in ("ready", "in-progress", "in-review"):
            data = valid()
            data["nodes"][1]["state"] = state
            self.assertRefused(data, "node b is " + state + " without a tracker state")

    def test_label_that_breaks_mermaid_is_refused(self):
        data = valid()
        data["nodes"][0]["label"] = 'say "hi"'
        self.assertRefused(data, "character the map does not allow")

    def test_label_that_starts_a_mermaid_list_is_refused(self):
        for label in ("1. Memory start-up", "12) Timer", "- dash", "+ plus", "* star", "# hash"):
            data = valid()
            data["nodes"][0]["label"] = label
            self.assertRefused(data, "starts like a Mermaid list item or heading")
        for label in ("Step 1: Memory start-up", "1.5 seconds", "S2 to S5"):
            data = valid()
            data["nodes"][0]["label"] = label
            self.assertEqual(self.problems(data), [], label)

    def test_snapshot_needs_a_full_commit(self):
        data = valid()
        data["snapshot"]["source_commit"] = "891a44f50"
        self.assertRefused(data, "not a full commit id")


class Forbidden(unittest.TestCase):
    def test_each_pattern_is_refused(self):
        samples = {
            "a URL": "see https" + "://example.org/x",
            "a tracker host": "app.plane" + ".so",
            "a home path": "/" + "Users/" + "someone/x",
            "a temporary path": "/" + "tmp/" + "evidence",
            "a uuid-like id": "01234567-89ab-cdef-0123-456789abcdef",
            "a home path in short form": "~" + "/notes",
            "an e-mail address": "someone" + "@" + "example.org",
            "an IPv4 address": "192.0.2" + ".10",
        }
        names = {"a home path in short form": "a home path"}
        for name, text in samples.items():
            self.assertEqual(startup_map.forbidden(text), ["the input contains " + names.get(name, name)], name)

    def test_load_refuses_forbidden_text_anywhere(self):
        data = valid()
        data["nodes"][0]["detail"] = "evidence in /" + "tmp/" + "x"
        folder = tempfile.mkdtemp()
        try:
            path = os.path.join(folder, "map.json")
            with open(path, "w", encoding="utf-8") as handle:
                json.dump(data, handle)
            _, found = startup_map.load(path)
            self.assertIn("the input contains a temporary path", found)
        finally:
            shutil.rmtree(folder)

    def test_ordinary_text_passes(self):
        self.assertEqual(startup_map.forbidden("Windows CI run 43375323383 at 11d59dc97; docs/setup.md"), [])
        self.assertEqual(startup_map.forbidden("version 1.4.0.525 at 0x0086a850, 300.1.2.3"), [])


class Rendering(unittest.TestCase):
    def test_curated_edges_and_nodes_are_dashed(self):
        text = startup_map.mermaid(valid())
        self.assertIn('c -. "blocks" .-> b', text)
        self.assertIn("a --> b", text)
        self.assertIn("class c curated", text)
        self.assertIn("classDef curated stroke-dasharray", text)

    def test_curated_requires_is_dashed(self):
        data = valid()
        data["edges"][0]["provenance"] = "curated"
        self.assertIn("a -.-> b", startup_map.mermaid(data))

    def test_estimate_is_labelled_an_estimate(self):
        data = valid()
        self.assertIn('c -. "estimate of 12 closure names" .-> a', startup_map.mermaid(data))
        self.assertIn("| c | estimated-unlock | a | estimate of 12 closure names", startup_map.doc(data))

    def test_estimate_row_is_modelled_and_never_measured(self):
        rows = [line for line in startup_map.doc(valid()).splitlines() if line.startswith("| c | estimated-unlock |")]
        self.assertEqual(len(rows), 1)
        self.assertIn("modelled, model: ", rows[0])
        self.assertNotIn("measured", rows[0])

    def test_curated_edge_prints_no_basis_kind(self):
        page = startup_map.doc(valid())
        self.assertIn("| c | blocks | b | curated: docs/example.md |", page)
        self.assertIn("| b | requires | a | measured, source: docs/example.md |", page)

    def test_legend(self):
        data = valid()
        page, block = startup_map.doc(data), startup_map.readme_block(data)
        arrows = ("An unlabelled arrow points from what is needed to what needs it. A `blocks` arrow starts at the "
                  "blocker, a `calls` arrow at the caller and an `estimate` arrow at the work.")
        self.assertIn(arrows, page)
        self.assertIn("distinct kinds of evidence", page)
        self.assertIn("An arrow points from what is needed to what needs it.", block)
        for text in (page, block):
            for word in ("weakest", "strongest"):
                self.assertNotIn(word, text)
        self.assertIn("An edge is `measured`, with the kind of report it cites, `curated` or `modelled`.", page)
        self.assertIn("| in-progress | Its ticket is in progress in the tracker. The snapshot commit does not have "
                      "all of its work. |", page)
        tiers = [tier for tier, _ in startup_map.TIERS]
        self.assertEqual(tiers.index("forced-link"), tiers.index("source") + 1)
        self.assertLess(tiers.index("forced-link"), tiers.index("lazy-link"))

    def test_state_is_text_and_class(self):
        text = startup_map.mermaid(valid())
        self.assertIn('b["Node b<br/>WAITING, source"]', text)
        self.assertIn("class b waiting", text)

    def test_state_source_is_shown(self):
        data = valid()
        self.assertIn('c["Node c<br/>READY, curated, VEGAS-1 Needs triage"]', startup_map.mermaid(data))
        page = startup_map.doc(data)
        self.assertIn("| c | Node c | ready | tracker, Needs triage | curated | VEGAS-1 |", page)
        self.assertIn("| b | Node b | waiting | repository | source |  |", page)
        self.assertIn("| Needs triage | It is `ready`, or `waiting` when a measured or curated", page)
        self.assertIn("A gate always takes its state from\nthe repository, and its ticket is a reference only.", page)
        self.assertIn("Needs info and Ready for human map as Needs triage and Ready for agent do.", page)

    def test_output_is_deterministic(self):
        data = valid()
        self.assertEqual(startup_map.doc(data), startup_map.doc(copy.deepcopy(data)))
        self.assertEqual(startup_map.readme_block(data), startup_map.readme_block(copy.deepcopy(data)))

    def test_splice_needs_one_marker_pair(self):
        block = startup_map.readme_block(valid())
        self.assertRaises(ValueError, startup_map.splice, "# title\n", block)
        twice = startup_map.BEGIN + startup_map.END + startup_map.BEGIN + startup_map.END
        self.assertRaises(ValueError, startup_map.splice, twice, block)
        spliced = startup_map.splice("# t\n" + startup_map.BEGIN + "old" + startup_map.END + "\ntail\n", block)
        self.assertEqual(spliced, "# t\n" + block + "\ntail\n")


class Overview(unittest.TestCase):
    def assertRefused(self, data, words):
        found = startup_map.validate(data)
        self.assertTrue(any(words in problem for problem in found), (words, found))

    def test_every_node_names_a_group_or_none(self):
        data = valid()
        del data["nodes"][0]["group"]
        self.assertRefused(data, "node a lacks group")

    def test_unknown_group_is_refused(self):
        data = valid()
        data["nodes"][0]["group"] = "missing"
        self.assertRefused(data, "node a names the unknown overview group missing")

    def test_group_without_a_node_is_refused(self):
        data = valid()
        data["overview"].append({"id": "gc", "label": "Group c"})
        self.assertRefused(data, "overview group gc has no node")

    def test_group_whose_nodes_differ_in_state_is_refused(self):
        data = valid()
        data["nodes"][1]["group"] = "ga"
        self.assertRefused(data, "overview group ga mixes the states accepted, waiting")

    def test_group_fields_and_ids(self):
        data = valid()
        data["overview"][0]["colour"] = "red"
        self.assertRefused(data, "overview group ga has the unsupported field colour")
        data = valid()
        del data["overview"][0]["label"]
        self.assertRefused(data, "overview group ga lacks label")
        data = valid()
        data["overview"][1]["id"] = "ga"
        self.assertRefused(data, "overview group ga is defined twice")
        data = valid()
        data["overview"][0]["id"] = "Group A"
        self.assertRefused(data, "has an id that is not lower case letters")
        data = valid()
        del data["overview"]
        self.assertRefused(data, "the input lacks overview")

    def test_group_label_follows_the_label_rules(self):
        data = valid()
        data["overview"][0]["label"] = 'say "hi"'
        self.assertRefused(data, "overview group ga label has a character the map does not allow")
        data = valid()
        data["overview"][0]["label"] = "1. First"
        self.assertRefused(data, "overview group ga label starts like a Mermaid list item or heading")

    def test_overview_arrows_cycle_is_refused(self):
        data = valid()
        data["overview"] = [{"id": "g1", "label": "One"}, {"id": "g2", "label": "Two"}]
        data["nodes"] = [node("p", "waiting", group="g1"), node("q", "waiting", group="g1"),
                         node("r", "waiting", group="g2"), node("s", "waiting", group="g2")]
        data["edges"] = [edge("r", "p"), edge("q", "s")]
        self.assertRefused(data, "the overview's arrows form a cycle")

    def test_overview_boxes_and_arrows(self):
        text = startup_map.overview_mermaid(valid())
        lines = text.splitlines()
        self.assertEqual(lines[:4], ["```mermaid", "flowchart TB", '  ga["Group a<br/>ACCEPTED"]',
                                     '  gb["Group b<br/>WAITING"]'])
        self.assertIn("  ga --> gb", lines)
        self.assertIn("  class ga accepted", lines)
        self.assertIn("  class gb waiting", lines)
        # c is left out, and calls and estimates are not drawn.
        self.assertNotIn("c[", text)
        self.assertNotIn("calls", text)
        self.assertNotIn("estimate", text)
        self.assertNotIn("subgraph", text)

    def test_overview_arrow_is_dashed_only_when_every_edge_behind_it_is_curated(self):
        data = valid()
        data["edges"][0]["provenance"] = "curated"
        self.assertIn("  ga -.-> gb", startup_map.overview_mermaid(data).splitlines())
        data["nodes"].append(node("d", "waiting", group="gb"))
        data["edges"].append(edge("d", "a"))
        lines = startup_map.overview_mermaid(data).splitlines()
        self.assertIn("  ga --> gb", lines)
        self.assertNotIn("  ga -.-> gb", lines)

    def test_overview_box_is_dashed_when_every_node_is_curated(self):
        data = valid()
        data["nodes"][2]["group"] = "gc"
        data["overview"].append({"id": "gc", "label": "Group c"})
        # ga holds a curated node and one that is not, so only gc is dashed.
        data["nodes"].append(node("d", tier="curated", group="ga"))
        self.assertEqual(startup_map.validate(data), [])
        lines = startup_map.overview_mermaid(data).splitlines()
        self.assertEqual([line for line in lines if line.endswith(" curated") and "class " in line], ["  class gc curated"])
        self.assertNotIn("curated", startup_map.overview_mermaid(valid()))

    def test_readme_shows_the_overview_and_the_page_the_full_diagram(self):
        data = valid()
        block, page = startup_map.readme_block(data), startup_map.doc(data)
        self.assertIn(startup_map.overview_mermaid(data), block)
        self.assertNotIn(startup_map.mermaid(data), block)
        self.assertIn(startup_map.mermaid(data), page)
        self.assertIn("| ga | Group a | accepted | a |", page)
        self.assertIn("| gb | Group b | waiting | b |", page)
        self.assertIn("Left out of the overview: `c`.", page)


class Check(unittest.TestCase):
    def setUp(self):
        self.folder = tempfile.mkdtemp()
        self.input = os.path.join(self.folder, "map.json")
        self.readme = os.path.join(self.folder, "README.md")
        self.doc = os.path.join(self.folder, "map.md")
        with open(self.input, "w", encoding="utf-8") as handle:
            json.dump(valid(), handle)
        with open(self.readme, "w", encoding="utf-8") as handle:
            handle.write("# t\n\n" + startup_map.BEGIN + "\n" + startup_map.END + "\n")
        self.args = ["--input", self.input, "--readme", self.readme, "--doc", self.doc]

    def tearDown(self):
        shutil.rmtree(self.folder)

    def run_quietly(self, args):
        stdout = sys.stdout
        sys.stdout = open(os.devnull, "w")
        try:
            return startup_map.main(args)
        finally:
            sys.stdout.close()
            sys.stdout = stdout

    def test_check_fails_until_generated(self):
        self.assertEqual(self.run_quietly(self.args + ["--check"]), 1)
        self.assertFalse(os.path.exists(self.doc))
        self.assertEqual(self.run_quietly(self.args), 0)
        self.assertEqual(self.run_quietly(self.args + ["--check"]), 0)

    def test_check_names_a_file_on_another_drive(self):
        def other_drive(path, start):
            raise ValueError("path is on mount 'C:', start on mount 'D:'")

        relpath = os.path.relpath
        os.path.relpath = other_drive
        try:
            self.assertEqual(self.run_quietly(self.args + ["--check"]), 1)
        finally:
            os.path.relpath = relpath

    def test_check_fails_on_a_hand_edit(self):
        self.run_quietly(self.args)
        with open(self.doc, "a", encoding="utf-8") as handle:
            handle.write("edited\n")
        self.assertEqual(self.run_quietly(self.args + ["--check"]), 1)

    def test_check_fails_on_a_hand_edit_of_the_readme_overview(self):
        self.run_quietly(self.args)
        with open(self.readme, encoding="utf-8") as handle:
            text = handle.read()
        self.assertIn("Group a<br/>", text)
        with open(self.readme, "w", encoding="utf-8") as handle:
            handle.write(text.replace("Group a<br/>", "Group A<br/>"))
        self.assertEqual(self.run_quietly(self.args + ["--check"]), 1)

    def test_check_accepts_crlf_line_ends(self):
        self.run_quietly(self.args)
        for path in (self.readme, self.doc):
            with open(path, encoding="utf-8") as handle:
                text = handle.read()
            with open(path, "w", encoding="utf-8", newline="") as handle:
                handle.write(text.replace("\n", "\r\n"))
        self.assertEqual(self.run_quietly(self.args + ["--check"]), 0)

    def test_missing_input_is_one_line_and_status_2(self):
        os.remove(self.input)
        stdout, sys.stdout = sys.stdout, io.StringIO()
        try:
            status = startup_map.main(self.args)
            printed = sys.stdout.getvalue()
        finally:
            sys.stdout = stdout
        self.assertEqual(status, 2)
        self.assertEqual(len(printed.splitlines()), 1, printed)
        self.assertTrue(printed.startswith("cannot read the input "), printed)
        self.assertFalse(os.path.exists(self.doc))

    def test_invalid_input_writes_nothing(self):
        data = valid()
        data["edges"].append(edge("a", "missing"))
        with open(self.input, "w", encoding="utf-8") as handle:
            json.dump(data, handle)
        self.assertEqual(self.run_quietly(self.args), 1)
        self.assertFalse(os.path.exists(self.doc))


if __name__ == "__main__":
    unittest.main()
