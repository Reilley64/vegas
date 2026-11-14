# Native ownership composition of committed legacy source only. This does not
# run the historical extractor, open an executable, or edit generated inputs.
function(vegas_compose_native_data)
  find_package(Git REQUIRED)
  set(root "${CMAKE_CURRENT_BINARY_DIR}/native-data")
  set(patch "${PROJECT_SOURCE_DIR}/src/runtime/native_data_retirements.patch")
  set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${patch}")
  set(inputs
    "src/generated/data/bsaudio/bsaudio.inc|870d9edb5b2de0545ce934fb3228bf47c6450254d5d134fa940c2864c9105b13"
    "src/generated/data/bshavok/bhkrigidbody_h_unit.inc|801786c7bf38eb1b7cf2745845efd568055bd5ddfe38105314e26ae6289a9ae7"
    "src/generated/data/fallout/misc/main.inc|b5d162d2a3e31b206c1f63c0c9a816be07f2e0d5d21cbc6ece067aecb1d5389a"
    "src/generated/data/fallout_shared/tesfile.inc|dfc4376955f40276d081d9cee18d5ffef1f1e3820e25bbe5562077deb8a47751"
    "src/generated/data/gamebryo2.2/corelibs/nianimation/nianimationkey.inc|0272c0c3e4e1c5f40a3e79247b0d01f4b220373c298f05f2cee15d72b1fd0f03"
    "src/generated/data/gamebryo2.2/corelibs/nianimation/nibooldata.inc|75c044905e583119c0a0d297cd2c2e684aef24610893d9990918ae0d7d2597b7"
    "src/generated/data/gamebryo2.2/corelibs/nianimation/niboolkey.inc|4725777323be3440d178eb1adc757a4b0db82df4723326efcbae409e129e6aa6"
    "src/generated/data/gamebryo2.2/corelibs/nianimation/nicolordata.inc|9d9c1c2bb5d39ee6b388b19b79168b360e1b7045d23fc7e1e375bd48954738e5"
    "src/generated/data/gamebryo2.2/corelibs/nianimation/nicolorkey.inc|1314dcb41204248208b92a5a78d302ef05d16b48f5cd961b69cb64a2661e5abc"
    "src/generated/data/gamebryo2.2/corelibs/nianimation/nicontrollermanager.inc|7c61a4c31b17440b11250d6f442757c0e0ae82ab215909b31c077b9bb6141459"
    "src/generated/data/gamebryo2.2/corelibs/nianimation/nicontrollersequence.inc|b849ba5e6b9e86d467615f32cca7ad0ca16be0a80b4c47ae90b384c06d16a764"
    "src/generated/data/gamebryo2.2/corelibs/nianimation/nieulerrotkey.inc|4e1c6a91a16a5ee75e704814176f5a939c5b36e7fccd57245031228feafce101"
    "src/generated/data/gamebryo2.2/corelibs/nianimation/nifloatdata.inc|049316462ac8fb1c09edc80b983a97e150465b4ba3e916d5313c72072efc60f5"
    "src/generated/data/gamebryo2.2/corelibs/nianimation/nifloatkey.inc|635334f2bac455606fcc55a3cbbdb954448f4f36f31c95d7a48f26b6386ffb1d"
    "src/generated/data/gamebryo2.2/corelibs/nianimation/nipathcontroller.inc|358e9056e7bafbd3c07f5d1f8dd20650b711cbdfaaebed128774fe50c6b97687"
    "src/generated/data/gamebryo2.2/corelibs/nianimation/niposdata.inc|9c9a3b37542681c845ed9d4cf1bc580a4ce00a46dd146136ef5d539a1234d236"
    "src/generated/data/gamebryo2.2/corelibs/nianimation/niposkey.inc|3cae6eb7373029f72d9e935d002227d2fd3157e97df6f3fb1b1e1d78339bce52"
    "src/generated/data/gamebryo2.2/corelibs/nianimation/nirotdata.inc|807868689ea8e3d67bc9d348e0fa11957b3cfccc7615bb2f74b09063f52cddbb"
    "src/generated/data/gamebryo2.2/corelibs/nianimation/nirotkey.inc|403b4a46916f0a2a54127f46d3c5281d4ffe92f6197a2b9e8ea5cc3d461e4330"
    "src/generated/data/gamebryo2.2/corelibs/niparticle/nipsysemitterctlrdata.inc|6e5fc2f42d47159d0998c6d5714cf8059d2fd56919e80b716fd863367d51610e"
    "src/generated/data/generated/crt_callback_status_o2_variant.inc|dfc6da4ac5bb67c0d4e12b8f7a2a9ac11f41f54e3fe0993c05caec4f98ce496c"
    "src/generated/data/havok/common/base/types/hkrefvariant.inc|c6342266ee408e91dd568d634bf49904be2f142c125cde3c678f7cb980aaf360"
    "src/generated/data/havok/common/serialize/util/hkbuiltintyperegistry.inc|1c381558aecf21d0578815ee1c066aa02d6d3cb5dd88ffc5e4177995bfcd7046"
    "src/generated/data/havok/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent.inc|22ea9effdb8c905fe4307e7f9bbca640eb206818e18f43e7223d1d532ace6fec"
    "src/generated/data/havok/physics/collide/shape/convex/cylinder/hkpcylindershape.inc|d0bcb0c29b0aeeaec411667941fc05d68b7200b23bdbfa27e2f37f866efbaf96"
    "src/generated/data/havok/physics/constraintsolver/constraint/contact/hkpsimplecontactconstraintinfo.inc|c87111103ca96eb8ef50ef1f0d2e1c8fb0470268540e0394d8c887befe490f14"
    "src/generated/data/staging/blk_00860000_od.inc|1e69de320c7d2c8f5cbec52f130538f03143175e6b70e64977b6287c29ae7a0c"
    "src/generated/data/staging/blk_00ba0000_o2.inc|a69af5aac183a6b64057e12976392d06ed63576363d8ce052fc9436090122a23"
    "src/generated/data/staging/blk_00c20000_od.inc|320b01dd37d1af5ae22bcd796f5dd5125623f70c512d8ac097a444f441e1559b"
    "src/generated/data/staging/blk_00c60000_o2.inc|3cbdd0e61b3d24af8e615f97b5f7670d8fe5a19b2a300f86f6e6b81f13a354a4"
    "src/generated/data/staging/blk_00c80000_o2.inc|d2bbac1ce858236bd13a771c2c03fe7cd30c7d826785cca20ae1ba6f7ceeb7c9"
    "src/generated/data/staging/blk_00ca0000_o2.inc|bb60388b9665aaf24bc3c5c25fd0a940147398f6e180afe0bab5970c9184805a"
    "src/generated/data/staging/blk_00d20000_o2.inc|033324c25a8c1860b6fd5e440d9dc9194cb9e2dc7800abf89cca364dfb601425"
    "src/generated/data/staging/blk_00d40000_o2.inc|5f78a93054fd4128e84d47f94d424db208bae43dd720677d129117d6f5f5474c"
    "src/generated/data/staging/blk_00d60000_o2.inc|a32d81f583e186a35485315433504afa49f4876f58ae39d88fd8c05922905b73"
    "src/generated/data/vtables.h|3751c0b212ad29b7380d86b632c14d5d36868e76c78c5eaed11b035f95288c48"
    "src/generated/data/vtables_010a.cpp|0eb7d4db3145867ae87400146b32154eadf02c1c3ba635befa3e3e58f5e9af93"
    "src/generated/data/vtables_010c.cpp|d40012aecb190d485d7feb085a9217e7c3c40ac530d5bc1bfa0f8a2e3ca4d3e3"
    "src/generated/data/vtables_010d.cpp|ed67c8bec41ed476610646445144816f71541b77d7c26c6fcf85a97380e1f469"
    "src/generated/data/vtables_010e.cpp|76c6ec007716bece303350f4d4f1a296ca216cb9aa1a0082dbf9024d835812d4"
  )
  # A pin holds only while every checkout keeps the committed bytes. Without
  # eol=lf or -text in .gitattributes a Windows checkout converts an input to
  # CRLF and its pin no longer matches; the patch needs the same attribute. git
  # check-attr needs a repository, so a source archive is not checked here;
  # there the hash check still covers the inputs and a converted patch does
  # not apply. The check reads this machine's effective attributes: a global
  # attributes file, .git/info/attributes or an uncommitted .gitattributes
  # line can make it pass locally, while CI's fresh checkout still stops. It
  # covers the end-of-line attributes only; ident and working-tree-encoding
  # are left to the hash check and git apply.
  set(paths)
  foreach(input IN LISTS inputs)
    string(REPLACE "|" ";" fields "${input}")
    list(GET fields 0 path)
    list(APPEND paths "${path}")
  endforeach()
  file(RELATIVE_PATH patch_path "${PROJECT_SOURCE_DIR}" "${patch}")
  list(APPEND paths "${patch_path}")
  # The prefix is empty only at the top of a work tree.
  execute_process(
    COMMAND "${GIT_EXECUTABLE}" rev-parse --show-prefix
    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" RESULT_VARIABLE rev_parse_result
    OUTPUT_VARIABLE prefix OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_VARIABLE rev_parse_error ERROR_STRIP_TRAILING_WHITESPACE)
  if(rev_parse_result EQUAL 0 AND prefix STREQUAL "")
    execute_process(
      COMMAND "${GIT_EXECUTABLE}" check-attr text eol -- ${paths}
      WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" RESULT_VARIABLE checked
      OUTPUT_VARIABLE attributes ERROR_VARIABLE diagnostic)
    if(NOT checked EQUAL 0)
      message(FATAL_ERROR "Cannot read the attributes of the native data composition inputs: ${diagnostic}")
    endif()
    string(REPLACE "\r" "" attributes "\n${attributes}")
    set(unprotected)
    foreach(path IN LISTS paths)
      string(FIND "${attributes}" "\n${path}: eol: lf\n" lf)
      string(FIND "${attributes}" "\n${path}: text: unset\n" binary)
      if(lf LESS 0 AND binary LESS 0)
        list(APPEND unprotected "${path}")
      endif()
    endforeach()
    if(unprotected)
      list(JOIN unprotected "\n  " unprotected)
      message(FATAL_ERROR "Native data composition inputs or patch without eol=lf or -text in .gitattributes, so a Windows checkout changes their committed bytes:\n  ${unprotected}")
    endif()
  else()
    set(skipped "Native data composition: the source root is not the top of a readable Git work tree; the inputs' line-ending attributes are not checked")
    if(NOT rev_parse_error STREQUAL "")
      string(APPEND skipped "\n${rev_parse_error}")
    endif()
    message(STATUS "${skipped}")
  endif()
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
