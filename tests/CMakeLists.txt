add_executable(fileformat_plugin_header_test fileformat/plugin_header_test.cpp)
target_include_directories(fileformat_plugin_header_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(fileformat_plugin_header_test PRIVATE game)
add_test(NAME fileformat.plugin_header COMMAND fileformat_plugin_header_test)

add_executable(fileformat_file_offsets_test fileformat/file_offsets_test.cpp)
target_include_directories(fileformat_file_offsets_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(fileformat_file_offsets_test PRIVATE game)
add_test(NAME fileformat.file_offsets COMMAND fileformat_file_offsets_test)

add_executable(fileformat_compression_test fileformat/compression_test.cpp)
target_include_directories(fileformat_compression_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(fileformat_compression_test PRIVATE game)
add_test(NAME fileformat.compression COMMAND fileformat_compression_test)

# Where the game archive builds, on Windows, the test links it. On other hosts
# the unit is compiled directly, so the test runs there under the sanitizers.
add_executable(fileformat_pack_structure_test fileformat/pack_structure_test.cpp)
target_include_directories(fileformat_pack_structure_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src)
if(WIN32)
  target_link_libraries(fileformat_pack_structure_test PRIVATE game)
else()
  target_sources(fileformat_pack_structure_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_structure.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_container.cpp
  )
  target_link_libraries(fileformat_pack_structure_test PRIVATE ZLIB::ZLIBSTATIC)
endif()
add_test(NAME fileformat.pack_structure COMMAND fileformat_pack_structure_test)

# Built the same way as the reader's test: the archive on Windows, the units
# themselves elsewhere.
add_executable(fileformat_pack_writer_test fileformat/pack_writer_test.cpp)
target_include_directories(fileformat_pack_writer_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src)
if(WIN32)
  target_link_libraries(fileformat_pack_writer_test PRIVATE game)
else()
  target_sources(fileformat_pack_writer_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_writer.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_structure.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_container.cpp
  )
  target_link_libraries(fileformat_pack_writer_test PRIVATE ZLIB::ZLIBSTATIC)
endif()
add_test(NAME fileformat.pack_writer COMMAND fileformat_pack_writer_test)

# Built the same way: the archive on Windows, the unit itself elsewhere. The
# executables it reads are built in memory by the test.
add_executable(fileformat_pe_file_test fileformat/pe_file_test.cpp)
target_include_directories(fileformat_pe_file_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src)
if(WIN32)
  target_link_libraries(fileformat_pe_file_test PRIVATE game)
else()
  target_sources(fileformat_pe_file_test PRIVATE ${PROJECT_SOURCE_DIR}/src/fileformat/pe_file.cpp)
endif()
add_test(NAME fileformat.pe_file COMMAND fileformat_pe_file_test)

add_executable(fileformat_original_identity_test fileformat/original_identity_test.cpp)
target_include_directories(fileformat_original_identity_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src)
if(WIN32)
  target_link_libraries(fileformat_original_identity_test PRIVATE game)
else()
  target_sources(fileformat_original_identity_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/fileformat/original_identity.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pe_file.cpp
  )
endif()
add_test(NAME fileformat.original_identity COMMAND fileformat_original_identity_test)

# Built the same way. The packs it checks are written by the data pack
# writer while the test runs.
add_executable(fileformat_pack_validation_test fileformat/pack_validation_test.cpp)
target_include_directories(fileformat_pack_validation_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src)
if(WIN32)
  target_link_libraries(fileformat_pack_validation_test PRIVATE game)
else()
  target_sources(fileformat_pack_validation_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_validation.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_structure.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_container.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_writer.cpp
  )
  target_link_libraries(fileformat_pack_validation_test PRIVATE ZLIB::ZLIBSTATIC)
endif()
add_test(NAME fileformat.pack_validation COMMAND fileformat_pack_validation_test)

# Built the same way. It writes its packs into a folder of its own under the
# temporary folder and removes it when it ends.
add_executable(fileformat_pack_open_test fileformat/pack_open_test.cpp)
target_include_directories(fileformat_pack_open_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src)
if(WIN32)
  target_link_libraries(fileformat_pack_open_test PRIVATE game)
else()
  target_sources(fileformat_pack_open_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_open.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_validation.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_structure.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_container.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_writer.cpp
  )
  target_link_libraries(fileformat_pack_open_test PRIVATE ZLIB::ZLIBSTATIC)
endif()
add_test(NAME fileformat.pack_open COMMAND fileformat_pack_open_test)

# Built the same way. The packs it validates are written by the data pack
# writer while the test runs.
add_executable(fileformat_pack_catalogue_test fileformat/pack_catalogue_test.cpp)
target_include_directories(fileformat_pack_catalogue_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src)
if(WIN32)
  target_link_libraries(fileformat_pack_catalogue_test PRIVATE game)
else()
  target_sources(fileformat_pack_catalogue_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_validation.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_structure.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_container.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_writer.cpp
  )
  target_link_libraries(fileformat_pack_catalogue_test PRIVATE ZLIB::ZLIBSTATIC)
endif()
add_test(NAME fileformat.pack_catalogue COMMAND fileformat_pack_catalogue_test)

# The SHA-256 of Mbed TLS against NIST's test vectors, which are stored beside
# the test. It links only the mbedtls_sha256 target, on every host.
add_executable(sha256_test sha256/sha256_test.cpp)
target_include_directories(sha256_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(sha256_test PRIVATE mbedtls_sha256)
add_test(NAME sha256.nist_vectors COMMAND sha256_test ${CMAKE_CURRENT_SOURCE_DIR}/sha256)

# Fails when a __thiscall, __fastcall or __stdcall keyword is written in game
# code: the C and C++ files under src/ and include/, src/generated included
# (VEGAS-12). Comments and literals do not count; a raw string that does not
# end fails. It reads the source folder only, on every host.
add_executable(source_calling_convention_keywords_test source/calling_convention_keywords_test.cpp)
target_include_directories(source_calling_convention_keywords_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
add_test(NAME source.calling_convention_keywords
  COMMAND source_calling_convention_keywords_test ${PROJECT_SOURCE_DIR})

# Setup's recipe ranges of C1 and the main window class's pointer match the
# recipe (tools/setup-recipe-ranges).
# Without Python 3 the configure goes on, and the test is still registered
# and fails with that reason, so the check is never silently missing.
find_package(Python3 COMPONENTS Interpreter)
if(Python3_Interpreter_FOUND)
  add_test(NAME setup.recipe_ranges
    COMMAND ${Python3_EXECUTABLE} ${PROJECT_SOURCE_DIR}/tools/setup-recipe-ranges/check.py
            --recipe ${PROJECT_SOURCE_DIR}/build/units.json
            --source ${PROJECT_SOURCE_DIR}/src/setup/single_instance_ranges.h
            --pointer-source ${PROJECT_SOURCE_DIR}/src/setup/main_window_class_range.h)
  # Check g on a recipe copy that binds an address 2 bytes after the pointer.
  add_test(NAME setup.recipe_ranges.pointer_bound
    COMMAND ${CMAKE_COMMAND} -DPYTHON=${Python3_EXECUTABLE}
      -DCHECK=${PROJECT_SOURCE_DIR}/tools/setup-recipe-ranges/check.py
      -DRECIPE=${PROJECT_SOURCE_DIR}/build/units.json
      -DSOURCE=${PROJECT_SOURCE_DIR}/src/setup/single_instance_ranges.h
      -DPOINTER_SOURCE=${PROJECT_SOURCE_DIR}/src/setup/main_window_class_range.h
      -DWORK=${CMAKE_CURRENT_BINARY_DIR}/recipe_ranges_pointer_bound
      -P ${CMAKE_CURRENT_SOURCE_DIR}/setup/recipe_ranges_pointer_bound.cmake)
else()
  string(CONCAT setup_recipe_ranges_missing
    "Python 3 was not found when configuring, so setup.recipe_ranges cannot "
    "run (tools/setup-recipe-ranges). Install Python 3 and configure again.")
  message(WARNING "${setup_recipe_ranges_missing}")
  add_test(NAME setup.recipe_ranges
    COMMAND ${CMAKE_COMMAND} -E echo "${setup_recipe_ranges_missing}")
  set_tests_properties(setup.recipe_ranges PROPERTIES
    FAIL_REGULAR_EXPRESSION "Python 3 was not found")
endif()

# Setup's preparation of a data pack (VEGAS-13), on synthetic executables
# built in memory. It links setup's library, never the game archive, on every
# host.
add_executable(setup_prepare_pack_test setup/prepare_pack_test.cpp)
target_include_directories(setup_prepare_pack_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(setup_prepare_pack_test PRIVATE vegas_setup mbedtls_sha256)
add_test(NAME setup.prepare_pack COMMAND setup_prepare_pack_test)

# Setup's installation of the pack and vegas-setup's command (VEGAS-13), with
# temporary folders and synthetic executables.
add_executable(setup_install_pack_test setup/install_pack_test.cpp)
target_include_directories(setup_install_pack_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(setup_install_pack_test PRIVATE vegas_setup)
add_test(NAME setup.install_pack COMMAND setup_install_pack_test)

add_executable(runtime_crt_test runtime/crt_test.cpp)
target_include_directories(runtime_crt_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(runtime_crt_test PRIVATE game)
add_test(NAME runtime.crt COMMAND runtime_crt_test)

add_executable(runtime_asm_helpers_test runtime/asm_helpers_test.cpp)
target_include_directories(runtime_asm_helpers_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include)
add_test(NAME runtime.asm_helpers COMMAND runtime_asm_helpers_test)

add_executable(runtime_new_test runtime/new_test.cpp ${PROJECT_SOURCE_DIR}/src/runtime/new.cpp)
target_include_directories(runtime_new_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include)
add_test(NAME runtime.new COMMAND runtime_new_test)

add_executable(runtime_havok_router_tls_test runtime/havok_router_tls_test.cpp)
target_include_directories(runtime_havok_router_tls_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(runtime_havok_router_tls_test PRIVATE game)
add_test(NAME runtime.havok_router_tls COMMAND runtime_havok_router_tls_test)

add_executable(runtime_havok_memory_prerequisite_test runtime/havok_memory_prerequisite_test.cpp)
target_include_directories(runtime_havok_memory_prerequisite_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(runtime_havok_memory_prerequisite_test PRIVATE game)
add_test(NAME runtime.havok_memory_prerequisite COMMAND runtime_havok_memory_prerequisite_test)

add_executable(runtime_d3d_texture_stage_lifetime_test
  runtime/d3d_texture_stage_lifetime_test.cpp
  ${PROJECT_SOURCE_DIR}/src/gamebryo2.2/corelibs/niconsolerenderer/nid3dtexturestage_lifetime.cpp
  ${PROJECT_SOURCE_DIR}/src/gamebryo2.2/corelibs/niconsolerenderer/nid3dtexturestage.cpp
)
# Built together with a unit that keeps the plain layout view of NiFixedString.
set_source_files_properties(runtime/d3d_texture_stage_lifetime_test.cpp PROPERTIES COMPILE_DEFINITIONS FNV_KEEPS_PLAIN_NIFIXEDSTRING)
target_include_directories(runtime_d3d_texture_stage_lifetime_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
add_test(NAME runtime.d3d_texture_stage_lifetime COMMAND runtime_d3d_texture_stage_lifetime_test)
add_test(NAME runtime.d3d_texture_stage_outstanding_owner
  COMMAND runtime_d3d_texture_stage_lifetime_test --outstanding-owner-termination)

add_executable(runtime_d3d_texture_stage_state_test
  runtime/d3d_texture_stage_state_test.cpp
  ${PROJECT_SOURCE_DIR}/src/gamebryo2.2/corelibs/niconsolerenderer/nid3dtexturestage.cpp
)
target_include_directories(runtime_d3d_texture_stage_state_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
add_test(NAME runtime.d3d_texture_stage_state COMMAND runtime_d3d_texture_stage_state_test)

add_executable(runtime_havok_byte_fill_test runtime/havok_byte_fill_test.cpp)
target_include_directories(runtime_havok_byte_fill_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(runtime_havok_byte_fill_test PRIVATE game)
add_test(NAME runtime.havok_byte_fill COMMAND runtime_havok_byte_fill_test)

add_executable(runtime_ray_similarity_math_test
  runtime/ray_similarity_math_test.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/common/internal/misc/ray_similarity_math.cpp
)
target_include_directories(runtime_ray_similarity_math_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include)
add_test(NAME runtime.ray_similarity_math COMMAND runtime_ray_similarity_math_test)

add_executable(runtime_game_timer_test
  runtime/game_timer_test.cpp
  ${PROJECT_SOURCE_DIR}/src/bscore/bstimer.cpp
  ${PROJECT_SOURCE_DIR}/src/fallout/interface/menus/recipemenu_timer.cpp
)
target_include_directories(runtime_game_timer_test PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
add_test(NAME runtime.game_timer COMMAND runtime_game_timer_test)
add_test(NAME runtime.game_timer_lazy_start COMMAND runtime_game_timer_test --lazy-start)
add_test(NAME runtime.game_timer_update_start COMMAND runtime_game_timer_test --update-start)

add_executable(runtime_magic_flag_byte_test runtime/magic_flag_byte_test.cpp)
target_include_directories(runtime_magic_flag_byte_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
add_test(NAME runtime.magic_flag_byte COMMAND runtime_magic_flag_byte_test)

# BSAudioDefinition from the bodies its owning unit includes, in storage of
# exactly the size the shared declaration gives.
add_executable(runtime_audio_definition_test runtime/audio_definition_test.cpp)
target_include_directories(runtime_audio_definition_test PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
add_test(NAME runtime.audio_definition COMMAND runtime_audio_definition_test)

add_executable(runtime_placeable_water_data_test runtime/placeable_water_data_test.cpp)
target_include_directories(runtime_placeable_water_data_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
add_test(NAME runtime.placeable_water_data COMMAND runtime_placeable_water_data_test)

add_executable(runtime_skin_bone_set_test
  runtime/skin_bone_set_test.cpp
  ${PROJECT_SOURCE_DIR}/src/gamebryo2.2/corelibs/nimain/skin_bone_set.cpp
)
target_include_directories(runtime_skin_bone_set_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include)
add_test(NAME runtime.skin_bone_set COMMAND runtime_skin_bone_set_test)


add_executable(runtime_havok_inline_string_test
  runtime/havok_inline_string_test.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/common/base/container/string/inline_storage_string.cpp
  ${PROJECT_SOURCE_DIR}/src/runtime/havok_router_tls.cpp
)
target_include_directories(runtime_havok_inline_string_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include)
add_test(NAME runtime.havok_inline_string COMMAND runtime_havok_inline_string_test)

add_executable(runtime_havok_owner_test runtime/havok_owner_test.cpp)
target_include_directories(runtime_havok_owner_test PRIVATE ${PROJECT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(runtime_havok_owner_test PRIVATE game)
add_test(NAME runtime.havok_owner COMMAND runtime_havok_owner_test)

add_executable(runtime_havok_worker_pool_test runtime/havok_worker_pool_test.cpp)
target_include_directories(runtime_havok_worker_pool_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(runtime_havok_worker_pool_test PRIVATE game)
add_test(NAME runtime.havok_worker_pool COMMAND runtime_havok_worker_pool_test)

add_executable(runtime_havok_base_system_test runtime/havok_base_system_test.cpp)
target_include_directories(runtime_havok_base_system_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(runtime_havok_base_system_test PRIVATE game)
add_test(NAME runtime.havok_base_system COMMAND runtime_havok_base_system_test "${CMAKE_CURRENT_BINARY_DIR}/havok-base-file.tmp")

add_executable(runtime_havok_startup_stop_test runtime/havok_startup_stop_test.cpp)
target_include_directories(runtime_havok_startup_stop_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(runtime_havok_startup_stop_test PRIVATE game)
if(UNIX)
  foreach(mode IN ITEMS direct fresh)
    add_test(NAME runtime.havok_startup_stop.${mode}
      COMMAND ${CMAKE_COMMAND}
        -DPROGRAM=$<TARGET_FILE:runtime_havok_startup_stop_test>
        -DMODE=${mode}
        -P ${CMAKE_CURRENT_SOURCE_DIR}/runtime/expect_startup_abort.cmake)
  endforeach()
endif()

add_executable(runtime_havok_core_caller_remedy_test runtime/havok_core_caller_remedy_test.cpp)
target_include_directories(runtime_havok_core_caller_remedy_test PRIVATE ${PROJECT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(runtime_havok_core_caller_remedy_test PRIVATE game)
add_test(NAME runtime.havok_core_caller_remedy COMMAND runtime_havok_core_caller_remedy_test)

add_executable(runtime_havok_diagnostic_consumers_test runtime/havok_diagnostic_consumers_test.cpp)
target_include_directories(runtime_havok_diagnostic_consumers_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(runtime_havok_diagnostic_consumers_test PRIVATE game)
add_test(NAME runtime.havok_diagnostic_consumers COMMAND runtime_havok_diagnostic_consumers_test)

add_executable(runtime_havok_core_review_remedy_test runtime/havok_core_review_remedy_test.cpp)
target_include_directories(runtime_havok_core_review_remedy_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(runtime_havok_core_review_remedy_test PRIVATE game)
add_test(NAME runtime.havok_core_review_remedy COMMAND runtime_havok_core_review_remedy_test)

add_executable(runtime_clamped_acos_test
  runtime/clamped_acos_test.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/common/base/math/clamped_acos.cpp
)
target_include_directories(runtime_clamped_acos_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include)
add_test(NAME runtime.clamped_acos COMMAND runtime_clamped_acos_test)

find_package(Threads REQUIRED)
target_link_libraries(runtime_game_timer_test PRIVATE Threads::Threads)

add_executable(runtime_canonical_memory_manager_test runtime/canonical_memory_manager_test.cpp)
if(WIN32)
  target_link_libraries(runtime_canonical_memory_manager_test PRIVATE game)
else()
  target_sources(runtime_canonical_memory_manager_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/bscore/legacy_memory_manager_startup.cpp
    ${PROJECT_SOURCE_DIR}/src/gamebryo2.2/corelibs/nimain/nipalette_memory.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/memoryusagetracker.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_virtual_memory.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_memory_heap.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_heap_set.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/fixed_pool.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/canonical_memory_manager.cpp
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/native_memory_pools.cpp
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/appmemory_console.cpp
    ${PROJECT_SOURCE_DIR}/src/runtime/tls.cpp)
endif()
target_include_directories(runtime_canonical_memory_manager_test PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
if(UNIX)
  target_link_libraries(runtime_canonical_memory_manager_test PRIVATE Threads::Threads)
endif()
add_test(NAME runtime.canonical_memory_manager COMMAND runtime_canonical_memory_manager_test)

add_executable(runtime_list_node_recycling_test runtime/list_node_recycling_test.cpp)
if(WIN32)
  target_link_libraries(runtime_list_node_recycling_test PRIVATE game)
else()
  target_sources(runtime_list_node_recycling_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_virtual_memory.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_memory_heap.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_heap_set.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/fixed_pool.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/canonical_memory_manager.cpp
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/native_memory_pools.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/memoryusagetracker.cpp
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/appmemory_console.cpp
    ${PROJECT_SOURCE_DIR}/src/gamebryo2.2/corelibs/nimain/nirefobject_lifetime.cpp
    ${PROJECT_SOURCE_DIR}/src/runtime/tls.cpp)
endif()
target_include_directories(runtime_list_node_recycling_test PRIVATE
  ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(runtime_list_node_recycling_test PRIVATE Threads::Threads)
add_test(NAME runtime.list_node_recycling COMMAND runtime_list_node_recycling_test)
if(UNIX)
  # The production recycler terminates on a slot it does not own.
  foreach(mode IN ITEMS foreign interior duplicate null)
    add_test(NAME runtime.list_node_recycling.reject_${mode}
      COMMAND ${CMAKE_COMMAND}
        -DPROGRAM=$<TARGET_FILE:runtime_list_node_recycling_test>
        -DMODE=--recycle-${mode}
        -DMARKER=recycle-${mode}
        -P ${CMAKE_CURRENT_SOURCE_DIR}/runtime/expect_abort.cmake)
  endforeach()
  # Remove terminates on a linked node while the list count is zero.
  add_test(NAME runtime.list_node_recycling.reject_uncounted_removal
    COMMAND ${CMAKE_COMMAND}
      -DPROGRAM=$<TARGET_FILE:runtime_list_node_recycling_test>
      -DMODE=--remove-uncounted
      -DMARKER=remove-uncounted
      -P ${CMAKE_CURRENT_SOURCE_DIR}/runtime/expect_abort.cmake)
endif()

# Unlike runtime.new's isolated forwarding fixture, this executable uses the
# actual getter, complete native global, heap suppliers and matching release.
add_executable(runtime_manager_new_test
  runtime/manager_new_test.cpp
  ${PROJECT_SOURCE_DIR}/src/runtime/new.cpp)
target_include_directories(runtime_manager_new_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
if(WIN32)
  target_link_libraries(runtime_manager_new_test PRIVATE game)
else()
  target_sources(runtime_manager_new_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_virtual_memory.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_memory_heap.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_heap_set.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/fixed_pool.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/canonical_memory_manager.cpp
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/native_memory_pools.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/memoryusagetracker.cpp
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/appmemory_console.cpp
    ${PROJECT_SOURCE_DIR}/src/runtime/tls.cpp)
  target_include_directories(runtime_manager_new_test PRIVATE ${PROJECT_SOURCE_DIR}/src)
  target_link_libraries(runtime_manager_new_test PRIVATE Threads::Threads)
endif()
add_test(NAME runtime.manager_new COMMAND runtime_manager_new_test)

# Keep the client in another TU. Windows links it to the complete game archive;
# host tests additionally place the actual provider object group on both sides
# of the client object to exercise both initialization/destruction link orders.
# The archive has no global allocation functions: as in FalloutNV, new.cpp is
# a source of the executable, or the Windows link takes the C runtime's.
add_library(runtime_manager_static_client OBJECT runtime/manager_static_client.cpp)
target_include_directories(runtime_manager_static_client PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
if(UNIX)
  target_link_libraries(runtime_manager_static_client PRIVATE Threads::Threads)
endif()
if(WIN32)
  add_executable(runtime_manager_static_lifetime_test
    runtime/manager_static_lifetime_test.cpp
    ${PROJECT_SOURCE_DIR}/src/runtime/new.cpp)
  target_include_directories(runtime_manager_static_lifetime_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
  target_link_libraries(runtime_manager_static_lifetime_test PRIVATE
    $<TARGET_OBJECTS:runtime_manager_static_client> game)
  add_test(NAME runtime.manager_static_lifetime COMMAND runtime_manager_static_lifetime_test)
else()
  add_library(runtime_manager_static_providers OBJECT
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_virtual_memory.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_memory_heap.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_heap_set.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/fixed_pool.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/canonical_memory_manager.cpp
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/native_memory_pools.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/memoryusagetracker.cpp
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/appmemory_console.cpp
    ${PROJECT_SOURCE_DIR}/src/runtime/tls.cpp
    ${PROJECT_SOURCE_DIR}/src/runtime/new.cpp)
  target_include_directories(runtime_manager_static_providers PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
  target_link_libraries(runtime_manager_static_providers PRIVATE Threads::Threads)
  foreach(order IN ITEMS client_first owner_first)
    set(test_target runtime_manager_static_${order}_test)
    add_executable(${test_target} runtime/manager_static_lifetime_test.cpp)
    target_include_directories(${test_target} PRIVATE ${PROJECT_SOURCE_DIR}/include)
    if(order STREQUAL "client_first")
      target_link_libraries(${test_target} PRIVATE
        $<TARGET_OBJECTS:runtime_manager_static_client>
        $<TARGET_OBJECTS:runtime_manager_static_providers>)
    else()
      target_link_libraries(${test_target} PRIVATE
        $<TARGET_OBJECTS:runtime_manager_static_providers>
        $<TARGET_OBJECTS:runtime_manager_static_client>)
    endif()
    target_link_libraries(${test_target} PRIVATE Threads::Threads)
    add_test(NAME runtime.manager_static_${order} COMMAND ${test_target})
  endforeach()
endif()

# The published Ni allocator: the actual manager startup entries, the holder's
# one writer, both recorded allocation entries and the Bethesda allocator.
add_executable(runtime_ni_allocator_join_test runtime/ni_allocator_join_test.cpp)
if(WIN32)
  target_link_libraries(runtime_ni_allocator_join_test PRIVATE game)
  target_sources(runtime_ni_allocator_join_test PRIVATE ${PROJECT_SOURCE_DIR}/src/runtime/new.cpp)
else()
  target_sources(runtime_ni_allocator_join_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/gamebryo2.2/corelibs/nisystem/ni_allocator_holder.cpp
    ${PROJECT_SOURCE_DIR}/src/gamebryo2.2/corelibs/nisystem/bsniallocator.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/newoverloads.cpp
    ${PROJECT_SOURCE_DIR}/src/runtime/new.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_virtual_memory.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_memory_heap.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_heap_set.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/fixed_pool.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/canonical_memory_manager.cpp
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/native_memory_pools.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/memoryusagetracker.cpp
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/appmemory_console.cpp
    ${PROJECT_SOURCE_DIR}/src/runtime/tls.cpp)
  target_link_libraries(runtime_ni_allocator_join_test PRIVATE Threads::Threads)
endif()
target_include_directories(runtime_ni_allocator_join_test PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
add_test(NAME runtime.ni_allocator_join COMMAND runtime_ni_allocator_join_test)
add_test(NAME runtime.ni_allocator_join.unpublished_free
  COMMAND ${CMAKE_COMMAND}
    -DPROGRAM=$<TARGET_FILE:runtime_ni_allocator_join_test>
    -DMODE=--free-without-holder
    -DMARKER=free-without-holder
    -P ${CMAKE_CURRENT_SOURCE_DIR}/runtime/expect_abort.cmake)
add_test(NAME runtime.ni_allocator_join.aligned_block_free
  COMMAND ${CMAKE_COMMAND}
    -DPROGRAM=$<TARGET_FILE:runtime_ni_allocator_join_test>
    -DMODE=--free-aligned-block
    -DMARKER=free-aligned-block
    -P ${CMAKE_CURRENT_SOURCE_DIR}/runtime/expect_abort.cmake)

# The startup main runs: fnv::memory::StartProcessMemory, then the Ni entries
# and global new and delete through what it established.
add_executable(runtime_process_startup_test runtime/process_startup_test.cpp)
if(WIN32)
  target_link_libraries(runtime_process_startup_test PRIVATE game)
  target_sources(runtime_process_startup_test PRIVATE ${PROJECT_SOURCE_DIR}/src/runtime/new.cpp)
else()
  target_sources(runtime_process_startup_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/bscore/memory_manager_startup.cpp
    ${PROJECT_SOURCE_DIR}/src/gamebryo2.2/corelibs/nisystem/ni_allocator_holder.cpp
    ${PROJECT_SOURCE_DIR}/src/gamebryo2.2/corelibs/nisystem/bsniallocator.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/newoverloads.cpp
    ${PROJECT_SOURCE_DIR}/src/runtime/new.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_virtual_memory.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_memory_heap.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_heap_set.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/fixed_pool.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/canonical_memory_manager.cpp
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/native_memory_pools.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/memoryusagetracker.cpp
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/appmemory_console.cpp
    ${PROJECT_SOURCE_DIR}/src/runtime/tls.cpp)
  target_link_libraries(runtime_process_startup_test PRIVATE Threads::Threads)
endif()
target_include_directories(runtime_process_startup_test PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
add_test(NAME runtime.process_startup COMMAND runtime_process_startup_test)
add_test(NAME runtime.process_startup.unpublished_ni_startup
  COMMAND ${CMAKE_COMMAND}
    -DPROGRAM=$<TARGET_FILE:runtime_process_startup_test>
    -DMODE=--ni-startup-unpublished
    -DMARKER=ni-startup-unpublished
    -P ${CMAKE_CURRENT_SOURCE_DIR}/runtime/expect_abort.cmake)

# The native owner of the single-instance strings, published from packs the
# data pack writer makes while the test runs.
add_executable(runtime_single_instance_strings_test runtime/single_instance_strings_test.cpp)
target_include_directories(runtime_single_instance_strings_test PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
if(WIN32)
  target_link_libraries(runtime_single_instance_strings_test PRIVATE game)
else()
  target_sources(runtime_single_instance_strings_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/single_instance_strings.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_validation.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_structure.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_container.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_writer.cpp)
  target_link_libraries(runtime_single_instance_strings_test PRIVATE ZLIB::ZLIBSTATIC)
endif()
add_test(NAME runtime.single_instance_strings COMMAND runtime_single_instance_strings_test)
add_test(NAME runtime.single_instance_strings.unpublished_read
  COMMAND ${CMAKE_COMMAND}
    -DPROGRAM=$<TARGET_FILE:runtime_single_instance_strings_test>
    -DMODE=--read-unpublished
    -DMARKER=read-unpublished
    -P ${CMAKE_CURRENT_SOURCE_DIR}/runtime/expect_abort.cmake)

# The decision of the single-instance and remote-session checks, on every
# branch, with the message box and the session query recorded. On Windows a
# second process also makes main's CreateMutexA call on a mutex the test holds.
add_executable(runtime_single_instance_check_test runtime/single_instance_check_test.cpp)
target_include_directories(runtime_single_instance_check_test PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
if(WIN32)
  target_link_libraries(runtime_single_instance_check_test PRIVATE game)
else()
  target_sources(runtime_single_instance_check_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/single_instance_check.cpp)
endif()
add_test(NAME runtime.single_instance_check COMMAND runtime_single_instance_check_test)

# The data pack stage of main, on packs the data pack writer makes in folders
# of the test's own while it runs.
add_executable(runtime_data_pack_startup_test runtime/data_pack_startup_test.cpp)
target_include_directories(runtime_data_pack_startup_test PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
if(WIN32)
  target_link_libraries(runtime_data_pack_startup_test PRIVATE game)
else()
  target_sources(runtime_data_pack_startup_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/data_pack_startup.cpp
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/single_instance_strings.cpp
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/main_window_class.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_open.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_validation.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_structure.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_container.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_writer.cpp)
  target_link_libraries(runtime_data_pack_startup_test PRIVATE ZLIB::ZLIBSTATIC)
endif()
add_test(NAME runtime.data_pack_startup COMMAND runtime_data_pack_startup_test)
add_test(NAME runtime.data_pack_startup.refused_publishes_nothing
  COMMAND ${CMAKE_COMMAND}
    -DPROGRAM=$<TARGET_FILE:runtime_data_pack_startup_test>
    -DMODE=--refused-then-read
    -DMARKER=refused-then-read
    -P ${CMAKE_CURRENT_SOURCE_DIR}/runtime/expect_abort.cmake)

# Run a copy of the built FalloutNV.exe alone in a folder of the test's own,
# with no original executable beside it. falloutnv.process_exit writes a
# complete synthetic pack beside the copy and requires exit code 0: the
# process image loads, its imports resolve, the C++ runtime starts, process
# memory initialisation completes, the pack beside the executable validates,
# C1 and the main window class are published, the single-instance,
# remote-session and second-window checks pass and main returns 0.
# falloutnv.process_exit.missing_pack writes the pack only in the working
# directory and requires exit code 2 with the missing pack reported on the
# standard error stream. Before the run with the pack the fixture makes the
# calls of the single-instance check with the message box recorded, and the
# second-window check with the foreground call recorded; only when it reports
# a remote session is the copy not run and the test skipped, and a mutex or a
# window of the class that already exists fails it. Each run has 60 seconds,
# so a run that waits fails instead of holding the runner. Neither shows the
# engine link, startup or boot.
if(WIN32)
  add_executable(falloutnv_pack_fixture runtime/falloutnv_pack_fixture.cpp)
  target_include_directories(falloutnv_pack_fixture PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
  target_link_libraries(falloutnv_pack_fixture PRIVATE game user32)
  foreach(mode IN ITEMS with-pack without-pack)
    if(mode STREQUAL "with-pack")
      set(test_name falloutnv.process_exit)
    else()
      set(test_name falloutnv.process_exit.missing_pack)
    endif()
    add_test(NAME ${test_name}
      COMMAND ${CMAKE_COMMAND}
        -DPROGRAM=$<TARGET_FILE:FalloutNV>
        -DFIXTURE=$<TARGET_FILE:falloutnv_pack_fixture>
        -DFOLDER=${CMAKE_CURRENT_BINARY_DIR}/${test_name}
        -DMODE=${mode}
        -DTIMEOUT=60
        -P ${CMAKE_CURRENT_SOURCE_DIR}/runtime/falloutnv_pack_folder.cmake)
  endforeach()
  set_tests_properties(falloutnv.process_exit PROPERTIES
    SKIP_REGULAR_EXPRESSION "SKIPPED: the session is remote, so main would show a message box")
endif()

add_executable(runtime_native_string_test runtime/native_string_test.cpp)
if(WIN32)
  target_link_libraries(runtime_native_string_test PRIVATE game)
else()
  target_sources(runtime_native_string_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/speedtree/native_string.cpp
    ${PROJECT_SOURCE_DIR}/src/unmapped/throw.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_virtual_memory.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_memory_heap.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_heap_set.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/fixed_pool.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/canonical_memory_manager.cpp
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/native_memory_pools.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/memoryusagetracker.cpp
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/appmemory_console.cpp
    ${PROJECT_SOURCE_DIR}/src/runtime/tls.cpp)
  target_link_libraries(runtime_native_string_test PRIVATE Threads::Threads)
endif()
target_include_directories(runtime_native_string_test PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
add_test(NAME runtime.native_string COMMAND runtime_native_string_test)

add_executable(runtime_native_fixed_string_test runtime/native_fixed_string_test.cpp)
if(WIN32)
  target_link_libraries(runtime_native_fixed_string_test PRIVATE game)
else()
  target_sources(runtime_native_fixed_string_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/gamebryo2.2/corelibs/nimain/native_fixed_string.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_virtual_memory.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_memory_heap.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_heap_set.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/fixed_pool.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/canonical_memory_manager.cpp
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/native_memory_pools.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/memoryusagetracker.cpp
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/appmemory_console.cpp
    ${PROJECT_SOURCE_DIR}/src/runtime/tls.cpp)
  target_link_libraries(runtime_native_fixed_string_test PRIVATE Threads::Threads)
endif()
target_include_directories(runtime_native_fixed_string_test PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
add_test(NAME runtime.native_fixed_string COMMAND runtime_native_fixed_string_test)

# Exercise the production LOS record array, map-load owner, bounded save reader
# and canonical manager protocol under the production global new and delete.
# Windows extracts the same owner from the complete archive; host builds name
# its actual production suppliers directly.
add_executable(runtime_los_map_array_test
  runtime/los_map_array_test.cpp
  ${PROJECT_SOURCE_DIR}/src/runtime/new.cpp)
if(WIN32)
  target_link_libraries(runtime_los_map_array_test PRIVATE game)
else()
  target_sources(runtime_los_map_array_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/fallout_shared/pathfinding/los_map_array.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_virtual_memory.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_memory_heap.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/engine_heap_set.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/fixed_pool.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/canonical_memory_manager.cpp
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/native_memory_pools.cpp
    ${PROJECT_SOURCE_DIR}/src/bscore/memoryusagetracker.cpp
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/appmemory_console.cpp
    ${PROJECT_SOURCE_DIR}/src/runtime/tls.cpp)
  target_link_libraries(runtime_los_map_array_test PRIVATE Threads::Threads)
endif()
target_include_directories(runtime_los_map_array_test PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
add_test(NAME runtime.los_map_array COMMAND runtime_los_map_array_test)

add_executable(runtime_allocation_context_test runtime/allocation_context_test.cpp)
if(WIN32)
  target_link_libraries(runtime_allocation_context_test PRIVATE game)
else()
  target_sources(runtime_allocation_context_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/bscore/memoryusagetracker.cpp
    ${PROJECT_SOURCE_DIR}/src/runtime/tls.cpp)
endif()
target_include_directories(runtime_allocation_context_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
if(UNIX)
  target_link_libraries(runtime_allocation_context_test PRIVATE Threads::Threads)
endif()
add_test(NAME runtime.allocation_context COMMAND runtime_allocation_context_test)

add_executable(runtime_havok_mopp_lifetime_test runtime/havok_mopp_lifetime_test.cpp)
if(WIN32)
  target_link_libraries(runtime_havok_mopp_lifetime_test PRIVATE game)
else()
  # Host checks use the same production owners without building Windows callers.
  target_sources(runtime_havok_mopp_lifetime_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/havok/common/base/object/native_referenced_object.cpp
    ${PROJECT_SOURCE_DIR}/src/havok/physics/collide/shape/compound/tree/mopp/native_mopp_construction.cpp
    ${PROJECT_SOURCE_DIR}/src/havok/physics/collide/shape/convex/sphere/native_sphere_construction.cpp
    ${PROJECT_SOURCE_DIR}/src/havok/common/base/memory/allocator/native_memory_allocator.cpp
    ${PROJECT_SOURCE_DIR}/src/havok/common/base/memory/allocator/freelist/native_system_allocator.cpp
    ${PROJECT_SOURCE_DIR}/src/havok/common/base/memory/router/native_memory_router.cpp
    ${PROJECT_SOURCE_DIR}/src/havok/common/base/memory/allocator/solver/native_solver_allocator.cpp
    ${PROJECT_SOURCE_DIR}/src/runtime/havok_memory_prerequisite.cpp
    ${PROJECT_SOURCE_DIR}/src/runtime/havok_router_tls.cpp
  )
endif()
target_include_directories(runtime_havok_mopp_lifetime_test PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(runtime_havok_mopp_lifetime_test PRIVATE Threads::Threads)
add_test(NAME runtime.havok_mopp_lifetime COMMAND runtime_havok_mopp_lifetime_test)

add_executable(runtime_havok_mesh_collection_test runtime/havok_mesh_collection_test.cpp)
if(WIN32)
  target_link_libraries(runtime_havok_mesh_collection_test PRIVATE game)
else()
  # Reuse the accepted native construction/allocator sources, not test providers.
  get_target_property(HAVOK_NATIVE_SHAPE_SOURCES runtime_havok_mopp_lifetime_test SOURCES)
  list(REMOVE_ITEM HAVOK_NATIVE_SHAPE_SOURCES runtime/havok_mopp_lifetime_test.cpp)
  target_sources(runtime_havok_mesh_collection_test PRIVATE
    ${HAVOK_NATIVE_SHAPE_SOURCES}
    ${PROJECT_SOURCE_DIR}/src/havok/physics/collide/shape/deprecated/mesh/native_mesh_shape.cpp
    ${PROJECT_SOURCE_DIR}/src/havok/physics/collide/shape/convex/triangle/native_triangle_shape.cpp
  )
endif()
target_include_directories(runtime_havok_mesh_collection_test PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(runtime_havok_mesh_collection_test PRIVATE Threads::Threads)
add_test(NAME runtime.havok_mesh_collection COMMAND runtime_havok_mesh_collection_test)

set(HAVOK_PACKFILE_RUNTIME_SOURCES
  ${PROJECT_SOURCE_DIR}/src/havok/common/base/object/native_referenced_object.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/physics/collide/shape/convex/triangle/native_triangle_shape.cpp
  ${PROJECT_SOURCE_DIR}/src/runtime/havok_router_tls.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/physics/collide/shape/compound/tree/mopp/native_mopp_construction.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/common/base/memory/router/native_memory_router.cpp
  ${PROJECT_SOURCE_DIR}/src/runtime/havok_memory_prerequisite.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/physics/collide/shape/deprecated/fastmesh/native_fast_mesh.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/common/serialize/packfile/native_fast_mesh_packfile.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/common/serialize/util/native_packfile_loader.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/common/serialize/util/packfile_load.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/common/serialize/data/native/native_world.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/common/serialize/packfile/packfile_data_finishing.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/common/serialize/util/builtin_type_registry.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/common/serialize/util/packfile_registry_finishing.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/common/serialize/util/packfile_resource.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/common/serialize/data/dict/dictionary_world.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/common/serialize/data/dict/dictionary_reflection.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/common/serialize/data/util/dictionary_conversion.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/common/serialize/tagfile/binary/dictionary_reader.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/common/serialize/util/serializer_entry.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/common/serialize/packfile/native_resource_statistics.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/common/base/memory/allocator/freelist/native_system_allocator.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/common/base/memory/allocator/native_memory_allocator.cpp
)
foreach(suite IN ITEMS havok_loaded_mesh_collection havok_fast_mesh_materialization havok_fast_mesh_loader havok_packfile_registry_resource havok_builtin_global_protocol havok_native_world_second_finish havok_legacy_packfile_builder havok_dictionary_serializer)
  add_executable(runtime_${suite}_test runtime/${suite}_test.cpp)
  if(WIN32)
    target_link_libraries(runtime_${suite}_test PRIVATE game)
  else()
    target_sources(runtime_${suite}_test PRIVATE ${HAVOK_PACKFILE_RUNTIME_SOURCES})
  endif()
  target_include_directories(runtime_${suite}_test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
  target_link_libraries(runtime_${suite}_test PRIVATE Threads::Threads)
  add_test(NAME runtime.${suite} COMMAND runtime_${suite}_test)
endforeach()

add_executable(runtime_havok_bvtree_cache_test runtime/havok_bvtree_cache_test.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/physics/collide/agent/compoundagent/bvtree/bvtree_cache.cpp)
target_include_directories(runtime_havok_bvtree_cache_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
add_test(NAME runtime.havok_bvtree_cache COMMAND runtime_havok_bvtree_cache_test)

add_executable(runtime_havok_simple_contact_rhs_test runtime/havok_simple_contact_rhs_test.cpp
  ${PROJECT_SOURCE_DIR}/src/havok/physics/constraintsolver/constraint/contact/simple_contact_rhs.cpp)
target_include_directories(runtime_havok_simple_contact_rhs_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
add_test(NAME runtime.havok_simple_contact_rhs COMMAND runtime_havok_simple_contact_rhs_test)

add_executable(runtime_havok_cylinder_settings_test runtime/havok_cylinder_settings_test.cpp)
target_include_directories(runtime_havok_cylinder_settings_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
if(WIN32)
  target_link_libraries(runtime_havok_cylinder_settings_test PRIVATE game)
else()
  target_sources(runtime_havok_cylinder_settings_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/havok/physics/collide/shape/convex/cylinder/cylinder_settings.cpp
    ${PROJECT_SOURCE_DIR}/src/havok/common/base/math/scalar_constants.cpp)
endif()
add_test(NAME runtime.havok_cylinder_settings COMMAND runtime_havok_cylinder_settings_test)

# Test the existing public transpose entry; no inverse or D3DX test provider.
add_executable(runtime_d3dx_matrix_transpose_test runtime/d3dx_matrix_transpose_test.cpp)
target_include_directories(runtime_d3dx_matrix_transpose_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
if(WIN32)
  target_link_libraries(runtime_d3dx_matrix_transpose_test PRIVATE game)
else()
  target_sources(runtime_d3dx_matrix_transpose_test PRIVATE ${PROJECT_SOURCE_DIR}/src/unmapped/d3dxmath.cpp)
endif()
add_test(NAME runtime.d3dx_matrix_transpose COMMAND runtime_d3dx_matrix_transpose_test)

# Test the existing typed inverse entry against the real native provider.
add_executable(runtime_d3dx_matrix_inverse_test runtime/d3dx_matrix_inverse_test.cpp)
target_include_directories(runtime_d3dx_matrix_inverse_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
if(WIN32)
  target_link_libraries(runtime_d3dx_matrix_inverse_test PRIVATE game)
else()
  target_sources(runtime_d3dx_matrix_inverse_test PRIVATE ${PROJECT_SOURCE_DIR}/src/unmapped/d3dxmath.cpp)
endif()
add_test(NAME runtime.d3dx_matrix_inverse COMMAND runtime_d3dx_matrix_inverse_test)

# Test the existing typed multiply entry and its public inverse/transpose pipeline.
add_executable(runtime_d3dx_matrix_multiply_test runtime/d3dx_matrix_multiply_test.cpp)
target_include_directories(runtime_d3dx_matrix_multiply_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
if(WIN32)
  target_link_libraries(runtime_d3dx_matrix_multiply_test PRIVATE game)
else()
  target_sources(runtime_d3dx_matrix_multiply_test PRIVATE ${PROJECT_SOURCE_DIR}/src/unmapped/d3dxmath.cpp)
endif()
add_test(NAME runtime.d3dx_matrix_multiply COMMAND runtime_d3dx_matrix_multiply_test)

# Exercise the existing typed entry with genuine complete production objects.
add_executable(runtime_d3dx_matrix_multiply_transpose_test runtime/d3dx_matrix_multiply_transpose_test.cpp)
target_include_directories(runtime_d3dx_matrix_multiply_transpose_test PRIVATE
  ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
if(WIN32)
  target_link_libraries(runtime_d3dx_matrix_multiply_transpose_test PRIVATE game)
else()
  target_sources(runtime_d3dx_matrix_multiply_transpose_test PRIVATE ${PROJECT_SOURCE_DIR}/src/unmapped/d3dxmath.cpp)
endif()
add_test(NAME runtime.d3dx_matrix_multiply_transpose COMMAND runtime_d3dx_matrix_multiply_transpose_test)

add_executable(runtime_d3dx_vector4_transform_test runtime/d3dx_vector4_transform_test.cpp)
target_include_directories(runtime_d3dx_vector4_transform_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
if(WIN32)
  target_link_libraries(runtime_d3dx_vector4_transform_test PRIVATE game)
else()
  target_sources(runtime_d3dx_vector4_transform_test PRIVATE ${PROJECT_SOURCE_DIR}/src/unmapped/d3dxmath.cpp)
endif()
add_test(NAME runtime.d3dx_vector4_transform COMMAND runtime_d3dx_vector4_transform_test)

add_executable(runtime_d3dx_vector3_normal_transform_test runtime/d3dx_vector3_normal_transform_test.cpp)
target_include_directories(runtime_d3dx_vector3_normal_transform_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
if(WIN32)
  target_link_libraries(runtime_d3dx_vector3_normal_transform_test PRIVATE game)
else()
  target_sources(runtime_d3dx_vector3_normal_transform_test PRIVATE ${PROJECT_SOURCE_DIR}/src/unmapped/d3dxmath.cpp)
endif()
add_test(NAME runtime.d3dx_vector3_normal_transform COMMAND runtime_d3dx_vector3_normal_transform_test)

add_executable(runtime_d3dx_vector3_coordinate_transform_test runtime/d3dx_vector3_coordinate_transform_test.cpp)
target_include_directories(runtime_d3dx_vector3_coordinate_transform_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
if(WIN32)
  target_link_libraries(runtime_d3dx_vector3_coordinate_transform_test PRIVATE game)
else()
  target_sources(runtime_d3dx_vector3_coordinate_transform_test PRIVATE ${PROJECT_SOURCE_DIR}/src/unmapped/d3dxmath.cpp)
endif()
add_test(NAME runtime.d3dx_vector3_coordinate_transform COMMAND runtime_d3dx_vector3_coordinate_transform_test)

# Check the startup copy of the pixel-format table against its owning unit,
# and the format that NiPixelFormat's readers obtain from it.
add_executable(runtime_pixel_format_startup_table_test runtime/pixel_format_startup_table_test.cpp)
target_include_directories(runtime_pixel_format_startup_table_test PRIVATE
  ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
if(WIN32)
  target_link_libraries(runtime_pixel_format_startup_table_test PRIVATE game)
else()
  target_sources(runtime_pixel_format_startup_table_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/gamebryo2.2/corelibs/nimain/console/nipoint3_console.cpp
    ${PROJECT_SOURCE_DIR}/src/gamebryo2.2/corelibs/nimain/nipixelformat_h_unit.cpp)
endif()
add_test(NAME runtime.pixel_format_startup_table COMMAND runtime_pixel_format_startup_table_test)

# Native replacements for the remaining D3DX math leaves (VEGAS-24).
foreach(d3dx_math_test vector3_normalize matrix_rotation_yaw_pitch_roll plane_normalize plane_transform)
  add_executable(runtime_d3dx_${d3dx_math_test}_test runtime/d3dx_${d3dx_math_test}_test.cpp)
  target_include_directories(runtime_d3dx_${d3dx_math_test}_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
  if(WIN32)
    target_link_libraries(runtime_d3dx_${d3dx_math_test}_test PRIVATE game)
  else()
    target_sources(runtime_d3dx_${d3dx_math_test}_test PRIVATE ${PROJECT_SOURCE_DIR}/src/unmapped/d3dxmath.cpp)
  endif()
  add_test(NAME runtime.d3dx_${d3dx_math_test} COMMAND runtime_d3dx_${d3dx_math_test}_test)
endforeach()

# Argument patterns of the D3DX calls restored from before 3f0599801 (VEGAS-90).
foreach(d3dx_call_test fallout_shared shader_constants lighting)
  add_executable(runtime_d3dx_call_arguments_${d3dx_call_test}_test
    runtime/d3dx_call_arguments_${d3dx_call_test}_test.cpp)
  target_include_directories(runtime_d3dx_call_arguments_${d3dx_call_test}_test PRIVATE
    ${PROJECT_SOURCE_DIR}/include)
  if(WIN32)
    target_link_libraries(runtime_d3dx_call_arguments_${d3dx_call_test}_test PRIVATE game)
  else()
    target_sources(runtime_d3dx_call_arguments_${d3dx_call_test}_test PRIVATE
      ${PROJECT_SOURCE_DIR}/src/unmapped/d3dxmath.cpp)
  endif()
  add_test(NAME runtime.d3dx_call_arguments_${d3dx_call_test}
    COMMAND runtime_d3dx_call_arguments_${d3dx_call_test}_test)
endforeach()
add_executable(fileformat_dds_header_test fileformat/dds_header_test.cpp)
target_include_directories(fileformat_dds_header_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src)
if(WIN32)
  target_link_libraries(fileformat_dds_header_test PRIVATE game)
else()
  target_sources(fileformat_dds_header_test PRIVATE ${PROJECT_SOURCE_DIR}/src/fileformat/dds_header.cpp)
endif()
add_test(NAME fileformat.dds_header COMMAND fileformat_dds_header_test)

# The checks of the game archive and its objects below read the windows-x64
# objects on the build host: with Go, with the llvm-objdump beside clang-cl and
# with Python 3. They are registered in every windows-x64 build, the cross build
# and a build on a Windows host such as the Windows CI job (VEGAS-95). A cross
# build stops when a tool is not found. On a Windows host the configure goes on
# with a warning, as for setup.recipe_ranges, and objects.tools is registered in
# place of the checks and fails with that reason, so they are never silently
# missing.
set(vegas_object_checks FALSE)
if(WIN32)
  find_program(GO_EXECUTABLE go)
  get_filename_component(compiler_dir "${CMAKE_CXX_COMPILER}" DIRECTORY)
  find_program(LLVM_OBJDUMP_EXECUTABLE llvm-objdump HINTS "${compiler_dir}")
  set(vegas_object_tools_missing "")
  if(NOT GO_EXECUTABLE)
    list(APPEND vegas_object_tools_missing "Go")
  endif()
  if(NOT LLVM_OBJDUMP_EXECUTABLE)
    list(APPEND vegas_object_tools_missing "llvm-objdump")
  endif()
  if(NOT Python3_Interpreter_FOUND)
    list(APPEND vegas_object_tools_missing "Python 3")
  endif()
  if(vegas_object_tools_missing)
    list(JOIN vegas_object_tools_missing ", " vegas_object_tools_missing)
    string(CONCAT vegas_object_tools_message
      "${vegas_object_tools_missing} not found when configuring, so the objects.* "
      "and archive.* checks of the game archive cannot run. Install the missing "
      "tools and configure again.")
    if(NOT CMAKE_HOST_WIN32)
      message(FATAL_ERROR "${vegas_object_tools_message}")
    endif()
    message(WARNING "${vegas_object_tools_message}")
    add_test(NAME objects.tools
      COMMAND ${CMAKE_COMMAND} -E echo "${vegas_object_tools_message}")
    set_tests_properties(objects.tools PROPERTIES
      FAIL_REGULAR_EXPRESSION "not found when configuring")
  else()
    set(vegas_object_checks TRUE)
  endif()
endif()

# Fails when an external name of the game archive has definitions that differ
# between members and is not recorded in the allowlist. A recorded name that
# no longer differs is printed as STALE and passes. The set of names depends on the compiler and the standard
# library. The allowlist was measured on the cross build; at 891a44f50 the
# Windows CI job's toolchain (clang-cl 20.1.8 with the standard library of
# Visual Studio) gave the same 519 names, so the test runs in both. The tool
# reads the archive with Go.
if(vegas_object_checks)
  add_test(NAME archive.differing_definitions
    COMMAND ${GO_EXECUTABLE} run . --archive $<TARGET_FILE:game>
            --allowlist ${PROJECT_SOURCE_DIR}/tools/differing-definitions/allowlist.tsv
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tools/differing-definitions)
endif()

# Fails when a function whose D3DX calls got their arguments back (VEGAS-90)
# again refers to an argument-less name of the matrix inverse, transpose or
# normal transform, or no longer to the native function it calls. One test per
# batch of tools/function-relocations/d3dx-call-arguments.tsv. Like the check
# above it reads the windows-x64 objects on the build host with Go.
if(vegas_object_checks)
  file(GENERATE OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/game-objects.txt
    CONTENT "$<JOIN:$<TARGET_OBJECTS:game>,\n>\n")
  foreach(d3dx_call_batch fallout_shared shader_constants lighting)
    add_test(NAME objects.d3dx_call_arguments_${d3dx_call_batch}
      COMMAND ${GO_EXECUTABLE} run . --table d3dx-call-arguments.tsv
              --objects ${CMAKE_CURRENT_BINARY_DIR}/game-objects.txt --batch ${d3dx_call_batch}
      WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tools/function-relocations)
  endforeach()
  # Fails when a function whose numeric mask or flag was spelled as the
  # address of a data name (VEGAS-93) again refers to that name.
  add_test(NAME objects.mask_constants
    COMMAND ${GO_EXECUTABLE} run . --table mask-constants.tsv
            --objects ${CMAKE_CURRENT_BINARY_DIR}/game-objects.txt
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tools/function-relocations)
endif()

if(WIN32)
  add_executable(runtime_windows_import_types_test runtime/windows_import_types_test.cpp)
  add_test(NAME runtime.windows_import_types COMMAND runtime_windows_import_types_test)
endif()

# Fails when a member of the game archive refers to an import slot variable
# that holds no function at run time. Generated data defines the slot of
# InterlockedExchangeAdd as null, because no x64 library exports the function,
# under a C++ name that a C name of the same slot is redirected to. The two
# critical section slot names with this C++ type have no definition at all.
# The archive is read with llvm-objdump on the build host.
if(vegas_object_checks)
  add_test(NAME archive.empty_import_slots
    COMMAND ${CMAKE_COMMAND}
      -DOBJDUMP=${LLVM_OBJDUMP_EXECUTABLE}
      -DARCHIVE=$<TARGET_FILE:game>
      -DWORK=${CMAKE_CURRENT_BINARY_DIR}/empty_import_slots.relocations.txt
      "-DNAMES=DAT_00fdf1ec,?DAT_00fdf1ec@@3P6AJPECJJ@ZEA,?DAT_00fdf05c@@3P6AXPEAU_RTL_CRITICAL_SECTION@@@ZEA,?DAT_00fdf100@@3P6AXPEAU_RTL_CRITICAL_SECTION@@@ZEA"
      -P ${CMAKE_CURRENT_SOURCE_DIR}/archive/expect_no_relocation.cmake)
endif()

# Fails when the function that deletes the hacking menu's element array
# (0x007687d0, VEGAS-72) again calls the transcribed vector deleting destructor
# or its 32-bit callees, or no longer calls the element's destructor and the
# sized array delete. It uses the object list and GO_EXECUTABLE of the checks
# above.
if(vegas_object_checks)
  add_test(NAME objects.hacking_array_retirement
    COMMAND ${GO_EXECUTABLE} run . --table hacking-array-retirement.tsv
            --objects ${CMAKE_CURRENT_BINARY_DIR}/game-objects.txt
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tools/function-relocations)
endif()

# Fails when the function at 0x005436e0 (VEGAS-96) again sees the NavMesh
# pointer that MakeNavMeshPointer returns as a trivial class: it then passes
# the mesh where the callee expects the address of its result and never
# destroys the result.
if(vegas_object_checks)
  add_test(NAME objects.navmesh_pointer_result
    COMMAND ${GO_EXECUTABLE} run . --table navmesh-pointer-result.tsv
            --objects ${CMAKE_CURRENT_BINARY_DIR}/game-objects.txt
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tools/function-relocations)
endif()

# Fails when WinMain (0x0086a850, VEGAS-30) again calls a boot function under
# a name that no object defines, or no longer under the name of its body.
if(vegas_object_checks)
  add_test(NAME objects.winmain_boot_calls
    COMMAND ${GO_EXECUTABLE} run . --table winmain-boot-calls.tsv
            --objects ${CMAKE_CURRENT_BINARY_DIR}/game-objects.txt
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tools/function-relocations)
endif()

# Fails when a boot-path call repaired to the body at its recipe row (VEGAS-90,
# VEGAS-30) again uses a name that no object defines, or no longer names the
# body, or a definition repaired for such a call (VEGAS-97) is no longer
# defined under its row's name.
if(vegas_object_checks)
  add_test(NAME objects.boot_call_repairs
    COMMAND ${GO_EXECUTABLE} run . --table boot-call-repairs.tsv
            --objects ${CMAKE_CURRENT_BINARY_DIR}/game-objects.txt
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tools/function-relocations)
endif()

# Fails when a call whose caller and callee disagreed on an integer width
# only (VEGAS-97) again refers to the requirer's former name, or a function no
# longer calls the agreed name.
if(vegas_object_checks)
  add_test(NAME objects.integer_width_calls
    COMMAND ${GO_EXECUTABLE} run . --table integer-width-calls.tsv
            --objects ${CMAKE_CURRENT_BINARY_DIR}/game-objects.txt
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tools/function-relocations)
endif()

# Fails when the npos of the string library at 0x010173f0 (VEGAS-100) is
# again zero: defined without its all-ones initial value, in a section that
# has no initialised contents, or with other bytes.
if(vegas_object_checks)
  add_test(NAME objects.string_npos
    COMMAND ${GO_EXECUTABLE} run . --table string-npos.tsv
            --objects ${CMAKE_CURRENT_BINARY_DIR}/game-objects.txt
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tools/data-values)
endif()

# Fails when a function that read the slot after the end of a two-slot
# generated table (VEGAS-30) again addresses that table at or past its end, or
# no longer calls through the name the recipe gives that slot.
if(vegas_object_checks)
  add_test(NAME objects.table_slot_reads
    COMMAND ${GO_EXECUTABLE} run . --table table-slot-reads.tsv
            --objects ${CMAKE_CURRENT_BINARY_DIR}/game-objects.txt
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tools/function-relocations)
endif()

# Fails when any relocation of any object of the game archive addresses a
# table of the fifteen generated vtable units at or past its end, or before
# it, other than the reads tools/table-bounds/allow.tsv lists, or when a read
# it lists is gone (VEGAS-30). Each table's length is its slot count in the
# source the build compiles: the composed copy for the four composed units.
if(vegas_object_checks)
  get_target_property(vegas_vtable_sources game SOURCES)
  list(FILTER vegas_vtable_sources INCLUDE REGEX "generated/data/vtables_01[0-9a-f][0-9a-f]\\.cpp$")
  list(LENGTH vegas_vtable_sources vegas_vtable_count)
  if(NOT vegas_vtable_count EQUAL 15)
    message(FATAL_ERROR "expected 15 generated vtable units, found ${vegas_vtable_count}")
  endif()
  list(JOIN vegas_vtable_sources "\n" vegas_vtable_lines)
  file(GENERATE OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/vtable-sources.txt
    CONTENT "${vegas_vtable_lines}\n")
  add_test(NAME objects.table_bounds
    COMMAND ${GO_EXECUTABLE} run . --sources ${CMAKE_CURRENT_BINARY_DIR}/vtable-sources.txt
            --root ${PROJECT_SOURCE_DIR}
            --objects ${CMAKE_CURRENT_BINARY_DIR}/game-objects.txt --allow allow.tsv
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tools/table-bounds)
endif()

# Fails when the function at 0x00cbaec0 (VEGAS-102) again calls slot 2 of the
# table it stores, DAT_010c8d28, with the object and its data, as a member
# call does, instead of with the data alone. That slot holds 0x00cb9cb0,
# which frees its one argument. The check traces rcx at the call through
# offset 16 of the table back to where it was set, which must be the load of
# the data pointer at offset 8; the member call passed the object there. It
# reads the archive with llvm-objdump. The patterns are specific to clang-cl
# at /O2. Blind spots: registers, not values, are matched; the trace follows
# address order, not control flow; a call that also passes something in rdx
# passes. Since VEGAS-106 the compiler loads the data into another register,
# which the inlined ReleaseItems also walks, and copies it to rcx, so the
# check no longer matches a load into rcx itself.
if(vegas_object_checks)
  add_test(NAME objects.release_and_destroy_slot_call
    COMMAND ${CMAKE_COMMAND}
      -DOBJDUMP=${LLVM_OBJDUMP_EXECUTABLE}
      -DARCHIVE=$<TARGET_FILE:game>
      -DWORK=${CMAKE_CURRENT_BINARY_DIR}/release_and_destroy_slot_call.disassembly.txt
      "-DFUNCTION=?ReleaseAndDestroy@FUN_00cbaec0_Obj@@QEAAPEAU1@E@Z"
      "-DSITE=^callq \\*0x10\\(%rax\\)$"
      -DREGISTER=rcx
      "-DORIGIN=^movq 0x8\\(%r[a-z0-9]+\\), BASE$"
      -DCOUNT=1
      -P ${CMAKE_CURRENT_SOURCE_DIR}/archive/expect_register_origin.cmake)
endif()

# Fails when the function at 0x00cb9cb0 (VEGAS-102), which seven slots of
# generated data hold, again frees a null pointer instead of the
# pointer it is given: the body passed {} to the memory manager's free and
# took no parameter. The one-pointer body moves its argument from rcx to rdx
# for the free. It reads the archive with llvm-objdump. The patterns are
# specific to clang-cl at /O2. Blind spots: a body that loads rdx from
# somewhere other than its argument after the move passes; the callee and the
# memory manager are relocations, not checked here.
if(vegas_object_checks)
  add_test(NAME objects.memory_free_forwarder
    COMMAND ${CMAKE_COMMAND}
      -DOBJDUMP=${LLVM_OBJDUMP_EXECUTABLE}
      -DARCHIVE=$<TARGET_FILE:game>
      -DWORK=${CMAKE_CURRENT_BINARY_DIR}/memory_free_forwarder.disassembly.txt
      "-DFUNCTION=?FUN_00cb9cb0@fnv_00cb9cb0@@YAXPEAX@Z"
      "-DFORBID=^xor[lq]?[ \t]+%[re]?dx, %[re]?dx$"
      "-DREQUIRE=^movq[ \t]+%rcx, %rdx$"
      -P ${CMAKE_CURRENT_SOURCE_DIR}/archive/expect_function_instructions.cmake)
endif()

add_test(NAME build.steamworks_sdk_configure
  COMMAND ${CMAKE_COMMAND}
    -DMODULE=${PROJECT_SOURCE_DIR}/third_party/steamworks_sdk.cmake
    -DWORK=${CMAKE_CURRENT_BINARY_DIR}/steamworks_sdk_configure
    -P ${CMAKE_CURRENT_SOURCE_DIR}/steamworks_sdk/configure_test.cmake)

# The one owner of NiAnimationKey's function tables and key sizes.
add_executable(runtime_animation_key_tables_test runtime/animation_key_tables_test.cpp)
target_include_directories(runtime_animation_key_tables_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
if(WIN32)
  target_link_libraries(runtime_animation_key_tables_test PRIVATE game)
else()
  target_sources(runtime_animation_key_tables_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/gamebryo2.2/corelibs/nianimation/nianimationkey_tables.cpp)
endif()
add_test(NAME runtime.animation_key_tables COMMAND runtime_animation_key_tables_test)

# The key table block has one owner in the game archive (VEGAS-51). It reads
# the archive with Python 3 and llvm-objdump.
if(vegas_object_checks)
  add_test(NAME archive.animation_key_tables
    COMMAND ${Python3_EXECUTABLE} ${PROJECT_SOURCE_DIR}/tools/animation-key-tables/check.py
            --archive $<TARGET_FILE:game> --recipe ${PROJECT_SOURCE_DIR}/build/units.json
            --objdump ${LLVM_OBJDUMP_EXECUTABLE})
endif()

# Fails when TESAnimGroup's sound entry resize (0x005f2820) scales a count by
# 16, the 32-bit size of TESAnimGroup::AnimGroupSound, or no longer steps
# through the entries it writes 24 bytes apart, the windows-x64 size. The
# body allocated count * 16 bytes and wrote 24-byte entries past the end of the
# block (docs/shared-tesanimgroup.md). It reads the archive with llvm-objdump.
# The patterns are specific to clang-cl at /O2. Blind spots: a count scaled by
# 16 in another way (an add chain, an lea with a multiple of 16) passes; the
# required addq $0x18 checks that the loop still steps 24 bytes, it does not
# tell the two sizes apart; the allocated size is not compared with the extent
# the body writes.
if(vegas_object_checks)
  add_test(NAME objects.anim_group_sound_entry_size
    COMMAND ${CMAKE_COMMAND}
      -DOBJDUMP=${LLVM_OBJDUMP_EXECUTABLE}
      -DARCHIVE=$<TARGET_FILE:game>
      -DWORK=${CMAKE_CURRENT_BINARY_DIR}/anim_group_sound_entry_size.disassembly.txt
      "-DFUNCTION=?FUN_005f2820@FUN_005f2820_shell@@QEAAXI@Z"
      "-DFORBID=^(shl|sal)[lq]?[ \t]+[$]0x4,|^imul[lq]?[ \t]+[$]0x10,"
      "-DREQUIRE=^addq[ \t]+[$]0x18,"
      -P ${CMAKE_CURRENT_SOURCE_DIR}/archive/expect_function_instructions.cmake)
endif()

# Fails when the cell's reference placement (0x00548880) no longer passes the
# x and z of GetRadii's by-value result (0x00413fc0) to the NiPoint2
# constructor. The body discarded the result and built the point from a local
# nothing wrote, so at /O2 the constructor got whatever xmm1 and xmm2 held
# (VEGAS-90). It reads the archive with llvm-objdump.
# The check is specific to clang-cl's windows-x64 code: the result address in
# rdx, set by one leaq. Blind spots: it does not follow branches; a load from
# the slot that is overwritten before the constructor call passes; it does not
# check that the constructor stores the two floats.
if(vegas_object_checks)
  add_test(NAME objects.cell_reference_radii_result
    COMMAND ${CMAKE_COMMAND}
      -DOBJDUMP=${LLVM_OBJDUMP_EXECUTABLE}
      -DARCHIVE=$<TARGET_FILE:game>
      -DWORK=${CMAKE_CURRENT_BINARY_DIR}/cell_reference_radii_result.disassembly.txt
      "-DFUNCTION=?FUN_00548880@FNV_Cell@fnv_00548880@@QEAAXPEAUFNV_Ref@2@H@Z"
      "-DCALLEE=?GetRadii@FUN_00413fc0_Class@@QEBA?AUblob12@@XZ"
      "-DNEXT=??0NiPoint2@fnv_00548880@@QEAA@MM@Z"
      -DSLOT_REGISTER=rdx
      -DLOADS=0:xmm1,8:xmm2
      -P ${CMAKE_CURRENT_SOURCE_DIR}/archive/expect_call_result_loads.cmake)
endif()

# The line in which vegas-setup names the commit it was built from
# (VEGAS-107). The test runs vegas-setup, so a cross build does not register
# it. The second test runs the header's generator on a folder without .git,
# as in a git archive export, on every host.
if(NOT CMAKE_CROSSCOMPILING)
  add_test(NAME setup.build_commit_line
    COMMAND ${CMAKE_COMMAND} -DPROGRAM=$<TARGET_FILE:vegas-setup>
      -P ${CMAKE_CURRENT_SOURCE_DIR}/setup/build_commit_line.cmake)
endif()
add_test(NAME setup.build_commit_export
  COMMAND ${CMAKE_COMMAND} -DGENERATOR=${PROJECT_SOURCE_DIR}/src/setup/build_commit.cmake
    -DWORK=${CMAKE_CURRENT_BINARY_DIR}/build_commit_export
    -DGIT_EXECUTABLE=${GIT_EXECUTABLE}
    -P ${CMAKE_CURRENT_SOURCE_DIR}/setup/build_commit_export.cmake)
# The generator on a repository each test creates: a clean checkout, a
# changed file, an untracked file under status.showUntrackedFiles=no, and an
# export under an exported GIT_DIR. They need git.
if(GIT_FOUND)
  foreach(case no_changes with_changes hidden_untracked git_dir)
    add_test(NAME setup.build_commit_${case}
      COMMAND ${CMAKE_COMMAND} -DGENERATOR=${PROJECT_SOURCE_DIR}/src/setup/build_commit.cmake
        -DWORK=${CMAKE_CURRENT_BINARY_DIR}/build_commit_${case}
        -DGIT_EXECUTABLE=${GIT_EXECUTABLE} -DCASE=${case}
        -P ${CMAKE_CURRENT_SOURCE_DIR}/setup/build_commit_repository.cmake)
  endforeach()
endif()

# The native owner of the main window class (VEGAS-52), published from packs
# the data pack writer makes while the test runs; a read before publication
# aborts. The data pack stage, refused, publishes no main window class.
add_executable(runtime_main_window_class_test runtime/main_window_class_test.cpp)
target_include_directories(runtime_main_window_class_test PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
if(WIN32)
  target_link_libraries(runtime_main_window_class_test PRIVATE game)
else()
  target_sources(runtime_main_window_class_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/main_window_class.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_validation.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_structure.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_container.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_writer.cpp)
  target_link_libraries(runtime_main_window_class_test PRIVATE ZLIB::ZLIBSTATIC)
endif()
add_test(NAME runtime.main_window_class COMMAND runtime_main_window_class_test)
add_test(NAME runtime.main_window_class.unpublished_read
  COMMAND ${CMAKE_COMMAND}
    -DPROGRAM=$<TARGET_FILE:runtime_main_window_class_test>
    -DMODE=--read-unpublished
    -DMARKER=read-unpublished
    -P ${CMAKE_CURRENT_SOURCE_DIR}/runtime/expect_abort.cmake)
add_test(NAME runtime.data_pack_startup.refused_publishes_no_window_class
  COMMAND ${CMAKE_COMMAND}
    -DPROGRAM=$<TARGET_FILE:runtime_data_pack_startup_test>
    -DMODE=--refused-then-read-window-class
    -DMARKER=refused-then-read-window-class
    -P ${CMAKE_CURRENT_SOURCE_DIR}/runtime/expect_abort.cmake)

# The decision of the second-window check (VEGAS-52) on both branches, with
# the window search and the foreground call recorded: no real window is
# looked for or touched.
add_executable(runtime_second_window_check_test runtime/second_window_check_test.cpp)
target_include_directories(runtime_second_window_check_test PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
if(WIN32)
  target_link_libraries(runtime_second_window_check_test PRIVATE game)
else()
  target_sources(runtime_second_window_check_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/second_window_check.cpp)
endif()
add_test(NAME runtime.second_window_check COMMAND runtime_second_window_check_test)

# Fails when a function that releases the items of an array (VEGAS-106) again
# passes ReleaseItems (0x00cba0d0) its own object as the item array, and a
# pointer converted to an integer as the count, instead of the array and its
# count. ReleaseItems is inlined into each: the check traces the array of
# every inlined step back to the load of the array field, at the offset
# given, and fails when it reaches the object's own pointer or the address of
# a member. Each function's number of inlined steps is fixed. A second check
# fails when the definition at the row's name, which takes a 32-bit count, is
# missing or again takes a 64-bit one. They read the archive with llvm-objdump.
# The patterns are specific to clang-cl at /O2. Blind spots: the trace follows
# address order, not control flow; the count is not traced; a call of
# ReleaseItems that is not inlined is not checked.
if(vegas_object_checks)
  set(vegas_release_items_arrays
    "FUN_00cbadf0|?FUN_00cbadf0@CBADDynamicArray@@QEAAXI_N@Z|0x8|2"
    "FUN_00cbadb0|??1FUN_00cbadb0_Obj@@UEAA@XZ|0x8|1"
    "FUN_00cbadb0_deleting|??_GFUN_00cbadb0_Obj@@UEAAPEAXI@Z|0x8|1"
    "ReleaseAndDestroy|?ReleaseAndDestroy@FUN_00cbaec0_Obj@@QEAAPEAU1@E@Z|0x8|1"
    "ArrayCBAF90_deleting|??_GArrayCBAF90@@UEAAPEAXI@Z|0x8|1"
    "FUN_00cbaf90|??1FUN_00cbaf90@@UEAA@XZ|0x18|1"
    "FUN_00cbaf90_deleting|??_GFUN_00cbaf90@@UEAAPEAXI@Z|0x18|1"
    "FUN_00cbb130|?FUN_00cbb130@FUN_00cbb130_Class@@QEAAPEAXE@Z|0x18|1")
  foreach(vegas_entry IN LISTS vegas_release_items_arrays)
    string(REPLACE "|" ";" vegas_entry "${vegas_entry}")
    list(GET vegas_entry 0 vegas_label)
    list(GET vegas_entry 1 vegas_function)
    list(GET vegas_entry 2 vegas_offset)
    list(GET vegas_entry 3 vegas_steps)
    add_test(NAME objects.release_items_array.${vegas_label}
      COMMAND ${CMAKE_COMMAND}
        -DOBJDUMP=${LLVM_OBJDUMP_EXECUTABLE}
        -DARCHIVE=$<TARGET_FILE:game>
        -DWORK=${CMAKE_CURRENT_BINARY_DIR}/release_items_array.${vegas_label}.disassembly.txt
        "-DFUNCTION=${vegas_function}"
        "-DSITE=^movq \\(%(r[a-z0-9]+),%r[a-z0-9]+,8\\), %rcx$"
        "-DFOLLOWED_BY=^decl 0x8\\(%rcx\\)$"
        "-DORIGIN=^movq ${vegas_offset}\\(%r[a-z0-9]+\\), BASE$"
        -DCOUNT=${vegas_steps}
        -P ${CMAKE_CURRENT_SOURCE_DIR}/archive/expect_register_origin.cmake)
  endforeach()
  add_test(NAME objects.release_items_count
    COMMAND ${CMAKE_COMMAND}
      -DOBJDUMP=${LLVM_OBJDUMP_EXECUTABLE}
      -DARCHIVE=$<TARGET_FILE:game>
      -DWORK=${CMAKE_CURRENT_BINARY_DIR}/release_items_count.disassembly.txt
      "-DFUNCTION=?ReleaseItems@@YAXPEAPEAVFUN_00cba0d0_cls@@I@Z"
      "-DFORBID=^testq[ \t]+%rdx, %rdx$"
      "-DREQUIRE=^testl[ \t]+%edx, %edx$"
      -P ${CMAKE_CURRENT_SOURCE_DIR}/archive/expect_function_instructions.cmake)
endif()

# Fails when a function that frees the data of an array whose table the
# recipe maps to DAT_010c8d28 (VEGAS-103) again calls slot 2 of the object's
# table as a member function, with the object in rcx and the data in rdx,
# instead of with the data alone. That slot holds 0x00cb9cb0, which frees its
# one argument. The check traces rcx at the call through offset 16 of the
# table back to the load of the data field, at the offset given, and fails
# when it reaches the object itself or the address of a member. It reads the
# archive with llvm-objdump. The patterns are specific to clang-cl at /O2.
# Blind spots: registers, not values, are matched; the trace follows address
# order, not control flow; a call that also passes something in rdx passes.
if(vegas_object_checks)
  set(vegas_slot_frees
    "FUN_00cbadb0|??1FUN_00cbadb0_Obj@@UEAA@XZ|0x8"
    "FUN_00cbadb0_deleting|??_GFUN_00cbadb0_Obj@@UEAAPEAXI@Z|0x8"
    "ArrayCBAF90_deleting|??_GArrayCBAF90@@UEAAPEAXI@Z|0x8"
    "FUN_00cbaf90|??1FUN_00cbaf90@@UEAA@XZ|0x18"
    "FUN_00cbaf90_deleting|??_GFUN_00cbaf90@@UEAAPEAXI@Z|0x18"
    "FUN_00cbb130|?FUN_00cbb130@FUN_00cbb130_Class@@QEAAPEAXE@Z|0x18")
  foreach(vegas_entry IN LISTS vegas_slot_frees)
    string(REPLACE "|" ";" vegas_entry "${vegas_entry}")
    list(GET vegas_entry 0 vegas_label)
    list(GET vegas_entry 1 vegas_function)
    list(GET vegas_entry 2 vegas_offset)
    add_test(NAME objects.slot_free_argument.${vegas_label}
      COMMAND ${CMAKE_COMMAND}
        -DOBJDUMP=${LLVM_OBJDUMP_EXECUTABLE}
        -DARCHIVE=$<TARGET_FILE:game>
        -DWORK=${CMAKE_CURRENT_BINARY_DIR}/slot_free_argument.${vegas_label}.disassembly.txt
        "-DFUNCTION=${vegas_function}"
        "-DSITE=^callq \\*0x10\\(%rax\\)$"
        -DREGISTER=rcx
        "-DORIGIN=^movq ${vegas_offset}\\(%r[a-z0-9]+\\), BASE$"
        -DCOUNT=1
        -P ${CMAKE_CURRENT_SOURCE_DIR}/archive/expect_register_origin.cmake)
  endforeach()
endif()

# Fails when a function of actor.cpp that frees an array's data through the
# slot after a generated table (VEGAS-103) again calls it under a name of the
# object and data form, which no object defines, or no longer under the name
# of the slot's one-pointer declaration. A second check fails when
# TempArray's destructor no longer passes the data pointer, loaded from
# offset 8, in rcx: the old form passed the object there and the data, read
# as 32 bits, in rdx. It reads the archive with llvm-objdump; the patterns are
# specific to clang-cl at /O2. Blind spot: the second check covers the
# destructor's own body; the inlined copies in the constructor at 0x00c7f060
# are covered by the name only.
if(vegas_object_checks)
  add_test(NAME objects.slot_free_calls
    COMMAND ${GO_EXECUTABLE} run . --table slot-free-calls.tsv
            --objects ${CMAKE_CURRENT_BINARY_DIR}/game-objects.txt
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tools/function-relocations)
  add_test(NAME objects.slot_free_argument.TempArray
    COMMAND ${CMAKE_COMMAND}
      -DOBJDUMP=${LLVM_OBJDUMP_EXECUTABLE}
      -DARCHIVE=$<TARGET_FILE:game>
      -DWORK=${CMAKE_CURRENT_BINARY_DIR}/slot_free_argument.TempArray.disassembly.txt
      "-DFUNCTION=??1TempArray@@QEAA@XZ"
      "-DSITE=^callq \\*\\(%rip\\)$"
      -DREGISTER=rcx
      "-DORIGIN=^movq 0x8\\(%r[a-z0-9]+\\), BASE$"
      -DCOUNT=1
      -P ${CMAKE_CURRENT_SOURCE_DIR}/archive/expect_register_origin.cmake)
endif()

# Fails when the deleting destructor of actor.cpp's BoneRecordArray
# (VEGAS-103) no longer passes the data pointer, loaded from offset 8, in rcx
# to the slot after its table. The member call it replaced passed the object
# there and the data in rdx. It reads the archive with llvm-objdump; the
# patterns are specific to clang-cl at /O2. Blind spot: the copies inlined
# into FUN_00c7e3b0 are covered by objects.slot_free_calls, by name only.
if(vegas_object_checks)
  add_test(NAME objects.slot_free_argument.BoneRecordArray
    COMMAND ${CMAKE_COMMAND}
      -DOBJDUMP=${LLVM_OBJDUMP_EXECUTABLE}
      -DARCHIVE=$<TARGET_FILE:game>
      -DWORK=${CMAKE_CURRENT_BINARY_DIR}/slot_free_argument.BoneRecordArray.disassembly.txt
      "-DFUNCTION=??_GBoneRecordArray@SkeletonBuild@@UEAAPEAXI@Z"
      "-DSITE=^callq \\*\\(%rip\\)$"
      -DREGISTER=rcx
      "-DORIGIN=^movq 0x8\\(%r[a-z0-9]+\\), BASE$"
      -DCOUNT=1
      -P ${CMAKE_CURRENT_SOURCE_DIR}/archive/expect_register_origin.cmake)
endif()

# Fails when a function that reads or writes the user folder buffer at
# 0x01202fa0 (VEGAS-109) again refers to the 8-byte pointer the buffer was
# defined as, addresses the buffer at or past its 260 bytes, or no longer
# refers to the buffer. It uses the object list and GO_EXECUTABLE of the
# checks above.
if(vegas_object_checks)
  add_test(NAME objects.log_path_buffer
    COMMAND ${GO_EXECUTABLE} run . --table log-path-buffer.tsv
            --objects ${CMAKE_CURRENT_BINARY_DIR}/game-objects.txt
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tools/function-relocations)
endif()

# The startup and blocker map (tools/startup-map). docs.startup_map fails when
# README.md or docs/startup-map.md differs from what the generator writes from
# map.json; docs.startup_map.generator runs the generator's own tests. Both
# read the source folder only, on every host. Without Python 3 the configure
# goes on, and both tests are still registered and fail with that reason.
if(Python3_Interpreter_FOUND)
  add_test(NAME docs.startup_map
    COMMAND ${Python3_EXECUTABLE} -B ${PROJECT_SOURCE_DIR}/tools/startup-map/startup_map.py --check)
  add_test(NAME docs.startup_map.generator
    COMMAND ${Python3_EXECUTABLE} -B ${PROJECT_SOURCE_DIR}/tools/startup-map/test_startup_map.py)
else()
  string(CONCAT docs_startup_map_missing
    "Python 3 was not found when configuring, so the startup map tests cannot "
    "run (tools/startup-map). Install Python 3 and configure again.")
  message(WARNING "${docs_startup_map_missing}")
  foreach(name docs.startup_map docs.startup_map.generator)
    add_test(NAME ${name} COMMAND ${CMAKE_COMMAND} -E echo "${docs_startup_map_missing}")
    set_tests_properties(${name} PROPERTIES FAIL_REGULAR_EXPRESSION "Python 3 was not found")
  endforeach()
endif()

# Fails when the setting value accessor at 0x0043d4d0 (VEGAS-111) again
# returns the address 4 bytes into the setting, the 32-bit offset of the
# value, instead of the value member of the shared Setting, 8 bytes in on
# windows-x64. It reads the archive with llvm-objdump. The patterns are
# specific to clang-cl at /O2, which adds the offset to the setting's address.
# Blind spots: an offset reached in another way (a register, an lea with an
# index) passes the forbidden pattern; the required pattern does not tell a
# load from an address.
if(vegas_object_checks)
  add_test(NAME objects.setting_value_accessor
    COMMAND ${CMAKE_COMMAND}
      -DOBJDUMP=${LLVM_OBJDUMP_EXECUTABLE}
      -DARCHIVE=$<TARGET_FILE:game>
      -DWORK=${CMAKE_CURRENT_BINARY_DIR}/setting_value_accessor.disassembly.txt
      "-DFUNCTION=?FUN_0043d4d0@@YAAEAHPEAVSetting@@@Z"
      "-DFORBID=^(addq[ \t]+[$]0x4, %r|leaq[ \t]+0x4[(]%r)"
      "-DREQUIRE=^(addq[ \t]+[$]0x8, %r|leaq[ \t]+0x8[(]%r)"
      -P ${CMAKE_CURRENT_SOURCE_DIR}/archive/expect_function_instructions.cmake)
  # Fails when a sampled caller of the accessor again calls its 32-bit form,
  # which no object defines, or no longer calls the form that takes the shared
  # Setting.
  add_test(NAME objects.setting_value_accessor_callers
    COMMAND ${GO_EXECUTABLE} run . --table setting-value-accessor.tsv
            --objects ${CMAKE_CURRENT_BINARY_DIR}/game-objects.txt
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tools/function-relocations)
endif()

# Fails when a path buffer of path-buffer-extents.tsv (VEGAS-112) again
# reaches fewer than the 260 bytes its writers copy: the distance from its
# symbol to the next symbol of its section, or to the section's end.
# DAT_01202b48 in the object of log_paths.cpp, which generated data
# defined as one byte, and DAT_01202e98 in the object of main.cpp, which it
# defined as an int under another name. Blind spot: padding before the next
# symbol counts, so an array a few bytes short passes; the static_assert in
# FUN_00c3bbd0 and in FUN_0086d480 holds the exact size. It uses the object
# list and GO_EXECUTABLE of the checks above.
if(vegas_object_checks)
  add_test(NAME objects.path_buffer_extents
    COMMAND ${GO_EXECUTABLE} run . --table path-buffer-extents.tsv
            --objects ${CMAKE_CURRENT_BINARY_DIR}/game-objects.txt
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tools/data-values)
endif()

# Fails when the float setting accessor at 0x00403e20 (VEGAS-116) again
# returns the address 4 bytes into the setting, the 32-bit offset of the
# value, instead of the value member of the shared Setting, 8 bytes in on
# windows-x64. It reads the archive with llvm-objdump. The patterns are
# specific to clang-cl at /O2, which adds the offset to the setting's address.
# Blind spots: an offset reached in another way (a register, an lea with an
# index) passes the forbidden pattern; the required pattern does not tell a
# load from an address.
if(vegas_object_checks)
  add_test(NAME objects.float_setting_accessor
    COMMAND ${CMAKE_COMMAND}
      -DOBJDUMP=${LLVM_OBJDUMP_EXECUTABLE}
      -DARCHIVE=$<TARGET_FILE:game>
      -DWORK=${CMAKE_CURRENT_BINARY_DIR}/float_setting_accessor.disassembly.txt
      "-DFUNCTION=?FUN_00403e20@@YAAEAMPEAVSetting@@@Z"
      "-DFORBID=^(addq[ \t]+[$]0x4, %r|leaq[ \t]+0x4[(]%r)"
      "-DREQUIRE=^(addq[ \t]+[$]0x8, %r|leaq[ \t]+0x8[(]%r)"
      -P ${CMAKE_CURRENT_SOURCE_DIR}/archive/expect_function_instructions.cmake)
  # Fails when a sampled caller of the accessor again calls its 32-bit form,
  # which no object defines, or no longer calls the form that takes the shared
  # Setting.
  add_test(NAME objects.float_setting_accessor_callers
    COMMAND ${GO_EXECUTABLE} run . --table float-setting-accessor.tsv
            --objects ${CMAKE_CURRENT_BINARY_DIR}/game-objects.txt
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tools/function-relocations)
endif()

# The checks of tests/checks, one file per check or ticket, included in name
# order (tests/checks/README.md). Each file registers its own tests, so a new
# check adds a file there instead of a block here.
file(GLOB vegas_check_files CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/checks/*.cmake")
list(SORT vegas_check_files)
foreach(vegas_check_file IN LISTS vegas_check_files)
  include("${vegas_check_file}")
endforeach()
