# Runs src/setup/build_commit.cmake on an empty folder, as a git archive
# export without .git is (VEGAS-107). The folder lies in the build folder,
# which may be inside a checkout. The header must name the commit "unknown".
#
# cmake -DGENERATOR=<build_commit.cmake> -DWORK=<folder> [-DGIT_EXECUTABLE=<git>] -P build_commit_export.cmake

file(REMOVE_RECURSE "${WORK}")
file(MAKE_DIRECTORY "${WORK}/export")
execute_process(COMMAND "${CMAKE_COMMAND}" "-DSOURCE_DIR=${WORK}/export"
  "-DOUTPUT=${WORK}/vegas_setup_build_commit.h" "-DGIT_EXECUTABLE=${GIT_EXECUTABLE}"
  -P "${GENERATOR}"
  RESULT_VARIABLE status)
if(NOT status STREQUAL "0")
  message(FATAL_ERROR "build_commit.cmake ended with status '${status}'")
endif()
file(READ "${WORK}/vegas_setup_build_commit.h" header)
if(NOT header MATCHES "\n#define VEGAS_SETUP_BUILD_COMMIT \"unknown\"\n$")
  message(FATAL_ERROR "the header for a folder without .git does not name \"unknown\":\n${header}")
endif()
file(REMOVE_RECURSE "${WORK}")
