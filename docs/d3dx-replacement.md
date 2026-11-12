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

- 4 call lines in 3 files call the matrix inverse (`0x00ee6dda`, 1 line),
  the matrix transpose (`0x00ee6dd4`, 2 lines) or the vector normal
  transform (`0x00ee6df2`, 1 line) without arguments. Two of the eleven
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
  gave each address one declaration and dropped the arguments, in 56 lines
  of 9 files, directly or in a variant unit later merged into the file.
- 52 of the 56 lines have their arguments back. 34 of them under
  VEGAS-90's restoration rule, in `xgamesetting.cpp`, `teswater.cpp`,
  `nid3dshaderconstantmap.cpp`, `nid3dhlslpixelshader.cpp`,
  `nid3dhlslvertexshader.cpp`, `lighting30shader.cpp` and
  `shadowlightshader.cpp`. Each argument list is the text of `3f0599801`'s
  parent. Each call now binds the native definition, which takes the
  arguments without a cast, and the argument values, their types and the
  local types they point to are the parent's: 16 floats for a matrix and 3
  for a point, from offset 0, except `0x00bbc050`, whose matrix type is only
  declared in its unit (unmeasured; the 64-byte obligation is its callers').
- The other 18 are the calls of `0x00e85d10` in `nid3dshaderconstantmap.cpp`,
  under the rule's translation tier. Each of its nine cases stores a matrix
  in register slot `slot` of the constant table at `0x0126f820`, then
  inverts and transposes that slot in place, as the mapping asks. The parent
  passed `&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot]`. The tip no
  longer declares `DAT_0126f820`, and the restored arguments name the same
  object as the store before each call does:
  `(*reinterpret_cast<::Matrix *>(&::g_afSCMatrixConstants))`. The parent's
  recipe binds `DAT_0126f820`, and the tip's `g_afSCMatrixConstants`, to
  `0x0126f820` in that unit. Each argument is a `MapMatrix*` of 64 bytes to
  the same slot, as in the parent.
- The tests `runtime.d3dx_call_arguments_*` check the native callees'
  contract with the restored argument patterns, not the repaired sites: they
  run each function's sequence of calls on objects of the same shape. The
  functions themselves do not link into a test and are not run. Each test
  also checks that skipping the calls fails, which is not what the
  argument-less calls did: `?FUN_00ee6dd4@@YAXXZ` has no definition at all,
  and the other two argument-less names call through an import pointer with
  whatever the registers hold.
- The sites are checked in the objects. In the windows-x64 cross build,
  `objects.d3dx_call_arguments_fallout_shared`, `_shader_constants` and
  `_lighting` (`tools/function-relocations`) fail when the code section of
  one of the 12 functions whose calls changed refers to an argument-less
  name of the three addresses, or no longer to the native function it calls.
  They check each function's own section: the object of
  `nid3dhlslpixelshader.cpp` keeps an argument-less call in `0x00e96da0`,
  listed below.
- Rulings that this restoration follows (VEGAS-90):
  - Each batch respells the recipe keys of its units in the same commit:
    the native name is bound where it is called, and an argument-less key
    leaves a unit whose object no longer requires it.
  - The function rows at `0x00ee6dda` and `0x00ee6df2` keep naming the
    argument-less definitions until the 4 lines below are decided.
  - "Same conversions" means the same argument expression, value and type
    up to the final implicit conversion into the native parameter, which
    must keep the address: a conversion to a base at offset 0, or a null
    constant.
  - `0x00bbc050` is restored with the size of its matrix type unmeasured.
  - A call whose parent callee returned `void` now binds a native function
    that returns `void*`; the result is discarded.
  - Translation tier: where the parent's argument names a global that the
    tip no longer declares, the restored argument may use the spelling of
    the same object that the same unit already uses. The recipe must bind
    both names to the same address, the final type and address passed
    must be the parent's, and the spelling must exist verbatim in the
    unit. The tier does not admit a unit that declares the object with
    another layout, such as `0x00e82e70` below, or an integer passed where
    a pointer is expected.
- The other 4 lines are not restored, because the parent's call does not
  fit the tip:
  - `0x00e82e70` in `src/staging/blk_00e80000_o2.cpp`, 2 lines: the parent
    declared `DAT_0126f8c0` as a 64-byte matrix of its own. In that unit at
    the tip it is a `Matrix` of 36 bytes, less than the 64 bytes the native
    inverse and transpose read and write.
  - `0x00e96da0` in `nid3dhlslpixelshader.cpp`, 1 line: the parent declared
    `void FUN_00ee6dd4(void*, int)` and passed an `int`, which is not the
    transpose's shape.
  - `0x00b7c7b0` in `nid3dpass.cpp`, 1 line: the parent declared the normal
    transform with an `unsigned int` third parameter and passed an
    `unsigned int` where the native function takes the matrix.
- `3f0599801` did not always replace a call one for one. In
  `src/staging/blk_00ba0000_o2.cpp` it replaced
  `D3DXVec3TransformCoord(&tmp, &dir, matrix);` with the argument-less
  `::FUN_00ee6df2();`, the vector normal transform by its import slot, and
  the `D3DXVec3TransformNormal` call that followed with `0x00ee6df8`, the
  coordinate transform. It followed that unit's symbols keys at its parent,
  which bound the coordinate transform name to `0x00ee6df2` and the normal
  transform name to `0x00ee6df8`. That line no longer exists.
- The 2 lines of `0x00e82e70` refuse because two types named `::Matrix`
  meet at `DAT_0126f8c0`: 64 bytes in `nid3dshaderconstantmap.cpp`, and a
  36-byte `struct Matrix { Vec3 a,b,c; }` in `blk_00e80000_o2.cpp`.
  The translation tier does not restore them: the unit's own declaration
  of `0x0126f8c0` has to be decided first.
- Next step: decide the 4 lines above with evidence beyond the parent's
  text, such as which object `0x00e82e70` really passes. Once no caller
  uses them, the second definitions at `0x00ee6dda` and `0x00ee6df2` can
  be retired.
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

## Other calls that 3f0599801 left without arguments

`3f0599801` dropped arguments from calls of other addresses too. Nothing
in this section is repaired yet.

`nid3dhlslvertexshader.cpp` calls `::FUN_00a29680()` without arguments
twice. The parent passed `(str_010f14a0, m_pcName, pcVariable)` and
`(str_010f14e8, m_pcName, pcVariable)`, under its own declaration
`void __cdecl FUN_00a29680(const char*, ...)`. The restoration rule does
not admit them: the callee's declaration at the tip,
`void FUN_00a29680()`, and its one definition, an empty function in
`nitimecontroller.cpp`, take no parameter, and the parent's arguments do
not compile against it. That declaration's name `?FUN_00a29680@@YAXXZ`
is a key of 87 recipe units.

The coordinator ruled on these calls (VEGAS-90):

- `0x00a29680` stays tabled. The parent declared that address in several
  ways, likely identical functions that the linker folded into one. The
  shared declaration is not reshaped.
- The route is the addendum "providers for restored identities": the
  callers that pass variadic debug output get an identity of their own,
  bound to `0x00a29680` by `symbols` keys only. It is a batch of its own,
  of low priority, that first lists which of the 219 calls of `0x00a29680`
  below pass arguments with side effects.
- The 1,139 calls below whose parent argument is now the object of a member
  call get a mechanical comparison, the parent's argument against the tip's
  object, in a later census batch.

A census of the source, by compiler parse, counts the other calls. It
takes every call in a `src` unit of the windows-x64 build that writes no
argument, to a callee whose declaration has no parameter and whose name the
unit's recipe binds to an address. It pairs each with the parent of
`3f0599801` as the restoration pairs its calls: the function with the same
`// @fnv` address, or else the same qualified name, and the call of the
same address in the same position. An operand is a written argument or the
object of a member call. Measured after the `0x00e85d10` restoration:

| Class | Calls |
| --- | ---: |
| No argument in the parent either | 71,425 |
| The parent's one argument is now the object of a member call | 1,139 |
| The parent's call had more operands | 1,019 |
| The parent's call had fewer operands | 97 |
| Not paired: no single parent function | 1,383 |
| Not paired: the function calls the address a different number of times | 1,530 |
| Total | 76,593 |

The 1,019 calls whose parent call had more operands, by callee family, the
source folder of the unit that holds the callee's function row:

| Family | Calls | Member calls | Callee addresses | Calling units |
| --- | ---: | ---: | ---: | ---: |
| `gamebryo2.2` | 284 | 11 | 22 | 101 |
| `fallout_shared` | 227 | 168 | 62 | 84 |
| `fallout` | 148 | 65 | 42 | 49 |
| `havok` | 94 | 42 | 25 | 39 |
| `staging` | 78 | 17 | 43 | 49 |
| `bsshader` | 71 | 0 | 26 | 18 |
| `bsmenu` | 36 | 13 | 9 | 22 |
| `bssystem` | 32 | 32 | 1 | 14 |
| `bscore` | 22 | 17 | 4 | 18 |
| units directly in `src` | 12 | 12 | 1 | 5 |
| D3DX forwarders | 5 | 0 | 4 | 4 |
| `unmapped` | 5 | 1 | 2 | 2 |
| `region system` | 3 | 3 | 1 | 1 |
| `bsaudio` | 2 | 0 | 1 | 2 |
| Total | 1,019 | 381 | 243 | 290 distinct |

- The total of calling units counts each unit once. A unit that calls
  into several families is in the row of each, so the rows add up to more
  (408).
- 219 of the `gamebryo2.2` calls are calls of `0x00a29680`, the two above
  among them.
- `bscore` also has 2 constructions.
- The D3DX forwarders are the 4 lines above and `0x00ee6dc2`, save texture
  to file, in `0x0079ffb0` in `interface.cpp`, where the parent passed
  three arguments.
- The census counts. It does not prove that an argument was lost: the
  parent's call may have bound another function at the same address under
  another name. The receiver class is not checked against the parent's
  argument.
- It does not see calls in headers, calls through pointers, or calls the
  compiler could not resolve. The parent was parsed with the tip's compile
  commands, and 2,038 of its 3,257 units report errors.

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
