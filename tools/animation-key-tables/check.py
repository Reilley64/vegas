#!/usr/bin/env python3
"""Check that NiAnimationKey's key sizes and function tables have one owner.

usage: check.py --archive GAME_LIB --recipe UNITS_JSON --objdump LLVM_OBJDUMP

Reads the windows-x64 game archive and fails when any of these holds:
  a. a member defines or refers to a name the recipe places in the block
     0x011f3758 to 0x011f3e3f, or the owner's two names are not each defined
     once, in uninitialised data outside a COMDAT section, with their sizes;
  b. an instruction stores a dword or a word through the owner or a block name;
  c. an indexed access through the function tables scales its index by other
     than 8, the size of one slot.
It also fails when the recipe does not give the block's 241 names, when no
instruction is relocated against the block at all, or when a member that
refers to the block or the owner has no such instruction: then the archive,
the recipe or the disassembly is not what the checks above need.
README.md in this directory says what each check sees and what it does not.
"""
import argparse
import json
import os
import re
import struct
import subprocess
import sys
import tempfile

BLOCK_START = 0x011F3758
TABLES_START = 0x011F3780
BLOCK_END = 0x011F3E40
OWNER_SCOPE = "NiAnimationKeyTables"
OWNER_SIZES = {"g_functions": 12 * 36 * 8, "g_keySizes": 36}
BLOCK_NAMES = 241

SECTION_UNINITIALIZED = 0x00000080
SECTION_COMDAT = 0x00001000
CLASS_EXTERNAL = 2
CLASS_STATIC = 3

REGISTERS = {}
for group in ("rax eax ax al", "rbx ebx bx bl", "rcx ecx cx cl", "rdx edx dx dl", "rsi esi si sil",
              "rdi edi di dil", "rbp ebp bp bpl", "rsp esp sp spl"):
    for spelling in group.split():
        REGISTERS[spelling] = group.split()[0]
for number in range(8, 16):
    for suffix in ("", "d", "w", "b"):
        REGISTERS["r%d%s" % (number, suffix)] = "r%d" % number
# Registers a call may change (Microsoft x64 calling convention).
VOLATILE = {"rax", "rcx", "rdx", "r8", "r9", "r10", "r11"}
NOT_A_WRITE = ("cmp", "test", "push", "nop", "bt", "prefetch")


def identifier(symbol):
    """The unqualified name of a mangled or C symbol, without its type."""
    if symbol.startswith("?"):
        return symbol[1:].split("@", 1)[0]
    return symbol[1:] if symbol.startswith("_") else symbol


def owner_name(symbol):
    """'g_functions' or 'g_keySizes' when the symbol is one of the owner's, else None."""
    for name in OWNER_SIZES:
        if symbol.startswith("?%s@%s@@" % (name, OWNER_SCOPE)):
            return name
    return None


def recipe_block_names(path):
    """Identifier -> recipe address, for every recipe symbol inside the block."""
    names = {}
    for unit in json.load(open(path))["units"]:
        for symbol, address in unit.get("symbols", {}).items():
            address = int(address, 16)
            if BLOCK_START <= address < BLOCK_END:
                names[identifier(symbol)] = address
    return names


def archive_members(data):
    """(name, bytes) of every object member, in stored order."""
    if not data.startswith(b"!<arch>\n"):
        raise SystemExit("not an archive")
    position, long_names = 8, b""
    while position < len(data):
        header = data[position:position + 60]
        size = int(header[48:58])
        body = data[position + 60:position + 60 + size]
        position += 60 + size + (size & 1)
        name = header[:16].decode().rstrip()
        if name in ("/", "/SYM64/"):
            continue
        if name == "//":
            long_names = body
            continue
        if name.startswith("/"):
            rest = long_names[int(name[1:]):]
            name = re.split(rb"[\x00\n]", rest, 1)[0].decode().rstrip("/")
        else:
            name = name.rstrip("/")
        yield name, body


