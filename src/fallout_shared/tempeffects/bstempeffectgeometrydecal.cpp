
// src/fallout_shared/tempeffects/bstempeffectgeometrydecal.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tempeffects/bstempeffectgeometrydecal.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <windows.h>
#include <new>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/DecalNode.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_0047d370_shell.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004adde0_shell.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_004ee4b0_shell.h"
#include "fnv/decl/FUN_004f00e0_shell.h"
#include "fnv/decl/FUN_00534570_shell.h"
#include "fnv/decl/FUN_006427a0_Class.h"
#include "fnv/decl/FUN_00682810_shell.h"
#include "fnv/decl/FUN_006828a0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00862110_cls.h"
#include "fnv/decl/FUN_008d01e0_Class.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009cdae0_shell.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00a673d0_shell.h"
#include "fnv/decl/FUN_00a674b0_cls.h"
#include "fnv/decl/FUN_00a67720_cls.h"
#include "fnv/decl/FUN_00a81bd0_class.h"
#include "fnv/decl/FUN_00a85580.h"
#include "fnv/decl/GeometryBuilder.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/NiAVObject.h"
#include "fnv/decl/NiGeometryData.h"
#include "fnv/decl/Q67530Cls.h"
#include "fnv/decl/RenderOwner.h"
#include "fnv/decl/S00a67410.h"
#include "fnv/decl/SkinInstance.h"
#include "fnv/decl/TESRegionDataMap.h"
#include "fnv/decl/ThreeByThreeMatrix.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/bhkCharacterController.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043f000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_00534000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00688000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_009e3000.h"
#include "fnv/symbols_00a58000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a85000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01030000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011d6000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f5000.h"
#include "fnv/decl/NiRenderer.h"
#include "fnv/symbols_00683000.h"
#include "fnv/symbols_00685000.h"
#include "fnv/symbols_0109e000.h"
struct NiRTTI
{
};

struct BSTempEffectGeometryDecal
{
    const NiRTTI* FUN_006838a0() const;
};

// @fnv 0x006838a0
const NiRTTI* BSTempEffectGeometryDecal::FUN_006838a0() const
{
    return &(*reinterpret_cast<const ::NiRTTI *>(&::g_011d6b04));
}

extern unsigned char* DAT_011f5b04;

// @fnv 0x00683a60
unsigned char* FUN_00683a60()
{
    return DAT_011f5b04;
}


// @fnv 0x00685d20
void __cdecl ForwardFloatAndInt(float afValue, int aiValue)
{
    ::PowFloat(afValue, aiValue);
}

struct NiFixedString;


// @fnv 0x00688460
NiFixedString* __cdecl FUN_00688460()
{
    return ::DAT_011c6228;
}

struct GlobalObjectO2_00a7b610
{
    int dummy;
};
GlobalObjectO2_00a7b610 g_011f5b2c;

struct FUN_00688590_shell
{
    GlobalObjectO2_00a7b610* GetRTTI() const;
};

// @fnv 0x00688590
GlobalObjectO2_00a7b610* FUN_00688590_shell::GetRTTI() const
{
    return &g_011f5b2c;
}

struct BSDismemberSkinInstance
{
    void* FUN_006885e0(unsigned int);
    void FUN_00688610();
};


// Calls FUN_00688610, then if bit 0 of flags is set calls __Dummy_00b6fef0 with this and 0x40, and returns this.
// @fnv 0x006885e0
void* BSDismemberSkinInstance::FUN_006885e0(unsigned int flags)
{
    FUN_00688610();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x40);
    return this;
}

struct FUN_00685e60_shell
{
    void FUN_00685e60(unsigned int, unsigned int);
};

// @fnv 0x00685e60
void FUN_00685e60_shell::FUN_00685e60(unsigned int a, unsigned int b)
{
    *(unsigned int*)(this + 0x0C) = a;
    *(unsigned int*)(this + 0x08) = b;
}

struct NiSkinInstance
{
    void* FUN_006885a0(unsigned int flags);
};
// Calls FUN_00a85580, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x006885a0
void* NiSkinInstance::FUN_006885a0(unsigned int flags)
{
    reinterpret_cast<::FUN_00a85580 *>((this))->FUN_00a85580::~FUN_00a85580();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x34);
    return this;
}

void __cdecl FUN_00688770();
struct FUN_006838d0_shell
{
    void FUN_00688770();
    void* FUN_006838d0(unsigned int flags);
};
// Calls FUN_00688770 on this, then deletes this with size 100 when flags has bit 0 set, and returns this.
// @fnv 0x006838d0
void* FUN_006838d0_shell::FUN_006838d0(unsigned int flags)
{
    this->FUN_00688770();
    if (flags & 1)
        ::FUN_00aa1460(this, 100);
    return this;
}

struct FUN_00685d40_shell
{
    void* ResetToZero();
};

// Sets the four floats at offsets 0x0, 0x4, 0x8 and 0xc of this object to 0.0f and returns this.
// @fnv 0x00685d40
void* FUN_00685d40_shell::ResetToZero()
{
    *(float*)((char*)this + 0xc) = 0.0f;
    *(float*)((char*)this + 0x8) = 0.0f;
    *(float*)((char*)this + 0x4) = 0.0f;
    *(float*)((char*)this + 0x0) = 0.0f;
    return this;
}

struct TESActorBaseData
{
    unsigned short GetFatigue() const;
};
struct BSThread
{
};
struct RefObj
{
};
struct Class87d40
{
    void ForwardActorBaseData(void*, intptr_t, intptr_t, int, int, int);
};
// Calls FUN_00a855f0 with the object reference, thread ID and fatigue obtained from a1, plus a2 through a6.
// @fnv 0x00687d40
void Class87d40::ForwardActorBaseData(void* apObject, intptr_t aiArg2, intptr_t aiArg3, int aiArg4, int aiArg5,
                                                 int aiArg6)
{
    reinterpret_cast<::SkinInstance *>(this)->FUN_00a855f0((const ::NiPoint3 *)(void *)(((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((RefObj*)apObject)))->FUN_007af430()))), (const ::NiPoint3 *)(reinterpret_cast<::ActorMover *>((((BSThread*)apObject)))->GetCurrentMoveModeType()),
                 ((TESActorBaseData*)apObject)->GetFatigue(), (::NiPoint3 *)(aiArg2), (::NiPoint3 *)(aiArg3), (::NiPoint3 *)(aiArg4), (::NiPoint3 *)(aiArg5), aiArg6);
}

struct NineDwords688430
{
    int v[9];
};
struct FUN_00688430_shell
{
    char _pad[0x68];
    NineDwords688430 data;
    void FUN_00688430(NineDwords688430* src);
};
// Copies the nine dwords from src into the data member at offset 0x68.
// @fnv 0x00688430
void FUN_00688430_shell::FUN_00688430(NineDwords688430* apSource)
{
    data = *apSource;
}

extern int DAT_01069a84;
struct FUN_00688470_shell
{
    void* FUN_006884c0(int a, int b, int c);
    void* ConstructShell(int a, int b, int c, int d, int e);
};
extern int DAT_01069a84;

// @fnv 0x00688610
void BSDismemberSkinInstance::FUN_00688610()
{
    *reinterpret_cast<int**>(this) = &DAT_01069a84;
    if (*reinterpret_cast<void***>(reinterpret_cast<char*>(this) + 0x38))
    {
        void* p = *reinterpret_cast<void***>(reinterpret_cast<char*>(this) + 0x38);
        ::FUN_00401030(p);
        *reinterpret_cast<void***>(reinterpret_cast<char*>(this) + 0x38) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x34) = 0;
    }
    reinterpret_cast<::FUN_00a85580 *>((reinterpret_cast<NiSkinInstance*>(this)))->FUN_00a85580::~FUN_00a85580();
}

struct Flt
{
    operator unsigned int();
};
struct CtlV
{
};
struct FUN_00688730_shell
{
    CtlV* GetNextIfSet();
};
// Returns the result of GetNext on the CtlV stored at offset 0xb8 when that pointer is non-null, otherwise returns 0.
// @fnv 0x00688730
CtlV* FUN_00688730_shell::GetNextIfSet()
{
    if ((unsigned int)(*(Flt*)((char*)this + 0xb8)))
        return ((::CtlV *)(::fnv_004a8a90::FUN_004a8a90((char *)(((CtlV*)(unsigned int)(*(Flt*)((char*)this + 0xb8)))))));
    return 0;
}

struct Point
{
    float x, y, z;
};
struct Decal
{
    bool FUN_00683a70(int, int, bool, const unsigned short*, const Point*, const unsigned short*);
};
// @fnv 0x00683a70
bool Decal::FUN_00683a70(int triangle, int base, bool strip, const unsigned short* indices, const Point* vertices,
                         const unsigned short* remap)
{
    int flags;
    {
        bool result = false;
        flags = 0;
        for (int i = 0; i < 3; ++i)
        {
            int inside;
            {
                unsigned short vertex = 0;
                inside = 0;
                if (strip)
                    vertex = indices[triangle + i] + base;
                else
                    vertex = indices[triangle * 3 + i] + base;
                if (remap)
                    vertex = remap[vertex];
                if (vertices[vertex].x < 0.0)
                    flags |= 1;
                else if (vertices[vertex].x > 1.0)
                    flags |= 2;
                else
                    ++inside;
                if (vertices[vertex].y < 0.0)
                    flags |= 4;
                else if (vertices[vertex].y > 1.0)
                    flags |= 8;
                else
                    ++inside;
                if (vertices[vertex].z > 0.10000000149011612)
                {
                    flags |= 16;
                    ++inside;
                }
                if (inside == 3)
                    return true;
            }
        }
        if (((flags & 3) == 3 || (flags & 12) == 12) && (flags & 16))
            result = true;
        return result;
    }
}

struct DtorOwner00685e80
{
    void FUN_00a81bd0();
};
typedef void (DtorOwner00685e80::*DtorMemberPointer)();
extern void FUN_0065ee50_Helper(void* object, unsigned int size, int count, DtorMemberPointer destructor);
struct FUN_00685e80_Class
{
    void* DestroyOrFree(unsigned int flags);
};
// @fnv 0x00685e80
void* FUN_00685e80_Class::DestroyOrFree(unsigned int flags)
{
    if (flags & 2)
    {
        FUN_0065ee50_Helper(this, 0x2c, *(int*)((char*)this - 4), &DtorOwner00685e80::FUN_00a81bd0);
        if (flags & 1)
            ::FUN_00401030((char*)this - 4);
        return (char*)this - 4;
    }
    reinterpret_cast<::FUN_00a81bd0_class *>((((DtorOwner00685e80*)this)))->FUN_00a81bd0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Candidate for claim clm_74791658c0c54ad694b5: ReadWeights, 165 bytes.
struct VecOwner
{
    float* GetElem(int i);
};
struct Calc
{
    int m0;  // +0
    int m4;  // +4
    void Helper(int a);
    void ReadWeights(int a, VecOwner* b);
};
void Calc::Helper(int a)
{}
float* VecOwner::GetElem(int i)
{
    return 0;
}
// @fnv 0x00685d70
void Calc::ReadWeights(int aiIndex, VecOwner* apOwner)
{
    reinterpret_cast<::FUN_004534f0_shell *>(this)->FUN_004534f0(aiIndex);
    int iAddress = aiIndex * this->m4 + this->m0;
    float f, g;
    float* pFloats;
    pFloats = (float*)iAddress;
    f = pFloats[0];
    g = 1.0f - f;
    *((float *)&(reinterpret_cast<::bhkCharacterController *>((apOwner))->GetVectorElement(0))) = f;
    f = pFloats[1];
    g = g - f;
    *((float *)&(reinterpret_cast<::bhkCharacterController *>((apOwner))->GetVectorElement(1))) = f;
    f = pFloats[2];
    g = g - f;
    *((float *)&(reinterpret_cast<::bhkCharacterController *>((apOwner))->GetVectorElement(2))) = f;
    *((float *)&(reinterpret_cast<::bhkCharacterController *>((apOwner))->GetVectorElement(3))) = g;
}

struct Cell4
{
    unsigned int value;
};

struct FUN_00685e20_cls
{
    int m_base;
    int m_iElementIndex;
    void GetCellAt(int index, Cell4* out);
};

// @fnv 0x00685e20
void FUN_00685e20_cls::GetCellAt(int index, Cell4* out)
{
    reinterpret_cast<::FUN_004534f0_shell *>(this)->FUN_004534f0(index);
    Cell4* p = (Cell4*)(m_base + index * m_iElementIndex);
    *out = *p;
}

struct SpawnBase
{
    SpawnBase();
    virtual ~SpawnBase();
    int unk04;
};

struct SpawnFieldA
{
    SpawnFieldA(int a1);
    int unk00;
    ~SpawnFieldA();
};

struct SpawnFieldB
{
    int unk00;
    SpawnFieldB(int a1);
};

struct FUN_006884c0 : SpawnBase
{
    virtual void unk08();
    virtual ~FUN_006884c0();

    SpawnFieldA m_08;
    SpawnFieldB m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;

    FUN_006884c0(int a1, int a2, int a3);
};
// Calls FUN_006884c0 with a, b, c, then sets the vtable, stores e at +0x34 and d at +0x38, sets the byte at +0x3c to 1, and returns this.
// @fnv 0x00688470
void* FUN_00688470_shell::ConstructShell(int aiArg1, int aiArg2, int aiArg3, int aiValue38, int aiValue34)
{
    new ((void *)this) ::FUN_006884c0(aiArg1, aiArg2, aiArg3);
    *(int*)this = (int)&DAT_01069a84;
    *(int*)((char*)this + 0x34) = aiValue34;
    *(int*)((char*)this + 0x38) = aiValue38;
    *(char*)((char*)this + 0x3c) = 1;
    return this;
}

// @fnv 0x006884c0
FUN_006884c0::FUN_006884c0(int aiFieldA, int aiFieldB, int aiFieldC) : m_08(aiFieldA), m_0c(0)
{
    m_10 = aiFieldB;
    m_14 = aiFieldC;
    m_18 = -1;
    m_1c = 0;
    m_20 = 0;
    m_24 = 0;
    m_28 = 0;
    m_30 = 0;
}

struct A8660Skin;

struct A8660Controller
{
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual bool IsActive();
};

struct A8660Solution
{
};

struct A8660Ref
{
    A8660Solution* m_pObject;

    A8660Solution* operator->();
    void Reset(void* pObject);
};

struct A8660Path
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    bool m_bForced;
    char unk15;
    char unk16;
    char unk17;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    A8660Ref m_spPrimary;
    A8660Ref m_spSecondary;

    void FinalizePath();
};


