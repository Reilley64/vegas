#!/usr/bin/env python3
"""Check setup's recipe ranges against the recipe.

usage: check.py --recipe UNITS_JSON --source SINGLE_INSTANCE_RANGES_H
                --pointer-source MAIN_WINDOW_CLASS_RANGE_H
                --suffix-source LOG_PATH_SUFFIX_RANGES_H

Reads the rows of singleInstanceRanges in src/setup/single_instance_ranges.h,
the row of mainWindowClassRange in src/setup/main_window_class_range.h and
the rows of logPathSuffixRanges in src/setup/log_path_suffix_ranges.h, and
fails when any of these holds:
  a. there are not exactly four rows;
  b. a row's name is not a str_ name that spells its address, or the recipe
     entries of src/fallout/misc/main.cpp, merged, do not bind it at exactly
     that address;
  c. a row's capacity is not the distance from its address to the next
     address any unit of the recipe binds, by a function row or a symbol;
  d. a row names a literal that no unit of the recipe binds at its address,
     whose name does not spell its whole text with a zero byte, or whose text
     is not the row's;
  e. there is not exactly one mainWindowClassRange row;
  f. its name is not a char pointer named for its address, the recipe entries
     of src/fallout/misc/main.cpp, merged, do not bind it, or a unit of the
     recipe binds it at another address;
  g. the distance from its address to the next address any unit of the
     recipe binds is less than 4, the size of a 32-bit pointer;
  h. there are not exactly four logPathSuffixRanges rows;
  i. a suffix row's name is not a UNK_ or str_ name that spells its address,
     or the recipe entries of src/fallout/misc/main.cpp, merged, do not bind
     it at exactly that address;
  j. a suffix row's capacity is not the distance from its address to the
     next address any unit of the recipe binds;
  k. a suffix row names a literal, as d checks for singleInstanceRanges.
README.md in this directory says what it does not check.
"""
import argparse
import bisect
import json
import re
import sys

MAIN_SOURCE = "src/fallout/misc/main.cpp"
ROWS = 4
ROW = re.compile(
    r'^\s*\{"(?P<field>[^"]*)", "(?P<name>[^"]*)", 0x(?P<address>[0-9a-fA-F]{8}), (?P<capacity>[0-9]+), '
    r'(?:\{\}|"(?P<literal>[^"]*)"), (?:\{\}|"(?P<text>[^"]*)")\},\s*$')
STR_NAME = re.compile(r"^\?str_([0-9a-f]{8})@@")
SUFFIX_NAME = re.compile(r"^\?(?:UNK|str)_([0-9a-f]{8})@@")
POINTER_ROW = re.compile(
    r'^inline constexpr PointerRange mainWindowClassRange\{"(?P<field>[^"]*)", "(?P<name>[^"]*)", '
    r'0x(?P<address>[0-9a-fA-F]{8}), (?P<capacity>[0-9]+)\};\s*$')
CHAR_POINTER_NAME = re.compile(r"^\?_?DAT_([0-9a-f]{8})@@3PADA$")
POINTER_BYTES = 4
LITERAL = re.compile(r"^\?\?_C@_0(?:(?P<digit>[0-9])|(?P<hex>[A-P]+)@)[A-P]*@(?P<content>.*)@$")


def rows(source, array="singleInstanceRanges"):
    """The rows of `array`, in order."""
    found, inside = [], False
    with open(source, encoding="utf-8") as text:
        for line in text:
            if array + "{{" in line:
                inside = True
            elif inside and line.strip() == "}};":
                break
            elif inside:
                match = ROW.match(line)
                if not match:
                    raise SystemExit("cannot read the row: " + line.strip())
                found.append(match)
    return found


def pointer_rows(source):
    """The mainWindowClassRange rows, in order."""
    with open(source, encoding="utf-8") as text:
        return [match for match in map(POINTER_ROW.match, text) if match]


