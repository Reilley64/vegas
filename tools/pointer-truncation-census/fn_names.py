#!/usr/bin/env python3
"""Qualified name of the function that encloses each census place, from libclang.

usage: fn_names.py GAME_COMMANDS_JSON FN_SITES_TSV OUT_TSV JOBS

FN_SITES_TSV rows: unit, file, line, column (of the start of the function), as parse.py writes them.
OUT_TSV rows: file, line, column, qualified name. Needs the clang Python bindings on PYTHONPATH;
LIBCLANG names the libclang library file when it is not found by default.
"""
import json, multiprocessing, os, shlex, sys
from clang import cindex

K = cindex.CursorKind
FN = {K.FUNCTION_DECL, K.CXX_METHOD, K.CONSTRUCTOR, K.DESTRUCTOR, K.FUNCTION_TEMPLATE, K.CONVERSION_FUNCTION}
SCOPE = {K.NAMESPACE, K.CLASS_DECL, K.STRUCT_DECL, K.UNION_DECL, K.CLASS_TEMPLATE, K.CLASS_TEMPLATE_PARTIAL_SPECIALIZATION}


def qualified(c):
    parts = []
    while c is not None and c.kind != K.TRANSLATION_UNIT:
        if c.kind in FN or c.kind in SCOPE:
            parts.append(c.spelling or '(anonymous)')
        c = c.semantic_parent
    return '::'.join(reversed(parts))


def one_unit(job):
    unit, command, wanted = job
    a = shlex.split(command)
    a = ['--driver-mode=cl'] + [x for x in a[1:a.index('--')] if not x.startswith(('/Fo', '/Fd')) and x != '-c']
    tu = cindex.Index.create().parse(unit, args=a)
    out = {}
    for f, line, col in wanted:
        fh = tu.get_file(f)
        out[(f, line, col)] = ''
        # The declaration may start with an attribute or a macro, where no cursor is a function:
        # try every token of its first lines and keep the function whose extent starts at the place.
        ext = cindex.SourceRange.from_locations(cindex.SourceLocation.from_position(tu, fh, line, col),
                                                cindex.SourceLocation.from_position(tu, fh, line + 4, 1))
        for tok in tu.get_tokens(extent=ext):
            c = cindex.Cursor.from_location(tu, tok.location)
            while c is not None and c.kind != K.TRANSLATION_UNIT and not (
                    c.kind in FN and c.extent.start.line == line and c.extent.start.column == col):
                c = c.semantic_parent
            if c is not None and c.kind in FN:
                out[(f, line, col)] = qualified(c)
                break
    return out


def main():
    if os.environ.get('LIBCLANG'):
        cindex.Config.set_library_file(os.environ['LIBCLANG'])
    commands = {c['file']: c['command'] for c in json.load(open(sys.argv[1]))}
    wanted, seen = {}, set()
    for row in sorted(set(open(sys.argv[2]))):
        unit, f, line, col = row.rstrip('\n').split('\t')
        if (f, line, col) not in seen:
            seen.add((f, line, col))
            wanted.setdefault(unit, []).append((f, int(line), int(col)))
    jobs = [(unit, commands[unit], places) for unit, places in sorted(wanted.items())]
    out = {}
    with multiprocessing.Pool(int(sys.argv[4])) as pool:
        for part in pool.imap_unordered(one_unit, jobs):
            out.update(part)
    with open(sys.argv[3], 'w') as w:
        for (f, line, col), name in sorted(out.items()):
            w.write('%s\t%d\t%d\t%s\n' % (f, line, col, name))


if __name__ == '__main__':
    main()
