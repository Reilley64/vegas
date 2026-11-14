# setup.recipe_ranges.save_directory_bound fails unless the recipe check of
# setup's ranges (tools/setup-recipe-ranges) refuses, with check n alone, a
# copy of the recipe in which one more unit binds an address 4 bytes into the
# setting key of the save directory strings (VEGAS-135): a capacity that is
# no longer the recipe bound. setup.recipe_ranges.save_directory_target_bound
# fails unless check s alone refuses a copy that binds an address 4 bytes into
# the first INI name, the string the pointer at 0x011a2ff4 reaches. Each copy
# is written in the build folder. Without Python 3 both tests are still
# registered and fail with that reason. Blind spot: each moves the bound of
# one row only; the other rows rely on the same code path.
set(setup_recipe_ranges_save_directory_cases
  "save_directory_bound|0x01082db0|n setting key: capacity 24, the recipe bound is 4"
  "save_directory_target_bound|0x01039c90|s first INI name: capacity 12, the recipe bound of the target is 4")
foreach(setup_recipe_ranges_save_directory_case IN LISTS setup_recipe_ranges_save_directory_cases)
  string(REPLACE "|" ";" setup_recipe_ranges_save_directory_parts "${setup_recipe_ranges_save_directory_case}")
  list(GET setup_recipe_ranges_save_directory_parts 0 setup_recipe_ranges_save_directory_name)
  list(GET setup_recipe_ranges_save_directory_parts 1 setup_recipe_ranges_save_directory_address)
  list(GET setup_recipe_ranges_save_directory_parts 2 setup_recipe_ranges_save_directory_expected)
  set(setup_recipe_ranges_save_directory_test setup.recipe_ranges.${setup_recipe_ranges_save_directory_name})
  if(Python3_Interpreter_FOUND)
    add_test(NAME ${setup_recipe_ranges_save_directory_test}
      COMMAND ${CMAKE_COMMAND} -DPYTHON=${Python3_EXECUTABLE}
        -DCHECK=${PROJECT_SOURCE_DIR}/tools/setup-recipe-ranges/check.py
        -DRECIPE=${PROJECT_SOURCE_DIR}/build/units.json
        -DSOURCE=${PROJECT_SOURCE_DIR}/src/setup/single_instance_ranges.h
        -DPOINTER_SOURCE=${PROJECT_SOURCE_DIR}/src/setup/main_window_class_range.h
        -DSUFFIX_SOURCE=${PROJECT_SOURCE_DIR}/src/setup/log_path_suffix_ranges.h
        -DSAVE_SOURCE=${PROJECT_SOURCE_DIR}/src/setup/save_directory_ranges.h
        -DADDRESS=${setup_recipe_ranges_save_directory_address}
        "-DEXPECTED=${setup_recipe_ranges_save_directory_expected}"
        -DWORK=${CMAKE_CURRENT_BINARY_DIR}/recipe_ranges_${setup_recipe_ranges_save_directory_name}
        -P ${CMAKE_CURRENT_SOURCE_DIR}/setup/recipe_ranges_save_directory_bound.cmake)
  else()
    add_test(NAME ${setup_recipe_ranges_save_directory_test}
      COMMAND ${CMAKE_COMMAND} -E echo
        "Python 3 was not found when configuring, so ${setup_recipe_ranges_save_directory_test} cannot run")
    set_tests_properties(${setup_recipe_ranges_save_directory_test} PROPERTIES
      FAIL_REGULAR_EXPRESSION "Python 3 was not found")
  endif()
endforeach()