struct Stateful_cls
{
    int unk00;
};

struct Obj_cls
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
    virtual void v58(void* p);
};

struct Node_cls
{
};

struct DecalEffect_cls
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
    virtual Node_cls* v38();
    int unk04;
    float m_08;
    int unk0c;
    float m_10;
    int unk14;
    int unk18;
    Obj_cls m_1c;
    int unk20;
    int unk24;
    unsigned char m_28;
    int unk2c;
    int unk30;
    Obj_cls m_34;
    bool FUN_006888a0(float f);
};

// If m_28 is clear, runs FUN_006828a0(f), sets a node's 0xbc float to m_10/m_08, and when m_10 > m_08 links m_34/m_1c objects and sets m_28.
// @fnv 0x006888a0
bool DecalEffect_cls::FUN_006888a0(float afValue)
{
    Obj_cls* outTmp;
    bool ok5;
    Stateful_cls* aSt;
    Node_cls* node7;
    Stateful_cls* t_;
    if (m_28 != 0)
    {
        return false;
    }
    ok5 = reinterpret_cast<::FUN_006828a0_shell *>(this)->FUN_006828a0(afValue);
    node7 = v38();
    t_ = ((::Stateful_cls *)(reinterpret_cast<::FUN_00a59d30_C *>((node7))->FUN_00a59d30(3)));
    aSt = t_;
    *(float*)((char*)aSt + 0xbc) = m_10 / m_08;
    if (m_10 > m_08)
    {
        outTmp = 0;
        if (((::Obj_cls *)(::FUN_00559450((int *)&(m_34)))) != 0)
        {
            ((::Obj_cls *)(::FUN_00559450((int *)&(m_34))))->v58(((::Obj_cls *)(::FUN_00559450((int *)&(m_1c)))));
            if (((::Obj_cls *)(reinterpret_cast<::FUN_009611e0_shell *>((((::Obj_cls *)(::FUN_00559450((int *)&(m_34))))))->FUN_009611e0())) != 0)
            {
                outTmp = ((::Obj_cls *)(reinterpret_cast<::FUN_009611e0_shell *>((((::Obj_cls *)(::FUN_00559450((int *)&(m_34))))))->FUN_009611e0()));
                reinterpret_cast<::DecalNode *>((outTmp))->RemoveEffect(this);
            }
        }
        if (outTmp != 0)
        {
            if (reinterpret_cast<::FUN_00453470_shell *>((((::Obj_cls *)(::FUN_00559450((int *)&(m_34))))))->FUN_00453470() == 0)
            {
                ((::Obj_cls *)(reinterpret_cast<::FUN_009611e0_shell *>((((::Obj_cls *)(::FUN_00559450((int *)&(m_34))))))->FUN_009611e0()))->v58(((::Obj_cls *)(::FUN_00559450((int *)&(m_34)))));
                DAT_011c57f0 = DAT_011c57f0 - 1;
            }
        }
        m_28 = 1;
    }
    return ok5;
}

struct GlobalRuntime
{
};

struct FeatureState
{
    unsigned char* FUN_00408d60();
};

extern char str_01069ba0;


typedef unsigned int(* VirtualQuery_fn)(void* object);

struct RuntimeController
{
    unsigned short GetRuntimeFlags();
};

// Builds a flags value from DAT_011de45c state and, when DAT_011de4e8 is set, logs details of the current object via FUN_0040fbe0.
// @fnv 0x00688a10
unsigned short RuntimeController::GetRuntimeFlags()
{
    unsigned short usFlags = 0;
    unsigned short usInitialFlags = usFlags;

    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::GlobalRuntime * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        usFlags += 4;
        usFlags += 2;
    }

    if (*(*reinterpret_cast<::FeatureState *>(&::g_011de4e8)).FUN_00408d60())
    {
        char* current = ((char *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::GlobalRuntime * *>(&::g_TESSaveLoadGame))))->GetHitSound()));
        if (current)
        {
            void* related = ((void *)(::FUN_004839c0((unsigned int)(std::uintptr_t)(*reinterpret_cast<void**>(current)))));
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    return usFlags;
}

