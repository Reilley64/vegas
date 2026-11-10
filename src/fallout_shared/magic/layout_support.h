#ifndef FNV_LAYOUT_SUPPORT_H
#define FNV_LAYOUT_SUPPORT_H
#include <stddef.h>
class Actor;
class EffectSetting;
class TESForm;
class TESFile;
class TESFaction;
class TESObjectREFR;
class MediaSet;
class MediaLocationController;
class NiNode;
class TESSound;
#include "fnv/bs_simple_list.h"
template <class T> class BSStringT
{
  public:
    T* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    BSStringT();
    ~BSStringT();
    bool Set(const T* text, unsigned int length);
    const T* String();
};
#endif
