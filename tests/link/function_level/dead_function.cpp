// The positive control of the link.function_level tests (VEGAS-126). main
// calls only LinkFunctionLevelUsed of the library member parts.cpp, so the
// link loads that member and discards its function that calls a name nothing
// defines: the check must accept the link. The program is linked, never run.
int LinkFunctionLevelUsed();

int main() {
  return LinkFunctionLevelUsed();
}
