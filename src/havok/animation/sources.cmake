# Havok animation units (VEGAS-14).
set(VEGAS_HAVOK_ANIMATION_SOURCES
  src/havok/animation/animation/animation/deltacompressed/hkadeltacompressedanimation.cpp
  src/havok/animation/animation/animation/deltacompressed/hkadeltacompressedanimationclass.cpp
  src/havok/animation/animation/animation/hkaanimation.cpp
  src/havok/animation/animation/animation/hkaanimationbindingclass.cpp
  src/havok/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation.cpp
  src/havok/animation/animation/animation/interleaved/hkainterleaveduncompressedanimationclass.cpp
  src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimation.cpp
  src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimationclass.cpp
  src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimationctor.cpp
  src/havok/animation/animation/animation/util/hkaanimationpreviewcolorclass.cpp
  src/havok/animation/animation/animation/util/hkatrackanalysis.cpp
  src/havok/animation/animation/animation/waveletcompressed/hkawaveletcompressedanimation.cpp
  src/havok/animation/animation/animation/waveletcompressed/hkawaveletcompressedanimationclass.cpp
  src/havok/animation/animation/deform/skinning/hkameshbinding.cpp
  src/havok/animation/animation/hkaanimationcontainerclass.cpp
  src/havok/animation/animation/ik/footplacement/hkafootplacementiksolver.cpp
  src/havok/animation/animation/ik/lookat/hkalookatiksolver.cpp
  src/havok/animation/animation/mapper/hkaskeletonmapper.cpp
  src/havok/animation/animation/mapper/hkaskeletonmapperutils.cpp
  src/havok/animation/animation/motion/default/hkadefaultanimatedreferenceframe.cpp
  src/havok/animation/animation/motion/default/hkadefaultanimatedreferenceframeclass.cpp
  src/havok/animation/animation/motionanalysis/hkafootstepanalysisinfo.cpp
  src/havok/animation/animation/motionanalysis/hkafootstepanalysisinfoclass.cpp
  src/havok/animation/animation/rig/hkaboneattachmentclass.cpp
  src/havok/animation/animation/rig/hkapose.cpp
  src/havok/animation/animation/rig/hkaskeletonutils.cpp
  src/havok/animation/ragdoll/instance/hkaragdollinstance.cpp
  src/havok/animation/ragdoll/penetration/hkadetectragdollpenetration.cpp
  src/havok/animation/ragdoll/utils/hkaragdollutils.cpp
)
target_sources(game PRIVATE ${VEGAS_HAVOK_ANIMATION_SOURCES})
# The units include project headers from include/. A pointer must never be narrowed to a 32-bit integer.
set_source_files_properties(${VEGAS_HAVOK_ANIMATION_SOURCES} PROPERTIES
  INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/include"
  COMPILE_DEFINITIONS "WIN32_LEAN_AND_MEAN;NOMINMAX"
  COMPILE_OPTIONS "-Werror=pointer-to-int-cast;-Werror=void-pointer-to-int-cast;-Werror=int-to-pointer-cast;-Werror=int-to-void-pointer-cast"
)
