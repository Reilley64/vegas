# The folder check of falloutnv.process_exit and
# falloutnv.process_exit.missing_pack (VEGAS-130). falloutnv.pack_folder_listing
# runs tests/runtime/falloutnv_pack_folder.cmake on a stand-in program and
# fixture (tests/runtime/falloutnv_pack_folder_test.cmake) and fails when the
# check passes a run that leaves an empty folder beside the executable, in the
# working directory or inside a new folder, or a file, or fails a run that
# leaves nothing. The check before VEGAS-130 listed files only, so it passed
# the three empty folders.
# Blind spots: the stand-ins are POSIX shell scripts, so the test is
# registered on hosts other than Windows only, so no CI job runs it (the only
# CI job runs on Windows); it runs no FalloutNV.exe and
# shows nothing about what main leaves; files and folders outside the test's
# folder are not looked for, by the check or by this test.
if(NOT CMAKE_HOST_WIN32)
  add_test(NAME falloutnv.pack_folder_listing
    COMMAND ${CMAKE_COMMAND}
      -DSCRIPT=${CMAKE_CURRENT_SOURCE_DIR}/runtime/falloutnv_pack_folder.cmake
      -DWORK=${CMAKE_CURRENT_BINARY_DIR}/falloutnv.pack_folder_listing
      -P ${CMAKE_CURRENT_SOURCE_DIR}/runtime/falloutnv_pack_folder_test.cmake)
endif()