def literal_text(name):
    """The text an MSVC string literal name spells, with its zero byte, or
    None when the name does not spell all of it."""
    match = LITERAL.match(name)
    if not match:
        return None
    if match["digit"] is not None:
        length = int(match["digit"]) + 1
    else:
        length = 0
        for letter in match["hex"]:
            length = length * 16 + ord(letter) - ord("A")
    content, text = match["content"], ""
    while content:
        if content.startswith("?$") and len(content) >= 4 and all("A" <= c <= "P" for c in content[2:4]):
            text += chr((ord(content[2]) - ord("A")) * 16 + ord(content[3]) - ord("A"))
            content = content[4:]
        elif re.match(r"[A-Za-z0-9_$]", content[0]):
            text += content[0]
            content = content[1:]
        else:
            return None
    return text if len(text) == length else None


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--recipe", required=True)
    parser.add_argument("--source", required=True)
    parser.add_argument("--pointer-source", required=True)
    parser.add_argument("--suffix-source", required=True)
    args = parser.parse_args()

    with open(args.recipe, encoding="utf-8") as text:
        units = json.load(text)["units"]
    bound, main_names, literals, binders = set(), {}, {}, {}
    for unit in units:
        for function in unit.get("functions", []):
            bound.add(int(function["address"], 16))
        for name, address in unit.get("symbols", {}).items():
            address = int(address, 16)
            bound.add(address)
            literals.setdefault(name, set()).add(address)
            binders.setdefault(name, set()).add(unit["source"])
            if unit["source"] == MAIN_SOURCE:
                main_names.setdefault(name, set()).add(address)
    addresses = sorted(bound)

    def check_rows(found, letters, name_pattern):
        count, name_letter, bound_letter, literal_letter = letters
        if len(found) != ROWS:
            problems.append("%s %d rows, expected %d" % (count, len(found), ROWS))
        for row in found:
            field, name = row["field"], row["name"]
            address, capacity = int(row["address"], 16), int(row["capacity"])
            spelled = name_pattern.match(name)
            if not spelled or int(spelled[1], 16) != address:
                problems.append("%s %s: %s does not spell 0x%08x" % (name_letter, field, name, address))
            if main_names.get(name) != {address}:
                problems.append("%s %s: %s is bound at %s for %s, not at 0x%08x only" % (
                    name_letter, field, name, sorted(hex(a) for a in main_names.get(name, ())) or "no address",
                    MAIN_SOURCE, address))
            following = bisect.bisect_right(addresses, address)
            distance = addresses[following] - address if following < len(addresses) else None
            if distance != capacity:
                problems.append("%s %s: capacity %d, the recipe bound is %s" % (bound_letter, field, capacity, distance))
            literal, text = row["literal"], row["text"]
            if (literal is None) != (text is None):
                problems.append("%s %s: a literal needs both its name and its text" % (literal_letter, field))
            elif literal is not None:
                if address not in literals.get(literal, ()):
                    problems.append("%s %s: no unit binds %s at 0x%08x" % (literal_letter, field, literal, address))
                if literal_text(literal) != text + "\0":
                    problems.append("%s %s: %s does not spell exactly \"%s\" and a zero byte" % (
                        literal_letter, field, literal, text))

    problems = []
    found = rows(args.source)
    check_rows(found, "abcd", STR_NAME)
    suffixes = rows(args.suffix_source, "logPathSuffixRanges")
    check_rows(suffixes, "hijk", SUFFIX_NAME)

    pointers = pointer_rows(args.pointer_source)
    if len(pointers) != 1:
        problems.append("e %d mainWindowClassRange rows, expected 1" % len(pointers))
    for row in pointers:
        field, name, address = row["field"], row["name"], int(row["address"], 16)
        spelled = CHAR_POINTER_NAME.match(name)
        if not spelled or int(spelled[1], 16) != address:
            problems.append("f %s: %s is not a char pointer named for 0x%08x" % (field, name, address))
        if MAIN_SOURCE not in binders.get(name, ()):
            problems.append("f %s: %s is not bound for %s" % (field, name, MAIN_SOURCE))
        if literals.get(name, set()) - {address}:
            problems.append("f %s: %s is also bound at %s" % (
                field, name, sorted(hex(a) for a in literals[name] - {address})))
        following = bisect.bisect_right(addresses, address)
        distance = addresses[following] - address if following < len(addresses) else None
        if distance is None or distance < POINTER_BYTES:
            problems.append("g %s: the recipe bound is %s, less than %d" % (field, distance, POINTER_BYTES))

    for problem in problems:
        print(problem)
    print("%d rows, %d pointer rows, %d suffix rows, %d problems" % (
        len(found), len(pointers), len(suffixes), len(problems)))
    return 1 if problems else 0


if __name__ == "__main__":
    sys.exit(main())
