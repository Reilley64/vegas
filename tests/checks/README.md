# Checks

Each `.cmake` file in this folder registers the tests of one check or one
ticket. The end of `tests/CMakeLists.txt` includes every `*.cmake` file here
in name order, so a new check is a new file here and `tests/CMakeLists.txt`
stays as it is: never append a block to it.

## Writing a check file

- Name it `<area>_<what>.cmake`, with the area its test names start with:
  `objects_setting_value.cmake` registers `objects.setting_value*`.
- Start it with a comment that says what the check fails on, and its blind
  spots.
- Keep it self-contained. Tests that read the game archive or its objects
  sit inside their own `if(vegas_object_checks) ... endif()`. Tests that run
  on every host sit outside it.
- Prefix every variable with the file's name: all check files share one
  scope.
- A test that needs Python 3 is still registered when Python 3 is missing,
  and then fails with that reason, as `setup.recipe_ranges` in
  `tests/CMakeLists.txt` does.
- The next build picks a new file up: the folder is globbed with
  `CONFIGURE_DEPENDS`.

## What a file can use

The file runs in the scope of `tests/CMakeLists.txt`, after all of it.
`CMAKE_CURRENT_SOURCE_DIR` is `tests/`; `CMAKE_CURRENT_LIST_DIR` is this
folder.

| Name | What it is |
| --- | --- |
| `vegas_object_checks` | TRUE in a windows-x64 build that found Go, llvm-objdump and Python 3. On a Windows host without the tools, `objects.tools` fails in place of the guarded tests. |
| `GO_EXECUTABLE` | Go; set inside `vegas_object_checks` |
| `LLVM_OBJDUMP_EXECUTABLE` | the llvm-objdump beside clang-cl; set inside `vegas_object_checks` |
| `${CMAKE_CURRENT_BINARY_DIR}/game-objects.txt` | the game archive's objects, one path per line; written inside `vegas_object_checks` |
| `$<TARGET_FILE:game>` | the game archive |
| `Python3_Interpreter_FOUND`, `Python3_EXECUTABLE` | Python 3, on every host |
