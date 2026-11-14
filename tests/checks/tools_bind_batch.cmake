# Fails when tools/bind-batch's gate stops refusing, per candidate, a stand-in
# whose recipe key is missing, held at another address too or doubled, or
# whose row is not the owner; a name on the differing-definitions list; a
# stand-in the tip's undefined list does not name (mangled or as
# llvm-undname prints it) or the unit defines, or an owner that list
# names; an unreadable signature (a
# calling convention only inside brackets); an owner overloaded in its class
# (by a function or a function template); or a unit whose AST dump fails;
# or stops refusing, per site, a void result used (not a whole statement or
# a cast to void), a result, parameter, this, count or calling-convention
# difference, the literal 0 or 1 to bool, an object pointer to void* that
# drops cv or steps derived-to-base, a member against a free call, a static
# member against a free function, a special member, a virtual function, a
# receiver that is not an explicit cast of the stand-in's class or reaches
# the call through a conversion, a site in a macro, header, template or
# lambda, a default argument, a callee whose text is not the name, or a
# descriptive function name that becomes a placeholder or another
# descriptive name; or stops labelling R5a, const added to this and a
# class-only difference; or stops recording a refused site so that its
# name is not bound. Also when the rewrite stops moving the owner verbatim
# with its comment lines and namespaces, stops respelling the cast and the
# callee, or applies edits that overlap; when the recipe respelling stops
# working in every entry of a source that holds the key, keeping order,
# merging into an existing key, or changing nothing when a key is bound
# elsewhere; when prove stops reading the proof mode from objcmp.py's
# verdict (byte-identical bindings, differences, kept or refused reports
# and a failing exit never pass; the moves need equal bytes), stops passing
# --base-holds-new and --function-order with the owners, stops dropping a
# name on one failing variant, a warnings difference, a missing check row,
# or a record layout that differs on windows-x64 or i686 other than a
# removed empty stand-in (an unnamed record's place aside), or a failed
# layout dump; or when apply stops
# needing the proof's files, applying only proved names, or writing nothing
# until every text, key and check row is ready, or check rows stop coming
# from the proof's rows alone with one forbid line per name; or when gate
# stops deleting an earlier proof's files or recording each unit's sha256,
# or prove and apply stop refusing, writing nothing, a unit whose text no
# longer has that sha256 or a plan without it. The tests use
# hand-made AST fragments, texts and reports, a fake compiler named
# clang-cl and a fake objcmp.py, and run on every host. Blind spot: no
# compiler output is read. A test method added to the .py but not to this
# list never runs.
set(tools_bind_batch_cases
    SignatureTest.test_member SignatureTest.test_free_static_virtual_const
    SignatureTest.test_calling_convention_at_depth_0 SignatureTest.test_strict_key_joins_32_and_64
    ExtractTest.test_declarations_and_site ExtractTest.test_unparsed_items_list_their_types
    ExtractTest.test_header_locations_are_not_main ExtractTest.test_lambda_site
    ExtractTest.test_use_of_the_result ExtractTest.test_declarations_of_the_owner_name
    GateTest.test_same_type_admits GateTest.test_void_result_used GateTest.test_parameter_conversions
    GateTest.test_object_pointer_to_void_pointer GateTest.test_call_form_virtual_this_count
    GateTest.test_static_against_free GateTest.test_site_and_receiver_refusals GateTest.test_naming
    GateTest.test_written_type GateUnitTest.test_admit GateUnitTest.test_refusals_per_candidate
    GateUnitTest.test_defined_overloaded_and_unreadable GateUnitTest.test_a_refused_site_keeps_the_name
    RecipeTest.test_respell_in_place RecipeTest.test_every_entry_that_holds_the_key
    RecipeTest.test_merge_into_existing_key_of_another_entry RecipeTest.test_conflicts_change_nothing
    RecipeTest.test_index_merges_entries RecipeTest.test_recipe_check RewriteTest.test_move_then_bind
    RewriteTest.test_stand_in_named_elsewhere_stays RewriteTest.test_no_move_when_visible
    RewriteTest.test_wrapped_move RewriteTest.test_overlapping_edits_refused
    RewriteTest.test_whole_names ProofModeTest.test_modes ProveTest.test_compare_reads_the_verdict
    ProveTest.test_prove_unit_modes_and_rows ProveTest.test_prove_unit_drops ProveTest.test_layouts
    ApplyTest.test_needs_the_proof ApplyTest.test_binds_the_proved_names
    ApplyTest.test_unproved_names_stay ApplyTest.test_nothing_written_unless_everything_is_ready
    ApplyTest.test_a_changed_export_refuses_prove_and_apply
    GateRunTest.test_gate_drops_an_earlier_proof_and_hashes_the_unit
    TableTest.test_rows_from_proof_and_forbid_once TableTest.test_usage)
if(Python3_Interpreter_FOUND)
  foreach(tools_bind_batch_case IN LISTS tools_bind_batch_cases)
    string(REGEX REPLACE "^.*\\.test_" "" tools_bind_batch_name "${tools_bind_batch_case}")
    add_test(NAME tools.bind_batch.${tools_bind_batch_name}
      COMMAND ${Python3_EXECUTABLE} -B "${PROJECT_SOURCE_DIR}/tools/bind-batch/test_bind_batch.py"
              ${tools_bind_batch_case})
  endforeach()
else()
  string(CONCAT tools_bind_batch_missing
    "Python 3 was not found when configuring, so the tools.bind_batch tests "
    "cannot run (tools/bind-batch). Install Python 3 and configure again.")
  message(WARNING "${tools_bind_batch_missing}")
  foreach(tools_bind_batch_case IN LISTS tools_bind_batch_cases)
    string(REGEX REPLACE "^.*\\.test_" "" tools_bind_batch_name "${tools_bind_batch_case}")
    add_test(NAME tools.bind_batch.${tools_bind_batch_name}
      COMMAND ${CMAKE_COMMAND} -E echo "${tools_bind_batch_missing}")
    set_tests_properties(tools.bind_batch.${tools_bind_batch_name} PROPERTIES
      FAIL_REGULAR_EXPRESSION "Python 3 was not found")
  endforeach()
endif()
