# setup.recipe_ranges.suffix_bound fails unless the recipe check of setup's
# ranges (tools/setup-recipe-ranges) refuses, with check j alone, a copy of
# the recipe in which one more unit binds an address 8 bytes into the third
# log path suffix (VEGAS-127): a capacity that is no longer the recipe bound.
# The copy is written in the build folder. Without Python 3 the test is still
# registered and fails with that reason. Blind spot: it moves the bound of one
# row only; the other rows rely on the same code path.
if(Python3_Interpreter_FOUND)
  add_test(NAME setup.recipe_ranges.suffix_bound
    COMMAND ${CMAKE_COMMAND} -DPYTHON=${Python3_EXECUTABLE}
      -DCHECK=${PROJECT_SOURCE_DIR}/tools/setup-recipe-ranges/check.py
      -DRECIPE=${PROJECT_SOURCE_DIR}/build/units.json
      -DSOURCE=${PROJECT_SOURCE_DIR}/src/setup/single_instance_ranges.h
      -DPOINTER_SOURCE=${PROJECT_SOURCE_DIR}/src/setup/main_window_class_range.h
      -DSUFFIX_SOURCE=${PROJECT_SOURCE_DIR}/src/setup/log_path_suffix_ranges.h
      -DWORK=${CMAKE_CURRENT_BINARY_DIR}/recipe_ranges_suffix_bound
      -P ${CMAKE_CURRENT_SOURCE_DIR}/setup/recipe_ranges_suffix_bound.cmake)
else()
  add_test(NAME setup.recipe_ranges.suffix_bound
    COMMAND ${CMAKE_COMMAND} -E echo "Python 3 was not found when configuring, so setup.recipe_ranges.suffix_bound cannot run")
  set_tests_properties(setup.recipe_ranges.suffix_bound PROPERTIES FAIL_REGULAR_EXPRESSION "Python 3 was not found")
endif()
