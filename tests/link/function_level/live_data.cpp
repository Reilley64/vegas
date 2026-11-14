// A program of the link.function_level negative tests (VEGAS-126). An
// initialized variable holds the address of a variable that nothing defines.
// The variable is in a data section that is not a COMDAT, which the link
// never discards, so the check must refuse the link. The program is linked,
// never run.
extern int link_function_level_missing_object;
int* volatile link_function_level_pointer = &link_function_level_missing_object;

int main() {
  return link_function_level_pointer != nullptr ? 0 : 1;
}
