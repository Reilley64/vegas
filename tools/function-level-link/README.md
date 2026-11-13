# Function-level link check

`check.py` fails unless every name that a function-level link left
unresolved is referenced only from sections that lld-link discarded. It reads
the executable, the link's `/MAP` file and the objects and static libraries
that the build made for the target. It does not read the system libraries
named in `SYSTEM_LIBRARIES` in `check.py`, so references from those are not
checked, and it refuses a map that names a member of any other library it did
not read. Python 3, standard library only.

```text
python3 check.py --exe FalloutNV.exe --map FalloutNV.map --inputs INPUTS
```

`INPUTS` lists one path per line. CTest writes it for each checked target and
runs the check as `link.function_level`; `tests/checks/link_function_level.cmake`
registers it. The rule, what the check proves and how to read a failure are
in `docs/function-level-link.md`.

Output:

- `LIVE NAME from kept OBJECT section N NAME (LEADER)`: a kept section
  refers to the unresolved NAME. NAME is `__imp_X` for a call through the
  import slot of an unresolved X.
- `UNCLASSIFIED ...`: the check cannot tell whether a referencing section is
  kept, or found no section that refers to the name.
- `REFUSED ...`: a map line out of its place, a map of another link, an
  object the map names that the check did not read, a library the map names
  that it neither read nor lists, or an absolute zero name that no object
  read refers to.
- `unresolved NAME: N references` for each unresolved name, with `, an import
  slot that holds zero` when lld-link made `__imp_X` a slot of its own for an
  unresolved X, then one summary line.

Exit status: 0 accepted, 1 refused, 2 usage error or unreadable input.
`test_check.py` tests it on hand-made objects, archives, maps and executables.
