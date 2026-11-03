
// src/staging/blk_007e0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <new>
#include <cstdlib>
#include <cstring>
#include "fnv/decl/AGOwner.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/EffectSettingList.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_00445300_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00470440.h"
#include "fnv/decl/FUN_005db4c0_struct.h"
#include "fnv/decl/FUN_007004e0_class.h"
#include "fnv/decl/FUN_007242c0_shell.h"
#include "fnv/decl/FUN_00724930_cls.h"
#include "fnv/decl/FUN_00726090_cls.h"
#include "fnv/decl/FUN_007af180_shell.h"
#include "fnv/decl/FUN_00a00e90_shell.h"
#include "fnv/decl/FUN_00a00f30_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a1d910_shell.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FaderManager.h"
#include "fnv/decl/FalloffController.h"
#include "fnv/decl/FocusManager.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/P03Value.h"
#include "fnv/decl/S7010.h"
#include "fnv/decl/SSN_b5.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/VATSMenuView.h"
#include "fnv/decl/VLList.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/W004702f0.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a09200__Value_00a09200.h"
#include "fnv/decl/fnv_00a09410__EvalValue.h"
#include "fnv/decl/fnv_00a1ddb0__FUN_00a1ddb0_shell.h"
#include "fnv/decl/fnv_00ad8510__BSAudioManager.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00718000.h"
#include "fnv/symbols_00726000.h"
#include "fnv/symbols_007ab000.h"
#include "fnv/symbols_007f6000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_011a0000.h"
#include "fnv/symbols_011ae000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011db000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "../../include/layout_support.h"
#include "fnv/decl/FUN_007e6700_Class.h"
#include "fnv/decl/FUN_00a011f0_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/S6a70.h"
#include "fnv/decl/SoundPlayback.h"
#include "fnv/decl/Twin_007e6580.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_007eb000.h"
#include "fnv/symbols_007ff000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_011d3000.h"


struct FUN_007e6760_cls
{
    bool FUN_007e6760();
};

// @fnv 0x007e6760
bool FUN_007e6760_cls::FUN_007e6760()
{
    return ::fnv_007ab810::FUN_007ab810() != 0;
}

struct BSAudio_
{
    void FUN_007eb8a0();
};

// @fnv 0x007eb8a0
void BSAudio_::FUN_007eb8a0()
{
    reinterpret_cast<::fnv_00ad8510::BSAudioManager *>(this)->FUN_00ad8510(0x3002, 0);
}

extern "C" void __cdecl FUN_007004e0();

struct FUN_007f7770_Class
{
    void FUN_007004e0();
    void FUN_007f7770();
};

// @fnv 0x007f7770
void FUN_007f7770_Class::FUN_007f7770()
{
    reinterpret_cast<::FUN_007004e0_class *>(this)->FUN_007004e0();
}

extern float DAT_012007d0;
extern float DAT_012007d4;

// @fnv 0x007f7a50
void __cdecl FUN_007f7a50(float afValue1, float afValue2)
{
    DAT_012007d0 = afValue1;
    DAT_012007d4 = afValue2;
    DAT_011ae5d4 = 1;
}

struct FOPipboyManager
{
    void InitializeMenuLight();
    void FUN_007fa200();
};

// @fnv 0x007fa200
void FOPipboyManager::FUN_007fa200()
{
    InitializeMenuLight();
}

struct Flt
{
    operator unsigned int();
};

struct FUN_007fa970_Class
{
    unsigned int FUN_007fa970();
};

// @fnv 0x007fa970
unsigned int FUN_007fa970_Class::FUN_007fa970()
{
    return ((Flt*)((char*)this + 0xe0))->operator unsigned int();
}

struct GO
{
    void* operator=(void*);
};
struct FUN_007fd620_Class
{
    char _0[0x24];
    GO m_go;
    void SetGo(void* p);
};
// @fnv 0x007fd620
void FUN_007fd620_Class::SetGo(void* apValue)
{
    m_go = apValue;
}

namespace fnv_007fd640 {
struct Flt
{
    operator unsigned int();
};

struct FUN_007fd640Class
{
    unsigned int FUN_007fd640();
};

// @fnv 0x007fd640
unsigned int FUN_007fd640Class::FUN_007fd640()
{
    return ((Flt*)((char*)this + 0x90))->operator unsigned int();
}
}  // namespace fnv_007fd640

struct RaceSexMenu
{
    void FUN_007fe910(void* apList);
};

// @fnv 0x007fe910
void RaceSexMenu::FUN_007fe910(void* apList)
{
    reinterpret_cast<::FUN_007af180_shell *>(this)->FUN_007af180((int)(apList));
}