def coff_symbols(body):
    """Sections (characteristics, raw size) and symbols (name, section, value, class) of an x64 COFF object."""
    big = len(body) >= 56 and body[0:4] == b"\x00\x00\xff\xff" and struct.unpack_from("<H", body, 4)[0] >= 2
    if big:
        machine = struct.unpack_from("<H", body, 6)[0]
        section_count, symbol_offset, symbol_count = struct.unpack_from("<III", body, 44)
        section_offset, record = 56, 20
    else:
        machine, section_count = struct.unpack_from("<HH", body, 0)
        symbol_offset, symbol_count = struct.unpack_from("<II", body, 8)
        section_offset, record = 20 + struct.unpack_from("<H", body, 16)[0], 18
    if machine != 0x8664:
        raise SystemExit("a member is not an x64 COFF object")
    strings = symbol_offset + symbol_count * record
    sections = []
    for index in range(section_count):
        at = section_offset + index * 40
        sections.append((struct.unpack_from("<I", body, at + 36)[0], struct.unpack_from("<I", body, at + 16)[0]))
    symbols, index = [], 0
    while index < symbol_count:
        at = symbol_offset + index * record
        if body[at:at + 4] == b"\x00\x00\x00\x00":
            offset = strings + struct.unpack_from("<I", body, at + 4)[0]
            name = body[offset:body.index(b"\x00", offset)].decode("latin-1")
        else:
            name = body[at:at + 8].rstrip(b"\x00").decode("latin-1")
        value = struct.unpack_from("<I", body, at + 8)[0]
        section = struct.unpack_from("<i" if big else "<h", body, at + 12)[0]
        storage_class, aux = body[at + record - 2], body[at + record - 1]
        symbols.append((name, section, value, storage_class))
        index += 1 + aux
    return sections, symbols


def memory_operand(text):
    """(width word or '', registers with their scales, operand index) of an instruction's memory operand."""
    match = re.search(r"(?:(\w+) ptr )?(?:\w+:)?\[([^\]]*)\]", text)
    if not match:
        return None
    operands = text.split(None, 1)[1] if " " in text else ""
    first = operands.split(",")[0]
    registers = {}
    for term in re.findall(r"[^+\-\s]+", match.group(2)):
        if "*" in term:
            scale, register = term.split("*") if term.split("*")[0].isdigit() else term.split("*")[::-1]
            registers[REGISTERS.get(register, register)] = int(scale)
        elif term in REGISTERS:
            registers[REGISTERS[term]] = 1
    return match.group(1) or "", registers, 0 if match.group(0) in first else 1


def destination_register(text):
    operands = text.split(None, 1)[1] if " " in text else ""
    return REGISTERS.get(operands.split(",")[0].strip())


def functions(listing):
    """(function, [(instruction, relocation target or None)]) from llvm-objdump -d -r output."""
    function, body = None, []
    for line in listing.split("\n"):
        match = re.match(r"[0-9a-f]+ <(.*)>:$", line)
        if match:
            if function is not None:
                yield function, body
            function, body = match.group(1), []
            continue
        match = re.match(r"\s+[0-9a-f]+:\s+IMAGE_REL_\w+\s+(\S+)", line)
        if match:
            if body:
                body[-1][1] = match.group(1)
            continue
        match = re.match(r"\s+[0-9a-f]+:\s+(\S.*?)(?:\s+#.*)?$", line)
        if match and function is not None:
            body.append([" ".join(match.group(1).split()), None])
    if function is not None:
        yield function, body


def is_store(text, operand):
    mnemonic = text.split()[0]
    return operand is not None and operand[2] == 0 and not mnemonic.startswith(NOT_A_WRITE)


def check_instructions(member, function, body, kind_of, problems, seen):
    """Checks b and c for one function. kind_of(target) is 'table', 'sizes' or None."""
    for index, (text, target) in enumerate(body):
        kind = kind_of(target) if target else None
        if kind is None:
            continue
        seen["relocated"] += 1
        operand = memory_operand(text)
        if is_store(text, operand) and operand[0] in ("dword", "word"):
            problems.append("b %s %s %s: %s" % (member, function, target, text))
        if not text.startswith("lea ") or kind != "table":
            continue
        # The register now holds the table's address: check every access through it until it is replaced.
        held = destination_register(text)
        for later, _ in body[index + 1:]:
            mnemonic = later.split()[0]
            operand = memory_operand(later)
            if operand is not None and held in operand[1] and mnemonic != "nop":
                others = {r: s for r, s in operand[1].items() if r != held}
                seen["indexed" if others else "through"] += 1
                if is_store(later, operand) and operand[0] in ("dword", "word"):
                    problems.append("b %s %s %s: %s" % (member, function, target, later))
                if others and (operand[1][held] != 1 or list(others.values()) != [8]):
                    problems.append("c %s %s %s: %s" % (member, function, target, later))
            if mnemonic == "ret" or (mnemonic == "call" and held in VOLATILE):
                break
            if destination_register(later) == held and not mnemonic.startswith(NOT_A_WRITE):
                break


