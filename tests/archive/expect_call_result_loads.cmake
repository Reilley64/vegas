# Fails unless the one definition of FUNCTION in ARCHIVE reads the result of
# its one call of CALLEE into registers before the next call, which must be a
# call of NEXT.
# CALLEE returns a record by value: the caller passes the record's address in
# SLOT_REGISTER, set by "leaq DISPLACEMENT(BASE), SLOT_REGISTER" before the
# call. LOADS is a comma-separated list of OFFSET:REGISTER pairs, OFFSET in
# decimal: each REGISTER must be loaded from DISPLACEMENT + OFFSET(BASE)
# between the call of CALLEE and the call of NEXT. Calls are matched by the
# relocation that follows the call instruction.
# OBJDUMP is llvm-objdump. The disassembly of FUNCTION, with relocations and
# without raw bytes, is written to WORK, read back line by line and removed.
# It also fails when no member or more than one member defines FUNCTION.
foreach(variable OBJDUMP ARCHIVE WORK FUNCTION CALLEE NEXT SLOT_REGISTER LOADS)
  if(NOT DEFINED ${variable} OR "${${variable}}" STREQUAL "")
    message(FATAL_ERROR
      "OBJDUMP, ARCHIVE, WORK, FUNCTION, CALLEE, NEXT, SLOT_REGISTER and LOADS are required")
  endif()
endforeach()

execute_process(
  COMMAND "${OBJDUMP}" -dr --no-show-raw-insn "--disassemble-symbols=${FUNCTION}" "${ARCHIVE}"
  OUTPUT_FILE "${WORK}"
  ERROR_VARIABLE error
  RESULT_VARIABLE result
)
if(NOT result EQUAL 0)
  file(REMOVE "${WORK}")
  message(FATAL_ERROR "${OBJDUMP} -dr failed (${result}): ${error}")
endif()
file(STRINGS "${WORK}" lines)
file(REMOVE "${WORK}")

# A definition starts with a line "ADDRESS <FUNCTION>:". Instructions follow as
# "OFFSET:<tab>MNEMONIC<tab>OPERANDS", and a relocation as a line
# "OFFSET:  TYPE<tab>SYMBOL" after the instruction it belongs to.
# state: "" before the call of CALLEE, "call" right after its call instruction,
# "after" once its relocation is seen, "next" right after the following call
# instruction, "done" when that call's relocation is seen.
set(definitions 0)
set(calls 0)
set(state "")
set(slot "")
set(between "")
set(next_symbol "")
set(pending "")
foreach(line IN LISTS lines)
  if(line MATCHES "^[0-9a-f]+ <(.*)>:$")
    if(CMAKE_MATCH_1 STREQUAL FUNCTION)
      math(EXPR definitions "${definitions} + 1")
    endif()
  elseif(line MATCHES "^[ \t]+[0-9a-f]+:[ \t]+IMAGE_REL_[A-Z0-9_]+[ \t]+(.+)$")
    set(symbol "${CMAKE_MATCH_1}")
    if(pending STREQUAL "call" AND symbol STREQUAL CALLEE)
      math(EXPR calls "${calls} + 1")
      if(state STREQUAL "")
        set(state "after")
        set(result_slot "${slot}")
      endif()
    elseif(pending STREQUAL "call" AND state STREQUAL "next")
      set(next_symbol "${symbol}")
      set(state "done")
    endif()
    set(pending "")
  elseif(line MATCHES "^ *[0-9a-f]+:[ \t]+([a-z0-9]+)[ \t]*(.*)$")
    set(mnemonic "${CMAKE_MATCH_1}")
    set(operands "${CMAKE_MATCH_2}")
    set(pending "")
    if(mnemonic MATCHES "^call")
      set(pending "call")
      if(state STREQUAL "after")
        set(state "next")
      endif()
    elseif(state STREQUAL "after")
      list(APPEND between "${mnemonic} ${operands}")
    endif()
    if(state STREQUAL "" AND operands MATCHES ", %${SLOT_REGISTER}$")
      if(mnemonic STREQUAL "leaq"
         AND operands MATCHES "^(-?)0x([0-9a-f]+)\\((%[a-z0-9]+)\\), %${SLOT_REGISTER}$")
        set(slot_sign "${CMAKE_MATCH_1}")
        set(slot_hex "${CMAKE_MATCH_2}")
        set(slot_base "${CMAKE_MATCH_3}")
        set(slot "${slot_sign}0x${slot_hex}(${slot_base})")
      else()
        set(slot "")
      endif()
    endif()
  endif()
endforeach()
if(NOT definitions EQUAL 1)
  message(FATAL_ERROR "${ARCHIVE} has ${definitions} definitions of ${FUNCTION}, not 1")
endif()
if(NOT calls EQUAL 1)
  message(FATAL_ERROR "${FUNCTION} has ${calls} calls of ${CALLEE}, not 1")
endif()
if(result_slot STREQUAL "")
  message(FATAL_ERROR
    "${FUNCTION} does not set ${SLOT_REGISTER} with leaq before its call of ${CALLEE}")
endif()
if(NOT state STREQUAL "done" OR NOT next_symbol STREQUAL NEXT)
  message(FATAL_ERROR
    "${FUNCTION}: the call after ${CALLEE} is '${next_symbol}', not ${NEXT}")
endif()

math(EXPR displacement "${slot_sign}0x${slot_hex}")
string(REPLACE "," ";" loads "${LOADS}")
set(missing "")
foreach(load IN LISTS loads)
  if(NOT load MATCHES "^([0-9]+):(.+)$")
    message(FATAL_ERROR "LOADS entry '${load}' is not OFFSET:REGISTER")
  endif()
  set(register "${CMAKE_MATCH_2}")
  math(EXPR address "${displacement} + ${CMAKE_MATCH_1}")
  if(address LESS 0)
    math(EXPR magnitude "0 - ${address}" OUTPUT_FORMAT HEXADECIMAL)
    set(operand "-${magnitude}(${slot_base}), %${register}")
  else()
    math(EXPR magnitude "${address}" OUTPUT_FORMAT HEXADECIMAL)
    set(operand "${magnitude}(${slot_base}), %${register}")
  endif()
  set(found FALSE)
  foreach(instruction IN LISTS between)
    if(instruction MATCHES "^[a-z0-9]+ (.*)$" AND CMAKE_MATCH_1 STREQUAL operand)
      set(found TRUE)
    endif()
  endforeach()
  if(NOT found)
    list(APPEND missing "${operand}")
  endif()
endforeach()
if(missing)
  list(JOIN missing "\n  " missing)
  list(JOIN between "\n  " between)
  message(FATAL_ERROR
    "${FUNCTION} passes ${result_slot} as the result of ${CALLEE} and does not load:\n"
    "  ${missing}\n"
    "before the call of ${NEXT}. Instructions between the two calls:\n  ${between}")
endif()
