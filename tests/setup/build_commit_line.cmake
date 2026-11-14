# Runs vegas-setup with no argument (VEGAS-107; docs/setup.md). It must end
# with status 1, print nothing to standard output, and print two lines to
# standard error: the commit it was built from, then the usage line. The test
# checks the format of the first line, not a particular commit, and shows it.
#
# cmake -DPROGRAM=<vegas-setup> -P build_commit_line.cmake

execute_process(COMMAND "${PROGRAM}"
  RESULT_VARIABLE status OUTPUT_VARIABLE out ERROR_VARIABLE err)
if(NOT status STREQUAL "1")
  message(FATAL_ERROR "vegas-setup with no argument ended with status '${status}', not 1")
endif()
if(NOT out STREQUAL "")
  message(FATAL_ERROR "vegas-setup printed to standard output:\n${out}")
endif()
if(NOT err MATCHES "^vegas-setup: built from commit ([^\r\n]*)\r?\nvegas-setup: usage: vegas-setup <install folder>\r?\n$")
  message(FATAL_ERROR "vegas-setup's standard error is not the commit line and the usage line:\n${err}")
endif()
set(commit "${CMAKE_MATCH_1}")
if(NOT commit STREQUAL "unknown")
  if(NOT commit MATCHES "^([0-9a-f]+), (no local changes|with local changes|local changes unknown)$")
    message(FATAL_ERROR "the commit line names '${commit}', not a commit and its local changes")
  endif()
  # A SHA-1 or a SHA-256 commit id.
  string(LENGTH "${CMAKE_MATCH_1}" length)
  if(NOT length EQUAL 40 AND NOT length EQUAL 64)
    message(FATAL_ERROR "the commit id '${CMAKE_MATCH_1}' has ${length} digits")
  endif()
endif()
message(STATUS "vegas-setup printed: vegas-setup: built from commit ${commit}")
