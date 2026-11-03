
// src/fallout_shared/havok/cameracaster_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/fallout_shared/havok/cameracaster_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/havok/cameracaster_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/havok/cameracaster.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout_shared/havok/cameracaster.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/cameracaster.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <new>
#include "fnv/decl/Callees.h"
#include "fnv/decl/DummyFlagsShell.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_00456630_helper.h"
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/decl/FUN_006212c0_shell.h"
#include "fnv/decl/FUN_00807770_Class.h"
#include "fnv/decl/Hld621210.h"
#include "fnv/decl/ListHolder.h"
#include "fnv/decl/ScriptX.h"
#include "fnv/decl/SortableArray.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_00c7f000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
extern int DAT_0104da3c;
struct FUN_00621100_shell
{
    void SetVtable();
};
struct bhkCharacterListener
{
    unsigned int FUN_00621270(unsigned int aiFlags);
};
struct FUN_00621290_shell
{
    void* InitFloats();
};

struct xP3
{
    float x, y, z;
};
union __declspec(align(16)) xM128
{
    float m128_f32[4];
    char m128_i8[16];
};
struct __declspec(align(16)) xVec4
{
    xM128 m_vComponents;
    xVec4();
};
struct __declspec(align(16)) xVec4b
{
    xM128 m_vComponents;
    int m_auiShapeKeys[4];
    xVec4b();
};
struct xHit
{
    int m_iWordAt00[18];
    void* m_48;
};
struct xHitList
{
};
struct xTag
{
    xTag();
    char m_iThirdValue;
};
struct __declspec(align(16)) xCollector
{
    xCollector();
    ~xCollector();
    int m_q[0xe8];
};
struct xPhantom
{
};
struct xFilter
{
    xFilter(unsigned int);
    unsigned int m_uiFilterValue;
};
struct xNode
{
};
struct xOwnerP
{
};
struct xActor
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual bool FUN_fc();
};

struct xMenuItem
{
    int m_iWordAt00[3];
    xActor* m_iThirdValue;
};
struct MenuItemCollection
{
};
struct xOutHit
{
};
struct xPtr
{
    void* m_p;
};
struct xCaster
{
    xPtr m_iWordAt00;
    bool FUN_00620bc0(const xP3& akFrom, xP3& akTo, xOutHit* apOut);
};
// @fnv 0x00620bc0
bool xCaster::FUN_00620bc0(const xP3& akFrom, xP3& akTo, xOutHit* apOut)
{
    bool RESULT = false;
    if (((::xPhantom *)(::FUN_00559450((int *)&(m_iWordAt00)))))
    {
        xVec4 FROM;
        xCollector COL;
        xVec4b TO;
        ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&FROM)), (const ::fnv_004a3e00::NiPoint3 &)(akFrom));
        ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&TO)), (const ::fnv_004a3e00::NiPoint3 &)(akTo));
        reinterpret_cast<::ScriptX *>((((::xPhantom *)(::FUN_00559450((int *)&(m_iWordAt00))))))->InvokeInterfaceCall((int)(&FROM), (int)(&TO), (int)(&COL), 0);
        RESULT = reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::xTag &)((*(::xTag *)(reinterpret_cast<::Hld621210 *>(&(COL))->FUN_00621210({})))))->FUN_005609f0();
        if (RESULT)
        {
            reinterpret_cast<::SortableArray *>(&(COL))->FUN_00cabad0();
            int I = 0;
            bool FOUND = false;
            bool ISX = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::MenuItemCollection *>(&::g_011f2250))))->GetName())) == 4;
            xActor* TARGET = 0;
            if (ISX)
            {
                xMenuItem* ITEM = ((::xMenuItem *)(reinterpret_cast<::ListHolder *>(&((*reinterpret_cast<::MenuItemCollection *>(&::g_011f2250))))->FUN_009c71c0()));
                if (ITEM)
                    TARGET = ITEM->m_iThirdValue;
                else
                    TARGET = (*reinterpret_cast<::xActor * *>(&::DAT_011f21cc));
                if (!TARGET)
                    TARGET = (*reinterpret_cast<::xActor * *>(&::_g_thePlayer));
            }
            while (!FOUND && I < ((int)(reinterpret_cast<::Callees *>((((::xHitList *)(::FUN_00460140((int)&(COL))))))->FUN_00726070())))
            {
                void* SHAPE = ((::xHit *)(reinterpret_cast<::FUN_00807770_Class *>((((::xHitList *)(::FUN_00460140((int)&(COL))))))->FUN_00807770(I)))->m_48;
                xFilter FILTER(::FUN_0043b540((char *)(SHAPE)));
                int TYPE = reinterpret_cast<::FUN_0043b4d0_shell *>(&(FILTER))->FUN_0043b4d0();
                xNode* NODE = ((::xNode *)(::FUN_00c7fa90((::S_Obj *)(SHAPE))));
                if (TYPE != 0x11 && (!NODE || reinterpret_cast<::FUN_00456630_helper *>((NODE))->FUN_00456610()))
                {
                    I++;
                    continue;
                }
                FOUND = true;
                switch (TYPE)
                {
                case 5:
                case 8:
                case 29:
                    if (!ISX)
                        break;
                case 19:
                case 20:
                case 25:
                case 30:
                case 32:
                    if (NODE)
                    {
                        xActor* ACTOR = ((::xActor *)(::FUN_0056f930((::NiAVObject *)(NODE))));
                        if (ACTOR)
                        {
                            if (ISX && ACTOR == TARGET)
                                FOUND = false;
                            else if (ACTOR->FUN_fc())
                            {
                                xActor* PACTOR = ACTOR;
                                xOwnerP* OWNER = ((::xOwnerP *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((PACTOR))->FUN_009306d0()));
                                if (OWNER && reinterpret_cast<::DummyFlagsShell *>((OWNER))->FUN_00621240())
                                    FOUND = false;
                            }
                        }
                    }
                    break;
                }
                if (!FOUND)
                    I++;
                else if (ISX)
                    void* LAST = ((::xHit *)(reinterpret_cast<::FUN_00807770_Class *>((((::xHitList *)(::FUN_00460140((int)&(COL))))))->FUN_00807770(I)))->m_48;
            }
            if (FOUND)
            {
                reinterpret_cast<::FUN_006212c0_shell *>((apOut))->FUN_006212c0(((::xHit *)(reinterpret_cast<::FUN_00807770_Class *>((((::xHitList *)(::FUN_00460140((int)&(COL))))))->FUN_00807770(I))));
                ::SetNiPoint3FromHkVector4((::NiPoint3 &)(akTo), (*(const ::hkVector4 *)(((::xVec4 *)(new ((void *)(apOut)) ::Vec3())))));
            }
            else
                RESULT = false;
        }
    }
    return RESULT;
}
