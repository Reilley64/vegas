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
