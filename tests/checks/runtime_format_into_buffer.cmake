# FUN_00406d00 (VEGAS-131) formats known values, more than the argument
# registers hold, and one text that does not fit its buffer; the test fails
# when the text, the result or the bytes after a short buffer differ. The
# body took its list from the address after its own copy of apFormat, so it
# never read the variable arguments. Blind spots: the test compiles the
# unit's source into its own program instead of linking the game archive,
# so it checks the source with the test's flags, not the archive's object;
# it covers the formats it names, not every conversion.
add_executable(runtime_format_into_buffer_test
  ${CMAKE_CURRENT_SOURCE_DIR}/runtime/format_into_buffer_test.cpp
  ${PROJECT_SOURCE_DIR}/src/fallout_shared/format_into_buffer.cpp)
target_include_directories(runtime_format_into_buffer_test PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include)
add_test(NAME runtime.format_into_buffer COMMAND runtime_format_into_buffer_test)
