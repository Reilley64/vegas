# Variadic functions that took their argument list from the address after
# their last named parameter (VEGAS-131). On windows-x64 that address is in
# the function's own frame, so the list never reached the caller's variable
# arguments. With va_start the list is the address of the slot of the first
# variable argument: the home slot of the register that holds it, which the
# function then saves there, or the caller's stack slot.
#
# Per entry, objects.variadic_list.LABEL.origin fails unless the list that
# the one definition of FUNCTION in the game archive passes or stores at
# SITE was set by ORIGIN, the address of that slot.
# objects.variadic_list.LABEL.spill, for an entry with a SPILL pattern,
# fails unless the function saves the register to its home slot, or when
# it has FORBID, an instruction of the old form's list: the address it
# passed (the stack cookie slot, or a slot that nothing writes) or its
# step of four bytes, the 32-bit size of an argument. It reads the
# archive with llvm-objdump. The patterns are specific to clang-cl at /O2
# and to each function's frame. Blind spots: registers, not values, are
# matched; the trace follows address order, not control flow; what the
# callee does with the list is not checked.
#
# Entry: LABEL|FUNCTION|SPILL or -|FORBID|SITE|ORIGIN
set(objects_variadic_lists_entries
  "FUN_00406d00|?FUN_00406d00@@YAHPEADHPEBDZZ|^movq[ \t]+%r9, 0x88\\(%rsp\\)$|^leaq[ \t]+0x40\\(%rsp\\), |^movq %(r[a-z0-9]+), 0x28\\(%rsp\\)$|^leaq 0x88\\(%rsp\\), BASE$"
  "FUN_00a0e470|?FUN_00a0e470@@YAHPEAUDebugText@@HPEBDZZ|^movq[ \t]+%r9, 0x68\\(%rsp\\)$|^leaq[ \t]+0x40\\(%rsp\\), |^movq %(r[a-z0-9]+), 0x28\\(%rsp\\)$|^leaq 0x68\\(%rsp\\), BASE$"
  "FUN_00a0e580|?FUN_00a0e580@@YAHPEAUFUN_00a0e580_VTab@@HHPEBDZZ|-|-|^movq %(r[a-z0-9]+), 0x20\\(%rsp\\)$|^leaq 0x70\\(%rsp\\), BASE$"
  "FUN_00a0e690|?FUN_00a0e690@@YAHPEAUDebugText@@HAEBURgbaColor@@PEBDZZ|-|-|^movq %(r[a-z0-9]+), 0x28\\(%rsp\\)$|^leaq 0x70\\(%rsp\\), BASE$"
  "InvokeVFuncWithVarArgs|?InvokeVFuncWithVarArgs@@YAHPEAUFUN_00a0e6d0_this@@HPEAXHHPEBDZZ|-|-|^movq %(r[a-z0-9]+), 0x28\\(%rsp\\)$|^leaq 0x90\\(%rsp\\), BASE$"
  "NiSprintf|?NiSprintf@@YAHPEADIPEBDZZ|^movq[ \t]+%r9, 0x88\\(%rsp\\)$|^leaq[ \t]+0x38\\(%rsp\\), |^movq %(r[a-z0-9]+), 0x28\\(%rsp\\)$|^leaq 0x88\\(%rsp\\), BASE$"
  "LogScriptCompileError|?LogScriptCompileError@@YAXPEAVScriptRunner@@PEAVScript@@PEADZZ|^movq[ \t]+%r9, 0x168\\(%rsp\\)$|^leaq[ \t]+0x28\\(%rsp\\), |^movq %(r8), 0x20\\(%rsp\\)$|^leaq 0x168\\(%rsp\\), BASE$"
  "ApplyPerkModifiers|?ApplyPerkModifiers@@YAXHPEAVActor@@ZZ|^movq[ \t]+%r8, 0x160\\(%rsp\\)$|^addq[ \t]+\\$0x4, |^movq %(rcx), \\(%rax\\)$|^leaq 0x160\\(%rsp\\), BASE$"
  "FUN_00406f60|?FUN_00406f60@@YAHPEAUFUN_00406f90_this@@PEBDZZ|^movq[ \t]+%r8, 0x50\\(%rsp\\)$|^leaq[ \t]+0x30\\(%rsp\\), |^movq %(r8), 0x28\\(%rsp\\)$|^leaq 0x50\\(%rsp\\), BASE$"
  "FUN_00703e80|?FUN_00703e80@fnv_00703e80@@YA_NPEBD00PEAXHHMM0ZZ|-|-|^movq %(r[a-z0-9]+), 0x78\\(%rsp\\)$|^leaq 0xf8\\(%rsp\\), BASE$"
  "FUN_007ca200|??0FUN_007ca200@@QEAA@HHHHHZZ|-|-|^movq %(rax), -0x20\\(%rbp\\)$|^leaq 0x50\\(%rbp\\), BASE$"
  "FUN_007d6350|??0FUN_007d6350@@QEAA@PEBDPEAXHHIHZZ|-|-|^movq %(rax), -0x10\\(%rbp\\)$|^leaq 0x78\\(%rbp\\), BASE$"
  "FUN_00845cc0|?FUN_00845cc0@@YAXPEBDZZ|^movq[ \t]+%rdx, 0x48\\(%rsp\\)$|^leaq[ \t]+0x2c\\(%rsp\\), |^movq %(rcx), 0x28\\(%rsp\\)$|^leaq 0x48\\(%rsp\\), BASE$"
  "ReportScriptError|?ReportScriptError@@YAXPEAUCStringArgument@@PEBDZZ|^movq[ \t]+%r8, 0x100\\(%rbp\\)$|^leaq[ \t]+0xb8\\(%rbp\\), %r8$|^movq %(r8), 0xb0\\(%rbp\\)$|^leaq 0x100\\(%rbp\\), BASE$"
  "FUN_00cb0c70|?FUN_00cb0c70@hkStringPtr@@QEAAXPEBDZZ|^movq[ \t]+%r8, 0x110\\(%rbp\\)$|^leaq[ \t]+0xb8\\(%rbp\\), |^movq %(rax), 0xb0\\(%rbp\\)$|^leaq 0x110\\(%rbp\\), BASE$"
  "ShaderPassEntry|??0ShaderPassEntry@BSShaderProperty@@QEAA@PEAVNiGeometry@@G_NEPEAVShadowSceneLight@@ZZ|-|-|^movq %(rax), 0x28\\(%rsp\\)$|^leaq 0x90\\(%rsp\\), BASE$"
)
if(vegas_object_checks)
  foreach(objects_variadic_lists_entry IN LISTS objects_variadic_lists_entries)
    string(REPLACE "|" ";" objects_variadic_lists_fields "${objects_variadic_lists_entry}")
    list(GET objects_variadic_lists_fields 0 objects_variadic_lists_label)
    list(GET objects_variadic_lists_fields 1 objects_variadic_lists_function)
    list(GET objects_variadic_lists_fields 2 objects_variadic_lists_spill)
    list(GET objects_variadic_lists_fields 3 objects_variadic_lists_forbid)
    list(GET objects_variadic_lists_fields 4 objects_variadic_lists_site)
    list(GET objects_variadic_lists_fields 5 objects_variadic_lists_origin)
    if(NOT objects_variadic_lists_spill STREQUAL "-")
      add_test(NAME objects.variadic_list.${objects_variadic_lists_label}.spill
        COMMAND ${CMAKE_COMMAND}
          -DOBJDUMP=${LLVM_OBJDUMP_EXECUTABLE}
          -DARCHIVE=$<TARGET_FILE:game>
          -DWORK=${CMAKE_CURRENT_BINARY_DIR}/variadic_list.${objects_variadic_lists_label}.spill.txt
          "-DFUNCTION=${objects_variadic_lists_function}"
          "-DFORBID=${objects_variadic_lists_forbid}"
          "-DREQUIRE=${objects_variadic_lists_spill}"
          -P ${CMAKE_CURRENT_SOURCE_DIR}/archive/expect_function_instructions.cmake)
    endif()
    add_test(NAME objects.variadic_list.${objects_variadic_lists_label}.origin
      COMMAND ${CMAKE_COMMAND}
        -DOBJDUMP=${LLVM_OBJDUMP_EXECUTABLE}
        -DARCHIVE=$<TARGET_FILE:game>
        -DWORK=${CMAKE_CURRENT_BINARY_DIR}/variadic_list.${objects_variadic_lists_label}.origin.txt
        "-DFUNCTION=${objects_variadic_lists_function}"
        "-DSITE=${objects_variadic_lists_site}"
        "-DORIGIN=${objects_variadic_lists_origin}"
        -DCOUNT=1
        -P ${CMAKE_CURRENT_SOURCE_DIR}/archive/expect_register_origin.cmake)
  endforeach()
endif()
