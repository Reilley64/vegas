# Runs the recipe check on a copy of the recipe in which one more unit binds
# ADDRESS (VEGAS-135), and requires that the check refuses it with one
# problem alone, the line EXPECTED: status 1, one problem. The copy lies in
# the build folder.
#
# cmake -DPYTHON=<python3> -DCHECK=<check.py> -DRECIPE=<units.json>
#   -DSOURCE=<single_instance_ranges.h> -DPOINTER_SOURCE=<main_window_class_range.h>
#   -DSUFFIX_SOURCE=<log_path_suffix_ranges.h> -DSAVE_SOURCE=<save_directory_ranges.h>
#   -DADDRESS=<0x........> -DEXPECTED=<problem line> -DWORK=<folder> -P recipe_ranges_save_directory_bound.cmake

file(REMOVE_RECURSE "${WORK}")
file(MAKE_DIRECTORY "${WORK}")
file(READ "${RECIPE}" recipe)
set(units_key "\"units\": [")
string(FIND "${recipe}" "${units_key}" first)
string(FIND "${recipe}" "${units_key}" last REVERSE)
if(first EQUAL -1 OR NOT first EQUAL last)
  message(FATAL_ERROR "the recipe does not hold exactly one ${units_key}")
endif()
string(REPLACE "${units_key}"
  "${units_key}{\"source\": \"probe.cpp\", \"symbols\": {\"?probe@@3HA\": \"${ADDRESS}\"}},"
  recipe "${recipe}")
file(WRITE "${WORK}/units.json" "${recipe}")
execute_process(COMMAND "${PYTHON}" "${CHECK}" --recipe "${WORK}/units.json"
  --source "${SOURCE}" --pointer-source "${POINTER_SOURCE}" --suffix-source "${SUFFIX_SOURCE}"
  --save-directory-source "${SAVE_SOURCE}"
  RESULT_VARIABLE status OUTPUT_VARIABLE output ERROR_VARIABLE output)
string(FIND "${output}" "${EXPECTED}\n" at)
if(NOT status STREQUAL "1" OR at EQUAL -1 OR NOT output MATCHES ", 1 problems\n$")
  message(FATAL_ERROR "the check did not refuse the copy with \"${EXPECTED}\" alone (status '${status}'):\n${output}")
endif()
file(REMOVE_RECURSE "${WORK}")
