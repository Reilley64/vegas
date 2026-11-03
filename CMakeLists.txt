cmake_minimum_required(VERSION 3.28)

project(vegas LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

enable_testing()

add_subdirectory(third_party)

add_library(game STATIC
  src/fileformat/compression.cpp
  src/fileformat/plugin_header.cpp
  src/runtime/crt.cpp
)
target_include_directories(game PUBLIC src)
target_link_libraries(game PRIVATE ZLIB::ZLIBSTATIC)
include(src/generated/data/sources.cmake)
include(src/bs_speedtree_sources.cmake)
include(src/gamebryo2.2/sources.cmake)
include(src/havok/common/sources.cmake)
include(src/havok/animation/sources.cmake)
include(src/havok/unplaced/sources.cmake)
include(src/root_sources.cmake)

add_executable(FalloutNV EXCLUDE_FROM_ALL src/main.cpp src/runtime/new.cpp)
target_include_directories(FalloutNV PRIVATE include)
target_link_libraries(FalloutNV PRIVATE game)

add_subdirectory(tests)
