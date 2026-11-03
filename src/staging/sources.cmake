# Second half of the staging blocks (blk_00c40000 to blk_00f20000) that compile for x64 without narrowing a pointer (VEGAS-21).
set(VEGAS21_STAGING_SOURCES
  src/staging/blk_00c80000_od.cpp
  src/staging/blk_00ca0000_od.cpp
  src/staging/blk_00cc0000_od.cpp
  src/staging/blk_00ce0000_od.cpp
  src/staging/blk_00d00000_o2.cpp
  src/staging/blk_00d40000_od.cpp
  src/staging/blk_00d60000_od.cpp
  src/staging/blk_00da0000_o2.cpp
  src/staging/blk_00da0000_od.cpp
  src/staging/blk_00dc0000_o2.cpp
  src/staging/blk_00dc0000_o2_tokens.cpp
  src/staging/blk_00dc0000_o2_welding.cpp
  src/staging/blk_00dc0000_od.cpp
  src/staging/blk_00de0000_od.cpp
  src/staging/blk_00e20000_od.cpp
  src/staging/blk_00e40000_od.cpp
  src/staging/blk_00e60000_od.cpp
  src/staging/blk_00ea0000_od.cpp
  src/staging/blk_00ec0000_od.cpp
  src/staging/blk_00ee0000_o2.cpp
  src/staging/blk_00f00000_o2.cpp
  src/staging/blk_00f20000_o2.cpp
)
target_sources(game PRIVATE ${VEGAS21_STAGING_SOURCES})
# The units include project headers from include/. A pointer must never be narrowed to a 32-bit integer.
set_source_files_properties(${VEGAS21_STAGING_SOURCES} PROPERTIES
  INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/include"
  COMPILE_DEFINITIONS "WIN32_LEAN_AND_MEAN;NOMINMAX"
  COMPILE_OPTIONS "-Werror=pointer-to-int-cast;-Werror=void-pointer-to-int-cast;-Werror=int-to-pointer-cast;-Werror=int-to-void-pointer-cast"
)
