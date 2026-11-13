#!/usr/bin/env python3
"""Object proof of one unit: compile it three ways, then compare base and head.

usage:
  proof.py compile [--target NAME] [--source FILE] BUILD_DIR SOURCE OUT_PREFIX
  proof.py compare BASE_PREFIX HEAD_PREFIX [--map FILE] [OLD=NEW ...]
  proof.py warnings [--strip PREFIX ...] A.log B.log

compile runs the command that BUILD_DIR/compile_commands.json holds for
SOURCE (its path, or its last components such as src/fallout/misc/main.cpp;
--target picks the entry of CMakeFiles/NAME.dir when several match) three
times: as it is, with /Ob0 and with /Od /Gy. It writes OUT_PREFIX.VARIANT.obj
and OUT_PREFIX.VARIANT.log for the variants flags, ob0 and od, and logs the
entry and the three commands in OUT_PREFIX.commands.json. --source compiles
FILE's content at SOURCE's path, through a clang -vfsoverlay file
(OUT_PREFIX.vfs.json), without writing the export.

compare runs objcmp.py on each variant's objects, passing the renames on, and
compares each variant's warnings.

warnings compares the warnings of two compiler logs with their line and
column positions removed, and every PREFIX removed from the paths.

Exit status: 0 compiled, or identical and equal; 1 a compile failed, or an
object or the warnings differ; 2 usage error, unreadable input or a
compiler that cannot start.
"""
import collections
import json
import os
import re
import shlex
import subprocess
import sys

VARIANTS = (("flags", []), ("ob0", ["/Ob0"]), ("od", ["/Od", "/Gy"]))
# clang, clang-cl or clang++, with a version or a Windows extension.
CLANG = re.compile(r"clang(-cl|\+\+)?(-[0-9.]+)?(\.exe|\.cmd|\.bat)?")
CANARY = "proof.py canary: the source override took effect"
HERE = os.path.dirname(os.path.abspath(__file__))


def usage():
    print(__doc__.strip().split("\n\n")[1], file=sys.stderr)
    return 2


def entry_for(build_dir, source, target):
    with open(os.path.join(build_dir, "compile_commands.json"), encoding="utf-8") as f:
        entries = json.load(f)
    want = source.replace("\\", "/").strip("/")
    found = []
    for e in entries:
        path = e["file"].replace("\\", "/")
        if path == want or path.endswith("/" + want):
            output = e.get("output", "").replace("\\", "/")
            if target is None or ("CMakeFiles/%s.dir/" % target) in output:
                found.append(e)
    if len(found) != 1:
        print("proof.py: %d compile commands match %s%s" % (len(found), source,
              "" if target is None else " in target " + target), file=sys.stderr)
        for e in found:
            print("  " + e.get("output", e["file"]), file=sys.stderr)
        return None
    return found[0]


def entry_words(entry):
    return entry["arguments"] if "arguments" in entry else shlex.split(entry["command"])


def command_with(entry, obj, extra):
    words = [w for w in entry_words(entry) if not w.startswith(("/Fo", "-Fo"))]
    at = words.index("--") if "--" in words else len(words) - 1
    return words[:at] + extra + ["/Fo" + obj] + words[at:]


def compile_unit(args):
    options = {"--target": None, "--source": None}
    while len(args) >= 2 and args[0] in options:
        options[args[0]], args = args[1], args[2:]
    target, override = options["--target"], options["--source"]
    if len(args) != 3:
        return usage()
    build_dir, source, prefix = args
    try:
        entry = entry_for(build_dir, source, target)
    except (OSError, ValueError, KeyError) as error:
        print("proof.py: %s" % error, file=sys.stderr)
        return 2
    if entry is None:
        return 2
    if os.name == "nt" and "arguments" not in entry:
        print("proof.py: the compile command of %s is a string; on Windows only an arguments array is read"
              % source, file=sys.stderr)
        return 2
    prefix = os.path.abspath(prefix)
    for name, _ in VARIANTS:
        if os.path.exists("%s.%s.obj" % (prefix, name)):
            os.remove("%s.%s.obj" % (prefix, name))
    overlay = canary = None
    if override is not None:
        # The compiler reads the unit's path through a virtual file system that
        # maps it to the override: the export is never written.
        override, overlay = os.path.abspath(override), prefix + ".vfs.json"
        words = entry_words(entry)
        if not os.path.isfile(override):
            reason = "the source override %s is not a file" % override
        elif not CLANG.fullmatch(os.path.basename(words[0]).lower()):
            reason = "--source needs clang's -vfsoverlay; the compiler is %s" % words[0]
        elif entry["file"] not in words:
            reason = "the compile command does not name %s as the entry's file spells it" % entry["file"]
        else:
            reason = None
        if reason:
            print("proof.py: %s" % reason, file=sys.stderr)
            return 2
        # The overlay maps the path the compiler is given, as the entry's
        # directory resolves it.
        unit = os.path.join(entry["directory"], entry["file"])
        for path, contents in ((overlay, override), (prefix + ".canary.vfs.json", prefix + ".canary.cpp")):
            with open(path, "w", encoding="utf-8") as f:
                json.dump({"version": 0, "use-external-names": False, "roots": [{
                    "type": "file", "name": unit, "external-contents": contents}]}, f, indent=1)
        with open(prefix + ".canary.cpp", "w", encoding="utf-8") as f:
            f.write("#error %s\n" % CANARY)
        canary = command_with(entry, prefix + ".canary.obj", ["-vfsoverlay", prefix + ".canary.vfs.json"])
    commands = [(name, command_with(entry, "%s.%s.obj" % (prefix, name), extra + (
        ["-vfsoverlay", overlay] if overlay else []))) for name, extra in VARIANTS]
    with open(prefix + ".commands.json", "w", encoding="utf-8") as f:
        json.dump(dict(entry=entry, source=override, overlay=overlay, canary=canary, commands=dict(commands)), f,
                  indent=1)
    status = 0
    try:
        if canary:
            # The unit read as one #error line must fail with that error, or
            # the overlay does not reach the compiler.
            code = run(canary, prefix + ".canary.log", entry["directory"])
            with open(prefix + ".canary.log", encoding="utf-8", errors="replace") as f:
                if code == 0 or CANARY not in f.read():
                    print("proof.py: the overlay did not replace the unit (canary exit %d, see %s.canary.log)"
                          % (code, prefix), file=sys.stderr)
                    return 2
        for name, command in commands:
            log = "%s.%s.log" % (prefix, name)
            code = run(command, log, entry["directory"])
            print("%s: %s" % (name, "compiled" if code == 0 else "FAILED (exit %d), see %s" % (code, log)))
            if code != 0:
                status = 1
    except OSError as error:
        print("proof.py: cannot run the compile command: %s" % error, file=sys.stderr)
        return 2
    return status


