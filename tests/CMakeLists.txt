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

find_package(Threads REQUIRED)
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
