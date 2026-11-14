// A program of the link.function_level negative tests (VEGAS-126). main
// constructs a class whose second virtual function nothing defines, so the
// class's virtual table is kept and its slot refers to that name: the check
// must refuse the link. The program is linked, never run.
struct LinkFunctionLevelShape {
  virtual int Sides();
  virtual int MissingCorners();
};

int LinkFunctionLevelShape::Sides() {
  return 3;
}

LinkFunctionLevelShape* volatile link_function_level_shape;

int main() {
  link_function_level_shape = new LinkFunctionLevelShape;
  return link_function_level_shape->Sides();
}