struct NiPoint3
{
    float x;
    float y;
    float z;
public:
    ::NiPoint3 &Subtract(const ::NiPoint3 &);
public:
    static const ::NiPoint3 ZERO;
};
struct Pt3Obj
{
    float x;
    float y;
    float z;
};
struct ArrayPoint : Pt3Obj
{
    ArrayPoint();
};
struct Pt3Arr
{
    float x;
    float y;
    float z;
    Pt3Arr();
};
float __cdecl FUN_00408840(float a);
struct Calc685
{
    static float ForwardFloatAndInt(float f, int i);
};
struct Obj16
{
    float x;
    float y;
    float z;
    float w;
    Obj16();
};
struct Obj4c
{
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
    void* m_44;
    unsigned short m_48;
    unsigned short m_4a;
    Obj4c();
};
struct Pair8
{
    unsigned short w;
    unsigned short p;
    float f;
    Pair8();
};
struct BigObj2c
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    int m_18;
    unsigned short m_1c;
    unsigned short m_1e;
    unsigned short m_20;
    unsigned short m_22;
    unsigned short m_24;
    unsigned short p26;
    int m_28;
    BigObj2c();
    ~BigObj2c();
};
struct Obj18c
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    Obj18c();
};
extern void(__cdecl* DAT_00fdf0c8)();
struct BSString
{
    char* m_p;
};
struct GeomObj
{
};
struct CtrlObj
{
};
struct SkinBase
{
};
struct NineDw
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
};
struct ThirteenDw
{
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
};
struct ConvObjA
{
};
struct ConvObjB
{
};
struct Obj1bc
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    NiPoint3 FUN_004b4500(NiPoint3* in);
};
struct SphB
{
    Pt3Obj m_afExtents;
    int m_0c;
    int m_10;
    int m_14;
};
struct SphA
{
    Pt3Obj m_afExtents;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
};
struct RetC4
{
    RetC4(const RetC4&);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
};
RetC4 __cdecl FUN_00c4b600(NiPoint3 pt);
struct SphC
{
    Pt3Obj m_afExtents;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    SphA FUN_0043f8d0(const RetC4& r);
};
struct Src38
{
    int m_00;
    int m_04;
    int m_08;
};
struct Obj160
{
    int m_00;
    int m_04;
    int m_08;
};
struct Small
{
    int m_00;
    int m_04;
    int m_08;
};
struct ChainObj
{
};
struct MidObj
{
};
struct Entry4
{
    unsigned char b0;
    unsigned char b1;
    unsigned short w;
};
struct SavedObj
{
};
struct Ctrl150
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    short s20;
    unsigned short m_22;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
};
struct CtrlHolder
{
};
struct SkinMid
{
};
struct XD8Obj
{
};
struct BigEntry
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    unsigned short s1c;
    unsigned short m_1e;
    unsigned short t20;
    unsigned short m_22;
    unsigned short t24;
    unsigned short m_26;
    int t28;
};
struct ThisObj
{
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
    BSString m_2c;
    int m_30;
    int m_34;
    Src38 m_38;
    NiPoint3 m_44;
    float m_50;
    float m_54;
    int m_58;
    int m_5c;
    int m_60;
    void BuildSkinPartitions();
};
struct DPoint
{
    float x, y, z;
    DPoint();
};
struct DMatrix
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    DMatrix();
    DPoint FUN_004b4500(const DPoint*);
    DMatrix FUN_0043f8d0(const DMatrix*);
};
struct DTransform
{
    DMatrix rotation;
    DPoint position;
    float scale;
};
struct DPartition
{
    int unk00;
    unsigned short* bones;
    float* weights;
    unsigned short* vertexMap;
    unsigned char* boneIndices;
    unsigned short* triangles;
    int unk18;
    unsigned short vertexCount, triangleCount, boneCount, stripCount, weightsPerVertex, unk26;
    int unk28;
    DPartition();
    ~DPartition();
};
struct DBoneWeight
{
    unsigned short index, unk02;
    float weight;
    DBoneWeight();
};
struct DBone
{
    DTransform transform;
    int unk34, unk38, unk3c, unk40;
    DBoneWeight* weights;
    unsigned short count, unk4a;
    DBone();
};
struct DPartitionFlag
{
    unsigned char enabled, unk01;
    unsigned short bodyPart;
};
struct DPartitionData
{
};
struct DSkinData
{
};
struct DSkin
{
};
struct DGeometryData
{
    unsigned short FUN_004a8ae0();
};
struct DGeometry
{
    DTransform& FUN_00461130();
};
struct DGeometryRef
{
};
struct DNewPartition
{
    int unk00, unk04, unk08, unk0c;
    DNewPartition();
};
DMatrix __cdecl FUN_00c4b600(DPoint);
float __cdecl DecalPower(float, int);
float __cdecl FloatAbs(float);
struct DDecal
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    DGeometryRef geometry;
    int unk30, unk34;
    DPoint position;
    DPoint direction;
    float size, angle;
    int unk58, vertexCount, bodyParts;
    void CreateDecalGeometry(DGeometry*, unsigned short, unsigned short, DPoint*, DPoint*, unsigned short*, DBone*,
                             DNewPartition*, unsigned short*);
    void BuildDecalGeometry();
};
// @fnv 0x00688660
void A8660Path::FinalizePath()
{
    if (!((::A8660Skin *)(::fnv_0043fad0::FUN_0043fad0((const char *)((m_spPrimary).operator->())))))
        return;
    if (!m_bForced)
    {
        if (((unsigned int)(reinterpret_cast<::Callees *>(((m_spSecondary).operator->()))->FUN_00726070())) > 1 && ((unsigned int)(reinterpret_cast<::Callees *>(((m_spPrimary).operator->()))->FUN_00726070())) > 1)
        {
            A8660Controller* pkController = ((::A8660Controller *)(reinterpret_cast<::FUN_00688730_shell *>(((m_spPrimary).operator->()))->GetNextIfSet()));
            if (pkController && pkController->IsActive())
                reinterpret_cast<::ThisObj *>(this)->BuildSkinPartitions();
            else
                reinterpret_cast<::DDecal *>(this)->BuildDecalGeometry();
        }
    }
    reinterpret_cast<::FUN_00682810_shell *>(this)->FUN_00682810();
    m_spPrimary.Reset(0);
    m_spSecondary.Reset(0);
}
// Builds per-part skin partition data from the skin instance and control tables, then passes the assembled arrays to CreateDecalGeometry.
// @fnv 0x00683c10
void ThisObj::BuildSkinPartitions()
{
    unsigned short* a1c4LocalAF;
    float* a1c0LocalAN;
    Obj1bc obj1bcLocalAE;
    Obj4c* arr198LocalAB;
    int count194LocalBA;
    int* a190LocalAI;
    Obj18c* x18cLocalCE;
    void* savedLocalAB;
    ThirteenDw thirteenLocalAI;
    Ctrl150* ctrl150LocalAG;
    int total14cLocalAC;
    unsigned short* a148LocalAD;
    void* p144LocalEF;
    int z140LocalBM;
    int flag13cLocalAL;
    NineDw nineLocalBC;
    unsigned char* a114LocalBI;
    unsigned short word110LocalBC;
    Pt3Arr* arr10cLocalAB;
    Pt3Obj sph2LocalAI;
    int cntFcLocalBB;
    unsigned short* aF8LocalBB;
    unsigned short wordF4LocalAD;
    unsigned int flagsLocalBC;
    unsigned char byteE9LocalBH;
    Pt3Obj* arrE8LocalFA;
    NiPoint3 ptE4LocalAB;
    void* xD8LocalDC;
    int* aD4LocalAA;
    unsigned short* aD0LocalBA;
    Pt3Obj ptCCLocalAD;
    int cntC0LocalBB;
    SphC sph3LocalCK;
    Small s3LocalBN;
    unsigned char byte89LocalAD;
    int cnt88LocalFB;
    SphA sph1LocalAC;
    Small s4LocalAA;
    BigObj2c* arr54LocalAD;
    Pt3Obj pt50LocalAN;
    Small s2LocalAK;
    void* data38LocalAM;
    Pt3Arr* arr34LocalCA;
    NiSkinInstance* skinInstLocalAA;
    Small s1LocalBB;
    Small s5LocalAF;
    unsigned short word14LocalBL;
    Obj16* arr10LocalCD;

    skinInstLocalAA = ((::NiSkinInstance *)(::fnv_0043fad0::FUN_0043fad0((const char *)(((GeomObj*)((const char *)(::FUN_00559450((int *)&(m_2c)))))))));
    savedLocalAB = 0;
    if (((unsigned char)(::fnv_0045bad0::FUN_0045bad0((const ::fnv_0045bad0::NiRTTI *)(::GlobalObjectO2_00a7b610 *)(&::g_011f49d8), (const ::fnv_0045bad0::NiObject *)(skinInstLocalAA)))))
        savedLocalAB = skinInstLocalAA;
    else
        return;
    flagsLocalBC = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((::CtrlObj *)(::fnv_0043b230::FUN_0043b230((const char *)(((SkinBase*)skinInstLocalAA)))))))->GetName()));


    nineLocalBC = *((::NineDw *)(::FUN_00461130((std::intptr_t)(((ConvObjA*)((const char *)(::FUN_00559450((int *)&(m_2c)))))))));

    reinterpret_cast<::ThreeByThreeMatrix *>(&(nineLocalBC))->FUN_004b45b0((::ThreeByThreeMatrix *)(void *)(&obj1bcLocalAE));

    *(NiPoint3*)&sph2LocalAI = obj1bcLocalAE.FUN_004b4500(&m_44);

    reinterpret_cast<::FUN_004a0c90_shell *>(&(sph3LocalCK))->FUN_004a0c90(m_54);
    sph1LocalAC = sph3LocalCK.FUN_0043f8d0(FUN_00c4b600(m_44));

    thirteenLocalAI = *((::ThirteenDw *)(::FUN_00461130((std::intptr_t)(((ConvObjB*)((const char *)(::FUN_00559450((int *)&(m_2c)))))))));
    reinterpret_cast<::NiPoint3 *>((((Obj160*)&thirteenLocalAI.m_24)))->Subtract((*(const ::NiPoint3 *)(&m_38)));

    ::FUN_00534550((::PathingActorData *)&(s1LocalBB));
    ::FUN_00534550((::PathingActorData *)&(s2LocalAK));
    ::FUN_00534550((::PathingActorData *)&(s3LocalBN));
    ::FUN_00534550((::PathingActorData *)&(s4LocalAA));
    ::FUN_00534550((::PathingActorData *)&(s5LocalAF));
    p144LocalEF = ((void *)(::fnv_004a8a90::FUN_004a8a90((char *)(((::ChainObj *)(::fnv_005495f0::FUN_005495f0((const char *)(((MidObj*)((const char *)(::FUN_00559450((int *)&(m_2c)))))))))))));
    z140LocalBM = 0;
    data38LocalAM = 0;
    arr198LocalAB = 0;
    xD8LocalDC = 0;
    ctrl150LocalAG = 0;
    (void)p144LocalEF;
    (void)z140LocalBM;
    data38LocalAM = (void*)((int)(reinterpret_cast<::LowProcess *>((((XD8Obj*)((void *)(reinterpret_cast<::TESRegionDataMap *>((((SkinMid*)skinInstLocalAA)))->GetRegionMapName())))))->GetTarget()));
    if (data38LocalAM == 0)
        return;
    cntFcLocalBB = (int)reinterpret_cast<::FUN_0047d370_shell *>((((ChainObj*)p144LocalEF)))->FUN_0047d370();
    byteE9LocalBH = ((unsigned char)(reinterpret_cast<::NiGeometryData *>((((::ChainObj *)(::fnv_005495f0::FUN_005495f0((const char *)(((MidObj*)((const char *)(::FUN_00559450((int *)&(m_2c)))))))))))->IsGeometryDataStreamable(0)));
    reinterpret_cast<::S00a67410 *>((((::ChainObj *)(::fnv_005495f0::FUN_005495f0((const char *)(((MidObj*)((const char *)(::FUN_00559450((int *)&(m_2c)))))))))))->FUN_00a67410((::BSFaceGenMorphData *)(::Small *)(&s1LocalBB));
    reinterpret_cast<::RenderOwner *>((((::ChainObj *)(::fnv_005495f0::FUN_005495f0((const char *)(((MidObj*)((const char *)(::FUN_00559450((int *)&(m_2c)))))))))))->GetBounds((::BoundOut *)(::Small *)(&s2LocalAK));
    reinterpret_cast<::FUN_00a67720_cls *>((((::ChainObj *)(::fnv_005495f0::FUN_005495f0((const char *)(((MidObj*)((const char *)(::FUN_00559450((int *)&(m_2c)))))))))))->GetKeyAndMode(0, (::FUN_00a67720_res *)(::Small *)(&s3LocalBN));
    reinterpret_cast<::FUN_00a674b0_cls *>((((::ChainObj *)(::fnv_005495f0::FUN_005495f0((const char *)(((MidObj*)((const char *)(::FUN_00559450((int *)&(m_2c)))))))))))->GetOutRec((::OutRec674 *)(::Small *)(&s4LocalAA));
    reinterpret_cast<::Q67530Cls *>((((::ChainObj *)(::fnv_005495f0::FUN_005495f0((const char *)(((MidObj*)((const char *)(::FUN_00559450((int *)&(m_2c)))))))))))->FillOutRec674((::OutRec674 *)(::Small *)(&s5LocalAF));
    word110LocalBC = 0;
    byte89LocalAD = 0;
    count194LocalBA = 0;
    ctrl150LocalAG = ((::Ctrl150 *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((CtrlHolder*)((::CtrlObj *)(::fnv_0043b230::FUN_0043b230((const char *)(((SkinBase*)skinInstLocalAA))))))))->FUN_0084e3a0()));
    flag13cLocalAL = ctrl150LocalAG->m_22 > 0;
    (void)flag13cLocalAL;
    for (int iValueDA = 0; iValueDA < (int)flagsLocalBC; iValueDA = iValueDA + 1)
    {
        {
            unsigned short wordD4ValueBD;
            unsigned char byteCDValueAL;
            int intCCValueDC;

            byteCDValueAL = ((::Entry4 *)(::GetField38((char *)(((SavedObj*)savedLocalAB)))))[iValueDA].b0;
            wordD4ValueBD = ((::Entry4 *)(::GetField38((char *)(((SavedObj*)savedLocalAB)))))[iValueDA].w;
            if ((int)wordD4ValueBD > 1000)
                wordD4ValueBD = (unsigned short)((int)wordD4ValueBD / 1000);
            else if ((int)wordD4ValueBD > 100)
            {
                while ((int)wordD4ValueBD > 100)
                    wordD4ValueBD = (unsigned short)(wordD4ValueBD - 100);
            }
            intCCValueDC = (int)wordD4ValueBD;
            if (byteCDValueAL != 0)
            {
                if ((1 << (intCCValueDC + 1)) & m_60)
                {
                    byte89LocalAD = 1;
                    word110LocalBC += ((BigEntry*)ctrl150LocalAG)[iValueDA].m_1e;
                    count194LocalBA = count194LocalBA + 1;
                }
            }
        }
    }

    if (!byte89LocalAD)
        return;
    total14cLocalAC = (int)word110LocalBC * 3;
    aF8LocalBB = new unsigned short[total14cLocalAC];
    aD4LocalAA = new int[cntFcLocalBB];
    word14LocalBL = 0;
    (void)word14LocalBL;
    a1c4LocalAF = new unsigned short[total14cLocalAC];
    aD0LocalBA = new unsigned short[cntFcLocalBB];
    a190LocalAI = new int[cntFcLocalBB];
    cnt88LocalFB = count194LocalBA;
    a148LocalAD = new unsigned short[count194LocalBA];
    a1c0LocalAN = new float[cntFcLocalBB * 4];
    a114LocalBI = new unsigned char[cntFcLocalBB * 4];
    FUN_00403d30(aD4LocalAA, -1, cntFcLocalBB << 2);
    arr54LocalAD = new BigObj2c[count194LocalBA];
    arr34LocalCA = new Pt3Arr[cntFcLocalBB];
    arr10LocalCD = new Obj16[cntFcLocalBB];
    arr10cLocalAB = 0;
    arrE8LocalFA = 0;
    arr10cLocalAB = new Pt3Arr[cntFcLocalBB];
    arrE8LocalFA = (Pt3Obj*)new ArrayPoint[cntFcLocalBB];
    ::FUN_00a85510((int)(((SkinMid*)skinInstLocalAA)), (int)(&s1LocalBB), (int)(&s4LocalAA), (int)(&s5LocalAF), (int)(&s2LocalAK), cntFcLocalBB, (int)(arr10cLocalAB), (int)(arrE8LocalFA));
    xD8LocalDC = ((void *)(reinterpret_cast<::TESRegionDataMap *>((((SkinMid*)skinInstLocalAA)))->GetRegionMapName()));
    data38LocalAM = (void*)((int)(reinterpret_cast<::LowProcess *>((((XD8Obj*)xD8LocalDC)))->GetTarget()));
    z140LocalBM = ((int)(reinterpret_cast<::LowProcess *>((((XD8Obj*)xD8LocalDC)))->GetActiveCombatTarget()));
    arr198LocalAB = new Obj4c[z140LocalBM];
    for (int jValueBA = 0; jValueBA < z140LocalBM; jValueBA = jValueBA + 1)
    {
        {
            Obj4c* dstValueBG;

            dstValueBG = (Obj4c*)((char*)arr198LocalAB + jValueBA * 0x4c);
            *(ThirteenDw*)dstValueBG = *(ThirteenDw*)&((Obj4c*)data38LocalAM)[jValueBA];
            if (jValueBA == 0)
                dstValueBG->m_44 = new Pair8[cntFcLocalBB * 4];
            else
                dstValueBG->m_44 = new Pair8[cntFcLocalBB];
        }
    }

    ptE4LocalAB = *(NiPoint3*)&sph2LocalAI;


    for (int kValueBC = 0; kValueBC < cntFcLocalBB; kValueBC = kValueBC + 1)
    {
        {
            float tmp200ValueAC;
            NiPoint3 gPtAValueAG;
            NiPoint3 gPtBValueBI;
            float tmp1e4ValueAC;

            gPtAValueAG = ::NiPoint3::ZERO;
            *(NiPoint3*)&pt50LocalAN = *(NiPoint3*)&arr10cLocalAB[kValueBC];
            *(NiPoint3*)&ptCCLocalAD = *(NiPoint3*)&arrE8LocalFA[kValueBC];
            reinterpret_cast<::Calc *>(&(s4LocalAA))->ReadWeights(kValueBC, (::VecOwner *)(void *)(&arr10LocalCD[kValueBC]));
            tmp200ValueAC = arr10LocalCD[kValueBC].x + arr10LocalCD[kValueBC].y + arr10LocalCD[kValueBC].z;
            arr10LocalCD[kValueBC].w = 1.0f - tmp200ValueAC;
            if ((double)arr10LocalCD[kValueBC].w < DAT_01030f28)
                arr10LocalCD[kValueBC].w = 0.0f;
            reinterpret_cast<::MyPoint439180 *>(&(pt50LocalAN))->FUN_00439180(*(float*)&thirteenLocalAI.m_30);
            gPtBValueBI = ::NiPoint3::ZERO;
            ::FUN_00a582f0((const float *)(void *)(&thirteenLocalAI), (const float *)(void *)(&thirteenLocalAI.m_24), 1, (const ::Point314 *)(void *)(&pt50LocalAN), (::Point314 *)(void *)(&gPtBValueBI));
            ::FUN_00a582f0((const float *)(void *)(&sph1LocalAC), (const float *)(void *)(&::NiPoint3::ZERO), 1, (const ::Point314 *)(void *)(&gPtBValueBI), (::Point314 *)(void *)(&gPtAValueAG));
            arr34LocalCA[kValueBC].x = gPtAValueAG.x / m_50 + 0.5f;
            arr34LocalCA[kValueBC].y = gPtAValueAG.y / m_50 + 0.5f;
            tmp1e4ValueAC = 1.0f - FUN_00404010(0.0f, reinterpret_cast<::FUN_004b6190_shell *>(&(ptE4LocalAB))->DotProduct((NiPoint3*)&ptCCLocalAD));
            arr34LocalCA[kValueBC].z =
                Calc685::ForwardFloatAndInt(tmp1e4ValueAC, 10) * (1.0f - FUN_00408840(gPtAValueAG.z) / 256.0f);
        }
    }

    wordF4LocalAD = 0;
    cntC0LocalBB = 0;
    count194LocalBA = 0;
    for (int mValueBC = 0; mValueBC < (int)flagsLocalBC; mValueBC = mValueBC + 1)
    {
        {
            unsigned short* x214ValueAG;
            unsigned short wordD4bValueBD;
            unsigned char byteCD2ValueAH;
            int intCC2ValueAH;

            x214ValueAG = 0;
            byteCD2ValueAH = ((::Entry4 *)(::GetField38((char *)(((SavedObj*)savedLocalAB)))))[mValueBC].b0;
            wordD4bValueBD = ((::Entry4 *)(::GetField38((char *)(((SavedObj*)savedLocalAB)))))[mValueBC].w;
            if ((int)wordD4bValueBD > 1000)
                wordD4bValueBD = (unsigned short)((int)wordD4bValueBD / 1000);
            else if ((int)wordD4bValueBD > 100)
            {
                while ((int)wordD4bValueBD > 100)
                    wordD4bValueBD = (unsigned short)(wordD4bValueBD - 100);
            }
            intCC2ValueAH = (int)wordD4bValueBD;
            if (byteCD2ValueAH != 0)
            {
                if ((1 << (intCC2ValueAH + 1)) & m_60)
                {
                    unsigned short word224ValueAP;
                    int x220ValueAE;
                    int x21cValueBB;
                    unsigned short word218ValueAB;

                    x21cValueBB = ((BigEntry*)ctrl150LocalAG)[mValueBC].t28;
                    (void)x21cValueBB;
                    word110LocalBC = ((BigEntry*)ctrl150LocalAG)[mValueBC].m_1e;
                    if (x214ValueAG == 0)
                        x214ValueAG = (unsigned short*)((BigEntry*)ctrl150LocalAG)[mValueBC].m_14;
                    word218ValueAB = 0;
                    word224ValueAP = 0;
                    (void)word218ValueAB;
                    (void)word224ValueAP;
                    FUN_00403d30(a190LocalAI, -1, cntFcLocalBB << 2);
                    FUN_00403d30(a1c0LocalAN, 0, (cntFcLocalBB << 2) << 2);
                    FUN_00403d30(a114LocalBI, 0, cntFcLocalBB << 2);
                    x220ValueAE = 0;
                    for (int nValueEC = 0; nValueEC < (int)word110LocalBC; nValueEC = nValueEC + 1)
                    {
                        {
                            unsigned char byte236ValueBG;
                            unsigned char byte235ValueBC;
                            unsigned short w234ValueAA;
                            unsigned short w230ValueAH;
                            unsigned short w22cValueAP;

                            byte235ValueBC = 0;
                            byte236ValueBG = 1;
                            w230ValueAH = 0;
                            w22cValueAP = 0;
                            w234ValueAA = 0;
                            if (flag13cLocalAL)
                            {
                                w230ValueAH = (unsigned short)(x214ValueAG[nValueEC] + cntC0LocalBB);
                                w22cValueAP = (unsigned short)(x214ValueAG[nValueEC + 1] + cntC0LocalBB);
                                w234ValueAA = (unsigned short)(x214ValueAG[nValueEC + 2] + cntC0LocalBB);
                            }
                            else
                            {
                                w230ValueAH = (unsigned short)(x214ValueAG[nValueEC * 3] + cntC0LocalBB);
                                w22cValueAP = (unsigned short)(x214ValueAG[nValueEC * 3 + 1] + cntC0LocalBB);
                                w234ValueAA = (unsigned short)(x214ValueAG[nValueEC * 3 + 2] + cntC0LocalBB);
                            }
                            if (w230ValueAH == w22cValueAP || w230ValueAH == w234ValueAA || w22cValueAP == w234ValueAA)
                            {
                                if (flag13cLocalAL)
                                    x220ValueAE = (x220ValueAE == 0);
                                continue;
                            }
                            byte235ValueBC = ((unsigned char)(reinterpret_cast<::Decal *>(this)->FUN_00683a70(nValueEC, cntC0LocalBB, flag13cLocalAL != 0, x214ValueAG,
                                                          (const ::Point *)(::Pt3Obj *)((Pt3Obj*)arr34LocalCA), (const unsigned short *)(0))));
                            if (byte235ValueBC && byte236ValueBG)
                            {
                                {
                                    for (int tValueEC = 0; tValueEC < 3; tValueEC = tValueEC + 1)
                                    {
                                        {
                                            unsigned short w244ValueBP;
                                            unsigned short w240ValueAG;

                                            w240ValueAG = flag13cLocalAL ? x214ValueAG[nValueEC + tValueEC]
                                                                         : x214ValueAG[nValueEC * 3 + tValueEC];
                                            w244ValueBP = (unsigned short)(w240ValueAG + cntC0LocalBB);
                                            if (aD4LocalAA[w244ValueBP] == -1)
                                            {
                                                unsigned char tmp248ValueAJ[4];

                                                aD4LocalAA[w244ValueBP] = (int)word14LocalBL;
                                                aF8LocalBB[wordF4LocalAD] = (unsigned short)word14LocalBL;
                                                wordF4LocalAD++;

                                                reinterpret_cast<::FUN_00685e20_cls *>(&(s5LocalAF))->GetCellAt((int)w244ValueBP, (::Cell4 *)(tmp248ValueAJ));
                                                for (int uValueAA = 0; uValueAA < 4; uValueAA = uValueAA + 1)
                                                {
                                                    if ((double)((float*)&arr10LocalCD[w244ValueBP])[uValueAA] !=
                                                        ::_DAT_01012060)
                                                    {
                                                        unsigned short w254ValueAM;
                                                        Obj4c* elemValueAK;

                                                        w254ValueAM = (unsigned short)tmp248ValueAJ[3 - uValueAA];
                                                        w254ValueAM =
                                                            ((unsigned short*)((BigEntry*)ctrl150LocalAG)[mValueBC]
                                                                 .m_04)[w254ValueAM];
                                                        elemValueAK = &arr198LocalAB[w254ValueAM];
                                                        ((Pair8*)elemValueAK->m_44)[elemValueAK->m_48].w =
                                                            word14LocalBL;
                                                        ((Pair8*)elemValueAK->m_44)[elemValueAK->m_48].f =
                                                            ((float*)&arr10LocalCD[w244ValueBP])[uValueAA];
                                                        elemValueAK->m_48++;
                                                    }
                                                }

                                                word14LocalBL++;
                                            }
                                            else
                                            {
                                                aF8LocalBB[wordF4LocalAD] = (unsigned short)aD4LocalAA[w244ValueBP];
                                                wordF4LocalAD++;
                                            }
                                            if (a190LocalAI[w244ValueBP] == -1)
                                            {
                                                unsigned char tmp258ValueCN[4];

                                                reinterpret_cast<::FUN_00685e20_cls *>(&(s5LocalAF))->GetCellAt((int)w244ValueBP, (::Cell4 *)(tmp258ValueCN));
                                                for (int u2ValueDD = 0; u2ValueDD < 4; u2ValueDD = u2ValueDD + 1)
                                                {
                                                    if ((double)((float*)&arr10LocalCD[w244ValueBP])[u2ValueDD] !=
                                                        ::_DAT_01012060)
                                                    {
                                                        unsigned short w264ValueAE;
                                                        int idx260ValueAD;

                                                        w264ValueAE = (unsigned short)tmp258ValueCN[3 - u2ValueDD];
                                                        idx260ValueAD = (int)word224ValueAP * 4 + u2ValueDD;
                                                        a1c0LocalAN[idx260ValueAD] =
                                                            ((float*)&arr10LocalCD[w244ValueBP])[u2ValueDD];
                                                        a114LocalBI[idx260ValueAD] = (unsigned char)w264ValueAE;
                                                    }
                                                }

                                                a190LocalAI[w244ValueBP] = (int)word224ValueAP;
                                                a1c4LocalAF[word218ValueAB] = (unsigned short)word224ValueAP;
                                                word218ValueAB++;
                                                aD0LocalBA[word224ValueAP] = (unsigned short)aD4LocalAA[w244ValueBP];
                                                word224ValueAP++;
                                            }
                                            else
                                            {
                                                a1c4LocalAF[word218ValueAB] = (unsigned short)a190LocalAI[w244ValueBP];
                                                word218ValueAB++;
                                            }
                                        }
                                    }
                                }
                                if (flag13cLocalAL)
                                {
                                    if (x220ValueAE)
                                    {
                                        int sw274ValueCD;
                                        int sw270ValueCC;
                                        int sw26cValueAA;
                                        int sw268ValueDC;

                                        sw270ValueCC = (int)aF8LocalBB[wordF4LocalAD - 3];
                                        sw274ValueCD = (int)aF8LocalBB[wordF4LocalAD - 1];
                                        aF8LocalBB[wordF4LocalAD - 3] = (unsigned short)sw274ValueCD;
                                        aF8LocalBB[wordF4LocalAD - 1] = (unsigned short)sw270ValueCC;
                                        sw26cValueAA = (int)a1c4LocalAF[word218ValueAB - 3];
                                        sw268ValueDC = (int)a1c4LocalAF[word218ValueAB - 1];
                                        a1c4LocalAF[word218ValueAB - 3] = (unsigned short)sw268ValueDC;
                                        a1c4LocalAF[word218ValueAB - 1] = (unsigned short)sw26cValueAA;
                                    }
                                }
                            }
                        nextN:
                            if (flag13cLocalAL)
                                x220ValueAE = (x220ValueAE == 0);
                        }
                    }

                    if ((int)word224ValueAP > 0)
                    {
                        int tmp278ValueAL;

                        arr54LocalAD[count194LocalBA].m_1e = (unsigned short)((int)word218ValueAB / 3);
                        arr54LocalAD[count194LocalBA].m_14 = FUN_00aa1070((unsigned int)word218ValueAB << 1);
                        ::__memcpy(arr54LocalAD[count194LocalBA].m_14, a1c4LocalAF,
                                     (unsigned int)word218ValueAB << 1);
                        arr54LocalAD[count194LocalBA].m_1c = word224ValueAP;
                        arr54LocalAD[count194LocalBA].m_0c = FUN_00aa1070((unsigned int)word224ValueAP << 1);
                        ::__memcpy(arr54LocalAD[count194LocalBA].m_0c, aD0LocalBA, (unsigned int)word224ValueAP << 1);
                        arr54LocalAD[count194LocalBA].m_20 = (unsigned short)((BigEntry*)ctrl150LocalAG)[mValueBC].t20;
                        arr54LocalAD[count194LocalBA].m_04 =
                            FUN_00aa1070((unsigned int)(unsigned short)((BigEntry*)ctrl150LocalAG)[mValueBC].t20 << 1);
                        ::__memcpy(arr54LocalAD[count194LocalBA].m_04,
                                     (void*)((BigEntry*)ctrl150LocalAG)[mValueBC].m_04,
                                     (unsigned int)(unsigned short)((BigEntry*)ctrl150LocalAG)[mValueBC].t20 << 1);
                        arr54LocalAD[count194LocalBA].m_24 = (unsigned short)((BigEntry*)ctrl150LocalAG)[mValueBC].t24;
                        tmp278ValueAL = (int)arr54LocalAD[count194LocalBA].m_24 * (int)word224ValueAP;
                        arr54LocalAD[count194LocalBA].m_08 = FUN_00aa1070((unsigned int)tmp278ValueAL << 2);
                        arr54LocalAD[count194LocalBA].m_10 = FUN_00aa1070((unsigned int)tmp278ValueAL);
                        ::__memcpy(arr54LocalAD[count194LocalBA].m_08, a1c0LocalAN,
                                     (unsigned int)((int)arr54LocalAD[count194LocalBA].m_24 * 4 *
                                                    (int)arr54LocalAD[count194LocalBA].m_1c));
                        ::__memcpy(arr54LocalAD[count194LocalBA].m_10, a114LocalBI,
                                     (unsigned int)((int)arr54LocalAD[count194LocalBA].m_24 *
                                                    (int)arr54LocalAD[count194LocalBA].m_1c));
                        if ((unsigned int)count194LocalBA >= (unsigned int)cnt88LocalFB)
                            DAT_00fdf0c8();
                        a148LocalAD[count194LocalBA] = (unsigned short)wordD4bValueBD;
                        count194LocalBA = count194LocalBA + 1;
                    }
                }
            }
            cntC0LocalBB += ((BigEntry*)ctrl150LocalAG)[mValueBC].s1c;
        }
    }

    delete arr10LocalCD;
    x18cLocalCE = 0;
    if (count194LocalBA > 0)
    {
        x18cLocalCE = new Obj18c;
        reinterpret_cast<::FUN_00685e60_shell *>((x18cLocalCE))->FUN_00685e60((unsigned int)(arr54LocalAD), count194LocalBA);
    }
    if ((int)word14LocalBL > 0)
    {
        unsigned short* x284ValueBI;
        Pt3Obj* x280ValueAD;
        Pt3Obj* x27cValueBB;

        x284ValueBI = new unsigned short[wordF4LocalAD];
        ::__memcpy(x284ValueBI, aF8LocalBB, (unsigned int)wordF4LocalAD << 1);
        x280ValueAD = (Pt3Obj*)new ArrayPoint[word14LocalBL];
        x27cValueBB = (Pt3Obj*)new ArrayPoint[word14LocalBL];
        for (int pValueFC = 0; pValueFC < cntFcLocalBB; pValueFC = pValueFC + 1)
        {
            {
                Pt3Obj t2a0ValueAI;
                Pt3Obj t294ValueAJ;


                if (aD4LocalAA[pValueFC] != -1)
                {
                    reinterpret_cast<::FUN_00534570_shell *>(&(s1LocalBB))->FUN_00534570(pValueFC, (*(::NiPoint3 *)(&t294ValueAJ)));
                    reinterpret_cast<::FUN_00534570_shell *>(&(s2LocalAK))->FUN_00534570(pValueFC, (*(::NiPoint3 *)(&t2a0ValueAI)));
                    x280ValueAD[aD4LocalAA[pValueFC]] = t294ValueAJ;
                    x27cValueBB[aD4LocalAA[pValueFC]] = *(Pt3Obj*)&arr34LocalCA[pValueFC];
                }
            }
        }

        for (int qValueAC = 0; qValueAC < z140LocalBM; qValueAC = qValueAC + 1)
        {
            {
                void* old44ValueHA;
                Obj4c* eValueCC;

                eValueCC = &arr198LocalAB[qValueAC];
                old44ValueHA = eValueCC->m_44;
                arr198LocalAB[qValueAC].m_44 = new Pair8[eValueCC->m_48];
                ::__memcpy(arr198LocalAB[qValueAC].m_44, old44ValueHA, (unsigned int)eValueCC->m_48 << 3);
                delete old44ValueHA;
            }
        }

        if (x18cLocalCE != 0)
            reinterpret_cast<::DDecal *>(this)->CreateDecalGeometry((::DGeometry *)(((const char *)(::FUN_00559450((int *)&(m_2c))))), (int)word14LocalBL, (int)wordF4LocalAD, (::DPoint *)(x280ValueAD), (::DPoint *)(x27cValueBB),
                                x284ValueBI, (::DBone *)(arr198LocalAB), (::DNewPartition *)(x18cLocalCE), a148LocalAD);
        else
            reinterpret_cast<::DDecal *>(this)->CreateDecalGeometry((::DGeometry *)(((const char *)(::FUN_00559450((int *)&(m_2c))))), (int)word14LocalBL, (int)wordF4LocalAD, (::DPoint *)(x280ValueAD), (::DPoint *)(x27cValueBB),
                                x284ValueBI, (::DBone *)(arr198LocalAB), (::DNewPartition *)(void *)(0), 0);
        m_5c = (int)word14LocalBL;
    }
    else
    {
        for (int q2ValueAH = 0; q2ValueAH < z140LocalBM; q2ValueAH = q2ValueAH + 1)
        {
            delete arr198LocalAB[q2ValueAH].m_44;
            arr198LocalAB[q2ValueAH].m_44 = 0;
        }

        delete arr198LocalAB;
    }
    delete arr10cLocalAB;
    delete arrE8LocalFA;
    delete aF8LocalBB;
    delete aD4LocalAA;
    delete arr34LocalCA;
    delete a1c4LocalAF;
    delete aD0LocalBA;
    delete a190LocalAI;
    delete a1c0LocalAN;
    delete a114LocalBI;
    delete a148LocalAD;
    if (byteE9LocalBH)
        reinterpret_cast<::FUN_00a673d0_shell *>((((::ChainObj *)(::fnv_005495f0::FUN_005495f0((const char *)(((MidObj*)((const char *)(::FUN_00559450((int *)&(m_2c)))))))))))->FUN_00a673d0();
    (void)cnt88LocalFB;
    (void)arr54LocalAD;
    (void)ptE4LocalAB;
    (void)cntC0LocalBB;
}
// Projects the skin's vertices onto the decal plane, rebuilds the selected body-part partitions and bones, and passes the new geometry to CreateDecalGeometry.
// @fnv 0x00685ef0
void DDecal::BuildDecalGeometry()
{
    unsigned short* partitionIndices_10;
    float* weights_6;
    DBone* newBones_3;
    int selectedCount_12;
    int* localRemap_40;
    DNewPartition* newPartition_14;
    DSkin* dismember_9;
    DPartition* partitions_15;
    int indexCapacity_4;
    unsigned short* flags_7;
    int boneCount_4;
    int strips_17;
    unsigned short* vertexMap_22;
    unsigned char* boneIndices_1;
    unsigned short triangleCount_33;
    int* remap_1;
    DPoint* positions_6;
    int sourceVertexCount_3;
    unsigned short* indices_3;
    unsigned short indexCount_11;
    int partitionCount_10;
    DPoint* normals_17;
    DSkinData* skinData_1;
    unsigned short* triangleData_17;
    unsigned short* partitionMap_7;
    bool selected_21;
    unsigned int flagCapacity_0;
    DBone* boneData_4;
    DPartition* outputPartitions_22;
    DBone* bones_53;
    DPoint* texcoords_0;
    DSkin* skin_1;
    unsigned short outputVertexCount_4;
    if (bodyParts == 0)
        return;
    skin_1 = ((::DSkin *)(::fnv_0043fad0::FUN_0043fad0((const char *)(((::DGeometry *)(::FUN_00559450((int *)&(geometry))))))));
    dismember_9 = 0;
    if (::fnv_0045bad0::FUN_0045bad0((const ::fnv_0045bad0::NiRTTI *)(::GlobalObjectO2_00a7b610 *)(&::g_011f49d8), (const ::fnv_0045bad0::NiObject *)(skin_1)))
        dismember_9 = skin_1;
    else
        return;
    partitionCount_10 = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((::DPartitionData *)(::fnv_0043b230::FUN_0043b230((const char *)(skin_1))))))->GetName()));
    DMatrix basis_6;
    DMatrix worldRotation_4 = ((::DGeometry *)(::FUN_00559450((int *)&(geometry))))->FUN_00461130().rotation;
    DMatrix inverse_11 = (*(::DMatrix *)(reinterpret_cast<::ThreeByThreeMatrix *>(&(worldRotation_4))->FUN_004b45b0({})));
    DPoint localDirection_29;
    localDirection_29 = inverse_11.FUN_004b4500(&direction);
    DMatrix rotation_6;
    reinterpret_cast<::FUN_004a0c90_shell *>(&(rotation_6))->FUN_004a0c90(angle);
    auto kRotated_6 = FUN_00c4b600(direction);
    basis_6 = rotation_6.FUN_0043f8d0(&kRotated_6);
    DTransform transform_40 = ((::DGeometry *)(::FUN_00559450((int *)&(geometry))))->FUN_00461130();
    reinterpret_cast<::NiPoint3 *>(&(transform_40.position))->Subtract((const ::NiPoint3 &)(position));
    boneData_4 = ((::DBone *)(reinterpret_cast<::LowProcess *>((((::DSkinData *)(reinterpret_cast<::TESRegionDataMap *>((skin_1))->GetRegionMapName()))))->GetTarget()));
    if (boneData_4 == 0 || boneData_4->weights == 0)
        return;
    boneCount_4 = 0;
    bones_53 = 0;
    newBones_3 = 0;
    skinData_1 = 0;
    partitions_15 = 0;
    sourceVertexCount_3 = ((::DGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(((::DGeometry *)(::FUN_00559450((int *)&(geometry))))))))->FUN_004a8ae0();
    triangleCount_33 = 0;
    triangleData_17 = 0;
    vertexMap_22 = 0;
    selected_21 = false;
    selectedCount_12 = 0;
    partitions_15 = ((::DPartition *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::DPartitionData *)(::fnv_0043b230::FUN_0043b230((const char *)(skin_1))))))->FUN_0084e3a0()));
    strips_17 = partitions_15->stripCount > 0;
    for (int scanPartitionIndex = 0; scanPartitionIndex < partitionCount_10; scanPartitionIndex++)
    {
        unsigned char scanEnabled_1 = ((::DPartitionFlag *)(::GetField38((char *)(dismember_9))))[scanPartitionIndex].enabled;
        unsigned short scanPart_50 = ((::DPartitionFlag *)(::GetField38((char *)(dismember_9))))[scanPartitionIndex].bodyPart;
        if (scanPart_50 > 1000)
            scanPart_50 /= 1000;
        else if (scanPart_50 > 100)
        {
            while (scanPart_50 > 100)
                scanPart_50 -= 100;
        }
        int scanPartIndex_40 = scanPart_50;
        if (scanEnabled_1 && ((1 << (scanPartIndex_40 + 1)) & bodyParts))
        {
            selected_21 = true;
            triangleCount_33 += partitions_15[scanPartitionIndex].triangleCount;
            selectedCount_12++;
        }
    }
    if (!selected_21)
        return;
    indexCapacity_4 = triangleCount_33 * 3;
    indices_3 = new unsigned short[indexCapacity_4];
    remap_1 = new int[sourceVertexCount_3];
    partitionIndices_10 = new unsigned short[indexCapacity_4];
    partitionMap_7 = new unsigned short[sourceVertexCount_3];
    localRemap_40 = new int[sourceVertexCount_3];
    flagCapacity_0 = partitionCount_10;
    flags_7 = new unsigned short[partitionCount_10];
    weights_6 = new float[sourceVertexCount_3 * 4];
    boneIndices_1 = new unsigned char[sourceVertexCount_3 * 4];
    ::FUN_00403d30(remap_1, -1, sourceVertexCount_3 * 4);
    outputPartitions_22 = new DPartition[selectedCount_12];
    texcoords_0 = new DPoint[sourceVertexCount_3];
    positions_6 = 0;
    normals_17 = 0;
    positions_6 = new DPoint[sourceVertexCount_3];
    normals_17 = new DPoint[sourceVertexCount_3];
    reinterpret_cast<::Class87d40 *>((skin_1))->ForwardActorBaseData(((::DGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(((::DGeometry *)(::FUN_00559450((int *)&(geometry)))))))), (int)(positions_6), (int)(normals_17), 0, 0, 12);
    skinData_1 = ((::DSkinData *)(reinterpret_cast<::TESRegionDataMap *>((skin_1))->GetRegionMapName()));
    bones_53 = ((::DBone *)(reinterpret_cast<::LowProcess *>((skinData_1))->GetTarget()));
    boneCount_4 = ((int)(reinterpret_cast<::LowProcess *>((skinData_1))->GetActiveCombatTarget()));
    newBones_3 = new DBone[boneCount_4];
    for (int allocBoneIndex = 0; allocBoneIndex < boneCount_4; allocBoneIndex++)
    {
        DBone* allocBone = &newBones_3[allocBoneIndex];
        allocBone->transform = bones_53[allocBoneIndex].transform;
        if (allocBoneIndex == 0)
            allocBone->weights = new DBoneWeight[sourceVertexCount_3 * 4];
        else
            allocBone->weights = new DBoneWeight[sourceVertexCount_3];
    }
    DPoint normalDirection_1 = localDirection_29;
    DPoint vertex_3;
    DPoint normal_35;
    for (int projectionVertex = 0; projectionVertex < sourceVertexCount_3; projectionVertex++)
    {
        DPoint projected_8 = (*reinterpret_cast<::DPoint *>((void *)&::NiPoint3::ZERO));
        vertex_3 = positions_6[projectionVertex];
        normal_35 = normals_17[projectionVertex];
        DPoint world_20 = (*reinterpret_cast<::DPoint *>((void *)&::NiPoint3::ZERO));
        reinterpret_cast<::MyPoint439180 *>(&(vertex_3))->FUN_00439180(transform_40.scale);
        ::FUN_00a582f0((const float *)(::DMatrix *)(&transform_40.rotation), (const float *)(::DPoint *)(&transform_40.position), 1, (const ::Point314 *)(::DPoint *)(&vertex_3), (::Point314 *)(::DPoint *)(&world_20));
        ::FUN_00a582f0((const float *)(::DMatrix *)(&basis_6), (const float *)(::DPoint *)(&(*reinterpret_cast<::DPoint *>((void *)&::NiPoint3::ZERO))), 1, (const ::Point314 *)(::DPoint *)(&world_20), (::Point314 *)(::DPoint *)(&projected_8));
        texcoords_0[projectionVertex].x = projected_8.x / size + 0.5f;
        texcoords_0[projectionVertex].y = projected_8.y / size + 0.5f;
        float opacity_6 = 1.0f - FUN_00404010(0.0f, reinterpret_cast<::FUN_004b6190_shell *>(&(normalDirection_1))->DotProduct((void *)&(normal_35)));
        texcoords_0[projectionVertex].z = DecalPower(opacity_6, 10) * (1.0f - FloatAbs(projected_8.z) / 200.0f);
    }
    indexCount_11 = 0;
    outputVertexCount_4 = 0;
    selectedCount_12 = 0;
    for (int buildPartitionIndex = 0; buildPartitionIndex < partitionCount_10; buildPartitionIndex++)
    {
        unsigned char buildEnabled_2 = ((::DPartitionFlag *)(::GetField38((char *)(dismember_9))))[buildPartitionIndex].enabled;
        unsigned short buildPart_43 = ((::DPartitionFlag *)(::GetField38((char *)(dismember_9))))[buildPartitionIndex].bodyPart;
        if (buildPart_43 > 1000)
            buildPart_43 /= 1000;
        else if (buildPart_43 > 100)
        {
            while (buildPart_43 > 100)
                buildPart_43 -= 100;
        }
        int buildPartIndex_11 = buildPart_43;
        if (buildEnabled_2 && ((1 << (buildPartIndex_11 + 1)) & bodyParts))
        {
            triangleCount_33 = partitions_15[buildPartitionIndex].triangleCount;
            triangleData_17 = partitions_15[buildPartitionIndex].triangles;
            vertexMap_22 = partitions_15[buildPartitionIndex].vertexMap;
            strips_17 = partitions_15[buildPartitionIndex].stripCount > 0;
            unsigned short localIndexCount_3 = 0;
            unsigned short localVertexCount_22 = 0;
            ::FUN_00403d30(localRemap_40, -1, sourceVertexCount_3 * 4);
            ::FUN_00403d30(weights_6, 0, sourceVertexCount_3 * 4 * 4);
            ::FUN_00403d30(boneIndices_1, 0, sourceVertexCount_3 * 4);
            int winding_3 = 0;
            int cursor_15 = 0;
            for (int triangleIndex = 0; triangleIndex < triangleCount_33; triangleIndex++)
            {
                bool accepted_3 = false;
                bool valid_1 = true;
                unsigned short first_20 = triangleData_17[cursor_15];
                unsigned short second_11 = triangleData_17[cursor_15 + 1];
                unsigned short third_53 = triangleData_17[cursor_15 + 2];
                first_20 = vertexMap_22[first_20];
                second_11 = vertexMap_22[second_11];
                third_53 = vertexMap_22[third_53];
                if (first_20 == second_11 || first_20 == third_53 || second_11 == third_53)
                {
                    if (strips_17)
                    {
                        winding_3 = !winding_3;
                        cursor_15++;
                    }
                    else
                        cursor_15 += 3;
                    continue;
                }
                accepted_3 = reinterpret_cast<::Decal *>(this)->FUN_00683a70(triangleIndex, 0, strips_17 != 0, triangleData_17, (const ::Point *)(texcoords_0), vertexMap_22);
                if (accepted_3 && valid_1)
                {
                    for (int corner = 0; corner < 3; corner++)
                    {
                        unsigned short localIndex = triangleData_17[cursor_15 + corner];
                        unsigned short sourceIndex = vertexMap_22[localIndex];
                        if (remap_1[sourceIndex] == -1)
                        {
                            remap_1[sourceIndex] = outputVertexCount_4;
                            indices_3[indexCount_11] = outputVertexCount_4;
                            indexCount_11++;
                            outputVertexCount_4++;
                        }
                        else
                        {
                            indices_3[indexCount_11] = remap_1[sourceIndex];
                            indexCount_11++;
                        }
                        if (localRemap_40[sourceIndex] == -1)
                        {
                            for (int influence = 0; influence < partitions_15[buildPartitionIndex].weightsPerVertex;
                                 influence++)
                            {
                                int sourceWeight_14 =
                                    localIndex * partitions_15[buildPartitionIndex].weightsPerVertex + influence;
                                int destWeight_2 =
                                    localVertexCount_22 * partitions_15[buildPartitionIndex].weightsPerVertex +
                                    influence;
                                weights_6[destWeight_2] = partitions_15[buildPartitionIndex].weights[sourceWeight_14];
                                boneIndices_1[destWeight_2] =
                                    partitions_15[buildPartitionIndex].boneIndices[sourceWeight_14];
                            }
                            localRemap_40[sourceIndex] = localVertexCount_22;
                            partitionIndices_10[localIndexCount_3] = localVertexCount_22;
                            localIndexCount_3++;
                            partitionMap_7[localVertexCount_22] = remap_1[sourceIndex];
                            localVertexCount_22++;
                        }
                        else
                        {
                            partitionIndices_10[localIndexCount_3] = localRemap_40[sourceIndex];
                            localIndexCount_3++;
                        }
                    }
                    if (strips_17 && winding_3)
                    {
                        int firstIndex_14 = indices_3[indexCount_11 - 3];
                        int lastIndex_7 = indices_3[indexCount_11 - 1];
                        indices_3[indexCount_11 - 3] = lastIndex_7;
                        indices_3[indexCount_11 - 1] = firstIndex_14;
                        int firstLocal_1 = partitionIndices_10[localIndexCount_3 - 3];
                        int lastLocal_23 = partitionIndices_10[localIndexCount_3 - 1];
                        partitionIndices_10[localIndexCount_3 - 3] = lastLocal_23;
                        partitionIndices_10[localIndexCount_3 - 1] = firstLocal_1;
                    }
                }
                if (strips_17)
                {
                    winding_3 = !winding_3;
                    cursor_15++;
                }
                else
                    cursor_15 += 3;
            }
            if (localVertexCount_22 > 0)
            {
                outputPartitions_22[selectedCount_12].triangleCount = localIndexCount_3 / 3;
                outputPartitions_22[selectedCount_12].triangles = (unsigned short*)::FUN_00aa1070(localIndexCount_3 * 2);
                ::__memcpy(outputPartitions_22[selectedCount_12].triangles, partitionIndices_10, localIndexCount_3 * 2);
                outputPartitions_22[selectedCount_12].vertexCount = localVertexCount_22;
                outputPartitions_22[selectedCount_12].vertexMap = (unsigned short*)::FUN_00aa1070(localVertexCount_22 * 2);
                ::__memcpy(outputPartitions_22[selectedCount_12].vertexMap, partitionMap_7, localVertexCount_22 * 2);
                outputPartitions_22[selectedCount_12].boneCount = partitions_15[buildPartitionIndex].boneCount;
                outputPartitions_22[selectedCount_12].bones =
                    (unsigned short*)::FUN_00aa1070(partitions_15[buildPartitionIndex].boneCount * 2);
                ::__memcpy(outputPartitions_22[selectedCount_12].bones, partitions_15[buildPartitionIndex].bones,
                       partitions_15[buildPartitionIndex].boneCount * 2);
                outputPartitions_22[selectedCount_12].weightsPerVertex =
                    partitions_15[buildPartitionIndex].weightsPerVertex;
                int weightCount = outputPartitions_22[selectedCount_12].weightsPerVertex * localVertexCount_22;
                outputPartitions_22[selectedCount_12].weights = (float*)::FUN_00aa1070(weightCount * 4);
                outputPartitions_22[selectedCount_12].boneIndices = (unsigned char*)::FUN_00aa1070(weightCount);
                ::__memcpy(outputPartitions_22[selectedCount_12].weights, weights_6,
                       outputPartitions_22[selectedCount_12].weightsPerVertex * 4 *
                           outputPartitions_22[selectedCount_12].vertexCount);
                ::__memcpy(outputPartitions_22[selectedCount_12].boneIndices, boneIndices_1,
                       outputPartitions_22[selectedCount_12].weightsPerVertex *
                           outputPartitions_22[selectedCount_12].vertexCount);
                if ((unsigned int)selectedCount_12 >= flagCapacity_0)
                    DebugBreak();
                flags_7[selectedCount_12] = buildPart_43;
                selectedCount_12++;
            }
        }
    }
    newPartition_14 = 0;
    if (selectedCount_12 > 0)
    {
        newPartition_14 = new DNewPartition;
        reinterpret_cast<::FUN_00685e60_shell *>((newPartition_14))->FUN_00685e60((unsigned int)(outputPartitions_22), selectedCount_12);
    }
    if (outputVertexCount_4 > 0)
    {
        unsigned short* finalIndices_1 = new unsigned short[indexCount_11];
        ::__memcpy(finalIndices_1, indices_3, indexCount_11 * 2);
        DPoint* sourcePositions_18 = ((::DPoint *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((::DGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(((::DGeometry *)(::FUN_00559450((int *)&(geometry))))))))))->FUN_007af430()));
        DPoint* sourceNormals_7 = ((::DPoint *)(reinterpret_cast<::ActorMover *>((((::DGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(((::DGeometry *)(::FUN_00559450((int *)&(geometry))))))))))->GetCurrentMoveModeType()));
        DPoint* finalPositions_26 = new DPoint[outputVertexCount_4];
        DPoint* finalTexcoords_13 = new DPoint[outputVertexCount_4];
        for (int iSourceVertexIndex = 0; iSourceVertexIndex < sourceVertexCount_3; iSourceVertexIndex++)
        {
            if (remap_1[iSourceVertexIndex] != -1)
            {
                DPoint* sourcePosition_3 = &sourcePositions_18[iSourceVertexIndex];
                DPoint* sourceNormal_28 = &sourceNormals_7[iSourceVertexIndex];
                finalPositions_26[remap_1[iSourceVertexIndex]] = *sourcePosition_3;
                finalTexcoords_13[remap_1[iSourceVertexIndex]] = texcoords_0[iSourceVertexIndex];
            }
        }
        for (int copyBoneIndex = 0; copyBoneIndex < boneCount_4; copyBoneIndex++)
        {
            DBone* sourceBone_18 = &bones_53[copyBoneIndex];
            DBone* copyBone_11 = &newBones_3[copyBoneIndex];
            for (int weightIndex = 0; weightIndex < sourceBone_18->count; weightIndex++)
            {
                unsigned short boneSourceIndex = sourceBone_18->weights[weightIndex].index;
                if (remap_1[boneSourceIndex] != -1)
                {
                    copyBone_11->weights[copyBone_11->count].index = remap_1[boneSourceIndex];
                    copyBone_11->weights[copyBone_11->count].weight = sourceBone_18->weights[weightIndex].weight;
                    copyBone_11->count++;
                }
            }
            DBoneWeight* oldWeights_41 = copyBone_11->weights;
            newBones_3[copyBoneIndex].weights = new DBoneWeight[copyBone_11->count];
            ::__memcpy(newBones_3[copyBoneIndex].weights, oldWeights_41, copyBone_11->count * 8);
            delete[] oldWeights_41;
        }
        if (newPartition_14)
            CreateDecalGeometry(((::DGeometry *)(::FUN_00559450((int *)&(geometry)))), outputVertexCount_4, indexCount_11, finalPositions_26,
                                finalTexcoords_13, finalIndices_1, newBones_3, newPartition_14, flags_7);
        else
            CreateDecalGeometry(((::DGeometry *)(::FUN_00559450((int *)&(geometry)))), outputVertexCount_4, indexCount_11, finalPositions_26,
                                finalTexcoords_13, finalIndices_1, newBones_3, 0, 0);
        vertexCount = outputVertexCount_4;
    }
    else
    {
        for (int cleanupBoneIndex = 0; cleanupBoneIndex < boneCount_4; cleanupBoneIndex++)
        {
            delete[] newBones_3[cleanupBoneIndex].weights;
            newBones_3[cleanupBoneIndex].weights = 0;
        }
        delete[] newBones_3;
    }
    delete[] positions_6;
    delete[] normals_17;
    delete[] indices_3;
    delete[] partitionIndices_10;
    delete[] partitionMap_7;
    delete[] remap_1;
    delete[] localRemap_40;
    delete[] weights_6;
    delete[] boneIndices_1;
    delete[] texcoords_0;
    delete[] flags_7;
}

