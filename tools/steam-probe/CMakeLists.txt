cmake_minimum_required(VERSION 3.25)
project(steam_probe LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(FATAL_ERROR "The Steam probe builds only for 64-bit build targets.")
endif()

set(STEAMWORKS_SDK "$ENV{STEAMWORKS_SDK}" CACHE PATH "Steamworks SDK folder, the one that holds public/steam/steam_api.h")
if(NOT EXISTS "${STEAMWORKS_SDK}/public/steam/steam_api.h")
    message(FATAL_ERROR "STEAMWORKS_SDK must name the Steamworks SDK folder, the one that holds public/steam/steam_api.h. It is \"${STEAMWORKS_SDK}\".")
endif()

set(steam_bin "${STEAMWORKS_SDK}/redistributable_bin")
add_library(steam_api SHARED IMPORTED)
target_include_directories(steam_api INTERFACE "${STEAMWORKS_SDK}/public")
if(WIN32)
    set(steam_runtime "${steam_bin}/win64/steam_api64.dll")
    set_target_properties(steam_api PROPERTIES IMPORTED_IMPLIB "${steam_bin}/win64/steam_api64.lib")
elseif(APPLE)
    set(steam_runtime "${steam_bin}/osx/libsteam_api.dylib")
else()
    set(steam_runtime "${steam_bin}/linux64/libsteam_api.so")
endif()
set_target_properties(steam_api PROPERTIES IMPORTED_LOCATION "${steam_runtime}")

# The static C++ runtime keeps the Microsoft Visual C++ Redistributable out of the test.
set(CMAKE_MSVC_RUNTIME_LIBRARY MultiThreaded)

# Named FalloutNV so that Steam starts it in place of the original release's executable.
add_executable(steam_probe main.cpp)
set_target_properties(steam_probe PROPERTIES OUTPUT_NAME FalloutNV)
target_link_libraries(steam_probe PRIVATE steam_api)
if(WIN32)
    target_compile_definitions(steam_probe PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()
if(UNIX AND NOT APPLE)
    set_target_properties(steam_probe PROPERTIES BUILD_RPATH "$ORIGIN")
endif()
add_custom_command(TARGET steam_probe POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${steam_runtime}" "$<TARGET_FILE_DIR:steam_probe>")
