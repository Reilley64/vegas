#!/usr/bin/env python3
"""Turn the clang-query output of queries.cq into one row per place.

usage: parse.py RUN_DIR SOURCE_ROOT BUILD_ROOT

Reads RUN_DIR/exits.txt and RUN_DIR/out/N.txt. Writes RUN_DIR/sites.tsv (one row per distinct
place), RUN_DIR/fn_sites.tsv (input of fn_names.py) and RUN_DIR/summary.txt. A place in a header
counts once. Places outside SOURCE_ROOT and BUILD_ROOT (compiler and SDK headers) are counted and
dropped. Kinds whose name starts with X_ are counted only; they measure what the table does not hold.
"""
import collections, os, re, sys

RUN, SOURCE, BUILD = sys.argv[1:4]
KINDS = ['A_ptr_to_narrow', 'B_ptr_wide_then_narrow', 'C_ptr_var_then_narrow', 'D_narrow_to_ptr',
         'E_mem_on_pointer_array', 'F_mem_scaled_by_4', 'G_pointer_array_from_byte_count']
COUNTED = ['X_untyped_storage_by_literal_or_times_4', 'X_pointer_copied_in_a_loop',
           'X_narrowing_of_other_64_bit_variable']
DIAG = re.compile(r'^(.*)\((\d+),(\d+)\): note: "(\w+)" binds here')
HEAD = re.compile(r"^(\w+) 0x[0-9a-f]+ <([^>]*)>(.*)$")
QUOTED = re.compile(r"'([^']*)'")
PREFIX = re.compile(r'^[| ]*[|`]-')
CASTS = ('ImplicitCastExpr', 'ParenExpr', 'CStyleCastExpr', 'CXXReinterpretCastExpr', 'CXXStaticCastExpr',
         'CXXConstCastExpr', 'CXXFunctionalCastExpr')
WRAPPERS = CASTS + ('MaterializeTemporaryExpr', 'ExprWithCleanups', 'CXXBindTemporaryExpr')
FOUR_BYTE = ('int', 'unsigned int', 'float', 'long', 'unsigned long')


class Node:
    def __init__(self, line):
        self.text = PREFIX.sub('', line)
        self.kind = self.text.split(' ', 1)[0]
        self.kids = []

    def type(self):
        m = HEAD.match(self.text)
        q = QUOTED.search(m.group(3)) if m else None
        return q.group(1) if q else '?'

    def walk(self):
        yield self
        for k in self.kids:
            yield from k.walk()

    def under(self, skip):
        """The first node at or below this one, along first children, that is not of a skipped kind."""
        n = self
        while n.kind in skip and n.kids:
            n = n.kids[0]
        return n

    def prefix(self, op):
        return self.kind == 'UnaryOperator' and ("prefix '%s'" % op) in self.text


def tree(lines):
    root = Node(lines[0])
    stack = [(0, root)]
    for line in lines[1:]:
        m = PREFIX.match(line)
        if not m:
            continue
        depth = len(m.group(0)) // 2
        n = Node(line)
        while stack[-1][0] >= depth:
            stack.pop()
        stack[-1][1].kids.append(n)
        stack.append((depth, n))
    return root


def origin(n):
    """What a converted operand is, from the first node below the conversion that is not a cast."""
    n = n.under(WRAPPERS)
    k = n.kind
    if k == 'CXXThisExpr':
        return 'this'
    if n.prefix('&'):
        return 'address-of'
    if k == 'StringLiteral':
        return 'string literal'
    if k == 'CXXDynamicCastExpr':
        return 'dynamic_cast result'
    if k == 'DeclRefExpr':
        if re.search(r" (Function|CXXMethod) 0x", n.text):
            return 'function address'
        return 'array' if n.type().endswith(']') else 'variable'
    if k == 'MemberExpr':
        return 'array' if n.type().endswith(']') else 'member'
    if k in ('CallExpr', 'CXXMemberCallExpr', 'CXXOperatorCallExpr'):
        return 'call result'
    if k == 'ArraySubscriptExpr' or n.prefix('*'):
        return 'loaded through a pointer'
    if k == 'BinaryOperator':
        return 'arithmetic'
    if k == 'ConditionalOperator':
        return 'conditional'
    if k == 'CXXNewExpr':
        return 'new expression'
    return k


def literal_value(n):
    m = re.search(r"IntegerLiteral 0x[0-9a-f]+ <[^>]*> '[^']*' (\d+)", n.text)
    return int(m.group(1)) if m else None


