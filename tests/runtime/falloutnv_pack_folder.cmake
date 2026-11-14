# Copies PROGRAM, the built FalloutNV.exe, alone into FOLDER/executable and
# runs it there with FOLDER/working as its working directory. FIXTURE writes a
# complete synthetic data pack whose mutex name and main window class name are
# one name new to this run.
#
# MODE with-pack: the pack is written beside the copy; the run must exit 0.
# MODE without-pack: the pack is written only in the working directory; the
# run must exit 2 and report on the standard error stream that the pack
# beside the executable is missing.
#
# In with-pack mode, before the run, FIXTURE --check makes the calls of the
# single-instance check on the same mutex name with the message box recorded,
# and names the decision on a line of its own. Only when it names a remote
# session is the program not run and the test skipped, so no message box can
# appear. A mutex that already exists under a name new to this run fails the
# test. After Continue, FIXTURE --check also makes the second-window check on
# the same name as the class name, with the real window search and the
# foreground call recorded, and names that decision on a line of its own. A
# window of a class whose name is new to this run fails the test, so a window
# on the runner cannot make main return before its checks are done, and so
# does any other result. Without the pack, main returns before CreateMutexA
# and can show no message box, so no check is made. Each run also has TIMEOUT
# seconds: a run that waits fails instead of holding the runner.
#
# In both modes, after the run FOLDER must hold the copy, the pack and the two
# folders the test made, and no other file or folder: main, which builds four
# log paths in memory (VEGAS-127), creates nothing in the executable's folder
# or in the working directory. Folders are listed too, so an empty folder
# left behind fails (VEGAS-130). Files and folders elsewhere are not looked
# for.
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
if(MODE STREQUAL "with-pack")
  execute_process(COMMAND "${FIXTURE}" --check "${mutex}" TIMEOUT ${TIMEOUT} RESULT_VARIABLE checked
    OUTPUT_VARIABLE checkOutput ERROR_VARIABLE checkError)
  if(checked EQUAL 3 AND checkOutput MATCHES "(^|\n)single-instance check: RemoteSession\r?\n")
    file(REMOVE_RECURSE "${FOLDER}")
    message("SKIPPED: the session is remote, so main would show a message box: ${checkOutput}")
    return()
  endif()
  if(checkOutput MATCHES "(^|\n)single-instance check: AlreadyRunning\r?\n")
    message(FATAL_ERROR
      "The mutex ${mutex}, new to this run, already exists: '${checked}': ${checkOutput}${checkError}")
  endif()
  if(NOT checkOutput MATCHES "(^|\n)single-instance check: Continue\r?\n")
    message(FATAL_ERROR "The single-instance check could not be made: '${checked}': ${checkOutput}${checkError}")
  endif()
  if(checkOutput MATCHES "(^|\n)second-window check: AlreadyOpen\r?\n")
    message(FATAL_ERROR
      "A window of the class ${mutex}, new to this run, already exists: '${checked}': ${checkOutput}${checkError}")
  endif()
  if(NOT checked EQUAL 0 OR NOT checkOutput MATCHES "(^|\n)second-window check: Continue\r?\n")
    message(FATAL_ERROR "The second-window check could not be made: '${checked}': ${checkOutput}${checkError}")
  endif()
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
file(GLOB_RECURSE left LIST_DIRECTORIES true RELATIVE "${FOLDER}" "${FOLDER}/*")
list(SORT left)
file(RELATIVE_PATH packLeft "${FOLDER}" "${pack}")
set(expected executable "executable/${name}" working "${packLeft}")
list(SORT expected)
file(REMOVE_RECURSE "${FOLDER}")
if(NOT result MATCHES "^-?[0-9]+$")
  message(FATAL_ERROR "The run did not exit: '${result}': ${output}${error}")
endif()
if(NOT left STREQUAL expected)
  message(FATAL_ERROR "After the run the folder holds '${left}', not only '${expected}': ${output}${error}")
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
