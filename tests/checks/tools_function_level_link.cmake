# Fails when tools/function-level-link's check.py accepts a reference to an
# unresolved name from a kept COMDAT section (external or static leader), from
# a section that is not a COMDAT in a loaded object (an object of the target
# is always loaded), from a section associated with a kept one or kept by a
# direct reference, through an import slot that lld-link made for an
# unresolved name, through a weak external, or from a section whose
# relocation count overflowed into its first relocation; refuses one from a
# discarded COMDAT, from a member the link did not load, from a COMDAT whose
# other copy the link selected, from a member that shares its map name with
# another member but not the listed symbol, or through the import slot of a
# defined name or of a library; stops refusing what it cannot classify (a
# member with no section the map could list, a label or a symbol of a section
# lld-link drops taken as such a section, a COMDAT without a leading symbol,
# an associative section with no valid parent (the high part of a bigobj
# parent number included) or one that two members of one map name define, two
# objects of one map name that both define a listed leading symbol, an
# unresolved name that no relocation targets, an absolute zero name that no
# object read refers to, a map that names a project object it did not read or
# a library that is neither read nor listed, a map line out of its place or
# after the static symbols, a map without its entry point or static symbols),
# a map of another link (name, timestamp, load address, entry point or section
# table) or unreadable input, a truncated archive member included; or stops
# reading backslash member names, bigobj objects, a map with CRLF line ends or
# a map in repro mode. The tests write small objects, archives, maps and
# executables and run on every host. Blind spot: the inputs are hand-made,
# not linker output; the link tests of link_function_level.cmake cover real
# links. A test method added to the .py but not to this list never runs.
set(tools_function_level_link_cases dead_comdat_accepted unresolved_export_refused
    kept_comdat_live static_leader_kept_live
    non_comdat_section_live associative_follows_parent member_not_loaded_accepted
    member_loaded_live member_with_only_comdats_unclassified backslash_member_name
    two_objects_one_name_unclassified two_objects_one_name_told_apart
    other_copy_selected_accepted no_relocation_unclassified zero_name_without_reference_refused
    known_zero_names_accepted unread_project_object_refused resource_object_not_read system_library_object_not_read
    unknown_map_line_refused missing_map_unreadable map_of_another_link_refused
    repro_mode_timestamp_not_compared bigobj_read truncated_object_unreadable
    truncated_member_unreadable import_slot_live import_slot_of_defined_name_accepted
    associative_kept_by_direct_reference associative_of_two_members_unclassified
    target_object_always_loaded import_of_unresolved_name_from_library_accepted
    unread_library_refused leaderless_comdat_unclassified bad_associative_parent_unclassified
    bigobj_associative_parent_high_part relocation_count_overflow_read weak_external_unresolved
    symbols_never_listed_are_no_evidence map_line_after_static_symbols_refused
    symbol_line_with_other_tail_refused crlf_map_read shell32_import_accepted)
if(Python3_Interpreter_FOUND)
  foreach(tools_function_level_link_case IN LISTS tools_function_level_link_cases)
    add_test(NAME tools.function_level_link.${tools_function_level_link_case}
      COMMAND ${Python3_EXECUTABLE} -B "${PROJECT_SOURCE_DIR}/tools/function-level-link/test_check.py"
              CheckTest.test_${tools_function_level_link_case})
  endforeach()
else()
  string(CONCAT tools_function_level_link_missing
    "Python 3 was not found when configuring, so the tools.function_level_link tests "
    "cannot run (tools/function-level-link). Install Python 3 and configure again.")
  message(WARNING "${tools_function_level_link_missing}")
  foreach(tools_function_level_link_case IN LISTS tools_function_level_link_cases)
    add_test(NAME tools.function_level_link.${tools_function_level_link_case}
      COMMAND ${CMAKE_COMMAND} -E echo "${tools_function_level_link_missing}")
    set_tests_properties(tools.function_level_link.${tools_function_level_link_case} PROPERTIES
      FAIL_REGULAR_EXPRESSION "Python 3 was not found")
  endforeach()
endif()
