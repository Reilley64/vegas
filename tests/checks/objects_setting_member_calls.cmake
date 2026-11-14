# Fails when a function whose call of a member of the unit's own Setting
# moved to SettingT<INISettingCollection>::Bool, the recipe's row at
# 0x00408d60 (VEGAS-117), again refers to the copy's member, which no object
# defines, or no longer refers to the row's member
# (tools/function-relocations/setting-member-calls.tsv). Blind spots: those
# of tools/function-relocations; it counts names, not calls, sees one
# function's own section, not the copies other functions inline, and does
# not see which member of the result the caller reads.
if(vegas_object_checks)
  add_test(NAME objects.setting_member_calls
    COMMAND ${GO_EXECUTABLE} run . --table setting-member-calls.tsv
            --objects ${CMAKE_CURRENT_BINARY_DIR}/game-objects.txt
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tools/function-relocations)
endif()
