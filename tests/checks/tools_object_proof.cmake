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
# difference; when objcmp.py counts RENAME- lines as differences, stops
# saying what a changed section keeps equal, stops naming each added,
# removed or moved address-significance entry, stops printing changed
# characteristics in hexadecimal with a changed alignment, reads a padded or
# truncated address-significance index, or stops refusing, with no artefact
# line, a base that holds both spellings of a rename, or its summary or
# --json report stops listing the retargets, kept sites and symbols that a
# section shifts, or --expect-kept passes a comparison with a kept site
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
# #error canary does not show to take effect. The tests write small objects,
# logs and a fake compiler and run on every host. Blind spot: the objects
# are hand-made, not compiler output. A test method added to the .py but not
# to this list never runs.
set(tools_object_proof_cases identical timestamp rename refused_renames unmatched_rename
    structural_differences difference unreadable warnings proof_compile counts section_equal
    alignment addrsig_encoding base_holds_both summary symbol_shift expect_kept kept_holes
    expect_kept_file kept_identical beside_kept compile_source source_fails_closed kept_symbol)
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
