#!/usr/bin/env python3
"""Census table: one row per file, function, kind and disposition.

usage: make_table.py BASE_RUN HEAD_RUN REPO BASE_COMMIT HEAD_COMMIT OUT_TSV OUT_SUMMARY

BASE_RUN and HEAD_RUN hold sites.tsv (parse.py), names.tsv (fn_names.py) and summary.txt of the
census of the two commits. The rows describe BASE_COMMIT. A place of a file changed between the two
commits counts as repaired when the head run no longer reports it at the line it moved to, or reports
it there with a byte count by sizeof alone: a cast is gone, a byte count or allocation uses sizeof. overrides.tsv, next to this file, replaces the disposition
of places checked by hand; an override that matches no place is an error.
"""
import collections, csv, os, re, subprocess, sys

BASE, HEAD, REPO, BASE_COMMIT, HEAD_COMMIT, OUT, SUMMARY = sys.argv[1:8]
HERE = os.path.dirname(os.path.abspath(__file__))

KIND = {
    'A_ptr_to_narrow': 'pointer cast to a narrower integer',
    'B_ptr_wide_then_narrow': 'pointer cast to a pointer-sized integer, then narrowed',
    'C_ptr_var_then_narrow': 'narrowing of a variable that holds a converted pointer',
    'D_narrow_to_ptr': 'narrower integer cast to a pointer',
    'E_mem_on_pointer_array': 'memory call on a pointer array',
    'F_mem_scaled_by_4': 'memory call with a byte count scaled by 4',
    'G_pointer_array_from_byte_count': 'pointer array from an allocation by byte count',
}
LIVE = {'this', 'address-of', 'function address', 'array', 'string literal', 'new expression', 'dynamic_cast result'}
CONSTANT = {'IntegerLiteral', 'CXXBoolLiteralExpr', 'CharacterLiteral', 'CXXNullPtrLiteralExpr', 'GNUNullExpr'}
FOUR_BYTE = {'int', 'unsigned int', 'float', 'long', 'unsigned long'}
UNTYPED = {'void', 'char', 'unsigned char', 'signed char'}


def load(run):
    names = {}
    for r in csv.reader(open(os.path.join(run, 'names.tsv')), delimiter='\t', quoting=csv.QUOTE_NONE):
        names[(r[0], r[1], r[2])] = r[3]
    rows = []
    for r in csv.reader(open(os.path.join(run, 'sites.tsv')), delimiter='\t', quoting=csv.QUOTE_NONE):
        f, line, col, kind, form, detail, origin, fn, units = r
        name = '(file scope)'
        if fn:
            a = fn.rsplit(':', 2)
            name = names.get((a[0], a[1], a[2]), '') or '(not resolved)'
        rows.append(dict(file=f, line=int(line), col=int(col), kind=kind, form=form, detail=detail, origin=origin, fn=name))
    return rows


def hunks():
    """For each file changed between the commits, its hunks as (base start, base count, head start, head count)."""
    out = collections.defaultdict(list)
    diff = subprocess.run(['git', '-C', REPO, 'diff', '-U0', BASE_COMMIT, HEAD_COMMIT, '--', 'src', 'include'],
                          capture_output=True, text=True, check=True).stdout
    current = None
    for line in diff.split('\n'):
        if line.startswith('--- a/'):
            current = line[6:]
        m = re.match(r'^@@ -(\d+)(?:,(\d+))? \+(\d+)(?:,(\d+))? ', line)
        if m and current:
            out[current].append((int(m.group(1)), int(m.group(2) or 1), int(m.group(3)), int(m.group(4) or 1)))
    return out


def head_line(f, line):
    """The head line of a base line of a changed file, or None when the line is removed or its hunk does not
    replace lines one for one."""
    shift = 0
    for s, n, t, k in changed[f]:
        if n and s <= line < s + n:
            return t + line - s if n == k else None
        if (n and line >= s + n) or (not n and line > s):
            shift += k - n
    return line + shift


def size(detail):
    return detail.split('; size by ', 1)[1] if '; size by ' in detail else ''


