# Native replacements for D3DX (VEGAS-24)

The original release imports its matrix, vector, plane, texture and shader
helpers from `d3dx9_38.dll` through 25 six-byte forwarders at `0x00ee6dc2` to
`0x00ee6e52`. This page records which of them are project code, the
conventions that code follows, and what still reaches D3DX.

Nothing here was checked against D3DX itself. The public D3DX 9 reference
describes what each function computes; it does not give the arithmetic, and no
D3DX library is part of the build. See "Not verified" below.

## Conventions

They are the ones the public D3DX 9 reference states for its math functions.

- A matrix is 16 floats in row-major order: element `m[row][column]`, also
  named `_11` to `_44`, at index `row * 4 + column`.
- Vectors are row vectors and stand on the left: `result = vector * matrix`.
  A product `first * second` therefore applies `first` before `second`.
- Translation is in the fourth row, `_41`, `_42`, `_43`.
- The coordinate system is left-handed and angles are in radians. The
  direction of a positive angle is the one the matrix below gives: a quarter
  turn of positive yaw takes +z to +x, positive pitch takes +y to +z, and
  positive roll takes +x to +y.
- A plane is the four coefficients of `a*x + b*y + c*z + d = 0`.

## Math functions

All eleven live in `src/unmapped/d3dxmath.cpp`, and `build/units.json` lists
each function row in that unit. Each reads its inputs completely before it
writes its output, so a call may name the same object as input and output.

The import-slot column is the recipe row that records where the original
forwarder at that address bound its D3DX import. The row is kept as that
record; it travels with the forwarder's function row, so nine of them are in
the d3dxmath unit's symbols. The other two stay in the staging unit
`src/staging/blk_00ee0000_o2.cpp` with the second definitions described under
"What still reaches D3DX".

| Address | D3DX function it replaces | Import slot | Result |
| --- | --- | --- | --- |
| `0x00ee6dc8` | `D3DXPlaneTransform` (inferred) | `__imp__D3DXPlaneTransform@12` = `0x00fdf418` | `(a, b, c, d) * matrix`, no normalization and no divide |
| `0x00ee6dce` | `D3DXPlaneNormalize` (inferred) | `__imp__D3DXPlaneNormalize@8` = `0x00fdf430` | all four coefficients divided by the length of `(a, b, c)` |
| `0x00ee6dd4` | `D3DXMatrixTranspose` | `__imp__D3DXMatrixTranspose@0` = `0x00fdf42c` | rows and columns exchanged |
| `0x00ee6dda` | `D3DXMatrixInverse` | `___imp__D3DXMatrixInverse` = `0x00fdf428` (staging unit) | the inverse, the determinant on request, null for a singular matrix |
| `0x00ee6de0` | `D3DXMatrixMultiply` | `__imp__D3DXMatrixMultiply@12` = `0x00fdf424` | `first * second` |
| `0x00ee6dec` | `D3DXVec3Normalize` | `__imp__D3DXVec3Normalize@8` = `0x00fdf41c` | the vector divided by its length |
| `0x00ee6df2` | `D3DXVec3TransformNormal` | `?g_D3DXVec3TransformNormal@@3P6AXXZA` = `0x00fdf420` (staging unit) | `(x, y, z, 0) * matrix`, first three components |
| `0x00ee6df8` | `D3DXVec3TransformCoord` | `__imp__D3DXVec3TransformCoord@12` = `0x00fdf414` | `(x, y, z, 1) * matrix`, divided by the fourth component |
| `0x00ee6dfe` | `D3DXMatrixMultiplyTranspose` | `__imp__D3DXMatrixMultiplyTranspose@12` = `0x00fdf410` | the transpose of `first * second` |
| `0x00ee6e04` | `D3DXMatrixRotationYawPitchRoll` | `__imp__D3DXMatrixRotationYawPitchRoll@16` = `0x00fdf40c` | roll about z, then pitch about x, then yaw about y |
| `0x00ee6e34` | `D3DXVec4Transform` | `__imp__D3DXVec4Transform@12` = `0x00fdf3ec` | `vector * matrix` |

The two plane functions are identified by inference, not by measurement. In
the original they are forwarders whose recovered bodies called themselves.
The grounds, all from this repository:

- the staging unit's recipe rows bind the two D3DX plane imports in the table,
  and the two self-calling functions take two and three arguments;
- before commit `3f0599801` ("refer to each recipe address by one name") the
  recovered water unit called `0x00ee6dce` as `D3DXPlaneNormalize` and
  `0x00ee6dc8` as `D3DXPlaneTransform`, with recipe keys
  `_D3DXPlaneNormalize@8` and `_D3DXPlaneTransform@12`;
- all three callers normalize a plane in place through `0x00ee6dce` and then
  pass it with a matrix to `0x00ee6dc8`.

