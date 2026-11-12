#!/usr/bin/env python3
"""Write the committed form of a scan: the family tables as Markdown and three TSV files.
usage: scan_tables.py SCAN_DIR OUT_DIR   -> OUT_DIR/families.md.part, members.tsv, same-address.tsv,
   other-manglings.tsv, unmeasured.md.part"""
import csv, os, sys
scan, out = sys.argv[1], sys.argv[2]
os.makedirs(out, exist_ok=True)
def rows(name):
    with open(os.path.join(scan, name)) as fh:
        return list(csv.DictReader(fh, delimiter="\t", quoting=csv.QUOTE_NONE))
def first(names):
    ks = names.split(" ")
    return "`%s`" % ks[0] + (" and %d more" % (len(ks) - 1) if len(ks) > 1 else "")
CLASS = {"interior of a declared aggregate": "aggregate", "type or size disagreement": "disagreement"}
with open(os.path.join(out, "families.md.part"), "w") as fh:
    fh.write("| Container | Name | Extent | Class | Names inside | Units | State |\n| --- | --- | ---: | --- | ---: | ---: | --- |\n")
    for r in rows("families.tsv"):
        extent = r["extent_high"] if r["basis"] != "indexed past its definition" else "indexed"
        if r["basis"] not in ("32-bit object", "type", "indexed past its definition"):
            extent += " at most"
        bound = " at most" if r["note"].startswith("upper bound") else ""
        fh.write("| `%s` | %s | %s | %s | %s%s | %s | %s |\n" % (
            r["container"], first(r["name"]), extent, CLASS[r["class"]], r["members"], bound, r["units"], r["state"]))
with open(os.path.join(out, "unmeasured.md.part"), "w") as fh:
    fh.write("| Container | Name | Kind | Extent between | Names in the uncertain part |\n| --- | --- | --- | --- | ---: |\n")
    for r in rows("unknown.tsv"):
        fh.write("| `%s` | %s | %s | %s and %s | %s |\n" % (r["container"], first(r["name"]), r["kind"], r["extent_low"], r["extent_high"], r["names_in_uncertain_part"]))
with open(os.path.join(out, "members.tsv"), "w") as fh:
    fh.write("container\taddress\toffset\tnames\tkind\tunits\taccesses\n")
    for r in rows("members.tsv"):
        fh.write("\t".join(r[k] for k in ("container", "address", "offset", "names", "kind", "units", "accesses")) + "\n")
with open(os.path.join(out, "other-manglings.tsv"), "w") as fh:
    fh.write("address\tsymbol\tunits\n")
    for r in rows("other_manglings.tsv"):
        fh.write("\t".join(r[k] for k in ("address", "symbol", "units")) + "\n")
with open(os.path.join(out, "same-address.tsv"), "w") as fh:
    fh.write("address\tclass\tunits\tdefined\tsymbols\n")
    for r in rows("two_names.tsv"):
        fh.write("\t".join(r[k] for k in ("address", "class", "units", "defined", "symbols")) + "\n")