struct NavMeshPtr
{
    void* FUN_00458b50();
};
struct BSStr
{
};
void __cdecl FUN_007e65b0();
struct FUN_007e66a0_cls
{
    char _0[0x28];
    void FUN_007e66a0(int a, int b);
};
// If b is zero and a is in [0,3), reads b from this[a+10]; for a==1, sets g_011daed8 from the navmesh pointer at this+0x34 and calls FUN_007e65b0.
// @fnv 0x007e66a0
void FUN_007e66a0_cls::FUN_007e66a0(int aiIndex, int aiValue)
{
    if (aiValue == 0 && aiIndex >= 0 && aiIndex < 3)
        aiValue = ((int*)this)[aiIndex + 10];
    switch (aiIndex)
    {
    case 1:
        reinterpret_cast<::TextString *>(&((*reinterpret_cast<::BSStr *>(&::g_011daed8))))->FUN_004037f0((const char*)((NavMeshPtr*)((char*)this + 0x34))->FUN_00458b50(), 0);
        FUN_007e65b0();
        break;
    }
}

void __cdecl DestroyList(void*);
struct FUN_007f69d0_Class
{
    void DestroyList();
    void* FUN_007f69d0(unsigned int flags);
};
struct GameTimerRecord
{
};
struct FUN_007f7880_Class
{
    unsigned char _0[0x28];
    unsigned char bActive;
    unsigned char _1[3];
    float f5;
    float f2;
    float f3;
    float f4;
    float f6;
    float f8;
    float f9;
    float f10;
    void FUN_007f7880(float a, float b, float c);
};
// @fnv 0x007f7880
void FUN_007f7880_Class::FUN_007f7880(float a, float b, float c)
{
    bActive = 1;
    f2 = a;
    f3 = a;
    f4 = b;
    f8 = c;
    f5 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((void *)&(g_timeGlobal))->FUN_00825c00();
    f10 = 0.0f;
    f6 = 0.0f;
}

struct ModelLoader
{
};
struct Loader_S
{
    void* m_p;
    ModelLoader* operator->();
};
// If g_011db63c is nonzero, calls the model loader with DAT_011a0bb0, true, true, then sets g_011db63c to 0.
// @fnv 0x007ffe00
void FUN_007ffe00()
{
    if ((unsigned int)(*reinterpret_cast<::Flt *>(&::g_011db63c)))
        reinterpret_cast<::FUN_00445300_shell *>((((ModelLoader*)(*reinterpret_cast<::Loader_S * *>(&::g_modelLoader)))))->FUN_00445300((char*)DAT_011a0bb0, true, true);
    *(GO*)&(*reinterpret_cast<::Flt *>(&::g_011db63c)) = 0;
}

struct FUN_007e0e30_Class
{
    void* m_p;
    void* m_sub;
    void FUN_007e0e30(bool(__cdecl* fn)(void*, unsigned int), unsigned int v);
};

// Calls fn on m_p with v and, if that returns true and m_sub is set, recurses into m_sub with the same arguments.
// @fnv 0x007e0e30
void FUN_007e0e30_Class::FUN_007e0e30(bool(__cdecl* fn)(void*, unsigned int), unsigned int uiValue)
{
    if (fn(m_p, uiValue) && m_sub)
        ((FUN_007e0e30_Class*)m_sub)->FUN_007e0e30(fn, uiValue);
}

struct FUN_007f7830_Class
{
    char _0[0x28];
    unsigned char bActive;
    void UpdateIfActive();
};
// Reads the global time and, when bActive is set, calls UpdateFalloff with that time as a float.
// @fnv 0x007f7830
void FUN_007f7830_Class::UpdateIfActive()
{
    float fappTime = (float)reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((void *)&(g_timeGlobal))->FUN_00825c00();
    if (bActive)
        reinterpret_cast<::FalloffController *>(this)->UpdateFalloff(fappTime);
}

struct FUN_007fecc0_Class
{
    unsigned char _0[0x158];
    unsigned char bActive;
    unsigned char _1[3];
    float fTime;
    float fValue;
    void FUN_007fecc0();
};

// Sets bActive to 1, stores the current global time in fTime and resets fValue to 0.0f.
// @fnv 0x007fecc0
void FUN_007fecc0_Class::FUN_007fecc0()
{
    bActive = 1;
    fTime = (float)reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((void *)&(g_timeGlobal))->FUN_00825c00();
    fValue = 0.0f;
}

struct FUN_007eb8d0_Class
{
    char _0[0x28];
    bool HasAllSlotsSet(int* p);
};

// Sets *p to 1 and checks that each of the 31 int slots at this+0x28 is non-zero, returning false on the first zero.
// @fnv 0x007eb8d0
bool FUN_007eb8d0_Class::HasAllSlotsSet(int* piIndex)
{
    *piIndex = 1;
    for (; *piIndex <= 0x1f; ++*piIndex)
    {
        if (*(int*)((char*)this + *piIndex * 4 + 0x28) == 0)
            return false;
    }
    return true;
}

struct Tile
{
    void Set(int, int);
    virtual ~Tile();
    public:
    static float GetInterfaceScale();
};
struct Menu
{
};
struct SimpleList
{
};
// @fnv 0x007e65b0
void FUN_007e65b0()
{
    if (DAT_011daec4)
    {
        ((Tile*)((::SimpleList *)(reinterpret_cast<::Callees *>((DAT_011daec4))->FUN_00726070())))->Set(0x1772, 1);
        reinterpret_cast<::FUN_00a1d910_shell *>((((Menu*)DAT_011daec4)))->FUN_00a1d910();
        DAT_011daec4 = 0;
    }
}

