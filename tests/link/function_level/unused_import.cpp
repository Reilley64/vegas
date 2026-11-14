// The second unit of the link.function_level.live_import program
// (VEGAS-126): it refers plainly to the name that main calls through its
// import slot, from a function nothing calls.
extern "C" int link_function_level_missing_import();

int LinkFunctionLevelUnusedImport() {
  return link_function_level_missing_import();
}
