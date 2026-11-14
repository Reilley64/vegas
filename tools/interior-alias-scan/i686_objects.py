#!/usr/bin/env python3
"""Compile every game unit of a windows-x64 build tree once more for 32-bit, one section per global (/Gw), so that
the size of each definition in the recipe's 32-bit address space can be read from its section.
usage: i686_objects.py BUILD_DIR OUT_DIR JOBS   (objects are written under OUT_DIR/CMakeFiles/game.dir)
Only the target, the optimization level and the output path of each recorded compile command change."""
import json, os, shlex, subprocess, sys
from multiprocessing.pool import ThreadPool
build, out, jobs = sys.argv[1], sys.argv[2], int(sys.argv[3])
os.makedirs(out, exist_ok=True)
cc = [c for c in json.load(open(os.path.join(build, "compile_commands.json"))) if "/FoCMakeFiles/game.dir/" in c["command"]]
def run(c):
    args = shlex.split(c["command"].replace("--target=x86_64-pc-windows-msvc", "--target=i686-pc-windows-msvc"))
    args = [a for a in args if not a.startswith(("-Werror=", "/Fd")) and a not in ("/O2", "/Ob2")]
    obj = None
    for i, a in enumerate(args):
        if a.startswith("/Fo"):
            obj = os.path.join(out, a[3:])
            args[i] = "/Fo" + obj
    os.makedirs(os.path.dirname(obj), exist_ok=True)
    args[1:1] = ["/Od", "/Gw", "-w"]
    r = subprocess.run(args, capture_output=True, text=True, cwd=c["directory"])
    return c["file"], r.returncode, r.stderr[-2000:]
failed = 0
with ThreadPool(jobs) as pool, open(os.path.join(out, "compile.log"), "w") as log:
    for f, rc, err in pool.imap_unordered(run, cc):
        if rc:
            failed += 1
            log.write("FAILED %s\n%s\n" % (f, err))
    log.write("units %d failed %d\n" % (len(cc), failed))
print("units", len(cc), "failed", failed)
