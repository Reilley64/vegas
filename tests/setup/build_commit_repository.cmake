# Runs src/setup/build_commit.cmake on a git repository that the test
# creates in WORK (VEGAS-107; docs/setup.md). CASE names what it checks:
#
# - no_changes: a clean checkout names its commit and "no local changes",
#   also when GIT_INDEX_FILE names another index or GIT_WORK_TREE another
#   folder.
# - with_changes: a changed tracked file gives "with local changes".
# - hidden_untracked: an untracked file gives "with local changes" even when
#   the repository sets status.showUntrackedFiles to no.
# - git_dir: an empty folder, as a git archive export, names "unknown" even
#   when GIT_DIR, or GIT_DIR and GIT_WORK_TREE, name the test's repository.
#
# cmake -DGENERATOR=<build_commit.cmake> -DWORK=<folder> -DGIT_EXECUTABLE=<git> -DCASE=<case> -P build_commit_repository.cmake

# The test's own git commands must not follow a git environment that ctest
# was started with.
unset(ENV{GIT_DIR})
unset(ENV{GIT_WORK_TREE})
unset(ENV{GIT_INDEX_FILE})

set(repo "${WORK}/repo")
set(header "${WORK}/vegas_setup_build_commit.h")

function(run_git)
  execute_process(COMMAND "${GIT_EXECUTABLE}" ${ARGN}
    WORKING_DIRECTORY "${repo}"
    RESULT_VARIABLE status OUTPUT_VARIABLE out ERROR_VARIABLE err
    OUTPUT_STRIP_TRAILING_WHITESPACE)
  if(NOT status STREQUAL "0")
    message(FATAL_ERROR "git ${ARGN} ended with status '${status}':\n${err}")
  endif()
  set(git_out "${out}" PARENT_SCOPE)
endfunction()

# Runs the generator on SOURCE with the environment assignments in ARGN and
# requires the header to name EXPECTED.
function(expect_commit source expected)
  file(REMOVE "${header}")
  execute_process(COMMAND "${CMAKE_COMMAND}" -E env ${ARGN}
    "${CMAKE_COMMAND}" "-DSOURCE_DIR=${source}" "-DOUTPUT=${header}"
    "-DGIT_EXECUTABLE=${GIT_EXECUTABLE}" -P "${GENERATOR}"
    RESULT_VARIABLE status)
  if(NOT status STREQUAL "0")
    message(FATAL_ERROR "build_commit.cmake ended with status '${status}'")
  endif()
  file(READ "${header}" text)
  if(NOT text MATCHES "\n#define VEGAS_SETUP_BUILD_COMMIT \"([^\"]*)\"\n$")
    message(FATAL_ERROR "the header has no commit line:\n${text}")
  endif()
  if(NOT CMAKE_MATCH_1 STREQUAL expected)
    message(FATAL_ERROR "case ${CASE} with '${ARGN}': the header names '${CMAKE_MATCH_1}', not '${expected}'")
  endif()
endfunction()

# A repository with one commit. Identity, signing and hooks are set on the
# command line, so the user's git configuration cannot stop the commit; the
# hooks folder is empty.
file(REMOVE_RECURSE "${WORK}")
file(MAKE_DIRECTORY "${repo}" "${WORK}/hooks" "${WORK}/export")
run_git(init --quiet)
file(WRITE "${repo}/tracked.txt" "first\n")
run_git(add tracked.txt)
run_git(-c user.name=test -c user.email=test
  -c commit.gpgsign=false -c "core.hooksPath=${WORK}/hooks"
  commit --quiet -m first)
run_git(rev-parse --verify "HEAD^{commit}")
set(head "${git_out}")

if(CASE STREQUAL "no_changes")
  expect_commit("${repo}" "${head}, no local changes")
  expect_commit("${repo}" "${head}, no local changes"
    "GIT_INDEX_FILE=${WORK}/missing-index")
  expect_commit("${repo}" "${head}, no local changes"
    "GIT_WORK_TREE=${WORK}/export")
elseif(CASE STREQUAL "with_changes")
  file(WRITE "${repo}/tracked.txt" "second\n")
  expect_commit("${repo}" "${head}, with local changes")
elseif(CASE STREQUAL "hidden_untracked")
  run_git(config status.showUntrackedFiles no)
  file(WRITE "${repo}/untracked.txt" "untracked\n")
  expect_commit("${repo}" "${head}, with local changes")
elseif(CASE STREQUAL "git_dir")
  expect_commit("${WORK}/export" "unknown" "GIT_DIR=${repo}/.git")
  expect_commit("${WORK}/export" "unknown" "GIT_DIR=${repo}/.git"
    "GIT_WORK_TREE=${WORK}/export")
else()
  message(FATAL_ERROR "unknown CASE '${CASE}'")
endif()
file(REMOVE_RECURSE "${WORK}")
