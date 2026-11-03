
// src/fallout_shared/bipedanim_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /GF /Ob1 (unit src/fallout_shared/bipedanim.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "fnv/decl/B4AEE60Owner.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSXFlags.h"
#include "fnv/decl/BipedAnimHelper.h"
#include "fnv/decl/BipedWeaponRemoval.h"
#include "fnv/decl/C4AEDE0Queue.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CloneSourceA5d6.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_004226e0_shell.h"
#include "fnv/decl/FUN_004303e0_Class.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_0045a5e0_shell.h"
#include "fnv/decl/FUN_004700d0_class.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_004aaef0_shell.h"
#include "fnv/decl/FUN_004aaf10_shell.h"
#include "fnv/decl/FUN_004aaff0_S.h"
#include "fnv/decl/FUN_004ac110_shell.h"
#include "fnv/decl/FUN_004ad010_shell.h"
#include "fnv/decl/FUN_004add70_shell.h"
#include "fnv/decl/FUN_004adda0_shell.h"
#include "fnv/decl/FUN_004adde0_shell.h"
#include "fnv/decl/FUN_004ae6a0_shell.h"
#include "fnv/decl/FUN_004af860_shell.h"
#include "fnv/decl/FUN_004af880_shell.h"
#include "fnv/decl/FUN_004afa20_shell.h"
#include "fnv/decl/FUN_00504e60_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_00572160_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0065a970_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008b0bd0_shell.h"
#include "fnv/decl/FUN_00950b30_Class.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009cdae0_shell.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00a5be90_shell.h"
#include "fnv/decl/FaceLoader.h"
#include "fnv/decl/Fake_FUN_004a2020.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/MyHost.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/decl/NiObjectD510.h"
#include "fnv/decl/QueueHelper.h"
#include "fnv/decl/QueueModelHolder.h"
#include "fnv/decl/TESRegionDataMap.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/W_0043b4f0.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_004436c0__FUN_004436c0_Class.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_00567050__FUN_00567050_shell.h"
#include "fnv/decl/fnv_00571760__Actor.h"
#include "fnv/decl/fnv_006148f0__FUN_006148f0_shell.h"
#include "fnv/decl/fnv_006149b0__RaceTexture.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008b0b00__FUN_008b0b00_cls.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040a000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043f000.h"
#include "fnv/symbols_00441000.h"
#include "fnv/symbols_00448000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00491000.h"
#include "fnv/symbols_004ab000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004af000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_00572000.h"
#include "fnv/symbols_00577000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e4000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_00657000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_00c6c000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_01199000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "bipedanim_decls.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
struct FixStrQ
{
    char* m_kHandle;
    FixStrQ(const char* s)
    {
        if (s == 0)
            m_kHandle = DAT_0109b220;
        else
            m_kHandle = ::NiGlobalStringTable::AddString(s);
    }
    ~FixStrQ()
    {
        if (m_kHandle == DAT_0109b220)
            return;
        long* pRef = (long*)(m_kHandle - 8);
        InterlockedDecrement(pRef);
    }
};
struct ResultQ;
struct FinderQ
{
    virtual void v00(), v01(), v02(), v03(), v04(), v05(), v06(), v07(), v08(), v09(), v10(), v11(), v12(), v13(),
        v14(), v15(), v16(), v17(), v18(), v19(), v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(),
        v30(), v31(), v32(), v33(), v34();
    virtual ResultQ* Find(const FixStrQ& name);
};
struct ExtQ
{
    char pad[0x78];
    FinderQ* m_pFinder;
    FinderQ* GetFinder()
    {
        FinderQ* p = m_pFinder;
        return p;
    }
};
struct ObjQ
{
    virtual void v00(), v01(), v02(), v03(), v04(), v05(), v06(), v07(), v08(), v09(), v10(), v11(), v12(), v13(),
        v14(), v15(), v16(), v17(), v18(), v19(), v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(),
        v30(), v31(), v32(), v33(), v34(), v35(), v36(), v37(), v38();
    virtual ResultQ* GetObjectByName(const FixStrQ& name);
};
// @fnv 0x00c4b310
ResultQ* __cdecl FUN_00c4b310(ObjQ* pObj, const char* pcName, bool bRecurse)
{
    if (!pObj || !pcName)
        return 0;
    ExtQ* pExt3 = ((::ExtQ *)(reinterpret_cast<::MyHost *>((pObj))->FUN_00a5c570((const ::MyRTTI *)(void *)(&(*reinterpret_cast<char *>(&::g_011f36ac))))));
    FixStrQ kName9(pcName);
    if (pExt3)
    {
        ResultQ* pRes2 = pExt3->GetFinder()->Find(kName9);
        if (pRes2)
            return pRes2;
    }
    if (bRecurse)
        return pObj->GetObjectByName(kName9);
    return 0;
}
