# link.function_level fails unless every name that the function-level link
# of FalloutNV.exe leaves unresolved is referenced only from sections that
# lld-link discarded (tools/function-level-link/check.py, VEGAS-126). It also
# fails when the check cannot classify a reference or a line of the map, when
# the map is missing or belongs to another link, when FalloutNV is not
# linked by lld-link with the rule, and when the map names a member of a
# library that the check neither reads nor lists as a system library. It
# reads the executable, its map and the objects and static libraries the
# build made for it. Blind spots: the objects of the listed system libraries
# (the C runtime, the Windows import libraries) are not read, so a reference
# from one of them to a name that nothing defines is caught only when no
# object read refers to that name; a name that only a linker option names is
# not checked; and a reference that lld-link resolved is not checked at all.
if(vegas_object_checks)
  # Registers test NAME on TARGET: the objects of TARGET and every static
  # library it links, followed through the libraries' own link interfaces.
  function(link_function_level_test name target)
    get_target_property(map ${target} VEGAS_LINK_MAP)
    if(NOT map)
      string(CONCAT message "${target} is not linked by lld-link with the function-level link, "
        "so ${name} cannot check it (CMakeLists.txt, vegas_function_level_link).")
      add_test(NAME ${name} COMMAND ${CMAKE_COMMAND} -E echo "${message}")
      set_tests_properties(${name} PROPERTIES FAIL_REGULAR_EXPRESSION "is not linked by lld-link")
      return()
    endif()
    set(archives "")
    set(seen "")
    get_target_property(pending ${target} LINK_LIBRARIES)
    while(pending)
      list(POP_FRONT pending item)
      string(REGEX REPLACE "^\\$<LINK_ONLY:(.*)>$" "\\1" item "${item}")
      if(item MATCHES "\\$<")
        message(FATAL_ERROR "${name}: cannot read the link library ${item} of ${target}")
      endif()
      if(NOT TARGET ${item})
        continue()  # a library of the system, such as user32
      endif()
      get_target_property(aliased ${item} ALIASED_TARGET)
      if(aliased)
        set(item ${aliased})
      endif()
      if(item IN_LIST seen)
        continue()
      endif()
      list(APPEND seen ${item})
      get_target_property(type ${item} TYPE)
      if(type STREQUAL "STATIC_LIBRARY")
        list(APPEND archives "$<TARGET_FILE:${item}>")
      endif()
      get_target_property(more ${item} INTERFACE_LINK_LIBRARIES)
      if(more)
        list(APPEND pending ${more})
      endif()
    endwhile()
    set(inputs "${CMAKE_CURRENT_BINARY_DIR}/link-function-level/${target}.inputs")
    file(GENERATE OUTPUT "${inputs}"
      CONTENT "$<JOIN:$<TARGET_OBJECTS:${target}>,\n>\n$<JOIN:${archives},\n>\n")
    add_test(NAME ${name}
      COMMAND ${Python3_EXECUTABLE} -B "${PROJECT_SOURCE_DIR}/tools/function-level-link/check.py"
              --exe $<TARGET_FILE:${target}> --map ${map} --inputs ${inputs})
  endfunction()

  link_function_level_test(link.function_level FalloutNV)

  # The negative tests: small programs linked with the same rule, each with
  # one live reference to a name that nothing defines, from code, from
  # initialized data, from a virtual table slot of a class that main
  # constructs, and from a call through an import slot (live_import, whose
  # second unit refers to the name plainly from dead code, so lld-link may
  # make the slot one of its own that holds zero, depending on the order of
  # its symbol table). Each test passes only when the check refuses its
  # program with that reference as LIVE and prints no UNCLASSIFIED or REFUSED
  # line. The positive control refers to a name that nothing defines only
  # from a function nothing calls, in a member of a static library that the
  # link loads; it passes only when the check accepts it with that one name.
  # The programs are linked, never run.
  add_library(link_function_level_parts STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/link/function_level/parts.cpp)
  set(link_function_level_cases live_code live_data live_vtable live_import dead_function)
  foreach(link_function_level_case IN LISTS link_function_level_cases)
    add_executable(link_function_level_${link_function_level_case}
      ${CMAKE_CURRENT_SOURCE_DIR}/link/function_level/${link_function_level_case}.cpp)
    vegas_function_level_link(link_function_level_${link_function_level_case})
  endforeach()
  target_sources(link_function_level_live_import PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/link/function_level/unused_import.cpp)
  target_link_libraries(link_function_level_dead_function PRIVATE link_function_level_parts)
  set(link_function_level_live_code "\\?link_function_level_missing_function@@YAXXZ")
  set(link_function_level_live_data "\\?link_function_level_missing_object@@3HA")
  set(link_function_level_live_vtable "\\?MissingCorners@LinkFunctionLevelShape@@UEAAHXZ")
  set(link_function_level_live_import "__imp_link_function_level_missing_import")
  foreach(link_function_level_case IN LISTS link_function_level_cases)
    link_function_level_test(link.function_level.${link_function_level_case}
      link_function_level_${link_function_level_case})
    if(link_function_level_case STREQUAL "dead_function")
      set_tests_properties(link.function_level.dead_function PROPERTIES PASS_REGULAR_EXPRESSION
        "accepted: 1 unresolved names, 1 references, all from discarded sections")
    else()
      set_tests_properties(link.function_level.${link_function_level_case} PROPERTIES
        PASS_REGULAR_EXPRESSION "LIVE ${link_function_level_${link_function_level_case}} from kept "
        FAIL_REGULAR_EXPRESSION "UNCLASSIFIED|REFUSED|unreadable|accepted|is not linked by lld-link")
    endif()
  endforeach()
endif()