def main():
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("--archive", required=True)
    parser.add_argument("--recipe", required=True)
    parser.add_argument("--objdump", required=True)
    args = parser.parse_args()

    block = recipe_block_names(args.recipe)
    if len(block) != BLOCK_NAMES:
        print("d the recipe gives %d names in the block, expected %d" % (len(block), BLOCK_NAMES))
        return 1

    def kind_of(target):
        name = owner_name(target)
        if name == "g_functions":
            return "table"
        if name == "g_keySizes":
            return "sizes"
        address = block.get(identifier(target))
        if address is None:
            return None
        return "table" if address >= TABLES_START else "sizes"

    problems, owners, users = [], {name: [] for name in OWNER_SIZES}, []
    for member, body in archive_members(open(args.archive, "rb").read()):
        sections, symbols = coff_symbols(body)
        uses = refers = False
        for name, section, value, storage_class in symbols:
            if storage_class not in (CLASS_EXTERNAL, CLASS_STATIC) or name.startswith("."):
                continue
            owner = owner_name(name)
            if identifier(name) in block and not owner:
                problems.append("a %s %s %s" % (member, "defines" if section > 0 else "refers to", name))
                uses = True
            if owner:
                uses = True
            if (owner or identifier(name) in block) and section == 0:
                refers = True
            if owner and section > 0:
                flags, raw_size = sections[section - 1]
                later = [v for _, s, v, c in symbols if s == section and v > value and c in (2, 3)]
                size = (min(later) if later else raw_size) - value
                owners[owner].append((member, flags, size))
        if uses:
            users.append((member, body, refers))

    for name, definitions in owners.items():
        if len(definitions) != 1:
            problems.append("a %s is defined %d times" % (name, len(definitions)))
        for member, flags, size in definitions:
            if not flags & SECTION_UNINITIALIZED or flags & SECTION_COMDAT or size != OWNER_SIZES[name]:
                problems.append("a %s in %s: section characteristics 0x%08x, %d bytes, expected uninitialised, "
                                "not COMDAT, %d bytes" % (name, member, flags, size, OWNER_SIZES[name]))

    seen = {"relocated": 0, "through": 0, "indexed": 0}
    with tempfile.TemporaryDirectory() as scratch:
        for member, body, refers in users:
            before = seen["relocated"]
            path = os.path.join(scratch, "member.obj")
            with open(path, "wb") as handle:
                handle.write(body)
            result = subprocess.run([args.objdump, "-d", "-r", "--x86-asm-syntax=intel", "--no-show-raw-insn",
                                     path], capture_output=True, text=True)
            if result.returncode != 0:
                problems.append("d objdump failed on %s" % member)
                continue
            for function, instructions in functions(result.stdout):
                check_instructions(member, function, instructions, kind_of, problems, seen)
            if refers and seen["relocated"] == before:
                problems.append("d %s refers to the block but no instruction is relocated against it" % member)
    if seen["relocated"] == 0:
        problems.append("d no instruction is relocated against the block")

    for problem in problems:
        print(problem)
    counts = {key: sum(p.startswith(key + " ") for p in problems) for key in "abcd"}
    print("members using the block: %d; instructions relocated against it: %d; accesses through a table "
          "register: %d, of them indexed: %d" % (len(users), seen["relocated"], seen["through"] + seen["indexed"],
                                                 seen["indexed"]))
    print("problems: a %d, b %d, c %d, d %d" % (counts["a"], counts["b"], counts["c"], counts["d"]))
    return 1 if problems else 0


if __name__ == "__main__":
    sys.exit(main())