def size_class(detail):
    s = size(detail)
    for name in ('sizeof and an added literal', 'sizeof of a 4-byte type', 'sizeof', 'count times 4',
                 'count times another constant', 'literal', 'variable'):
        if s.startswith(name):
            return name
    return '?'


def element(t):
    """Element type of a pointer or array type, as written in the syntax tree."""
    t = t.strip()
    if t.endswith(']'):
        return t[:t.rindex('[')].strip()
    if t.endswith('*'):
        return t[:-1].strip()
    m = re.search(r'\((\*+)\)\(', t)
    if m:
        return t[:m.start(1)] + m.group(1)[1:] + t[m.end(1):] if len(m.group(1)) > 1 else '(function)'
    return t


def is_pointer(t):
    return t.endswith('*') or re.search(r'\(\*+\)\(', t) is not None


def operands(detail):
    """Element types of the destination and the source of a memory call; '-' when there is no source."""
    parts = detail.split(';')[0].split(' <- ')
    return [plain(element(p)) if p.strip() not in ('-', '?') else p.strip() for p in parts]


def plain(t):
    return re.sub(r'\b(const|volatile)\b', '', t).strip()


base, head = load(BASE), load(HEAD)
changed = hunks()
head_at = collections.defaultdict(list)
for r in head:
    head_at[(r['file'], r['line'], r['kind'])].append(r)
scaled = {(r['file'], r['line'], r['col']) for r in base if r['kind'] == 'F_mem_scaled_by_4'}


def repaired(r):
    """A place of a changed file is repaired when the head run no longer reports it at its head line, or, for a
    memory call or an allocation, reports it there with a byte count by sizeof alone. A statement can span lines:
    the place is its first line, and the change may be on a later one."""
    if r['file'] not in changed:
        return False
    line = head_line(r['file'], r['line'])
    there = head_at[(r['file'], line, r['kind'])] if line else []
    if r['kind'][0] in 'ABCD':
        return not there
    return all(size_class(h['detail']) == 'sizeof' for h in there)


def disposition(r):
    k, o, c = r['kind'][0], r['origin'], size_class(r['detail'])
    if k in 'ABC':
        if repaired(r):
            return 'repaired: the statement that held the cast is removed'
        if o in CONSTANT:
            return 'no action: the operand is a constant'
        if o in LIVE:
            return 'open: the address of a live object is cut to 32 bits; the receiving declaration is 32-bit'
        return 'open: a pointer-typed value is cut to 32 bits; a truncation if the value is an address'
    if k == 'D':
        if repaired(r):
            return 'repaired: the statement that held the cast is removed'
        if o in CONSTANT:
            return 'no action: the operand is a constant'
        return 'open: a pointer is rebuilt from a 32-bit value'
    if c == 'sizeof':
        return 'no action: the byte count uses sizeof'
    if c == 'sizeof and an added literal':
        return 'open: sizeof with an added literal; a literal that is a 32-bit member offset is wrong on a 64-bit build target'
    if k == 'G':
        if repaired(r):
            return 'repaired: the allocation uses the element size'
        if c == 'count times 4':
            return 'open: a pointer array is allocated as a count times 4 bytes'
        if c == 'literal':
            return 'open: a pointer array is allocated from a literal byte count'
        return 'open: a pointer array is allocated from a byte count that is not the element size'
    dest, source = (operands(r['detail']) + ['-'])[:2]
    e = dest
    if not is_pointer(dest) and is_pointer(source):
        # kind E: only the source is pointer storage, such as the address of a pointer copied by bytes
        if repaired(r):
            return 'repaired: the byte count uses the element size'
        return 'open: the bytes of pointer storage are copied into storage declared with another type'
    is_scaled = k == 'F' or (r['file'], r['line'], r['col']) in scaled
    if is_pointer(e):
        if repaired(r):
            return 'repaired: the byte count uses the element size'
        if c == 'sizeof of a 4-byte type':
            return 'open: the byte count is sizeof of a 4-byte type on a pointer array'
        if is_scaled:
            return 'open: count times 4 on a pointer array; the storage it covers is not established'
        if c == 'count times another constant':
            return 'open: count times a constant other than 4 on a pointer array'
        if c == 'literal':
            return 'open: literal byte count on a pointer array'
        return 'open: variable byte count on a pointer array; where it is computed is not followed'
    # only kind F reaches here: the storage is not typed as a pointer array
    if c == 'sizeof of a 4-byte type':
        return 'no action: the byte count uses sizeof'
    if e in FOUR_BYTE:
        return 'declared 4-byte scalar (declared type only); not checked whether the storage holds pointers'
    if e in UNTYPED:
        return 'open: count times 4; the element type is not visible at the call'
    return 'open: count times 4; the element is a structure whose size was not checked against 4'


