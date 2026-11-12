# Copies PROGRAM, the built FalloutNV.exe, alone into FOLDER/executable and
# runs it there with FOLDER/working as its working directory. FIXTURE writes a
# complete synthetic data pack whose mutex name is new to this run.
#
# MODE with-pack: the pack is written beside the copy; the run must exit 0.
# MODE without-pack: the pack is written only in the working directory; the
# run must exit 2 and report on the standard error stream that the pack
# beside the executable is missing.
#
# Before the run, FIXTURE --check makes the calls of the single-instance check
# on the same mutex name with the message box recorded. When main would show a
# message box, because the session is remote or the mutex exists, the program
# is not run and the test is skipped, so no message box can appear. Each run
# also has TIMEOUT seconds: a run that waits fails instead of holding the
# runner.
if(NOT DEFINED PROGRAM OR NOT DEFINED FIXTURE OR NOT DEFINED FOLDER OR NOT DEFINED MODE OR NOT DEFINED TIMEOUT)
  message(FATAL_ERROR "PROGRAM, FIXTURE, FOLDER, MODE and TIMEOUT are required")
endif()
file(REMOVE_RECURSE "${FOLDER}")
file(MAKE_DIRECTORY "${FOLDER}/executable" "${FOLDER}/working")
file(COPY "${PROGRAM}" DESTINATION "${FOLDER}/executable")
get_filename_component(name "${PROGRAM}" NAME)
if(MODE STREQUAL "with-pack")
  set(pack "${FOLDER}/executable/vegas-data.pack")
elseif(MODE STREQUAL "without-pack")
  set(pack "${FOLDER}/working/vegas-data.pack")
else()
  message(FATAL_ERROR "Unknown MODE '${MODE}'")
endif()
string(RANDOM LENGTH 8 ALPHABET 0123456789abcdef suffix)
set(mutex "vegas-pe-${suffix}")
execute_process(COMMAND "${FIXTURE}" --check "${mutex}" TIMEOUT ${TIMEOUT} RESULT_VARIABLE checked
  OUTPUT_VARIABLE checkOutput ERROR_VARIABLE checkError)
if(checked EQUAL 3)
  file(REMOVE_RECURSE "${FOLDER}")
  message("SKIPPED: the single-instance check would show a message box here: ${checkOutput}")
  return()
endif()
if(NOT checked EQUAL 0)
  message(FATAL_ERROR "The single-instance check could not be made: '${checked}': ${checkOutput}${checkError}")
endif()
execute_process(COMMAND "${FIXTURE}" "${pack}" "${mutex}" RESULT_VARIABLE written)
if(NOT written EQUAL 0)
  message(FATAL_ERROR "The fixture did not write the pack: ${written}")
endif()
execute_process(
  COMMAND "${FOLDER}/executable/${name}"
  WORKING_DIRECTORY "${FOLDER}/working"
  TIMEOUT ${TIMEOUT}
  RESULT_VARIABLE result
  OUTPUT_VARIABLE output
  ERROR_VARIABLE error
)
file(REMOVE_RECURSE "${FOLDER}")
if(NOT result MATCHES "^-?[0-9]+$")
  message(FATAL_ERROR "The run did not exit: '${result}': ${output}${error}")
endif()
if(MODE STREQUAL "with-pack")
  if(NOT result EQUAL 0)
    message(FATAL_ERROR "Expected exit code 0, got ${result}: ${output}${error}")
  endif()
else()
  if(NOT result EQUAL 2)
    message(FATAL_ERROR "Expected exit code 2, got ${result}: ${output}${error}")
  endif()
  string(FIND "${error}" "vegas-data.pack is missing beside the executable" missing)
  if(missing EQUAL -1)
    message(FATAL_ERROR "Expected the missing pack to be reported, got: ${output}${error}")
  endif()
endif()
