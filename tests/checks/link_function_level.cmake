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
endif()