struct ListX
{
    ~ListX();
};
struct FUN_007f6a00_Class
{
    char _0[8];
    ListX l;
    void DestroyList();
};
// @fnv 0x007f69d0
void* FUN_007f69d0_Class::FUN_007f69d0(unsigned int flags)
{
    reinterpret_cast<::FUN_007f6a00_Class *>(this)->DestroyList();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x007f6a00
void FUN_007f6a00_Class::DestroyList()
{
    reinterpret_cast<::EffectSettingList *>(&(l))->EffectSettingList::~EffectSettingList();
}

struct NiPoint2
{
    float x;
    float y;
};


struct FUN_007f78f0_Class
{
    unsigned char _0[0x28];
    unsigned char bActive;
    unsigned char _1[3];
    float fTime;
    NiPoint2 f2;
    NiPoint2 f4;
    NiPoint2 f6;
    NiPoint2 f8;

    void InitFromPoints(const NiPoint2* a, const NiPoint2* b, const NiPoint2* c);
};

// Marks the object active, copies three NiPoint2 inputs into f2/f4/f6, stores the global time in fTime and DAT_011f4980 in f8.
// @fnv 0x007f78f0
void FUN_007f78f0_Class::InitFromPoints(const NiPoint2* apPoint1, const NiPoint2* apPoint2,
                                                   const NiPoint2* apPoint3)
{
    bActive = 1;
    f2 = *apPoint1;
    f4 = *apPoint2;
    f6 = *apPoint3;
    fTime = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((void *)&(g_timeGlobal))->FUN_00825c00();
    f8 = ::DAT_011f4980;
}

struct FUN_007e0d80_shell : Flt
{
    char* m_buffer;
    unsigned int FUN_004039a0();
    void FUN_004039c0(unsigned int newLength);
    void FUN_00438470(FUN_007e0d80_shell* other);
    FUN_007e0d80_shell* AppendString(FUN_007e0d80_shell* other);
};
// @fnv 0x007e0d80
FUN_007e0d80_shell* FUN_007e0d80_shell::AppendString(FUN_007e0d80_shell* other)
{
    if ((unsigned int)*other)
    {
        if ((unsigned int)*this)
        {
            unsigned int newLength = ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(this)->FUN_004048e0())) + ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((other))->FUN_004048e0()));
            if (newLength > FUN_004039a0())
            {
                reinterpret_cast<::TextString *>(this)->FUN_004037f0((char*)(unsigned int)*this, newLength);
            }
            memcpy(m_buffer + ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(this)->FUN_004048e0())), (char*)(unsigned int)*other, reinterpret_cast<::S7010 *>((other))->GetLengthPlusOne());
            FUN_004039c0(newLength);
        }
        else
        {
            FUN_00438470(other);
        }
    }
    return this;
}

// @fnv 0x007e1970
int FUN_007e1970()
{
    return 0x41e;
}

// @fnv 0x007e65a0
int __cdecl FUN_007e65a0()
{
    return 0x41b;
}

struct SysMgr
{
};
struct TaskA
{
    virtual int Run(int a);
};
struct MgrB
{
};


class Base
{
  public:
    virtual ~Base();
};

class MemA
{
  public:
    ~MemA();
};
class MemB
{
  public:
    ~MemB();
};

class FUN_007e9130_cls : public Base
{
  public:
    virtual ~FUN_007e9130_cls();
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    MemA m_b0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    MemB m_11c;
};

// @fnv 0x007e9130
FUN_007e9130_cls::~FUN_007e9130_cls()
{
    reinterpret_cast<::FaderManager *>(((*reinterpret_cast<::SysMgr * *>(&::DAT_011d8804))))->StopFader((::FADER_ENUM)(0), 0);
    ::FUN_007f6920();
    TaskA* pTask = ((::TaskA *)(reinterpret_cast<::Callees *>(((*reinterpret_cast<::MgrB * *>(&::DAT_011db0d4))))->FUN_00726070()));
    TaskA* p = pTask;
    (void)(p ? p->Run(1) : 0);
    (*reinterpret_cast<::MgrB * *>(&::DAT_011db0d4)) = 0;
}

// Computes the squared length of a 3-component vector and returns its approximate square root via a bit-manipulation lookup table.
// @fnv 0x007eb7f0
float __cdecl FastSqrt(const float* v)
{
    float f;
    unsigned int* p = (unsigned int*)&f;
    short e;
    f = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
    if (*p == 0)
    {
        return 0.0f;
    }
    else
    {
        e = (short)((*p >> 23) - 0x7f);
        *p &= 0x7fffff;
        if (e & 1)
            *p |= 0x800000;
        e >>= 1;
        *p = DAT_011f4aa8[*p >> 16] | ((e + 0x7f) << 23);
        return f;
    }
}

