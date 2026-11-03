# Third-party code

## zlib 1.2.1

`zlib-1.2.1/` is the zlib 1.2.1 core from the official archive (https://zlib.net/fossils/zlib-1.2.1.tar.gz), which the
game links. Its licence is the zlib licence, in `zlib-1.2.1/README` and `zlib-1.2.1/zlib.h`.

One file is altered: `zlib-1.2.1/inflate.c` carries the game's own changes to `inflateInit2_`, `inflate` and
`inflateEnd`. They are part of how the game reads compressed data, so the copy keeps them. A note at the top of the
file says so. The changes are also given as a diff against the official file, `patches/zlib-1.2.1-fnv-inflate.patch`
(`patch -R` on `inflate.c` gives the official file back). Every other file is unaltered.

`zlib-1.2.1/UPSTREAM.json` records the archive's SHA-256, the SHA-256 of every file kept, and for `inflate.c` both the
official and the altered file's SHA-256 and the patch's. Platform ports, contributed code and prebuilt objects from the
archive were left out.

## Fetched by the build

The build downloads these libraries. `third_party/CMakeLists.txt` pins each one to a version and the SHA-256 of its
release archive, and the download fails if the archive doesn't match.

- SDL3, from the libsdl-org/SDL GitHub releases. Its licence is the zlib licence.
- FFmpeg, from ffmpeg.org. The build enables only the Bink demuxer and the bink, binkaudio_rdft, binkaudio_dct and mp3
  decoders, and builds FFmpeg as DLLs. These parts are LGPL-2.1 or later. On Windows, FFmpeg's configure script and
  make run under MSYS2, from a Visual Studio developer prompt because the DLL step calls `lib.exe` and `dumpbin.exe`.
  The `MSYS2_ROOT` cache variable names the MSYS2 folder and defaults to `C:/msys64`. That MSYS2 needs the `make` and
  `diffutils` packages.
- libogg and libvorbis, from downloads.xiph.org. Their licence is the BSD-style Xiph licence.
