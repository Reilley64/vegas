# Writes the header that names the commit vegas-setup is built from
# (VEGAS-107; docs/setup.md). The build runs this script on every build and
# passes an OUTPUT in the build folder. It rewrites OUTPUT only when the text
# changes, so setup_main.cpp is compiled again only then.
#
# cmake -DSOURCE_DIR=<checkout> -DOUTPUT=<header> [-DGIT_EXECUTABLE=<git>] -P build_commit.cmake
#
# The text is "<commit>, no local changes" when `git status --porcelain`
# prints nothing, "<commit>, with local changes" when it prints a line, and
# "<commit>, local changes unknown" when it fails. It is "unknown" without
# git, or when SOURCE_DIR is not the top of its own checkout, such as a git
# archive export, even one inside another checkout.
#
# An exported GIT_DIR, GIT_WORK_TREE or GIT_INDEX_FILE would make git read
# another repository or index than SOURCE_DIR's own, so the script removes
# them first. --untracked-files=normal lists an untracked file even when the
# user's status.showUntrackedFiles is no.

unset(ENV{GIT_DIR})
unset(ENV{GIT_WORK_TREE})
unset(ENV{GIT_INDEX_FILE})

set(commit "unknown")
if(GIT_EXECUTABLE)
  execute_process(COMMAND "${GIT_EXECUTABLE}" rev-parse --show-prefix
    WORKING_DIRECTORY "${SOURCE_DIR}"
    RESULT_VARIABLE prefix_status OUTPUT_VARIABLE prefix
    OUTPUT_STRIP_TRAILING_WHITESPACE ERROR_QUIET)
  if(prefix_status EQUAL 0 AND prefix STREQUAL "")
    execute_process(COMMAND "${GIT_EXECUTABLE}" rev-parse --verify "HEAD^{commit}"
      WORKING_DIRECTORY "${SOURCE_DIR}"
      RESULT_VARIABLE head_status OUTPUT_VARIABLE head
      OUTPUT_STRIP_TRAILING_WHITESPACE ERROR_QUIET)
    if(head_status EQUAL 0 AND head MATCHES "^[0-9a-f]+$")
      # --no-optional-locks: the status must not write the checkout's index.
      execute_process(COMMAND "${GIT_EXECUTABLE}" --no-optional-locks status --porcelain
        --untracked-files=normal
        WORKING_DIRECTORY "${SOURCE_DIR}"
        RESULT_VARIABLE status_status OUTPUT_VARIABLE status
        ERROR_QUIET)
      if(NOT status_status EQUAL 0)
        set(commit "${head}, local changes unknown")
      elseif(status STREQUAL "")
        set(commit "${head}, no local changes")
      else()
        set(commit "${head}, with local changes")
      endif()
    endif()
  endif()
endif()

file(CONFIGURE OUTPUT "${OUTPUT}" @ONLY CONTENT
"// Written by src/setup/build_commit.cmake in the build folder (VEGAS-107).
#define VEGAS_SETUP_BUILD_COMMIT \"${commit}\"
")
