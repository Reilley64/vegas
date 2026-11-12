
// src/havok/physics/dynamics/world/hkpworld.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/hkpworld.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkUlong.h"
#include "fnv/symbols_01272000.h"
#include <new>

#include "havok/hkMemoryRouter.h"
#include "fnv/tls.h"
#include "fnv/symbols_00c85000.h"
#include <cstddef>
#include <xmmintrin.h>
#include <intrin.h>
#include "generated/data/vtables.h"
#include <windows.h>
#include <cstring>
#include "fnv/decl/C66A00This.h"
#include "fnv/decl/CbfOwner.h"
#include "fnv/decl/D04B90World.h"
#include "fnv/decl/DebugArrowEntry.h"
#include "fnv/decl/Dispatcher.h"
#include "fnv/decl/DispatcherCF7080.h"
#include "fnv/decl/FUN_00c66e20_Class.h"
#include "fnv/decl/FUN_00c67850_Class.h"
#include "fnv/decl/FUN_00c87c30_t.h"
#include "fnv/decl/FUN_00c89c80_obj.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00c93580_Class.h"
#include "fnv/decl/FUN_00cac980_class.h"
#include "fnv/decl/FUN_00cb8ac0_class.h"
#include "fnv/decl/FUN_00cbf6b0_class.h"
#include "fnv/decl/FUN_00cf6da0_cls.h"
#include "fnv/decl/FUN_00cf86f0_class.h"
#include "fnv/decl/FUN_00cf8710_cls.h"
#include "fnv/decl/FUN_00cfa860.h"
#include "fnv/decl/FUN_00d06fb0_cls.h"
#include "fnv/decl/FUN_00d07470_cls.h"
#include "fnv/decl/FUN_00d07950_cls.h"
#include "fnv/decl/FUN_00d081e0_cls.h"
#include "fnv/decl/FUN_00d08210_Collidable.h"
#include "fnv/decl/FnvCpu_FUN_00c89720_CpuInterface.h"
#include "fnv/decl/Fun_cls.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/Owner89730.h"
#include "fnv/decl/Pending.h"
#include "fnv/decl/PhantomCls.h"
#include "fnv/decl/Root.h"
#include "fnv/decl/S_00c8a280_Obj.h"
#include "fnv/decl/S_00cfab30_this.h"
#include "fnv/decl/S_00cfaed0_This.h"
#include "fnv/decl/S_00d9e280_D.h"
#include "fnv/decl/S_Owner.h"
#include "fnv/decl/SaveBuffer.h"
#include "fnv/decl/Shell_c6a540.h"
#include "fnv/decl/TransformedPosDAD.h"
#include "fnv/decl/ViewerConstraint.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/WorldView.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/fnv_00c67df0__PendingWorld.h"
#include "fnv/decl/fnv_00c68de0__FNV_C68DE0_OWNER.h"
#include "fnv/decl/fnv_00c6aac0__FUN_00c6aac0_Owner.h"
#include "fnv/decl/fnv_00cf3040__FUN_00cf3040_class.h"
#include "fnv/decl/fnv_00cf3e60__FUN_00cf3e60_class.h"
#include "fnv/decl/fnv_00cf7690__Vec.h"
#include "fnv/decl/fnv_00cf7ae0__S_00cf7ae0.h"
#include "fnv/decl/hkMapD01A.h"
#include "fnv/decl/hkMultiThreadCheckCF6E.h"
#include "fnv/decl/hkOwnerD064.h"
#include "fnv/decl/hkOwnerXd06540.h"
#include "fnv/decl/hkOwnerXd06590.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/hkpEntityC9C.h"
#include "fnv/decl/hkpEntityC9C0.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00c87000.h"
#include "fnv/symbols_00c8a000.h"
#include "fnv/symbols_00c8c000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00c91000.h"
#include "fnv/symbols_00c92000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_00cb3000.h"
#include "fnv/symbols_00cb4000.h"
#include "fnv/symbols_00cb5000.h"
#include "fnv/symbols_00cb6000.h"
#include "fnv/symbols_00cbd000.h"
#include "fnv/symbols_00cc1000.h"
#include "fnv/symbols_00cf1000.h"
#include "fnv/symbols_00cf7000.h"
#include "fnv/symbols_00cfd000.h"
#include "fnv/symbols_00cfe000.h"
#include "fnv/symbols_00cff000.h"
#include "fnv/symbols_00d00000.h"
#include "fnv/symbols_00d04000.h"
#include "fnv/symbols_00d05000.h"
#include "fnv/symbols_00d06000.h"
#include "fnv/symbols_00d1a000.h"
#include "fnv/symbols_00d1b000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_01076000.h"
#include "fnv/symbols_0108f000.h"
#include "fnv/symbols_010c3000.h"
#include "fnv/symbols_010c4000.h"
#include "fnv/symbols_010c5000.h"
#include "fnv/symbols_010c6000.h"
#include "fnv/symbols_011ac000.h"
#include "fnv/symbols_011af000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
#include "havok/hkpWorld.h"
#include "havok/hkpSimulation.h"
#include "havok/hkpCollisionDispatcher.h"
#include "fnv/decl/S_00ce5290.h"
#include "fnv/symbols_simd.h"
class hkWorldCFD4;
struct hkpWorldQ;

struct FUN_00c98820_ArrayObject;
struct FUN_00c98820_Class
{
    int m_00;
    int m_04;
    FUN_00c98820_ArrayObject** m_08;
    int m_0c;

    void FUN_00c98820(void* first, void* second, int color, hkUlong id, int tag);
};
class C91World : public hkpWorld {
public:
    int FUN_00c91b10(float delta);
};
struct WorldFinishEntryC91C : hkpWorld {
    int FUN_00c91c00(void* queue, void* pool);
};

struct FUN_00cf7c10 {
};

// hkpCollisionFilter's hkpCollidableCollidableFilter base, the interface after its hkReferencedObject part.
struct hkpCollisionFilterBases : hkReferencedObject {
    void* m_collidableCollidableFilter;
};
static inline void* collidableCollidableFilterOf(void* filter)
{
    return filter ? &static_cast<hkpCollisionFilterBases*>(filter)->m_collidableCollidableFilter : 0;
}
// hkpCollisionInput field saved with the world: the config pointer.
struct WorldSaveCollisionInput {
    char pad00[0x70];
    void* m_config;  // +0x70
};
struct FUN_00c91120 : hkpWorld {
    void ExecutePendingOperations();
};

// @fnv 0x00c91120
void FUN_00c91120::ExecutePendingOperations()
{
    m_iPendingOperationCount = 0;
    reinterpret_cast<::Pending *>(m_pPendingOperations)->FUN_00cf7c10();
}

struct FUN_00c91180_Class : hkpWorld {
    void EnterTlsGuard();
    void IncrementCounter();
};

// @fnv 0x00c91180
void FUN_00c91180_Class::IncrementCounter()
{
    EnterTlsGuard();
    ++m_iIsLocked;
}

struct KdTreeManagerC9125 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
    virtual void v14(int);
};
struct FUN_00c91250_Class : hkpWorld {
    void FUN_00c91250();
};

// @fnv 0x00c91250
void FUN_00c91250_Class::FUN_00c91250()
{
    if (m_pKdTreeManager)
        static_cast<KdTreeManagerC9125*>(m_pKdTreeManager)->v14(0);
}

struct FUN_00cf6d20_Class {
    void FUN_00cf6d20();
};
struct FUN_00cf6d30_Class {
};
struct FUN_00c91280_BroadPhase : hkReferencedObject {
    hkMultiThreadCheck m_kMultiThreadCheck;
};
struct FUN_00c91280_Class : hkpWorld {
    void FUN_00c91280(int);
};
// Calls ResetThreadCheck on the world's and the broad phase's multithread checks when a is zero, otherwise calls FUN_00cf6d20 on both.
// @fnv 0x00c91280
void FUN_00c91280_Class::FUN_00c91280(int a)
{
    FUN_00c91280_BroadPhase* broadPhase = static_cast<FUN_00c91280_BroadPhase*>(m_pJobSemaphore);
    if (!a) {
        reinterpret_cast<::hkMultiThreadCheckCF6E *>(&m_kMultiThreadCheck)->ResetThreadCheck();
        reinterpret_cast<::hkMultiThreadCheckCF6E *>(&broadPhase->m_kMultiThreadCheck)->ResetThreadCheck();
    } else {
        reinterpret_cast<FUN_00cf6d20_Class*>(&m_kMultiThreadCheck)->FUN_00cf6d20();
        reinterpret_cast<FUN_00cf6d20_Class*>(&broadPhase->m_kMultiThreadCheck)->FUN_00cf6d20();
    }
}

struct NiBinaryStream {
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int (__cdecl* m_pfnWrite)(NiBinaryStream* pThis, const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents)
    {
        unsigned int uiBytes = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytes;
        return uiBytes;
    }
};
struct Ctx_00caa840 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    NiBinaryStream* m_pBackingStream;
};
struct Blk40 { float f[16]; };
template <class T> inline unsigned int WriteBinaryArray(NiBinaryStream& binstream, const T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    return binstream.BinaryWrite(pValue, uiNumEls * sizeof(T), &uiSize, uiNumEls);
}
template <class T> inline void SerializeValue(Ctx_00caa840& kStream, const T& tValue)
{
    WriteBinaryArray(*kStream.m_pBackingStream, &tValue, 1);
}
struct Data_00caa840 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    Blk40 m_20;
    Blk40 m_60;
    unsigned char unkA0;
    unsigned char unkA1;
    char m_a2;
    unsigned char unkA3;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    ::C8A4B0Shape* m_b0;
    unsigned int unkB4;
    unsigned int unkB8;
    int m_bc;
    unsigned int unkC0;
    int m_c4;
    int m_c8;
};

struct FUN_00caa840_shell {
    void* m_iWordAt00;
    Data_00caa840* m_data;
    void WriteToStream(Ctx_00caa840* ctx);
};

// @fnv 0x00caa840
void FUN_00caa840_shell::WriteToStream(Ctx_00caa840* ctx)
{
    reinterpret_cast<::S_00c8a280_Obj *>(this)->FUN_00c8a280((*(::S_00c8a280_Stream *)(ctx)));
    Data_00caa840* d = m_data;
    SerializeValue(*ctx, d->m_20);
    SerializeValue(*ctx, d->m_60);
    SerializeValue(*ctx, d->m_c4);
    SerializeValue(*ctx, d->m_c8);
    SerializeValue(*ctx, d->m_bc);
    ::SaveShape(d->m_b0, (*(::C8A4B0Stream *)(ctx)));
    if (d->m_b0)
        SerializeValue(*ctx, d->m_a2);
}

// Calls the virtual at offset 0x18 with "hkpContactMgrFactory", then the virtual at offset 0x1c on self.
// @fnv 0x00c90e40
void FUN_00c90e40(void* self, int arg)
{
    void** vtable = *static_cast<void***>(self);
    reinterpret_cast<void (*)(void*, const char*)>(vtable[6])(self, "hkpContactMgrFactory");
    reinterpret_cast<void (*)(void*)>(vtable[7])(self);
}

struct FUN_00cf86e0_class : public hkpSimulation {
    void FUN_00cf86e0(float);
};
// Forwards the value to the world's simulation.
// @fnv 0x00c91040
void FUN_00c91040(void* p, int edx, float afValue)
{
    static_cast<FUN_00cf86e0_class*>(static_cast<hkpWorld*>(p)->m_pSimulation)->FUN_00cf86e0(afValue);
}

struct RefObj {  };
struct DDCC60World { void removeReference(); };
struct FUN_00c910d0_Class {
    void* m_iWordAt00; void* m_iWordAt04; void* m_8; void* m_iThirdValue; void* m_10; void* m_14; void* m_18;
    void* m_1c; void* m_20; void* m_24; void* m_28; void* m_2c; void* m_30; void* m_34;
    void* m_38; void* m_3c; void* m_40; void* m_44; void* m_48; void* m_4c; void* m_50;
    void* m_54; void* m_58; void* m_5c; void* m_60; void* m_64; void* m_68; void* m_6c;
    void* m_70; void* m_74; void* m_78; void* m_7c; void* m_80; void* m_84; void* m_88;
    void* m_8c; void* m_90; void* m_94; void* m_98; void* m_9c; void* m_a0; void* m_a4;
    void* m_a8; void* m_ac; void* m_b0; void* m_b4; void* m_b8; void* m_bc; void* m_c0;
    void* m_c4; void* m_c8; void* m_cc; void* m_d0; void* m_d4; void* m_d8; void* m_dc;
    void* m_e0; void* m_e4; void* m_e8; void* m_ec; void* m_f0; void* m_f4; void* m_f8;
    void* m_fc; void* m_100; void* m_104; void* m_108; void* m_10c; void* m_110; void* m_114;
    void* m_118; void* m_11c; void* m_120; void* m_124; void* m_128; void* m_12c; void* m_130;
    void* m_134; void* m_138; void* m_13c; void* m_140; void* m_144; void* m_148; void* m_14c;
    void* m_150; void* m_154; void* m_158; void* m_15c; void* m_160; void* m_164; void* m_168;
    void* m_16c; void* m_170; void* m_174; void* m_178; void* m_17c; void* m_180; void* m_184;
    void* m_188; void* m_18c; void* m_190; void* m_194; void* m_198; void* m_19c; void* m_1a0;
    void* m_1a4; void* m_1a8; void* m_1ac; void* m_1b0; void* m_1b4; void* m_1b8;
    void* m_1bc;
    void SetRefObject(void*);
};
// @fnv 0x00c910d0
void FUN_00c910d0_Class::SetRefObject(void* p)
{
    void* old = m_1bc;
    if (old) {
        (*(void (*)(void*))(*(void***)old)[4])(old);
        reinterpret_cast<::hkReferencedObjectC905 *>((((DDCC60World*)m_1bc)))->FUN_00c905b0();
    }
    m_1bc = p;
    if (p) reinterpret_cast<::FUN_00c90510_class *>((((RefObj*)p)))->FUN_00c90510();
}

struct FUN_00cf7ae0_Class {
};
struct FUN_00c91140_Class {
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1C;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2C;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3C;
    unsigned int m_40;
    unsigned int m_44;
    unsigned int m_48;
    unsigned int m_4C;
    unsigned int m_50;
    unsigned int m_54;
    unsigned int m_58;
    unsigned int m_5C;
    unsigned int m_60;
    unsigned int m_64;
    unsigned int m_68;
    unsigned int m_6C;
    unsigned int m_70;
    unsigned int m_74;
    unsigned int m_78;
    unsigned int m_7C;
    unsigned int m_80;
    unsigned int m_84;
    FUN_00cf7ae0_Class* m_88;
    unsigned int m_8C;
    int m_90;
    void FUN_00c91140();
};
// @fnv 0x00c91140
void FUN_00c91140_Class::FUN_00c91140()
{
    m_90 = 0;
    reinterpret_cast<::fnv_00cf7ae0::S_00cf7ae0 *>((m_88))->FUN_00cf7ae0();
}

struct S_00cf7540_Ref {
    void* m_p;
};
struct S_00cf7540 {
    void AddEntry(S_00cf7540_Ref*, S_00cf7540_Ref*, int, int);
};
struct FUN_00c91170_Class : hkpWorld {
    void FUN_00c91170(S_00cf7540_Ref*, S_00cf7540_Ref*, int, int);
};
// @fnv 0x00c91170
void FUN_00c91170_Class::FUN_00c91170(S_00cf7540_Ref* a, S_00cf7540_Ref* b, int c, int d)
{
    static_cast<S_00cf7540*>(m_pPendingOperations)->AddEntry(a, b, c, d);
}

void __cdecl FUN_00c904e0();
struct FUN_00c91190_Class : hkpWorld {
    void FUN_00c91190();
};
// @fnv 0x00c91190
void FUN_00c91190_Class::FUN_00c91190()
{
    --m_iIsLocked;
    FUN_00c904e0();
}


struct FUN_00c911d0_Class : hkpWorld {
    void EnterLock(void*);
};

// @fnv 0x00c911d0
void FUN_00c911d0_Class::EnterLock(void* unused)
{
    CRITICAL_SECTION* cs = static_cast<CRITICAL_SECTION*>(m_pModifyConstraintCriticalSection);
    if (cs)
    {
        EnterCriticalSection(cs);
        return;
    }
}

extern void (*DAT_00fdf05c)(void*);

struct FUN_00c911f0_Class : hkpWorld {
    void FUN_00c911f0(void*);
};

// @fnv 0x00c911f0
void FUN_00c911f0_Class::FUN_00c911f0(void* p)
{
    void* pStoredKey = m_pModifyConstraintCriticalSection;
    if (pStoredKey)
        DAT_00fdf05c(pStoredKey);
}

namespace fnv_00c91f40 {
struct RefObj { void RetainReference(); void removeReference(); };
struct FUN_00c91f40_Class : ::hkpWorld {
    void SetRefObj(RefObj* obj);
};
// @fnv 0x00c91f40
void FUN_00c91f40_Class::SetRefObj(RefObj* apRefObj)
{
    if (apRefObj) reinterpret_cast<::FUN_00c90510_class *>((apRefObj))->FUN_00c90510();
    RefObj* old = static_cast<RefObj*>(m_pMemoryWatchDog);
    if (old) reinterpret_cast<::hkReferencedObjectC905 *>((old))->FUN_00c905b0();
    m_pMemoryWatchDog = apRefObj;
}
}  // namespace fnv_00c91f40

class hkpAction;

struct hkpPhysicsSystem
{
};

struct FUN_00c928c0_ActionList
{
    hkpAction** m_ppActions;
    int m_uiItemCount;
};

struct FUN_00c928c0_ActionOwner
{
    unsigned char m_auiShapeKeys[0x38];
    FUN_00c928c0_ActionList m_actionList;
};

struct FUN_00c928c0_Context
{
    unsigned char m_pad00[0x28];
    FUN_00c928c0_ActionOwner** m_owners1;
    unsigned int m_ownerCount1;
    unsigned char m_pad30[0x04];
    FUN_00c928c0_ActionOwner** m_owners2;
    unsigned int m_ownerCount2;
};

// Iterates both owner arrays in context and calls physicsSystem->FUN_00d06590 on every action in each owner's action list.
// @fnv 0x00c928c0
void FUN_00c928c0(
    FUN_00c928c0_Context* context,
    hkpPhysicsSystem* physicsSystem)
{
    FUN_00c928c0_ActionOwner** owner = context->m_owners1;
    FUN_00c928c0_ActionOwner** end = owner + context->m_ownerCount1;

    while (owner != end)
    {
        FUN_00c928c0_ActionList* actions = &(*owner)->m_actionList;
        int action = 0;

        while (action < actions->m_uiItemCount)
        {
            reinterpret_cast<::hkOwnerXd06590 *>((physicsSystem))->FUN_00d06590((::hkShapeXd06590 *)(actions->m_ppActions[action]));
            ++action;
        }

        ++owner;
        end = context->m_owners1 + context->m_ownerCount1;
    }

    owner = context->m_owners2;
    end = owner + context->m_ownerCount2;

    while (owner != end)
    {
        FUN_00c928c0_ActionList* actions = &(*owner)->m_actionList;
        int action = 0;

        while (action < actions->m_uiItemCount)
        {
            reinterpret_cast<::hkOwnerXd06590 *>((physicsSystem))->FUN_00d06590((::hkShapeXd06590 *)(actions->m_ppActions[action]));
            ++action;
        }

        ++owner;
        end = context->m_owners2 + context->m_ownerCount2;
    }
}

struct hkpWorld_MemUsageOut {
    int m_maxSize;
    int m_totalSize;
    void* m_maxObject;
};

// The island fields ComputeMemoryUsage reads: constraint info sizes, constraint count and entity count.
struct FUN_00c92b50_Island {
    void* m_vtbl;
    int m_refs;
    int m_maxSizeOfSchema;
    int m_sizeOfSchemas;
    int m_numSolverResults;
    int m_numSolverElemTemps;
    void* m_world;
    int m_numConstraints;
    char pad20[0x28];
    void* m_entities;
    int m_numEntities;
};
struct FUN_00c92b50_Class {
    char pad[0x28];
    void* m_data;   // +0x28
    int m_iElementCount;     // +0x2c
    void ComputeMemoryUsage(hkpWorld_MemUsageOut* out);
};

// Accumulates per-object memory sizes into out->m_totalSize and tracks the largest object in out->m_maxSize/m_maxObject.
// @fnv 0x00c92b50
void FUN_00c92b50_Class::ComputeMemoryUsage(hkpWorld_MemUsageOut* out)
{
    out->m_maxSize = 0;
    out->m_totalSize = 0;
    out->m_maxObject = 0;

    for (int i = m_iElementCount - 1; i >= 0; --i) {
        FUN_00c92b50_Island* obj = ((FUN_00c92b50_Island**)m_data)[i];
        int a = obj->m_numConstraints;
        int b = obj->m_numEntities;
        int q = a / 80;
        int r = (q + q + 8);
        int size = r * 3 + obj->m_numSolverElemTemps;
        int size2 = (r + b * 8 + 10) << 4;
        size = ((size * 4 + 0x17) & 0xfffffff0) + size2 + obj->m_sizeOfSchemas;
        out->m_totalSize += size;
        if (size > out->m_maxSize) {
            out->m_maxSize = size;
            out->m_maxObject = obj;
        }
    }
}

struct CA8B80Command {
    unsigned char m_bType;
    void* m_p;
};
struct CA8B80Queue {
};
struct FUN_00c97510 {
};
struct FUN_00c97f50_Class : hkpWorld {
    void DispatchOrQueue(void* p);
};
struct FUN_00c98350_Class {
    void* m_p;
    void* InitAndMaybeFree(int);
};
// @fnv 0x00c98350
void* FUN_00c98350_Class::InitAndMaybeFree(int flags)
{
    m_p = &DAT_010c3bb8;
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct LockedListenerList {
    void* m_vtbl;
    int m_refs;
    void** m_data;
    int m_size;
    int m_capacity;
    CRITICAL_SECTION* m_cs;
};
struct FUN_00c983e0_Class : LockedListenerList {
    void ForEachCall(const void* geometries, const void* transform, hkUlong id, int tag, hkUlong shapeIdHint);
};

// Locks the critical section, calls the second virtual method of each object in the array with the five arguments, then unlocks.
// @fnv 0x00c983e0
void FUN_00c983e0_Class::ForEachCall(const void* aiArg1, const void* aiArg2, hkUlong aiArg3, int aiArg4, hkUlong aiArg5)
{
    EnterCriticalSection(m_cs);
    for (int i = 0; i < m_size; ++i) {
        void* obj = m_data[i];
        void** vtbl = *(void***)obj;
        typedef void (* Fn)(void*, const void*, const void*, hkUlong, int, hkUlong);
        ((Fn)vtbl[1])(obj, aiArg1, aiArg2, aiArg3, aiArg4, aiArg5);
    }
    LeaveCriticalSection(m_cs);
}


struct FUN_00c984a0_Class {
    unsigned int unk00;
    unsigned int unk04;
    void** unk08;
    int unk0C;
    unsigned int unk10;
    CRITICAL_SECTION* unk14;
    void FUN_00c984a0(int color, hkUlong id, int tag);
};

// Locks the critical section, calls virtual method slot 3 on each of unk0C objects in the unk08 array with a1, a2, a3, then unlocks.
// @fnv 0x00c984a0
void FUN_00c984a0_Class::FUN_00c984a0(int aiArg1, hkUlong aiArg2, int aiArg3)
{
    EnterCriticalSection(unk14);
    for (int i = 0; i < unk0C; ++i) {
        void* obj = unk08[i];
        void** vtbl = *(void***)obj;
        ((void (*)(void*, int, hkUlong, int))vtbl[3])(obj, aiArg1, aiArg2, aiArg3);
    }
    LeaveCriticalSection(unk14);
}

struct FUN_00c98540_Class : LockedListenerList {
    void CallAllWithArgs(hkUlong id, int tag, hkUlong shapeIdHint);
};


// @fnv 0x00c98540
void FUN_00c98540_Class::CallAllWithArgs(hkUlong aiArg1, int aiArg2, hkUlong aiArg3)
{
    CRITICAL_SECTION* pLock = m_cs;
    EnterCriticalSection(pLock);
    int i = 0;
    if (m_size > 0) {
        do {
            void* obj = m_data[i];
            void** vtbl = *(void***)obj;
            void (* fn)(void*, hkUlong, int, hkUlong) = (void (*)(void*, hkUlong, int, hkUlong))vtbl[5];
            fn(obj, aiArg1, aiArg2, aiArg3);
            ++i;
        } while (i < m_size);
    }
    CRITICAL_SECTION* pLock2 = m_cs;
    LeaveCriticalSection(pLock2);
}


struct FUN_00c98600_Class {
    unsigned int unk00;
    unsigned int unk04;
    void* m_ppData;      // +0x08
    int m_uiItemCount;        // +0x0C
    unsigned int unk10;
    CRITICAL_SECTION* m_cs;         // +0x14
    void CallVirtualOnAll(const void* a, const void* b, const void* c, const void* d, const void* e, const void* f, const void* g, const void* h);
};

// @fnv 0x00c98600
void FUN_00c98600_Class::CallVirtualOnAll(const void* aiArg0, const void* aiArg1, const void* aiArg2, const void* aiArg3, const void* aiArg4, const void* aiArg5, const void* aiArg6, const void* aiArg7)
{
    EnterCriticalSection(m_cs);
    for (int i = 0; i < m_uiItemCount; ++i) {
        void** arr = (void**)m_ppData;
        void* obj = arr[i];
        void** vtbl = *(void***)obj;
        typedef void (* Fn)(void*, const void*, const void*, const void*, const void*, const void*, const void*, const void*, const void*);
        Fn fn = (Fn)vtbl[7];
        fn(obj, aiArg0, aiArg1, aiArg2, aiArg3, aiArg4, aiArg5, aiArg6, aiArg7);
    }
    LeaveCriticalSection(m_cs);
}

struct FUN_00c990b0_Class : LockedListenerList {
    void FUN_00c990b0(const char* text, int color, hkUlong id, int tag);
};


// Locks the critical section, calls virtual method at vtable offset 0x2c on each element of the array, then unlocks.
// @fnv 0x00c990b0
void FUN_00c990b0_Class::FUN_00c990b0(const char* aiArg1, int aiArg2, hkUlong aiArg3, int aiArg4)
{
    EnterCriticalSection(m_cs);
    int i = 0;
    if (m_size > 0) {
        do {
            void* obj = m_data[i];
            void** ppVtable = *(void***)obj;
            void (* fn)(void*, const char*, int, hkUlong, int) = (void (*)(void*, const char*, int, hkUlong, int))ppVtable[0x2c / 4];
            fn(obj, aiArg1, aiArg2, aiArg3, aiArg4);
            ++i;
        } while (i < m_size);
    }
    LeaveCriticalSection(m_cs);
}


struct FUN_00c995f0_Class : LockedListenerList {
    void FUN_00c995f0();
};

// Calls FUN_00fdf05c and FUN_00fdf100 on the pointer at offset 0x14 and clears the int at offset 0xc.
// @fnv 0x00c995f0
void FUN_00c995f0_Class::FUN_00c995f0()
{
    CRITICAL_SECTION* p = m_cs;
    EnterCriticalSection(p);
    p = m_cs;
    m_size = 0;
    LeaveCriticalSection(p);
}

struct FUN_00c90f30_Class {
    int unk00;
    void* FUN_00c90f30();
};
// @fnv 0x00c90f30
void* FUN_00c90f30_Class::FUN_00c90f30() { unk00 = 70; return this; }

struct CpuScalar {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    float value;
};
struct CpuObject {
    unsigned int unk00;
    unsigned int unk04;
    CpuScalar* value;
    float FUN_00c91020();
};
// @fnv 0x00c91020
float CpuObject::FUN_00c91020()
{
    return value->value;
}

namespace fnv_00c91030 {
struct CpuScalar {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    float value;
};
struct CpuObject {
    unsigned int unk00;
    unsigned int unk04;
    CpuScalar* value;
    float FUN_00c91030();
};
// @fnv 0x00c91030
float CpuObject::FUN_00c91030()
{
    return value->value;
}
}  // namespace fnv_00c91030

struct FUN_00cf86f0_Class {
};

struct FUN_00c91060_Class {
    void* m_iWordAt00;
    void* m_iWordAt04;
    FUN_00cf86f0_Class* m_8;
    void FUN_00c91060();
};

// @fnv 0x00c91060
void FUN_00c91060_Class::FUN_00c91060()
{
    reinterpret_cast<::FUN_00cf86f0_class *>((m_8))->IsFieldEqual();
}

struct Inner
{
    void Tail();
};

struct FUN_00c91070_cls
{
    int unk00;
    int unk04;
    Inner* m_08;
    void FUN_00c91070();
};

// @fnv 0x00c91070
void FUN_00c91070_cls::FUN_00c91070()
{
    reinterpret_cast<::FUN_00cf8710_cls *>((m_08))->FUN_00cf8710();
}

namespace fnv_00c91080 {
struct Inner
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int Tail(int a);
};

struct FUN_00c91080_cls
{
    int unk00;
    int unk04;
    Inner* m_08;
    int FUN_00c91080(int a);
};

// @fnv 0x00c91080
int FUN_00c91080_cls::FUN_00c91080(int a)
{
    return m_08->Tail(a);
}
}  // namespace fnv_00c91080

struct FnvCpu_FUN_00c91090_CpuInterface {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void Invoke(int arg0);
};
struct FnvCpu_FUN_00c91090_CpuOwner {
    unsigned int unk00;
    unsigned int unk04;
    FnvCpu_FUN_00c91090_CpuInterface* target;
    void FUN_00c91090(int arg0);
};
// @fnv 0x00c91090
void FnvCpu_FUN_00c91090_CpuOwner::FUN_00c91090(int arg0)
{
    target->Invoke(arg0);
}

namespace fnv_00c91110 {
struct CpuObject {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    void* value;
    void* FUN_00c91110();
};
// @fnv 0x00c91110
void* CpuObject::FUN_00c91110()
{
    return value;
}
}  // namespace fnv_00c91110

struct PendingOperations {
};

struct WorldWithPending : hkpWorld {
    void FUN_00c91160();
};

// @fnv 0x00c91160
void WorldWithPending::FUN_00c91160()
{
    reinterpret_cast<::fnv_00cf7690::Vec *>((((PendingOperations*)m_pPendingOperations)))->FUN_00cf7690({});
}

struct Target
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void Forward(void* a);
};

struct FUN_00c91270_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    Target* m_5C;
    void FUN_00c91270(void* a);
};

// @fnv 0x00c91270
void FUN_00c91270_cls::FUN_00c91270(void* a)
{
    m_5C->Forward(a);
}

struct FUN_00c98250_Class {
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* FUN_00c98250(int, int, int);
};

// @fnv 0x00c98250
void* FUN_00c98250_Class::FUN_00c98250(int, int, int)
{
    return (void*)((char*)&this->m_8);
}

// @fnv 0x00c982a0
void FUN_00c982a0(char* pFlag, int a2, int a3, int a4, int a5, int a6)
{
    *pFlag = 1;
}

// FUN_00c982b0: stdcall with 8 stack parameters; writes 1 through the first parameter pointer.
// @fnv 0x00c982b0
void FUN_00c982b0(unsigned char* flag, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    *flag = 1;
}


struct ScopedMemContext {
    int m_saved;
public:
    ScopedMemContext(int ctx)
    {
        m_saved = g_tlsBlock.memoryContext;
        g_tlsBlock.memoryContext = ctx;
    }
    ~ScopedMemContext()
    {
        g_tlsBlock.memoryContext = m_saved;
    }
};

struct C67Owner {
    int unk00;
    int unk04;
    int unk08;
    struct C67Flags* unk0C;
};

struct C67Flags {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int unk10;
    void clearFlag20() { unk10 &= ~0x20; }
};
struct C67Collidable {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    signed char m_iOwnerOffset;
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    char m_type;
    C67Owner* getOwner() { return (C67Owner*)((char*)this + m_iOwnerOffset); }
};

struct C67Entry {
    void removeReference();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C67Collidable m_kCollidable;
};

inline C67Owner* getEntityOwner(C67Collidable* coll)
{
    if (coll->m_type == 1)
        return coll->getOwner();
    return 0;
}

struct C67Sink {
};

class FUN_00c67aa0_Class {
public:
    virtual void vf00(); virtual void vf01(); virtual void vf02(); virtual void vf03();
    virtual void vf04(); virtual void vf05(); virtual void vf06(); virtual void vf07();
    virtual void vf08(); virtual void vf09(); virtual void vf10(); virtual void vf11();
    virtual void vf12(); virtual void vf13(); virtual void vf14(); virtual void vf15();
    virtual void vf16(); virtual void vf17(); virtual void vf18(); virtual void vf19();
    virtual void vf20(); virtual void vf21(); virtual void vf22(); virtual void vf23();
    virtual void vf24(); virtual void vf25(); virtual void vf26(); virtual void vf27();
    virtual void vf28(); virtual void vf29(); virtual void vf30(); virtual void vf31();
    virtual void vf32(); virtual void vf33(); virtual void vf34(); virtual void vf35();
    virtual void vf36();
    virtual C67Sink* getSink();
    int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48;
    C67Entry** m_entries;
    unsigned int m_iNumberOfEntries;
    void FlushEntries();
};

struct WorldExt : public hkpWorld {
    bool FUN_00c91060() throw();
    void FUN_00c91120() throw();
};

struct Class_012677d0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void* unk14;
    void* unk18;
};

extern float DAT_012677c4;
extern char DAT_012677a0;
extern int DAT_012677c8;
extern float DAT_011afe68;
extern unsigned char DAT_01267b2c;
extern float DAT_012677ac;
extern char DAT_012677cd;

struct bhkWorld {
    virtual void v00() throw();
    virtual void v01() throw();
    virtual void v02() throw();
    virtual void v03() throw();
    virtual void v04() throw();
    virtual void v05() throw();
    virtual void v06() throw();
    virtual void v07() throw();
    virtual void v08() throw();
    virtual void v09() throw();
    virtual void v10() throw();
    virtual void v11() throw();
    virtual void v12() throw();
    virtual void v13() throw();
    virtual void v14() throw();
    virtual void v15() throw();
    virtual void v16() throw();
    virtual void v17() throw();
    virtual void v18() throw();
    virtual void v19() throw();
    virtual void v20() throw();
    virtual void v21() throw();
    virtual void v22() throw();
    virtual void v23() throw();
    virtual void v24() throw();
    virtual void v25() throw();
    virtual void v26() throw();
    virtual void v27() throw();
    virtual void v28() throw();
    virtual void v29() throw();
    virtual void v30() throw();
    virtual void v31() throw();
    virtual void v32() throw();
    virtual void v33() throw();
    virtual void v34() throw();
    virtual void v35() throw();
    virtual void v36() throw();
    virtual WorldExt* GetHkpWorld() throw();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    char unk14;
    char unk15;
    char unk16;
    char unk17;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    void** unk2C;
    unsigned int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    unsigned int unk50;


    bool StepSimulation();
};

// 0x00c910a0  ret 4
// @fnv 0x00c910a0
void FUN_00c910a0(const void*) {
}

// @fnv 0x00c911a0
void FUN_00c911a0()
{
}

extern void (*DAT_00fdf100)(void*);

struct FUN_00c91230_World : hkpWorld {
    void FUN_00c91230(void* param);
};

// @fnv 0x00c91230
void FUN_00c91230_World::FUN_00c91230(void* param) {
    if (m_pModifyConstraintCriticalSection != 0) {
        DAT_00fdf100(m_pModifyConstraintCriticalSection);
    }
}

struct FUN_00c912c0_Class : hkpWorld {
    unsigned int FUN_00c912c0();
};
// @fnv 0x00c912c0
unsigned int FUN_00c912c0_Class::FUN_00c912c0()
{
    volatile unsigned short* markCount = &m_kMultiThreadCheck.m_usMarkedForWrite;
    unsigned char highBit = static_cast<unsigned char>(*markCount >> 15);
    return highBit & 1;
}

struct Comparator {
    virtual void unused_00();
    virtual void unused_01();
    virtual void unused_02();
    virtual void unused_03();
    virtual void unused_04();
    virtual void unused_05();
    virtual void unused_06();
    virtual void unused_07();
    virtual void unused_08();
    virtual void unused_09();
    virtual void unused_0a();
    virtual void unused_0b();
    virtual void unused_0c();
    virtual void unused_0d();
    virtual void unused_0e();
    virtual void unused_0f();
    virtual void unused_10();
    virtual void unused_11();
    virtual void unused_12();
    virtual bool accepts(const void* left, const void* right);
};
struct FilterCore {
    virtual void reserved();
    virtual unsigned char* evaluate(unsigned char* answer, const void* left, const void* right);
};
struct FilterOwner {
    void* unknown_00;
    void* unknown_04;
    FilterCore core;
};
struct Pair {
    const void* left;
    const void* right;
};
struct OpPacket {
    unsigned char opcode;
    const void* left;
    const void* right;
};
struct EventSink {
};
struct FUN_00c913b0_Class {
    void* unknown_00;
    void* unknown_04;
    void* unknown_08;
    void* unknown_0c;
    void* unknown_10;
    void* unknown_14;
    void* unknown_18;
    void* unknown_1c;
    void* unknown_20;
    void* unknown_24;
    void* unknown_28;
    void* unknown_2c;
    void* unknown_30;
    void* unknown_34;
    void* unknown_38;
    void* unknown_3c;
    void* unknown_40;
    void* unknown_44;
    void* unknown_48;
    void* unknown_4c;
    void* unknown_50;
    void* unknown_54;
    Comparator* m_comparator;
    void* unknown_5c;
    void* unknown_60;
    EventSink* m_callback;
    void* unknown_68;
    void* unknown_6c;
    void* unknown_70;
    void* unknown_74;
    void* unknown_78;
    FilterOwner* m_iFilter;
    void* unknown_80;
    void* unknown_84;
    void* unknown_88;
    void* unknown_8c;
    void* unknown_90;
    void* m_pDataAtOffset94;
    void ProcessPair(const void* left, const void* right);
};
// @fnv 0x00c913b0
void FUN_00c913b0_Class::ProcessPair(const void* left, const void* right)
{
    OpPacket command;
    Pair pair;
    if (m_pDataAtOffset94) {
        command.opcode = 0x13;
        command.left = left;
        command.right = right;
        reinterpret_cast<::WorldWithPending *>(this)->FUN_00c91160();
        return;
    }

    const char* a = static_cast<const char*>(left);
    const char* b = static_cast<const char*>(right);
    const void* primaryB = b + 0x24;
    const void* primaryA = a + 0x24;
    if (m_comparator->accepts(primaryA, primaryB)) {
        unsigned char answer;
        const void* secondaryB = b + 0x10;
        const void* secondaryA = a + 0x10;
        if (*m_iFilter->core.evaluate(&answer, secondaryA, secondaryB)) {
            if (!::FindEntryValue((::LinkNode *)(secondaryA), (::LinkNode *)(secondaryB))) {
                pair.left = primaryA;
                pair.right = primaryB;
                reinterpret_cast<::DispatcherCF7080 *>((m_callback))->FUN_00cf7080((::PairCF7080 *)(&pair), 1, (const ::FilterCF7080 *)(::FilterCore *)(m_iFilter ? &m_iFilter->core : 0));
            }
        }
    }
}

struct Sh00c91160 {  };

struct QueuedOp
{
    unsigned char m_ucOperationType;      // +0x0
    int m_p;                  // +0x4
    short m_kPointA;                // +0x8
    unsigned char m_kPointB;        // +0xa
};

struct SimVtbl
{
    void* slot[12];
    void (* invoke)(void*, int, int, void*, int);   // +0x30
};

struct Sim
{
    SimVtbl* m_vtbl;
};

struct WorldQ
{
    char pad0[8];
    Sim* m_pSimulation;                              // +0x08
    char pad_c[0x94 - 0xc];
    int m_iCriticalOperationsLockCount;               // +0x94

    void DispatchOp(int a0, int a1, int a2);
};

// @fnv 0x00c91470
void WorldQ::DispatchOp(int aiArg0, int aiArg1, int aiArg2)
{
    if (m_iCriticalOperationsLockCount)
    {
        QueuedOp op;
        op.m_ucOperationType = 0x17;
        op.m_p = aiArg0;
        op.m_kPointA = (short)aiArg1;
        op.m_kPointB = (unsigned char)aiArg2;
        reinterpret_cast<::WorldWithPending *>((((Sh00c91160*)this)))->FUN_00c91160();
        return;
    }
    Sim* sim = m_pSimulation;
    sim->m_vtbl->invoke(sim, aiArg0, aiArg1, this, aiArg2);
}

class hkpWorldC914;
class hkpMotionC914;


struct hkpCollidableQualityC914 {
};

class hkpEntityC914 {
public:
    virtual void V00() throw();
    virtual void V01() throw();
    virtual void V02() throw();
    virtual void V03() throw();
    virtual hkpMotionC914* getMotion() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkpWorldC914* m_pOwningWorld;
    int m_ulUserData;
    const void* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    hkpMotionC914* m_pMotionState;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_uiUniqueId;
    int m_d8;
    int m_dc;
    hkpCollidableQualityC914 m_e0;
    int m_e4;
    short m_e8;
    unsigned short m_ea;
    unsigned short m_ec;
    short m_ee;
    int m_f0;

};

struct hkWorldOperationBaseC914 {
    unsigned char m_type;
};

struct hkWorldOperationAddEntityC914 : public hkWorldOperationBaseC914 {
    hkpEntityC914* m_pEntity;
    int m_iActivationState;

    hkWorldOperationAddEntityC914() { m_type = 1; }
};

class hkpWorldC914 {
public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int m_98;
    bool m_bBlockExecutingPendingOperations;
    bool m_bBlockExecutingPendingOperationQueues;
    char m_9e;
    char m_9f;
    int m_a0;
    int m_iPendingOperationQueueCount;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    int m_e0;
    int m_e4;
    int m_e8;
    int m_ec;
    int m_f0;
    int m_f4;
    int m_f8;
    int m_fc;
    int m_100;
    int m_uiLastEntityUid;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    int m_138;
    int m_13c;
    int m_140;
    int m_144;
    int m_148;
    int m_14c;
    int m_150;
    int m_154;
    int m_158;
    int m_15c;
    int m_160;
    int m_164;
    int m_168;
    int m_16c;
    int m_170;
    int m_174;
    int m_178;
    int m_17c;
    int m_180;
    int m_184;
    int m_188;
    int m_18c;
    int m_190;
    int m_194;
    int m_198;
    int m_19c;
    int m_1a0;
    int m_1a4;
    int m_1a8;
    int m_1ac;
    int m_1b0;
    int m_1b4;
    int m_1b8;
    int m_1bc;
    int m_1c0;
    int m_1c4;
    int m_1c8;
    int m_1cc;
    int m_1d0;
    int m_1d4;
    int m_1d8;
    int m_1dc;
    int m_1e0;
    int m_1e4;
    int m_1e8;
    int m_1ec;
    int m_1f0;
    int m_1f4;
    int m_1f8;
    int m_1fc;
    int m_200;
    int m_204;
    int m_208;
    int m_20c;
    int m_210;
    int m_214;
    int m_218;
    int m_21c;
    int m_220;
    int m_224;
    int m_228;
    int m_22c;
    int m_230;
    int m_234;
    int m_238;
    int m_23c;
    int m_240;
    int m_244;
    int m_248;
    int m_24c;
    int m_250;
    int m_254;
    int m_258;
    int m_25c;
    int m_260;
    int m_264;
    int m_268;
    int m_26c;
    int m_270;
    int m_274;
    int m_278;
    int m_27c;
    int m_280;
    int m_284;
    int m_288;
    int m_28c;
    int m_290;
    int m_294;
    int m_298;
    int m_29c;
    int m_2a0;
    int m_2a4;
    int m_2a8;
    int m_2ac;
    int m_2b0;
    int m_2b4;
    int m_2b8;
    int m_2bc;
    int m_2c0;
    int m_2c4;
    int m_2c8;
    int m_2cc;
    int m_2d0;
    int m_2d4;
    int m_2d8;
    int m_2dc;
    int m_2e0;
    int m_2e4;
    int m_2e8;
    int m_2ec;
    int m_2f0;
    int m_2f4;
    int m_2f8;
    int m_2fc;
    int m_300;
    char m_304;
    unsigned char m_305;
    unsigned char m_306;
    unsigned char m_307;

    bool areCriticalOperationsLocked() const { return m_iCriticalOperationsLockCount != 0; }
    void lockCriticalOperations() { m_iCriticalOperationsLockCount++; }
    void unlockAndAttemptToExecutePendingOperations()
    {
        m_iCriticalOperationsLockCount--;
        if (m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations) {
            if (m_iPendingOperationCount)
                reinterpret_cast<::FUN_00c91120 *>(this)->ExecutePendingOperations();
            if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount)
                reinterpret_cast<::FUN_00c91140_Class *>(this)->FUN_00c91140();
        }
    }

    void FUN_00c91120() throw();

    hkpEntityC914* FUN_00c914d0(hkpEntityC914* pkEntity, int iInitialActivationState) throw();
};


struct PointerArray {
    void** elements;
    int size;
    __forceinline int Find(void* target) const {
        for(int index=0;index<size;++index) {
            if(elements[index]==target) return index;
        }
        return -1;
    }
};
struct ObjectTable {
    unsigned int unk000;
unsigned int unk004;
unsigned int unk008;
unsigned int unk00c;
unsigned int unk010;
unsigned int unk014;
unsigned int unk018;
unsigned int unk01c;
unsigned int unk020;
unsigned int unk024;
unsigned int unk028;
unsigned int unk02c;
unsigned int unk030;
unsigned int unk034;
unsigned int unk038;
unsigned int unk03c;
unsigned int unk040;
unsigned int unk044;
unsigned int unk048;
unsigned int unk04c;
unsigned int unk050;
unsigned int unk054;
unsigned int unk058;
unsigned int unk05c;
unsigned int unk060;
unsigned int unk064;
unsigned int unk068;
unsigned int unk06c;
unsigned int unk070;
unsigned int unk074;
unsigned int unk078;
unsigned int unk07c;
unsigned int unk080;
unsigned int unk084;
unsigned int unk088;
unsigned int unk08c;
unsigned int unk090;
unsigned int unk094;
unsigned int unk098;
unsigned int unk09c;
unsigned int unk0a0;
unsigned int unk0a4;
unsigned int unk0a8;
unsigned int unk0ac;
unsigned int unk0b0;
unsigned int unk0b4;
unsigned int unk0b8;
unsigned int unk0bc;
unsigned int unk0c0;
unsigned int unk0c4;
unsigned int unk0c8;
unsigned int unk0cc;
unsigned int unk0d0;
unsigned int unk0d4;
unsigned int unk0d8;
unsigned int unk0dc;
unsigned int unk0e0;
unsigned int unk0e4;
unsigned int unk0e8;
unsigned int unk0ec;
unsigned int unk0f0;
unsigned int unk0f4;
unsigned int unk0f8;
unsigned int unk0fc;
unsigned int unk100;
unsigned int unk104;
unsigned int unk108;
unsigned int unk10c;
unsigned int unk110;
unsigned int unk114;
unsigned int unk118;
unsigned int unk11c;
unsigned int unk120;
unsigned int unk124;
unsigned int unk128;
unsigned int unk12c;
unsigned int unk130;
unsigned int unk134;
unsigned int unk138;
unsigned int unk13c;
unsigned int unk140;
unsigned int unk144;
unsigned int unk148;
unsigned int unk14c;
unsigned int unk150;
unsigned int unk154;
    PointerArray pointers;
    void RemovePointer(void* value);
};
// Finds value in the pointers array and clears its slot to null.
// @fnv 0x00c91840
void ObjectTable::RemovePointer(void* value) {
    int index=pointers.Find(value);
    pointers.elements[index]=0;
}

struct SearchArray {
unsigned int unk000;
unsigned int unk004;
unsigned int unk008;
unsigned int unk00c;
unsigned int unk010;
unsigned int unk014;
unsigned int unk018;
unsigned int unk01c;
unsigned int unk020;
unsigned int unk024;
unsigned int unk028;
unsigned int unk02c;
unsigned int unk030;
unsigned int unk034;
unsigned int unk038;
unsigned int unk03c;
unsigned int unk040;
unsigned int unk044;
unsigned int unk048;
unsigned int unk04c;
unsigned int unk050;
unsigned int unk054;
unsigned int unk058;
unsigned int unk05c;
unsigned int unk060;
unsigned int unk064;
unsigned int unk068;
unsigned int unk06c;
unsigned int unk070;
unsigned int unk074;
unsigned int unk078;
unsigned int unk07c;
unsigned int unk080;
unsigned int unk084;
unsigned int unk088;
unsigned int unk08c;
unsigned int unk090;
unsigned int unk094;
unsigned int unk098;
unsigned int unk09c;
unsigned int unk0a0;
unsigned int unk0a4;
unsigned int unk0a8;
unsigned int unk0ac;
unsigned int unk0b0;
unsigned int unk0b4;
unsigned int unk0b8;
unsigned int unk0bc;
unsigned int unk0c0;
unsigned int unk0c4;
unsigned int unk0c8;
unsigned int unk0cc;
unsigned int unk0d0;
unsigned int unk0d4;
unsigned int unk0d8;
unsigned int unk0dc;
unsigned int unk0e0;
unsigned int unk0e4;
unsigned int unk0e8;
unsigned int unk0ec;
unsigned int unk0f0;
unsigned int unk0f4;
unsigned int unk0f8;
unsigned int unk0fc;
unsigned int unk100;
unsigned int unk104;
unsigned int unk108;
unsigned int unk10c;
unsigned int unk110;
unsigned int unk114;
unsigned int unk118;
unsigned int unk11c;
unsigned int unk120;
unsigned int unk124;
unsigned int unk128;
unsigned int unk12c;
unsigned int unk130;
unsigned int unk134;
unsigned int unk138;
unsigned int unk13c;
unsigned int unk140;
unsigned int unk144;
unsigned int unk148;
unsigned int unk14c;
unsigned int unk150;
unsigned int unk154;
unsigned int unk158;
unsigned int unk15c;
unsigned int unk160;
void** items;
int count;
void ClearValue(void* value);
int find(void* value) const { for(int i=0;i<count;++i){if(items[i]==value)return i;}return -1;}
};
// Finds value in items and sets the matching entry to 0.
// @fnv 0x00c918e0
void SearchArray::ClearValue(void* value){items[find(value)]=0;}

struct EntryListNode {
    int* volatile entries;
    int count;
    int findIndex(int value) const {
        int total = count;
        int index = 0;
        if (total > 0) {
            int* cursor = entries;
            do {
                if (*cursor == value)
                    return index;
                ++index;
                ++cursor;
            } while (index < total);
        }
        return -1;
    }
};
struct FUN_00c919d0_Class : hkpWorld {
    void FUN_00c919d0(int value);
};
// @fnv 0x00c919d0
void FUN_00c919d0_Class::FUN_00c919d0(int value) {
    EntryListNode& list=*reinterpret_cast<EntryListNode*>(&m_kIslandPostIntegrateListeners);
    list.entries[list.findIndex(value)]=0;
}

struct CD22Registry {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5();
    int m_refs;
    CD22Registry* m_inner;
    int FUN_00c91ba0();
};

// @fnv 0x00c91ba0
int CD22Registry::FUN_00c91ba0()
{
    reinterpret_cast<::FUN_00c91180_Class *>(this)->IncrementCounter();
    int r = m_inner->v5();
    reinterpret_cast<::FUN_00c91190_Class *>(this)->FUN_00c91190();
    return r;
}

struct hkShapeC927 {
    unsigned short m_type;
    unsigned short unk02;
    int unk04[4];
    hkShapeC927* m_pChildAtom;
};

struct hkRecordC927 {
    void* m_object;
    int unk04[2];
    hkShapeC927* m_pCollisionShape;
    int unk10[8];
};

struct hkRecordListC927 {
    hkRecordC927* m_data;
    unsigned short m_iElementCount;
};

struct hkEntityC927 {
    char unk00[0xac];
    hkRecordListC927 m_records;
};

struct hkWorldC927 {
    int unk00[0x12];
    hkEntityC927** m_kActorEntries;
    int m_iActorEntryCount;
};

class hkSetC927 {
public:
};

// @fnv 0x00c927f0
void __cdecl FUN_00c927f0(hkWorldC927* world, hkSetC927* set)
{
    for (int i = 0; i < world->m_iActorEntryCount; i++) {
        hkRecordListC927* list = &world->m_kActorEntries[i]->m_records;
        for (int j = 0; j < list->m_iElementCount; j++) {
            hkRecordC927& rec = list->m_data[j];
            const hkShapeC927* shape = rec.m_pCollisionShape;
            while (shape->m_type >= 0x17)
                shape = shape->m_pChildAtom;
            if (shape->m_type != 0x16)
                reinterpret_cast<::hkOwnerXd06540 *>((set))->FUN_00d06540((::hkShapeXd06540 *)(rec.m_object));
        }
    }
}

struct hkArrayRaw { void** m_data; int m_iElementCount; int m_iCapacityState; };


struct PendingOps { 
    void* m_vtbl; void* m_04; void* m_08; void* m_0c; 
    hkArrayRaw m_10; hkArrayRaw m_1c;
};
struct HandlerRegistration { void* data; void* other; HandlerRegistration* next; };
struct WorldSave {
    void* m_vtbl; unsigned short m_usMemSizeAndFlags; short m_sReferenceCount;
    void* m_pSimulation; unsigned int m_unknown0c;
    hkVector4 m_kGravity;
    void* m_pFixedIsland; void* m_pFixedRigidBody;
    hkArrayRaw m_kActiveSimulationIslands;
    hkArrayRaw m_kInactiveSimulationIslands;
    hkArrayRaw m_kDirtySimulationIslands;
    void* m_pMaintenanceManager; void* m_pMemoryWatchDog;
    unsigned char m_bAssertOnRunningOutOfSolverMemory;
    void* m_pJobSemaphore; void* m_pKdTreeManager;
    unsigned char m_bUseKdTree;
    void* m_pBroadPhaseDispatcher; void* m_pPhantomBroadPhaseListener;
    void* m_pEntityEntityBroadPhaseListener; void* m_pBroadPhaseBorderListener;
    void* m_pMultithreadedSimulationJobData;
    void* m_pCollisionInput; void* m_pCollisionFilter; void* m_pDispatcher;
    void* m_pConvexListCollisionFilter; PendingOps* m_pPendingOperations;
    int m_iPendingOperationCount; int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount; int m_iCriticalOperationsLockCountForPhantoms;
    unsigned char m_bBlockExecutingPendingOperations; unsigned char m_bBlockExecutingPendingOperationQueues;
    HandlerRegistration* m_pPendingOperationQueues; int m_iPendingOperationQueueCount;
    hkMultiThreadCheck m_kMultiThreadCheck;
    unsigned char m_bProcessActionsInSingleThread;
    unsigned char m_bAllowUnconstrainedIslandJob;
    unsigned int m_uiMinDesiredIslandSize;
    void* m_pModifyConstraintCriticalSection; int m_iIsLocked;
    void* m_pIslandDirtyListCriticalSection; void* m_pPropertyMasterLock;
    unsigned char m_bWantSimulationIslands;
    float m_fSnapCollisionToConvexEdgeThreshold; float m_fSnapCollisionToConcaveEdgeThreshold;
    unsigned char m_bEnableToiWeldRejection; unsigned char m_bWantDeactivation;
    unsigned char m_bActivateOnBodyTransformChange;
    float m_fDeactivationReferenceDistance; float m_fToiCollisionResponseRotateNormal;
    int m_iMaxSectorsPerMidphaseTask; unsigned char m_bProcessToisMultithreaded;
    int m_iMaxSectorsPerNarrowphaseTask; int m_iMaxEntriesPerMidphaseToiTask;
    int m_iMaxEntriesPerNarrowphaseToiTask;
    float m_fSimplifiedToiPenetrationThreshold; float m_fToiPenetrationThreshold;
    float m_fHigherToiPenetrationThreshold; float m_fForcedToiPenetrationThreshold;
    unsigned int m_uiLastEntityUid; unsigned int m_uiLastIslandUid; unsigned int m_uiLastConstraintUid;
    hkArrayRaw m_kPhantoms; hkArrayRaw m_kActionListeners; hkArrayRaw m_kEntityListenerArray;
    hkArrayRaw m_kPhantomListeners; hkArrayRaw m_kConstraintListeners; hkArrayRaw m_kWorldDeletionListeners;
    hkArrayRaw m_kIslandActivationListeners; hkArrayRaw m_kWorldPostSimulationListeners;
    hkArrayRaw m_kWorldPostIntegrateListeners; hkArrayRaw m_kWorldPostCollideListeners;
    hkArrayRaw m_kIslandPostIntegrateListeners; hkArrayRaw m_kIslandPostCollideListeners;
    hkArrayRaw m_kContactListeners; hkArrayRaw m_kContactImpulseLimitBreachedListeners;
    void* m_pViolatedConstraintArray; void* m_pBroadPhaseBorder;
    void FUN_00c92db0(struct ObjectWriter* writer, void* unused);
};
struct ObjectWriter {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void WriteValue(char* name, void* value, int flags);
    virtual void slot10();
    virtual void WriteArray(int kind, char* name, void* array, int length, int bounded);
    virtual void OpenBlock(char* name);
    virtual void CloseBlock();
    int m_unknown04;
    void* m_reference08;
    int m_unknown0c;
    unsigned char m_writeAll10;
};
extern char str_010c6700;
extern char str_0109c938;
extern char str_010c66f0;
extern char str_010c66e4;
extern char str_010c66d8;
extern char str_010c41a4;
extern char str_010c66b8;
extern char str_010c6698;
extern char str_010c6684;
extern char str_010c6664;
extern char str_010c664c;
extern char str_010c6630;
extern char str_010c6624;
extern char str_010c6618;
extern char str_010c660c;
extern char str_010c6600;
extern char str_010c65f8;
extern char str_010c65e8;
extern char str_010c65d8;
extern char str_010c65c4;
extern char str_010c65a4;
extern char str_010c6598;
extern char str_010c6580;
extern char str_010c6578;
extern char str_010c6564;
extern char str_010c6558;
extern char str_010c654c;
extern char str_010c6540;
extern char str_010c6534;
extern char str_010c6524;
extern char str_010c6514;
extern char str_010c6504;
extern char str_010c64f4;
extern char str_010c64e4;
extern char str_010c64d4;
extern char str_010c64c8;
static __forceinline void SaveArray(ObjectWriter* writer,hkArrayRaw& array,char* name,unsigned int stride) {
    if ((array.m_iCapacityState & 0x80000000u) == 0 || writer->m_writeAll10) {
        void* ptr = array.m_data;
         unsigned int capacity = (array.m_iCapacityState & 0x3fffffff);
         int bounded = ::fnv_00d06f80::FUN_00d06f80((const char *)(ptr), capacity * stride);
        writer->WriteArray(3, name, array.m_data, array.m_iElementCount * stride, bounded);
    }
}
static __forceinline void SaveBlob(ObjectWriter* writer,char* name,void* address,unsigned int length) {
    reinterpret_cast<::FUN_00d06fb0_cls *>((writer))->DispatchWithMode(name,address,length,0);
}

// Serializes the WorldSave to the writer: writes arrays, blobs and nested blocks for its members, then clears the writer reference.
// @fnv 0x00c92db0
void WorldSave::FUN_00c92db0(ObjectWriter* writer,void* unused) {
    writer->m_reference08 = m_pCollisionInput;
    SaveArray(writer, m_kActiveSimulationIslands, &str_010c6700, 4);
    for (int i = m_kActiveSimulationIslands.m_iElementCount - 1; i >= 0; --i) writer->WriteValue(&str_0109c938, m_kActiveSimulationIslands.m_data[i], 0);
    SaveArray(writer, m_kInactiveSimulationIslands, &str_010c66f0, 4);
    for (int i = m_kInactiveSimulationIslands.m_iElementCount - 1; i >= 0; --i) writer->WriteValue(&str_010c66e4, m_kInactiveSimulationIslands.m_data[i], 0);
    writer->WriteValue(&str_010c6084, reinterpret_cast<void*>(m_pFixedIsland), 0);
    SaveArray(writer, m_kPhantoms, &str_010c66d8, 4);
    for (int i = 0; i < m_kPhantoms.m_iElementCount; ++i) writer->WriteValue(&str_010c41a4, m_kPhantoms.m_data[i], 0);
    if (m_pModifyConstraintCriticalSection) {    SaveBlob(writer,&str_010c66b8, reinterpret_cast<void*>(m_pModifyConstraintCriticalSection), 0x18);}
    SaveBlob(writer,&str_010c6698, reinterpret_cast<void*>(m_pIslandDirtyListCriticalSection), 0x18);
    if (m_pPropertyMasterLock) {    SaveBlob(writer,&str_010c6684, reinterpret_cast<void*>(m_pPropertyMasterLock), 0x18);}
    SaveBlob(writer,&str_010c6664, reinterpret_cast<void*>(m_pMultithreadedSimulationJobData), 0x120);
    if (m_pPendingOperationQueues) {
       HandlerRegistration* position = m_pPendingOperationQueues;
       do {
    SaveBlob(writer,&str_010c664c, reinterpret_cast<void*>(m_pPendingOperationQueues), 0x10);
          if (m_pPendingOperationQueues->data) {
              hkArrayRaw* batch = static_cast<hkArrayRaw*>(m_pPendingOperationQueues->data);
    SaveArray(writer, (*batch), &str_010c6630, 20);
          }
          position = position->next;
       } while (position);
    }
    writer->OpenBlock(&str_010c6624);
    writer->WriteValue(&str_010c6618, reinterpret_cast<void*>(m_pSimulation), 0);
    SaveArray(writer, m_kDirtySimulationIslands, &str_010c660c, 4);
    writer->WriteValue(&str_010c6600, reinterpret_cast<void*>(m_pMaintenanceManager), 0);
    SaveBlob(writer,&str_010c65f8, reinterpret_cast<void*>(m_pPendingOperations), 0x28);
    writer->OpenBlock(&str_010c65f8);
    SaveArray(writer, m_pPendingOperations->m_10, &str_010c65e8, 20);
    SaveArray(writer, m_pPendingOperations->m_1c, &str_010c65d8, 16);
    writer->CloseBlock();
    writer->WriteValue(&str_010c65c4, reinterpret_cast<void*>(m_pBroadPhaseBorder), 0);
    writer->OpenBlock(&str_010c65bc);
    writer->WriteValue(&str_010c65b0, reinterpret_cast<void*>(m_pJobSemaphore), 0);
    SaveBlob(writer,&str_010c65a4, reinterpret_cast<void*>(m_pBroadPhaseDispatcher), 0x10c);
    SaveBlob(writer,&str_010c65a4, reinterpret_cast<void*>(m_pEntityEntityBroadPhaseListener), 0x10);
    SaveBlob(writer,&str_010c65a4, reinterpret_cast<void*>(m_pPhantomBroadPhaseListener), 0xc);
    SaveBlob(writer,&str_010c65a4, reinterpret_cast<void*>(m_pBroadPhaseBorderListener), 0xc);
    SaveBlob(writer,&str_010c6598, reinterpret_cast<void*>(m_pCollisionInput), 0x80);
    if (m_pCollisionInput) {
      SaveBlob(writer,&str_010c6580,static_cast<WorldSaveCollisionInput*>(m_pCollisionInput)->m_config,0x10);
    }
    writer->WriteValue(&str_010c6578, reinterpret_cast<void*>(m_pCollisionFilter), 0);
    writer->WriteValue(&str_010c6564, reinterpret_cast<void*>(m_pConvexListCollisionFilter), 0);
    writer->WriteValue(&str_010c6558, reinterpret_cast<void*>(m_pDispatcher), 0);
    writer->CloseBlock(); writer->CloseBlock();
    writer->OpenBlock(&str_010c654c);
    SaveArray(writer, m_kEntityListenerArray, &str_010c6540, 4);
    SaveArray(writer, m_kPhantomListeners, &str_010c6534, 4);
    SaveArray(writer, m_kConstraintListeners, &str_010c6524, 4);
    SaveArray(writer, m_kWorldDeletionListeners, &str_010c6514, 4);
    SaveArray(writer, m_kIslandActivationListeners, &str_010c6504, 4);
    SaveArray(writer, m_kWorldPostSimulationListeners, &str_010c64f4, 4);
    SaveArray(writer, m_kWorldPostIntegrateListeners, &str_010c64e4, 4);
    SaveArray(writer, m_kWorldPostCollideListeners, &str_010c64d4, 4);
    SaveArray(writer, m_kIslandPostIntegrateListeners, &str_010c64e4, 4);
    SaveArray(writer, m_kContactListeners, &str_010c64c8, 4);
    writer->CloseBlock();
    writer->m_reference08 = 0;
}

struct WorldWatchDogHolder : hkpWorld {
    void* FUN_00c93570();
};

// @fnv 0x00c93570
void* WorldWatchDogHolder::FUN_00c93570() {
    return m_pMemoryWatchDog;
}


class hkpPhantom;




struct PendingOperation {
    unsigned char m_type;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    hkpPhantom* m_pPhantom;
};

class hkpPhantom : public hkReferencedObject {
  public:
    hkpWorld* m_pOwningWorld;
    int unk0C;
    int unk10;
    int unk14;
    void* unk18;

    virtual ~hkpPhantom();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0C();
    virtual void* vfunc10();
};

struct FUN_00c936a0_World : hkpWorld {
    void FUN_00c91120();

    hkpPhantom* FUN_00c936a0(hkpPhantom* phantom);
};

// @fnv 0x00c936a0
hkpPhantom* FUN_00c936a0_World::FUN_00c936a0(hkpPhantom* phantom)
{
    if (m_iCriticalOperationsLockCount + m_iCriticalOperationsLockCountForPhantoms) {
        PendingOperation op;
        op.m_type = 0xD;
        op.m_pPhantom = phantom;
        reinterpret_cast<::WorldWithPending *>(this)->FUN_00c91160();
        return 0;
    }

    m_iCriticalOperationsLockCount++;

    if (!phantom->unk18) {
        phantom->unk18 = phantom->vfunc10();
    }

    phantom->m_pOwningWorld = this;
    reinterpret_cast<::FUN_00c90510_class *>((((RefObj*)phantom)))->FUN_00c90510();

    hkArray<hkpPhantom*>& phantoms = m_kPhantoms;
    hkMemoryRouter* mem = &hkMemoryRouter::getInstance();
    if (phantoms.m_iElementCount == (phantoms.m_iCapacityState & 0x3FFFFFFF)) {
        ::ResizeAudioStream((::AudioAllocator *)(mem->m_heap), (::AudioStream *)(void *)(&phantoms), 4);
    }

    void* p = phantoms.m_data + phantoms.m_iElementCount;
    __assume(p != 0);
    ::new (p) hkpPhantom*(phantom);
    phantoms.m_iElementCount++;

    ::fnv_00cb5b10::QueryEntityIntoBuffer((::fnv_00cb5b10::WorldRec *)(::hkpWorld *)(this), (::fnv_00cb5b10::EntityRec *)(phantom));
    ::fnv_00d00780::NotifyPhantomAdded((::fnv_00d00780::World833 *)(::hkpWorld *)(this), (::fnv_00d00780::hkpPhantom *)(phantom));
    reinterpret_cast<::PhantomCls *>((phantom))->FUN_00d07b90();

    if (--m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations) {
        if (m_iPendingOperationCount) {
            reinterpret_cast<::FUN_00c91120 *>(this)->ExecutePendingOperations();
        }
        if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount) {
            reinterpret_cast<::FUN_00c91140_Class *>(this)->FUN_00c91140();
        }
    }

    return phantom;
}

namespace fnv_00c937e0 {




template <class T>
__forceinline void constructWithCopyXc937e0(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T>
class hkArrayXc937e0 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void AddBack(const T& t)
    {
        hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(&kAlloc), (::AudioStream *)(void *)(this), sizeof(T));
        constructWithCopyXc937e0(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

class hkpEntityListenerXc937e0;

class hkpWorldXc937e0 {
public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    hkArrayXc937e0<void*> m_kEntityListenerArray;

    void FUN_00c937e0(hkpEntityListenerXc937e0* pkListener);
};

// Appends pkListener to the world's entity listener array, growing it if needed.
// @fnv 0x00c937e0
void hkpWorldXc937e0::FUN_00c937e0(hkpEntityListenerXc937e0* pkListener)
{
    m_kEntityListenerArray.AddBack(pkListener);
}
}  // namespace fnv_00c937e0

namespace fnv_00c93820 {




template <class T>
__forceinline void constructWithCopyC938(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T>
class hkArrayC938 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void AddBack(const T& t)
    {
        hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(&kAlloc), (::AudioStream *)(void *)(this), sizeof(T));
        constructWithCopyC938(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

class hkpEntityListenerC938;

class hkpWorldC938 {
public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    hkArrayC938<void*> m_kEntityListenerArray;

    void FUN_00c93820(hkpEntityListenerC938* pkListener);
};

// @fnv 0x00c93820
void hkpWorldC938::FUN_00c93820(hkpEntityListenerC938* pkListener)
{
    m_kEntityListenerArray.AddBack(pkListener);
}
}  // namespace fnv_00c93820

namespace fnv_00c93860 {




template <class T>
__forceinline void constructWithCopyXc93860(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T>
class hkArrayXc93860 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void AddBack(const T& t)
    {
        hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(&kAlloc), (::AudioStream *)(void *)(this), sizeof(T));
        constructWithCopyXc93860(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

class hkpEntityListenerXc93860;

class hkpWorldXc93860 {
public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    hkArrayXc93860<void*> m_kEntityListenerArray;

    void FUN_00c93860(hkpEntityListenerXc93860* pkListener);
};

// @fnv 0x00c93860
void hkpWorldXc93860::FUN_00c93860(hkpEntityListenerXc93860* pkListener)
{
    m_kEntityListenerArray.AddBack(pkListener);
}
}  // namespace fnv_00c93860

namespace fnv_00c938a0 {




template <class T>
__forceinline void constructWithCopyXc938a0(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T>
class hkArrayXc938a0 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void AddBack(const T& t)
    {
        hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(&kAlloc), (::AudioStream *)(void *)(this), sizeof(T));
        constructWithCopyXc938a0(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

class hkpEntityListenerXc938a0;

class hkpWorldXc938a0 {
public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    hkArrayXc938a0<void*> m_kEntityListenerArray;

    void FUN_00c938a0(hkpEntityListenerXc938a0* pkListener);
};

// Appends pkListener to the world's entity listener array, growing it if needed.
// @fnv 0x00c938a0
void hkpWorldXc938a0::FUN_00c938a0(hkpEntityListenerXc938a0* pkListener)
{
    m_kEntityListenerArray.AddBack(pkListener);
}
}  // namespace fnv_00c938a0

namespace fnv_00c938e0 {




template <class T>
__forceinline void constructWithCopyC938(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T>
class hkArrayC938 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void AddBack(const T& t)
    {
        hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(&kAlloc), (::AudioStream *)(void *)(this), sizeof(T));
        constructWithCopyC938(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

class hkpWorldPostCollideListenerC938;

class hkpWorldC938 {
public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    hkArrayC938<void*> m_kEntityListenerArray;
    hkArrayC938<void*> m_kPhantomListeners;
    hkArrayC938<void*> m_kConstraintListeners;
    hkArrayC938<void*> m_kWorldDeletionListeners;
    hkArrayC938<void*> m_kIslandActivationListeners;
    hkArrayC938<void*> m_kWorldPostSimulationListeners;
    hkArrayC938<void*> m_kWorldPostIntegrateListeners;
    hkArrayC938<void*> m_kWorldPostCollideListeners;

    void AddPostCollideListener(hkpWorldPostCollideListenerC938* pkListener);
};

// Appends pkListener to the world's post-collide listener array.
// @fnv 0x00c938e0
void hkpWorldC938::AddPostCollideListener(hkpWorldPostCollideListenerC938* pkListener)
{
    m_kWorldPostCollideListeners.AddBack(pkListener);
}
}  // namespace fnv_00c938e0

namespace fnv_00c93920 {




template <class T>
__forceinline void constructWithCopyXc93920(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T>
class hkArrayXc93920 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void AddBack(const T& t)
    {
        hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(&kAlloc), (::AudioStream *)(void *)(this), sizeof(T));
        constructWithCopyXc93920(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

class hkpEntityListenerXc93920;

class hkpWorldXc93920 {
public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    hkArrayXc93920<void*> m_kEntityListenerArray;

    void FUN_00c93920(hkpEntityListenerXc93920* pkListener);
};

// Appends pkListener to the world's entity listener array, growing it if needed.
// @fnv 0x00c93920
void hkpWorldXc93920::FUN_00c93920(hkpEntityListenerXc93920* pkListener)
{
    m_kEntityListenerArray.AddBack(pkListener);
}
}  // namespace fnv_00c93920

namespace fnv_00c93960 {




template <class T>
__forceinline void constructWithCopyC939(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T>
class hkArrayC939 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void AddBack(const T& t)
    {
        hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(&kAlloc), (::AudioStream *)(void *)(this), sizeof(T));
        constructWithCopyC939(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

class hkpWorldPostIntegrateListenerC939;

class hkpWorldC939 {
public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    hkArrayC939<void*> m_kEntityListenerArray;
    hkArrayC939<void*> m_kPhantomListeners;
    hkArrayC939<void*> m_kConstraintListeners;
    hkArrayC939<void*> m_kWorldDeletionListeners;
    hkArrayC939<void*> m_kIslandActivationListeners;
    hkArrayC939<void*> m_kWorldPostSimulationListeners;
    hkArrayC939<void*> m_kWorldPostIntegrateListeners;

    void FUN_00c93960(hkpWorldPostIntegrateListenerC939* pkListener);
};

// Appends pkListener to the world's post-integrate listener array.
// @fnv 0x00c93960
void hkpWorldC939::FUN_00c93960(hkpWorldPostIntegrateListenerC939* pkListener)
{
    m_kWorldPostIntegrateListeners.AddBack(pkListener);
}
}  // namespace fnv_00c93960

namespace fnv_00c939e0 {




template <class T>
__forceinline void constructWithCopyC939(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T>
class hkArrayC939 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void AddBack(const T& t)
    {
        hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(&kAlloc), (::AudioStream *)(void *)(this), sizeof(T));
        constructWithCopyC939(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

class hkpIslandPostIntegrateListenerC939;

class hkpWorldC939 {
public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    hkArrayC939<void*> m_kEntityListenerArray;
    hkArrayC939<void*> m_kPhantomListeners;
    hkArrayC939<void*> m_kConstraintListeners;
    hkArrayC939<void*> m_kWorldDeletionListeners;
    hkArrayC939<void*> m_kIslandActivationListeners;
    hkArrayC939<void*> m_kWorldPostSimulationListeners;
    hkArrayC939<void*> m_kWorldPostIntegrateListeners;
    hkArrayC939<void*> m_kWorldPostCollideListeners;
    hkArrayC939<void*> m_kIslandPostIntegrateListeners;

    void FUN_00c939e0(hkpIslandPostIntegrateListenerC939* pkListener);
};

// Appends pkListener to the world's post-integrate listener array.
// @fnv 0x00c939e0
void hkpWorldC939::FUN_00c939e0(hkpIslandPostIntegrateListenerC939* pkListener)
{
    m_kIslandPostIntegrateListeners.AddBack(pkListener);
}
}  // namespace fnv_00c939e0

namespace fnv_00c93a20 {




template <class T>
__forceinline void constructWithCopyXc93a20(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T>
class hkArrayXc93a20 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void AddBack(const T& t)
    {
        hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(&kAlloc), (::AudioStream *)(void *)(this), sizeof(T));
        constructWithCopyXc93a20(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

class hkpEntityListenerXc93a20;

class hkpWorldXc93a20 {
public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    hkArrayXc93a20<void*> m_kEntityListenerArray;

    void FUN_00c93a20(hkpEntityListenerXc93a20* pkListener);
};

// Appends pkListener to the world's entity listener array, growing it if it is full.
// @fnv 0x00c93a20
void hkpWorldXc93a20::FUN_00c93a20(hkpEntityListenerXc93a20* pkListener)
{
    m_kEntityListenerArray.AddBack(pkListener);
}
}  // namespace fnv_00c93a20

struct FUN_00c93ae0_Vt {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c(void* p, int n);
    virtual void slot10();
};

struct FUN_00c93ae0_Dtm {
};

struct FUN_00c93ae0_Cb {
    int FUN_00c92d70(void* p, float f);
};

struct FUN_00c93ae0_Pair {
};

struct FUN_00c93ae0_class {
    void FUN_00c93ae0(void* p1, void* p2, float f);
};

// Calls FUN_00c92d70 on this with p1 and f; if it returns 0, invokes slot0c(p1, 11), FUN_00d051b0 on p1, slot10, then FUN_00c91c00(p1, p2).
// @fnv 0x00c93ae0
void FUN_00c93ae0_class::FUN_00c93ae0(void* p1, void* p2, float fValue) {
    if (reinterpret_cast<FUN_00c93ae0_Cb*>(this)->FUN_00c92d70(p1, fValue)) {
        return;
    }
    FUN_00c93ae0_Vt* o = reinterpret_cast<FUN_00c93ae0_Vt*>(p2);
    o->slot0c(p1, 11);
    reinterpret_cast<::Dispatcher *>((reinterpret_cast<FUN_00c93ae0_Dtm*>(p1)))->FUN_00d051b0();
    o->slot10();
    reinterpret_cast<::WorldFinishEntryC91C *>((reinterpret_cast<FUN_00c93ae0_Pair*>(this)))->FUN_00c91c00(p1, p2);
}

template <class T>
struct hkArrayC93D {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayC93D() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
};

struct hkMultiThreadCheckC93D {
    hkUint32 m_uiThreadId;
    hkUint16 m_usMarkedForWrite;
    hkUint16 m_usMarkCount;

    hkMultiThreadCheckC93D() throw() : m_uiThreadId(0xfffffff1), m_usMarkedForWrite(0x8000) {}
};

class hkReferencedObjectC93D {
public:
    virtual void CalcContentStatistics() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    hkReferencedObjectC93D() throw() : m_sReferenceCount(1) {}
};

class FUN_00c93d10 : public hkReferencedObjectC93D {
public:
    void* m_pSimulation;
    char m_padC[0x4];
    hkVector4 m_kGravity;
    void* m_pFixedIsland;
    void* m_pFixedRigidBody;
    hkArrayC93D<void*> m_kActiveSimulationIslands;
    hkArrayC93D<void*> m_kInactiveSimulationIslands;
    hkArrayC93D<void*> m_kDirtySimulationIslands;
    void* m_pMaintenanceManager;
    void* m_pMemoryWatchDog;
    char m_pad54[0x54];
    hkMultiThreadCheckC93D m_kMultiThreadCheck;
    char m_padB0[0x6c];
    hkArrayC93D<void*> m_kPhantoms;
    hkArrayC93D<void*> m_kActionListeners;
    hkArrayC93D<void*> m_kEntityListenerArray;
    hkArrayC93D<void*> m_kPhantomListeners;
    hkArrayC93D<void*> m_kConstraintListeners;
    hkArrayC93D<void*> m_kWorldDeletionListeners;
    hkArrayC93D<void*> m_kIslandActivationListeners;
    hkArrayC93D<void*> m_kWorldPostSimulationListeners;
    hkArrayC93D<void*> m_kWorldPostIntegrateListeners;
    hkArrayC93D<void*> m_kWorldPostCollideListeners;
    hkArrayC93D<void*> m_kIslandPostIntegrateListeners;
    hkArrayC93D<void*> m_kIslandPostCollideListeners;
    hkArrayC93D<void*> m_kContactListeners;

    FUN_00c93d10(int iUnused) throw();
    virtual void CalcContentStatistics() throw();
};

// Initializes the object by setting the pointer member at offset 0x50 to null.
// @fnv 0x00c93d10
FUN_00c93d10::FUN_00c93d10(int iUnused) throw()
    : m_pMemoryWatchDog(0)
{
}

namespace fnv_00c976a0 {



template <typename T>
struct hkArrayC976 {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const { return m_iElementCount; }
    T& operator[](int i) { return m_data[i]; }
    void _clearAndDeallocate(hkMemoryAllocator& kAlloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<T>(m_data, m_iCapacityState & 0x3fffffff);
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    ~hkArrayC976() throw() { _clearAndDeallocate(hkMemoryRouter::getInstance().heap()); }
};

template <typename T, int N>
struct hkInplaceArrayC976 : public hkArrayC976<T> {
    T m_kStorage[N];
    hkInplaceArrayC976() throw()
    {
        this->m_data = m_kStorage;
        this->m_iElementCount = 0;
        this->m_iCapacityState = N | 0x80000000;
    }
};

template <typename T>
struct hkSmallArrayC976 {
    T* m_data;
    hkUint16 m_iElementCount;
    hkUint16 m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; ++i) {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    void removeAt(int iIndex)
    {
        m_iElementCount--;
        m_data[iIndex] = m_data[m_iElementCount];
    }
};

class hkpEntityC976;
class hkpActionC976;

class hkpSimulationIslandC976 {
public:
    char m_acUnk00[0x20];
    hkUint16 m_usStorageIndex;
    char m_acUnk22[0x3];
    hkUint8 m_bSplitCheckRequested : 1;
    hkUint8 m_isSparse : 1;

    bool isFixed() const { return m_usStorageIndex == 0xffff; }
};

class hkpEntityC976 {
public:
    char m_acUnk00[0xcc];
    hkpSimulationIslandC976* m_pSimulationIsland;
    char m_acUnkD0[0x138];
    hkSmallArrayC976<hkpActionC976*> m_ppActions;

    hkpSimulationIslandC976* GetSimulationIsland() const { return m_pSimulationIsland; }
};

class hkpActionC976 {
public:
    virtual ~hkpActionC976() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void GetEntities(hkArrayC976<hkpEntityC976*>& kEntitiesOut) throw();
    int m_iUnk04;
    void* m_pOwningWorld;
    hkpSimulationIslandC976* m_pCurrentSimulationIsland;

    hkpSimulationIslandC976* GetSimulationIsland() const { return m_pCurrentSimulationIsland; }
};

// @fnv 0x00c976a0
void RemoveActionFromEntity(hkpActionC976* pkAction, hkpEntityC976* pkEntity) throw()
{
    pkEntity->m_ppActions.removeAt(pkEntity->m_ppActions.indexOf(pkAction));
    hkpSimulationIslandC976* pkIsland = pkEntity->GetSimulationIsland();
    pkIsland->m_bSplitCheckRequested = true;
    pkIsland->m_isSparse = false;

    hkInplaceArrayC976<hkpEntityC976*, 4> kEntities;
    pkAction->GetEntities(kEntities);

    hkpSimulationIslandC976* pkNewIsland = 0;
    for (int i = 0; i < kEntities.GetLogicalSize(); i++) {
        if (kEntities[i] != pkEntity) {
            pkNewIsland = kEntities[i]->GetSimulationIsland();
            if (!pkNewIsland->isFixed())
                break;
        }
    }
    if (pkNewIsland != pkAction->GetSimulationIsland()) {
        reinterpret_cast<::SaveBuffer *>((pkAction->GetSimulationIsland()))->RemoveEntry((::FUN_00d07130Arg *)(pkAction));
        reinterpret_cast<::FUN_00d07470_cls *>((pkNewIsland))->AddItem((::ListItem *)(pkAction));
    }
}
}  // namespace fnv_00c976a0

struct SystemObject {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    void* owner;
    void* attachment;
};
struct ActiveFlag {
    char value;
    operator bool() const { return value != 0; }
};
struct PhysicsSystem {
    unsigned int unk00;
    unsigned int unk04;
    hkArray<void*> entities;
    hkArray<SystemObject*> constraints;
    hkArray<void*> actions;
    hkArray<void*> phantoms;
    unsigned int unk38;
    unsigned int unk3c;
    ActiveFlag active;
    ActiveFlag isActive() const { return active; }
};
inline int findNull(const hkArray<void*>& values) {
    for (int i = 0; i < values.m_iElementCount; ++i) {
        if (values.m_data[i] == 0)
            return i;
    }
    return -1;
}
struct SystemWorld : hkpWorld {
    void FUN_00c954e0(void**, int);
    void FUN_00c97f80(PhysicsSystem* system);
};
class hkpConstraintInstanceC980;
class hkpActionC980;
class hkpRigidBodyC980;
class hkpEntityC980;
class hkpPhantomC980;

template <class T>
struct hkArrayC980 {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const { return m_iElementCount; }
    const T& operator[](int i) const { return m_data[i]; }
    const T* begin() const { return m_data; }
    int indexOf(const T& t, int startIdx = 0, int endIdx = -1) const
    {
        if (endIdx < 0)
            endIdx = m_iElementCount;
        for (int i = startIdx; i < endIdx; ++i) {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};

struct hkBoolRetC980 {
    char m_cBooleanValue;
    hkBoolRetC980() throw() {}
};

class hkpPhysicsSystemC980 {
public:
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    hkArrayC980<hkpRigidBodyC980*> m_ppRigidBodies;
    hkArrayC980<hkpConstraintInstanceC980*> m_ppConstraints;
    hkArrayC980<hkpActionC980*> m_ppActions;
    hkArrayC980<hkpPhantomC980*> m_kPhantoms;

    const hkArrayC980<hkpRigidBodyC980*>& getRigidBodies() const { return m_ppRigidBodies; }
    const hkArrayC980<hkpConstraintInstanceC980*>& getConstraints() const { return m_ppConstraints; }
    const hkArrayC980<hkpActionC980*>& getActions() const { return m_ppActions; }
    const hkArrayC980<hkpPhantomC980*>& getPhantomArray() const { return m_kPhantoms; }
};

class hkpWorldC980 {
public:

    void FUN_00c980d0(const hkpPhysicsSystemC980* pkSys) throw();
};

namespace fnv_00c98260 {



class hkReferencedObjectC982 {
public:
    virtual ~hkReferencedObjectC982() throw() {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        hkMemoryRouter::getInstance().heap().blockFree(p, static_cast<hkReferencedObjectC982*>(p)->m_usMemSizeAndFlags);
    }
};

class hkPrimaryC982 : public hkReferencedObjectC982 {
};

class hkSecondaryC982 : public hkReferencedObjectC982 {
};

class hkListenerPairC982 : public hkPrimaryC982, public hkSecondaryC982 {
public:
    hkListenerPairC982* DestroyAndMaybeFree(unsigned int uiFlags) throw();
};

// Destroys the object, then frees it via hkPrimaryC982::operator delete when uiFlags has bit 0 set, and returns this.
// @fnv 0x00c98260
hkListenerPairC982* hkListenerPairC982::DestroyAndMaybeFree(unsigned int uiFlags) throw()
{
    this->hkListenerPairC982::~hkListenerPairC982();
    if (uiFlags & 1)
        ::operator delete(this);
    return this;
}
}  // namespace fnv_00c98260

namespace fnv_00c982e0 {



class FUN_00cfa860 {
public:
    virtual void V0() throw();
    ~FUN_00cfa860() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        hkMemoryRouter::getInstance().heap().blockFree(p, static_cast<FUN_00cfa860*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00cfa860* FUN_00c982e0(unsigned int uiFlags) throw();
};

// Runs the destructor, then frees the object through operator delete when bit 0 of uiFlags is set, and returns this.
// @fnv 0x00c982e0
FUN_00cfa860* FUN_00cfa860::FUN_00c982e0(unsigned int uiFlags) throw()
{
    reinterpret_cast<::FUN_00cfa860 *>((this))->::FUN_00cfa860::~FUN_00cfa860();
    if (uiFlags & 1)
        FUN_00cfa860::operator delete(this);
    return this;
}
}  // namespace fnv_00c982e0

namespace fnv_00c98370 {



class hkReferencedObjectC983 {
public:
    virtual ~hkReferencedObjectC983() throw() {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        hkMemoryRouter::getInstance().heap().blockFree(p, static_cast<hkReferencedObjectC983*>(p)->m_usMemSizeAndFlags);
    }
};

class hkPrimaryC983 : public hkReferencedObjectC983 {
};

class hkSecondaryC983 {
public:
    virtual ~hkSecondaryC983() throw() {}
    int m_0c;
};

class hkListenerPairC983 : public hkPrimaryC983, public hkSecondaryC983 {
public:
    hkListenerPairC983* FUN_00c98370(unsigned int uiFlags) throw();
};

// Destroys the object and, when bit 0 of uiFlags is set, frees its memory via operator delete; returns this.
// @fnv 0x00c98370
hkListenerPairC983* hkListenerPairC983::FUN_00c98370(unsigned int uiFlags) throw()
{
    this->hkListenerPairC983::~hkListenerPairC983();
    if (uiFlags & 1)
        ::operator delete(this);
    return this;
}
}  // namespace fnv_00c98370

namespace fnv_00c983b0 {

struct FnvCpu_FUN_00c983b0_CpuObject {
    unsigned int unk00;
    unsigned short size;
    void FUN_00c93e50();
    FnvCpu_FUN_00c983b0_CpuObject* FUN_00c983b0(unsigned int flags);
};
// @fnv 0x00c983b0
FnvCpu_FUN_00c983b0_CpuObject* FnvCpu_FUN_00c983b0_CpuObject::FUN_00c983b0(unsigned int flags)
{
    FUN_00c93e50();
    if (flags & 1) {
        hkMemoryRouter::getInstance().heap().blockFree(this, size);
    }
    return this;
}
}  // namespace fnv_00c983b0


class hkListenerC984 {
public:
    virtual void v00();
    virtual void v04();
    virtual void onEvent(hkUlong originalGeomId, const void* transform, hkUlong id, int tag, hkUlong shapeIdHint);
};

class hkDispatcherC984 {
public:
    int unk00;
    int unk04;
    hkListenerC984** m_kListeners;
    int m_numListeners;
    int unk10;
    CRITICAL_SECTION* m_kCriticalSection;

    void DispatchEvent(hkUlong originalGeomId, const void* transform, hkUlong id, int tag, hkUlong shapeIdHint);
};

// Locks the critical section, calls onEvent on every registered listener with the five arguments, then unlocks it.
// @fnv 0x00c98440
void hkDispatcherC984::DispatchEvent(hkUlong aiArg0, const void* aiArg1, hkUlong aiArg2, int aiArg3, hkUlong aiArg4)
{
    EnterCriticalSection(m_kCriticalSection);
    for (int i = 0; i < m_numListeners; i++)
        m_kListeners[i]->onEvent(aiArg0, aiArg1, aiArg2, aiArg3, aiArg4);
    LeaveCriticalSection(m_kCriticalSection);
}

namespace fnv_00c984f0 {

struct hkListenerC984 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10(void* a, void* b, void* c);
};

struct hkObjC984 {
    int unk00;
    int unk04;
    hkListenerC984** m_kListeners;
    int m_numListeners;
    int unk10;
    CRITICAL_SECTION* m_kCriticalSection;

    void FUN_00c984f0(void* a, void* b, void* c);
};

// Enters the critical section, calls v10 on each listener with the three arguments, then leaves the critical section.
// @fnv 0x00c984f0
void hkObjC984::FUN_00c984f0(void* a, void* b, void* c)
{
    EnterCriticalSection(m_kCriticalSection);
    for (int i = 0; i < m_numListeners; i++)
        m_kListeners[i]->v10(a, b, c);
    LeaveCriticalSection(m_kCriticalSection);
}
}  // namespace fnv_00c984f0

extern void(* DAT_00fdf05c)(void* pvSection);
extern void(* DAT_00fdf100)(void* pvSection);

class hkCriticalSectionC985 {
public:
    int m_kCriticalSection[6];
    void enter() { DAT_00fdf05c(this); }
    void leave() { DAT_00fdf100(this); }
};

struct hkVector3C985 {
    float x;
    float y;
    float z;
};

class hkListenerC985 {
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void notify(void* a, void* b, void* c, float x, float y, float z, void* d);
};

class hkDispatcherC985 {
public:
    int unk00;
    int unk04;
    hkListenerC985** m_kListeners;
    int m_numListeners;
    int unk10;
    hkCriticalSectionC985* m_lock;

    void FUN_00c98590(void* a, void* b, void* c, float x, float y, float z, void* d);
};

// @fnv 0x00c98590
void hkDispatcherC985::FUN_00c98590(void* apArg1, void* apArg2, void* apArg3, float x, float y, float z, void* apArg4)
{
    m_lock->enter();
    for (int i = 0; i < m_numListeners; i++)
        m_kListeners[i]->notify(apArg1, apArg2, apArg3, x, y, z, apArg4);
    m_lock->leave();
}

class hkpListenerC986 {
public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual void V6() throw();
    virtual void V7() throw();
    virtual void notify(const void* position, int color, hkUlong id, int tag) throw();
};

class hkpListenerListC986 {
public:
    int unk00;
    int unk04;
    hkpListenerC986** m_data;
    int m_iElementCount;
    int unk10;
    CRITICAL_SECTION* m_pWorldLock;

    void FUN_00c98670(const void* position, int color, hkUlong id, int tag);
};

// @fnv 0x00c98670
void hkpListenerListC986::FUN_00c98670(const void* aiArg0, int aiArg1, hkUlong aiArg2, int aiArg3)
{
    EnterCriticalSection(m_pWorldLock);
    for (int i = 0; i < m_iElementCount; i++)
        m_data[i]->notify(aiArg0, aiArg1, aiArg2, aiArg3);
    LeaveCriticalSection(m_pWorldLock);
}

class hkpListenerC98B {
public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual void V6() throw();
    virtual void V7() throw();
    virtual void V8() throw();
    virtual void notify(const void* start, const void* end, int color, hkUlong id, int tag) throw();
};

class hkpListenerListC98B : public hkReferencedObject {
public:
    hkpListenerC98B** m_data;
    int m_iElementCount;
    int m_iCapacityAndFlags;
    CRITICAL_SECTION* m_pWorldLock;

    void FUN_00c986c0(const void* start, const void* end, int color, hkUlong id, int tag);
};

// @fnv 0x00c986c0
void hkpListenerListC98B::FUN_00c986c0(const void* aiArg0, const void* aiArg1, int aiArg2, hkUlong aiArg3, int aiArg4)
{
    EnterCriticalSection(m_pWorldLock);
    for (int i = 0; i < m_iElementCount; i++)
        m_data[i]->notify(aiArg0, aiArg1, aiArg2, aiArg3, aiArg4);
    LeaveCriticalSection(m_pWorldLock);
}

// 0x00c98720  unit_74447a602ec8.cpp  /MT /O2 /GS /EHsc /Gy
// thiscall, 6 stack args (ret 0x18): lock pointer at this+0x14, walk the array at
// this+8 for this->count0c elements, call vtable slot 0x28 with the six args, unlock.

struct Listener00c98720 {
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0c();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual void s28(const void*, const void*, const void*, int color, hkUlong id, int tag);
};

struct C00c98720 {
    char pad00[0x8];
    Listener00c98720** arr08;
    int count0c;
    char pad10[0x4];
    CRITICAL_SECTION* pCS14;

    void FUN_00c98720(const void* a, const void* b, const void* c, int color, hkUlong id, int tag);
};

// Locks the critical section, calls s28 with the six arguments on each listener in arr08, then unlocks it.
// @fnv 0x00c98720
void C00c98720::FUN_00c98720(const void* aiArg0, const void* aiArg1, const void* aiArg2, int aiArg3, hkUlong aiArg4, int aiArg5) {
    EnterCriticalSection(pCS14);
    for (int i = 0; i < count0c; ++i) {
        arr08[i]->s28(aiArg0, aiArg1, aiArg2, aiArg3, aiArg4, aiArg5);
    }
    LeaveCriticalSection(pCS14);
}



struct FUN_00c986c0_Obj {
};

struct FUN_00c98b60_Class {
    void FUN_00c98b60(__m128* v, float f, int color, hkUlong id, int tag);
};

// For each of the first three axes, builds a vector with f on that axis and calls FUN_00c986c0 with the sum and difference against *v.
// @fnv 0x00c98b60
void FUN_00c98b60_Class::FUN_00c98b60(__m128* v, float f, int c, hkUlong d, int e)
{
    int i = 0;
    __m128 vecZero = _mm_setzero_ps();
    for (; i < 3; ++i) {
        union {
            __m128 v;
            float f[4];
        } vecAxis;
        vecAxis.v = vecZero;
        vecAxis.f[i] = f;
        __m128 vecSum = _mm_add_ps(*v, vecAxis.v);
        __m128 diff = _mm_sub_ps(*v, vecAxis.v);
        reinterpret_cast<::hkpListenerListC98B *>((reinterpret_cast<FUN_00c986c0_Obj*>(this)))->FUN_00c986c0((&vecSum), (&diff), c, d, e);
    }
}

struct IListener {
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c(void* a1, void* a2, void* a3, void* a4, void* a5);
};

struct ListenerManager {
    int unk00;
    int unk04;
    IListener** m_kListeners;
    int m_uiItemCount;
    int unk10;
    CRITICAL_SECTION* m_cs;

    void FUN_00c99100(void* a1, void* a2, void* a3, void* a4, void* a5);
};

// @fnv 0x00c99100
void ListenerManager::FUN_00c99100(void* apArg1, void* apArg2, void* apArg3, void* apArg4, void* apArg5) {
    EnterCriticalSection(m_cs);
    for (int i = 0; i < m_uiItemCount; ++i) {
        m_kListeners[i]->v0c(apArg1, apArg2, apArg3, apArg4, apArg5);
    }
    LeaveCriticalSection(m_cs);
}

struct FUN_00c99160_Dispatch {
    virtual void fn00();
    virtual void fn04();
    virtual void fn08();
    virtual void fn0c();
    virtual void fn10();
    virtual void fn14();
    virtual void fn18();
    virtual void fn1c();
    virtual void fn20();
    virtual void fn24();
    virtual void fn28();
    virtual void fn2c();
    virtual void fn30();
    virtual void fn34();
    virtual void fn38();
    virtual void fn3c(const void* geometries, const void* transform, int color, hkUlong id, int tag);
};
struct FUN_00c99160_Owner {
    int unk00;
    int unk04;
    FUN_00c99160_Dispatch** listeners;
    int listenerCount;
    int unk10;
    CRITICAL_SECTION* mutex;
    void DispatchToListeners(const void* geometries, const void* transform, int color, hkUlong id, int tag);
};
// @fnv 0x00c99160
void FUN_00c99160_Owner::DispatchToListeners(const void* aiArg0, const void* aiArg1, int aiArg2, hkUlong aiArg3, int aiArg4) {
    EnterCriticalSection(mutex);
    for(int i = 0; i < listenerCount; ++i) {
        listeners[i]->fn3c(aiArg0, aiArg1, aiArg2, aiArg3, aiArg4);
    }
    LeaveCriticalSection(mutex);
}

struct FUN_00c991c0_Interface {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void slot38(const void* geometries, int color, hkUlong id, int tag);
};

struct FUN_00c991c0_Class {
    void* m_iWordAt00;
    void* m_iWordAt04;
    FUN_00c991c0_Interface** m_8;
    int m_iThirdValue;
    void* m_10;
    void* m_14;

    void DispatchToSlots(const void* geometries, int color, hkUlong id, int tag);
};

extern void (*DAT_00fdf05c)(void*);
extern void (*DAT_00fdf100)(void*);

// @fnv 0x00c991c0
void FUN_00c991c0_Class::DispatchToSlots(const void* aiArg1, int aiArg2, hkUlong aiArg3, int aiArg4) {
    FUN_00c991c0_Class* self = this;

    DAT_00fdf05c(self->m_14);

    int index = 0;
    while (index < self->m_iThirdValue) {
        FUN_00c991c0_Interface* object = self->m_8[index];
        object->slot38(aiArg1, aiArg2, aiArg3, aiArg4);
        ++index;
    }

    DAT_00fdf100(self->m_14);
}

struct HavokHelper {
    void FUN_00c99870(const hkQuaternion& a1, float a2, hkUlong id, int tag);
};

struct __declspec(align(16)) AlignedRotation : hkRotation {
};

namespace fnv_00c99eb0 {

struct FNV_Subobject {
};
extern void* DAT_010c69cc;
struct FUN_00c99eb0 {
    void* m_ppVirtualMethodTable;
    unsigned short m_04;
    unsigned short m_flag06;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
    void* m_14;
    FUN_00c99eb0();
};
// Initialises the object's fields, allocates 0x18 bytes from the allocator and stores the result of FUN_00cf6da0(1000) in m_14.
// @fnv 0x00c99eb0
FUN_00c99eb0::FUN_00c99eb0() {
    m_flag06 = 1;
    m_ppVirtualMethodTable = &DAT_010c69cc;
    m_08 = 0;
    m_0C = 0;
    m_10 = 0x80000000u;
    void* memory = hkMemoryRouter::getInstance().heap().blockAlloc(0x18);
    void* pSubobject = memory
        ? ((void *)(reinterpret_cast<::FUN_00cf6da0_cls *>((static_cast<FNV_Subobject*>(memory)))->FUN_00cf6da0(1000)))
        : 0;
    m_14 = pSubobject;
}
}  // namespace fnv_00c99eb0

struct FUN_00ca8420_Local {
    unsigned char unk00;
    void* unk04;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
};

struct FUN_00ca8420_Target {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    int unk90;
    int unk94;

};

struct FUN_00ca8420_Class {
    void* unk00;
    void* unk04;
    FUN_00ca8420_Target* unk08;

    void FUN_00ca8420(int param2, int param3, int param4);
};


// @fnv 0x00ca8420
void FUN_00ca8420_Class::FUN_00ca8420(int aiArg1, int aiArg2, int aiArg3)
{
    if (unk08 != 0 && unk08->unk94 != 0) {
        FUN_00ca8420_Local local;
        local.unk08 = (unsigned char)aiArg1;
        local.unk09 = (unsigned char)aiArg2;
        local.unk00 = 4;
        local.unk04 = this;
        local.unk0A = (unsigned char)aiArg3;
        reinterpret_cast<::WorldWithPending *>((unk08))->FUN_00c91160();
        return;
    }

    ::FUN_00cb6f70((::MotionObj *)(void *)(this), aiArg1, aiArg2, aiArg3, {}, {}, {}, {}, {});

    if (unk08 != 0) {
        ::fnv_00d006e0::NotifyEntitySetMotionType((::fnv_00d006e0::World833 *)(unk08), (::fnv_00d006e0::hkpEntity *)(void *)(this));
    }

    ::InvokeMotionTypeCallbacks((::TaskOwner *)(void *)(this));
}

struct hkVector3CA8A {
    float x;
    float y;
    float z;
};

struct hkWorldOperationBaseCA8A {
    unsigned char m_type;
};

class hkpEntityCA8A;

struct hkSetVelocityOpCA8A : public hkWorldOperationBaseCA8A {
    hkpEntityCA8A* m_pEntity;
    float m_fVelocity[3];

    hkSetVelocityOpCA8A() { m_type = 0x1b; }
};

class hkpWorldCA8A {
public:
    int unk00[0x25];
    int m_iCriticalOperationsLockCount;

    bool areCriticalOperationsLocked() const { return m_iCriticalOperationsLockCount != 0; }
};

struct UnkCall {
};

class hkpMotionCA8A {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void SetTranslationalVelocity(const hkVector3CA8A& v);
};

class hkpEntityCA8A {
public:
    int unk00;
    int unk04;
    hkpWorldCA8A* m_pOwningWorld;
    int unk0C[0x35];
    hkpMotionCA8A m_pMotionState;

    void FUN_00ca8a80(const hkVector3CA8A& v);
};

// @fnv 0x00ca8a80
void hkpEntityCA8A::FUN_00ca8a80(const hkVector3CA8A& akVelocity)
{
    if (m_pOwningWorld && m_pOwningWorld->areCriticalOperationsLocked()) {
        hkSetVelocityOpCA8A kOp;
        kOp.m_pEntity = this;
        kOp.m_fVelocity[0] = akVelocity.x;
        kOp.m_fVelocity[1] = akVelocity.y;
        kOp.m_fVelocity[2] = akVelocity.z;
        reinterpret_cast<::WorldWithPending *>((m_pOwningWorld))->FUN_00c91160();
        return;
    }
    reinterpret_cast<::hkpEntityC9C *>((reinterpret_cast<UnkCall*>(this)))->FUN_00c9c1d0();
    m_pMotionState.SetTranslationalVelocity(akVelocity);
}

struct FUN_00ca94c0_Ctx {
    void* self;
    const void* arg;
    unsigned int result;
};
struct FUN_00ca94c0_Elem {
    virtual void Visit(FUN_00ca94c0_Ctx* ctx);
};
struct FUN_00ca94c0_Class {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    FUN_00ca94c0_Elem** m_pElements;
    int m_uiItemCount;
    int FUN_00ca94c0(const void* arg);
};
// Iterates the element array backwards, calling Visit on each non-null element with a context holding self and arg, and returns the accumulated result.
// @fnv 0x00ca94c0
int FUN_00ca94c0_Class::FUN_00ca94c0(const void* arg) {
    FUN_00ca94c0_Ctx ctx;
    ctx.self = this;
    ctx.arg = arg;
    ctx.result = 0;
    int i = m_uiItemCount - 1;
    if (i >= 0) {
        do {
            if (m_pElements[i]) {
                FUN_00ca94c0_Elem** slot = &m_pElements[i];
                (*slot)->Visit(&ctx);
            }
        } while (--i >= 0);
    }
    return ctx.result;
}

struct Allocator9 {  };
struct Guard9 {
    unsigned int previous;
    Guard9()
    {
        previous = g_tlsBlock.memoryContext;
        g_tlsBlock.memoryContext = 16;
    }
    ~Guard9()
    {
        g_tlsBlock.memoryContext = previous;
    }
};
struct Node9 { void* vtable; int value; int references; int previous; int next; };
struct Class9 {
    void* unk00; void* unk04; int callbackFlag; int* data;
    int* GetOrCreateData(unsigned char* wasEmpty);
};
// @fnv 0x00caa5d0
int* Class9::GetOrCreateData(unsigned char* wasEmpty) {
    Guard9 guard;
    *wasEmpty = (data == 0);
    if (*wasEmpty) {
        Node9* allocated = (Node9*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::Allocator9 *>(&::g_memoryManager))))->FUN_00aa3e40(20);
        int* nextData;
        if (allocated) {
            int* contents = &allocated->value;
            allocated->references = 1;
            allocated->previous = 0;
            allocated->next = 0;
            allocated->vtable = &::DAT_010c5dc0;
            *contents = 0;
            nextData = contents;
        } else nextData = 0;
        data = nextData;
        if (callbackFlag) reinterpret_cast<::FUN_00c89c80_obj *>(this)->CopyFromSource((uintptr_t)(data ? (Node9*)((char*)data - offsetof(Node9, value)) : 0));
    }
    return data;
}


typedef unsigned int (__cdecl* ReadFn)(NiBinaryStream* pThis, void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents);

inline unsigned int BinaryRead(NiBinaryStream* stream, void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes = 0, unsigned int uiNumComponents = 0)
{
    unsigned int uiBytes = ((ReadFn)stream->m_pfnRead)(stream, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    stream->m_uiStreamFlags += uiBytes;
    return uiBytes;
}

struct NiStream {
    void* m_vtbl;
    unsigned int m_uiFormatVersion;
    unsigned int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    unsigned int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    unsigned int unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    unsigned int unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84;
    unsigned int unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4;
    unsigned int unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4;
    unsigned int unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4;
    unsigned int unkE8, unkEC, unkF0, unkF4, unkF8, unkFC, unk100, unk104;
    unsigned int unk108, unk10C, unk110, unk114, unk118, unk11C, unk120, unk124;
    unsigned int unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144;
    unsigned int unk148, unk14C, unk150, unk154, unk158, unk15C, unk160, unk164;
    unsigned int unk168, unk16C, unk170, unk174, unk178, unk17C, unk180, unk184;
    unsigned int unk188, unk18C, unk190, unk194, unk198, unk19C, unk1A0, unk1A4;
    unsigned int unk1A8, unk1AC, unk1B0, unk1B4, unk1B8, unk1BC, unk1C0, unk1C4;
    unsigned int unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC, unk1E0;
    unsigned char unk1E4;
    unsigned char m_bEndianSwap;
    unsigned char unk1E6;
    unsigned char unk1E7;
    unsigned int unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC;
    unsigned int unk200, unk204, unk208, unk20C, unk210, unk214, unk218, unk21C;
    unsigned int unk220, unk224, unk228, unk22C, unk230, unk234, unk238, unk23C;
    unsigned int unk240, unk244, unk248;
    NiBinaryStream* m_pUnderlyingStream;
};

template <class T>
inline unsigned int NiBinaryStreamLoad(NiBinaryStream* binstream, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    return BinaryRead(binstream, pValue, uiNumEls * sizeof(T), &uiSize, uiNumEls);
}

template <class T>
inline void ReadBinaryValue(NiStream& stream, T& value)
{
    NiBinaryStreamLoad(stream.m_pUnderlyingStream, &value, 1);
}


inline void SwapDword(unsigned long& val) {
    val = _byteswap_ulong(val);
}

inline void ByteSwapBlk(Blk40& blk)
{
    unsigned long* u = (unsigned long*)&blk;
    SwapDword(u[12]);
    SwapDword(u[13]);
    SwapDword(u[14]);
    SwapDword(u[15]);
    ::SwapEndianBlocks((unsigned int *)(void *)(&blk));
}

struct FUN_00d1df70 {
    void removeReference();
};

struct Data_caa6a0 : Data_00caa840 {
};

struct FUN_00d53200_class {
    void* m_unk00;
    Data_caa6a0* m_data;

    void FUN_00c8a230(NiStream& stream);

    void ReadFromStream(NiStream& stream);
};

// Reads the object's data blocks and floats from the stream, byte-swaps them when needed, and loads a referenced object for stream versions above 0x1d.
// @fnv 0x00caa6a0
void FUN_00d53200_class::ReadFromStream(NiStream& stream)
{
    FUN_00c8a230(stream);

    Data_caa6a0* const data = m_data;

    BinaryRead(stream.m_pUnderlyingStream, &data->m_20, 0x40);
    BinaryRead(stream.m_pUnderlyingStream, &data->m_60, 0x40);
    ReadBinaryValue(stream, data->m_c4);
    ReadBinaryValue(stream, data->m_c8);
    float* const pDefaultFloat = (float*)&data->m_bc;
    ReadBinaryValue(stream, *pDefaultFloat);

    if (stream.m_bEndianSwap != 1) {
        ByteSwapBlk(data->m_20);
        ByteSwapBlk(data->m_60);
    }

    if (stream.m_uiFormatVersion > 0x1d) {
        hkReferencedObject* obj = ((::hkReferencedObject *)(::FUN_00c8a330((::Stream674 *)this)));
        reinterpret_cast<::FUN_00cb8ac0_class *>((data))->SetReferencedObject((::RefObj *)(obj));
        if (obj) {
            ReadBinaryValue(stream, data->m_a2);
            reinterpret_cast<::hkReferencedObjectC905 *>((((FUN_00d1df70*)obj)))->FUN_00c905b0();
        }
    }

    if (*pDefaultFloat == 0.0f) {
        *pDefaultFloat = 100.0f;
    }
}

struct MemoryScope {
 int previous;
public:
    MemoryScope()
    {
        previous = g_tlsBlock.memoryContext;
        g_tlsBlock.memoryContext = 16;
    }
    ~MemoryScope()
    {
        g_tlsBlock.memoryContext = previous;
    }
};
struct Point3 { float x,y,z;  };
struct Strings {
 void* unk00; char** unk04;
 unsigned short unk08,unk0A,unk0C,unk0E;
 void Append(char* text) {
  unsigned n=unk0A;
  if(n>=unk08) reinterpret_cast<::ViewerStrings *>(this)->SetSize(n+unk0E);
  reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(n,text);
 }
};
struct Constraint {
 int unk00;
 int unk04;
 int unk08;
 int unk0C;
 int unk10;
 int unk14;
 int unk18;
 int unk1C;
 int unk20;
 int unk24;
 int unk28;
 int unk2C;
 hkVector4 unk30;
 hkVector4 unk40;
 hkVector4 unk50;
 hkVector4 unk60;
 int unk70;
 int unk74;
 int unk78;
 int unk7C;
 int unk80;
 int unk84;
 int unk88;
 int unk8C;
 hkVector4 unk90;
 unsigned short unkA0; unsigned char unkA2,unkA3;
 int unkA4;
 int unkA8;
 float unkAC;
 int unkB0;
 int unkB4;
 int unkB8;
 float unkBC;
 int unkC0;
 float unkC4;
 float unkC8;
};
struct Owner {
 int unk00; Constraint* unk04;
 void AppendConstraintToStrings(Strings*);
public:
    void ClearReferences();
public:
    ::Owner *FUN_00cf5ea0();
};
// @fnv 0x00caa960
void Owner::AppendConstraintToStrings(Strings* strings) {
 MemoryScope scope;
 reinterpret_cast<::ViewerConstraint *>(this)->FUN_00c8a560((::BC8AD40StringArray *)(strings));
 Constraint* constraint=unk04;
 if(constraint) {
  Point3 temp;
  ::FUN_004a3970((::NiPoint3_local &)(temp),constraint->unk50);
  strings->Append(reinterpret_cast<::NiPoint3 *>(&(temp))->FUN_00a59af0("PivotInA"));
  ::FUN_004a3970((::NiPoint3_local &)(temp),constraint->unk90);
  strings->Append(reinterpret_cast<::NiPoint3 *>(&(temp))->FUN_00a59af0("PivotInB"));
  ::FUN_004a3970((::NiPoint3_local &)(temp),constraint->unk60);
  strings->Append(reinterpret_cast<::NiPoint3 *>(&(temp))->FUN_00a59af0("AxleInB"));
  ::FUN_004a3970((::NiPoint3_local &)(temp),constraint->unk30);
  strings->Append(reinterpret_cast<::NiPoint3 *>(&(temp))->FUN_00a59af0("Perp2AxleInA1"));
  ::FUN_004a3970((::NiPoint3_local &)(temp),constraint->unk40);
  strings->Append(reinterpret_cast<::NiPoint3 *>(&(temp))->FUN_00a59af0("Perp2AxleInA2"));
  strings->Append(FUN_00a7d550("MinAngle",float(constraint->unkC4*57.2957763671875)));
  strings->Append(FUN_00a7d550("MaxAngle",float(constraint->unkC8*57.2957763671875)));
  strings->Append(FUN_00a7d550("MaxFrictionTrq",constraint->unkBC));
  strings->Append(::fnv_00a7d5e0::FUN_00a7d5e0("Motor",constraint->unkA2 ? "Active" : "Inactive"));
  float motorAngle=constraint->unkAC;
  strings->Append(FUN_00a7d550("MotorAngle",float(motorAngle*57.2957763671875)));
 }
}

class hkRefObjCBFB {
public:
    virtual ~hkRefObjCBFB() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjCBFB() { m_sReferenceCount = 1; }
};

class hkListenerACBFB {
public:
    virtual void a0() = 0;
};

class hkListenerBCBFB {
public:
    virtual void b0() = 0;
};

class hkListenerCCBFB {
public:
    virtual void c0() = 0;
};

class hkListenerDCBFB {
public:
    virtual void d0() = 0;
};

class FUN_00cbfba0 : public hkRefObjCBFB, public hkListenerACBFB, public hkListenerBCBFB, public hkListenerCCBFB, public hkListenerDCBFB {
public:
    int unk18;
    int unk1C;
    int m_20;

    FUN_00cbfba0() throw();
    virtual ~FUN_00cbfba0() throw();
    virtual void a0();
    virtual void b0();
    virtual void c0();
    virtual void d0();
};

// Initializes the object's m_20 field to 0.
// @fnv 0x00cbfba0
FUN_00cbfba0::FUN_00cbfba0() throw()
    : m_20(0)
{
}

// Reconstructed ClearIndexedValues (FNV 1.4.0.525, /MT /O2 /GS /EHsc /Gy).
// Stand-in declarations; unknown fields are named by their byte offset.
// External callees keep the pack's FUN_ names and bind through relocations.


struct Elem676;
struct Sub676 { char m_pad0000[0x14]; unsigned char m_14; };
struct Elem676 { char m_pad0000[0xc]; Sub676* m_iThirdValue; void removeReference(); };

struct Q676 {
    void FUN_00c954e0(Elem676** arr, int count);
};

struct GC676 { void* m_p; int m_unused; };

struct Tmp676 { float m_f; unsigned char b0, b1, b2, b3, b4; };

struct GCObj676 {
    virtual void *g00(void*);
    virtual void *g01(void*);
    virtual void *g02(void*);
    virtual void *g03(void*);
    virtual void *g04(void*);
    virtual void *g05(void*);
    virtual void *g06(void*);
    virtual void *g07(void*);
    virtual void *g08(void*);
    virtual void *g09(void*);
    virtual void *g10(void*);
    virtual void *g11(void*);
    virtual void *g12(void*);
    virtual void *g13(void*);
    virtual void *g14(void*);
    virtual void *g15(void*);
    virtual void *g16(void*);
    virtual void *g17(void*);
    virtual void *g18(void*);
    virtual void *g19(void*);
    virtual void *g20(void*);
    virtual void *g21(void*);
    virtual void *g22(void*);
    virtual void *g23(void*);
    virtual void *g24(void*);
    virtual void *g25(void*);
    virtual void *g26(void*);
    virtual void *g27(void*);
    virtual void *g28(void*);
    virtual void *g29(void*);
    virtual void *g30(void*);
    virtual void *g31(void*);
    virtual void *g32(void*);
    virtual void *g33(void*);
    virtual void *g34(void*);
    virtual void *g35(void*);
    virtual void g36(void*);
};

struct This676 {
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
    virtual void* v37();
    char m_pad0004[0x30];
    Elem676** m_aiIndexedValues;              // +0x34
    unsigned int m_uiItemCount;         // +0x38
    void ClearIndexedValues();
};

// Scoped override of the thread-local context field (0x10 during the operation).
struct Guard676 {
    int m_saved;
public:
    Guard676()
    {
        m_saved = g_tlsBlock.memoryContext;
        g_tlsBlock.memoryContext = 0x10;
    }
    ~Guard676()
    {
        g_tlsBlock.memoryContext = m_saved;
    }
};

extern GC676* FUN_00c85ef0(GC676* out, Elem676* obj, void* rtti);

struct BoolC68BF0 {
    char m_cBooleanValue;
};
struct HkEntityC68BF0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int m_uiValue1;
};
struct EntityC68BF0;
struct HkWorldC68BF0 {
};
struct EntityC68BF0 {
    int unk00;
    int unk04;
    int unk08;
    HkEntityC68BF0* m_pkHkEntity;
};
struct WorldC68BF0 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual HkWorldC68BF0* GetHavokWorld();
    bool FUN_00c68bf0(EntityC68BF0* pkEntity);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_uiBatchDepth;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    EntityC68BF0** m_ppkPendingAdds;
    unsigned int m_uiNumPendingAdds;
};

struct FUN_00c91000_Class
{
    __m128 m_iWordAt00;
    __m128 m_10;

    void FUN_00c91000(const __m128* value);
};

// @fnv 0x00c91000
void FUN_00c91000_Class::FUN_00c91000(const __m128* value)
{
    m_10 = *value;
}

struct FUN_00c91620_Target;

struct FUN_00c91620_Args {
    unsigned char type;
    FUN_00c91620_Target* target;
};

struct FUN_00c91620_Aux {
    void* m_00; void* m_04; void* m_08; void* m_0c;
    void* m_10; void* m_14; void* m_18; void* m_1c; void* m_20;
    void FreeStorage();
};

struct FUN_00c91620_Target {
    virtual void vf00(); virtual void vf04(); virtual void vf08();
    virtual void vf0c(); virtual void vf10(); virtual void vf14();

    unsigned short m_04;
    void* m_08; void* m_0c; void* m_10; void* m_14;
    void* m_18; void* m_1c; void* m_20; void* m_24;
    void* m_28; void* m_2c;
    FUN_00c91620_Aux m_30;
    int m_54;

};

struct FUN_00c91620_Class {
    void* m_00; void* m_04; void* m_08; void* m_0c;
    void* m_10; void* m_14; void* m_18; void* m_1c;
    void* m_20; void* m_24; void* m_28; void* m_2c;
    void* m_30; void* m_34; void* m_38; void* m_3c;
    void* m_40; void* m_44; void* m_48; void* m_4c;
    void* m_50; void* m_54; void* m_58; void* m_5c;
    void* m_60; void* m_64; void* m_68; void* m_6c;
    void* m_70; void* m_74; void* m_78; void* m_7c;
    void* m_80; void* m_84; void* m_88; void* m_8c;
    void* m_90;
    int m_94;
    void* m_98;
    unsigned char m_9c;
    unsigned char m_9d;
    void* m_a0;
    int m_a4;
    void FUN_00c91120();
    unsigned char* ProcessTarget(unsigned char* result, FUN_00c91620_Target* target);
};
// While batching, queues pkEntity in the pending-adds array (flushing at 3000); otherwise calls ProcessTarget on the Havok world; true if skipped or added.
// @fnv 0x00c68bf0
bool WorldC68BF0::FUN_00c68bf0(EntityC68BF0* pkEntity)
{
    bool bResult = false;
    HkWorldC68BF0* pkWorld = GetHavokWorld();
    if (pkWorld && pkEntity)
    {
        if (m_uiBatchDepth > 0)
        {
            HkEntityC68BF0* pkHkEntity = pkEntity->m_pkHkEntity;
            if (!pkHkEntity || (pkHkEntity->m_uiValue1 & 0x30))
                return true;
            pkHkEntity->m_uiValue1 |= 0x20;
            if (m_uiNumPendingAdds >= 3000)
            {
                reinterpret_cast<::fnv_00c67df0::PendingWorld *>(this)->ProcessPendingItems();
                reinterpret_cast<::WorldView *>(this)->ReleaseBodies();
                reinterpret_cast<::Owner *>(this)->ClearReferences();
                reinterpret_cast<::FUN_00c67aa0_Class *>(this)->FlushEntries();
            }
            reinterpret_cast<::FUN_00c90510_class *>((pkEntity))->FUN_00c90510();
            m_ppkPendingAdds[m_uiNumPendingAdds] = pkEntity;
            m_uiNumPendingAdds++;
            bResult = true;
        }
        else
        {
            HkEntityC68BF0* pkHkEntity = pkEntity->m_pkHkEntity;
            if (!pkHkEntity || (pkHkEntity->m_uiValue1 & 0x30))
                return true;
            bResult = (*(::BoolC68BF0 *)(reinterpret_cast<::FUN_00c91620_Class *>((pkWorld))->ProcessTarget((unsigned char *)(pkEntity), {}))).m_cBooleanValue != 0;
        }
    }
    return bResult;
}


// If m_94 is nonzero, calls FUN_00c91160 with type 2 and writes 0 to *result; otherwise runs the helper calls on target and writes 1 to *result.
// @fnv 0x00c91620
unsigned char* FUN_00c91620_Class::ProcessTarget(
    unsigned char* result, FUN_00c91620_Target* target)
{
    if (m_94 != 0) {
        FUN_00c91620_Args args;
        args.type = 2;
        args.target = target;
        reinterpret_cast<::WorldWithPending *>(this)->FUN_00c91160();
        *result = 0;
        return result;
    }

    m_94 = 1;
    ::FUN_00cb5c10((::Owner *)(::FUN_00c91620_Class *)(this), (::Evt *)(target));
    ::FUN_00d005a0((::D005A0World *)(::FUN_00c91620_Class *)(this), target);
    ::FUN_00cffab0((::Class_00cffab0 *)(target));
    m_9d = 0;
    ::FUN_00cb4740((::Obj *)(::FUN_00c91620_Class *)(this), (::Obj *)(target));

    if (target->m_54 != 0) {
        reinterpret_cast<::hkMapD01A *>(&(target->m_30))->FreeStorage();
    }

    if (target->m_04 == 0) {
        target->vf14();
    }
    reinterpret_cast<::hkReferencedObjectC905 *>((target))->FUN_00c905b0();

    --m_94;
    m_9d = 1;

    if (m_94 == 0 && m_9c == 0) {
        if (m_8c != 0)
            reinterpret_cast<::FUN_00c91120 *>(this)->ExecutePendingOperations();
        if (m_a4 == 1 && m_90 != 0)
            reinterpret_cast<::FUN_00c91140_Class *>(this)->FUN_00c91140();
    }
    *result = 1;
    return result;
}

template <class T>
class hkArrayXc91700 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++) {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};

class hkWorldXc91700 {
public:
    int unk000[71];
    hkArrayXc91700<void*> m_entries;

    void FUN_00c91700(void* entry);
};

// Sets the array slot containing the given entry to null by looking up its index in m_entries.
// @fnv 0x00c91700
void hkWorldXc91700::FUN_00c91700(void* entry)
{
    m_entries.m_data[m_entries.indexOf(entry)] = 0;
}

template <class T>
class hkArrayC9175 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++) {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};

class hkWorldC9175 {
public:
    int unk000[80];
    hkArrayC9175<void*> m_entries;

    void FUN_00c91750(void* entry);
};

// Sets the entry at the index found by indexOf to 0, clearing it from the m_entries array.
// @fnv 0x00c91750
void hkWorldC9175::FUN_00c91750(void* entry)
{
    m_entries.m_data[m_entries.indexOf(entry)] = 0;
}

template <class T>
class hkArrayC917 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++) {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};

class hkWorldC917 {
public:
    int unk000[74];
    hkArrayC917<void*> m_entries;

    void FUN_00c917a0(void* entry);
};

// Sets the m_entries slot at indexOf(entry) to null.
// @fnv 0x00c917a0
void hkWorldC917::FUN_00c917a0(void* entry)
{
    m_entries.m_data[m_entries.indexOf(entry)] = 0;
}

template <class T>
class hkArrayC91F {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++) {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};

class hkWorldC91F {
public:
    int unk000[77];
    hkArrayC91F<void*> m_entries;

    void FUN_00c917f0(void* entry);
};

// Sets the array slot containing the given entry to null.
// @fnv 0x00c917f0
void hkWorldC91F::FUN_00c917f0(void* entry)
{
    m_entries.m_data[m_entries.indexOf(entry)] = 0;
}

template <class T>
class hkArrayC918 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++) {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};

class hkWorldC918 {
public:
    int unk000[95];
    hkArrayC918<void*> m_entries;

    void FUN_00c91890(void* entry);
};

// Sets the array slot at indexOf(entry) to 0, clearing the entry from m_entries.
// @fnv 0x00c91890
void hkWorldC918::FUN_00c91890(void* entry)
{
    m_entries.m_data[m_entries.indexOf(entry)] = 0;
}

template <class T>
class hkArrayXc91930 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++) {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};

class hkWorldXc91930 {
public:
    int unk000[92];
    hkArrayXc91930<void*> m_entries;

    void FUN_00c91930(void* entry);
};

// Sets the entry at the index found by indexOf to 0, clearing the slot in the m_entries array.
// @fnv 0x00c91930
void hkWorldXc91930::FUN_00c91930(void* entry)
{
    m_entries.m_data[m_entries.indexOf(entry)] = 0;
}

template <class T>
class hkArrayXc91980 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++) {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};

class hkWorldXc91980 {
public:
    int unk000[101];
    hkArrayXc91980<void*> m_entries;

    void FUN_00c91980(void* entry);
};

// Sets the entry at the index found by indexOf to 0, clearing it from the m_entries array.
// @fnv 0x00c91980
void hkWorldXc91980::FUN_00c91980(void* entry)
{
    m_entries.m_data[m_entries.indexOf(entry)] = 0;
}

template <class T>
class hkArrayXc91a20 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++) {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};

class hkWorldXc91a20 {
public:
    int unk000[104];
    hkArrayXc91a20<void*> m_entries;

    void FUN_00c91a20(void* entry);
};

// Sets the entry at the index found by indexOf to 0, clearing the slot in m_entries.
// @fnv 0x00c91a20
void hkWorldXc91a20::FUN_00c91a20(void* entry)
{
    m_entries.m_data[m_entries.indexOf(entry)] = 0;
}

template <class T>
class hkArrayXc91a70 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++) {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};

class hkWorldXc91a70 {
public:
    int unk000[83];
    hkArrayXc91a70<void*> m_entries;

    void FUN_00c91a70(void* entry);
};

// Sets the m_entries slot at indexOf(entry) to null.
// @fnv 0x00c91a70
void hkWorldXc91a70::FUN_00c91a70(void* entry)
{
    m_entries.m_data[m_entries.indexOf(entry)] = 0;
}

template <class T>
class hkArrayXc91ac0 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++) {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};

class hkWorldXc91ac0 {
public:
    int unk000[107];
    hkArrayXc91ac0<void*> m_entries;

    void FUN_00c91ac0(void* entry);
};

// Sets the entry at the index found by indexOf to null.
// @fnv 0x00c91ac0
void hkWorldXc91ac0::FUN_00c91ac0(void* entry)
{
    m_entries.m_data[m_entries.indexOf(entry)] = 0;
}




struct JobHeader {
    unsigned char m_eJobType;
    unsigned char m_ucSubType;
    unsigned char m_executionFlags;
    unsigned char unk03;
    unsigned short m_jobSize;
    short m_iAffinity;

    JobHeader(unsigned char type, unsigned char subType, unsigned short size, short affinity = -1)
        : m_eJobType(type), m_ucSubType(subType), m_jobSize(size), m_iAffinity(affinity) {}
};

struct RayCastCommand {
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    int m_uiFilterInfo;
    int m_ulUserData;
    void* m_pResultBuffer;
    int m_iResultCount;
    int m_iResultCapacity;
    int unk34;
    int unk38;
    int unk3C;
};

struct JobDoneHeader {
    int m_iJobId;
    int unk04;
    int unk08;
    int unk0C;
};

struct JobBase {
    JobHeader m_kHeader;
    int unk08;
    int unk0C;
    void* m_pCompletionSemaphore;
    JobDoneHeader* m_pJobDoneHeader;
    int unk18;

    __forceinline JobBase(unsigned char subType, unsigned short size)
        : m_kHeader(1, subType, size)
    {
        unk18 = 0;
        m_kHeader.m_executionFlags = 1;
    }
};

__declspec(align(16)) struct Job : JobBase {
    void* m_pCollisionInput;
    int m_iFirstIndex;
    RayCastCommand* m_pCommands;
    int m_iCommandCount;
    int unk2C;
    int unk30;
    void* m_pJobSemaphore;
    int unk38;
    void* m_kdTreeUnk0C;
    void* m_kdTreeUnk10;
    int unk44;
    int unk48;
    int unk4C;

    __forceinline Job(void* input, JobDoneHeader* jobHeader, RayCastCommand* commandArray, int numCommands, void* broadphase, void* semaphore)
        : JobBase(3, sizeof(Job))
    {
        m_pJobDoneHeader = jobHeader;
        m_pCollisionInput = input;
        m_pCompletionSemaphore = semaphore;
        m_iFirstIndex = sizeof(RayCastCommand);
        m_pCommands = commandArray;
        m_iCommandCount = numCommands;
        m_pJobSemaphore = broadphase;
        m_pJobDoneHeader->m_iJobId = (numCommands == 0) ? 1 : (numCommands - 1) / 64 + 1;
        unk38 = 0;
        m_kdTreeUnk0C = 0;
        m_kdTreeUnk10 = 0;
        unk2C = 0;
        unk30 = 0;
    }
};

struct JobQueue {
};

struct ThreadPool {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void processWork(JobQueue* queue, int type);
    virtual void RunWorkerThread();
};

struct KdTreeManager {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual bool isTreeActive();
    int unk04;
    int unk08;
    void* m_treeData0C;
    void* m_treeData10;
};

struct hkpWorldHelper : hkpWorld {
    void ExecuteRayCastJobs(RayCastCommand* commandArray, int numCommands, JobQueue* jobQueue, ThreadPool* threadPool, void* semaphore, int numCommandsPerJob);
};

// Splits the commands into jobs of numCommandsPerJob queued on jobQueue, runs the thread pool, then calls FUN_00d04380 on semaphore.
// @fnv 0x00c92110
void hkpWorldHelper::ExecuteRayCastJobs(RayCastCommand* commandArray, int numCommands, JobQueue* jobQueue, ThreadPool* threadPool, void* semaphore, int numCommandsPerJob) {
    JobDoneHeader* jobHeader = static_cast<JobDoneHeader*>(hkMemoryRouter::getInstance().heap().blockAlloc(sizeof(JobDoneHeader)));

    Job job(m_pCollisionInput, jobHeader, commandArray, numCommands, m_pJobSemaphore, semaphore);

    if (m_pKdTreeManager && ((KdTreeManager*)m_pKdTreeManager)->isTreeActive()) {
        KdTreeManager* kd = (KdTreeManager*)m_pKdTreeManager;
        job.m_kdTreeUnk0C = kd->m_treeData0C;
        job.m_kdTreeUnk10 = kd->m_treeData10;
        job.m_pJobSemaphore = 0;
    }

    while (job.m_iCommandCount > 0) {
        Job subJob = job;
        subJob.m_iCommandCount = (job.m_iCommandCount < numCommandsPerJob) ? job.m_iCommandCount : numCommandsPerJob;
        job.m_pCommands += numCommandsPerJob;
        job.m_iCommandCount -= numCommandsPerJob;
        reinterpret_cast<::D04B90World *>((jobQueue))->AddObjectCopy((const ::D04B90Object *)&(subJob), (void *)(1));
    }

    threadPool->processWork(jobQueue, 0xb);
    threadPool->RunWorkerThread();

    ::FUN_00d04380(semaphore, {});

    hkMemoryRouter::getInstance().heap().blockFree(jobHeader, sizeof(JobDoneHeader));
}

namespace fnv_00c92290 {



struct CollisionInput {
    int unk00;
    int unk04;
    float m_fScalar;
};

struct JobHeader {
    unsigned char m_ucSubType;
    unsigned char m_eJobType;
    unsigned char m_eSpuType;
    unsigned char unk03;
    unsigned short m_iElementCount;
    short m_iAffinity;

    JobHeader(unsigned char subType, unsigned char type, unsigned short size, unsigned char spuType)
        : m_ucSubType(subType), m_eJobType(type), m_eSpuType(spuType), m_iElementCount(size), m_iAffinity(-1) {}
};

struct ClosestPointsCommand {
    int unk00;
    int unk04;
    int unk08;
    int m_iResultCapacity;
};

struct JobDoneHeader {
    int m_iJobId;
    int unk04;
    int unk08;
    int unk0C;
};

struct CollisionQueryJob {
    JobHeader m_kHeader;
    int unk08;
    int unk0C;
    void* m_pCompletionSemaphore;
    JobDoneHeader* m_pJobDoneHeader;
    CollisionInput* m_pCollisionInput;
    int unk1C;

    __forceinline CollisionQueryJob(unsigned char subType, unsigned short size)
        : m_kHeader(subType, 2, size, 2)
    {
        unk1C = 0;
    }
};

__declspec(align(16)) struct ClosestPointsJob : CollisionQueryJob {
    void* m_pJobSemaphore;
    void* m_kdTreeUnk0C;
    void* m_kdTreeUnk10;
    float m_fScalar;
    int m_maxNumResults;
    ClosestPointsCommand* m_pCommands;
    int m_iCommandCount;
    int unk3C;

    __forceinline ClosestPointsJob(CollisionInput* input, JobDoneHeader* jobHeader, ClosestPointsCommand* commandArray, int numCommands, void* broadphase, float tolerance, void* semaphore)
        : CollisionQueryJob(2, sizeof(ClosestPointsJob))
    {
        for (int i = 0; i < numCommands; i++)
        {
            commandArray[i].m_iResultCapacity = 0;
        }
        m_iCommandCount = numCommands;
        m_pCollisionInput = input;
        m_pJobSemaphore = broadphase;
        m_fScalar = tolerance;
        m_pCompletionSemaphore = semaphore;
        m_pCommands = commandArray;
        m_pJobDoneHeader = jobHeader;
        m_maxNumResults = 0x40;
        jobHeader->m_iJobId = (numCommands - 1) / 64 + 1;
        m_kdTreeUnk0C = 0;
        m_kdTreeUnk10 = 0;
    }

};

struct JobQueue {
};

struct ThreadPool {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void processWork(JobQueue* queue, int type);
    virtual void RunWorkerThread();
};

struct KdTreeManager {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual bool isTreeActive();
    int unk04;
    int unk08;
    void* m_treeData0C;
    void* m_treeData10;
};

struct hkpWorldHelper : hkpWorld {
    void SubmitClosestPointsJobs(ClosestPointsCommand* commandArray, int numCommands, JobQueue* jobQueue, ThreadPool* threadPool, void* semaphore, int numCommandsPerJob);
};

// Splits commandArray into ClosestPointsJob batches, queues them on jobQueue, runs threadPool, calls FUN_00d04380(semaphore), and frees the job header.
// @fnv 0x00c92290
void hkpWorldHelper::SubmitClosestPointsJobs(ClosestPointsCommand* commandArray, int numCommands, JobQueue* jobQueue, ThreadPool* threadPool, void* semaphore, int numCommandsPerJob) {
    JobDoneHeader* jobHeader = static_cast<JobDoneHeader*>(hkMemoryRouter::getInstance().heap().blockAlloc(sizeof(JobDoneHeader)));

    CollisionInput* input = (CollisionInput*)m_pCollisionInput;
    ClosestPointsJob job(input, jobHeader, commandArray, numCommands, m_pJobSemaphore, input->m_fScalar, semaphore);
    ::FUN_00d05de0();

    if (m_pKdTreeManager && ((KdTreeManager*)m_pKdTreeManager)->isTreeActive()) {
        KdTreeManager* kd = (KdTreeManager*)m_pKdTreeManager;
        job.m_kdTreeUnk0C = kd->m_treeData0C;
        job.m_kdTreeUnk10 = kd->m_treeData10;
        job.m_pJobSemaphore = 0;
    }

    while (job.m_iCommandCount > 0) {
        ClosestPointsJob subJob = job;
        subJob.m_iCommandCount = (job.m_iCommandCount < numCommandsPerJob) ? job.m_iCommandCount : numCommandsPerJob;
        job.m_pCommands += numCommandsPerJob;
        job.m_iCommandCount -= numCommandsPerJob;
        reinterpret_cast<::D04B90World *>((jobQueue))->AddObjectCopy((const ::D04B90Object *)&(subJob), (void *)(1));
    }

    threadPool->processWork(jobQueue, 0xb);
    threadPool->RunWorkerThread();

    ::FUN_00d04380(semaphore, {});

    hkMemoryRouter::getInstance().heap().blockFree(jobHeader, sizeof(JobDoneHeader));
}
}  // namespace fnv_00c92290

extern const char str_010c64b8[];
extern const char str_010c41f8[];
extern void* DAT_010c6488;
struct TimerEntry { const char* name; unsigned int ticks; unsigned int unk08; };
struct TimerBuffer { unsigned int unk00; TimerEntry* current; unsigned int unk08; TimerEntry* end; };
struct __declspec(align(16)) LinearCaster {
    void* unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    float unk80;
};
struct QueryTree {
    virtual void slot00(); virtual void slot04(); virtual void slot08(); virtual void slot0C();
    virtual bool enabled();
    virtual void slot14(); virtual void slot18(); virtual void slot1C();
    virtual void cast(void*,void*,void*,void*,int,void*,void*);
};
struct CollisionInput {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    int unk70;
};
struct WorldQuery : hkpWorld { void FUN_00c92430(void*,void*,void*,void*); };
// Records a timer, then performs a collision cast via the KD-tree manager if enabled, otherwise via a linear caster, and records a second timer.
// @fnv 0x00c92430
void WorldQuery::FUN_00c92430(void* a,void* b,void* c,void* d) {
    TimerBuffer* timer = (TimerBuffer*)TlsGetValue(DAT_0126835c);
    TimerEntry* entry = timer->current;
    if (entry < timer->end) {
        entry->name = str_010c64b8;
        _ReadWriteBarrier();
        volatile unsigned int ticks = (unsigned int)__rdtsc();
        entry->ticks = ticks;
        timer->current = entry + 1;
    }
    if (m_pKdTreeManager && ((QueryTree*)m_pKdTreeManager)->enabled()) {
        void* filter = collidableCollidableFilterOf(m_pCollisionFilter);
        CollisionInput* input = (CollisionInput*)m_pCollisionInput;
        ((QueryTree*)m_pKdTreeManager)->cast(a,b,filter,input,input->unk70,c,d);
    } else {
        LinearCaster caster;
        caster.unk80 = ::DAT_0104da4c;
        caster.unk00 = &DAT_010c6488;
        caster.unk24 = 0;
        reinterpret_cast<::S_00cfaed0_This *>(&(caster))->FUN_00cfaed0((::S_00cfaed0_Iface *)(m_pJobSemaphore),(::S_00cfaed0_P2 *)(a),(::S_00cfaed0_P3 *)(b),collidableCollidableFilterOf(m_pCollisionFilter),(::S_00cfaed0_P5 *)(m_pCollisionInput),((CollisionInput*)m_pCollisionInput)->unk70,0,c,d);
    }
    timer = (TimerBuffer*)TlsGetValue(DAT_0126835c);
    entry = timer->current;
    if (entry < timer->end) {
        entry->name = ::DAT_010c41f8;
        _ReadWriteBarrier();
        volatile unsigned int ticks = (unsigned int)__rdtsc();
        entry->ticks = ticks;
        timer->current = entry + 1;
    }
}

namespace fnv_00c92540 {



struct JobHeader {
    unsigned char m_eJobType;
    unsigned char m_ucSubType;
    unsigned char m_executionFlags;
    unsigned char unk03;
    unsigned short m_jobSize;
    short m_iAffinity;

    JobHeader(unsigned char type, unsigned char subType, unsigned short size, short affinity = -1)
        : m_eJobType(type), m_ucSubType(subType), m_jobSize(size), m_iAffinity(affinity) {}
};

struct LinearCastCommand {
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    int m_uiFilterInfo;
    void* m_pResultBuffer;
    int m_iResultCount;
    int m_iResultCapacity;
};

struct JobDoneHeader {
    int m_iJobId;
    int unk04;
    int unk08;
    int unk0C;
};

struct JobBase {
    JobHeader m_kHeader;
    int unk08;
    int unk0C;
    void* m_pCompletionSemaphore;
    JobDoneHeader* m_pJobDoneHeader;
    void* m_pCollisionInput;
    int unk1C;

    __forceinline JobBase(unsigned char subType, unsigned short size)
        : m_kHeader(4, subType, size)
    {
        unk1C = 0;
    }
};

__declspec(align(16)) struct Job : JobBase {
    int m_maxNumResults;
    LinearCastCommand* m_pCommands;
    int m_iCommandCount;
    void* m_pJobSemaphore;
    int unk30;
    void* m_kdTreeUnk0C;
    void* m_kdTreeUnk10;
    int unk3C;

    __forceinline Job(void* input, JobDoneHeader* jobHeader, LinearCastCommand* commandArray, int numCommands, void* broadphase, void* semaphore)
        : JobBase(2, sizeof(Job))
    {
        m_pJobDoneHeader = jobHeader;
        m_pCollisionInput = input;
        m_maxNumResults = 0x40;
        m_pCompletionSemaphore = semaphore;
        m_pCommands = commandArray;
        m_iCommandCount = numCommands;
        m_pJobSemaphore = broadphase;
        jobHeader->m_iJobId = (numCommands - 1) / 64 + 1;
        unk30 = 0;
        m_kdTreeUnk0C = 0;
        m_kdTreeUnk10 = 0;
    }
};

struct JobQueue {
};

struct ThreadPool {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void processWork(JobQueue* queue, int type);
    virtual void RunWorkerThread();
};

struct KdTreeManager {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual bool isTreeActive();
    int unk04;
    int unk08;
    void* m_treeData0C;
    void* m_treeData10;
};

struct hkpWorldHelper : hkpWorld {
    void ExecuteLinearCastCommands(LinearCastCommand* commandArray, int numCommands, JobQueue* jobQueue, ThreadPool* threadPool, void* semaphore, int numCommandsPerJob);
};

// Splits the commands into jobs of numCommandsPerJob queued on jobQueue, runs the thread pool, then calls FUN_00d04380 on semaphore.
// @fnv 0x00c92540
void hkpWorldHelper::ExecuteLinearCastCommands(LinearCastCommand* commandArray, int numCommands, JobQueue* jobQueue, ThreadPool* threadPool, void* semaphore, int numCommandsPerJob) {
    JobDoneHeader* jobHeader = static_cast<JobDoneHeader*>(hkMemoryRouter::getInstance().heap().blockAlloc(sizeof(JobDoneHeader)));

    Job job(m_pCollisionInput, jobHeader, commandArray, numCommands, m_pJobSemaphore, semaphore);

    if (m_pKdTreeManager && ((KdTreeManager*)m_pKdTreeManager)->isTreeActive()) {
        KdTreeManager* kd = (KdTreeManager*)m_pKdTreeManager;
        job.m_pJobSemaphore = 0;
        job.m_kdTreeUnk0C = kd->m_treeData0C;
        job.m_kdTreeUnk10 = kd->m_treeData10;
    }
    job.m_kHeader.m_executionFlags = 1;

    while (job.m_iCommandCount > 0) {
        Job subJob = job;
        subJob.m_iCommandCount = (job.m_iCommandCount < numCommandsPerJob) ? job.m_iCommandCount : numCommandsPerJob;
        job.m_pCommands += numCommandsPerJob;
        job.m_iCommandCount -= numCommandsPerJob;
        reinterpret_cast<::D04B90World *>((jobQueue))->AddObjectCopy((const ::D04B90Object *)&(subJob), (void *)(1));
    }

    threadPool->processWork(jobQueue, 0xb);
    threadPool->RunWorkerThread();

    ::FUN_00d04380(semaphore, {});

    hkMemoryRouter::getInstance().heap().blockFree(jobHeader, sizeof(JobDoneHeader));
}
}  // namespace fnv_00c92540


struct zzVal_c92860 { void* v; };

// Calls FUN_00c927f0 on each owner in m_owners1 and m_owners2 with the given value.
// @fnv 0x00c92860
static __declspec(noinline) void InvokeOnAllOwners(FUN_00c928c0_Context* ctx, zzVal_c92860 value)
{
    void* v = value.v;
    FUN_00c928c0_ActionOwner** p = ctx->m_owners1;
    while (p != ctx->m_owners1 + ctx->m_ownerCount1)
    {
        ::FUN_00c927f0((::hkWorldC927 *)(*p), (::hkSetC927 *)(v));
        ++p;
    }

    p = ctx->m_owners2;
    while (p != ctx->m_owners2 + ctx->m_ownerCount2)
    {
        ::FUN_00c927f0((::hkWorldC927 *)(*p), (::hkSetC927 *)(v));
        ++p;
    }
}

FUN_00c928c0_Context* volatile zz_ctx_c92860 = 0;
void* volatile zz_val_c92860 = 0;

void zz_call_c92860(void)
{
    zzVal_c92860 s;
    s.v = zz_val_c92860;
    InvokeOnAllOwners(zz_ctx_c92860, s);
}


class EntityC92B;

class IslandC92B {
public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned short m_usStorageIndex;
    unsigned short unk22;
    int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    int** m_pEntities;
};

class EntityC92B {
public:
    int unk00, unk04, unk08;
    IslandC92B* m_pSimulationIsland;
};

template <class T>
struct hkSmallArrayC92B {
    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fff; }
    void AddBack(const T& e)
    {
        if (m_iElementCount == getCapacity())
            ::FUN_00d06cb0((::GrowBuf *)(void *)(this), sizeof(T));
        m_data[m_iElementCount++] = e;
    }
};

class WorldC92B {
public:
    int unk00[0xcc / 4];
    IslandC92B* m_pFixedIsland;
    int unkD0[(0xe8 - 0xd0) / 4];
    unsigned char m_iMaxEntriesPerNarrowphaseToiTask;
    unsigned char unkE9[0x208 - 0xe9];
    hkSmallArrayC92B<EntityC92B*> m_kActorEntries;
};

class ListenerC92B {
public:
    void FUN_00c92bd0(EntityC92B* pkEntity, WorldC92B* pkWorld);
};


// Appends pkEntity to m_kActorEntries; moves it to the fixed island if its island's storage index is 0xffff, else calls FUN_00cb5570 if islands differ.
// @fnv 0x00c92bd0
void ListenerC92B::FUN_00c92bd0(EntityC92B* pkEntity, WorldC92B* pkWorld)
{
    pkWorld->m_kActorEntries.AddBack(pkEntity);
    IslandC92B* pkIsland = pkEntity->m_pSimulationIsland;
    if (pkIsland->m_usStorageIndex == 0xffff && pkWorld->m_iMaxEntriesPerNarrowphaseToiTask != 5) {
        reinterpret_cast<::SaveBuffer *>((pkIsland))->RemoveEntry((::FUN_00d07130Arg *)(pkEntity));
        reinterpret_cast<::FUN_00d07470_cls *>((pkWorld->m_pFixedIsland))->AddItem((::ListItem *)(pkEntity));
        return;
    }
    if (pkWorld->m_pFixedIsland != pkIsland && pkWorld->m_iMaxEntriesPerNarrowphaseToiTask != 5)
        ::FUN_00cb5570((::ObjA *)(::ListenerC92B *)(this), (::ObjB *)(pkWorld), (::ObjB *)(pkIsland->m_pEntities[0]));
}

class FUN_00c905b0_s {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

};

class ActionC92C : public FUN_00c905b0_s {
public:
    void* m_pOwningWorld;

};

template <class T>
class hkArrayC92C {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t, int iStart = 0, int iEnd = -1) const
    {
        if (iEnd < 0)
            iEnd = m_iElementCount;
        for (int i = iStart; i < iEnd; ++i) {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    void removeAt(int iIndex)
    {
        m_iElementCount--;
        if (m_iElementCount != iIndex)
            m_data[iIndex] = m_data[m_iElementCount];
    }
};

class WorldC92C;

struct RemoveActionOpC92C {
    unsigned char m_type;
    ActionC92C* m_pAction;
};

class WorldC92C {
public:
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088;
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int m_iCriticalOperationsLockCountForPhantoms;
    bool m_bBlockExecutingPendingOperations;
    char unk09D[3];
    int unkA0;
    int m_iPendingOperationQueueCount;
    int unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC, unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4;
    int unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104;
    int unk108, unk10C;
    hkArrayC92C<ActionC92C*> m_ppActions;

    bool areCriticalOperationsLocked() const
    {
        return m_iCriticalOperationsLockCount + m_iCriticalOperationsLockCountForPhantoms != 0;
    }
    void lockCriticalOperations() { m_iCriticalOperationsLockCount++; }
    void unlockCriticalOperations()
    {
        if (--m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations) {
            if (m_iPendingOperationCount)
                reinterpret_cast<::FUN_00c91120 *>(this)->ExecutePendingOperations();
            if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount)
                reinterpret_cast<::FUN_00c91140_Class *>(this)->FUN_00c91140();
        }
    }
    void FUN_00c91120();
    void FUN_00c92c70(ActionC92C* pkAction);
};
// Caps the count at 200, then for each array element updates it via the v37 queue, calls g36, removes its reference, and finally zeroes the array and count.
// @fnv 0x00c676e0
void This676::ClearIndexedValues()
{
    Guard676 guard;
    if (m_uiItemCount > 0u)
    {
        if (m_uiItemCount >= 200u) m_uiItemCount = 200u;
        Q676* q = (Q676*)v37();
        if (q != 0)
        {
            q->FUN_00c954e0(m_aiIndexedValues, (int)m_uiItemCount);
            for (unsigned int i = 0; i < m_uiItemCount; i++)
            {
                Elem676* e = m_aiIndexedValues[i];
                if (e != 0)
                {
                    Sub676* c = e->m_iThirdValue;
                    if (c != 0)
                    {
                        c->m_14 &= 0xef;
                        goto body_cont;
                    }
                }
                reinterpret_cast<::WorldC92C *>((q))->FUN_00c92c70((::ActionC92C *)(e));
body_cont:
                ;
                Elem676* e2 = m_aiIndexedValues[i];
                GC676 slot;
                GC676* r = FUN_00c85ef0(&slot, e2, &(*reinterpret_cast<unsigned char *>(&::g_01267b70)));
                GCObj676* o = (GCObj676*)r->m_p;
                if (o != 0)
                {
                    Tmp676 tmp = { 0.0f, 0, 0, 0, 0, 0 };
                    o->g36(&tmp);
                }
                reinterpret_cast<::hkReferencedObjectC905 *>((m_aiIndexedValues[i]))->FUN_00c905b0();
            }
            ::std::memset(m_aiIndexedValues, 0, m_uiItemCount * 4);
            m_uiItemCount = 0;
        }
    }
}

// Removes pkAction from the world's action list, either by queueing a deferred removal or by executing it immediately under a critical lock.
// @fnv 0x00c92c70
void WorldC92C::FUN_00c92c70(ActionC92C* pkAction)
{
    if (areCriticalOperationsLocked()) {
        RemoveActionOpC92C kOp;
        kOp.m_type = 0xe;
        kOp.m_pAction = pkAction;
        reinterpret_cast<::WorldWithPending *>(this)->FUN_00c91160();
        return;
    }
    lockCriticalOperations();
    ::FUN_00d00820((::D00820World *)(::WorldC92C *)(this), pkAction);
    reinterpret_cast<::Fun_cls *>((pkAction))->FUN_00d07b50();
    ::FUN_00cb5d00((::S_00cb5d00_Owner *)(::WorldC92C *)(this), (::S_00cb5d00_Query *)(pkAction));
    m_ppActions.removeAt(m_ppActions.indexOf(pkAction));
    pkAction->m_pOwningWorld = 0;
    if (pkAction->m_usMemSizeAndFlags == 0)
        pkAction->vf34();
    reinterpret_cast<::hkReferencedObjectC905 *>((pkAction))->FUN_00c905b0();
    unlockCriticalOperations();
}

template <int SIZE>
__forceinline void memCpyOneAlignedXc937a0(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}



template <class T>
class hkArrayXc937a0 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline void AddBack(const T& e)
    {
        hkMemoryRouter& router = hkMemoryRouter::getInstance();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(router.m_heap), (::AudioStream *)(void *)(this), sizeof(T));
        memCpyOneAlignedXc937a0<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};

class hkOwnerXc937a0 {
public:
    int unk00[71];
    hkArrayXc937a0<void*> m_kNode;

    void FUN_00c937a0(void* item);
};

// @fnv 0x00c937a0
void hkOwnerXc937a0::FUN_00c937a0(void* item)
{
    m_kNode.AddBack(item);
}


template <typename T> struct hkArrayC93 {
    __forceinline ~hkArrayC93() throw()
    {
        hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class hkBaseObjectC93 {
public:
    virtual ~hkBaseObjectC93() throw() {}
};
class hkReferencedObjectC93 : public hkBaseObjectC93 {
public:
    void RetainReference() const throw();
    void removeReference() const throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

template <typename T> struct hkRefPtrC93 {
    __forceinline ~hkRefPtrC93() throw()
    {
        if (m_pRetainedObject) reinterpret_cast<::hkReferencedObjectC905 *>((void *)(m_pRetainedObject))->FUN_00c905b0();
        m_pRetainedObject = 0;
    }
    __forceinline void operator=(T* e) throw()
    {
        if (e) e->RetainReference();
        if (m_pRetainedObject) reinterpret_cast<::hkReferencedObjectC905 *>((void *)(m_pRetainedObject))->FUN_00c905b0();
        m_pRetainedObject = e;
    }
    T* m_pRetainedObject;
};

class WorldDeletableC93 {
public:
    virtual ~WorldDeletableC93() throw();
};

struct ChunkBufferC93 {
    __forceinline ~ChunkBufferC93() throw()
    {
        if (m_pBuffer) hkMemoryRouter::getInstance().heap().blockFree(m_pBuffer, 0x200);
    }
    void* m_pBuffer;
};

struct MtSimulationJobDataC93 {
    __forceinline void operator delete(void* p) throw() { if (p) hkMemoryRouter::getInstance().heap().blockFree(p, sizeof(MtSimulationJobDataC93)); }
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    ChunkBufferC93 m_kBuffer;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
};

struct CollisionAgentConfigC93 {
    __forceinline void operator delete(void* p) throw() { if (p) hkMemoryRouter::getInstance().heap().blockFree(p, sizeof(CollisionAgentConfigC93)); }
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};

struct ProcessCollisionInputC93 {
    __forceinline void operator delete(void* p) throw() { if (p) hkMemoryRouter::getInstance().heap().blockFree(p, sizeof(ProcessCollisionInputC93)); }
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    ChunkBufferC93 m_kBuffer;
    unsigned int unk68;
    unsigned int unk6c;
    CollisionAgentConfigC93* m_pConfiguration;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
};


struct CriticalSectionC93 {
    __forceinline void operator delete(void* p) throw() { if (p) hkMemoryRouter::getInstance().heap().blockFree(p, sizeof(CriticalSectionC93)); }
    __forceinline ~CriticalSectionC93() throw() { DeleteCriticalSection(&m_kCriticalSection); }
    CRITICAL_SECTION m_kCriticalSection;
};

struct BroadPhaseDispatcherC93 {
    __forceinline void operator delete(void* p) throw() { if (p) hkMemoryRouter::getInstance().heap().blockFree(p, sizeof(BroadPhaseDispatcherC93)); }
    ~BroadPhaseDispatcherC93() throw();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
};

struct WorldOperationQueueC93 {
    __forceinline void operator delete(void* p) throw() { if (p) hkMemoryRouter::getInstance().heap().blockFree(p, sizeof(WorldOperationQueueC93)); }
    ~WorldOperationQueueC93() throw();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
};

struct ViolatedConstraintArrayC93 {
    __forceinline void operator delete(void* p) throw() { if (p) hkMemoryRouter::getInstance().heap().blockFree(p, sizeof(ViolatedConstraintArrayC93)); }
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
};

class hkBoolC93 {
public:
    hkBoolC93(bool b) throw() : m_cBooleanValue(b) {}
    char m_cBooleanValue;
};

class FUN_00c93e50 : public hkReferencedObjectC93 {
public:
    virtual ~FUN_00c93e50() throw();

    hkReferencedObjectC93* m_pSimulation;
    unsigned int unk0c;
    float m_gravityX;
    float m_gravityY;
    float m_gravityZ;
    float m_gravityW;
    WorldDeletableC93* m_pFixedIsland;
    void* m_pFixedRigidBody;
    hkArrayC93<void*> m_kActiveSimulationIslands;
    hkArrayC93<void*> m_kInactiveSimulationIslands;
    hkArrayC93<void*> m_kDirtySimulationIslands;
    hkReferencedObjectC93* m_pMaintenanceManager;
    hkRefPtrC93<hkReferencedObjectC93> m_pMemoryWatchDog;
    bool m_bAssertOnRunningOutOfSolverMemory;
    hkReferencedObjectC93* m_pJobSemaphore;
    hkReferencedObjectC93* m_pKdTreeManager;
    bool m_bUseKdTree;
    BroadPhaseDispatcherC93* m_pBroadPhaseDispatcher;
    WorldDeletableC93* m_pPhantomBroadPhaseListener;
    WorldDeletableC93* m_pEntityEntityBroadPhaseListener;
    WorldDeletableC93* m_pBroadPhaseBorderListener;
    MtSimulationJobDataC93* m_pMultithreadedSimulationJobData;
    ProcessCollisionInputC93* m_pCollisionInput;
    hkReferencedObjectC93* m_pCollisionFilter;
    hkReferencedObjectC93* m_pDispatcher;
    hkReferencedObjectC93* m_pConvexListCollisionFilter;
    WorldOperationQueueC93* m_pPendingOperations;
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int m_iCriticalOperationsLockCountForPhantoms;
    bool m_bBlockExecutingPendingOperations;
    bool m_bBlockExecutingPendingOperationQueues;
    void* m_pPendingOperationQueues;
    int m_iPendingOperationQueueCount;
    unsigned int m_multiThreadCheckThreadId;
    unsigned int m_multiThreadCheckMarks;
    bool m_bProcessActionsInSingleThread;
    bool m_bAllowUnconstrainedIslandJob;
    unsigned int m_uiMinDesiredIslandSize;
    CriticalSectionC93* m_pModifyConstraintCriticalSection;
    int m_iIsLocked;
    CriticalSectionC93* m_pIslandDirtyListCriticalSection;
    CriticalSectionC93* m_pPropertyMasterLock;
    bool m_bWantSimulationIslands;
    float m_fSnapCollisionToConvexEdgeThreshold;
    float m_fSnapCollisionToConcaveEdgeThreshold;
    bool m_bEnableToiWeldRejection;
    bool m_bWantDeactivation;
    bool m_bActivateOnBodyTransformChange;
    float m_fDeactivationReferenceDistance;
    float m_fToiCollisionResponseRotateNormal;
    int m_iMaxSectorsPerMidphaseTask;
    bool m_bProcessToisMultithreaded;
    int m_iMaxSectorsPerNarrowphaseTask;
    int m_iMaxEntriesPerMidphaseToiTask;
    int m_iMaxEntriesPerNarrowphaseToiTask;
    float m_fSimplifiedToiPenetrationThreshold;
    float m_fToiPenetrationThreshold;
    float m_fHigherToiPenetrationThreshold;
    float m_fForcedToiPenetrationThreshold;
    unsigned int m_uiLastEntityUid;
    unsigned int m_uiLastIslandUid;
    unsigned int m_uiLastConstraintUid;
    hkArrayC93<void*> m_kPhantoms;
    hkArrayC93<void*> m_kActionListeners;
    hkArrayC93<void*> m_kEntityListenerArray;
    hkArrayC93<void*> m_kPhantomListeners;
    hkArrayC93<void*> m_kConstraintListeners;
    hkArrayC93<void*> m_kWorldDeletionListeners;
    hkArrayC93<void*> m_kIslandActivationListeners;
    hkArrayC93<void*> m_kWorldPostSimulationListeners;
    hkArrayC93<void*> m_kWorldPostIntegrateListeners;
    hkArrayC93<void*> m_kWorldPostCollideListeners;
    hkArrayC93<void*> m_kIslandPostIntegrateListeners;
    hkArrayC93<void*> m_kIslandPostCollideListeners;
    hkArrayC93<void*> m_kContactListeners;
    hkArrayC93<void*> m_kContactImpulseLimitBreachedListeners;
    ViolatedConstraintArrayC93* m_pViolatedConstraintArray;
    hkReferencedObjectC93* m_pBroadPhaseBorder;
};


// Releases owned resources, removes references to simulation components, and calls FUN_00c93580 and FUN_00d00e80 during cleanup.
// @fnv 0x00c93e50
FUN_00c93e50::~FUN_00c93e50() throw()
{
    delete m_pMultithreadedSimulationJobData;

    reinterpret_cast<::hkReferencedObjectC905 *>((void *)(m_pMaintenanceManager))->FUN_00c905b0();
    m_pMaintenanceManager = 0;

    if (m_pModifyConstraintCriticalSection) {
        delete m_pModifyConstraintCriticalSection;
        m_pModifyConstraintCriticalSection = 0;
    }
    if (m_pPropertyMasterLock) {
        delete m_pPropertyMasterLock;
        m_pPropertyMasterLock = 0;
    }
    if (m_pIslandDirtyListCriticalSection) {
        delete m_pIslandDirtyListCriticalSection;
        m_pIslandDirtyListCriticalSection = 0;
    }

    m_pMemoryWatchDog = 0;

    reinterpret_cast<::FUN_00c93580_Class *>(this)->FUN_00c93580();

    reinterpret_cast<::FUN_00c91620_Class *>(this)->ProcessTarget((unsigned char *)(m_pFixedRigidBody), {});
    m_pFixedRigidBody = 0;

    ::ClearSlotReference((int *)(::FUN_00c93e50 *)(this), (int *)(m_pFixedIsland));
    delete m_pFixedIsland;
    m_pFixedIsland = 0;

    ::FUN_00d00e80((::D00E80World *)(::FUN_00c93e50 *)(this));

    reinterpret_cast<::hkReferencedObjectC905 *>((void *)(m_pJobSemaphore))->FUN_00c905b0();
    m_pJobSemaphore = 0;
    reinterpret_cast<::hkReferencedObjectC905 *>((void *)(m_pDispatcher))->FUN_00c905b0();
    m_pDispatcher = 0;

    delete m_pBroadPhaseDispatcher;

    if (m_pBroadPhaseBorder) reinterpret_cast<::hkReferencedObjectC905 *>((void *)(m_pBroadPhaseBorder))->FUN_00c905b0();

    delete m_pPhantomBroadPhaseListener;
    delete m_pEntityEntityBroadPhaseListener;
    delete m_pBroadPhaseBorderListener;

    reinterpret_cast<::hkReferencedObjectC905 *>((void *)(m_pCollisionFilter))->FUN_00c905b0();
    reinterpret_cast<::hkReferencedObjectC905 *>((void *)(m_pConvexListCollisionFilter))->FUN_00c905b0();

    delete m_pCollisionInput->m_pConfiguration;
    delete m_pCollisionInput;

    reinterpret_cast<::hkReferencedObjectC905 *>((void *)(m_pSimulation))->FUN_00c905b0();

    delete m_pPendingOperations;

    if (m_pKdTreeManager) reinterpret_cast<::hkReferencedObjectC905 *>((void *)(m_pKdTreeManager))->FUN_00c905b0();

    delete m_pViolatedConstraintArray;
}


template <typename T> struct hkArrayC97 {
    int GetLogicalSize() const { return m_iElementCount; }
    T& operator[](int i) { return m_data[i]; }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

template <typename T, int N> struct hkInplaceArrayC97 : public hkArrayC97<T> {
    hkInplaceArrayC97() throw()
    {
        this->m_data = m_kStorage;
        this->m_iElementCount = 0;
        this->m_iCapacityState = N | 0x80000000;
    }
    __forceinline ~hkInplaceArrayC97() throw()
    {
        hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
        this->m_iElementCount = 0;
        if ((this->m_iCapacityState & 0x80000000) == 0)
            kAlloc.bufFree(this->m_data, (this->m_iCapacityState & 0x3fffffff) * sizeof(T));
    }
    T m_kStorage[N];
};

struct hkSmallArrayUtilC97 {
public:
    static void __cdecl GrowArray(void* apvArray, int iSizeElem) throw();
};
template <typename T> struct hkSmallArrayC97 {
    int getCapacity() const { return m_iCapacityState & 0x3fff; }
    void AddBack(const T& t) throw()
    {
        if (m_iElementCount == getCapacity())
            ::FUN_00d06cb0((::GrowBuf *)(void *)(this), sizeof(T));
        m_data[m_iElementCount++] = t;
    }
    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;
};

class hkpActionC97;
class hkpWorldC97;

class hkpSimulationIslandC97 {
public:
    bool isFixed() const { return m_usStorageIndex == 0xffff; }
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned short m_usStorageIndex;
};

class hkpEntityC97 {
public:
    hkpSimulationIslandC97* GetSimulationIsland() const { return m_pSimulationIsland; }
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    hkpSimulationIslandC97* m_pSimulationIsland;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    hkSmallArrayC97<hkpActionC97*> m_ppActions;
};

class hkpActionC97 {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void GetEntities(hkArrayC97<hkpEntityC97*>& kEntitiesOut) throw();
    void RetainReference() const throw();
    void setWorld(hkpWorldC97* pkWorld) { m_pOwningWorld = pkWorld; }
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkpWorldC97* m_pOwningWorld;
};

struct hkWorldOperationC97 {
    enum Type { ADD_ACTION = 0xa };
    struct TypeTag {
        TypeTag(Type eType) : m_type(static_cast<unsigned char>(eType)) {}
        unsigned char m_type;
    };
    struct AddActionCommand : public TypeTag {
        AddActionCommand() : TypeTag(ADD_ACTION) {}
        hkpActionC97* m_pAction;
    };
};

struct hkpWorldOperationUtilC97 {
};
struct hkpWorldCallbackUtilC97 {
};

class hkpWorldC97 {
public:
    bool areCriticalOperationsLocked() const { return m_iCriticalOperationsLockCount != 0; }
    void lockCriticalOperations() { m_iCriticalOperationsLockCount++; }
    void unlockCriticalOperations() { m_iCriticalOperationsLockCount--; }
    __forceinline void attemptToExecutePendingOperations()
    {
        if (m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations) {
            if (m_iPendingOperationCount)
                reinterpret_cast<::FUN_00c91120 *>(this)->ExecutePendingOperations();
            if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount)
                reinterpret_cast<::FUN_00c91140_Class *>(this)->FUN_00c91140();
        }
    }
    __forceinline void unlockAndAttemptToExecutePendingOperations()
    {
        unlockCriticalOperations();
        attemptToExecutePendingOperations();
    }
    void ExecutePendingOperations() throw();
    hkpActionC97* FUN_00c97370(hkpActionC97* pkAction) throw();

    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int m_iCriticalOperationsLockCountForPhantoms;
    bool m_bBlockExecutingPendingOperations;
    bool m_bBlockExecutingPendingOperationQueues;
    void* m_pPendingOperationQueues;
    int m_iPendingOperationQueueCount;
};

// @fnv 0x00c97370
hkpActionC97* hkpWorldC97::FUN_00c97370(hkpActionC97* pkAction) throw()
{
    if (areCriticalOperationsLocked()) {
        hkWorldOperationC97::AddActionCommand kOp;
        kOp.m_pAction = pkAction;
        reinterpret_cast<::WorldWithPending *>(this)->FUN_00c91160();
        return 0;
    }

    reinterpret_cast<::FUN_00c90510_class *>((void *)(pkAction))->FUN_00c90510();
    lockCriticalOperations();

    hkInplaceArrayC97<hkpEntityC97*, 4> kEntities;
    pkAction->GetEntities(kEntities);
    pkAction->setWorld(this);

    hkpEntityC97* pkFirstMovableEntity = 0;
    for (int i = 0; i < kEntities.GetLogicalSize(); i++) {
        kEntities[i]->m_ppActions.AddBack(pkAction);

        hkpSimulationIslandC97* pkIsland = kEntities[i]->GetSimulationIsland();
        if (!pkIsland->isFixed()) {
            if (pkFirstMovableEntity == 0) {
                pkFirstMovableEntity = kEntities[i];
                reinterpret_cast<::FUN_00d07470_cls *>((pkIsland))->AddItem((::ListItem *)(pkAction));
            } else if (pkFirstMovableEntity->GetSimulationIsland() != pkIsland) {
                ::FUN_00cb5570((::ObjA *)(::hkpWorldC97 *)(this), (::ObjB *)(pkFirstMovableEntity), (::ObjB *)(kEntities[i]));
            }
        }
    }

    if (pkFirstMovableEntity == 0) {
        reinterpret_cast<::FUN_00d07470_cls *>((kEntities[0]->GetSimulationIsland()))->AddItem((::ListItem *)(pkAction));
    }

    unlockAndAttemptToExecutePendingOperations();
    ::NotifyActionAdded((::World833 *)(::hkpWorldC97 *)(this), (::hkpAction *)(pkAction));
    return pkAction;
}



namespace hkRouterC97E {
    
}

class hkRefObjC97E {
public:
    virtual ~hkRefObjC97E();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void* operator new(size_t nbytes)
    {
        hkRefObjC97E* b = static_cast<hkRefObjC97E*>(hkMemoryRouter::getInstance().heap().blockAlloc(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};

struct InfoC97E {
    int unk00;
    int unk04;
    int m_08;
};

class FUN_00cf3ea0 : public hkRefObjC97E {
public:
    int unk08[9];
    int m_2c;
    int unk30[2];

    FUN_00cf3ea0(void* a1, void* a2, InfoC97E* a3, bool a4) throw();
};

class FUN_00c97e30_C {
public:
    FUN_00cf3ea0* Create(void* a1, void* a2, InfoC97E* a3);
};

struct C97E80PendingOperation {
    unsigned char m_type;
    void* m_pAction;
};
struct C97E80Action {
    virtual void function00();
    virtual void function04();
    virtual void function08();
    virtual void function0C();
    virtual void function10();
    virtual void function14();
    virtual int getReferenceCount();
    unsigned int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    void* m_owner44;
};
struct C97E80Owner {
    int unk00, unk04;
    hkpWorld* m_pOwningWorld;
};
struct C97E80PendingShell {
};
struct C97E80RemoveShell {
    void FUN_00c97510(void* owner);
};
struct C97E80ActionChangeShell {
};
struct C97E80ReleaseShell {
};
struct C97E80CleanupShell {
    void FUN_00c91120();
};
struct C97E80Return { bool m_iResultCode; };
struct C97E80World : hkpWorld {
    C97E80Return FUN_00c97e80(C97E80Action* action);
};
// Returns the larger of fA and fB.
// @fnv 0x00c98210
float __cdecl FUN_00c98210(float fA, float fB)
{
    return (fA > fB) ? fA : fB;
}

struct __declspec(align(16)) FUN_00c987e0_Pose {
    hkVector4 translation;
    hkQuaternion rotation;
    hkVector4 scale;
};
struct FUN_00c98780_Obj {
};
struct FUN_00c987e0_Cls {
    void FUN_00c987e0(const void* a1,const void* a2,const void* a3,int color,hkUlong id,int tag);
};
struct __declspec(align(16)) EC98BE0Vector {
    float x;
    float y;
    float z;
    float w;
};
struct EC98BE0Owner {
    void FUN_00c98b60(EC98BE0Vector* position, float scalar, int color, hkUlong id, int tag);
    void FUN_00c98be0(const void* x, const void* y, float scalar, int color, hkUlong id, int tag);
};
// Constructs a position vector from x and y, then calls FUN_00c98b60 with that position, scalar, and the remaining arguments.
// @fnv 0x00c98be0
void EC98BE0Owner::FUN_00c98be0(const void* x, const void* y, float scalar, int a, hkUlong b, int c)
{
    EC98BE0Vector position;
    reinterpret_cast<::TransformedPosDAD *>(&(position))->FUN_00c7f7a0((*(const ::hkQsTransformDAD *)(x)), (*(const ::hkVector4DAD *)(y)));
    FUN_00c98b60(&position, scalar, a, b, c);
}

struct __declspec(align(16)) FUN_00c7f640_Class {
    void FUN_00c7f640(const void* m, const void* p);
};

struct FUN_00c98c30_Class {
    void FUN_00c98b60(const void* p, float c, int color, hkUlong id, int tag);
    void FUN_00c98c30(const void* a, const void* b, float c, int color, hkUlong id, int tag);
};

// Builds a temporary via FUN_00c7f640(a, b), then calls FUN_00c98b60 with its address and c, d, e, f.
// @fnv 0x00c98c30
void FUN_00c98c30_Class::FUN_00c98c30(const void* a, const void* b, float c, int d, hkUlong e, int f)
{
    FUN_00c7f640_Class v;
    v.FUN_00c7f640(a, b);
    FUN_00c98b60(&v, c, d, e, f);
}


template <class T>
class hkArrayC995 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++) {
            if (m_data[i] == t) {
                return i;
            }
        }
        return -1;
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index) {
            m_data[index] = m_data[m_iElementCount];
        }
    }
};

class hkListenerListC995 {
public:
    int unk00;
    int unk04;
    hkArrayC995<void*> m_kListeners;
    CRITICAL_SECTION* m_pWorldLock;

    void RemoveListener(void* listener);
};

// Removes the given listener from m_kListeners under m_pWorldLock.
// @fnv 0x00c99590
void hkListenerListC995::RemoveListener(void* listener)
{
    EnterCriticalSection(m_pWorldLock);
    int i = m_kListeners.indexOf(listener);
    if (i >= 0) {
        m_kListeners.removeAt(i);
    }
    LeaveCriticalSection(m_pWorldLock);
}

namespace fnv_00c99ce0 {
extern void (* DAT_00fdf100)(int* pLock);

template <int SIZE>
__forceinline void memCpyOneAlignedXc99ce0(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}



template <class T>
class hkArrayXc99ce0 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline void AddBack(const T& e)
    {
        hkMemoryRouter& router = hkMemoryRouter::getInstance();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(router.m_heap), (::AudioStream *)(void *)(this), sizeof(T));
        memCpyOneAlignedXc99ce0<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};

class hkOwnerXc99ce0 {
public:
    int unk00[2];
    hkArrayXc99ce0<void*> m_kNode;
    int* m_lock;

    void Add(void* item);
};

// @fnv 0x00c99ce0
void hkOwnerXc99ce0::Add(void* item)
{
    DAT_00fdf05c(m_lock);
    m_kNode.AddBack(item);
    DAT_00fdf100(m_lock);
}
}  // namespace fnv_00c99ce0

struct S_00ce5290_Bool
{
    char m_cBooleanValue;
};

class Ce52e0Helper
{
public:
    void FUN_00ce52e0(const void* a);
};

// @fnv 0x00ce52e0
void Ce52e0Helper::FUN_00ce52e0(const void* a)
{
    reinterpret_cast<::S_00ce5290*>(this)->SetFromInput(a);
}

class hkpWorldD0AD;

class hkMemberD0AD {
public:
};

class hkListenerAD0AD {
public:
    virtual void onA();
};

class hkListenerBD0AD {
public:
    virtual void onB();
};

class hkReferencedObjectD0AD {
public:
    virtual ~hkReferencedObjectD0AD();
    int m_memSizeAndRefCount;
};

class hkSharedD0AD : public hkReferencedObjectD0AD, public hkListenerAD0AD, public hkListenerBD0AD {
public:
    int m_useCount;
    hkMemberD0AD m_kMemberDescriptor;
};

class hkpWorldD0AD {
public:
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C;
    int unk090, unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC;
    int unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C;
    int unk150, unk154, unk158, unk15C, unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C, unk1A0, unk1A4, unk1A8, unk1AC;
    int unk1B0, unk1B4, unk1B8, unk1BC;
    hkSharedD0AD* m_pSharedObject;

};

// Decrements the shared object's m_useCount and at zero calls FUN_00d9e280 on its member, FUN_00c91750 and FUN_00c91a70 on the world, then FUN_00c905b0.
// @fnv 0x00d0adf0
void __cdecl ReleaseSharedObject(hkpWorldD0AD* pkWorld)
{
    hkSharedD0AD* pkShared = pkWorld->m_pSharedObject;
    if (--pkShared->m_useCount == 0) {
        reinterpret_cast<::S_00d9e280_D *>(&(pkShared->m_kMemberDescriptor))->FUN_00d9e280((::S_00d9e280_World *)(pkWorld));
        reinterpret_cast<::hkWorldC9175 *>((pkWorld))->FUN_00c91750(pkShared);
        reinterpret_cast<::hkWorldXc91a70 *>((pkWorld))->FUN_00c91a70(pkShared);
        reinterpret_cast<::hkReferencedObjectC905 *>((pkShared))->FUN_00c905b0();
    }
}

class FlagState {
public:
    unsigned int unk00, unk04;
    unsigned char unk08, state;
    unsigned short first, second;
    void SetFlagBits(unsigned int a, unsigned int b, int code);
};
// @fnv 0x00c914d0
hkpEntityC914* hkpWorldC914::FUN_00c914d0(hkpEntityC914* pkEntity, int iInitialActivationState) throw()
{
    if (areCriticalOperationsLocked()) {
        hkWorldOperationAddEntityC914 kOp;
        kOp.m_pEntity = pkEntity;
        kOp.m_iActivationState = iInitialActivationState;
        reinterpret_cast<::WorldWithPending *>(this)->FUN_00c91160();
        return 0;
    }

    reinterpret_cast<::hkpEntityC9C0 *>((pkEntity))->UpdateBoundingVolume((const ::hkpWorldC9C0 *)(::hkpWorldC914 *)(this), (const ::hkpShapeC9C0 *)(pkEntity->m_pCollisionShape));
    if (pkEntity->m_pMotionState == 0)
        pkEntity->m_pMotionState = pkEntity->getMotion();

    FUN_00cf1480(0.0f, 0.0f, &pkEntity->m_f0);
    pkEntity->m_ea = 0;
    pkEntity->m_ec = 0;
    m_bBlockExecutingPendingOperationQueues = false;
    pkEntity->m_uiUniqueId = ++m_uiLastEntityUid;
    reinterpret_cast<::FUN_00c90510_class *>((pkEntity))->FUN_00c90510();
    ::fnv_00cb4640::FUN_00cb4640((::fnv_00cb4640::TaskCtx *)(::hkpWorldC914 *)(this), (::fnv_00cb4640::TaskCtx *)(pkEntity), iInitialActivationState);
    reinterpret_cast<::FlagState *>(&(pkEntity->m_e0))->SetFlagBits(m_305, m_306, m_307);

    lockCriticalOperations();
    m_bBlockExecutingPendingOperationQueues = true;
    ::fnv_00cb59f0::FUN_00cb59f0((::fnv_00cb59f0::S_00cb59f0_A *)(::hkpWorldC914 *)(this), (::fnv_00cb59f0::S_00cb59f0_B *)(pkEntity));
    ::fnv_00d00500::NotifyEntityAdded((::fnv_00d00500::World833 *)(::hkpWorldC914 *)(this), (::fnv_00d00500::hkpEntity *)(pkEntity));
    ::FUN_00cffa00((::ProfOwner_cffa00 *)(pkEntity));
    unlockAndAttemptToExecutePendingOperations();
    return pkEntity;
}
// Sets the top two bits of first from a and of second from b, inverting a if (code & 3) < (state & 3) and b if code < state.
// @fnv 0x00c90ed0
void FlagState::SetFlagBits(unsigned int a, unsigned int b, int code) {
    int previous = state;
    unsigned int x = ((unsigned int)(code & 3) < (unsigned int)(previous & 3) ? ~a : a);
    unsigned int y = b;
    x <<= 14;
    if (code < previous) y = ~y;
    first = (unsigned short)((first & 0x3fff) | x);
    second = (unsigned short)((second & 0x3fff) | (y << 14));
}

struct OverlapResult {
    char value;
    OverlapResult() {}
};
struct OverlapPhantom;
struct OverlapCollidable {
    int unk00, unk04, unk08, unk0c;
    signed char ownerOffset;
    char unk11, unk12, unk13;
    int unk14;
    char type;
    OverlapPhantom* owner() {
        return reinterpret_cast<OverlapPhantom*>(reinterpret_cast<char*>(this) + ownerOffset);
    }
};
struct OverlapPhantom {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void add(OverlapCollidable*);
    virtual OverlapResult overlaps(OverlapCollidable*);
    virtual void remove(OverlapCollidable*);
    int unk04, unk08, unk0c;
    OverlapCollidable collidable;
};
struct OverlapFilter {
    virtual void v00();
    virtual OverlapResult enabled(OverlapCollidable*, OverlapCollidable*);
};
struct OverlapContext {
    int unk00, unk04;
    OverlapFilter filter;
};
// Adds or removes other from phantom and, when other is type 2, mirrors the change on other's owner based on the filter result.
// @fnv 0x00c90f40
static __declspec(noinline) void SyncOverlap(OverlapPhantom* phantom, OverlapCollidable* other, OverlapContext* context)
{
    OverlapResult old = phantom->overlaps(other);
    if (context->filter.enabled(&phantom->collidable, other).value) {
        if (!old.value)
            phantom->add(other);
        if (other->type == 2) {
            OverlapResult otherOld = other->owner()->overlaps(&phantom->collidable);
            if (!otherOld.value)
                other->owner()->add(&phantom->collidable);
        }
    } else {
        if (old.value)
            phantom->remove(other);
        if (other->type == 2) {
            OverlapResult otherOld = other->owner()->overlaps(&phantom->collidable);
            if (otherOld.value)
                other->owner()->remove(&phantom->collidable);
        }
    }
}
OverlapPhantom* volatile overlapPhantom;
OverlapCollidable* volatile overlapOther;
OverlapContext* volatile overlapContext;
void invokeOverlap() {
    SyncOverlap(overlapPhantom, overlapOther, overlapContext);
}

// @fnv 0x00c910b0
void FUN_00c910b0()
{
}

// @fnv 0x00c911b0
void __cdecl FUN_00c911b0(void)
{
}

extern int DAT_010c6420;
extern int DAT_010c6378;

struct CFB240ContactMgrFactory {
    virtual ~CFB240ContactMgrFactory();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* operator new(size_t n) {
        CFB240ContactMgrFactory* b = static_cast<CFB240ContactMgrFactory*>(hkMemoryRouter::getInstance().heap().blockAlloc(n));
        b->m_usMemSizeAndFlags = (unsigned short)n;
        return b;
    }
    void operator delete(void*) {}
    void removeReference() throw();
    CFB240ContactMgrFactory() throw() { m_sReferenceCount = 1; }
};
struct FUN_00cfd450 : CFB240ContactMgrFactory {
    int unk08;
    FUN_00cfd450(void*) throw();
public:
    FUN_00cfd450(::hkWorldCFD4 *);
};
struct FUN_00cfca20 : CFB240ContactMgrFactory {
    int unk08;
    FUN_00cfca20(void*) throw();
};
struct OtherC912 {
    void* vtable; short unknown; short refs; int kind;
    OtherC912() throw() { refs = 1; kind = 3; vtable = &DAT_010c6378; }
};
struct FactoryThreeC912 : CFB240ContactMgrFactory {
    OtherC912 other;
    virtual ~FactoryThreeC912();
    FactoryThreeC912() throw()
    {
    }
};
struct CFB240Dispatcher {
    void SetContactMgrFactory(CFB240ContactMgrFactory*, int);
};

// Creates two factories from world and a third, registers them with the dispatcher at slots 1, 2 and 3, then releases the local references.
// @fnv 0x00c912e0
static void RegisterContactMgrFactories(CFB240Dispatcher* dispatcher, void* world)
{
    FUN_00cfd450* first = new FUN_00cfd450(world);
    FUN_00cfca20* second = new FUN_00cfca20(world);
    FactoryThreeC912* third = new FactoryThreeC912;
    dispatcher->SetContactMgrFactory(first, 1);
    dispatcher->SetContactMgrFactory(second, 2);
    dispatcher->SetContactMgrFactory(third, 3);
    reinterpret_cast<::hkReferencedObjectC905 *>((((FUN_00d1df70*)first)))->FUN_00c905b0();
    reinterpret_cast<::hkReferencedObjectC905 *>((((FUN_00d1df70*)second)))->FUN_00c905b0();
    reinterpret_cast<::hkReferencedObjectC905 *>((((FUN_00d1df70*)third)))->FUN_00c905b0();
}

void c912e0_caller(CFB240Dispatcher* d, void* w)
{
    RegisterContactMgrFactories(d, w);
}

struct Shape64 {};
struct Container64 {
    void AddShape(Shape64* shape);
};
struct Shape64List {
    Shape64** data;
    int count;
};
struct Element64 {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14;
    int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44;
    Shape64List shapes;
};
struct Context64 {
    int unk00; int unk04; int unk08; int unk0C; int unk10;
    int unk14; int unk18; int unk1C; int unk20; int unk24;
    Element64** elements;
    int elementCount;
};
// Adds every shape of every element in context to container, then stores whether elementCount is greater than zero in result.
// @fnv 0x00c92760
unsigned char* __cdecl CollectShapes(unsigned char* pbHasElements, Context64* context, Container64* volatile container)
{
    Element64** element = context->elements;
    if (element != context->elements + context->elementCount)
    {
        do
        {
            Shape64List* shapes = &(*element)->shapes;
            int index = 0;
            if (shapes->count > 0)
            {
                do
                {
                    container->AddShape(shapes->data[index]);
                    ++index;
                } while (index < shapes->count);
            }
            ++element;
        } while (element != context->elements + context->elementCount);
    }
    *pbHasElements = context->elementCount > 0;
    return pbHasElements;
}

struct BorderSet {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    hkpPhantom* p18;
    hkpPhantom* p1c;
    hkpPhantom* p20;
    hkpPhantom* p24;
    hkpPhantom* p28;
    hkpPhantom* p2c;
};
struct PhantomWorld : hkpWorld {
    BorderSet* FUN_00c91110();
};
struct PhantomSink {
    void FUN_00d064f0(hkpPhantom* p);
};
// Iterates the world's phantoms and sends each to out->FUN_00d064f0, skipping the six border phantoms when a BorderSet is present.
// @fnv 0x00c92950
static __declspec(noinline) void FUN_00c92950(PhantomWorld* world, PhantomSink* apSink)
{
    BorderSet* border = (::BorderSet *)(reinterpret_cast<::fnv_00c91110::CpuObject *>((world))->FUN_00c91110());
    if (border) {
        for (int i = 0; i < world->m_kPhantoms.m_iElementCount; ++i) {
            hkpPhantom* p = world->m_kPhantoms.m_data[i];
            if (p != border->p18 && p != border->p1c &&
                p != border->p20 && p != border->p24 &&
                p != border->p28 && p != border->p2c)
                reinterpret_cast<::hkOwnerD064 *>((apSink))->FUN_00d064f0((::hkShapeD064 *)(p));
        }
    } else {
        for (int i = 0; i < world->m_kPhantoms.m_iElementCount; ++i)
            reinterpret_cast<::hkOwnerD064 *>((apSink))->FUN_00d064f0((::hkShapeD064 *)(world->m_kPhantoms.m_data[i]));
    }
}
PhantomWorld* volatile g_world;
PhantomSink* volatile FnvHavok_hkpworld_g_out;
void invokePhantomCopy() { FUN_00c92950(g_world, FnvHavok_hkpworld_g_out); }

struct MonitorStream {
    char* start;
    char* current;
    char* saved;
    char* end;
};
struct MonitorRecord {
    const char* name;
    unsigned int time;
    unsigned int unused;
};
__forceinline void timer(const char* name, const char* first = 0) {
    MonitorStream* stream = (MonitorStream*)TlsGetValue(DAT_0126835c);
    char* current = stream->current;
    if (current < stream->end) {
        volatile MonitorRecord* record = (volatile MonitorRecord*)current;
        record->name = name;
        if (first) *(const char* volatile*)(current + sizeof(MonitorRecord)) = first;
        _ReadWriteBarrier();
        volatile unsigned int stamp = (unsigned int)__rdtsc();
        record->time = stamp;
        stream->current = current + (first ? 16 : 12);
    }
}
struct CollisionObject;
struct BroadphaseHandle {
    unsigned int id;
    unsigned char type;
    signed char ownerOffset;
    signed char quality;
    unsigned char flags;
};
struct CollisionObject {
    unsigned int shape;
    unsigned int shapeKey;
    unsigned int motion;
    unsigned int parent;
    signed char ownerOffset;
    unsigned char forceCollideOntoPpu;
    unsigned short shapeSize;
    BroadphaseHandle handle;
    unsigned int boundingVolume;
};
struct EntityState {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned char tail;
    unsigned char flags;
};
struct CollisionEntity {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    CollisionObject collidable;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    EntityState* state;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned char type;
};

struct FilterBool {
    char value;
    FilterBool() {}
    FilterBool(bool enabled) : value(enabled) {}
};
struct PhantomInterface {
    virtual void unused00(); virtual void unused04();
    virtual void unused08(); virtual void unused0c();
    virtual void unused10(); virtual void unused14();
    virtual void unused18();
    virtual void addOverlap(CollisionObject*);
    virtual FilterBool hasOverlap(CollisionObject*);
    virtual void removeOverlap(CollisionObject*);
    virtual void unused28(); virtual void unused2c();
    virtual void refresh();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CollisionObject collidable;
};
struct OverlapPair { BroadphaseHandle* first; BroadphaseHandle* second; OverlapPair() {} };
struct PairArray {
    OverlapPair* data;
    int size;
    int capacityAndFlags;
    OverlapPair storage[128];
    __forceinline void init() { data = storage; size = 0; capacityAndFlags = 0x80000080; }
};
struct Broadphase {
    virtual void unused00(); virtual void unused04();
    virtual void unused08(); virtual void unused0c();
    virtual void unused10(); virtual void unused14();
    virtual void unused18(); virtual void unused1c();
    virtual void unused20(); virtual void unused24();
    virtual void unused28(); virtual void unused2c();
    virtual void unused30(); virtual void unused34();
    virtual void unused38(); virtual void unused3c();
    virtual void unused40(); virtual void unused44();
    virtual void query(BroadphaseHandle*, PairArray*);
};
struct CollisionFilterInterface {
    virtual void unused00();
    virtual FilterBool enabled(CollisionObject*, CollisionObject*);
};
struct CollisionFilter {
    unsigned int unk00;
    unsigned int unk04;
    CollisionFilterInterface filter;
};
struct CollisionDispatcher {
    unsigned int unk0000;     unsigned int unk0004;     unsigned int unk0008;     unsigned int unk000C;
    unsigned int unk0010;     unsigned int unk0014;     unsigned int unk0018;     unsigned int unk001C;
    unsigned int unk0020;     unsigned int unk0024;     unsigned int unk0028;     unsigned int unk002C;
    unsigned int unk0030;     unsigned int unk0034;     unsigned int unk0038;     unsigned int unk003C;
    unsigned int unk0040;     unsigned int unk0044;     unsigned int unk0048;     unsigned int unk004C;
    unsigned int unk0050;     unsigned int unk0054;     unsigned int unk0058;     unsigned int unk005C;
    unsigned int unk0060;     unsigned int unk0064;     unsigned int unk0068;     unsigned int unk006C;
    unsigned int unk0070;     unsigned int unk0074;     unsigned int unk0078;     unsigned int unk007C;
    unsigned int unk0080;     unsigned int unk0084;     unsigned int unk0088;     unsigned int unk008C;
    unsigned int unk0090;     unsigned int unk0094;     unsigned int unk0098;     unsigned int unk009C;
    unsigned int unk00A0;     unsigned int unk00A4;     unsigned int unk00A8;     unsigned int unk00AC;
    unsigned int unk00B0;     unsigned int unk00B4;     unsigned int unk00B8;     unsigned int unk00BC;
    unsigned int unk00C0;     unsigned int unk00C4;     unsigned int unk00C8;     unsigned int unk00CC;
    unsigned int unk00D0;     unsigned int unk00D4;     unsigned int unk00D8;     unsigned int unk00DC;
    unsigned int unk00E0;     unsigned int unk00E4;     unsigned int unk00E8;     unsigned int unk00EC;
    unsigned int unk00F0;     unsigned int unk00F4;     unsigned int unk00F8;     unsigned int unk00FC;
    unsigned int unk0100;     unsigned int unk0104;     unsigned int unk0108;     unsigned int unk010C;
    unsigned int unk0110;     unsigned int unk0114;     unsigned int unk0118;     unsigned int unk011C;
    unsigned int unk0120;     unsigned int unk0124;     unsigned int unk0128;     unsigned int unk012C;
    unsigned int unk0130;     unsigned int unk0134;     unsigned int unk0138;     unsigned int unk013C;
    unsigned int unk0140;     unsigned int unk0144;     unsigned int unk0148;     unsigned int unk014C;
    unsigned int unk0150;     unsigned int unk0154;     unsigned int unk0158;     unsigned int unk015C;
    unsigned int unk0160;     unsigned int unk0164;     unsigned int unk0168;     unsigned int unk016C;
    unsigned int unk0170;     unsigned int unk0174;     unsigned int unk0178;     unsigned int unk017C;
    unsigned int unk0180;     unsigned int unk0184;     unsigned int unk0188;     unsigned int unk018C;
    unsigned int unk0190;     unsigned int unk0194;     unsigned int unk0198;     unsigned int unk019C;
    unsigned int unk01A0;     unsigned int unk01A4;     unsigned int unk01A8;     unsigned int unk01AC;
    unsigned int unk01B0;     unsigned int unk01B4;     unsigned int unk01B8;     unsigned int unk01BC;
    unsigned int unk01C0;     unsigned int unk01C4;     unsigned int unk01C8;     unsigned int unk01CC;
    unsigned int unk01D0;     unsigned int unk01D4;     unsigned int unk01D8;     unsigned int unk01DC;
    unsigned int unk01E0;     unsigned int unk01E4;     unsigned int unk01E8;     unsigned int unk01EC;
    unsigned int unk01F0;     unsigned int unk01F4;     unsigned int unk01F8;     unsigned int unk01FC;
    unsigned int unk0200;     unsigned int unk0204;     unsigned int unk0208;     unsigned int unk020C;
    unsigned int unk0210;     unsigned int unk0214;     unsigned int unk0218;     unsigned int unk021C;
    unsigned int unk0220;     unsigned int unk0224;     unsigned int unk0228;     unsigned int unk022C;
    unsigned int unk0230;     unsigned int unk0234;     unsigned int unk0238;     unsigned int unk023C;
    unsigned int unk0240;     unsigned int unk0244;     unsigned int unk0248;     unsigned int unk024C;
    unsigned int unk0250;     unsigned int unk0254;     unsigned int unk0258;     unsigned int unk025C;
    unsigned int unk0260;     unsigned int unk0264;     unsigned int unk0268;     unsigned int unk026C;
    unsigned int unk0270;     unsigned int unk0274;     unsigned int unk0278;     unsigned int unk027C;
    unsigned int unk0280;     unsigned int unk0284;     unsigned int unk0288;     unsigned int unk028C;
    unsigned int unk0290;     unsigned int unk0294;     unsigned int unk0298;     unsigned int unk029C;
    unsigned int unk02A0;     unsigned int unk02A4;     unsigned int unk02A8;     unsigned int unk02AC;
    unsigned int unk02B0;     unsigned int unk02B4;     unsigned int unk02B8;     unsigned int unk02BC;
    unsigned int unk02C0;     unsigned int unk02C4;     unsigned int unk02C8;     unsigned int unk02CC;
    unsigned int unk02D0;     unsigned int unk02D4;     unsigned int unk02D8;     unsigned int unk02DC;
    unsigned int unk02E0;     unsigned int unk02E4;     unsigned int unk02E8;     unsigned int unk02EC;
    unsigned int unk02F0;     unsigned int unk02F4;     unsigned int unk02F8;     unsigned int unk02FC;
    unsigned int unk0300;     unsigned int unk0304;     unsigned int unk0308;     unsigned int unk030C;
    unsigned int unk0310;     unsigned int unk0314;     unsigned int unk0318;     unsigned int unk031C;
    unsigned int unk0320;     unsigned int unk0324;     unsigned int unk0328;     unsigned int unk032C;
    unsigned int unk0330;     unsigned int unk0334;     unsigned int unk0338;     unsigned int unk033C;
    unsigned int unk0340;     unsigned int unk0344;     unsigned int unk0348;     unsigned int unk034C;
    unsigned int unk0350;     unsigned int unk0354;     unsigned int unk0358;     unsigned int unk035C;
    unsigned int unk0360;     unsigned int unk0364;     unsigned int unk0368;     unsigned int unk036C;
    unsigned int unk0370;     unsigned int unk0374;     unsigned int unk0378;     unsigned int unk037C;
    unsigned int unk0380;     unsigned int unk0384;     unsigned int unk0388;     unsigned int unk038C;
    unsigned int unk0390;     unsigned int unk0394;     unsigned int unk0398;     unsigned int unk039C;
    unsigned int unk03A0;     unsigned int unk03A4;     unsigned int unk03A8;     unsigned int unk03AC;
    unsigned int unk03B0;     unsigned int unk03B4;     unsigned int unk03B8;     unsigned int unk03BC;
    unsigned int unk03C0;     unsigned int unk03C4;     unsigned int unk03C8;     unsigned int unk03CC;
    unsigned int unk03D0;     unsigned int unk03D4;     unsigned int unk03D8;     unsigned int unk03DC;
    unsigned int unk03E0;     unsigned int unk03E4;     unsigned int unk03E8;     unsigned int unk03EC;
    unsigned int unk03F0;     unsigned int unk03F4;     unsigned int unk03F8;     unsigned int unk03FC;
    unsigned int unk0400;     unsigned int unk0404;     unsigned int unk0408;     unsigned int unk040C;
    unsigned int unk0410;     unsigned int unk0414;     unsigned int unk0418;     unsigned int unk041C;
    unsigned int unk0420;     unsigned int unk0424;     unsigned int unk0428;     unsigned int unk042C;
    unsigned int unk0430;     unsigned int unk0434;     unsigned int unk0438;     unsigned int unk043C;
    unsigned int unk0440;     unsigned int unk0444;     unsigned int unk0448;     unsigned int unk044C;
    unsigned int unk0450;     unsigned int unk0454;     unsigned int unk0458;     unsigned int unk045C;
    unsigned int unk0460;     unsigned int unk0464;     unsigned int unk0468;     unsigned int unk046C;
    unsigned int unk0470;     unsigned int unk0474;     unsigned int unk0478;     unsigned int unk047C;
    unsigned int unk0480;     unsigned int unk0484;     unsigned int unk0488;     unsigned int unk048C;
    unsigned int unk0490;     unsigned int unk0494;     unsigned int unk0498;     unsigned int unk049C;
    unsigned int unk04A0;     unsigned int unk04A4;     unsigned int unk04A8;     unsigned int unk04AC;
    unsigned int unk04B0;     unsigned int unk04B4;     unsigned int unk04B8;     unsigned int unk04BC;
    unsigned int unk04C0;     unsigned int unk04C4;     unsigned int unk04C8;     unsigned int unk04CC;
    unsigned int unk04D0;     unsigned int unk04D4;     unsigned int unk04D8;     unsigned int unk04DC;
    unsigned int unk04E0;     unsigned int unk04E4;     unsigned int unk04E8;     unsigned int unk04EC;
    unsigned int unk04F0;     unsigned int unk04F4;     unsigned int unk04F8;     unsigned int unk04FC;
    unsigned int unk0500;     unsigned int unk0504;     unsigned int unk0508;     unsigned int unk050C;
    unsigned int unk0510;     unsigned int unk0514;     unsigned int unk0518;     unsigned int unk051C;
    unsigned int unk0520;     unsigned int unk0524;     unsigned int unk0528;     unsigned int unk052C;
    unsigned int unk0530;     unsigned int unk0534;     unsigned int unk0538;     unsigned int unk053C;
    unsigned int unk0540;     unsigned int unk0544;     unsigned int unk0548;     unsigned int unk054C;
    unsigned int unk0550;     unsigned int unk0554;     unsigned int unk0558;     unsigned int unk055C;
    unsigned int unk0560;     unsigned int unk0564;     unsigned int unk0568;     unsigned int unk056C;
    unsigned int unk0570;     unsigned int unk0574;     unsigned int unk0578;     unsigned int unk057C;
    unsigned int unk0580;     unsigned int unk0584;     unsigned int unk0588;     unsigned int unk058C;
    unsigned int unk0590;     unsigned int unk0594;     unsigned int unk0598;     unsigned int unk059C;
    unsigned int unk05A0;     unsigned int unk05A4;     unsigned int unk05A8;     unsigned int unk05AC;
    unsigned int unk05B0;     unsigned int unk05B4;     unsigned int unk05B8;     unsigned int unk05BC;
    unsigned int unk05C0;     unsigned int unk05C4;     unsigned int unk05C8;     unsigned int unk05CC;
    unsigned int unk05D0;     unsigned int unk05D4;     unsigned int unk05D8;     unsigned int unk05DC;
    unsigned int unk05E0;     unsigned int unk05E4;     unsigned int unk05E8;     unsigned int unk05EC;
    unsigned int unk05F0;     unsigned int unk05F4;     unsigned int unk05F8;     unsigned int unk05FC;
    unsigned int unk0600;     unsigned int unk0604;     unsigned int unk0608;     unsigned int unk060C;
    unsigned int unk0610;     unsigned int unk0614;     unsigned int unk0618;     unsigned int unk061C;
    unsigned int unk0620;     unsigned int unk0624;     unsigned int unk0628;     unsigned int unk062C;
    unsigned int unk0630;     unsigned int unk0634;     unsigned int unk0638;     unsigned int unk063C;
    unsigned int unk0640;     unsigned int unk0644;     unsigned int unk0648;     unsigned int unk064C;
    unsigned int unk0650;     unsigned int unk0654;     unsigned int unk0658;     unsigned int unk065C;
    unsigned int unk0660;     unsigned int unk0664;     unsigned int unk0668;     unsigned int unk066C;
    unsigned int unk0670;     unsigned int unk0674;     unsigned int unk0678;     unsigned int unk067C;
    unsigned int unk0680;     unsigned int unk0684;     unsigned int unk0688;     unsigned int unk068C;
    unsigned int unk0690;     unsigned int unk0694;     unsigned int unk0698;     unsigned int unk069C;
    unsigned int unk06A0;     unsigned int unk06A4;     unsigned int unk06A8;     unsigned int unk06AC;
    unsigned int unk06B0;     unsigned int unk06B4;     unsigned int unk06B8;     unsigned int unk06BC;
    unsigned int unk06C0;     unsigned int unk06C4;     unsigned int unk06C8;     unsigned int unk06CC;
    unsigned int unk06D0;     unsigned int unk06D4;     unsigned int unk06D8;     unsigned int unk06DC;
    unsigned int unk06E0;     unsigned int unk06E4;     unsigned int unk06E8;     unsigned int unk06EC;
    unsigned int unk06F0;     unsigned int unk06F4;     unsigned int unk06F8;     unsigned int unk06FC;
    unsigned int unk0700;     unsigned int unk0704;     unsigned int unk0708;     unsigned int unk070C;
    unsigned int unk0710;     unsigned int unk0714;     unsigned int unk0718;     unsigned int unk071C;
    unsigned int unk0720;     unsigned int unk0724;     unsigned int unk0728;     unsigned int unk072C;
    unsigned int unk0730;     unsigned int unk0734;     unsigned int unk0738;     unsigned int unk073C;
    unsigned int unk0740;     unsigned int unk0744;     unsigned int unk0748;     unsigned int unk074C;
    unsigned int unk0750;     unsigned int unk0754;     unsigned int unk0758;     unsigned int unk075C;
    unsigned int unk0760;     unsigned int unk0764;     unsigned int unk0768;     unsigned int unk076C;
    unsigned int unk0770;     unsigned int unk0774;     unsigned int unk0778;     unsigned int unk077C;
    unsigned int unk0780;     unsigned int unk0784;     unsigned int unk0788;     unsigned int unk078C;
    unsigned int unk0790;     unsigned int unk0794;     unsigned int unk0798;     unsigned int unk079C;
    unsigned int unk07A0;     unsigned int unk07A4;     unsigned int unk07A8;     unsigned int unk07AC;
    unsigned int unk07B0;     unsigned int unk07B4;     unsigned int unk07B8;     unsigned int unk07BC;
    unsigned int unk07C0;     unsigned int unk07C4;     unsigned int unk07C8;     unsigned int unk07CC;
    unsigned int unk07D0;     unsigned int unk07D4;     unsigned int unk07D8;     unsigned int unk07DC;
    unsigned int unk07E0;     unsigned int unk07E4;     unsigned int unk07E8;     unsigned int unk07EC;
    unsigned int unk07F0;     unsigned int unk07F4;     unsigned int unk07F8;     unsigned int unk07FC;
    unsigned int unk0800;     unsigned int unk0804;     unsigned int unk0808;     unsigned int unk080C;
    unsigned int unk0810;     unsigned int unk0814;     unsigned int unk0818;     unsigned int unk081C;
    unsigned int unk0820;     unsigned int unk0824;     unsigned int unk0828;     unsigned int unk082C;
    unsigned int unk0830;     unsigned int unk0834;     unsigned int unk0838;     unsigned int unk083C;
    unsigned int unk0840;     unsigned int unk0844;     unsigned int unk0848;     unsigned int unk084C;
    unsigned int unk0850;     unsigned int unk0854;     unsigned int unk0858;     unsigned int unk085C;
    unsigned int unk0860;     unsigned int unk0864;     unsigned int unk0868;     unsigned int unk086C;
    unsigned int unk0870;     unsigned int unk0874;     unsigned int unk0878;     unsigned int unk087C;
    unsigned int unk0880;     unsigned int unk0884;     unsigned int unk0888;     unsigned int unk088C;
    unsigned int unk0890;     unsigned int unk0894;     unsigned int unk0898;     unsigned int unk089C;
    unsigned int unk08A0;     unsigned int unk08A4;     unsigned int unk08A8;     unsigned int unk08AC;
    unsigned int unk08B0;     unsigned int unk08B4;     unsigned int unk08B8;     unsigned int unk08BC;
    unsigned int unk08C0;     unsigned int unk08C4;     unsigned int unk08C8;     unsigned int unk08CC;
    unsigned int unk08D0;     unsigned int unk08D4;     unsigned int unk08D8;     unsigned int unk08DC;
    unsigned int unk08E0;     unsigned int unk08E4;     unsigned int unk08E8;     unsigned int unk08EC;
    unsigned int unk08F0;     unsigned int unk08F4;     unsigned int unk08F8;     unsigned int unk08FC;
    unsigned int unk0900;     unsigned int unk0904;     unsigned int unk0908;     unsigned int unk090C;
    unsigned int unk0910;     unsigned int unk0914;     unsigned int unk0918;     unsigned int unk091C;
    unsigned int unk0920;     unsigned int unk0924;     unsigned int unk0928;     unsigned int unk092C;
    unsigned int unk0930;     unsigned int unk0934;     unsigned int unk0938;     unsigned int unk093C;
    unsigned int unk0940;     unsigned int unk0944;     unsigned int unk0948;     unsigned int unk094C;
    unsigned int unk0950;     unsigned int unk0954;     unsigned int unk0958;     unsigned int unk095C;
    unsigned int unk0960;     unsigned int unk0964;     unsigned int unk0968;     unsigned int unk096C;
    unsigned int unk0970;     unsigned int unk0974;     unsigned int unk0978;     unsigned int unk097C;
    unsigned int unk0980;     unsigned int unk0984;     unsigned int unk0988;     unsigned int unk098C;
    unsigned int unk0990;     unsigned int unk0994;     unsigned int unk0998;     unsigned int unk099C;
    unsigned int unk09A0;     unsigned int unk09A4;     unsigned int unk09A8;     unsigned int unk09AC;
    unsigned int unk09B0;     unsigned int unk09B4;     unsigned int unk09B8;     unsigned int unk09BC;
    unsigned int unk09C0;     unsigned int unk09C4;     unsigned int unk09C8;     unsigned int unk09CC;
    unsigned int unk09D0;     unsigned int unk09D4;     unsigned int unk09D8;     unsigned int unk09DC;
    unsigned int unk09E0;     unsigned int unk09E4;     unsigned int unk09E8;     unsigned int unk09EC;
    unsigned int unk09F0;     unsigned int unk09F4;     unsigned int unk09F8;     unsigned int unk09FC;
    unsigned int unk0A00;     unsigned int unk0A04;     unsigned int unk0A08;     unsigned int unk0A0C;
    unsigned int unk0A10;     unsigned int unk0A14;     unsigned int unk0A18;     unsigned int unk0A1C;
    unsigned int unk0A20;     unsigned int unk0A24;     unsigned int unk0A28;     unsigned int unk0A2C;
    unsigned int unk0A30;     unsigned int unk0A34;     unsigned int unk0A38;     unsigned int unk0A3C;
    unsigned int unk0A40;     unsigned int unk0A44;     unsigned int unk0A48;     unsigned int unk0A4C;
    unsigned int unk0A50;     unsigned int unk0A54;     unsigned int unk0A58;     unsigned int unk0A5C;
    unsigned int unk0A60;     unsigned int unk0A64;     unsigned int unk0A68;     unsigned int unk0A6C;
    unsigned int unk0A70;     unsigned int unk0A74;     unsigned int unk0A78;     unsigned int unk0A7C;
    unsigned int unk0A80;     unsigned int unk0A84;     unsigned int unk0A88;     unsigned int unk0A8C;
    unsigned int unk0A90;     unsigned int unk0A94;     unsigned int unk0A98;     unsigned int unk0A9C;
    unsigned int unk0AA0;     unsigned int unk0AA4;     unsigned int unk0AA8;     unsigned int unk0AAC;
    unsigned int unk0AB0;     unsigned int unk0AB4;     unsigned int unk0AB8;     unsigned int unk0ABC;
    unsigned int unk0AC0;     unsigned int unk0AC4;     unsigned int unk0AC8;     unsigned int unk0ACC;
    unsigned int unk0AD0;     unsigned int unk0AD4;     unsigned int unk0AD8;     unsigned int unk0ADC;
    unsigned int unk0AE0;     unsigned int unk0AE4;     unsigned int unk0AE8;     unsigned int unk0AEC;
    unsigned int unk0AF0;     unsigned int unk0AF4;     unsigned int unk0AF8;     unsigned int unk0AFC;
    unsigned int unk0B00;     unsigned int unk0B04;     unsigned int unk0B08;     unsigned int unk0B0C;
    unsigned int unk0B10;     unsigned int unk0B14;     unsigned int unk0B18;     unsigned int unk0B1C;
    unsigned int unk0B20;     unsigned int unk0B24;     unsigned int unk0B28;     unsigned int unk0B2C;
    unsigned int unk0B30;     unsigned int unk0B34;     unsigned int unk0B38;     unsigned int unk0B3C;
    unsigned int unk0B40;     unsigned int unk0B44;     unsigned int unk0B48;     unsigned int unk0B4C;
    unsigned int unk0B50;     unsigned int unk0B54;     unsigned int unk0B58;     unsigned int unk0B5C;
    unsigned int unk0B60;     unsigned int unk0B64;     unsigned int unk0B68;     unsigned int unk0B6C;
    unsigned int unk0B70;     unsigned int unk0B74;     unsigned int unk0B78;     unsigned int unk0B7C;
    unsigned int unk0B80;     unsigned int unk0B84;     unsigned int unk0B88;     unsigned int unk0B8C;
    unsigned int unk0B90;     unsigned int unk0B94;     unsigned int unk0B98;     unsigned int unk0B9C;
    unsigned int unk0BA0;     unsigned int unk0BA4;     unsigned int unk0BA8;     unsigned int unk0BAC;
    unsigned int unk0BB0;     unsigned int unk0BB4;     unsigned int unk0BB8;     unsigned int unk0BBC;
    unsigned int unk0BC0;     unsigned int unk0BC4;     unsigned int unk0BC8;     unsigned int unk0BCC;
    unsigned int unk0BD0;     unsigned int unk0BD4;     unsigned int unk0BD8;     unsigned int unk0BDC;
    unsigned int unk0BE0;     unsigned int unk0BE4;     unsigned int unk0BE8;     unsigned int unk0BEC;
    unsigned int unk0BF0;     unsigned int unk0BF4;     unsigned int unk0BF8;     unsigned int unk0BFC;
    unsigned int unk0C00;     unsigned int unk0C04;     unsigned int unk0C08;     unsigned int unk0C0C;
    unsigned int unk0C10;     unsigned int unk0C14;     unsigned int unk0C18;     unsigned int unk0C1C;
    unsigned int unk0C20;     unsigned int unk0C24;     unsigned int unk0C28;     unsigned int unk0C2C;
    unsigned int unk0C30;     unsigned int unk0C34;     unsigned int unk0C38;     unsigned int unk0C3C;
    unsigned int unk0C40;     unsigned int unk0C44;     unsigned int unk0C48;     unsigned int unk0C4C;
    unsigned int unk0C50;     unsigned int unk0C54;     unsigned int unk0C58;     unsigned int unk0C5C;
    unsigned int unk0C60;     unsigned int unk0C64;     unsigned int unk0C68;     unsigned int unk0C6C;
    unsigned int unk0C70;     unsigned int unk0C74;     unsigned int unk0C78;     unsigned int unk0C7C;
    unsigned int unk0C80;     unsigned int unk0C84;     unsigned int unk0C88;     unsigned int unk0C8C;
    unsigned int unk0C90;     unsigned int unk0C94;     unsigned int unk0C98;     unsigned int unk0C9C;
    unsigned int unk0CA0;     unsigned int unk0CA4;     unsigned int unk0CA8;     unsigned int unk0CAC;
    unsigned int unk0CB0;     unsigned int unk0CB4;     unsigned int unk0CB8;     unsigned int unk0CBC;
    unsigned int unk0CC0;     unsigned int unk0CC4;     unsigned int unk0CC8;     unsigned int unk0CCC;
    unsigned int unk0CD0;     unsigned int unk0CD4;     unsigned int unk0CD8;     unsigned int unk0CDC;
    unsigned int unk0CE0;     unsigned int unk0CE4;     unsigned int unk0CE8;     unsigned int unk0CEC;
    unsigned int unk0CF0;     unsigned int unk0CF4;     unsigned int unk0CF8;     unsigned int unk0CFC;
    unsigned int unk0D00;     unsigned int unk0D04;     unsigned int unk0D08;     unsigned int unk0D0C;
    unsigned int unk0D10;     unsigned int unk0D14;     unsigned int unk0D18;     unsigned int unk0D1C;
    unsigned int unk0D20;     unsigned int unk0D24;     unsigned int unk0D28;     unsigned int unk0D2C;
    unsigned int unk0D30;     unsigned int unk0D34;     unsigned int unk0D38;     unsigned int unk0D3C;
    unsigned int unk0D40;     unsigned int unk0D44;     unsigned int unk0D48;     unsigned int unk0D4C;
    unsigned int unk0D50;     unsigned int unk0D54;     unsigned int unk0D58;     unsigned int unk0D5C;
    unsigned int unk0D60;     unsigned int unk0D64;     unsigned int unk0D68;     unsigned int unk0D6C;
    unsigned int unk0D70;     unsigned int unk0D74;     unsigned int unk0D78;     unsigned int unk0D7C;
    unsigned int unk0D80;     unsigned int unk0D84;     unsigned int unk0D88;     unsigned int unk0D8C;
    unsigned int unk0D90;     unsigned int unk0D94;     unsigned int unk0D98;     unsigned int unk0D9C;
    unsigned int unk0DA0;     unsigned int unk0DA4;     unsigned int unk0DA8;     unsigned int unk0DAC;
    unsigned int unk0DB0;     unsigned int unk0DB4;     unsigned int unk0DB8;     unsigned int unk0DBC;
    unsigned int unk0DC0;     unsigned int unk0DC4;     unsigned int unk0DC8;     unsigned int unk0DCC;
    unsigned int unk0DD0;     unsigned int unk0DD4;     unsigned int unk0DD8;     unsigned int unk0DDC;
    unsigned int unk0DE0;     unsigned int unk0DE4;     unsigned int unk0DE8;     unsigned int unk0DEC;
    unsigned int unk0DF0;     unsigned int unk0DF4;     unsigned int unk0DF8;     unsigned int unk0DFC;
    unsigned int unk0E00;     unsigned int unk0E04;     unsigned int unk0E08;     unsigned int unk0E0C;
    unsigned int unk0E10;     unsigned int unk0E14;     unsigned int unk0E18;     unsigned int unk0E1C;
    unsigned int unk0E20;     unsigned int unk0E24;     unsigned int unk0E28;     unsigned int unk0E2C;
    unsigned int unk0E30;     unsigned int unk0E34;     unsigned int unk0E38;     unsigned int unk0E3C;
    unsigned int unk0E40;     unsigned int unk0E44;     unsigned int unk0E48;     unsigned int unk0E4C;
    unsigned int unk0E50;     unsigned int unk0E54;     unsigned int unk0E58;     unsigned int unk0E5C;
    unsigned int unk0E60;     unsigned int unk0E64;     unsigned int unk0E68;     unsigned int unk0E6C;
    unsigned int unk0E70;     unsigned int unk0E74;     unsigned int unk0E78;     unsigned int unk0E7C;
    unsigned int unk0E80;     unsigned int unk0E84;     unsigned int unk0E88;     unsigned int unk0E8C;
    unsigned int unk0E90;     unsigned int unk0E94;     unsigned int unk0E98;     unsigned int unk0E9C;
    unsigned int unk0EA0;     unsigned int unk0EA4;     unsigned int unk0EA8;     unsigned int unk0EAC;
    unsigned int unk0EB0;     unsigned int unk0EB4;     unsigned int unk0EB8;     unsigned int unk0EBC;
    unsigned int unk0EC0;     unsigned int unk0EC4;     unsigned int unk0EC8;     unsigned int unk0ECC;
    unsigned int unk0ED0;     unsigned int unk0ED4;     unsigned int unk0ED8;     unsigned int unk0EDC;
    unsigned int unk0EE0;     unsigned int unk0EE4;     unsigned int unk0EE8;     unsigned int unk0EEC;
    unsigned int unk0EF0;     unsigned int unk0EF4;     unsigned int unk0EF8;     unsigned int unk0EFC;
    unsigned int unk0F00;     unsigned int unk0F04;     unsigned int unk0F08;     unsigned int unk0F0C;
    unsigned int unk0F10;     unsigned int unk0F14;     unsigned int unk0F18;     unsigned int unk0F1C;
    unsigned int unk0F20;     unsigned int unk0F24;     unsigned int unk0F28;     unsigned int unk0F2C;
    unsigned int unk0F30;     unsigned int unk0F34;     unsigned int unk0F38;     unsigned int unk0F3C;
    unsigned int unk0F40;     unsigned int unk0F44;     unsigned int unk0F48;     unsigned int unk0F4C;
    unsigned int unk0F50;     unsigned int unk0F54;     unsigned int unk0F58;     unsigned int unk0F5C;
    unsigned int unk0F60;     unsigned int unk0F64;     unsigned int unk0F68;     unsigned int unk0F6C;
    unsigned int unk0F70;     unsigned int unk0F74;     unsigned int unk0F78;     unsigned int unk0F7C;
    unsigned int unk0F80;     unsigned int unk0F84;     unsigned int unk0F88;     unsigned int unk0F8C;
    unsigned int unk0F90;     unsigned int unk0F94;     unsigned int unk0F98;     unsigned int unk0F9C;
    unsigned int unk0FA0;     unsigned int unk0FA4;     unsigned int unk0FA8;     unsigned int unk0FAC;
    unsigned int unk0FB0;     unsigned int unk0FB4;     unsigned int unk0FB8;     unsigned int unk0FBC;
    unsigned int unk0FC0;     unsigned int unk0FC4;     unsigned int unk0FC8;     unsigned int unk0FCC;
    unsigned int unk0FD0;     unsigned int unk0FD4;     unsigned int unk0FD8;     unsigned int unk0FDC;
    unsigned int unk0FE0;     unsigned int unk0FE4;     unsigned int unk0FE8;     unsigned int unk0FEC;
    unsigned int unk0FF0;     unsigned int unk0FF4;     unsigned int unk0FF8;     unsigned int unk0FFC;
    unsigned int unk1000;     unsigned int unk1004;     unsigned int unk1008;     unsigned int unk100C;
    unsigned int unk1010;     unsigned int unk1014;     unsigned int unk1018;     unsigned int unk101C;
    unsigned int unk1020;     unsigned int unk1024;     unsigned int unk1028;     unsigned int unk102C;
    unsigned int unk1030;     unsigned int unk1034;     unsigned int unk1038;     unsigned int unk103C;
    unsigned int unk1040;     unsigned int unk1044;     unsigned int unk1048;     unsigned int unk104C;
    unsigned int unk1050;     unsigned int unk1054;     unsigned int unk1058;     unsigned int unk105C;
    unsigned int unk1060;     unsigned int unk1064;     unsigned int unk1068;     unsigned int unk106C;
    unsigned int unk1070;     unsigned int unk1074;     unsigned int unk1078;     unsigned int unk107C;
    unsigned int unk1080;     unsigned int unk1084;     unsigned int unk1088;     unsigned int unk108C;
    unsigned int unk1090;     unsigned int unk1094;     unsigned int unk1098;     unsigned int unk109C;
    unsigned int unk10A0;     unsigned int unk10A4;     unsigned int unk10A8;     unsigned int unk10AC;
    unsigned int unk10B0;     unsigned int unk10B4;     unsigned int unk10B8;     unsigned int unk10BC;
    unsigned int unk10C0;     unsigned int unk10C4;     unsigned int unk10C8;     unsigned int unk10CC;
    unsigned int unk10D0;     unsigned int unk10D4;     unsigned int unk10D8;     unsigned int unk10DC;
    unsigned int unk10E0;     unsigned int unk10E4;     unsigned int unk10E8;     unsigned int unk10EC;
    unsigned int unk10F0;     unsigned int unk10F4;     unsigned int unk10F8;     unsigned int unk10FC;
    unsigned int unk1100;     unsigned int unk1104;     unsigned int unk1108;     unsigned int unk110C;
    unsigned int unk1110;     unsigned int unk1114;     unsigned int unk1118;     unsigned int unk111C;
    unsigned int unk1120;     unsigned int unk1124;     unsigned int unk1128;     unsigned int unk112C;
    unsigned int unk1130;     unsigned int unk1134;     unsigned int unk1138;     unsigned int unk113C;
    unsigned int unk1140;     unsigned int unk1144;     unsigned int unk1148;     unsigned int unk114C;
    unsigned int unk1150;     unsigned int unk1154;     unsigned int unk1158;     unsigned int unk115C;
    unsigned int unk1160;     unsigned int unk1164;     unsigned int unk1168;     unsigned int unk116C;
    unsigned int unk1170;     unsigned int unk1174;     unsigned int unk1178;     unsigned int unk117C;
    unsigned int unk1180;     unsigned int unk1184;     unsigned int unk1188;     unsigned int unk118C;
    unsigned int unk1190;     unsigned int unk1194;     unsigned int unk1198;     unsigned int unk119C;
    unsigned int unk11A0;     unsigned int unk11A4;     unsigned int unk11A8;     unsigned int unk11AC;
    unsigned int unk11B0;     unsigned int unk11B4;     unsigned int unk11B8;     unsigned int unk11BC;
    unsigned int unk11C0;     unsigned int unk11C4;     unsigned int unk11C8;     unsigned int unk11CC;
    unsigned int unk11D0;     unsigned int unk11D4;     unsigned int unk11D8;     unsigned int unk11DC;
    unsigned int unk11E0;     unsigned int unk11E4;     unsigned int unk11E8;     unsigned int unk11EC;
    unsigned int unk11F0;     unsigned int unk11F4;     unsigned int unk11F8;     unsigned int unk11FC;
    unsigned int unk1200;     unsigned int unk1204;     unsigned int unk1208;     unsigned int unk120C;
    unsigned int unk1210;     unsigned int unk1214;     unsigned int unk1218;     unsigned int unk121C;
    unsigned int unk1220;     unsigned int unk1224;     unsigned int unk1228;     unsigned int unk122C;
    unsigned int unk1230;     unsigned int unk1234;     unsigned int unk1238;     unsigned int unk123C;
    unsigned int unk1240;     unsigned int unk1244;     unsigned int unk1248;     unsigned int unk124C;
    unsigned int unk1250;     unsigned int unk1254;     unsigned int unk1258;     unsigned int unk125C;
    unsigned int unk1260;     unsigned int unk1264;     unsigned int unk1268;     unsigned int unk126C;
    unsigned int unk1270;     unsigned int unk1274;     unsigned int unk1278;     unsigned int unk127C;
    unsigned int unk1280;     unsigned int unk1284;     unsigned int unk1288;     unsigned int unk128C;
    unsigned int unk1290;     unsigned int unk1294;     unsigned int unk1298;     unsigned int unk129C;
    unsigned int unk12A0;     unsigned int unk12A4;     unsigned int unk12A8;     unsigned int unk12AC;
    unsigned int unk12B0;     unsigned int unk12B4;     unsigned int unk12B8;     unsigned int unk12BC;
    unsigned int unk12C0;     unsigned int unk12C4;     unsigned int unk12C8;     unsigned int unk12CC;
    unsigned int unk12D0;     unsigned int unk12D4;     unsigned int unk12D8;     unsigned int unk12DC;
    unsigned int unk12E0;     unsigned int unk12E4;     unsigned int unk12E8;     unsigned int unk12EC;
    unsigned int unk12F0;     unsigned int unk12F4;     unsigned int unk12F8;     unsigned int unk12FC;
    unsigned int unk1300;     unsigned int unk1304;     unsigned int unk1308;     unsigned int unk130C;
    unsigned int unk1310;     unsigned int unk1314;     unsigned int unk1318;     unsigned int unk131C;
    unsigned int unk1320;     unsigned int unk1324;     unsigned int unk1328;     unsigned int unk132C;
    unsigned int unk1330;     unsigned int unk1334;     unsigned int unk1338;     unsigned int unk133C;
    unsigned int unk1340;     unsigned int unk1344;     unsigned int unk1348;     unsigned int unk134C;
    unsigned int unk1350;     unsigned int unk1354;     unsigned int unk1358;     unsigned int unk135C;
    unsigned int unk1360;     unsigned int unk1364;     unsigned int unk1368;     unsigned int unk136C;
    unsigned int unk1370;     unsigned int unk1374;     unsigned int unk1378;     unsigned int unk137C;
    unsigned int unk1380;     unsigned int unk1384;     unsigned int unk1388;     unsigned int unk138C;
    unsigned int unk1390;     unsigned int unk1394;     unsigned int unk1398;     unsigned int unk139C;
    unsigned int unk13A0;     unsigned int unk13A4;     unsigned int unk13A8;     unsigned int unk13AC;
    unsigned int unk13B0;     unsigned int unk13B4;     unsigned int unk13B8;     unsigned int unk13BC;
    unsigned int unk13C0;     unsigned int unk13C4;     unsigned int unk13C8;     unsigned int unk13CC;
    unsigned int unk13D0;     unsigned int unk13D4;     unsigned int unk13D8;     unsigned int unk13DC;
    unsigned int unk13E0;     unsigned int unk13E4;     unsigned int unk13E8;     unsigned int unk13EC;
    unsigned int unk13F0;     unsigned int unk13F4;     unsigned int unk13F8;     unsigned int unk13FC;
    unsigned int unk1400;     unsigned int unk1404;     unsigned int unk1408;     unsigned int unk140C;
    unsigned int unk1410;     unsigned int unk1414;     unsigned int unk1418;     unsigned int unk141C;
    unsigned int unk1420;     unsigned int unk1424;     unsigned int unk1428;     unsigned int unk142C;
    unsigned int unk1430;     unsigned int unk1434;     unsigned int unk1438;     unsigned int unk143C;
    unsigned int unk1440;     unsigned int unk1444;     unsigned int unk1448;     unsigned int unk144C;
    unsigned int unk1450;     unsigned int unk1454;     unsigned int unk1458;     unsigned int unk145C;
    unsigned int unk1460;     unsigned int unk1464;     unsigned int unk1468;     unsigned int unk146C;
    unsigned int unk1470;     unsigned int unk1474;     unsigned int unk1478;     unsigned int unk147C;
    unsigned int unk1480;     unsigned int unk1484;     unsigned int unk1488;     unsigned int unk148C;
    unsigned int unk1490;     unsigned int unk1494;     unsigned int unk1498;     unsigned int unk149C;
    unsigned int unk14A0;     unsigned int unk14A4;     unsigned int unk14A8;     unsigned int unk14AC;
    unsigned int unk14B0;     unsigned int unk14B4;     unsigned int unk14B8;     unsigned int unk14BC;
    unsigned int unk14C0;     unsigned int unk14C4;     unsigned int unk14C8;     unsigned int unk14CC;
    unsigned int unk14D0;     unsigned int unk14D4;     unsigned int unk14D8;     unsigned int unk14DC;
    unsigned int unk14E0;     unsigned int unk14E4;     unsigned int unk14E8;     unsigned int unk14EC;
    unsigned int unk14F0;     unsigned int unk14F4;     unsigned int unk14F8;     unsigned int unk14FC;
    unsigned int unk1500;     unsigned int unk1504;     unsigned int unk1508;     unsigned int unk150C;
    unsigned int unk1510;     unsigned int unk1514;     unsigned int unk1518;     unsigned int unk151C;
    unsigned int unk1520;     unsigned int unk1524;     unsigned int unk1528;     unsigned int unk152C;
    unsigned int unk1530;     unsigned int unk1534;     unsigned int unk1538;     unsigned int unk153C;
    unsigned int unk1540;     unsigned int unk1544;     unsigned int unk1548;     unsigned int unk154C;
    unsigned int unk1550;     unsigned int unk1554;     unsigned int unk1558;     unsigned int unk155C;
    unsigned int unk1560;     unsigned int unk1564;     unsigned int unk1568;     unsigned int unk156C;
    unsigned int unk1570;     unsigned int unk1574;     unsigned int unk1578;     unsigned int unk157C;
    unsigned int unk1580;     unsigned int unk1584;     unsigned int unk1588;     unsigned int unk158C;
    unsigned int unk1590;     unsigned int unk1594;     unsigned int unk1598;     unsigned int unk159C;
    unsigned int unk15A0;     unsigned int unk15A4;     unsigned int unk15A8;     unsigned int unk15AC;
    unsigned int unk15B0;     unsigned int unk15B4;     unsigned int unk15B8;     unsigned int unk15BC;
    unsigned int unk15C0;     unsigned int unk15C4;     unsigned int unk15C8;     unsigned int unk15CC;
    unsigned int unk15D0;     unsigned int unk15D4;     unsigned int unk15D8;     unsigned int unk15DC;
    unsigned int unk15E0;     unsigned int unk15E4;     unsigned int unk15E8;     unsigned int unk15EC;
    unsigned int unk15F0;     unsigned int unk15F4;     unsigned int unk15F8;     unsigned int unk15FC;
    unsigned int unk1600;     unsigned int unk1604;     unsigned int unk1608;     unsigned int unk160C;
    unsigned int unk1610;     unsigned int unk1614;     unsigned int unk1618;     unsigned int unk161C;
    unsigned int unk1620;     unsigned int unk1624;     unsigned int unk1628;     unsigned int unk162C;
    unsigned int unk1630;     unsigned int unk1634;     unsigned int unk1638;     unsigned int unk163C;
    unsigned int unk1640;     unsigned int unk1644;     unsigned int unk1648;     unsigned int unk164C;
    unsigned int unk1650;     unsigned int unk1654;     unsigned int unk1658;     unsigned int unk165C;
    unsigned int unk1660;     unsigned int unk1664;     unsigned int unk1668;     unsigned int unk166C;
    unsigned int unk1670;     unsigned int unk1674;     unsigned int unk1678;     unsigned int unk167C;
    unsigned int unk1680;     unsigned int unk1684;     unsigned int unk1688;     unsigned int unk168C;
    unsigned int unk1690;     unsigned int unk1694;     unsigned int unk1698;     unsigned int unk169C;
    unsigned int unk16A0;     unsigned int unk16A4;     unsigned int unk16A8;     unsigned int unk16AC;
    unsigned int unk16B0;     unsigned int unk16B4;     unsigned int unk16B8;     unsigned int unk16BC;
    unsigned int unk16C0;     unsigned int unk16C4;     unsigned int unk16C8;     unsigned int unk16CC;
    unsigned int unk16D0;     unsigned int unk16D4;     unsigned int unk16D8;     unsigned int unk16DC;
    unsigned int unk16E0;     unsigned int unk16E4;     unsigned int unk16E8;     unsigned int unk16EC;
    unsigned int unk16F0;     unsigned int unk16F4;     unsigned int unk16F8;     unsigned int unk16FC;
    unsigned int unk1700;     unsigned int unk1704;     unsigned int unk1708;     unsigned int unk170C;
    unsigned int unk1710;     unsigned int unk1714;     unsigned int unk1718;     unsigned int unk171C;
    unsigned int unk1720;     unsigned int unk1724;     unsigned int unk1728;     unsigned int unk172C;
    unsigned int unk1730;     unsigned int unk1734;     unsigned int unk1738;     unsigned int unk173C;
    unsigned int unk1740;     unsigned int unk1744;     unsigned int unk1748;     unsigned int unk174C;
    unsigned int unk1750;     unsigned int unk1754;     unsigned int unk1758;     unsigned int unk175C;
    unsigned int unk1760;     unsigned int unk1764;     unsigned int unk1768;     unsigned int unk176C;
    unsigned int unk1770;     unsigned int unk1774;     unsigned int unk1778;     unsigned int unk177C;
    unsigned int unk1780;     unsigned int unk1784;     unsigned int unk1788;     unsigned int unk178C;
    unsigned int unk1790;     unsigned int unk1794;     unsigned int unk1798;     unsigned int unk179C;
    unsigned int unk17A0;     unsigned int unk17A4;     unsigned int unk17A8;     unsigned int unk17AC;
    unsigned int unk17B0;     unsigned int unk17B4;     unsigned int unk17B8;     unsigned int unk17BC;
    unsigned int unk17C0;     unsigned int unk17C4;     unsigned int unk17C8;     unsigned int unk17CC;
    unsigned int unk17D0;     unsigned int unk17D4;     unsigned int unk17D8;     unsigned int unk17DC;
    unsigned int unk17E0;     unsigned int unk17E4;     unsigned int unk17E8;     unsigned int unk17EC;
    unsigned int unk17F0;     unsigned int unk17F4;     unsigned int unk17F8;     unsigned int unk17FC;
    unsigned int unk1800;     unsigned int unk1804;     unsigned int unk1808;     unsigned int unk180C;
    unsigned int unk1810;     unsigned int unk1814;     unsigned int unk1818;     unsigned int unk181C;
    unsigned int unk1820;     unsigned int unk1824;     unsigned int unk1828;     unsigned int unk182C;
    unsigned int unk1830;     unsigned int unk1834;     unsigned int unk1838;     unsigned int unk183C;
    unsigned int unk1840;     unsigned int unk1844;     unsigned int unk1848;     unsigned int unk184C;
    unsigned int unk1850;     unsigned int unk1854;     unsigned int unk1858;     unsigned int unk185C;
    unsigned int unk1860;     unsigned int unk1864;     unsigned int unk1868;     unsigned int unk186C;
    unsigned int unk1870;     unsigned int unk1874;     unsigned int unk1878;     unsigned int unk187C;
    unsigned int unk1880;     unsigned int unk1884;     unsigned int unk1888;     unsigned int unk188C;
    unsigned int unk1890;     unsigned int unk1894;     unsigned int unk1898;     unsigned int unk189C;
    unsigned int unk18A0;     unsigned int unk18A4;     unsigned int unk18A8;     unsigned int unk18AC;
    unsigned int unk18B0;     unsigned int unk18B4;     unsigned int unk18B8;     unsigned int unk18BC;
    unsigned int unk18C0;     unsigned int unk18C4;     unsigned int unk18C8;     unsigned int unk18CC;
    unsigned int unk18D0;     unsigned int unk18D4;     unsigned int unk18D8;     unsigned int unk18DC;
    unsigned int unk18E0;     unsigned int unk18E4;     unsigned int unk18E8;     unsigned int unk18EC;
    unsigned int unk18F0;     unsigned int unk18F4;     unsigned int unk18F8;     unsigned int unk18FC;
    unsigned int unk1900;     unsigned int unk1904;     unsigned int unk1908;     unsigned int unk190C;
    unsigned int unk1910;     unsigned int unk1914;     unsigned int unk1918;     unsigned int unk191C;
    unsigned int unk1920;     unsigned int unk1924;     unsigned int unk1928;     unsigned int unk192C;
    unsigned int unk1930;     unsigned int unk1934;     unsigned int unk1938;     unsigned int unk193C;
    unsigned int unk1940;     unsigned int unk1944;     unsigned int unk1948;     unsigned int unk194C;
    unsigned int unk1950;     unsigned int unk1954;     unsigned int unk1958;     unsigned int unk195C;
    unsigned int unk1960;     unsigned int unk1964;     unsigned int unk1968;     unsigned int unk196C;
    unsigned int unk1970;     unsigned int unk1974;     unsigned int unk1978;     unsigned int unk197C;
    unsigned int unk1980;     unsigned int unk1984;     unsigned int unk1988;     unsigned int unk198C;
    unsigned int unk1990;     unsigned int unk1994;     unsigned int unk1998;     unsigned int unk199C;
    unsigned int unk19A0;     unsigned int unk19A4;     unsigned int unk19A8;     unsigned int unk19AC;
    unsigned int unk19B0;     unsigned int unk19B4;     unsigned int unk19B8;     unsigned int unk19BC;
    unsigned int unk19C0;     unsigned int unk19C4;     unsigned int unk19C8;     unsigned int unk19CC;
    unsigned int unk19D0;     unsigned int unk19D4;     unsigned int unk19D8;     unsigned int unk19DC;
    unsigned int unk19E0;     unsigned int unk19E4;     unsigned int unk19E8;     unsigned int unk19EC;
    unsigned int unk19F0;     unsigned int unk19F4;     unsigned int unk19F8;     unsigned int unk19FC;
    unsigned int unk1A00;     unsigned int unk1A04;     unsigned int unk1A08;     unsigned int unk1A0C;
    unsigned int unk1A10;     unsigned int unk1A14;     unsigned int unk1A18;     unsigned int unk1A1C;
    unsigned int unk1A20;     unsigned int unk1A24;     unsigned int unk1A28;     unsigned int unk1A2C;
    unsigned int unk1A30;     unsigned int unk1A34;     unsigned int unk1A38;     unsigned int unk1A3C;
    unsigned int unk1A40;     unsigned int unk1A44;     unsigned int unk1A48;     unsigned int unk1A4C;
    unsigned int unk1A50;     unsigned int unk1A54;     unsigned int unk1A58;     unsigned int unk1A5C;
    unsigned int unk1A60;     unsigned int unk1A64;     unsigned int unk1A68;     unsigned int unk1A6C;
    unsigned int unk1A70;     unsigned int unk1A74;     unsigned int unk1A78;     unsigned int unk1A7C;
    unsigned int unk1A80;     unsigned int unk1A84;     unsigned int unk1A88;     unsigned int unk1A8C;
    unsigned int unk1A90;     unsigned int unk1A94;     unsigned int unk1A98;     unsigned int unk1A9C;
    unsigned int unk1AA0;     unsigned int unk1AA4;     unsigned int unk1AA8;     unsigned int unk1AAC;
    unsigned int unk1AB0;     unsigned int unk1AB4;     unsigned int unk1AB8;     unsigned int unk1ABC;
    unsigned int unk1AC0;     unsigned int unk1AC4;     unsigned int unk1AC8;     unsigned int unk1ACC;
    unsigned int unk1AD0;     unsigned int unk1AD4;     unsigned int unk1AD8;     unsigned int unk1ADC;
    unsigned int unk1AE0;     unsigned int unk1AE4;     unsigned int unk1AE8;     unsigned int unk1AEC;
    unsigned int unk1AF0;     unsigned int unk1AF4;     unsigned int unk1AF8;     unsigned int unk1AFC;
    unsigned int unk1B00;     unsigned int unk1B04;     unsigned int unk1B08;     unsigned int unk1B0C;
    unsigned int unk1B10;     unsigned int unk1B14;     unsigned int unk1B18;     unsigned int unk1B1C;
    unsigned int unk1B20;     unsigned int unk1B24;     unsigned int unk1B28;     unsigned int unk1B2C;
    unsigned int unk1B30;     unsigned int unk1B34;     unsigned int unk1B38;     unsigned int unk1B3C;
    unsigned int unk1B40;     unsigned int unk1B44;     unsigned int unk1B48;     unsigned int unk1B4C;
    unsigned int unk1B50;     unsigned int unk1B54;     unsigned int unk1B58;     unsigned int unk1B5C;
    unsigned int unk1B60;     unsigned int unk1B64;     unsigned int unk1B68;     unsigned int unk1B6C;
    unsigned int unk1B70;     unsigned int unk1B74;     unsigned int unk1B78;     unsigned int unk1B7C;
    unsigned int unk1B80;     unsigned int unk1B84;     unsigned int unk1B88;     unsigned int unk1B8C;
    unsigned int unk1B90;     unsigned int unk1B94;     unsigned int unk1B98;     unsigned int unk1B9C;
    unsigned int unk1BA0;     unsigned int unk1BA4;     unsigned int unk1BA8;     unsigned int unk1BAC;
    unsigned char qualityEnabled[10][10];
};
struct Agent {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CollisionObject* first;
    CollisionObject* second;
};
struct CollisionAgentEntry { Agent* agent; CollisionObject* other; };

static __declspec(noinline) void __cdecl SyncOverlap(PhantomInterface* phantom, CollisionObject* other, CollisionFilter* filter) {
    FilterBool overlapping = phantom->hasOverlap(other);
    CollisionObject* self = &phantom->collidable;
    if (filter->filter.enabled(self, other).value) {
        if (!overlapping.value) phantom->addOverlap(other);
        if (other->handle.type == 2) {
            FilterBool reverseOverlap = ((PhantomInterface*)((char*)other + other->ownerOffset))->hasOverlap(self);
            if (!reverseOverlap.value) ((PhantomInterface*)((char*)other + other->ownerOffset))->addOverlap(self);
        }
    } else {
        if (overlapping.value) phantom->removeOverlap(other);
        if (other->handle.type == 2) {
            FilterBool reverseOverlap = ((PhantomInterface*)((char*)other + other->ownerOffset))->hasOverlap(self);
            if (reverseOverlap.value) ((PhantomInterface*)((char*)other + other->ownerOffset))->removeOverlap(self);
        }
    }
}
struct BroadphaseDispatcher {
};
struct FilterCommand {
    unsigned char type;
    CollisionEntity* entity;
    unsigned char updateCollection;
    unsigned char updateShape;
};
struct CallRet : hkpWorld {
    void FUN_00c946e0(CollisionEntity*, int, int);
    void FUN_00c91120();
};
__forceinline void releasePairs(PairArray& pairs) {
hkMemoryAllocator* heap = hkMemoryRouter::getInstance().m_heap;
pairs.size=0;
if ((pairs.capacityAndFlags & 0x80000000)==0) heap->bufFree(pairs.data,(pairs.capacityAndFlags & 0x3fffffff)*sizeof(OverlapPair));
}

__forceinline void constructPairs(OverlapPair* p,int n) { for(int j=0;j<n;++j) ::new(p+j) OverlapPair; }
__forceinline OverlapPair& expandOverlapPair(PairArray& pairs) {
hkMemoryRouter* router = &hkMemoryRouter::getInstance();
if (pairs.size == (pairs.capacityAndFlags & 0x3fffffff)) ::ResizeAudioStream((::AudioAllocator *)(router->m_heap),(::AudioStream *)(void *)(&pairs),sizeof(OverlapPair));
constructPairs(pairs.data+pairs.size,1);
return pairs.data[pairs.size++];
}
// Updates collision filter state for entity, syncing phantom overlaps and agent pairs, then dispatches new collision pairs.
// @fnv 0x00c946e0
void CallRet::FUN_00c946e0(CollisionEntity* entity, int updateCollection, int updateShape) {
    if (m_iCriticalOperationsLockCount) {
        FilterCommand command;
        command.type = 0x12;
        command.entity = entity;
        command.updateCollection = (unsigned char)updateCollection;
        command.updateShape = (unsigned char)updateShape;
        reinterpret_cast<::WorldWithPending *>(this)->FUN_00c91160();
        return;
    }
    timer("LtUpdateFilterOnEntity", "Stinit");
    ++m_iCriticalOperationsLockCount;
    if (entity->type == 5) reinterpret_cast<::FUN_00d08210_Collidable *>(&(entity->collidable))->UpdateCollisionIndices();
    PairArray pairs;
    pairs.init();
    if (updateCollection == 0) {
        timer("Stbroadphase");
        ((Broadphase*)m_pJobSemaphore)->query(&entity->collidable.handle, &pairs);
        timer("Stphantom");
        for (int i = 0; i < pairs.size; ++i) {
            BroadphaseHandle* handle = pairs.data[i].second;
            CollisionObject* object = (CollisionObject*)((char*)handle + handle->ownerOffset);
            if (object->handle.type == 2) {
                PhantomInterface* phantom = (PhantomInterface*)((char*)object + object->ownerOffset);
                if (phantom) {
                    CollisionObject* collidable = &entity->collidable;
                    SyncOverlap(phantom, collidable, (CollisionFilter*)m_pCollisionFilter);
                    if (updateShape != 0) phantom->refresh();
                    --pairs.size;
                    if (pairs.size != i) {
memCpyOneAlignedXc937a0<sizeof(OverlapPair)>(&pairs.data[i], &pairs.data[pairs.size]);
                    }
                    --i;
                }
            }
        }
        hkArray<CollisionAgentEntry>* agents = ((::hkArray< ::CollisionAgentEntry> *)(reinterpret_cast<::FUN_00d081e0_cls *>(&(entity->collidable))->FUN_00d081e0()));
        PairArray existing;
        existing.init();
        for (int i = 0; i < agents->m_iElementCount; ++i) {
            OverlapPair& pair = expandOverlapPair(existing);
            pair.first = &agents->m_data[i].agent->first->handle;
            pair.second = &agents->m_data[i].agent->second->handle;
        }
        ::FUN_00cf7130((::EdgeArray *)(::PairArray *)(&existing), (::EdgeArray *)(::PairArray *)(&pairs));
        releasePairs(existing);
    }
    timer("StcheckAgts");
    int quality = entity->collidable.handle.quality;
    CollisionObject* collidable = &entity->collidable;
    hkArray<CollisionAgentEntry>* agents = ((::hkArray< ::CollisionAgentEntry> *)(reinterpret_cast<::FUN_00d081e0_cls *>((collidable))->FUN_00d081e0()));
    for (int i = 0; i < agents->m_iElementCount; ++i) {
        CollisionAgentEntry& entry = agents->m_data[i];
CollisionObject* other; if(!((CollisionFilter*)m_pCollisionFilter)->filter.enabled(collidable, entry.other).value) goto ResetAgent; other=entry.other; if(!((CollisionDispatcher*)m_pDispatcher)->qualityEnabled[quality][other->handle.quality]) goto ResetAgent; if(updateShape==1) { EntityState* state; if(entity->type==5) state=((CollisionEntity*)((char*)other + other->ownerOffset))->state; else state=entity->state; ::FUN_00cfeba0((::FUN_00cfeba0_Obj *)(entry.agent),(void **)(m_pCollisionInput),state); } goto nextAgent; ResetAgent: ::FUN_00cc1160((::Owner *)(entry.agent)); --i; entity->state->flags = (entity->state->flags & ~2) | 1; nextAgent:;
    }
    if (pairs.size > 0) {
        timer("StaddAgts");
        CollisionFilter* filter = (CollisionFilter*)m_pCollisionFilter;
        reinterpret_cast<::DispatcherCF7080 *>((((BroadphaseDispatcher*)m_pBroadPhaseDispatcher)))->FUN_00cf7080((::PairCF7080 *)(pairs.data), pairs.size, (const ::FilterCF7080 *)(::CollisionFilterInterface *)(filter ? &filter->filter : 0));
    }
    if (--m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations) {
        if (m_iPendingOperationCount) reinterpret_cast<::FUN_00c91120 *>(this)->ExecutePendingOperations();
        if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount) reinterpret_cast<::FUN_00c91140_Class *>(this)->FUN_00c91140();
    }
    releasePairs(pairs);
    timer("lt");
}



PhantomInterface* volatile probePhantom;
CollisionObject* volatile probeObject;
CollisionFilter* volatile probeFilter;
void probeOverlapCaller() { SyncOverlap(probePhantom, probeObject, probeFilter); }


struct RotationInput {
    __m128 translation;
    __m128 rotation;
};
struct VectorTemporary {
    union { __m128 value; float components[4]; };
};
struct RotationOwner {
    void ApplyRotation(const RotationInput*, const __m128*, const __m128*, int color, hkUlong id, int tag);
};
// Transforms position via FUN_00c7f7a0, rotates direction by the transform's quaternion, then calls FUN_00c98820 with both plus a, b and c.
// @fnv 0x00c99610
void RotationOwner::ApplyRotation(const RotationInput* transform, const __m128* position,
    const __m128* direction, int a, hkUlong b, int c)
{
    VectorTemporary worldPosition;
    __m128 worldDirection;
    reinterpret_cast<::TransformedPosDAD *>(&(worldPosition))->FUN_00c7f7a0((*(const ::hkQsTransformDAD *)(transform)), (*(const ::hkVector4DAD *)(position)));
    __m128 q = transform->rotation;
    __m128 v = *direction;
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 product = _mm_mul_ps(v, q);
    __m128 sum01 = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    __m128 dot3 = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sum01);
    __m128 crossA = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2));
    __m128 crossB = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xd2), _mm_shuffle_ps(q, q, 0xc9));
    __m128 cross = _mm_sub_ps(crossB, crossA);
    cross = _mm_mul_ps(cross, w);
    __m128 square = _mm_mul_ps(w, w);
    __m128 weighted = _mm_mul_ps(_mm_add_ps(square, ::DAT_010c71e0), v);
    __m128 projected = _mm_mul_ps(_mm_shuffle_ps(dot3, dot3, 0), q);
    __m128 rotated = _mm_add_ps(cross, _mm_add_ps(weighted, projected));
    worldDirection = _mm_add_ps(rotated, rotated);
    reinterpret_cast<::FUN_00c98820_Class *>(this)->FUN_00c98820((void *)(&worldPosition), (void *)(&worldDirection), a, b, c);
}


struct hkTransformC997;

struct __declspec(align(16)) hkVector4C997 {
    float x, y, z, w;
    const __m128& getQuad() const { return *(const __m128*)&x; }
    __m128& getQuad() { return *(__m128*)&x; }
    void setZero4() { getQuad() = _mm_setzero_ps(); }
    void set(float a, float b, float c, float d = 0.0f)
    {
        getQuad() = _mm_setr_ps(a, b, c, d);
    }
    void setSub4(const hkVector4C997& a, const hkVector4C997& b) { getQuad() = _mm_sub_ps(*(__m128*)&a.x, *(__m128*)&b.x); }
};

class hkDebugDisplayHandlerC997 {
public:
    void DrawAxes(const hkTransformC997& kWorldFromLocal, float fSize, hkUlong aiId, int aiAllocationTag) throw();
};
// Builds an aligned rotation from the quaternion a1 and forwards it with a2, a3 and a4 to DrawAxes.
// @fnv 0x00c99870
void HavokHelper::FUN_00c99870(const hkQuaternion& aQuat, float afValue, hkUlong aiArg3, int aiArg4) {
    AlignedRotation rot;
    reinterpret_cast<::Ce52e0Helper *>(&(rot))->FUN_00ce52e0(&(aQuat));
    reinterpret_cast<::hkDebugDisplayHandlerC997 *>(this)->DrawAxes((const ::hkTransformC997 &)(rot), afValue, aiArg3, aiArg4);
}

// Transforms a local origin and three axis vectors by kWorldFromLocal, then draws red, green, and blue debug lines from the origin along each axis.
// @fnv 0x00c99720
void hkDebugDisplayHandlerC997::DrawAxes(const hkTransformC997& kWorldFromLocal, float afLength, hkUlong aiId, int aiAllocationTag) throw()
{
    hkVector4C997 kTemp;
    kTemp.setZero4();
    hkVector4C997 akStart;
    reinterpret_cast<::TransformedPosDAD *>(&(akStart))->FUN_00c7f7a0((const ::hkQsTransformDAD &)(kWorldFromLocal), (const ::hkVector4DAD &)(kTemp));

    hkVector4C997 akAxes[3];
    kTemp.set(afLength, 0.0f, 0.0f);
    reinterpret_cast<::TransformedPosDAD *>(&(akAxes[0]))->FUN_00c7f7a0((const ::hkQsTransformDAD &)(kWorldFromLocal), (const ::hkVector4DAD &)(kTemp));
    kTemp.set(0.0f, afLength, 0.0f);
    reinterpret_cast<::TransformedPosDAD *>(&(akAxes[1]))->FUN_00c7f7a0((const ::hkQsTransformDAD &)(kWorldFromLocal), (const ::hkVector4DAD &)(kTemp));
    kTemp.set(0.0f, 0.0f, afLength);
    reinterpret_cast<::TransformedPosDAD *>(&(akAxes[2]))->FUN_00c7f7a0((const ::hkQsTransformDAD &)(kWorldFromLocal), (const ::hkVector4DAD &)(kTemp));

    hkVector4C997 akDirs[3];
    akDirs[0].setSub4(akAxes[0], akStart);
    akDirs[1].setSub4(akAxes[1], akStart);
    akDirs[2].setSub4(akAxes[2], akStart);

    reinterpret_cast<::DebugArrowEntry *>(this)->FUN_00c98880((const ::hkVector4_S &)(akStart), (const ::hkVector4_S &)(akDirs[0]), 0xffff0000, aiId, aiAllocationTag);
    reinterpret_cast<::DebugArrowEntry *>(this)->FUN_00c98880((const ::hkVector4_S &)(akStart), (const ::hkVector4_S &)(akDirs[1]), 0xff008000, aiId, aiAllocationTag);
    reinterpret_cast<::DebugArrowEntry *>(this)->FUN_00c98880((const ::hkVector4_S &)(akStart), (const ::hkVector4_S &)(akDirs[2]), 0xff0000ff, aiId, aiAllocationTag);
}

#include <stdarg.h>
struct RigidBody_s {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
struct RigidBodyList_s {
    RigidBody_s** m_apEntities;
    int m_uiItemCount;
};
struct Owner_s {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    RigidBodyList_s m_rigidBodyList;
};
struct System_s {
};
struct Context_s {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Owner_s* m_owner0;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    Owner_s** m_owners2;
    int m_ownerCount2;
};
struct BoolResult {
    char value;
    BoolResult(bool v) : value(v) {}
};
// Adds rigid bodies of m_owner0 and of each owner in m_owners2 to a3; returns true if m_ownerCount2 > 0 or m_owner0 has bodies.
// @fnv 0x00c926a0
static __declspec(noinline) BoolResult AddBodiesToSystem(Context_s* a2, ...) {
    va_list args;
    va_start(args, a2);
    System_s* a3 = va_arg(args, System_s*);
    va_end(args);
    bool flag = false;
    Owner_s* owner0 = a2->m_owner0;
    if (owner0) {
        for (int i = 0; i < owner0->m_rigidBodyList.m_uiItemCount; ++i) {
            if (i != 0 || owner0->m_rigidBodyList.m_apEntities[0]->unk10 != 0) {
                reinterpret_cast<::Container64 *>((a3))->AddShape((::Shape64 *)(owner0->m_rigidBodyList.m_apEntities[i]));
            }
        }
        flag = owner0->m_rigidBodyList.m_uiItemCount > 0;
    }
    for (Owner_s** it = a2->m_owners2; it != a2->m_owners2 + a2->m_ownerCount2; ++it) {
        RigidBodyList_s* list = &(*it)->m_rigidBodyList;
        for (int k = 0; k < list->m_uiItemCount; ++k) {
            reinterpret_cast<::Container64 *>((a3))->AddShape((::Shape64 *)(list->m_apEntities[k]));
        }
    }
    return BoolResult(a2->m_ownerCount2 > 0 || flag);
}

Context_s* volatile retry_context;
System_s* volatile retry_system;
volatile char retry_result;
void retryCaller() { retry_result = AddBodiesToSystem(retry_context, retry_system).value; }

// FUN_00c98240 : MSVC this-adjusting thunk  (sub ecx, 0x08 ; jmp <impl>)
struct A1_00c98240 {
    A1_00c98240();
    virtual void FUN_00c98240();
    char pad[0x04];
};
struct A2_00c98240 {
    A2_00c98240();
    virtual void FUN_00c98240();
};
struct Own_00c98240 : A1_00c98240, A2_00c98240 {
    Own_00c98240();
    virtual void key_fn();
// @fnv 0x00c98240
    void FUN_00c98240();
};
Own_00c98240::Own_00c98240() { }
void Own_00c98240::key_fn() { }
Own_00c98240* make_00c98240() { static Own_00c98240 o; return &o; }

// FUN_00c98310 : MSVC this-adjusting thunk  (sub ecx, 0x14 ; jmp <impl>)
struct A1_00c98310 {
    A1_00c98310();
    virtual void FUN_00c98310();
    char pad[0x10];
};
struct A2_00c98310 {
    A2_00c98310();
    virtual void FUN_00c98310();
};
struct Own_00c98310 : A1_00c98310, A2_00c98310 {
    Own_00c98310();
    virtual void key_fn();
// @fnv 0x00c98310
    void FUN_00c98310();
};
Own_00c98310::Own_00c98310() { }
void Own_00c98310::key_fn() { }
Own_00c98310* make_00c98310() { static Own_00c98310 o; return &o; }

// FUN_00c98320 : MSVC this-adjusting thunk  (sub ecx, 0x08 ; jmp <impl>)
struct A1_00c98320 {
    A1_00c98320();
    virtual void FUN_00c98320();
    char pad[0x04];
};
struct A2_00c98320 {
    A2_00c98320();
    virtual void FUN_00c98320();
};
struct Own_00c98320 : A1_00c98320, A2_00c98320 {
    Own_00c98320();
    virtual void key_fn();
// @fnv 0x00c98320
    void FUN_00c98320();
};
Own_00c98320::Own_00c98320() { }
void Own_00c98320::key_fn() { }
Own_00c98320* make_00c98320() { static Own_00c98320 o; return &o; }

// sub ecx,8; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct FnvHavok00c98330_PrimaryBase
{
    virtual void FUN_00c98330();
    int unk04;
    int unk08;
};

struct FnvHavok00c98330_SecondaryBase
{
    virtual void FUN_00c98330();
};

struct FnvHavok00c98330_Derived : FnvHavok00c98330_PrimaryBase, FnvHavok00c98330_SecondaryBase
{
    FnvHavok00c98330_Derived();
// @fnv 0x00c98330
    virtual void FUN_00c98330();
};

FnvHavok00c98330_Derived::FnvHavok00c98330_Derived()
{
}

// FUN_00c98340 : MSVC this-adjusting thunk  (sub ecx, 0x10 ; jmp <impl>)
struct A1_00c98340 {
    A1_00c98340();
    virtual void FUN_00c98340();
    char pad[0x0c];
};
struct A2_00c98340 {
    A2_00c98340();
    virtual void FUN_00c98340();
};
struct Own_00c98340 : A1_00c98340, A2_00c98340 {
    Own_00c98340();
    virtual void key_fn();
// @fnv 0x00c98340
    void FUN_00c98340();
};
Own_00c98340::Own_00c98340() { }
void Own_00c98340::key_fn() { }
Own_00c98340* make_00c98340() { static Own_00c98340 o; return &o; }

#include <math.h>
#include "fnv/symbols_simd.h"
struct FUN_00c905xx_Obj {
};

struct HkRefPtr {
    FUN_00c905xx_Obj* m_p;
    HkRefPtr& operator=(HkRefPtr& rhs)
        {
            FUN_00c905xx_Obj* pNew = rhs.m_p;
            if (pNew)
                reinterpret_cast<::FUN_00c90510_class *>((pNew))->FUN_00c90510();
            if (m_p)
                reinterpret_cast<::hkReferencedObjectC905 *>((m_p))->FUN_00c905b0();
            m_p = pNew;
            return *this;
        }
};

struct Sub_78_70 { float f00; int i04; };

struct Sub_78 {
    char pad00[0x8];
    float unk08;
    char pad0c[0x60];
    unsigned char b6c;
    unsigned char b6d;
    char pad6e[0x02];
    Sub_78_70* p70;
};

struct Sub_80 {
    char pad00[0x1e40];
    float f1e40;
    float f1e44;
};

struct Sub_08 {
    char pad00[0x24];
    float f24;
};

struct Dst_00c91c50 {
    char pad00[0x10];
    __m128 v10;
    int i_20;
    float f_24;
    unsigned char b_28;
    unsigned char b_29;
    char pad2a[0x06];
    __m128 v30;
    __m128 v40;
    unsigned char b_50;
    char pad51[0x02];
    unsigned char b_53;
    float f_54;
    HkRefPtr p58;
    HkRefPtr p5c;
    float f_60;
    int i_64;
    float f_68;
    HkRefPtr p6c;
    int i_70;
    unsigned char b_74;
    unsigned char b_75;
    char pad76[0x02];
    float f_78;
    float f_7c;
    int i_80;
    int i_84;
    float f_88;
    unsigned char b_8c;
    char pad8d[0x03];
    volatile float f_90;
    char pad94[0x04];
    unsigned char b_98;
    unsigned char b_99;
    char pad9a[0x02];
    float f_9c;
    int i_a0;
    unsigned char b_a4;
    unsigned char b_a5;
    unsigned char b_a6;
    unsigned char b_a7;
    float f_a8;
    float f_ac;
    int i_b0;
    unsigned char b_b4;
    char padb5[0x03];
    int i_b8;
    int i_bc;
    float f_c0;
    float f_c4;
    float f_c8;
    float f_cc;
    unsigned char b_d0;
    unsigned char b_d1;
    unsigned char b_d2;
    char padd3[0x01];
    int i_d4;
    unsigned char b_d8;
    unsigned char b_d9;
    char padda[0x02];
    float f_dc;
    unsigned char b_e0;
};

// hkpBroadPhaseBorder fields read when copying the world setup.
struct BroadPhaseBorderC91C50 {
    char pad00[0x30];
    int m_type;                                 // +0x30
    unsigned char m_postponeAndSortCallbacks;   // +0x34
};
struct Src_00c91c50 {
    char pad00[0x08];
    Sub_08* p08;
    char pad0c[0x04];
    __m128 v10;
    char pad20[0x30];
    HkRefPtr p50;
    char pad54[0x08];
    int i5c;
    unsigned char b60;
    char pad61[0x17];
    Sub_78* p78;
    HkRefPtr p7c;
    Sub_80* p80;
    HkRefPtr p84;
    char pad88[0x28];
    unsigned char b_b0;
    unsigned char b_b1;
    char padb2[0x02];
    int i_b4;
    char padb8[0x10];
    unsigned char b_c8;
    char padc9[0x03];
    float f_cc;
    float f_d0;
    unsigned char b_d4;
    unsigned char b_d5;
    unsigned char b_d6;
    char padd7[0x01];
    float f_d8;
    float f_dc;
    int i_e0;
    unsigned char b_e4;
    char pade5[0x03];
    int i_e8;
    int i_ec;
    unsigned char b_f0;
    char padf1[0x03];
    float f_f4;
    float f_f8;
    float f_fc;
    float f_100;
    char pad104[0xb8];
    void* p_1bc;
    int i_1c0;
    char pad1c4[0x20];
    float f_1e4;
    float f_1e8;
    char pad1ec[0x54];
    float f_240;
    char pad244[0xb0];
    int i_2f4;
    int i_2f8;
    char pad2fc[0x08];
    unsigned char b_304;
    unsigned char b_305;
    unsigned char b_306;
    unsigned char b_307;
    float f_308;
    char pad30c[0x04];
    __m128 v_310;
    __m128 v_320;
    int i_330;
    int i_334;
    int i_338;
    char pad33c[0x04];
    unsigned char b_340;
    void FUN_00c91c50(Dst_00c91c50* pOut);
};

// Copies fields from this into pOut, calling FUN_00c90510 on p50 and FUN_00c905b0 on pOut->p6c before transferring the reference.
// @fnv 0x00c91c50
void Src_00c91c50::FUN_00c91c50(Dst_00c91c50* pOut)
{
    unsigned char unkZero;

    pOut->v10 = this->v10;
    pOut->i_20 = this->i_338;
    pOut->v30 = this->v_310;
    pOut->v40 = this->v_320;
    pOut->f_54 = this->p78->unk08;
    pOut->p58 = this->p7c;
    pOut->p5c = this->p84;
    const BroadPhaseBorderC91C50* border = static_cast<const BroadPhaseBorderC91C50*>(this->p_1bc);
    pOut->b_28 = (unsigned char)(border ? border->m_type : 3);
    pOut->b_29 = *(border ? &border->m_postponeAndSortCallbacks : &(unkZero = 0));
    pOut->b_50 = (this->i5c != 0);
    pOut->b_53 = this->b60;
    pOut->f_60 = this->p80->f1e40;
    pOut->f_68 = this->p80->f1e44;
    pOut->f_90 = this->f_cc;
    pOut->f_90 = this->f_d0;
    pOut->b_98 = this->b_d4;
    if (this->p50.m_p)
        reinterpret_cast<::FUN_00c90510_class *>((this->p50.m_p))->FUN_00c90510();
    if (pOut->p6c.m_p)
        reinterpret_cast<::hkReferencedObjectC905 *>((pOut->p6c.m_p))->FUN_00c905b0();
    pOut->p6c.m_p = this->p50.m_p;
    pOut->i_70 = this->i_330;
    pOut->i_64 = this->i_334;
    pOut->b_74 = this->b_340;
    pOut->b_75 = this->p78->b6d;
    pOut->f_24 = this->f_240;
    pOut->f_78 = this->f_1e4;
    pOut->f_7c = this->f_1e8;
    pOut->i_80 = this->i_2f4;
    pOut->i_84 = this->i_2f8;
    pOut->f_88 = (float)sqrt(this->f_308);
    pOut->b_8c = this->b_304;
    pOut->b_a4 = this->b_305;
    pOut->b_a5 = this->b_306;
    pOut->b_a6 = this->b_307;
    pOut->f_9c = this->p78->p70->f00;
    pOut->i_a0 = this->p78->p70->i04;
    pOut->b_99 = this->p78->b6c;
    pOut->b_a7 = this->b_d6;
    pOut->f_ac = this->f_dc;
    pOut->i_b0 = this->i_e0;
    pOut->b_b4 = this->b_e4;
    pOut->i_b8 = this->i_e8;
    pOut->i_bc = this->i_ec;
    pOut->f_a8 = this->f_d8;
    pOut->f_c0 = this->f_f4;
    pOut->f_c4 = this->f_f8;
    pOut->f_c8 = this->f_fc;
    pOut->f_cc = this->f_100;
    pOut->b_d0 = this->b_d5;
    pOut->b_d1 = this->b_f0;
    pOut->f_dc = this->p08->f24;
    pOut->b_d2 = this->b_c8;
    pOut->b_d8 = this->b_b0;
    pOut->b_d9 = this->b_b1;
    pOut->i_d4 = this->i_b4;
    pOut->b_e0 = (this->i_1c0 != 0);
}

class FUN_00d065e0 {
  public:
    void* vtable;
    unsigned short memorySize;
    short referenceCount;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned char active;
    unsigned char unk41, unk42, unk43;
    FUN_00d065e0() throw();
    static void* operator new(size_t size)
    {
        FUN_00d065e0* memory = static_cast<FUN_00d065e0*>(hkMemoryRouter::getInstance().heap().blockAlloc(size));
        memory->memorySize = (unsigned short)size;
        return memory;
    }
    void FUN_00d064f0(void* phantom);
};
struct MatchStatus {
    unsigned char value;
    MatchStatus(bool v) : value(v) {}
    operator bool() const { return value != 0; }
};
struct MatchPhantoms {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14;
    void* p18; void* p1C; void* p20; void* p24; void* p28; void* p2C;
};
struct MatchWorld {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    void** phantoms;
    int phantomCount;
    MatchPhantoms* FUN_00c91110();
    void AddPhysicsSystem(hkArrayXc937a0<FUN_00d065e0*>* systems);
};
struct FUN_00d065e0Value { FUN_00d065e0* p; };
MatchStatus __cdecl AddBodiesToSystem(MatchWorld*, FUN_00d065e0*);
static __declspec(noinline) void FUN_00c92950(MatchWorld* world, FUN_00d065e0* system)
{
    MatchPhantoms* excluded = world->FUN_00c91110();
    if (excluded) {
        for (int i=0; i<world->phantomCount; ++i) {
            void* p = world->phantoms[i];
            if (p != excluded->p18 && p != excluded->p1C && p != excluded->p20 &&
                p != excluded->p24 && p != excluded->p28 && p != excluded->p2C)
                system->FUN_00d064f0(p);
        }
    } else {
        for (int i=0; i<world->phantomCount; ++i)
            system->FUN_00d064f0(world->phantoms[i]);
    }
}
// Creates one or two FUN_00d065e0 objects, adds them to the systems array, then calls CollectShapes, FUN_00c92950, InvokeOnAllOwners and FUN_00c928c0 on the last.
// @fnv 0x00c93b30
void MatchWorld::AddPhysicsSystem(hkArrayXc937a0<FUN_00d065e0*>* systems)
{
    FUN_00d065e0* first = new FUN_00d065e0;
    FUN_00d065e0* system;
    if (AddBodiesToSystem(this, first)) {
        first->active = 0;
        systems->AddBack(first);
        system = new FUN_00d065e0;
    } else {
        system = first ? first : new FUN_00d065e0;
    }
    systems->AddBack(system);
    ::CollectShapes((unsigned char *)(::MatchWorld *)(this), (::Context64 *)(system), {});
    FUN_00c92950(this, system);
    zzVal_c92860 a = { system };
    InvokeOnAllOwners((FUN_00c928c0_Context*)this, a);
    FUN_00c928c0((FUN_00c928c0_Context*)this, (hkpPhysicsSystem*)system);
}

extern const char str_010c6758[];
extern const char str_010c6734[];
extern const char str_010c6720[];

struct TimerEntryC944 { const char* name; unsigned int ticks; unsigned int unk08; };
struct TimerEntryC9442 { const char* name; unsigned int ticks; unsigned int unk08; const char* name2; };
struct TimerBufferC944 { unsigned int unk00; void* current; unsigned int unk08; void* end; };



class BroadPhaseC944 {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34(); virtual void v38();
    virtual void v3C(); virtual void v40(); virtual void v44();
    virtual void updateOverlaps(struct HandleC944* a, struct TempArray* arr);   // vtable +0x48
};

struct WorldObjectC944; struct CollidableC944;
struct HandleC944 {
    unsigned int m_iOwnerObjectOffset;
    unsigned char m_type;
    signed char m_iOwnerOffset;
    unsigned char m_ucObjectQualityType;
    unsigned int m_uiCollisionFilterData;
    CollidableC944* getOwner() { return reinterpret_cast<CollidableC944*>(reinterpret_cast<char*>(this) + m_iOwnerOffset); }
};
class hkpCdBody { public: void* m_pCollisionShape; unsigned int m_uiCollisionShapeKey; void* m_pMotionState; hkpCdBody* m_parent; };
struct CollidableC944 : hkpCdBody {
    signed char m_iOwnerOffset;
    unsigned char m_uiForceCollideOntoPpu;
    unsigned short m_uiShapeSizeOnSpu;
    HandleC944 m_kBroadPhaseHandle;
    WorldObjectC944* getOwner() { return reinterpret_cast<WorldObjectC944*>(reinterpret_cast<char*>(this) + m_iOwnerOffset); }
};
struct FilterResult { char value; FilterResult() {} FilterResult(bool b) : value(b) {} FilterResult(const FilterResult& b) : value(b.value) {} };
struct WorldObjectC944 : hkReferencedObject {
    hkpWorld* m_pOwningWorld;
    unsigned int m_ulUserData;
    CollidableC944 m_kCollidable;
    virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
    virtual void v14(); virtual void v18();
};
class PhantomC944 : public WorldObjectC944 {
public:
    virtual void AddOverlappingCollidable(CollidableC944*);
    virtual FilterResult GetFilterResult(CollidableC944*);
    virtual void RemoveOverlappingObject(CollidableC944*);
    virtual void v28(); virtual void v2c();
    virtual void ProcessContactPoints();
};
struct BroadPhaseC944HandlePair { HandleC944* first; HandleC944* second; };

struct TempArray {
    BroadPhaseC944HandlePair* m_data; // +0x00
    int m_iElementCount;                // +0x04
    int m_iCapacityState;    // +0x08
    char* m_original;
    TempArray(int count) : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000u) {
        char* top = static_cast<char*>(hkMemoryRouter::getInstance().allocateStack((count * int(sizeof(BroadPhaseC944HandlePair)) + 127) & ~127));
        m_data = reinterpret_cast<BroadPhaseC944HandlePair*>(top);
        m_original = top;
        m_iCapacityState = count | 0x80000000u;
    }
    void releaseStack() {
        char* oldTop = m_original;
        if ((void*)oldTop == m_data) m_iElementCount = 0;
        hkMemoryRouter::getInstance().deallocateStack(oldTop);
    }
    void releaseHeap(hkMemoryAllocator& heap) {
        m_iElementCount = 0;
        if (!(m_iCapacityState & 0x80000000u))
            heap.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(BroadPhaseC944HandlePair));
        m_data = 0;
        m_iCapacityState = 0x80000000u;
    }
};

struct PendingOp {
    unsigned char m_type;      // +0x00
    void* m_p;                 // +0x04
    unsigned char m_flag;      // +0x08
};

struct hkpCollidableCollidableFilter {
    virtual ~hkpCollidableCollidableFilter();
    virtual FilterResult IsCollisionEnabled(const CollidableC944*,const CollidableC944*);
};
struct hkpCollisionFilter : hkReferencedObject, hkpCollidableCollidableFilter {};
static __declspec(noinline) void SyncOverlap(PhantomC944* phantom,CollidableC944* collidable,hkpCollisionFilter* filter)
{
    FilterResult added = phantom->GetFilterResult(collidable);
    if (filter->IsCollisionEnabled(&phantom->m_kCollidable,collidable).value) {
        if (!added.value) phantom->AddOverlappingCollidable(collidable);
        if (collidable->m_kBroadPhaseHandle.m_type == 2) {
            if (!static_cast<PhantomC944*>(collidable->getOwner())->GetFilterResult(&phantom->m_kCollidable).value)
                static_cast<PhantomC944*>(collidable->getOwner())->AddOverlappingCollidable(&phantom->m_kCollidable);
        }
    } else {
        if (added.value) phantom->RemoveOverlappingObject(collidable);
        if (collidable->m_kBroadPhaseHandle.m_type == 2) {
            if (static_cast<PhantomC944*>(collidable->getOwner())->GetFilterResult(&phantom->m_kCollidable).value)
                static_cast<PhantomC944*>(collidable->getOwner())->RemoveOverlappingObject(&phantom->m_kCollidable);
        }
    }
}

struct PhantomArgC944 { PhantomC944* p; PhantomArgC944(PhantomC944* q) : p(q) {} };
struct WorldC944 : hkpWorld { void UpdatePhantom(PhantomC944*, int);  void FUN_00c91120();  };

// Queries broad phase for overlaps with a phantom, applies collision filters, and optionally processes contact points.
// @fnv 0x00c944a0
void WorldC944::UpdatePhantom(PhantomC944* apPhantom, int abProcessContacts)
{
    if (m_iCriticalOperationsLockCount != 0)
    {
        PendingOp op;
        op.m_type = 0x14;
        op.m_p = (PhantomC944*)apPhantom;
        op.m_flag = (unsigned char)abProcessContacts;
        reinterpret_cast<::WorldWithPending *>(this)->FUN_00c91160();
        return;
    }
    m_iCriticalOperationsLockCount = 1;

    TimerBufferC944* t1 = (TimerBufferC944*)TlsGetValue(DAT_0126835c);
    TimerEntryC9442* e1 = (TimerEntryC9442*)t1->current;
    if (e1 < t1->end)
    {
        e1->name = str_010c6758;
        e1->name2 = str_010c6748;
        _ReadWriteBarrier();
        volatile unsigned int ticks1 = (unsigned int)__rdtsc();
        e1->ticks = ticks1;
        t1->current = e1 + 1;
    }

    int queryCount = m_iBroadPhaseQuerySize;
    PhantomC944* ent = *(PhantomC944* volatile*)&apPhantom;
    TempArray arr(queryCount);
    ((BroadPhaseC944*)m_pJobSemaphore)->updateOverlaps(&ent->m_kCollidable.m_kBroadPhaseHandle, &arr);

    TimerBufferC944* t2 = (TimerBufferC944*)TlsGetValue(DAT_0126835c);
    TimerEntryC944* e2 = (TimerEntryC944*)t2->current;
    if (e2 < t2->end)
    {
        e2->name = str_010c6734;
        _ReadWriteBarrier();
        volatile unsigned int ticks2 = (unsigned int)__rdtsc();
        e2->ticks = ticks2;
        t2->current = e2 + 1;
    }

    unsigned int i = 0;
    if (arr.m_iElementCount > 0)
    {
        do
        {
            HandleC944* p = arr.m_data[i].second;
            if (p != &ent->m_kCollidable.m_kBroadPhaseHandle)
            {
                CollidableC944* q = p->getOwner();
                SyncOverlap(ent,q,static_cast<hkpCollisionFilter*>(m_pCollisionFilter));
            }
            i++;
        } while ((int)i < arr.m_iElementCount);
    }

    if (abProcessContacts != 0)
    {
        TimerBufferC944* t3 = (TimerBufferC944*)TlsGetValue(DAT_0126835c);
        TimerEntryC944* e3 = (TimerEntryC944*)t3->current;
        if (e3 < t3->end)
        {
            e3->name = str_010c6720;
                _ReadWriteBarrier();
        volatile unsigned int ticks3 = (unsigned int)__rdtsc();
            e3->ticks = ticks3;
            t3->current = e3 + 1;
        }
        ent->ProcessContactPoints();
    }

    if (--m_iCriticalOperationsLockCount == 0)
    {
        if (m_bBlockExecutingPendingOperations == 0)
        {
            if (m_iPendingOperationCount != 0)
                reinterpret_cast<::FUN_00c91120 *>(this)->ExecutePendingOperations();
            if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount != 0)
                reinterpret_cast<::FUN_00c91140_Class *>(this)->FUN_00c91140();
        }
    }

    TimerBufferC944* t4 = (TimerBufferC944*)TlsGetValue(DAT_0126835c);
    TimerEntryC944* e4 = (TimerEntryC944*)t4->current;
    if (e4 < t4->end)
    {
        e4->name = str_01076f38;
        _ReadWriteBarrier();
        volatile unsigned int ticks4 = (unsigned int)__rdtsc();
        e4->ticks = ticks4;
        t4->current = e4 + 1;
    }

    arr.releaseStack();
    arr.releaseHeap(hkMemoryRouter::getInstance().heap());
}




struct MyPendingQueue {
};

struct FUN_00cf70f0_Class {
};

struct FUN_00d01a80_Class {
    void FreeStorage() throw();
};

struct FUN_00c905b0_Class {
};

struct MyExecPending {
    void ExecutePendingOperations() throw();
    void FUN_00c91120() throw();
};

struct MyExecBodyPending {
};

class hkpSimulation_00c951b0 {
public:
    virtual ~hkpSimulation_00c951b0() throw();
    virtual void slot04() throw();
    virtual void slot08() throw();
    virtual void slot0c() throw();
    virtual void slot10() throw();
    virtual void slot14() throw();
    virtual void slot18() throw();
    virtual void slot1c() throw();
    virtual void removeEntities(void* const* entities, int numEntities, hkpWorld* world, int unk) throw();
};

class hkpBroadPhase_00c951b0 {
public:
    virtual ~hkpBroadPhase_00c951b0() throw();
    virtual void slot04() throw();
    virtual void slot08() throw();
    virtual void slot0c() throw();
    virtual void slot10() throw();
    virtual void slot14() throw();
    virtual void slot18() throw();
    virtual void slot1c() throw();
    virtual void DispatchCollisionPairs(void* array, void* pairs) throw();
};


struct DummyCollidable_00c951b0 {
    void* m_pCollisionShape;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_kBroadPhaseHandle;
};

struct EntityMember {
    void* unk00; void* unk04; void* unk08; void* unk0c;
    void* unk10; void* unk14; void* unk18; void* unk1c; void* unk20;
    void FreeStorage() throw();
};
struct DummyEntity_00c951b0 {
    virtual ~DummyEntity_00c951b0() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void v10() throw();
    virtual void v14() throw();
    short memSizeAndFlags;
    short referenceCount;
    void* unk08;
    void* unk0c;
    DummyCollidable_00c951b0 collidable;
    void* unk28;
    void* unk2c;
    EntityMember member;
    void* world;
};

struct WorldOp_00c951b0 {
    unsigned char m_type;
    unsigned char pad0;
    unsigned short pad1;
    void* m_kActorEntries;
    short m_iActorEntryCount;
};

struct MonitorCommand {
    const char* name;
    unsigned int time;
    unsigned int timeHigh;
};
struct MonitorBeginCommand : MonitorCommand {
    const char* firstSub;
};
struct hkMonitorStream_00c951b0 {
    int m_00;
    char* m_commandPosition;
    int m_08;
    char* m_pCommandBufferEnd;
    inline void timerBeginList(const char* name, const char* firstSub, volatile unsigned int& stamp) throw() {
        MonitorBeginCommand* pos = (MonitorBeginCommand*)m_commandPosition;
        if ((char*)pos < m_pCommandBufferEnd) {
            pos->name = name;
            pos->firstSub = firstSub;
            _ReadWriteBarrier();
            stamp = (unsigned int)__rdtsc();
            pos->time = stamp;
            m_commandPosition = reinterpret_cast<char*>(pos + 1);
        }
    }
    inline void timerSplitList(const char* name) throw() {
        MonitorCommand* pos = (MonitorCommand*)m_commandPosition;
        if ((char*)pos < m_pCommandBufferEnd) {
            pos->name = name;
            _ReadWriteBarrier();
            volatile unsigned int stamp = (unsigned int)__rdtsc();
            pos->time = stamp;
            m_commandPosition = reinterpret_cast<char*>(pos + 1);
        }
    }
    inline void timerEndList(const char* name) throw() { timerSplitList(name); }
};


template <class T>
struct MyArrayBase {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    inline MyArrayBase() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
};

template <class T>
struct MyArray {
    hkArray<T>& base;
    inline MyArray(hkArray<T>& b) throw() : base(b) { base.m_data=0; base.m_iElementCount=0; base.m_iCapacityState=0x80000000; }

    inline ~MyArray() throw() {
        hkMemoryAllocator* memory = hkMemoryRouter::getInstance().m_temp;
        base.m_iElementCount = 0;
        if ((base.m_iCapacityState & 0x80000000) == 0) {
            memory->bufFree(base.m_data, (base.m_iCapacityState & 0x3fffffff) * sizeof(T));
        }
    }

    inline void reserve(hkMemoryRouter* tm, int num) throw() {
        if ((base.m_iCapacityState & 0x3fffffff) < num) {
            ::FUN_00c908c0((::SpawnedObject *)(tm->m_temp), (::SpawnedArray *)(void *)(&base), num, sizeof(T));
        }
    }

    inline void pushBackUnchecked(const T& val) throw() {
        base.m_data[base.m_iElementCount++] = val;
    }
};

struct Pair_00c951b0 {
    void* a;
    void* b;
};

struct MyLocalArray : public MyArrayBase<Pair_00c951b0> {
    Pair_00c951b0* m_savedStack;

    inline MyLocalArray(int capacity) throw() {
        void* cur = hkMemoryRouter::getInstance().allocateStack((capacity * int(sizeof(Pair_00c951b0)) + 127) & ~127);
        this->m_data = static_cast<Pair_00c951b0*>(cur);
        this->m_savedStack = static_cast<Pair_00c951b0*>(cur);
        this->m_iCapacityState = capacity | 0x80000000;
    }

    inline ~MyLocalArray() throw() {
        Pair_00c951b0* savedStack = m_savedStack;
        if (savedStack == this->m_data) {
            this->m_iElementCount = 0;
        }
        hkMemoryRouter::getInstance().deallocateStack(savedStack);
        hkMemoryAllocator* memory = hkMemoryRouter::getInstance().m_heap;
        this->m_iElementCount = 0;
        if ((this->m_iCapacityState & 0x80000000) == 0) {
            memory->bufFree(this->m_data, (this->m_iCapacityState & 0x3fffffff) * sizeof(Pair_00c951b0));
        }
    }
};

union PendingOrHandles {
    WorldOp_00c951b0 operation;
    hkArray<void*> handles;
};
union TimerOrEnd { volatile unsigned int stamp; void* const* end; };
struct HostWorld_00c951b0 : hkpWorld {
    void RemoveEntities(void* const* entityBatch, int numEntities) throw();
};
// @fnv 0x00c67aa0
void FUN_00c67aa0_Class::FlushEntries()
{
    ScopedMemContext ctx(0x10);
    if (m_iNumberOfEntries > 0) {
        if (m_iNumberOfEntries >= 3000)
            m_iNumberOfEntries = 3000;
        unsigned int count = m_iNumberOfEntries;
        unsigned int num = DAT_011afe7c;
        if (count < num)
            num = count;
        unsigned int start = count - num;
        C67Sink* sink = getSink();
        if (sink) {
            reinterpret_cast<::HostWorld_00c951b0 *>((sink))->RemoveEntities((void *const *)(::C67Entry **)(&m_entries[start]), num);
            for (unsigned int i = start; i < m_iNumberOfEntries; i++) {
                C67Owner* owner = getEntityOwner(&m_entries[i]->m_kCollidable);
                if (owner) {
                    C67Flags* f = owner->unk0C;
                    if (f)
                        f->clearFlag20();
                }
                reinterpret_cast<::hkReferencedObjectC905 *>((m_entries[i]))->FUN_00c905b0();
                m_entries[i] = 0;
            }
            m_iNumberOfEntries = start;
        }
    }
}

// Removes a batch of entities from the simulation, dispatches broad-phase collision pairs, and invokes per-entity removal callbacks.
// @fnv 0x00c951b0
void HostWorld_00c951b0::RemoveEntities(void* const* entityBatch, int numEntities) throw()
{
    PendingOrHandles pendingOrHandles;
    if (numEntities < 1)
        return;

    if (m_iCriticalOperationsLockCount != 0)
    {
        {
        WorldOp_00c951b0& op = pendingOrHandles.operation;
        op.m_type = 7;
        op.m_kActorEntries = (void*)entityBatch;
        op.m_iActorEntryCount = (short)numEntities;
        reinterpret_cast<::WorldWithPending *>((((MyPendingQueue*)this)))->FUN_00c91160();
        }
        return;
    }

    m_iCriticalOperationsLockCount = 1;
    void* const* it;
    TimerOrEnd timerOrEnd;

    ((hkMonitorStream_00c951b0*)TlsGetValue(DAT_0126835c))->timerBeginList("LtRemEntities", "StInit+CallBck", timerOrEnd.stamp);

    ((hkpSimulation_00c951b0*)m_pSimulation)->removeEntities(entityBatch, numEntities, this, 1);

    {
        MyArray<void*> array(pendingOrHandles.handles);
        array.reserve(&hkMemoryRouter::getInstance(), numEntities);
        it = entityBatch;
        timerOrEnd.end = entityBatch + numEntities;

        for (; it != timerOrEnd.end; ++it)
        {
            DummyCollidable_00c951b0* coll = &((DummyEntity_00c951b0*)*it)->collidable;
            if (coll->m_pCollisionShape != 0)
            {
                array.pushBackUnchecked(&coll->m_kBroadPhaseHandle);
            }
        }

        if (array.base.m_iElementCount != 0)
        {
            ((hkMonitorStream_00c951b0*)TlsGetValue(DAT_0126835c))->timerSplitList("StBroadPhase");

            MyLocalArray pairs(m_iBroadPhaseQuerySize);

            ((hkpBroadPhase_00c951b0*)m_pJobSemaphore)->DispatchCollisionPairs(&array.base, &pairs);

            ((hkMonitorStream_00c951b0*)TlsGetValue(DAT_0126835c))->timerSplitList("StDelAgents");

            reinterpret_cast<::Dispatcher *>((((FUN_00cf70f0_Class*)m_pBroadPhaseDispatcher)))->DispatchPairs((::Pair *)(pairs.m_data), pairs.m_iElementCount);
        }
    }

    ((hkMonitorStream_00c951b0*)TlsGetValue(DAT_0126835c))->timerSplitList("StRemoveCb");

    for (it = entityBatch; it != timerOrEnd.end; ++it)
    {
        ::FUN_00d005a0((::D005A0World *)(::hkpWorld *)(this), *it);
        ::FUN_00cffab0((::Class_00cffab0 *)(*it));
        ::FUN_00cb4740((::Obj *)(::hkpWorld *)(this), (::Obj *)(*it));

        if (((DummyEntity_00c951b0*)*it)->world != 0)
        {
            reinterpret_cast<::hkMapD01A *>(&(((DummyEntity_00c951b0*)*it)->member))->FreeStorage();
        }

        if (((DummyEntity_00c951b0*)*it)->memSizeAndFlags == 0)
        {
            ((DummyEntity_00c951b0*)*it)->v14();
        }

        reinterpret_cast<::hkReferencedObjectC905 *>((((FUN_00c905b0_Class*)*it)))->FUN_00c905b0();
    }

    ((hkMonitorStream_00c951b0*)TlsGetValue(DAT_0126835c))->timerEndList("lt");

    --m_iCriticalOperationsLockCount;
    if (m_iCriticalOperationsLockCount == 0)
    {
        if (!m_bBlockExecutingPendingOperations)
        {
            if (m_iPendingOperationCount != 0)
            {
                reinterpret_cast<::FUN_00c91120 *>((((MyExecPending*)this)))->ExecutePendingOperations();
            }
            if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount != 0)
            {
                reinterpret_cast<::FUN_00c91140_Class *>((((MyExecBodyPending*)this)))->FUN_00c91140();
            }
        }
    }
}

struct Op { char type; void* p; };
struct Pt { unsigned short x; unsigned short pad; unsigned short y; };
struct Req { char k; Req(char c):k(c){} Req(const Req& o):k(o.k){} };
struct Info { int u0, u1, cnt; };
struct Sub {
  virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
  virtual int T20();
  virtual void T24(Req r, Pt* out);
};
struct Item;
struct Dev {
  virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
  virtual int T20();
  virtual void T24(Req r, Pt* out);
};
struct Item {
  virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5();
  virtual int T18();
  virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
  virtual void T40();
  int u04, u08;
  struct Ctl3* m_0c;
  int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30;
  unsigned int m_34;
  int unk38; int unk3c; int unk40;
  Info* m_44;
};
struct Ctl3 {
  virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
  virtual int T20();
  virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
  virtual void T40();
  int unk04; int unk08; int unk0c; int unk10; int unk14;
  Sub* m_18; unsigned short m_1c, m_1e;
};
struct Mgr {
  void* unk00;
  void* unk04;
  void* unk08;
  void* unk0C;
  void* unk10;
  void* unk14;
  void* unk18;
  void* unk1C;
  void* unk20;
  void* unk24;
  void* unk28;
  void* unk2C;
  void* unk30;
  void* unk34;
  void* unk38;
  void* unk3C;
  void* unk40;
  void* unk44;
  void* unk48;
  void* unk4C;
  void* unk50;
  void* unk54;
  void* unk58;
  void* unk5C;
  void* unk60;
  void* unk64;
  void* unk68;
  void* unk6C;
  void* unk70;
  void* unk74;
  void* unk78;
  void* unk7C;
  void* unk80;
  void* unk84;
  void* unk88;
  void* m_8c; unsigned int m_90; unsigned int m_94; unsigned int m_98; char m_9c;
  char unk9d, unk9e, unk9f; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc; int unke0; int unke4; int unke8; int unkec; int unkf0; int unkf4; int unkf8; int unkfc; int unk100; int unk104; int unk108;
  unsigned int m_10c;
  void FUN_00c91120();
  void* FUN_00c97d30(Item* it);
};
// Allocates a FUN_00cf3ea0 built from the arguments, copies a3->m_08 into its m_2c, passes it to FUN_00c97d30, and returns it.
// @fnv 0x00c97e30
FUN_00cf3ea0* FUN_00c97e30_C::Create(void* a1, void* a2, InfoC97E* apInfo)
{
    FUN_00cf3ea0* p = new FUN_00cf3ea0(a1, a2, apInfo, true);
    p->m_2c = apInfo->m_08;
    reinterpret_cast<::Mgr *>(this)->FUN_00c97d30((::Item *)(p));
    return p;
}
// If m_94 is nonzero, queues an op of type 8 for it and returns 0; otherwise sets it up, calls FUN_00cb3ca0 and returns its result.
// @fnv 0x00c97d30
void* Mgr::FUN_00c97d30(Item* it)
{
  unsigned int v94 = m_94;
  if (v94) {
    Op o; o.type = 8; o.p = it;
    reinterpret_cast<::WorldWithPending *>(this)->FUN_00c91160();
    return 0;
  }
  if (it->m_0c->T20() == 12) {
    Ctl3* c = it->m_0c;
    if (c->m_1c == 0) {
      Pt pt;
      c->m_18->T24(Req(1), &pt);
      c->m_1c = pt.x;
      c->m_1e = pt.y;
    }
  }
  m_9c = 1;
  reinterpret_cast<::fnv_00cf3e60::FUN_00cf3e60_class *>((it))->FUN_00cf3e60();
  it->m_34 = ++m_10c;
  void* res = ((void *)(::FUN_00cb3ca0((::FUN_00cb3ca0_object *)(::Mgr *)(this), (int *)(it), 1)));
  if (it->T18() == 1) {
    if (it->m_44->cnt == 0)
      reinterpret_cast<::hkpWorldC97 *>(this)->FUN_00c97370((::hkpActionC97 *)(it->m_44));
    it->m_0c->T40();
  }
  m_9c = 0;
  if (!m_94 && m_8c) reinterpret_cast<::FUN_00c91120 *>(this)->ExecutePendingOperations();
  return res;
}

// Calls AddBodiesToSystem, stores the result of CollectShapes into system->active, and returns that value.
// @fnv 0x00c927c0
static __declspec(noinline) unsigned char FUN_00c927c0(MatchWorld* world, FUN_00d065e0* system)
{
    AddBodiesToSystem(world, system);
    unsigned char active = (*(::MatchStatus *)(::CollectShapes((unsigned char *)(world), (::Context64 *)(system), {}))).value;
    system->active = active;
    return active;
}

MatchWorld* volatile g_matchWorld;
FUN_00d065e0* volatile g_matchSystem;
volatile unsigned char g_matchResult;
void CallMatchSystem() { g_matchResult = FUN_00c927c0(g_matchWorld, g_matchSystem); }

namespace fnv_00c982c0 {
#include <windows.h>


// @fnv 0x00c982c0
void FUN_00c982c0(unsigned char* out, int a1, int a2, int a3, int a4)
{
    *out = 1;
}
}  // namespace fnv_00c982c0



// @fnv 0x00c982d0
void FUN_00c982d0(unsigned char* out, int a2, int a3)
{
    *out = 1;
}

namespace fnv_00c96df0 {
extern const char str_010c68ec[];
extern const char str_010c68dc[];
extern "C" unsigned __int64 __rdtsc() throw();
extern "C" void _ReadWriteBarrier();




struct BroadPhaseHandle {
    int m_iOwnerObjectOffset;
    char m_type;
    signed char m_iOwnerOffset;
};

struct BroadPhaseHandlePair {
    void* m_kPointA;
    BroadPhaseHandle* m_kPointB;
};

template <class T, int N>
struct InplaceArray {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T m_kStorage[N];

    InplaceArray() throw() {
        m_data = m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = N | 0x80000000;
    }

    ~InplaceArray() throw() {
        hkMemoryAllocator* mem = hkMemoryRouter::getInstance().m_heap;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0) {
            mem->bufFree(m_data, (cap & 0x3fffffff) * sizeof(T));
        }
    }
};

struct __declspec(align(16)) Aabb {
    float m_kMinimumCorner[4];
    float m_kMaximumCorner[4];
};

struct Shape {
    virtual void slot00() throw();
    virtual void slot04() throw();
    virtual void slot08() throw();
    virtual void slot0c() throw();
    virtual void slot10() throw();
    virtual void slot14() throw();
    virtual void slot18() throw();
    virtual void getAabb(const void* transform, float tol, Aabb& out) throw();
    int unk04;
    int unk08;
    int m_type;
};

struct Collidable {
    Shape* m_pCollisionShape;
    int unk04;
    void* m_kMotionTransform;
};

struct BroadPhase {
    virtual void slot00() throw();
    virtual void slot04() throw();
    virtual void slot08() throw();
    virtual void slot0c() throw();
    virtual void slot10() throw();
    virtual void slot14() throw();
    virtual void slot18() throw();
    virtual void slot1c() throw();
    virtual void slot20() throw();
    virtual void slot24() throw();
    virtual void slot28() throw();
    virtual void slot2c() throw();
    virtual void slot30() throw();
    virtual void slot34() throw();
    virtual void slot38() throw();
    virtual void slot3c() throw();
    virtual void slot40() throw();
    virtual void GetAabbHits(const Aabb& aabb, void* pairs);
};

struct FilterResult {
    char val;
    FilterResult() throw() {}
};

struct FilterBase {
    virtual void slot00() throw();
    int unk04;
};

struct FilterSub {
    virtual void slot00() throw();
    virtual FilterResult IsCollisionEnabled(const Collidable* a, const Collidable* b) throw();
};

struct C96CollisionFilter : public FilterBase, public FilterSub {
};

struct DispatcherAgentEntry {
    void (__cdecl* m_func)(const Collidable* a, const Collidable* b, const void* input, void* collector) throw();
    void* m_func1;
    void* m_func2;
    void* m_func3;
    void* m_func4;
};

struct C96CollisionDispatcher {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    unsigned char m_agent2TypeMap[32][32];
    unsigned char m_agent3TypeMap[32][32];
    int m_iEntryCount;
    DispatcherAgentEntry m_entries[35];
};

struct QueryCollisionInput {
    C96CollisionDispatcher* m_pCollisionDispatcher;
    int unk04;
    float m_fScalar;
};

struct Collector {
    void* vtable;
    char m_earlyOutHit;
};

struct MonitorCommand {
    const char* m_name;
    unsigned int m_ticks;
    unsigned int m_extra;
    const char* m_category;
};

struct C96MonitorStream {
    char* m_kRayStart;
    char* m_pos;
    char* m_kRayEnd;
    char* m_endLimit;

    static C96MonitorStream& GetMonitorStream() throw() {
        return *(C96MonitorStream*)TlsGetValue(DAT_0126835c);
    }
};

struct World {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    BroadPhase* m_pJobSemaphore;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    QueryCollisionInput* m_pCollisionInput;
    C96CollisionFilter* m_pCollisionFilter;

    void FUN_00c96df0(Collidable* collA, const QueryCollisionInput* input, Collector* collector) throw();
};

// @fnv 0x00c96df0
void World::FUN_00c96df0(Collidable* collA, const QueryCollisionInput* input, Collector* collector) throw() {

    C96MonitorStream& ms1 = C96MonitorStream::GetMonitorStream();
    char* pos1 = ms1.m_pos;
    if (pos1 < ms1.m_endLimit) {
        ((MonitorCommand*)pos1)->m_name = str_010c68ec;
        ((MonitorCommand*)pos1)->m_category = ::str_010c6748;
        _ReadWriteBarrier();
        unsigned int t;
        t = static_cast<unsigned int>(__rdtsc());
        ((MonitorCommand*)pos1)->m_ticks = t;
        ms1.m_pos = pos1 + 16;
    }

    float diff = input->m_fScalar - this->m_pCollisionInput->m_fScalar * 0.5;
    float tol = (diff < ::_DAT_01012060) ? 0.0f : diff;

    Aabb aabb;
    collA->m_pCollisionShape->getAabb(collA->m_kMotionTransform, tol, aabb);

    InplaceArray<BroadPhaseHandlePair, 128> pairs;
    this->m_pJobSemaphore->GetAabbHits(aabb, &pairs);

    int typeA = collA->m_pCollisionShape->m_type;
    const BroadPhaseHandlePair* p = pairs.m_data;

    C96MonitorStream& ms2 = C96MonitorStream::GetMonitorStream();
    char* pos2 = ms2.m_pos;
    if (pos2 < ms2.m_endLimit) {
        ((MonitorCommand*)pos2)->m_name = str_010c68dc;
        _ReadWriteBarrier();
        unsigned int t;
        t = static_cast<unsigned int>(__rdtsc());
        ((MonitorCommand*)pos2)->m_ticks = t;
        ms2.m_pos = pos2 + 12;
    }

    int count = pairs.m_iElementCount;
    while (--count >= 0) {
        BroadPhaseHandle* handleB = p->m_kPointB;
        Collidable* collB = (Collidable*)((char*)handleB + handleB->m_iOwnerOffset);
        if (collA != collB) {
            if (this->m_pCollisionFilter->IsCollisionEnabled(collA, collB).val) {
                Shape* shapeB = collB->m_pCollisionShape;
                if (shapeB) {
                    unsigned char agentType = input->m_pCollisionDispatcher->m_agent2TypeMap[typeA][shapeB->m_type];
                    input->m_pCollisionDispatcher->m_entries[agentType].m_func(collA, collB, input, collector);
                    if (collector->m_earlyOutHit) {
                        break;
                    }
                }
            }
        }
        ++p;
    }

    C96MonitorStream& ms3 = C96MonitorStream::GetMonitorStream();
    char* pos3 = ms3.m_pos;
    if (pos3 < ms3.m_endLimit) {
        ((MonitorCommand*)pos3)->m_name = ::str_01076f38;
        _ReadWriteBarrier();
        unsigned int t;
        t = static_cast<unsigned int>(__rdtsc());
        ((MonitorCommand*)pos3)->m_ticks = t;
        ms3.m_pos = pos3 + 12;
    }
}
}  // namespace fnv_00c96df0

struct S96_BoolResult {char value;};
extern const char str_010c6908[];
struct S96_TimerEntry {const char* name; unsigned tick; unsigned unk08;};
struct S96_Timer {int unk00; S96_TimerEntry* unk04; int unk08; S96_TimerEntry* unk0C;};
struct S96_Collidable {int unk00,unk04,unk08,unk0C,unk10,unk14; short unk18; signed char unk1A;};
struct S96_Constraint {unsigned char unk00,unk01,unk02,unk03; int unk04,unk08,unk0C; S96_Collidable* unk10; S96_Collidable* unk14;};
struct S96_EntityArray {void** data; int size; int capacity;};
struct S96_Island { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; unsigned char unk24,unk25; short unk26; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; S96_EntityArray unk48; int unk54; int unk58; S96_Constraint** unk5C; int unk60;};
struct S96_IslandArray {S96_Island** data; int size; int capacity;};
struct S96_FilterCheck {virtual void slot0(); virtual S96_BoolResult Check(S96_Collidable*,S96_Collidable*);};
struct S96_Filter {int unk00,unk04; S96_FilterCheck unk08;};
struct S96_Operation {unsigned char unk00,unk01,unk02,unk03;};
struct S96_RemovalList {S96_Constraint** data; int size; int capacity; S96_Constraint* local[32]; void clear(){size=0;} int GetLogicalSize() const {return size;} S96_Constraint*& back(){return data[size-1];} void popBack(){--size;}};
struct S96_WorldShell : hkpWorld {
    void FUN_00c91120(); 
 __forceinline void S96_attempt() {
  if(!m_iCriticalOperationsLockCount && !m_bBlockExecutingPendingOperations) {
   if(m_iPendingOperationCount) reinterpret_cast<::FUN_00c91120 *>(this)->ExecutePendingOperations();
   if(m_iPendingOperationQueueCount==1 && m_iQueuedOperationCount) reinterpret_cast<::FUN_00c91140_Class *>(this)->FUN_00c91140();
  }
 }
 static __forceinline void S96_TimerBegin(const char* name) {
  S96_Timer* timer=(S96_Timer*)TlsGetValue(DAT_0126835c);
  if(timer->unk04<timer->unk0C) {
   S96_TimerEntry* entry=timer->unk04;
   entry->name=name;
   unsigned tick;
   tick = static_cast<unsigned int>(__rdtsc());
   entry->tick=tick;
   timer->unk04=entry+1;
  }
 }
 static __forceinline void S96_TimerEnd() {
  S96_Timer* timer=(S96_Timer*)TlsGetValue(DAT_0126835c);
  if(timer->unk04<timer->unk0C) {
   S96_TimerEntry* entry=timer->unk04;
   entry->name=::DAT_010c41f8;
   unsigned tick;
   tick = static_cast<unsigned int>(__rdtsc());
   entry->tick=tick;
   timer->unk04=entry+1;
  }
 }
 __forceinline bool S96_enabled(S96_Constraint* c) {
  return ((S96_Filter*)m_pCollisionFilter)->unk08.Check(c->unk10,c->unk14).value && ((char*)m_pDispatcher)[0x1bb0+c->unk10->unk1A*10+c->unk14->unk1A];
 }
 void FUN_00c96ff0(int mode,int update);
public:
};
// Constraint storage blocks of an island are 512 bytes.
static const int kS96BlockBytes = 512;
// @fnv 0x00c96ff0
void S96_WorldShell::FUN_00c96ff0(int mode,int update) {
 if(m_iCriticalOperationsLockCount) {
  S96_Operation op;
  op.unk00=21;
  op.unk01=(unsigned char)mode;
  op.unk02=(unsigned char)update;
  reinterpret_cast<::WorldWithPending *>(this)->FUN_00c91160();
  return;
 }
 m_bBlockExecutingPendingOperations=true;
 S96_TimerBegin(str_010c6908);
 if(mode==0) {
  for(int i=0;i<m_kActiveSimulationIslands.m_iElementCount;++i) {
   S96_EntityArray& entities=((S96_Island*)m_kActiveSimulationIslands.m_data[i])->unk48;
   for(int j=0;j<entities.size;++j) reinterpret_cast<::CallRet *>(this)->FUN_00c946e0((::CollisionEntity *)(entities.data[j]),0,update);
  }
  for(int i=0;i<m_kInactiveSimulationIslands.m_iElementCount;++i) {
   S96_EntityArray& entities=((S96_Island*)m_kInactiveSimulationIslands.m_data[i])->unk48;
   for(int j=0;j<entities.size;++j) reinterpret_cast<::CallRet *>(this)->FUN_00c946e0((::CollisionEntity *)(entities.data[j]),0,update);
  }
  } else {
  ++m_iCriticalOperationsLockCount;
  S96_IslandArray* arrays[2]={(S96_IslandArray*)&m_kActiveSimulationIslands,(S96_IslandArray*)&m_kInactiveSimulationIslands};
  for(int a=0;a<2;++a) {
   S96_RemovalList removed;
   removed.data=removed.local;
   removed.size=0;
   removed.capacity=0x80000020;
   for(int i=0;i<arrays[a]->size;++i) {
    S96_Island* island=arrays[a]->data[i];
    removed.clear();
    int j=0;
    while(j<island->unk60) {
     S96_Constraint* current=island->unk5C[j++];
     S96_Constraint* end=(j==island->unk60)?(S96_Constraint*)((char*)current+island->unk58):(S96_Constraint*)((char*)current+kS96BlockBytes);
     for(;current<end;current=(S96_Constraint*)((char*)current+current->unk03)) {
      if(!S96_enabled(current)) {
       hkMemoryRouter* holder=&hkMemoryRouter::getInstance();
       if(removed.size==(removed.capacity&0x3fffffff)) ::ResizeAudioStream((::AudioAllocator *)(holder->m_heap),(::AudioStream *)(void *)(&removed),4);
       removed.data[removed.size++]=current;
       island->unk25=(island->unk25&~2)|1;
      } else if(update==1) ::FUN_00cfeba0((::FUN_00cfeba0_Obj *)(current),(void **)(void *)((void*)m_pCollisionInput),island);
     }
    }
    while(removed.GetLogicalSize()) {
     S96_Constraint* c=removed.back();
     removed.popBack();
     ::FUN_00cc1160((::Owner *)(c));
    }
   }
   hkMemoryAllocator* alloc=hkMemoryRouter::getInstance().m_heap;
   removed.size=0;
   if((removed.capacity&0x80000000)==0) alloc->bufFree(removed.data,(removed.capacity&0x3fffffff)*4);
  }
  --m_iCriticalOperationsLockCount;
 }
 if(mode==0) {
  for(int i=0;i<m_kPhantoms.m_iElementCount;++i) reinterpret_cast<::WorldC944 *>(this)->UpdatePhantom((::PhantomC944 *)(m_kPhantoms.m_data[i]),update);
 }
 m_bBlockExecutingPendingOperations=false;
 S96_attempt();
 S96_TimerEnd();
}

extern const char str_010c699c[];
extern const char str_010c698c[];
extern const char str_010c697c[];
extern const char str_010c6970[];
extern const char str_010c6964[];
extern const char str_010c6938[];
extern const char str_010c692c[];
extern const char str_010c6920[];

struct S97_Bool {
    char m_cBooleanValue;
    inline S97_Bool(bool b) { m_cBooleanValue = static_cast<char>(b); }
    inline operator bool() const { return m_cBooleanValue != 0; }
};

template <class T> struct S97_PadSpu {
    T m_kStorage;
    __forceinline T val() const { return m_kStorage; }
    __forceinline T operator->() const { return m_kStorage; }
    __forceinline void operator=(const T& t) { m_kStorage = t; }
};

struct S97_MonitorStream {
    S97_PadSpu<char*> m_kRayStart;
    S97_PadSpu<char*> m_kRayEnd;
    S97_PadSpu<char*> m_pRayCursor;
    S97_PadSpu<char*> m_pCurrentCommand;

    static __forceinline S97_MonitorStream& GetMonitorStream() { return *(S97_MonitorStream*)TlsGetValue(DAT_0126835c); }
    __forceinline char* GetStreamEnd() { return m_kRayEnd.val(); }
    __forceinline char* getCapacityMinus16() { return m_pCurrentCommand.val(); }
    __forceinline S97_Bool memoryAvailable() { return GetStreamEnd() < getCapacityMinus16(); }
    __forceinline void setEnd(char* ptr) { m_kRayEnd = ptr; }

    struct CommandTimingEntry {
        const char* m_pCommandName;
        unsigned int m_uiStartTicks;
        unsigned int m_uiEndTicks;
        __forceinline void setTime()
        {
            unsigned int ticks;
            ticks = static_cast<unsigned int>(__rdtsc());
            m_uiStartTicks = ticks;
        }
    };
    struct TimedNameRecord : public CommandTimingEntry {
        const char* m_pFirst;
    };
public:
};

static __forceinline void S97_timerList(const char* name1, const char* name2)
{
    S97_MonitorStream& mStream = S97_MonitorStream::GetMonitorStream();
    if (mStream.memoryAvailable()) {
        S97_MonitorStream::TimedNameRecord* h = reinterpret_cast<S97_MonitorStream::TimedNameRecord*>(mStream.GetStreamEnd());
        h->m_pCommandName = name1;
        h->m_pFirst = name2;
        h->setTime();
        mStream.setEnd(reinterpret_cast<char*>(h + 1));
    }
}
static __forceinline void S97_timer(const char* name)
{
    S97_MonitorStream& mStream = S97_MonitorStream::GetMonitorStream();
    if (mStream.memoryAvailable()) {
        S97_MonitorStream::CommandTimingEntry* h = reinterpret_cast<S97_MonitorStream::CommandTimingEntry*>(mStream.GetStreamEnd());
        h->m_pCommandName = name;
        h->setTime();
        mStream.setEnd(reinterpret_cast<char*>(h + 1));
    }
}

struct S97_HeapAllocator { __forceinline hkMemoryAllocator& get(const void*) { return hkMemoryRouter::getInstance().heap(); } };
struct S97_TempAllocator { __forceinline hkMemoryAllocator& get(void*) { return hkMemoryRouter::getInstance().temp(); } };

template <typename T> struct S97_ArrayBase {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline S97_ArrayBase() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    __forceinline S97_ArrayBase(T* ptr, int size, int capacity) : m_data(ptr), m_iElementCount(size), m_iCapacityState(capacity | 0x80000000) {}
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline T* begin() { return m_data; }
    __forceinline void clear() { m_iElementCount = 0; }
    __forceinline void _clearAndDeallocate(hkMemoryAllocator& alloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0) {
            alloc._bufFree<T>(m_data, getCapacity());
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
template <typename T, typename A> struct S97_Array : public S97_ArrayBase<T> {
    __forceinline S97_Array() {}
    __forceinline S97_Array(T* buffer, int size, int capacity) : S97_ArrayBase<T>(buffer, size, capacity) {}
    __forceinline void ClearAndRelease() { S97_ArrayBase<T>::_clearAndDeallocate(A().get(this)); }
};
template <typename T, unsigned N> struct S97_InplaceArray : public S97_Array<T, S97_HeapAllocator> {
    __forceinline explicit S97_InplaceArray(int size = 0) : S97_Array<T, S97_HeapAllocator>(m_kStorage, size, N) {}
    T m_kStorage[N];
};

struct S97_Aabb;
struct S97_Shape {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18();
    virtual void getAabb(const void* localToWorld, float tolerance, S97_Aabb& out) const;
    int unk04; int unk08; int m_type;
    __forceinline int getType() const { return m_type; }
};
struct S97_Collidable {
    const S97_Shape* m_pCollisionShape; unsigned int m_uiCollisionShapeKey; const void* m_pMotionState; const void* m_parent;
    __forceinline const S97_Shape* getShape() const { return m_pCollisionShape; }
    __forceinline const void* getTransform() const { return m_pMotionState; }
};
struct S97_CollisionInput;
typedef void (__cdecl* S97_GetClosestPointsFunc)(const S97_Collidable&, const S97_Collidable&, const S97_CollisionInput&, void*);
struct S97_AgentFuncs { S97_GetClosestPointsFunc m_pGetPenetrationsFunc; int f04; int f08; int f0C; int f10; };
struct S97_DispatcherHead {
    int unk000; int unk004; int unk008; int unk00C;
};
struct S97_Dispatcher {
    __forceinline S97_GetClosestPointsFunc getGetClosestPointsFunc(int typeA, int typeB) const
    {
        const hkpCollisionDispatcher* dispatcher = reinterpret_cast<const hkpCollisionDispatcher*>(this);
        int idx = (unsigned char)dispatcher->m_agent2Types[typeA][typeB];
        return (S97_GetClosestPointsFunc)dispatcher->m_agent2Func[idx].m_getClosestPointsFunc;
    }
};
struct S97_CollisionInput {
    S97_PadSpu<S97_Dispatcher*> m_pCollisionDispatcher;
    int unk04;
    float m_fScalar;
    __forceinline float getTolerance() const { return m_fScalar; }
};
struct S97_CcFilter {
    virtual void v00();
    virtual S97_Bool IsCollisionEnabled(const S97_Collidable& a, const S97_Collidable& b) const;
};
struct S97_RefObject { virtual ~S97_RefObject(); unsigned short m_usMemSizeAndFlags; short m_sReferenceCount; };
struct S97_CollisionFilter : public S97_RefObject, public S97_CcFilter {};
struct __declspec(align(16)) S97_Aabb { float m_kMinimumCorner[4]; float m_kMaximumCorner[4]; };
struct S97_TypedHandle {
    int m_iOwnerObjectOffset; signed char m_type; signed char m_iOwnerOffset;
    __forceinline void* getOwner() const { return const_cast<char*>(reinterpret_cast<const char*>(this) + m_iOwnerOffset); }
};
struct S97_HandlePair { S97_TypedHandle* m_kPointA; S97_TypedHandle* m_kPointB; };
struct S97_BroadPhase {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40();
    virtual void FindOverlappingPairs(const S97_Aabb& aabb, S97_ArrayBase<S97_HandlePair>& pairsOut) const;
};
struct S97_TreeWorldManager {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual bool isUpToDate() const;
    int unk04; int unk08; const void* m_pRayQueryAabbTree; const void* m_pKdTree;
    __forceinline const void* getAabbTree() const { return m_pRayQueryAabbTree; }
    __forceinline const void* getKdTree() const { return m_pKdTree; }
};

void __cdecl FUN_00d1c560(const void* tree, const S97_Aabb* aabb, void* callback, S97_ArrayBase<void*>* hits, void* mask, void* context);
__declspec(noinline) void __cdecl CallWithDefaults(const void* tree, const S97_Aabb& aabb, S97_ArrayBase<void*>& hits) {
    if (tree) FUN_00d1c560(tree, &aabb, 0, &hits, 0, 0);
}

struct S97_World {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54;
    S97_BroadPhase* m_pJobSemaphore;
    S97_TreeWorldManager* m_pKdTreeManager;
    int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74;
    S97_CollisionInput* m_pCollisionInput;
    S97_CollisionFilter* m_pCollisionFilter;
    inline const S97_CollisionInput* getCollisionInput() const { return m_pCollisionInput; }
    inline const S97_CollisionFilter* getCollisionFilter() const { return m_pCollisionFilter; }
    void FUN_00c97850(const S97_Collidable* collA, const S97_CollisionInput& input, void* collector) const;
};

// @fnv 0x00c97850
void S97_World::FUN_00c97850(const S97_Collidable* collA, const S97_CollisionInput& input, void* collector) const
{
    S97_Aabb aabb;
    collA->getShape()->getAabb(collA->getTransform(), input.getTolerance() - getCollisionInput()->getTolerance() * DAT_01011588, aabb);

    if (m_pKdTreeManager && m_pKdTreeManager->isUpToDate()) {
        S97_timerList(str_010c699c, str_010c698c);
        const void* tree = m_pKdTreeManager->getAabbTree();
        const void* kdTree = m_pKdTreeManager->getKdTree();
        if (tree) {
            S97_InplaceArray<void*, 128> hits;
            CallWithDefaults(tree, aabb, hits);
            S97_timer(str_010c697c);
            int typeA = collA->getShape()->getType();
            for (int i = 0; i < hits.GetLogicalSize(); i++) {
                const S97_Collidable* collB = (const S97_Collidable*)hits[i];
                if (collA == collB) continue;
                if (!getCollisionFilter()->IsCollisionEnabled(*collA, *collB)) continue;
                const S97_Shape* shapeB = collB->getShape();
                if (!shapeB) continue;
                int typeB = shapeB->getType();
                S97_GetClosestPointsFunc func = input.m_pCollisionDispatcher->getGetClosestPointsFunc(typeA, typeB);
                func(*collA, *collB, input, collector);
            }
            hits.ClearAndRelease();
        }
        if (kdTree) {
            S97_timer(str_010c6970);
            S97_Array<uintptr_t, S97_TempAllocator> hits;
            ::FUN_00d1b850((::QueryObj *)(kdTree), &(aabb), &(hits));
            S97_timer(str_010c6964);
            int typeA = collA->getShape()->getType();
            for (int i = 0; i < hits.GetLogicalSize(); i++) {
                const S97_Collidable* collB = (const S97_Collidable*)hits[i];
                if (collA == collB) continue;
                if (!getCollisionFilter()->IsCollisionEnabled(*collA, *collB)) continue;
                const S97_Shape* shapeB = collB->getShape();
                if (!shapeB) continue;
                int typeB = shapeB->getType();
                S97_GetClosestPointsFunc func = input.m_pCollisionDispatcher->getGetClosestPointsFunc(typeA, typeB);
                func(*collA, *collB, input, collector);
            }
            hits.ClearAndRelease();
        }
        S97_timer(str_01076f38);
    } else {
        S97_timerList(str_010c6938, str_010c692c);
        S97_InplaceArray<S97_HandlePair, 128> hits;
        m_pJobSemaphore->FindOverlappingPairs(aabb, hits);
        S97_HandlePair* p = hits.begin();
        int typeA = collA->getShape()->getType();
        S97_timer(str_010c6920);
        for (int i = hits.GetLogicalSize() - 1; i >= 0; p++, i--) {
            const S97_TypedHandle* tp = p->m_kPointB;
            const S97_Collidable* collB = static_cast<const S97_Collidable*>(tp->getOwner());
            if (collA == collB) continue;
            if (!getCollisionFilter()->IsCollisionEnabled(*collA, *collB)) continue;
            const S97_Shape* shapeB = collB->getShape();
            if (!shapeB) continue;
            int typeB = shapeB->getType();
            S97_GetClosestPointsFunc func = input.m_pCollisionDispatcher->getGetClosestPointsFunc(typeA, typeB);
            func(*collA, *collB, input, collector);
        }
        S97_timer(str_01076f38);
        hits.ClearAndRelease();
    }
    }

namespace fnv_00c91f70 {
#pragma intrinsic(__rdtsc)
#pragma intrinsic(_ReadWriteBarrier)
extern "C" unsigned __int64 __rdtsc();

extern "C" void _ReadWriteBarrier();

extern unsigned long g_monitorTls;
extern const char g_rayBegin[];
struct RayTimerEntry { const char* volatile name; unsigned int ticks; unsigned int secondCounter; };
struct RayMonitor { void* unk00; RayTimerEntry* current; void* unk08; RayTimerEntry* end; };
inline void RecordRayTimer(const char* name) {
    RayMonitor* monitor=(RayMonitor*)TlsGetValue(g_monitorTls);
    RayTimerEntry* entry=monitor->current;
    if(entry < monitor->end) {
        entry->name=name;
        _ReadWriteBarrier();
        volatile unsigned int ticks=(unsigned int)__rdtsc();
        entry->ticks=ticks;
        monitor->current=entry+1;
    }
}
struct RayManager {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual bool IsEnabled(); virtual void slot5();
    virtual void CastRay(const void*,void*,void*);
};
struct RayCaster {
    virtual void Process();
    int unk04,unk08,unk0c;
    hkVector4 m_vRayOrigins,m_direction,m_inverseDirection;
    void* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    RayCaster() : m_pCollisionShape(0),m_uiCollisionShapeKey(0) {}
    void CastRay(void*,const void*,void*,int,void*);
};
struct RayWorld : hkpWorld { void FUN_00c91f70(const void* input,void* output); };
// Records ray timer markers, then dispatches the ray cast to the RayManager if enabled or to a local RayCaster otherwise.
// @fnv 0x00c91f70
void RayWorld::FUN_00c91f70(const void* input,void* output) {
    RecordRayTimer(g_rayBegin);
    if(m_pKdTreeManager && ((RayManager*)m_pKdTreeManager)->IsEnabled()) {
        ((RayManager*)m_pKdTreeManager)->CastRay(input,m_pCollisionFilter,output);
    } else {
        __declspec(align(16)) RayCaster caster;
        reinterpret_cast<::CbfOwner *>(&(caster))->FUN_00cbf860((::CbfTarget *)(m_pJobSemaphore),(::CbfSrc *)(input),(int *)(m_pCollisionFilter),0,(intptr_t)(output));
    }
    RecordRayTimer(::DAT_010c41f8);
}
}  // namespace fnv_00c91f70

extern void* DAT_00fdf044;
namespace fnv_00c92040 {
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);

struct S00c92040_Rec {
    const char* name;
    unsigned int tsc;
    unsigned int unk08;
};

struct S00c92040_Pool {
    void* unk00;
    S00c92040_Rec* cur;
    void* unk08;
    S00c92040_Rec* end;
};

struct S00c92040_Ifc {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool v4();
    virtual void v5(int, int, int);
    virtual void v6();
    virtual void v7(const void*, void*, void*);
};

struct __declspec(align(16)) S00c92040_Arg {
    const char* p00;
    unsigned int u04;
    unsigned int u08;
    unsigned int u0C;
    unsigned int u10;
    unsigned int u14;
    unsigned int u18;
    unsigned int u1C;
    unsigned int u20;
    unsigned int u24;
    unsigned int u28;
    unsigned int u2C;
    int f30;
    int f34;
    int f38;
    int f3C;

};

struct S00c92040_Obj {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* p58;
    S00c92040_Ifc* p5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* p7C;

    void FUN_00c92040(const void* a, void* b);
};

// @fnv 0x00c92040
void S00c92040_Obj::FUN_00c92040(const void* a, void* b)
{
    extern const char str_010c64a8[];
    extern const char str_010c41f8[];
    extern const char DAT_010c647c[];

    typedef S00c92040_Pool* (* AllocFn)(unsigned long);
    AllocFn alloc = (AllocFn)DAT_00fdf044;

    S00c92040_Pool* pool = alloc(DAT_0126835c);
    S00c92040_Rec* rec = pool->cur;

    if (rec < pool->end) {
        rec->name = str_010c64a8;
        _ReadWriteBarrier();
        volatile unsigned int ts = (unsigned int)__rdtsc();
        rec->tsc = ts;
        rec++;
        pool->cur = rec;
    }

    if (p5C != 0 && p5C->v4()) {
        p5C->v7(a, p7C, b);
    } else {
        S00c92040_Arg arg;
        arg.p00 = DAT_010c647c;
        arg.f30 = 0;
        arg.f34 = 0;
        reinterpret_cast<::S_00cfab30_this *>(&(arg))->RecordAndDispatch((::S_00cfab30_object *)(p58), (::S_00cfab30_arg *)(a), p7C, nullptr, b);
    }

    pool = alloc(DAT_0126835c);
    rec = pool->cur;

    if (rec < pool->end) {
        rec->name = str_010c41f8;
        _ReadWriteBarrier();
        volatile unsigned int ts = (unsigned int)__rdtsc();
        rec->tsc = ts;
        rec++;
        pool->cur = rec;
    }
}
}  // namespace fnv_00c92040

namespace fnv_00c93c30 {
struct FnvBody;

struct FnvBodyArrayEntry {
    void* unk00;
    FnvBody* unk04;
};

struct FnvBodyArray {
    FnvBodyArrayEntry* m_data;
    int m_uiItemCount;
    int m_pRayCursor;
};

struct FnvBody {
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    signed char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    signed char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    unsigned char unk14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    unsigned char unk18;
};

struct FnvAdjustedBody {
    signed char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    unsigned char unk14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    unsigned char unk18;
};

struct FnvActionTarget {
};



struct FnvBroadPhase {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44(const void* flags, FnvBodyArray* bodies);
};



struct FnvMsg {
    unsigned char unk00;
    void* unk04;
};

struct FnvWorld : WorldWithPending {
    void FUN_00c93c30(const void* flags);
};

// When locked, queues a message via FUN_00c91160; otherwise queries bodies from the broad phase and calls FUN_00c9c1d0 on each whose adjusted byte 0x18 is 1.
// @fnv 0x00c93c30
void FnvWorld::FUN_00c93c30(const void* flags) {
    if (m_iCriticalOperationsLockCount != 0) {
        FnvMsg msg;
        msg.unk00 = 0x20;

        void* buffer = hkMemoryRouter::getInstance().heap().blockAlloc(0x20);
        msg.unk04 = buffer;
        ::FUN_00cb1260(buffer, flags, 0x20);
        reinterpret_cast<::WorldWithPending *>((this))->FUN_00c91160();
        return;
    }

    FnvBroadPhase* broadPhase = (FnvBroadPhase*)m_pJobSemaphore;
    FnvBodyArray bodies;
    bodies.m_data = 0;
    bodies.m_uiItemCount = 0;
    bodies.m_pRayCursor = 0x80000000;

    broadPhase->vf44(flags, &bodies);

    int index = 0;
    while (index < bodies.m_uiItemCount) {
        FnvBody* body = bodies.m_data[index].unk04;
        unsigned char* pAdjusted = (unsigned char*)body + body->unk05;
        if (pAdjusted[0x18] == 1) {
            FnvActionTarget* target = (FnvActionTarget*)(pAdjusted + (signed char)pAdjusted[0x10]);
            if (target != 0)
                reinterpret_cast<::hkpEntityC9C *>((target))->FUN_00c9c1d0();
        }
        ++index;
    }

    hkMemoryAllocator* alloc = hkMemoryRouter::getInstance().m_heap;
    bodies.m_uiItemCount = 0;
    if ((bodies.m_pRayCursor & 0x80000000) == 0)
        alloc->bufFree(bodies.m_data, (bodies.m_pRayCursor & 0x3FFFFFFF) * 8);
}
}  // namespace fnv_00c93c30

namespace std{ class type_info; } typedef float TR;
typedef float TF32; typedef double TD64; typedef signed char TC; typedef signed char TI8;
typedef signed short TI16; typedef signed int TI32; typedef unsigned char TU; typedef unsigned char TU8;
typedef unsigned short TU16; typedef unsigned int TU32; typedef unsigned long __w64 TU1; typedef signed long __w64 TL;
typedef void*Tvl; enum TR1{ KS=0,KF=1} ;
typedef unsigned __int64 TU64; typedef __int64 TI64; typedef long TST2; typedef size_t TS4;
typedef TU16 TOI; typedef TR TT; __forceinline TL __cdecl TGBO(const void*base,const void*pntr)throw(){ return TL((const char*)pntr-(const char*)base);
} template<typename TYPE>__forceinline TYPE*__cdecl TABO(TYPE*base,TL offset)throw(){ return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base)+offset); }
class TFLOF{ public:TFLOF()throw():vf1(0){ } int vf1;
} ; class TC1; struct TV;
typedef int TB32; class TB{ public:typedef char CompileTimeTrueType; typedef int CompileTimeFalseType;
inline TB()throw(){ } inline TB(bool b)throw(){ vb1=static_cast<char>(b);
} inline operator bool()const{ return vb1!=0; }
inline TB&operator=(bool e)throw(){ vb1=static_cast<char>(e); return*this; }
inline TB operator==(bool e)const throw(){ return static_cast<int>(vb1)==static_cast<int>(e); } inline TB operator!=(bool e)const throw(){
return static_cast<int>(vb1)!=static_cast<int>(e); } private:char vb1; }
; class TH{ public:inline operator float()const; private:TI16 vv;
} ; extern"C"{ extern const TR TUF8iTR[256];
} class TUF8{ public:enum{ MAX_VALUE=256}
; inline operator float()const; public:TU8 vv; }
; extern"C"{ extern const TR TUI8TR[256]; }
template<typename ENUM,typename STORAGE>class TE1{ public:TE1()throw(){ } TE1(ENUM e)throw(){
vs8=static_cast<STORAGE>(e); } operator ENUM()const{ return static_cast<ENUM>(vs8);
} void operator=(ENUM e)throw(){ vs8=static_cast<STORAGE>(e); }
TB operator==(ENUM e)const throw(){ return vs8==static_cast<STORAGE>(e); } TB operator!=(ENUM e)const throw(){
return vs8!=static_cast<STORAGE>(e); } private:STORAGE vs8; }
; template<typename BITS,typename STORAGE>class TF; template<typename TYPE>class TPS{ public:__forceinline TPS()throw(){
} __forceinline TPS(TYPE e)throw():vs8(e){ } __forceinline void operator=(TYPE e)throw(){
vs8=e; } __forceinline TYPE val()const throw(){ return vs8;
} __forceinline TYPE operator->()const throw(){ return vs8; }
__forceinline operator TYPE()const{ return val(); } private:TYPE vs8;
} ; struct TCOBAC; enum KMC{
KMCR,KMCB,KMCC5,KMCCS1,KMCD4,KMCE1,KMCS1,KMCG,KMCD3,KMCM2,KMCSD,KMCV1,KMCD1,KMCU5,KMCA4,KMCB1,KMCC3,KMCA2,KMCT,KMCDF,KMCD,KMCU,KMCBC,KMCS6,KMCA5,KMCS4,KMCS,KMCS5,KMCM4,KMCM1,KMCT1,KMCH,KMCA1,KMCA3,KMCBP,KMCC7,KMCD2,KMCM,KMCS2,KMCC4,KMCC1,KMCM5,KMCA,KMCD5,KMCC6,KMCE,KMCM6,KMCW,KMCRB,KMCP1,KMCS3,KMCC,KMCC2,KMCV,KMCI,KMCAU,KMCAC1,KMCAD,KMCAM,KMCAR,KMCAC2,KMCAR1,KMCAC,KMCBR,KMCBD,KMCCR,KMCCD,KMCCS,KMCAN,KMCAA,KMCAS,KMCU1,KMCU2,KMCU3,KMCU4,KMCPA,KMCM3} ; template<typename T>class TTLD{ public:__forceinline T getData()const throw(){
return(T)TlsGetValue(vsI1); } unsigned long vsI1; }
; typedef std::type_info TCTI; struct TCTIH; class TCRIU;
template<typename T>struct TSOTOV{ enum{ val=sizeof(T)} ;
} ; template<>struct TSOTOV<void>{ enum{
val=1} ; } ;
namespace TMU{ template<unsigned int NBYTES>struct IntegerTypeByByteSize; template<>struct IntegerTypeByByteSize<1>;
template<>struct IntegerTypeByByteSize<2>; template<>struct IntegerTypeByByteSize<4>; template<>struct IntegerTypeByByteSize<8>; template<unsigned int NBYTES>struct IntegerTypeByByteSize;
} namespace TMU{ } class TO1; template<typename TYPE>__forceinline void __cdecl TDC(TYPE*ptr,int numberOfObjects,int cl)throw(){
hkMemoryRouter::getInstance().heap().blockFree(static_cast<void*>(ptr),numberOfObjects*TSOTOV<TYPE>::val); } template<typename TYPE>__forceinline TYPE*__cdecl TAS1(int n,const char*what=0)throw(){ hkMemoryRouter&mem=hkMemoryRouter::getInstance();
return static_cast<TYPE*>(mem.allocateStack((((n*TSOTOV<TYPE>::val)+((128)-1))&(~((128)-1))))); } template<typename TYPE>__forceinline void __cdecl TDS(TYPE*ptr)throw(){ hkMemoryRouter::getInstance().deallocateStack(static_cast<void*>(ptr));
} extern const TC1 TBOC; class TBO{ public:__forceinline virtual~TBO()throw();
public:} ; extern const TC1 TROC; class TSC3;
class TCS2; class TVCR; class TRO:public TBO{ public:virtual~TRO()throw();
 enum LockMode{ LOCK_MODE_NONE,LOCK_MODE_AUTO,LOCK_MODE_MANUAL} ;
virtual void vs9()const throw(); virtual void vs10()const throw(); public:enum{ MASK_MEMSIZE=0x7fff}
; TU16 vmSAF; mutable TI16 vrC; public:}
; template<typename T>class TS3; extern struct TSIN*TSIL; struct TSIN;
class TO1; class TSW; class TS6; class TSP;
class TSB1; class TMT; struct TCHA; template<typename T,typename A>class TA2;
class TO1; typedef TO1 TO; class TE2; class TES;
typedef void(__cdecl*TERF)(const char*s,void*errorReportObject); namespace TCE2{ template<bool b>struct BooleanTrueSpecialization; template<>struct BooleanTrueSpecialization<true>;
template<bool b>struct TrueOnlyTrait; template<>struct TrueOnlyTrait<true>; } template<class TYPE>class TRP{
public:__forceinline TYPE*val()const throw(); __forceinline operator TYPE*()const; private:TYPE*vp4; }
; template<class TYPE>__forceinline TYPE*TRP<TYPE>::val()const throw(){ return vp4; }
struct TPNA; 
template<bool N>struct TTB{ typedef TTB<N>type; enum{ result=N}
; } ; typedef TTB<true>TTIP;
typedef TTB<false>TTIC; template<typename T>TB::CompileTimeFalseType operator==(const T&,const TTIP&)throw(); template<typename T>struct TIPT:public TTB<(sizeof(*static_cast<T*>(0)==*static_cast<const TTIP*>(0))==sizeof(TB::CompileTimeTrueType))>{ }
; template<>struct TIPT<bool>:public TTIP{ } ;
; template<>struct TIPT<TB>:public TTIP{ } ;
; template<>struct TIPT<char>:public TTIP{ } ;
; template<>struct TIPT<TI8>:public TTIP{ } ;
; template<>struct TIPT<TU8>:public TTIP{ } ;
; template<>struct TIPT<TI16>:public TTIP{ } ;
; template<>struct TIPT<TU16>:public TTIP{ } ;
; template<>struct TIPT<TI32>:public TTIP{ } ;
; template<>struct TIPT<TU32>:public TTIP{ } ;
; template<>struct TIPT<TI64>:public TTIP{ } ;
; template<>struct TIPT<TU64>:public TTIP{ } ;
; template<>struct TIPT<TL>:public TTIP{ } ;
; template<>struct TIPT<TU1>:public TTIP{ } ;
; template<>struct TIPT<TUF8>:public TTIP{ } ;
; template<>struct TIPT<TH>:public TTIP{ } ;
; template<>struct TIPT<TR>:public TTIP{ } ;
; template<>struct TIPT<TD64>:public TTIP{ } ;
; template<>struct TIPT<TV>:public TTIP{ } ;
; template<typename T>struct TIPT<T*>:public TTIP{ } ;
template<typename T,unsigned int N>struct TIPT<T[N]>:public TIPT<T>{ } ; class TAU{
public:template<typename T>static __forceinline void construct(T*t,int n,TTIP)throw(); template<typename T>static __forceinline void construct(T*t,int n,TTIC)throw(); template<typename T>static __forceinline void constructWithCopy(T*t,int n,const T&tcopy,TTIP)throw(); template<typename T>static __forceinline void constructWithCopy(T*t,int n,const T&tcopy,TTIC)throw();
template<typename T>static __forceinline void destruct(T*t,int n,TTIP)throw(); template<typename T>static __forceinline void destruct(T*t,int n,TTIC)throw();
} ; template<typename T>__forceinline void TAU::construct(T*t,int n,TTIP)throw(){ }
template<typename T>__forceinline void TAU::construct(T*t,int n,TTIC)throw(){ for(int i=0;i<n;++i){ ::new(reinterpret_cast<TPNA*>(t+i))T; }
} template<typename T>__forceinline void TAU::constructWithCopy(T*t,int n,const T&tcopy,TTIP)throw(){ for(int i=0;i<n;++i){ t[i]=tcopy;
} } template<typename T>__forceinline void TAU::constructWithCopy(T*t,int n,const T&tcopy,TTIC)throw(){ for(int i=0;i<n;++i){
::new(reinterpret_cast<TPNA*>(t+i))T(tcopy); } } template<typename T>__forceinline void TAU::destruct(T*t,int n,TTIP)throw(){
} template<typename T>__forceinline void TAU::destruct(T*t,int n,TTIC)throw(){ for(int i=0;i<n;++i){ static_cast<T*>(t)[i].~T();
} } struct TCTA{ hkMemoryAllocator&get(void*)throw(){
return hkMemoryRouter::getInstance().temp(); } } ;
struct TCHA{ hkMemoryAllocator&get(const void*)throw(){ return hkMemoryRouter::getInstance().heap(); }
} ; struct TCDA; template<int OFFSET>struct TCSA;
template<typename T>class TAB{ friend class TAU; friend class TAS2; public:typedef TAB<T>ThisType;
__forceinline TAB()throw(); __forceinline TAB(T*buffer,int size,int capacity)throw(); protected:public:__forceinline~TAB()throw(); __forceinline T&operator[](int i)throw();
__forceinline const T&operator[](int i)const throw(); __forceinline int GetLogicalSize()const throw(); __forceinline int getCapacity()const throw(); __forceinline void clear()throw();
__forceinline void _clearAndDeallocate(hkMemoryAllocator&alloc)throw(); __forceinline void _pushBack(hkMemoryAllocator&alloc,const T&e)throw(); __forceinline void pushBackUnchecked(const T&e)throw(); __forceinline void FUN_00c908c0(hkMemoryAllocator&alloc,int n)throw();
__forceinline void _reserveExactly(hkMemoryAllocator&alloc,int n)throw(); __forceinline T*expandByUnchecked(int n)throw(); typedef T*iterator; typedef const T*const_iterator;
__forceinline iterator begin()throw(); __forceinline const_iterator begin()const throw(); protected:public:enum{ CAPACITY_MASK=int(0x3FFFFFFF),FLAG_MASK=int(0xC0000000),DONT_DEALLOCATE_FLAG=int(0x80000000),FORCE_SIGNED=-1}
; protected:friend class TSC3; T*vd1; int vs4;
int vcAF; public:} ; template<typename T,typename Allocator=TCHA>class TA2:public TAB<T>{
public:typedef Allocator AllocatorType; friend class TAU; typedef TA2<T,TCTA>Temp; typedef TA2<T,TCDA>Debug;
typedef TA2<T,TCHA>Heap; __forceinline TA2()throw():TAB<T>(){ } __forceinline~TA2()throw();
explicit __forceinline TA2(int size)throw(); __forceinline TA2(int size,const T&fill)throw(); protected:__forceinline TA2(const TA2&a)throw(); public:__forceinline void ClearAndRelease()throw(){
TAB<T>::_clearAndDeallocate(AllocatorType().get(this)); } __forceinline void AddBack(const T&e)throw(){ TAB<T>::_pushBack(AllocatorType().get(this),e);
} __forceinline void reserve(int size)throw(){ TAB<T>::FUN_00c908c0(AllocatorType().get(this),size); }
__forceinline void reserveExactly(int size)throw(){ TAB<T>::_reserveExactly(AllocatorType().get(this),size); } }
; template<typename T,unsigned N,typename Allocator=TCHA>class TIA:public TA2<T,Allocator>{ public:typedef TIA<T,N,Allocator>mytype; __forceinline TB wasReallocated()const throw();
public:T vs8[N]; public:} ; template<typename T,unsigned N>class TIAA16;
template<typename T>__forceinline T&TAB<T>::operator[](int i)throw(){ ; return vd1[i]; }
template<typename T>__forceinline const T&TAB<T>::operator[](int i)const throw(){ ; return vd1[i]; }
template<typename T>__forceinline int TAB<T>::GetLogicalSize()const throw(){ return vs4; } template<typename T>__forceinline int TAB<T>::getCapacity()const throw(){
return(vcAF&static_cast<int>(CAPACITY_MASK)); } template<typename T>__forceinline void TAB<T>::_reserveExactly(hkMemoryAllocator&alloc,int n)throw(){ if(getCapacity()<n){
::FUN_00c908c0((::SpawnedObject *)(&alloc),(::SpawnedArray *)(void *)(this),n,sizeof(T)); } } template<typename T>__forceinline void TAB<T>::FUN_00c908c0(hkMemoryAllocator&alloc,int n)throw(){
const int capacity=getCapacity(); if(capacity<n){ int cap2=2*capacity; int newSize=(n<cap2)?cap2:n;
::FUN_00c908c0((::SpawnedObject *)(&alloc),(::SpawnedArray *)(void *)(this),newSize,sizeof(T)); } } template<typename T>__forceinline void TAB<T>::clear()throw(){
TAU::destruct(vd1,vs4,typename TIPT<T>::type()); vs4=0; } template<typename T>__forceinline TAB<T>::TAB()throw():vd1(0),vs4(0),vcAF(DONT_DEALLOCATE_FLAG){
} template<typename T>__forceinline TAB<T>::~TAB()throw(){ ; ;
} template<typename T>__forceinline void TAB<T>::_clearAndDeallocate(hkMemoryAllocator&alloc)throw(){ clear(); if((vcAF&DONT_DEALLOCATE_FLAG)==0){
alloc._bufFree<T>(vd1,getCapacity()); } vd1=0; vcAF=DONT_DEALLOCATE_FLAG;
} template<typename T>__forceinline void TAB<T>::_pushBack(hkMemoryAllocator&alloc,const T&t)throw(){ if(vs4==getCapacity()){ ;
::ResizeAudioStream((::AudioAllocator *)(&alloc),(::AudioStream *)(void *)(this),sizeof(T)); } TAU::constructWithCopy(vd1+vs4,1,t,typename TIPT<T>::type()); vs4++;
} template<typename T>__forceinline void TAB<T>::pushBackUnchecked(const T&t)throw(){ ; TAU::constructWithCopy(vd1+vs4,1,t,typename TIPT<T>::type());
vs4++; } template<typename T>__forceinline T*TAB<T>::expandByUnchecked(int n)throw(){ ;
int oldsize=vs4; vs4=oldsize+n; TAU::construct(vd1+oldsize,vs4-oldsize,typename TIPT<T>::type()); return vd1+oldsize;
} template<typename T>typename TAB<T>::iterator TAB<T>::begin()throw(){ return vd1; }
template<typename T>typename TAB<T>::const_iterator TAB<T>::begin()const throw(){ return vd1; } template<typename T,typename Allocator>__forceinline TA2<T,Allocator>::~TA2()throw(){
ClearAndRelease(); } template<typename T,unsigned N,typename Allocator>TB TIA<T,N,Allocator>::wasReallocated()const throw(){ return this->vd1!=vs8;
} namespace TSAU{ void __cdecl FUN_00c908c0(void*,int numElem,int sizeElem)throw(); void __cdecl ResizeAudioStream(void*array,int sizeElem)throw();
} template<typename T>class TSA1{ friend void __cdecl TSAU::FUN_00c908c0(void*,int numElem,int sizeElem)throw(); friend void __cdecl TSAU::ResizeAudioStream(void*array,int sizeElem)throw();
public:__forceinline int GetLogicalSize()const throw(); __forceinline int getCapacity()const throw(); __forceinline void AddBack(const T&e)throw(); typedef T*iterator;
typedef const T*const_iterator; __forceinline iterator begin()throw(); __forceinline const_iterator begin()const throw(); __forceinline void reserve(int n)throw();
void ClearAndRelease()throw(); public:enum{ CAPACITY_MASK=TU16(0x3fff),FLAG_MASK=TU16(0xC000),DONT_DEALLOCATE_FLAG=TU16(0x8000),LOCKED_FLAG=TU16(0x4000),FORCE_SIGNED=-1} ;
protected:friend class TSC3; void releaseMemory()throw(); T*vd1; TU16 vs4;
TU16 vcAF; public:} ; template<typename T>__forceinline void TSA1<T>::ClearAndRelease()throw(){
releaseMemory(); vd1=0; vs4=0; vcAF=TU16(DONT_DEALLOCATE_FLAG|(vcAF&LOCKED_FLAG));
} template<typename T>__forceinline int TSA1<T>::GetLogicalSize()const throw(){ return vs4; }
template<typename T>__forceinline int TSA1<T>::getCapacity()const throw(){ return(vcAF&static_cast<int>(CAPACITY_MASK)); } template<typename T>__forceinline void TSA1<T>::releaseMemory()throw(){
if((vcAF&DONT_DEALLOCATE_FLAG)==0){ TDC(vd1,getCapacity(),KMCA5); } }
template<typename T>__forceinline void TSA1<T>::AddBack(const T&t)throw(){ if(vs4==getCapacity()){ TSAU::ResizeAudioStream(this,sizeof(T)); }
vd1[vs4++]=t; } template<typename T>typename TSA1<T>::iterator TSA1<T>::begin()throw(){ return vd1;
} template<typename T>typename TSA1<T>::const_iterator TSA1<T>::begin()const throw(){ return vd1; }
template<typename T>__forceinline void TSA1<T>::reserve(int n)throw(){ const int capacity=getCapacity(); if(capacity<n){ int cap2=2*capacity;
int newSize=(n<cap2)?cap2:n; TSAU::FUN_00c908c0(this,newSize,sizeof(T)); } }
template<typename KEY>struct TMO; template<>struct TMO<int>; template<typename KEY,typename VAL=KEY,typename OPS=TMO<KEY> >class TMB; template<typename KEY,typename VAL=KEY,typename OPS=TMO<KEY>,typename Allocator=TCHA>class TM;
template<int N>struct TPMS; template<>struct TPMS<8>; template<typename K,typename V,typename Allocator=TCHA>class TPM; class TVCR;
class TRV; typedef float TR; typedef __m128 TQR; class TV4;
typedef const TV4&TV4P; union TQRU; class TSR{ public:operator TR()const;
private:TQR vr; } ; typedef const TSR&TSRP;
class TV4C; typedef const TV4C&TV4CP; class TV4C; typedef const TV4C&TV4CP;
class TV4C; extern const TQR TQRH; extern const TQR TQR3333; namespace TM2{
} namespace std{ } extern"C"{
} namespace TM2{ } extern const TQR TQR0000;
extern const TQR TQR1111; extern const TQR TQR1000; extern const TQR TQR0100; extern const TQR TQR0010;
extern const TQR TQR0001; extern const TQR TQR3333; extern const TQR TQRH; extern const TQR TQRMH;
extern const TQR TQRM; extern const TQR TQRE; class TV4; class TQ;
class TM3; class TR2; class TT1; class TQT;
class TV4{ public:TB::CompileTimeTrueType operator==(const TTIP&)const throw(); ; __forceinline TV4()throw(){
} __forceinline TV4(TR x,TR y,TR z,TR w=0)throw(); __forceinline TV4(const TQR&q)throw(); __forceinline TV4(const TV4&v)throw();
private:TQR vq; public:operator TQR()const; } ;
class TQ{ public:TB::CompileTimeTrueType operator==(const TTIP&)const throw(); ; public:TV4 vv1;
protected:} ; class TM3{ public:TB::CompileTimeTrueType operator==(const TTIP&)const throw();
; protected:TV4 vc0; TV4 vc1; TV4 vc2;
} ; extern"C"{ }
class __declspec(align(16))TR2:public TM3{ public:TB::CompileTimeTrueType operator==(const TTIP&)const throw(); ; }
; class TT1{ public:TB::CompileTimeTrueType operator==(const TTIP&)const throw(); ;
private:TR2 vr2; TV4 vt5; } ;
class TST1{ public:public:public:TV4 vcOM0; TV4 vcOM1; TQ vr0;
TQ vr11; TV4 vcOML; } ;
class TQT{ public:TB::CompileTimeTrueType operator==(const TTIP&)const throw(); ; enum IdentityInitializer{
IDENTITY,} ; enum ZeroInitializer{ ZERO,}
; public:TV4 vt5; TQ vr2; TV4 vs;
} ; class TM4; static const TQR g_vNearOneVector={
1.0f-1e-5f,1.0f-1e-5f,1.0f-1e-5f,1.0f-1e-5f} ; static const TQR g_vNearNegativeOneVector={ -(1.0f-1e-3f),-(1.0f-1e-3f),-(1.0f-1e-3f),-(1.0f-1e-3f)}
; class TS6{ public:enum ReplaceType{ REPLACE_ONE,REPLACE_ALL}
; private:} ; class TSP;
class TSB1; class TSP{ public:enum StringFlags{ OWNED_FLAG=0x1,}
; inline operator const char*()const; private:const char*vsAF1; }
; class TCE; class TC1; class TCA2;
extern const TC1 TCMC; class TypeMetadataClass; class TC1; class TSW;
class TCA2; extern const TC1 TCEC; extern const TC1 TCEIC; class TCE;
extern const TC1 TRRAC; struct TRRA; extern const TC1 TRI32AC; struct TRI32A;
extern const TC1 TUAC; struct TUA; extern const TC1 TGAC; struct TGA;
extern const TC1 TMNTAC; struct TMNTA; extern const TC1 TLAC; struct TLA;
extern const TC1 TSAC; struct TSA; extern const TC1 TDAC; struct TDA;
extern const TC1 TATAC; struct TATA; extern const TC1 TDOTAC; struct TDOTA;
extern const TC1 TDAC1; struct TDA1; class TMTC{ public:enum AccessType{
KAI=0,KAR=1,KAR1=2,} ; enum ReadMode{ THIS_OBJECT_ONLY,RECURSIVE}
; protected:public:enum{ MARKED_RO=0xffffffe1,MARKED_RO_SELF_ONLY=0xffffffc1,UNMARKED=0xfffffff1} ;
TU32 vtI; TU16 vmC; protected:TU16 vmBS; public:static class TCS2*vcS1;
} ; typedef TU16 TCPI; class TCP;
enum TST{ KSI=0,KSS,KFST=KSS,KSC3,KST1,KSB,KSC,KSCV,KSC1,KSBT,KSL,KSM,KSCT1,KSCT,KSSHF,KSEM,KST,KSCM,KSMIS=KSCM+1,KSC2,KSPCV,KSME,KSCP,KSMS,KSCL,KSTC,KSMR,KSHF,KSSR,KSB1,KSP,KSPC,KSU,KSU1,KSU2,KSMI,KSA=-1} ; class TCD;
class TCV; enum TBS{ KSBS=512} ;
typedef __declspec(align(16))char TSB[KSBS]; class TA; struct TSRCI; struct TSRCO;
struct TSRBCI; struct TSRBCO; class TRHC; class TCB;
class TSC2; class TS5; typedef TU16 TVI; typedef TU32 TSK;
class TSKP; extern const TC1 TSC; class TCS1; class TS1:public TRO{
public:__forceinline void getAabb(const TT1&localToWorld,TR tolerance,TA&out)const throw(); virtual void vs111()const throw(); virtual void vs12()const throw(); virtual void vs13()const throw();
struct PhysicsShape{ bool vmA3R; bool viFOK; bool vhDMS;
} ; virtual void vs14()const throw(); protected:virtual void CalculateAabb(const TT1&localToWorld,TR tolerance,TA&out)const throw()=0;
virtual void vs15()const throw(); virtual void vs16()const throw(); virtual void vs17()const throw(); public:typedef void(__cdecl*GetSupportingVertexFunc)(const void*thisObj,TV4P direction,TCV&supportVertex);
typedef void(__cdecl*ConvertVertexIdsToVerticesFunc)(const void*thisObj,const TVI*ids,int numIds,class TCV*verticesOut); typedef int(__cdecl*WeldContactPointFunc)(const void*thisObj,TVI*featurePoints,TU8&numFeaturePoints,TV4&contactPointWs,const TT1*thisObjTransform,const TCS1*collidingShape,const TT1*collidingTransform,TV4&separatingNormalInOut); typedef void(__cdecl*GetCentreFunc)(const void*thisObj,TV4&centreOut); typedef int(__cdecl*GetNumCollisionSpheresFunc)(const void*thisObj);
typedef const TS5*(__cdecl*GetCollisionSpheresFunc)(const void*thisObj,TS5*sphereBuffer); typedef void(__cdecl*GetAabbFunc)(const void*thisObj,const TT1&localToWorld,TR tolerance,TA&out); typedef TB(__cdecl*CastRayFunc)(const void*thisObj,const TSRCI&input,TSRCO&output); typedef void(__cdecl*CastRayWithCollectorFunc)(const void*thisObj,const TSRCI&input,const TCB&cdBody,TRHC&collector);
typedef TV4C(__cdecl*CastRayBundleFunc)(const void*thisObj,const TSRBCI&input,TSRBCO&output,TV4CP mask); typedef const TS1*(__cdecl*GetChildShapeFunc)(const void*thisObj,TSK key,TSB&buffer); typedef TU32(__cdecl*GetCollisionFilterInfoFunc)(const void*thisObj,TSK key); struct ShapeCallbackDispatchTable{
TPS<GetSupportingVertexFunc>vgSVF; TPS<ConvertVertexIdsToVerticesFunc>vcVITV; TPS<WeldContactPointFunc>vwCPF; TPS<GetCentreFunc>vgCF;
TPS<GetNumCollisionSpheresFunc>vgNCSF; TPS<GetCollisionSpheresFunc>vgCSF1; TPS<GetAabbFunc>vgAF; TPS<CastRayFunc>vcR;
TPS<CastRayWithCollectorFunc>vcRWC; TPS<CastRayBundleFunc>vcRB; TPS<GetChildShapeFunc>vgCSF; TPS<GetCollisionFilterInfoFunc>vgCFIF;
} ; struct AlignedShapeCallbackTable{ __declspec(align(64))GetSupportingVertexFunc vgSVF;
ConvertVertexIdsToVerticesFunc vcVITV; WeldContactPointFunc vwCPF; GetCentreFunc vgCF; GetNumCollisionSpheresFunc vgNCSF;
GetCollisionSpheresFunc vgCSF1; GetAabbFunc vgAF; CastRayFunc vcR; CastRayWithCollectorFunc vcRWC;
CastRayBundleFunc vcRB; GetChildShapeFunc vgCSF; GetCollisionFilterInfoFunc vgCFIF; }
; typedef void(__cdecl*RegisterFunc)(ShapeCallbackDispatchTable&sf); public:public:TU1 vuD; public:TE1<::TST,TU32>vt6;
public:} ; __declspec(align(16))class TAS; void TS1::getAabb(const TT1&localToWorld,TR tolerance,TA&out)const throw(){
CalculateAabb(localToWorld,tolerance,out); } class TS1; class TMS1;
class TC2; class TCB{ public:friend class TC2; __forceinline const TT1&getTransform()const throw();
__forceinline const TS1*getShape()const throw(); public:__forceinline const TMS1*GetMotionState()const throw(); __forceinline void setMotionState(const TMS1*state)throw(); public:const TS1*vs2;
TSK vsK; const void*vm3; const TCB*vp1; }
; const TT1&TCB::getTransform()const throw(){ ; return*static_cast<const TT1*>(vm3);
} const TMS1*TCB::GetMotionState()const throw(){ return static_cast<const TMS1*>(vm3); }
void TCB::setMotionState(const TMS1*state)throw(){ vm3=state; } const TS1*TCB::getShape()const throw(){
return vs2; } class TBPH{ public:TU32 vi;
public:} ; enum TCQT{ KCQI=-1,KCQF=0,KCQK,KCQD,KCQDST,KCQM1,KCQC1,KCQB,KCQU,KCQC,KCQKR,KCQM}
; class TTBPH:public TBPH{ public:protected:enum{ OFFSET_INVALID=127}
; friend class TBPB; TI8 vt6; TI8 voO;
public:TI8 voQT; TU32 vcFI; } ;
class TA; struct TAU32; class TS1; class TT1;
class TC2:public TCB{ public:inline const TS1*getShape()const throw(); inline const TTBPH*getBroadPhaseHandle()const throw(); inline TTBPH*getBroadPhaseHandle()throw();
public:public:struct BoundingVolumeData{ __forceinline void invalidate()throw(){ vm2[0]=1; vm1[0]=0;
} public:TU32 vm2[3]; TU8 veM1[3]; TU8 veS;
TU32 vm1[3]; TU8 veM[3]; TU8 vp; TU16 vnCSA;
TU16 vcCSA; TAU32*vcSA; TSK*vcSK; }
; enum ForceCollideOntoPpuReasons{ FORCE_PPU_USER_REQUEST=1,FORCE_PPU_SHAPE_REQUEST=2,FORCE_PPU_MODIFIER_REQUEST=4,} ;
protected:TI8 voO; public:TU8 vfCOP; TU16 vsSOS; class TTBPH vbPH;
public:struct BoundingVolumeData vbVD; TR vaPD; } ;
class TA{ public:TA()throw(){ } __forceinline TA(const TV4&min,const TV4&max)throw();
public:TV4 vm2; TV4 vm1; } ;
__declspec(align(16))struct TAU32; __forceinline const TS1*TC2::getShape()const throw(){ return vs2; }
inline const TTBPH*TC2::getBroadPhaseHandle()const throw(){ return&vbPH; } inline TTBPH*TC2::getBroadPhaseHandle()throw(){
return&vbPH; } struct TANE; class TLC:public TC2{
public:public:struct CollisionKeyEntry{ TANE*vaE; TLC*vp2; }
; protected:TA2<struct CollisionKeyEntry>vcE; } ;
extern const TC1 TPVC; extern const TC1 TPC; struct TPV; class CollisionRelatedClass;
class TW; class TS1; class TP; class TRB;
extern const TC1 TWOC; namespace TWO1{ enum Result{ POSTPONED,DONE}
; } class TWO:public TRO{ public:enum MtChecks{
MULTI_THREADING_CHECKS_ENABLE,MULTI_THREADING_CHECKS_IGNORE} ; inline TC2*getCollidableRw()throw(); inline const TC2*getCollidable()const throw();
virtual void vs18()throw(); public:enum BroadPhaseType{ BROAD_PHASE_INVALID,BROAD_PHASE_ENTITY,BROAD_PHASE_PHANTOM,BROAD_PHASE_BORDER,BROAD_PHASE_MAX_ID} ;
protected:friend class TW; friend class TWOU; inline void setWorld(TW*world)throw(); inline virtual~TWO()throw();
public:virtual class TMS1*GetMotionState()throw()=0; protected:TW*vw; TU1 vuD; protected:class TLC vc3;
protected:class TMTC vmTC; TSP vn; TA2<class CollisionRelatedClass>vp5; private:class TRO*vaD;
void*vtD; public:} ; inline TC2*TWO::getCollidableRw()throw(){
return&vc3; } inline const TC2*TWO::getCollidable()const throw(){ return&vc3;
} void TWO::setWorld(TW*world)throw(){ vw=world; }
extern const TC1 TMC; class TM1{ public:enum ResponseType{ RESPONSE_INVALID,RESPONSE_SIMPLE_CONTACT,RESPONSE_REPORTING,RESPONSE_NONE,RESPONSE_MAX_ID}
; private:TE1<ResponseType,TI8>vrT; TR vf2; TR vr1;
public:} ; class TSR1; struct TSI{
enum DeactivationClass{ DEACTIVATION_CLASS_INVALID,DEACTIVATION_CLASS_OFF,DEACTIVATION_CLASS_LOW,DEACTIVATION_CLASS_MEDIUM,DEACTIVATION_CLASS_HIGH,DEACTIVATION_CLASS_AGGRESSIVE,DEACTIVATION_CLASSES_END} ; struct FloatAndHalfRecord{
float vlVTI; float vaVTI; float vsOVM; float vrSVT;
float vmDS[2]; TH vmRS[2]; } ;
__declspec(align(16))float vo; float vt; float vd; float vfT;
TV4 vgAPSS; TV4 vgAPS; TV4 viVF; TV4 viIVF;
float vdDT; float vtDD; float vdDFT; float vfTDD;
float vcRV; FloatAndHalfRecord vdI[DEACTIVATION_CLASSES_END]; float vdT; float viDT;
int vnS; int vnMS; float viNMS; float viNS;
TB vfCCOIS; TU8 vdNIFSF[2]; TU8 vdIC; float vmCVS;
} ; struct T1dMSI; struct T3dAMSI;
struct TVCA; class TJS; class TVA; class TSDA;
class TSDR; class TCI2; class TSR1; struct TSET;
struct TILBE; struct TILBH; class TCI2; extern"C"{
} struct TCI1{ int vmSOS; int vsOS;
int vnSR; int vnSET; inline void clear()throw(){ vmSOS=0;
vsOS=0; vnSR=0; vnSET=0; }
} ; class TCQI1; class TCQO;
class TCO; class TCI2; extern const TC1 TCDC; extern const TC1 TCIC;
typedef void VoidTypeAlias; class TCD1; class TCD1; class TCD1;
class TE; class TRB; class TCO; class FUN_00d07830;
class TCL; class TW; extern const TC1 TCIC1; typedef void VoidTypeAlias;
class TCI2; __declspec(align(16))struct TCI3; class TMS1{ public:inline TT1&getTransform()throw();
inline const TT1&getTransform()const throw(); protected:TT1 vt4; class TST1 vsT3; public:TV4 vdA;
TR voR; TR vlD; TR vaD1; TUF8 vmLV;
TUF8 vmAV; TU8 vdC; } ;
TT1&TMS1::getTransform()throw(){ return vt4; } const TT1&TMS1::getTransform()const throw(){
return vt4; } extern const TC1 TMC1; class TM5:public TRO{
public:enum MotionType{ MOTION_INVALID,MOTION_DYNAMIC,MOTION_SPHERE_INERTIA,MOTION_BOX_INERTIA,MOTION_KEYFRAMED,MOTION_FIXED,MOTION_THIN_BOX_INERTIA,MOTION_CHARACTER,MOTION_MAX_ID} ; public:virtual void vs19()throw();
virtual void vs20()throw(); virtual void vs211()const throw(); virtual void vs22()const throw(); virtual void vs23()throw();
virtual void vs24()throw(); virtual void vs25()const throw(); virtual void vs26()const throw(); virtual void vs27()throw();
inline TMS1*GetMotionState()throw(); inline const TMS1*GetMotionState()const throw(); virtual void vs28()throw(); virtual void vs29()throw();
virtual void vs30()throw(); inline const TT1&getTransform()const throw(); virtual void vs311()throw(); virtual void vs32()throw();
virtual void vs33()throw(); virtual void vs34()const throw(); virtual void vs35()throw(); virtual void vs36()throw();
virtual void vs37()throw(); virtual void vs38()throw(); virtual void vs39()throw(); virtual void vs40()throw();
public:virtual void vs411()throw(); inline void SynchronizeDeactivationCountersWithWorld(int worldFlag0,int worldFlag1,int worldDeactivationIntegrateCounter)throw(); public:enum{ NUM_INACTIVE_FRAMES_TO_DEACTIVATE=5}
; public:TE1<MotionType,TU8>vt6; TU8 vdIC; TU16 vdNIF[2];
class TMS1 vmS; TV4 viAMI; TV4 vlV; TV4 vaV;
TV4 vdRP[2]; TU32 vdRO[2]; class TMSM*vsM; TU16 vsQTI;
TH vgF; } ; class TRM:public TM5{
} ; TMS1*TM5::GetMotionState()throw(){ return&vmS;
} const TMS1*TM5::GetMotionState()const throw(){ return&vmS; }
const TT1&TM5::getTransform()const throw(){ return vmS.getTransform(); } void TM5::SynchronizeDeactivationCountersWithWorld(int worldFlag0,int worldFlag1,int worldDeactivationIntegrateCounter)throw(){
; ; if((((unsigned)worldDeactivationIntegrateCounter)%4)<(((unsigned)vdIC)%4)){ worldFlag0=(~worldFlag0)<<14;
} else{ worldFlag0<<=14; }
if(worldDeactivationIntegrateCounter<vdIC){ worldFlag1=(~worldFlag1)<<14; } else{
worldFlag1<<=14; } vdNIF[0]=TU16((vdNIF[0]&0x3fff)|worldFlag0); vdNIF[1]=TU16((vdNIF[1]&0x3fff)|worldFlag1);
} extern const TC1 TKRMC; class TKRM:public TM5{ public:virtual~TKRM()throw();
virtual void vs19()throw(); virtual void vs20()throw(); virtual void vs42()const throw(); virtual void vs23()throw();
virtual void vs22()const throw(); virtual void vs24()throw(); virtual void vs43()const throw(); virtual void vs26()const throw();
virtual void vs34()const throw(); virtual void vs35()throw(); virtual void vs36()throw(); virtual void vs37()throw();
virtual void vs38()throw(); virtual void vs39()throw(); virtual void vs40()throw(); protected:public:public:virtual void vs44()throw();
virtual void vs45()throw(); public:} ; class TMSM:public TKRM{
public:private:} ; class TEL; class TEAL;
class TCL1; class TM5; class FUN_00d07830; class TW;
class TCI2; class TA1; class TDCM; class TSCCU1;
class TLF; class TBB; class TdBB; extern const TC1 TEC;
class TE:public TWO{ public:enum SpuCollisionCallbackEventFilter{ SPU_SEND_NONE=0x00,SPU_SEND_CONTACT_POINT_ADDED=0x01,SPU_SEND_CONTACT_POINT_PROCESS=0x02,SPU_SEND_CONTACT_POINT_REMOVED=0x04,SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS=SPU_SEND_CONTACT_POINT_ADDED|SPU_SEND_CONTACT_POINT_PROCESS} ;
public:virtual~TE()throw(); inline TB isFixed()const throw();  protected:public:inline TM5*getMotion()throw();
virtual void vs46()throw(); virtual TMS1*GetMotionState()throw(){ return 0; }
protected:class TM1 vm; protected:friend class TWCU1; public:public:class SmallArraySerializeOverrideType{ public:void*vd1;
TU16 vs4; TU16 vcAF; } ;
public:void*vlCIU; TR vdM; TBB*vbB; public:TU32 vsD1;
public:TOI vsI5; protected:TU16 vcPCD; protected:TSA1<struct TCI3>vcM; protected:TA2<TCI2*>vcS;
protected:TA2<TU8>vcR1; FUN_00d07830*vsI; public:TI8 vaRL; TU8 vnSKICPP;
TU8 vrMF; TU32 vu; public:struct SpuCollisionCallback{ public:TSCCU1*vu1;
TU16 vc; TU8 veF; TU8 vuF; }
; struct ExtendedListeners{ TSA1<TEAL*>vaL1; TSA1<TEL*>veL;
} ; public:struct SpuCollisionCallback vsCC; public:class TMSM vm3;
protected:friend class TECU; friend class TWCU; friend class TW; friend class FUN_00d07830;
friend class TWOU; TSA1<TCL1*>vcL1; protected:TSA1<TA1*>va1; public:TRP<TLF>vlF;
protected:mutable ExtendedListeners*veL1; } ; inline TM5*TE::getMotion()throw(){
return&vm3; } inline TB TE::isFixed()const throw(){ return vm3.vt6==TM5::MOTION_FIXED;
} class TSI1{ public:public:__declspec(align(16))TPS<TT>vsT2; TPS<TT>veT;
TPS<TR>vdT; TPS<TR>viDT; } ;
class TS; typedef TS TSBW; class TW; class TSI1;
class FUN_00d07830; class TE; class TB; struct TTD;
class TMS{
 public:__forceinline char*__cdecl GetStreamEnd()throw(){ return ve.val(); }
__forceinline char*__cdecl getCapacityMinus16()throw(){ return vcM16.val(); } __forceinline char*__cdecl getCapacity()throw(){
return vc.val(); } __forceinline TB __cdecl memoryAvailable()throw(){ return GetStreamEnd()<getCapacityMinus16();
} __forceinline void __cdecl setEnd(char*ptr)throw(){ ve=ptr; }
public:public:TPS<char*>vs7; TPS<char*>ve; TPS<char*>vc; TPS<char*>vcM16;
TB viBAOTH; public:struct Command{ const char*vcAM; }
; struct CommandFilterEntry:public TMS::Command{ float vv; }
; struct CommandTimingEntry:public TMS::Command{ TU32 vt0; TU32 vt11;
__forceinline void setTime()throw(); } ; struct TimedNameRecord:public TMS::CommandTimingEntry{
const char*vnOFS; } ; struct CommandTimingStringEntry:public TMS::CommandTimingEntry{
const char*voN; } ; struct PointerAndIntegerCommand:public TMS::Command{
void*vp6; int vsAF; } ;
public:
    static TMS&GetMonitorStream()throw(){  return*(*reinterpret_cast<::TTLD< ::TMS *> *>(&::DAT_0126835c)).getData();
}
} ; void TMS::CommandTimingEntry::setTime()throw(){ TU32 ticks;
ticks = static_cast<unsigned int>(__rdtsc());
 vt0=ticks; } class TTFH; class TWMAWD;
class TCB; struct TCI; class TCLF; class TC2;
class TCCF{ public:virtual~TCCF()throw(); virtual void vs47()const throw(); }
; struct TWRCI; extern const TC1 TRCFC; class TRCF{
public:virtual~TRCF()throw(); virtual void vs48()const throw(); } ;
struct TCI; class TBTS; class TSCF{ public:virtual void vs49()const throw();
virtual void vs50()const throw(); virtual void vs511()const throw(); virtual~TSCF()throw(); }
; struct TSRCI; class TSC1; class TS1;
extern const TC1 TRSCFC; class TRSCF{ public:virtual void vs52()const throw(); virtual~TRSCF()throw();
} ; extern const TC1 TCFC; class TBTS;
class EnumIntegerValue:public TRO,public TCCF,public TSCF,public TRSCF,public TRCF{ public:enum TFT{ KFU=0,KFN=1,KFG=2,KFL=3,KFC1=4,KFP=5,KFC=6,} ;
public:virtual void vs47()const throw(); virtual void vs53()const throw(); virtual void vs50()const throw(); virtual void vs511()const throw();
virtual void vs54()const throw(); virtual void vs48()const throw(); public:TU32 unusedBefore0; TU32 unusedBefore1;
TE1<TFT,TU32>vt6; TU32 unusedAfter0; TU32 unusedAfter1; TU32 unusedAfter2;
public:} ; extern const TC1 TCFLC; class TCFL;
extern const class TC1 TWCC; class TWC:public TRO{ public:enum SolverType{ SOLVER_TYPE_INVALID,SOLVER_TYPE_2ITERS_SOFT,SOLVER_TYPE_2ITERS_MEDIUM,SOLVER_TYPE_2ITERS_HARD,SOLVER_TYPE_4ITERS_SOFT,SOLVER_TYPE_4ITERS_MEDIUM,SOLVER_TYPE_4ITERS_HARD,SOLVER_TYPE_8ITERS_SOFT,SOLVER_TYPE_8ITERS_MEDIUM,SOLVER_TYPE_8ITERS_HARD,SOLVER_TYPE_MAX_ID}
; enum SimulationType{ SIMULATION_TYPE_INVALID,SIMULATION_TYPE_DISCRETE,SIMULATION_TYPE_CONTINUOUS,SIMULATION_TYPE_MULTITHREADED,} ;
enum ContactPointGeneration{ CONTACT_POINT_ACCEPT_ALWAYS,CONTACT_POINT_REJECT_DUBIOUS,CONTACT_POINT_REJECT_MANY,} ; enum BroadPhaseBorderBehaviour{
BROADPHASE_BORDER_ASSERT,BROADPHASE_BORDER_FIX_ENTITY,BROADPHASE_BORDER_REMOVE_ENTITY,BROADPHASE_BORDER_DO_NOTHING,} ; public:TV4 vg1; TI32 vbPQS;
TR vcRV; TE1<BroadPhaseBorderBehaviour,TI8>vbPBB; TB vmPASBPBC; class TA vbPWA;
TB vuKT; TB vuMT; enum TreeUpdateType{ REBUILD_ACTIVE,REBUILD_ALL,}
; TE1<TreeUpdateType,TI8>vtUT; TB vaUKT; TR vcT;
TRP<class EnumIntegerValue>vcF; TRP<class TCLF>vcLF; TR veMLV; int vsOTEQ;
TR veMPDT; TRP<class TWMAWD>vmWD; TI32 vbPNM; TE1<ContactPointGeneration,TI8>vcPG;
TB vaTSCC; TR vsT1; TR vsD; TI32 vsI3;
TI32 vsM1; TR vmCV; TB vfCCOIS; TR vsCTCET1;
TR vsCTCET; TB veTWR; TB veDW; TR viLCEOD;
TI32 viLCMI; TU8 vdNIFSF0; TU8 vdNIFSF1; TU8 vdIC;
TB vsAORBTC; TR vdRD; TR vtCRRN; int vmSPCT;
TB vpTM; int vmEPTCT; int vmNTCPS; TR vnTTAPST;
TR vnTTAPT; TR vnTTAPTH; TR vnTTAPTF; TB veD;
TE1<SimulationType,TI8>vsT; TB veSI; TU32 vmDIS; TB vpAIST;
TB vaIOIWCIASJ; TR vfMPS; TB vfCC; virtual~TWC()throw();
} ; class EnumIntegerValue; class TCLF;
class TCD; class TC2; struct TCI; struct TPCI;
class TCL1; class TTBPD; struct TWRCI; struct TWRCO;
struct TLCI; class TRHC; class TCPC; class TCBPC;
class TBP; class TBPH; class TA; class TWO;
class TE; class TEL; class TRB; class TP;
class TPL; class TPBPL; class TEEBPL; class TBPBL;
class TA1; class TAL; class TCI2; class TCD1;
class TCL; class TPS1; class FUN_00d07830; class TCMF;
struct TMTS; class TWPSL; class TWPIL; class TWPCL;
class TWDL; class TIAL; class TCILBL; class TIPIL;
class TIPCL; class TSI1; class TWPBF; class TS2;
class TWOQ; struct TDIOPOQ; class TWMM; class TWMAWD;
class TBO1; class TJQ; class TJTP; class TdW;
struct TWRCC; struct TWLCC; struct TWGCPC; namespace TWO1{
struct TypeTag; class TypeTagRelatedClass; } struct TOP;
extern"C"enum TUCFOWM{ KUFOWFC,KUFOWDEECO,} ; enum TUCFOEM{
KUFOEFC,KUFOEDEECO} ; enum TEA{ KEADNA,KEADA}
; enum TUCFM{ KUCFISC,KUCFPSC} ;
struct TWDSI{ TSI1 vsI4; TSI vsI2; }
; struct TMC2; enum TSR2{ KSRS,KSRMFBI,KSRMFDC,KSRMFDTS,}
; class TW:public TRO{ public:void FUN_00c94bd0(TE*const*entityBatch,int numEntities,TEA initialActivationState=KEADA)throw(); enum ReintegrationRecollideMode{
RR_MODE_REINTEGRATE=1,RR_MODE_RECOLLIDE_BROADPHASE=2,RR_MODE_RECOLLIDE_NARROWPHASE=4,RR_MODE_ALL=7} ; struct ReintegrationCollisionRequest{ int vmRBS;
int vsRBS; FUN_00d07830*vlSI; } ;
enum MtAccessChecking{ MT_ACCESS_CHECKING_ENABLED=0,MT_ACCESS_CHECKING_DISABLED} ; inline const EnumIntegerValue*getCollisionFilter()const throw();
enum CachedAabbUpdate{ SHIFT_BROADPHASE_UPDATE_ENTITY_AABBS,SHIFT_BROADPHASE_IGNORE_ENTITY_AABBS} ; inline const TA2<FUN_00d07830*>&getActiveSimulationIslands()const throw();
public:__forceinline void lockCriticalOperations()throw(); __forceinline void unlockCriticalOperations()throw(); __forceinline int areCriticalOperationsLocked()const throw(); __forceinline void unlockAndAttemptToExecutePendingOperations()throw();
__forceinline void attemptToExecutePendingOperations(bool executeBodyOperations=true)throw();  private:void FUN_00c91120()throw(); 
public:public:TS2*vs3; TV4 vg1; FUN_00d07830*vfI; TRB*vfRB;
TA2<FUN_00d07830*>vaSI; TA2<FUN_00d07830*>viSI; TA2<FUN_00d07830*>vdSI; TWMM*vmM;
TRP<TWMAWD>vmWD; TB vaOROOSM; TBP*vbP; class TTWM*vkTM;
TB vaUT; TTBPD*vbPD; TPBPL*vpBPL; TEEBPL*veEBPL;
TBPBL*vbPBL; TMTS*vmSJD; TPCI*vcI; EnumIntegerValue*vcF;
TCD*vcD1; TCLF*vcLF; TWOQ*vpO; int vpOC;
int vpBOC; int vcOLC; int vcOLCFP; TB vbEPO;
TB vcOA; TDIOPOQ*vpOQ; int vpOQC; mutable class TMTC vmTC;
TB vpAIST; TB vaIOIWCIASJ; TU32 vmDIS; class TCS2*vmCCS;
int viL; class TCS2*viDLCS; class TCS2*vpML; TB vwSI;
TR vsCTCET1; TR vsCTCET; TB veTWR; TB vwD;
TB vsAORBTC; TR vdRD; TR vtCRRN; int vmSPCT;
TB vpTM; int vmEPTCT; int vmNTCPS; TE1<TWC::SimulationType,TI32>vsT;
TR vnTTAPST; TR vnTTAPT; TR vnTTAPTH; TR vnTTAPTF;
static TB vfMS; class TBHolder{ public:public:TB voFMSV; }
; public:TU32 vlEU; TU32 vlIU; public:TU32 vlCU;
friend class TWOU; friend class TWCU; friend class TS2; friend class THS;
friend class TCS; friend class TMTS1; friend class TSCCM; TA2<TP*>vp3;
TA2<TAL*>vaL; TA2<TEL*>veL; TA2<TPL*>vpL; TA2<TCL*>vcL;
TA2<TWDL*>vwDL; TA2<TIAL*>viAL; TA2<TWPSL*>vwPSL; TA2<TWPIL*>vwPIL;
TA2<TWPCL*>vwPCL; TA2<TIPIL*>viPIL; TA2<TIPCL*>viPCL; TA2<TCL1*>vcL1;
TA2<TCILBL*>vcILBL; TVCA*vvCA; class TBPB*vbPB; class TCCU*vcCU;
class TdW*vdW; public:struct TWDSI vdSI1; TV4 vbPE[2]; int vbPNM;
int vsOTEQ; TI32 vbPQS; TI32 vbPUS; TE1<TWC::ContactPointGeneration,TI8>vcPG;
} ; const TA2<FUN_00d07830*>&TW::getActiveSimulationIslands()const throw(){ return vaSI; }
// Updates the physics system's entities, phantoms, actions and constraints, using bulk calls when no null entries are present and per-entry calls otherwise.
// @fnv 0x00c97f80
void SystemWorld::FUN_00c97f80(PhysicsSystem* system) {
    if (system->entities.m_iElementCount > 0) {
        if (findNull(system->entities) == -1) {
            reinterpret_cast<::TW *>(this)->FUN_00c94bd0((::TE *const *)(system->entities.m_data), system->entities.m_iElementCount, (::TEA)(system->isActive() ? 1 : 0));
        } else {
            for (int i = 0; i < system->entities.m_iElementCount; ++i) {
                if (system->entities.m_data[i])
                    reinterpret_cast<::hkpWorldC914 *>(this)->FUN_00c914d0((::hkpEntityC914 *)(system->entities.m_data[i]), system->isActive() ? 1 : 0);
            }
        }
    }
    if (system->phantoms.m_iElementCount > 0) {
        if (findNull(system->phantoms) == -1) {
            FUN_00c954e0(system->phantoms.m_data, system->phantoms.m_iElementCount);
        } else {
            for (int i = 0; i < system->phantoms.m_iElementCount; ++i) {
                if (system->phantoms.m_data[i])
                    reinterpret_cast<::FUN_00c936a0_World *>(this)->FUN_00c936a0((::hkpPhantom *)(system->phantoms.m_data[i]));
            }
        }
    }
    for (int i = 0; i < system->actions.m_iElementCount; ++i) {
        if (system->actions.m_data[i])
            reinterpret_cast<::hkpWorldC97 *>(this)->FUN_00c97370((::hkpActionC97 *)(system->actions.m_data[i]));
    }
    for (int i = 0; i < system->constraints.m_iElementCount; ++i) {
        if (system->constraints.m_data[i] &&
            (system->constraints.m_data[i]->owner || system->constraints.m_data[i]->attachment))
            reinterpret_cast<::Mgr *>(this)->FUN_00c97d30((::Item *)(system->constraints.m_data[i]));
    }
}
inline const EnumIntegerValue*TW::getCollisionFilter()const throw(){ ; return vcF;
} void TW::lockCriticalOperations()throw(){ ; vcOLC++;
; } void TW::unlockCriticalOperations()throw(){ ;
vcOLC--; ; } int TW::areCriticalOperationsLocked()const throw(){
; ; return vcOLC; }
void TW::attemptToExecutePendingOperations(bool executeBodyOperations)throw(){ ; if(!vcOLC&&!vbEPO){ if(vpOC){
reinterpret_cast<::FUN_00c91120 *>(this)->ExecutePendingOperations(); } if(vpOQC==1&&executeBodyOperations){ if(vpBOC){
reinterpret_cast<::FUN_00c91140_Class *>(this)->FUN_00c91140(); } } }
} void TW::unlockAndAttemptToExecutePendingOperations()throw(){ unlockCriticalOperations(); attemptToExecutePendingOperations();
} extern struct TCDU*g_checkDeterminismUtil; class TI; class TO1;
class TCS2; class TMT; struct TCDU; class TVA;
class TCO:public TRO{ public:public:virtual void vs55()throw(); virtual void vs56()throw(); virtual void vs57()throw();
virtual void vs58()throw(); public:TCI1 vcI1; } ;
class TCI2; class TE; class TSI1; class TVA;
class FUN_00d07830; class TVA; class TVA; class TCQSI;
class TCQI1; struct TCSI; struct TBJTH; struct TBJT;
struct TBJTC; struct TSJTC; struct TBJTH; struct TSCBT;
struct TCSR; class TCSS; struct TPCI; class TCM2;
struct TPCO; struct TCQI; class TLC; class TCD;
class TCO; struct TCI; class TCB; class TCA;
struct TAE; typedef void TAD; struct TA3I; struct TA3PI;
namespace TA3{ typedef int AgentType; enum{ MIN_TOTAL_SIZE=16,MAX_MEMORY_INCREASE=80,MAX_TOTAL_SIZE=128}
; enum StreamCommand{ STREAM_NULL=0,STREAM_END=1,STREAM_CALL=2,STREAM_CALL_FLIPPED=3,STREAM_CALL_WITH_TIM=4,STREAM_CALL_WITH_TIM_FLIPPED=5,STREAM_CALL_AGENT=6,TRANSFORM_FLAG=0x08,STREAM_CALL_WITH_TRANSFORM=TRANSFORM_FLAG|STREAM_CALL,STREAM_CALL_FLIPPED_WITH_TRANSFORM=TRANSFORM_FLAG|STREAM_CALL_FLIPPED,STREAM_CALL_WITH_TIM_WITH_TRANSFORM=TRANSFORM_FLAG|STREAM_CALL_WITH_TIM,STREAM_CALL_WITH_TIM_FLIPPED_WITH_TRANSFORM=TRANSFORM_FLAG|STREAM_CALL_WITH_TIM_FLIPPED,STREAM_CALL_AGENT_WITH_TRANSFORM=TRANSFORM_FLAG|STREAM_CALL_AGENT,} ;
typedef TAD*(__cdecl*CreateFunc)(const TA3I&input,TAE*entry,TAD*agentData); typedef void(__cdecl*DestroyFunc)(TAE*entry,TAD*agentData,TCM2*mgr,TCO&constraintOwner,TCD*dispatcher); typedef TAD*(__cdecl*ProcessFunc)(const TA3PI&input,TAE*entry,TAD*agentData,TV4*separatingNormalOut,TPCO&result); enum Symmetric{
IS_SYMMETRIC,IS_NOT_SYMMETRIC,IS_NOT_SYMMETRIC_AND_FLIPPED} ; typedef void(__cdecl*SepNormalFunc)(const TA3I&input,TAE*entry,TAD*agentData,TV4&separatingNormalOut); typedef TAD*(__cdecl*CleanupFunc)(TAE*entry,TAD*agentData,TCM2*mgr,TCO&constraintOwner);
typedef void(__cdecl*RemovePointFunc)(TAE*entry,TAD*agentData,TCPI idToRemove); typedef void(__cdecl*CommitPotentialFunc)(TAE*entry,TAD*agentData,TCPI iContactPointId); typedef void(__cdecl*CreateZombieFunc)(TAE*entry,TAD*agentData,TCPI idTobecomeZombie); typedef void(__cdecl*UpdateFilterFunc)(TAE*entry,TAD*agentData,const TCB&bodyA,const TCB&bodyB,const TCI&input,TCM2*mgr,TCO&constraintOwner);
typedef void(__cdecl*CalcStatisticsFunc)(TAE*entry,TAD*agentData,const TCI&input,TSC3*collector); typedef void(__cdecl*InvalidateTimFunc)(TAE*entry,TAD*agentData,const TCI&input); typedef void(__cdecl*WarpTimeFunc)(TAE*entry,TAD*agentData,TT oldTime,TT newTime,const TCI&input); }
typedef void TAD; struct TANE; struct TANS; class TC2;
struct TANE; struct TANS; struct TANT{ TU32 vbUILS;
TIA<TANS*,1>vs1; } ; class TTBPHP;
class TBPL{ public:virtual~TBPL()throw(); virtual void vs59()throw(); virtual void vs60()throw();
} ; class TUF; class TA1;
class TE; class TCI2; class TSI1; class TBP;
class TW; class TCD; struct TWDSI; class TBPHP;
struct TCI; struct TPCO; extern const TC1 FUN_00d07830Class; class FUN_00d07830:public TCO{
public:__forceinline void*__cdecl operator new(std::size_t nbytes){ ; TRO*b=static_cast<TRO*>(hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes))); b->vmSAF=static_cast<TU16>(nbytes);
; return b; } __forceinline void*__cdecl operator new(std::size_t,void*p){
return p; } inline TB isFixed()const throw(); virtual void vs9()const throw();
protected:friend class TW; friend class TWOU; friend class TWCU; friend class TS2;
friend class TCS; friend class TAMU; FUN_00d07830(TW*world)throw(); ~FUN_00d07830()throw();
void FUN_00d07420(TE*entity)throw(); virtual void vs55()throw(); virtual void vs56()throw(); virtual void vs57()throw();
protected:public:public:public:public:TW*vw; int vnC1; TOI vsI5; TOI vdLI;
TU vsCFC; bool vsCR:2; bool vsE:2; bool vaLCN:2;
bool vaIL:2; bool viIAIA:2; bool vaM:2; bool vtTIISM:2;
bool viIJ:2; protected:mutable TMTC vmTC; public:TR vtSLHFC; TR vtSLLFC;
TA2<TA1*>va1; TT vtOD; TIA<TE*,1>ve1; TANT vaT;
; ; public:
    FUN_00d07830(::hkpWorldQ *);
} ;
inline TB FUN_00d07830::isFixed()const throw(){ return vsI5==0xffff; } class THC;
class TLF; class TRBC; extern const TC1 TRBC1; class TRB:public TE{
public:virtual~TRB()throw(); inline const TT1&getTransform()const throw(); virtual void vs611()const throw(); public:inline TM5*getRigidMotion()const throw();
public:protected:virtual TMS1*GetMotionState()throw(); public:} ; inline TM5*TRB::getRigidMotion()const throw(){
return const_cast<TMSM*>(&vm3); } inline const TT1&TRB::getTransform()const throw(){ return getRigidMotion()->getTransform();
} class TCI2; class TE; struct TANT;
class TCS; class TWOU; class TRB; class TBO1;
class TA; class TRB; class TWO; class TCI2;
class TS1; class TCCF1; namespace TWO1{ enum Type{
OPERATION_ID_ANY=0,OPERATION_ID_INVALID=0,ENTITY_ADD,ENTITY_REMOVE,ENTITY_UPDATE_BROAD_PHASE,RIGIDBODY_SET_MOTION_TYPE,WORLD_OBJECT_SET_SHAPE,ENTITY_BATCH_ADD,ENTITY_BATCH_REMOVE,CONSTRAINT_ADD,CONSTRAINT_REMOVE,ACTION_ADD,ACTION_REMOVE,ISLAND_MERGE,PHANTOM_ADD,PHANTOM_REMOVE,PHANTOM_BATCH_ADD,PHANTOM_BATCH_REMOVE,PHANTOM_UPDATE_BROAD_PHASE,UPDATE_FILTER_ENTITY,UPDATE_FILTER_ENTITY_PAIR,UPDATE_FILTER_PHANTOM,UPDATE_FILTER_WORLD,UPDATE_MOVED_BODY_INFO,ENTITY_BATCH_REINTEGRATE_AND_RECOLLIDE,RIGIDBODY_SET_POSITION_AND_ROTATION,RIGIDBODY_SET_LINEAR_VELOCITY,RIGIDBODY_SET_ANGULAR_VELOCITY,RIGIDBODY_APPLY_LINEAR_IMPULSE,RIGIDBODY_APPLY_POINT_IMPULSE,RIGIDBODY_APPLY_ANGULAR_IMPULSE,WORLD_OBJECT_ADD_REFERENCE,WORLD_OBJECT_REMOVE_REFERENCE,ACTIVATE_REGION,ACTIVATE_ENTITY,DEACTIVATE_ENTITY,CONSTRAINT_FILTER_BROKEN_EVENT,USER_CALLBACK} ; class TypeTagRelatedClass; struct TypeTag{
TypeTag(Type type)throw():vt6(type){ } TE1<Type,TU8>vt6; private:TypeTag()throw();
} ; struct HandleNode; struct UpdateEntity;
struct RigidBodyMotionTypeChange; struct WorldObjectShapeChange; struct EntityBatchAddPayload:public TypeTag{ EntityBatchAddPayload()throw():TypeTag(ENTITY_BATCH_ADD){
} TE**ve1; TOI vnE; TE1<TEA,TU8>va2;
} ; struct WorldOperationBeforeAddConstraint; struct AddConstraint;
struct WorldOperationBeforeAddActionCommand; struct AddActionCommand; struct WorldOperationAfterAddActionCommand; struct WorldOperation;
struct ForwardDeclaredCommandType; struct ForwardDeclaredWorldOperation8; struct LaterForwardDeclaredCommandType; struct ForwardDeclaredWorldOperation10;
struct OperationBeforePhantomBroadphaseUpdate; struct PhantomBroadphaseUpdate; struct OperationAfterPhantomBroadphaseUpdate; struct SecondPostPhantomBroadphaseOperation;
struct ForwardDeclaredStructAtPositionThirteen; struct ForwardDeclaredStructAtPositionFourteen; struct PhysicsCommand; struct ForwardDeclaredStructAtPositionSixteen;
struct RigidBodyPositionRotationUpdate; struct FourteenthForwardDeclaredType; struct FifteenthForwardDeclaredType; struct ForwardDeclaredStructInSequence;
struct ForwardDeclaredTypeAtPositionThirteen; struct TrailingForwardDeclaredStruct; struct AddReference; struct RemoveReference;
struct ForwardStructAtPositionTwentyFive; struct ForwardStructAtPositionTwentySix; struct IncompleteStructType; struct ForwardDeclaredType;
struct StructAfterForwardDeclaredType; struct OpaqueStructType; } struct TBOE;
class TWOQ; struct TDIOPOQ; class TW; struct TCBE;
struct TCRE; class TSI1; class TP; class TCILBL;
class TCILBLI; class TSCCM; class TCE1; class TCP;
class TCPP; class FUN_00d07830; class TCPE; class TC2;
struct TCI; class TCM2; class TSC3:public TRO{ public:enum MemoryType{
MEM_OBJECT,MEM_NORMAL,MEM_ALLOCATED,MEM_ARRAY,MEM_OTHER,MEM_LAST,} ; enum Flag{ EXCLUDE_OBJECT_MEMORY=0x1,}
; virtual void vs62()throw(); virtual void vs63()throw(); virtual void vs64()throw();
virtual void vs65()throw(); virtual void vs66()throw(); protected:public:const void*vcD; TVCR*vvR;
bool viUAM; } ; class TCMF;
struct TPCP; struct TPCD; class TCB; struct TPCI;
struct TPCO; class TC2; class TGC; class TCPM;
struct TSCCA; class TCPP; __declspec(align(16))class TCPPWEUD16; class TCPPS;
; class TCQI1; class TCQO; class TCP;
class TCPP; struct TSCCA; class TSCCDI; class TSCCDII;
extern TR KCLERV; extern TR KCEERV; extern"C"{ }
; class TCP; class TCM1; class TCPPS;
struct TCA1; typedef void(__cdecl*TCABJF)(class TCD1*vcD2,const TCQI1&in,TCQO&out); struct TBCA; struct TBA;
struct TSCCA; struct TBSCA; struct TSSCA; struct TSLTCA;
struct TSLTCA1; struct TSLRCA; struct TOPCA; struct TLCA;
struct TLSCA; struct TLLCA; struct T2dACA; struct TACA;
struct TALCA; struct TTLCA; struct TCLCA; struct TAFCA;
struct TAMCA; struct TRMCA; struct TLFCA; struct TLMCA;
struct TPCA; struct TMCA; struct TSCMCA; struct TMCMCA;
struct TCOMCMCA; struct TVSMCA; struct TMSMCA; struct TIMCA;
class TCM2; class TCP; class TCPP; class TV4;
class TDCM; class TDCIM; class TSCCAU; class TCP;
class TSR1; class TRB; class TSCCM; class TSCCD;
class TW; extern const TC1 TSCCMC; class TSCCM; class TRB;
class TV4; class TCP; class TSCCU; struct TPCP;
class TCS1; class TTS; class TGC; __declspec(align(16))class TGC16;
enum{ KMCP=256} ; struct TAE;
struct TPCD; class TCM2; struct TPCO; class TC2;
struct TCI; struct TPCO; class TE; class TDCM;
enum TCPA{ KCPA=0,KCPR=1} ; struct TTPAE;
struct TMPAE; struct TSCCA; struct TCPAE; struct TTPAE;
struct TMPAE; struct TCPCE; struct TCPRE; struct TCPE1;
class TCL1; class TWCU{ public: }
; class TE; class TECU{ public:
protected:public:protected:} ; class TCD; class EnumIntegerValue;
class TCLF; struct TCAC; class TSCQD; struct TCI{
public:TR getTolerance()const throw(){ return vt3; } public:TPS<TCD*>vd3;
TPS<TB32>vwCP; TPS<TR>vt3; TPS<const EnumIntegerValue*>vf; TPS<const TCLF*>vcLF;
mutable TPS<TB32>vcPA; struct AabbBoundsAndScale{ TV4 vbOL; TV4 vbOH;
TV4 vbS; } ; AabbBoundsAndScale va32I;
} ; struct TA1nS; struct TCQI;
struct TA1nS; struct TPCI:public TCI{ public:public:TSI1 vsI4; mutable TPS<TCQI*>vcQI;
mutable TA1nS*vsAS; void*vdI1; TB veDW; TB vaTSCC;
TCAC*vc4; } ; class TBP;
class TBPH; class TBPHP; class TA; class TPCC;
class TBPCC; typedef char TBPAC; class TBP:public TRO{ public:enum BroadPhaseType{
BROADPHASE_16BIT,BROADPHASE_32BIT} ; virtual void vs67()const throw(); virtual void vs68()throw();
virtual void vs69()throw(); virtual void UpdatePairs(const TAB<TBPH*>&addObjectList,const TAB<TA>&addAabbList,TA2<TBPHP>&newPairs)throw()=0; virtual void vs70()throw(); virtual void vs711()throw();
virtual void vs72()const throw(); virtual void vs73()throw(); virtual void vs74()throw(); virtual void vs75()throw();
virtual void vs76()throw(); virtual void vs77()const throw(); virtual void getAabb(const TBPH*object,TA&aabb)const throw()=0; virtual void vs78()const throw();
virtual void vs79()const throw(); virtual void vs80()const throw(); virtual void vs811()const throw(); virtual void vs82()throw();
virtual void vs83()throw(); virtual void vs84()const throw(); struct TCRI{ TV4 vf3;
int vnC; const TV4*vtB; int vtS; const TBPAC*vaCI;
} ; virtual void vs85()const throw(); virtual void vs86()const throw();
virtual void vs87()const throw(); virtual void vs88()const throw(); struct TCAI{ TV4 vf3;
TV4 vt2; TV4 vhE; const TBPAC*vaCI; }
; virtual void vs89()const throw(); virtual void vs90()throw(); typedef TBP*(__cdecl*createBroadPhaseFunc)(const TV4&worldMin,const TV4&worldMax,int numMarkers);
static createBroadPhaseFunc vdCF; protected:protected:mutable TMTC vmTC; class TCS2*vcS1; public:class ScopedBroadPhaseFactoryOverride{
public:public:createBroadPhaseFunc voCBF; private:} ; }
; class TBPH; class TBPHP{ public:TBPH*va;
TBPH*vb; } ; class TNBPL:public TRO,public TBPL{
public:virtual void vs59()throw(); virtual void vs60()throw(); } ;
class TTBPHP; class TBPHP; class TBPL; class TTBPD{
public: protected:TBPL*vbPL[8][8]; TNBPL vnBPL; }
; template<typename T>class TLA1:public TA2<T>{ public:__forceinline TLA1(int capacity)throw(){ this->vd1=TAS1<T>(capacity);
this->vcAF=capacity|TA2<T>::DONT_DEALLOCATE_FLAG; vlM=this->vd1; } __forceinline TB wasReallocated()const throw(){
return vlM!=this->vd1; } __forceinline~TLA1()throw(){ if(!wasReallocated()){
TA2<T>::clear(); } TDS<T>(vlM); }
T*vlM; } ; namespace TSTU{
// @fnv 0x00c94bd0
 extern const TQR g_vSimdVectorConstant; } void TW::FUN_00c94bd0(TE*const*entities,int count,TEA activation)throw(){
if(count==0)return; if(areCriticalOperationsLocked()){ TWO1::EntityBatchAddPayload op; op.ve1=const_cast<TE**>(entities);
op.vnE=(TU16)count; op.va2=activation; reinterpret_cast<::WorldWithPending *>(this)->FUN_00c91160(); return;
} { TMS&mStream=TMS::GetMonitorStream(); if(mStream.memoryAvailable()){
TMS::TimedNameRecord*h=reinterpret_cast<TMS::TimedNameRecord*>(mStream.GetStreamEnd()); h->vcAM="L""t""AddEntities"; h->vnOFS="S""t""init"; h->setTime();
mStream.setEnd(reinterpret_cast<char*>(h+1)); } } ;
lockCriticalOperations(); TA2<TBPH*,TCTA>handles; handles.reserveExactly(count); TA2<TA,TCTA>bounds;
bounds.reserveExactly(count); bool used=false; FUN_00d07830*island; if(vwSI){
island=new FUN_00d07830(this); island->vsCR=true; if(activation==KEADA){ island->vsI5=(TOI)getActiveSimulationIslands().GetLogicalSize();
island->viIAIA=true; island->vaM=true; } else{
island->vsI5=(TOI)viSI.GetLogicalSize(); island->viIAIA=false; island->vaM=false; }
} else{ island=getActiveSimulationIslands()[0]; island->ve1.reserve(island->ve1.GetLogicalSize()+count);
} { TR radius=(TR)(0.5*vcI->getTolerance()); for(int i=0;i<count;++i){
TE*entity=entities[i]; entity->vu=++vlEU; reinterpret_cast<::FUN_00c90510_class *>((void *)(entity))->FUN_00c90510(); if(!entity->getCollidable()->GetMotionState())entity->vc3.setMotionState(entity->GetMotionState());
TMS1*ms=static_cast<TRB*>(entity)->getRigidMotion()->GetMotionState(); ::FUN_00cf1480(0,0,(int *)&(*ms)); entity->getMotion()->vdNIF[0]=0; entity->getMotion()->vdNIF[1]=0;
entity->setWorld(this); const TU8*flags=vdSI1.vsI2.vdNIFSF; entity->getMotion()->SynchronizeDeactivationCountersWithWorld(flags[0],flags[1],vdSI1.vsI2.vdIC); if(entity->isFixed())vfI->FUN_00d07420(entity);
else{ used=true; island->FUN_00d07420(entity); }
TC2*c=entity->getCollidableRw(); const TS1*shape=c->getShape(); c->vbVD.invalidate(); if(shape){
TA*aabb=bounds.expandByUnchecked(1); c->getShape()->getAabb(c->getTransform(),radius,*aabb); handles.pushBackUnchecked(c->getBroadPhaseHandle()); reinterpret_cast<::hkpEntityC9C0 *>((entity))->UpdateBoundingVolume((const ::hkpWorldC9C0 *)(const ::TW *)(this),(const ::hkpShapeC9C0 *)(shape));
} } } if(vwSI){
if(used){ island->vsCFC=(TU)island->ve1[0]->vu; TA2<FUN_00d07830*>&islands=activation==KEADA?const_cast<TA2<FUN_00d07830*>&>(getActiveSimulationIslands()):viSI; islands.AddBack(island);
} else delete island; } TLA1<TBPHP>pairs(vbPQS);
{ TMS&mStream=TMS::GetMonitorStream(); if(mStream.memoryAvailable()){ TMS::CommandTimingEntry*h=reinterpret_cast<TMS::CommandTimingEntry*>(mStream.GetStreamEnd());
h->vcAM="S""t""Broadphase"; h->setTime(); mStream.setEnd(reinterpret_cast<char*>(h+1)); }
} ; vbP->UpdatePairs(handles,bounds,pairs); {
TMS&mStream=TMS::GetMonitorStream(); if(mStream.memoryAvailable()){ TMS::CommandTimingEntry*h=reinterpret_cast<TMS::CommandTimingEntry*>(mStream.GetStreamEnd()); h->vcAM="S""t""CreateAgents";
h->setTime(); mStream.setEnd(reinterpret_cast<char*>(h+1)); } }
; reinterpret_cast<::DispatcherCF7080 *>((void *)(vbPD))->FUN_00cf7080((::PairCF7080 *)(::TTBPHP *)(reinterpret_cast<TTBPHP*>(pairs.begin())),pairs.GetLogicalSize(),(const ::FilterCF7080 *)(const ::TCCF *)(getCollisionFilter())); { TMS&mStream=TMS::GetMonitorStream();
if(mStream.memoryAvailable()){ TMS::CommandTimingEntry*h=reinterpret_cast<TMS::CommandTimingEntry*>(mStream.GetStreamEnd()); h->vcAM="S""t""AddedCb"; h->setTime();
mStream.setEnd(reinterpret_cast<char*>(h+1)); } } ;
for(int j=0;j<count;++j){ TE*entity=entities[j]; ::fnv_00d00500::NotifyEntityAdded((::fnv_00d00500::World833 *)(::TW *)(this),(::fnv_00d00500::hkpEntity *)(entity)); ::FUN_00cffa00((::ProfOwner_cffa00 *)(entity));
} unlockAndAttemptToExecutePendingOperations(); { TMS&mStream=TMS::GetMonitorStream();
if(mStream.memoryAvailable()){ TMS::CommandTimingEntry*h=reinterpret_cast<TMS::CommandTimingEntry*>(mStream.GetStreamEnd()); h->vcAM="l""t"""; h->setTime();
mStream.setEnd(reinterpret_cast<char*>(h+1)); } } ;
}

extern const char str_010c68c8[];
extern const char str_010c41f8[];
struct Sbp_TimerEntry { const char* name; unsigned int tick; unsigned int unk08; };
struct Sbp_Timer { void* unk00; Sbp_TimerEntry* unk04; void* unk08; Sbp_TimerEntry* unk0C; };
struct Sbp_Pair { void* a; void* b; };
template <class T> struct Sbp_Array {
    T* data; int size; int capacity;
    void destroy() { ClearAndRelease(hkMemoryRouter::getInstance().m_heap); }
    void ClearAndRelease(hkMemoryAllocator* heap) {
        size = 0;
        if ((capacity & 0x80000000) == 0) heap->bufFree(data, (capacity & 0x3fffffff) * sizeof(T));
    }
};
struct Sbp_Vec {
    __m128 q;
    void add4(const Sbp_Vec& a) { q = _mm_add_ps(q, a.q); }
};
struct Sbp_BroadPhase {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20();
    virtual void ShiftBroadPhase(const Sbp_Vec& shift, Sbp_Vec& effective, Sbp_Array<Sbp_Pair>& pairs);
    virtual void GetOffsetLowHigh32Bit(Sbp_Vec& low, Sbp_Vec& high);
};
struct Sbp_CollisionInput {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    Sbp_Vec m_kAabbMin;
    Sbp_Vec m_kAabbMaximum;
};
struct Sbp_Dispatcher {  };
struct Sbp_Phantom {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual int getType();
};
struct Sbp_AabbPhantom : Sbp_Phantom {
    int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C;
    int unkA0; int unkA4; int unkA8; int unkAC;
    Sbp_Vec m_aabbMin;
    Sbp_Vec m_aabbMax;
};
struct Sbp_ShapePhantom : Sbp_Phantom {
    int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C;
    int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; int unkB4; int unkB8; int unkBC;
    int unkC0; int unkC4; int unkC8; int unkCC; int unkD0; int unkD4; int unkD8; int unkDC;
    Sbp_Vec m_vTranslation;
};
struct Sbp_Border {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14;
    Sbp_Phantom* m_kPhantoms[6];
    void shiftPhantoms(__m128& raw);
};
static inline Sbp_Phantom* Sbp_getPhantom(Sbp_Border* b, const int& i) { return b->m_kPhantoms[i]; }
__forceinline void Sbp_Border::shiftPhantoms(__m128& raw) { Sbp_Vec& effective=(Sbp_Vec&)raw;
    Sbp_Phantom* const* phantoms = m_kPhantoms;
    for (int i = 0; i < 6; i++) {
        Sbp_Phantom* phantom = phantoms[i];
        switch (phantom->getType()) {
        case 0:
            ((Sbp_AabbPhantom*)phantom)->m_aabbMin.add4(effective);
            ((Sbp_AabbPhantom*)phantom)->m_aabbMax.q = _mm_add_ps(effective.q, ((Sbp_AabbPhantom*)phantom)->m_aabbMax.q);
            break;
        case 1:
        case 2:
            ((Sbp_ShapePhantom*)phantom)->m_vTranslation.add4(effective);
            break;
        }
    }
}
struct Sbp_Entity { int unk00; int unk04; int unk08; int unk0C; void* unk10; };
struct Sbp_Island {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44;
    Sbp_Array<Sbp_Entity*> m_kActorEntries;
};
template <class T> static __forceinline T* Sbp_bufAlloc(hkMemoryAllocator* heap, int& n) {
    int bytes = n * sizeof(T);
    T* p = static_cast<T*>(heap->bufAlloc(bytes));
    n = bytes / (int)sizeof(T);
    return p;
}
template <class T> static __forceinline void Sbp_freeArray(hkMemoryAllocator* heap, T* data, int cap) {
    if ((cap & 0x80000000) == 0) heap->bufFree(data, (cap & 0x3fffffff) * sizeof(T));
}
template <class T> static inline void Sbp_copy(T* dst, const T* src, int n) {
    for (int i = 0; i < n; i++) dst[i] = src[i];
}
static __forceinline void Sbp_initArray(Sbp_Island**& data, int& size, int& cap, int n) {
    size = n;
    hkMemoryAllocator* heap = hkMemoryRouter::getInstance().m_heap;
    _ReadWriteBarrier();
    data = size ? Sbp_bufAlloc<Sbp_Island*>(heap, size) : 0;
    cap = size ? size : 0x80000000;
}

struct Sbp_World : hkpWorld {
    void FUN_00c96a20(const __m128& rawShift, __m128& rawEffective, int update);
    void FUN_00c91120();
};
static __forceinline void doShift(Sbp_World* self,const __m128& rawShift, __m128& rawEffective, int update){
    const Sbp_Vec& shift = (const Sbp_Vec&)rawShift;
    Sbp_Vec& effective = (Sbp_Vec&)rawEffective;


    {
        Sbp_Timer* timer = (Sbp_Timer*)TlsGetValue(DAT_0126835c);
        Sbp_TimerEntry* entry = timer->unk04;
        if (entry < timer->unk0C) {
            entry->name = str_010c68c8;
            unsigned int openingTick;
            openingTick = static_cast<unsigned int>(__rdtsc());
            entry->tick = openingTick;
            timer->unk04 = entry + 1;
        }
    }
    Sbp_Array<Sbp_Pair> pairs;
    pairs.data = 0;
    pairs.size = 0;
    pairs.capacity = 0x80000000;
    ((Sbp_BroadPhase*)self->m_pJobSemaphore)->ShiftBroadPhase(shift, effective, pairs);
    Sbp_CollisionInput* input = (Sbp_CollisionInput*)self->m_pCollisionInput;
    ((Sbp_BroadPhase*)self->m_pJobSemaphore)->GetOffsetLowHigh32Bit(input->m_kAabbMin, input->m_kAabbMaximum);
    Sbp_Vec* ext = (Sbp_Vec*)self->m_kBroadPhaseAabb;
    ext[0].add4(effective);
    ext[1].add4(effective);
    ++self->m_iCriticalOperationsLockCount;
    reinterpret_cast<::DispatcherCF7080 *>((((Sbp_Dispatcher*)self->m_pBroadPhaseDispatcher)))->FUN_00cf7080((::PairCF7080 *)(pairs.data), pairs.size,
        (const ::FilterCF7080 *)(void *)collidableCollidableFilterOf(self->m_pCollisionFilter));
    Sbp_Border* border = (Sbp_Border*)self->m_pBroadPhaseBorder;
    if (border) border->shiftPhantoms(effective.q);
    if (update == 0) {
        Sbp_Array<Sbp_Entity*> entities;
        entities.data = 0;
        entities.size = 0;
        entities.capacity = 0x80000000;
        int numInactive = self->m_kInactiveSimulationIslands.m_iElementCount;
        void* fixedIsland = self->m_pFixedIsland;
        Sbp_Island** islandData;
        int numIslands; int islandCap;
        Sbp_initArray(islandData, numIslands, islandCap, numInactive + self->m_kActiveSimulationIslands.m_iElementCount + 1);
        int numFixed = fixedIsland != 0;
        void** src = fixedIsland ? &fixedIsland : 0;
        Sbp_copy(islandData, (Sbp_Island**)src, numFixed);
        Sbp_copy(islandData + numFixed, (Sbp_Island**)self->m_kActiveSimulationIslands.m_data, self->m_kActiveSimulationIslands.m_iElementCount);
        Sbp_copy(islandData + (self->m_kActiveSimulationIslands.m_iElementCount + numFixed), (Sbp_Island**)self->m_kInactiveSimulationIslands.m_data, self->m_kInactiveSimulationIslands.m_iElementCount);
        for (int i = 0; i < numIslands; i++) {
            Sbp_Island* island = islandData[i];
            for (int j = 0; j < island->m_kActorEntries.size; j++) {
                Sbp_Entity*& entity = island->m_kActorEntries.data[j];
                if (entity->unk10 != 0) {
                    hkMemoryRouter* router = &hkMemoryRouter::getInstance();
                    if (entities.size == (entities.capacity & 0x3fffffff)) ::ResizeAudioStream((::AudioAllocator *)(router->m_heap), (::AudioStream *)(void *)(&entities), 4);
                    entities.data[entities.size++] = entity;
                }
            }
        }
        ::FUN_00d1a330((const ::CollisionContext *)(self->m_pCollisionInput), (::EntityNode *const *)(entities.data), entities.size);
        {
            Sbp_freeArray(hkMemoryRouter::getInstance().m_heap, islandData, islandCap);
        }
        entities.destroy();
    }
    if (--self->m_iCriticalOperationsLockCount == 0 && !self->m_bBlockExecutingPendingOperations) {
        if (self->m_iPendingOperationCount) reinterpret_cast<::FUN_00c91120 *>((self))->ExecutePendingOperations();
        if (self->m_iPendingOperationQueueCount == 1 && self->m_iQueuedOperationCount) reinterpret_cast<::FUN_00c91140_Class *>((self))->FUN_00c91140();
    }
    {
        Sbp_Timer* timer = (Sbp_Timer*)TlsGetValue(DAT_0126835c);
        Sbp_TimerEntry* entry = timer->unk04;
        if (entry < timer->unk0C) {
            entry->name = ::DAT_010c41f8;
            unsigned int closingTick;
            closingTick = static_cast<unsigned int>(__rdtsc());
            entry->tick = closingTick;
            timer->unk04 = entry + 1;
        }
    }
    pairs.destroy();
}

// @fnv 0x00c96a20
void Sbp_World::FUN_00c96a20(const __m128& rawShift, __m128& rawEffective, int update) { doShift(this,rawShift,rawEffective,update); }

namespace fnv_00c977c0 {




struct FUN_00c90510_s {
};

struct FUN_00c905b0_s {
};

class hkBoolC977 {
public:
    hkBoolC977(bool b) { m_cBooleanValue = static_cast<char>(b); }
    operator bool() const { return m_cBooleanValue != 0; }
    char m_cBooleanValue;
};

class hkpCollidableCollidableFilterC977 { public: virtual ~hkpCollidableCollidableFilterC977() throw(); };
class hkpShapeCollectionFilterC977 { public: virtual ~hkpShapeCollectionFilterC977() throw(); };
class hkpRayShapeCollectionFilterC977 { public: virtual ~hkpRayShapeCollectionFilterC977() throw(); };
class hkpRayCollidableFilterC977 { public: virtual ~hkpRayCollidableFilterC977() throw(); };

class FUN_00cbfba0 : public hkReferencedObject,
                     public hkpCollidableCollidableFilterC977,
                     public hkpShapeCollectionFilterC977,
                     public hkpRayShapeCollectionFilterC977,
                     public hkpRayCollidableFilterC977 {
public:
    FUN_00cbfba0() throw();
    int unk18;
    int unk1C;
    int m_type;
    int unk24;
    int unk28;
    int unk2C;

    static void* operator new(size_t nbytes)
    {
        hkReferencedObject* b = static_cast<hkReferencedObject*>(hkMemoryRouter::getInstance().heap().blockAlloc(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
};

class hkpNullCollisionFilterC977 : public FUN_00cbfba0 {
public:
    hkpNullCollisionFilterC977() throw() { m_type = 1; }
    virtual ~hkpNullCollisionFilterC977() throw();
};

struct hkpCollisionInputC977 {
    int unk00;
    int unk04;
    int unk08;
    FUN_00cbfba0* m_iFilter;
};

class hkpWorldC977 {
public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74;
    hkpCollisionInputC977* m_pCollisionInput;
    FUN_00cbfba0* m_pCollisionFilter;

    void FUN_00c977c0(FUN_00cbfba0* filter, hkBoolC977 runUpdate, int updateMode, int ProcessContactPoints);
};

// Uses filter, or a new hkpNullCollisionFilterC977 if null, as m_pCollisionFilter and in m_pCollisionInput, optionally calling FUN_00c96ff0 when runUpdate.
// @fnv 0x00c977c0
void hkpWorldC977::FUN_00c977c0(FUN_00cbfba0* filter, hkBoolC977 runUpdate, int updateMode, int ProcessContactPoints)
{
    if (filter == 0)
        filter = new hkpNullCollisionFilterC977();
    else
        reinterpret_cast<::FUN_00c90510_class *>((((FUN_00c90510_s*)filter)))->FUN_00c90510();
    reinterpret_cast<::hkReferencedObjectC905 *>((((FUN_00c905b0_s*)m_pCollisionFilter)))->FUN_00c905b0();
    m_pCollisionFilter = filter;
    m_pCollisionInput->m_iFilter = m_pCollisionFilter;
    if (runUpdate)
        reinterpret_cast<::S96_WorldShell *>(this)->FUN_00c96ff0(updateMode, ProcessContactPoints);
}
}  // namespace fnv_00c977c0

typedef float hkReal_S;
typedef signed short hkInt16_S;
typedef unsigned short hkUint16_S;
typedef hkUlong hkUlong_S;
typedef size_t hk_size_t;class FinishingFlag
{
public:
FinishingFlag():m_bFinishing(0){}
int m_bFinishing;
};
class hkBool_S
{
public:
typedef char CompileTimeTrueType;inline hkBool_S(bool b)
{
m_cBooleanValue=static_cast<char>(b);
}
inline operator bool()const
{
return m_cBooleanValue !=0;
}
private:
char m_cBooleanValue;};
template<typename TYPE>
class ValueWrapper
{
public:
__forceinline ValueWrapper(){}
private:
TYPE m_kStorage;};
class hkBaseObject_S
{
public:
static const struct ClassMemberDescriptor Members[];public:
__forceinline hkBaseObject_S(){}
};
class hkReferencedObject_S:public hkBaseObject_S
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject_S*b=static_cast<hkReferencedObject_S*>(hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16_S>(nbytes);;return b;}
public:
enum
{
MASK_MEMSIZE=0x7fff
};
hkUint16_S m_usMemSizeAndFlags;
public:
hkReferencedObject_S(class FinishingFlag flag){}
};template<typename T>
class hkSingleton
{
public:
static T*s_instance;protected:
hkSingleton(){}
};template<bool N>struct BooleanTypeConstant{typedef BooleanTypeConstant<N>type;enum{result=N};};
typedef BooleanTypeConstant<true>hkTypeIsPod;
struct RouterHeapAllocatorProvider
{
hkMemoryAllocator&get(const void*){return hkMemoryRouter::getInstance().heap();}
};
template<typename T>
class HavokElementArray
{
public:
typedef HavokElementArray<T>ThisType;
protected:
__forceinline HavokElementArray(const HavokElementArray&a){;}
public:
__forceinline void _useExternalArray(T*,int cap);
protected:
__forceinline HavokElementArray<T>&copyFromArray(hkMemoryAllocator&,const HavokElementArray<T>&src,hkTypeIsPod);
public:
enum
{
CAPACITY_MASK=int(0x3FFFFFFF),
FLAG_MASK=int(0xC0000000),
DONT_DEALLOCATE_FLAG=int(0x80000000),
FORCE_SIGNED=-1
};
protected:
friend class hkStatisticsCollector;
public:
HavokElementArray(FinishingFlag f){}
};
template<typename T,typename Allocator_S=RouterHeapAllocatorProvider>
class hkArray_S:public HavokElementArray<T>
{
public:
typedef Allocator_S AllocatorType;protected:
__forceinline hkArray_S(const hkArray_S&a);
public:
__forceinline hkArray_S&operator=(const HavokElementArray<T>&a);};

typedef __m128 hkQuadReal;
class hkVector4_S;
typedef const hkVector4_S&hkVector4Parameter;
class VectorComponentValue
{
public:
VectorComponentValue(const hkQuadReal&x)
:m_vValue(x)
{
}
operator hkReal_S()const
{
hkReal_S s;
_mm_store_ss(&s,m_vValue);
return s;
}
__forceinline hkQuadReal broadcast()const
{
return _mm_shuffle_ps(m_vValue,m_vValue,0);
}
__forceinline const hkQuadReal&getQuad()const
{
return m_vValue;
}
private:
hkQuadReal m_vValue;};
typedef const VectorComponentValue&hkSimdRealParameter;
class hkQuaternion_S;
class hkTransform_S;
class hkQsTransform_S;
class hkVector4_S
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline void operator=(const hkVector4_S&v);
__forceinline void set(hkReal_S x,hkReal_S y,hkReal_S z,hkReal_S w=0);
__forceinline void SetAllComponents(hkSimdRealParameter x);
__forceinline void add4(const hkVector4_S&a);
__forceinline void setAdd4(const hkVector4_S&a,const hkVector4_S&b);
__forceinline void sub4(const hkVector4_S&a);
__forceinline void setSub4(const hkVector4_S&a,const hkVector4_S&b);
__forceinline void setMul4(hkVector4Parameter a,hkVector4Parameter b);
__forceinline void addMul4(hkSimdRealParameter r,const hkVector4_S&a);
__forceinline void addMul4(hkVector4Parameter a,hkVector4Parameter b);
__forceinline void setAddMul4(const hkVector4_S&a,const hkVector4_S&x,const hkVector4_S&y);
__forceinline void setCross(const hkVector4_S&a,const hkVector4_S&b);
__forceinline void SetRotatedDirection(const hkQuaternion_S&q,const hkVector4_S&b);
__forceinline VectorComponentValue dot3(const hkVector4_S&a)const;
__forceinline VectorComponentValue length3()const;
__forceinline void setXYZW(const hkVector4_S&xyz,const hkVector4_S&w);
__forceinline VectorComponentValue getSimdAt(int i)const;
__forceinline void broadcast(int i);
__forceinline void setBroadcast(hkVector4Parameter v,int i);
__forceinline hkQuadReal&getQuad();
private:
hkQuadReal m_vComponents;
public:
operator hkQuadReal()const
{
return m_vComponents;
}
};
class hkQuaternion_S
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
inline void SetProduct(const hkQuaternion_S&q0,const hkQuaternion_S&q1);
__forceinline const hkVector4_S&getImag()const;
public:
hkVector4_S m_vec;
protected:
void setFlippedRotation(const hkVector4_S&from);};
class hkQsTransform_S
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline const hkVector4_S&getTranslation()const;
__forceinline const hkQuaternion_S&getRotation()const;
public:
hkVector4_S m_vTranslation;
hkQuaternion_S m_rotation;
hkVector4_S m_vScale;};
inline hkQuadReal&hkVector4_S::getQuad()
{
return m_vComponents;
}
inline void hkVector4_S::operator=(const hkVector4_S&v)
{
m_vComponents=v.m_vComponents;
}
inline void hkVector4_S::set(hkReal_S a,hkReal_S b,hkReal_S c,hkReal_S d)
{
m_vComponents=_mm_setr_ps(a,b,c,d);
}
inline void hkVector4_S::SetAllComponents(hkSimdRealParameter a)
{
m_vComponents=_mm_shuffle_ps(a.getQuad(),a.getQuad(),(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
}
inline void hkVector4_S::add4(const hkVector4_S&v)
{
m_vComponents=_mm_add_ps(m_vComponents,v.m_vComponents);
}
inline void hkVector4_S::setAdd4(const hkVector4_S&v0,const hkVector4_S&v1)
{
m_vComponents=_mm_add_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4_S::sub4(const hkVector4_S&v)
{
m_vComponents=_mm_sub_ps(m_vComponents,v.m_vComponents);
}
inline void hkVector4_S::setSub4(const hkVector4_S&v0,const hkVector4_S&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4_S::setMul4(const hkVector4_S&a,const hkVector4_S&b)
{
m_vComponents=_mm_mul_ps(a.m_vComponents,b.m_vComponents);
}
inline void hkVector4_S::addMul4(hkSimdRealParameter r,const hkVector4_S&v1)
{
m_vComponents=_mm_add_ps(m_vComponents,
_mm_mul_ps(r.broadcast(),v1.m_vComponents));
}
inline void hkVector4_S::addMul4(const hkVector4_S&x,const hkVector4_S&y)
{
m_vComponents=_mm_add_ps(m_vComponents,
_mm_mul_ps(x.m_vComponents,y.m_vComponents));
}
inline void hkVector4_S::setAddMul4(const hkVector4_S&a,const hkVector4_S&x,const hkVector4_S&y)
{
m_vComponents=_mm_add_ps(a.m_vComponents,
_mm_mul_ps(x.m_vComponents,y.m_vComponents));
}
inline void hkVector4_S::setCross(const hkVector4_S&v0,const hkVector4_S&v1)
{
hkQuadReal cross0;
cross0=_mm_mul_ps(
_mm_shuffle_ps(v0.m_vComponents,v0.m_vComponents,(((3)<<6)|((0)<<4)|((2)<<2)|((1)))),
_mm_shuffle_ps(v1.m_vComponents,v1.m_vComponents,(((3)<<6)|((1)<<4)|((0)<<2)|((2)))));
hkQuadReal cross1;
cross1=_mm_mul_ps(
_mm_shuffle_ps(v0.m_vComponents,v0.m_vComponents,(((3)<<6)|((1)<<4)|((0)<<2)|((2)))),
_mm_shuffle_ps(v1.m_vComponents,v1.m_vComponents,(((3)<<6)|((0)<<4)|((2)<<2)|((1)))));
m_vComponents=_mm_sub_ps(cross0,cross1);}
inline VectorComponentValue hkVector4_S::dot3(const hkVector4_S&a)const
{
hkQuadReal x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
hkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
return _mm_add_ss(_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum);}
inline VectorComponentValue hkVector4_S::length3()const
{
return _mm_sqrt_ss(this->dot3(*this).getQuad());
}
inline void hkVector4_S::setXYZW(const hkVector4_S&xyz,const hkVector4_S&w)
{
m_vComponents=_mm_shuffle_ps(xyz.m_vComponents,_mm_unpackhi_ps(xyz.m_vComponents,w.m_vComponents),(((3)<<6)|((0)<<4)|((1)<<2)|((0))));
}
inline VectorComponentValue hkVector4_S::getSimdAt(int i)const
{
switch(i)
{
case 0:
return m_vComponents;
case 1:
return _mm_shuffle_ps(m_vComponents,m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
case 2:
return _mm_shuffle_ps(m_vComponents,m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
case 3:
default:
return _mm_shuffle_ps(m_vComponents,m_vComponents,(((3)<<6)|((3)<<4)|((3)<<2)|((3))));
}
}
inline void hkVector4_S::broadcast(int i)
{
if(i==0)
{
m_vComponents=_mm_shuffle_ps(m_vComponents,m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
}
}
inline void hkVector4_S::setBroadcast(const hkVector4_S&v,int i)
{
if(i==0)
{
m_vComponents=_mm_shuffle_ps(v.m_vComponents,v.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
}
else if(i==3)
{
m_vComponents=_mm_shuffle_ps(v.m_vComponents,v.m_vComponents,(((3)<<6)|((3)<<4)|((3)<<2)|((3))));
}
}
__forceinline void hkVector4_S::SetRotatedDirection(const hkQuaternion_S&quat,const hkVector4_S&direction)
{
hkVector4_S minusHalf;minusHalf.getQuad()=::DAT_010c71e0;
hkVector4_S qreal;
qreal.setBroadcast(quat.m_vec,3);
hkVector4_S q2minus1;
q2minus1.setAddMul4(minusHalf,qreal,qreal);
hkVector4_S ret;
ret.setMul4(direction,q2minus1);
hkVector4_S imagDotDir;
imagDotDir.getQuad()=quat.getImag().dot3(direction).getQuad();
imagDotDir.broadcast(0);
ret.addMul4(imagDotDir,quat.getImag());
hkVector4_S imagCrossDir;
imagCrossDir.setCross(quat.getImag(),direction);
ret.addMul4(qreal,imagCrossDir);
this->setAdd4(ret,ret);}
inline const hkVector4_S&hkQuaternion_S::getImag()const
{
return m_vec;
}
inline void hkQuaternion_S::SetProduct(const hkQuaternion_S&q0,const hkQuaternion_S&q1)
{
hkVector4_S vec;
vec.setCross(q0.getImag(),q1.getImag());
vec.addMul4(q0.m_vec.getSimdAt(3),q1.getImag());
hkVector4_S dot;
dot.SetAllComponents(q0.m_vec.dot3(q1.m_vec));
hkVector4_S w;
w.sub4(dot);
m_vec.setXYZW(vec,w);}
const hkVector4_S&hkQsTransform_S::getTranslation()const
{
return m_vTranslation;
}
const hkQuaternion_S&hkQsTransform_S::getRotation()const
{
return m_rotation;
}
class hkDisplayGeometry;
class hkDebugDisplayHandler
{
public:
enum Command
{
HK_STEP=0x00,
HK_ADD_GEOMETRY,
HK_UPDATE_GEOMETRY,
HK_SET_COLOR_GEOMETRY,
HK_REMOVE_GEOMETRY,
HK_DISPLAY_GEOMETRY_WITH_TRANSFORM,
HK_DISPLAY_GEOMETRY,
HK_DISPLAY_POINT,
HK_DISPLAY_LINE,
HK_DISPLAY_TEXT,
HK_SEND_STATISTICS_DUMP_DEPRICATED,
HK_HOLD_IMMEDIATE,
HK_ADD_CAMERA,
HK_UPDATE_CAMERA,
HK_REMOVE_CAMERA,
HK_SEND_MEMSTATS_DUMP,
HK_ADD_GEOMETRY_INSTANCE,
HK_DISPLAY_TEXT_3D,
HK_UPDATE_BEHAVIOR,
HK_LIST_BEHAVIORS,
HK_DISPLAY_ANNOTATION,
};};
class hkDebugDisplay:public hkReferencedObject_S,public hkSingleton<hkDebugDisplay>
{
friend class hkSingleton<hkDebugDisplay>;
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject_S*b=static_cast<hkReferencedObject_S*>(hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16_S>(nbytes);;return b;}__forceinline void __cdecl operator delete(void*p){hkReferencedObject_S*b=static_cast<hkReferencedObject_S*>(p);;hkMemoryRouter::getInstance().heap().blockFree(p,b->m_usMemSizeAndFlags);}__forceinline void*__cdecl operator new(std::size_t,void*p){return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkDebugDisplay();
~hkDebugDisplay();
void addDebugDisplayHandler(hkDebugDisplayHandler*debugDisplay);
void removeDebugDisplayHandler(hkDebugDisplayHandler*debugDisplay);
void clear();
public:
void AddDisplayGeometry(const hkArray_S<hkDisplayGeometry*>&geometries,const hkTransform_S&transform,hkUlong_S id,int tag,hkUlong_S shapeIdHint);
void ReplaceGeometry(hkUlong_S origianalGeomId,const hkTransform_S&transform,hkUlong_S id,int tag,hkUlong_S shapeIdHint);
void SetGeometryColor(int color,hkUlong_S id,int tag);
void m_bUpdateGeometry(const hkTransform_S&transform,hkUlong_S id,int tag);
void RemoveGeometry(hkUlong_S id,int tag,hkUlong_S shapeIdHint);
void DisplayCamera(const hkVector4_S&from,const hkVector4_S&to,const hkVector4_S&up,hkReal_S nearPlane,hkReal_S farPlane,hkReal_S fov,const char*name);
void DisplayBehaviorGraph(hkArray_S<int>&wordVarIdx,hkArray_S<int>&wordStack,hkArray_S<int>&quadVarIdx,hkArray_S<hkVector4_S>&quadStack,
hkArray_S<char*>&activeNodes,hkArray_S<int>&activeStateIds,hkArray_S<int>&activeTransitions,hkArray_S<hkQsTransform_S>&transforms);
void DisplayPoint(const hkVector4_S&position,int color,hkUlong_S id,int tag);
void DisplayTriangle(const hkVector4_S&a,const hkVector4_S&b,const hkVector4_S&c,int color,hkUlong_S id,int tag);
void displayLineModelSpace(const hkQsTransform_S&worldFromModel,const hkVector4_S&start,const hkVector4_S&end,int color,hkUlong_S id,int tag);
void displayLineModelSpace(const hkTransform_S&worldFromModel,const hkVector4_S&start,const hkVector4_S&end,int color,hkUlong_S id,int tag);
void displayRay(const hkVector4_S&start,const hkVector4_S&direction,int color,hkUlong_S id,int tag);
void displayRayModelSpace(const hkQsTransform_S&worldFromModel,const hkVector4_S&start,const hkVector4_S&direction,int color,hkUlong_S id,int tag);
void displayRayModelSpace(const hkTransform_S&worldFromModel,const hkVector4_S&start,const hkVector4_S&direction,int color,hkUlong_S id,int tag);
void RenderLine(const hkVector4_S&start,const hkVector4_S&dir,int color,hkUlong_S id,int tag);
void displayStar(const hkVector4_S&position,hkReal_S scale,int color,hkUlong_S id,int tag);
void displayStarModelSpace(const hkQsTransform_S&worldFromModel,const hkVector4_S&position,hkReal_S scale,int color,hkUlong_S id,int tag);
void displayStarModelSpace(const hkTransform_S&worldFromModel,const hkVector4_S&position,hkReal_S scale,int color,hkUlong_S id,int tag);
void DisplayPlane(const hkVector4_S&plane,const hkVector4_S&offset,hkReal_S scale,int color,hkUlong_S id,int tag);
void FUN_00c998b0(int numTransforms,const hkInt16_S*parentIndices,const hkQsTransform_S*modelSpacePose,const hkQsTransform_S&worldFromModel,hkUlong_S id,int tag,int color=0x7fffffff,hkReal_S boneAxisSize=0.25f,hkBool_S showRootTranslation=false);
void displayLocalSpacePose(int numTransforms,const hkInt16_S*parentIndices,const hkQsTransform_S*localSpacePose,const hkQsTransform_S&worldFromModel,hkUlong_S id,int tag,int color=0x7fffffff,hkReal_S boneAxisSize=0.25f,hkBool_S showRootTranslation=false);
void displayText(const char*text,int color,hkUlong_S id,int tag);
void Display3DText(const char*text,const hkVector4_S&pos,int color,hkUlong_S id,int tag);
void displayFrame(const hkQsTransform_S&worldFromLocal,hkReal_S size,hkUlong_S id,int tag);
void displayFrame(const hkTransform_S&worldFromLocal,hkReal_S size,hkUlong_S id,int tag);
void DisplayGeometryList(const HavokElementArray<hkDisplayGeometry*>&geometries,const hkTransform_S&transform,int color,hkUlong_S id,int tag);
void DisplayGeometryList(const HavokElementArray<hkDisplayGeometry*>&geometries,int color,hkUlong_S id,int tag);
void displayAabb(const class hkAabb&aabb,int color,hkUlong_S id,int tag);
void displayLitTriangle(const hkVector4_S&a,const hkVector4_S&b,const hkVector4_S&c,int color);
protected:
hkArray_S<hkDebugDisplayHandler*>m_kDebugDisplayHandlers;
mutable class PhysicsSimulationContext*m_pPhysicsSimulationContext;
};
// Renders bone hierarchy lines and local axis frames for a skeleton pose by transforming model-space positions and rotations into world space.
// @fnv 0x00c998b0
void hkDebugDisplay::FUN_00c998b0(int numTransforms,const hkInt16_S*parentIndices,const hkQsTransform_S*modelSpacePose,const hkQsTransform_S&worldFromModel,hkUlong_S id,int tag,int color,hkReal_S boneAxisSize,hkBool_S showRootTranslation)
{
const hkInt16_S numBones=static_cast<hkInt16_S>(numTransforms);
for(hkInt16_S i=0;i<numBones;i++)
{
hkVector4_S p1;
reinterpret_cast<::TransformedPosDAD *>(&(p1))->FUN_00c7f7a0((const ::hkQsTransformDAD &)(worldFromModel),(const ::hkVector4DAD &)(modelSpacePose[i].getTranslation()));
hkReal_S boneLen=1.0f;
const hkInt16_S parent=parentIndices[i];
if(parent==-1)
{
if(showRootTranslation)
{
hkVector4_S p2;
p2.set(0,0,0,0);
reinterpret_cast<::TransformedPosDAD *>(&(p2))->FUN_00c7f7a0((const ::hkQsTransformDAD &)(worldFromModel),(const ::hkVector4DAD &)(p2));
reinterpret_cast<::hkpListenerListC98B *>(this)->FUN_00c986c0(&(p1), &(p2),color,id,tag);
}
}
else
{
hkVector4_S p2;
reinterpret_cast<::TransformedPosDAD *>(&(p2))->FUN_00c7f7a0((const ::hkQsTransformDAD &)(worldFromModel),(const ::hkVector4DAD &)(modelSpacePose[parent].getTranslation()));
reinterpret_cast<::hkpListenerListC98B *>(this)->FUN_00c986c0(&(p1), &(p2),color,id,tag);
hkVector4_S bone;
bone.setSub4(p1,p2);
boneLen=bone.length3();
boneLen=(boneLen>10.0f)? 10.0f:boneLen;
boneLen=(boneLen<0.1f)? 0.1f:boneLen;
}
const hkVector4_S worldPosition=p1;
hkQuaternion_S worldRotation;::fnv_00c66320::FUN_00c66320((::fnv_00c66320::__m128 *)&(worldRotation), nullptr, (const ::fnv_00c66320::__m128 *)&(worldFromModel.getRotation()), (const ::fnv_00c66320::__m128 *)&(modelSpacePose[i].getRotation()));
{
hkVector4_S boneLocalFrame;
hkVector4_S p2;
p1=worldPosition;
boneLocalFrame.set(boneAxisSize*boneLen,0,0,0);
p2.SetRotatedDirection(worldRotation,boneLocalFrame);
p2.add4(p1);
reinterpret_cast<::hkpListenerListC98B *>(this)->FUN_00c986c0(&(p1), &(p2),0x7fff0000,id,tag);
p1=worldPosition;
boneLocalFrame.set(0,boneAxisSize*boneLen,0,0);
p2.SetRotatedDirection(worldRotation,boneLocalFrame);
p2.add4(p1);
reinterpret_cast<::hkpListenerListC98B *>(this)->FUN_00c986c0(&(p1), &(p2),0x7f00ff00,id,tag);
p1=worldPosition;
boneLocalFrame.set(0,0,boneAxisSize*boneLen,0);
p2.SetRotatedDirection(worldRotation,boneLocalFrame);
p2.add4(p1);
reinterpret_cast<::hkpListenerListC98B *>(this)->FUN_00c986c0(&(p1), &(p2),0x7f0000ff,id,tag);
}
}
}



class hkQuaternionDAD;

class __declspec(align(16)) hkVector4DAD {
public:
    __forceinline void SetRotatedDirection(const hkQuaternionDAD& quat, const hkVector4DAD& direction);
    inline hkVector4DAD& operator=(const hkVector4DAD& v) { m_vComponents = v.m_vComponents; return *this; }
    __forceinline void setAdd4(const hkVector4DAD& a, const hkVector4DAD& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setMul4(const hkVector4DAD& a, const hkVector4DAD& b) { m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void addMul4(const hkVector4DAD& a, const hkVector4DAD& b) { m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents)); }
    __forceinline void setCross(const hkVector4DAD& v1, const hkVector4DAD& v2)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9), _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2), _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline void setBroadcast3(const hkVector4DAD& v) { m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff); }
    __forceinline __m128 dot3(const hkVector4DAD& v) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }

    __m128 m_vComponents;
};

class hkQuaternionDAD {
public:
     // SetProduct
    const hkVector4DAD& getImag() const { return m_vec; }

    hkVector4DAD m_vec;
};

__forceinline void hkVector4DAD::SetRotatedDirection(const hkQuaternionDAD& quat, const hkVector4DAD& direction)
{
    hkVector4DAD qreal; qreal.setBroadcast3(quat.m_vec);
    hkVector4DAD q2minus1; q2minus1.m_vComponents = _mm_add_ps(_mm_mul_ps(qreal.m_vComponents, qreal.m_vComponents), ::DAT_010c71e0);
    hkVector4DAD ret; ret.setMul4(q2minus1, direction);
    hkVector4DAD imagDotDir; imagDotDir.m_vComponents = quat.getImag().dot3(direction); imagDotDir.m_vComponents = _mm_shuffle_ps(imagDotDir.m_vComponents, imagDotDir.m_vComponents, 0);
    hkVector4DAD imagCrossDir; imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(imagDotDir, quat.getImag());
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}

class hkQsTransformDAD {
public:
    __forceinline void SetProduct(const hkQsTransformDAD& t1, const hkQsTransformDAD& t2)
    {
        hkVector4DAD temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        ::fnv_00c66320::FUN_00c66320((::fnv_00c66320::__m128 *)&(m_rotation), nullptr, (const ::fnv_00c66320::__m128 *)&(t1.m_rotation), (const ::fnv_00c66320::__m128 *)&(t2.m_rotation));
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }

    hkVector4DAD m_vTranslation;
    hkQuaternionDAD m_rotation;
    hkVector4DAD m_vScale;
};



__forceinline void transformLocalPoseToModelPoseDAD(int numTransforms, const short* parentIndices, const hkQsTransformDAD& worldFromModel, const hkQsTransformDAD* poseLocal, hkQsTransformDAD* poseModelOut)
{
    for (int i = 0; i < numTransforms; i++)
    {
        const int parentId = parentIndices[i];
        const hkQsTransformDAD& worldFromParent = (-1 != parentId) ? poseModelOut[parentId] : worldFromModel;
        poseModelOut[i].SetProduct(worldFromParent, poseLocal[i]);
    }
}

class PoseUserDAD {
public:
    void FUN_00c99d40(int numBones, const short* parents, const hkQsTransformDAD* poseLocal, const void* a4, hkUlong a5, int a6, int a7, float a8, int a9);
};

// Converts local bone poses to model space on the stack and forwards them to FUN_00c998b0.
// @fnv 0x00c99d40
void PoseUserDAD::FUN_00c99d40(int numBones, const short* parents, const hkQsTransformDAD* poseLocal, const void* a4, hkUlong a5, int a6, int a7, float a8, int a9)
{
    hkQsTransformDAD* poseModel = static_cast<hkQsTransformDAD*>(hkMemoryRouter::getInstance().allocateStack((numBones * int(sizeof(hkQsTransformDAD)) + 0x7f) & ~0x7f));

    transformLocalPoseToModelPoseDAD(numBones, parents, reinterpret_cast<const hkQsTransformDAD&>(::DAT_01268700), poseLocal, poseModel);
    reinterpret_cast<::hkDebugDisplay *>(this)->FUN_00c998b0(numBones, parents, (const ::hkQsTransform_S *)(poseModel), (*(const ::hkQsTransform_S *)(a4)), a5, a6, a7, a8, (::hkBool_S)(a9));

    hkMemoryRouter::getInstance().deallocateStack(poseModel);
}

namespace fnv_00caa3f0 {

struct AutoMemoryContext {
 unsigned int previous;
 AutoMemoryContext(unsigned int value):previous(g_tlsBlock.memoryContext){g_tlsBlock.memoryContext=value;}
 ~AutoMemoryContext(){g_tlsBlock.memoryContext=previous;}
};
struct __declspec(align(16)) HingeVector {float x,y,z,w;};
struct HingeTransform {HingeVector rotation0,rotation1,rotation2,translation;};
struct HingeTransformsAtom {unsigned short type; HingeTransform a,b;};
struct HingeMotorAtom {unsigned short type;unsigned char enabled,axis; unsigned short solverOffset,initializedOffset,previousAngleOffset;float targetAngle;void* motor;};
struct HingeFrictionAtom {unsigned short type;unsigned char enabled,axis;unsigned short firstSolverResult,solverResultCount;float maxTorque;};
struct HingeLimitAtom {unsigned short type;unsigned char enabled,axis;float minimum,maximum,tau;};
struct Hinge2DAngAtom {unsigned short type;unsigned char freeAxis,axis;};
struct HingeBallSocketAtom {unsigned short type;unsigned char solvingMethod,bodiesToNotify;float velocityStabilizationFactor;};
struct HingeAtoms {HingeTransformsAtom transforms;HingeMotorAtom motor;HingeFrictionAtom friction;HingeLimitAtom limit;Hinge2DAngAtom angular;HingeBallSocketAtom ballSocket;};
class hkpConstraintData : public hkReferencedObject {public: unsigned int userData;};
class hkpLimitedHingeConstraintData : public hkpConstraintData {
public:
 HingeAtoms atoms;
 hkpLimitedHingeConstraintData();
 static void* operator new(size_t size) {void* p=hkMemoryRouter::getInstance().heap().blockAlloc(size); static_cast<hkReferencedObject*>(p)->m_usMemSizeAndFlags=(unsigned short)size;return p;}
 static void operator delete(void* p) {hkMemoryRouter::getInstance().heap().blockFree(p,0xe0);}
};
class LimitedHingeWrapper {
public: unsigned int unk00;hkpLimitedHingeConstraintData* data;
 unsigned int FUN_00caa3f0();
};
// Ensures the hkpLimitedHingeConstraintData is allocated and returns its size.
// @fnv 0x00caa3f0
unsigned int LimitedHingeWrapper::FUN_00caa3f0()
{
 AutoMemoryContext context(0x10);
 if(!data) data=new hkpLimitedHingeConstraintData;
 return sizeof(hkpLimitedHingeConstraintData);
}
}  // namespace fnv_00caa3f0


extern int DAT_01268188;
extern int DAT_01268318;
void* FUN_00aa13e0(unsigned int size);



class TlsGuard_caa4a0 {
public:
    int m_saved;
    TlsGuard_caa4a0() { m_saved = g_tlsBlock.memoryContext; g_tlsBlock.memoryContext = 0x10; }
    ~TlsGuard_caa4a0() { g_tlsBlock.memoryContext = m_saved; }
};

class bhkRefObject {
public:
    const void* m_vtbl;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    bhkRefObject() {
        reinterpret_cast<::FUN_00c87c30_t *>(this)->FUN_00c87c30();
        m_vtbl = (const void*)&DAT_0108febc;
        _ReadWriteBarrier();
        const int inc = 1;
        unk0c = 0;
        DAT_01268188 += inc;
        _ReadWriteBarrier();
        m_vtbl = (const void*)fnv_vftable_FUN_00c88380;
        _ReadWriteBarrier();
        DAT_01268318 += inc;
    }
};

struct caa4a0_TblHost { void* m_00; void* m_04; void* m_08; unsigned int* m_0c; };
struct caa4a0_TblFirst { unsigned int* m_00; };

class caa4a0_RefObj {
public:
    virtual void slot00();
    virtual void slot04(int a, void* b);
};

class caa4a0_Target {
public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual unsigned int* slotb4(bool* flagOut);
    unsigned int unk04;
    caa4a0_TblHost* unk08;
    caa4a0_TblFirst* unk0c;
    bhkRefObject* FUN_00caa4a0(void* param);
};

// Allocates a bhkRefObject, calls FUN_00c89730, and if a table entry is set, invokes slot04 on the object from slotb4.
// @fnv 0x00caa4a0
bhkRefObject* caa4a0_Target::FUN_00caa4a0(void* param) {
    TlsGuard_caa4a0 guard;
    FUN_00c876f0();
    bhkRefObject* obj = new bhkRefObject();
    reinterpret_cast<::Owner89730 *>((this))->FUN_00c89730(obj, (::Process89730 *)(param));
    unsigned int* tbl = 0;
    if (this != 0 && this->unk08 != 0)
        tbl = this->unk08->m_0c;
    else if (this->unk0c != 0)
        tbl = this->unk0c->m_00;
    if (tbl != 0 && tbl[44] != 0) {
        bool b;
        unsigned int* p = this->slotb4(&b);
        caa4a0_RefObj* ref = (caa4a0_RefObj*)(p != 0 ? p - 1 : 0);
        ref->slot04(0, param);
    }
    FUN_00c87700();
    return obj;
}

static inline void** AddBack(hkArray<void*>* arr, void* listener) {
    hkMemoryRouter* mem = &hkMemoryRouter::getInstance();
    if (arr->m_iElementCount == (arr->m_iCapacityState & 0x3fffffff)) {
        ::ResizeAudioStream((::AudioAllocator *)(mem->m_heap), (::AudioStream *)(void *)(arr), 4);
    }
    void** p = &arr->m_data[arr->m_iElementCount];
    *p = listener;
    arr->m_iElementCount++;
    return p;
}

struct FUN_00c939a0_Class : hkpWorld {
    void** FUN_00c939a0(void* listener);
};

// Adds the given listener to the island post-collide listener array and returns a pointer to the new slot.
// @fnv 0x00c939a0
void** FUN_00c939a0_Class::FUN_00c939a0(void* listener) {
    return AddBack(&m_kIslandPostCollideListeners, listener);
}



struct hkpWorld_Listener : hkpWorld {
    void*& FUN_00c93a60(void* listener);
};

// Appends a listener pointer to m_kWorldDeletionListeners, growing the array via FUN_00c90940 when full, and returns the stored pointer.
// @fnv 0x00c93a60
void*& hkpWorld_Listener::FUN_00c93a60(void* listener) {
    hkArray<void*>* arr = &m_kWorldDeletionListeners;
    hkMemoryRouter* mem = &hkMemoryRouter::getInstance();
    if (arr->m_iElementCount == (arr->m_iCapacityState & 0x3fffffff)) {
        ::ResizeAudioStream((::AudioAllocator *)(mem->m_heap), (::AudioStream *)(void *)(arr), 4);
    }
    void** slot = &arr->m_data[arr->m_iElementCount];
    *slot = listener;
    arr->m_iElementCount++;
    return *slot;
}

struct FUN_00c92c70_Class {
};

struct FUN_00c936a0_Class {
};

struct NiRTTI;
struct NiObject {
    virtual const NiRTTI* GetStreamableRTTI();
};

union __declspec(align(16)) PositionQuad {
    __m128 simd;
    signed char bytes[16];
};
struct __declspec(align(16)) SavedPosition {
    PositionQuad quad;
    SavedPosition() {}
    SavedPosition(const SavedPosition& other) { quad.simd = *(const __m128*)&other.quad.bytes[0]; }
};

struct ActionObj {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void AssignEntity(void* entity);
    void* unk04;
    FUN_00c92c70_Class* m_pOwningWorld;
    void* unk0C;
    void* m_pEntity;
};

struct FUN_00cac980_Holder {
};

struct FUN_00cac910_shell : FUN_00cac980_Holder {
    const SavedPosition& FUN_00cac910();
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    ActionObj* unk30;
};

struct ArgClass {
    void* unk00;
    void* unk04;
    void* unk08;
};

extern const SavedPosition zeroPosition;

struct HostClass : NiObject {
    void* unk04;
    FUN_00cac910_shell* unk08;
    __forceinline const SavedPosition& getPosition() {
        FUN_00cac910_shell* proxy = unk08;
        const SavedPosition* result = &zeroPosition;
        if (proxy) {
            reinterpret_cast<::FnvCpu_FUN_00c89720_CpuInterface *>((this))->FUN_00c89720();
            result = &proxy->FUN_00cac910();
            reinterpret_cast<::FnvCpu_FUN_00c89720_CpuInterface *>((this))->FUN_00c89720();
        }
        return *result;
    }
    bool FUN_00c6d3f0(ArgClass* a1, int a2);
};

// If the action's current entity differs from a1->unk08, calls world->FUN_00c92c70, a virtual with a1->unk08, then FUN_00c936a0; returns true if so.
// @fnv 0x00c6d3f0
bool HostClass::FUN_00c6d3f0(ArgClass* a1, int aiUnused) {
    FUN_00cac910_shell* obj = this->unk08;
    if (obj) {
        ActionObj* action = (ActionObj*)reinterpret_cast<::FUN_00cac980_class *>((obj))->FUN_00cac980();
        if (action) {
            void* curEnt = action->m_pEntity;
            void* ent = a1 ? a1->unk08 : 0;
            if (curEnt != ent) {
                FUN_00c92c70_Class* world = action->m_pOwningWorld;
                SavedPosition position(getPosition());
                if (world) {
                    reinterpret_cast<::WorldC92C *>((world))->FUN_00c92c70((::ActionC92C *)(action));
                }
                action->AssignEntity(a1 ? a1->unk08 : 0);
                if (world) {
                    reinterpret_cast<::FUN_00c936a0_World *>((((FUN_00c936a0_Class*)world)))->FUN_00c936a0((::hkpPhantom *)(action));
                }
                return true;
            }
        }
    }
    return false;
}



template <typename T>
inline T* hkArrayPushBack(hkArray<T>& arr, hkMemoryRouter* mem, const T& t) {
    if (arr.m_iElementCount == (arr.m_iCapacityState & 0x3fffffff)) {
        ::ResizeAudioStream((::AudioAllocator *)(mem->m_heap), (::AudioStream *)(void *)(&arr), sizeof(T));
    }
    T* p = &arr.m_data[arr.m_iElementCount];
    *p = t;
    arr.m_iElementCount++;
    return p;
}

struct FUN_00c93aa0_Class : hkpWorld {
    void* FUN_00c93aa0(void* listener);
};

// Adds a listener to m_kContactImpulseLimitBreachedListeners via hkArrayPushBack and returns a pointer to the new element.
// @fnv 0x00c93aa0
void* FUN_00c93aa0_Class::FUN_00c93aa0(void* listener) {
    hkArray<void*>* arr = &m_kContactImpulseLimitBreachedListeners;
    return hkArrayPushBack(*arr, &hkMemoryRouter::getInstance(), listener);
}





struct hkpBroadPhaseHandle {
    unsigned char unk00;
};

class hkpPhantom;

struct PhantomBatchAccess : hkpPhantom {
    int unk1C;
    int unk20;
    hkpBroadPhaseHandle m_handle;
    virtual void slot14() throw();
    virtual void slot18() throw();
    virtual void slot1C() throw();
    virtual void slot20() throw();
    virtual void slot24() throw();
    virtual void slot28() throw();
    virtual void slot2C() throw();
    virtual void slot30() throw();
    virtual void slot34() throw();
};

struct BroadPhaseCastCollector {
    hkpBroadPhaseHandle* m_kPointA;
    hkpBroadPhaseHandle* m_kPointB;
};

template <class T>
struct PhantomBatchLocalArray : hkArray<T> {
    T* m_pTrailingData;
    __forceinline PhantomBatchLocalArray(int n) throw() {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = (int)0x80000000;
        void* p = hkMemoryRouter::getInstance().allocateStack((n * (int)sizeof(T) + 0x7f) & ~0x7f);
        this->m_data = static_cast<T*>(p);
        this->m_iCapacityState = n | (int)0x80000000;
        m_pTrailingData = static_cast<T*>(p);
    }
};

template <class T>
__forceinline void PhantomBatchLocalArray_release(PhantomBatchLocalArray<T>& a) throw() {
    if (a.m_pTrailingData == a.m_data) {
        a.m_iElementCount = 0;
    }
    T* local = a.m_pTrailingData;
    hkMemoryRouter::getInstance().deallocateStack(local);

    hkMemoryAllocator* heap = hkMemoryRouter::getInstance().m_heap;
    int cap = a.m_iCapacityState;
    a.m_iElementCount = 0;
    if (cap & (int)0x80000000) {
        return;
    }
    heap->bufFree(a.m_data, (cap & 0x3fffffff) * (int)sizeof(T));
}

__forceinline int PhantomBatchIndexOf(const hkArray<hkpPhantom*>& arr, hkpPhantom* phantom) throw() {
    int count = arr.m_iElementCount;
    int idx = 0;
    if (count > 0) {
        hkpPhantom** cursor = arr.m_data;
        do {
            if (*cursor == phantom) {
                return idx;
            }
            ++idx;
            ++cursor;
        } while (idx < count);
    }
    return -1;
}

__forceinline void PhantomBatchRemoveAt(hkArray<hkpPhantom*>& arr, int index) throw() {
    --arr.m_iElementCount;
    if (arr.m_iElementCount != index) {
        arr.m_data[index] = arr.m_data[arr.m_iElementCount];
    }
}

struct RemovePhantomBatchOp {
    unsigned char m_type;
    hkpPhantom** m_kPhantoms;
    unsigned short m_iPhantomCount;
};

struct BroadPhaseVt {
    virtual void s00() throw();
    virtual void s04() throw();
    virtual void s08() throw();
    virtual void s0C() throw();
    virtual void s10() throw();
    virtual void s14() throw();
    virtual void s18() throw();
    virtual void s1C() throw();
    virtual void RemoveObjectBatch(hkArray<hkpBroadPhaseHandle*>& handles, hkArray<BroadPhaseCastCollector>& pairs) throw();
};

struct BroadPhaseDispatcher {
};

struct World_RemovePhantomBatch : hkpWorld {
    void FUN_00c91120() throw();
    void FUN_00c95800(hkpPhantom** phantomBatch, int numPhantoms);
};
// @fnv 0x00c980d0
void hkpWorldC980::FUN_00c980d0(const hkpPhysicsSystemC980* pkSys) throw()
{
    for (int c = 0; c < pkSys->getConstraints().GetLogicalSize(); ++c) {
        if (pkSys->getConstraints()[c])
            reinterpret_cast<::C97E80World *>(this)->FUN_00c97e80((::C97E80Action *)(pkSys->getConstraints()[c]));
    }
    for (int a = 0; a < pkSys->getActions().GetLogicalSize(); ++a) {
        if (pkSys->getActions()[a])
            reinterpret_cast<::FUN_00c97f50_Class *>(this)->DispatchOrQueue(pkSys->getActions()[a]);
    }
    if (pkSys->getRigidBodies().indexOf(0) == -1) {
        reinterpret_cast<::HostWorld_00c951b0 *>(this)->RemoveEntities((void *const *)(::hkpEntityC980 *const *)((hkpEntityC980* const*)pkSys->getRigidBodies().begin()), pkSys->getRigidBodies().GetLogicalSize());
    } else {
        for (int r = 0; r < pkSys->getRigidBodies().GetLogicalSize(); ++r) {
            if (pkSys->getRigidBodies()[r])
                reinterpret_cast<::FUN_00c91620_Class *>(this)->ProcessTarget((unsigned char *)(::hkpEntityC980 *)((hkpEntityC980*)pkSys->getRigidBodies()[r]), {});
        }
    }
    if (pkSys->getPhantomArray().indexOf(0) == -1) {
        reinterpret_cast<::World_RemovePhantomBatch *>(this)->FUN_00c95800((::hkpPhantom **)(::hkpPhantomC980 *const *)(pkSys->getPhantomArray().begin()), pkSys->getPhantomArray().GetLogicalSize());
    } else {
        for (int p = 0; p < pkSys->getPhantomArray().GetLogicalSize(); ++p) {
            if (pkSys->getPhantomArray()[p])
                reinterpret_cast<::WorldC92C *>(this)->FUN_00c92c70((::ActionC92C *)(pkSys->getPhantomArray()[p]));
        }
    }
}

// Removes a batch of phantoms from the world, updating broad-phase and phantom lists, and defers if a critical lock is held.
// @fnv 0x00c95800
void World_RemovePhantomBatch::FUN_00c95800(hkpPhantom** phantomBatch, int numPhantoms) {
    if (m_iCriticalOperationsLockCount + m_iCriticalOperationsLockCountForPhantoms) {
        RemovePhantomBatchOp op;
        op.m_type = 0x10;
        op.m_kPhantoms = phantomBatch;
        op.m_iPhantomCount = (unsigned short)numPhantoms;
        reinterpret_cast<::WorldWithPending *>(this)->FUN_00c91160();
        return;
    }

    ++m_iCriticalOperationsLockCount;

    PhantomBatchLocalArray<hkpBroadPhaseHandle*> handles(numPhantoms);
    for (int ph = 0; ph < numPhantoms; ++ph) {
        hkpPhantom* phantom = phantomBatch[ph];
        hkpBroadPhaseHandle* const& handle = &static_cast<PhantomBatchAccess*>(phantom)->m_handle;
        handles.m_data[handles.m_iElementCount] = handle;
        handles.m_iElementCount++;
        ::FUN_00d00820((::D00820World *)(::hkpWorld *)(this), phantom);
        reinterpret_cast<::Fun_cls *>((static_cast<PhantomBatchAccess*>(phantom)))->FUN_00d07b50();
    }

    if (handles.m_iElementCount) {
        PhantomBatchLocalArray<BroadPhaseCastCollector> pairs(m_iBroadPhaseQuerySize);
        ((BroadPhaseVt*)m_pJobSemaphore)->RemoveObjectBatch(handles, pairs);
        reinterpret_cast<::Dispatcher *>((((BroadPhaseDispatcher*)m_pBroadPhaseDispatcher)))->DispatchPairs((::Pair *)(pairs.m_data), pairs.m_iElementCount);
        PhantomBatchLocalArray_release(pairs);
    }

    for (int i = 0; i < numPhantoms; ++i) {
        hkpPhantom* phantom = phantomBatch[i];
        phantom->m_pOwningWorld = 0;
        int idx = PhantomBatchIndexOf(m_kPhantoms, phantom);
        PhantomBatchRemoveAt(m_kPhantoms, idx);
        if (phantom->m_usMemSizeAndFlags == 0) {
            static_cast<PhantomBatchAccess*>(phantom)->slot34();
        }
        reinterpret_cast<::hkReferencedObjectC905 *>((((FUN_00d1df70*)phantom)))->FUN_00c905b0();
    }

    if (--m_iCriticalOperationsLockCount == 0) {
        if (m_bBlockExecutingPendingOperations == 0) {
            if (m_iPendingOperationCount != 0) {
                reinterpret_cast<::FUN_00c91120 *>(this)->ExecutePendingOperations();
            }
            if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount != 0) {
                reinterpret_cast<::FUN_00c91140_Class *>(this)->FUN_00c91140();
            }
        }
    }
    PhantomBatchLocalArray_release(handles);
}

struct __declspec(align(16)) Vec_00c98780 {
    __m128 q;
};

struct Cls_00c98780 {
    void FUN_00c98780(const hkTransform& tr, const hkVector4& a, const hkVector4& b, int color, hkUlong id, int tag);
};
// Builds a pose via FUN_00ce52e0(a1) and passes its address with a2 through a6 to FUN_00c98780 on this.
// @fnv 0x00c987e0
void FUN_00c987e0_Cls::FUN_00c987e0(const void* a1,const void* a2,const void* a3,int a4,hkUlong a5,int a6)
{
    FUN_00c987e0_Pose pose;
    reinterpret_cast<::Ce52e0Helper *>(&(pose))->FUN_00ce52e0(a1);
    reinterpret_cast<::Cls_00c98780 *>((reinterpret_cast<FUN_00c98780_Obj*>(this)))->FUN_00c98780((*(const ::hkTransform *)(&pose)),(*(const ::hkVector4 *)(a2)),(*(const ::hkVector4 *)(a3)),a4,a5,a6);
}

// Builds two vectors from a and b with tr via FUN_00c7f7a0, then passes them with x, y and z to FUN_00c986c0.
// @fnv 0x00c98780
void Cls_00c98780::FUN_00c98780(const hkTransform& tr, const hkVector4& a, const hkVector4& b, int x, hkUlong y, int z)
{
    Vec_00c98780 pa;
    reinterpret_cast<::TransformedPosDAD *>(&(pa))->FUN_00c7f7a0((const ::hkQsTransformDAD &)(tr), (const ::hkVector4DAD &)(a));
    Vec_00c98780 pb;
    reinterpret_cast<::TransformedPosDAD *>(&(pb))->FUN_00c7f7a0((const ::hkQsTransformDAD &)(tr), (const ::hkVector4DAD &)(b));
    reinterpret_cast<::hkpListenerListC98B *>(this)->FUN_00c986c0(&(pa), &(pb), x, y, z);
}


struct Vec_00c98c80 {
    __m128 m_vComponents;
    void set(const float& x, const float& y, const float& z, const float& w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
};

struct Aabb_00c98c80 {
    Vec_00c98c80 m_kMinimumCorner;
    Vec_00c98c80 m_kMaximumCorner;
};

struct Line_00c98c80 {
    Vec_00c98c80 a;
    Vec_00c98c80 b;
};

struct Disp_00c98c80 {
    void FUN_00c98c80(const Aabb_00c98c80* box, int color, hkUlong id, int tag);
};

// Builds the 12 edge lines of the AABB box and draws each with FUN_00c986c0.
// @fnv 0x00c98c80
void Disp_00c98c80::FUN_00c98c80(const Aabb_00c98c80* box, int p2, hkUlong p3, int p4)
{
    const float* pMin = reinterpret_cast<const float*>(&box->m_kMinimumCorner.m_vComponents);
    const float* pMax = reinterpret_cast<const float*>(&box->m_kMaximumCorner.m_vComponents);
    Line_00c98c80 aabbEdges[12];
    aabbEdges[0].a.set(pMin[0], pMin[1], pMin[2], DAT_01011d78);
    aabbEdges[0].b.set(pMin[0], pMax[1], pMin[2], DAT_01011d78);
    aabbEdges[1].a.set(pMin[0], pMin[1], pMin[2], DAT_01011d78);
    aabbEdges[1].b.set(pMin[0], pMin[1], pMax[2], DAT_01011d78);
    aabbEdges[2].a.set(pMin[0], pMin[1], pMin[2], DAT_01011d78);
    aabbEdges[2].b.set(pMax[0], pMin[1], pMin[2], DAT_01011d78);
    aabbEdges[3].a.set(pMax[0], pMax[1], pMax[2], DAT_01011d78);
    aabbEdges[3].b.set(pMax[0], pMax[1], pMin[2], DAT_01011d78);
    aabbEdges[4].a.set(pMax[0], pMax[1], pMax[2], DAT_01011d78);
    aabbEdges[4].b.set(pMin[0], pMax[1], pMax[2], DAT_01011d78);
    aabbEdges[5].a.set(pMax[0], pMax[1], pMax[2], DAT_01011d78);
    aabbEdges[5].b.set(pMax[0], pMin[1], pMax[2], DAT_01011d78);
    aabbEdges[6].a.set(pMin[0], pMax[1], pMin[2], DAT_01011d78);
    aabbEdges[6].b.set(pMax[0], pMax[1], pMin[2], DAT_01011d78);
    aabbEdges[7].a.set(pMin[0], pMax[1], pMin[2], DAT_01011d78);
    aabbEdges[7].b.set(pMin[0], pMax[1], pMax[2], DAT_01011d78);
    aabbEdges[8].a.set(pMax[0], pMax[1], pMin[2], DAT_01011d78);
    aabbEdges[8].b.set(pMax[0], pMin[1], pMin[2], DAT_01011d78);
    aabbEdges[9].a.set(pMin[0], pMax[1], pMax[2], DAT_01011d78);
    aabbEdges[9].b.set(pMin[0], pMin[1], pMax[2], DAT_01011d78);
    aabbEdges[10].a.set(pMin[0], pMin[1], pMax[2], DAT_01011d78);
    aabbEdges[10].b.set(pMax[0], pMin[1], pMax[2], DAT_01011d78);
    aabbEdges[11].a.set(pMax[0], pMin[1], pMax[2], DAT_01011d78);
    aabbEdges[11].b.set(pMax[0], pMin[1], pMin[2], DAT_01011d78);

    for (int i = 0; i < 12; i++)
    {
        reinterpret_cast<::hkpListenerListC98B *>(this)->FUN_00c986c0((&aabbEdges[i].a), (&aabbEdges[i].b), p2, p3, p4);
    }
}

struct Xf_00c996e0 {
    __m128 c0;
    __m128 c1;
    __m128 c2;
};

struct Pose_00c996e0 {
    void ApplyRotation(const Xf_00c996e0& t, int b, int c, int d, int e, int g);
    void FUN_00c996e0(const hkQsTransform& a, int b, int c, int d, int e, int g);
};

// Converts an hkQsTransform into a local Xf_00c996e0 and forwards it to ApplyRotation with the remaining parameters.
// @fnv 0x00c996e0
void Pose_00c996e0::FUN_00c996e0(const hkQsTransform& a, int b, int c, int d, int e, int g)
{
    Xf_00c996e0 t;
    reinterpret_cast<::Ce52e0Helper *>(&(t))->FUN_00ce52e0(&(a));
    ApplyRotation(t, b, c, d, e, g);
}

inline unsigned int GetMemContextCAA()
{
    return g_tlsBlock.memoryContext;
}

inline void SetMemContextCAA(unsigned int m_uiGeometryShaderFlags)
{
    g_tlsBlock.memoryContext = m_uiGeometryShaderFlags;
}

class AutoMemContextCAA {
public:
    AutoMemContextCAA(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContextCAA();
        SetMemContextCAA(m_uiGeometryShaderFlags);
    }
    ~AutoMemContextCAA() { SetMemContextCAA(m_uiPrevious); }
    unsigned int m_uiPrevious;
};




struct __declspec(align(16)) hkVector4CAA {
    __m128 m_vComponents;
    inline hkVector4CAA& operator=(const hkVector4CAA& v) { m_vComponents = v.m_vComponents; return *this; }
};

class hkReferencedObjectCAA {
public:
    virtual ~hkReferencedObjectCAA();

    void* operator new(size_t nbytes)
    {
        hkReferencedObjectCAA* b = static_cast<hkReferencedObjectCAA*>(hkMemoryRouter::getInstance().heap().blockAlloc(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }

    void operator delete(void* p, size_t nbytes)
    {
        hkMemoryRouter::getInstance().heap().blockFree(p, nbytes);
    }

     // removeReference

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class ShapeChildCAA {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual hkReferencedObjectCAA* v0C();
};

class ShapeCAA : public hkReferencedObjectCAA {
public:
    ShapeCAA(); // FUN_00cb9090


    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4CAA m_v20;
    hkVector4CAA m_v30;
    hkVector4CAA m_v40;
    hkVector4CAA m_v50;
    hkVector4CAA m_v60;
    hkVector4CAA m_v70;
    hkVector4CAA m_v80;
    hkVector4CAA m_v90;
    unsigned char unkA0;
    unsigned char unkA1;
    unsigned char m_flagA2;
    unsigned char unkA3;
    int unkA4;
    int unkA8;
    int unkAC;
    ShapeChildCAA* m_pChildAtom;
    int unkB4;
    int unkB8;
    float m_fBC;
    float unkC0;
    float m_fC4;
    float m_fC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
};

struct ShapeCinfoCAA {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_vScale;
};


class ShapeClonerCAA {
public:
    ShapeCAA* ReleaseObject(ShapeCAA* shape, ShapeCinfoCAA* cinfo);
    ShapeCAA* FUN_00caa250(ShapeCAA* dst, ShapeCinfoCAA* cinfo);

    int unk00;
    ShapeCAA* m_pCollisionShape;
};

// Copies fields from m_pCollisionShape into dst (new if null), applies cinfo->m_vScale if not 1.0, copies the child atom, and returns FUN_00c8a1b0(dst, cinfo).
// @fnv 0x00caa250
ShapeCAA* ShapeClonerCAA::FUN_00caa250(ShapeCAA* apDstShape, ShapeCinfoCAA* cinfo)
{
    AutoMemContextCAA kContext(0x10);
    ShapeCAA* src = m_pCollisionShape;
    if (!apDstShape)
    {
        apDstShape = new ShapeCAA;
    }
    apDstShape->m_v20 = src->m_v20;
    apDstShape->m_v30 = src->m_v30;
    apDstShape->m_v40 = src->m_v40;
    apDstShape->m_v50 = src->m_v50;
    apDstShape->m_v60 = src->m_v60;
    apDstShape->m_v70 = src->m_v70;
    apDstShape->m_v80 = src->m_v80;
    apDstShape->m_v90 = src->m_v90;
    apDstShape->m_fBC = src->m_fBC;
    apDstShape->m_fC4 = src->m_fC4;
    apDstShape->m_fC8 = src->m_fC8;
    float scale = cinfo->m_vScale;
    if (scale != 1.0f)
    {
        ::FUN_00cbd9e0(scale, (::FUN_00cbd9e0_cls *)(apDstShape));
    }
    ShapeChildCAA* pChildAtom = src->m_pChildAtom;
    if (pChildAtom)
    {
        hkReferencedObjectCAA* obj = pChildAtom->v0C();
        reinterpret_cast<::FUN_00cb8ac0_class *>((apDstShape))->SetReferencedObject((::RefObj *)(obj));
        reinterpret_cast<::hkReferencedObjectC905 *>((obj))->FUN_00c905b0();
        apDstShape->m_flagA2 = src->m_flagA2;
    }
    return ReleaseObject(apDstShape, cinfo);
}

namespace BatchAdd {



class hkAabb {
  public:
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
};

struct BroadPhaseCastCollector {
    void* m_kPointA;
    void* m_kPointB;
};

template <typename T>
class StackAllocatedArray : public hkArray<T> {
public:
    void* m_initialBuffer;

    __forceinline StackAllocatedArray(int capacity) throw() {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = 0x80000000;
        void* cur = hkMemoryRouter::getInstance().allocateStack((capacity * int(sizeof(T)) + 0x7f) & ~0x7f);
        this->m_data = static_cast<T*>(cur);
        this->m_iCapacityState = capacity | 0x80000000;
        this->m_initialBuffer = cur;
    }

    __forceinline void ClearAndRelease(hkMemoryRouter* tm) throw() {
        hkMemoryAllocator* mem = tm->m_heap;
        int cap = this->m_iCapacityState;
        this->m_iElementCount = 0;
        if ((cap & 0x80000000) == 0) {
            mem->bufFree(this->m_data, (cap & 0x3fffffff) * sizeof(T));
        }
        this->m_data = 0;
        this->m_iCapacityState = 0x80000000;
    }

    __forceinline ~StackAllocatedArray() throw() {
        void* const initialBuffer = this->m_initialBuffer;
        if (initialBuffer == this->m_data) {
            this->m_iElementCount = 0;
        }
        hkMemoryRouter::getInstance().deallocateStack(initialBuffer);
        this->ClearAndRelease(&hkMemoryRouter::getInstance());
    }

    __forceinline void setSizeUnchecked(int size) throw() {
        this->m_iElementCount = size;
    }
};

template <typename T>
__forceinline void hkConstructWithCopy(T* p, int n, const T& t) throw() {
    for (int i = 0; i < n; ++i) {
        p[i] = t;
    }
}

template <typename T>
struct hkArrayEx : public hkArray<T> {
    __forceinline void AddBack(const T& t) throw() {
        hkMemoryRouter* tm = &hkMemoryRouter::getInstance();
        if (this->m_iElementCount == (this->m_iCapacityState & 0x3fffffff)) {
            ::ResizeAudioStream((::AudioAllocator *)(tm->m_heap), (::AudioStream *)(void *)(this), sizeof(T));
        }
        hkConstructWithCopy(this->m_data + this->m_iElementCount, 1, t);
        this->m_iElementCount++;
    }
};

struct PhantomView : public ::hkpPhantom {
    unsigned int unk1C;
    unsigned int unk20;
    int m_kBroadPhaseHandle;
    virtual void* vfunc10() throw();
    virtual void slot14() throw();
    virtual void ComputeAabb(hkAabb* aabb) throw();
};



struct BroadPhase {
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0C() throw();
    virtual void v10() throw();
    virtual void v14() throw();
    virtual void UpdatePairs(const hkArray<void*>& handles, const hkArray<hkAabb>& aabbs, hkArray<BroadPhaseCastCollector>& pairs) throw();
};

struct BroadPhaseDispatcher {
};

struct PendingOp {
    unsigned char m_type;
    unsigned char m_uiStandInValue;
    unsigned char m_iValueAfterStandIn;
    unsigned char m_pAuxiliaryObject;
    hkpPhantom* const* m_kPhantoms;
    short m_iPhantomCount;
    short m_pad3;
};

struct WorldHelper : public hkpWorld {
    void FUN_00c91120() throw();

    void FUN_00c954e0(hkpPhantom* const* phantomBatch, int numPhantoms) throw();
};

// Adds a batch of phantoms to the world (queued as a pending op if locked), updates broad phase pairs, and passes them to FUN_00cf7080.
// @fnv 0x00c954e0
void WorldHelper::FUN_00c954e0(hkpPhantom* const* phantomBatch, int numPhantoms) throw() {
    if ((m_iCriticalOperationsLockCount + m_iCriticalOperationsLockCountForPhantoms) != 0) {
        PendingOp op;
        op.m_type = 0x0f;
        op.m_kPhantoms = phantomBatch;
        op.m_iPhantomCount = (short)numPhantoms;
        reinterpret_cast<::WorldWithPending *>(this)->FUN_00c91160();
        return;
    }

    m_iCriticalOperationsLockCount++;

    StackAllocatedArray<void*> handles(numPhantoms);
    StackAllocatedArray<hkAabb> aabbs(numPhantoms);
    aabbs.setSizeUnchecked(numPhantoms);
    handles.setSizeUnchecked(numPhantoms);

    for (int i = 0; i < numPhantoms; i++) {
        hkArrayEx<hkpPhantom*>* const phantoms = (hkArrayEx<hkpPhantom*>*)&m_kPhantoms;
        PhantomView* phantom = static_cast<PhantomView*>(phantomBatch[i]);
        if (!phantom->unk18) {
            phantom->unk18 = phantom->vfunc10();
        }
        phantom->m_pOwningWorld = this;
        handles.m_data[i] = &phantom->m_kBroadPhaseHandle;
        phantom->ComputeAabb(&aabbs.m_data[i]);
        reinterpret_cast<::FUN_00d07950_cls *>((phantom))->FUN_00d07950((*(const ::hkAabbD07950 *)(&aabbs.m_data[i])));
        reinterpret_cast<::FUN_00c90510_class *>((phantom))->FUN_00c90510();

        phantoms->AddBack(phantom);

        ::fnv_00d00780::NotifyPhantomAdded((::fnv_00d00780::World833 *)(::hkpWorld *)(this), (::fnv_00d00780::hkpPhantom *)(phantom));
        reinterpret_cast<::PhantomCls *>((phantom))->FUN_00d07b90();
    }

    StackAllocatedArray<BroadPhaseCastCollector> pairs(m_iBroadPhaseQuerySize);
    ((BroadPhase*)m_pJobSemaphore)->UpdatePairs(handles, aabbs, pairs);

    void* filter = ::collidableCollidableFilterOf(m_pCollisionFilter);
    reinterpret_cast<::DispatcherCF7080 *>((((BroadPhaseDispatcher*)m_pBroadPhaseDispatcher)))->FUN_00cf7080((::PairCF7080 *)(pairs.m_data), pairs.m_iElementCount, (const ::FilterCF7080 *)(filter));

    m_iCriticalOperationsLockCount--;
    if (m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations) {
        if (m_iPendingOperationCount != 0) {
            reinterpret_cast<::FUN_00c91120 *>(this)->ExecutePendingOperations();
        }
        if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount != 0) {
            reinterpret_cast<::FUN_00c91140_Class *>(this)->FUN_00c91140();
        }
    }
}

}

struct PendingCalls_00c97510 { void FUN_00c91120();  };




struct hkpEntity;
struct hkpSimulationIsland;
template <typename T>
inline void ConstructWithCopyC97510(T* pDst, int iCount, const T& kItem)
{
    for (int i = 0; i < iCount; ++i)
        pDst[i] = kItem;
}
template <typename T>
inline void PushBackC97510(::hkArray<T>& kArray, const T& kItem)
{
    hkMemoryRouter* pkMemory = &hkMemoryRouter::getInstance();
    if (kArray.m_iElementCount == (kArray.m_iCapacityState & 0x3fffffff))
        ::ResizeAudioStream((::AudioAllocator *)(pkMemory->m_heap), (::AudioStream *)(void *)(&kArray), sizeof(T));
    ConstructWithCopyC97510(kArray.m_data + kArray.m_iElementCount, 1, kItem);
    kArray.m_iElementCount++;
}

struct hkpWorldDecomp;

template <typename T>
struct InplaceArray4 : ::hkArray<T> {
    T m_kStorage[4];

    InplaceArray4() {
        this->m_data = m_kStorage;
        this->m_iElementCount = 0;
        this->m_iCapacityState = 0x80000004;
    }

    void ClearAndRelease() {
        hkMemoryAllocator* mem = hkMemoryRouter::getInstance().m_heap;
        int cap = this->m_iCapacityState;
        this->m_iElementCount = 0;
        if ((cap & 0x80000000) == 0) {
            mem->bufFree(this->m_data, (cap & 0x3fffffff) * sizeof(T));
        }
    }
};

template <typename T>
struct ResizableArray {
    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    int indexOf(T val) const {
        for (int i = 0; i < (int)m_iElementCount; ++i) {
            if (m_data[i] == val) return i;
        }
        return -1;
    }

    void removeAt(int index) {
        m_iElementCount--;
        m_data[index] = m_data[m_iElementCount];
    }
};

class hkpAction {
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void GetEntities(::hkArray<hkpEntity*>& entitiesOut);

    int unk04;
    ::hkpWorld* m_pOwningWorld;
    hkpSimulationIsland* m_pCurrentSimulationIsland;

};

struct hkpEntity {
    unsigned int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    unsigned int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    unsigned int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    unsigned int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    unsigned int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    unsigned int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    unsigned int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    unsigned int unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    unsigned int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    unsigned int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    unsigned int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    unsigned int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    unsigned int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    unsigned int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    unsigned int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    unsigned int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    unsigned int unk200, unk204;
    ResizableArray<hkpAction*> m_ppActions;
};

struct hkpSimulationIsland {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    ::hkpWorld* m_pOwningWorld;
    unsigned short unk1c;
    unsigned short unk1e;
    unsigned short unk20;
    unsigned short m_bSplitCheckRequested;

};


struct hkpWorldDecomp : ::hkpWorld {
    void FUN_00c97510(hkpAction* action);
};
// @fnv 0x00c97f50
void FUN_00c97f50_Class::DispatchOrQueue(void* p)
{
    if (m_iCriticalOperationsLockCount) {
        CA8B80Command cmd;
        cmd.m_bType = 0xb;
        cmd.m_p = p;
        reinterpret_cast<::WorldWithPending *>((((CA8B80Queue*)this)))->FUN_00c91160();
    } else {
        reinterpret_cast<::hkpWorldDecomp *>((((FUN_00c97510*)this)))->FUN_00c97510((::hkpAction *)(p));
    }
}
// If m_iCriticalOperationsLockCount is nonzero, queues a type-9 pending operation and returns false; otherwise runs helper calls on action and returns true.
// @fnv 0x00c97e80
C97E80Return C97E80World::FUN_00c97e80(C97E80Action* action) {
    if (m_iCriticalOperationsLockCount) {
        C97E80PendingOperation operation;
        operation.m_type = 9;
        operation.m_pAction = action;
        reinterpret_cast<::WorldWithPending *>((((C97E80PendingShell*)this)))->FUN_00c91160();
        C97E80Return r = {false};
        return r;
    }

    m_iCriticalOperationsLockCount = 1;
    if (action->getReferenceCount() == 1 &&
        ((C97E80Owner*)action->m_owner44)->m_pOwningWorld == this) {
        reinterpret_cast<::hkpWorldDecomp *>((((C97E80RemoveShell*)this)))->FUN_00c97510((::hkpAction *)(action->m_owner44));
    }
    reinterpret_cast<::FUN_00c90510_class *>((((RefObj*)action)))->FUN_00c90510();
    ::FUN_00cb3dd0((::CB3DD0World *)(::hkpWorld *)(this), (::CB3DD0Entity *)(action), 1);
    reinterpret_cast<::fnv_00cf3040::FUN_00cf3040_class *>((((C97E80ActionChangeShell*)action)))->RemoveReferenceFromSlots(this);
    reinterpret_cast<::hkReferencedObjectC905 *>((((C97E80ReleaseShell*)action)))->FUN_00c905b0();
    --m_iCriticalOperationsLockCount;
    if (m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations) {
        if (m_iPendingOperationCount) {
            reinterpret_cast<::FUN_00c91120 *>((((C97E80CleanupShell*)this)))->ExecutePendingOperations();
        }
        if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount) {
            reinterpret_cast<::FUN_00c91140_Class *>((((C97E80CleanupShell*)this)))->FUN_00c91140();
        }
    }
    C97E80Return r = {true};
    return r;
}


// Removes an hkpAction from its owning world, detaches it from its entities and island, then flushes pending operations if the critical lock count reaches zero.
// @fnv 0x00c97510
void hkpWorldDecomp::FUN_00c97510(hkpAction* action)
{
    reinterpret_cast<::FUN_00c90510_class *>((action))->FUN_00c90510();
    this->m_iCriticalOperationsLockCount++;
    ::NotifyActionRemoved((::WorldA *)(::hkpWorld *)(this), action);

    {
        InplaceArray4<hkpEntity*> entities;
        action->GetEntities(entities);

        for (int i = 0; i < entities.m_iElementCount; ++i)
        {
            hkpEntity* entity = entities.m_data[i];
            int idx = entity->m_ppActions.indexOf(action);
            entity->m_ppActions.removeAt(idx);
        }

        hkpSimulationIsland* island = action->m_pCurrentSimulationIsland;
        reinterpret_cast<::SaveBuffer *>((island))->RemoveEntry((::FUN_00d07130Arg *)(action));

        action->m_pOwningWorld = 0;
        reinterpret_cast<::hkReferencedObjectC905 *>((action))->FUN_00c905b0();

        ::hkpWorld* w = island->m_pOwningWorld;
        if (island->m_bSplitCheckRequested == 0xffff)
        {
            island->m_bSplitCheckRequested = (unsigned short)w->m_kDirtySimulationIslands.m_iElementCount;
            PushBackC97510(w->m_kDirtySimulationIslands, (void*)island);
        }

        entities.ClearAndRelease();
    }

    this->m_iCriticalOperationsLockCount--;
    if (this->m_iCriticalOperationsLockCount == 0 && !this->m_bBlockExecutingPendingOperations)
    {
        if (this->m_iPendingOperationCount != 0)
        {
            reinterpret_cast<::FUN_00c91120 *>((((PendingCalls_00c97510*)this)))->ExecutePendingOperations();
        }
        if (this->m_iPendingOperationQueueCount == 1 && this->m_iQueuedOperationCount != 0)
        {
            reinterpret_cast<::FUN_00c91140_Class *>((((PendingCalls_00c97510*)this)))->FUN_00c91140();
        }
    }

    reinterpret_cast<::hkReferencedObjectC905 *>((action))->FUN_00c905b0();
}

struct FUN_00c91210_Class {
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void* m_38;
    void* m_3c;
    void* m_40;
    void* m_44;
    void* m_48;
    void* m_4c;
    void* m_50;
    void* m_54;
    void* m_58;
    void* m_5c;
    void* m_60;
    void* m_64;
    void* m_68;
    void* m_6c;
    void* m_70;
    void* m_74;
    void* m_78;
    void* m_7c;
    void* m_80;
    void* m_84;
    void* m_88;
    void* m_8c;
    void* m_90;
    void* m_94;
    void* m_98;
    void* m_9c;
    void* m_a0;
    void* m_a4;
    void* m_a8;
    void* m_ac;
    void* m_b0;
    void* m_b4;
    CRITICAL_SECTION* m_b8;
    void FUN_00c91210(void*);
};
// @fnv 0x00c91210
void FUN_00c91210_Class::FUN_00c91210(void* cs)
{
    if (m_b8)
        LeaveCriticalSection(m_b8);
}

struct FUN_00c91180_Helper {
};
struct FUN_00c91b70_Class {
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* FUN_00c91b70(float f);
};
// Between FUN_00c91180 and FUN_00c91190, calls vtable entry 4 of the object at m_8 with f and returns its result.
// @fnv 0x00c91b70
void* FUN_00c91b70_Class::FUN_00c91b70(float afValue)
{
    reinterpret_cast<::FUN_00c91180_Class *>((((FUN_00c91180_Helper*)this)))->IncrementCounter();
    void* p = ((void* (*)(void*, float))(*((void***)m_8))[4])(m_8, afValue);
    reinterpret_cast<::FUN_00c91190_Class *>((((FUN_00c91180_Helper*)this)))->FUN_00c91190();
    return p;
}

namespace AdvanceTimeDetail {
struct WorldLock {
};

struct Simulation {
    virtual ~Simulation();
    virtual const hkClass* GetClassType() const;
    virtual void CalcContentStatistics(void*, const hkClass*) const;
    virtual int SimulateForDeltaTime(float);
    virtual int integrate(float);
    virtual int collide();
    virtual int AdvanceSimulationTime();
};
}

struct WorldAdvanceEntry : hkpWorld {
    int FUN_00c91bd0();
};
// @fnv 0x00c6ae70
bool bhkWorld::StepSimulation() {
    DAT_012677c4 = 0.0f;
    DAT_012677a0 = 1;
    DAT_012677c8 = 0;
    bool result = false;

    if (this->unk30 > 0) {
        if (!DAT_012677a2) {
            if (this->unk30 >= 0xbb8) {
                this->unk30 = 0xbb8;
            }
            unsigned int val = this->unk30;
            unsigned int count = DAT_011afe80;
            if (val < count) {
                count = val;
            }
            unsigned int remaining = val - count;
            reinterpret_cast<::S_Owner *>((this))->FUN_00c674d0((::S_Item **)(void *)(&this->unk2C[remaining]), count);
            this->unk30 = remaining;
            DAT_012677a2 = 1;
        }
        reinterpret_cast<::FUN_00c67850_Class *>((this))->ProcessConstraints();
        reinterpret_cast<::fnv_00c6aac0::FUN_00c6aac0_Owner *>((this))->FUN_00c6aac0();
    }

    if (this->unk15 != 0 && DAT_011afe68 > 0.0f) {
        WorldExt* world = this->GetHkpWorld();
        bool isMultithreaded = (world->m_iMaxEntriesPerNarrowphaseToiTask == 3);
        if (isMultithreaded) {
            reinterpret_cast<::FUN_00cbf6b0_class *>((DAT_012677d0))->EnsureObjectsCreated(DAT_01267b2c);
        }
        DAT_012677ac = DAT_011ac3a0 * DAT_01267b38;
        reinterpret_cast<::Shell_c6a540 *>((this))->FUN_00c6a540(DAT_011afe64);
        reinterpret_cast<::C66A00This *>((this))->FUN_00c66a00();

        this->GetHkpWorld();
        if (world->m_iCriticalOperationsLockCount == 0 && world->m_bBlockExecutingPendingOperations == 0) {
            if (world->m_iPendingOperationCount != 0) {
                reinterpret_cast<::FUN_00c91120 *>((world))->ExecutePendingOperations();
            }
            if (world->m_iPendingOperationQueueCount == 1 && world->m_iQueuedOperationCount != 0) {
                reinterpret_cast<::FUN_00c91140_Class *>((world))->FUN_00c91140();
            }
        }

        this->GetHkpWorld();
        reinterpret_cast<::CpuObject *>((world))->FUN_00c91020();
        ::FUN_00c91040((void *)(world), DAT_011afe64, {});
        reinterpret_cast<::WorldAdvanceEntry *>((world))->FUN_00c91bd0();
        while (!world->FUN_00c91060()) {
            reinterpret_cast<::fnv_00c91030::CpuObject *>((world))->FUN_00c91030();
            if (!isMultithreaded) {
                reinterpret_cast<::C91World *>((world))->FUN_00c91b10(DAT_012677ac);
            } else {
                reinterpret_cast<::FUN_00c93ae0_class *>((world))->FUN_00c93ae0(DAT_012677d0->unk14, DAT_012677d0->unk18, DAT_012677ac);
            }
        }

        reinterpret_cast<::FUN_00c66e20_Class *>((this))->FUN_00c66e20(DAT_011afe68);
        reinterpret_cast<::fnv_00c68de0::FNV_C68DE0_OWNER *>((this))->FUN_00c68de0();
        result = true;
    }

    if (this->unk50 > 0) {
        reinterpret_cast<::FUN_00c67aa0_Class *>((this))->FlushEntries();
    }

    if (DAT_012677cd != 0) {
        reinterpret_cast<::Root *>((this))->SetProcessEnabled(1);
        DAT_012677cd = 0;
    }

    DAT_012677a0 = 0;
    return result;
}

// Calls FUN_00c91180, then a virtual method on m_pSimulation, then FUN_00c91190, and returns the virtual method's result.
// @fnv 0x00c91bd0
int WorldAdvanceEntry::FUN_00c91bd0()
{
    reinterpret_cast<::FUN_00c91180_Class *>((reinterpret_cast<AdvanceTimeDetail::WorldLock*>(this)))->IncrementCounter();
    int result = reinterpret_cast<AdvanceTimeDetail::Simulation*>(m_pSimulation)->AdvanceSimulationTime();
    reinterpret_cast<::FUN_00c91190_Class *>((reinterpret_cast<AdvanceTimeDetail::WorldLock*>(this)))->FUN_00c91190();
    return result;
}

// Moved from hkpworld_gs_nogs_variant.cpp (VEGAS-15).
#include "fnv/symbols_00c98000.h"
void FUN_00c90e40(void* self, int arg);
void FUN_00c982a0(char* pFlag, int a2, int a3, int a4, int a5, int a6);
void FUN_00c982b0(unsigned char* flag, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
void* __cdecl FUN_00d06f80(void* array, unsigned int bytes);
extern void* FUN_00ec61c0(void* dst, int value, unsigned int size);
static void InvokeOnAllOwners(FUN_00c928c0_Context* ctx, zzVal_c92860 value);
void zz_call_c92860(void);
void __cdecl FUN_00d06cb0(void* apvArray, int iSizeElem);
void __cdecl ReleaseSharedObject(hkpWorldD0AD* pkWorld);

struct FUN_00c98820_ArrayObject
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24(void* first, void* second, int color, hkUlong id, int tag);
};


// @fnv 0x00c98820
void FUN_00c98820_Class::FUN_00c98820(void* first, void* second, int third, hkUlong fourth, int fifth)
{
    __m128 sum = _mm_add_ps(*(__m128*)second, *(__m128*)first);

    for (int index = 0; index < m_0c; ++index)
    {
        FUN_00c98820_ArrayObject* object = m_08[index];
        object->vf24(first, &sum, third, fourth, fifth);
    }
}

// Moved from hkpworld_rtm_variant.cpp (VEGAS-15).
#include <new>
#include "fnv/decl/Big.h"
#include "fnv/decl/CC0280Writer.h"
#include "fnv/decl/FUN_009ba5f0_shell.h"
#include "fnv/decl/FUN_00c90e60_cls.h"
#include "fnv/decl/FUN_00cb1600.h"
#include "fnv/decl/FUN_00cc00e0.h"
#include "fnv/decl/FUN_00cc02d0_cls.h"
#include "fnv/decl/FUN_00cf6f90.h"
#include "fnv/decl/FUN_00cf75c0.h"
#include "fnv/decl/FUN_00cf87c0.h"
#include "fnv/decl/FUN_00cfc030_cls.h"
#include "fnv/decl/FUN_00d02c80.h"
#include "fnv/decl/FUN_00d0b250.h"
#include "fnv/decl/FUN_00d107d0_t.h"
#include "fnv/decl/ListenerMgrD0A.h"
#include "fnv/decl/S00ca8c90_Body.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/decl/Stepper.h"
#include "fnv/decl/bpb__hkpBroadPhaseBorder.h"
#include "fnv/decl/fnv_00d08cf0__FUN_00d08cf0.h"
#include "fnv/symbols_00cab000.h"
#include "fnv/symbols_00d01000.h"
#include "fnv/symbols_00d0b000.h"
#include "fnv/symbols_00d10000.h"
#include "fnv/symbols_01013000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01019000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01031000.h"
static void SyncOverlap(OverlapPhantom* phantom, OverlapCollidable* other, OverlapContext* context);
void invokeOverlap();
class hkWorldCFD4;
static void RegisterContactMgrFactories(CFB240Dispatcher* dispatcher, void* world);
void c912e0_caller(CFB240Dispatcher* d, void* w);
static void FUN_00c92950(PhantomWorld* world, PhantomSink* out);
void invokePhantomCopy();
void probeOverlapCaller();
static BoolResult AddBodiesToSystem(Context_s* a2, ...);
void retryCaller();
static unsigned char FUN_00c927c0(MatchWorld* world, FUN_00d065e0* system);
void CallMatchSystem();
void FUN_00c982d0(unsigned char* out, int a2, int a3);
struct hkpWorldQ;
static __forceinline void doShift(Sbp_World* self,const __m128& rawShift, __m128& rawEffective, int update);


class C91Simulation {
public:
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual int SimulateForDeltaTime(float delta);
};


// @fnv 0x00c91b10
int C91World::FUN_00c91b10(float delta)
{
    reinterpret_cast<::FUN_00c91180_Class *>(this)->IncrementCounter();
    ::FUN_00d01d20((::Src *)(void *)(this));
    int result = reinterpret_cast<C91Simulation*>(m_pSimulation)->SimulateForDeltaTime(delta);
    if (m_pKdTreeManager) {
        if (m_bUseKdTree)
            reinterpret_cast<::FUN_00c91270_cls *>(this)->FUN_00c91270(0);
        else
            reinterpret_cast<FUN_00c91250_Class*>(this)->FUN_00c91250();
    }
    reinterpret_cast<FUN_00c91190_Class*>(this)->FUN_00c91190();
    return result;
}

struct StepSimulationEntryC91C {
};

struct TreeUpdateEntryC91C {
};


// @fnv 0x00c91c00
int WorldFinishEntryC91C::FUN_00c91c00(void* queue, void* pool)
{
    int result = reinterpret_cast<::Stepper *>((reinterpret_cast<StepSimulationEntryC91C*>(m_pSimulation)))->FUN_00d03290((::Job *)(queue), (::Jobs *)(pool));
    if (result != 0)
        return result;
    if (m_pKdTreeManager == 0)
        return 0;
    if (m_bUseKdTree != 0) {
        reinterpret_cast<::FUN_00c91270_cls *>((reinterpret_cast<TreeUpdateEntryC91C*>(this)))->FUN_00c91270(queue);
        return 0;
    }
    reinterpret_cast<FUN_00c91250_Class*>(this)->FUN_00c91250();
    return 0;
}



__declspec(align(16)) struct V4 {
    union { __m128 q; float f[4]; };
    V4() {}
    V4(__m128 v) {q=v;}
    void cross(const V4& a, const V4& b);
    void normalize();
    void plus(const V4& a,const V4& b) {q=_mm_add_ps(a.q,b.q);}
    void minus(const V4& a,const V4& b) {q=_mm_sub_ps(a.q,b.q);}
    void scaled(__m128 s, const V4& v) { q=_mm_mul_ps(_mm_shuffle_ps(s,s,0),v.q); }
    void add(const V4& v) { q=_mm_add_ps(q,v.q); }
    void absolute(const V4& a) { q = _mm_and_ps(a.q, ::DAT_01017d10); }
    void scale(__m128 scalar) { q = _mm_mul_ps(_mm_shuffle_ps(scalar, scalar, 0), q); }
};

static __forceinline __m128 vload(const V4& v)
{
    return v.q;
}

static __forceinline void vstore(V4& v, __m128 q)
{
    v.q = q;
}

__forceinline void V4::cross(const V4& a, const V4& b)
{
    __m128 left = _mm_mul_ps(_mm_shuffle_ps(a.q,a.q,0xC9), _mm_shuffle_ps(b.q,b.q,0xD2));
    __m128 right = _mm_mul_ps(_mm_shuffle_ps(a.q,a.q,0xD2), _mm_shuffle_ps(b.q,b.q,0xC9));
    q = _mm_sub_ps(left,right);
}
__forceinline void V4::normalize()
{
    __m128 sq = _mm_mul_ps(q,q);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(sq,sq,0x55),sq);
    sum = _mm_add_ss(_mm_shuffle_ps(sq,sq,0xAA),sum);
    __m128 r = _mm_rsqrt_ss(sum);
    q = _mm_mul_ps(q,_mm_shuffle_ps(r,r,0));
}

struct PlaneDraw {
    void FUN_00c98e60(const V4& plane, const V4& offset, float scale, int color, hkUlong id, int tag) throw();
};

struct TierQuotientCtor { double denominator; float threshold; __forceinline float value() const { return denominator/threshold; } };
extern "C" void __debugbreak();
struct WorldCtor;
struct ObjectCtor;
union WordCtor { int i; float f; ObjectCtor* p; void* raw; };
struct ObjectVtableCtor {

    void (* vf00)(ObjectCtor*);
    void (* vf04)(ObjectCtor*);
    void (* vf08)(ObjectCtor*);
    void (* vf0c)(ObjectCtor*, WorldCtor*);
    void (* vf10)(ObjectCtor*);
    void (* vf14)(ObjectCtor*);
    void (* vf18)(ObjectCtor*);
    void (* vf1c)(ObjectCtor*);
    void (* vf20)(ObjectCtor*);
    void (* vf24)(ObjectCtor*);
    void (* vf28)(ObjectCtor*);
    void (* vf2c)(ObjectCtor*);
    void (* vf30)(ObjectCtor*);
    void (* vf34)(ObjectCtor*);
    void (* vf38)(ObjectCtor*);
    void (* vf3c)(ObjectCtor*);
    void (* vf40)(ObjectCtor*);
    void (* vf44)(ObjectCtor*);
    void (* vf48)(ObjectCtor*);
    void (* vf4c)(ObjectCtor*);
    void (* vf50)(ObjectCtor*);
    void (* vf54)(ObjectCtor*);
    void (* vf58)(ObjectCtor*);
    void (* vf5c)(ObjectCtor*);
    void (* vf60)(ObjectCtor*);
    void (* vf64)(ObjectCtor*);
    void (* vf68)(ObjectCtor*);
    void (* vf6c)(ObjectCtor*);
    void (* vf70)(ObjectCtor*,::hkQuadReal*,::hkQuadReal*,::hkQuadReal*);
};
struct ObjectCtor {
    ObjectVtableCtor* vtable;
    unsigned short size;
    short references;

    WordCtor unk08;
    WordCtor unk0c;
    WordCtor unk10;
    WordCtor unk14;
    WordCtor unk18;
    WordCtor unk1c;
    union { WordCtor unk20; struct { unsigned short id20,id22; }; };
    union { WordCtor unk24; struct { unsigned short id24; unsigned char flags26,flags27; }; };
    WordCtor unk28;
    WordCtor unk2c;
    WordCtor unk30;
    WordCtor unk34;
    WordCtor unk38;
    WordCtor unk3c;
    WordCtor unk40;
    WordCtor unk44;
    WordCtor unk48;
    WordCtor unk4c;
    WordCtor unk50;
    WordCtor unk54;
    WordCtor unk58;
    WordCtor unk5c;
    WordCtor unk60;
    WordCtor unk64;
    WordCtor unk68;
    union { WordCtor unk6c; struct { unsigned char flag6c,flag6d,flag6e,flag6f; }; };
    WordCtor unk70;
    WordCtor unk74;
    WordCtor unk78;
    WordCtor unk7c;
    WordCtor unk80;
    WordCtor unk84;
    WordCtor unk88;
    WordCtor unk8c;
    WordCtor unk90;
    WordCtor unk94;
    WordCtor unk98;
    WordCtor unk9c;
    WordCtor unka0;
    WordCtor unka4;
    WordCtor unka8;
    WordCtor unkac;
    WordCtor unkb0;
    WordCtor unkb4;
    WordCtor unkb8;
    WordCtor unkbc;
    WordCtor unkc0;
    WordCtor unkc4;
    WordCtor unkc8;
    WordCtor unkcc;
    WordCtor unkd0;
    WordCtor unkd4;
    WordCtor unkd8;
    WordCtor unkdc;
    WordCtor unke0;
    WordCtor unke4;
    WordCtor unke8;
    WordCtor unkec;
    WordCtor unkf0;
    WordCtor unkf4;
    WordCtor unkf8;
    WordCtor unkfc;
    WordCtor unk100;
    WordCtor unk104;
    WordCtor unk108;
    WordCtor unk10c;
    WordCtor unk110;
    WordCtor unk114;
    WordCtor unk118;
    WordCtor unk11c;
    WordCtor unk120;
    ObjectCtor* FUN_00cfd450(WorldCtor*);
    ObjectCtor* FUN_00cbfba0();
    ObjectCtor* FUN_00d0d020(WorldCtor*);
    ObjectCtor* FUN_00d07830(WorldCtor*);
    ObjectCtor* FUN_00cfca20(WorldCtor*);
    void SetContactMgrFactory(ObjectCtor*,int);
};
static __forceinline void* worldAlloc(int size) {
    return hkMemoryRouter::getInstance().heap().blockAlloc(size);
}
template<class T> static __forceinline T* allocObject(int size) {
    T* obj=static_cast<T*>(worldAlloc(size));
    obj->size=(unsigned short)size;
    return obj;
}
static __forceinline void release(ObjectCtor* p) { reinterpret_cast<::hkReferencedObjectC905 *>((((::FUN_00d1df70*)p)))->FUN_00c905b0(); }

struct RawArrayCtor {
    ObjectCtor** data; int count; unsigned capacity;
    __forceinline void push(ObjectCtor* value) {
        hkMemoryRouter* router=&hkMemoryRouter::getInstance();
        if(count==(capacity&0x3fffffffu)) ::ResizeAudioStream((::AudioAllocator *)(router->m_heap),(::AudioStream *)(void *)(this),4);
        ObjectCtor** slot=data+count; for(int i=0;i<1;++i) slot[i]=value;
        ++count;
    }
};
struct RangeCtor { float start,end,delta,inverse; };
struct DeactivationCtor { float inverseThreshold, inverseVelocity, damping, time; float distanceSquared, radiusSquared; unsigned short distanceHalf, radiusHalf; };
struct SolverCtor {
    float unk00,unk04,unk08,unk0c;
    ::hkQuadReal unk10,unk20,unk30,unk40;
    float unk50,unk54,unk58,unk5c,unk60;
    DeactivationCtor tiers[6];
    float unk10c,unk110;
    int unk114,unk118;
    float unk11c,unk120;
    unsigned char unk124,unk125,unk126,unk127;
    float unk128;
    int unk12c;
    __forceinline DeactivationCtor& configureTier(int tierIndex,float threshold,float speed,float magnitude,float gravityScale);
};
struct ManifoldCtor { float tolerance; int count,unk08,unk0c; };
struct CollisionInputCtor {
    ObjectCtor* dispatcher;
    int unk04;
    float tolerance;
    ObjectCtor* filter;
    ObjectCtor* convexFilter;
    int unk14,unk18,unk1c;
    ::hkQuadReal offset,extent,scale;
    RangeCtor range;
    void* agents;
    int unk64;
    RangeCtor* time;
    unsigned char flag6c,flag6d;
    unsigned short unk6e;
    ManifoldCtor* manifold;
    int unk74,unk78,unk7c;
    static void* operator new(size_t n) { return worldAlloc(n); }
    CollisionInputCtor() { unk64=0;unk04=0; }
};

struct WorldInfoCtor {

    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ::hkQuadReal gravity;
    int querySize;
    float solverFriction;
    signed char borderBehavior;
    unsigned char postponeBorder;
    unsigned char unk2a;
    unsigned char unk2b;
    int unk2c;
    ::hkQuadReal minimum;
    ::hkQuadReal maximum;
    unsigned char borderEnabled;
    unsigned char borderAlternate;
    signed char borderMode;
    unsigned char borderFlag;
    float tolerance;
    ObjectCtor* filter;
    ObjectCtor* convexFilter;
    float config60;
    int toiQueueSize;
    float config68;
    ObjectCtor* watchdog;
    int markers;
    signed char generation;
    unsigned char quality;
    unsigned char unk76;
    unsigned char unk77;
    float solverTau;
    float solverDamping;
    int iterations;
    int microsteps;
    float damping;
    unsigned char flag8c;
    unsigned char unk8d;
    unsigned char unk8e;
    unsigned char unk8f;
    float snap;
    float snapOther;
    unsigned char weld;
    unsigned char flag99;
    unsigned char unk9a;
    unsigned char unk9b;
    float manifoldTolerance;
    int manifoldCount;
    unsigned char flagA4;
    unsigned char flagA5;
    unsigned char flagA6;
    unsigned char activate;
    float referenceDistance;
    float rotateNormal;
    int sectors;
    unsigned char threadToi;
    unsigned char unkb5;
    unsigned char unkb6;
    unsigned char unkb7;
    int toiEntries;
    int toiPairs;
    float toi0;
    float toi1;
    float toi2;
    float toi3;
    unsigned char deactivate;
    signed char simulationType;
    unsigned char wantIslands;
    unsigned char unkd3;
    int minIsland;
    unsigned char singleActions;
    unsigned char unkd9;
    unsigned char unkda;
    unsigned char unkdb;
    float simulationValue;
    unsigned char flagE0;
    unsigned char unke1;
    unsigned char unke2;
    unsigned char unke3;
};
struct WorldCtor {
    void* vtable;
    unsigned short size;
    short references;
    ObjectCtor* simulation;
    int unk0c;
    ::hkQuadReal gravity;
    ObjectCtor* fixedIsland;
    ObjectCtor* fixedBody;
    RawArrayCtor active, inactive, dirty;
    ObjectCtor* kdTree;
    ObjectCtor* watchdog;
    unsigned char assertMemory,unk55,unk56,unk57;
    ObjectCtor* broadphase;
    ObjectCtor* border;
    unsigned char autoTree,unk61,unk62,unk63;
    ObjectCtor* broadphaseDispatcher;
    ObjectCtor* phantomListener;
    ObjectCtor* entityListener;
    ObjectCtor* borderListener;
    ObjectCtor* jobs;
    CollisionInputCtor* input;
    ObjectCtor* filter;
    ObjectCtor* dispatcher;
    ObjectCtor* convexFilter;
    ObjectCtor* pending;
    int pendingCount,bodyCount,criticalCount,phantomCount;
    unsigned char blockOperations, allowOperations;
    unsigned short unk9e;
    int pendingQueues,queueCount;
    hkMultiThreadCheck threadCheck;
    unsigned char singleActions, separateIntegration;
    unsigned short unkB2;
    int minIsland;
    ObjectCtor* modifyLock;
    int locked;
    ObjectCtor* dirtyLock;
    ObjectCtor* propertyLock;
    unsigned char wantIslands,unkC9,unkCA,unkCB;
    float snapConvex,snapConcave;
    unsigned char weld,deactivate,activate,unkD7;
    float referenceDistance,rotateNormal;
    int sectors;
    unsigned char threadToi,unkE5,unkE6,unkE7;
    int toiEntries,toiPairs,simulationType;
    float toi0,toi1,toi2,toi3;
    int lastEntity,lastIsland,lastConstraint;
    RawArrayCtor phantoms,actions,entities,phantomCallbacks,constraints,deletionCallbacks,
                 islandCallbacks,postSimulation,postIntegrate,postCollide,islandIntegrate,
                 islandCollide,contacts,impulseLimits;
    ObjectCtor* violated;
    ObjectCtor* broadphaseBorder;
    ObjectCtor* callbackUtil;
    ObjectCtor* destruction;
    int unk1c8,unk1cc;
    RangeCtor time;
    SolverCtor solver;
    ::hkQuadReal minimum,maximum;
    int markers,toiQueueSize,querySize,updateSize;
    unsigned char generation,unk341,unk342,unk343;
    WorldCtor* FUN_00c95a80(WorldInfoCtor*,int);
};
namespace WorldCtorFactorySetup {
static void RegisterContactMgrFactories(::CFB240Dispatcher* dispatcher, WorldCtor* world)
{
    ::FUN_00cfd450* first = new ::FUN_00cfd450(world);
    ::FUN_00cfca20* second = new ::FUN_00cfca20(world);
    ::FactoryThreeC912* third = new ::FactoryThreeC912;
    dispatcher->SetContactMgrFactory(first, 1);
    dispatcher->SetContactMgrFactory(second, 2);
    dispatcher->SetContactMgrFactory(third, 3);
    reinterpret_cast<::hkReferencedObjectC905 *>((((::FUN_00d1df70*)first)))->FUN_00c905b0();
    reinterpret_cast<::hkReferencedObjectC905 *>((((::FUN_00d1df70*)second)))->FUN_00c905b0();
    reinterpret_cast<::hkReferencedObjectC905 *>((((::FUN_00d1df70*)third)))->FUN_00c905b0();
}
}
struct StreamCtor {
    int unk00,unk04,unk08,unk0c;
};
struct ErrorCtor {
    virtual void f0(); virtual void f1(); virtual void f2();
    virtual int report(int,unsigned,const char*,const char*,int);
};
extern unsigned char DAT_012681dc;
extern void UpdateSkyEntries(float,float);
extern ObjectCtor* (__cdecl* DAT_011b37a0)(::hkQuadReal*,::hkQuadReal*,int);

extern int DAT_010c6714;
extern int DAT_010c63f0;
extern int DAT_010c63e0;
extern int DAT_010c6410;
extern int DAT_010c6400;
extern int DAT_010c646c;
extern int DAT_010c6460;
extern int DAT_010c644c;
extern int DAT_010c6440;
extern int DAT_010c6434;
extern int DAT_010c63cc;
extern float DAT_010c6840;
extern float DAT_010c6844;
extern float DAT_010c6848;
extern float DAT_010c684c;
extern float DAT_010c6850;
extern float DAT_010c6860;
extern float DAT_010c42e8;
extern float DAT_0102d934;
struct BodyInfoCtor {

    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    float unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    unsigned char motionType,unkb5,unkb6,unkb7;
    int unkb8;
    int unkbc;
};
struct BuildConfigCtor {
    float magnitude,tolerance,config68,config60,toi0,toi1,toi2,toi3;
    unsigned short one,three,four,five;
    unsigned char multithread,quality,contacts,weld;
};
static __forceinline float length3(::hkQuadReal v) {
    ::hkQuadReal square=_mm_mul_ps(v,v);
    ::hkQuadReal y=_mm_shuffle_ps(square,square,0x55);
    ::hkQuadReal z=_mm_shuffle_ps(square,square,0xaa);
    y=_mm_add_ss(y,square);
    z=_mm_add_ss(z,y);
    z=_mm_sqrt_ss(z);
    float result;
    _mm_store_ss(&result,z);
    return result;
}
static __forceinline void initArray(RawArrayCtor& a) {
    a.capacity=0x80000000u; a.data=0; a.count=0;
}
static __forceinline void setRange(RangeCtor& r,double a,double b) {
 r.start=a; r.end=b; float d=b-a; r.delta=d; r.inverse=d==0.0f ? 0.0f : 1.0f/d;
}

struct DispatcherCtor {
    int unk0000,unk0004,unk0008,unk000c,unk0010,unk0014,unk0018,unk001c,unk0020,unk0024,unk0028,unk002c,unk0030,unk0034,unk0038,unk003c;
    int unk0040,unk0044,unk0048,unk004c,unk0050,unk0054,unk0058,unk005c,unk0060,unk0064,unk0068,unk006c,unk0070,unk0074,unk0078,unk007c;
    int unk0080,unk0084,unk0088,unk008c,unk0090,unk0094,unk0098,unk009c,unk00a0,unk00a4,unk00a8,unk00ac,unk00b0,unk00b4,unk00b8,unk00bc;
    int unk00c0,unk00c4,unk00c8,unk00cc,unk00d0,unk00d4,unk00d8,unk00dc,unk00e0,unk00e4,unk00e8,unk00ec,unk00f0,unk00f4,unk00f8,unk00fc;
    int unk0100,unk0104,unk0108,unk010c,unk0110,unk0114,unk0118,unk011c,unk0120,unk0124,unk0128,unk012c,unk0130,unk0134,unk0138,unk013c;
    int unk0140,unk0144,unk0148,unk014c,unk0150,unk0154,unk0158,unk015c,unk0160,unk0164,unk0168,unk016c,unk0170,unk0174,unk0178,unk017c;
    int unk0180,unk0184,unk0188,unk018c,unk0190,unk0194,unk0198,unk019c,unk01a0,unk01a4,unk01a8,unk01ac,unk01b0,unk01b4,unk01b8,unk01bc;
    int unk01c0,unk01c4,unk01c8,unk01cc,unk01d0,unk01d4,unk01d8,unk01dc,unk01e0,unk01e4,unk01e8,unk01ec,unk01f0,unk01f4,unk01f8,unk01fc;
    int unk0200,unk0204,unk0208,unk020c,unk0210,unk0214,unk0218,unk021c,unk0220,unk0224,unk0228,unk022c,unk0230,unk0234,unk0238,unk023c;
    int unk0240,unk0244,unk0248,unk024c,unk0250,unk0254,unk0258,unk025c,unk0260,unk0264,unk0268,unk026c,unk0270,unk0274,unk0278,unk027c;
    int unk0280,unk0284,unk0288,unk028c,unk0290,unk0294,unk0298,unk029c,unk02a0,unk02a4,unk02a8,unk02ac,unk02b0,unk02b4,unk02b8,unk02bc;
    int unk02c0,unk02c4,unk02c8,unk02cc,unk02d0,unk02d4,unk02d8,unk02dc,unk02e0,unk02e4,unk02e8,unk02ec,unk02f0,unk02f4,unk02f8,unk02fc;
    int unk0300,unk0304,unk0308,unk030c,unk0310,unk0314,unk0318,unk031c,unk0320,unk0324,unk0328,unk032c,unk0330,unk0334,unk0338,unk033c;
    int unk0340,unk0344,unk0348,unk034c,unk0350,unk0354,unk0358,unk035c,unk0360,unk0364,unk0368,unk036c,unk0370,unk0374,unk0378,unk037c;
    int unk0380,unk0384,unk0388,unk038c,unk0390,unk0394,unk0398,unk039c,unk03a0,unk03a4,unk03a8,unk03ac,unk03b0,unk03b4,unk03b8,unk03bc;
    int unk03c0,unk03c4,unk03c8,unk03cc,unk03d0,unk03d4,unk03d8,unk03dc,unk03e0,unk03e4,unk03e8,unk03ec,unk03f0,unk03f4,unk03f8,unk03fc;
    int unk0400,unk0404,unk0408,unk040c,unk0410,unk0414,unk0418,unk041c,unk0420,unk0424,unk0428,unk042c,unk0430,unk0434,unk0438,unk043c;
    int unk0440,unk0444,unk0448,unk044c,unk0450,unk0454,unk0458,unk045c,unk0460,unk0464,unk0468,unk046c,unk0470,unk0474,unk0478,unk047c;
    int unk0480,unk0484,unk0488,unk048c,unk0490,unk0494,unk0498,unk049c,unk04a0,unk04a4,unk04a8,unk04ac,unk04b0,unk04b4,unk04b8,unk04bc;
    int unk04c0,unk04c4,unk04c8,unk04cc,unk04d0,unk04d4,unk04d8,unk04dc,unk04e0,unk04e4,unk04e8,unk04ec,unk04f0,unk04f4,unk04f8,unk04fc;
    int unk0500,unk0504,unk0508,unk050c,unk0510,unk0514,unk0518,unk051c,unk0520,unk0524,unk0528,unk052c,unk0530,unk0534,unk0538,unk053c;
    int unk0540,unk0544,unk0548,unk054c,unk0550,unk0554,unk0558,unk055c,unk0560,unk0564,unk0568,unk056c,unk0570,unk0574,unk0578,unk057c;
    int unk0580,unk0584,unk0588,unk058c,unk0590,unk0594,unk0598,unk059c,unk05a0,unk05a4,unk05a8,unk05ac,unk05b0,unk05b4,unk05b8,unk05bc;
    int unk05c0,unk05c4,unk05c8,unk05cc,unk05d0,unk05d4,unk05d8,unk05dc,unk05e0,unk05e4,unk05e8,unk05ec,unk05f0,unk05f4,unk05f8,unk05fc;
    int unk0600,unk0604,unk0608,unk060c,unk0610,unk0614,unk0618,unk061c,unk0620,unk0624,unk0628,unk062c,unk0630,unk0634,unk0638,unk063c;
    int unk0640,unk0644,unk0648,unk064c,unk0650,unk0654,unk0658,unk065c,unk0660,unk0664,unk0668,unk066c,unk0670,unk0674,unk0678,unk067c;
    int unk0680,unk0684,unk0688,unk068c,unk0690,unk0694,unk0698,unk069c,unk06a0,unk06a4,unk06a8,unk06ac,unk06b0,unk06b4,unk06b8,unk06bc;
    int unk06c0,unk06c4,unk06c8,unk06cc,unk06d0,unk06d4,unk06d8,unk06dc,unk06e0,unk06e4,unk06e8,unk06ec,unk06f0,unk06f4,unk06f8,unk06fc;
    int unk0700,unk0704,unk0708,unk070c,unk0710,unk0714,unk0718,unk071c,unk0720,unk0724,unk0728,unk072c,unk0730,unk0734,unk0738,unk073c;
    int unk0740,unk0744,unk0748,unk074c,unk0750,unk0754,unk0758,unk075c,unk0760,unk0764,unk0768,unk076c,unk0770,unk0774,unk0778,unk077c;
    int unk0780,unk0784,unk0788,unk078c,unk0790,unk0794,unk0798,unk079c,unk07a0,unk07a4,unk07a8,unk07ac,unk07b0,unk07b4,unk07b8,unk07bc;
    int unk07c0,unk07c4,unk07c8,unk07cc,unk07d0,unk07d4,unk07d8,unk07dc,unk07e0,unk07e4,unk07e8,unk07ec,unk07f0,unk07f4,unk07f8,unk07fc;
    int unk0800,unk0804,unk0808,unk080c,unk0810,unk0814,unk0818,unk081c,unk0820,unk0824,unk0828,unk082c,unk0830,unk0834,unk0838,unk083c;
    int unk0840,unk0844,unk0848,unk084c,unk0850,unk0854,unk0858,unk085c,unk0860,unk0864,unk0868,unk086c,unk0870,unk0874,unk0878,unk087c;
    int unk0880,unk0884,unk0888,unk088c,unk0890,unk0894,unk0898,unk089c,unk08a0,unk08a4,unk08a8,unk08ac,unk08b0,unk08b4,unk08b8,unk08bc;
    int unk08c0,unk08c4,unk08c8,unk08cc,unk08d0,unk08d4,unk08d8,unk08dc,unk08e0,unk08e4,unk08e8,unk08ec,unk08f0,unk08f4,unk08f8,unk08fc;
    int unk0900,unk0904,unk0908,unk090c,unk0910,unk0914,unk0918,unk091c,unk0920,unk0924,unk0928,unk092c,unk0930,unk0934,unk0938,unk093c;
    int unk0940,unk0944,unk0948,unk094c,unk0950,unk0954,unk0958,unk095c,unk0960,unk0964,unk0968,unk096c,unk0970,unk0974,unk0978,unk097c;
    int unk0980,unk0984,unk0988,unk098c,unk0990,unk0994,unk0998,unk099c,unk09a0,unk09a4,unk09a8,unk09ac,unk09b0,unk09b4,unk09b8,unk09bc;
    int unk09c0,unk09c4,unk09c8,unk09cc,unk09d0,unk09d4,unk09d8,unk09dc,unk09e0,unk09e4,unk09e8,unk09ec,unk09f0,unk09f4,unk09f8,unk09fc;
    int unk0a00,unk0a04,unk0a08,unk0a0c,unk0a10,unk0a14,unk0a18,unk0a1c,unk0a20,unk0a24,unk0a28,unk0a2c,unk0a30,unk0a34,unk0a38,unk0a3c;
    int unk0a40,unk0a44,unk0a48,unk0a4c,unk0a50,unk0a54,unk0a58,unk0a5c,unk0a60,unk0a64,unk0a68,unk0a6c,unk0a70,unk0a74,unk0a78,unk0a7c;
    int unk0a80,unk0a84,unk0a88,unk0a8c,unk0a90,unk0a94,unk0a98,unk0a9c,unk0aa0,unk0aa4,unk0aa8,unk0aac,unk0ab0,unk0ab4,unk0ab8,unk0abc;
    int unk0ac0,unk0ac4,unk0ac8,unk0acc,unk0ad0,unk0ad4,unk0ad8,unk0adc,unk0ae0,unk0ae4,unk0ae8,unk0aec,unk0af0,unk0af4,unk0af8,unk0afc;
    int unk0b00,unk0b04,unk0b08,unk0b0c,unk0b10,unk0b14,unk0b18,unk0b1c,unk0b20,unk0b24,unk0b28,unk0b2c,unk0b30,unk0b34,unk0b38,unk0b3c;
    int unk0b40,unk0b44,unk0b48,unk0b4c,unk0b50,unk0b54,unk0b58,unk0b5c,unk0b60,unk0b64,unk0b68,unk0b6c,unk0b70,unk0b74,unk0b78,unk0b7c;
    int unk0b80,unk0b84,unk0b88,unk0b8c,unk0b90,unk0b94,unk0b98,unk0b9c,unk0ba0,unk0ba4,unk0ba8,unk0bac,unk0bb0,unk0bb4,unk0bb8,unk0bbc;
    int unk0bc0,unk0bc4,unk0bc8,unk0bcc,unk0bd0,unk0bd4,unk0bd8,unk0bdc,unk0be0,unk0be4,unk0be8,unk0bec,unk0bf0,unk0bf4,unk0bf8,unk0bfc;
    int unk0c00,unk0c04,unk0c08,unk0c0c,unk0c10,unk0c14,unk0c18,unk0c1c,unk0c20,unk0c24,unk0c28,unk0c2c,unk0c30,unk0c34,unk0c38,unk0c3c;
    int unk0c40,unk0c44,unk0c48,unk0c4c,unk0c50,unk0c54,unk0c58,unk0c5c,unk0c60,unk0c64,unk0c68,unk0c6c,unk0c70,unk0c74,unk0c78,unk0c7c;
    int unk0c80,unk0c84,unk0c88,unk0c8c,unk0c90,unk0c94,unk0c98,unk0c9c,unk0ca0,unk0ca4,unk0ca8,unk0cac,unk0cb0,unk0cb4,unk0cb8,unk0cbc;
    int unk0cc0,unk0cc4,unk0cc8,unk0ccc,unk0cd0,unk0cd4,unk0cd8,unk0cdc,unk0ce0,unk0ce4,unk0ce8,unk0cec,unk0cf0,unk0cf4,unk0cf8,unk0cfc;
    int unk0d00,unk0d04,unk0d08,unk0d0c,unk0d10,unk0d14,unk0d18,unk0d1c,unk0d20,unk0d24,unk0d28,unk0d2c,unk0d30,unk0d34,unk0d38,unk0d3c;
    int unk0d40,unk0d44,unk0d48,unk0d4c,unk0d50,unk0d54,unk0d58,unk0d5c,unk0d60,unk0d64,unk0d68,unk0d6c,unk0d70,unk0d74,unk0d78,unk0d7c;
    int unk0d80,unk0d84,unk0d88,unk0d8c,unk0d90,unk0d94,unk0d98,unk0d9c,unk0da0,unk0da4,unk0da8,unk0dac,unk0db0,unk0db4,unk0db8,unk0dbc;
    int unk0dc0,unk0dc4,unk0dc8,unk0dcc,unk0dd0,unk0dd4,unk0dd8,unk0ddc,unk0de0,unk0de4,unk0de8,unk0dec,unk0df0,unk0df4,unk0df8,unk0dfc;
    int unk0e00,unk0e04,unk0e08,unk0e0c,unk0e10,unk0e14,unk0e18,unk0e1c,unk0e20,unk0e24,unk0e28,unk0e2c,unk0e30,unk0e34,unk0e38,unk0e3c;
    int unk0e40,unk0e44,unk0e48,unk0e4c,unk0e50,unk0e54,unk0e58,unk0e5c,unk0e60,unk0e64,unk0e68,unk0e6c,unk0e70,unk0e74,unk0e78,unk0e7c;
    int unk0e80,unk0e84,unk0e88,unk0e8c,unk0e90,unk0e94,unk0e98,unk0e9c,unk0ea0,unk0ea4,unk0ea8,unk0eac,unk0eb0,unk0eb4,unk0eb8,unk0ebc;
    int unk0ec0,unk0ec4,unk0ec8,unk0ecc,unk0ed0,unk0ed4,unk0ed8,unk0edc,unk0ee0,unk0ee4,unk0ee8,unk0eec,unk0ef0,unk0ef4,unk0ef8,unk0efc;
    int unk0f00,unk0f04,unk0f08,unk0f0c,unk0f10,unk0f14,unk0f18,unk0f1c,unk0f20,unk0f24,unk0f28,unk0f2c,unk0f30,unk0f34,unk0f38,unk0f3c;
    int unk0f40,unk0f44,unk0f48,unk0f4c,unk0f50,unk0f54,unk0f58,unk0f5c,unk0f60,unk0f64,unk0f68,unk0f6c,unk0f70,unk0f74,unk0f78,unk0f7c;
    int unk0f80,unk0f84,unk0f88,unk0f8c,unk0f90,unk0f94,unk0f98,unk0f9c,unk0fa0,unk0fa4,unk0fa8,unk0fac,unk0fb0,unk0fb4,unk0fb8,unk0fbc;
    int unk0fc0,unk0fc4,unk0fc8,unk0fcc,unk0fd0,unk0fd4,unk0fd8,unk0fdc,unk0fe0,unk0fe4,unk0fe8,unk0fec,unk0ff0,unk0ff4,unk0ff8,unk0ffc;
    int unk1000,unk1004,unk1008,unk100c,unk1010,unk1014,unk1018,unk101c,unk1020,unk1024,unk1028,unk102c,unk1030,unk1034,unk1038,unk103c;
    int unk1040,unk1044,unk1048,unk104c,unk1050,unk1054,unk1058,unk105c,unk1060,unk1064,unk1068,unk106c,unk1070,unk1074,unk1078,unk107c;
    int unk1080,unk1084,unk1088,unk108c,unk1090,unk1094,unk1098,unk109c,unk10a0,unk10a4,unk10a8,unk10ac,unk10b0,unk10b4,unk10b8,unk10bc;
    int unk10c0,unk10c4,unk10c8,unk10cc,unk10d0,unk10d4,unk10d8,unk10dc,unk10e0,unk10e4,unk10e8,unk10ec,unk10f0,unk10f4,unk10f8,unk10fc;
    int unk1100,unk1104,unk1108,unk110c,unk1110,unk1114,unk1118,unk111c,unk1120,unk1124,unk1128,unk112c,unk1130,unk1134,unk1138,unk113c;
    int unk1140,unk1144,unk1148,unk114c,unk1150,unk1154,unk1158,unk115c,unk1160,unk1164,unk1168,unk116c,unk1170,unk1174,unk1178,unk117c;
    int unk1180,unk1184,unk1188,unk118c,unk1190,unk1194,unk1198,unk119c,unk11a0,unk11a4,unk11a8,unk11ac,unk11b0,unk11b4,unk11b8,unk11bc;
    int unk11c0,unk11c4,unk11c8,unk11cc,unk11d0,unk11d4,unk11d8,unk11dc,unk11e0,unk11e4,unk11e8,unk11ec,unk11f0,unk11f4,unk11f8,unk11fc;
    int unk1200,unk1204,unk1208,unk120c,unk1210,unk1214,unk1218,unk121c,unk1220,unk1224,unk1228,unk122c,unk1230,unk1234,unk1238,unk123c;
    int unk1240,unk1244,unk1248,unk124c,unk1250,unk1254,unk1258,unk125c,unk1260,unk1264,unk1268,unk126c,unk1270,unk1274,unk1278,unk127c;
    int unk1280,unk1284,unk1288,unk128c,unk1290,unk1294,unk1298,unk129c,unk12a0,unk12a4,unk12a8,unk12ac,unk12b0,unk12b4,unk12b8,unk12bc;
    int unk12c0,unk12c4,unk12c8,unk12cc,unk12d0,unk12d4,unk12d8,unk12dc,unk12e0,unk12e4,unk12e8,unk12ec,unk12f0,unk12f4,unk12f8,unk12fc;
    int unk1300,unk1304,unk1308,unk130c,unk1310,unk1314,unk1318,unk131c,unk1320,unk1324,unk1328,unk132c,unk1330,unk1334,unk1338,unk133c;
    int unk1340,unk1344,unk1348,unk134c,unk1350,unk1354,unk1358,unk135c,unk1360,unk1364,unk1368,unk136c,unk1370,unk1374,unk1378,unk137c;
    int unk1380,unk1384,unk1388,unk138c,unk1390,unk1394,unk1398,unk139c,unk13a0,unk13a4,unk13a8,unk13ac,unk13b0,unk13b4,unk13b8,unk13bc;
    int unk13c0,unk13c4,unk13c8,unk13cc,unk13d0,unk13d4,unk13d8,unk13dc,unk13e0,unk13e4,unk13e8,unk13ec,unk13f0,unk13f4,unk13f8,unk13fc;
    int unk1400,unk1404,unk1408,unk140c,unk1410,unk1414,unk1418,unk141c,unk1420,unk1424,unk1428,unk142c,unk1430,unk1434,unk1438,unk143c;
    int unk1440,unk1444,unk1448,unk144c,unk1450,unk1454,unk1458,unk145c,unk1460,unk1464,unk1468,unk146c,unk1470,unk1474,unk1478,unk147c;
    int unk1480,unk1484,unk1488,unk148c,unk1490,unk1494,unk1498,unk149c,unk14a0,unk14a4,unk14a8,unk14ac,unk14b0,unk14b4,unk14b8,unk14bc;
    int unk14c0,unk14c4,unk14c8,unk14cc,unk14d0,unk14d4,unk14d8,unk14dc,unk14e0,unk14e4,unk14e8,unk14ec,unk14f0,unk14f4,unk14f8,unk14fc;
    int unk1500,unk1504,unk1508,unk150c,unk1510,unk1514,unk1518,unk151c,unk1520,unk1524,unk1528,unk152c,unk1530,unk1534,unk1538,unk153c;
    int unk1540,unk1544,unk1548,unk154c,unk1550,unk1554,unk1558,unk155c,unk1560,unk1564,unk1568,unk156c,unk1570,unk1574,unk1578,unk157c;
    int unk1580,unk1584,unk1588,unk158c,unk1590,unk1594,unk1598,unk159c,unk15a0,unk15a4,unk15a8,unk15ac,unk15b0,unk15b4,unk15b8,unk15bc;
    int unk15c0,unk15c4,unk15c8,unk15cc,unk15d0,unk15d4,unk15d8,unk15dc,unk15e0,unk15e4,unk15e8,unk15ec,unk15f0,unk15f4,unk15f8,unk15fc;
    int unk1600,unk1604,unk1608,unk160c,unk1610,unk1614,unk1618,unk161c,unk1620,unk1624,unk1628,unk162c,unk1630,unk1634,unk1638,unk163c;
    int unk1640,unk1644,unk1648,unk164c,unk1650,unk1654,unk1658,unk165c,unk1660,unk1664,unk1668,unk166c,unk1670,unk1674,unk1678,unk167c;
    int unk1680,unk1684,unk1688,unk168c,unk1690,unk1694,unk1698,unk169c,unk16a0,unk16a4,unk16a8,unk16ac,unk16b0,unk16b4,unk16b8,unk16bc;
    int unk16c0,unk16c4,unk16c8,unk16cc,unk16d0,unk16d4,unk16d8,unk16dc,unk16e0,unk16e4,unk16e8,unk16ec,unk16f0,unk16f4,unk16f8,unk16fc;
    int unk1700,unk1704,unk1708,unk170c,unk1710,unk1714,unk1718,unk171c,unk1720,unk1724,unk1728,unk172c,unk1730,unk1734,unk1738,unk173c;
    int unk1740,unk1744,unk1748,unk174c,unk1750,unk1754,unk1758,unk175c,unk1760,unk1764,unk1768,unk176c,unk1770,unk1774,unk1778,unk177c;
    int unk1780,unk1784,unk1788,unk178c,unk1790,unk1794,unk1798,unk179c,unk17a0,unk17a4,unk17a8,unk17ac,unk17b0,unk17b4,unk17b8,unk17bc;
    int unk17c0,unk17c4,unk17c8,unk17cc,unk17d0,unk17d4,unk17d8,unk17dc,unk17e0,unk17e4,unk17e8,unk17ec,unk17f0,unk17f4,unk17f8,unk17fc;
    int unk1800,unk1804,unk1808,unk180c,unk1810,unk1814,unk1818,unk181c,unk1820,unk1824,unk1828,unk182c,unk1830,unk1834,unk1838,unk183c;
    int unk1840,unk1844,unk1848,unk184c,unk1850,unk1854,unk1858,unk185c,unk1860,unk1864,unk1868,unk186c,unk1870,unk1874,unk1878,unk187c;
    int unk1880,unk1884,unk1888,unk188c,unk1890,unk1894,unk1898,unk189c,unk18a0,unk18a4,unk18a8,unk18ac,unk18b0,unk18b4,unk18b8,unk18bc;
    int unk18c0,unk18c4,unk18c8,unk18cc,unk18d0,unk18d4,unk18d8,unk18dc,unk18e0,unk18e4,unk18e8,unk18ec,unk18f0,unk18f4,unk18f8,unk18fc;
    int unk1900,unk1904,unk1908,unk190c,unk1910,unk1914,unk1918,unk191c,unk1920,unk1924,unk1928,unk192c,unk1930,unk1934,unk1938,unk193c;
    int unk1940,unk1944,unk1948,unk194c,unk1950,unk1954,unk1958,unk195c,unk1960,unk1964,unk1968,unk196c,unk1970,unk1974,unk1978,unk197c;
    int unk1980,unk1984,unk1988,unk198c,unk1990,unk1994,unk1998,unk199c,unk19a0,unk19a4,unk19a8,unk19ac,unk19b0,unk19b4,unk19b8,unk19bc;
    int unk19c0,unk19c4,unk19c8,unk19cc,unk19d0,unk19d4,unk19d8,unk19dc,unk19e0,unk19e4,unk19e8,unk19ec,unk19f0,unk19f4,unk19f8,unk19fc;
    int unk1a00,unk1a04,unk1a08,unk1a0c,unk1a10,unk1a14,unk1a18,unk1a1c,unk1a20,unk1a24,unk1a28,unk1a2c,unk1a30,unk1a34,unk1a38,unk1a3c;
    int unk1a40,unk1a44,unk1a48,unk1a4c,unk1a50,unk1a54,unk1a58,unk1a5c,unk1a60,unk1a64,unk1a68,unk1a6c,unk1a70,unk1a74,unk1a78,unk1a7c;
    int unk1a80,unk1a84,unk1a88,unk1a8c,unk1a90,unk1a94,unk1a98,unk1a9c,unk1aa0,unk1aa4,unk1aa8,unk1aac,unk1ab0,unk1ab4,unk1ab8,unk1abc;
    int unk1ac0,unk1ac4,unk1ac8,unk1acc,unk1ad0,unk1ad4,unk1ad8,unk1adc,unk1ae0,unk1ae4,unk1ae8,unk1aec,unk1af0,unk1af4,unk1af8,unk1afc;
    int unk1b00,unk1b04,unk1b08,unk1b0c,unk1b10,unk1b14,unk1b18,unk1b1c,unk1b20,unk1b24,unk1b28,unk1b2c,unk1b30,unk1b34,unk1b38,unk1b3c;
    int unk1b40,unk1b44,unk1b48,unk1b4c,unk1b50,unk1b54,unk1b58,unk1b5c,unk1b60,unk1b64,unk1b68,unk1b6c,unk1b70,unk1b74,unk1b78,unk1b7c;
    int unk1b80,unk1b84,unk1b88,unk1b8c,unk1b90,unk1b94,unk1b98,unk1b9c,unk1ba0,unk1ba4,unk1ba8,unk1bac,unk1bb0,unk1bb4,unk1bb8,unk1bbc;
    int unk1bc0,unk1bc4,unk1bc8,unk1bcc,unk1bd0,unk1bd4,unk1bd8,unk1bdc,unk1be0,unk1be4,unk1be8,unk1bec,unk1bf0,unk1bf4,unk1bf8,unk1bfc;
    int unk1c00,unk1c04,unk1c08,unk1c0c,unk1c10,unk1c14,unk1c18,unk1c1c,unk1c20,unk1c24,unk1c28,unk1c2c,unk1c30,unk1c34,unk1c38,unk1c3c;
    int unk1c40,unk1c44,unk1c48,unk1c4c,unk1c50,unk1c54,unk1c58,unk1c5c;
    int agents;
};


__forceinline DeactivationCtor& SolverCtor::configureTier(int tierIndex,float threshold,float speed,float magnitude,float gravityScale) {
        TierQuotientCtor quotient;
        quotient.denominator=speed*magnitude;
        quotient.threshold=threshold;
        float ratio=quotient.value();
        DeactivationCtor& tier=tiers[tierIndex];
        tier.damping=1.0f-(unk120*0.016f)*ratio;
        tier.inverseThreshold=1.0f/threshold;
        tier.inverseVelocity=1.0f/(threshold*gravityScale);
        tier.time=(float)speed>0.0f ? unk120*0.016f/(float)speed : DAT_010c6848;
    return tier;
}
// @fnv 0x00c95a80
WorldCtor* WorldCtor::FUN_00c95a80(WorldInfoCtor* info, int version) {
    vtable=&DAT_010c6714;
    references=1;
    int tierIndex=0;
    initArray(active); initArray(inactive); initArray(dirty);
    watchdog=0;
    threadCheck.m_uiThreadId=0xfffffff1;
    threadCheck.m_usMarkedForWrite=0x8000;
    initArray(phantoms); initArray(actions); initArray(entities);
    initArray(phantomCallbacks); initArray(constraints); initArray(deletionCallbacks);
    initArray(islandCallbacks); initArray(postSimulation); initArray(postIntegrate);
    initArray(postCollide); initArray(islandIntegrate); initArray(islandCollide);
    initArray(contacts); initArray(impulseLimits);
    lastEntity=-1; lastConstraint=-1; locked=0; assertMemory=1;
    ObjectCtor* object=(ObjectCtor*)worldAlloc(0x204);
    if(object) object->vtable=0; else object=0;
    violated=object;
    object=(ObjectCtor*)worldAlloc(0x28);
    pending=object ? ((::ObjectCtor *)(new ((void *)(object)) ::FUN_00cf75c0(this))) : 0;
    pendingQueues=0; pendingCount=0; bodyCount=0; criticalCount=0; phantomCount=0;
    blockOperations=0; allowOperations=1;
    modifyLock=0; propertyLock=0; dirtyLock=0;
    queueCount=1; destruction=0;
    minimum=info->minimum;
    maximum=info->maximum;
    markers=info->markers;
    broadphase=DAT_011b37a0(&minimum,&maximum,info->markers);
    int broadphaseQuerySize=info->querySize;
    querySize=broadphaseQuerySize;
    updateSize=broadphaseQuerySize/2;
    toiQueueSize=info->toiQueueSize;
    if(version!=0x111d4) {
        int buffer[0x80];
        StreamCtor stream;
        new ((void *)&(stream)) ::FUN_00cb1600((char*)buffer,sizeof(buffer));
        reinterpret_cast<::SinkOwner *>((((::StreamCtor *)(reinterpret_cast<::FUN_00cc02d0_cls *>((((::StreamCtor *)(reinterpret_cast<::SinkOwner *>((((::StreamCtor *)&(reinterpret_cast<::CC0280Writer *>((((::StreamCtor *)(reinterpret_cast<::SinkOwner *>(&(stream))->FUN_00cc01c0("** Havok libs built with version [")))))->WriteInt(0x111d4)))))->FUN_00cc01c0("], used with code built with [")))))->FUN_00cc02d0(version)))))->FUN_00cc01c0("]. **");
        if((*reinterpret_cast<::ErrorCtor * *>(&::DAT_01268360))->report(3,0x53c94b42,(char*)buffer,".\\World\\hkpWorld.cpp",0xbb5))
            __debugbreak();
        reinterpret_cast<struct ::FUN_00cc00e0 *>(&(stream))->FUN_00cc00e0::~FUN_00cc00e0();
    }
    gravity=info->gravity;
    UpdateSkyEntries(info->snap,info->snapOther);
    snapConvex=info->snap;
    snapConcave=info->snap;
    weld=info->weld;
    activate=info->activate;
    rotateNormal=info->rotateNormal;
    sectors=info->sectors;
    threadToi=info->threadToi;
    toiEntries=info->toiEntries;
    toiPairs=info->toiPairs;
    referenceDistance=info->referenceDistance;
    solver.unk00=1.0f;
    reinterpret_cast<::FUN_00c90e60_cls *>(&(solver))->FUN_00c90e60(info->solverTau,info->solverDamping);
    solver.unk60=info->solverFriction;
    solver.unk114=info->iterations;
    solver.unk120=1.0f/info->iterations;
    solver.unk118=info->microsteps;
    solver.unk128=info->damping*info->damping;
    solver.unk11c=1.0f/info->microsteps;
    solver.unk124=info->flag8c;
    solver.unk125=info->flagA4;
    solver.unk126=info->flagA5;
    solver.unk127=info->flagA6;
    solver.unk10c=0.0f; solver.unk110=0.0f;
    float magnitude=length3(info->gravity);
    if(magnitude==0.0f) magnitude=DAT_010c6860;
    float gravityScale=magnitude*0.1f;
    for(;tierIndex<6;++tierIndex) {
        float threshold; float speed;
        switch(tierIndex) {
        case 0: case 1: threshold=1.1920928955078125e-7f; speed=0.0f; break;
        case 2: threshold=0.01f; speed=DAT_010c6850; break;
        case 3: threshold=0.017f; speed=DAT_0101df44; break;
        case 4: threshold=0.02f; speed=DAT_01017870; break;
        default: threshold=0.025f; speed=DAT_010231a8; break;
        }
        DeactivationCtor& tier=solver.configureTier(tierIndex,threshold*magnitude,speed,magnitude,gravityScale);
        float distance=info->referenceDistance;
        tier.distanceSquared=distance*distance;
        tier.radiusSquared=(4.0f*distance)*(4.0f*distance);
        union { float f; int bits; } halfDistance,halfRadius;
        halfDistance.f=(2.0*distance)*(2.0*distance);
        tier.distanceHalf=(unsigned short)(halfDistance.bits>>16);
        halfRadius.f=(8.0f*distance)*(8.0f*distance);
        tier.radiusHalf=(unsigned short)(halfRadius.bits>>16);
    }
    if(info->watchdog) reinterpret_cast<::FUN_00c90510_class *>((info->watchdog))->FUN_00c90510();
    if(watchdog) release(watchdog);
    watchdog=info->watchdog;
    wantIslands=info->wantIslands;
    deactivate=info->deactivate;
    if(!wantIslands && deactivate) deactivate=wantIslands;
    singleActions=info->singleActions;
    separateIntegration=0;
    object=(ObjectCtor*)worldAlloc(0x10c);
    broadphaseDispatcher=object ? ((::ObjectCtor *)(new ((void *)(object)) ::FUN_00cf6f90())) : 0;
    object=allocObject<ObjectCtor>(0xc);
    object->references=1;
    object->vtable=(ObjectVtableCtor*)&DAT_010c63f0;
    object->unk08.raw=&DAT_010c63e0;
    phantomListener=object;
    object=allocObject<ObjectCtor>(0x10);
    entityListener=((::ObjectCtor *)(reinterpret_cast<::FUN_00d107d0_t *>((object))->FUN_00d107d0(this)));
    object=allocObject<ObjectCtor>(0xc);
    object->references=1;
    object->vtable=(ObjectVtableCtor*)&DAT_010c6410;
    object->unk08.raw=&DAT_010c6400;
    borderListener=object;
    broadphaseDispatcher->unk28.raw=phantomListener ? &phantomListener->unk08 : 0;
    broadphaseDispatcher->unk44.raw=phantomListener ? &phantomListener->unk08 : 0;
    broadphaseDispatcher->unk48.raw=phantomListener ? &phantomListener->unk08 : 0;
    broadphaseDispatcher->unk24.raw=entityListener ? &entityListener->unk08 : 0;
    broadphaseDispatcher->unk2c.raw=borderListener ? &borderListener->unk08 : 0;
    broadphaseDispatcher->unk64.raw=borderListener ? &borderListener->unk08 : 0;
    broadphaseDispatcher->unk4c.raw=borderListener ? &borderListener->unk08 : 0;
    broadphaseDispatcher->unk68.raw=borderListener ? &borderListener->unk08 : 0;
    broadphaseDispatcher->unk6c.raw=borderListener ? &borderListener->unk08 : 0;
    ObjectCtor* agent=((::ObjectCtor *)(::new ((void *)(allocObject<ObjectCtor>(0xc))) ::FUN_00cfd450((::hkWorldCFD4 *)(::WorldCtor *)(this))));
    dispatcher=((::ObjectCtor *)(reinterpret_cast<::FUN_00cfc030_cls *>((allocObject<ObjectCtor>(0x1e50)))->FUN_00cfc030((void*)&((void (&)())::FUN_00d10790),(agent))));
    release(agent);
    if(!info->filter) {
        object=allocObject<ObjectCtor>(0x30);
        new ((void *)(object)) ::FUN_00cbfba0();
        object->vtable=(ObjectVtableCtor*)&DAT_010c646c;
        object->unk08.raw=&DAT_010c6460;
        object->unk0c.raw=&DAT_010c644c;
        object->unk10.raw=&DAT_010c6440;
        object->unk14.raw=&DAT_010c6434;
        object->unk20.i=1;
        filter=object;
    } else {
        filter=info->filter;
        reinterpret_cast<::FUN_00c90510_class *>((filter))->FUN_00c90510();
    }
    if(!info->convexFilter) {
        object=allocObject<ObjectCtor>(8);
        object->references=1;
        object->vtable=(ObjectVtableCtor*)&DAT_010c63cc;
        convexFilter=object;
    } else {
        convexFilter=info->convexFilter;
        reinterpret_cast<::FUN_00c90510_class *>((convexFilter))->FUN_00c90510();
    }
    CollisionInputCtor* in=new CollisionInputCtor;
    input=in;
    in->unk04=0;
    in->dispatcher=dispatcher;
    in->tolerance=info->tolerance;
    in->filter=filter;
    in->convexFilter=convexFilter;
    generation=info->generation;
    in->flag6d=info->quality;
    ManifoldCtor* manifold=(ManifoldCtor*)worldAlloc(0x10);
    if(manifold) { manifold->tolerance=DAT_01013ea4; manifold->count=20; } else manifold=0;
    in->manifold=manifold;
    manifold->tolerance=info->manifoldTolerance;
    in->manifold->count=info->manifoldCount;
    in->flag6c=info->flag99;
    in->unk14=0;
    in->agents=&((DispatcherCtor*)in->dispatcher)->agents;
    setRange(in->range,0.0f,0.0f);
    ::hkQuadReal extent=_mm_sub_ps(info->maximum,info->minimum);
    float inverseX=1.0f/extent[0];
    float inverseY=1.0f/extent[1];
    float inverseZ=1.0f/extent[2];
    in->scale=_mm_mul_ps(_mm_setr_ps(inverseX,inverseY,inverseZ,0.0f),_mm_shuffle_ps(_mm_load_ss(&DAT_010c6844),_mm_load_ss(&DAT_010c6844),0));
    in->offset=_mm_xor_ps(info->minimum,::DAT_010c44d0);
    ::hkQuadReal scalarCoeff=_mm_load_ss(&DAT_010c6840);
    ::hkQuadReal splatCoeff=_mm_shuffle_ps(scalarCoeff,scalarCoeff,0);
    _mm_store_ps(reinterpret_cast<float*>(&in->extent),_mm_add_ps(_mm_mul_ps(splatCoeff,extent),in->offset));
    ::hkQuadReal zero=_mm_setzero_ps();
    in->scale=_mm_shuffle_ps(in->scale,_mm_unpackhi_ps(in->scale,zero),0xc4);
    ::hkQuadReal voffset=_mm_load_ps(reinterpret_cast<float*>(&in->offset)); _mm_store_ps(reinterpret_cast<float*>(&in->offset),_mm_shuffle_ps(voffset,_mm_unpackhi_ps(voffset,zero),0xc4));
    _mm_store_ps(reinterpret_cast<float*>(&in->extent),_mm_shuffle_ps(in->extent,_mm_unpackhi_ps(in->extent,zero),0xc4));
    broadphase->vtable->vf70(broadphase,&in->offset,&in->extent,&in->scale);
    WorldCtorFactorySetup::RegisterContactMgrFactories((::CFB240Dispatcher*)dispatcher,this);
    if(DAT_012681dc) info->simulationType=3;
    minIsland=0;
    simulationType=info->simulationType;
    switch(simulationType) {
    case 3:
        object=(ObjectCtor*)worldAlloc(0x18);
        modifyLock=object ? ((::ObjectCtor *)(reinterpret_cast<::FUN_00cf6da0_cls *>((object))->FUN_00cf6da0(4000))) : 0;
        object=(ObjectCtor*)worldAlloc(0x18);
        propertyLock=object ? ((::ObjectCtor *)(reinterpret_cast<::FUN_00cf6da0_cls *>((object))->FUN_00cf6da0(4000))) : 0;
        simulation=((::ObjectCtor *)(new ((void *)(allocObject<ObjectCtor>(0x180))) ::FUN_00d02c80((::World *)(::WorldCtor *)(this))));
        minIsland=info->minIsland;
        break;
    case 2: simulation=allocObject<ObjectCtor>(0x50)->FUN_00d0d020(this); break;
    case 1: simulation=((::ObjectCtor *)(new ((void *)(allocObject<ObjectCtor>(0x2c))) ::FUN_00cf87c0(this))); break;
    }
    object=(ObjectCtor*)worldAlloc(0x18);
    dirtyLock=object ? ((::ObjectCtor *)(reinterpret_cast<::FUN_00cf6da0_cls *>((object))->FUN_00cf6da0(4000))) : 0;
    simulation->unk24.f=info->simulationValue;
    magnitude=length3(gravity);
    if(magnitude==0.0f) magnitude=DAT_010c6860;
    toi0=info->toi0; toi1=info->toi1; toi2=info->toi2; toi3=info->toi3;
    BuildConfigCtor config;
    config.magnitude=magnitude;
    config.tolerance=input->tolerance;
    config.config68=info->config68;
    config.config60=info->config60;
    config.toi0=info->toi0;config.toi1=info->toi1;config.toi2=info->toi2;config.toi3=info->toi3;
    config.multithread=info->simulationType>=2;
    config.quality=info->generation==2;
    config.contacts=info->generation>=1;
    config.one=1;config.three=3;config.four=4;config.five=5;
    config.weld=info->weld;
    reinterpret_cast<::Big *>((dispatcher))->FUN_00cfb570((::Src *)(void *)(&config));
    input->agents=&((DispatcherCtor*)dispatcher)->agents;
    fixedIsland=((::ObjectCtor *)(new ((void *)(allocObject<ObjectCtor>(0x6c))) ::FUN_00d07830((::hkpWorldQ *)(::WorldCtor *)(this))));
    fixedIsland->id20=0xffff;
    fixedIsland->flags26 &= 0xf3;
    fixedIsland->flags26 &= 0xfc;
    if(!wantIslands) {
        ObjectCtor* island=((::ObjectCtor *)(new ((void *)(allocObject<ObjectCtor>(0x6c))) ::FUN_00d07830((::hkpWorldQ *)(::WorldCtor *)(this))));
        active.push(island);
        island->id20=0;
    }
    BodyInfoCtor body;
    reinterpret_cast<::Owner *>(&(body))->FUN_00cf5ea0();
    body.unk90=0.0f;
    body.motionType=5;
    fixedBody=((::ObjectCtor *)(reinterpret_cast<::S00ca8c90_Body *>((allocObject<ObjectCtor>(0x220)))->FUN_00ca8c90((*(const ::CInfo181 *)(&body)))));
    reinterpret_cast<::hkpWorldC914 *>(this)->FUN_00c914d0((::hkpEntityC914 *)(fixedBody),1);
    release(fixedBody);
    setRange(time,0.0f,0.016666668f);
    input->time=&time;
    if(info->borderBehavior!=3) {
        ObjectCtor* pendingBorder=allocObject<ObjectCtor>(0x44);
        int behavior=info->borderBehavior;
        broadphaseBorder=((::ObjectCtor *)(new ((void *)(pendingBorder)) ::bpb::hkpBroadPhaseBorder((::bpb::hkpWorld *)(::WorldCtor *)(this),behavior,info->postponeBorder)));
    } else broadphaseBorder=0;
    kdTree=((::ObjectCtor *)(new ((void *)(allocObject<ObjectCtor>(0x10))) ::FUN_00d0b250()));
    kdTree->vtable->vf0c(kdTree,this);
    callbackUtil=0;
    if(info->flagE0) ::fnv_00d0b040::FUN_00d0b040((::fnv_00d0b040::TargetClass *)(::WorldCtor *)(this));
    if(info->borderEnabled) {
        border=((::ObjectCtor *)(new ((void *)(allocObject<ObjectCtor>(0x24))) ::ListenerMgrD0A((::FUN_00d0a2d0 *)(::WorldCtor *)(this),0)));
        autoTree=info->borderFlag;
    } else if(info->borderAlternate) {
        ObjectCtor* alternate=allocObject<ObjectCtor>(0x70); int borderMode=info->borderMode; border=((::ObjectCtor *)(new ((void *)(alternate)) ::fnv_00d08cf0::FUN_00d08cf0((::fnv_00d08cf0::ListenerManager *)(::WorldCtor *)(this),borderMode,0.0f)));
        autoTree=info->borderFlag;
    } else border=0;
    if(info->simulationType!=3) ((FUN_00cf6d20_Class*)&threadCheck)->FUN_00cf6d20();
    object=(ObjectCtor*)worldAlloc(0x120);
    if(object) {
        object->unkf4.i=0;
        object->unk94.i=0;
    } else object=0;
    jobs=object;
    return this;
}

namespace ArrowHeadRatios {extern const float DAT_010c69c4=0.14999997615814208984375f; extern const float DAT_010c69c0=-0.14999997615814208984375f;}
namespace ArrowLengthLimit { extern const float DAT_0104da4c = 1.1920928955078125e-7f; }
__forceinline ::hkQuadReal arrowSplat(float t) { ::hkQuadReal q = _mm_load_ss(&t); return _mm_shuffle_ps(q,q,0); }
struct ArrowVectorView {
    union { ::hkQuadReal q; float f[4]; };
};


__forceinline ::hkQuadReal arrowDot3(::hkQuadReal a, ::hkQuadReal b) {
    ::hkQuadReal products = _mm_mul_ps(a,b);
    ::hkQuadReal xy = _mm_add_ss(_mm_shuffle_ps(products,products,0x55),products);
    return _mm_add_ss(_mm_shuffle_ps(products,products,0xaa),xy);
}
__forceinline float arrowScalar(::hkQuadReal q) { float out; _mm_store_ss(&out,q); return out; }
__forceinline void arrowPerpendicular(ArrowVectorView* v, ArrowVectorView& out) {
    int least=0, side=1, other=2;
    float low=fabsf(v->f[0]);
    float y=fabsf(v->f[1]);
    float z=fabsf(v->f[2]);
    if(y<low) { side=0; least=1; low=y; }
    if(z<low) { other=least; }
    out.q=_mm_setzero_ps();
    out.f[side]=v->f[other];
    out.f[other]=-v->f[side];
}
__forceinline void arrowCross(ArrowVectorView& out,const ArrowVectorView& left,const ArrowVectorView& right) {
    ::hkQuadReal first=_mm_mul_ps(_mm_shuffle_ps(left.q,left.q,0xc9),_mm_shuffle_ps(right.q,right.q,0xd2));
    ::hkQuadReal second=_mm_mul_ps(_mm_shuffle_ps(left.q,left.q,0xd2),_mm_shuffle_ps(right.q,right.q,0xc9));
    out.q=_mm_sub_ps(first,second);
}
__forceinline void drawDebugArrow(::FUN_00c986c0_Obj* drawer, ArrowVectorView* a, ArrowVectorView* v, int a3, hkUlong a4, int a5)
{
    if (arrowScalar(arrowDot3(v->q,v->q)) < ::DAT_0104da4c) return;
    ArrowVectorView sum;
    sum.q = _mm_add_ps(_mm_load_ps(a->f),v->q);
    ArrowVectorView u;
    arrowPerpendicular(v,u);
    float scaleValue0 = DAT_01019de0;
    ::hkQuadReal uq = u.q;
    ::hkQuadReal usq = _mm_mul_ps(uq, uq);
    ::hkQuadReal t0 = _mm_shuffle_ps(usq, usq, 0x55);
    ::hkQuadReal t1 = _mm_add_ss(t0, usq);
    ::hkQuadReal t2 = _mm_shuffle_ps(usq, usq, 0xaa);
    ::hkQuadReal tt = _mm_add_ss(t2, t1);
    ::hkQuadReal r = _mm_rsqrt_ss(tt);
    ::hkQuadReal fr = _mm_mul_ss(_mm_mul_ss(tt, r), r);
    ::hkQuadReal eq = _mm_cmpeq_ss(tt, _mm_set_ss(::DAT_01011d78));
    ::hkQuadReal factor = _mm_andnot_ps(eq, _mm_mul_ss(_mm_mul_ss(_mm_set_ss(::fnv_00c88020::DAT_01016248), r), _mm_sub_ss(_mm_set_ss(::DAT_01017718), fr)));
    ::hkQuadReal n = _mm_mul_ps(uq, _mm_shuffle_ps(factor, factor, 0));
    ArrowVectorView unit,cross; unit.q=n; arrowCross(cross,*v,unit);
    ::hkQuadReal len = _mm_sqrt_ss(arrowDot3(v->q,v->q));
    ::hkQuadReal scaledN = _mm_mul_ps(_mm_shuffle_ps(len, len, 0), n);
    ::hkQuadReal aq = _mm_load_ps(a->f);
    ::hkQuadReal c = arrowSplat(scaleValue0);
    ::hkQuadReal base = _mm_add_ps(_mm_mul_ps(c, sum.q),
                             _mm_mul_ps(_mm_sub_ps(_mm_load_ps((*reinterpret_cast<::ArrowVectorView *>((void *)&::DAT_010ec7f0)).f), c), aq));
    ArrowVectorView o1, o2, o3, o4;
    float scaleValue1 = ArrowHeadRatios::DAT_010c69c4;
    o1.q = _mm_add_ps(base, _mm_mul_ps(arrowSplat(scaleValue1), scaledN));
    float scaleValue2 = ::DAT_010c69c0;
    o2.q = _mm_add_ps(base, _mm_mul_ps(arrowSplat(scaleValue2), scaledN));
    float scaleValue3 = ArrowHeadRatios::DAT_010c69c4;
    o3.q = _mm_add_ps(base, _mm_mul_ps(arrowSplat(scaleValue3), cross.q));
    float scaleValue4 = ::DAT_010c69c0;
    o4.q = _mm_add_ps(base, _mm_mul_ps(arrowSplat(scaleValue4), cross.q));
    reinterpret_cast<::hkpListenerListC98B *>((drawer))->FUN_00c986c0((&a->q), (&sum.q), a3, a4, a5);
    reinterpret_cast<::hkpListenerListC98B *>((drawer))->FUN_00c986c0((&sum.q), (&o1.q), a3, a4, a5);
    reinterpret_cast<::hkpListenerListC98B *>((drawer))->FUN_00c986c0((&sum.q), (&o2.q), a3, a4, a5);
    reinterpret_cast<::hkpListenerListC98B *>((drawer))->FUN_00c986c0((&sum.q), (&o3.q), a3, a4, a5);
    reinterpret_cast<::hkpListenerListC98B *>((drawer))->FUN_00c986c0((&sum.q), (&o4.q), a3, a4, a5);
}
// @fnv 0x00c98e60
void PlaneDraw::FUN_00c98e60(const V4& plane, const V4& offset, float scale, int color, hkUlong id, int tag) throw()
{
    float negW = -plane.f[3];
    V4 base;
    base.scaled(_mm_load_ss(&negW), plane);
    base.add(offset);

    V4 basis;
    basis.absolute(plane);

    int axis;
    if (basis.f[0] < basis.f[1]) {
        if (basis.f[1] < basis.f[2])
            axis = 2;
        else
            axis = 1;
    } else {
        if (basis.f[0] < basis.f[2])
            axis = 2;
        else
            axis = 0;
    }

    vstore(basis, _mm_setzero_ps());
    basis.f[(axis + 1) % 3] = 1.0f;

    basis.cross(plane, basis);
    basis.normalize();
    basis.scale(_mm_load_ss(&scale));
    V4 side;
    side.cross(basis,plane);
    side.normalize();
    side.scale(_mm_load_ss(&scale));

    int n = 1;
    int left = 4;
    do {
        V4 a;
        if ((n-1)&2) a.minus(base,side); else a.plus(side,base);
        if ((n%4)/2) a.minus(a,basis); else a.plus(a,basis);
        V4 c;
        if ((n%4)/2) c.minus(base,side); else c.plus(side,base);
        int n1=n+1;
        if ((n1%4)/2) c.minus(c,basis); else c.plus(c,basis);
        reinterpret_cast<::hkpListenerListC98B *>(this)->FUN_00c986c0(&(a), &(c), color, id, tag);
        n = n1;
        --left;
    } while (left != 0);

    reinterpret_cast<::DebugArrowEntry *>(this)->FUN_00c98880((const ::hkVector4_S &)(base), (const ::hkVector4_S &)((const ::V4 &)(V4(_mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&scale), _mm_load_ss(&scale), 0), plane.q)))), color, id, tag);
}
// @fnv 0x00c98880
void DebugArrowEntry::FUN_00c98880(const ::hkVector4_S& kFrom, const ::hkVector4_S& kWorldPosition, int uiColor, hkUlong aiId, int aiAllocationTag)
{
    drawDebugArrow((::FUN_00c986c0_Obj*)this, (ArrowVectorView*)&kFrom, (ArrowVectorView*)&kWorldPosition, uiColor, aiId, aiAllocationTag);
}

struct ScalarC992 {
    ::hkQuadReal q;
    ScalarC992() {}
    ScalarC992(float f) { q = _mm_load_ss(&f); }
    ScalarC992(const ::hkQuadReal& v) { q = v; }
    ::hkQuadReal broadcast() const { return _mm_shuffle_ps(q,q,0); }
    const ::hkQuadReal& value() const { return q; }
};

inline ScalarC992 operator*(const ScalarC992& a,const ScalarC992& b) { return _mm_mul_ss(a.value(),b.value()); }
inline ScalarC992 operator+(const ScalarC992& a,const ScalarC992& b) { return _mm_add_ss(a.value(),b.value()); }
struct Vec_c99210 {
    ::hkQuadReal m_vComponents;
    void setSub4(const Vec_c99210& a, const Vec_c99210& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    void setColor(float x,float y,float z,float w) { m_vComponents = _mm_setr_ps(x,y,z,w); }
    void set(float x, float y, float z, float w) { m_vComponents = _mm_setr_ps(x, y, z, w); }
    __forceinline void setCross(const Vec_c99210& v1, const Vec_c99210& v2)
    {
        ::hkQuadReal cross0 = _mm_mul_ps(_mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2), _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
        ::hkQuadReal cross1 = _mm_mul_ps(_mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9), _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline ScalarC992 dot3(const Vec_c99210& b) const
    {
        ::hkQuadReal x2 = _mm_mul_ps(m_vComponents, b.m_vComponents);
        ::hkQuadReal xy = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xy);
    }
    __forceinline ScalarC992 inverseLength3() const
    {
        ::hkQuadReal h = _mm_set_ss(0.5f), t = _mm_set_ss(3.0f), z = _mm_set_ss(0.0f);
        ::hkQuadReal square = dot3(*this).q;
        ::hkQuadReal mask = _mm_cmpeq_ss(square,z);
        ::hkQuadReal guess = _mm_rsqrt_ss(square);
        ::hkQuadReal adjusted = _mm_mul_ss(_mm_mul_ss(h,guess), _mm_sub_ss(t,_mm_mul_ss(_mm_mul_ss(square,guess),guess)));
        return _mm_andnot_ps(mask,adjusted);
    }
    __forceinline void normalize3()
    {
        m_vComponents = _mm_mul_ps(inverseLength3().broadcast(), m_vComponents);
    }
    __forceinline void mulS(float s) { m_vComponents = _mm_mul_ps(m_vComponents, _mm_set_ps1(s)); }
    void mul4(const ScalarC992& s) { m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents); }
    void setMul4(const Vec_c99210& a, const Vec_c99210& b) { m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents); }
    void scaled(const ScalarC992& f, const Vec_c99210& v) { m_vComponents = _mm_mul_ps(f.broadcast(), v.m_vComponents); }
    void accumulate(const ScalarC992& f, const Vec_c99210& v) { m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(f.broadcast(), v.m_vComponents)); }
    void add4(const Vec_c99210& a) { m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents); }
};



// @fnv 0x00c99210
void FUN_00c99210(const ::hkVector4_S& vertexA, const ::hkVector4_S& vertexB, const ::hkVector4_S& vertexC, unsigned int color)
{
    const Vec_c99210& a = reinterpret_cast<const Vec_c99210&>(vertexA);
    const Vec_c99210& b = reinterpret_cast<const Vec_c99210&>(vertexB);
    const Vec_c99210& c = reinterpret_cast<const Vec_c99210&>(vertexC);
    Vec_c99210 e1; e1.setSub4(b, a);
    Vec_c99210 e2; e2.setSub4(c, a);
    Vec_c99210 n; n.setCross(e1, e2);
    n.normalize3();

    Vec_c99210 l0; l0.set(0.5f, 2.0f, 1.0f, 0.0f);
    l0.normalize3();
    const ScalarC992 weight0(0.9f);
    Vec_c99210 l1; l1.set(-3.0f, -2.0f, -1.0f, 0.0f);
    l1.normalize3();
    Vec_c99210 rgb;
    rgb.set((unsigned char)(color >> 16) * (double(1.0f / 255.0f)), (unsigned char)(color >> 8) * (double(1.0f / 255.0f)), (unsigned char)color * (double(1.0f / 255.0f)), 0.0f);
    Vec_c99210 c0; c0.set(0.75f, 0.75f, 0.75f, 0.0f); c0.setMul4(c0, rgb);
    Vec_c99210 c1; c1.setColor(0.0f, 0.05f, DAT_010c6850, 0.0f); c1.setMul4(c1, rgb);
    const ScalarC992 half(0.5f);
    l1.mul4(ScalarC992(0.9f));
    l0.mul4(weight0);
    Vec_c99210 res;
    res.scaled(l0.dot3(n) * half + half, c0);
    res.accumulate(l1.dot3(n) * half + half, c1);
    res.accumulate(ScalarC992(0.05f), rgb);
    res.m_vComponents = _mm_min_ps(_mm_max_ps(res.m_vComponents, (*reinterpret_cast<const ::Vec_c99210 *>(&::DAT_01267e30)).m_vComponents), _mm_set_ps1(1.0f));
    float alpha = (int)(color >> 24) * (double(1.0f / 255.0f));
    unsigned int argb = PackColorBigEndian(res.m_vComponents[0], res.m_vComponents[1], res.m_vComponents[2], alpha);
    (*reinterpret_cast<::C00c98720 * *>(&::DAT_012681e0))->FUN_00c98720(&vertexA, &vertexB, &vertexC, argb, 0, 0);
}
#include "generated/data/havok/physics/dynamics/world/hkpworld.inc"
