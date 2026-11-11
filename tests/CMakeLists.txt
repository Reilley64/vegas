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
  target_sources(fileformat_pack_structure_test PRIVATE ${PROJECT_SOURCE_DIR}/src/fileformat/pack_structure.cpp)
  target_link_libraries(fileformat_pack_structure_test PRIVATE ZLIB::ZLIBSTATIC)
endif()
add_test(NAME fileformat.pack_structure COMMAND fileformat_pack_structure_test)

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
