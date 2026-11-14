# objects.log_path_copies fails when one of WinMain's four log-path builders,
# statements S2 to S5 in src/fallout/misc/log_paths.cpp, again calls the C
# runtime's strcpy_s or strcat_s, which end the process when the path does
# not fit, or no longer calls fnv::crt's, which leave the buffer empty
# (VEGAS-130, tools/function-relocations/log-path-copies.tsv). Blind spots:
# those of tools/function-relocations. It reads the relocations of each
# builder's own section, so it counts names, not calls, and does not see a
# copy made through a pointer or by inlined code.
if(vegas_object_checks)
  add_test(NAME objects.log_path_copies
    COMMAND ${GO_EXECUTABLE} run . --table log-path-copies.tsv
            --objects ${CMAKE_CURRENT_BINARY_DIR}/game-objects.txt
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tools/function-relocations)
endif()
