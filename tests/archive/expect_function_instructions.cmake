# Fails when the one definition of FUNCTION in ARCHIVE has an instruction that
# matches the regular expression FORBID, or none that matches REQUIRE.
# OBJDUMP is llvm-objdump. The disassembly of FUNCTION, without raw bytes, is
# written to WORK, read back line by line and removed. It also fails when no
# member or more than one member defines FUNCTION.
foreach(variable OBJDUMP ARCHIVE WORK FUNCTION FORBID REQUIRE)
  if(NOT DEFINED ${variable} OR "${${variable}}" STREQUAL "")
    message(FATAL_ERROR "OBJDUMP, ARCHIVE, WORK, FUNCTION, FORBID and REQUIRE are required")
  endif()
endforeach()

execute_process(
  COMMAND "${OBJDUMP}" -d --no-show-raw-insn "--disassemble-symbols=${FUNCTION}" "${ARCHIVE}"
  OUTPUT_FILE "${WORK}"
  ERROR_VARIABLE error
  RESULT_VARIABLE result
)
if(NOT result EQUAL 0)
  file(REMOVE "${WORK}")
  message(FATAL_ERROR "${OBJDUMP} -d failed (${result}): ${error}")
endif()
file(STRINGS "${WORK}" lines)
file(REMOVE "${WORK}")

# A definition starts with a line "ADDRESS <FUNCTION>:" and its instructions
# follow, one per line, as "OFFSET:<tab>MNEMONIC<tab>OPERANDS".
set(definitions 0)
set(instructions "")
foreach(line IN LISTS lines)
  if(line MATCHES "^[0-9a-f]+ <(.*)>:$")
    if(CMAKE_MATCH_1 STREQUAL FUNCTION)
      math(EXPR definitions "${definitions} + 1")
    endif()
  elseif(line MATCHES "^ *[0-9a-f]+:[ \t]+(.+)$")
    list(APPEND instructions "${CMAKE_MATCH_1}")
  endif()
endforeach()
if(NOT definitions EQUAL 1)
  message(FATAL_ERROR "${ARCHIVE} has ${definitions} definitions of ${FUNCTION}, not 1")
endif()

set(forbidden "")
set(required 0)
foreach(instruction IN LISTS instructions)
  if(instruction MATCHES "${FORBID}")
    list(APPEND forbidden "${instruction}")
  endif()
  if(instruction MATCHES "${REQUIRE}")
    math(EXPR required "${required} + 1")
  endif()
endforeach()
if(forbidden)
  list(JOIN forbidden "\n  " forbidden)
  message(FATAL_ERROR "${FUNCTION} has forbidden instructions:\n  ${forbidden}")
endif()
if(required EQUAL 0)
  message(FATAL_ERROR "${FUNCTION} has no instruction that matches ${REQUIRE}")
endif()
