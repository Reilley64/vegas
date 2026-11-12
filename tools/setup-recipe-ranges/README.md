# Setup recipe ranges check

Setup reads C1's four strings at original addresses that the source writes as
data in `src/setup/single_instance_ranges.h` (`docs/setup.md`). Each value
there is a fact of the recipe, `build/units.json`. This command fails when one
no longer matches the recipe.

It needs Python 3 and no other package.

```text
python3 check.py --recipe build/units.json --source src/setup/single_instance_ranges.h
```

Each problem is printed on one line that starts with the check's letter,
followed by one summary line. The exit status is 1 when there is a problem.

## Where it runs

CTest runs it as `setup.recipe_ranges` on every host. When configuring does
not find Python 3, it warns and goes on, and `setup.recipe_ranges` is still
registered: it then fails, and its output says that Python 3 was not found.
The cross build for Windows still needs Python 3 for other tests, and its
configure fails without it.

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

## What is not checked

- That the rows are in catalogue order and that each capacity is the size of
  its field: `static_assert`s in the header check the sizes, and
  `setup.prepare_pack` spells the order and the addresses itself.
- Whether the original release stores the strings where the recipe says, in
  a data section: no original file is read.
- Literal names that spell a character other than a letter, a digit, `_`, `$`
  or a `?$` escape are reported as not spelling their text.
