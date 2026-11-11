# Pointer truncation census

Generates `docs/pointer-truncation-census.tsv`. The table is generated: regenerate it, do not edit it by hand. `docs/pointer-truncation-census.md` explains the kinds, the dispositions and what the census cannot see.

| File | Role |
| --- | --- |
| `queries.cq` | The `clang-query` matchers: seven kinds of place, and three kinds that are only counted. |
| `run.sh` | Runs the matchers over every unit of the game archive of one build tree, then the next two. |
| `parse.py` | Turns the matcher output into one row per place, with operand types and how the byte count is written. |
| `fn_names.py` | Names the function that encloses each place, through libclang. |
| `make_table.py` | Gives each place a disposition and writes the table and a summary. |
| `overrides.tsv` | Dispositions of places checked by hand. Each row needs its reason in the commit that adds it. |

## Requirements

- A configured windows-x64 build tree with `-DCMAKE_EXPORT_COMPILE_COMMANDS=ON`. Configure is enough; nothing is compiled.
- `clang-query` and the clang Python bindings of the same LLVM release as the compiler. `CLANG_QUERY` names the program. `PYTHONPATH` must hold the bindings, and `LIBCLANG` names the libclang library when it is not found by default.
- Python 3.9 or newer and Git.

## Regenerate

The table describes one commit, the base, and marks the places that a later commit, the head, repairs. Export each commit to its own folder, configure a build tree for each, then run from this folder:

```text
sh run.sh BASE_BUILD BASE_SOURCE BASE_RUN JOBS
sh run.sh HEAD_BUILD HEAD_SOURCE HEAD_RUN JOBS
python3 make_table.py BASE_RUN HEAD_RUN REPOSITORY BASE_COMMIT HEAD_COMMIT TABLE.tsv SUMMARY.txt
```

`BASE_RUN` and `HEAD_RUN` are new folders that receive the matcher output, `sites.tsv` with one row per place, `names.tsv` and `summary.txt`. `REPOSITORY` is a clone that holds both commits; `make_table.py` reads their difference from it. Give the same commit twice, and the same run folder twice, for a table with no repaired places.

`TABLE.tsv` must equal `docs/pointer-truncation-census.tsv` for the two commits that `docs/pointer-truncation-census.md` names. `SUMMARY.txt` holds the counts the document quotes: places by kind and disposition, the names of the memory functions that were matched, and the counted-only kinds.

A run parses every unit of the game archive, 2,224 at the time of writing. Every unit must exit 0; `summary.txt` lists the ones that did not.

## Rules

- A place is a source position. A place in a header counts once, however many units include it. Places in compiler and SDK headers are dropped.
- The kinds come from the conversion kind and the types in the syntax tree, not from the text.
- A memory function is any function whose qualified name contains `mem` or `Mem` followed by `cpy`, `copy`, `move`, `set` or `cmp`, the first letter of that word in either case (`memcpy`, `MemCpy`, `memMove`), and does not contain `wmem`. A name written in other letter case, such as `MEMCPY`, does not match. Pointer arguments and the byte count are found by type, not by position, so `memcpy_s` and `memmove_s` need no special case. The byte count is the last argument that is not a pointer.
- `parse.py` classes each byte count as `sizeof`, `sizeof and an added literal`, `sizeof of a 4-byte type`, `count times 4`, `count times another constant`, `literal` or `variable`. `count times 4` is any byte count with a product by 4 or a shift left by 2 in it, such as `n * 4` or `n * 4 + 4`; `literal` is a byte count with no name in it.
- An argument written as `*(T*)&member` is the member read through a cast. Its storage type is the member's own type.
- A pointer to a function counts as a pointer: an array of function pointers is a pointer array.
- The element type of a memory call is taken from the destination. When only the source points to pointer storage, such as the address of a pointer copied by bytes into a `float`, the place is open on its own: the bytes of a pointer go into storage of another type.
- A count scaled by 4 on storage declared as a 4-byte scalar is labelled by its declared type only. Nothing checks whether that storage holds pointers; `overrides.tsv` corrects the places checked by hand.
- A row of `overrides.tsv` matches by file, function, kind letter and a part of the place's detail column in `sites.tsv`. `make_table.py` stops if a row matches nothing.
