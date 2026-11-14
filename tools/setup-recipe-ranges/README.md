# Setup recipe ranges check

Setup reads C1's four strings at original addresses that the source writes as
data in `src/setup/single_instance_ranges.h`, the four log path suffixes at
those of `src/setup/log_path_suffix_ranges.h`, the main window class
through the pointer whose address `src/setup/main_window_class_range.h` holds,
and the ten save directory strings at the addresses and through the two
pointers of `src/setup/save_directory_ranges.h` (`docs/setup.md`). Each value
of these files but the two capacities of 256 bytes, which no recipe bound
gives, is a fact of the recipe, `build/units.json`. This command fails when
one no longer matches the recipe.

It needs Python 3 and no other package.

```text
python3 check.py --recipe build/units.json --source src/setup/single_instance_ranges.h \
  --pointer-source src/setup/main_window_class_range.h \
  --suffix-source src/setup/log_path_suffix_ranges.h \
  --save-directory-source src/setup/save_directory_ranges.h
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

`setup.recipe_ranges.save_directory_bound` and
`setup.recipe_ranges.save_directory_target_bound`
(`tests/checks/setup_recipe_ranges_save_directory_bound.cmake`) run it on
copies of the recipe in which one more unit binds an address 4 bytes into the
setting key, or 4 bytes into the first INI name at `0x01039c8c`, and require
that check **n**, or **s**, alone refuses it. Without Python 3 they are
registered and fail with that reason.

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
- **l.** `saveDirectoryRanges` has exactly eight rows, each on one line in the
  form of `singleInstanceRanges`.
- **m.** The recipe entries of `src/fallout/misc/saveload/bgssaveloadmanager.cpp`,
  merged across all of them, bind each row's name at the row's address and at
  no other, and no unit of the recipe binds it at another address. A name of
  the form `DAT_`, `UNK_` or `str_` and eight hex digits spells the row's
  address; the two `g_..._arg1` names spell none.
- **n.** Each save directory row's capacity is the recipe bound, as in **c**.
- **o.** A save directory row that names a literal passes the tests of **d**.
  No row names one today.
- **p.** `saveDirectoryPointerRanges` has exactly two rows, each on one line:
  the field, the pointer's name and address, the capacity, then the target's
  name and address, or `{}` and `0`.
- **q.** Each pointer's name is a char pointer (`@@3PADA`, `@@3PBDB` and the
  other two `const` forms) named `DAT_` or `_DAT_` with its address. The
  merged `bgssaveloadmanager.cpp` entries bind it, and no unit of the recipe
  binds it at another address.
- **r.** The distance from each pointer's address to the next address that any
  unit of the recipe binds is at least 4.
- **s.** A pointer row with a target: the target's name is a `DAT_`, `UNK_` or
  `str_` name that spells the target's address, the recipe binds it there and
  nowhere else, and the row's capacity is the recipe bound at the target. A
  row without a target has the capacity 256.

## What is not checked

- That the rows are in catalogue order and that each capacity is the size of
  its field: `static_assert`s in the headers check the sizes, and
  `setup.prepare_pack` spells the order and the addresses itself.
- That the save directory rows are the addresses
  `BGSSaveLoadManager::GetSaveDirectory` reads: they were read from its body
  in `bgssaveloadmanager.cpp`, and `setup.prepare_pack` spells them itself.
- That the pointer at `0x011a2ff4` holds `0x01039c8c` in the original
  release: setup refuses the executable when it does not (`PointerTarget`).
  That the recipe binds no address of the string the pointer at
  `0x011a2ff0` reaches, which gives it 256 bytes: no original file is read.
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