The yaw, pitch and roll matrix, with `s` and `c` the sine and cosine of each
angle, is

```
cr*cy + sr*sp*sy    sr*cp    sr*sp*cy - cr*sy    0
cr*sp*sy - sr*cy    cr*cp    sr*sy + cr*sp*cy    0
cp*sy               -sp      cp*cy               0
0                   0        0                   1
```

Its angles are `float`. Before `3f0599801` the one caller, `FUN_00bb2fc0` in
`src/staging/blk_00ba0000_o2.cpp`, declared the function with three `float`
angles and its recipe key spelled three floats; the forwarder declared three
`unsigned int`. `3f0599801` unified the address to the forwarder's
declaration, which converted the caller's angles to integers. The native
function takes `float` again, and the recipe keys spell three floats.

Decisions the public reference does not settle, kept as project choices
until D3DX results can be measured:

- `D3DXVec3Normalize` of a zero-length vector gives the zero vector, and
  `D3DXPlaneNormalize` of a plane with a zero-length normal gives the zero
  plane. Neither divides by zero.
- The two normalizations, the plane transform and the rotation compute in
  double precision and round to single precision once. Inputs whose squares
  overflow or underflow single precision, such as `2^127` and `2^-140`,
  normalize here, where a single-precision evaluation would not. A result
  too large for single precision is an infinity of its sign.
- The rotation test compares angle-dependent elements within `1e-6`. The
  tolerance is the test's choice and says nothing about distance from D3DX
  results.

The tests mark each of these cases as a project choice.

`D3DXPlaneTransform` expects the inverse transpose of the transformation that
moves the points, and a plane whose normal is normalized. The function does
not check either.

## What still reaches D3DX

Measured on the source and the windows-x64 link, not on a running game. In
the forced link of every archive member with no error limit, the names in
the undefined list that contain `D3DX` fall from 18 to 16 with this
increment: the imports of `D3DXVec3Normalize` and
`D3DXMatrixRotationYawPitchRoll` are no longer referenced.

- 56 call lines in 9 files call the matrix inverse (`0x00ee6dda`, 23 lines),
  the matrix transpose (`0x00ee6dd4`, 30 lines) or the vector normal
  transform (`0x00ee6df2`, 3 lines) without arguments. Two of the eleven
  project-code addresses, `0x00ee6dda` and `0x00ee6df2`, therefore still have
  a second definition, without parameters, in the staging unit; it calls
  through an import pointer. `0x00ee6dd4` has a declaration without
  parameters and no such definition.
- These lines did not lose their arguments when the callers were recovered.
  The repository's own history has them: before `3f0599801` the files called
  the three addresses with arguments, under local declarations of their own
  types (for example `FUN_00ee6dda(ptr, 0, ptr);` and
  `FUN_00ee6dd4(ptr, ptr);` in `nid3dshaderconstantmap.cpp`), or under local
  names such as `D3DXMatrixInverse`, `Invert` and `Transpose`. That commit
  gave each address one declaration and dropped the arguments. Every one of
  the 56 lines was added by it, directly or in a variant unit later merged
  into the file, in place of a call with arguments. `3f0599801`'s parent is
  the admissible source for restoring them, which is a follow-up. Each local
  declaration there is a stand-in type to review before its call is
  restored; one of them, in `nid3dhlslpixelshader.cpp`, declares
  `void FUN_00ee6dd4(void*, int)`, which is not the transpose's shape.
- `3f0599801` did not always replace a call one for one. In
  `src/staging/blk_00ba0000_o2.cpp` it replaced
  `D3DXVec3TransformCoord(&tmp, &dir, matrix);` with the argument-less
  `::FUN_00ee6df2();`, the vector normal transform by its import slot, and
  the `D3DXVec3TransformNormal` call that followed with `0x00ee6df8`, the
  coordinate transform. It followed that unit's symbols keys at its parent,
  which bound the coordinate transform name to `0x00ee6df2` and the normal
  transform name to `0x00ee6df8`. That line no longer exists.
- Next step: restore the 56 argument-less calls from the parent of
  `3f0599801` under VEGAS-90's restoration rule: an argument is restored where
  the callee's definition takes that many parameters of compatible types,
  and each local stand-in type is reviewed first. Once no caller uses them,
  the second definitions at `0x00ee6dda` and `0x00ee6df2` can be retired.
- Textures and surfaces: `0x00ee6dc2` (save texture to file), `0x00ee6de6`
  (surface copy), `0x00ee6e10`, `0x00ee6e16` and `0x00ee6e1c` (volume, cube
  and 2D texture from a file in memory) and `0x00ee6e22` (image information)
  still call their imports.
