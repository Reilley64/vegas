# The native owner of the log path suffixes (VEGAS-127), the LOGS entry of
# catalogue version 3. runtime.log_path_suffixes publishes packs that the data
# pack writer makes while the test runs and reads each field back with zeros
# after its string; it fails when a publication keeps another value or moves
# the owner's storage. runtime.log_path_suffixes.unpublished_read fails unless
# a read before any publication aborts, and
# runtime.data_pack_startup.refused_publishes_no_log_path_suffixes unless a
# read after a refused pack stage, with nothing published before, aborts.
# Blind spots: the packs are synthetic, and on hosts other than Windows the
# test compiles the owner's units itself instead of linking the game archive.
add_executable(runtime_log_path_suffixes_test ${CMAKE_CURRENT_SOURCE_DIR}/runtime/log_path_suffixes_test.cpp)
target_include_directories(runtime_log_path_suffixes_test PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
if(WIN32)
  target_link_libraries(runtime_log_path_suffixes_test PRIVATE game)
else()
  target_sources(runtime_log_path_suffixes_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/log_path_suffixes.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_validation.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_structure.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_container.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_writer.cpp)
  target_link_libraries(runtime_log_path_suffixes_test PRIVATE ZLIB::ZLIBSTATIC)
endif()
add_test(NAME runtime.log_path_suffixes COMMAND runtime_log_path_suffixes_test)
add_test(NAME runtime.log_path_suffixes.unpublished_read
  COMMAND ${CMAKE_COMMAND}
    -DPROGRAM=$<TARGET_FILE:runtime_log_path_suffixes_test>
    -DMODE=--read-unpublished
    -DMARKER=read-unpublished
    -P ${CMAKE_CURRENT_SOURCE_DIR}/runtime/expect_abort.cmake)
add_test(NAME runtime.data_pack_startup.refused_publishes_no_log_path_suffixes
  COMMAND ${CMAKE_COMMAND}
    -DPROGRAM=$<TARGET_FILE:runtime_data_pack_startup_test>
    -DMODE=--refused-then-read-log-path-suffixes
    -DMARKER=refused-then-read-log-path-suffixes
    -P ${CMAKE_CURRENT_SOURCE_DIR}/runtime/expect_abort.cmake)
