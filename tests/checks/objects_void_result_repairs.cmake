# Fails when a body that VEGAS-124 repaired to return the value it
# computes is not defined under its row's name, which carries the result,
# or when a listed function refers to the former void name
# (tools/function-relocations/void-result-repairs.tsv). Blind spots: those
# of tools/function-relocations; it reads names, not instructions, so it
# does not see which value the body leaves in the return register.
if(vegas_object_checks)
  add_test(NAME objects.void_result_repairs
    COMMAND ${GO_EXECUTABLE} run . --table void-result-repairs.tsv
            --objects ${CMAKE_CURRENT_BINARY_DIR}/game-objects.txt
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tools/function-relocations)
endif()
