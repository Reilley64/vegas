#!/usr/bin/env python3
"""Step 1 of the interior-alias scan: per object, the data definitions and every code reference to a data symbol.

usage: scan_objects.py BUILD_DIR OUT_JSONL [JOBS]
Reads every object under BUILD_DIR/CMakeFiles/game.dir with llvm-readobj and llvm-objdump. One JSON line per object:
  defs: symbol -> [section name, value, size]   size = distance to the next symbol of the same section, or to its end
  refs: [symbol, displacement, kind, width, scale, function]
        kind: r (read), w (write), rw, a (address taken and not followed), c (address passed on or stored)
        width: operand bytes of the access, 0 when unknown; scale: index scale of an indexed access, 0 when none
"""
import json, os, re, subprocess, sys
from multiprocessing import Pool

# The directory of llvm-readobj and llvm-objdump; empty to take them from PATH.
LLVM = os.path.join(os.environ["LLVM_BIN"], "") if os.environ.get("LLVM_BIN") else ""
WIDTH = {"byte": 1, "word": 2, "dword": 4, "qword": 8, "xmmword": 16, "ymmword": 32, "tbyte": 10}
REG64 = {}
for names in ("rax eax ax al", "rbx ebx bx bl", "rcx ecx cx cl", "rdx edx dx dl", "rsi esi si sil", "rdi edi di dil",
              "rbp ebp bp bpl", "rsp esp sp spl"):
    n = names.split()
    for x in n:
        REG64[x] = n[0]
for i in range(8, 16):
    for suffix in ("", "d", "w", "b"):
        REG64["r%d%s" % (i, suffix)] = "r%d" % i
REGW = {}
for r in REG64:
    if r.startswith("r") and (r[1:].isdigit() or len(r) == 3 and not r[1].isdigit()):
        REGW[r] = 8
    elif r.startswith("e") or r.endswith("d"):
        REGW[r] = 4
    elif r.endswith("w") or r in ("ax", "bx", "cx", "dx", "si", "di", "bp", "sp"):
        REGW[r] = 2
    else:
        REGW[r] = 1
MEM = re.compile(r"(?:(\w+) ptr )?\[([^\]]*)\]")


def symbols(obj):
    out = subprocess.run([LLVM + "llvm-readobj", "--symbols", obj], capture_output=True, text=True).stdout
    syms, seclen = [], {}
    for block in out.split("  Symbol {")[1:]:
        f = dict(re.findall(r"^\s+(\w+): (.*)$", block, re.M))
        m = re.match(r"(\S+) \((-?\d+)\)", f.get("Section", ""))
        if not m:
            continue
        sec, idx = m.group(1), int(m.group(2))
        cls = f.get("StorageClass", "").split(" ")[0]
        if cls == "Static" and "AuxSectionDef" in block:
            seclen[idx] = int(re.search(r"Length: (\d+)", block).group(1))
            continue
        if idx <= 0 or cls not in ("External", "Static"):
            continue
        syms.append((f["Name"], sec, idx, int(f["Value"])))
    by_sec = {}
    for name, sec, idx, value in syms:
        by_sec.setdefault(idx, []).append(value)
    defs = {}
    for name, sec, idx, value in syms:
        if sec.startswith(".text") or name.startswith("$") or name.startswith(".") or name.startswith("@"):
            continue
        later = [v for v in by_sec[idx] if v > value]
        end = min(later) if later else seclen.get(idx)
        defs[name] = [sec, value, None if end is None else end - value]
    return defs


def mem_operand(ins):
    """(position of the memory operand among the operands, width, base, index scale, displacement) or None."""
    m = MEM.search(ins)
    if not m:
        return None
    ops = ins.split(None, 1)[1] if " " in ins.strip() or "\t" in ins else ""
    pos = 0 if ops.lstrip().startswith(m.group(0)) else 1
    width = WIDTH.get(m.group(1) or "", 0)
    inner = m.group(2)
    base, scale, disp, regs = None, 0, 0, []
    for sign, term in re.findall(r"([+-]?)\s*([^+\-\s]+)", inner):
        if "*" in term:
            scale = next(int(x) for x in term.split("*") if x.isdigit())
            regs += [REG64.get(x) for x in term.split("*") if x in REG64]
        elif term in REG64 or term == "rip":
            regs.append(REG64.get(term, term))
            if base is None:
                base = term
            else:
                scale = scale or 1
        else:
            try:
                disp += int(term, 16) * (-1 if sign == "-" else 1)
            except ValueError:
                pass
    return pos, width, regs, scale, disp


def access(ins):
    """Direction and width of the memory access of one instruction."""
    mnem = ins.split()[0]
    mo = mem_operand(ins)
    if mo is None:
        return None
    pos, width, base, scale, disp = mo
    if not width:
        other = [t for t in re.findall(r"\b[a-z0-9]+\b", MEM.sub("", ins.split(None, 1)[1])) if t in REGW]
        width = REGW[other[0]] if other else 0
        if mnem.startswith(("movss", "cvtss", "addss", "mulss", "subss", "divss", "comiss", "ucomiss")):
            width = 4
        if mnem.startswith(("movsd", "cvtsd", "addsd", "mulsd", "subsd", "divsd", "comisd", "ucomisd")):
            width = 8
    if mnem == "lea":
        return "a", 0, base, scale, disp
    if mnem in ("call", "jmp"):
        return "r", 8, base, scale, disp
    if mnem in ("cmp", "test", "push", "comiss", "ucomiss", "comisd", "ucomisd") or pos == 1:
        return "r", width, base, scale, disp
    if mnem.startswith(("mov", "set", "pop", "cvt", "vmov")) and pos == 0:
        return "w", width, base, scale, disp
    return "rw", width, base, scale, disp


