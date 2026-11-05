if(NOT DEFINED PROGRAM OR NOT DEFINED MODE)
  message(FATAL_ERROR "PROGRAM and MODE are required")
endif()
execute_process(
  COMMAND "${PROGRAM}" "${MODE}"
  RESULT_VARIABLE result
  OUTPUT_VARIABLE output
  ERROR_VARIABLE error
)
if(NOT result STREQUAL "Subprocess aborted")
  message(FATAL_ERROR "Expected abort, got '${result}': ${output}${error}")
endif()
string(FIND "${error}" "Havok native base owners are ready, but the legacy singleton graph is not migrated." diagnostic)
string(FIND "${error}" "actual-game-entry-abort" marker)
if(diagnostic EQUAL -1 OR marker EQUAL -1)
  message(FATAL_ERROR "Abort lacked expected diagnostic or marker: ${output}${error}")
endif()