// @fnv 0x007eb8c0
int __cdecl FUN_007eb8c0()
{
    return (int)1056u;
}

class B7F7790Ref
{
  public:
    ~B7F7790Ref();
    void Reset(void* pvObject);

    void* m_pvObject;
};

class B7F7790List
{
  public:
    ~B7F7790List();

    int unk00;
};

class B7F7790Object
{
  public:
    virtual ~B7F7790Object();
};

class FUN_007f7790_cls
{
  public:
    ~FUN_007f7790_cls();

    B7F7790Ref m_kRef;
    B7F7790List m_kList;
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
    B7F7790Object* m_pPointer;
};

// Resets m_kRef to null and deletes the owned object pointer.
// @fnv 0x007f7790
FUN_007f7790_cls::~FUN_007f7790_cls()
{
    m_kRef.Reset(0);
    delete m_pPointer;
}

class NiColor;

struct ImageSpaceEffectParam
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    ImageSpaceEffectParam(float a, float b, float c, float d);
};

struct Dummy_00718c90;

struct SystemColorManager
{
    bool GetColor(int id, NiColor& out);
};


struct PipboyStub : FOPipboyManager
{
    void FUN_007f7f40();
};

struct FUN_007f7fb0_Value
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0C;
};

struct FUN_007f7fb0_Class
{
    unsigned char unk00[0xC0];
    FUN_007f7fb0_Value unkC0;

    void FUN_007f7fb0(const FUN_007f7fb0_Value* value);
};

// Copies the four-field value into the object's unkC0 member.
// @fnv 0x007f7fb0
void FUN_007f7fb0_Class::FUN_007f7fb0(const FUN_007f7fb0_Value* value)
{
    unkC0 = *value;
}

struct Quad4
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
};

struct FUN_007f7fe0_cls
{
    unsigned char _0[0xa8];
    Quad4 m_q;
    void SetQuad(const Quad4* src);
};
// @fnv 0x007f7f40
void PipboyStub::FUN_007f7f40()
{
    ImageSpaceEffectParam p(0.0f, 0.0f, 0.0f, 0.0f);
    if (reinterpret_cast<SystemColorManager*>(FUN_00718b60())->GetColor(4, *(NiColor*)&p))
    {
        reinterpret_cast<::FUN_007f7fe0_cls *>(this)->SetQuad((const ::Quad4 *)(::ImageSpaceEffectParam *)(&p));
        reinterpret_cast<::FUN_007f7fb0_Class *>(this)->FUN_007f7fb0((const ::FUN_007f7fb0_Value *)(::ImageSpaceEffectParam *)(&p));
        InitializeMenuLight();
    }
}

// Copies the four unsigned ints from src into the m_q member of this object.
// @fnv 0x007f7fe0
void FUN_007f7fe0_cls::SetQuad(const Quad4* apQuad)
{
    m_q = *apQuad;
}

struct SoundPlaybackHandle
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    SoundPlaybackHandle();
    SoundPlaybackHandle& operator=(const SoundPlaybackHandle&);
    ~SoundPlaybackHandle();
};

struct BSSoundHandleEx
{
    SoundPlaybackHandle base;
    ~BSSoundHandleEx();
};

struct BSAudio
{
    BSSoundHandleEx GetSoundHandleByEditorID(const char*, unsigned int);
};

struct GlobalObject_0044f440
{
};



struct FUN_007fa0f0_Class
{

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

    unsigned int unk110;

    unsigned int unk114;

    unsigned int unk118;

    unsigned int unk11C;

    float unk120;

    float unk124;

    float unk128;

    float unk12c;

    float values[1];

    void SetValue(int index, bool play);
};

// @fnv 0x007fa0f0
void FUN_007fa0f0_Class::SetValue(int index, bool play)
{
    if (unk120 != values[index])
    {
        unk120 = values[index];
        unk12c = *((float *)&(::FUN_00403e20((float *)&(::g_011db288))));
        if (g_burstSoundEnabled && play)
        {
            BSSoundHandleEx handle;
            handle = ::FUN_00453a70()->GetSoundHandleByEditorID("UIPipBoyTab", 0x121);
            reinterpret_cast<::FUN_00ad8830_shell *>(&(handle))->FUN_00ad8830(false);
        }
    }
}

struct FUN_007fb730_Class
{
    float x;
    float y;
    float z;

    FUN_007fb730_Class* Add(FUN_007fb730_Class* output, const FUN_007fb730_Class* input);
};

// Adds the input vector's x, y and z to this vector's components and writes the sum to output, returning output.
// @fnv 0x007fb730
FUN_007fb730_Class* FUN_007fb730_Class::Add(FUN_007fb730_Class* output, const FUN_007fb730_Class* input)
{
    FUN_007fb730_Class result = *this;

    result.x = result.x + input->x;
    result.y = result.y + input->y;
    result.z = result.z + input->z;

    *output = result;
    return output;
}

class NiBound7FD
{
  public:
};

class NiAVObject7FD
{
  public:
};

