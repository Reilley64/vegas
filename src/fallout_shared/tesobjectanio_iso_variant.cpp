// src/fallout_shared/tesobjectanio_iso_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout_shared/tesobjectanio.cpp that match byte for byte only
// with VC9 SP1 and /MT /Od /Oy- /GS /EHsc /Gy (unit lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0048a520_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "tesobjectanio_decls.h"
struct SFTX
{
};
struct B2_4fe
{
    B2_4fe();
    virtual ~B2_4fe();
    unsigned char pad[0x1c];
};
struct FUN_00511950 : public TESForm, public B2_4fe
{
    int pAnim;
    FUN_00511950();
    virtual ~FUN_00511950();
};
struct FUN_005119e0_obj
{
    void* Destroy(unsigned int flags);
};
struct FUN_004855a0
{
};
struct FUN_00485680
{
};
struct S_0048a520
{
};
struct _ref_0084e3a0_t
{
};
struct FUN_00511d10_shell
{
    void FUN_00511d10();
};
class B511A10Form
{
  public:
    virtual ~B511A10Form();

    unsigned char m_cFormType;
    unsigned int m_iFormFlags;
    unsigned int m_iFormID;
    void* m_pkSourceFile;
    void* m_pkNextSourceFile;
};
class B511A10TextureSwap
{
  public:
    virtual ~B511A10TextureSwap();

    const char* m_pcModel;
    unsigned short m_usLength;
    unsigned short m_usMaxLength;
    float m_fBound;
    void* m_pkTextures;
    unsigned int m_uiValue1;
    void* m_pkSwapItem;
    void* m_pkSwapNext;
};
class FUN_00511a10_cls : public B511A10Form, public B511A10TextureSwap
{
  public:
    virtual ~FUN_00511a10_cls();
};

struct AnimationObjectComparison : TESObjectANIO
{
    bool FUN_00511dc0(TESForm* otherForm);
};

// @fnv 0x00511dc0
bool AnimationObjectComparison::FUN_00511dc0(TESForm* otherForm)
{
    TESObjectANIO* otherAnimation = dynamic_cast<TESObjectANIO*>(otherForm);
    if (!otherAnimation)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270(otherAnimation))
        return true;
    if (pObject != otherAnimation->pObject)
        return true;
    return false;
}

struct FUN_005e78f0_t
{
};
struct AnimationCopyEntry : TESObjectANIO
{
    void FUN_00511d70(TESForm* apCopy);
};
// @fnv 0x00511d70
void AnimationCopyEntry::FUN_00511d70(TESForm* apCopy)
{
    TESObjectANIO* panimObj = dynamic_cast<TESObjectANIO*>(apCopy);
    if (panimObj == 0)
        return;
    reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)this)))->FUN_004851b0(apCopy);
    pObject = panimObj->pObject;
}