struct NiFixedString;
struct NiPoint2
{
    float x;
    float y;
};
struct NiObj;
struct NiAVObject;
struct DPoint;
struct DBone;
struct DNewPartition;
struct DGeometry;
struct ObjC;
struct ObjD;


struct GO
{
    NiObj* m_p;
    GO(int a);
    ~GO();
    operator NiObj*() const;
};
struct PtrHolder
{
    void* FUN_0066b0d0(void* p);
};
struct VSub
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void v36(int a, GO* s);
};
struct VSubOwner
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    VSub sub;
};
struct NiTriShape
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
    int tf04;
    int tf08;
    int tf0c;
    int tf10;
    int tf14;
    int tf18;
    int tf1c;
    int tf20;
    int tf24;
    int tf28;
    int tf2c;
    int tf30;
    int tf34;
    int tf38;
    int tf3c;
    int tf40;
    int tf44;
    int tf48;
    int tf4c;
    int tf50;
    int tf54;
    int tf58;
    int tf5c;
    int tf60;
    int tf64;
    int tf68;
    int tf6c;
    int tf70;
    int tf74;
    int tf78;
    int tf7c;
    int tf80;
    int tf84;
    int tf88;
    int tf8c;
    int tf90;
    int tf94;
    int tf98;
    int tf9c;
    int tfa0;
    int tfa4;
    int tfa8;
    int tfac;
    int tfb0;
    int tfb4;
    int tfb8;
    int tfbc;
    int tfc0;
    NiTriShape(unsigned short a, NiPoint3* c, NiPoint3* d, void* z1, NiPoint2* z2, unsigned short z3, unsigned int z4,
               unsigned short div, unsigned short* e);
};
struct ObjB
{
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
    int u40;
    int u44;
    int u48;
    int u4c;
    int u50;
    int u54;
    int u58;
    int u5c;
    int u60;
    int u64;
    int u68;
    int u6c;
    int u70;
    int u74;
    int u78;
    PtrHolder m_7c;
    int w80;
    int w84;
    int w88;
    int w8c;
    int w90;
    int w94;
    int w98;
    int w9c;
    int wa0;
    int wa4;
    int wa8;
    int wac;
    int wb0;
    int wb4;
    int wb8;
    int wbc;
    int wc0;
    int wc4;
    int wc8;
    int wcc;
    int wd0;
    ObjB();
};
struct SkinDataX
{
};
struct SkinX
{
};
struct ObjC
{
    int cf00;
    int cf04;
    int cf08;
    int cf0c;
    int cf10;
    int cf14;
    int cf18;
    int cf1c;
    int cf20;
    int cf24;
    int cf28;
    int cf2c;
    int cf30;
    int cf34;
    int cf38;
    int cf3c;
    int cf40;
    int cf44;
    ObjC(int partList, DBone* bone, int x);
};
struct ObjD
{
    virtual ~ObjD();
    int df04;
    int df08;
    int df0c;
    int df10;
    int df14;
    int df18;
    int df1c;
    int df20;
    int df24;
    int df28;
    int df2c;
    int df30;
    int df34;
    int df38;
    int df3c;
    ObjD(ObjC* c, int x, int* arr, Entry4* textObj, int n);
    void FUN_004addc0(void* p);
};
struct ObjE
{
    virtual ~ObjE();
    int ef04;
    int ef08;
    int ef0c;
    ObjE();
};
struct GeomX
{
};

