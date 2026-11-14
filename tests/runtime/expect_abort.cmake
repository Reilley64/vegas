# Runs PROGRAM with MODE and requires it to print MARKER and then abort.
if(NOT DEFINED PROGRAM OR NOT DEFINED MODE OR NOT DEFINED MARKER)
  message(FATAL_ERROR "PROGRAM, MODE and MARKER are required")
endif()
execute_process(
  COMMAND "${PROGRAM}" "${MODE}"
  RESULT_VARIABLE result
  OUTPUT_VARIABLE output
  ERROR_VARIABLE error
)
string(FIND "${error}" "${MARKER}" marker)
if(marker EQUAL -1)
  message(FATAL_ERROR "The program did not reach '${MARKER}': ${output}${error}")
endif()
if(WIN32)
  if(result EQUAL 0)
    message(FATAL_ERROR "Expected abort, got '${result}': ${output}${error}")
  endif()
elseif(NOT result STREQUAL "Subprocess aborted")
  message(FATAL_ERROR "Expected abort, got '${result}': ${output}${error}")
endif()
