# Runs SCRIPT, the folder check of falloutnv.process_exit
# (falloutnv_pack_folder.cmake), on stand-ins for FalloutNV.exe and the pack
# fixture, in WORK, and fails unless the check fails exactly the runs that
# leave something behind. Each stand-in program is a POSIX shell script: it
# exits 0 beside a pack and 2, with the missing pack reported, without one,
# as main does, and then leaves what its case names. The stand-in fixture
# reports Continue for both checks and writes a one-line pack.
#
# Cases, each in both modes of SCRIPT: nothing left, which must pass; an
# empty folder beside the executable, an empty folder in the working
# directory, an empty folder inside a new folder, and a file, each of which
# must fail on the folder check's message.
if(NOT DEFINED SCRIPT OR NOT DEFINED WORK)
  message(FATAL_ERROR "SCRIPT and WORK are required")
endif()
file(REMOVE_RECURSE "${WORK}")
file(MAKE_DIRECTORY "${WORK}")

set(fixture "${WORK}/fixture")
file(WRITE "${fixture}" [=[#!/bin/sh
if [ "$1" = --check ]; then
  echo "single-instance check: Continue"
  echo "second-window check: Continue"
  exit 0
fi
echo pack > "$1"
]=])
file(CHMOD "${fixture}" PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE)

set(cases nothing beside working nested file)
set(leave_nothing ":")
set(leave_beside [=[mkdir "$(dirname "$0")/My Games"]=])
set(leave_working [=[mkdir "My Games"]=])
set(leave_nested [=[mkdir -p "$(dirname "$0")/My Games/FalloutNV"]=])
set(leave_file [=[echo log > "$(dirname "$0")/log.txt"]=])

set(failures)
foreach(case IN LISTS cases)
  file(MAKE_DIRECTORY "${WORK}/${case}")
  set(program "${WORK}/${case}/FalloutNV")
  file(WRITE "${program}" "#!/bin/sh\n${leave_${case}}\n"
    [=[if [ -f "$(dirname "$0")/vegas-data.pack" ]; then exit 0; fi
echo "vegas-data.pack is missing beside the executable" >&2
exit 2
]=])
  file(CHMOD "${program}" PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE)
  foreach(mode IN ITEMS with-pack without-pack)
    execute_process(
      COMMAND "${CMAKE_COMMAND}" -DPROGRAM=${program} -DFIXTURE=${fixture}
        -DFOLDER=${WORK}/${case}/run-${mode} -DMODE=${mode} -DTIMEOUT=60 -P "${SCRIPT}"
      RESULT_VARIABLE result OUTPUT_VARIABLE output ERROR_VARIABLE error)
    string(FIND "${error}" "After the run the folder holds" reported)
    if(case STREQUAL "nothing")
      if(NOT result EQUAL 0)
        list(APPEND failures "${case}, ${mode}: the check failed a run that left nothing: ${output}${error}")
      endif()
    elseif(result EQUAL 0 OR reported EQUAL -1)
      list(APPEND failures "${case}, ${mode}: the check did not fail on what the run left: '${result}': ${output}${error}")
    endif()
  endforeach()
endforeach()
file(REMOVE_RECURSE "${WORK}")
if(failures)
  list(JOIN failures "\n" failures)
  message(FATAL_ERROR "${failures}")
endif()