// Builds a NiTriShape from the given points and indices, attaches skin/partition data and copies transform properties from the geometry, then stores the shape.
// @fnv 0x00687d90
void DDecal::CreateDecalGeometry(DGeometry* geom, unsigned short ausVertexCount, unsigned short ausIndexCount,
                                 DPoint* apVertices, DPoint* d, unsigned short* apIndices, DBone* bone,
                                 DNewPartition* apNewPartition, unsigned short* apPartMap)
{
    NiTriShape* objA =
        new NiTriShape(ausVertexCount, (NiPoint3*)apVertices, (NiPoint3*)d, 0, 0, 0, 0, ausIndexCount / 3, apIndices);
    ::AssignFixedString((char *)(objA), (int)&(*FUN_00688460()), {});
    ObjB* entries;
    entries = new ObjB();
    reinterpret_cast<::FUN_00439410_cls *>((objA))->FUN_00439410((::ArgObject *)(entries));
    reinterpret_cast<::FUN_004ee4b0_shell *>((entries))->FUN_004ee4b0(1.0f);
    GO strLocal(0);
    ((VSubOwner*)unk58)->sub.v36(0, &strLocal);
    NiObj* partCount;
    partCount = strLocal;
    if (((unsigned char)(::FUN_0043b300(&(*reinterpret_cast<const ::NiRTTI *>(&::g_011f444c)), (NiAVObject*)partCount))))
        entries->m_7c.FUN_0066b0d0(partCount);
    SkinX* count;
    count = (SkinX*)((::DSkin *)(::fnv_0043fad0::FUN_0043fad0((const char *)(geom))));
    int objD;
    objD = ((int)(reinterpret_cast<::LowProcess *>((((::SkinDataX *)(reinterpret_cast<::TESRegionDataMap *>((count))->GetRegionMapName()))))->GetActiveCombatTarget()));
    ObjC* textObj;
    textObj = new ObjC(objD, bone, ::GetOffsetC((std::intptr_t)(((::SkinDataX *)(reinterpret_cast<::TESRegionDataMap *>((count))->GetRegionMapName())))));
    int* s;
    s = ((int *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((count))->FUN_00825c00()));
    long objC;
    int* partList = new int[objD];
    for (objC = 0; objC < objD; objC++)
        partList[objC] = s[objC];
    int skin;
    skin = 0;
    unsigned int vertexMap[15];
    if (apNewPartition)
    {
        skin = (int)((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((DPartitionData*)apNewPartition)))->GetName()));
    }
    else
    {
        long idx;
        idx = 2;
        for (unsigned int bitIdx = 0; bitIdx < 15; bitIdx++)
        {
            if (bodyParts & idx)
            {
                vertexMap[skin] = bitIdx;
                skin++;
            }
            idx = idx << 1;
        }
    }
    Entry4* kIter;
    kIter = new Entry4[skin];
    {
        long j;
        for (j = 0; j < skin; j++)
        {
            kIter[j].b0 = 1;
            kIter[j].b1 = 1;
            if (apPartMap)
                kIter[j].w = apPartMap[j];
            else
                kIter[j].w = (unsigned short)vertexMap[j];
        }
    }
    ObjD* arr1 = new ObjD(textObj, ((int)(reinterpret_cast<::MagicCaster_shell *>((count))->FUN_0044edb0())), partList, kIter, skin);
    if (apNewPartition)
    {
        arr1->FUN_004addc0(apNewPartition);
        reinterpret_cast<::FUN_004adde0_shell *>((objA))->FUN_004adde0((::NiNode *)(arr1));
    }
    else
    {
        ObjE* val;
        val = new ObjE();
        if (((unsigned char)(reinterpret_cast<::GeometryBuilder *>((val))->FUN_00a84980((::SourceGeometry *)(void *)(((void *)(::fnv_005495f0::FUN_005495f0((const char *)(objA))))), {}, {}, {}, {}, {}, {}, {}))))
        {
            arr1->FUN_004addc0(val);
            reinterpret_cast<::FUN_004adde0_shell *>((objA))->FUN_004adde0((::NiNode *)(arr1));
        }
        else
        {
            delete val;
            delete arr1;
        }
    }
    reinterpret_cast<::FUN_00440460_S *>((objA))->FUN_00440460((const ::V3 *)(&(reinterpret_cast<::NiAVObject *>((((GeomX*)((::DGeometry *)(::FUN_00559450((int *)&(geometry)))))))->FUN_0043c490())));
    reinterpret_cast<::FUN_0043fa80_s *>((objA))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(((std::intptr_t)(::FUN_006a9540((char *)(((GeomX*)((::DGeometry *)(::FUN_00559450((int *)&(geometry))))))))))));
    reinterpret_cast<::FUN_00440490_shell *>((objA))->FUN_00440490(reinterpret_cast<::FUN_009cdae0_shell *>((((GeomX*)((::DGeometry *)(::FUN_00559450((int *)&(geometry)))))))->GetFloatAt64());
    reinterpret_cast<::FUN_004f00e0_shell *>((objA))->FUN_004f00e0((void *)(::FUN_0045bb80((std::intptr_t)(((GeomX*)((::DGeometry *)(::FUN_00559450((int *)&(geometry)))))))));
    reinterpret_cast<::FUN_00688430_shell *>((objA))->FUN_00688430((::NineDwords688430 *)(::NineDw *)(((::NineDw *)(::FUN_00461130((std::intptr_t)(((GeomX*)((::DGeometry *)(::FUN_00559450((int *)&(geometry)))))))))));
    reinterpret_cast<::FUN_006427a0_Class *>((objA))->SetValue(reinterpret_cast<::FUN_008d01e0_Class *>((((GeomX*)((::DGeometry *)(::FUN_00559450((int *)&(geometry)))))))->FUN_008d01e0());
    objA->v47();
    reinterpret_cast<::FUN_00a5a040_Class *>((objA))->FUN_00a5a040();
    ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(objA), 0, 0);
    ((PtrHolder*)&unk1c)->FUN_0066b0d0(objA);
    unk20 = (int)((::DGeometry *)(::FUN_00559450((int *)&(geometry))));
}

