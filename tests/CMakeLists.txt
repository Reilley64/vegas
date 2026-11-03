add_executable(fileformat_plugin_header_test fileformat/plugin_header_test.cpp)
target_include_directories(fileformat_plugin_header_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(fileformat_plugin_header_test PRIVATE game)
add_test(NAME fileformat.plugin_header COMMAND fileformat_plugin_header_test)

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
