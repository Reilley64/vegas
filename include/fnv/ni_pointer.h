#ifndef FNV_NI_POINTER_H
#define FNV_NI_POINTER_H

// NiPointer: the Gamebryo smart pointer. It holds one pointer to a
// reference-counted object.
//
// This is the shared declaration of the template. It declares only the
// members that the unit holding their function row in build/units.json
// defines. The header has no body: that unit defines a member and emits it,
// once per element type. Members whose owner does not define them under the
// template's name are not declared here.
// docs/shared-ni-pointer.md has the rule for moving a unit onto this header.
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    // 0x0066b0d0, src/gamebryo2.2/corelibs/nimain/nishader.cpp.
    NiPointer<T>& operator=(T* object);
};

#endif