namespace fnv_00688770 {
class NiNode;
class NiAVObject
{
  public:
};
class NiNode
{
  public:
    virtual void FUN_000();
    virtual void FUN_004();
    virtual void FUN_008();
    virtual void FUN_00c();
    virtual void FUN_010();
    virtual void FUN_014();
    virtual void FUN_018();
    virtual void FUN_01c();
    virtual void FUN_020();
    virtual void FUN_024();
    virtual void FUN_028();
    virtual void FUN_02c();
    virtual void FUN_030();
    virtual void FUN_034();
    virtual void FUN_038();
    virtual void FUN_03c();
    virtual void FUN_040();
    virtual void FUN_044();
    virtual void FUN_048();
    virtual void FUN_04c();
    virtual void FUN_050();
    virtual void FUN_054();
    virtual void FUN_058();
    virtual void FUN_05c();
    virtual void FUN_060();
    virtual void FUN_064();
    virtual void FUN_068();
    virtual void FUN_06c();
    virtual void FUN_070();
    virtual void FUN_074();
    virtual void FUN_078();
    virtual void FUN_07c();
    virtual void FUN_080();
    virtual void FUN_084();
    virtual void FUN_088();
    virtual void FUN_08c();
    virtual void FUN_090();
    virtual void FUN_094();
    virtual void FUN_098();
    virtual void FUN_09c();
    virtual void FUN_0a0();
    virtual void FUN_0a4();
    virtual void FUN_0a8();
    virtual void FUN_0ac();
    virtual void FUN_0b0();
    virtual void FUN_0b4();
    virtual void FUN_0b8();
    virtual void FUN_0bc();
    virtual void FUN_0c0();
    virtual void FUN_0c4();
    virtual void FUN_0c8();
    virtual void FUN_0cc();
    virtual void FUN_0d0();
    virtual void FUN_0d4();
    virtual void FUN_0d8();
    virtual void FUN_0dc();
    virtual void FUN_0e0();
    virtual void FUN_0e4();
    virtual void FUN_0e8(NiAVObject* pkChild);
};
template <class T> class NiPointer
{
  public:
    ~NiPointer();
    NiPointer<T>& operator=(T* pObject);
    operator T*() const;
    T* operator->() const;
    T* m_pObject;
};

struct FUN_00682860
{
    virtual ~FUN_00682860();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct FUN_00688770 : FUN_00682860
{
    NiPointer<NiAVObject> m_spGeometry;
    int unk20;
    char* m_pData;
    int unk28;
    NiPointer<NiAVObject> m_sp2C;
    NiPointer<NiAVObject> m_sp30;
    NiPointer<NiAVObject> m_sp34;
    virtual ~FUN_00688770();
};

// Detaches m_spGeometry from its parent, deletes m_pData, and clears m_sp2C and m_sp30.
// @fnv 0x00688770
FUN_00688770::~FUN_00688770()
{
    if (m_spGeometry)
    {
        if (((::fnv_00688770::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>(((m_spGeometry).operator->()))->FUN_009611e0())))
            ((::fnv_00688770::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>(((m_spGeometry).operator->()))->FUN_009611e0()))->FUN_0e8(m_spGeometry);
        m_spGeometry = 0;
    }
    if (m_pData)
        delete m_pData;
    m_sp2C = 0;
    m_sp30 = 0;
}
}  // namespace fnv_00688770

struct SaveGameBuffer688
{
};
struct SaveForm688
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
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual const char* GetName();
};

