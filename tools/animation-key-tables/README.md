# Animation key tables check

NiAnimationKey's key sizes and function tables are one block of the original
release, recipe addresses `0x011f3758` to `0x011f3e3f`, and
`NiAnimationKeyTables` is its one owner (`docs/animation-key-tables.md`). This
command reads the windows-x64 game archive and fails when the block has
become separate storage again or is written with the wrong width or stride.

It needs Python 3 and `llvm-objdump`, and no other package.

```text
python3 check.py --archive GAME_LIB --recipe build/units.json --objdump LLVM_OBJDUMP
```

Each problem is printed on one line that starts with the check's letter,
followed by two summary lines. The exit status is 1 when there is a problem.

## Where it runs

CTest runs it as `archive.animation_key_tables` in the cross build only, the
same as `archive.differing_definitions`. Configuring the cross build fails
when Python 3 or `llvm-objdump` is not found. The compile-time guard beside
it: `nianimationkey_registration.cpp` builds with the `-Werror` pointer
narrowing checks set in `src/root_sources.cmake`, so a registration that casts
a function to a 32-bit integer does not compile.

## What is checked

The block names are the recipe names whose address is in the block. A symbol
of an archive member is one of them when its unqualified name is, whatever
its scope and type mangling: the recipe's mangling is the 32-bit one.

- **a.** No member defines or refers to a block name. `g_functions` and
  `g_keySizes` of `NiAnimationKeyTables` are each defined once, in
  uninitialised data outside a COMDAT section, with 3,456 and 36 bytes: the
  distance to the next symbol of the section or to its end.
- **b.** No instruction stores a dword or a word through the owner or a block
  name: neither one relocated against it nor one that addresses memory
  through a register loaded with its address. A slot holds an 8-byte
  pointer and a key size is one byte.
- **c.** An access that indexes through a register loaded with the address of
  `g_functions` or of a block name in the function tables has exactly one
  index register, scaled by 8, one slot. An index already scaled to bytes,
  `[table + index]`, is the stride error this repairs.
- **d.** The checks above have something to read. The recipe gives the
  block's 241 names, at least one instruction is relocated against the owner
  or a block name, and every member that refers to one of them, rather than
  defines it, has such an instruction. A recipe without the block, a
  disassembler that prints nothing, a disassembler that fails on a member
  (`d objdump failed on MEMBER`) or a reference from data only fails here.
  An empty or different recipe stops the check before it reads the archive,
  with that one line and no summary.

## What is not checked

- A register is followed from the instruction that loads the table address
  in program order to `ret`, to a call that may change it, or to an
  instruction that writes it. Copies of the address to another register or to
  memory, uses past a branch target that is reached another way, and callees
  are not followed.
- A symbol that names the block by an identifier the recipe does not use, or
  a block address reached as an offset from an unrelated symbol, is not seen.
- Correct slots are not checked: `[table + 8*index + displacement]` passes
  whatever the index and displacement are. `docs/animation-key-tables.md`
  records how the slots were matched.
- Function pointer types and the readers' signatures are not checked.
