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

The build never downloads the Steamworks SDK and the SDK is never committed, because its licence does not allow the
headers to be published. The files in `redistributable_bin` may ship with a program. A configuration that targets
Windows, which is the `windows-x64` preset on Windows or as a cross build, needs the SDK in a folder on the machine.
`third_party/steamworks_sdk.cmake` stops that configure with an error when no folder is named or the folder lacks one
of these files:

- `public/steam/steam_api.h`
- `redistributable_bin/win64/steam_api64.lib`
- `redistributable_bin/win64/steam_api64.dll`

VEGAS-29 asks that configuration fails without the SDK. That is read as every configuration that targets Windows.
Builds for macOS and Linux do not use the SDK and configure without it.

To build for Windows, get the SDK from the Steamworks partner site, unpack it, and set the `STEAMWORKS_SDK` environment
variable to the absolute path of the folder that holds `public` and `redistributable_bin`. Export it once, in the
shell's profile, because the build runs the check again whenever it regenerates. A relative path is looked up from the
folder `cmake` runs in, so it stops working when the build regenerates from the build folder.

The `STEAMWORKS_SDK` CMake variable, as in `-DSTEAMWORKS_SDK=<folder>`, names the folder instead, and is used when both
are set. CMake keeps a `-D` value in the build folder's cache, so a value given once is used by every later configure
of that build folder, even when the environment variable is set to another folder afterwards. The error says whether
the folder came from the CMake variable or the environment variable.

`Build: windows-x64` checks the SDK out of the private `steamworks-sdk` repository of this repository's owner into
`steamworks-sdk`, with the read-only deploy key in the secret the workflow names. In that repository `public` and
`redistributable_bin` are under `sdk`, so the workflow passes `-DSTEAMWORKS_SDK` with the `sdk` folder of the checkout.
`.gitignore` lists `steamworks-sdk`, so a tree laid out like CI's cannot add the SDK. Pull requests from forks, mirrors
and Dependabot receive no secret, and for them the job stops at `Policy: Require the Steamworks SDK deploy key` instead
of building without the SDK. Dependabot's pull requests build only if a Dependabot secret of the same name exists.

The original release linked zlib 1.2.1 with changes to `inflate.c`: the game supplied each stream's inflate state, and
`inflate` did not check the Adler-32 trailer. The game now gets the same results through zlib's own API, in
`src/fileformat/compression.cpp`. It calls `inflateValidate(stream, 0)` so a wrong trailer still decompresses. The
compressed-record reader keeps one stream per thread and calls `inflateReset` before each record, and each compressed
BSA file keeps its own stream.
