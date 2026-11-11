#ifndef FNV_BS_STRING_H
#define FNV_BS_STRING_H

// BSStringT: the engine's string holder. It owns one character buffer, taken
// with new[] and released with delete[], and keeps the length and the
// capacity in 16 bits each, so neither exceeds 65535.
//
// This is the one shared declaration of the template. It declares the three
// fields, the seven members that build/units.json gives to
// src/bscore/bsstring.cpp, and the destructor. The header has no body: each
// member is defined and emitted for char by the unit that holds its function
// row. docs/shared-string.md has the rule for moving a unit onto this header
// and the members that are not declared yet.
template <class T> class BSStringT
{
  public:
    T* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    // Owned by src/bscore/bsstring.cpp.
    BSStringT();                                            // 0x004037b0
    bool Set(const T* text, unsigned int minimumCapacity);  // 0x004037f0
    void Init();                                            // 0x00403970
    unsigned int MaxLength();                               // 0x004039a0
    void SetLength(unsigned int length);                    // 0x004039c0
    void SetMaxLength(unsigned int length);                 // 0x00403a00
    BSStringT<T>& operator=(const T* text);                 // 0x00438390
    // The function row is in src/fallout_shared/tesobjectacti.cpp.
    ~BSStringT();                                           // 0x004037d0
};

#endif