template <class T> class NiPointer7FD
{
  public:
    T* Get() const;

    T* m_pObject;
};

class ShadowSceneNode7FD
{
  public:
};


class Light7FD
{
  public:
    void FUN_007fd660(float fScale);

    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    int unk020, unk024, unk028, unk02C, unk030, unk034, unk038, unk03C;
    int unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C;
    int unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C;
    int unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC;
    int unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8;
    NiPointer7FD<NiAVObject7FD> m_spNode;
    NiPointer7FD<NiAVObject7FD> m_spLight;
};

// @fnv 0x007fd660
void Light7FD::FUN_007fd660(float fScale)
{
    float fRadius = reinterpret_cast<::Twin_0084d030 *>((void *)&((*(const ::NiBound7FD *)(reinterpret_cast<::FUN_0043d450_Owner *>((void *)(((::NiAVObject7FD *)(::FUN_00559450((int *)&(m_spNode))))))->FUN_0043d450()))))->GetStoredFloatValue() * 3.0 * fScale;
    reinterpret_cast<::SSN_b5 *>((((::ShadowSceneNode7FD *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(3)))))->FUN_00b5ca70((::Node_b5 *)(::NiAVObject7FD *)(((::NiAVObject7FD *)(::FUN_00559450((int *)&(m_spLight))))), fRadius);
}

struct NiNode;
template <class T> class NiPtrS
{
  public:
    T* m_pObject;
    ~NiPtrS();
    NiPtrS<T>& operator=(T* object);
};

class FUN_007fad10
{
  public:
    virtual ~FUN_007fad10();
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
};

class FUN_007fed10 : public FUN_007fad10
{
  public:
    NiPtrS<NiNode> m_spA[4];
    NiPtrS<NiNode> m_spB[4];
    NiPtrS<NiNode> m_sp0;
    NiPtrS<NiNode> m_sp1;
    NiPtrS<NiNode> m_sp2;
    NiPtrS<NiNode> m_sp3;
    NiPtrS<NiNode> m_sp4;
    NiPtrS<NiNode> m_sp5;
    virtual ~FUN_007fed10();
};

// Destructor that clears the four m_spA and m_spB NiNode smart pointers and the six m_sp0-m_sp5 pointers by assigning null.
// @fnv 0x007fed10
FUN_007fed10::~FUN_007fed10()
{
    for (int i = 0; i < 4; i++)
    {
        m_spA[i] = 0;
        m_spB[i] = 0;
    }
    m_sp0 = 0;
    m_sp1 = 0;
    m_sp2 = 0;
    m_sp3 = 0;
    m_sp4 = 0;
    m_sp5 = 0;
}

struct Entry;
struct ValueX
{
    void Clear();
};
struct MenuX
{
};
struct TileX
{
};
struct Entry
{
    TileX* tile;
    int data;
    int extra;
    Entry(TileX*, int*);
};
struct Entries
{
    Entry* first;
    Entries* next;
    void AddTail(Entry* const&);
};
struct ListOwner
{
    int unk00;
    Entries entries;
    TileX* parent;
    int unk10;
    int unk14;
    const char* templateName;
    unsigned short count;
    TileX* FUN_007e0e70(int data, const char* text, void* compare, const char* name);
};
// @fnv 0x007e0e70
TileX* ListOwner::FUN_007e0e70(int data, const char* text, void* compare, const char* name)
{
    if (parent && (templateName || name))
    {
        TileX* tile = ((::TileX *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((::MenuX *)(reinterpret_cast<::FUN_00a03c90_shell *>((parent))->FUN_00a03c90()))))->FUN_00a1ddb0((::Tile *)(parent), (char *)(name ? name : templateName), (::Tile *)(0))));
        if (!reinterpret_cast<::FUN_00a00f30_shell *>((tile))->FUN_00a00f30(0xfaa))
            reinterpret_cast<::Tile *>((tile))->Set(0xfaa, -1);
        if (text)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile))->FUN_00a01350(0xfc4, (char *)(text), true);
        if (compare)
        {
            reinterpret_cast<::FUN_00470440 *>(&(entries))->FUN_007a7eb0((::BGSPerkEntry *)(::Entry *)(new Entry(tile, &data)), (int (*)(BGSPerkEntry *, BGSPerkEntry *))(compare));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
                reinterpret_cast<::FUN_00724930_cls *>(this)->FUN_00724930();
        }
        else
        {
            reinterpret_cast<::Callees *>(&(entries))->FUN_00905820((void *)&(const ::Entry *const &)(new Entry(tile, &data)));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
            {
                reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(tile));
                reinterpret_cast<::VATSMenuView *>(this)->FUN_00724dd0();
            }
            reinterpret_cast<::Tile *>((tile))->Set(0xfac, count++);
        }
        if (::GetRaceCount((char *)this) == 1 && reinterpret_cast<::TileListBoxCalls *>((parent))->GetFloat(::FUN_00a00940("_number_of_visible_items", -1)) > 0.0)
        {
            ValueX* value = ((::ValueX *)(reinterpret_cast<::FUN_00a00e90_shell *>((parent))->FindTraitValue(0xfb0)));
            reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((value))->RemoveFromReactions();
            reinterpret_cast<::AGOwner *>((value))->FUN_00a09130(0x7d0, (::Tile *)(tile), 0xfb0);
            reinterpret_cast<::P03Value *>((value))->AppendFloatAction(0x7d3, reinterpret_cast<::TileListBoxCalls *>((parent))->GetFloat(::FUN_00a00940("_number_of_visible_items", -1)));
            reinterpret_cast<::fnv_00a09410::EvalValue *>((value))->FUN_00a09410(0);
        }
        return tile;
    }
    else
        return 0;
}

