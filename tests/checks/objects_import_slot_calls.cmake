# Fails when a function that calls imported functions through their SDK
# declarations (VEGAS-135; GetSaveDirectory, 0x00876ad0) again refers to a
# generated import slot variable or to an import's thunk, which a definition
# in the unit that takes the address of a generated asm label of the
# import's name makes of an SDK call, or no longer refers
# to the import library's __imp_ slot of each import it calls
# (tools/function-relocations/import-slot-calls.tsv). Blind spots: those of
# tools/function-relocations; it counts names, not calls, so the number and
# order of the calls and their arguments are not checked (the object proof
# of VEGAS-135 lists them).
if(vegas_object_checks)
  add_test(NAME objects.import_slot_calls
    COMMAND ${GO_EXECUTABLE} run . --table import-slot-calls.tsv
            --objects ${CMAKE_CURRENT_BINARY_DIR}/game-objects.txt
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tools/function-relocations)
endif()
