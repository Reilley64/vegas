
// src/fallout_shared/tesobjectrefr_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout_shared/tesobjectrefr.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_00446000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_00575000.h"
#include "fnv/symbols_00576000.h"
#include "fnv/symbols_00579000.h"
#include "fnv/symbols_0057a000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011f6000.h"
#include "tesobjectrefr_decls.h"
void* FUN_0056a8c0();

class BSExtraData
{
  public:
    virtual ~BSExtraData();
    unsigned char m_type;
    BSExtraData* m_next;
};
struct Owner;
struct ExtraBase2
{
    virtual void v0();
};
class NonActorMagicTarget : public BSExtraData, public ExtraBase2
{
  public:
    NonActorMagicTarget(Owner* o);
    int unk10, unk14, unk18, unk1c, unk20, unk24;
};
struct ExtraList
{
};
struct Owner
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18(unsigned int flag);
    ExtraBase2* FUN_00575f30();
};
// @fnv 0x00575f30
ExtraBase2* Owner::FUN_00575f30()
{
    NonActorMagicTarget* p = 0;
    if (::FUN_00576040((::TESForm *)(((int)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430())))))
    {
        p = dynamic_cast<NonActorMagicTarget*>(reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>((((::ExtraList *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_00410220(0x33));
        if (!p)
        {
            p = new NonActorMagicTarget(this);
            reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>((((::ExtraList *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_0040ff60(p);
            v18(0x80000000);
        }
    }
    return p;
}