struct WXObject;

template <class T> struct WXPointer
{
    T* m_pObject;

    WXPointer(T* apObject);
    ~WXPointer();
    WXPointer& operator=(T* apObject);
};

struct WXPoint3
{
    float x;
    float y;
    float z;

    WXPoint3(float afX, float afY, float afZ);
};

struct WXParam
{
    float fA;
    float fB;
    float fC;
    float fD;

    WXParam(float afA, float afB, float afC, float afD);
};

struct WXTimeGlobal
{
};

struct WXIntSetting
{
};

struct WXFloatSetting
{
};



struct FUN_007faa20
{
    WXPointer<WXObject> spObject04;
    WXPointer<WXObject> spObject08;
    WXPointer<WXObject> spObject0C;
    WXPointer<WXObject> spObject10;
    WXPointer<WXObject> spObject14;
    int iValue18;
    WXPointer<WXObject> spObject1C;
    int iValue20;
    WXPointer<WXObject> spObject24;
    bool bFlag28;
    bool bFlag29;
    bool bFlag2A;
    WXPoint3 kPoint2C;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    char unk4C;
    bool bFlag4D;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    bool bFlag60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    bool bFlag74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    float fValue8C;
    float fValue90;
    bool bFlag94;
    bool bFlag95;
    int unk98;
    int unk9C;
    float fDurationA0;
    float fTimeA4;
    WXParam kParamA8;
    bool bFlagB8;
    bool bFlagB9;
    WXPointer<WXObject> spObjectBC;
    WXParam kParamC0;
    int unkD0;
    WXPointer<WXObject> spObjectD4;

    FUN_007faa20();
    virtual ~FUN_007faa20();
};

// @fnv 0x007faa20
FUN_007faa20::FUN_007faa20()
    : spObject04(0), spObject08(0), spObject0C(0), spObject10(0), spObject14(0), spObject1C(0), spObject24(0),
      kPoint2C(0.0f, 0.0f, 0.0f), kParamA8(0.0f, 0.0f, 0.0f, 0.0f), spObjectBC(0), kParamC0(0.0f, 0.0f, 0.0f, 0.0f),
      spObjectD4(0)
{
    spObject24 = 0;
    spObject04 = 0;
    spObject14 = 0;
    spObject0C = 0;
    spObject10 = 0;
    iValue18 = 0;
    bFlag28 = false;
    bFlag29 = false;
    bFlag4D = false;
    bFlag60 = false;
    bFlag74 = false;
    bFlagB8 = false;
    bFlagB9 = false;
    fValue8C = 0.0f;
    fValue90 = 0.0f;
    spObject1C = 0;
    kParamA8 = WXParam(0.0f, 0.0f, 0.0f, 0.0f);
    bFlag2A = false;
    bFlag95 = false;
    fTimeA4 = (double)reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::WXTimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00() + std::rand() % *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::WXIntSetting *>(&::g_011db4f8))))));
    fDurationA0 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::WXFloatSetting *>(&::g_011db4d0))))));
    bFlag94 = false;
    iValue20 = 0;
}

struct Accum
{
    Accum(int, unsigned int, unsigned int);
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
};
struct Ref
{
    void* object;
    Ref(void* = 0);
    ~Ref();
    Ref& operator=(void*);
    operator Accum*() const;
};
struct Pair
{
    int value;
    Ref node;
    Pair();
    ~Pair();
};
struct FloatSetting
{
};
struct IntSetting
{
};
struct StringSetting
{
};

