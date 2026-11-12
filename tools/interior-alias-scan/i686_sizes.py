#!/usr/bin/env python3
"""Sizes of the data definitions of 32-bit objects built with one section per global.
usage: i686_sizes.py OBJ_ROOT OUT_JSONL JOBS   -> one line per object: {"object", "defs": symbol -> [section, value, size]}"""
import json, os, sys
from multiprocessing import Pool
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import scan_objects
if __name__ == "__main__":
    root, out, jobs = sys.argv[1], sys.argv[2], int(sys.argv[3])
    objs = sorted(os.path.join(r, f) for r, _, fs in os.walk(root) for f in fs if f.endswith(".obj"))
    with Pool(jobs) as pool, open(out, "w") as fh:
        for obj, defs in zip(objs, pool.imap(scan_objects.symbols, objs, chunksize=8)):
            fh.write(json.dumps({"object": os.path.relpath(obj, root), "defs": defs}) + "\n")
    print("objects:", len(objs))
