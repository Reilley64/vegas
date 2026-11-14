# Batch binding

Binds calls of a stand-in name, which no object defines, to the body at the
recipe's function row, under the kinds already admitted (VEGAS-11, rulings of
2026-11-13), and proves each binding with `tools/object-proof`. Python 3,
standard library only, and the clang-cl of a configured windows-x64 build.
Run it on the cross-build host (macOS or Linux), not on Windows: apply
writes the recipe and the check table in text mode.

`bind_batch.py` runs three steps; each reads the previous step's files in
`OUT`, so each can be run again alone:

1. **gate** decides ADMIT or REFUSE per call site from the declarations, the
   recipe and two name lists only. Nothing is compiled to an object.
2. **prove** compiles each admitted name's rewrite at the unit's flags,
   `/Ob0` and `/Od /Gy`, keeps a name only when every variant passes in one
   of the proof modes `objcmp.py` names, and compares the unit's record
   layouts on windows-x64 and i686.
3. **apply** writes the rewrite of the proved names into a checkout: the
   moves, or the moves and the calls with the recipe keys and check rows.

## Run a batch

```sh
T=tools/bind-batch/bind_batch.py
python3 $T gate CANDIDATES BUILD OUT --recipe build/units.json --differing NAMES --undefined UNDEFINED --jobs 3
python3 $T prove OUT BUILD --jobs 3
python3 $T apply OUT REPO --stage moves                                  # commit: the moves
python3 $T apply OUT REPO --stage bind \
        --table tools/function-relocations/batch-bindings.tsv --batch NAME   # commit: the bindings
```

- `CANDIDATES`: tab-separated with a header `unit site name owner address`:
  the requiring unit as the recipe spells its source, `*` (every site) or
  `LINE:COL`, the stand-in's and the row owner's windows-x64 mangled names,
  and the row's address. List every requiring unit of a name: a name is
  bound only when every site in every unit listed is admitted.
- `BUILD`: a configured windows-x64 build tree. Its
  `compile_commands.json` gives each unit's command and file; gate, prove
  and apply read the unit's text from that export. Run gate and prove
  through the build-slot wrapper: they parse or compile many units.
- `NAMES`: one mangled name per line (first column): the
  differing-definitions lists of the tip's measurement. Required.