struct FUN_007ffec0
{
    int unk000;
    Pair first;
    int unk00c;
    int unk010;
    Pair entries[32];
    Ref unk114;
    bool unk118;
    bool active[16];
    bool unk129;
    short unk12a;
    int values[16];
    int states[16];
    bool flags[16];
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    bool unk284;
    char unk285;
    short unk286;
    int unk288;
    float unk28c;
    float unk290;
    float unk294;
    bool unk298;
    char unk299;
    short unk29a;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    float unk2ac;
    float unk2b0;
    bool unk2b4;
    bool unk2b5;
    short unk2b6;
    int unk2b8;
    int unk2bc;
    float unk2c0;
    Ref unk2c4;
    int unk2c8;
    Ref unk2cc;
    FUN_007ffec0();
};
// Initializes the object's fields, loads a texture, creates a disabled Accum, and clears the 16 per-slot arrays.
// @fnv 0x007ffec0
FUN_007ffec0::FUN_007ffec0()
{
    unk118 = false;
    unk129 = true;
    unk28c = 0.0f;
    unk290 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::g_011db6bc))))));
    unk298 = false;
    unk284 = false;
    unk2ac = 0.0f;
    unk2b0 = 0.0f;
    unk2c0 = 0.0f;
    unk294 = (double)reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((void *)&(g_timeGlobal))->FUN_00825c00() + std::rand() % *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::IntSetting *>(&::g_011db75c))))));
    unk2b4 = false;
    unk2b5 = false;
    unk240 = 0;
    first.value = 0;
    first.node = 0;
    ::BSShaderManager::GetTexture(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StringSetting *>(&::g_011db744))))->GetMenuTitle())), true, (::NiPointer< ::NiTexture> &)(unk2c4), false, false);
    unk000 = 0;
    unk00c = 0;
    unk010 = -1;
    unk2cc = new Accum(0x65, 1, 0x2f7);
    reinterpret_cast<::FUN_005db4c0_struct *>((((Accum*)unk2cc)))->FUN_005db4c0(false);
    unk2c8 = 1;
    for (int index = 0; index < 16; ++index)
    {
        active[index] = false;
        states[index] = 0;
        values[index] = 0;
        flags[index] = false;
    }
}

struct RemoveTile
{
    virtual void* Destroy(unsigned int);
};
struct RemoveOwned
{
    void* FUN_004459e0(unsigned int);
};
struct RemoveData
{
    RemoveTile* tile;
    RemoveOwned* owned;
    bool filtered;
};
struct RemoveNode
{
    RemoveData* data;
    RemoveNode* next;
};
struct RemoveInterface
{
};
struct RemoveBase
{
    int unk00;
};
struct RemoveView : RemoveBase, RemoveNode
{
    RemoveTile* container;
    RemoveTile* selected;
    bool RemoveNodeFromList(RemoveNode*, RemoveNode*);
};
// @fnv 0x007f7380
bool RemoveView::RemoveNodeFromList(RemoveNode* node, RemoveNode* previous)
{
    if (node)
    {
        if ((*((::RemoveData **)(new ((void *)(node)) ::Vec3())))->tile == selected)
        {
            selected = ((::RemoveNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())) ? (*((::RemoveData **)(new ((void *)(((::RemoveNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))) ::Vec3())))->tile
                                            : (previous && previous != node ? (*((::RemoveData **)(new ((void *)(previous)) ::Vec3())))->tile : 0);
            if (selected)
                reinterpret_cast<::FocusManager *>((((::RemoveInterface *)(::fnv_004b7210::FUN_004b7210()))))->FUN_00715860((::FocusTile *)(selected), 0xfc3, true);
        }
        if (container && (*((::RemoveData **)(new ((void *)(node)) ::Vec3())))->filtered)
        {
            reinterpret_cast<::FUN_00a012d0_t *>((container))->FUN_00a012d0(FUN_00a01860("_num_filtered"),
                                    (float)(reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(FUN_00a01860("_num_filtered")) - 1.0), true);
        }
        RemoveTile* tile_2 = (*((::RemoveData **)(new ((void *)(node)) ::Vec3())))->tile;
        RemoveTile* tileCopyA = tile_2;
        tileCopyA ? tileCopyA->Destroy(1) : 0;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(true))
        {
            RemoveOwned* owned3 = (*((::RemoveData **)(new ((void *)(node)) ::Vec3())))->owned;
            RemoveOwned* ownedCopyB = owned3;
            ownedCopyB ? ownedCopyB->FUN_004459e0(1) : 0;
        }
        {
            RemoveData* record7 = *((::RemoveData **)(new ((void *)(node)) ::Vec3()));
            FUN_00401030(record7);
        }
        if (node == static_cast<RemoveNode*>(this))
        {
            if (next)
            {
                previous = next;
                next = ((::RemoveNode *)(reinterpret_cast<::Callees *>((previous))->FUN_00726070()));
                data = *((::RemoveData **)(new ((void *)(previous)) ::Vec3()));
                reinterpret_cast<::CombatProcedure *>((previous))->Initialize((::CombatController *)(::RemoveNode *)(0));
                RemoveNode* oldA = previous;
                RemoveNode* oldCopyATmp = oldA;
                oldCopyATmp ? ((void *)(reinterpret_cast<::W004702f0 *>((oldCopyATmp))->FUN_004702f0(1))) : 0;
            }
            else
            {
                data = 0;
            }
        }
        else
        {
            reinterpret_cast<::CombatProcedure *>((previous))->Initialize((::CombatController *)(::RemoveNode *)(((::RemoveNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()))));
            reinterpret_cast<::CombatProcedure *>((node))->Initialize((::CombatController *)(::RemoveNode *)(0));
            RemoveNode* oldB = node;
            RemoveNode* oldCopyB4 = oldB;
            oldCopyB4 ? ((void *)(reinterpret_cast<::W004702f0 *>((oldCopyB4))->FUN_004702f0(1))) : 0;
        }
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(false))
            reinterpret_cast<::FUN_00726090_cls *>(this)->FUN_00726090();
        return true;
    }
    return false;
}

