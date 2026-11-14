# Interior-alias scan

Lists every data name of the recipe whose address lies inside another name's
extent, grouped into families by the container. `docs/interior-alias-scan.md`
describes the method, the classes and the limits, and holds the tables this
scan writes.

It needs Python 3, `llvm-readobj`, `llvm-objdump`, and a configured and built
windows-x64 tree with `-DCMAKE_EXPORT_COMPILE_COMMANDS=ON`. Set `LLVM_BIN` to
the directory of the LLVM tools when they are not on `PATH`.

```text
sh run.sh BUILD_DIR build/units.json OUT_DIR JOBS
```

| Step | Writes |
| --- | --- |
| `scan_objects.py` | per windows-x64 object of the game archive: data definitions and every code reference to a data symbol |
| `i686_objects.py` | each game unit compiled again for 32-bit, `/Od /Gw`, from the recorded compile commands; units that do not compile are listed in `OUT_DIR/i686/compile.log` |
| `i686_sizes.py` | the size of each 32-bit definition, its extent in the recipe's address space |
| `scan_families.py` | names, families, members, addresses with more than one symbol, unmeasured containers and the symbols left out, with `owners.tsv` |
| `scan_tables.py` | `OUT_DIR/tables`: the committed form |

`owners.tsv` lists each native owner that replaces recipe names: the recipe
address and the owner's symbol in the recipe's 32-bit mangling. Add a line
when a family gets one owner.

To update the document, replace its two tables under "Families" and
"Unmeasured containers" with `families.md.part` and `unmeasured.md.part`, copy
`members.tsv`, `same-address.tsv` and `other-manglings.tsv` to
`docs/interior-alias-scan/`, and update the counts from
`OUT_DIR/scan/counts.txt`.