def literal_child(n, values=None):
    for k in n.kids:
        v = literal_value(k.under(CASTS))
        if v is not None and (values is None or v in values):
            return True
    return False


def is_operator(n, op):
    return n.kind == 'BinaryOperator' and n.text.rstrip().endswith("'%s'" % op)


def size_class(n):
    """How a byte count is written: by sizeof, by sizeof and an added literal, by a count scaled by 4
    or by another constant, by a literal alone, or by a variable."""
    nodes = list(n.walk())
    sizeofs = [x for x in nodes if x.kind == 'UnaryExprOrTypeTraitExpr' and ' sizeof' in x.text]
    if sizeofs:
        top = n.under(CASTS)
        if (is_operator(top, '+') or is_operator(top, '-')) and literal_child(top):
            return 'sizeof and an added literal'
        named = []
        for s in sizeofs:
            q = QUOTED.findall(HEAD.match(s.text).group(3))
            named.append(q[-1] if len(q) > 1 else (s.kids[0].under(('ParenExpr',)).type() if s.kids else '?'))
        if all(t in FOUR_BYTE for t in named):
            return 'sizeof of a 4-byte type'
        return 'sizeof'
    if any((is_operator(x, '*') and literal_child(x, (4,))) or
           (is_operator(x, '<<') and len(x.kids) == 2 and literal_value(x.kids[1].under(CASTS)) == 2) for x in nodes):
        return 'count times 4'
    if any((is_operator(x, '*') and literal_child(x)) or
           (is_operator(x, '<<') and len(x.kids) == 2 and literal_value(x.kids[1].under(CASTS)) is not None)
           for x in nodes):
        return 'count times another constant'
    if any(x.kind in ('DeclRefExpr', 'MemberExpr', 'CXXThisExpr', 'CallExpr', 'CXXMemberCallExpr',
                      'CXXOperatorCallExpr', 'ArraySubscriptExpr') for x in nodes):
        return 'variable'
    return 'literal'


def literals(n):
    return sorted({v for v in (literal_value(x) for x in n.walk()) if v is not None})


def storage_type(arg):
    """Type of a pointer argument under its casts. An argument written as *(T*)&member is the member
    read through a cast: the member's own type is the storage."""
    n = arg.under(CASTS)
    if n.prefix('*') and n.kids:
        inner = n.kids[0].under(CASTS)
        if inner.prefix('&') and inner.kids:
            t = inner.kids[0].under(CASTS).type()
            if is_storage(t):
                return t
    return n.type()


def is_storage(t):
    """A pointer or an array type. A pointer to a function is written with the stars in parentheses."""
    t = t.strip()
    return t.endswith('*') or t.endswith(']') or re.search(r'\(\*+\)\(', t) is not None


def describe(kind, root):
    dest = QUOTED.search(HEAD.match(root.text).group(3)).group(1)
    if kind == 'A_ptr_to_narrow':
        return root.kind, root.kids[0].type() + ' -> ' + dest, origin(root.kids[0])
    if kind in ('B_ptr_wide_then_narrow', 'C_ptr_var_then_narrow'):
        for x in root.walk():
            if '<PointerToIntegral>' in x.text and x.kids:
                return root.kind, '%s -> %s -> %s' % (x.kids[0].type(), x.type(), dest), origin(x.kids[0])
        return root.kind, root.kids[0].under(CASTS).type() + ' -> ' + dest, 'variable holding a converted pointer'
    if kind == 'D_narrow_to_ptr':
        return root.kind, root.kids[0].type() + ' -> ' + dest, origin(root.kids[0])
    call = root if kind != 'G_pointer_array_from_byte_count' else next(
        x for x in root.walk() if x.kind in ('CallExpr', 'CXXMemberCallExpr'))
    callee = re.search(r"(?:Function|CXXMethod) 0x[0-9a-f]+ '([^']+)'", ' '.join(x.text for x in call.kids[0].walk()))
    name = callee.group(1) if callee else '?'
    args = call.kids[1:]
    if kind == 'G_pointer_array_from_byte_count':
        sizes = [a for a in args if not is_storage(a.under(CASTS).type())] or args
        return name, '%s; size by %s %s' % (dest, size_class(sizes[-1]), ','.join(map(str, literals(sizes[-1])))), ''
    storage = [storage_type(a) for a in args if is_storage(storage_type(a))]
    counts = [a for a in args if not is_storage(storage_type(a))]
    size = counts[-1] if counts else None
    return name, '%s <- %s; size by %s %s' % (
        storage[0] if storage else '?', storage[1] if len(storage) > 1 else '-',
        size_class(size) if size else '?', ','.join(map(str, literals(size))) if size else ''), ''