void __cdecl FUN_007f7a50(float a, float b);

struct Menu;

// VEGAS17-CONFLICT: Menu (variant definition below differs from the one above)
struct Menu
{
    virtual ~Menu();  // the original class is polymorphic (rtti_variants.py)
    virtual void M01();
    virtual void M02();
    virtual void M03();
    virtual void M04();
    virtual void M05();
    virtual void M06();
    virtual void M07();
    virtual void M08();
    virtual void M09();
    virtual void M10();
    virtual void M11();
    virtual void M12();
    virtual int GetID();
    char menuData[0x24];
public:
    void SetMenuVisibility(bool);
};

void FUN_007e65b0();

int FUN_007e1970();

int __cdecl FUN_007e65a0();

int __cdecl WXRand();

class TileMenu;

class TextEditMenu;

class Menu;

struct TextEditState
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    void FUN_00716aa0(int maxLength);
};

struct TextEditSetting
{
};

class TileMenu : public Tile
{
  public:
    virtual ~TileMenu();
};

class TextEditMenu : public Menu
{
  public:
    Tile* input;
    Tile* accept;
    Tile* title;
    TextEditState editor;
    void(__cdecl* callback)(const char*);
};

// @fnv 0x007e6320
bool __cdecl FUN_007e6320(const char* titleText, const char* initialText, void(__cdecl* callback)(const char*))
{
    Menu* previous = ((::Menu *)(::FUN_00a09030(0x41b)));
    if (previous)
        delete previous;

    RemoveInterface* interfaceManager = ((::RemoveInterface *)(::fnv_004b7210::FUN_004b7210()));
    float depthA = ::Tile::GetInterfaceScale();
    Tile* root2 = reinterpret_cast<::fnv_00a01b00::TileLoader *>((reinterpret_cast<::InterfaceManager *>((interfaceManager))->FUN_00586150()))->FUN_00a01b00({});
    Menu* menu = reinterpret_cast<::FUN_00a03c90_shell *>((root2))->FUN_00a03c90();
    if (menu && menu->GetID() == FUN_007e65a0())
    {
        reinterpret_cast<::FUN_00a1dc70_shell *>((menu))->FUN_00a1dc70(dynamic_cast<TileMenu*>(root2), false);
        (*reinterpret_cast<::TextEditMenu * *>(&::DAT_011daec4)) = dynamic_cast<TextEditMenu*>(menu);
        if (reinterpret_cast<::TileListBoxCalls *>((root2))->GetFloat(0xfa7) == 6006.0 || reinterpret_cast<::TileListBoxCalls *>((root2))->GetFloat(0xfa7) == 102.0)
            reinterpret_cast<::FUN_00a012d0_t *>((root2))->FUN_00a012d0(0xfad, depthA, true);

        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::TextEditMenu * *>(&::DAT_011daec4))->title))->FUN_00a01350(0xfc4, (char *)(titleText), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::TextEditMenu * *>(&::DAT_011daec4))->input))->FUN_00a01350(0xfc4, (char *)(initialText), true);
        (*reinterpret_cast<::TextEditMenu * *>(&::DAT_011daec4))->editor.FUN_00716aa0((int)reinterpret_cast<::TileListBoxCalls *>(((*reinterpret_cast<::TextEditMenu * *>(&::DAT_011daec4))->input))->GetFloat(0xfba));
        reinterpret_cast<::S6a70 *>(&((*reinterpret_cast<::TextEditMenu * *>(&::DAT_011daec4))->editor))->SetBothStrings(reinterpret_cast<::FUN_00a011f0_shell *>(((*reinterpret_cast<::TextEditMenu * *>(&::DAT_011daec4))->input))->FUN_00a011f0(0xfc4));
        reinterpret_cast<::S7010 *>(&((*reinterpret_cast<::TextEditMenu * *>(&::DAT_011daec4))->editor))->FUN_00717010(true);
        reinterpret_cast<::Twin_007e6580 *>(&((*reinterpret_cast<::TextEditMenu * *>(&::DAT_011daec4))->editor))->SetIsForegroundEffect(true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::TextEditMenu * *>(&::DAT_011daec4))->accept))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::TextEditSetting *>(&::g_011d38b8))))->GetMenuTitle()))), true);
        (*reinterpret_cast<::TextEditMenu * *>(&::DAT_011daec4))->callback = callback;
        reinterpret_cast<::FUN_007e6700_Class *>(((*reinterpret_cast<::TextEditMenu * *>(&::DAT_011daec4))))->FUN_007e6700();
        menu->SetMenuVisibility(false);
        return true;
    }
    else if (menu && ((int)(reinterpret_cast<::Callees *>((menu))->FUN_00726070())))
    {
        delete menu;
    }
    return false;
}

#include "generated/data/staging/blk_007e0000_od.inc"