- `UNDEFINED`: the tip's forced-unlimited link's undefined names, one per
  line, as lld-link prints them (llvm-undname's text) or mangled. Required:
  a stand-in it does not list is refused, and so is an owner it lists.
- apply takes only the names in `OUT/proved.txt` (and in `--only FILE`,
  first column, when given) whose every site is admitted. It exits 1,
  writing nothing, when `OUT` has no `proof.tsv`, `proved.txt` or
  `rows.tsv`, when a unit's text in the export no longer has the sha256
  that gate recorded, when a unit's file in `REPO` is neither the export's
  text nor its moves, when a recipe key cannot be respelled, or when a bound name
  has no check row. Build and commit the moves, then apply `--stage bind`.

## Gate

Per candidate, then per site, the first refusal that applies:

| Kind | Refused when |
| --- | --- |
| `recipe:address`, `recipe:no-key`, `recipe:no-row` | the requiring unit's `symbols` maps, all entries of its source merged, have no key whose demangled name equals the stand-in's (calling convention and `__ptr64` aside) and whose addresses are exactly the row's, or have several; or the function row at the address is not the owner; or the candidate names no one address. An address in an identifier never counts. |
| `differing-definitions` | the stand-in or the owner is in `NAMES` |
| `defined:not-listed`, `defined:owner-undefined`, `defined:name` | `UNDEFINED` does not list the stand-in; it lists the owner: no object of the link defines it; the unit defines the stand-in |
| `signature:unreadable` | llvm-undname's text of either name has no calling convention outside every bracket (a function that returns a function pointer) |
| `not-declared:name`, `not-declared:owner`, `not-declared:owner-class`, `not-declared:owner-name` | the unit does not declare the exact mangled name, the owner's class is not defined in it, or the owner has no plain qualified name |
| `overload:owner` | the owner's class (for a member) or namespace declares another function of the owner's name: a call could pick it |
| `site:macro`, `site:header`, `site:template`, `site:not-a-call`, `site:name-text`, `site:none` | the reference is spelled in a macro or a header, inside a template or lambda, is not the callee of a call, or its text is not the plain name; no site |
| `call-form:special-member`, `call-form:member-free`, `call-form:static-free` | a constructor, destructor or operator; a member against a free or static function; a static member against a free function |
| `virtual` | either function is virtual |
| `void-result-used` | the owner returns void and the call is not a whole statement of a block or cast to `void`. A label: a call that is the body of an unbraced `if` or loop also gets it; any result difference is refused |
| `conversion:*` | any type that is not the same: result, parameter count, `this` qualifiers other than added `const`, calling convention, a default argument used, the literal `0` or `1` to `bool` (`conversion:literal-bool`: the object differs, so it stays a per-address step), or a parameter other than an object pointer to `void *` (R5a: implicit, no cv dropped, no derived-to-base step) |
| `receiver:not-a-cast`, `receiver:conversion`, `receiver:cast-text` | a member call's receiver is not an explicit cast, reaches the call through a conversion, or the cast's written type is not the stand-in's class name with cv-qualifiers and one `*` or `&` |
| `naming:descriptive-function`, `naming:descriptive-differs` | the stand-in's function name is descriptive and the owner's differs: a placeholder (it carries the row's own address; any other name counts as descriptive) or another descriptive name. Both stay for the reviewed override table (`docs/symbol-naming-batches.md`, "The rule") |
| `move:*` | the owner (its class, for a member) is not visible at the site and cannot move verbatim: in a header, nested in a class, a template, not alone on its lines, inside a linkage block, or needing more than three types it names that are declared between the two places |

An admitted site's kind column holds its labels: `same-type`, `R5a`,
`const-this` (`const` added to `this`), `class-only` (the member's name
is the same on both sides and only its class differs, the full scope
compared, namespaces included) and `name+class` (one label: a placeholder
member, or static member, becomes another name in another class), joined
by `+`. Under both class labels the receiver stays open.

Types are compared as llvm-undname prints the two mangled names of one
translation unit: equal strings are equal types as the name carries them;
`noexcept` and attributes are left to the proof. The AST comes from
`clang-cl ... /Zs -Xclang -ast-dump=json` with the unit's command; only the
top-level declarations that mention a wanted name are parsed. No edit touches
a class definition other than moving it whole and removing a stand-in's own
non-virtual member declaration, so no class changes layout.

`gate.tsv` has one row per site (or per candidate when no site is found);
`gate.json` holds the edits: per name the call edits, the moves, the stand-in
declarations to remove once every call is bound, the enclosing functions of
sites that are not bound, and the recipe key and row; per unit the sha256 of
the text it read. Gate deletes `OUT`'s `proof.tsv`, `proved.txt` and
`rows.tsv`: an earlier proof does not hold for a new plan.

## Rewrite

- A member call: the receiver cast's class becomes the owner's class, fully
  qualified, and the member name becomes the owner's. A free or static call:
  the callee becomes the owner's fully qualified name.
- A move: the owner's class definition (or, for a free function, its first
  namespace-scope declaration) with the comment lines just above it, and the
  types it names that are declared between the two places, go verbatim, in
  their order, before the outermost declaration holding the first site in
  the deepest namespace both share, each wrapped in a block of its own
  namespaces.
- The stand-in's declarations go once no reference to them remains, when they
  are alone on their lines, and so does its class when that leaves it empty
  and the file names it nowhere else.
- `--stage bind` respells the requiring unit's `symbols` key of the stand-in
  as the row's 32-bit name in every entry of the source that holds it, and
  drops it where the source already has the row's key. It appends a
  `forbid` line per bound name and a `function` line per function that
  `prove` saw holding a bound call (`rows.tsv`) to the table.
  `tools/function-relocations` reads the table.

## Prove

Prove exits 1, writing nothing, when a unit's text in the export no longer
has the sha256 that gate recorded. Per unit, each name alone, then all of
the unit's passing names together.
The moves alone must give byte-identical objects (timestamp aside). The
binding is compared with `objcmp.py --json --map --base-holds-new
--function-order` (the owners), and passes at a variant only when the
verdict names one of these modes, recorded per variant in `proof.tsv`:

| Mode | Verdict |
| --- | --- |
| `strict` | `identical: ... once the renames are applied` |
| `merge-definition`, `merge-reference` | `merged`: the stand-in merges into the owner the unit defines, or into the unit's existing reference to it (ruling of 2026-11-13) |
| `function-order` | `reordered`: only the owner's COMDAT sections, their associative children and the `__real@`/`__xmm@`/`__ymm@` constants the owner refers to changed place (`tools/object-proof/README.md`); `+` joins it to a merge |

Byte-identical objects (`identical: the bytes are equal`) do not pass: the
call was not bound. Warnings must be equal without positions. A name whose
call no COMDAT function holds both at the unit's flags and at `/Od /Gy` is
dropped: it would have no check row. A function that holds the call at the
unit's flags only holds an inlined copy, which another compiler may not
inline, so it gets no row. Then the unit's record layouts (`-Xclang
-fdump-record-layouts-complete`, syntax only, the unit's command, and the
same with `--target=i686-pc-windows-msvc`) of the base and of all its
proved bindings must be equal block for block, but for the removed empty
stand-in classes; an unnamed record's file, line and column, which a move
shifts, are left out. A dump that fails drops the unit's names.

`proof.tsv` gives per unit and name `PROVED` with the mode per variant, or
`DROPPED` with the stage and a label: `compile-failed`,
`inlinable-at-unit-flags` (differs at the unit's flags only, with the owner
defined in the unit), `warnings`, `differs`, `layout`. Labels are for the
report; any difference drops the name. `proved.txt` lists the names proved
in every unit, `rows.tsv` the check rows.

## What stays open

- Receivers, class layouts across units and lifetimes stay open for every
  retargeted cast: the binding takes the unit's own cast, and the object is
  not proven to be the owner's class.
- The proof sees one object at a time: the link's choice among COMDAT
  copies is measured separately (definitions per name).
- An overload the gate does not see (a using-declaration, a base class's
  function), `noexcept`, `[[noreturn]]` and a cast between related classes
  that adjusts the pointer are caught by the proof (the object differs, or
  the rewrite does not compile), not refused by the gate. A cast between
  related classes that leaves the pointer as it is gives the same object:
  it stays open with the receiver.
- `objcmp.py`'s own blind spots apply (`tools/object-proof/README.md`).
- The host tests (`tools.bind_batch.*`, `test_bind_batch.py`) use hand-made
  AST fragments, texts and reports, a fake compiler and a fake `objcmp.py`,
  not compiler output.
