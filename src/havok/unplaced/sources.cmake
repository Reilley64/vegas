# Havok units with no source path yet (VEGAS-14).
set(VEGAS_HAVOK_UNPLACED_SOURCES
  src/havok/unplaced/cellmopp.cpp
  src/havok/unplaced/crtgpr.cpp
  src/havok/unplaced/focollisionlistener.cpp
  src/havok/unplaced/havokstream.cpp
  src/havok/unplaced/hkaprocessflyingcolors.cpp
  src/havok/unplaced/hkmap.cpp
  src/havok/unplaced/hkpsolvercheck.cpp
  src/havok/unplaced/hkstringmap.cpp
  src/havok/unplaced/loadedareabound.cpp
  src/havok/unplaced/pathingrequestcover.cpp
  src/havok/unplaced/sockapi.cpp
  src/havok/unplaced/specificitemcollector.cpp
  src/havok/unplaced/viewcaster.cpp
)
target_sources(game PRIVATE ${VEGAS_HAVOK_UNPLACED_SOURCES})
# The units include project headers from include/. A pointer must never be narrowed to a 32-bit integer.
set_source_files_properties(${VEGAS_HAVOK_UNPLACED_SOURCES} PROPERTIES
  INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/include"
  COMPILE_DEFINITIONS "WIN32_LEAN_AND_MEAN;NOMINMAX"
  COMPILE_OPTIONS "-Werror=pointer-to-int-cast;-Werror=void-pointer-to-int-cast;-Werror=int-to-pointer-cast;-Werror=int-to-void-pointer-cast"
)
