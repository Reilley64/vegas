// A program of the link.function_level negative tests (VEGAS-126). main
// calls a function that nothing defines, so the call is live and the check
// must refuse the link. The program is linked, never run.
void link_function_level_missing_function();

int main() {
  link_function_level_missing_function();
  return 0;
}