- Shaders: `0x00ee6e0a`, `0x00ee6e46`, `0x00ee6e4c` and `0x00ee6e52` (compile
  and assemble), `0x00ee6e28` and `0x00ee6e2e` (shader profile names),
  `0x00ee6e3a` (buffer) and `0x00ee6e40` (constant table).

The compile and assemble path is not removed. Two shader loaders in
`src/bsshader/bsshader.cpp`, the vertex shader loader `0x00be0fe0` and the
pixel shader loader `0x00be1750`, each have three branches:

1. A packaged shader: when the shader package has an entry for the shader's
   cache name, its bytes are used.
2. A compile from source: taken only when no packaged shader was found, a
   global flag is set and no cache file exists on disk. The loader compiles
   the source file through `0x00ee6e0a` and, on success, writes the result to
   a cache file. If the compile fails it returns its failure value. The
   compile branch also holds a fallback that reads the cache file after a
   failed compile. It can never run: the branch is entered only when no
   cache file exists, and the fallback returns the failure value when none
   exists.
3. A loose cache file: otherwise, the loader reads the cache file from disk,
   and returns its failure value when the file is missing.

32 functions that create the game's shaders call one or both loaders. The
Gamebryo program creators that compile or assemble are entries of virtual
tables in `src/generated`.

## DDS header reader

`fileformat::ReadDdsImageInfo` in `src/fileformat/dds_header.cpp` reads what
`D3DXGetImageInfoFromFileInMemory` reports for a DDS file: width, height,
depth, mip levels, the Direct3D 9 format and the resource kind. No game code
calls it yet.

Its rules come from three public pages of the Direct3D documentation,
"Programming Guide for DDS", "DDS_HEADER structure" and "DDS_PIXELFORMAT
structure":

- A file is refused unless it has 128 bytes, the magic number `DDS `, a header
  size of 124 and a pixel format size of 32.
- The format is the row of the guide's table "Common DDS File Resource Formats
  and Associated Header Content" that matches the pixel format, limited to
  rows that name a Direct3D 9 format. The rows `D3DFMT_A2B10G10R10` and
  `D3DFMT_A2R10G10B10` are refused: the guide marks them as written
  inconsistently by common tools. The `DX10` extension header is refused.
- Masks are compared with the table in three ways. For an RGB format the
  alpha mask is compared only when the alpha-pixels flag is set, and is
  ignored otherwise. For an alpha-only format only the alpha mask is
  compared. For a luminance format all four masks are compared as stored, and
  the alpha-pixels flag is not looked at; the table's luminance rows have zero
  green and blue masks, so a luminance file must store them as zero.
- The file is a cube map or a volume when the second capabilities say so, and
  a texture otherwise. Depth is the header's depth for a volume and 1
  otherwise.
- The mip level count is the header's count when the header flags say it is
  present and it is not zero, and 1 otherwise.

The reader also refuses a zero width or height, a volume with zero depth, and
a header that claims to be both a cube map and a volume.

Width, height, depth and the mip level count are reported as stored, with no
upper bound and no check against each other or against the length of the
file. The cube map face flags, the pitch or linear size, the first capability
word and every header flag but the mip count flag are not read. A consumer
must bound the values before it sizes or indexes anything with them. The
header comment in `src/fileformat/dds_header.h` lists what is validated and
what is trusted.

Decisions the reference does not settle, to be settled before a caller is
bound:

- The mip level rule reads the count only when the mip count flag is set.
  The public header page advises readers not to rely on that flag, because
  some writers leave it clear; a file with a count and no flag reads as one
  level here.

Not covered: the pixel data, the BMP and TGA files the texture loader also
accepts, and DDS pixel formats outside the guide's table. The texture loader
tests for eight bump-map formats (`D3DFORMAT` values 60 to 64, 67, 110 and
117); the guide's table has header content for 110 and 117 only.

The reader is a member of the game archive although no game code calls it:
the Windows test links the one game library.

## Owner decisions

As the reviewers ruled for this increment:

- The zero-length results are kept as project choices until D3DX results can
  be measured.
- The import-slot rows are kept, with the function rows they belong to.
- The reader stays in the game archive while unbound.
- The bump formats 60 to 64 and 67 are refused until a permitted source for
  their header content is named.
- Shader loaders: when no packaged shader is passed, the compile branch is to
  become the function's existing failure return, so that nothing is compiled
  while playing.

Open for the owner:

- Whether the loose cache-file branch of the shader loaders counts as shader
  packages, and who regenerates the generated virtual tables that hold the
  compiling and assembling program creators.
- Image information for BMP and TGA files.

## Not verified

- That any function returns the same bits as the D3DX function it replaces.
  The tests check hand-derived values and identities.
- The project choices above, and which DDS headers D3DX accepts or refuses.
- Behaviour in the running game. The acceptance check "during the playable
  run" needs a game that starts.
