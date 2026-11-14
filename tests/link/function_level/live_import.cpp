// A program of the link.function_level negative tests (VEGAS-126). main
// calls a function that nothing defines through its import slot
// (dllimport), and unused_import.cpp refers to the same name plainly from a
// function nothing calls. When lld-link replaces the plain name by zero
// before it reaches the slot's name, it makes the slot an import slot of its
// own that holds zero; otherwise it replaces the slot's name by zero too.
// Either way main's call is live and the check must refuse the link. The
// program is linked, never run.
extern "C" __declspec(dllimport) int link_function_level_missing_import();

int main() {
  return link_function_level_missing_import();
}