def rel(path):
    path = os.path.normpath(path)
    for root, tag in ((SOURCE, ''), (BUILD, '<build>/')):
        if path.startswith(root + '/'):
            return tag + path[len(root) + 1:]
    return None


def start(loc):
    m = re.match(r'^(.*):(\d+):(\d+)$', loc.split(',')[0].strip())
    return (m.group(1), int(m.group(2)), int(m.group(3))) if m and m.group(1) != 'line' else None


sites = {}
counted = collections.defaultdict(set)
outside = collections.Counter()
units = {}
for row in open(os.path.join(RUN, 'exits.txt')):
    n, code, unit = row.rstrip('\n').split(' ', 2)
    units[n] = (int(code), unit)
failed = [(n, c, u) for n, (c, u) in units.items() if c != 0]
for n, (code, unit) in sorted(units.items(), key=lambda x: int(x[0])):
    text = open(os.path.join(RUN, 'out', n + '.txt'), errors='replace').read().split('\n')
    i, current = 0, None
    while i < len(text):
        line = text[i]
        m = DIAG.match(line)
        if m:
            f, row, col, name = m.group(1), int(m.group(2)), int(m.group(3)), m.group(4)
            r = rel(f)
            if name in COUNTED:
                current = None
                if r is not None:
                    counted[name].add((r, row, col))
            elif name in KINDS:
                if r is None:
                    outside[name] += 1
                    current = None
                else:
                    current = sites.setdefault((r, row, col, name), {'units': set(), 'fn': None})
                    current['units'].add(unit)
            elif name == 'fn' and current is not None:
                current['fn'] = (os.path.normpath(f), row, col)
            i += 1
            continue
        m = re.match(r'^Binding for "(\w+)":$', line)
        if m and m.group(1) in KINDS:
            kind = m.group(1)
            j = i + 1
            block = []
            while j < len(text) and text[j] != '':
                block.append(text[j])
                j += 1
            h = HEAD.match(block[0]) if block else None
            s = start(h.group(2)) if h else None
            if s:
                r = rel(s[0])
                key = (r, s[1], s[2], kind)
                if r is not None and key in sites and 'detail' not in sites[key]:
                    form, detail, org = describe(kind, tree(block))
                    sites[key].update(form=form, detail=detail.strip(), origin=org)
            i = j
            continue
        i += 1

with open(os.path.join(RUN, 'sites.tsv'), 'w') as w, open(os.path.join(RUN, 'fn_sites.tsv'), 'w') as fw:
    for (f, row, col, kind), d in sorted(sites.items()):
        fn = d['fn']
        w.write('\t'.join([f, str(row), str(col), kind, d.get('form', '?'), d.get('detail', '?'), d.get('origin', '?'),
                           ('%s:%d:%d' % fn) if fn else '', str(len(d['units']))]) + '\n')
        if fn:
            fw.write('\t'.join([sorted(d['units'])[0], fn[0], str(fn[1]), str(fn[2])]) + '\n')
with open(os.path.join(RUN, 'summary.txt'), 'w') as w:
    w.write('units run: %d, nonzero exit: %d\n' % (len(units), len(failed)))
    for n, c, u in failed:
        w.write('  exit %d: %s\n' % (c, rel(u) or u))
    by = collections.Counter(key[3] for key in sites)
    for name in KINDS:
        w.write('%s: %d places, %d match records in compiler and SDK headers (dropped)\n' % (name, by[name], outside[name]))
    for name in COUNTED:
        w.write('%s: %d places (counted only)\n' % (name, len(counted[name])))
    w.write('places without detail: %d\n' % sum(1 for d in sites.values() if 'detail' not in d))
    callee = collections.Counter(d.get('form', '?') for key, d in sites.items() if key[3][0] in 'EF')
    seen = set()
    calls = collections.Counter()
    for key, d in sorted(sites.items()):
        if key[3][0] in 'EF' and key[:3] not in seen:
            seen.add(key[:3])
            calls[d.get('form', '?')] += 1
    for name, count in sorted(calls.items(), key=lambda x: (-x[1], x[0])):
        w.write('memory call name %s: %d calls\n' % (name, count))
sys.stdout.write(open(os.path.join(RUN, 'summary.txt')).read())
