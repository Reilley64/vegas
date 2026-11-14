# Fails when a member of ARCHIVE has a relocation to one of NAMES.
# OBJDUMP is llvm-objdump. Its relocation listing is written to WORK, read
# back line by line and removed.
foreach(variable OBJDUMP ARCHIVE WORK NAMES)
  if(NOT DEFINED ${variable} OR "${${variable}}" STREQUAL "")
    message(FATAL_ERROR "OBJDUMP, ARCHIVE, WORK and NAMES are required")
  endif()
endforeach()
string(REPLACE "," ";" names "${NAMES}")
# An empty name would match every relocation line that ends in a blank.
foreach(name IN LISTS names)
  if(name STREQUAL "")
    message(FATAL_ERROR "NAMES has an empty entry: ${NAMES}")
  endif()
endforeach()

execute_process(
  COMMAND "${OBJDUMP}" -r "${ARCHIVE}"
  OUTPUT_FILE "${WORK}"
  ERROR_VARIABLE error
  RESULT_VARIABLE result
)
if(NOT result EQUAL 0)
  file(REMOVE "${WORK}")
  message(FATAL_ERROR "${OBJDUMP} -r failed (${result}): ${error}")
endif()

# A member starts with a line "ARCHIVE(MEMBER):<tab>file format ...". A
# relocation line ends with a space and the target's name.
set(alternatives "")
foreach(name IN LISTS names)
  string(REGEX REPLACE "([][+.*()^$?|\\])" "\\\\\\1" escaped "${name}")
  list(APPEND alternatives "${escaped}")
endforeach()
list(JOIN alternatives "|" alternatives)
file(STRINGS "${WORK}" lines REGEX "file format |[ \t](${alternatives})$")
file(REMOVE "${WORK}")

set(member "")
set(found "")
foreach(line IN LISTS lines)
  if(line MATCHES "\\(([^()]+)\\):[ \t]+file format ")
    set(member "${CMAKE_MATCH_1}")
  elseif(line MATCHES "[ \t]([^ \t]+)$")
    list(APPEND found "${member} -> ${CMAKE_MATCH_1}")
  endif()
endforeach()
list(LENGTH lines line_count)
if(line_count EQUAL 0)
  message(FATAL_ERROR "${OBJDUMP} listed no member of ${ARCHIVE}")
endif()
list(REMOVE_DUPLICATES found)
if(found)
  list(JOIN found "\n  " found)
  message(FATAL_ERROR "Members with a relocation to a forbidden name:\n  ${found}")
endif()
