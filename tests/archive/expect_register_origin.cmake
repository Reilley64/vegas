# Fails unless the one definition of FUNCTION in ARCHIVE has exactly COUNT
# sites and, at each, the traced register was set by an instruction that
# matches ORIGIN.
# A site is an instruction that matches the regular expression SITE and, when
# FOLLOWED_BY is given, is followed by an instruction that matches FOLLOWED_BY
# within the next four. The traced register is SITE's first capture group,
# such as the base register of a load, or REGISTER when SITE captures none,
# such as the argument register of a call. It is traced back to where it was
# set: the nearest instruction before the site, in address order, that writes
# it. A copy "movq %REG, %TRACED" or a scaled address
# "leaq (%REG,%INDEX,8), %TRACED" is followed to REG in the same way. The
# instruction the trace ends at must match ORIGIN, in which the text BASE
# stands for the register it writes. A load "movq D(%ADDRESS), %TRACED" whose
# ADDRESS was last set by "leaq E(%REG), %ADDRESS" is matched as
# "movq D+E(%REG), %TRACED", the sum in hexadecimal. A trace that reaches no write, such as a
# register that holds an argument from the function's entry, fails.
# Registers are written without "%" in REGISTER and SITE's capture group.
# OBJDUMP is llvm-objdump. The disassembly of FUNCTION, without raw bytes, is
# written to WORK, read back line by line and removed. Before matching, a
# trailing comment "# ..." is removed from each instruction and runs of
# blanks are replaced by one space. It also fails when
# no member or more than one member defines FUNCTION.
foreach(variable OBJDUMP ARCHIVE WORK FUNCTION SITE ORIGIN COUNT)
  if(NOT DEFINED ${variable} OR "${${variable}}" STREQUAL "")
    message(FATAL_ERROR "OBJDUMP, ARCHIVE, WORK, FUNCTION, SITE, ORIGIN and COUNT are required")
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
    string(REGEX REPLACE "[ \t]+#.*$" "" instruction "${CMAKE_MATCH_1}")
    string(REGEX REPLACE "[ \t]+" " " instruction "${instruction}")
    list(APPEND instructions "${instruction}")
  endif()
endforeach()
if(NOT definitions EQUAL 1)
  message(FATAL_ERROR "${ARCHIVE} has ${definitions} definitions of ${FUNCTION}, not 1")
endif()
list(LENGTH instructions total)

# The 64-bit register that an operand such as %edi, %r14d or %rdi writes.
function(full_register operand out)
  set(register "")
  if(operand MATCHES "^%(r[0-9]+)[dwb]?$")
    set(register "${CMAKE_MATCH_1}")
  elseif(operand MATCHES "^%e([a-z][a-z])$")
    set(register "r${CMAKE_MATCH_1}")
  elseif(operand MATCHES "^%(r[a-z][a-z])$")
    set(register "${CMAKE_MATCH_1}")
  endif()
  set(${out} "${register}" PARENT_SCOPE)
endfunction()

# The index of the nearest instruction before BEFORE that writes REGISTER, or
# -1. An instruction writes the register that is its last operand, unless it
# only reads its operands.
function(last_write register before out)
  set(found -1)
  set(index ${before})
  while(index GREATER 0)
    math(EXPR index "${index} - 1")
    list(GET instructions ${index} instruction)
    if(instruction MATCHES "^(cmp|test|push|j|call|bt|nop)")
      continue()
    endif()
    if(instruction MATCHES "(%[a-z0-9]+)$")
      full_register("${CMAKE_MATCH_1}" written)
      if(written STREQUAL register)
        set(found ${index})
        break()
      endif()
    endif()
  endwhile()
  set(${out} ${found} PARENT_SCOPE)
endfunction()

set(sites 0)
set(failures "")
set(index 0)
while(index LESS total)
  list(GET instructions ${index} instruction)
  if(instruction MATCHES "${SITE}")
    if(CMAKE_MATCH_COUNT GREATER 0)
      set(register "${CMAKE_MATCH_1}")
    else()
      set(register "${REGISTER}")
    endif()
    set(counted TRUE)
    if(DEFINED FOLLOWED_BY AND NOT FOLLOWED_BY STREQUAL "")
      set(counted FALSE)
      set(next ${index})
      foreach(step RANGE 1 4)
        math(EXPR next "${next} + 1")
        if(next LESS total)
          list(GET instructions ${next} following)
          if(following MATCHES "${FOLLOWED_BY}")
            set(counted TRUE)
          endif()
        endif()
      endforeach()
    endif()
    if(counted)
      math(EXPR sites "${sites} + 1")
      set(at ${index})
      set(trace "")
      while(TRUE)
        last_write("${register}" ${at} at)
        if(at LESS 0)
          list(APPEND failures "at \"${instruction}\" (instruction ${index}), %${register} is written by nothing before it: ${trace}")
          break()
        endif()
        list(GET instructions ${at} source)
        string(APPEND trace "${source}; ")
        if(source MATCHES "^movq %(r[a-z0-9]+), %${register}$")
          set(register "${CMAKE_MATCH_1}")
        elseif(source MATCHES "^leaq \\(%(r[a-z0-9]+),%r[a-z0-9]+,8\\), %${register}$")
          set(register "${CMAKE_MATCH_1}")
        else()
          # A load through an address that "leaq DISPLACEMENT(%REG), %ADDRESS"
          # set is matched as the load from REG at the sum of both
          # displacements.
          if(source MATCHES "^movq (0x[0-9a-f]+)?\\(%(r[a-z0-9]+)\\), %${register}$")
            set(displacement "${CMAKE_MATCH_1}")
            set(address "${CMAKE_MATCH_2}")
            if(displacement STREQUAL "")
              set(displacement 0)
            endif()
            last_write("${address}" ${at} computed)
            if(computed GREATER_EQUAL 0)
              list(GET instructions ${computed} computation)
              if(computation MATCHES "^leaq (0x[0-9a-f]+)?\\(%(r[a-z0-9]+)\\), %${address}$")
                set(offset "${CMAKE_MATCH_1}")
                set(object "${CMAKE_MATCH_2}")
                if(offset STREQUAL "")
                  set(offset 0)
                endif()
                math(EXPR offset "${offset} + ${displacement}" OUTPUT_FORMAT HEXADECIMAL)
                string(APPEND trace "${computation}; ")
                set(source "movq ${offset}(%${object}), %${register}")
              endif()
            endif()
          endif()
          string(REPLACE "BASE" "%${register}" expected "${ORIGIN}")
          if(NOT source MATCHES "${expected}")
            list(APPEND failures "at \"${instruction}\" (instruction ${index}), the register comes from: ${trace}")
          endif()
          break()
        endif()
      endwhile()
    endif()
  endif()
  math(EXPR index "${index} + 1")
endwhile()

if(NOT sites EQUAL COUNT)
  list(APPEND failures "${sites} sites, not ${COUNT}")
endif()
if(failures)
  list(JOIN failures "\n  " failures)
  message(FATAL_ERROR "${FUNCTION}:\n  ${failures}")
endif()
