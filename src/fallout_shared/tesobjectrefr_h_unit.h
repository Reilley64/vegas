// fallout_shared/tesobjectrefr_h_unit.h: declares TESObjectREFR
#ifndef FNV_TESOBJECTREFR_WRAPPER_H
#define FNV_TESOBJECTREFR_WRAPPER_H
#include "fnv/decl/Ref3.h"
class NiNode;
class TESObjectREFR
{
  public:
    virtual void Set3D(NiNode* niNode, bool unloadArt);
    void Get3D(NiNode* niNode, bool unloadArt);
};

// @fnv 0x008d47d0
void TESObjectREFR::Get3D(NiNode* niNode, bool unloadArt)
{
    reinterpret_cast<::Ref3 *>(this)->FUN_005702e0((::Obj3 *)(niNode), unloadArt);
}
#endif