def references(obj, data_names):
    out = subprocess.run([LLVM + "llvm-objdump", "-d", "-r", "--x86-asm-syntax=intel", "--no-show-raw-insn", obj],
                         capture_output=True, text=True).stdout
    refs, func, body, pending = [], None, [], []

    def flush():
        # body: list of [instruction text, relocation target or None]
        for i, (ins, target, trailing) in enumerate(body):
            if target is None or target not in data_names:
                continue
            acc = access(ins)
            if acc is None:
                refs.append([target, 0, "c", 0, 0, func])
                continue
            kind, width, base, scale, disp = acc
            disp += trailing
            if kind != "a":
                refs.append([target, disp, kind, width, scale, func])
                continue
            # lea reg, [rip + target]: follow the register until it is overwritten
            reg = REG64.get(re.match(r"lea\s+(\w+),", ins).group(1))
            found = False
            for later, _, _ in body[i + 1:i + 60]:
                lm = later.split()[0]
                if lm == "nop":
                    # alignment padding such as nop word ptr cs:[rax + rax] names registers but reads nothing
                    continue
                if lm in ("ret", "jmp") and "[" not in later:
                    break
                la = access(later)
                if la is not None and reg in la[2]:
                    if la[0] == "a":
                        refs.append([target, disp + la[4], "c", 0, la[3], func])
                    else:
                        refs.append([target, disp + la[4], la[0], la[1], la[3], func])
                    found = True
                ops = later.split(None, 1)[1] if len(later.split(None, 1)) > 1 else ""
                first = ops.split(",")[0].strip()
                if la is not None and reg in la[2]:
                    if REG64.get(first) == reg and lm.startswith(("mov", "lea", "cvt")):
                        break
                    continue
                if lm == "call":
                    if reg in ("rcx", "rdx", "r8", "r9", "rax", "r10", "r11"):
                        if not found and reg in ("rcx", "rdx", "r8", "r9"):
                            refs.append([target, disp, "c", 0, 0, func])
                            found = True
                        break
                    continue
                if REG64.get(first) == reg and lm in ("mov", "lea", "xor", "pop", "movzx", "movsx", "movsxd"):
                    break
                if re.search(r"\b%s\b" % reg, ops) and la is None and lm in ("mov", "add", "push", "cmp"):
                    refs.append([target, disp, "c", 0, 0, func])
                    found = True
            if not found:
                refs.append([target, disp, "a", 0, 0, func])

    for line in out.split("\n"):
        m = re.match(r"[0-9a-f]+ <(.*)>:$", line)
        if m:
            flush()
            func, body = m.group(1), []
            pending.clear()
            continue
        m = re.match(r"\s+([0-9a-f]+):\s+IMAGE_REL_\w+\s+(\S+)", line)
        if m:
            if body:
                body[-1][1] = m.group(2)
                pending.append((len(body) - 1, int(m.group(1), 16)))
            continue
        m = re.match(r"\s+([0-9a-f]+):\s+(\S.*?)(?:\s+#.*)?$", line)
        if m:
            # bytes of the instruction after a 4-byte relocated field shift its rip-relative displacement
            for index, at in pending:
                body[index][2] = int(m.group(1), 16) - (at + 4)
            pending.clear()
            body.append([m.group(2).replace("\t", " "), None, 0])
    flush()
    return refs


def is_data_name(n):
    if n.startswith(("??_C@", "__real@", "__xmm@", "__ymm@", "__imp_", "$", "??_R", "__security")):
        return False
    return True


def one(obj):
    defs = symbols(obj)
    # a reference is to data when its target is not a function: decided in step 2 from the recipe, so keep every
    # target whose mangled name is not that of a function
    def data_like(n):
        if not is_data_name(n):
            return False
        if n.startswith("?"):
            m = re.search(r"@@(\d)", n)
            return bool(m) and m.group(1) in "23" or "@4" in n
        return True
    names = _Any(data_like)
    refs = references(obj, names)
    return {"object": obj, "defs": defs, "refs": refs}


class _Any:
    def __init__(self, f):
        self.f = f

    def __contains__(self, n):
        return self.f(n)


if __name__ == "__main__":
    build, out = sys.argv[1], sys.argv[2]
    jobs = int(sys.argv[3]) if len(sys.argv) > 3 else 2
    objs = []
    for root, _, files in os.walk(os.path.join(build, "CMakeFiles/game.dir")):
        objs += [os.path.join(root, f) for f in files if f.endswith(".obj")]
    objs.sort()
    with Pool(jobs) as pool, open(out, "w") as fh:
        for rec in pool.imap(one, objs, chunksize=8):
            rec["object"] = os.path.relpath(rec["object"], os.path.join(build, "CMakeFiles/game.dir"))
            fh.write(json.dumps(rec) + "\n")
    print("objects:", len(objs))
