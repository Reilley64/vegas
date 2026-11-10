# Native ownership composition of committed legacy source only. This does not
# run the historical extractor, open an executable, or edit generated inputs.
function(vegas_compose_native_data)
  find_package(Git REQUIRED)
  set(root "${CMAKE_CURRENT_BINARY_DIR}/native-data")
  set(patch "${PROJECT_SOURCE_DIR}/src/runtime/native_data_retirements.patch")
  set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${patch}")
  set(inputs
    "src/generated/data/gamebryo2.2/corelibs/nianimation/nicontrollersequence.inc|b849ba5e6b9e86d467615f32cca7ad0ca16be0a80b4c47ae90b384c06d16a764"
    "src/generated/data/havok/common/base/types/hkrefvariant.inc|c6342266ee408e91dd568d634bf49904be2f142c125cde3c678f7cb980aaf360"
    "src/generated/data/havok/common/serialize/util/hkbuiltintyperegistry.inc|1c381558aecf21d0578815ee1c066aa02d6d3cb5dd88ffc5e4177995bfcd7046"
    "src/generated/data/havok/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent.inc|22ea9effdb8c905fe4307e7f9bbca640eb206818e18f43e7223d1d532ace6fec"
    "src/generated/data/havok/physics/collide/shape/convex/cylinder/hkpcylindershape.inc|d0bcb0c29b0aeeaec411667941fc05d68b7200b23bdbfa27e2f37f866efbaf96"
    "src/generated/data/havok/physics/constraintsolver/constraint/contact/hkpsimplecontactconstraintinfo.inc|c87111103ca96eb8ef50ef1f0d2e1c8fb0470268540e0394d8c887befe490f14"
    "src/generated/data/staging/blk_00860000_od.inc|1e69de320c7d2c8f5cbec52f130538f03143175e6b70e64977b6287c29ae7a0c"
    "src/generated/data/staging/blk_00d20000_o2.inc|033324c25a8c1860b6fd5e440d9dc9194cb9e2dc7800abf89cca364dfb601425"
    "src/generated/data/staging/blk_00d40000_o2.inc|5f78a93054fd4128e84d47f94d424db208bae43dd720677d129117d6f5f5474c"
    "src/generated/data/staging/blk_00d60000_o2.inc|a32d81f583e186a35485315433504afa49f4876f58ae39d88fd8c05922905b73"
    "src/generated/data/vtables.h|3751c0b212ad29b7380d86b632c14d5d36868e76c78c5eaed11b035f95288c48"
    "src/generated/data/vtables_010a.cpp|7feb5a02504d953dafcc059fcf0790c9d9b2ccb30d83b7c081fe67331cdd7229"
    "src/generated/data/vtables_010c.cpp|21ed6daad46431d6fc44cb269fef81b5219097f6712fdbbc6dbd454205ac4c27"
    "src/generated/data/vtables_010d.cpp|792afac5e0052599724a354577c9ad090c727e4f82889313b551ef48dfd86f32"
    "src/generated/data/vtables_010e.cpp|84bf82374edbd3d9a9007ad2b02f033b2905ea2d5b3f474e9748d0158d24ef46"
  )
  foreach(input IN LISTS inputs)
    string(REPLACE "|" ";" fields "${input}")
    list(GET fields 0 path)
    list(GET fields 1 expected)
    file(SHA256 "${PROJECT_SOURCE_DIR}/${path}" actual)
    if(NOT actual STREQUAL expected)
      message(FATAL_ERROR "Native data composition input changed: ${path}; audit the ownership retirement before rebuilding")
    endif()
    get_filename_component(directory "${root}/${path}" DIRECTORY)
    file(MAKE_DIRECTORY "${directory}")
    configure_file("${PROJECT_SOURCE_DIR}/${path}" "${root}/${path}" COPYONLY)
  endforeach()
  execute_process(
    COMMAND "${GIT_EXECUTABLE}" apply --no-index --unidiff-zero --check --whitespace=error-all "${patch}"
    WORKING_DIRECTORY "${root}" RESULT_VARIABLE checked ERROR_VARIABLE diagnostic)
  if(NOT checked EQUAL 0)
    message(FATAL_ERROR "Native data retirement does not apply: ${diagnostic}")
  endif()
  execute_process(
    COMMAND "${GIT_EXECUTABLE}" apply --no-index --unidiff-zero --whitespace=error-all "${patch}"
    WORKING_DIRECTORY "${root}" RESULT_VARIABLE applied ERROR_VARIABLE diagnostic)
  if(NOT applied EQUAL 0)
    message(FATAL_ERROR "Native data retirement failed: ${diagnostic}")
  endif()

  # Each full data TU is replaced in place in the target source list, never
  # omitted. Its other definitions and all unrelated generated units remain.
  get_target_property(sources game SOURCES)
  foreach(name IN ITEMS vtables_010a.cpp vtables_010c.cpp vtables_010d.cpp vtables_010e.cpp)
    set(original "src/generated/data/${name}")
    list(FIND sources "${original}" position)
    if(position LESS 0)
      message(FATAL_ERROR "Missing complete native data TU: ${original}")
    endif()
    list(REMOVE_AT sources ${position})
    list(INSERT sources ${position} "${root}/${original}")
  endforeach()
  set_property(TARGET game PROPERTY SOURCES "${sources}")
  target_include_directories(game BEFORE PRIVATE "${root}/src")
endfunction()
vegas_compose_native_data()
