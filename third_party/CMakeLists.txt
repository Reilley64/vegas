include(ExternalProject)
include(FetchContent)

# Checked first, so a missing SDK stops the configure before anything is downloaded.
include(steamworks_sdk.cmake)

FetchContent_Declare(SDL3
  URL https://github.com/libsdl-org/SDL/releases/download/release-3.4.18/SDL3-3.4.18.tar.gz
  URL_HASH SHA256=9c75cf16330322c217dedd2e0609f1124f1b54b8633e763467b4684d0f4334a3
)
FetchContent_Declare(Ogg
  URL https://downloads.xiph.org/releases/ogg/libogg-1.3.6.tar.xz
  URL_HASH SHA256=5c8253428e181840cd20d41f3ca16557a9cc04bad4a3d04cce84808677fa1061
  OVERRIDE_FIND_PACKAGE
)
FetchContent_Declare(Vorbis
  URL https://downloads.xiph.org/releases/vorbis/libvorbis-1.3.7.tar.xz
  URL_HASH SHA256=b33cc4934322bcbf6efcbacf49e3ca01aadbea4114ec9589d1b1e9d20f72954b
)
FetchContent_Declare(zlib
  URL https://github.com/madler/zlib/releases/download/v1.3.2/zlib-1.3.2.tar.xz
  URL_HASH SHA256=d7a0654783a4da529d1bb793b7ad9c3318020af77667bcae35f95d0e42a792f3
)

set(SDL_STATIC OFF)
set(SDL_TEST_LIBRARY OFF)
set(ZLIB_BUILD_SHARED OFF)
set(ZLIB_BUILD_TESTING OFF)
set(ZLIB_INSTALL OFF)
# libvorbis 1.3.7 asks for CMake 2.8.12, which CMake 4 no longer accepts.
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
FetchContent_MakeAvailable(SDL3 Ogg Vorbis zlib)
unset(CMAKE_POLICY_VERSION_MINIMUM)

# SHA-256 from Mbed TLS 3.6 LTS, for setup to identify the original release
# (VEGAS-13). Only the two files below are built: SOURCE_SUBDIR names a folder
# without a CMakeLists.txt, so Mbed TLS's own build is never added.
FetchContent_Declare(mbedtls
  URL https://github.com/Mbed-TLS/mbedtls/releases/download/mbedtls-3.6.7/mbedtls-3.6.7.tar.bz2
  URL_HASH SHA256=a7e8bcbec0e6f761b4af24f25677626b35f762f68eef79c08677a363212d11f6
  SOURCE_SUBDIR no-cmake-build
)
FetchContent_MakeAvailable(mbedtls)
add_library(mbedtls_sha256 STATIC
  ${mbedtls_SOURCE_DIR}/library/sha256.c
  ${mbedtls_SOURCE_DIR}/library/platform_util.c
)
target_include_directories(mbedtls_sha256
  PUBLIC ${mbedtls_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/mbedtls
  PRIVATE ${mbedtls_SOURCE_DIR}/library
)
target_compile_definitions(mbedtls_sha256 PUBLIC "MBEDTLS_CONFIG_FILE=\"vegas_sha256_config.h\"")

# FFmpeg builds only with its own configure script and make, so on Windows it runs
# under MSYS2's bash. Only the parts the game plays are enabled, and FFmpeg is
# linked as DLLs.
set(MSYS2_ROOT "C:/msys64" CACHE PATH "MSYS2 folder whose bash and make build FFmpeg on Windows")
set(ffmpeg_options
  --toolchain=msvc
  --cc=clang-cl
  --cxx=clang-cl
  --ld=lld-link
  --ar=llvm-lib
  --nm=llvm-nm
  --extra-cflags=-MD
  --enable-shared
  --disable-static
  --disable-autodetect
  --disable-everything
  --disable-programs
  --disable-doc
  --disable-network
  --disable-x86asm
  --disable-avdevice
  --disable-avfilter
  --disable-swresample
  --disable-swscale
  --enable-demuxer=bink
  --enable-decoder=bink,binkaudio_rdft,binkaudio_dct,mp3
)
if(CMAKE_CROSSCOMPILING)
  list(APPEND ffmpeg_options --enable-cross-compile --target-os=win64 --arch=x86_64)
endif()

set(ffmpeg_prefix "${CMAKE_CURRENT_BINARY_DIR}/ffmpeg")
cmake_host_system_information(RESULT jobs QUERY NUMBER_OF_LOGICAL_CORES)
if(CMAKE_HOST_WIN32)
  find_program(MSYS2_BASH bash PATHS "${MSYS2_ROOT}/usr/bin" NO_DEFAULT_PATH REQUIRED)
  find_program(MSYS2_MAKE make PATHS "${MSYS2_ROOT}/usr/bin" NO_DEFAULT_PATH REQUIRED)
  execute_process(
    COMMAND "${MSYS2_ROOT}/usr/bin/cygpath" -u "${ffmpeg_prefix}"
    OUTPUT_VARIABLE ffmpeg_install_dir
    OUTPUT_STRIP_TRAILING_WHITESPACE
    COMMAND_ERROR_IS_FATAL ANY
  )
  # A login shell puts MSYS2's tools first on PATH, keeps the Windows PATH that
  # holds clang-cl and stays in the step's working folder.
  set(msys ${CMAKE_COMMAND} -E env MSYS2_PATH_TYPE=inherit CHERE_INVOKING=1 MSYSTEM=MSYS "${MSYS2_BASH}" -l)
  set(ffmpeg_configure ${msys} ./configure)
  set(ffmpeg_build ${msys} -c "exec make -j${jobs}")
  set(ffmpeg_install ${msys} -c "exec make install")
else()
  set(ffmpeg_install_dir "${ffmpeg_prefix}")
  set(ffmpeg_configure ./configure)
  set(ffmpeg_build make -j${jobs})
  set(ffmpeg_install make install)
endif()

ExternalProject_Add(ffmpeg
  URL https://ffmpeg.org/releases/ffmpeg-9.0.2.tar.xz
  URL_HASH SHA256=8c3850283eb25fa026482078a04051e0be17347b09ef81a0849bec15a96e002e
  PREFIX "${ffmpeg_prefix}"
  INSTALL_DIR "${ffmpeg_prefix}"
  BUILD_IN_SOURCE TRUE
  CONFIGURE_COMMAND ${ffmpeg_configure} --prefix=${ffmpeg_install_dir} ${ffmpeg_options}
  BUILD_COMMAND ${ffmpeg_build}
  INSTALL_COMMAND ${ffmpeg_install}
)
