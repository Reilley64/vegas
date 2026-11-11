# The Steamworks SDK's licence does not allow its headers to be published, so a build that
# targets Windows takes the SDK from a folder on the machine instead of downloading it. The folder is
# the STEAMWORKS_SDK CMake variable or, when that is unset or empty, the STEAMWORKS_SDK
# environment variable. Builds for other systems do not use the SDK and are not checked.
if(NOT CMAKE_SYSTEM_NAME STREQUAL "Windows")
  return()
endif()

set(steamworks_sdk "${STEAMWORKS_SDK}")
set(steamworks_sdk_source "CMake variable")
if(steamworks_sdk STREQUAL "")
  set(steamworks_sdk "$ENV{STEAMWORKS_SDK}")
  set(steamworks_sdk_source "environment variable")
endif()
set(steamworks_sdk_help "Set the STEAMWORKS_SDK CMake variable (-DSTEAMWORKS_SDK=<folder>) or the STEAMWORKS_SDK environment variable to the Steamworks SDK folder, the one that holds public/steam/steam_api.h.")
if(steamworks_sdk STREQUAL "")
  message(FATAL_ERROR "STEAMWORKS_SDK is not set. ${steamworks_sdk_help}")
endif()
# A Windows path may use backslashes. file(TO_CMAKE_PATH) is not used: it reads its input
# as a search path and splits it at every ':' on hosts other than Windows.
string(REPLACE "\\" "/" steamworks_sdk "${steamworks_sdk}")
foreach(file IN ITEMS
    public/steam/steam_api.h
    redistributable_bin/win64/steam_api64.lib
    redistributable_bin/win64/steam_api64.dll)
  if(NOT EXISTS "${steamworks_sdk}/${file}")
    message(FATAL_ERROR "The STEAMWORKS_SDK ${steamworks_sdk_source} is \"${steamworks_sdk}\", which has no ${file}. ${steamworks_sdk_help}")
  endif()
endforeach()
