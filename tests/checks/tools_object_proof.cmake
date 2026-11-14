# Fails when tools/object-proof's objcmp.py no longer tells identical COFF
# objects (equal bytes, a timestamp-only difference in a regular and a bigobj
# object, a symbol respelled with its rename) from a real difference, accepts
# a rename that merges two names or that the head still holds, lets an
# unmatched rename relax the comparison, stops comparing a structural field
# (header, section flags, order and COMDAT selection, storage class), or no
# longer exits 2 on unreadable input; when proof.py's warnings comparison
# stops ignoring positions, path prefixes and line endings; or when proof.py
# compile and compare stop passing the variant flags, removing stale objects
# and reporting a failed compile, a compiler that cannot start or a warnings
# difference; when objcmp.py counts RENAME- lines as differences or lets
# them alone pass, stops saying what a changed section keeps equal or naming
# each added, removed or moved address-significance entry, stops printing
# changed characteristics in hexadecimal with a changed alignment, reads a
# padded or truncated address-significance index, stops refusing, with no
# artefact line, a base that holds both spellings of a rename, its summary
# or --json report stops listing the retargets, kept sites and symbols that
# a section shifts, or --expect-kept passes a comparison with a kept site
# missing, extra or in another function, or with any other difference
# beside them (an OLD symbol other than an undefined external of NEW's type
# and value 0, another rename's OLD, OLD marked address-significant other
# than as often as in the base, NEW at another place in the symbol table),
# with OLD still defined or held in a name no rename respells, stops
# printing those differences, stops reading a section key that starts with
# #, reports a listed site that byte-identical objects keep as missing, or
# treats a list with no site other than no option; or when proof.py compile
# --source writes the unit's file, stops compiling the override's content at
# the unit's path or stops logging the entry and commands, or compiles with
# a compiler other than clang, a command that names the unit otherwise than
# the entry's file, an override that is not a file, or an overlay that its
# #error canary does not show to take effect; or when objcmp.py
# --base-holds-new stops calling a merge into the base's own definition or
# its existing reference "merged" (one NEW symbol at OLD's or NEW's place,
# one address-significance entry of NEW), or calls one so where the bytes are
# equal, other symbols or address-significance entries change order, the
# head still holds OLD (beside the call, alone or in a label),
# no relocation of the base targets OLD, OLD is defined or embedded in
# another name, is a static or weak external symbol or has an aux record,
# NEW is held twice or is a static symbol, an address-significance entry of NEW is
# added or removed alone, the relocations only change order, a call goes to
# another name or with another type, a second call is retargeted, code or
# the owner's body changes, or the head's NEW is another kind of symbol, or
# combines it with --expect-kept; or when objcmp.py --function-order stops
# calling a unit whose listed function's COMDAT sections and associative
# children moved, also among themselves, "reordered" (or "merged and
# reordered") and one where nothing moved "identical", or calls one so where
# a non-COMDAT section (one the listed function leads too) or an unlisted
# function's section changed place (then with one ORDER-FIXED line and
# nothing more), two .CRT$XCU entries swapped, a .CRT$ child of any group
# (XC, XI, XL, XP, XT) moved with its parent, the symbol multisets differ
# by a count, a section was added, a moved section's bytes
# changed, a relocation was retargeted, a symbol moved to another section,
# another address-significance entry moved or the listed function's entry
# went, or combines it with --expect-kept, or compares the symbols as a
# multiset when no listed section moved (a merge with other symbols
# reordered or NEW at a third place, or a rename with two symbols swapped);
# or when an address-significance table whose characteristics differ under
# a merge raises an error in place of a difference line; or when
# SYMBOL-ORDER is reported where the symbol multisets differ. The tests write small objects, logs and
# a fake compiler and run on every host. Blind spot: the objects
# are hand-made, not compiler output. A test method added to the .py but not
# to this list never runs.
set(tools_object_proof_cases identical timestamp rename refused_renames unmatched_rename
    structural_differences difference unreadable warnings proof_compile counts section_equal
    alignment addrsig_encoding base_holds_both summary symbol_shift expect_kept kept_holes
    expect_kept_file kept_identical beside_kept compile_source source_fails_closed kept_symbol
    refusal_alone base_holds_new merge_attacks function_order symbol_order_only_when_equal
    function_order_keeps_symbol_order merge_addrsig_characteristics merge_symbol_kinds
    function_order_fixed_sections)
if(Python3_Interpreter_FOUND)
  foreach(tools_object_proof_case IN LISTS tools_object_proof_cases)
    add_test(NAME tools.object_proof.${tools_object_proof_case}
      COMMAND ${Python3_EXECUTABLE} -B "${PROJECT_SOURCE_DIR}/tools/object-proof/test_object_proof.py"
              ObjectProofTest.test_${tools_object_proof_case})
  endforeach()
else()
  string(CONCAT tools_object_proof_missing
    "Python 3 was not found when configuring, so the tools.object_proof tests "
    "cannot run (tools/object-proof). Install Python 3 and configure again.")
  message(WARNING "${tools_object_proof_missing}")
  foreach(tools_object_proof_case IN LISTS tools_object_proof_cases)
    add_test(NAME tools.object_proof.${tools_object_proof_case}
      COMMAND ${CMAKE_COMMAND} -E echo "${tools_object_proof_missing}")
    set_tests_properties(tools.object_proof.${tools_object_proof_case} PROPERTIES
      FAIL_REGULAR_EXPRESSION "Python 3 was not found")
  endforeach()
endif()
