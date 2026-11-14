# The native owner of the save directory strings (VEGAS-135), the SDIR entry
# of catalogue version 4. runtime.save_directory_strings publishes packs that
# the data pack writer makes while the test runs and reads each field back
# with zeros after its string; it fails when a publication keeps another value
# or moves the owner's storage. runtime.save_directory_strings.unpublished_read
# fails unless a read before any publication aborts, and
# runtime.data_pack_startup.refused_publishes_no_save_directory_strings unless
# a read after a refused pack stage, with nothing published before, aborts.
# Blind spots: the packs are synthetic, and on hosts other than Windows the
# test compiles the owner's units itself instead of linking the game archive.
add_executable(runtime_save_directory_strings_test ${CMAKE_CURRENT_SOURCE_DIR}/runtime/save_directory_strings_test.cpp)
target_include_directories(runtime_save_directory_strings_test PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
if(WIN32)
  target_link_libraries(runtime_save_directory_strings_test PRIVATE game)
else()
  target_sources(runtime_save_directory_strings_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src/fallout/misc/save_directory_strings.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_validation.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_structure.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_container.cpp
    ${PROJECT_SOURCE_DIR}/src/fileformat/pack_writer.cpp)
  target_link_libraries(runtime_save_directory_strings_test PRIVATE ZLIB::ZLIBSTATIC)
endif()
add_test(NAME runtime.save_directory_strings COMMAND runtime_save_directory_strings_test)
add_test(NAME runtime.save_directory_strings.unpublished_read
  COMMAND ${CMAKE_COMMAND}
    -DPROGRAM=$<TARGET_FILE:runtime_save_directory_strings_test>
    -DMODE=--read-unpublished
    -DMARKER=read-unpublished
    -P ${CMAKE_CURRENT_SOURCE_DIR}/runtime/expect_abort.cmake)
add_test(NAME runtime.data_pack_startup.refused_publishes_no_save_directory_strings
  COMMAND ${CMAKE_COMMAND}
    -DPROGRAM=$<TARGET_FILE:runtime_data_pack_startup_test>
    -DMODE=--refused-then-read-save-directory-strings
    -DMARKER=refused-then-read-save-directory-strings
    -P ${CMAKE_CURRENT_SOURCE_DIR}/runtime/expect_abort.cmake)
