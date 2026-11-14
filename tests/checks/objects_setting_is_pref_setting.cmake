# objects.setting_is_pref_setting fails unless exactly one member of the
# game archive defines Setting::IsPrefSetting, the identity that slot 1 of
# Setting's table names at 0x0047c850 (VEGAS-129), and its body returns false
# as the function at that address does: it must clear eax and must not set it
# to 1. Blind spots: it reads the one definition's instructions and nothing
# else, so it does not see which member defines it, which tables refer to it,
# or a body that returns false some other way.
if(vegas_object_checks)
  add_test(NAME objects.setting_is_pref_setting
    COMMAND ${CMAKE_COMMAND}
      -DOBJDUMP=${LLVM_OBJDUMP_EXECUTABLE}
      -DARCHIVE=$<TARGET_FILE:game>
      -DWORK=${CMAKE_CURRENT_BINARY_DIR}/setting_is_pref_setting.disassembly.txt
      "-DFUNCTION=?IsPrefSetting@Setting@@UEAA_NXZ"
      "-DFORBID=^mov[bl][ \t]+[$]0x1, %(al|eax)$"
      "-DREQUIRE=^xorl[ \t]+%eax, %eax$"
      -P ${CMAKE_CURRENT_SOURCE_DIR}/archive/expect_function_instructions.cmake)
endif()