def overrides():
    rows = []
    with open(os.path.join(HERE, 'overrides.tsv')) as f:
        for r in csv.DictReader(f, delimiter='\t', quoting=csv.QUOTE_NONE):
            r['used'] = 0
            rows.append(r)
    return rows


OVER = overrides()


def final(r):
    for o in OVER:
        if o['file'] == r['file'] and o['function'] == r['fn'] and r['kind'].startswith(o['kind'] + '_') \
                and o['detail'] in r['detail']:
            o['used'] += 1
            return o['disposition']
    d = disposition(r)
    if r['file'].startswith(('src/generated/', '<build>/')) and d.startswith('open: '):
        return 'generated file, not edited here; ' + d[6:]
    return d


agg = collections.Counter()
places = []
for r in base:
    d = final(r)
    agg[(r['file'], r['fn'], KIND[r['kind']], d)] += 1
    places.append((r, d))
unused = [o for o in OVER if not o['used']]
if unused:
    sys.exit('overrides that match no place: ' + '; '.join('%s %s %s' % (o['file'], o['function'], o['kind']) for o in unused))
with open(OUT, 'w') as w:
    w.write('file\tfunction\tkind\tplaces\tdisposition\n')
    for (f, fn, k, d), n in sorted(agg.items()):
        w.write('%s\t%s\t%s\t%d\t%s\n' % (f, fn, k, n, d))


def counted(run):
    out = {}
    for line in open(os.path.join(run, 'summary.txt')):
        m = re.match(r'^(X_\w+): (\d+) places', line)
        if m:
            out[m.group(1)] = int(m.group(2))
    return out


with open(SUMMARY, 'w') as w:
    by = collections.Counter()
    for (f, fn, k, d), n in agg.items():
        by[(k, d)] += n
    w.write('base places: %d, rows: %d, files: %d\n' % (len(base), len(agg), len({k[0] for k in agg})))
    for (k, d), n in sorted(by.items()):
        w.write('%5d\t%s\t%s\n' % (n, k, d))
    group = collections.Counter()
    for (k, d), n in by.items():
        group[d.split(':')[0].split(';')[0].split(' (')[0]] += n
    for g, n in sorted(group.items()):
        w.write('group %s: %d\n' % (g, n))
    hk, bk = collections.Counter(r['kind'] for r in head), collections.Counter(r['kind'] for r in base)
    for k in sorted(KIND):
        w.write('kind %s: base %d, head %d\n' % (k, bk[k], hk[k]))
    cb, ch = counted(BASE), counted(HEAD)
    for k in sorted(cb):
        w.write('counted only %s: base %d, head %d\n' % (k, cb[k], ch.get(k, 0)))
    calls = collections.Counter()
    for key in {(r['file'], r['line'], r['col'], r['form']) for r in base if r['kind'][0] in 'EF'}:
        calls[key[3]] += 1
    for name, n in sorted(calls.items(), key=lambda x: (-x[1], x[0])):
        w.write('memory call name %s: %d\n' % (name, n))
    for o in OVER:
        w.write('override used %d times: %s %s %s\n' % (o['used'], o['file'], o['function'], o['kind']))
    for r, d in sorted(places, key=lambda x: (x[0]['file'], x[0]['line'], x[0]['col'])):
        if d.startswith(('repaired', 'open: sizeof with')) or 'hand-checked' in d:
            w.write('place\t%s\t%d\t%s\t%s\t%s\n' % (r['file'], r['line'], r['fn'], KIND[r['kind']], d))
sys.stdout.write(''.join(l for l in open(SUMMARY) if not l.startswith('place\t')))