def run(command, log, directory):
    with open(log, "wb") as out:
        return subprocess.call(command, cwd=directory, stdout=out, stderr=subprocess.STDOUT)


POSITION = re.compile(r"^(.*?)(?:\(\d+(?:,\d+)?\)|:\d+(?::\d+)?):\s*warning:")
CLASS = re.compile(r"\[(-W[^\],]+)")


def warning_lines(path, strip):
    lines = collections.Counter()
    with open(path, encoding="utf-8", errors="replace") as f:
        for line in f:
            if "warning:" not in line:
                continue
            line = line.rstrip("\r\n").replace("\\", "/")
            for prefix in strip:
                line = line.replace(prefix, "")
            lines[POSITION.sub(r"\1: warning:", line)] += 1
    return lines


def warning_class(line):
    match = CLASS.search(line)
    return match.group(1) if match else "(no class)"


def compare_warnings(path_a, path_b, strip, out):
    """Prints how the warnings differ; returns True when they are equal."""
    a, b = warning_lines(path_a, strip), warning_lines(path_b, strip)
    classes_a, classes_b = collections.Counter(), collections.Counter()
    for lines, classes in ((a, classes_a), (b, classes_b)):
        for line, count in lines.items():
            classes[warning_class(line)] += count
    if a == b:
        out("warnings equal: %d lines, %d classes" % (sum(a.values()), len(classes_a)))
        return True
    out("warnings differ: %d lines -> %d" % (sum(a.values()), sum(b.values())))
    for name in sorted(set(classes_a) | set(classes_b)):
        if classes_a[name] != classes_b[name]:
            out("\tclass\t%s\t%d -> %d" % (name, classes_a[name], classes_b[name]))
    for line, count in sorted((a - b).items()):
        out("\t-%d\t%s" % (count, line))
    for line, count in sorted((b - a).items()):
        out("\t+%d\t%s" % (count, line))
    return False


def warnings(args):
    strip = []
    while len(args) >= 2 and args[0] == "--strip":
        strip.append(args[1].replace("\\", "/"))
        args = args[2:]
    if len(args) != 2:
        return usage()
    try:
        return 0 if compare_warnings(args[0], args[1], strip, print) else 1
    except OSError as error:
        print("proof.py: %s" % error, file=sys.stderr)
        return 2


def compare(args):
    if len(args) < 2 or any(a.startswith("-") for a in args[:2]):
        return usage()
    base, head, renames = args[0], args[1], args[2:]
    status = 0
    for name, _ in VARIANTS:
        print("== %s" % name)
        sys.stdout.flush()
        code = subprocess.call([sys.executable, os.path.join(HERE, "objcmp.py"),
                                "%s.%s.obj" % (base, name), "%s.%s.obj" % (head, name)] + renames)
        if code == 2:
            return 2
        try:
            equal = compare_warnings("%s.%s.log" % (base, name), "%s.%s.log" % (head, name), [], print)
        except OSError as error:
            print("proof.py: %s" % error, file=sys.stderr)
            return 2
        if code != 0 or not equal:
            status = 1
    return status


def main(argv):
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(errors="backslashreplace")
    commands = {"compile": compile_unit, "compare": compare, "warnings": warnings}
    if not argv or argv[0] not in commands:
        return usage()
    return commands[argv[0]](argv[1:])


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