struct Decal688 : BSTempEffectGeometryDecal
{
    void FUN_00688b00();
};

// Writes a BLOK-tagged save block for the decal, logs the record size and form info, and back-patches the block size.
// @fnv 0x00688b00
void Decal688::FUN_00688b00()
{
    unsigned short usSize = 0;
    char* pcSizePos = 0;
    char* pStart = ((char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((SaveGameBuffer688*)(*reinterpret_cast<::GlobalRuntime * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
    if (*(*reinterpret_cast<::FeatureState *>(&::g_011de4e8)).FUN_00408d60())
        pStart = ((char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((SaveGameBuffer688*)(*reinterpret_cast<::GlobalRuntime * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::GlobalRuntime * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        unsigned int uiTag = 'BLOK';
        reinterpret_cast<::FUN_008579b0_shell *>((((SaveGameBuffer688*)(*reinterpret_cast<::GlobalRuntime * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&uiTag), 4);
        pcSizePos = ((char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((SaveGameBuffer688*)(*reinterpret_cast<::GlobalRuntime * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
        reinterpret_cast<::FUN_008579b0_shell *>((((SaveGameBuffer688*)(*reinterpret_cast<::GlobalRuntime * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&usSize), 2);
    }

    if (*(*reinterpret_cast<::FeatureState *>(&::g_011de4e8)).FUN_00408d60())
    {
        char* pcEnd = ((char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((SaveGameBuffer688*)(*reinterpret_cast<::GlobalRuntime * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
        char* pcRecord = ((char *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::GlobalRuntime * *>(&::g_TESSaveLoadGame))))->GetHitSound()));
        if (pcRecord)
        {
            SaveForm688* pForm = (SaveForm688*)((void *)(::FUN_004839c0((unsigned int)(std::uintptr_t)(*(void**)pcRecord))));
            ::FUN_0040fbe0(
                );
        }
        else
        {
            ::FUN_0040fbe0(
                );
        }
    }
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::GlobalRuntime * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        char* pCur = ((char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((SaveGameBuffer688*)(*reinterpret_cast<::GlobalRuntime * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
        char* pBlock = pcSizePos;
        if (pCur > pBlock + 0xffff)
            ::FUN_005b5e40(
                );
        *(unsigned short*)pcSizePos = (unsigned short)(pCur - pBlock);
    }
}

extern int DAT_010699bc;

struct BaseA
{
    BaseA(int a, float b);
    ~BaseA() throw();
};

struct Sub1c
{
    Sub1c(int a);
    ~Sub1c() throw();
    void Reset(int a);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned char unk0c;
};

struct Sub4
{
    Sub4(int a);
    ~Sub4() throw();
    void Reset(unsigned int a);
    unsigned int unk00;
};

struct SubDef
{
    SubDef();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct Obj4
{
};

struct Aux30
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, m_30;
};

struct FUN_00683900_cls : BaseA
{
    int m_00;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18;
    Sub1c m_1c;
    Sub4 m_2c;
    Sub4 m_30;
    Sub4 m_34;
    SubDef m_38;
    SubDef m_44;
    float m_50;
    float m_54;
    unsigned int m_58;
    unsigned int m_5c;
    unsigned int m_60;

    FUN_00683900_cls(int a1, float a2, const Aux30* a3, Obj4* a4, SubDef a5, SubDef a6, float a11, float a12,
                     unsigned int a13);
};

// Initializes BaseA and members, copying a5, a6, and a3->m_30 into their corresponding fields.
// @fnv 0x00683900
FUN_00683900_cls::FUN_00683900_cls(int a1, float a2, const Aux30* a3, Obj4* a4, SubDef a5, SubDef a6, float a11,
                                   float a12, unsigned int a13)
    : BaseA(a1, a2), m_00((int)&DAT_010699bc), m_1c(0), m_2c(0), m_30(0), m_34(0), m_38(), m_44()
{
    m_1c.unk0c = 0;
    m_1c.Reset(0);
    m_1c.unk08 = 0;
    m_2c.Reset((unsigned int)a4);
    m_30.Reset(((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((a4))->FUN_009611e0())));
    m_38 = a5;
    m_44 = a6;
    m_50 = a11;
    m_54 = a12;
    m_60 = a13;
    m_5c = 0;
    m_58 = a3->m_30;
}


struct DecalLoad688Size
{
    unsigned char low, middleLow, middleHigh, high;
};
struct DecalLoad688Header
{
    int formID;
    unsigned char flags;
    DecalLoad688Size dataSize;
    unsigned char version;
};
struct DecalLoad688Reader
{
};
struct DecalLoad688Version
{
};
struct DecalLoad688Buffer
{
};
struct DecalLoad688Runtime
{
};
struct DecalLoad688 : BSTempEffectGeometryDecal
{
    bool FUN_00688c90();
};

// Reads a four-byte marker and two-byte value, then logs when the current buffer position differs from their sum.
// @fnv 0x00688c90
bool DecalLoad688::FUN_00688c90()
{
    bool result5 = 1;
    unsigned short count = 0;
    unsigned int base = 0;
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::GlobalRuntime * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        unsigned int blok;
        reinterpret_cast<::FUN_008579e0_shell *>((((DecalLoad688Reader*)(*reinterpret_cast<::GlobalRuntime * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(&blok, 4);
        if (blok != 0x424c4f4b)
        {
            DecalLoad688Header* form7 = ((::DecalLoad688Header *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((DecalLoad688Runtime*)(*reinterpret_cast<::GlobalRuntime * *>(&::g_TESSaveLoadGame)))))));
            if (form7)
            {
                SaveForm688* obj_2 = (SaveForm688*)((void *)(::FUN_004839c0((unsigned int)(std::uintptr_t)((void*)(form7->formID)))));
                ::FUN_005b5e40((*reinterpret_cast<char (*)[]>(&::fnv_008d0bc0::DAT_01015718)), &str_01069ba0, 1932, form7->formID, obj_2->GetName(), form7->version,
                             *(int*)&form7->dataSize);
            }
            else
            {
                ::FUN_005b5e40((*reinterpret_cast<char (*)[]>(&::fnv_008d0bc0::DAT_010156a8)), &str_01069ba0, 1932, reinterpret_cast<::FUN_008df040_shell *>(((DecalLoad688Version*)(*reinterpret_cast<::GlobalRuntime * *>(&::g_TESSaveLoadGame))))->FUN_008df040());
            }
        }
        base = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((DecalLoad688Buffer*)(*reinterpret_cast<::GlobalRuntime * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00();
        reinterpret_cast<::FUN_008579e0_shell *>((((DecalLoad688Reader*)(*reinterpret_cast<::GlobalRuntime * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(&count, 2);
    }
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::GlobalRuntime * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        unsigned int cur4 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((DecalLoad688Buffer*)(*reinterpret_cast<::GlobalRuntime * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00();
        DecalLoad688Header* form2 = ((::DecalLoad688Header *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((DecalLoad688Runtime*)(*reinterpret_cast<::GlobalRuntime * *>(&::g_TESSaveLoadGame)))))));
        if (form2)
        {
            SaveForm688* obj3 = (SaveForm688*)((void *)(::FUN_004839c0((unsigned int)(std::uintptr_t)((void*)(form2->formID)))));
            if (cur4 > count + base)
            {
                ::FUN_005b5e40((*reinterpret_cast<char (*)[]>(&::fnv_008d0bc0::DAT_01015588)), cur4 - (count + base), &str_01069ba0, 2104, form2->formID, obj3->GetName(),
                             form2->version, *(int*)&form2->dataSize);
            }
            else if (cur4 < count + base)
            {
                ::FUN_005b5e40((*reinterpret_cast<char (*)[]>(&::fnv_008d0bc0::DAT_01015500)), (count + base) - cur4, &str_01069ba0, 2104, form2->formID, obj3->GetName(),
                             form2->version, *(int*)&form2->dataSize);
            }
        }
        else
        {
            if (cur4 > count + base)
            {
                ::FUN_005b5e40((*reinterpret_cast<char (*)[]>(&::fnv_008d0bc0::DAT_010154a0)), cur4 - (count + base), &str_01069ba0, 2104,
                             reinterpret_cast<::FUN_008df040_shell *>(((DecalLoad688Version*)(*reinterpret_cast<::GlobalRuntime * *>(&::g_TESSaveLoadGame))))->FUN_008df040());
            }
            else if (cur4 < count + base)
            {
                ::FUN_005b5e40((*reinterpret_cast<char (*)[]>(&::fnv_008d0bc0::DAT_01015440)), (count + base) - cur4, &str_01069ba0, 2104,
                             reinterpret_cast<::FUN_008df040_shell *>(((DecalLoad688Version*)(*reinterpret_cast<::GlobalRuntime * *>(&::g_TESSaveLoadGame))))->FUN_008df040());
            }
        }
    }
    return result5;
}

struct NiSkinInstance_o2
{
    void FUN_00a85580_o2();
    void* FUN_006885a0(unsigned int flags);
};

extern "C" void __cdecl _Call_a5d3a0();

struct FUN_00a81f90_class
{
    void* FUN_00a81f90();
};

// @fnv 0x00a81f90
void* FUN_00a81f90_class::FUN_00a81f90()
{
    _Call_a5d3a0();
    *(int*)this = (int)&DAT_0109e47c;
    *(int*)((char*)this + 0xc) = 0;
    return this;
}

struct S_00a85580_RefObject
{
    virtual ~S_00a85580_RefObject() throw();
    virtual void DeleteThis() throw();
    volatile LONG m_uiRefCount;
    void DecRefCount() throw()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> struct S_00a85580_Pointer
{
    T* m_pObject;
    ~S_00a85580_Pointer() throw()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
};

struct S_00a85580_Object
{
    virtual ~S_00a85580_Object() throw();
    int m_uiRefCount;
};

struct S_00a85580_Renderer;

struct FUN_00a85580_o2;

struct S_00a85580_Renderer
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void PurgeSkinInstance(FUN_00a85580_o2* skin) throw();
};

struct FUN_00a85580_o2 : S_00a85580_Object
{
    S_00a85580_Pointer<S_00a85580_RefObject> unk8;
    S_00a85580_Pointer<S_00a85580_RefObject> unkC;
    int unk10;
    void* unk14;
    ~FUN_00a85580_o2() throw();
};

// @fnv 0x00a85580
FUN_00a85580_o2::~FUN_00a85580_o2() throw()
{
    FUN_00aa10f0(unk14);
    if ((*reinterpret_cast<::S_00a85580_Renderer * *>(&::NiRenderer::ms_pRenderer)))
        (*reinterpret_cast<::S_00a85580_Renderer * *>(&::NiRenderer::ms_pRenderer))->PurgeSkinInstance(this);
}

#include "generated/data/fallout_shared/tempeffects/bstempeffectgeometrydecal.inc"
