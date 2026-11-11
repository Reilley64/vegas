# Runs the Steamworks SDK check as a script against folders this script makes, with the
# target system given, and requires the result and the error text of each case.
if(NOT DEFINED MODULE OR NOT DEFINED WORK)
  message(FATAL_ERROR "MODULE and WORK are required")
endif()

file(REMOVE_RECURSE "${WORK}")
set(header public/steam/steam_api.h)
set(library redistributable_bin/win64/steam_api64.lib)
set(runtime redistributable_bin/win64/steam_api64.dll)
file(MAKE_DIRECTORY "${WORK}/empty")
# A ':' cannot be in a folder name on Windows.
set(complete_folders complete other_complete "with space")
if(NOT CMAKE_HOST_WIN32)
  list(APPEND complete_folders "with:colon")
endif()
foreach(file IN ITEMS "${header}" "${library}" "${runtime}")
  foreach(folder IN LISTS complete_folders)
    file(WRITE "${WORK}/${folder}/${file}" "")
  endforeach()
endforeach()
file(WRITE "${WORK}/no_header/${library}" "")
file(WRITE "${WORK}/no_header/${runtime}" "")
file(WRITE "${WORK}/no_library/${header}" "")
file(WRITE "${WORK}/no_library/${runtime}" "")
file(WRITE "${WORK}/no_runtime/${header}" "")
file(WRITE "${WORK}/no_runtime/${library}" "")

# NAME is the case and SYSTEM the target system. ENVIRONMENT is the value of the
# environment variable, or empty to leave it unset. EXPECT is a list of texts the error
# must hold, or empty when the check must pass. The remaining arguments go to cmake.
function(check name system environment expect)
  if(environment STREQUAL "")
    unset(ENV{STEAMWORKS_SDK})
  else()
    set(ENV{STEAMWORKS_SDK} "${environment}")
  endif()
  execute_process(
    COMMAND "${CMAKE_COMMAND}" "-DCMAKE_SYSTEM_NAME=${system}" ${ARGN} -P "${MODULE}"
    RESULT_VARIABLE result
    OUTPUT_VARIABLE output
    ERROR_VARIABLE error
  )
  if(expect STREQUAL "")
    if(NOT result EQUAL 0)
      message(FATAL_ERROR "${name}: expected the check to pass, got '${result}': ${output}${error}")
    endif()
    return()
  endif()
  if(result EQUAL 0)
    message(FATAL_ERROR "${name}: expected the check to stop: ${output}${error}")
  endif()
  # CMake wraps the lines of an error message.
  string(REGEX REPLACE "[ \n]+" " " error "${error}")
  foreach(text IN LISTS expect)
    string(FIND "${error}" "${text}" found)
    if(found EQUAL -1)
      message(FATAL_ERROR "${name}: the error does not hold '${text}': ${output}${error}")
    endif()
  endforeach()
endfunction()

set(names "STEAMWORKS_SDK CMake variable (;STEAMWORKS_SDK environment variable to")
set(from_variable "The STEAMWORKS_SDK CMake variable is")
set(from_environment "The STEAMWORKS_SDK environment variable is")

check(unset Windows "" "STEAMWORKS_SDK is not set;${names}")
check(empty_value Windows "" "STEAMWORKS_SDK is not set;${names}" -DSTEAMWORKS_SDK=)
check(missing_folder Windows "" "has no ${header};${names}" "-DSTEAMWORKS_SDK=${WORK}/missing")
check(empty_folder Windows "" "${from_variable} \"${WORK}/empty\", which has no ${header};${names}" "-DSTEAMWORKS_SDK=${WORK}/empty")
check(no_header Windows "" "has no ${header};${names}" "-DSTEAMWORKS_SDK=${WORK}/no_header")
check(no_library Windows "" "has no ${library};${names}" "-DSTEAMWORKS_SDK=${WORK}/no_library")
check(no_runtime Windows "" "has no ${runtime};${names}" "-DSTEAMWORKS_SDK=${WORK}/no_runtime")
check(complete Windows "" "" "-DSTEAMWORKS_SDK=${WORK}/complete")

check(environment_empty_folder Windows "${WORK}/empty" "${from_environment} \"${WORK}/empty\", which has no ${header};${names}")
check(environment_complete Windows "${WORK}/complete" "")
check(environment_under_empty_value Windows "${WORK}/complete" "" -DSTEAMWORKS_SDK=)
check(environment_empty_folder_under_empty_value Windows "${WORK}/empty" "${from_environment} \"${WORK}/empty\"" -DSTEAMWORKS_SDK=)

# The CMake variable is used when both are set.
check(variable_over_environment Windows "${WORK}/empty" "" "-DSTEAMWORKS_SDK=${WORK}/other_complete")
check(variable_over_complete_environment Windows "${WORK}/complete" "${from_variable} \"${WORK}/empty\", which has no ${header}" "-DSTEAMWORKS_SDK=${WORK}/empty")

# Backslashes separate folders, as in a path Windows gives. The error shows the path with slashes.
string(REPLACE "/" "\\" backslash_work "${WORK}")
check(backslash_variable Windows "" "" "-DSTEAMWORKS_SDK=${backslash_work}\\complete")
check(backslash_environment Windows "${backslash_work}\\complete" "")
check(backslash_empty_folder Windows "${backslash_work}\\empty" "${from_environment} \"${WORK}/empty\", which has no ${header}")

# The value is one folder, not a list of folders.
check(space_variable Windows "" "" "-DSTEAMWORKS_SDK=${WORK}/with space")
check(space_environment Windows "${WORK}/with space" "")
if(NOT CMAKE_HOST_WIN32)
  check(colon_variable Windows "" "" "-DSTEAMWORKS_SDK=${WORK}/with:colon")
  check(colon_environment Windows "${WORK}/with:colon" "")
endif()

# A build for another system needs no SDK and does not look at a folder it is given.
foreach(system IN ITEMS Darwin Linux)
  check(${system}_unset ${system} "" "")
  check(${system}_empty_folder ${system} "${WORK}/empty" "" "-DSTEAMWORKS_SDK=${WORK}/empty")
endforeach()
