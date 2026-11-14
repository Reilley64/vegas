// The library member of the link.function_level positive control
// (VEGAS-126): dead_function.cpp calls LinkFunctionLevelUsed, and nothing
// calls LinkFunctionLevelUnused, the one function that refers to a name that
// nothing defines.
void link_function_level_missing_from_dead_code();

int LinkFunctionLevelUsed() {
  return 0;
}

void LinkFunctionLevelUnused() {
  link_function_level_missing_from_dead_code();
}
