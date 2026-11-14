# Functions whose declaration had lost its "...": the body passed the
# address of a fixed parameter as the argument list of a callee whose
# format is an earlier parameter. The declaration now ends in "..." after
# that format, and the body makes its list with va_start (VEGAS-134,
# docs/variadic-lists.md). Their mangled names changed with it.
#
# Per entry, objects.ellipsis_restored.LABEL.origin fails unless the list
# that the one definition of FUNCTION in the game archive passes or stores
# at SITE was set by ORIGIN, the address of the home slot of the first
# variable argument's register. .spill fails unless the function saves
# that register to its home slot (SPILL), or when it has an instruction of
# the old form's list (FORBID): the address of its copy of the fixed
# parameter. .former_name fails when a member of the archive has a
# relocation to FORMER, the name before the change, as a caller of the old
# declaration has; a definition alone is seen by .spill and .origin. Each
# test fails on the old form. The instruction patterns are
# specific to clang-cl at /O2 and to the function's frame, measured with
# clang-cl 23.1.5 (the cross build) and 20.1.8 (the Windows CI job), whose
# frames are equal here. Blind spots: registers, not values, are matched;
# the trace follows address order, not control flow; what the callee does
# with the list, and whether a caller's arguments fit the format, are not
# checked.
#
# Entry: LABEL|FUNCTION|FORMER|SPILL|FORBID|SITE|ORIGIN
set(objects_ellipsis_restored_entries
  "FUN_00cb0f80|?FUN_00cb0f80@@YAXPEADPEBDZZ|?FUN_00cb0f80@@YAXPEADPEBD0@Z|^movq[ \t]+%r8, 0x70\\(%rsp\\)$|^leaq[ \t]+0x38\\(%rsp\\), |^movq %(r[a-z0-9]+), 0x28\\(%rsp\\)$|^leaq 0x70\\(%rsp\\), BASE$"
)
if(vegas_object_checks)
  foreach(objects_ellipsis_restored_entry IN LISTS objects_ellipsis_restored_entries)
    string(REPLACE "|" ";" objects_ellipsis_restored_fields "${objects_ellipsis_restored_entry}")
    list(GET objects_ellipsis_restored_fields 0 objects_ellipsis_restored_label)
    list(GET objects_ellipsis_restored_fields 1 objects_ellipsis_restored_function)
    list(GET objects_ellipsis_restored_fields 2 objects_ellipsis_restored_former)
    list(GET objects_ellipsis_restored_fields 3 objects_ellipsis_restored_spill)
    list(GET objects_ellipsis_restored_fields 4 objects_ellipsis_restored_forbid)
    list(GET objects_ellipsis_restored_fields 5 objects_ellipsis_restored_site)
    list(GET objects_ellipsis_restored_fields 6 objects_ellipsis_restored_origin)
    add_test(NAME objects.ellipsis_restored.${objects_ellipsis_restored_label}.spill
      COMMAND ${CMAKE_COMMAND}
        -DOBJDUMP=${LLVM_OBJDUMP_EXECUTABLE}
        -DARCHIVE=$<TARGET_FILE:game>
        -DWORK=${CMAKE_CURRENT_BINARY_DIR}/ellipsis_restored.${objects_ellipsis_restored_label}.spill.txt
        "-DFUNCTION=${objects_ellipsis_restored_function}"
        "-DFORBID=${objects_ellipsis_restored_forbid}"
        "-DREQUIRE=${objects_ellipsis_restored_spill}"
        -P ${CMAKE_CURRENT_SOURCE_DIR}/archive/expect_function_instructions.cmake)
    add_test(NAME objects.ellipsis_restored.${objects_ellipsis_restored_label}.origin
      COMMAND ${CMAKE_COMMAND}
        -DOBJDUMP=${LLVM_OBJDUMP_EXECUTABLE}
        -DARCHIVE=$<TARGET_FILE:game>
        -DWORK=${CMAKE_CURRENT_BINARY_DIR}/ellipsis_restored.${objects_ellipsis_restored_label}.origin.txt
        "-DFUNCTION=${objects_ellipsis_restored_function}"
        "-DSITE=${objects_ellipsis_restored_site}"
        "-DORIGIN=${objects_ellipsis_restored_origin}"
        -DCOUNT=1
        -P ${CMAKE_CURRENT_SOURCE_DIR}/archive/expect_register_origin.cmake)
    add_test(NAME objects.ellipsis_restored.${objects_ellipsis_restored_label}.former_name
      COMMAND ${CMAKE_COMMAND}
        -DOBJDUMP=${LLVM_OBJDUMP_EXECUTABLE}
        -DARCHIVE=$<TARGET_FILE:game>
        -DWORK=${CMAKE_CURRENT_BINARY_DIR}/ellipsis_restored.${objects_ellipsis_restored_label}.former_name.txt
        "-DNAMES=${objects_ellipsis_restored_former}"
        -P ${CMAKE_CURRENT_SOURCE_DIR}/archive/expect_no_relocation.cmake)
  endforeach()
endif()
