# Third-party code

The build downloads these libraries. `third_party/CMakeLists.txt` pins each one to a version and the SHA-256 of its
release archive, and the download fails if the archive doesn't match.

- SDL3, from the libsdl-org/SDL GitHub releases. Its licence is the zlib licence.
- FFmpeg, from ffmpeg.org. The build enables only the Bink demuxer and the bink, binkaudio_rdft, binkaudio_dct and mp3
  decoders, and builds FFmpeg as DLLs. These parts are LGPL-2.1 or later. On Windows, FFmpeg's configure script and
  make run under MSYS2, from a Visual Studio developer prompt because the DLL step calls `lib.exe` and `dumpbin.exe`.
  The `MSYS2_ROOT` cache variable names the MSYS2 folder and defaults to `C:/msys64`. That MSYS2 needs the `make` and
  `diffutils` packages.
- libogg and libvorbis, from downloads.xiph.org. Their licence is the BSD-style Xiph licence.
- zlib 1.3.2, from the madler/zlib GitHub releases. The game links it statically. Its licence is the zlib licence.

The original release linked zlib 1.2.1 with changes to `inflate.c`: the game supplied each stream's inflate state, and
`inflate` did not check the Adler-32 trailer. The game now gets the same results through zlib's own API, in
`src/fileformat/compression.cpp`. It calls `inflateValidate(stream, 0)` so a wrong trailer still decompresses. The
compressed-record reader keeps one stream per thread and calls `inflateReset` before each record, and each compressed
BSA file keeps its own stream.
