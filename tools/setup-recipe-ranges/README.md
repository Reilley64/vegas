# Setup recipe ranges check

Setup reads C1's four strings at original addresses that the source writes as
data in `src/setup/single_instance_ranges.h`, the four log path suffixes at
those of `src/setup/log_path_suffix_ranges.h`, and the main window class
through the pointer whose address `src/setup/main_window_class_range.h` holds
(`docs/setup.md`). Each value of the first two files, and the pointer's
address and name in the third, is a fact of the recipe, `build/units.json`.
This command fails when one no longer matches the recipe.

It needs Python 3 and no other package.

```text
python3 check.py --recipe build/units.json --source src/setup/single_instance_ranges.h \
  --pointer-source src/setup/main_window_class_range.h \
  --suffix-source src/setup/log_path_suffix_ranges.h
```

Each problem is printed on one line that starts with the check's letter,
followed by one summary line. The exit status is 1 when there is a problem.

## Where it runs

CTest runs it as `setup.recipe_ranges` on every host. When configuring does
not find Python 3, it warns and goes on, and `setup.recipe_ranges` is still
registered: it then fails, and its output says that Python 3 was not found.
The cross build for Windows still needs Python 3 for other tests, and its
configure fails without it.

`setup.recipe_ranges.pointer_bound` runs the command on a copy of the recipe,
in the build folder, in which one more unit binds an address 2 bytes after the
class name's pointer, and requires that check **g** alone refuses it. It is
registered only when Python 3 is found.

`setup.recipe_ranges.suffix_bound` (`tests/checks/setup_recipe_ranges_suffix_bound.cmake`)
runs it on a copy of the recipe in which one more unit binds an address 8
bytes into the third log path suffix, and requires that check **j** alone
refuses it. Without Python 3 it is registered and fails with that reason.

## What is checked

- **a.** `singleInstanceRanges` has exactly four rows, each on one line in the
  form the file uses. A row in another form stops the check with that line.
- **b.** Each row's name is a `str_` name that spells the row's address. The
  recipe entries of `src/fallout/misc/main.cpp`, merged across all of them,
  bind the name at that address and at no other.
- **c.** Each row's capacity is the recipe bound: the distance from its
  address to the next address that any unit of the recipe binds, by a
  function row or a symbol.
- **d.** A row that names a literal: some unit of the recipe binds the literal
  at the row's address, and the literal's name spells its whole text, the
  row's text and then a zero byte.
- **e.** `mainWindowClassRange` has exactly one row, on one line in the form
  the file uses.
- **f.** Its name is a char pointer (`@@3PADA`) named `DAT_` or `_DAT_` with
  its address. The recipe entries of `src/fallout/misc/main.cpp`, merged, bind
  it, and no unit of the recipe binds it at another address.
- **g.** The distance from its address to the next address that any unit of
  the recipe binds is at least 4, the size of the 32-bit pointer.
- **h.** `logPathSuffixRanges` has exactly four rows, each on one line in the
  form of `singleInstanceRanges`.
- **i.** Each suffix row's name is a `UNK_` or `str_` name that spells the
  row's address, and the recipe entries of `src/fallout/misc/main.cpp`,
  merged, bind it at that address and at no other.
- **j.** Each suffix row's capacity is the recipe bound, as in **c**.
- **k.** A suffix row that names a literal passes the tests of **d**. No row
  names one today.

## What is not checked

- That the rows are in catalogue order and that each capacity is the size of
  its field: `static_assert`s in the headers check the sizes, and
  `setup.prepare_pack` spells the order and the addresses itself.
- That the suffix rows' addresses are those WinMain passes to its log-path
  builders: the recipe binds them under one-byte `UNK_` names that say
  nothing of their use, and `setup.prepare_pack` spells the addresses
  itself. They were read from the arguments of the four calls in
  `FUN_0086a850` (`src/fallout/misc/main.cpp`).
- Whether the original release stores the strings where the recipe says, in
  a data section: no original file is read.
- The main window class's capacity, 256 bytes, which is the documented limit
  of a window class name and not a recipe bound: a `static_assert` in the
  header ties it to the field. The recipe binds no address of the string the
  pointer points to, so nothing here checks the string or its text.
- Which pointer the row names: another char pointer that the recipe binds
  for `src/fallout/misc/main.cpp` passes **f** and **g**. `setup.prepare_pack`
  spells the pointer's address itself, which fixes its identity.
- Literal names that spell a character other than a letter, a digit, `_`, `$`
  or a `?$` escape are reported as not spelling their text.
