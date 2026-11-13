# Runs the recipe check on a copy of the recipe in which one more unit binds
# an address 2 bytes after the main window class pointer (VEGAS-52). Check g
# must refuse it, and no other check: status 1, one problem, a line that
# starts with g. The copy lies in the build folder.
#
# cmake -DPYTHON=<python3> -DCHECK=<check.py> -DRECIPE=<units.json>
#   -DSOURCE=<single_instance_ranges.h> -DPOINTER_SOURCE=<main_window_class_range.h>
#   -DWORK=<folder> -P recipe_ranges_pointer_bound.cmake

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
  "${units_key}{\"source\": \"probe.cpp\", \"symbols\": {\"?probe_011a2fea@@3HA\": \"0x011a2fea\"}},"
  recipe "${recipe}")
file(WRITE "${WORK}/units.json" "${recipe}")
execute_process(COMMAND "${PYTHON}" "${CHECK}" --recipe "${WORK}/units.json"
  --source "${SOURCE}" --pointer-source "${POINTER_SOURCE}"
  RESULT_VARIABLE status OUTPUT_VARIABLE output ERROR_VARIABLE output)
if(NOT status STREQUAL "1" OR NOT output MATCHES "(^|\n)g [^\n]*the recipe bound is 2, less than 4\n"
   OR NOT output MATCHES ", 1 problems\n$")
  message(FATAL_ERROR "check g did not refuse the copy alone (status '${status}'):\n${output}")
endif()
file(REMOVE_RECURSE "${WORK}")
