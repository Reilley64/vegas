cmake_minimum_required(VERSION 3.28)

project(vegas LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

enable_testing()

add_subdirectory(third_party)

# llvm-lib stores members in reverse input order. The canonical LOS owner is
# listed first so that it is the one member stored after the accepted 2,218.
add_library(game STATIC
  src/fallout_shared/pathfinding/los_map_array.cpp
  src/bscore/legacy_memory_manager_startup.cpp
  src/gamebryo2.2/corelibs/nimain/nipalette_memory.cpp
  src/bscore/engine_virtual_memory.cpp
  src/bscore/engine_memory_heap.cpp
  src/bscore/engine_heap_set.cpp
  src/bscore/fixed_pool.cpp
  src/bscore/canonical_memory_manager.cpp
  src/fallout/misc/native_memory_pools.cpp
  src/fileformat/compression.cpp
  src/fileformat/plugin_header.cpp
  src/runtime/crt.cpp
  src/runtime/endian_u16.cpp
  src/runtime/endian_u32.cpp
  src/runtime/havok_router_tls.cpp
  src/runtime/havok_memory_prerequisite.cpp
  src/runtime/tls.cpp
)
target_include_directories(game PUBLIC src)
set_source_files_properties(
  src/bscore/legacy_memory_manager_startup.cpp
  src/gamebryo2.2/corelibs/nimain/nipalette_memory.cpp
  src/bscore/engine_virtual_memory.cpp
  src/bscore/engine_memory_heap.cpp
  src/bscore/engine_heap_set.cpp
  src/bscore/fixed_pool.cpp
  src/bscore/canonical_memory_manager.cpp
  src/fallout/misc/native_memory_pools.cpp
  src/speedtree/native_string.cpp
  src/gamebryo2.2/corelibs/nisystem/ni_allocator_holder.cpp
  src/gamebryo2.2/corelibs/nimain/native_fixed_string.cpp
  src/fallout_shared/pathfinding/los_map_array.cpp
  src/bscore/memory_manager_startup.cpp
  src/gamebryo2.2/corelibs/nimain/nirefobject_lifetime.cpp
  src/gamebryo2.2/corelibs/nianimation/nianimationkey_tables.cpp
  PROPERTIES INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/include")
set_source_files_properties(src/runtime/endian_u16.cpp src/runtime/endian_u32.cpp PROPERTIES INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/include")
set_source_files_properties(src/runtime/havok_router_tls.cpp PROPERTIES INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(game PRIVATE ZLIB::ZLIBSTATIC)
include(src/generated/data/sources.cmake)
include(src/bs_speedtree_sources.cmake)
include(src/gamebryo2.2/sources.cmake)
include(src/havok/physics/sources.cmake)
include(src/havok/common/sources.cmake)
include(src/havok/animation/sources.cmake)
include(src/havok/unplaced/sources.cmake)
include(src/root_sources.cmake)
include(src/fallout_shared/sources.cmake)
include(src/staging/sources.cmake)
include(src/fallout/sources.cmake)
include(src/runtime/native_data_composition.cmake)
# One COMDAT data section per table of the generated vtable units (VEGAS-30),
# so that a link keeps only the tables something refers to. It is a compile
# option, not an edit of the generated files. No known read passes the end of
# a table (docs/table-slot-reads.md), so all fifteen units take it. Only
# compilers with the MSVC command line take /Gw; the host's AppleClang builds
# the units as before.
if(CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
  get_target_property(vegas_vtable_sources game SOURCES)
  list(FILTER vegas_vtable_sources INCLUDE REGEX "generated/data/vtables_01[0-9a-f][0-9a-f]\\.cpp$")
  list(LENGTH vegas_vtable_sources vegas_vtable_count)
  if(NOT vegas_vtable_count EQUAL 15)
    message(FATAL_ERROR "expected 15 generated vtable units with /Gw, found ${vegas_vtable_count}")
  endif()
  set_property(SOURCE ${vegas_vtable_sources} TARGET_DIRECTORY game APPEND PROPERTY COMPILE_OPTIONS /Gw)
endif()
# Keep the accepted 2,217 logical-member sequence intact; the canonical native
# string owner, the Ni allocator holder, the native global string table owner,
# the process memory startup, the NiRefObject lifetime owner, the structural
# reader of the data pack, the data pack container layout, the data pack
# writer, the PE file reader and then the original release identification are
# the only appended production members, in that order.
target_sources(game PRIVATE src/speedtree/native_string.cpp)
target_sources(game PRIVATE src/gamebryo2.2/corelibs/nisystem/ni_allocator_holder.cpp)
target_sources(game PRIVATE src/gamebryo2.2/corelibs/nimain/native_fixed_string.cpp)
target_sources(game PRIVATE src/bscore/memory_manager_startup.cpp)
target_sources(game PRIVATE src/gamebryo2.2/corelibs/nimain/nirefobject_lifetime.cpp)
target_sources(game PRIVATE src/fileformat/pack_structure.cpp)
target_sources(game PRIVATE src/fileformat/pack_container.cpp)
target_sources(game PRIVATE src/fileformat/pack_writer.cpp)
target_sources(game PRIVATE src/fileformat/pe_file.cpp)
target_sources(game PRIVATE src/fileformat/original_identity.cpp)
# Added at the end of the source list, after them: the DDS header reader
# (VEGAS-24). The archive lists the appended members in reverse order, so it
# is the first member listed.
target_sources(game PRIVATE src/fileformat/dds_header.cpp)
# Added after it: the NiAnimationKey table owner (VEGAS-51).
target_sources(game PRIVATE src/gamebryo2.2/corelibs/nianimation/nianimationkey_tables.cpp)
# After it, the check of the data pack's original (VEGAS-52).
target_sources(game PRIVATE src/fileformat/pack_validation.cpp)
# Then the step that opens the file of a data pack and checks it (VEGAS-52).
target_sources(game PRIVATE src/fileformat/pack_open.cpp)
# Then the native owner of the single-instance strings (VEGAS-52).
target_sources(game PRIVATE src/fallout/misc/single_instance_strings.cpp)
# Then the decision of the single-instance and remote-session checks
# (VEGAS-52).
target_sources(game PRIVATE src/fallout/misc/single_instance_check.cpp)
# Then the data pack stage of main (VEGAS-52), now the first member listed.
target_sources(game PRIVATE src/fallout/misc/data_pack_startup.cpp)

add_executable(FalloutNV src/main.cpp src/runtime/new.cpp)
target_include_directories(FalloutNV PRIVATE include)
# user32: GetSystemMetrics and MessageBoxA of WinMain's first checks (VEGAS-52).
target_link_libraries(FalloutNV PRIVATE game user32)

# Setup (VEGAS-13; docs/setup.md). It compiles the PE reader and the data
# pack sources itself, so the game archive and its members are unchanged.
# Setup and the game never link together.
add_library(vegas_setup STATIC
  src/setup/staged_pack.cpp
  src/setup/prepare_pack.cpp
  src/fileformat/pe_file.cpp
  src/fileformat/original_identity.cpp
  src/fileformat/pack_writer.cpp
  src/fileformat/pack_structure.cpp
  src/fileformat/pack_container.cpp
  src/fileformat/pack_validation.cpp
)
target_include_directories(vegas_setup PUBLIC src)
target_link_libraries(vegas_setup PRIVATE ZLIB::ZLIBSTATIC mbedtls_sha256)

add_subdirectory(tests)
