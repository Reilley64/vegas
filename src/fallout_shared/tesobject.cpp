// fallout_shared/tesobject.cpp: TESObject, TESBoundObject, SceneObjectLookup, TESFormList and more (81 functions)

#include <cstdint>
#include <string.h>
#include <new>
#include "fnv/decl/A5D2C0Object.h"
#include "fnv/decl/BSXFlags.h"
#include "fnv/decl/BSXFlags_shell.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/ControllerOwner.h"
#include "fnv/decl/FUN_00402a20_class.h"
#include "fnv/decl/FUN_00407820_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0040e500_shell.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_00418770_shell.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_00444ed0_shell.h"
#include "fnv/decl/FUN_004472a0_shell.h"
#include "fnv/decl/FUN_0044a690_cls.h"
#include "fnv/decl/FUN_0044a970_Cls.h"
#include "fnv/decl/FUN_00457ba0_class.h"
#include "fnv/decl/FUN_0045a5e0_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00477ba0_shell.h"
#include "fnv/decl/FUN_0047cdb0_shell.h"
#include "fnv/decl/FUN_004aad00_shell.h"
#include "fnv/decl/FUN_004fb970_class.h"
#include "fnv/decl/FUN_004fd4f0_Class.h"
#include "fnv/decl/FUN_0050d4a0_shell.h"
#include "fnv/decl/FUN_00510130_shell.h"
#include "fnv/decl/FUN_00510360_Class.h"
#include "fnv/decl/FUN_00510380_Class.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005bb4d0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00603bb0_Owner.h"
#include "fnv/decl/FUN_0064dc30_class.h"
#include "fnv/decl/FUN_0064dee0_Class.h"
#include "fnv/decl/FUN_0064e300_Class.h"
#include "fnv/decl/FUN_0064e340_class.h"
#include "fnv/decl/FUN_0064e480_Class.h"
#include "fnv/decl/FUN_0065f7a0_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00929240_Class.h"
#include "fnv/decl/FUN_0092c870_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009cdae0_shell.h"
#include "fnv/decl/FUN_009d9f00_Class.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FlagSet.h"
#include "fnv/decl/LightCreation__LightForm.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MyHost.h"
#include "fnv/decl/NP_0044aed0.h"
#include "fnv/decl/RefrShell_569350.h"
#include "fnv/decl/S_447010.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Thing.h"
#include "fnv/decl/TreeManager.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Unk65.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0047a520__Fn47a520.h"
#include "fnv/decl/fnv_0047ce10__OwnerShell.h"
#include "fnv/decl/fnv_00483370__FUN_00483370.h"
#include "fnv/decl/fnv_0050f9c0__FUN_0050f9c0_shell.h"
#include "fnv/decl/fnv_00567400__FUN_00567400_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_00ad8100__FUN_00ad8100_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_0040a000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00448000.h"
#include "fnv/symbols_0044c000.h"
#include "fnv/symbols_0044d000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_00480000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00489000.h"
#include "fnv/symbols_0048b000.h"
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_0050e000.h"
#include "fnv/symbols_00511000.h"
#include "fnv/symbols_00517000.h"
#include "fnv/symbols_00518000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00569000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0062c000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_0065f000.h"
#include "fnv/symbols_00664000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00c8e000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01029000.h"
#include "fnv/symbols_01082000.h"
#include "fnv/symbols_010a2000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c8000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011df000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_01203000.h"
#include "tesobject_decls.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/TESActorBase.h"
#include "fnv/symbols_011f6000.h"
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <cstdio>
#include "fnv/decl/FNV_ad0470_class.h"
#include "fnv/decl/FUN_00658f30.h"
#include "fnv/decl/FUN_0065dc60Class.h"
#include "fnv/decl/FUN_0065dd90_Class.h"
#include "fnv/decl/FUN_00ac0640.h"
#include "fnv/decl/FUN_00ac0b80_It.h"
#include "fnv/decl/FUN_00ac0c40_It.h"
#include "fnv/decl/FUN_00ac5c00_cls.h"
#include "fnv/decl/FUN_00ac6100_cls.h"
#include "fnv/decl/FUN_00ac9df0_Q.h"
#include "fnv/decl/GvIos.h"
#include "fnv/decl/Ostream.h"
#include "fnv/decl/S00acede0_Obj.h"
#include "fnv/decl/S_00acfb90_Class.h"
#include "fnv/decl/StrA.h"
#include "fnv/decl/StrB.h"
#include "fnv/decl/StringQ.h"
#include "fnv/decl/Vec.h"
#include "fnv/decl/VecQ_acab30.h"
#include "fnv/decl/VecQ_acb3c0.h"
#include "fnv/decl/fnv_0065ed70__FUN_0065ed70.h"
#include "fnv/decl/fnv_00aca560__FUN_00aca560_Q.h"
#include "fnv/decl/fnv_00aca7a0__FUN_00aca7a0_Q.h"
#include "fnv/decl/rework_acda90__VecQ_acda90.h"
#include "fnv/decl/vecacd__VcVector.h"
#include "fnv/symbols_0065e000.h"
#include "fnv/symbols_00aaf000.h"
#include "fnv/symbols_00ab7000.h"
#include "fnv/symbols_00ac0000.h"
#include "fnv/symbols_00ac2000.h"
#include "fnv/symbols_00ac6000.h"
#include "fnv/symbols_00ac7000.h"
#include "fnv/symbols_00ad5000.h"
#include "fnv/symbols_01021000.h"
#include "fnv/symbols_01063000.h"
#include "fnv/symbols_010a3000.h"

// @fnv 0x0050fbe0
NiNode* TESObject::_CreateNiNode(TESObjectREFR* reference, bool arg1)
{
    return 0;
}

// @fnv 0x005101e0
TESObject* TESFormList::InsertObjectAfter(TESObject* after, TESObject* object)
{
    if (this == (TESFormList*)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>(((*reinterpret_cast<::BSSimpleList< ::BGSPerkEntry *> * *>(&::g_dataHandler))))->FUN_00726070())))
        reinterpret_cast<::TESForm *>((void *)(((TESBoundObject*)object)))->GetFormType();
    ((BGSDehydrationStage*)object)->FUN_0050f9a0((SpellItem*)after);
    if (after)
    {
        reinterpret_cast<::fnv_0050f9c0::FUN_0050f9c0_shell *>((((TESResponse*)object)))->FUN_0050f9c0((::fnv_0050f9c0::TESForm *)(::TESIdleForm *)((TESIdleForm*)((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((TESObjectREFR*)after)))->FUN_007af430()))));
        if (((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((TESObjectREFR*)after)))->FUN_007af430())))
            ((BGSDehydrationStage*)((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((TESObjectREFR*)after)))->FUN_007af430())))->FUN_0050f9a0((SpellItem*)object);
        reinterpret_cast<::fnv_0050f9c0::FUN_0050f9c0_shell *>((((TESResponse*)after)))->FUN_0050f9c0((::fnv_0050f9c0::TESForm *)(::TESIdleForm *)((TESIdleForm*)object));
    }
    else
    {
        reinterpret_cast<::fnv_0050f9c0::FUN_0050f9c0_shell *>((((TESResponse*)object)))->FUN_0050f9c0((::fnv_0050f9c0::TESForm *)(::TESIdleForm *)(0));
    }
    if (!((::TESObject *)(reinterpret_cast<::FUN_00510360_Class *>(this)->FUN_00510360(object))))
        m_pSecondObject = object;
    if (!((::TESObject *)(reinterpret_cast<::FUN_00510380_Class *>(this)->GetTerrainMinLevel((::BGSTerrainManager *)(object)))))
        m_pFirstObject = object;
    ++m_uiObjectCount;
    reinterpret_cast<::TESPackage *>((((InterfaceManager*)object)))->SetProcedureType((::PACKAGE_PROCEDURE_TYPE)((unsigned int)this));
    return object;
}

// @fnv 0x0050f9e0
bool TESObject::HasLoaded3D()
{
    if (!this)
        return false;
    switch (GetFormType())
    {
    case 28:
        if ((TESObject*)DAT_011ca258 == this)
            return true;
        break;
    case 32:
        if ((TESObject*)DAT_011ca220 == this || (TESObject*)DAT_011ca250 == this || (TESObject*)DAT_011ca25c == this ||
            (TESObject*)DAT_011ca260 == this || (TESObject*)DAT_011ca254 == this || (TESObject*)DAT_011ca224 == this ||
            (TESObject*)DAT_011ca26c == this || (TESObject*)DAT_011ca244 == this || (TESObject*)DAT_011ca248 == this ||
            (TESObject*)DAT_011ca24c == this || (TESObject*)DAT_011ca230 == this || (TESObject*)DAT_011ca264 == this ||
            (TESObject*)DAT_011ca228 == this || (TESObject*)DAT_011ca22c == this)
            return true;
        break;
    case 21:
        if (!FUN_00404dc0(::FUN_004895b0((::TESForm *)(::TESObject *)(this)), "EditorMarker.NIF"))
            return true;
        break;
    case 30:
        if (!::FUN_00489540(this))
            return true;
        break;
    case 4:
    case 48:
        return true;
    }
    switch (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((TESForm*)this)))->FUN_0084e3a0())))
    {
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
    case 107:
    case 108:
    case 109:
    case 110:
    case 111:
    case 112:
    case 113:
    case 114:
    case 115:
    case 116:
    case 117:
    case 118:
    case 119:
        return true;
    }
    return false;
}

// Builds a NiNode from the reference's model, names it with the editor ID, applies scale, and returns the node or null.
// @fnv 0x0050d250
NiNode* TESObjectLIGH::Create3DModel(TESObjectREFR* reference)
{
    NiNode* node = 0;
    NiPointer<NiAVObject> empty(0);
    NiPointer<NiAVObject> source(CreateNiNode(reference));
    if (((NiPointer<NiNode>*)&source)->operator->())
    {
        unsigned int size = ((BGSCameraPath*)this)->HasNameForWarning() + 16;
        void* buffer = _alloca(size);
        if (!model.GetModelLength())
        {
            node = ((NiPointer<NiNode>*)&source)->operator->()->GetAsNiNode();
            if (node)
                ::AssignFixedString((char *)(node), (int)&(const ::NiFixedString &)(NiFixedString(GetEditorID())), {});
        }
        if (reinterpret_cast<::FUN_0050d4a0_shell *>((((PlayerCharacter*)this)))->FUN_0050d4a0() && reference)
            reinterpret_cast<::TESForm *>((reference))->SetCollisionDisabled(true);
        float scale = 1.0f;
        if (reference)
            scale = reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((((PlayerCharacter*)reference)))->FUN_00567400();
        {
            CloningProcess process(scale);
            if (model.GetModelLength())
            {
                node = (NiNode*)((::NiAVObject *)(reinterpret_cast<::A5D2C0Object *>((((NiPointer<NiNode>*)&source)->operator->()))->FUN_00a5d2c0((::A5D2C0CloningProcess &)(process))));
            }
            else if (!node)
            {
                node = new BSFadeNode;
            }
            reinterpret_cast<::LightCreation::LightForm *>(this)->FUN_0050d810((::LightCreation::Reference *)(reference), (::LightCreation::Scene *)(node), false);
            reinterpret_cast<::FUN_00a5a040_Class *>((node))->FUN_00a5a040();
            return node;
        }
    }
    return 0;
}

struct String_0044a540
{
    void _Tidy(bool, unsigned int);
};

// @fnv 0x0044a540
void FUN_0044a540(std::basic_string<char, std::char_traits<char>, std::allocator<char> >* apString)
{
    reinterpret_cast<String_0044a540*>(apString)->_Tidy(true, 0);
}

namespace fnv_0044a580 {
namespace std {
template <class T> struct char_traits
{
};
template <class T> class allocator
{
};
template <class C, class T, class A> class basic_string
{
  public:
    int pad0;
    char* Ptr;
    int pad1[4];
    unsigned int Res;
    void _Eos(unsigned int);
    bool _Grow(unsigned int, bool);
    char* _Myptr();
    void EraseRange(unsigned int, unsigned int);
};
}
struct AnimIdle
{
};
void FUN_00ec30e8();
typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > Str;
struct FUN_0044a580_cls : public Str
{
    FUN_0044a580_cls* AssignSubstring(Str& _Right, unsigned int _Roff, unsigned int _Count);
};
// Copies up to _Count characters starting at _Roff from _Right into this string, handling self-assignment by shifting in place.
// @fnv 0x0044a580
FUN_0044a580_cls* FUN_0044a580_cls::AssignSubstring(Str& _Right, unsigned int _Roff, unsigned int _Count)
{
    if (((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((AnimIdle*)&_Right)))->FUN_00825c00())) < _Roff)
        FUN_00ec30e8();
    unsigned int _Num = ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((AnimIdle*)&_Right)))->FUN_00825c00())) - _Roff;
    if (_Count < _Num)
        _Num = _Count;
    if (this == &_Right)
    {
        reinterpret_cast<::FUN_0044a690_cls *>(this)->EraseRange(_Roff + _Num, ::g_010173f0);
        reinterpret_cast<::FUN_0044a690_cls *>(this)->EraseRange(0, _Roff);
    }
    else if (_Grow(_Num, false))
    {
        ::FUN_0044ccd0(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970(), Res, reinterpret_cast<::FUN_0044a970_Cls *>(&(_Right))->FUN_0044a970() + _Roff, _Num);
        _Eos(_Num);
    }
    return this;
}
}  // namespace fnv_0044a580

namespace fnv_0044a730 {
namespace std {
template <class T> struct char_traits
{
};
template <class T> class allocator
{
};
template <class C, class T, class A> class basic_string
{
  public:
    int pad0;
    char* Ptr;
    int pad1[4];
    unsigned int Res;
    void _Eos(unsigned int);
    void FUN_0064df10(char*, unsigned int);
};
}
struct FUN_0044a730_cls : public std::basic_string<char, std::char_traits<char>, std::allocator<char> >
{
    void FUN_0044a730(bool, unsigned int);
};
// @fnv 0x0044a730
void FUN_0044a730_cls::FUN_0044a730(bool _Built, unsigned int _Newsize)
{
    if (!_Built)
    {
    }
    else if (Res >= 16)
    {
        char* _Ptr = this->Ptr;
        if (_Newsize > 0)
            ::FUN_0044ccd0((char*)&this->Ptr, 16, _Ptr, _Newsize);
        FUN_0064df10(_Ptr, Res + 1);
    }
    Res = 15;
    _Eos(_Newsize);
}
}  // namespace fnv_0044a730

namespace fnv_0044a880 {
namespace std {
template <class _Elem> struct char_traits;
template <class _Ty> class allocator;
template <class _Elem, class _Traits, class _Ax> class basic_string
{
  public:
    char* _Myptr();
    void ResizeString(unsigned int _Newsize);
};
}

void __cdecl FUN_0044a8c0(char&, const char&);

// Sets the string's size field to _Newsize and writes a null terminator at the new end of the buffer.
// @fnv 0x0044a880
template <>
void std::basic_string<char, std::char_traits<char>, std::allocator<char> >::ResizeString(unsigned int _Newsize)
{
    char c = 0;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x14) = _Newsize;
    FUN_0044a8c0(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970()[_Newsize], c);
}
}  // namespace fnv_0044a880

struct _DummyTag
{
};
_DummyTag __cdecl FUN_0065e750();
char* __cdecl FUN_0044e420(char*, unsigned int, const char*, unsigned int, _DummyTag);

// @fnv 0x0044ccd0
char* __cdecl FUN_0044ccd0(char* _First1, unsigned int _Size_in_bytes, const char* _First2, unsigned int _Count)
{
    return FUN_0044e420(_First1, _Size_in_bytes, _First2, _Count, FUN_0065e750());
}

struct NiStream;
struct blob6
{
    char b[6];
};
struct ShortPoint3
{
    static struct blob6 ComponentProduct(void*, void*);
    float Length();
    short SqrLength();
    short Dot(void*);
    struct blob6 Cross(void*);
    float GetFloatX();
    float GetFloatY();
    float GetFloatZ();
    void SetFloatX(float);
    void SetFloatY(float);
    void SetFloatZ(float);
    static void* GetZERO();
    static void* GetUNIT_X();
    static void* GetUNIT_Y();
    static void* GetUNIT_Z();
    static void* GetUNIT_ALL();
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    short x;
    short y;
    short z;
};
struct FUN_0050e8b0_shell : public ShortPoint3
{
    ShortPoint3* FUN_0050e8b0(void*);
};
// @fnv 0x0050e820
TESBoundObject::TESBoundObject()
{
    ::FUN_0050e9c0((char *)&(bounds));
    reinterpret_cast<::FUN_0050e8b0_shell *>(&(bounds.min))->FUN_0050e8b0((void *)&(GetActorValueShortVector()));
    reinterpret_cast<::FUN_0050e8b0_shell *>(&(bounds.max))->FUN_0050e8b0((void *)&(GetActorValueShortVector()));
}

// Copies the x, y and z components from arPt into this point and returns this.
// @fnv 0x0050e8b0
ShortPoint3* FUN_0050e8b0_shell::FUN_0050e8b0(void* apPoint)
{
    x = ((ShortPoint3*)apPoint)->x;
    y = ((ShortPoint3*)apPoint)->y;
    z = ((ShortPoint3*)apPoint)->z;
    return this;
}

struct ActorValueShortVector : public TESBoundPoint
{
    ActorValueShortVector(int, int, int);
public:
    ::ActorValueShortVector *Subtract(::ActorValueShortVector *, const ::ActorValueShortVector &);
};
// Returns a reference to a static ActorValueShortVector constructed with (0, 0, 0).
// @fnv 0x0050e8f0
const TESBoundPoint& GetActorValueShortVector()
{
    static ActorValueShortVector DAT_011c9124(0, 0, 0);
    return DAT_011c9124;
}


// Calls _ref_006815c0 on pThis and on pThis + 6, then returns pThis.
// @fnv 0x0050e9c0
void* FUN_0050e9c0(char* pThis)
{
    (void *)(pThis);
    (void *)(pThis + 6);
    return pThis;
}

struct FUN_0050e9f0_shell : public TESBoundObject
{
    void FUN_0050e9f0();
};

extern const void* const vftable_TESBoundObject[];
void FUN_0050f930(void*);

struct NiPoint3
{
    float x, y, z;
    NiPoint3 operator-(const NiPoint3& pt) const;
public:
    static const ::NiPoint3 ZERO;
};

struct FUN_0050ea10_class
{
    char pad[0xc];
    NiPoint3 m_kCenter;
    NiPoint3 m_kExtents;
    // Computes the box minimum corner by subtracting m_kExtents from m_kCenter and stores it in arPoint.
// @fnv 0x0050ea10
    void FUN_0050ea10(NiPoint3& arMinCorner) const
    {
        arMinCorner = m_kCenter - m_kExtents;
    }
};

static void (FUN_0050ea10_class::*volatile p)(NiPoint3&) const = &FUN_0050ea10_class::FUN_0050ea10;

struct FUN_0050eaa0_shell : public TESBoundObject
{
    void FUN_0050eaa0(TESBoundObject*);
};


// Copies 0xc bytes from offset 0x24 of apCopy into offset 0x24 of this object.
// @fnv 0x0050eaa0
void FUN_0050eaa0_shell::FUN_0050eaa0(TESBoundObject* apCopy)
{
    ::__memcpy((char*)&this->bounds, (char*)&apCopy->bounds, 0xc);
}

namespace fnv_0050ebf0 {
struct FUN_0050ebf0_shell : public TESBoundObject
{
    float FUN_0050ebf0();
};

struct ActorValueShortVector
{
    short x, y, z;
    ActorValueShortVector operator-(const ActorValueShortVector& rhs) const
    {
        return (*(::fnv_0050ebf0::ActorValueShortVector *)(reinterpret_cast<::ActorValueShortVector *>((void *)this)->Subtract((::ActorValueShortVector *)&(rhs), *(const ::ActorValueShortVector *)nullptr)));
    }
};


// Subtracts the ActorValueShortVector at offset 0x2a from the one at 0x24, passes the result to FUN_0050ec80, and scales it by DAT_01011588.
// @fnv 0x0050ebf0
float FUN_0050ebf0_shell::FUN_0050ebf0()
{
    return ((double)(::FUN_0050ec80((short *)(&((*(::fnv_0050ebf0::ActorValueShortVector *)(reinterpret_cast<::ActorValueShortVector *>((void *)(((ActorValueShortVector*)((char*)this + 0x24))))->Subtract((::ActorValueShortVector *)&(*(const ActorValueShortVector*)((char*)this + 0x2a)), *(const ::ActorValueShortVector *)nullptr)))))))) *
           ::DAT_01011588;
}
}  // namespace fnv_0050ebf0

struct BGSDebris;
struct BGSDestructibleObjectForm;
struct BGSExplosion;
struct BGSMenuIcon;
struct BGSMessageIcon;
struct BGSTextureSet;
struct CollisionComponent;
struct DestructionStageData;
struct IDebugText;
struct QueuedFile;
struct Script;
struct TESIcon;
struct TESModelTextureSwap;
struct TESTexture;
struct DistantTreeTextureInfo;
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
struct FUN_0050ee20_shell : public TESBoundAnimObject
{
    bool FUN_0050ee20(char*);
};
// @fnv 0x00605410
NiNode* TESCreature::Create3DModel(TESObjectREFR* reference)
{
    if (reinterpret_cast<::FUN_0047cdb0_shell *>(&(actorData))->FUN_0047cdb0() && reference && !reinterpret_cast<::Thing *>((reference))->FUN_0056afc0())
    {
        reinterpret_cast<::fnv_0047ce10::OwnerShell *>(&(actorData))->FUN_0047ce10((::fnv_0047ce10::RefShell *)(reference));
        return ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()))->Create3DModel(reference);
    }
    NiNode* node = 0;
    if (reference)
    {
        BipedAnim* biped = reference->GetBipedAnim();
        node = Get3DObject(reference, false);
        if (biped)
        {
            if (::FUN_004aae30(node, (::NiFixedString *)("Bip01")))
            {
                reinterpret_cast<::FUN_004aad00_shell *>((biped))->InitBoneSlots((::NiAVObject *)(node));
                reinterpret_cast<::FUN_00a5a040_Class *>((node))->FUN_00a5a040();
                NiUpdateData update(0.0f, false, false);
                reinterpret_cast<::FUN_00a59c60_cls *>((node))->FUN_00a59c60((::std::intptr_t)&(update));
            }
        }
        else if (::FUN_004aae30(node, (::NiFixedString *)("Bip01")))
        {
            biped = new BipedAnim(reference, node);
            reference->SetBipedAnim(biped);
            reinterpret_cast<::FUN_00a5a040_Class *>((node))->FUN_00a5a040();
            NiUpdateData update(0.0f, false, false);
            reinterpret_cast<::FUN_00a59c60_cls *>((node))->FUN_00a59c60((::std::intptr_t)&(update));
        }
    }
    return node;
}

// Calls the virtual function at vtable offset 0x14c with pfilename and 0, returning its bool result.
// @fnv 0x0050ee20
bool FUN_0050ee20_shell::FUN_0050ee20(char* pfilename)
{
    return (this->*(*(bool(FUN_0050ee20_shell::***)(char*, int))this)[0x14c / 4])(pfilename, 0);
}


// @fnv 0x0050f6f0
void* FUN_0050f6f0(void* pThis)
{
    new ((void *)(pThis)) ::TESBoundObject();
    *(int**)pThis = &DAT_0106c92c;
    return pThis;
}

struct FUN_0050f740_shell : public TESBoundAnimObject
{
    void FUN_0050f740();
};


// @fnv 0x0050f740
void FUN_0050f740_shell::FUN_0050f740()
{
    *(void**)this = &(*reinterpret_cast<void * *>(&::DAT_0106c92c));
    reinterpret_cast<::FUN_0050e9f0_shell *>((this))->FUN_0050e9f0();
}

namespace fnv_0050f7a0 {

// @fnv 0x0050f7a0
void* FUN_0050f7a0(void* pThis)
{
    new ((void *)(pThis)) ::TESBoundObject();
    *(int**)pThis = &(*reinterpret_cast<int *>(&::DAT_01029994));
    return pThis;
}
}  // namespace fnv_0050f7a0

extern int DAT_01029b1c;

// @fnv 0x0050f8c0
TESObject* FUN_0050f8c0(TESObject* apObject)
{
    new ((void *)(apObject)) ::fnv_00483370::FUN_00483370();
    *reinterpret_cast<int**>(apObject) = &DAT_01029b1c;
    reinterpret_cast<int*>(apObject)[7] = 0;
    reinterpret_cast<int*>(apObject)[8] = 0;
    reinterpret_cast<int*>(apObject)[6] = 0;
    return apObject;
}

struct TESObjectREFR_s
{
};
struct FUN_0050fd90_cls
{
    const char* FUN_0050fd90(TESObject* apObject);
};
// @fnv 0x0050fd90
const char* FUN_0050fd90_cls::FUN_0050fd90(TESObject* apObject)
{
    const char* result = 0;
    if (apObject)
        result = reinterpret_cast<::TESObjectREFR *>((((TESObjectREFR_s*)apObject)))->GetModelFilePath();
    if (!result)
        result = ((const char *)(::FUN_00480e60(this, (::Reference *)(apObject))));
    if (!result)
        result = ::FUN_004895b0((::TESForm *)(::TESObject *)((TESObject*)this));
    return result;
}

struct FUN_0050fd90_stub
{
};
struct FUN_0050fdf0_cls
{
    void FormatScaledName(PlayerCharacter* apPlayer, char* apBuffer);
};
// @fnv 0x0050fdf0
void FUN_0050fdf0_cls::FormatScaledName(PlayerCharacter* apPlayer, char* apBuffer)
{
    const char* name = reinterpret_cast<::FUN_0050fd90_cls *>((((FUN_0050fd90_stub*)this)))->FUN_0050fd90((::TESObject *)(apPlayer));
    ::FUN_00406d00(apBuffer, 260, "%s%i", name, ::FUN_00406d90((float)(reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((apPlayer))->FUN_00567400() * g_d100)));
}

struct FUN_005100d0_s
{
    int a;
    int b;
    int c;
    int d;
    FUN_005100d0_s* FUN_005100d0(int);
};

// Sets all four integer fields of the object to zero and returns the object pointer.
// @fnv 0x005100d0
FUN_005100d0_s* FUN_005100d0_s::FUN_005100d0(int)
{
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    return this;
}

struct FUN_005102b0_shell : public TESFormList
{
    TESObject* FUN_005102b0(TESObject*);
};

// Calls a helper with the object and returns the resulting TESObject pointer.
// @fnv 0x005102b0
TESObject* FUN_005102b0_shell::FUN_005102b0(TESObject* lpNew)
{
    lpNew = InsertObjectAfter(m_pSecondObject, lpNew);
    return lpNew;
}

struct FUN_0064df10_helper
{
    void deallocate(void* _Ptr, unsigned int __formal);
};

// @fnv 0x0064df10
void FUN_0064df10_helper::deallocate(void* _Ptr, unsigned int uiUnused)
{
    ::FUN_00401030(_Ptr);
}

namespace fnv_0044d580 {
struct FUN_0065e750_struct
{
    char FUN_0065e750();
};
extern char __cdecl FUN_0065e750();
extern void __cdecl FUN_0044e460(void*, void*, void*, void*, char);

// Calls FUN_0065e750 and passes its returned char as the fifth argument to FUN_0044e460 along with a, b, c and d.
// @fnv 0x0044d580
void __cdecl FUN_0044d580(void* apArg1, void* apArg2, void* apArg3, void* apArg4)
{
    char v = FUN_0065e750();
    FUN_0044e460(apArg1, apArg2, apArg3, apArg4, v);
}
}  // namespace fnv_0044d580


struct FUN_0050e990
{
    void* DeleteThis(unsigned int flags);
};

// @fnv 0x0050e990
void* FUN_0050e990::DeleteThis(unsigned int flags)
{
    reinterpret_cast<::FUN_0050e9f0_shell *>((this))->FUN_0050e9f0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


// @fnv 0x0050ea90
int FUN_0050ea90()
{
    return (*reinterpret_cast<int *>(&::g_pkString_c55));
}

struct FUN_0050f5a0_struct
{
    void FUN_0050f5a0();
};

// @fnv 0x0050f5a0
void FUN_0050f5a0_struct::FUN_0050f5a0()
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18) = 0;
}

extern NiFixedString* DAT_011c6218;

// @fnv 0x0050f5c0
NiFixedString* FUN_0050f5c0()
{
    return DAT_011c6218;
}

struct BaseProcess;

class FUN_008d0560_class
{
  public:
    NiNode* FUN_008d0560(BipedAnim* apBiped);
};

// @fnv 0x008d0560
NiNode* FUN_008d0560_class::FUN_008d0560(BipedAnim* apBiped)
{
    return 0;
}

struct FUN_00933790Class
{
    int GetZero(const char*);
};

// @fnv 0x00933790
int FUN_00933790Class::GetZero(const char* arg)
{
    int result = 0;
    return result;
}

namespace fnv_0050f710 {
struct FUN_0050f740_shell
{
    void* FUN_0050f710(unsigned int flags);
};


// Calls FUN_0050f740, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0050f710
void* FUN_0050f740_shell::FUN_0050f710(unsigned int flags)
{
    reinterpret_cast<::FUN_0050f740_shell *>(this)->FUN_0050f740();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_0050f710

void FUN_0050f930(void* obj);

struct FUN_0050f900_Class
{
    void* FUN_0050f900(unsigned int flags);
};

struct FUN_0050eb30_class
{
    float FUN_0050eb30();
};

// @fnv 0x0050eb30
float FUN_0050eb30_class::FUN_0050eb30()
{
    return (float)(short)*(short*)this;
}

struct FUN_0050eb70_Class
{
    float GetShortValueAsFloat();
};

// @fnv 0x0050eb70
float FUN_0050eb70_Class::GetShortValueAsFloat()
{
    return (float)*(short*)((char*)this + 4);
}

struct FUN_0059b820_class : TESBoundObject
{
    NiNode* FUN_0059b820(TESObjectREFR* reference, bool flag);
};

// @fnv 0x0059b820
NiNode* FUN_0059b820_class::FUN_0059b820(TESObjectREFR* reference, bool flag)
{
    NiAVObject* result = Get3DObject(reference, flag);
    return static_cast<NiNode*>(result);
}

struct FUN_006055d0_class
{
    void FUN_006055d0(::std::intptr_t a);
};
extern "C" void __cdecl FUN_00ec3205(::std::intptr_t);

struct FUN_00aca4b0_class
{
    void* vtbl;
    void FUN_00aca4b0();
};

// @fnv 0x00aca4b0
void FUN_00aca4b0_class::FUN_00aca4b0()
{
    vtbl = &(*reinterpret_cast<void * *>(&::DAT_010a2fa4));
    vtbl = &(*reinterpret_cast<void * *>(&::DAT_010a2f9c));
    FUN_00ec3205((::std::intptr_t)this);
}

struct S_4029f0
{
    void FUN_004029f0(bool);
};
// Calls FUN_00402a20 with index 1 and the inverse of b.
// @fnv 0x004029f0
void S_4029f0::FUN_004029f0(bool b)
{
    reinterpret_cast<::FUN_00402a20_class *>(this)->FUN_00402a20(1, !b);
}

struct FUN_00409aa0_shell
{
    void FUN_00409aa0(unsigned int, bool);
    void FUN_00409a70(bool);
};
// Calls FUN_00409aa0 with 1 and the inverse of b.
// @fnv 0x00409a70
void FUN_00409aa0_shell::FUN_00409a70(bool b)
{
    FUN_00409aa0(1, !b);
}

class NiFixedString;
class NiTexture;
struct Holder
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual void v64() = 0;
    virtual void v65() = 0;
    virtual void v66() = 0;
    virtual void v67() = 0;
    virtual void v68() = 0;
    virtual void v69() = 0;
    virtual void v70() = 0;
    virtual void v71() = 0;
    virtual void v72() = 0;
    virtual void v73() = 0;
    virtual void v74() = 0;
    virtual void v75() = 0;
    virtual void v76() = 0;
    virtual void v77() = 0;
    virtual void v78() = 0;
    virtual void v79() = 0;
    virtual void v80() = 0;
    virtual void v81() = 0;
    virtual void v82() = 0;
    virtual void v83() = 0;
    virtual void v84() = 0;
    virtual void v85() = 0;
    virtual void v86() = 0;
    virtual void v87() = 0;
    virtual void v88() = 0;
    virtual void v89() = 0;
    virtual void v90() = 0;
    virtual void v91() = 0;
    virtual void v92() = 0;
    virtual void v93() = 0;
    virtual void v94() = 0;
    virtual void vt(const char*) = 0;
    void FUN_0050f5d0();
public:
    bool FUN_00a5bc40(const ::NiFixedString &, ::NiTexture *);
};
// @fnv 0x00519040
NiNode* TESObjectDOOR::Create3DModel(TESObjectREFR* reference)
{
    NiNode* node = ((::NiNode *)(reinterpret_cast<::FUN_0050ee20_shell *>(this)->FUN_0050ee20((char *)(reference))));
    if (((::TESForm *)(reinterpret_cast<::FUN_00407820_shell *>((((TESChallenge*)this)))->FUN_00407820())) && !reinterpret_cast<::FUN_005bb4d0_shell *>((::FUN_00453a70()))->FUN_005bb4d0())
        reinterpret_cast<::fnv_00ad8100::FUN_00ad8100_shell *>((::FUN_00453a70()))->FUN_00ad8100((char *)(::FUN_00511840((char *)(((TESSound*)((::TESForm *)(reinterpret_cast<::FUN_00407820_shell *>((((TESChallenge*)this)))->FUN_00407820())))))), 0x121,
                                          ((::TESForm *)(reinterpret_cast<::FUN_00407820_shell *>((((TESChallenge*)this)))->FUN_00407820())));
    if (node)
    {
        NiTimeController* controller = ((::NiTimeController *)(reinterpret_cast<::MyHost *>((node))->FUN_00a5c570((const ::MyRTTI *)(const ::NiRTTI *)((const NiRTTI*)&g_011dfeac))));
        if (::FUN_00517fa0((void *)this) && (!reference || !reinterpret_cast<::FUN_00477ba0_shell *>((reference))->FUN_00477ba0()))
        {
            if (!controller)
            {
                TESObjectDoorController* doorController = new TESObjectDoorController;
                reinterpret_cast<::FUN_00929240_Class *>((doorController))->FUN_00929240(
                    ((::SETTING_VALUE *)&(::FUN_00403e20((float *)(((SettingT_GameSettingCollection_*)&originalRuntimeFloatSetting35)))))->f);
                reinterpret_cast<::FUN_0040e500_shell *>((((BGSAcousticSpace*)doorController)))->SetValue((::std::intptr_t)((TESSound*)&((void (&)(NiAVObject *))::FUN_00518f80)));
                doorController->SetTarget(node);
            }
            NiExtraData* extra = node->GetExtraData(FUN_00448a80());
            if (!extra)
            {
                extra = new NiExtraData;
                reinterpret_cast<::Holder *>((node))->FUN_00a5bc40(FUN_00448a80(), (::NiTexture *)(extra));
            }
            reinterpret_cast<::BSXFlags_shell *>((extra))->FUN_00519230(true, true);
        }
        else if (controller)
        {
            reinterpret_cast<::ControllerOwner *>((((NiObjectNET*)node)))->FUN_00a5c480(controller);
        }
    }
    return node;
}
// @fnv 0x0050f5d0
void Holder::FUN_0050f5d0()
{
    vt(::FUN_004895b0((::TESForm *)(::TESObject *)((TESObject*)this)));
}

struct FUN_0044a9d0_Class
{
    unsigned int FUN_0044a9d0();
};
extern void __cdecl FUN_00ec30b0();
struct FUN_0044a8d0_Class : FUN_0044a9d0_Class
{
    void _Tidy(bool, unsigned int);
    void _Eos(unsigned int);
    bool FUN_0044a8d0(unsigned int, bool);
};
template <int N> struct EndianSizeTag
{
};

struct FUN_0050ed30_class
{
    void FUN_0050ed30();
};
// @fnv 0x0050edd0
void TESBoundObject::LoadBoundData(TESFile* file)
{
    if (file && ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) == 0x444e424f)
    {
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&bounds), 12);
        if (file->IsEndianConversionRequired())
            reinterpret_cast<::FUN_0050ed30_class *>(&(bounds))->FUN_0050ed30();
    }
}

// @fnv 0x0050ed30
void FUN_0050ed30_class::FUN_0050ed30()
{
    ::FUN_00407a90((short *)(unsigned char *)((unsigned char*)this + 6));
    ::FUN_00407a90((short *)(unsigned char *)((unsigned char*)this + 8));
    ::FUN_00407a90((short *)(unsigned char *)((unsigned char*)this + 10));
    ::FUN_00407a90((short *)(unsigned char *)((unsigned char*)this));
    ::FUN_00407a90((short *)(unsigned char *)((unsigned char*)this + 2));
    ::FUN_00407a90((short *)(unsigned char *)((unsigned char*)this + 4));
}

struct FNStub
{
    const char* GetFullName();
};
int BSStringLength(const char* s);
struct FUN_005f6ed0_Class
{
    unsigned short FUN_005f6ed0();
};
// Computes a size starting at 30, adding the length of the full names of the FNStub objects at offsets 24 and 44 when present.
// @fnv 0x005f6ed0
unsigned short FUN_005f6ed0_Class::FUN_005f6ed0()
{
    unsigned short size = 0;
    size += 28;
    size += 1;
    if (((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)((char*)this + 24))))->FUN_00408da0())))
        size += BSStringLength(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)((char*)this + 24))))->FUN_00408da0())));
    size += 1;
    if (((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)((char*)this + 44))))->FUN_00408da0())))
        size += BSStringLength(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)((char*)this + 44))))->FUN_00408da0())));
    return size;
}

struct FUN_0050ece0_class
{
    char p[0x24];
    TESObjectBound bound;
    void FUN_0050ece0();
};
// Calls FUN_00401500 twice around a AppendChunk call on the bound member with 0xc, invoking bound.FUN_0050ed30 when it returns true.
// @fnv 0x0050ece0
void FUN_0050ece0_class::FUN_0050ece0()
{
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_0050ed30_class *>(&(bound))->FUN_0050ed30();
    ::AppendChunk((::std::uintptr_t)((char*)0x444e424f), (char*)&bound, 0xc);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_0050ed30_class *>(&(bound))->FUN_0050ed30();
}

namespace fnv_0050ea50 {
class NiPoint3
{
  public:
    float x;
    float y;
    float z;

    NiPoint3 operator+(NiPoint3 const& rhs) const;
};

class Target_0050ea50
{
  public:
    unsigned char pad[0x0c];
    NiPoint3 point1;
    NiPoint3 point2;

    void FUN_0050ea50(NiPoint3& result);
};

// Adds point1 and point2 and stores the sum in result.
// @fnv 0x0050ea50
void Target_0050ea50::FUN_0050ea50(NiPoint3& result)
{
    result = point1 + point2;
}
}  // namespace fnv_0050ea50

struct FUN_0050f7c0_Class
{
    void* DestroyIfFlagged(unsigned int flags);
};


struct FUN_005e7f90_class : public NiAVObject
{
  public:
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

    virtual const char* GetModelName();

    NiAVObject* CreateFadeNode(const char* pfilename);
};

// Creates a new BSFadeNode, sets its name from this object's model name, and returns it.
// @fnv 0x005e7f90
NiAVObject* FUN_005e7f90_class::CreateFadeNode(const char* pfilename)
{
    NiAVObject* pData3D = 0;
    pData3D = new BSFadeNode;
    ::AssignFixedString((char *)(pData3D), (int)&(const ::NiFixedString &)(NiFixedString(this->GetModelName())), {});
    return pData3D;
}

int _fopen(const char*, const char*);
int _fclose(int);

// Builds a path from arg's string (inline or heap) and checks it can be opened with _fopen, closing the handle; returns whether opening succeeded.
// @fnv 0x00ac6e10
bool CanOpenFile(void* apPathHolder)
{
    const char* name;
    if (*(unsigned int*)((char*)apPathHolder + 0x18) >= 0x10)
        name = *(const char**)((char*)apPathHolder + 4);
    else
        name = (const char*)apPathHolder + 4;
    int fp = _fopen(name, (const char*)&(*reinterpret_cast<int *>(&::DAT_01082cb8)));
    if (fp == 0)
        return false;
    else
        _fclose(fp);
    return true;
}

class Fb990Arg
{
  public:
};

class Fb990Embedded
{
  public:
    virtual void Slot00()
    {}
    virtual void Slot01()
    {}
    virtual void Slot02()
    {}
    virtual void Slot03()
    {}
    virtual void Slot04()
    {}
    virtual int Slot05()
    {
        return 0;
    }
};

struct Fb990Holder
{
    char unk00[0x3c];
    Fb990Embedded m_3c;
};

class Fb990Target
{
  public:
};


class FUN_004fb990_cls
{
  public:
    void ApplyIfReady(Fb990Arg* a);
};

template <class T> class BSStringT
{
  public:
    T* data;
    unsigned short length, capacity;
    BSStringT();
    ~BSStringT();
    operator const T*() const;
};
struct Extra503
{
};
struct Ref503
{
};
struct Setting503
{
};
struct Parent503;
struct Child503
{
};
struct Parent503
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
    virtual void remove(Child503*);
};
struct Root503
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
    virtual Child503* get(const NiFixedString&);
};
const NiFixedString& FUN_005039e0();
struct Shell503
{
    Root503* FUN_0050ee50(Ref503*, bool);
    Root503* GetRootAndRemoveChildren(Ref503*, bool);
};
// @fnv 0x00503820
Root503* Shell503::GetRootAndRemoveChildren(Ref503* ref, bool flag)
{
    Root503* count = FUN_0050ee50(ref, flag);
    int root = ref ? reinterpret_cast<::FUN_00418770_shell *>((((::Extra503 *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->FUN_00418770() : 1;
    if (count && root < *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::Setting503 *>(&::g_011c846c)))))))
    {
        Child503* child;
        if (root == 1)
        {
            child = count->get(FUN_005039e0());
            if (child)
                ((::Parent503 *)(reinterpret_cast<::FUN_009611e0_shell *>((child))->FUN_009611e0()))->remove(child);
            ::FUN_00c8ecf0((::HavokObject *)(count));
        }
        else
        {
            for (int i = root; i < *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::Setting503 *>(&::g_011c846c)))))); i++)
            {
                BSStringT<char> name;
                ::FUN_00406f60((::FUN_00406f90_this *)(::BSStringT<char> *)(&name), "Arrow%d", i);
                child = count->get(NiFixedString(name));
                if (child)
                    ((::Parent503 *)(reinterpret_cast<::FUN_009611e0_shell *>((child))->FUN_009611e0()))->remove(child);
            }
        }
    }
    return count;
}

namespace fnv_0050d600 {
struct FUN_0048cee0_class
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual int Slot05();
    int FUN_0048cee0();
};

struct FUN_0045a5e0_class
{
};


struct FUN_0050d600_shell
{
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
    FUN_0048cee0_class unk3c;

    void FUN_0050d600(int value);
};

// @fnv 0x0050d600
void FUN_0050d600_shell::FUN_0050d600(int value)
{
    if (unk3c.FUN_0048cee0())
    {
        reinterpret_cast<::FUN_0045a5e0_shell *>(((*reinterpret_cast<::fnv_0050d600::FUN_0045a5e0_class * *>(&::g_modelLoader))))->FUN_0045a5e0((char *)(unk3c.Slot05()));
    }
}
}  // namespace fnv_0050d600

struct FUN_0050e960_cls
{
    unsigned short m_00;
    unsigned short m_02;
    unsigned short m_04;
    FUN_0050e960_cls* FUN_0050e960(unsigned short a, unsigned short b, unsigned short c);
};

// Stores the three unsigned short arguments into m_00, m_02 and m_04 and returns this.
// @fnv 0x0050e960
FUN_0050e960_cls* FUN_0050e960_cls::FUN_0050e960(unsigned short ausFirst, unsigned short ausSecond,
                                                 unsigned short ausThird)
{
    m_00 = ausFirst;
    m_02 = ausSecond;
    m_04 = ausThird;
    return this;
}

struct Vec3Ret
{
    float x;
    float y;
    float z;
    Vec3Ret(float a, float b, float c);
};

class Bound24
{
  public:
};

class FUN_0050ead0_cls
{
  public:
    Vec3Ret FUN_0050ead0();
};

// FUN_0050eb50 : returns a float computed from a signed 16-bit field at offset +2.
struct FUN_0050eb50_cls
{
    char m_b00;
    char m_b01;
    short m_s02;

    float FUN_0050eb50();
};
// Returns a Vec3Ret built from the A, B and C values of the Bound24 at offset 0x24 of this object.
// @fnv 0x0050ead0
Vec3Ret FUN_0050ead0_cls::FUN_0050ead0()
{
    Vec3Ret r(reinterpret_cast<::FUN_0050eb30_class *>((((Bound24*)((char*)this + 0x24))))->FUN_0050eb30(), reinterpret_cast<::FUN_0050eb50_cls *>((((Bound24*)((char*)this + 0x24))))->FUN_0050eb50(),
              reinterpret_cast<::FUN_0050eb70_Class *>((((Bound24*)((char*)this + 0x24))))->GetShortValueAsFloat());
    return r;
}

// @fnv 0x0050eb50
float FUN_0050eb50_cls::FUN_0050eb50()
{
    return (float)(int)this->m_s02;
}


struct FUN_0050f7f0_shell
{
    void FUN_0050f7f0();
};
// Calls FUN_0050f7f0, frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0050f7c0
void* FUN_0050f7c0_Class::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_0050f7f0_shell *>(this)->FUN_0050f7f0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x0050f7f0
void FUN_0050f7f0_shell::FUN_0050f7f0()
{
    *reinterpret_cast<void**>(this) = reinterpret_cast<void*>(&DAT_01029994);
    reinterpret_cast<::FUN_0050e9f0_shell *>((this))->FUN_0050e9f0();
}

struct Owner;
struct Param;
struct Effect
{
};
struct Record
{
    virtual void slot_000();
    virtual void slot_004();
    virtual void slot_008();
    virtual void slot_00c();
    virtual void slot_010();
    virtual void slot_014();
    virtual void slot_018();
    virtual void slot_01c();
    virtual void slot_020();
    virtual void slot_024();
    virtual void slot_028();
    virtual void slot_02c();
    virtual void slot_030();
    virtual void slot_034();
    virtual void slot_038();
    virtual void slot_03c();
    virtual void slot_040();
    virtual void slot_044();
    virtual void slot_048();
    virtual void slot_04c();
    virtual void slot_050();
    virtual void slot_054();
    virtual void slot_058();
    virtual void slot_05c();
    virtual void slot_060();
    virtual void slot_064();
    virtual void slot_068();
    virtual void slot_06c();
    virtual void slot_070();
    virtual void slot_074();
    virtual void slot_078();
    virtual void slot_07c();
    virtual void slot_080();
    virtual void slot_084();
    virtual void slot_088();
    virtual void slot_08c();
    virtual void slot_090();
    virtual void slot_094();
    virtual void slot_098();
    virtual void slot_09c();
    virtual void slot_0a0();
    virtual void slot_0a4();
    virtual void slot_0a8();
    virtual void slot_0ac();
    virtual void slot_0b0();
    virtual void slot_0b4();
    virtual void slot_0b8();
    virtual void slot_0bc();
    virtual void slot_0c0();
    virtual void slot_0c4();
    virtual void slot_0c8();
    virtual void slot_0cc();
    virtual void slot_0d0();
    virtual void slot_0d4();
    virtual void slot_0d8();
    virtual void slot_0dc();
    virtual void slot_0e0();
    virtual void slot_0e4();
    virtual void slot_0e8();
    virtual void slot_0ec();
    virtual void slot_0f0();
    virtual void slot_0f4();
    virtual void slot_0f8();
    virtual void slot_0fc();
    virtual Effect* GetSecondary();
};
struct Param
{
};
struct FUN_00664f50_class
{
};
struct Owner
{
    virtual void slot_000();
    virtual void slot_004();
    virtual void slot_008();
    virtual void slot_00c();
    virtual void slot_010();
    virtual void slot_014();
    virtual void slot_018();
    virtual void slot_01c();
    virtual void slot_020();
    virtual void slot_024();
    virtual void slot_028();
    virtual void slot_02c();
    virtual void slot_030();
    virtual void slot_034();
    virtual void slot_038();
    virtual void slot_03c();
    virtual void slot_040();
    virtual void slot_044();
    virtual void slot_048();
    virtual void slot_04c();
    virtual void slot_050();
    virtual void slot_054();
    virtual void slot_058();
    virtual void slot_05c();
    virtual void slot_060();
    virtual void slot_064();
    virtual void slot_068();
    virtual void slot_06c();
    virtual void slot_070();
    virtual void slot_074();
    virtual void slot_078();
    virtual void slot_07c();
    virtual void slot_080();
    virtual void slot_084();
    virtual void slot_088();
    virtual void slot_08c();
    virtual void slot_090();
    virtual void slot_094();
    virtual void slot_098();
    virtual void slot_09c();
    virtual void slot_0a0();
    virtual void slot_0a4();
    virtual void slot_0a8();
    virtual void slot_0ac();
    virtual void slot_0b0();
    virtual void slot_0b4();
    virtual void slot_0b8();
    virtual void slot_0bc();
    virtual void slot_0c0();
    virtual void slot_0c4();
    virtual void slot_0c8();
    virtual void slot_0cc();
    virtual void slot_0d0();
    virtual void slot_0d4();
    virtual void slot_0d8();
    virtual void slot_0dc();
    virtual void slot_0e0();
    virtual void slot_0e4();
    virtual void slot_0e8();
    virtual void slot_0ec();
    virtual void slot_0f0();
    virtual void slot_0f4();
    virtual void slot_0f8();
    virtual void slot_0fc();
    virtual void slot_100();
    virtual void slot_104();
    virtual void slot_108();
    virtual void slot_10c();
    virtual void slot_110();
    virtual void slot_114();
    virtual void slot_118();
    virtual void slot_11c();
    virtual void slot_120();
    virtual void slot_124();
    virtual void slot_128();
    virtual void slot_12c();
    virtual void slot_130();
    virtual void slot_134();
    virtual void slot_138();
    virtual void slot_13c();
    virtual void slot_140();
    virtual void slot_144();
    virtual void slot_148();
    virtual void slot_14c();
    virtual void slot_150();
    virtual void slot_154();
    virtual void slot_158();
    virtual void slot_15c();
    virtual void slot_160();
    virtual void slot_164();
    virtual void slot_168();
    virtual void slot_16c();
    virtual void slot_170();
    virtual void slot_174();
    virtual void slot_178();
    virtual void slot_17c();
    virtual void Notify(Record*);
    int FUN_00401170();
    Record* CreateRecord(Param* target, int unused);
};
// If FUN_00401170 returns 0x25, creates a Record via CreateTreeInstance, notifies it, and passes its secondary effect's FUN_008d6f30 result to target.
// @fnv 0x0050f810
Record* Owner::CreateRecord(Param* target, int unused)
{
    Record* created = 0;
    if (FUN_00401170() != 0x25)
        return 0;
    if (::FUN_00664840(1))
    {
        created = ((::Record *)(reinterpret_cast<::TreeManager *>((static_cast<FUN_00664f50_class*>(::FUN_00664840(1))))->CreateTreeInstance((::TreeReference *)(target), (::TESObjectTREE *)(::Owner *)(this))));
    }
    Notify(created);
    if (created && created->GetSecondary() && target)
        reinterpret_cast<::RefrShell_569350 *>((target))->FUN_00569350((::TESForm *)(void *)(((void *)(reinterpret_cast<::LowProcess *>((created->GetSecondary()))->GetTarget()))));
    return created;
}

struct S_0050f930_Base
{
    virtual void vfn_00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ~S_0050f930_Base();
};
struct S_0050f930_Item
{
    int unk00;
};
struct FUN_0050f930 : S_0050f930_Base
{
    S_0050f930_Item* unk18;
    ~FUN_0050f930();
};
// @fnv 0x0050e9f0
void FUN_0050e9f0_shell::FUN_0050e9f0()
{
    *reinterpret_cast<const void* const**>(this) = vftable_TESBoundObject;
    reinterpret_cast<struct ::FUN_0050f930 *>((this))->FUN_0050f930::~FUN_0050f930();
}
// Calls FUN_0050f930 on this, deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x0050f900
void* FUN_0050f900_Class::FUN_0050f900(unsigned int flags)
{
    reinterpret_cast<struct ::FUN_0050f930 *>((this))->FUN_0050f930::~FUN_0050f930();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor that, if unk18 is set, calls RemoveNode on it passing this.
// @fnv 0x0050f930
FUN_0050f930::~FUN_0050f930()
{
    if (unk18)
        reinterpret_cast<::FUN_00510130_shell *>((unk18))->RemoveNode((::NiNode *)(void *)(this));
}

namespace fnv_0050fe50 {
struct ModelBaseType
{
    unsigned int FUN_00401170();
};
struct ModelReference
{
};
struct CachedModel
{
};
struct CachedModelPointer
{
    CachedModel* value;
    CachedModelPointer(CachedModel*);
    ~CachedModelPointer();
};
struct ModelCache
{
};
struct ModelOwner
{
    NiNode* GetModelNode(ModelReference*);
};
// @fnv 0x0050fe50
NiNode* ModelOwner::GetModelNode(ModelReference* reference)
{
    const char* pModelName = reinterpret_cast<::FUN_0050fd90_cls *>(this)->FUN_0050fd90((::TESObject *)(reference));
    NiNode* pNode = 0;
    if (reference && reinterpret_cast<::FUN_00444ed0_shell *>((reference))->FUN_00444ed0() && ((::fnv_0050fe50::ModelBaseType *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()))->FUN_00401170() != 30)
    {
        CachedModelPointer cachedModel(0);
        reinterpret_cast<::FUN_004472a0_shell *>(((*reinterpret_cast<::fnv_0050fe50::ModelCache * *>(&::g_modelLoader))))->FUN_004472a0((char *)(pModelName), &cachedModel);
        if (((::fnv_0050fe50::CachedModel *)(::FUN_00559450((int *)&(cachedModel)))))
            reinterpret_cast<::FUN_0092c870_shell *>((((::fnv_0050fe50::CachedModel *)(::FUN_00559450((int *)&(cachedModel))))))->FUN_0092c870();
        pNode = new BSFadeNode;
    }
    else
    {
        unsigned int flags = ((unsigned int)(::FUN_0045c6b0((::TESForm_0045c6b0 *)(::fnv_0050fe50::ModelOwner *)(this))));
        if (reference && reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((reference))->FUN_00567400() != 1.0)
        {
            char scaledName[260];
            reinterpret_cast<::FUN_0050fdf0_cls *>(this)->FormatScaledName((::PlayerCharacter *)(reference), scaledName);
            CachedModelPointer cachedScaled(0);
            reinterpret_cast<::FUN_004472a0_shell *>(((*reinterpret_cast<::fnv_0050fe50::ModelCache * *>(&::g_modelLoader))))->FUN_004472a0((char *)(scaledName), &cachedScaled);
            if (((::fnv_0050fe50::CachedModel *)(::FUN_00559450((int *)&(cachedScaled)))))
            {
                reinterpret_cast<::FUN_0092c870_shell *>((((::fnv_0050fe50::CachedModel *)(::FUN_00559450((int *)&(cachedScaled))))))->FUN_0092c870();
                pNode = ((::NiNode *)(::fnv_0043b230::FUN_0043b230((const char *)(((::fnv_0050fe50::CachedModel *)(::FUN_00559450((int *)&(cachedScaled))))))));
                ++(*reinterpret_cast<unsigned int *>(&::g_iKeptModelCount));
            }
        }
        if (!pNode)
            pNode = reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>(((*reinterpret_cast<::fnv_0050fe50::ModelCache * *>(&::g_modelLoader))))->FUN_00447080((char *)(pModelName), flags, true, false, false, false);
    }
    return pNode;
}
}  // namespace fnv_0050fe50

struct Ev510Node
{
};

struct Ev510Obj : TESObject
{
    bool FUN_00510080();
};

// @fnv 0x00510080
bool Ev510Obj::FUN_00510080()
{
    Ev510Node* p = (Ev510Node*)CreateNiNode(0);
    reinterpret_cast<::FUN_00a5a040_Class *>((p))->FUN_00a5a040();
    NiUpdateData data(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((p))->FUN_00a59c60((::std::intptr_t)&(data));
    return true;
}

class FUN_005f0d30_sub
{
  public:
};

class FUN_005f0d30_cls
{
  public:
    int Probe();
    void ApplyFlagIfProbeMatches(unsigned char flag);
};

// If Probe() returns 0x2a, calls Apply(0x10, flag, 1) on the sub-object at offset 0x30.
// @fnv 0x005f0d30
void FUN_005f0d30_cls::ApplyFlagIfProbeMatches(unsigned char flag)
{
    if (Probe() == 0x2a)
    {
        reinterpret_cast<::FlagSet *>((reinterpret_cast<FUN_005f0d30_sub*>(reinterpret_cast<char*>(this) + 0x30)))->FUN_0047dd50(0x10, flag, 1);
    }
}

struct FUN_0050ee50_obj
{
    void FUN_0050ee50(TESObjectREFR* a1, int a2);
};

struct FUN_007af430_ref
{
};

struct FUN_005f8bf0_form
{
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
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94(TESObjectREFR* reference);
};

struct FUN_005f8bf0_shell : public TESCreature
{
    void CalcLeveledCreature(TESObjectREFR* pRef);
};

// @fnv 0x005f8bf0
void FUN_005f8bf0_shell::CalcLeveledCreature(TESObjectREFR* pRef)
{
    if (reinterpret_cast<::FUN_0047cdb0_shell *>(&(actorData))->FUN_0047cdb0() && pRef && !reinterpret_cast<::Thing *>((pRef))->FUN_0056afc0())
    {
        reinterpret_cast<::fnv_0047ce10::OwnerShell *>(&(actorData))->FUN_0047ce10((::fnv_0047ce10::RefShell *)(pRef));
        reinterpret_cast<FUN_005f8bf0_form*>(((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reinterpret_cast<FUN_007af430_ref*>(pRef)))->FUN_007af430())))->slot94(pRef);
    }
    else
    {
        reinterpret_cast<FUN_0050ee50_obj*>(this)->FUN_0050ee50(pRef, 0);
    }
}

namespace fnv_005f8c70 {
class SubObj
{
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual int s5();
};
class NodeLike
{
  public:
    bool FUN_008256d0();
};
class MgrLike
{
  public:
};

class FUN_005f8c70_cls
{
  public:
    char unk00[0xdc];
    SubObj m_dc;
    char unkE0[0x118 - 0xe0];
    void FUN_0050fbf0(int);
    void FUN_005f8c70(int arg);
};

// @fnv 0x005f8c70
void FUN_005f8c70_cls::FUN_005f8c70(int arg)
{
    char acBuffer[0x104];
    char* pcInsert;
    NodeLike* p = (NodeLike*)((char*)this + 0x118);
    while (p != 0 && !p->FUN_008256d0())
    {
        ::TaskQueueInterface::CopyStringToBuffer(acBuffer, 0x104, (const char *)(m_dc.s5()));
        pcInsert = ::FUN_0040ab30(acBuffer, 0x5c);
        ::TaskQueueInterface::CopyStringToBuffer(pcInsert + 1, 0x104 - (pcInsert - acBuffer) - 1, (const char *)(*((::std::intptr_t *)((void *)(p)))));
        reinterpret_cast<::FUN_0045a5e0_shell *>(((*reinterpret_cast<::fnv_005f8c70::MgrLike * *>(&::g_modelLoader))))->FUN_0045a5e0(acBuffer);
        p = ((::fnv_005f8c70::NodeLike *)(reinterpret_cast<::Callees *>((p))->FUN_00726070()));
    }
    FUN_0050fbf0(arg);
}
}  // namespace fnv_005f8c70

struct FUN_0065de30
{
    void* value;
    explicit FUN_0065de30(void* source);
    FUN_0065de30(const FUN_0065de30& other);
};
struct FUN_007ab050_Class
{
    void AssignSubstring(unsigned int a, unsigned int b, unsigned int c);
    FUN_007ab050_Class* FUN_007ab050(unsigned int a, unsigned int b, unsigned int c, void* source);
};
// @fnv 0x007ab050
FUN_007ab050_Class* FUN_007ab050_Class::FUN_007ab050(unsigned int uiFirst, unsigned int uiSecond, unsigned int uiThird,
                                                     void* source)
{
    reinterpret_cast<::Unk65 *>(this)->FUN_0044a7b0((*(int *)&(const ::FUN_0065de30 &)(FUN_0065de30(source))));
    reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(0, 0);
    AssignSubstring(uiFirst, uiSecond, uiThird);
    return this;
}

// Thiscall with one stack arg (ret 4): copies a dword and a 12-byte value from
// the argument into this, then initialises a sub-object at this+0x10 with two
// calls and returns this.


struct FUN_00ac04c0_tri
{
    unsigned int a, b, c;
};

struct FUN_00ac04c0_src
{
    unsigned int m_00;
    FUN_00ac04c0_tri m_04;
};

class FUN_00ac04c0_sub
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;

    void Attach(const void* p, unsigned int b, unsigned int c);
};

class FUN_00ac04c0_cls
{
  public:
    unsigned int m_00;
    FUN_00ac04c0_tri m_04;
    FUN_00ac04c0_sub m_10;

    FUN_00ac04c0_cls* CopyFromSource(const FUN_00ac04c0_src* src);
};

// Copies m_00 and m_04 from src, resets the m_10 sub-object and attaches it to src+0x10, then returns this.
// @fnv 0x00ac04c0
FUN_00ac04c0_cls* FUN_00ac04c0_cls::CopyFromSource(const FUN_00ac04c0_src* pSource)
{
    m_00 = pSource->m_00;
    m_04 = pSource->m_04;
    unsigned int pz;
    unsigned int pz2;
    FUN_00ac04c0_sub* node = &m_10;
    FUN_00ac04c0_tri tri0;
    FUN_00ac04c0_tri tri1;
    FUN_00ac04c0_tri tri2;
    FUN_00ac04c0_tri tri3;
    FUN_00ac04c0_tri tri4;
    FUN_00ac04c0_tri tri5;
    FUN_00ac04c0_tri tri6;
    FUN_00ac04c0_tri tri7;
    reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>((node))->FUN_0044a730(0, 0);
    node->Attach((const char*)pSource + 0x10, 0, ::g_010173f0);
    return this;
}

void __cdecl FUN_00ec9907(void* p);
unsigned int __cdecl FUN_00ec6130(const void* p);

struct FUN_0044a7f0_sub
{
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
    void FUN_0044a7f0(const void* a, unsigned int b);
};

struct Scratch44
{
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
};

struct FUN_00ac5430_cls
{
    unsigned int unk00;
    FUN_0044a7f0_sub m_04;
    void* m_3c;
    void FUN_00ac5430();
};

// @fnv 0x00ac5430
void FUN_00ac5430_cls::FUN_00ac5430()
{
    if (m_3c != 0)
    {
        FUN_00ec9907(m_3c);
    }
    Scratch44 tmp;
    unsigned int h = FUN_00ec6130(&(*reinterpret_cast<int *>((void *)&::DAT_01011584)));
    m_04.FUN_0044a7f0(&(*reinterpret_cast<int *>((void *)&::DAT_01011584)), h);
    m_3c = 0;
}


class ThisBase_aca270
{
  public:
    virtual ~ThisBase_aca270();
    unsigned int m_04;
    unsigned int m_08;
    ThisBase_aca270(ThisBase_aca270* aArg);
};

class ThisMember_aca270
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    void Method(ThisMember_aca270* aOther, unsigned int aZero, unsigned int aData);
};

class ThisLocal_aca270
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3c;
    unsigned int m_40;
    unsigned int m_44;
    unsigned int m_48;
    unsigned int m_4c;
    unsigned int m_50;
    unsigned int m_54;
    unsigned int m_58;
    unsigned int m_5c;
    unsigned int m_60;
};

class FUN_00aca270 : public ThisBase_aca270
{
  public:
    ThisMember_aca270 m_0c;

    FUN_00aca270(ThisBase_aca270* aArg);
    virtual ~FUN_00aca270();
};

// Initializes m_0c with Init(0, 0), then calls Method on the argument's m_0c with 0 and g_aca270Data.
// @fnv 0x00aca270
FUN_00aca270::FUN_00aca270(ThisBase_aca270* aArg) : ThisBase_aca270(aArg)
{
    ThisLocal_aca270 aBuf;
    ThisMember_aca270* pMember = &m_0c;
    reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>((pMember))->FUN_0044a730(0, 0);
    pMember->Method(&((FUN_00aca270*)aArg)->m_0c, 0, ::g_010173f0);
}

namespace fnv_0050ee50 {
class Model;
struct RefOps
{
};
struct ObjectOps
{
    unsigned int FUN_00401170();
};
struct NodeOps
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual NiNode* asNode();
};
struct ChildOps
{
};
class Model
{
  public:
    unsigned int a, b, c, d;
    Model(const char*, NiAVObject*);
    ~Model();
    void* FUN_004431f0(unsigned int);
};
struct ModelPointerOps
{
};
struct ControllerOps
{
};
struct NamedObjectOps
{
};
struct LoaderOps
{
};
struct CacheOps
{
};
class NiMemObject
{
  public:
};
struct FUN_00a5ecb0 : NiMemObject
{
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
    FUN_00a5ecb0(unsigned int);
};
struct AttachNodeOps
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
    virtual void attach(NodeOps*, bool);
};
struct CloneObject17 : TESBoundObject
{
    NiAVObject* FUN_0050ee50(TESObjectREFR*, bool);
};
// @fnv 0x0050ee50
NiAVObject* CloneObject17::FUN_0050ee50(TESObjectREFR* reference, bool forceClone)
{
    NiAVObject* p = 0;
    if (this == (TESBoundObject*)DAT_011ca220 || this == (TESBoundObject*)DAT_011ca250)
        reference = 0;
    NiNode* h = CreateNiNode(reference);
    if (reference && reinterpret_cast<::FUN_00444ed0_shell *>((((RefOps*)reference)))->FUN_00444ed0() &&
        ((ObjectOps*)((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((RefOps*)reference)))->FUN_007af430())))->FUN_00401170() != 30)
        return h;
    if (h)
    {
        if (reinterpret_cast<::FUN_0050d4a0_shell *>((((ObjectOps*)this)))->FUN_0050d4a0() && reference)
            reinterpret_cast<::TESForm *>((((RefOps*)reference)))->SetCollisionDisabled(true);
        if (!forceClone && ((int)(::std::uintptr_t)(reinterpret_cast<::Callees *>((((NodeOps*)h)))->FUN_00726070())) == 1)
        {
            bool canReuse = false;
            switch (((ObjectOps*)this)->FUN_00401170())
            {
            case 21:
            case 43:
                if (::FUN_004b5bf0((::NiAVObject *)(h)))
                    forceClone = true;
            case 40:
            case 41:
            case 42:
            case 51:
                break;
            case 35:
            case 81:
                break;
            case 28: {
                canReuse = true;
                NiNode* node = ((NodeOps*)h)->asNode();
                if (node && ((void *)(reinterpret_cast<::S_FUN_0045bc00 *>((((ChildOps*)node)))->FUN_0045bc00(0))) && ((::NiAVObject *)(::fnv_0043b230::FUN_0043b230((const char *)(((::fnv_0050ee50::Model *)(reinterpret_cast<::NiNode *>((((ChildOps*)node)))->GetAt(0))))))))
                {
                    NiAVObject* p = ((::NiAVObject *)(::fnv_0043b230::FUN_0043b230((const char *)(((::fnv_0050ee50::Model *)(reinterpret_cast<::NiNode *>((((ChildOps*)node)))->GetAt(0)))))));
                    NamedObjectOps* h = (NamedObjectOps*)((void *)(::FUN_00653270((const ::NiRTTI *)(void *)(&(*reinterpret_cast<char *>(&::g_011f36ac))), (::NiObject *)(p))));
                    if (h && ((void *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((h))->FUN_0047a520((::fnv_0047a520::NFSHelper *)(::NiFixedString *)(FUN_0050f5c0())))))
                        canReuse = false;
                }
                break;
            }
            default:
                canReuse = !::FUN_0062c3c0((::Refr62C3C0 *)(reference), (unsigned int)(h));
                break;
            }
            if (canReuse)
            {
                ControllerOps* controller = (ControllerOps*)((void *)(reinterpret_cast<::NiAVObject *>((((NodeOps*)h)))->GetExtraData((*(const ::NiFixedString *)((void*)&FUN_00448a80())))));
                if (controller)
                {
                    ControllerOps* testController = controller;
                    if (reinterpret_cast<::BSXFlags *>((testController))->GetAddon())
                        canReuse = false;
                }
            }
            if (canReuse && ::FUN_0048b310(this, (void *)(reference)))
                canReuse = false;
            if (canReuse && ::FUN_00569410((::NiAVObject *)(h)))
                canReuse = false;
            if (canReuse)
            {
                if (!reference || reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((((RefOps*)reference)))->FUN_00567400() == reinterpret_cast<::FUN_009cdae0_shell *>((((NodeOps*)h)))->GetFloatAt64())
                    p = h;
            }
        }
        if (!p)
        {
            float scale = 1.0f;
            if (reference)
                scale = reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((((RefOps*)reference)))->FUN_00567400();
            if (scale == reinterpret_cast<::FUN_009cdae0_shell *>((((NodeOps*)h)))->GetFloatAt64())
                scale = 1.0f;
            if (scale == 0.0)
            {
                ::FUN_005b5e40();
                scale = 1.0f;
            }
            CloningProcess process(scale);
            if (forceClone)
            {
                NodeOps* pCachedNode = ((::fnv_0050ee50::NodeOps *)(reinterpret_cast<::FUN_00457ba0_class *>(((*reinterpret_cast<::fnv_0050ee50::CacheOps * *>(&::g_TES))))->FUN_00457ba0((::NiAVObject *)(h), (::CloningProcess *)&(process))));
                if (pCachedNode && pCachedNode->asNode())
                    p = pCachedNode->asNode();
                else
                {
                    NodeOps* node = (NodeOps*)new FUN_00a5ecb0(0);
                    ((AttachNodeOps*)node)->attach(pCachedNode, true);
                    p = (NiAVObject*)node;
                }
            }
            else
                p = ((::NiAVObject *)(reinterpret_cast<::A5D2C0Object *>((((NodeOps*)h)))->FUN_00a5d2c0((::A5D2C0CloningProcess &)(process))));
            if (scale != 1.0 && reinterpret_cast<::FUN_009cdae0_shell *>((((NodeOps*)h)))->GetFloatAt64() == 1.0)
            {
                reinterpret_cast<::FUN_00440490_shell *>((((NodeOps*)p)))->FUN_00440490(scale);
                char filename[260];
                reinterpret_cast<::FUN_0050fdf0_cls *>((((ObjectOps*)this)))->FormatScaledName((::PlayerCharacter *)(reference), filename);
                NiPointer<Model> model(0);
                reinterpret_cast<::FUN_004472a0_shell *>(((*reinterpret_cast<::fnv_0050ee50::LoaderOps * *>(&::g_modelLoader))))->FUN_004472a0((char *)(filename), (void *)&(model));
                if (!((::fnv_0050ee50::Model *)(::FUN_00559450((int *)(((ModelPointerOps*)&model))))))
                {
                    reinterpret_cast<::NP_0044aed0 *>((((ModelPointerOps*)&model)))->FUN_0044aed0((::WaitableObject *)(::fnv_0050ee50::Model *)(new Model(filename, p)));
                    reinterpret_cast<::FUN_0092c870_shell *>((((::fnv_0050ee50::Model *)(::FUN_00559450((int *)(((ModelPointerOps*)&model)))))))->FUN_0092c870();
                    if (!((bool)(reinterpret_cast<::S_447010 *>(((*reinterpret_cast<::fnv_0050ee50::LoaderOps * *>(&::g_modelLoader))))->CallFoo((::std::intptr_t)(filename), (::std::intptr_t)(((::fnv_0050ee50::Model *)(::FUN_00559450((int *)(((ModelPointerOps*)&model))))))))))
                    {
                        Model* pFailedModel = ((::fnv_0050ee50::Model *)(::FUN_00559450((int *)(((ModelPointerOps*)&model)))));
                        reinterpret_cast<::NP_0044aed0 *>((((ModelPointerOps*)&model)))->FUN_0044aed0((::WaitableObject *)(::fnv_0050ee50::Model *)(0));
                        delete pFailedModel;
                    }
                    else
                        ++(*reinterpret_cast<unsigned int *>(&::g_iReleasedModelCount));
                    CloningProcess unscaled(1.0f);
                    p = ((::NiAVObject *)(reinterpret_cast<::A5D2C0Object *>((((NodeOps*)p)))->FUN_00a5d2c0((::A5D2C0CloningProcess &)(unscaled))));
                }
                else
                {
                    if (((::NiAVObject *)(::fnv_0043b230::FUN_0043b230((const char *)(((::fnv_0050ee50::Model *)(::FUN_00559450((int *)(((ModelPointerOps*)&model))))))))) &&
                        reinterpret_cast<::FUN_009cdae0_shell *>((((NodeOps*)((::NiAVObject *)(::fnv_0043b230::FUN_0043b230((const char *)(((::fnv_0050ee50::Model *)(::FUN_00559450((int *)(((ModelPointerOps*)&model))))))))))))->GetFloatAt64() ==
                            reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((((RefOps*)reference)))->FUN_00567400())
                    {
                        NiAVObject* replacement = _CreateNiNode(reference, forceClone);
                        return replacement;
                    }
                    else
                        ::FUN_005b5e40();
                }
            }
        }
        if (p)
        {
            reinterpret_cast<::FUN_00440490_shell *>((((NodeOps*)p)))->FUN_00440490(1.0f);
            reinterpret_cast<::TaskQueueInterface *>((((NodeOps*)p)))->QueueActorDisarm(0);
            reinterpret_cast<::FUN_0043fa80_s *>((((NodeOps*)p)))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&(*reinterpret_cast<char *>(&::DAT_011a9448)))));
            reinterpret_cast<::FUN_00440460_S *>((((NodeOps*)p)))->FUN_00440460((const ::V3 *)(void *)(&(*reinterpret_cast<char *>((void *)&::NiPoint3::ZERO))));
            if (reinterpret_cast<::FUN_009611e0_shell *>((((NodeOps*)p)))->FUN_009611e0())
                reinterpret_cast<::FUN_0050f5a0_struct *>((((NodeOps*)p)))->FUN_0050f5a0();
        }
    }
    return p;
}
}  // namespace fnv_0050ee50

struct LoadedModel0050fbf0
{
};

struct ModelPtr0050fbf0
{
    LoadedModel0050fbf0* m_pObject;
    ModelPtr0050fbf0(LoadedModel0050fbf0* apObject);
    ~ModelPtr0050fbf0();
    operator LoadedModel0050fbf0*() const;
};

struct ModelLoader0050fbf0
{
};

class ModelForm0050fbf0
{
  public:
    int GetFormType();
    void FUN_0050fbf0(PlayerCharacter* apPlayer);
};
// @fnv 0x006055d0
void FUN_006055d0_class::FUN_006055d0(::std::intptr_t a)
{
    reinterpret_cast<::ModelForm0050fbf0 *>(this)->FUN_0050fbf0((::PlayerCharacter *)(a));
}
// If the argument is ready, reads Slot05 from DAT_011ca284->m_3c and passes it to DAT_011c3b3c->Apply; otherwise calls Fallback.
// @fnv 0x004fb990
void FUN_004fb990_cls::ApplyIfReady(Fb990Arg* a)
{
    Fb990Arg* p = a;
    if (!((bool)(reinterpret_cast<::FUN_004fb970_class *>((p))->GetByteAtOffsetD9())))
    {
        reinterpret_cast<::ModelForm0050fbf0 *>((this))->FUN_0050fbf0((::PlayerCharacter *)(a));
    }
    else
    {
        ::std::intptr_t r = (*reinterpret_cast<::Fb990Holder * *>(&::DAT_011ca284))->m_3c.Slot05();
        reinterpret_cast<::FUN_0045a5e0_shell *>(((*reinterpret_cast<::Fb990Target * *>(&::g_modelLoader))))->FUN_0045a5e0((char *)(r));
    }
}


// @fnv 0x0050fbf0
void ModelForm0050fbf0::FUN_0050fbf0(PlayerCharacter* apPlayer)
{
    if (this == (*reinterpret_cast<::ModelForm0050fbf0 * *>(&::DAT_011ca220)) || this == (*reinterpret_cast<::ModelForm0050fbf0 * *>(&::DAT_011ca250)))
        apPlayer = 0;

    const char* pModelPath = reinterpret_cast<::FUN_0050fd90_cls *>(this)->FUN_0050fd90((::TESObject *)(apPlayer));
    if (pModelPath && *pModelPath)
    {
        if (apPlayer && reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((apPlayer))->FUN_00567400() != 1.0)
        {
            char acScaledPath5[260];
            reinterpret_cast<::FUN_0050fdf0_cls *>(this)->FormatScaledName(apPlayer, acScaledPath5);
            reinterpret_cast<::FUN_0045a5e0_shell *>(((*reinterpret_cast<::ModelLoader0050fbf0 * *>(&::g_modelLoader))))->FUN_0045a5e0((char *)(acScaledPath5));
            bool bRelease = true;
            ModelPtr0050fbf0 modelPtr(0);
            if (reinterpret_cast<::FUN_004472a0_shell *>(((*reinterpret_cast<::ModelLoader0050fbf0 * *>(&::g_modelLoader))))->FUN_004472a0((char *)(acScaledPath5), (void *)&(modelPtr)) &&
                ((::std::intptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((LoadedModel0050fbf0*)modelPtr)))->GetName())) > 0)
                bRelease = false;
            if (bRelease)
            {
                reinterpret_cast<::FUN_0045a5e0_shell *>(((*reinterpret_cast<::ModelLoader0050fbf0 * *>(&::g_modelLoader))))->FUN_0045a5e0((char *)(pModelPath));
                g_iReleasedModelCount--;
            }
            else
                g_iKeptModelCount--;
        }
        else
            reinterpret_cast<::FUN_0045a5e0_shell *>(((*reinterpret_cast<::ModelLoader0050fbf0 * *>(&::g_modelLoader))))->FUN_0045a5e0((char *)(pModelPath));
    }

    if (GetFormType() == 0x2a)
        reinterpret_cast<::FUN_00603bb0_Owner *>(this)->FUN_00603bb0();
}

void __cdecl StrXran();
void __cdecl StrXlen();

struct StdString
{
    int unk00;
    char _Buf[16];
    unsigned int _Mysize;
    ::std::uintptr_t _Myres;


    unsigned int size() const;
    void _Eos(unsigned int auiNewsize);
    StdString& Replace(unsigned int _Off, ::std::uintptr_t _N0, StdString& _Right, unsigned int _Roff, unsigned int _Count);
};

// Replaces _N0 characters at _Off with _Count characters from _Right at _Roff, growing the buffer and shifting the tail as needed.
// @fnv 0x007ab250
StdString& StdString::Replace(unsigned int _Off, ::std::uintptr_t _N0, StdString& _Right, unsigned int _Roff,
                              unsigned int _Count)
{
    if (_Mysize < _Off || reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((void *)&(_Right))->FUN_00825c00() < _Roff)
        StrXran();
    if (_Mysize - _Off < _N0)
        _N0 = _Mysize - _Off;
    unsigned int _Num = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((void *)&(_Right))->FUN_00825c00() - _Roff;
    if (_Num < _Count)
        _Count = _Num;
    if (::g_010173f0 - _Count <= _Mysize - _N0)
        StrXlen();

    ::std::uintptr_t _Nm = _Mysize - _N0 - _Off;
    unsigned int _Newsize = _Mysize + _Count - _N0;
    if (_Mysize < _Newsize)
        reinterpret_cast<::FUN_0044a8d0_Class *>(this)->FUN_0044a8d0(_Newsize, false);

    if (this != &_Right)
    {
        ::fnv_0044d580::FUN_0044d580(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Off + _Count, (void *)(_Myres - _Off - _Count), (void *)(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Off + _N0), (void *)(_Nm));
        ::FUN_0044ccd0(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Off, _Myres - _Off, reinterpret_cast<::FUN_0044a970_Cls *>(&(_Right))->FUN_0044a970() + _Roff, _Count);
    }
    else if (_Count <= _N0)
    {
        ::fnv_0044d580::FUN_0044d580(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Off, (void *)(_Myres - _Off), (void *)(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Roff), (void *)(_Count));
        ::fnv_0044d580::FUN_0044d580(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Off + _Count, (void *)(_Myres - _Off - _Count), (void *)(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Off + _N0), (void *)(_Nm));
    }
    else if (_Roff <= _Off)
    {
        ::fnv_0044d580::FUN_0044d580(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Off + _Count, (void *)(_Myres - _Off - _Count), (void *)(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Off + _N0), (void *)(_Nm));
        ::fnv_0044d580::FUN_0044d580(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Off, (void *)(_Myres - _Off), (void *)(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Roff), (void *)(_Count));
    }
    else if (_Off + _N0 <= _Roff)
    {
        ::fnv_0044d580::FUN_0044d580(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Off + _Count, (void *)(_Myres - _Off - _Count), (void *)(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Off + _N0), (void *)(_Nm));
        ::fnv_0044d580::FUN_0044d580(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Off, (void *)(_Myres - _Off), (void *)(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + (_Roff + _Count - _N0)), (void *)(_Count));
    }
    else
    {
        ::fnv_0044d580::FUN_0044d580(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Off, (void *)(_Myres - _Off), (void *)(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Roff), (void *)(_N0));
        ::fnv_0044d580::FUN_0044d580(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Off + _Count, (void *)(_Myres - _Off - _Count), (void *)(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Off + _N0), (void *)(_Nm));
        ::fnv_0044d580::FUN_0044d580(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Off + _N0, (void *)(_Myres - _Off - _N0), (void *)(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Roff + _Count), (void *)(_Count - _N0));
    }

    _Eos(_Newsize);
    return *this;
}

struct FUN_0050eb90_Point3
{
    float x, y, z;
};
struct FUN_0050eb90_Component
{
};
struct FUN_0050eb90_Class
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned int unk18, unk1c, unk20, unk24;
    unsigned short unk28;
    FUN_0050eb90_Component component;
    FUN_0050eb90_Point3 FUN_0050eb90();
};
// Builds a Point3 from the component's three float accessors and returns it.
// @fnv 0x0050eb90
FUN_0050eb90_Point3 FUN_0050eb90_Class::FUN_0050eb90()
{
    FUN_0050eb90_Point3 result;
    reinterpret_cast<::FUN_00416870_t *>(&(result))->FUN_00416870(reinterpret_cast<::FUN_0050eb30_class *>(&(component))->FUN_0050eb30(), reinterpret_cast<::FUN_0050eb50_cls *>(&(component))->FUN_0050eb50(), reinterpret_cast<::FUN_0050eb70_Class *>(&(component))->GetShortValueAsFloat());
    return result;
}

struct InsertValue
{
    unsigned int x, y, z, w;
};
struct InsertIterator
{
    void* container;
    InsertValue* pointer;
};
struct InsertAllocator
{
    unsigned int state;
    InsertValue* FUN_0064df30(unsigned int);
};
void __cdecl FUN_0064e4b0(InsertValue*, InsertValue*, const InsertValue&);
void __cdecl FUN_0064e4e0(InsertValue*, InsertValue*, InsertValue*);
struct InsertVector
{
    unsigned int control;
    unsigned int proxy;
    InsertAllocator allocator;
    InsertValue* first;
    InsertValue* last;
    InsertValue* end;
    unsigned int FUN_0064de90();
    InsertValue* FUN_0064e480(InsertValue*, InsertValue*, InsertValue*);
    void Insert(InsertIterator _Where, unsigned int _Count, const InsertValue& _Val);
};
// Inserts _Count copies of _Val at _Where, growing or reallocating the vector's storage when capacity is insufficient.
// @fnv 0x0064df50
void InsertVector::Insert(InsertIterator _Where, unsigned int _Count, const InsertValue& _Val)
{
    unsigned int _Capacity = ((unsigned int)(reinterpret_cast<::FUN_0064e300_Class *>(this)->FUN_0064e300()));
    if (_Count == 0)
        ;
    else if (FUN_0064de90() - ((unsigned int)(reinterpret_cast<::FUN_0064dc30_class *>(this)->FUN_0064dc30())) < _Count)
        ::fnv_0065f640::ThrowVectorTooLong();
    else if (_Capacity < ((unsigned int)(reinterpret_cast<::FUN_0064dc30_class *>(this)->FUN_0064dc30())) + _Count)
    {
        _Capacity = FUN_0064de90() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < ((unsigned int)(reinterpret_cast<::FUN_0064dc30_class *>(this)->FUN_0064dc30())) + _Count)
            _Capacity = ((unsigned int)(reinterpret_cast<::FUN_0064dc30_class *>(this)->FUN_0064dc30())) + _Count;
        InsertValue* _Newvec = allocator.FUN_0064df30(_Capacity);
        InsertValue* _Ptr = _Newvec;
        try
        {
            _Ptr = FUN_0064e480(first, _Where.pointer, _Newvec);
            _Ptr = ((::InsertValue *)(reinterpret_cast<::FUN_0064e340_class *>(this)->FUN_0064e340((::std::intptr_t)(_Ptr), _Count, (::std::intptr_t)&(_Val))));
            reinterpret_cast<::FUN_0064e480_Class *>(this)->FUN_0064e480(_Where.pointer, last, _Ptr);
        }
        catch (...)
        {
            reinterpret_cast<::FUN_0064dee0_Class *>(this)->ForwardToHelper((::std::intptr_t)(_Newvec), (::std::intptr_t)(_Ptr));
            reinterpret_cast<::FUN_0064df10_helper *>(&(allocator))->deallocate(_Newvec, _Capacity);
            throw;
        }
        _Count += ((unsigned int)(reinterpret_cast<::FUN_0064dc30_class *>(this)->FUN_0064dc30()));
        if (first != 0)
        {
            reinterpret_cast<::FUN_0064dee0_Class *>(this)->ForwardToHelper((::std::intptr_t)(first), (::std::intptr_t)(last));
            reinterpret_cast<::FUN_0064df10_helper *>(&(allocator))->deallocate(first, end - first);
        }
        end = _Newvec + _Capacity;
        last = _Newvec + _Count;
        first = _Newvec;
    }
    else if ((unsigned int)(last - _Where.pointer) < _Count)
    {
        InsertValue _Tmp = _Val;
        reinterpret_cast<::FUN_0064e480_Class *>(this)->FUN_0064e480(_Where.pointer, last, _Where.pointer + _Count);
        try
        {
            reinterpret_cast<::FUN_0064e340_class *>(this)->FUN_0064e340((::std::intptr_t)(last), _Count - (last - _Where.pointer), (::std::intptr_t)&(_Tmp));
        }
        catch (...)
        {
            reinterpret_cast<::FUN_0064dee0_Class *>(this)->ForwardToHelper((::std::intptr_t)(_Where.pointer + _Count), (::std::intptr_t)(last + _Count));
            throw;
        }
        last += _Count;
        FUN_0064e4b0(_Where.pointer, last - _Count, _Tmp);
    }
    else
    {
        InsertValue _Tmp = _Val;
        InsertValue* _Oldend = last;
        last = FUN_0064e480(_Oldend - _Count, _Oldend, last);
        FUN_0064e4e0(_Where.pointer, _Oldend - _Count, _Oldend);
        FUN_0064e4b0(_Where.pointer, _Where.pointer + _Count, _Tmp);
    }
}

struct GrowString
{
    unsigned int unk00;
    char* data;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int size;
    unsigned int capacity;
    void ResizeString(unsigned int);
    void ResizeBuffer(unsigned int requested, unsigned int oldSize);
};
// @fnv 0x0044a8d0
bool FUN_0044a8d0_Class::FUN_0044a8d0(unsigned int uiNewSize, bool bTrim)
{
    if (FUN_0044a9d0() < uiNewSize)
        FUN_00ec30b0();
    if (*(unsigned int*)((char*)this + 0x18) < uiNewSize)
        reinterpret_cast<::GrowString *>(this)->ResizeBuffer(uiNewSize, *(unsigned int*)((char*)this + 0x14));
    else if (bTrim && uiNewSize < 16)
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true,
              uiNewSize < *(unsigned int*)((char*)this + 0x14) ? uiNewSize : *(unsigned int*)((char*)this + 0x14));
    else if (uiNewSize == 0)
        _Eos(0);
    return 0 < uiNewSize;
}
// Grows the string buffer to at least requested bytes, copies oldSize bytes from the old data, and updates data and capacity.
// @fnv 0x0044aa10
void GrowString::ResizeBuffer(unsigned int requested, unsigned int oldSize)
{
    ::std::uintptr_t uiNewCapacity = requested | 15;
    if (reinterpret_cast<::FUN_0044a9d0_Class *>(this)->FUN_0044a9d0() < uiNewCapacity)
        uiNewCapacity = requested;
    else if (uiNewCapacity / 3 < capacity / 2 && capacity <= reinterpret_cast<::FUN_0044a9d0_Class *>(this)->FUN_0044a9d0() - capacity / 2)
        uiNewCapacity = capacity + capacity / 2;
    char* pNewData = 0;
    try
    {
        pNewData = ((char *)(reinterpret_cast<::FUN_0065f7a0_Class *>(this)->FUN_0065f7a0((void *)(uiNewCapacity + 1))));
    }
    catch (...)
    {
        uiNewCapacity = requested;
        try
        {
            pNewData = ((char *)(reinterpret_cast<::FUN_0065f7a0_Class *>(this)->FUN_0065f7a0((void *)(uiNewCapacity + 1))));
        }
        catch (...)
        {
            reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, 0);
            throw;
        }
    }
    if (oldSize > 0)
        FUN_0044ccd0(pNewData, uiNewCapacity + 1, reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970(), oldSize);
    reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, 0);
    data = pNewData;
    capacity = uiNewCapacity;
    ResizeString(oldSize);
}

namespace fnv_004fd440 {
struct NiModelData
{
};
struct BaseModelForm
{
};
struct RefTarget
{
};
struct ModelLoaderMgr
{
};
struct ProjectileShell
{
    void LoadModel(RefTarget* arg);
};
// For a non-null reference, passes its model name to the loader or calls FUN_0050fbf0 on selected paths.
// @fnv 0x004fd440
void ProjectileShell::LoadModel(RefTarget* apRef)
{
    if (apRef)
    {
        switch (reinterpret_cast<::FUN_004fd4f0_Class *>(this)->FUN_004fd4f0())
        {
        case 0x40000:
        case 0x100000:
            reinterpret_cast<::ModelForm0050fbf0 *>(this)->FUN_0050fbf0((::PlayerCharacter *)(apRef));
            break;
        default:
            RefTarget* ref = apRef;
            if (ref && ((::fnv_004fd440::BaseModelForm *)(reinterpret_cast<::FUN_009d9f00_Class *>((ref))->FUN_009d9f00())) && ((::fnv_004fd440::NiModelData *)(reinterpret_cast<::Twin_0044ddc0 *>((((::fnv_004fd440::BaseModelForm *)(reinterpret_cast<::FUN_009d9f00_Class *>((ref))->FUN_009d9f00()))))->GetName())))
            {
                const char* name = reinterpret_cast<::FUN_0050fd90_cls *>((((::fnv_004fd440::NiModelData *)(reinterpret_cast<::Twin_0044ddc0 *>((((::fnv_004fd440::BaseModelForm *)(reinterpret_cast<::FUN_009d9f00_Class *>((ref))->FUN_009d9f00()))))->GetName()))))->FUN_0050fd90((::TESObject *)(0));
                reinterpret_cast<::FUN_0045a5e0_shell *>(((*reinterpret_cast<::fnv_004fd440::ModelLoaderMgr * *>(&::g_modelLoader))))->FUN_0045a5e0((char *)(name));
            }
            else
            {
                reinterpret_cast<::ModelForm0050fbf0 *>(this)->FUN_0050fbf0((::PlayerCharacter *)(apRef));
            }
            break;
        }
    }
}
}  // namespace fnv_004fd440

namespace fnv_007ab0a0 {
namespace std {
template <class _Elem> struct char_traits
{
};
template <class _Ty> class allocator
{
};
template <class _Elem, class _Traits, class _Ax> class basic_string;
template <> class basic_string<char, char_traits<char>, allocator<char> >
{
  public:
    void* m_pContainerProxy;

    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    ::std::uintptr_t _Myres;
    bool _Inside(const char*);
    void _Eos(unsigned int);
    void _Tidy(bool, unsigned int);
    basic_string* FUN_007ab0a0(unsigned int, unsigned int, const char*, unsigned int);
};
}
extern void __cdecl FUN_00ec30e8();
extern void __cdecl FUN_00ec30b0();

// Replaces a substring at pos with src, handling internal pointers, bounds checks, and buffer growth.
// @fnv 0x007ab0a0
std::basic_string<char, std::char_traits<char>, std::allocator<char> >* std::basic_string<
    char, std::char_traits<char>, std::allocator<char> >::FUN_007ab0a0(unsigned int pos, unsigned int count,
                                                                       const char* src, unsigned int srcCount)
{
    if (_Inside(src))
    {
        return ((::fnv_007ab0a0::std::basic_string<char, ::fnv_007ab0a0::std::char_traits<char>, ::fnv_007ab0a0::std::allocator<char>> *)&(reinterpret_cast<::StdString *>(this)->Replace(pos, count, (*(::StdString *)(this)), (unsigned int)(src - reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970()), srcCount)));
    }
    if (_Mysize < pos)
        FUN_00ec30e8();
    if (_Mysize - pos < count)
        count = _Mysize - pos;
    if (::g_010173f0 - srcCount <= _Mysize - count)
        FUN_00ec30b0();
    ::std::uintptr_t tail = _Mysize - count - pos;
    if (srcCount < count)
        ::fnv_0044d580::FUN_0044d580(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + pos + srcCount, (void *)(_Myres - pos - srcCount), (void *)(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + pos + count), (void *)(tail));
    if (srcCount > 0 || count > 0)
    {
        unsigned int newSize = (_Mysize + srcCount) - count;
        if (reinterpret_cast<::FUN_0044a8d0_Class *>(this)->FUN_0044a8d0(newSize, false))
        {
            if (count < srcCount)
                ::fnv_0044d580::FUN_0044d580(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + pos + srcCount, (void *)(_Myres - pos - srcCount), (void *)(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + pos + count), (void *)(tail));
            ::FUN_0044ccd0(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + pos, _Myres - pos, src, srcCount);
            _Eos(newSize);
        }
    }
    return this;
}
}  // namespace fnv_007ab0a0

class MemoryManager
{
  public:
};

struct El
{
    std::string s;
    int unk;
    std::vector<unsigned int> v;
};

class ElAllocator
{
  public:
    typedef El* pointer;
    typedef std::size_t size_type;
    pointer allocate(size_type n)
    {
        return static_cast<pointer>(::operator new(n * sizeof(El)));
    }
    void deallocate(pointer p, size_type)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(p);
    }
    void construct(pointer p, const El& v)
    {
        ::new (static_cast<void*>(p)) El(v);
    }
    void destroy(pointer p)
    {
        p->~El();
    }
    size_type max_size() const throw()
    {
        size_type c = (size_type)(-1) / sizeof(El);
        return 0 < c ? c : 1;
    }
};

// The original's vector<El> storage: the allocator, then the first, last and end pointers.
class InsertVector_ob1_nogf
{
  public:
    typedef std::size_t size_type;
    typedef El* pointer;
    typedef El value_type;
    ElAllocator _Alval;
    pointer _Myfirst, _Mylast, _Myend;
    size_type capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    size_type size() const
    {
        return _Mylast - _Myfirst;
    }
    size_type max_size() const
    {
        return _Alval.max_size();
    }
    void _Destroy(pointer first, pointer last)
    {
        for (; first != last; ++first)
            _Alval.destroy(first);
    }
    pointer _Umove(pointer first, pointer last, pointer dest)
    {
        for (; first != last; ++dest, ++first)
            _Alval.construct(dest, *first);
        return dest;
    }
    pointer _Ufill(pointer dest, size_type count, const El& value)
    {
        for (size_type i = 0; i < count; ++i)
            _Alval.construct(dest + i, value);
        return dest + count;
    }
    void FUN_00abfa90(pointer _Where, size_type _Count, const El& _Val);
};

// @fnv 0x00abfa90
void InsertVector_ob1_nogf::FUN_00abfa90(pointer _Where, size_type _Count, const El& _Val)
{
    size_type _Capacity = capacity();
    if (_Count == 0)
        ;
    else if (max_size() - size() < _Count)
        ::fnv_0065f640::ThrowVectorTooLong();
    else if (_Capacity < size() + _Count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        pointer _Newvec = _Alval.allocate(_Capacity);
        pointer _Ptr = _Newvec;
        try
        {
            _Ptr = _Umove(_Myfirst, _Where, _Newvec);
            _Ptr = _Ufill(_Ptr, _Count, _Val);
            _Umove(_Where, _Mylast, _Ptr);
        }
        catch (...)
        {
            _Destroy(_Newvec, _Ptr);
            _Alval.deallocate(_Newvec, _Capacity);
            throw;
        }
        _Count += size();
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myend = _Newvec + _Capacity;
        _Mylast = _Newvec + _Count;
        _Myfirst = _Newvec;
    }
    else if ((size_type)(_Mylast - _Where) < _Count)
    {
        value_type _Tmp = _Val;
        _Umove(_Where, _Mylast, _Where + _Count);
        try
        {
            _Ufill(_Mylast, _Count - (_Mylast - _Where), _Tmp);
        }
        catch (...)
        {
            _Destroy(_Where + _Count, _Mylast + _Count);
            throw;
        }
        _Mylast += _Count;
        std::fill(_Where, _Mylast - _Count, _Tmp);
    }
    else
    {
        value_type _Tmp = _Val;
        pointer _Oldend = _Mylast;
        _Mylast = _Umove(_Oldend - _Count, _Oldend, _Mylast);
        std::copy_backward(_Where, _Oldend - _Count, _Oldend);
        std::fill(_Where, _Where + _Count, _Tmp);
    }
}

namespace skac53 {
void FUN_00ec7c56();
int FUN_00ec7c66(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
int FUN_00ec7c6b(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
struct BxSecureTag
{
};
struct BxStrTraits
{
    static char* _Copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c66(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static char* _Move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c6b(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static unsigned int length(const char* _First)
    {
        return strlen(_First);
    }
    static int compare(const char* _First1, const char* _First2, unsigned int _Count)
    {
        return memcmp(_First1, _First2, _Count);
    }
    static void assign(char& _Left, const char& _Right)
    {
        _Left = _Right;
    }
};
inline BxSecureTag BxCharTraitsCat()
{
    BxSecureTag _Secure_char_traits;
    return _Secure_char_traits;
}
struct BxTraitsHelper
{
    template <class T>
    static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Copy_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return copy_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
    template <class T>
    static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Move_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return move_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
};
struct BxBadAlloc
{
    const char* pWhat;
    int iDoFree;
    BxBadAlloc(const char* what);
    ~BxBadAlloc();
};
template <class T> inline T* BxAllocate(unsigned int count, T*)
{
    if (count <= 0)
    {
        count = 0;
    }
    else if (((unsigned int)(-1) / count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)::FUN_00401000(count * sizeof(T));
}
template <class T> struct BxAllocT
{
    typedef T* pointer;
    BxAllocT() throw()
    {}
    BxAllocT(const BxAllocT<T>&) throw()
    {}
    pointer allocate(unsigned int _Count)
    {
        return BxAllocate(_Count, (pointer)0);
    }
    pointer allocate(unsigned int _Count, const void*)
    {
        return allocate(_Count);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        ::FUN_00401030(_Ptr);
    }
    unsigned int max_size() const
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
typedef BxAllocT<char> BxCharAlloc;
struct BxStringVal
{
    BxCharAlloc _Alval;
    BxStringVal(BxCharAlloc _Al = BxCharAlloc()) : _Alval(_Al)
    {}
    BxStringVal(const BxStringVal& _Right) : _Alval(_Right._Alval)
    {}
};
struct BxString : public BxStringVal
{
    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    BxString(const char* _Ptr) : BxStringVal()
    {
        _Tidy();
        assign(_Ptr);
    }
    BxString() : BxStringVal()
    {
        _Tidy();
    }
    BxString& operator=(const BxString& _Right)
    {
        return assign(_Right);
    }
    BxString& assign(const BxString& _Right)
    {
        return assign(_Right, 0, (*reinterpret_cast<int *>(&::g_010173f0)));
    }
    BxString(const BxString& _Right) : BxStringVal(_Right)
    {
        _Tidy();
        assign(_Right, 0, (*reinterpret_cast<int *>(&::g_010173f0)));
    }
    ~BxString()
    {
        _Tidy(true);
    }
    static void _Xlen();
    static void _Xran();
    unsigned int size() const
    {
        return _Mysize;
    }
    char& operator[](unsigned int _Off)
    {
        if (!(_Off <= _Mysize))
        {
            FUN_00ec7c56();
        }
        do
        {
        } while (0);
        return _Myptr()[_Off];
    }
    unsigned int max_size() const
    {
        unsigned int _Num = _Alval.max_size();
        return _Num <= 1 ? 1 : _Num - 1;
    }
    char* _Myptr()
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    const char* _Myptr() const
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    void _Eos(unsigned int _Newsize)
    {
        BxStrTraits::assign(_Myptr()[_Mysize = _Newsize], char());
    }
    BxString& erase(unsigned int _Off = 0, unsigned int _Count = (unsigned int)-1)
    {
        if (_Mysize < _Off)
        {
            _Xran();
        }
        if (_Mysize - _Off < _Count)
        {
            _Count = _Mysize - _Off;
        }
        if (0 < _Count)
        {
            BxTraitsHelper::move_s<BxStrTraits>(_Myptr() + _Off, _Myres - _Off, _Myptr() + _Off + _Count,
                                                _Mysize - _Off - _Count);
            unsigned int _Newsize = _Mysize - _Count;
            _Eos(_Newsize);
        }
        return *this;
    }
    bool _Inside(const char* _Ptr)
    {
        if (_Ptr == 0 || _Ptr < _Myptr() || _Myptr() + _Mysize <= _Ptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void _Tidy(bool _Built = false, unsigned int _Newsize = 0)
    {
        if (!_Built)
        {
        }
        else if (16 <= _Myres)
        {
            char* _Ptr = _Bx._Ptr;
            if (0 < _Newsize)
            {
                BxTraitsHelper::copy_s<BxStrTraits>(_Bx._Buf, 16, _Ptr, _Newsize);
            }
            _Alval.deallocate(_Ptr, _Myres + 1);
        }
        _Myres = 16 - 1;
        _Eos(_Newsize);
    }
    void _Copy(unsigned int _Newsize, unsigned int _Oldlen)
    {
        unsigned int _Newres = _Newsize | 15;
        if (max_size() < _Newres)
        {
            _Newres = _Newsize;
        }
        else if (_Newres / 3 < _Myres / 2 && _Myres <= max_size() - _Myres / 2)
        {
            _Newres = _Myres + _Myres / 2;
        }
        char* _Ptr = 0;
        try
        {
            _Ptr = _Alval.allocate(_Newres + 1);
        }
        catch (...)
        {
            _Newres = _Newsize;
            try
            {
                _Ptr = _Alval.allocate(_Newres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < _Oldlen)
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Ptr, _Newres + 1, _Myptr(), _Oldlen);
        }
        _Tidy(true);
        _Bx._Ptr = _Ptr;
        _Myres = _Newres;
        _Eos(_Oldlen);
    }
    bool _Grow(unsigned int _Newsize, bool _Trim = false)
    {
        if (max_size() < _Newsize)
        {
            _Xlen();
        }
        if (_Myres < _Newsize)
        {
            _Copy(_Newsize, _Mysize);
        }
        else if (_Trim && _Newsize < 16)
        {
            reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, _Newsize < _Mysize ? _Newsize : _Mysize);
        }
        else if (_Newsize == 0)
        {
            _Eos(0);
        }
        return 0 < _Newsize;
    }
    BxString& assign(const BxString& _Right, unsigned int _Roff, unsigned int _Count)
    {
        if (_Right.size() < _Roff)
        {
            _Xran();
        }
        unsigned int _Num = _Right.size() - _Roff;
        if (_Count < _Num)
        {
            _Num = _Count;
        }
        if (this == &_Right)
        {
            erase((unsigned int)(_Roff + _Num)), erase(0, _Roff);
        }
        else if (_Grow(_Num))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Right._Myptr() + _Roff, _Num);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& assign(const char* _Ptr, unsigned int _Count)
    {
        if (_Inside(_Ptr))
        {
            return assign(*this, _Ptr - _Myptr(), _Count);
        }
        if (_Grow(_Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Ptr, _Count);
            _Eos(_Count);
        }
        return *this;
    }
    const char& operator[](unsigned int _Off) const
    {
        if (!(_Off <= _Mysize))
        {
            FUN_00ec7c56();
        }
        return _Myptr()[_Off];
    }
    BxString& append(const BxString& _Right, unsigned int _Roff, unsigned int _Count)
    {
        if (_Right.size() < _Roff)
        {
            _Xran();
        }
        unsigned int _Num = _Right.size() - _Roff;
        if (_Num < _Count)
        {
            _Count = _Num;
        }
        if ((*reinterpret_cast<int *>(&::g_010173f0)) - _Mysize <= _Count || _Mysize + _Count < _Mysize)
        {
            _Xlen();
        }
        if (0 < _Count && _Grow(_Num = _Mysize + _Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr() + _Mysize, _Myres - _Mysize, _Right._Myptr() + _Roff, _Count);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& append(const char* _Ptr, unsigned int _Count)
    {
        if (_Inside(_Ptr))
        {
            return append(*this, _Ptr - _Myptr(), _Count);
        }
        if ((*reinterpret_cast<int *>(&::g_010173f0)) - _Mysize <= _Count)
        {
            _Xlen();
        }
        unsigned int _Num;
        if (0 < _Count && _Grow(_Num = _Mysize + _Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr() + _Mysize, _Myres - _Mysize, _Ptr, _Count);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& append(const char* _Ptr)
    {
        return append(_Ptr, BxStrTraits::length(_Ptr));
    }
    BxString& operator+=(const char* _Ptr)
    {
        return append(_Ptr);
    }
    const char* c_str() const
    {
        return _Myptr();
    }
    int compare(unsigned int _Off, unsigned int _N0, const char* _Ptr, unsigned int _Count) const
    {
        if (_Mysize < _Off)
            _Xran();
        if (_Mysize - _Off < _N0)
            _N0 = _Mysize - _Off;
        unsigned int _Ans = BxStrTraits::compare(_Myptr() + _Off, _Ptr, _N0 < _Count ? _N0 : _Count);
        return _Ans != 0 ? (int)_Ans : _N0 < _Count ? -1 : _N0 == _Count ? 0 : +1;
    }
    int compare(const char* _Ptr) const
    {
        return compare(0, _Mysize, _Ptr, BxStrTraits::length(_Ptr));
    }
    BxString& assign(const char* _Ptr)
    {
        return assign(_Ptr, BxStrTraits::length(_Ptr));
    }
};
inline bool operator==(const BxString& _Left, const char* _Right)
{
    return _Left.compare(_Right) == 0;
}
inline bool operator!=(const BxString& _Left, const char* _Right)
{
    return !(_Left == _Right);
}
struct GvFileHandle;
void FUN_00ac6430(int code, BxString message);
}

struct SeekBinaryFile
{
    skac53::BxString kPath;
    skac53::BxString kMagic;
    skac53::GvFileHandle* pFile;
    virtual void v00();
    __declspec(noinline) bool FUN_00ac53a0(long offset);
};

// @fnv 0x00ac53a0
bool SeekBinaryFile::FUN_00ac53a0(long offset)
{
    if (pFile == 0)
    {
        return false;
    }
    if (std::fseek((std::FILE *)(pFile), offset, 0) != 0)
    {
        skac53::FUN_00ac6430(7, kPath);
        reinterpret_cast<::FUN_00ac5430_cls *>(this)->FUN_00ac5430();
        return false;
    }
    return true;
}

extern "C" unsigned __cdecl FUN_00ec6130(const char*);

inline void DeadX()
{
    const char* d_dmji;
    const char* d1;
    const char* d2;
    const char* d_t;
    const char* d4;
    const char* d5;
    const char* d_wovsp;
    const char* d7;
    const char* d8;
    const char* d_yji;
}

inline void Dead4()
{
    const char* e_mwhkwl;
    const char* e1;
    const char* e2;
    const char* e_hei;
}

struct StrX
{
    void* al;
    union
    {
        char buf[16];
        char* ptr;
    } bx;
    unsigned size;
    unsigned res;
    StrX Substr(unsigned off, unsigned n) const;
    StrX& AssignSubstring(const StrX& rR_igxcnj, unsigned off, unsigned n);
    ~StrX()
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, 0);
    }
    StrX& assign(const StrX& rR_igxcnj)
    {
        return AssignSubstring(rR_igxcnj, 0, ::g_010173f0);
    }
    StrX& operator=(const StrX& rR_igxcnj)
    {
        return assign(rR_igxcnj);
    }
    unsigned rfind(const char* p, unsigned off = ::g_010173f0) const
    {
        return reinterpret_cast<::StringQ *>((void *)this)->FUN_00a0c300(p, off, LenX(p));
    }
    static unsigned LenX(const char* p)
    {
        return FUN_00ec6130(p);
    }
};

StrX SubX(const StrX& s, unsigned off, unsigned n);

inline const unsigned& GetMaxX(const unsigned& a, const unsigned& b)
{
    return a < b ? b : a;
}

// @fnv 0x00ac6a30
bool __cdecl FUN_00ac6a30(StrX s, StrX* pA, StrX* pB, StrX* pC)
{
    unsigned uiLen_da = s.size;
    unsigned i1 = s.rfind("\\");
    unsigned i_wuftt = s.rfind("/");
    unsigned i3 = s.rfind(":");
    if (i1 == ::g_010173f0)
        i1 = 0;
    else
        i1++;
    if (i_wuftt == ::g_010173f0)
        i_wuftt = 0;
    else
        i_wuftt++;
    if (i3 == ::g_010173f0)
        i3 = 0;
    else
        i3++;
    unsigned uiStart_pgdky = GetMaxX(i1, i_wuftt);
    if (uiStart_pgdky > 0 && i3 > uiStart_pgdky)
        return false;
    uiStart_pgdky = GetMaxX(uiStart_pgdky, i3);
    if (uiStart_pgdky == uiLen_da)
        return false;
    unsigned uiDot_hda = s.rfind(".");
    unsigned uiExt_tt;
    if (uiDot_hda == ::g_010173f0)
    {
        uiDot_hda = uiLen_da;
        uiExt_tt = uiLen_da;
    }
    else
        uiExt_tt = uiDot_hda + 1;
    if (uiDot_hda == uiStart_pgdky)
        return false;
    if (uiDot_hda < uiStart_pgdky)
        uiDot_hda = uiLen_da;
    if (uiStart_pgdky < uiDot_hda)
    {
    }
    else
        ::ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\algs.cpp", 0xaa);
    Dead4();
    *pA = s.Substr(0, uiStart_pgdky);
    DeadX();
    *pB = s.Substr(uiStart_pgdky, uiDot_hda - uiStart_pgdky);
    DeadX();
    *pC = s.Substr(uiExt_tt, uiLen_da - uiExt_tt);
    DeadX();
    return true;
}

namespace fnv_00ad3aa0 {
struct G16
{
    int a, b, c, d;
};
extern "C" G16 FUN_00ec38a9();
inline G16 GetG()
{
    return FUN_00ec38a9();
}
struct StrX
{
    char buf[0x1c];
    ~StrX()
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, 0);
    }
};
struct SrcX
{
    StrX FUN_00ad3e60();
};
struct FUN_00ad3ca0
{
    char buf[0x74];
    FUN_00ad3ca0(const StrX& s);
    ~FUN_00ad3ca0();
};
struct B0
{
    virtual void V0();
    int m4;
    B0()
    {
        m4 = 0;
    }
};
struct B1 : B0
{
    virtual void V0();
    B1()
    {}
};
inline void DeadA()
{
    int a0;
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
    int a6;
    int a7;
    int a8;
    int a9;
    int a10;
    int a11;
}
inline void DeadB()
{
    int b0;
    int b1;
    int b2;
    int b3;
    int b4;
    int b5;
    int b6;
    int b7;
    int b8;
    int b9;
    int b10;
    int b11;
    int b12;
    int b13;
    int b14;
}
struct ObjX : B1
{
    G16 m8;
    virtual void V0();
    ObjX(const FUN_00ad3ca0& a)
    {
        G16 g = FUN_00ec38a9();
        m8 = g;
    }
};
// @fnv 0x00ad3aa0
int FUN_00ad3aa0(B0** out, SrcX* src)
{
    if (out && !*out)
    {
        DeadA();
        *out = new ObjX(FUN_00ad3ca0(src->FUN_00ad3e60()));
    }
    DeadB();
    return 2;
}
}

// namespace fnv_00ad3aa0


struct S00aaec10_Sub
{
    void AssignSubstring(const void*, int, unsigned int);
};

struct S00aaec10_Guard
{
    __forceinline S00aaec10_Guard()
    {}
    __forceinline ~S00aaec10_Guard()
    {}
};

struct S00aaec10_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S00aaec10_Sub sub;
    S00aaec10_Obj* FUN_00aaec10(const void* src);
};

// @fnv 0x00aaec10
S00aaec10_Obj* S00aaec10_Obj::FUN_00aaec10(const void* src)
{
    unsigned int u00;
    unsigned int u01;
    unsigned int u02;
    unsigned int u03;
    unsigned int u04;
    unsigned int u05;
    unsigned int u06;
    unsigned int u07;
    unsigned int u08;
    unsigned int u09;
    unsigned int u10;
    unsigned int u11;
    unsigned int u12;
    unsigned int u13;
    unsigned int u14;
    unsigned int u15;
    unsigned int u16;
    unsigned int u17;
    unsigned int u18;
    unsigned int u19;
    unsigned int u20;
    unsigned int u21;
    unsigned int u22;
    unsigned int u23;
    unsigned int u24;
    unsigned int u25;
    unsigned int u26;
    unsigned int u27;
    new ((void *)this) ::FUN_00658f30((*(const ::FUN_00658f30 *)(src)));
    {
        S00aaec10_Guard g;
        S00aaec10_Sub* p5 = &sub;
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>((p5))->FUN_0044a730(false, 0);
        p5->AssignSubstring((const char*)src + 0x20, 0, ::g_010173f0);
    }
    return this;
}

static __forceinline void D23()
{
    int a[23];
}

static __forceinline void D18()
{
    int a[18];
}

struct FileString
{
    int allocator_ob1;
    union
    {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length, capacity;
    FileString(const char*);
    FileString(const FileString& other)
    {
        int aiD[23];
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(false, 0);
        AssignSubstring(other, 0, ::g_010173f0);
    }
    void Tail()
    {}
    ~FileString();
    FileString& AssignSubstring(const FileString&, unsigned int, unsigned int);
};

struct FileReader
{
    int vtable;
    FileString fileName, signature;
    int fileSize;
    FileReader(FileString);
    ~FileReader();
    bool FUN_00ac4910(FileString);
};

// @fnv 0x00ab7e30
bool FUN_00ab7e30(const FileString& fileName, void* output)
{
    FileReader reader(FileString("FRTRI003"));
    if (!reader.FUN_00ac4910(fileName))
        return false;
    D18();
    return ::FUN_00ab7f40((::TriWriterRework::Writer *)(::FileReader *)(&reader), (::TriWriterRework::Tri *)(output));
}

void __cdecl FUN_00ec7c56();

extern "C" int __cdecl memcpy_s(void*, unsigned int, const void*, unsigned int);

namespace std {
template <class E> struct char_traits_ob1
{
    static void assign(E& dest, const E& value)
    {
        dest = value;
    }
    static E* _Copy_s(E* dest, unsigned int size, const E* source, unsigned int count)
    {
        memcpy_s(dest, size, source, count);
        return dest;
    }
};
template <class E> class allocator_ob1
{
  public:
    void deallocate(E* ptr, unsigned int)
    {
        ::FUN_00401030(ptr);
    }
};
struct SecureTraitsTag
{
};
template <class T> inline SecureTraitsTag charTraitsCat()
{
    SecureTraitsTag tag;
    return tag;
}
namespace _Traits_helper {
template <class T>
inline char* copy_s(char* dest, unsigned int size, const char* source, unsigned int count, SecureTraitsTag)
{
    return T::_Copy_s(dest, size, source, count);
}
template <class T> inline char* copy_s(char* dest, unsigned int size, const char* source, unsigned int count)
{
    return copy_s<T>(dest, size, source, count, charTraitsCat<T>());
}
}
template <class E, class T, class A> class basic_string_ob1
{
  public:
    A alloc;
    union Buffer
    {
        E chars[16];
        E* pointer;
    } buffer;
    unsigned int length, capacity;
    E* _Myptr()
    {
        return 16 <= capacity ? buffer.pointer : buffer.chars;
    }
    void _Eos(unsigned int size)
    {
        T::assign(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970()[length = size], E());
    }
    void _Tidy(bool built, unsigned int size)
    {
        if (!built)
            ;
        else if (16 <= capacity)
        {
            E* ptr = buffer.pointer;
            if (0 < size)
                _Traits_helper::copy_s<T>(buffer.chars, 16, ptr, size);
            alloc.deallocate(ptr, capacity + 1);
        }
        capacity = 15;
        _Eos(size);
    }
    basic_string_ob1& assign(const basic_string_ob1&, unsigned int, unsigned int);
    basic_string_ob1& operator=(const basic_string_ob1& other)
    {
        return assign(other, 0, ~0u);
    }
    ~basic_string_ob1()
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, 0);
    }
};
}

typedef std::basic_string_ob1<char, std::char_traits_ob1<char>, std::allocator_ob1<char> > GameString;

struct Vector3
{
    float x, y, z;
};

struct GameRecord
{
    int id;
    Vector3 position;
    GameString name;
};

struct GameAllocator
{
    void destroy(GameRecord* ptr)
    {
        ptr->~GameRecord();
    }
};

struct GameVector;

struct GameAux
{
    const GameVector* container;
    const GameVector* GetShapeContainer() const
    {
        return container;
    }
};

struct GameConstIterator
{
    GameAux* owner;
    GameRecord* current;
    GameConstIterator(GameRecord*, GameVector*);
    GameConstIterator& func_0x00ac0c40(int);
    const GameVector* GetShapeContainer() const
    {
        return owner ? owner->GetShapeContainer() : 0;
    }
    bool hasContainer() const
    {
        return owner != 0;
    }
    bool sameContainer(const GameConstIterator& other) const
    {
        return owner == other.owner;
    }
    bool operator==(const GameConstIterator& other) const
    {
        if (!(hasContainer() && sameContainer(other)))
            FUN_00ec7c56();
        return current == other.current;
    }
    bool operator!=(const GameConstIterator& other) const
    {
        return !(*this == other);
    }
};

struct GameIterator : GameConstIterator
{
    GameIterator(GameRecord* p, GameVector* v) : GameConstIterator(p, v)
    {}
    GameIterator& operator+=(int count)
    {
        reinterpret_cast<::FUN_00ac0c40_It *>(this)->FUN_00ac0c40(count);
        return *this;
    }
    GameIterator operator+(int count) const
    {
        GameIterator tmp = *this;
        return tmp += count;
    }
};

struct GameVector
{
    GameAux* iteratorOwner;
    int unk04;
    GameAllocator allocator_ob1;
    GameRecord *first, *last, *limit;
    unsigned int size() const
    {
        return last - first;
    }
    GameIterator makeIter(GameConstIterator it)
    {
        return GameIterator(it.current, this);
    }
    void destroy(GameRecord*, GameRecord*);
    GameIterator begin()
    {
        return GameIterator(first, this);
    }
    GameIterator end()
    {
        return GameIterator(last, this);
    }
    GameIterator func_0x00abb5f0(GameConstIterator, GameConstIterator);
    void FUN_00abb3c0(unsigned int count, GameRecord value);
};

inline GameConstIterator& GameConstIterator::func_0x00ac0c40(int count)
{
    if (!hasContainer())
        FUN_00ec7c56();
    if (!(current + count <= GetShapeContainer()->last && current + count >= GetShapeContainer()->first))
        FUN_00ec7c56();
    current += count;
    return *this;
}

inline GameConstIterator::GameConstIterator(GameRecord* ptr, GameVector* container) : owner(0)
{
    if (!container || container->first > ptr || ptr > container->last)
        FUN_00ec7c56();
    owner = container->iteratorOwner;
    current = ptr;
}

struct ForwardTag
{
};

struct BidirectionalTag : ForwardTag
{
};

struct RandomTag : BidirectionalTag
{
};

struct NonScalarTag
{
};

struct RangeTag
{
};

inline RandomTag iterRandom(GameRecord* const&, GameRecord* const&)
{
    RandomTag cat;
    return cat;
}

inline NonScalarTag ptrCat(GameRecord* const&, GameRecord* const&)
{
    NonScalarTag cat;
    return cat;
}

struct UnchangedTag
{
};

inline GameRecord* checkedBase(GameRecord*& ptr, UnchangedTag)
{
    return ptr;
}

inline GameRecord* checkedBase(GameRecord*& ptr)
{
    UnchangedTag tag;
    return checkedBase(ptr, tag);
}

inline GameRecord* copyOpt(GameRecord* first, GameRecord* last, GameRecord* dest, ForwardTag, NonScalarTag, RangeTag)
{
    for (; first != last; ++dest, ++first)
        *dest = *first;
    return dest;
}

inline GameRecord* copyOpt(GameRecord* first, GameRecord* last, GameRecord* dest, RandomTag, NonScalarTag, RangeTag)
{
    GameRecord* result = dest + (last - first);
    copyOpt(first, last, checkedBase(dest), ForwardTag(), NonScalarTag(), RangeTag());
    return result;
}

inline GameRecord* uncheckedCopy(GameRecord* first, GameRecord* last, GameRecord* dest)
{
    return copyOpt(checkedBase(first), checkedBase(last), dest, iterRandom(first, dest), ptrCat(first, dest),
                   RangeTag());
}

void destroyRange(GameRecord* first, GameRecord* last, GameAllocator& alloc, NonScalarTag)
{
    for (; first != last; ++first)
        alloc.destroy(first);
}

inline void destroyRange(GameRecord* first, GameRecord* last, GameAllocator& alloc)
{
    destroyRange(first, last, alloc, ptrCat(first, last));
}

inline void GameVector::destroy(GameRecord* first, GameRecord* last)
{
    destroyRange(first, last, allocator_ob1);
}

inline GameIterator GameVector::func_0x00abb5f0(GameConstIterator firstArg, GameConstIterator lastArg)
{
    GameIterator firstIt = makeIter(firstArg);
    GameIterator lastIt = makeIter(lastArg);
    if (firstIt != lastIt)
    {
        GameRecord* rangeStart = firstIt.current;
        GameRecord* ptr = uncheckedCopy(lastIt.current, last, rangeStart);
        destroy(ptr, last);
        last = ptr;
    }
    return firstIt;
}

namespace fnv_00ac0530 {
struct FUN_00ac0640_cls
{
};

struct AcFrameGuard
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
    int unk5C;
    int unk60;
    __forceinline ~AcFrameGuard()
    {}
};

struct FUN_00ac0530_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    FUN_00ac0640_cls m_1c;
    void AssignSubstring(int a, int b, int c);
    FUN_00ac0530_cls* FUN_00ac0530(::std::intptr_t a);
};


// @fnv 0x00ac0530
FUN_00ac0530_cls* FUN_00ac0530_cls::FUN_00ac0530(::std::intptr_t a)
{
    reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>((this))->FUN_0044a730(0, 0);
    this->AssignSubstring(a, 0, (*reinterpret_cast<int *>(&::g_010173f0)));
    {
        AcFrameGuard guard;
        new ((void *)&(m_1c)) ::FUN_00ac0640((*(const ::FUN_00ac0640 *)(a + 0x1c)));
    }
    return this;
}
}

// namespace fnv_00ac0530


extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);

extern "C" int __cdecl memmove_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);

void __cdecl FUN_00ec7c56();

namespace std {
class bad_alloc_ob1
{
  public:
    bad_alloc_ob1(const char* pcMessage = "bad allocation") throw();
    virtual ~bad_alloc_ob1() throw();

  private:
    const char* m_pcWhat;
    int m_iDoFree;
};
}

struct SecureCharTag
{
};

struct CharTraits
{
    static unsigned int length(const char* pcFirst)
    {
        return strlen(pcFirst);
    }
    static char* _Copy_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memcpy_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
    static char* _Move_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memmove_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
    static void assign(char& cLeft, const char& cRight)
    {
        cLeft = cRight;
    }
};

struct TraitsHelper
{
    static SecureCharTag CharTraitsCat()
    {
        SecureCharTag kTag;
        return kTag;
    }
    static char* CopySHelper(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                             SecureCharTag)
    {
        return CharTraits::_Copy_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
    }
    static char* CopyS(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
    {
        return CopySHelper(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCat());
    }
    static char* MoveSHelper(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                             SecureCharTag)
    {
        return CharTraits::_Move_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
    }
    static char* MoveS(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
    {
        return MoveSHelper(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCat());
    }
};

inline char* AllocateChars(unsigned int ItemUpdateArray, char*)
{
    if (ItemUpdateArray <= 0)
        ItemUpdateArray = 0;
    else if (((unsigned int)(-1) / ItemUpdateArray) < sizeof(char))
        throw std::bad_alloc_ob1(0);
    return (char*)::FUN_00401000(ItemUpdateArray * sizeof(char));
}

struct CharAllocator
{
    CharAllocator()
    {}
    void deallocate(char* pcPtr, unsigned int)
    {
        ::FUN_00401030(pcPtr);
    }
    char* allocate(unsigned int ItemUpdateArray)
    {
        return AllocateChars(ItemUpdateArray, (char*)0);
    }
    unsigned int max_size() const
    {
        unsigned int ItemUpdateArray = (unsigned int)(-1) / sizeof(char);
        return 0 < ItemUpdateArray ? ItemUpdateArray : 1;
    }
};

struct StringBase
{
    static void _Xlen();
    static void _Xran();
};

struct StringVal : public StringBase
{
    StringVal(CharAllocator kAl = CharAllocator()) : m_kAlval(kAl)
    {}
    CharAllocator m_kAlval;
};

struct String : public StringVal
{
    static const unsigned int npos;
    String(const char* pcPtr) : StringVal()
    {
        _Tidy();
        assign(pcPtr);
    }
    String(const String& kRight) : StringVal(kRight.m_kAlval)
    {
        _Tidy();
        assign(kRight, 0, ::g_010173f0);
    }
    ~String()
    {
        _Tidy(true);
    }
    String& assign(const String& kRight, unsigned int uiRoff, unsigned int ItemUpdateArray)
    {
        if (kRight.size() < uiRoff)
            _Xran();
        unsigned int uiElementCount = kRight.size() - uiRoff;
        if (ItemUpdateArray < uiElementCount)
            uiElementCount = ItemUpdateArray;
        if (this == &kRight)
            erase((unsigned int)(uiRoff + uiElementCount)), erase(0, uiRoff);
        else if (_Grow(uiElementCount))
        {
            TraitsHelper::CopyS(_Myptr(), m_uiRes, kRight._Myptr() + uiRoff, uiElementCount);
            _Eos(uiElementCount);
        }
        return *this;
    }
    String& assign(const char* pcPtr, unsigned int ItemUpdateArray)
    {
        if (_Inside(pcPtr))
            return assign(*this, pcPtr - _Myptr(), ItemUpdateArray);
        if (_Grow(ItemUpdateArray))
        {
            TraitsHelper::CopyS(_Myptr(), m_uiRes, pcPtr, ItemUpdateArray);
            _Eos(ItemUpdateArray);
        }
        return *this;
    }
    String& assign(const char* pcPtr)
    {
        return assign(pcPtr, CharTraits::length(pcPtr));
    }
    String& erase(unsigned int uiOff = 0, unsigned int ItemUpdateArray = ::g_010173f0)
    {
        if (m_uiSize < uiOff)
            _Xran();
        if (m_uiSize - uiOff < ItemUpdateArray)
            ItemUpdateArray = m_uiSize - uiOff;
        if (0 < ItemUpdateArray)
        {
            TraitsHelper::MoveS(_Myptr() + uiOff, m_uiRes - uiOff, _Myptr() + uiOff + ItemUpdateArray,
                                m_uiSize - uiOff - ItemUpdateArray);
            unsigned int uiNewsize = m_uiSize - ItemUpdateArray;
            _Eos(uiNewsize);
        }
        return *this;
    }
    const char* c_str() const
    {
        if (16 <= m_uiRes)
            return m_kBx.m_pcPtr;
        return m_kBx.m_acBuf;
    }
    unsigned int size() const
    {
        return m_uiSize;
    }
    unsigned int length() const
    {
        return m_uiSize;
    }
    unsigned int max_size() const
    {
        unsigned int uiElementCount = m_kAlval.max_size();
        return uiElementCount <= 1 ? 1 : uiElementCount - 1;
    }
    const char& operator[](unsigned int uiOff) const
    {
        if (!(uiOff <= m_uiSize))
            FUN_00ec7c56();
        do
        {
        } while (0);
        return _Myptr()[uiOff];
    }
    void _Copy(unsigned int uiNewsize, unsigned int uiOldlen)
    {
        unsigned int uiNewres = uiNewsize | 15;
        if (max_size() < uiNewres)
            uiNewres = uiNewsize;
        else if (uiNewres / 3 < m_uiRes / 2 && m_uiRes <= max_size() - m_uiRes / 2)
            uiNewres = m_uiRes + m_uiRes / 2;
        char* pcPtr = 0;
        try
        {
            pcPtr = m_kAlval.allocate(uiNewres + 1);
        }
        catch (...)
        {
            uiNewres = uiNewsize;
            try
            {
                pcPtr = m_kAlval.allocate(uiNewres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < uiOldlen)
            TraitsHelper::CopyS(pcPtr, uiNewres + 1, _Myptr(), uiOldlen);
        _Tidy(true);
        m_kBx.m_pcPtr = pcPtr;
        m_uiRes = uiNewres;
        _Eos(uiOldlen);
    }
    void _Eos(unsigned int uiNewsize)
    {
        CharTraits::assign(_Myptr()[m_uiSize = uiNewsize], char());
    }
    bool _Grow(unsigned int uiNewsize, bool bTrim = false)
    {
        if (max_size() < uiNewsize)
            _Xlen();
        if (m_uiRes < uiNewsize)
            _Copy(uiNewsize, m_uiSize);
        else if (bTrim && uiNewsize < 16)
            reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, uiNewsize < m_uiSize ? uiNewsize : m_uiSize);
        else if (uiNewsize == 0)
            _Eos(0);
        return 0 < uiNewsize;
    }
    bool _Inside(const char* pcPtr)
    {
        if (pcPtr == 0 || pcPtr < _Myptr() || _Myptr() + m_uiSize <= pcPtr)
            return false;
        else
            return true;
    }
    char* _Myptr()
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    const char* _Myptr() const
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    void _Tidy(bool bBuilt = false, unsigned int uiNewsize = 0)
    {
        if (!bBuilt)
            ;
        else if (16 <= m_uiRes)
        {
            char* pcPtr = m_kBx.m_pcPtr;
            if (0 < uiNewsize)
                TraitsHelper::CopyS(m_kBx.m_acBuf, 16, pcPtr, uiNewsize);
            m_kAlval.deallocate(pcPtr, m_uiRes + 1);
        }
        m_uiRes = 15;
        _Eos(uiNewsize);
    }
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
};

const unsigned int String::npos = (unsigned int)(-1);

struct S_00ac05b0_Sub
{
    S_00ac05b0_Sub(const S_00ac05b0_Sub& kOther);
};

class FUN_00ac05b0 : public String
{
  public:
    FUN_00ac05b0(const FUN_00ac05b0& kOther);
    int m_iValue;
    S_00ac05b0_Sub m_kSub;
};

// @fnv 0x00ac05b0
FUN_00ac05b0::FUN_00ac05b0(const FUN_00ac05b0& kOther)
    : String(kOther), m_iValue(kOther.m_iValue), m_kSub(kOther.m_kSub)
{}

namespace fnv_00ac3df0 {
namespace binac3 {
void FUN_00ec7c56();
int FUN_00ec7c66(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
int FUN_00ec7c6b(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
struct BxSecureTag
{
};
struct BxStrTraits
{
    static char* _Copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c66(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static char* _Move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c6b(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static unsigned int length(const char* _First)
    {
        return strlen(_First);
    }
    static void assign(char& _Left, const char& _Right)
    {
        _Left = _Right;
    }
};
inline BxSecureTag BxCharTraitsCat()
{
    BxSecureTag _Secure_char_traits;
    return _Secure_char_traits;
}
struct BxTraitsHelper
{
    template <class T>
    static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Copy_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return copy_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
    template <class T>
    static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Move_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return move_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
};
struct BxBadAlloc
{
    const char* pWhat;
    int iDoFree;
    BxBadAlloc(const char* what);
    ~BxBadAlloc();
};
template <class T> inline T* BxAllocate(unsigned int count, T*)
{
    if (count <= 0)
    {
        count = 0;
    }
    else if (((unsigned int)(-1) / count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)::FUN_00401000(count * sizeof(T));
}
template <class T> struct BxAllocT
{
    typedef T* pointer;
    BxAllocT() throw()
    {}
    BxAllocT(const BxAllocT<T>&) throw()
    {}
    pointer allocate(unsigned int _Count)
    {
        return BxAllocate(_Count, (pointer)0);
    }
    pointer allocate(unsigned int _Count, const void*)
    {
        return allocate(_Count);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        ::FUN_00401030(_Ptr);
    }
    unsigned int max_size() const
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
typedef BxAllocT<char> BxCharAlloc;
struct BxStringVal
{
    BxCharAlloc _Alval;
    BxStringVal(BxCharAlloc _Al = BxCharAlloc()) : _Alval(_Al)
    {}
    BxStringVal(const BxStringVal& _Right) : _Alval(_Right._Alval)
    {}
};
struct BxString : public BxStringVal
{
    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    BxString(const char* _Ptr) : BxStringVal()
    {
        _Tidy();
        assign(_Ptr);
    }
    BxString() : BxStringVal()
    {
        _Tidy();
    }
    BxString& operator=(const BxString& _Right)
    {
        return assign(_Right);
    }
    BxString& assign(const BxString& _Right)
    {
        return assign(_Right, 0, ::g_010173f0);
    }
    BxString(const BxString& _Right) : BxStringVal(_Right)
    {
        _Tidy();
        assign(_Right, 0, (unsigned int)-1);
    }
    ~BxString()
    {
        _Tidy(true);
    }
    static void _Xlen();
    static void _Xran();
    unsigned int size() const
    {
        return _Mysize;
    }
    char& operator[](unsigned int _Off)
    {
        if (!(_Off <= _Mysize))
        {
            FUN_00ec7c56();
        }
        do
        {
        } while (0);
        return _Myptr()[_Off];
    }
    unsigned int max_size() const
    {
        unsigned int _Num = _Alval.max_size();
        return _Num <= 1 ? 1 : _Num - 1;
    }
    char* _Myptr()
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    const char* _Myptr() const
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    void _Eos(unsigned int _Newsize)
    {
        BxStrTraits::assign(_Myptr()[_Mysize = _Newsize], char());
    }
    BxString& erase(unsigned int _Off = 0, unsigned int _Count = (unsigned int)-1)
    {
        if (_Mysize < _Off)
        {
            _Xran();
        }
        if (_Mysize - _Off < _Count)
        {
            _Count = _Mysize - _Off;
        }
        if (0 < _Count)
        {
            BxTraitsHelper::move_s<BxStrTraits>(_Myptr() + _Off, _Myres - _Off, _Myptr() + _Off + _Count,
                                                _Mysize - _Off - _Count);
            unsigned int _Newsize = _Mysize - _Count;
            _Eos(_Newsize);
        }
        return *this;
    }
    bool _Inside(const char* _Ptr)
    {
        if (_Ptr == 0 || _Ptr < _Myptr() || _Myptr() + _Mysize <= _Ptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void _Tidy(bool _Built = false, unsigned int _Newsize = 0)
    {
        if (!_Built)
        {
        }
        else if (16 <= _Myres)
        {
            char* _Ptr = _Bx._Ptr;
            if (0 < _Newsize)
            {
                BxTraitsHelper::copy_s<BxStrTraits>(_Bx._Buf, 16, _Ptr, _Newsize);
            }
            _Alval.deallocate(_Ptr, _Myres + 1);
        }
        _Myres = 16 - 1;
        _Eos(_Newsize);
    }
    void _Copy(unsigned int _Newsize, unsigned int _Oldlen)
    {
        unsigned int _Newres = _Newsize | 15;
        if (max_size() < _Newres)
        {
            _Newres = _Newsize;
        }
        else if (_Newres / 3 < _Myres / 2 && _Myres <= max_size() - _Myres / 2)
        {
            _Newres = _Myres + _Myres / 2;
        }
        char* _Ptr = 0;
        try
        {
            _Ptr = _Alval.allocate(_Newres + 1);
        }
        catch (...)
        {
            _Newres = _Newsize;
            try
            {
                _Ptr = _Alval.allocate(_Newres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < _Oldlen)
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Ptr, _Newres + 1, _Myptr(), _Oldlen);
        }
        _Tidy(true);
        _Bx._Ptr = _Ptr;
        _Myres = _Newres;
        _Eos(_Oldlen);
    }
    bool _Grow(unsigned int _Newsize, bool _Trim = false)
    {
        if (max_size() < _Newsize)
        {
            _Xlen();
        }
        if (_Myres < _Newsize)
        {
            _Copy(_Newsize, _Mysize);
        }
        else if (_Trim && _Newsize < 16)
        {
            reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, _Newsize < _Mysize ? _Newsize : _Mysize);
        }
        else if (_Newsize == 0)
        {
            _Eos(0);
        }
        return 0 < _Newsize;
    }
    BxString& assign(const BxString& _Right, unsigned int _Roff, unsigned int _Count)
    {
        if (_Right.size() < _Roff)
        {
            _Xran();
        }
        unsigned int _Num = _Right.size() - _Roff;
        if (_Count < _Num)
        {
            _Num = _Count;
        }
        if (this == &_Right)
        {
            erase((unsigned int)(_Roff + _Num)), erase(0, _Roff);
        }
        else if (_Grow(_Num))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Right._Myptr() + _Roff, _Num);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& assign(const char* _Ptr, unsigned int _Count)
    {
        if (_Inside(_Ptr))
        {
            return assign(*this, _Ptr - _Myptr(), _Count);
        }
        if (_Grow(_Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Ptr, _Count);
            _Eos(_Count);
        }
        return *this;
    }
    BxString& assign(const char* _Ptr)
    {
        return assign(_Ptr, BxStrTraits::length(_Ptr));
    }
};
struct BxException
{
    const char* _m_what;
    int _m_doFree;
    BxException();
    BxException(const BxException& _That);
    virtual ~BxException();
    virtual const char* what() const;
};
struct BxLogicError : public BxException
{
    BxString _Str;
    explicit BxLogicError(const BxString& _Message) : _Str(_Message)
    {}
    virtual ~BxLogicError()
    {}
    virtual const char* what() const
    {
        return _Str._Myptr();
    }
};
struct BxLengthError : public BxLogicError
{
    explicit BxLengthError(const BxString& _Message) : BxLogicError(_Message)
    {}
    virtual ~BxLengthError()
    {}
};

}
using namespace binac3;

struct FUN_00ac3df0
{
    BxString kPath;
    BxString kName;
    int unk3c;
    FUN_00ac3df0(BxString name);
    virtual void v00();
};

// @fnv 0x00ac3df0
FUN_00ac3df0::FUN_00ac3df0(BxString name)
{
    kName = name;
    if (kName.size() == 8)
    {
    }
    else
    {
        ::ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\binaryFile.cpp", 0x22);
    }
    unk3c = 0;
    kName[5] = '0';
}
}

// namespace fnv_00ac3df0

namespace wrac52 {
void FUN_00ec7c56();
int FUN_00ec7c66(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
int FUN_00ec7c6b(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
struct BxSecureTag
{
};
struct BxStrTraits
{
    static char* _Copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c66(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static char* _Move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c6b(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static unsigned int length(const char* _First)
    {
        return strlen(_First);
    }
    static int compare(const char* _First1, const char* _First2, unsigned int _Count)
    {
        return memcmp(_First1, _First2, _Count);
    }
    static void assign(char& _Left, const char& _Right)
    {
        _Left = _Right;
    }
};
inline BxSecureTag BxCharTraitsCat()
{
    BxSecureTag _Secure_char_traits;
    return _Secure_char_traits;
}
struct BxTraitsHelper
{
    template <class T>
    static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Copy_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return copy_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
    template <class T>
    static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Move_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return move_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
};
struct BxBadAlloc
{
    const char* pWhat;
    int iDoFree;
    BxBadAlloc(const char* what);
    ~BxBadAlloc();
};
template <class T> inline T* BxAllocate(unsigned int count, T*)
{
    if (count <= 0)
    {
        count = 0;
    }
    else if (((unsigned int)(-1) / count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)::FUN_00401000(count * sizeof(T));
}
template <class T> struct BxAllocT
{
    typedef T* pointer;
    BxAllocT() throw()
    {}
    BxAllocT(const BxAllocT<T>&) throw()
    {}
    pointer allocate(unsigned int _Count)
    {
        return BxAllocate(_Count, (pointer)0);
    }
    pointer allocate(unsigned int _Count, const void*)
    {
        return allocate(_Count);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        ::FUN_00401030(_Ptr);
    }
    unsigned int max_size() const
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
typedef BxAllocT<char> BxCharAlloc;
struct BxStringVal
{
    BxCharAlloc _Alval;
    BxStringVal(BxCharAlloc _Al = BxCharAlloc()) : _Alval(_Al)
    {}
    BxStringVal(const BxStringVal& _Right) : _Alval(_Right._Alval)
    {}
};
struct BxString : public BxStringVal
{
    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    BxString(const char* _Ptr) : BxStringVal()
    {
        _Tidy();
        assign(_Ptr);
    }
    BxString() : BxStringVal()
    {
        _Tidy();
    }
    BxString& operator=(const BxString& _Right)
    {
        return assign(_Right);
    }
    BxString& assign(const BxString& _Right)
    {
        return assign(_Right, 0, ::g_010173f0);
    }
    BxString(const BxString& _Right) : BxStringVal(_Right)
    {
        _Tidy();
        assign(_Right, 0, ::g_010173f0);
    }
    ~BxString()
    {
        _Tidy(true);
    }
    static void _Xlen();
    static void _Xran();
    unsigned int size() const
    {
        return _Mysize;
    }
    char& operator[](unsigned int _Off)
    {
        if (!(_Off <= _Mysize))
        {
            FUN_00ec7c56();
        }
        do
        {
        } while (0);
        return _Myptr()[_Off];
    }
    unsigned int max_size() const
    {
        unsigned int _Num = _Alval.max_size();
        return _Num <= 1 ? 1 : _Num - 1;
    }
    char* _Myptr()
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    const char* _Myptr() const
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    void _Eos(unsigned int _Newsize)
    {
        BxStrTraits::assign(_Myptr()[_Mysize = _Newsize], char());
    }
    BxString& erase(unsigned int _Off = 0, unsigned int _Count = (unsigned int)-1)
    {
        if (_Mysize < _Off)
        {
            _Xran();
        }
        if (_Mysize - _Off < _Count)
        {
            _Count = _Mysize - _Off;
        }
        if (0 < _Count)
        {
            BxTraitsHelper::move_s<BxStrTraits>(_Myptr() + _Off, _Myres - _Off, _Myptr() + _Off + _Count,
                                                _Mysize - _Off - _Count);
            unsigned int _Newsize = _Mysize - _Count;
            _Eos(_Newsize);
        }
        return *this;
    }
    bool _Inside(const char* _Ptr)
    {
        if (_Ptr == 0 || _Ptr < _Myptr() || _Myptr() + _Mysize <= _Ptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void _Tidy(bool _Built = false, unsigned int _Newsize = 0)
    {
        if (!_Built)
        {
        }
        else if (16 <= _Myres)
        {
            char* _Ptr = _Bx._Ptr;
            if (0 < _Newsize)
            {
                BxTraitsHelper::copy_s<BxStrTraits>(_Bx._Buf, 16, _Ptr, _Newsize);
            }
            _Alval.deallocate(_Ptr, _Myres + 1);
        }
        _Myres = 16 - 1;
        _Eos(_Newsize);
    }
    void _Copy(unsigned int _Newsize, unsigned int _Oldlen)
    {
        unsigned int _Newres = _Newsize | 15;
        if (max_size() < _Newres)
        {
            _Newres = _Newsize;
        }
        else if (_Newres / 3 < _Myres / 2 && _Myres <= max_size() - _Myres / 2)
        {
            _Newres = _Myres + _Myres / 2;
        }
        char* _Ptr = 0;
        try
        {
            _Ptr = _Alval.allocate(_Newres + 1);
        }
        catch (...)
        {
            _Newres = _Newsize;
            try
            {
                _Ptr = _Alval.allocate(_Newres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < _Oldlen)
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Ptr, _Newres + 1, _Myptr(), _Oldlen);
        }
        _Tidy(true);
        _Bx._Ptr = _Ptr;
        _Myres = _Newres;
        _Eos(_Oldlen);
    }
    bool _Grow(unsigned int _Newsize, bool _Trim = false)
    {
        if (max_size() < _Newsize)
        {
            _Xlen();
        }
        if (_Myres < _Newsize)
        {
            _Copy(_Newsize, _Mysize);
        }
        else if (_Trim && _Newsize < 16)
        {
            reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, _Newsize < _Mysize ? _Newsize : _Mysize);
        }
        else if (_Newsize == 0)
        {
            _Eos(0);
        }
        return 0 < _Newsize;
    }
    BxString& assign(const BxString& _Right, unsigned int _Roff, unsigned int _Count)
    {
        if (_Right.size() < _Roff)
        {
            _Xran();
        }
        unsigned int _Num = _Right.size() - _Roff;
        if (_Count < _Num)
        {
            _Num = _Count;
        }
        if (this == &_Right)
        {
            erase((unsigned int)(_Roff + _Num)), erase(0, _Roff);
        }
        else if (_Grow(_Num))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Right._Myptr() + _Roff, _Num);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& assign(const char* _Ptr, unsigned int _Count)
    {
        if (_Inside(_Ptr))
        {
            return assign(*this, _Ptr - _Myptr(), _Count);
        }
        if (_Grow(_Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Ptr, _Count);
            _Eos(_Count);
        }
        return *this;
    }
    const char& operator[](unsigned int _Off) const
    {
        if (!(_Off <= _Mysize))
        {
            FUN_00ec7c56();
        }
        return _Myptr()[_Off];
    }
    BxString& append(const BxString& _Right, unsigned int _Roff, unsigned int _Count)
    {
        if (_Right.size() < _Roff)
        {
            _Xran();
        }
        unsigned int _Num = _Right.size() - _Roff;
        if (_Num < _Count)
        {
            _Count = _Num;
        }
        if (::g_010173f0 - _Mysize <= _Count || _Mysize + _Count < _Mysize)
        {
            _Xlen();
        }
        if (0 < _Count && _Grow(_Num = _Mysize + _Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr() + _Mysize, _Myres - _Mysize, _Right._Myptr() + _Roff, _Count);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& append(const char* _Ptr, unsigned int _Count)
    {
        if (_Inside(_Ptr))
        {
            return append(*this, _Ptr - _Myptr(), _Count);
        }
        if (::g_010173f0 - _Mysize <= _Count)
        {
            _Xlen();
        }
        unsigned int _Num;
        if (0 < _Count && _Grow(_Num = _Mysize + _Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr() + _Mysize, _Myres - _Mysize, _Ptr, _Count);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& append(const char* _Ptr)
    {
        return (*(::wrac52::BxString *)&(reinterpret_cast<::StrA *>(this)->FUN_00a0c430(_Ptr, BxStrTraits::length(_Ptr))));
    }
    BxString& operator+=(const char* _Ptr)
    {
        return append(_Ptr);
    }
    const char* c_str() const
    {
        return _Myptr();
    }
    int compare(unsigned int _Off, unsigned int _N0, const char* _Ptr, unsigned int _Count) const
    {
        if (_Mysize < _Off)
            _Xran();
        if (_Mysize - _Off < _N0)
            _N0 = _Mysize - _Off;
        unsigned int _Ans = BxStrTraits::compare(_Myptr() + _Off, _Ptr, _N0 < _Count ? _N0 : _Count);
        return _Ans != 0 ? (int)_Ans : _N0 < _Count ? -1 : _N0 == _Count ? 0 : +1;
    }
    int compare(const char* _Ptr) const
    {
        return compare(0, _Mysize, _Ptr, BxStrTraits::length(_Ptr));
    }
    BxString& assign(const char* _Ptr)
    {
        return assign(_Ptr, BxStrTraits::length(_Ptr));
    }
};
inline bool operator==(const BxString& _Left, const char* _Right)
{
    return _Left.compare(_Right) == 0;
}
inline bool operator!=(const BxString& _Left, const char* _Right)
{
    return !(_Left == _Right);
}
struct BxException
{
    const char* _m_what;
    int _m_doFree;
    BxException();
    BxException(const BxException& _That);
    virtual ~BxException();
    virtual const char* what() const;
};
struct BxLogicError : public BxException
{
    BxString _Str;
    explicit BxLogicError(const BxString& _Message) : _Str(_Message)
    {}
    virtual ~BxLogicError()
    {}
    virtual const char* what() const
    {
        return _Str._Myptr();
    }
};
struct BxLengthError : public BxLogicError
{
    explicit BxLengthError(const BxString& _Message) : BxLogicError(_Message)
    {}
    virtual ~BxLengthError()
    {}
};

struct GvHeap
{
    void* FUN_00aa3e40(unsigned int _Size);
    void FUN_00aa4060(void* _Ptr);
};
template <class T> inline T* GvHeapAllocate(unsigned int _Count, T*)
{
    if (_Count <= 0)
    {
        _Count = 0;
    }
    else if (((unsigned int)(-1) / _Count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)((GvHeap*)&(*reinterpret_cast<int *>(&::g_memoryManager)))->FUN_00aa3e40(_Count * sizeof(T));
}
template <class T> inline void GvDestroyOne(T* _Ptr)
{
    reinterpret_cast<::fnv_0065ed70::FUN_0065ed70 *>((_Ptr))->fnv_0065ed70::FUN_0065ed70::~FUN_0065ed70();
}
template <class T1, class T2> inline void GvConstruct(T1* _Ptr, const T2& _Val);
template <class T> struct GvAlloc
{
    typedef T* pointer;
    GvAlloc() throw()
    {}
    GvAlloc(const GvAlloc<T>&) throw()
    {}
    template <class O> GvAlloc(const GvAlloc<O>&) throw()
    {}
    pointer allocate(unsigned int _Count)
    {
        return GvHeapAllocate(_Count, (pointer)0);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        reinterpret_cast<::FNV_MemoryManager *>((((GvHeap*)&(*reinterpret_cast<int *>(&::g_memoryManager)))))->FUN_00aa4060(_Ptr);
    }
    void destroy(pointer _Ptr)
    {
        GvDestroyOne(_Ptr);
    }
    void construct(pointer _Ptr, const T& _Val)
    {
        GvConstruct(_Ptr, _Val);
    }
    unsigned int max_size() const throw()
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
struct GvNonscalarTag
{
};
struct GvScalarTag
{
};
struct GvRangeCheckedTag
{
};
template <class T1, class T2> struct GvPtrCatHelper
{
    typedef GvNonscalarTag _Ptr_cat;
};
template <> struct GvPtrCatHelper<char*, char*>
{
    typedef GvScalarTag _Ptr_cat;
};
template <> struct GvPtrCatHelper<unsigned short*, unsigned short*>
{
    typedef GvScalarTag _Ptr_cat;
};
template <class T> struct GvPtrCatHelper<T**, T**>
{
    typedef GvScalarTag _Ptr_cat;
};
template <class T1, class T2> inline typename GvPtrCatHelper<T1, T2>::_Ptr_cat GvPtrCat(T1&, T2&)
{
    typename GvPtrCatHelper<T1, T2>::_Ptr_cat _Cat;
    return _Cat;
}
template <class A> inline void GvDestroyRange(typename A::pointer, typename A::pointer, A&, GvScalarTag)
{}
template <class T, class A>
void GvUninitFillN(T* _First, unsigned int _Count, const T& _Val, A& _Al, GvNonscalarTag, GvRangeCheckedTag);
template <class T, class A> inline void GvUncheckedFillN(T* _First, unsigned int _Count, const T& _Val, A& _Al)
{
    ::fnv_00ac2440::FUN_00ac2440((::fnv_00ac2440::Elem *)(_First), _Count, (const ::fnv_00ac2440::Elem &)(_Val));
}
template <class A>
inline void GvDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al, GvNonscalarTag)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class A> inline void GvDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al)
{
    GvDestroyRange<A>(_First, _Last, _Al, GvPtrCat(_First, _Last));
}
struct GvInputTag
{
};
struct GvForwardTag : GvInputTag
{
};
struct GvBidiTag : GvForwardTag
{
};
struct GvRandomTag : GvBidiTag
{
};
struct GvUnchangedTag
{
};
template <class I1, class I2> inline GvRandomTag GvIterRandom(const I1&, const I2&)
{
    GvRandomTag _Cat;
    return _Cat;
}
struct GvBaseTag
{
};
template <class T> struct GvConstIterator;
template <class I> struct GvCheckedHelper
{
    typedef GvUnchangedTag _Tag;
    typedef I _Base;
};
template <class T> struct GvCheckedHelper<GvConstIterator<T> >
{
    typedef GvBaseTag _Tag;
    typedef const T* _Base;
};
template <class I, class B> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It, B)
{
    return _It._Checked_iterator_base();
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I, class B> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It, B)
{
    return _It._Checked_iterator_base();
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It)
{
    typename GvCheckedHelper<I>::_Tag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It)
{
    typename GvCheckedHelper<I>::_Tag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
}
template <class O, class D, class T> inline void GvFillN(O _First, D _Count, const T& _Val, GvRangeCheckedTag)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class O, class D, class T, class C>
inline void GvFillN(O _First, D _Count, const T& _Val, C, GvRangeCheckedTag)
{
    GvFillN(_First, _Count, _Val, GvRangeCheckedTag());
}
template <class O, class D, class T>
inline void GvFillN(O _First, D _Count, const T& _Val, GvRandomTag, GvRangeCheckedTag)
{
    O _Last = _First + _Count;
    (void)_Last;
    GvFillN(GvCheckedBase(_First), _Count, _Val, GvRangeCheckedTag());
}
template <class I> inline GvRandomTag GvIterCat(const I&)
{
    GvRandomTag _Cat;
    return _Cat;
}
template <class O, class D, class T> inline void GvUncheckedFillValues(O _First, D _Count, const T& _Val)
{
    GvFillN(_First, _Count, _Val, GvIterCat(_First), GvRangeCheckedTag());
}
template <class T, class A>
inline void GvUninitFillN(T* _First, unsigned int _Count, const T& _Val, A&, GvScalarTag, GvRangeCheckedTag)
{
    GvUncheckedFillValues(_First, _Count, _Val);
}
template <class I, class O, class C>
inline O GvCopyOpt(I _First, I _Last, O _Dest, C, GvNonscalarTag, GvRangeCheckedTag)
{
    for (; _First != _Last; ++_Dest, ++_First)
    {
        *_Dest = *_First;
    }
    return _Dest;
}
template <class I, class O>
inline O GvCopyOpt(I _First, I _Last, O _Dest, GvRandomTag, GvNonscalarTag, GvRangeCheckedTag)
{
    O _Result = _Dest + (_Last - _First);
    GvCopyOpt(_First, _Last, GvCheckedBase(_Dest), GvForwardTag(), GvNonscalarTag(), GvRangeCheckedTag());
    return _Result;
}
template <class I, class O, class C> inline O GvCopyOpt(I _First, I _Last, O _Dest, C, GvScalarTag, GvRangeCheckedTag)
{
    int _Off = _Last - _First;
    O _Result = _Dest + _Off;
    if (_Off > 0)
        FUN_00ec7c6b(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class I, class O> inline O GvUncheckedCopy(I _First, I _Last, O _Dest)
{
    return GvCopyOpt(GvCheckedBase(_First), GvCheckedBase(_Last), _Dest, GvIterRandom(_First, _Dest),
                     GvPtrCat(_First, _Dest), GvRangeCheckedTag());
}
template <class I, class F, class A>
inline F GvUninitCopy(I _First, I _Last, F _Dest, A& _Al, GvNonscalarTag, GvRangeCheckedTag)
{
    F _Next = _Dest;
    try
    {
        for (; _First != _Last; ++_Dest, ++_First)
        {
            _Al.construct(_Dest, *_First);
        }
    }
    catch (...)
    {
        for (; _Next != _Dest; ++_Next)
        {
            _Al.destroy(_Next);
        }
        throw;
    }
    return _Dest;
}
template <class I, class F, class A>
inline F GvUninitCopy(I _First, I _Last, F _Dest, A&, GvScalarTag, GvRangeCheckedTag)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    F _Result = _Dest + _Count;
    if (_Count > 0)
        FUN_00ec7c6b(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return _Result;
}
template <class I, class F, class A> inline F GvUncheckedUninitCopy(I _First, I _Last, F _Dest, A& _Al)
{
    return GvUninitCopy(GvCheckedBase(_First), GvCheckedBase(_Last), _Dest, _Al, GvPtrCat(_First, _Dest),
                        GvRangeCheckedTag());
}
template <class T1, class T2> inline void GvConstruct(T1* _Ptr, const T2& _Val)
{
    void* _Vptr = _Ptr;
    ::new (_Vptr) T1(_Val);
}
struct GvContainer;
struct GvAuxCont
{
    const GvContainer* _Mycontainer;
    GvAuxCont(const GvContainer* _Pcont) : _Mycontainer(_Pcont)
    {}
    const GvContainer* _Getcont() const
    {
        return _Mycontainer;
    }
};
struct GvContainer
{
    GvAuxCont* _Myownedaux;
    GvContainer()
    {}
    GvContainer(const GvContainer&)
    {}
    GvContainer& operator=(const GvContainer&)
    {
        return *this;
    }
    ~GvContainer()
    {}
};
template <class A> struct GvAuxBase : GvContainer
{
    GvAlloc<GvAuxCont> _Alaux;
    explicit GvAuxBase(A _Al) : _Alaux(_Al)
    {
        _Myownedaux = new (_Alaux.allocate(1)) GvAuxCont(this);
    }
    GvAuxBase(const GvAuxBase& _Right) : _Alaux(_Right._Alaux)
    {
        _Myownedaux = new (_Alaux.allocate(1)) GvAuxCont(this);
    }
    ~GvAuxBase()
    {
        _Myownedaux->~GvAuxCont();
        _Alaux.deallocate(_Myownedaux, 1);
    }
};
struct GvIterBase
{
    GvAuxCont* _Myaux;
    GvIterBase() : _Myaux(0)
    {}
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    bool _Same_container(const GvIterBase& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    void _Set_container(const GvContainer* _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const GvContainer* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
};
template <class T> struct GvVector;
template <class T> struct GvConstIterator : GvIterBase
{
    T* _Myptr;
    const T* _Checked_iterator_base() const
    {
        return _Myptr;
    }
    GvConstIterator(T* _Ptr, const GvContainer* _Pvector)
    {
        {
            if (!(_Pvector != 0 && ((GvVector<T>*)_Pvector)->_Myfirst <= _Ptr &&
                  _Ptr <= ((GvVector<T>*)_Pvector)->_Mylast))
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
        }
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    GvConstIterator& operator+=(int _Off)
    {
        {
            if (!this->_Has_container())
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
        }
        {
            if (!(_Myptr + _Off <= ((GvVector<T>*)this->_Getmycont())->_Mylast &&
                  _Myptr + _Off >= ((GvVector<T>*)this->_Getmycont())->_Myfirst))
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
        }
        _Myptr += _Off;
        return *this;
    }
    bool operator==(const GvConstIterator& _Right) const
    {
        {
            if (!(this->_Has_container() && this->_Same_container(_Right)))
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
        }
        do
        {
        } while (0);
        return _Myptr == _Right._Myptr;
    }
    bool operator!=(const GvConstIterator& _Right) const
    {
        return !(*this == _Right);
    }
    int operator-(const GvConstIterator& _Right) const
    {
        {
            if (!(this->_Has_container() && this->_Same_container(_Right)))
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
        }
        return _Myptr - _Right._Myptr;
    }
};
template <class T> struct GvIterator : GvConstIterator<T>
{
    GvIterator(T* _Ptr, const GvContainer* _Pvector) : GvConstIterator<T>(_Ptr, _Pvector)
    {}
    GvIterator& operator+=(int _Off)
    {
        (*(GvConstIterator<T>*)this) += _Off;
        return *this;
    }
    GvIterator operator+(int _Off) const
    {
        GvIterator _Tmp = *this;
        return (_Tmp += _Off);
    }
};
template <class T> struct GvVectorVal : GvAuxBase<GvAlloc<T> >
{
    GvAlloc<T> _Alval;
    GvVectorVal(GvAlloc<T> _Al = GvAlloc<T>()) : GvAuxBase<GvAlloc<T> >(_Al), _Alval(_Al)
    {}
};
template <class T> struct GvVector : GvVectorVal<T>
{
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    GvVector() : GvVectorVal<T>()
    {
        _Buy(0);
    }
    explicit GvVector(unsigned int _Count) : GvVectorVal<T>()
    {
        _Construct_n(_Count, T());
    }
    void _Construct_n(unsigned int _Count, const T& _Val)
    {
        if (_Buy(_Count))
        {
            try
            {
                _Mylast = _Ufill(_Myfirst, _Count, _Val);
            }
            catch (...)
            {
                _Tidy();
                throw;
            }
        }
    }
    GvVector(const GvVector& _Right) : GvVectorVal<T>(_Right._Alval)
    {
        if (_Buy(_Right.size()))
        {
            try
            {
                _Mylast = _Ucopy(_Right.begin(), _Right.end(), _Myfirst);
            }
            catch (...)
            {
                _Tidy();
                throw;
            }
        }
    }
    ~GvVector()
    {
        reinterpret_cast<::S00acede0_Obj *>(this)->FUN_00acede0();
    }
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    unsigned int max_size() const
    {
        return this->_Alval.max_size();
    }
    GvIterator<T> begin()
    {
        return GvIterator<T>(_Myfirst, this);
    }
    GvIterator<T> end()
    {
        return GvIterator<T>(_Mylast, this);
    }
    GvConstIterator<T> begin() const
    {
        return GvConstIterator<T>(_Myfirst, this);
    }
    GvConstIterator<T> end() const
    {
        return GvConstIterator<T>(_Mylast, this);
    }
    static void _Xlen()
    {
        throw BxLengthError("vector<T> too long");
    }
    bool _Buy(unsigned int _Capacity)
    {
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
        if (_Capacity == 0)
        {
            return false;
        }
        else if (max_size() < _Capacity)
        {
            _Xlen();
        }
        else
        {
            _Myfirst = this->_Alval.allocate(_Capacity);
            _Mylast = _Myfirst;
            _Myend = _Myfirst + _Capacity;
        }
        return true;
    }
    void _Destroy(T* _First, T* _Last)
    {
        GvDestroyRange(_First, _Last, this->_Alval);
    }
    void _Tidy()
    {
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
    }
    T* _Ufill(T* _Ptr, unsigned int _Count, const T& _Val)
    {
        GvUncheckedFillN(_Ptr, _Count, _Val, this->_Alval);
        return _Ptr + _Count;
    }
    GvIterator<T> _Make_iter(GvConstIterator<T> _Where) const
    {
        return GvIterator<T>(_Where._Myptr, this);
    }
    GvIterator<T> erase(GvConstIterator<T> _First_arg, GvConstIterator<T> _Last_arg)
    {
        GvIterator<T> _First = _Make_iter(_First_arg);
        GvIterator<T> _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            T* _Ptr = GvUncheckedCopy(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return _First;
    }
    void clear()
    {
        erase(begin(), end());
    }
    void resize(unsigned int _Newsize, T _Val)
    {
        if (size() < _Newsize)
            _Insert_n(end(), _Newsize - size(), _Val);
        else if (_Newsize < size())
            erase(begin() + _Newsize, end());
    }
    void resize(unsigned int _Newsize)
    {
        resize(_Newsize, T());
    }
    T& operator[](unsigned int _Pos)
    {
        {
            if (!(_Pos < size()))
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
        }
        return *(_Myfirst + _Pos);
    }
    template <class I> T* _Ucopy(I _First, I _Last, T* _Ptr)
    {
        return GvUncheckedUninitCopy(_First, _Last, _Ptr, this->_Alval);
    }
    GvVector& operator=(const GvVector& _Right)
    {
        if (this != &_Right)
        {
            if (_Right.size() == 0)
            {
                reinterpret_cast<::Vec *>(this)->FUN_00acac40();
            }
            else if (_Right.size() <= size())
            {
                T* _Ptr = GvUncheckedCopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
                _Destroy(_Ptr, _Mylast);
                _Mylast = _Myfirst + _Right.size();
            }
            else if (_Right.size() <= capacity())
            {
                T* _Ptr = _Right._Myfirst + size();
                GvUncheckedCopy(_Right._Myfirst, _Ptr, _Myfirst);
                _Mylast = _Ucopy(_Ptr, _Right._Mylast, _Mylast);
            }
            else
            {
                if (_Myfirst != 0)
                {
                    _Destroy(_Myfirst, _Mylast);
                    this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
                }
                if (_Buy(_Right.size()))
                {
                    _Mylast = _Ucopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
                }
            }
        }
        return *this;
    }
    void _Insert_n(GvConstIterator<T> _Where, unsigned int _Count, const T& _Val);
    GvIterator<T> insert(GvConstIterator<T> _Where, const T& _Val)
    {
        unsigned int _Off = size() == 0 ? 0 : _Where - begin();
        _Insert_n(_Where, 1, _Val);
        return begin() + _Off;
    }
    void push_back(const T& _Val)
    {
        if (size() < capacity())
        {
            _Mylast = _Ufill(_Mylast, 1, _Val);
        }
        else
        {
            insert(end(), _Val);
        }
    }
};
struct GvFileHandle;
void FUN_00ac6430(int code, BxString message);
}
using namespace wrac52;

struct GvBinaryFile
{
    BxString kPath;
    BxString kMagic;
    GvFileHandle* pFile;
    virtual void v00();
    bool FUN_00ac5220(const void* data, unsigned int size, unsigned int count);
};

// @fnv 0x00ac5220
bool GvBinaryFile::FUN_00ac5220(const void* data, unsigned int size, unsigned int count)
{
    if (pFile == 0)
    {
        return false;
    }
    if (fwrite(data, size, count, (FILE*)pFile) != count)
    {
        FUN_00ac6430(6, kPath);
        reinterpret_cast<::FUN_00ac5430_cls *>(this)->FUN_00ac5430();
        return false;
    }
    return true;
}

namespace fnv_00ac6430 {
namespace errac6 {
void FUN_00ec7c56();
int FUN_00ec7c66(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
int FUN_00ec7c6b(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
struct BxSecureTag
{
};
struct BxStrTraits
{
    static char* _Copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c66(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static char* _Move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c6b(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static unsigned int length(const char* _First)
    {
        return strlen(_First);
    }
    static void assign(char& _Left, const char& _Right)
    {
        _Left = _Right;
    }
};
inline BxSecureTag BxCharTraitsCat()
{
    BxSecureTag _Secure_char_traits;
    return _Secure_char_traits;
}
struct BxTraitsHelper
{
    template <class T>
    static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Copy_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return copy_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
    template <class T>
    static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Move_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return move_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
};
struct BxBadAlloc
{
    const char* pWhat;
    int iDoFree;
    BxBadAlloc(const char* what);
    ~BxBadAlloc();
};
template <class T> inline T* BxAllocate(unsigned int count, T*)
{
    if (count <= 0)
    {
        count = 0;
    }
    else if (((unsigned int)(-1) / count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)::FUN_00401000(count * sizeof(T));
}
template <class T> struct BxAllocT
{
    typedef T* pointer;
    BxAllocT() throw()
    {}
    BxAllocT(const BxAllocT<T>&) throw()
    {}
    pointer allocate(unsigned int _Count)
    {
        return BxAllocate(_Count, (pointer)0);
    }
    pointer allocate(unsigned int _Count, const void*)
    {
        return allocate(_Count);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        ::FUN_00401030(_Ptr);
    }
    unsigned int max_size() const
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
typedef BxAllocT<char> BxCharAlloc;
struct BxStringVal
{
    BxCharAlloc _Alval;
    BxStringVal(BxCharAlloc _Al = BxCharAlloc()) : _Alval(_Al)
    {}
    BxStringVal(const BxStringVal& _Right) : _Alval(_Right._Alval)
    {}
};
struct BxString : public BxStringVal
{
    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    BxString(const char* _Ptr) : BxStringVal()
    {
        _Tidy();
        assign(_Ptr);
    }
    BxString(const BxString& _Right) : BxStringVal(_Right)
    {
        _Tidy();
        assign(_Right, 0, (unsigned int)-1);
    }
    ~BxString()
    {
        _Tidy(true);
    }
    static void _Xlen();
    static void _Xran();
    unsigned int size() const
    {
        return _Mysize;
    }
    char& operator[](unsigned int _Off)
    {
        if (!(_Off <= _Mysize))
        {
            FUN_00ec7c56();
        }
        return _Myptr()[_Off];
    }
    unsigned int max_size() const
    {
        unsigned int _Num = _Alval.max_size();
        return _Num <= 1 ? 1 : _Num - 1;
    }
    char* _Myptr()
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    const char* _Myptr() const
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    void _Eos(unsigned int _Newsize)
    {
        BxStrTraits::assign(_Myptr()[_Mysize = _Newsize], char());
    }
    BxString& erase(unsigned int _Off = 0, unsigned int _Count = (unsigned int)-1)
    {
        if (_Mysize < _Off)
        {
            _Xran();
        }
        if (_Mysize - _Off < _Count)
        {
            _Count = _Mysize - _Off;
        }
        if (0 < _Count)
        {
            BxTraitsHelper::move_s<BxStrTraits>(_Myptr() + _Off, _Myres - _Off, _Myptr() + _Off + _Count,
                                                _Mysize - _Off - _Count);
            unsigned int _Newsize = _Mysize - _Count;
            _Eos(_Newsize);
        }
        return *this;
    }
    bool _Inside(const char* _Ptr)
    {
        if (_Ptr == 0 || _Ptr < _Myptr() || _Myptr() + _Mysize <= _Ptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void _Tidy(bool _Built = false, unsigned int _Newsize = 0)
    {
        if (!_Built)
        {
        }
        else if (16 <= _Myres)
        {
            char* _Ptr = _Bx._Ptr;
            if (0 < _Newsize)
            {
                BxTraitsHelper::copy_s<BxStrTraits>(_Bx._Buf, 16, _Ptr, _Newsize);
            }
            _Alval.deallocate(_Ptr, _Myres + 1);
        }
        _Myres = 16 - 1;
        _Eos(_Newsize);
    }
    void _Copy(unsigned int _Newsize, unsigned int _Oldlen)
    {
        unsigned int _Newres = _Newsize | 15;
        if (max_size() < _Newres)
        {
            _Newres = _Newsize;
        }
        else if (_Newres / 3 < _Myres / 2 && _Myres <= max_size() - _Myres / 2)
        {
            _Newres = _Myres + _Myres / 2;
        }
        char* _Ptr = 0;
        try
        {
            _Ptr = _Alval.allocate(_Newres + 1);
        }
        catch (...)
        {
            _Newres = _Newsize;
            try
            {
                _Ptr = _Alval.allocate(_Newres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < _Oldlen)
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Ptr, _Newres + 1, _Myptr(), _Oldlen);
        }
        _Tidy(true);
        _Bx._Ptr = _Ptr;
        _Myres = _Newres;
        _Eos(_Oldlen);
    }
    bool _Grow(unsigned int _Newsize, bool _Trim = false)
    {
        if (max_size() < _Newsize)
        {
            _Xlen();
        }
        if (_Myres < _Newsize)
        {
            _Copy(_Newsize, _Mysize);
        }
        else if (_Trim && _Newsize < 16)
        {
            reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, _Newsize < _Mysize ? _Newsize : _Mysize);
        }
        else if (_Newsize == 0)
        {
            _Eos(0);
        }
        return 0 < _Newsize;
    }
    BxString& assign(const BxString& _Right, unsigned int _Roff, unsigned int _Count)
    {
        if (_Right.size() < _Roff)
        {
            _Xran();
        }
        unsigned int _Num = _Right.size() - _Roff;
        if (_Count < _Num)
        {
            _Num = _Count;
        }
        if (this == &_Right)
        {
            erase((unsigned int)(_Roff + _Num)), erase(0, _Roff);
        }
        else if (_Grow(_Num))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Right._Myptr() + _Roff, _Num);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& assign(const char* _Ptr, unsigned int _Count)
    {
        if (_Inside(_Ptr))
        {
            return assign(*this, _Ptr - _Myptr(), _Count);
        }
        if (_Grow(_Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Ptr, _Count);
            _Eos(_Count);
        }
        return *this;
    }
    BxString& assign(const char* _Ptr)
    {
        return assign(_Ptr, BxStrTraits::length(_Ptr));
    }
};
struct BxException
{
    const char* _m_what;
    int _m_doFree;
    BxException();
    BxException(const BxException& _That);
    virtual ~BxException();
    virtual const char* what() const;
};
struct BxLogicError : public BxException
{
    BxString _Str;
    explicit BxLogicError(const BxString& _Message) : _Str(_Message)
    {}
    virtual ~BxLogicError()
    {}
    virtual const char* what() const
    {
        return _Str._Myptr();
    }
};
struct BxLengthError : public BxLogicError
{
    explicit BxLengthError(const BxString& _Message) : BxLogicError(_Message)
    {}
    virtual ~BxLengthError()
    {}
};

void* FUN_00ec44d0(void* dst, const void* src, unsigned int count);
}
using namespace errac6;

// @fnv 0x00ac6430
void FUN_00ac6430(int code, BxString message)
{
    if (::DAT_011f6c88 == 0)
    {
        unsigned int uiLength = message.size();
        ::DAT_011f6c88 = code;
        if (uiLength < 0x100)
        {
        }
        else
        {
            ::ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\lastError.cpp", 0x41);
        }
        uiLength = uiLength < 0x100 ? uiLength : 0xff;
        FUN_00ec44d0((*reinterpret_cast<char (*)[256]>(&::DAT_011f6c8c)), &message[0], uiLength);
        (*reinterpret_cast<char (*)[256]>(&::DAT_011f6c8c))[uiLength] = 0;
    }
}
}

// namespace fnv_00ac6430

namespace fnv_00ac9790 {

void __cdecl FUN_00ec7c56();
namespace std {
template <class C> struct char_traits_ob1;
template <class C> class allocator_ob1;
template <class C, class Traits, class Alloc> class basic_string_ob1
{
  public:
    unsigned int allocatorState;
    union Storage
    {
        C local[16];
        C* heap;
    } storage;
    unsigned int length, capacity;
    basic_string_ob1(const C*);
    basic_string_ob1(const basic_string_ob1& other)
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(false, 0);
        assign(other, 0, ::g_010173f0);
    }
    ~basic_string_ob1();
    basic_string_ob1& assign(const basic_string_ob1&, unsigned int, unsigned int);
    static const unsigned int npos;
    const C* c_str() const
    {
        return capacity >= 16 ? storage.heap : storage.local;
    }

  protected:
    void _Tidy(bool, unsigned int);
};
typedef basic_string_ob1<char, char_traits_ob1<char>, allocator_ob1<char> > string;
template <class T> class vector
{
  public:
    unsigned int unk00, unk04, unk08;
    T* first;
    T* last;
    T* capacity;
    unsigned int size() const
    {
        return last - first;
    }
    const T& operator[](unsigned int index) const
    {
        {
            if (!(index < size()))
            {
                {
                    FUN_00ec7c56();
                }
            }
        }
        return first[index];
    }
};
class ios_base
{
  public:
    virtual ~ios_base();
    unsigned int standardStream;
    int state, exceptions, format, precision, width;
    void* values;
    void* callbacks;
    void* locale;
    int rdstate() const
    {
        return state;
    }
    bool fail() const
    {
        return (rdstate() & 6) != 0;
    }
};
template <class C, class Traits> class basic_streambuf
{
  public:
    virtual ~basic_streambuf();
    unsigned int lock;
    C *readBegin, *writeBegin;
    C **readBeginRef, **writeBeginRef;
    C *readNext, *writeNext;
    C **readNextRef, **writeNextRef;
    int readCount, writeCount;
    int *readCountRef, *writeCountRef;
    void* locale;
};
template <class C, class Traits> class basic_ostream;
template <class C, class Traits> class basic_ios : public ios_base
{
  public:
    virtual ~basic_ios();
    basic_streambuf<C, Traits>* buffer;
    basic_ostream<C, Traits>* tiedStream;
    C fill;
    void setstate(int, bool = false);
};
template <class C, class Traits> class basic_ostream : virtual public basic_ios<C, Traits>
{
  public:
    virtual ~basic_ostream();
    basic_ostream(basic_streambuf<C, Traits>*, bool = false);
    basic_ostream& put(C);
    basic_ostream& flush();
};
typedef basic_ostream<char, char_traits_ob1<char> > ostream;
template <class C, class Traits> class basic_filebuf : public basic_streambuf<C, Traits>
{
  public:
    void* codec;
    C putback;
    bool wrote;
    int conversionState;
    bool ownsFile;
    void* file;
    basic_filebuf();
    basic_filebuf* open(const char*, int, int);
    bool _Endwrite();
    void _Init(void*, int);
    basic_filebuf* close()
    {
        basic_filebuf* answer = this;
        void* stream = file;
        if (stream == 0)
            answer = 0;
        else
        {
            if (!_Endwrite())
                answer = 0;
            if (fclose((FILE*)stream) != 0)
                answer = 0;
        }
        _Init(0, 2);
        return answer;
    }
};
template <class C, class Traits = char_traits_ob1<C> > class basic_ofstream : public basic_ostream<C, Traits>
{
  public:
    basic_ofstream(const char* name, int mode, int prot) : basic_ostream<C, Traits>(&fileBuffer)
    {
        const char* filename = name;
        int openMode = mode | 2;
        int protection = prot;
        basic_filebuf<C, Traits>* buffer = &fileBuffer;
        if (buffer->open(filename, openMode, protection) == 0)
            this->setstate(2);
    }
    virtual ~basic_ofstream();
    basic_filebuf<C, Traits> fileBuffer;
    void close()
    {
        if (((::fnv_00ac9790::std::basic_filebuf<char, ::fnv_00ac9790::std::char_traits_ob1<char>> *)(reinterpret_cast<::S_00acfb90_Class *>(&(fileBuffer))->FUN_00acfb90())) == 0)
            this->setstate(2);
    }
};
typedef basic_ofstream<char> ofstream;
}
void __cdecl FUN_00ac6430(int, std::string);
std::ostream& __cdecl FUN_00ad47f0(std::ostream&, const char*);
std::ostream& __cdecl FUN_00ad4ba0(std::ostream&, const std::string&);
extern "C" char DAT_010a3028;
// @fnv 0x00ac9790
bool __cdecl FUN_00ac9790(const std::string& path, const std::vector<std::vector<std::string> >& sections)
{
    if (sections.size() == 0)
    {
        FUN_00ac6430(11, std::string(&DAT_010a3028));
        return false;
    }
    std::ofstream output(path.c_str(), 2, 64);
    if (output.fail())
    {
        FUN_00ac6430(5, path);
        return false;
    }
    for (unsigned int i = 0; i < sections.size(); ++i)
    {
        unsigned int childCount = sections[i].size();
        for (unsigned int j = 0; j < childCount; ++j)
        {
            FUN_00ad47f0(FUN_00ad4ba0(FUN_00ad47f0(output, &DAT_01021184), sections[i][j]), &DAT_01021184);
            if (j == childCount - 1)
            {
                reinterpret_cast<::FUN_00ac9df0_Q *>(&(output))->FUN_00ac9df0(10);
                reinterpret_cast<::Ostream *>(&(output))->FUN_00aca3c0();
                reinterpret_cast<::Ostream *>(&(output))->FUN_00aca3c0();
            }
            else
            {
                FUN_00ad47f0(output, &DAT_01063cd8);
            }
        }
        if (output.fail())
        {
            FUN_00ac6430(6, path);
            output.close();
            return false;
        }
    }
    output.close();
    return true;
}
}

// namespace fnv_00ac9790


class StrFld
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    __declspec(noinline) void FUN_0044a730(bool, unsigned int);
    __declspec(noinline) void AssignSubstring(const StrFld&, unsigned int, unsigned int);
    StrFld(const StrFld& r)
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(false, 0);
        AssignSubstring(r, 0, ::g_010173f0);
    }
    ~StrFld()
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, 0);
    }
};

void StrFld::FUN_0044a730(bool, unsigned int)
{}

void StrFld::AssignSubstring(const StrFld&, unsigned int, unsigned int)
{}

class FUN_00acb310
{
  public:
    StrFld m_00;
    StrFld m_1c;
    FUN_00acb310(const StrFld& a1, const StrFld& a2);
};

// @fnv 0x00acb310
FUN_00acb310::FUN_00acb310(const StrFld& a1, const StrFld& a2) : m_00(a1), m_1c(a2)
{
    unsigned int u00;
    unsigned int u01;
    unsigned int u02;
    unsigned int u03;
    unsigned int u04;
    unsigned int u05;
    unsigned int u06;
    unsigned int u07;
    unsigned int u08;
    unsigned int u09;
    unsigned int u10;
    unsigned int u11;
    unsigned int u12;
    unsigned int u13;
    unsigned int u14;
    unsigned int u15;
    unsigned int u16;
    unsigned int u17;
    unsigned int u18;
    unsigned int u19;
    unsigned int u20;
    unsigned int u21;
    unsigned int u22;
    unsigned int u23;
    unsigned int u24;
    unsigned int u25;
    unsigned int u26;
    unsigned int u27;
    unsigned int u28;
    unsigned int u29;
    unsigned int u30;
    unsigned int u31;
    unsigned int u32;
    unsigned int u33;
    unsigned int u34;
    unsigned int u35;
    unsigned int u36;
    unsigned int u37;
    unsigned int u38;
}

struct _iobuf_ob1
{
    char* _ptr;
    int _cnt;
    char* _base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char* _tmpfname;
};


template <class _Ty> class allocatorDEB0
{
  public:
    void deallocate(_Ty* _Ptr, unsigned int)
    {
        ::operator delete(_Ptr);
    }
};

class _LockitDEB0
{
  public:
    explicit _LockitDEB0(int _Kind);
    ~_LockitDEB0();
    int _Locktype;
};

class facetDEB0
{
  public:
    virtual ~facetDEB0();
    facetDEB0* _Decref()
    {
        {
            _LockitDEB0 _Lock(0);
            if (0 < _Refs && _Refs != (unsigned int)(-1))
                --_Refs;
            return (_Refs == 0 ? this : 0);
        }
    }
    unsigned int _Refs;
};

class localeDEB0
{
  public:
    ~localeDEB0()
    {
        if (_Ptr != 0)
            delete _Ptr->_Decref();
    }
    facetDEB0* _Ptr;
};

class _MutexDEB0
{
  public:
    ~_MutexDEB0();
    void* _Mtx;
};

class basic_streambufDEB0
{
  public:
    typedef char _Elem;
    virtual ~basic_streambufDEB0()
    {
        delete _Plocale;
    }

    _Elem* eback() const
    {
        return (*_IGfirst);
    }
    _Elem* gptr() const
    {
        return (*_IGnext);
    }
    _Elem* egptr() const
    {
        return (*_IGnext + *_IGcount);
    }
    _Elem* pptr() const
    {
        return (*_IPnext);
    }
    _Elem* epptr() const
    {
        return (*_IPnext + *_IPcount);
    }
    void setg(_Elem* _First, _Elem* _Next, _Elem* _Last)
    {
        *_IGfirst = _First;
        *_IGnext = _Next;
        *_IGcount = (int)(_Last - _Next);
    }
    void _InitSB()
    {
        _IGfirst = &_Gfirst;
        _IPfirst = &_Pfirst;
        _IGnext = &_Gnext;
        _IPnext = &_Pnext;
        _IGcount = &_Gcount;
        _IPcount = &_Pcount;
        setp(0, 0);
        setg(0, 0, 0);
    }
    void _InitSB(_Elem** _Gf, _Elem** _Gn, int* _Gc, _Elem** _Pf, _Elem** _Pn, int* _Pc)
    {
        _IGfirst = _Gf;
        _IPfirst = _Pf;
        _IGnext = _Gn;
        _IPnext = _Pn;
        _IGcount = _Gc;
        _IPcount = _Pc;
    }
    void setp(_Elem* _First, _Elem* _Last)
    {
        *_IPfirst = _First;
        *_IPnext = _First;
        *_IPcount = (int)(_Last - _First);
    }

    _MutexDEB0 _Mylock;
    _Elem* _Gfirst;
    _Elem* _Pfirst;
    _Elem** _IGfirst;
    _Elem** _IPfirst;
    _Elem* _Gnext;
    _Elem* _Pnext;
    _Elem** _IGnext;
    _Elem** _IPnext;
    int _Gcount;
    int _Pcount;
    int* _IGcount;
    int* _IPcount;
    localeDEB0* _Plocale;
};

class basic_filebufDEB0 : public basic_streambufDEB0
{
  public:
    virtual ~basic_filebufDEB0()
    {
        if (_Closef)
            reinterpret_cast<::S_00acfb90_Class *>(this)->FUN_00acfb90();
    }
    enum _Initfl
    {
        _Newfl,
        _Openfl,
        _Closefl
    };
    bool _Endwrite()
    {
        if (_Pcvt == 0 || !_Wrotesome)
            return (true);
        return (false);
    }
    void _Init(struct _iobuf_ob1* _File, _Initfl _Which)
    {
        static int _Stinit;
        _Closef = _Which == _Openfl;
        _Wrotesome = false;
        _InitSB();
        if (_File != 0 && sizeof(char) == 1)
        {
            char** _Pb = (char**)&_File->_base;
            char** _Pn = (char**)&_File->_ptr;
            int* _Nr = (int*)&_File->_cnt;
            _InitSB(_Pb, _Pn, _Nr, _Pb, _Pn, _Nr);
        }
        _Myfile = _File;
        _State = _Stinit;
        _Pcvt = 0;
    }
    basic_filebufDEB0* close()
    {
        basic_filebufDEB0* _Ans = this;
        if (_Myfile == 0)
            _Ans = 0;
        else
        {
            if (!_Endwrite())
                _Ans = 0;
            if (fclose((FILE*)_Myfile) != 0)
                _Ans = 0;
        }
        _Init(0, _Closefl);
        return (_Ans);
    }
    void* _Pcvt;
    char _Mychar;
    bool _Wrotesome;
    int _State;
    bool _Closef;
    struct _iobuf_ob1* _Myfile;
};

class ios_baseDEB0
{
  public:
    virtual ~ios_baseDEB0();
    int unk04;
};

class basic_iosDEB0 : public ios_baseDEB0
{
  public:
    virtual ~basic_iosDEB0();
};

class basic_istreamDEB0 : virtual public basic_iosDEB0
{
  public:
    virtual ~basic_istreamDEB0()
    {}
    int _Chcount;
};

// std::basic_ifstream<char>::~basic_ifstream (vbase-adjusted this)
class FUN_00acc8c0 : public basic_istreamDEB0
{
  public:
    virtual ~FUN_00acc8c0();
    basic_filebufDEB0 _Filebuffer;
};

// @fnv 0x00acc8c0
FUN_00acc8c0::~FUN_00acc8c0()
{}

namespace fnv_00ad3000 {
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
extern "C" int __cdecl memmove_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
unsigned int __cdecl FUN_00ec7c56();
namespace std {
class bad_alloc_ob1
{
  public:
    bad_alloc_ob1(const char* pcMessage = "bad allocation") throw();
    virtual ~bad_alloc_ob1() throw();

  private:
    const char* m_pcWhat;
    int m_iDoFree;
};
}
struct SecureCharTag
{
};
struct CharTraits
{
    static unsigned int length(const char* pcFirst)
    {
        return strlen(pcFirst);
    }
    static char* _Copy_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memcpy_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
    static char* _Move_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memmove_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
    static void assign(char& cLeft, const char& cRight)
    {
        cLeft = cRight;
    }
};
struct TraitsHelper
{
    static SecureCharTag CharTraitsCat()
    {
        SecureCharTag kTag;
        return kTag;
    }
    static char* CopySHelper(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                             SecureCharTag)
    {
        return CharTraits::_Copy_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
    }
    static char* CopyS(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
    {
        return CopySHelper(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCat());
    }
    static char* MoveSHelper(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                             SecureCharTag)
    {
        return CharTraits::_Move_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
    }
    static char* MoveS(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
    {
        return MoveSHelper(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCat());
    }
};
inline char* AllocateChars(unsigned int ItemUpdateArray, char*)
{
    if (ItemUpdateArray <= 0)
        ItemUpdateArray = 0;
    else if (((unsigned int)(-1) / ItemUpdateArray) < sizeof(char))
        throw std::bad_alloc_ob1(0);
    return (char*)::FUN_00401000(ItemUpdateArray * sizeof(char));
}
struct CharAllocator
{
    CharAllocator()
    {}
    void deallocate(char* pcPtr, unsigned int)
    {
        ::FUN_00401030(pcPtr);
    }
    char* allocate(unsigned int ItemUpdateArray)
    {
        return AllocateChars(ItemUpdateArray, (char*)0);
    }
    unsigned int max_size() const
    {
        unsigned int ItemUpdateArray = (unsigned int)(-1) / sizeof(char);
        return 0 < ItemUpdateArray ? ItemUpdateArray : 1;
    }
};
struct StringBase
{
    static void _Xlen();
    static void _Xran();
};
struct StringVal : public StringBase
{
    StringVal(CharAllocator kAl = CharAllocator()) : m_kAlval(kAl)
    {}
    CharAllocator m_kAlval;
};
struct String : public StringVal
{
    String(const char* pcPtr) : StringVal()
    {
        _Tidy();
        assign(pcPtr);
    }
    String(const String& kRight) : StringVal(kRight.m_kAlval)
    {
        _Tidy();
        assign(kRight, 0, ::g_010173f0);
    }
    ~String()
    {
        _Tidy(true);
    }
    String& assign(const String& kRight, unsigned int uiRoff, unsigned int ItemUpdateArray)
    {
        if (kRight.size() < uiRoff)
            _Xran();
        unsigned int uiElementCount = kRight.size() - uiRoff;
        if (ItemUpdateArray < uiElementCount)
            uiElementCount = ItemUpdateArray;
        if (this == &kRight)
            erase((unsigned int)(uiRoff + uiElementCount)), erase(0, uiRoff);
        else if (_Grow(uiElementCount))
        {
            TraitsHelper::CopyS(_Myptr(), m_uiRes, kRight._Myptr() + uiRoff, uiElementCount);
            _Eos(uiElementCount);
        }
        return *this;
    }
    String& assign(const char* pcPtr, unsigned int ItemUpdateArray)
    {
        if (_Inside(pcPtr))
            return assign(*this, pcPtr - _Myptr(), ItemUpdateArray);
        if (_Grow(ItemUpdateArray))
        {
            TraitsHelper::CopyS(_Myptr(), m_uiRes, pcPtr, ItemUpdateArray);
            _Eos(ItemUpdateArray);
        }
        return *this;
    }
    String& assign(const char* pcPtr)
    {
        return assign(pcPtr, CharTraits::length(pcPtr));
    }
    String& erase(unsigned int uiOff = 0, unsigned int ItemUpdateArray = ::g_010173f0)
    {
        if (m_uiSize < uiOff)
            _Xran();
        if (m_uiSize - uiOff < ItemUpdateArray)
            ItemUpdateArray = m_uiSize - uiOff;
        if (0 < ItemUpdateArray)
        {
            TraitsHelper::MoveS(_Myptr() + uiOff, m_uiRes - uiOff, _Myptr() + uiOff + ItemUpdateArray,
                                m_uiSize - uiOff - ItemUpdateArray);
            unsigned int uiNewsize = m_uiSize - ItemUpdateArray;
            _Eos(uiNewsize);
        }
        return *this;
    }
    const char* c_str() const
    {
        if (16 <= m_uiRes)
            return m_kBx.m_pcPtr;
        return m_kBx.m_acBuf;
    }
    unsigned int size() const
    {
        return m_uiSize;
    }
    unsigned int length() const
    {
        return m_uiSize;
    }
    unsigned int max_size() const
    {
        unsigned int uiElementCount = m_kAlval.max_size();
        return uiElementCount <= 1 ? 1 : uiElementCount - 1;
    }
    const char& operator[](unsigned int uiOff) const
    {
        if (!(uiOff <= m_uiSize))
            FUN_00ec7c56();
        do
        {
        } while (0);
        return _Myptr()[uiOff];
    }
    void _Copy(unsigned int uiNewsize, unsigned int uiOldlen)
    {
        unsigned int uiNewres = uiNewsize | 15;
        if (max_size() < uiNewres)
            uiNewres = uiNewsize;
        else if (uiNewres / 3 < m_uiRes / 2 && m_uiRes <= max_size() - m_uiRes / 2)
            uiNewres = m_uiRes + m_uiRes / 2;
        char* pcPtr = 0;
        try
        {
            pcPtr = m_kAlval.allocate(uiNewres + 1);
        }
        catch (...)
        {
            uiNewres = uiNewsize;
            try
            {
                pcPtr = m_kAlval.allocate(uiNewres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < uiOldlen)
            TraitsHelper::CopyS(pcPtr, uiNewres + 1, _Myptr(), uiOldlen);
        _Tidy(true);
        m_kBx.m_pcPtr = pcPtr;
        m_uiRes = uiNewres;
        _Eos(uiOldlen);
    }
    void _Eos(unsigned int uiNewsize)
    {
        CharTraits::assign(_Myptr()[m_uiSize = uiNewsize], char());
    }
    bool _Grow(unsigned int uiNewsize, bool bTrim = false)
    {
        if (max_size() < uiNewsize)
            _Xlen();
        if (m_uiRes < uiNewsize)
            _Copy(uiNewsize, m_uiSize);
        else if (bTrim && uiNewsize < 16)
            reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, uiNewsize < m_uiSize ? uiNewsize : m_uiSize);
        else if (uiNewsize == 0)
            _Eos(0);
        return 0 < uiNewsize;
    }
    bool _Inside(const char* pcPtr)
    {
        if (pcPtr == 0 || pcPtr < _Myptr() || _Myptr() + m_uiSize <= pcPtr)
            return false;
        else
            return true;
    }
    char* _Myptr()
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    const char* _Myptr() const
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    void _Tidy(bool bBuilt = false, unsigned int uiNewsize = 0)
    {
        if (!bBuilt)
            ;
        else if (16 <= m_uiRes)
        {
            char* pcPtr = m_kBx.m_pcPtr;
            if (0 < uiNewsize)
                TraitsHelper::CopyS(m_kBx.m_acBuf, 16, pcPtr, uiNewsize);
            m_kAlval.deallocate(pcPtr, m_uiRes + 1);
        }
        m_uiRes = 15;
        _Eos(uiNewsize);
    }
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
};
extern "C" char* __cdecl strcpy(char* pcDst, const char* pcSrc);
struct FUN_00ad3000
{
    String first;
    String second;
    FUN_00ad3000(const FUN_00ad3000& kRight);
};

// @fnv 0x00ad3000
FUN_00ad3000::FUN_00ad3000(const FUN_00ad3000& kRight) : first(kRight.first), second(kRight.second)
{}
}

// namespace fnv_00ad3000

namespace fnv_00ad3e60 {
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
extern "C" int __cdecl memmove_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
unsigned int __cdecl FUN_00ec7c56();
namespace std {
class bad_alloc_ob1
{
  public:
    bad_alloc_ob1(const char* pcMessage = "bad allocation") throw();
    virtual ~bad_alloc_ob1() throw();

  private:
    const char* m_pcWhat;
    int m_iDoFree;
};
}
struct SecureCharTag
{
};
struct CharTraits
{
    static unsigned int length(const char* pcFirst)
    {
        return strlen(pcFirst);
    }
    static char* _Copy_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memcpy_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
    static char* _Move_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memmove_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
    static void assign(char& cLeft, const char& cRight)
    {
        cLeft = cRight;
    }
};
struct TraitsHelper
{
    static SecureCharTag CharTraitsCat()
    {
        SecureCharTag kTag;
        return kTag;
    }
    static char* CopySHelper(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                             SecureCharTag)
    {
        return CharTraits::_Copy_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
    }
    static char* CopyS(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
    {
        return CopySHelper(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCat());
    }
    static char* MoveSHelper(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                             SecureCharTag)
    {
        return CharTraits::_Move_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
    }
    static char* MoveS(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
    {
        return MoveSHelper(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCat());
    }
};
inline char* AllocateChars(unsigned int ItemUpdateArray, char*)
{
    if (ItemUpdateArray <= 0)
        ItemUpdateArray = 0;
    else if (((unsigned int)(-1) / ItemUpdateArray) < sizeof(char))
        throw std::bad_alloc_ob1(0);
    return (char*)::FUN_00401000(ItemUpdateArray * sizeof(char));
}
struct CharAllocator
{
    CharAllocator()
    {}
    void deallocate(char* pcPtr, unsigned int)
    {
        ::FUN_00401030(pcPtr);
    }
    char* allocate(unsigned int ItemUpdateArray)
    {
        return AllocateChars(ItemUpdateArray, (char*)0);
    }
    unsigned int max_size() const
    {
        unsigned int ItemUpdateArray = (unsigned int)(-1) / sizeof(char);
        return 0 < ItemUpdateArray ? ItemUpdateArray : 1;
    }
};
struct StringBase
{
    static void _Xlen();
    static void _Xran();
};
struct StringVal : public StringBase
{
    StringVal(CharAllocator kAl = CharAllocator()) : m_kAlval(kAl)
    {}
    CharAllocator m_kAlval;
};
struct String : public StringVal
{
    String(const char* pcPtr) : StringVal()
    {
        _Tidy();
        assign(pcPtr);
    }
    String(const String& kRight) : StringVal(kRight.m_kAlval)
    {
        _Tidy();
        assign(kRight, 0, ::g_010173f0);
    }
    ~String()
    {
        _Tidy(true);
    }
    String& assign(const String& kRight, unsigned int uiRoff, unsigned int ItemUpdateArray)
    {
        if (kRight.size() < uiRoff)
            _Xran();
        unsigned int uiElementCount = kRight.size() - uiRoff;
        if (ItemUpdateArray < uiElementCount)
            uiElementCount = ItemUpdateArray;
        if (this == &kRight)
            erase((unsigned int)(uiRoff + uiElementCount)), erase(0, uiRoff);
        else if (_Grow(uiElementCount))
        {
            TraitsHelper::CopyS(_Myptr(), m_uiRes, kRight._Myptr() + uiRoff, uiElementCount);
            _Eos(uiElementCount);
        }
        return *this;
    }
    String& assign(const char* pcPtr, unsigned int ItemUpdateArray)
    {
        if (_Inside(pcPtr))
            return assign(*this, pcPtr - _Myptr(), ItemUpdateArray);
        if (_Grow(ItemUpdateArray))
        {
            TraitsHelper::CopyS(_Myptr(), m_uiRes, pcPtr, ItemUpdateArray);
            _Eos(ItemUpdateArray);
        }
        return *this;
    }
    String& assign(const char* pcPtr)
    {
        return assign(pcPtr, CharTraits::length(pcPtr));
    }
    String& erase(unsigned int uiOff = 0, unsigned int ItemUpdateArray = ::g_010173f0)
    {
        if (m_uiSize < uiOff)
            _Xran();
        if (m_uiSize - uiOff < ItemUpdateArray)
            ItemUpdateArray = m_uiSize - uiOff;
        if (0 < ItemUpdateArray)
        {
            TraitsHelper::MoveS(_Myptr() + uiOff, m_uiRes - uiOff, _Myptr() + uiOff + ItemUpdateArray,
                                m_uiSize - uiOff - ItemUpdateArray);
            unsigned int uiNewsize = m_uiSize - ItemUpdateArray;
            _Eos(uiNewsize);
        }
        return *this;
    }
    const char* c_str() const
    {
        if (16 <= m_uiRes)
            return m_kBx.m_pcPtr;
        return m_kBx.m_acBuf;
    }
    unsigned int size() const
    {
        return m_uiSize;
    }
    unsigned int length() const
    {
        return m_uiSize;
    }
    unsigned int max_size() const
    {
        unsigned int uiElementCount = m_kAlval.max_size();
        return uiElementCount <= 1 ? 1 : uiElementCount - 1;
    }
    const char& operator[](unsigned int uiOff) const
    {
        if (!(uiOff <= m_uiSize))
            FUN_00ec7c56();
        do
        {
        } while (0);
        return _Myptr()[uiOff];
    }
    void _Copy(unsigned int uiNewsize, unsigned int uiOldlen)
    {
        unsigned int uiNewres = uiNewsize | 15;
        if (max_size() < uiNewres)
            uiNewres = uiNewsize;
        else if (uiNewres / 3 < m_uiRes / 2 && m_uiRes <= max_size() - m_uiRes / 2)
            uiNewres = m_uiRes + m_uiRes / 2;
        char* pcPtr = 0;
        try
        {
            pcPtr = m_kAlval.allocate(uiNewres + 1);
        }
        catch (...)
        {
            uiNewres = uiNewsize;
            try
            {
                pcPtr = m_kAlval.allocate(uiNewres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < uiOldlen)
            TraitsHelper::CopyS(pcPtr, uiNewres + 1, _Myptr(), uiOldlen);
        _Tidy(true);
        m_kBx.m_pcPtr = pcPtr;
        m_uiRes = uiNewres;
        _Eos(uiOldlen);
    }
    void _Eos(unsigned int uiNewsize)
    {
        CharTraits::assign(_Myptr()[m_uiSize = uiNewsize], char());
    }
    bool _Grow(unsigned int uiNewsize, bool bTrim = false)
    {
        if (max_size() < uiNewsize)
            _Xlen();
        if (m_uiRes < uiNewsize)
            _Copy(uiNewsize, m_uiSize);
        else if (bTrim && uiNewsize < 16)
            reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, uiNewsize < m_uiSize ? uiNewsize : m_uiSize);
        else if (uiNewsize == 0)
            _Eos(0);
        return 0 < uiNewsize;
    }
    bool _Inside(const char* pcPtr)
    {
        if (pcPtr == 0 || pcPtr < _Myptr() || _Myptr() + m_uiSize <= pcPtr)
            return false;
        else
            return true;
    }
    char* _Myptr()
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    const char* _Myptr() const
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    void _Tidy(bool bBuilt = false, unsigned int uiNewsize = 0)
    {
        if (!bBuilt)
            ;
        else if (16 <= m_uiRes)
        {
            char* pcPtr = m_kBx.m_pcPtr;
            if (0 < uiNewsize)
                TraitsHelper::CopyS(m_kBx.m_acBuf, 16, pcPtr, uiNewsize);
            m_kAlval.deallocate(pcPtr, m_uiRes + 1);
        }
        m_uiRes = 15;
        _Eos(uiNewsize);
    }
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
};
extern "C" char* __cdecl strcpy(char* pcDst, const char* pcSrc);
struct Named_ad3e
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    String m_kName;
};

struct NameHolder_ad3e
{
    Named_ad3e* m_pkNamed;
    String FUN_00ad3e60() const;
};

// @fnv 0x00ad3e60
String NameHolder_ad3e::FUN_00ad3e60() const
{
    return m_pkNamed->m_kName;
}
}

// namespace fnv_00ad3e60

union BxQ_ad6bb0
{
    char _Buf[16];
    char* _Ptr;
};

struct AlQ_ad6bb0
{
};

inline bool operator==(const AlQ_ad6bb0&, const AlQ_ad6bb0&)
{
    return true;
}

template <class T> inline void Swap_ad6bb0(T& _Left, T& _Right)
{
    T _Tmp = _Left;
    _Left = _Right;
    _Right = _Tmp;
}

struct StrQ_ad6bb0
{
    AlQ_ad6bb0 _Alval;
    BxQ_ad6bb0 _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    void _Tidy(bool _Built, unsigned int _Newsize);
    StrQ_ad6bb0& assign(const StrQ_ad6bb0& _Right, unsigned int _Roff, unsigned int _Count);
    StrQ_ad6bb0(const StrQ_ad6bb0& _Right)
    {
        int _D0;
        int _D1;
        int _D2;
        int _D3;
        int _D4;
        int _D5;
        int _D6;
        int _D7;
        int _D8;
        int _D9;
        int _D10;
        int _D11;
        int _D12;
        int _D13;
        int _D14;
        int _D15;
        int _D16;
        int _D17;
        int _D18;
        int _D19;
        int _D20;
        int _D21;
        int _D22;
        int _D23;
        int _D24;
        int _D25;
        int _D26;
        int _D27;
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(false, 0);
        assign(_Right, 0, ::g_010173f0);
    }
    StrQ_ad6bb0& operator=(const StrQ_ad6bb0& _Right)
    {
        return assign(_Right, 0, ::g_010173f0);
    }
    ~StrQ_ad6bb0()
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, 0);
    }
    void FUN_00ad6bb0(StrQ_ad6bb0& _Right);
};

// @fnv 0x00ad6bb0
void StrQ_ad6bb0::FUN_00ad6bb0(StrQ_ad6bb0& _Right)
{
    if (this == &_Right)
        ;
    else if (_Alval == _Right._Alval)
    {
        BxQ_ad6bb0 _Tbx = _Bx;
        _Bx = _Right._Bx, _Right._Bx = _Tbx;
        unsigned int _Tsize = _Mysize;
        _Mysize = _Right._Mysize, _Right._Mysize = _Tsize;
        unsigned int _Tres = _Myres;
        _Myres = _Right._Myres, _Right._Myres = _Tres;
    }
    else
    {
        StrQ_ad6bb0 _Tmp = *this;
        *this = _Right;
        _Right = _Tmp;
    }
}


extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);

extern "C" int __cdecl memmove_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);

namespace std {}

extern "C" char* __cdecl strcpy(char* pcDst, const char* pcSrc);

struct IdName_ac34
{
    int m_iId;
    String m_kName;
};

// @fnv 0x00ac34c0
void __cdecl FUN_00ac34c0(IdName_ac34* pPtr, const IdName_ac34& kVal)
{
    void* pvPtr = pPtr;
    ::new (pvPtr) IdName_ac34(kVal);
}


extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);

extern "C" int __cdecl memmove_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);

namespace std {}

extern "C" char* __cdecl strcpy(char* pcDst, const char* pcSrc);

struct Point3_b2e7
{
    float x;
    float y;
    float z;
};

struct FUN_00b2e740
{
    bool m_bEnableState;
    Point3_b2e7 m_kPathOffset;
    float m_fBoundRadius;
    String m_kName;
    Point3_b2e7 m_kPoint1;
    Point3_b2e7 m_kPoint2;
    Point3_b2e7 m_kPoint3;

    FUN_00b2e740(const FUN_00b2e740& kOther);
};

// @fnv 0x00b2e740
FUN_00b2e740::FUN_00b2e740(const FUN_00b2e740& kOther)
    : m_bEnableState(kOther.m_bEnableState), m_kPathOffset(kOther.m_kPathOffset), m_fBoundRadius(kOther.m_fBoundRadius),
      m_kName(kOther.m_kName), m_kPoint1(kOther.m_kPoint1), m_kPoint2(kOther.m_kPoint2), m_kPoint3(kOther.m_kPoint3)
{}

struct SubObj0C
{
    void FUN_00ad3000(int v);
};

static __forceinline void Dead9()
{
    int aiD[9];
}

struct Entry48
{
    int unk00;
    int unk04;
    int unk08;
    SubObj0C unk0C;
    int unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    bool unk44;
    bool unk45;
    inline Entry48(int a, int b, int c, int d, bool e)
    {
        unk00 = a;
        unk04 = b;
        unk08 = c;
        unk0C.FUN_00ad3000(d);
        unk44 = e;
        unk45 = false;
        Dead9();
    }
};

struct Owner_ob1
{
    Entry48* FUN_00ad1960(int a, int b, int c, int d, bool e);
};

// @fnv 0x00ad1960
Entry48* Owner_ob1::FUN_00ad1960(int a, int b, int c, int d, bool e)
{
    void* mem = ((void *)(::FUN_00ad5370(1, (::AllocElem48 *)(0))));

    try
    {
        new (mem) Entry48(a, b, c, d, e);
    }
    catch (...)
    {
        FUN_00401030(mem);
        throw;
    }
    return (Entry48*)mem;
}

extern "C" void* __cdecl FUN_00ec9a47(const char* name, const char* mode);

struct PadStr : StrFld
{
    PadStr(const PadStr& r) : StrFld(r)
    {
        int dqb[4];
    }
};

void __cdecl FUN_00ac6430(int iLevel, PadStr kMsg);

inline FileString::~FileString()
{
    reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, 0);
}

static inline const char* FsC(const FileString& s)
{
    return s.capacity >= 16 ? s.storage.pointer : s.storage.buffer;
}

static inline unsigned FsLen(const FileString& s)
{
    return s.length;
    int dql[4];
}

static __forceinline void Pad()
{
    int dq[17];
}

// @fnv 0x00ac4910
bool FileReader::FUN_00ac4910(FileString kPath)
{
    reinterpret_cast<::FUN_00ac5430_cls *>((((GvBinaryFile*)this)))->FUN_00ac5430();
    ((GvBinaryFile*)this)->pFile =
        (GvFileHandle*)FUN_00ec9a47(kPath.capacity >= 16 ? kPath.storage.pointer : kPath.storage.buffer, "wb");
    if (!((GvBinaryFile*)this)->pFile)
    {
        FUN_00ac6430(5, *(PadStr*)&kPath);
        return false;
    }
    if (!((GvBinaryFile*)this)->FUN_00ac5220(FsC(signature), FsLen(signature), true))
    {
        FUN_00ac6430(5, *(PadStr*)&kPath);
        reinterpret_cast<::FUN_00ac5430_cls *>((((GvBinaryFile*)this)))->FUN_00ac5430();
        return false;
        Pad();
    }
    fileName.AssignSubstring(kPath, 0, ::g_010173f0);
    return true;
}

struct CopyStr
{
    void* al;
    union
    {
        char buf[16];
        char* ptr;
    } bx;
    unsigned size;
    unsigned res;
    CopyStr& AssignSubstring(const CopyStr& r, unsigned off, unsigned n);
    CopyStr(const CopyStr& r)
    {
        int aiD[26];
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(false, 0);
        AssignSubstring(r, 0, ::g_010173f0);
    }
};

// @fnv 0x00ad6990
void FUN_00ad6990(CopyStr* ptr, const CopyStr& val)
{
    void* vptr = ptr;
    ::new (vptr) CopyStr(val);
}

struct StringAssignmentOps
{
    bool FUN_0044a8d0(unsigned int, bool);
    char* FUN_0044a970();
    void ResizeString(unsigned int);
    GameString& EraseRange(unsigned int, unsigned int);
};

struct InsertText : BxStringVal
{
    BxQ_ad6bb0 storage;
    unsigned int length, capacity;
    InsertText(const InsertText& rhs) : BxStringVal(rhs)
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(false, 0);
        assign(rhs, 0, ~0u);
    }
    ~InsertText()
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, 0);
    }
    InsertText& operator=(const InsertText& rhs)
    {
        return assign(rhs, 0, ~0u);
    }
    unsigned int size() const
    {
        return length;
    }
    char* data()
    {
        return 16 <= capacity ? storage._Ptr : storage._Buf;
    }
    void eos(unsigned int newSize)
    {
        std::char_traits_ob1<char>::assign(data()[length = newSize], char());
    }
    void FUN_0044a730(bool built, unsigned int newSize)
    {
        if (!built)
            ;
        else if (16 <= capacity)
        {
            char* ptr = storage._Ptr;
            if (0 < newSize)
                std::_Traits_helper::copy_s<std::char_traits_ob1<char> >(storage._Buf, 16, ptr, newSize);
            BxCharAlloc& al = _Alval;
            al.deallocate(ptr, capacity + 1);
        }
        capacity = 15;
        eos(newSize);
    }
    InsertText& assign(const InsertText& right, unsigned int off, unsigned int count)
    {
        unsigned int sourceSize = right.size();
        if (sourceSize < off)
            StringBase::_Xran();
        unsigned int num = sourceSize - off;
        if (count < num)
            num = count;
        if (this == &right)
        {
            reinterpret_cast<StringAssignmentOps*>(this)->EraseRange(off + num, ~0u);
            reinterpret_cast<StringAssignmentOps*>(this)->EraseRange(0, off);
        }
        else if (reinterpret_cast<StringAssignmentOps*>(this)->FUN_0044a8d0(num, false))
        {
            char* destination = reinterpret_cast<StringAssignmentOps*>(this)->FUN_0044a970();
            const char* source =
                reinterpret_cast<StringAssignmentOps*>(const_cast<InsertText*>(&right))->FUN_0044a970() + off;
            unsigned int destinationCapacity = capacity;
            ::FUN_0044ccd0(destination, destinationCapacity, source, num);
            reinterpret_cast<StringAssignmentOps*>(this)->ResizeString(num);
        }
        return *this;
    }
};

struct MM
{
};

extern const char DAT_010173c4[];

struct ErrorText
{
    unsigned char allocator_ob1;
    union
    {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length, capacity;
    explicit ErrorText(const char*);
    ~ErrorText();
};

struct InsertionLengthError
{
    virtual ~InsertionLengthError();
    const char* message;
    bool ownsMessage;
    ErrorText detail;
    explicit InsertionLengthError(const ErrorText&);
};

inline void __cdecl ThrowVectorTooLong()
{
    throw InsertionLengthError(ErrorText(DAT_010173c4));
}

struct InsertItem;

struct InsertionSource
{
    const InsertItem* value;
};

struct InsertItem
{
    unsigned int kind;
    struct Coordinates
    {
        unsigned int x, y, z;
    } coordinates;
    InsertText text;
    InsertItem(InsertionSource rhs) : text(rhs.value->text)
    {
        const Coordinates& source = rhs.value->coordinates;
        Coordinates& destination = coordinates;
        unsigned int copiedKind = rhs.value->kind;
        unsigned int copiedX = source.x;
        unsigned int copiedY = source.y;
        unsigned int copiedZ = source.z;
        kind = copiedKind;
        destination.x = copiedX;
        destination.y = copiedY;
        destination.z = copiedZ;
    }
};

namespace wrac52 {
template <> struct GvAlloc<InsertItem>
{
  public:
    typedef InsertItem value_type;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef unsigned int size_type;
    typedef int difference_type;
    template <class U> struct rebind
    {
        typedef GvAlloc<U> other;
    };
    GvAlloc() throw()
    {}
    GvAlloc(const GvAlloc&) throw()
    {}
    template <class U> GvAlloc(const GvAlloc<U>&) throw()
    {}
    pointer address(reference x) const
    {
        return &x;
    }
    const_pointer address(const_reference x) const
    {
        return &x;
    }
    pointer allocate(size_type n, const void* = 0)
    {
        return (pointer)::FUN_0065e4c0(n);
    }
    void deallocate(pointer p, size_type)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MM *>(&::g_memoryManager))))->FUN_00aa4060(p);
    }
    void construct(pointer p, const InsertItem& v)
    {
        GvConstruct(p, v);
    }
    void destroy(pointer p)
    {
        GvDestroyOne(p);
    }
    size_type max_size() const throw()
    {
        size_type c = (size_type)(-1) / sizeof(InsertItem);
        return 0 < c ? c : 1;
    }
};
}

struct InsertMoveTag
{
};

template <class I> inline InsertMoveTag InsertMoveCat(const I&)
{
    InsertMoveTag tag;
    return tag;
}

inline void FillInsertRange(InsertItem* first, InsertItem* last, const InsertItem& value)
{
    for (; first != last; ++first)
        *first = value;
}

inline void FUN_00ac1600(InsertItem* first, InsertItem* last, const InsertItem& value)
{
    FillInsertRange(GvCheckedBase(first), GvCheckedBase(last), value);
}

extern InsertItem* __cdecl FUN_00ac1e20(InsertItem*, InsertItem*, InsertItem*, GvAlloc<InsertItem>&);

extern InsertItem* __cdecl FUN_00ac3730(InsertItem*, InsertItem*, InsertItem*, GvAlloc<InsertItem>&);

__forceinline InsertItem* DispatchInsertMove(InsertItem* f, InsertItem* l, InsertItem* d, GvAlloc<InsertItem>& a,
                                             InsertMoveTag, GvRangeCheckedTag)
{
    return FUN_00ac3730(f, l, d, a);
}
__forceinline InsertItem* PrepareInsertMove(InsertItem* f, InsertItem* l, InsertItem* d, GvAlloc<InsertItem>& a)
{
    return DispatchInsertMove(GvCheckedBase(f), GvCheckedBase(l), d, a, InsertMoveCat(d), GvRangeCheckedTag());
}

extern InsertItem* __cdecl FUN_00ac1ea0(InsertItem*, InsertItem*, InsertItem*, GvRandomTag, InsertMoveTag,
                                        GvRangeCheckedTag);

struct TextAssignment
{
    InsertText& AssignSubstring(const InsertText&, unsigned int, unsigned int);
};

inline InsertItem* __cdecl FUN_00ac1ea0(InsertItem* f, InsertItem* l, InsertItem* d, GvRandomTag, InsertMoveTag,
                                        GvRangeCheckedTag)
{
    const int length = l - f;
    InsertItem* result = d - length;
    const InsertItem* begin = f;
    const InsertItem* end = l;
    InsertItem* output = d;
    while (begin != end)
    {
        const InsertItem& source = *--end;
        --output;
        output->kind = source.kind;
        output->coordinates.x = source.coordinates.x;
        output->coordinates.y = source.coordinates.y;
        output->coordinates.z = source.coordinates.z;
        reinterpret_cast<TextAssignment*>(&output->text)->AssignSubstring(source.text, 0, ~0u);
    }
    return result;
}
__forceinline InsertItem* InsertMoveBackward(InsertItem* f, InsertItem* l, InsertItem* d)
{
    return FUN_00ac1ea0(GvCheckedBase(f), GvCheckedBase(l), d, GvIterRandom(f, d), InsertMoveCat(d),
                        GvRangeCheckedTag());
}

struct ItemVector : GvVector<InsertItem>
{
    typedef InsertItem* pointer;
    typedef InsertItem value_type;
    typedef unsigned int size_type;
    typedef GvConstIterator<InsertItem> const_iterator;
    void FUN_0065dd90(pointer a, pointer b)
    {
        GvDestroyRange(a, b, this->_Alval);
    }
    __forceinline pointer _Umove(pointer f, pointer l, pointer d)
    {
        return PrepareInsertMove(f, l, d, this->_Alval);
    }
    pointer MoveTail(pointer f, pointer l, pointer d)
    {
        return FUN_00ac1e20(f, l, d, this->_Alval);
    }
    void FUN_00abeb00(const_iterator _Where, size_type _Count, InsertionSource _Val);
};

// @fnv 0x00abb3c0
void GameVector::FUN_00abb3c0(unsigned int count, GameRecord value)
{
    if (size() < count)
        reinterpret_cast<::ItemVector *>(this)->FUN_00abeb00((*(::wrac52::GvConstIterator< ::InsertItem> *)&(const ::GameConstIterator &)(end())), count - size(), (*(::InsertionSource *)&(value)));
    else if (count < size())
        func_0x00abb5f0(begin() + count, end());
}

// @fnv 0x00abeb00
void ItemVector::FUN_00abeb00(const_iterator _Where, size_type _Count, InsertionSource _Val)
{
    size_type _Capacity = capacity();
    if (_Count == 0)
        ;
    else if (max_size() - size() < _Count)
        ::fnv_0065f640::ThrowVectorTooLong();
    else if (_Capacity < size() + _Count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        pointer _Newvec = this->_Alval.allocate(_Capacity);
        pointer _Ptr = _Newvec;
        try
        {
            _Ptr = _Umove(this->_Myfirst, _Where._Myptr, _Newvec);
            _Ptr = _Ufill(_Ptr, _Count, *_Val.value);
            MoveTail(_Where._Myptr, this->_Mylast, _Ptr);
        }
        catch (...)
        {
            reinterpret_cast<::FUN_0065dd90_Class *>(this)->FUN_0065dd90((::std::intptr_t)(_Newvec), (::std::intptr_t)(_Ptr));
            this->_Alval.deallocate(_Newvec, _Capacity);
            throw;
        }
        _Count += size();
        if (_Myfirst != 0)
        {
            reinterpret_cast<::FUN_0065dd90_Class *>(this)->FUN_0065dd90((::std::intptr_t)(_Myfirst), (::std::intptr_t)(_Mylast));
            this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myend = _Newvec + _Capacity;
        _Mylast = _Newvec + _Count;
        _Myfirst = _Newvec;
    }
    else if ((size_type)(_Mylast - _Where._Myptr) < _Count)
    {
        value_type _Tmp = *_Val.value;
        _Umove(_Where._Myptr, _Mylast, _Where._Myptr + _Count);
        try
        {
            _Ufill(_Mylast, _Count - (_Mylast - _Where._Myptr), _Tmp);
        }
        catch (...)
        {
            reinterpret_cast<::FUN_0065dd90_Class *>(this)->FUN_0065dd90((::std::intptr_t)(_Where._Myptr + _Count), (::std::intptr_t)(_Mylast + _Count));
            throw;
        }
        _Mylast += _Count;
        FUN_00ac1600(_Where._Myptr, _Mylast - _Count, _Tmp);
    }
    else
    {
        value_type _Tmp(_Val);
        pointer _Oldend = _Mylast;
        _Mylast = MoveTail(_Oldend - _Count, _Oldend, _Mylast);
        InsertMoveBackward(_Where._Myptr, _Oldend - _Count, _Oldend);
        FUN_00ac1600(_Where._Myptr, _Where._Myptr + _Count, _Tmp);
    }
}

extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);

bool CanOpenFile(const String& path);

String FUN_00ad4210(const String&, const char*);

String FUN_00ad42e0(const String&, const String&);

inline String& updateCandidate(String& destination, const String& source)
{
    return destination.assign(source, 0, ::g_010173f0);
}

// @fnv 0x00ac6fa0
String FUN_00ac6fa0(const String& directory, const String& baseName, const String& extension)
{
    String candidateName = FUN_00ad42e0(FUN_00ad4210(baseName, "."), extension);
    int retryIndex = 0;
    while (CanOpenFile(FUN_00ad42e0(directory, candidateName)))
    {
        char number[12];
        sprintf(number, "%d", ++retryIndex);
        updateCandidate(candidateName, FUN_00ad42e0(FUN_00ad4210(FUN_00ad4210(baseName, number), "."), extension));
    }
    return candidateName;
}

class FUN_0044a4c0 : public BxStringVal
{
  public:
    BxQ_ad6bb0 storage;
    unsigned int length, capacity;
    FUN_0044a4c0() : BxStringVal()
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(false, 0);
    }
    explicit FUN_0044a4c0(const char* s) : BxStringVal()
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(false, 0);
        reinterpret_cast<BxString*>(this)->assign(s);
    }
    FUN_0044a4c0(const FUN_0044a4c0& right) : BxStringVal(right)
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(false, 0);
        reinterpret_cast<BxString*>(this)->assign(reinterpret_cast<const BxString&>(right), 0, ::g_010173f0);
    }
    ~FUN_0044a4c0()
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, 0);
    }
    char* data()
    {
        return 16 <= capacity ? storage._Ptr : storage._Buf;
    }
    void endString(unsigned int n)
    {
        BxStrTraits::assign(data()[length = n], char());
    }
    void FUN_0044a730(bool built, unsigned int n)
    {
        if (!built)
            ;
        else if (16 <= capacity)
        {
            char* old = storage._Ptr;
            if (0 < n)
                BxTraitsHelper::copy_s<BxStrTraits>(storage._Buf, 16, old, n);
            _Alval.deallocate(old, capacity + 1);
        }
        capacity = 15;
        endString(n);
    }
    unsigned int size() const
    {
        return length;
    }
    const char* data() const
    {
        return 16 <= capacity ? storage._Ptr : storage._Buf;
    }
    int FUN_00ac9da0(const FUN_0044a4c0& right) const
    {
        return reinterpret_cast<::FUN_00ac6100_cls *>((void *)this)->FUN_00ac6100(0, length, (::std::intptr_t)(right.data()), right.size());
    }
    int FUN_00ac6100(unsigned int off, unsigned int count, const char* text, unsigned int size) const
    {
        if (length < off)
            StringBase::_Xran();
        if (length - off < count)
            count = length - off;
        unsigned int comparison = BxStrTraits::compare(data() + off, text, count < size ? count : size);
        return comparison != 0 ? (int)comparison : count < size ? -1 : count == size ? 0 : 1;
    }
    int compare(const char* s) const
    {
        return reinterpret_cast<::FUN_00ac6100_cls *>((void *)this)->FUN_00ac6100(0, length, (::std::intptr_t)(s), BxStrTraits::length(s));
    }
};

inline bool operator==(const FUN_0044a4c0& a, const FUN_0044a4c0& b)
{
    return a.FUN_00ac9da0(b) == 0;
}

inline bool operator==(const FUN_0044a4c0& a, const char* b)
{
    return a.compare(b) == 0;
}

inline bool operator!=(const FUN_0044a4c0& a, const char* b)
{
    return !(a == b);
}

class ParserCtype : public facetDEB0
{
  public:
    virtual void facetSlot1();
    virtual void facetSlot2();
    virtual void facetSlot3();
    virtual void facetSlot4();
    virtual void facetSlot5();
    virtual char do_widen(char) const;
    char widen(char ch) const
    {
        return do_widen(ch);
    }
};

extern const ParserCtype& __cdecl ParserUseFacet(const localeDEB0&);

class ParserIos : public basic_iosDEB0
{
  public:
    int state;
    int rdstate() const
    {
        return state;
    }
    bool eof() const
    {
        return rdstate() & 1;
    }
    bool fail() const
    {
        return (rdstate() & 6) != 0;
    }
    localeDEB0 GetLocale() const;
    char FUN_00ad30c0(char ch) const
    {
        const ParserCtype& facet = ParserUseFacet(GetLocale());
        return facet.widen(ch);
    }
};

class ParserStream : virtual public ParserIos
{
  public:
    virtual ~ParserStream();
    int count;
};

extern ParserStream& __cdecl FUN_00ad43a0(ParserStream&, FUN_0044a4c0&);

inline ParserStream& ReadParserLine(ParserStream& stream, FUN_0044a4c0& value)
{
    return (*(::ParserStream *)&(::fnv_00ad5770::FUN_00ad5770((::fnv_00ad5770::FUN_00ad5770_Q &)(stream), (::fnv_00ad5770::StrQ &)(value), reinterpret_cast<::GvIos *>((void *)&(stream))->FUN_00ad30c0('\n'))));
}

namespace pairparser {
struct FUN_00acb310
{
    FUN_0044a4c0 first, second;
    FUN_00acb310(const FUN_0044a4c0& a, const FUN_0044a4c0& b) : first(a), second(b)
    {}
};
}

struct ParserPairs : GvVector<pairparser::FUN_00acb310>
{
    void FUN_00acb3c0(const pairparser::FUN_00acb310& value)
    {
        if (size() < capacity())
            _Mylast = _Ufill(_Mylast, 1, value);
        else
            insert(end(), value);
    }
};

// @fnv 0x00ac7f50
bool __cdecl FUN_00ac7f50(ParserStream* stream, ParserPairs* result, const FUN_0044a4c0* excluded, int limit)
{
    FUN_0044a4c0 key;
    int entries = 0;
    while (!stream->eof() && !stream->fail() && (!limit || entries < limit))
    {
        FUN_00ad43a0(*stream, key);
        if (stream->eof() || stream->fail())
            break;
        char next;
        while (!stream->eof() && !stream->fail())
        {
            next = reinterpret_cast<::fnv_00aca7a0::FUN_00aca7a0_Q *>((stream))->FUN_00aca7a0();
            if (next == '\n' || stream->eof() || stream->fail())
                break;
            else if (next == ' ' || next == '\t')
                next = reinterpret_cast<::fnv_00aca560::FUN_00aca560_Q *>((stream))->FUN_00aca560();
            else
                break;
        }
        FUN_0044a4c0 value("");
        if (!stream->eof() && !stream->fail())
            ReadParserLine(*stream, value);
        if (key == *excluded && *excluded != "")
            continue;
        reinterpret_cast<::VecQ_acb3c0 *>((result))->FUN_00acb3c0((const ::S00ad5bd0_Elem &)((const ::pairparser::FUN_00acb310 &)(pairparser::FUN_00acb310(key, value))));
        ++entries;
    }
    if (stream->fail() && !stream->eof())
        return false;
    else
        return true;
}

namespace ac8parse {
template <class T> struct char_traits_ob1
{
    static unsigned length(const T* p)
    {
        return strlen(p);
    }
    static T* _Copy_s(T*, unsigned, const T*, unsigned);
    static void assign(T&, const T&);
};
template <class T> struct _Allocator_base
{
};
template <class T> class allocator_ob1 : public _Allocator_base<T>
{
  public:
    allocator_ob1() throw()
    {}
    allocator_ob1(const allocator_ob1&) throw()
    {}
};
class _Container_base_secure
{
};
class _String_base : public _Container_base_secure
{
};
template <class T, class A> class _String_val : public _String_base
{
  protected:
    _String_val(A al = A()) : allocatorValue(al)
    {}
    _String_val(const _String_val& other) : allocatorValue(other.allocatorValue)
    {}
    A allocatorValue;
};
template <class E, class T, class A> class basic_string_ob1 : public _String_val<E, A>
{
    typedef _String_val<E, A> Base;

  public:
    union Storage
    {
        E buf[16];
        E* ptr;
    } storage;
    unsigned len, res;
    int FUN_00ac9da0(const basic_string_ob1&) const;

    basic_string_ob1(const E* p) : Base()
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(false, 0);
        assign(p);
    }
    basic_string_ob1& assign(const E* p)
    {
        return assign(p, T::length(p));
    }
    basic_string_ob1& assign(const E* p, unsigned n)
    {
        if (_Inside(p))
            return AssignSubstring(*this, unsigned(p - _Myptr()), n);
        if (_Grow(n, false))
        {
            T::_Copy_s(_Myptr(), res, p, n);
            _Eos(n);
        }
        return *this;
    }
    bool _Inside(const E*);
    bool _Grow(unsigned, bool);
    E* _Myptr()
    {
        return 16 <= res ? storage.ptr : storage.buf;
    }
    void _Eos(unsigned n)
    {
        const E zero = E();
        len = n;
        T::assign(_Myptr()[n], zero);
    }
    inline basic_string_ob1() : Base()
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(false, 0);
    }
    inline basic_string_ob1(const basic_string_ob1& r) : Base(r)
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(false, 0);
        AssignSubstring(r, 0, ::g_010173f0);
    }
    inline ~basic_string_ob1()
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, 0);
    }
    const E* c_str() const
    {
        return 16 <= res ? storage.ptr : storage.buf;
    }
    basic_string_ob1& AssignSubstring(const basic_string_ob1&, unsigned, unsigned);

  protected:
    void FUN_0044a730(bool, unsigned);
};
typedef basic_string_ob1<char, char_traits_ob1<char>, allocator_ob1<char> > string;
}
using namespace ac8parse;

namespace ac8parse {
typedef string Str;
inline bool operator==(const Str& a, const Str& b)
{
    return a.FUN_00ac9da0(b) == 0;
}
inline bool operator!=(const Str& a, const Str& b)
{
    return !(a == b);
}
void FUN_00ec7c56();  // -> 0x00ec7c56  (_invalid_parameter)

struct Tok
{
    Str a, b;
    Tok();
};
struct Vec
{
    unsigned allocatorProxy;
    unsigned iteratorProxy;
    unsigned unk08;
    Tok* first;
    Tok* last;
    Tok* end;
    void FUN_00acf580(unsigned, Tok);
    inline void resize(unsigned n)
    {
        FUN_00acf580(n, Tok());
    }
    inline Tok& operator[](unsigned i)
    {
        if (!(i < (unsigned)(last - first)))
            ac8parse::FUN_00ec7c56();
        return first[i];
    }
};
struct Big;
struct VB
{  // virtual base at Big+0x58
    VB();
    virtual ~VB();
    unsigned unk04;
    int flags;
    unsigned unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    int rdstate() const
    {
        return flags;
    }
    bool fail() const
    {
        return (rdstate() & 6) != 0;
    }
    void FUN_00acc8c0();
    void FUN_00aca4b0();
};
struct FileBuf
{
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38,
        unk3c, unk40, unk44, unk48, unk4c;
    FileBuf();
    ~FileBuf();
    FileBuf* Open(const char*, int, int);
};
struct Input : virtual VB
{
    unsigned count;
    Input(FileBuf*);
    virtual ~Input()
    {}
};
struct Big : Input
{
    FileBuf buffer;
    void Init(FileBuf*, bool);
    void SetState(int);
    Big(const char* filename, int mode, int prot) : Input(&buffer)
    {
        if (!buffer.Open(filename, mode | 1, prot))
            SetState(2);
    }
    virtual ~Big()
    {}
};

void FUN_00ac6430(int, Str);  // -> 0x00ac6430  SetError(int, string)

}

// @fnv 0x00ac8c50
bool FUN_00ac8c50(const Str& name, const Str& arg2, ac8parse::Vec* pVec)
{
    Str msg5;
    Big kObj(name.c_str(), 1, 0x40);
    if (kObj.fail())
    {
        ac8parse::FUN_00ac6430(4, name);
        return false;
    }
    pVec->resize(0);
    if (!::FUN_00ac7f50((::ParserStream *)(::ac8parse::Big *)(&kObj), (::ParserPairs *)(pVec), (const ::FUN_0044a4c0 *)&(const ::ac8parse::basic_string_ob1<char, ::ac8parse::char_traits_ob1<char>, ::ac8parse::allocator_ob1<char>> &)("//"), 1))
    {
        ac8parse::FUN_00ac6430(4, name);
        return false;
    }
    if ((*pVec)[0].a != arg2)
    {
        ac8parse::FUN_00ac6430(2, name);
        return false;
    }
    pVec->resize(0);
    if (!::FUN_00ac7f50((::ParserStream *)(::ac8parse::Big *)(&kObj), (::ParserPairs *)(pVec), (const ::FUN_0044a4c0 *)&(const ::ac8parse::basic_string_ob1<char, ::ac8parse::char_traits_ob1<char>, ::ac8parse::allocator_ob1<char>> &)("//"), 0))
    {
        ac8parse::FUN_00ac6430(4, name);
        return false;
    }
    else
    {
        return true;
    }
}

extern bool __cdecl CanOpenFile(void*);

template <> __declspec(noinline) GvAuxBase<GvAlloc<BxString> >::~GvAuxBase()
{
    _Myownedaux->~GvAuxCont();
    _Alaux.deallocate(_Myownedaux, 1);
}

template <class T> struct CsvArray : GvVector<T>
{
};

typedef CsvArray<BxString> CsvRow;

namespace std {
class ios_base
{
  public:
    virtual ~ios_base()
    {
        FUN_00ec3205(this);
    }
    static void __cdecl FUN_00ec3205(ios_base*);
    unsigned int standardStream;
    int state, exceptions, format, precision, width;
    void* array;
    void* callbacks;
    localeDEB0* locale;
    int rdstate() const
    {
        return state;
    }
    bool eof() const
    {
        return (int)rdstate() & 1;
    }
    bool fail() const
    {
        return ((int)rdstate() & (4 | 2)) != 0;
    }
    localeDEB0 getloc() const
    {
        return *locale;
    }
    void setstate(int);
};
template <class E> struct CsvCtype
{
    E widen(char) const;
};
template <class E> const CsvCtype<E>& CsvUseFacet(const localeDEB0&);
template <class E, class Tr> class basic_ios : public ios_base
{
  public:
    virtual ~basic_ios()
    {}
    E FUN_00ad30c0(char c) const
    {
        const CsvCtype<E>& facet = CsvUseFacet<E>(getloc());
        return facet.widen(c);
    }
    void init(basic_streambufDEB0*, bool);
    basic_streambufDEB0* streambuf;
    void* tied;
    E fill;
};
template <class E, class Tr> class basic_istream : virtual public basic_ios<E, Tr>
{
  public:
    explicit basic_istream(basic_streambufDEB0* sb, bool isstd = false) : count(0)
    {
        this->init(sb, isstd);
    }
    virtual ~basic_istream()
    {}
    int count;
};
template <class E, class Tr> class basic_ifstream : public basic_istream<E, Tr>
{
  public:
    basic_ifstream(const char* name, int mode, int prot) : basic_istream<E, Tr>(&filebuf)
    {
        filebuf._Init(0, basic_filebufDEB0::_Newfl);
        if (open(name, mode | 1, prot) == 0)
            this->setstate(2);
    }
    basic_filebufDEB0* open(const char*, int, int);
    virtual ~basic_ifstream()
    {}
    basic_filebufDEB0 filebuf;
};
typedef basic_ifstream<char, char_traits_ob1<char> > ifstream_ob1;
inline basic_istream<char, char_traits_ob1<char> >& getline(basic_istream<char, char_traits_ob1<char> >& input, BxString& line)
{
    return (*(::std::basic_istream<char, ::std::char_traits_ob1<char>> *)&(::fnv_00ad5770::FUN_00ad5770((::fnv_00ad5770::FUN_00ad5770_Q &)(input), (::fnv_00ad5770::StrQ &)(line), reinterpret_cast<::GvIos *>((void *)&(input))->FUN_00ad30c0('\n'))));
}
}

// @fnv 0x00ac9120
bool __cdecl FUN_00ac9120(const BxString& path, CsvArray<CsvRow>& table)
{

    reinterpret_cast<::vecacd::VcVector *>(&(table))->FUN_00acdba0();

    CsvRow row;

    if (!CanOpenFile((void*)&path))
    {
        FUN_00ac6430(3, path);
        return false;
    }

    std::ifstream_ob1 input(path.c_str(), 1, 64);

    if (input.fail())
    {
        FUN_00ac6430(4, path);
        return false;
    }

    while (!input.eof() && !input.fail())
    {

        BxString line;

        std::getline(input, line);

        if (!input.fail())
        {

            char ch[2] = {0, 0};

            const char* p = line.c_str();

            bool empty = true;

            reinterpret_cast<::Vec *>(&(row))->FUN_00acac40();

            while (*p != '\n' && *p != '\0')
            {

                BxString entry("");

                bool quote = false;

                if (*p == '"')
                {
                    quote = true;
                    ++p;
                }

                for (; (*p != ',' || quote) && *p != '\0' && *p != '\n'; ++p)
                {

                    if (*p == '"')
                    {
                        quote = !quote;
                        continue;
                    }

                    if (*p != ' ' && *p != '\t')
                        empty = false;

                    ch[0] = *p;

                    entry += ch;
                }

                if (*p != '\0')
                    ++p;

                reinterpret_cast<::VecQ_acab30 *>(&(row))->FUN_00acab30((const ::vecdac9::VsString &)(entry));
            }

            if (!empty)
                reinterpret_cast<::rework_acda90::VecQ_acda90 *>(&(table))->FUN_00acda90((const ::rework_acda90::ElQ_acda90 &)(row));
        }
    }

    if (!input.eof() && input.fail())
    {
        FUN_00ac6430(1, path);
        return false;
    }

    return true;
}

namespace fnv_00ac9ff0 {
namespace std {
class Str_ac9ff0 : public BxStringVal
{
  public:
    Str_ac9ff0(const char* s) : BxStringVal()
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(false, 0);
        reinterpret_cast<BxString*>(this)->assign(s);
    }
    Str_ac9ff0(const Str_ac9ff0& right) : BxStringVal(right)
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(false, 0);
        reinterpret_cast<BxString*>(this)->assign(reinterpret_cast<const BxString&>(right), 0, ::g_010173f0);
    }
    ~Str_ac9ff0()
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, 0);
    }
    void _Tidy(bool built, unsigned int count)
    {
        if (!built)
            ;
        else if (16 <= capacity)
        {
            char* old = storage._Ptr;
            if (0 < count)
                BxTraitsHelper::copy_s<BxStrTraits>(storage._Buf, 16, old, count);
            _Alval.deallocate(old, capacity + 1);
        }
        capacity = 15;
        eos(count);
    }
    char* data()
    {
        return 16 <= capacity ? storage._Ptr : storage._Buf;
    }
    void eos(unsigned int n)
    {
        BxStrTraits::assign(data()[length = n], char());
    }
    BxQ_ad6bb0 storage;
    unsigned int length, capacity;
};
typedef Str_ac9ff0 string;

class exception
{
  public:
    exception();
    exception(const exception&);
    virtual ~exception();
    const char* _m_what;
    int _m_doFree;
};

class runtime_error : public exception
{
  public:
    explicit runtime_error(const string& _Message) : _Str(_Message)
    {}
    virtual ~runtime_error()
    {}
    string _Str;
};

class ios_base
{
  public:
    class failure : public runtime_error
    {
      public:
        explicit failure(const string& _Message) : runtime_error(_Message)
        {}
        virtual ~failure()
        {}
    };
    void FUN_00ac9ff0(int _State, bool _Reraise);
    int unk00;
    int unk04;
    int _Mystate;
    int _Except;
};

// @fnv 0x00ac9ff0
void ios_base::FUN_00ac9ff0(int _State, bool _Reraise)
{
    _Mystate = _State & 0x17;
    if ((_Mystate & _Except) == 0)
        ;
    else if (_Reraise)
        throw;
    else if (_Mystate & _Except & 4)
        throw failure("ios_base::badbit set");
    else if (_Mystate & _Except & 2)
        throw failure("ios_base::failbit set");
    else
        throw failure("ios_base::eofbit set");
}
}
}

// namespace fnv_00ac9ff0

inline bool InsertionEqualAlloc(const BxCharAlloc&, const BxCharAlloc&)
{
    return true;
}

class InsertionText : public BxStringVal
{
  public:
    BxQ_ad6bb0 storage;
    unsigned int length, capacity;
    InsertionText(const InsertionText& right) : BxStringVal(right)
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(false, 0);
        AssignSubstring(right, 0, ::g_010173f0);
    }
    ~InsertionText()
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, 0);
    }
    InsertionText& operator=(const InsertionText& right)
    {
        return AssignSubstring(right, 0, ::g_010173f0);
    }
    unsigned int size() const
    {
        return length;
    }
    unsigned int max_size() const
    {
        unsigned int _Num = _Alval.max_size();
        return _Num <= 1 ? 1 : _Num - 1;
    }
    InsertionText& erase(unsigned int _Off = 0, unsigned int _Count = (unsigned int)-1)
    {
        if (length < _Off)
        {
            StringBase::_Xran();
        }
        if (length - _Off < _Count)
        {
            _Count = length - _Off;
        }
        if (0 < _Count)
        {
            BxTraitsHelper::move_s<BxStrTraits>(data() + _Off, capacity - _Off, data() + _Off + _Count,
                                                length - _Off - _Count);
            unsigned int _Newsize = length - _Count;
            eos(_Newsize);
        }
        return *this;
    }
    void _Copy(unsigned int _Newsize, unsigned int _Oldlen)
    {
        unsigned int _Newres = _Newsize | 15;
        if (max_size() < _Newres)
        {
            _Newres = _Newsize;
        }
        else if (_Newres / 3 < capacity / 2 && capacity <= max_size() - capacity / 2)
        {
            _Newres = capacity + capacity / 2;
        }
        char* _Ptr = 0;
        try
        {
            _Ptr = _Alval.allocate(_Newres + 1);
        }
        catch (...)
        {
            _Newres = _Newsize;
            try
            {
                _Ptr = _Alval.allocate(_Newres + 1);
            }
            catch (...)
            {
                FUN_0044a730(true);
                throw;
            }
        }
        if (0 < _Oldlen)
        {
            std::_Traits_helper::copy_s<std::char_traits_ob1<char> >(_Ptr, _Newres + 1, data(), _Oldlen);
        }
        FUN_0044a730(true);
        storage._Ptr = _Ptr;
        capacity = _Newres;
        eos(_Oldlen);
    }
    bool grow(unsigned int _Newsize, bool _Trim = false)
    {
        if (max_size() < _Newsize)
        {
            StringBase::_Xlen();
        }
        if (capacity < _Newsize)
        {
            _Copy(_Newsize, length);
        }
        else if (_Trim && _Newsize < 16)
        {
            reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, _Newsize < length ? _Newsize : length);
        }
        else if (_Newsize == 0)
        {
            eos(0);
        }
        return 0 < _Newsize;
    }
    const char* data() const
    {
        return 16 <= capacity ? storage._Ptr : storage._Buf;
    }
    InsertionText& AssignSubstring(const InsertionText& right, unsigned int off, unsigned int count)
    {
        if (right.size() < off)
            StringBase::_Xran();
        unsigned int n = right.length - off;
        if (count < n)
            n = count;
        if (this == &right)
            erase(off + n), erase(0, off);
        else if (grow(n))
        {
            std::_Traits_helper::copy_s<std::char_traits_ob1<char> >(data(), capacity, right.data() + off, n);
            eos(n);
        }
        return *this;
    }
    void swap(InsertionText& right)
    {
        if (this == &right)
            ;
        else if (InsertionEqualAlloc(_Alval, right._Alval))
        {
            BxQ_ad6bb0 saved = storage;
            storage = right.storage;
            right.storage = saved;
            unsigned int savedLength = length;
            length = right.length;
            right.length = savedLength;
            unsigned int savedCapacity = capacity;
            capacity = right.capacity;
            right.capacity = savedCapacity;
        }
        else
        {
            InsertionText saved = *this;
            *this = right;
            right = saved;
        }
    }
    char* data()
    {
        return 16 <= capacity ? storage._Ptr : storage._Buf;
    }
    void eos(unsigned int n)
    {
        std::char_traits_ob1<char>::assign(data()[length = n], char());
    }
    void FUN_0044a730(bool built = false, unsigned int n = 0)
    {
        if (!built)
            ;
        else if (16 <= capacity)
        {
            char* ptr = storage._Ptr;
            if (0 < n)
                std::_Traits_helper::copy_s<std::char_traits_ob1<char> >(storage._Buf, 16, ptr, n);
            _Alval.deallocate(ptr, capacity + 1);
        }
        capacity = 15;
        eos(n);
    }
};

namespace wrac52 {
template <> inline InsertionText* BxAllocT<InsertionText>::allocate(unsigned int count)
{
    return ((::InsertionText *)(::fnv_00ad5310::FUN_00ad5310(count)));
}
}

struct InsertAlloc : BxAllocT<InsertionText>
{
    void destroy(InsertionText* p)
    {
        GvDestroyOne(p);
    }
};

namespace wrac52 {
template <>
inline void GvUncheckedFillN<InsertionText, InsertAlloc>(InsertionText* first, unsigned int count,
                                                         const InsertionText& value, InsertAlloc& al)
{
    ::fnv_00ad5b00::FUN_00ad5b00((::fnv_00ad5b00::Str<char, ::fnv_00ad5b00::Al<char>> *)(first), count, (const ::fnv_00ad5b00::Str<char, ::fnv_00ad5b00::Al<char>> &)(value), (::fnv_00ad5b00::Box< ::fnv_00ad5b00::Str<char, ::fnv_00ad5b00::Al<char>>> &)(al));
}
}
InsertionText* __cdecl FUN_00ad66e0(InsertionText*, InsertionText*, InsertionText*, InsertAlloc&, InsertMoveTag,
                                    GvRangeCheckedTag);

InsertionText* __cdecl FUN_00ad5dd0(InsertionText*, InsertionText*, InsertionText*, InsertAlloc&);

inline InsertionText* InsertMove(InsertionText* first, InsertionText* last, InsertionText* dest, InsertAlloc& al)
{
    return FUN_00ad66e0(GvCheckedBase(first), GvCheckedBase(last), dest, al, InsertMoveCat(dest), GvRangeCheckedTag());
}

inline void __cdecl InsertionSwap(InsertionText& left, InsertionText& right)
{
    left.swap(right);
}

template <class T> inline void InsertionSwapAdl(T& left, T& right)
{
    InsertionSwap(left, right);
}

template <class I, class O, class C> inline O BackwardOpt(I first, I last, O dest, C, InsertMoveTag, GvRangeCheckedTag)
{
    while (first != last)
        InsertionSwapAdl(*--dest, *--last);
    return dest;
}

template <class I, class O>
inline O BackwardOpt(I first, I last, O dest, GvRandomTag, InsertMoveTag cat, GvRangeCheckedTag)
{
    O result = dest - (last - first);
    BackwardOpt(first, last, GvCheckedBase(dest), GvForwardTag(), cat, GvRangeCheckedTag());
    return result;
}

inline InsertionText* __cdecl FUN_00ad5250(InsertionText* first, InsertionText* last, InsertionText* dest)
{
    return BackwardOpt(GvCheckedBase(first), GvCheckedBase(last), dest, GvIterRandom(first, dest), InsertMoveCat(dest),
                       GvRangeCheckedTag());
}

template <class I, class T> inline void InsertFillInner(I first, I last, const T& value)
{
    for (; first != last; ++first)
        *first = value;
}

template <class I, class T> inline void InsertFill(I first, I last, const T& value)
{
    InsertFillInner(GvCheckedBase(first), GvCheckedBase(last), value);
}

struct InsertStrings : GvAuxBase<InsertAlloc>
{
    typedef unsigned int size_type;
    typedef InsertionText value_type;
    typedef InsertionText* pointer;
    typedef GvConstIterator<InsertionText> const_iterator;
    InsertAlloc _Alval;
    pointer _Myfirst, _Mylast, _Myend;
    size_type size() const
    {
        return _Mylast - _Myfirst;
    }
    size_type capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    size_type max_size() const
    {
        return _Alval.max_size();
    }
    void _Destroy(pointer first, pointer last)
    {
        GvDestroyRange(first, last, _Alval);
    }
    pointer _MoveSuffix(pointer first, pointer last, pointer dest)
    {
        return FUN_00ad5dd0(first, last, dest, _Alval);
    }
    pointer _Umove(pointer first, pointer last, pointer dest)
    {
        return InsertMove(first, last, dest, _Alval);
    }
    pointer _Ufill(pointer ptr, size_type count, const InsertionText& value)
    {
        GvUncheckedFillN(ptr, count, value, _Alval);
        return ptr + count;
    }
    static void FUN_00ac0b00()
    {
        throw BxLengthError("vector<T> too long");
    }
    void FUN_00ad07c0(const_iterator, size_type, const InsertionText&);
};

// @fnv 0x00ad07c0
void InsertStrings::FUN_00ad07c0(const_iterator _Where, size_type _Count, const InsertionText& _Val)
{
    size_type _Capacity = capacity();
    if (_Count == 0)
        ;
    else if (max_size() - size() < _Count)
        ::FUN_00ac0b00();
    else if (_Capacity < size() + _Count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        pointer _Newvec = this->_Alval.allocate(_Capacity);
        pointer _Ptr = _Newvec;
        try
        {
            _Ptr = _Umove(this->_Myfirst, _Where._Myptr, _Newvec);
            _Ptr = _Ufill(_Ptr, _Count, _Val);
            _MoveSuffix(_Where._Myptr, this->_Mylast, _Ptr);
        }
        catch (...)
        {
            _Destroy(_Newvec, _Ptr);
            this->_Alval.deallocate(_Newvec, _Capacity);
            throw;
        }
        _Count += size();
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myend = _Newvec + _Capacity;
        _Mylast = _Newvec + _Count;
        _Myfirst = _Newvec;
    }
    else if ((size_type)(_Mylast - _Where._Myptr) < _Count)
    {
        value_type _Tmp = _Val;
        _Umove(_Where._Myptr, _Mylast, _Where._Myptr + _Count);
        try
        {
            _Ufill(_Mylast, _Count - (_Mylast - _Where._Myptr), _Tmp);
        }
        catch (...)
        {
            _Destroy(_Where._Myptr + _Count, _Mylast + _Count);
            throw;
        }
        _Mylast += _Count;
        InsertFill(_Where._Myptr, _Mylast - _Count, _Tmp);
    }
    else
    {
        value_type _Tmp = _Val;
        pointer _Oldend = _Mylast;
        _Mylast = _Umove(_Oldend - _Count, _Oldend, _Mylast);
        ::fnv_00ad5250::FUN_00ad5250((::fnv_00ad5250::std::String *)(_Where._Myptr), (::fnv_00ad5250::std::String *)(::InsertionText *)(_Oldend - _Count), (::fnv_00ad5250::std::String *)(_Oldend));
        InsertFill(_Where._Myptr, _Where._Myptr + _Count, _Tmp);
    }
}

struct PairAssignView
{
    void* al;
    union
    {
        char buf[16];
        char* ptr;
    } bx;
    unsigned size;
    unsigned res;
    PairAssignView& AssignSubstring(const PairAssignView& other, unsigned int offset, unsigned int count)
    {
        BxString* dest = (BxString*)this;
        if (other.size < offset)
            BxString::_Xran();
        unsigned int copied = other.size - offset;
        if (count < copied)
            copied = count;
        if (this == &other)
            dest->erase(offset + copied), dest->erase(0, offset);
        else if (dest->_Grow(copied))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(dest->_Myptr(), res, ((const BxString&)other)._Myptr() + offset,
                                                copied);
            dest->_Eos(copied);
        }
        return *this;
    }
};

template <class K, class V> struct PairRecord
{
    K first;
    V second;
    PairRecord() : first(), second()
    {}
    PairRecord(const K& key, const V& value) : first(key), second(value)
    {}
    template <class A, class B> PairRecord(const PairRecord<A, B>& other) : first(other.first), second(other.second)
    {}
};

typedef PairRecord<unsigned int, BxString> PointPair;

void ThrowVectorTooLong();

PointPair* CallWithIterators(PointPair*, PointPair*, PointPair*, GvAlloc<PointPair>&);

PointPair* FUN_00ac1da0(PointPair*, PointPair*, PointPair*, GvAlloc<PointPair>&);

PointPair* FUN_00ac1580(PointPair*, PointPair*, PointPair*);

template <class T> struct PairAllocator : GvAlloc<T>
{
    T* allocate(unsigned int count)
    {
        return ((::PairRecord<unsigned int, ::wrac52::BxString> *)(::fnv_0065e430::FUN_0065e430(count)));
    }
};

template <class T> struct PairVectorVal : GvAuxBase<PairAllocator<T> >
{
    PairAllocator<T> _Alval;
};

struct PairMoveTag
{
};

template <class I> inline PairMoveTag PairMoveCategory(I&)
{
    PairMoveTag tag;
    return tag;
}

template <class I, class O, class A, class M>
__forceinline O PairUninitMove(I first, I last, O dest, A& alloc, M, GvRangeCheckedTag)
{
    return CallWithIterators(first, last, dest, alloc);
}

template <class I, class O, class A> __forceinline O PairUncheckedMove(I first, I last, O dest, A& alloc)
{
    return PairUninitMove(GvCheckedBase(first), GvCheckedBase(last), dest, alloc, PairMoveCategory(dest),
                          GvRangeCheckedTag());
}

template <class I, class V> inline void PairFillRange(I first, I last, const V& _Val)
{
    for (; first != last; ++first)
        *first = _Val;
}

template <class I, class V> inline void PairFill(I first, I last, const V& _Val)
{
    PairFillRange(GvCheckedBase(first), GvCheckedBase(last), _Val);
}

template <class I, class O, class C>
__declspec(noinline) O PairCopyBackward(I first, I last, O dest, C, GvNonscalarTag, GvRangeCheckedTag)
{
    while (first != last)
        *--dest = *--last;
    return dest;
}

template <class I, class O>
__declspec(noinline) O PairCopyBackward(I first, I last, O dest, GvRandomTag, GvNonscalarTag, GvRangeCheckedTag)
{
    O result = dest - (last - first);
    PairCopyBackward(first, last, GvCheckedBase(dest), GvForwardTag(), GvNonscalarTag(), GvRangeCheckedTag());
    return result;
}

template <class I, class O, class C, class M>
inline O PairMoveBackward(I first, I last, O dest, C cat, M, GvRangeCheckedTag)
{
    return PairCopyBackward(first, last, dest, cat, GvPtrCat(first, dest), GvRangeCheckedTag());
}

inline PointPair* FUN_00ac1580(PointPair* first, PointPair* last, PointPair* dest)
{
    return PairMoveBackward(GvCheckedBase(first), GvCheckedBase(last), dest, GvIterRandom(first, dest),
                            PairMoveCategory(dest), GvRangeCheckedTag());
}

template <class I, class V> inline void LastFillRange(I first, I last, const V& value)
{
    for (; first != last; ++first)
    {
        first->first = value.first;
        ((PairAssignView&)first->second).AssignSubstring((const PairAssignView&)value.second, 0, ::g_010173f0);
    }
}

template <class I, class V> inline void LastFill(I first, I last, const V& value)
{
    LastFillRange(GvCheckedBase(first), GvCheckedBase(last), value);
}

template <class T> struct PairInsertionVector : PairVectorVal<T>
{
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    unsigned int max_size() const
    {
        return this->_Alval.max_size();
    }
    static void _Xlen()
    {
        throw BxLengthError("vector<T> too long");
    }
    T* _Ufill(T* p, unsigned int n, const T& val)
    {
        GvUncheckedFillN(p, n, val, this->_Alval);
        return p + n;
    }

    void FUN_0065dc60(T*, T*);
    template <class I> T* _Umove(I first, I last, T* dest)
    {
        return PairUncheckedMove(first, last, dest, this->_Alval);
    }
    T* _UmoveSuffix(T* first, T* last, T* dest)
    {
        return FUN_00ac1da0(first, last, dest, this->_Alval);
    }
    void FUN_00abe310(GvConstIterator<T> _Where, unsigned int _Count, const T& _Val);
};

template <class T> inline void PairInsertionVector<T>::FUN_0065dc60(T* first, T* last)
{
    GvDestroyRange(first, last, this->_Alval);
}

// @fnv 0x00abe310
template <class T>
void PairInsertionVector<T>::FUN_00abe310(GvConstIterator<T> _Where, unsigned int _Count, const T& _Val)
{
    unsigned int _Capacity = capacity();
    if (_Count == 0)
    {
    }
    else if (max_size() - size() < _Count)
    {
        ::fnv_0065f640::ThrowVectorTooLong();
    }
    else if (_Capacity < size() + _Count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        T* _Newvec = this->_Alval.allocate(_Capacity);
        T* _Ptr = _Newvec;
        try
        {
            _Ptr = _Umove(_Myfirst, _Where._Myptr, _Newvec);
            _Ptr = _Ufill(_Ptr, _Count, _Val);
            _UmoveSuffix(_Where._Myptr, _Mylast, _Ptr);
        }
        catch (...)
        {
            reinterpret_cast<::FUN_0065dc60Class *>(this)->FUN_0065dc60((::std::intptr_t)(_Newvec), (::std::intptr_t)(_Ptr));
            this->_Alval.deallocate(_Newvec, _Capacity);
            throw;
        }
        _Count += size();
        if (_Myfirst != 0)
        {
            reinterpret_cast<::FUN_0065dc60Class *>(this)->FUN_0065dc60((::std::intptr_t)(_Myfirst), (::std::intptr_t)(_Mylast));
            this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myend = _Newvec + _Capacity;
        _Mylast = _Newvec + _Count;
        _Myfirst = _Newvec;
    }
    else if ((unsigned int)(_Mylast - _Where._Myptr) < _Count)
    {
        T _Tmp = _Val;
        _Umove(_Where._Myptr, _Mylast, _Where._Myptr + _Count);
        try
        {
            _Ufill(_Mylast, _Count - (_Mylast - _Where._Myptr), _Tmp);
        }
        catch (...)
        {
            reinterpret_cast<::FUN_0065dc60Class *>(this)->FUN_0065dc60((int)(_Where._Myptr + _Count), (int)(_Mylast + _Count));
            throw;
        }
        _Mylast += _Count;
        PairFill(_Where._Myptr, _Mylast - _Count, _Tmp);
    }
    else
    {
        T _Tmp = _Val;
        T* _Oldend = _Mylast;
        _Mylast = _Umove(_Oldend - _Count, _Oldend, _Mylast);
        FUN_00ac1580(_Where._Myptr, _Oldend - _Count, _Oldend);
        LastFill(_Where._Myptr, _Where._Myptr + _Count, _Tmp);
    }
}

template void PairInsertionVector<PointPair>::FUN_00abe310(GvConstIterator<PointPair>, unsigned int, const PointPair&);

// inline copy of the unit's StrQ_ad6bb0::FUN_00ad6bb0 (string swap): the original inlined it here
struct StrQSwap_ad6bb0 : StrQ_ad6bb0
{
    inline void Swap(StrQ_ad6bb0& other)
    {
        if (this == &other)
        {
        }
        else if (_Alval == other._Alval)
        {
            BxQ_ad6bb0 buffer = _Bx;
            _Bx = other._Bx, other._Bx = buffer;
            unsigned length = _Mysize;
            _Mysize = other._Mysize, other._Mysize = length;
            unsigned capacity = _Myres;
            _Myres = other._Myres, other._Myres = capacity;
        }
        else
        {
            BxString saved = *(BxString*)this;
            *(BxString*)this = *(BxString*)&other;
            *(BxString*)&other = saved;
        }
    }
};

inline void swap(BxString& _Left, BxString& _Right)
{
    reinterpret_cast<::StrQ_ad6bb0 *>((((StrQSwap_ad6bb0*)&_Left)))->FUN_00ad6bb0(*(StrQ_ad6bb0*)&_Right);
}

// @fnv 0x00ad66e0
BxString* __cdecl FUN_00ad66e0(BxString* _First, BxString* _Last, BxString* _Dest, GvAlloc<BxString>& _Al)
{
    BxString* _Next = _Dest;
    BxString _Val;
    try
    {
        for (; _First != _Last; ++_Dest, ++_First)
        {
            _Al.construct(_Dest, _Val);
            swap(*_Dest, *_First);
        }
    }
    catch (...)
    {
        for (; _Next != _Dest; ++_Next)
            _Al.destroy(_Next);
        throw;
    }
    return _Dest;
}

namespace Insert52Detail {

extern const char DAT_010173c4[];
struct ErrorText
{
    unsigned char allocator_ob1;
    union
    {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length, capacity;
    explicit ErrorText(const char*);
    ~ErrorText();
};
struct InsertionLengthError
{
    virtual ~InsertionLengthError();
    const char* message;
    bool ownsMessage;
    ErrorText detail;
    explicit InsertionLengthError(const ErrorText&);
};
inline void __cdecl ThrowVectorTooLong()
{
    throw InsertionLengthError(ErrorText(DAT_010173c4));
}
struct Point3
{
    float x, y, z;
};
struct Element52
{
    BxString name;
    GvVector<Point3> points;
    Element52(const Element52& other) : name(other.name), points(other.points)
    {}
    ~Element52()
    {}
};
template <class T> struct InsertAllocator
{
    typedef T* pointer;
    InsertAllocator() throw()
    {}
    InsertAllocator(const InsertAllocator&) throw()
    {}
    template <class O> InsertAllocator(const InsertAllocator<O>&) throw()
    {}
    pointer allocate(unsigned int n)
    {
        return (pointer)::FUN_0065e550(n);
    }
    void deallocate(pointer p, unsigned int)
    {
        reinterpret_cast<::FNV_MemoryManager *>((((GvHeap*)&(*reinterpret_cast<int *>(&::g_memoryManager)))))->FUN_00aa4060(p);
    }
    void destroy(pointer p)
    {
        GvDestroyOne(p);
    }
    void construct(pointer p, const T& v)
    {
        GvConstruct(p, v);
    }
    unsigned int max_size() const throw()
    {
        unsigned int count = (unsigned int)(-1) / sizeof(T);
        return 0 < count ? count : 1;
    }
};
template <class T> struct InsertVectorVal : GvAuxBase<InsertAllocator<T> >
{
    InsertAllocator<T> _Alval;
    InsertVectorVal(InsertAllocator<T> a = InsertAllocator<T>()) : GvAuxBase<InsertAllocator<T> >(a), _Alval(a)
    {}
};
template <class T, class A>
inline void InsertUninitFillN(T* first, unsigned int count, const T& value, A& alloc, GvNonscalarTag, GvRangeCheckedTag)
{
    T* next = first;
    try
    {
        for (; 0 < count; --count, ++first)
            alloc.construct(first, value);
    }
    catch (...)
    {
        for (; next != first; ++next)
            alloc.destroy(next);
        throw;
    }
}
template <class T, class A> inline void InsertUncheckedFillN(T* first, unsigned int count, const T& value, A& alloc)
{
    ::fnv_00ac2540::FUN_00ac2540((::fnv_00ac2540::FUN_00ac0530 *)(first), count, (const ::fnv_00ac2540::FUN_00ac0530 &)(value));
}
struct InsertMoveTag
{
};
template <class I> inline InsertMoveTag InsertMoveCategory(const I&)
{
    InsertMoveTag tag;
    return tag;
}
template <class I, class O, class A>
inline O InsertUninitMove(I first, I last, O dest, A& alloc, InsertMoveTag, GvRangeCheckedTag)
{
    return GvUncheckedUninitCopy(first, last, dest, alloc);
}
template <class I, class O, class A> inline O InsertUncheckedMove(I first, I last, O dest, A& alloc)
{
    return InsertUninitMove(GvCheckedBase(first), GvCheckedBase(last), dest, alloc, InsertMoveCategory(dest),
                            GvRangeCheckedTag());
}
template <class I, class T> inline void InsertFillLoop(I first, I last, const T& value)
{
    for (; first != last; ++first)
        *first = value;
}
template <class I, class T> inline void InsertFill(I first, I last, const T& value)
{
    InsertFillLoop(GvCheckedBase(first), GvCheckedBase(last), value);
}
template <class I, class O, class C>
inline O InsertBackwardCopy(I first, I last, O dest, C, GvNonscalarTag, GvRangeCheckedTag)
{
    while (first != last)
        *--dest = *--last;
    return dest;
}
template <class I, class O>
inline O InsertBackwardCopy(I first, I last, O dest, GvRandomTag, GvNonscalarTag, GvRangeCheckedTag)
{
    O result = dest - (last - first);
    InsertBackwardCopy(first, last, GvCheckedBase(dest), GvForwardTag(), GvNonscalarTag(), GvRangeCheckedTag());
    return result;
}
template <class I, class O, class C>
inline O InsertBackwardDispatch(I first, I last, O dest, C cat, InsertMoveTag, GvRangeCheckedTag)
{
    return InsertBackwardCopy(first, last, dest, cat, GvPtrCat(first, dest), GvRangeCheckedTag());
}
template <class I, class O> inline O InsertMoveBackward(I first, I last, O dest)
{
    return InsertBackwardDispatch(GvCheckedBase(first), GvCheckedBase(last), dest, GvIterRandom(first, dest),
                                  InsertMoveCategory(dest), GvRangeCheckedTag());
}
struct ElementVector : InsertVectorVal<Element52>
{
    typedef Element52* pointer;
    typedef unsigned int size_type;
    typedef GvConstIterator<Element52> const_iterator;
    pointer _Myfirst, _Mylast, _Myend;
    size_type size() const
    {
        return _Mylast - _Myfirst;
    }
    size_type capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    size_type max_size() const
    {
        return this->_Alval.max_size();
    }
    void _Destroy(pointer first, pointer last)
    {
        GvDestroyRange(first, last, this->_Alval);
    }
    pointer _Ufill(pointer dest, size_type count, const Element52& value)
    {
        InsertUncheckedFillN(dest, count, value, this->_Alval);
        return dest + count;
    }
    template <class I> pointer _Umove(I first, I last, pointer dest)
    {
        return InsertUncheckedMove(first, last, dest, this->_Alval);
    }
    static void _Xlen()
    {
        ::fnv_0065f640::ThrowVectorTooLong();
    }
    void FUN_00abf210(const_iterator, size_type, const Element52&);
};

// @fnv 0x00abf210
void ElementVector::FUN_00abf210(const_iterator _Where, size_type _Count, const Element52& _Val)
{
    size_type _Capacity = capacity();

    if (_Count == 0)
        ;
    else if (max_size() - size() < _Count)
        _Xlen();
    else if (_Capacity < size() + _Count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        pointer _Newvec = this->_Alval.allocate(_Capacity);
        pointer _Ptr = _Newvec;

        try
        {
            _Ptr = _Umove(_Myfirst, _Where._Myptr, _Newvec);
            _Ptr = _Ufill(_Ptr, _Count, _Val);
            _Umove(_Where._Myptr, _Mylast, _Ptr);
        }
        catch (...)
        {
            _Destroy(_Newvec, _Ptr);
            this->_Alval.deallocate(_Newvec, _Capacity);
            throw;
        }

        _Count += size();
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }

        _Myend = _Newvec + _Capacity;
        _Mylast = _Newvec + _Count;
        _Myfirst = _Newvec;
    }
    else if ((size_type)(_Mylast - _Where._Myptr) < _Count)
    {
        Element52 _Tmp = _Val;

        _Umove(_Where._Myptr, _Mylast, _Where._Myptr + _Count);

        try
        {
            _Ufill(_Mylast, _Count - (_Mylast - _Where._Myptr), _Tmp);
        }
        catch (...)
        {
            _Destroy(_Where._Myptr + _Count, _Mylast + _Count);
            throw;
        }

        _Mylast += _Count;

        InsertFill(_Where._Myptr, _Mylast - _Count, _Tmp);
    }
    else
    {
        Element52 _Tmp = _Val;

        pointer _Oldend = _Mylast;
        _Mylast = _Umove(_Oldend - _Count, _Oldend, _Mylast);

        InsertMoveBackward(_Where._Myptr, _Oldend - _Count, _Oldend);
        InsertFill(_Where._Myptr, _Where._Myptr + _Count, _Tmp);
    }
}

}

struct ResizeText : BxStringVal
{
    BxQ_ad6bb0 storage;
    unsigned int length, capacity;
    ResizeText& operator=(const ResizeText& other)
    {
        reinterpret_cast<BxString*>(this)->assign(reinterpret_cast<const BxString&>(other), 0, ~0u);
        return *this;
    }
    ~ResizeText()
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, 0);
    }
    char* data()
    {
        return 16 <= capacity ? storage._Ptr : storage._Buf;
    }
    void eos(unsigned int n)
    {
        BxStrTraits::assign(data()[length = n], char());
    }
    void FUN_0044a730(bool built, unsigned int n)
    {
        if (!built)
            ;
        else if (16 <= capacity)
        {
            char* old = storage._Ptr;
            if (0 < n)
                BxTraitsHelper::copy_s<BxStrTraits>(storage._Buf, 16, old, n);
            BxCharAlloc& allocator_ob1 = _Alval;
            allocator_ob1.deallocate(old, capacity + 1);
        }
        capacity = 15;
        eos(n);
    }
};

struct ResizeEntry
{
    unsigned int key;
    ResizeText text;
};

struct ResizeConstIterator : GvIterBase
{
    ResizeEntry* _Myptr;
    ResizeConstIterator(ResizeEntry* ptr, const GvContainer* container)
    {
        if (!(container != 0 && static_cast<const GvVector<ResizeEntry>*>(container)->_Myfirst <= ptr &&
              ptr <= static_cast<const GvVector<ResizeEntry>*>(container)->_Mylast))
            ::FUN_00ec7c56();
        _Set_container(container);
        _Myptr = ptr;
    }
    bool operator==(const ResizeConstIterator& other) const
    {
        if (!(_Has_container() && _Same_container(other)))
            ::FUN_00ec7c56();
        return _Myptr == other._Myptr;
    }
    bool operator!=(const ResizeConstIterator& other) const
    {
        return !(*this == other);
    }
};

struct ResizeIterator : ResizeConstIterator
{
    ResizeIterator(ResizeEntry* ptr, const GvContainer* container) : ResizeConstIterator(ptr, container)
    {}
    ResizeIterator& operator+=(int offset)
    {
        reinterpret_cast<::FUN_00ac0b80_It *>(&(static_cast<ResizeConstIterator&>(*this)))->FUN_00ac0b80(offset);
        return *this;
    }
    ResizeIterator operator+(int offset) const
    {
        ResizeIterator result = *this;
        return result += offset;
    }
};

struct ResizeEntries : GvVector<ResizeEntry>
{
    ResizeIterator begin()
    {
        return ResizeIterator(_Myfirst, this);
    }
    ResizeIterator end()
    {
        return ResizeIterator(_Mylast, this);
    }
    void FUN_00abe310(ResizeConstIterator, unsigned int, const ResizeEntry&);
    ResizeIterator makeIterator(ResizeConstIterator where) const
    {
        return ResizeIterator(where._Myptr, this);
    }
    ResizeIterator FUN_00abb280(ResizeConstIterator firstArg, ResizeConstIterator lastArg)
    {
        ResizeIterator first = makeIterator(firstArg);
        ResizeIterator last = makeIterator(lastArg);
        if (first != last)
        {
            ResizeEntry* ptr = GvUncheckedCopy(last._Myptr, _Mylast, first._Myptr);
            _Destroy(ptr, _Mylast);
            _Mylast = ptr;
        }
        return first;
    }
    void FUN_00abb060(unsigned int count, ResizeEntry value);
};

// @fnv 0x00abb060
void ResizeEntries::FUN_00abb060(unsigned int count, ResizeEntry value)
{
    if (size() < count)
        FUN_00abe310(end(), count - size(), value);
    else if (count < size())
        FUN_00abb280(begin() + count, end());
}

namespace fnv_00ad5500 {

namespace std {
template <class _Elem> struct char_traits_ob1
{
    int x;
};
template <class _Elem> class allocator_ob1
{
    int x;
};
template <class _Elem, class _Tr, class _Al> class basic_string_ob1
{
  public:
    union
    {
        _Elem _Buf[20];
        _Elem* _Ptr;
    } _Bx;
    unsigned int _Mysize, _Myres;
    basic_string_ob1()
    {
        bool _Free;
        bool* _P = &_Free;
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(false, 0);
    }
    ~basic_string_ob1()
    {
        int _Z1;
        (void)_Z1;
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, 0);
    }

  protected:
    void _Tidy(bool, unsigned int);
};
}
typedef std::basic_string_ob1<char, std::char_traits_ob1<char>, std::allocator_ob1<char> > GameString;

// base init
void FUN_00ec3740(void* dst, const GameString& src);
void FUN_00ec35d7(void* p);

class TmpCls
{
  public:
    void* m_vtbl;
    GameString m_kPointA, m_kPointB, m_iThirdValue, m_iFourthElementInteger;
    void FUN_00ec32e3(int);
    TmpCls(const GameString& s) : m_kPointA(), m_kPointB(), m_iThirdValue(), m_iFourthElementInteger()
    {
        FUN_00ec32e3(0);
        FUN_00ec3740(this, s);
    }
    ~TmpCls()
    {
        int _T1, _T2;
        (void)_T1;
        (void)_T2;
        FUN_00ec35d7(this);
        m_kPointA.~basic_string_ob1();
        m_kPointB.~basic_string_ob1();
        m_iThirdValue.~basic_string_ob1();
        m_iFourthElementInteger.~basic_string_ob1();
    }
};

class SrcCls
{
  public:
    GameString FUN_00ad3e60();
};

class ObjBase
{
  public:
    void* m_vtbl;
    int m_refs;
    ObjBase()
    {
        m_vtbl = &::DAT_010a31fc;
        m_refs = 0;
    }
};
class ObjMid : public ObjBase
{
  public:
    ObjMid()
    {
        m_vtbl = &::DAT_010a3228;
    }
};
class ObjNew : public ObjMid
{
  public:
    ObjNew(const TmpCls&)
    {
        m_vtbl = &::DAT_010a3204;
    }
};

// @fnv 0x00ad5500
int FUN_00ad5500(ObjNew** output, SrcCls* source)
{
    if (output && !*output)
        *output = new ObjNew(TmpCls(source->FUN_00ad3e60()));
    return 2;
}
}

// namespace fnv_00ad5500


namespace rdac5e {
int FUN_00ec7c6b(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
struct BxSecureTag
{
};
struct BxStrTraits
{
    static char* _Copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        ::FUN_0044ccd0(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static char* _Move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c6b(_First1, _Size, _First2, _Count);
        return _First1;
    }

    static void assign(char& _Left, const char& _Right)
    {
        _Left = _Right;
    }
};
inline BxSecureTag BxCharTraitsCat()
{
    BxSecureTag _Secure_char_traits;
    return _Secure_char_traits;
}
struct BxTraitsHelper
{
    template <class T>
    static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Copy_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return copy_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
    template <class T>
    static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Move_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return move_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
};
struct BxBadAlloc
{
    const char* pWhat;
    int iDoFree;
    BxBadAlloc(const char* what);
    ~BxBadAlloc();
};
template <class T> inline T* BxAllocate(unsigned int count, T*)
{
    if (count <= 0)
    {
        count = 0;
    }
    else if (((unsigned int)(-1) / count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)::FUN_00401000(count * sizeof(T));
}
template <class T> struct BxAllocT
{
    typedef T* pointer;
    BxAllocT() throw()
    {}
    BxAllocT(const BxAllocT<T>&) throw()
    {}
    pointer allocate(unsigned int _Count)
    {
        return BxAllocate(_Count, (pointer)0);
    }
    pointer allocate(unsigned int _Count, const void*)
    {
        return allocate(_Count);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        ::FUN_00401030(_Ptr);
    }
    unsigned int max_size() const
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
typedef BxAllocT<char> BxCharAlloc;
struct BxStringVal
{
    BxCharAlloc _Alval;
    BxStringVal(BxCharAlloc _Al = BxCharAlloc()) : _Alval(_Al)
    {}
    BxStringVal(const BxStringVal& _Right) : _Alval(_Right._Alval)
    {}
};
struct BxString : public BxStringVal
{
    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;

    __forceinline BxString(const BxString& _Right) : BxStringVal(_Right)
    {
        _Tidy();
        assign(_Right, 0, ::g_010173f0);
    }
    ~BxString()
    {
        _Tidy(true);
    }
    static void _Xlen();
    static void _Xran();
    unsigned int size() const
    {
        return _Mysize;
    }

    unsigned int max_size() const
    {
        unsigned int _Num = _Alval.max_size();
        return _Num <= 1 ? 1 : _Num - 1;
    }
    char* _Myptr()
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    const char* _Myptr() const
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    void _Eos(unsigned int _Newsize)
    {
        BxStrTraits::assign(_Myptr()[_Mysize = _Newsize], char());
    }
    BxString& erase(unsigned int _Off = 0, unsigned int _Count = (unsigned int)-1)
    {
        if (_Mysize < _Off)
        {
            _Xran();
        }
        if (_Mysize - _Off < _Count)
        {
            _Count = _Mysize - _Off;
        }
        if (0 < _Count)
        {
            BxTraitsHelper::move_s<BxStrTraits>(_Myptr() + _Off, _Myres - _Off, _Myptr() + _Off + _Count,
                                                _Mysize - _Off - _Count);
            unsigned int _Newsize = _Mysize - _Count;
            _Eos(_Newsize);
        }
        return *this;
    }

    void _Tidy(bool _Built = false, unsigned int _Newsize = 0)
    {
        if (!_Built)
        {
        }
        else if (16 <= _Myres)
        {
            char* _Ptr = _Bx._Ptr;
            if (0 < _Newsize)
            {
                BxTraitsHelper::copy_s<BxStrTraits>(_Bx._Buf, 16, _Ptr, _Newsize);
            }
            _Alval.deallocate(_Ptr, _Myres + 1);
        }
        _Myres = 16 - 1;
        _Eos(_Newsize);
    }
    void _Copy(unsigned int _Newsize, unsigned int _Oldlen)
    {
        unsigned int _Newres = _Newsize | 15;
        if (max_size() < _Newres)
        {
            _Newres = _Newsize;
        }
        else if (_Newres / 3 < _Myres / 2 && _Myres <= max_size() - _Myres / 2)
        {
            _Newres = _Myres + _Myres / 2;
        }
        char* _Ptr = 0;
        try
        {
            _Ptr = _Alval.allocate(_Newres + 1);
        }
        catch (...)
        {
            _Newres = _Newsize;
            try
            {
                _Ptr = _Alval.allocate(_Newres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < _Oldlen)
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Ptr, _Newres + 1, _Myptr(), _Oldlen);
        }
        _Tidy(true);
        _Bx._Ptr = _Ptr;
        _Myres = _Newres;
        _Eos(_Oldlen);
    }
    bool _Grow(unsigned int _Newsize, bool _Trim = false)
    {
        if (max_size() < _Newsize)
        {
            _Xlen();
        }
        if (_Myres < _Newsize)
        {
            _Copy(_Newsize, _Mysize);
        }
        else if (_Trim && _Newsize < 16)
        {
            reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, _Newsize < _Mysize ? _Newsize : _Mysize);
        }
        else if (_Newsize == 0)
        {
            _Eos(0);
        }
        return 0 < _Newsize;
    }
    BxString& assign(const BxString& _Right, unsigned int _Roff, unsigned int _Count)
    {
        if (_Right.size() < _Roff)
        {
            _Xran();
        }
        unsigned int _Num = _Right.size() - _Roff;
        if (_Count < _Num)
        {
            _Num = _Count;
        }
        if (this == &_Right)
        {
            erase((unsigned int)(_Roff + _Num)), erase(0, _Roff);
        }
        else if (_Grow(_Num))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Right._Myptr() + _Roff, _Num);
            _Eos(_Num);
        }
        return *this;
    }
};

void FUN_00ac6430(int code, BxString message);
}

struct FaceBinaryReadReceiver
{
    rdac5e::BxString kPath;
    rdac5e::BxString kMagic;
    int unk3c;
    char* pData;
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual bool v10(void* data, unsigned int size, unsigned int count);
    __declspec(noinline) bool FUN_00ac5e00(void* data, unsigned int size, unsigned int count);
};

// @fnv 0x00ac5e00
bool FaceBinaryReadReceiver::FUN_00ac5e00(void* data, unsigned int size, unsigned int count)
{
    if (pData == 0)
    {
        return false;
    }
    if (!v10(data, 1, size * count))
    {
        rdac5e::FUN_00ac6430(1, kPath);
        reinterpret_cast<::FUN_00ac5c00_cls *>(this)->ClearHolders();
        return false;
    }
    return true;
}

namespace plusad42 {
void FUN_00ec7c56();
int FUN_00ec7c66(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
int FUN_00ec7c6b(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
struct BxSecureTag
{
};
struct BxStrTraits
{
    static char* _Copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c66(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static char* _Move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c6b(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static unsigned int length(const char* _First)
    {
        return strlen(_First);
    }
    static int compare(const char* _First1, const char* _First2, unsigned int _Count)
    {
        return memcmp(_First1, _First2, _Count);
    }
    static void assign(char& _Left, const char& _Right)
    {
        _Left = _Right;
    }
};
inline BxSecureTag BxCharTraitsCat()
{
    BxSecureTag _Secure_char_traits;
    return _Secure_char_traits;
}
struct BxTraitsHelper
{
    template <class T>
    static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Copy_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return copy_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
    template <class T>
    static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Move_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return move_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
};
struct BxBadAlloc
{
    const char* pWhat;
    int iDoFree;
    BxBadAlloc(const char* what);
    ~BxBadAlloc();
};
template <class T> inline T* BxAllocate(unsigned int count, T*)
{
    if (count <= 0)
    {
        count = 0;
    }
    else if (((unsigned int)(-1) / count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)::FUN_00401000(count * sizeof(T));
}
template <class T> struct BxAllocT
{
    typedef T* pointer;
    BxAllocT() throw()
    {}
    BxAllocT(const BxAllocT<T>&) throw()
    {}
    pointer allocate(unsigned int _Count)
    {
        return BxAllocate(_Count, (pointer)0);
    }
    pointer allocate(unsigned int _Count, const void*)
    {
        return allocate(_Count);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        ::FUN_00401030(_Ptr);
    }
    unsigned int max_size() const
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
typedef BxAllocT<char> BxCharAlloc;
struct BxStringVal
{
    BxCharAlloc _Alval;
    BxStringVal(BxCharAlloc _Al = BxCharAlloc()) : _Alval(_Al)
    {}
    BxStringVal(const BxStringVal& _Right) : _Alval(_Right._Alval)
    {}
};
struct BxString : public BxStringVal
{
    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    BxString(const char* _Ptr) : BxStringVal()
    {
        _Tidy();
        assign(_Ptr);
    }
    BxString() : BxStringVal()
    {
        _Tidy();
    }
    BxString& operator=(const BxString& _Right)
    {
        return assign(_Right);
    }
    BxString& assign(const BxString& _Right)
    {
        return assign(_Right, 0, ::g_010173f0);
    }
    BxString(const BxString& _Right) : BxStringVal(_Right)
    {
        _Tidy();
        assign(_Right, 0, ::g_010173f0);
    }
    ~BxString()
    {
        _Tidy(true);
    }
    static void _Xlen();
    static void _Xran();
    unsigned int size() const
    {
        return _Mysize;
    }
    char& operator[](unsigned int _Off)
    {
        if (!(_Off <= _Mysize))
        {
            FUN_00ec7c56();
        }
        do
        {
        } while (0);
        return _Myptr()[_Off];
    }
    unsigned int max_size() const
    {
        unsigned int _Num = _Alval.max_size();
        return _Num <= 1 ? 1 : _Num - 1;
    }
    char* _Myptr()
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    const char* _Myptr() const
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    void _Eos(unsigned int _Newsize)
    {
        BxStrTraits::assign(_Myptr()[_Mysize = _Newsize], char());
    }
    BxString& erase(unsigned int _Off = 0, unsigned int _Count = (unsigned int)-1)
    {
        if (_Mysize < _Off)
        {
            _Xran();
        }
        if (_Mysize - _Off < _Count)
        {
            _Count = _Mysize - _Off;
        }
        if (0 < _Count)
        {
            BxTraitsHelper::move_s<BxStrTraits>(_Myptr() + _Off, _Myres - _Off, _Myptr() + _Off + _Count,
                                                _Mysize - _Off - _Count);
            unsigned int _Newsize = _Mysize - _Count;
            _Eos(_Newsize);
        }
        return *this;
    }
    bool _Inside(const char* _Ptr)
    {
        if (_Ptr == 0 || _Ptr < _Myptr() || _Myptr() + _Mysize <= _Ptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void _Tidy(bool _Built = false, unsigned int _Newsize = 0)
    {
        if (!_Built)
        {
        }
        else if (16 <= _Myres)
        {
            char* _Ptr = _Bx._Ptr;
            if (0 < _Newsize)
            {
                BxTraitsHelper::copy_s<BxStrTraits>(_Bx._Buf, 16, _Ptr, _Newsize);
            }
            _Alval.deallocate(_Ptr, _Myres + 1);
        }
        _Myres = 16 - 1;
        _Eos(_Newsize);
    }
    void _Copy(unsigned int _Newsize, unsigned int _Oldlen)
    {
        unsigned int _Newres = _Newsize | 15;
        if (max_size() < _Newres)
        {
            _Newres = _Newsize;
        }
        else if (_Newres / 3 < _Myres / 2 && _Myres <= max_size() - _Myres / 2)
        {
            _Newres = _Myres + _Myres / 2;
        }
        char* _Ptr = 0;
        try
        {
            _Ptr = _Alval.allocate(_Newres + 1);
        }
        catch (...)
        {
            _Newres = _Newsize;
            try
            {
                _Ptr = _Alval.allocate(_Newres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < _Oldlen)
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Ptr, _Newres + 1, _Myptr(), _Oldlen);
        }
        _Tidy(true);
        _Bx._Ptr = _Ptr;
        _Myres = _Newres;
        _Eos(_Oldlen);
    }
    bool _Grow(unsigned int _Newsize, bool _Trim = false)
    {
        if (max_size() < _Newsize)
        {
            _Xlen();
        }
        if (_Myres < _Newsize)
        {
            _Copy(_Newsize, _Mysize);
        }
        else if (_Trim && _Newsize < 16)
        {
            reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, _Newsize < _Mysize ? _Newsize : _Mysize);
        }
        else if (_Newsize == 0)
        {
            _Eos(0);
        }
        return 0 < _Newsize;
    }
    BxString& assign(const BxString& _Right, unsigned int _Roff, unsigned int _Count)
    {
        if (_Right.size() < _Roff)
        {
            _Xran();
        }
        unsigned int _Num = _Right.size() - _Roff;
        if (_Count < _Num)
        {
            _Num = _Count;
        }
        if (this == &_Right)
        {
            erase((unsigned int)(_Roff + _Num)), erase(0, _Roff);
        }
        else if (_Grow(_Num))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Right._Myptr() + _Roff, _Num);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& assign(const char* _Ptr, unsigned int _Count)
    {
        if (_Inside(_Ptr))
        {
            return assign(*this, _Ptr - _Myptr(), _Count);
        }
        if (_Grow(_Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Ptr, _Count);
            _Eos(_Count);
        }
        return *this;
    }
    const char& operator[](unsigned int _Off) const
    {
        if (!(_Off <= _Mysize))
        {
            FUN_00ec7c56();
        }
        return _Myptr()[_Off];
    }
    BxString& append(const BxString& _Right, unsigned int _Roff, unsigned int _Count)
    {
        if (_Right.size() < _Roff)
        {
            _Xran();
        }
        unsigned int _Num = _Right.size() - _Roff;
        if (_Num < _Count)
        {
            _Count = _Num;
        }
        if (::g_010173f0 - _Mysize <= _Count || _Mysize + _Count < _Mysize)
        {
            _Xlen();
        }
        if (0 < _Count && _Grow(_Num = _Mysize + _Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr() + _Mysize, _Myres - _Mysize, _Right._Myptr() + _Roff, _Count);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& append(const char* _Ptr, unsigned int _Count)
    {
        if (_Inside(_Ptr))
        {
            return append(*this, _Ptr - _Myptr(), _Count);
        }
        if (::g_010173f0 - _Mysize <= _Count)
        {
            _Xlen();
        }
        unsigned int _Num;
        if (0 < _Count && _Grow(_Num = _Mysize + _Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr() + _Mysize, _Myres - _Mysize, _Ptr, _Count);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& append(const char* _Ptr)
    {
        return (*(::plusad42::BxString *)&(reinterpret_cast<::StrA *>(this)->FUN_00a0c430(_Ptr, BxStrTraits::length(_Ptr))));
    }
    BxString& operator+=(const char* _Ptr)
    {
        return append(_Ptr);
    }
    const char* c_str() const
    {
        return _Myptr();
    }
    int compare(unsigned int _Off, unsigned int _N0, const char* _Ptr, unsigned int _Count) const
    {
        if (_Mysize < _Off)
            _Xran();
        if (_Mysize - _Off < _N0)
            _N0 = _Mysize - _Off;
        unsigned int _Ans = BxStrTraits::compare(_Myptr() + _Off, _Ptr, _N0 < _Count ? _N0 : _Count);
        return _Ans != 0 ? (int)_Ans : _N0 < _Count ? -1 : _N0 == _Count ? 0 : +1;
    }
    int compare(const char* _Ptr) const
    {
        return compare(0, _Mysize, _Ptr, BxStrTraits::length(_Ptr));
    }
    BxString& assign(const char* _Ptr)
    {
        return assign(_Ptr, BxStrTraits::length(_Ptr));
    }
};
inline bool operator==(const BxString& _Left, const char* _Right)
{
    return _Left.compare(_Right) == 0;
}
inline bool operator!=(const BxString& _Left, const char* _Right)
{
    return !(_Left == _Right);
}
struct BxException
{
    const char* _m_what;
    int _m_doFree;
    BxException();
    BxException(const BxException& _That);
    virtual ~BxException();
    virtual const char* what() const;
};
struct BxLogicError : public BxException
{
    BxString _Str;
    explicit BxLogicError(const BxString& _Message) : _Str(_Message)
    {}
    virtual ~BxLogicError()
    {}
    virtual const char* what() const
    {
        return _Str._Myptr();
    }
};
struct BxLengthError : public BxLogicError
{
    explicit BxLengthError(const BxString& _Message) : BxLogicError(_Message)
    {}
    virtual ~BxLengthError()
    {}
};

struct GvHeap
{
    void* FUN_00aa3e40(unsigned int _Size);
    void FUN_00aa4060(void* _Ptr);
};
template <class T> inline T* GvHeapAllocate(unsigned int _Count, T*)
{
    if (_Count <= 0)
    {
        _Count = 0;
    }
    else if (((unsigned int)(-1) / _Count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)((GvHeap*)&(*reinterpret_cast<int *>(&::g_memoryManager)))->FUN_00aa3e40(_Count * sizeof(T));
}
template <class T> inline void GvDestroyOne(T* _Ptr)
{
    _Ptr->~T();
}
template <class T> struct GvAlloc
{
    typedef T* pointer;
    GvAlloc() throw()
    {}
    GvAlloc(const GvAlloc<T>&) throw()
    {}
    template <class O> GvAlloc(const GvAlloc<O>&) throw()
    {}
    pointer allocate(unsigned int _Count)
    {
        return GvHeapAllocate(_Count, (pointer)0);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        ((GvHeap*)&(*reinterpret_cast<int *>(&::g_memoryManager)))->FUN_00aa4060(_Ptr);
    }
    void destroy(pointer _Ptr)
    {
        GvDestroyOne(_Ptr);
    }
    void construct(pointer _Ptr, const T& _Val)
    {
        GvConstruct(_Ptr, _Val);
    }
    unsigned int max_size() const throw()
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
struct GvNonscalarTag
{
};
struct GvScalarTag
{
};
struct GvRangeCheckedTag
{
};
template <class T1, class T2> struct GvPtrCatHelper
{
    typedef GvNonscalarTag _Ptr_cat;
};
template <> struct GvPtrCatHelper<char*, char*>
{
    typedef GvScalarTag _Ptr_cat;
};
template <> struct GvPtrCatHelper<unsigned short*, unsigned short*>
{
    typedef GvScalarTag _Ptr_cat;
};
template <class T> struct GvPtrCatHelper<T**, T**>
{
    typedef GvScalarTag _Ptr_cat;
};
template <class T1, class T2> inline typename GvPtrCatHelper<T1, T2>::_Ptr_cat GvPtrCat(T1&, T2&)
{
    typename GvPtrCatHelper<T1, T2>::_Ptr_cat _Cat;
    return _Cat;
}
template <class A> inline void GvDestroyRange(typename A::pointer, typename A::pointer, A&, GvScalarTag)
{}
template <class T, class A>
void GvUninitFillN(T* _First, unsigned int _Count, const T& _Val, A& _Al, GvNonscalarTag, GvRangeCheckedTag);
template <class T, class A> inline void GvUncheckedFillN(T* _First, unsigned int _Count, const T& _Val, A& _Al)
{
    GvUninitFillN(_First, _Count, _Val, _Al, GvPtrCat(_First, _First), GvRangeCheckedTag());
}
template <class A>
inline void GvDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al, GvNonscalarTag)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class A> inline void GvDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al)
{
    GvDestroyRange<A>(_First, _Last, _Al, GvPtrCat(_First, _Last));
}
struct GvInputTag
{
};
struct GvForwardTag : GvInputTag
{
};
struct GvBidiTag : GvForwardTag
{
};
struct GvRandomTag : GvBidiTag
{
};
struct GvUnchangedTag
{
};
template <class I1, class I2> inline GvRandomTag GvIterRandom(const I1&, const I2&)
{
    GvRandomTag _Cat;
    return _Cat;
}
struct GvBaseTag
{
};
template <class T> struct GvConstIterator;
template <class I> struct GvCheckedHelper
{
    typedef GvUnchangedTag _Tag;
    typedef I _Base;
};
template <class T> struct GvCheckedHelper<GvConstIterator<T> >
{
    typedef GvBaseTag _Tag;
    typedef const T* _Base;
};
template <class I, class B> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It, B)
{
    return _It._Checked_iterator_base();
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I, class B> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It, B)
{
    return _It._Checked_iterator_base();
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It)
{
    typename GvCheckedHelper<I>::_Tag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It)
{
    typename GvCheckedHelper<I>::_Tag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
}
template <class O, class D, class T> inline void GvFillN(O _First, D _Count, const T& _Val, GvRangeCheckedTag)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class O, class D, class T, class C>
inline void GvFillN(O _First, D _Count, const T& _Val, C, GvRangeCheckedTag)
{
    GvFillN(_First, _Count, _Val, GvRangeCheckedTag());
}
template <class O, class D, class T>
inline void GvFillN(O _First, D _Count, const T& _Val, GvRandomTag, GvRangeCheckedTag)
{
    O _Last = _First + _Count;
    (void)_Last;
    GvFillN(GvCheckedBase(_First), _Count, _Val, GvRangeCheckedTag());
}
template <class I> inline GvRandomTag GvIterCat(const I&)
{
    GvRandomTag _Cat;
    return _Cat;
}
template <class O, class D, class T> inline void GvUncheckedFillValues(O _First, D _Count, const T& _Val)
{
    GvFillN(_First, _Count, _Val, GvIterCat(_First), GvRangeCheckedTag());
}
template <class T, class A>
inline void GvUninitFillN(T* _First, unsigned int _Count, const T& _Val, A&, GvScalarTag, GvRangeCheckedTag)
{
    GvUncheckedFillValues(_First, _Count, _Val);
}
template <class I, class O, class C>
inline O GvCopyOpt(I _First, I _Last, O _Dest, C, GvNonscalarTag, GvRangeCheckedTag)
{
    for (; _First != _Last; ++_Dest, ++_First)
    {
        *_Dest = *_First;
    }
    return _Dest;
}
template <class I, class O>
inline O GvCopyOpt(I _First, I _Last, O _Dest, GvRandomTag, GvNonscalarTag, GvRangeCheckedTag)
{
    O _Result = _Dest + (_Last - _First);
    GvCopyOpt(_First, _Last, GvCheckedBase(_Dest), GvForwardTag(), GvNonscalarTag(), GvRangeCheckedTag());
    return _Result;
}
template <class I, class O, class C> inline O GvCopyOpt(I _First, I _Last, O _Dest, C, GvScalarTag, GvRangeCheckedTag)
{
    int _Off = _Last - _First;
    O _Result = _Dest + _Off;
    if (_Off > 0)
        FUN_00ec7c6b(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class I, class O> inline O GvUncheckedCopy(I _First, I _Last, O _Dest)
{
    return GvCopyOpt(GvCheckedBase(_First), GvCheckedBase(_Last), _Dest, GvIterRandom(_First, _Dest),
                     GvPtrCat(_First, _Dest), GvRangeCheckedTag());
}
template <class I, class F, class A>
inline F GvUninitCopy(I _First, I _Last, F _Dest, A& _Al, GvNonscalarTag, GvRangeCheckedTag)
{
    F _Next = _Dest;
    try
    {
        for (; _First != _Last; ++_Dest, ++_First)
        {
            _Al.construct(_Dest, *_First);
        }
    }
    catch (...)
    {
        for (; _Next != _Dest; ++_Next)
        {
            _Al.destroy(_Next);
        }
        throw;
    }
    return _Dest;
}
template <class I, class F, class A>
inline F GvUninitCopy(I _First, I _Last, F _Dest, A&, GvScalarTag, GvRangeCheckedTag)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    F _Result = _Dest + _Count;
    if (_Count > 0)
        FUN_00ec7c6b(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return _Result;
}
template <class I, class F, class A> inline F GvUncheckedUninitCopy(I _First, I _Last, F _Dest, A& _Al)
{
    return GvUninitCopy(GvCheckedBase(_First), GvCheckedBase(_Last), _Dest, _Al, GvPtrCat(_First, _Dest),
                        GvRangeCheckedTag());
}
template <class T1, class T2> inline void GvConstruct(T1* _Ptr, const T2& _Val)
{
    void* _Vptr = _Ptr;
    ::new (_Vptr) T1(_Val);
}
struct GvContainer;
struct GvAuxCont
{
    const GvContainer* _Mycontainer;
    GvAuxCont(const GvContainer* _Pcont) : _Mycontainer(_Pcont)
    {}
    const GvContainer* _Getcont() const
    {
        return _Mycontainer;
    }
};
struct GvContainer
{
    GvAuxCont* _Myownedaux;
    GvContainer()
    {}
    GvContainer(const GvContainer&)
    {}
    GvContainer& operator=(const GvContainer&)
    {
        return *this;
    }
    ~GvContainer()
    {}
};
template <class A> struct GvAuxBase : GvContainer
{
    GvAlloc<GvAuxCont> _Alaux;
    explicit GvAuxBase(A _Al) : _Alaux(_Al)
    {
        _Myownedaux = new (_Alaux.allocate(1)) GvAuxCont(this);
    }
    GvAuxBase(const GvAuxBase& _Right) : _Alaux(_Right._Alaux)
    {
        _Myownedaux = new (_Alaux.allocate(1)) GvAuxCont(this);
    }
    ~GvAuxBase()
    {
        _Myownedaux->~GvAuxCont();
        _Alaux.deallocate(_Myownedaux, 1);
    }
};
struct GvIterBase
{
    GvAuxCont* _Myaux;
    GvIterBase() : _Myaux(0)
    {}
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    bool _Same_container(const GvIterBase& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    void _Set_container(const GvContainer* _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const GvContainer* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
};
template <class T> struct GvVector;
template <class T> struct GvConstIterator : GvIterBase
{
    T* _Myptr;
    const T* _Checked_iterator_base() const
    {
        return _Myptr;
    }
    GvConstIterator(T* _Ptr, const GvContainer* _Pvector)
    {
        {
            if (!(_Pvector != 0 && ((GvVector<T>*)_Pvector)->_Myfirst <= _Ptr &&
                  _Ptr <= ((GvVector<T>*)_Pvector)->_Mylast))
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
        }
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    GvConstIterator& operator+=(int _Off)
    {
        {
            if (!this->_Has_container())
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
        }
        {
            if (!(_Myptr + _Off <= ((GvVector<T>*)this->_Getmycont())->_Mylast &&
                  _Myptr + _Off >= ((GvVector<T>*)this->_Getmycont())->_Myfirst))
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
        }
        _Myptr += _Off;
        return *this;
    }
    bool operator==(const GvConstIterator& _Right) const
    {
        {
            if (!(this->_Has_container() && this->_Same_container(_Right)))
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
        }
        do
        {
        } while (0);
        return _Myptr == _Right._Myptr;
    }
    bool operator!=(const GvConstIterator& _Right) const
    {
        return !(*this == _Right);
    }
    int operator-(const GvConstIterator& _Right) const
    {
        {
            if (!(this->_Has_container() && this->_Same_container(_Right)))
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
        }
        return _Myptr - _Right._Myptr;
    }
};
template <class T> struct GvIterator : GvConstIterator<T>
{
    GvIterator(T* _Ptr, const GvContainer* _Pvector) : GvConstIterator<T>(_Ptr, _Pvector)
    {}
    GvIterator& operator+=(int _Off)
    {
        (*(GvConstIterator<T>*)this) += _Off;
        return *this;
    }
    GvIterator operator+(int _Off) const
    {
        GvIterator _Tmp = *this;
        return (_Tmp += _Off);
    }
};
template <class T> struct GvVectorVal : GvAuxBase<GvAlloc<T> >
{
    GvAlloc<T> _Alval;
    GvVectorVal(GvAlloc<T> _Al = GvAlloc<T>()) : GvAuxBase<GvAlloc<T> >(_Al), _Alval(_Al)
    {}
};
template <class T> struct GvVector : GvVectorVal<T>
{
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    GvVector() : GvVectorVal<T>()
    {
        _Buy(0);
    }
    explicit GvVector(unsigned int _Count) : GvVectorVal<T>()
    {
        _Construct_n(_Count, T());
    }
    void _Construct_n(unsigned int _Count, const T& _Val)
    {
        if (_Buy(_Count))
        {
            try
            {
                _Mylast = _Ufill(_Myfirst, _Count, _Val);
            }
            catch (...)
            {
                _Tidy();
                throw;
            }
        }
    }
    GvVector(const GvVector& _Right) : GvVectorVal<T>(_Right._Alval)
    {
        if (_Buy(_Right.size()))
        {
            try
            {
                _Mylast = _Ucopy(_Right.begin(), _Right.end(), _Myfirst);
            }
            catch (...)
            {
                _Tidy();
                throw;
            }
        }
    }
    ~GvVector()
    {
        _Tidy();
    }
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    unsigned int max_size() const
    {
        return this->_Alval.max_size();
    }
    GvIterator<T> begin()
    {
        return GvIterator<T>(_Myfirst, this);
    }
    GvIterator<T> end()
    {
        return GvIterator<T>(_Mylast, this);
    }
    GvConstIterator<T> begin() const
    {
        return GvConstIterator<T>(_Myfirst, this);
    }
    GvConstIterator<T> end() const
    {
        return GvConstIterator<T>(_Mylast, this);
    }
    static void _Xlen()
    {
        throw BxLengthError("vector<T> too long");
    }
    bool _Buy(unsigned int _Capacity)
    {
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
        if (_Capacity == 0)
        {
            return false;
        }
        else if (max_size() < _Capacity)
        {
            _Xlen();
        }
        else
        {
            _Myfirst = this->_Alval.allocate(_Capacity);
            _Mylast = _Myfirst;
            _Myend = _Myfirst + _Capacity;
        }
        return true;
    }
    void _Destroy(T* _First, T* _Last)
    {
        GvDestroyRange(_First, _Last, this->_Alval);
    }
    void _Tidy()
    {
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
    }
    T* _Ufill(T* _Ptr, unsigned int _Count, const T& _Val)
    {
        GvUncheckedFillN(_Ptr, _Count, _Val, this->_Alval);
        return _Ptr + _Count;
    }
    GvIterator<T> _Make_iter(GvConstIterator<T> _Where) const
    {
        return GvIterator<T>(_Where._Myptr, this);
    }
    GvIterator<T> erase(GvConstIterator<T> _First_arg, GvConstIterator<T> _Last_arg)
    {
        GvIterator<T> _First = _Make_iter(_First_arg);
        GvIterator<T> _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            T* _Ptr = GvUncheckedCopy(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return _First;
    }
    void clear()
    {
        erase(begin(), end());
    }
    void resize(unsigned int _Newsize, T _Val)
    {
        if (size() < _Newsize)
            _Insert_n(end(), _Newsize - size(), _Val);
        else if (_Newsize < size())
            erase(begin() + _Newsize, end());
    }
    void resize(unsigned int _Newsize)
    {
        resize(_Newsize, T());
    }
    T& operator[](unsigned int _Pos)
    {
        {
            if (!(_Pos < size()))
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
        }
        return *(_Myfirst + _Pos);
    }
    template <class I> T* _Ucopy(I _First, I _Last, T* _Ptr)
    {
        return GvUncheckedUninitCopy(_First, _Last, _Ptr, this->_Alval);
    }
    GvVector& operator=(const GvVector& _Right)
    {
        if (this != &_Right)
        {
            if (_Right.size() == 0)
            {
                clear();
            }
            else if (_Right.size() <= size())
            {
                T* _Ptr = GvUncheckedCopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
                _Destroy(_Ptr, _Mylast);
                _Mylast = _Myfirst + _Right.size();
            }
            else if (_Right.size() <= capacity())
            {
                T* _Ptr = _Right._Myfirst + size();
                GvUncheckedCopy(_Right._Myfirst, _Ptr, _Myfirst);
                _Mylast = _Ucopy(_Ptr, _Right._Mylast, _Mylast);
            }
            else
            {
                if (_Myfirst != 0)
                {
                    _Destroy(_Myfirst, _Mylast);
                    this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
                }
                if (_Buy(_Right.size()))
                {
                    _Mylast = _Ucopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
                }
            }
        }
        return *this;
    }
    void _Insert_n(GvConstIterator<T> _Where, unsigned int _Count, const T& _Val);
    GvIterator<T> insert(GvConstIterator<T> _Where, const T& _Val)
    {
        unsigned int _Off = size() == 0 ? 0 : _Where - begin();
        _Insert_n(_Where, 1, _Val);
        return begin() + _Off;
    }
    void push_back(const T& _Val)
    {
        if (size() < capacity())
        {
            _Mylast = _Ufill(_Mylast, 1, _Val);
        }
        else
        {
            insert(end(), _Val);
        }
    }
};
}

// @fnv 0x00ad4210
plusad42::BxString FUN_00ad4210(const plusad42::BxString& _Left, const char* _Right)
{
    return plusad42::BxString(_Left) += _Right;
}

namespace rdac52 {
void FUN_00ec7c56();
int FUN_00ec7c66(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
int FUN_00ec7c6b(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
struct BxSecureTag
{
};
struct BxStrTraits
{
    static char* _Copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c66(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static char* _Move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c6b(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static unsigned int length(const char* _First)
    {
        return strlen(_First);
    }
    static int compare(const char* _First1, const char* _First2, unsigned int _Count)
    {
        return memcmp(_First1, _First2, _Count);
    }
    static void assign(char& _Left, const char& _Right)
    {
        _Left = _Right;
    }
};
inline BxSecureTag BxCharTraitsCat()
{
    BxSecureTag _Secure_char_traits;
    return _Secure_char_traits;
}
struct BxTraitsHelper
{
    template <class T>
    static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Copy_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return copy_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
    template <class T>
    static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Move_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return move_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
};
struct BxBadAlloc
{
    const char* pWhat;
    int iDoFree;
    BxBadAlloc(const char* what);
    ~BxBadAlloc();
};
template <class T> inline T* BxAllocate(unsigned int count, T*)
{
    if (count <= 0)
    {
        count = 0;
    }
    else if (((unsigned int)(-1) / count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)::FUN_00401000(count * sizeof(T));
}
template <class T> struct BxAllocT
{
    typedef T* pointer;
    BxAllocT() throw()
    {}
    BxAllocT(const BxAllocT<T>&) throw()
    {}
    pointer allocate(unsigned int _Count)
    {
        return BxAllocate(_Count, (pointer)0);
    }
    pointer allocate(unsigned int _Count, const void*)
    {
        return allocate(_Count);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        ::FUN_00401030(_Ptr);
    }
    unsigned int max_size() const
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
typedef BxAllocT<char> BxCharAlloc;
struct BxStringVal
{
    BxCharAlloc _Alval;
    BxStringVal(BxCharAlloc _Al = BxCharAlloc()) : _Alval(_Al)
    {}
    BxStringVal(const BxStringVal& _Right) : _Alval(_Right._Alval)
    {}
};
struct BxString : public BxStringVal
{
    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    BxString(const char* _Ptr) : BxStringVal()
    {
        _Tidy();
        assign(_Ptr);
    }
    BxString() : BxStringVal()
    {
        _Tidy();
    }
    BxString& operator=(const BxString& _Right)
    {
        return assign(_Right);
    }
    BxString& assign(const BxString& _Right)
    {
        return assign(_Right, 0, ::g_010173f0);
    }
    BxString(const BxString& _Right) : BxStringVal(_Right)
    {
        _Tidy();
        assign(_Right, 0, ::g_010173f0);
    }
    ~BxString()
    {
        _Tidy(true);
    }
    static void _Xlen();
    static void _Xran();
    unsigned int size() const
    {
        return _Mysize;
    }
    char& operator[](unsigned int _Off)
    {
        if (!(_Off <= _Mysize))
        {
            FUN_00ec7c56();
        }
        do
        {
        } while (0);
        return _Myptr()[_Off];
    }
    unsigned int max_size() const
    {
        unsigned int _Num = _Alval.max_size();
        return _Num <= 1 ? 1 : _Num - 1;
    }
    char* _Myptr()
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    const char* _Myptr() const
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    void _Eos(unsigned int _Newsize)
    {
        BxStrTraits::assign(_Myptr()[_Mysize = _Newsize], char());
    }
    BxString& erase(unsigned int _Off = 0, unsigned int _Count = (unsigned int)-1)
    {
        if (_Mysize < _Off)
        {
            _Xran();
        }
        if (_Mysize - _Off < _Count)
        {
            _Count = _Mysize - _Off;
        }
        if (0 < _Count)
        {
            BxTraitsHelper::move_s<BxStrTraits>(_Myptr() + _Off, _Myres - _Off, _Myptr() + _Off + _Count,
                                                _Mysize - _Off - _Count);
            unsigned int _Newsize = _Mysize - _Count;
            _Eos(_Newsize);
        }
        return *this;
    }
    bool _Inside(const char* _Ptr)
    {
        if (_Ptr == 0 || _Ptr < _Myptr() || _Myptr() + _Mysize <= _Ptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void _Tidy(bool _Built = false, unsigned int _Newsize = 0)
    {
        if (!_Built)
        {
        }
        else if (16 <= _Myres)
        {
            char* _Ptr = _Bx._Ptr;
            if (0 < _Newsize)
            {
                BxTraitsHelper::copy_s<BxStrTraits>(_Bx._Buf, 16, _Ptr, _Newsize);
            }
            _Alval.deallocate(_Ptr, _Myres + 1);
        }
        _Myres = 16 - 1;
        _Eos(_Newsize);
    }
    void _Copy(unsigned int _Newsize, unsigned int _Oldlen)
    {
        unsigned int _Newres = _Newsize | 15;
        if (max_size() < _Newres)
        {
            _Newres = _Newsize;
        }
        else if (_Newres / 3 < _Myres / 2 && _Myres <= max_size() - _Myres / 2)
        {
            _Newres = _Myres + _Myres / 2;
        }
        char* _Ptr = 0;
        try
        {
            _Ptr = _Alval.allocate(_Newres + 1);
        }
        catch (...)
        {
            _Newres = _Newsize;
            try
            {
                _Ptr = _Alval.allocate(_Newres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < _Oldlen)
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Ptr, _Newres + 1, _Myptr(), _Oldlen);
        }
        _Tidy(true);
        _Bx._Ptr = _Ptr;
        _Myres = _Newres;
        _Eos(_Oldlen);
    }
    bool _Grow(unsigned int _Newsize, bool _Trim = false)
    {
        if (max_size() < _Newsize)
        {
            _Xlen();
        }
        if (_Myres < _Newsize)
        {
            _Copy(_Newsize, _Mysize);
        }
        else if (_Trim && _Newsize < 16)
        {
            reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, _Newsize < _Mysize ? _Newsize : _Mysize);
        }
        else if (_Newsize == 0)
        {
            _Eos(0);
        }
        return 0 < _Newsize;
    }
    BxString& assign(const BxString& _Right, unsigned int _Roff, unsigned int _Count)
    {
        if (_Right.size() < _Roff)
        {
            _Xran();
        }
        unsigned int _Num = _Right.size() - _Roff;
        if (_Count < _Num)
        {
            _Num = _Count;
        }
        if (this == &_Right)
        {
            erase((unsigned int)(_Roff + _Num)), erase(0, _Roff);
        }
        else if (_Grow(_Num))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Right._Myptr() + _Roff, _Num);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& assign(const char* _Ptr, unsigned int _Count)
    {
        if (_Inside(_Ptr))
        {
            return assign(*this, _Ptr - _Myptr(), _Count);
        }
        if (_Grow(_Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Ptr, _Count);
            _Eos(_Count);
        }
        return *this;
    }
    const char& operator[](unsigned int _Off) const
    {
        if (!(_Off <= _Mysize))
        {
            FUN_00ec7c56();
        }
        return _Myptr()[_Off];
    }
    BxString& append(const BxString& _Right, unsigned int _Roff, unsigned int _Count)
    {
        if (_Right.size() < _Roff)
        {
            _Xran();
        }
        unsigned int _Num = _Right.size() - _Roff;
        if (_Num < _Count)
        {
            _Count = _Num;
        }
        if (::g_010173f0 - _Mysize <= _Count || _Mysize + _Count < _Mysize)
        {
            _Xlen();
        }
        if (0 < _Count && _Grow(_Num = _Mysize + _Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr() + _Mysize, _Myres - _Mysize, _Right._Myptr() + _Roff, _Count);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& append(const char* _Ptr, unsigned int _Count)
    {
        if (_Inside(_Ptr))
        {
            return append(*this, _Ptr - _Myptr(), _Count);
        }
        if (::g_010173f0 - _Mysize <= _Count)
        {
            _Xlen();
        }
        unsigned int _Num;
        if (0 < _Count && _Grow(_Num = _Mysize + _Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr() + _Mysize, _Myres - _Mysize, _Ptr, _Count);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& append(const char* _Ptr)
    {
        return append(_Ptr, BxStrTraits::length(_Ptr));
    }
    BxString& operator+=(const char* _Ptr)
    {
        return append(_Ptr);
    }
    const char* c_str() const
    {
        return _Myptr();
    }
    int compare(unsigned int _Off, unsigned int _N0, const char* _Ptr, unsigned int _Count) const
    {
        if (_Mysize < _Off)
            _Xran();
        if (_Mysize - _Off < _N0)
            _N0 = _Mysize - _Off;
        unsigned int _Ans = BxStrTraits::compare(_Myptr() + _Off, _Ptr, _N0 < _Count ? _N0 : _Count);
        return _Ans != 0 ? (int)_Ans : _N0 < _Count ? -1 : _N0 == _Count ? 0 : +1;
    }
    int compare(const char* _Ptr) const
    {
        return compare(0, _Mysize, _Ptr, BxStrTraits::length(_Ptr));
    }
    BxString& assign(const char* _Ptr)
    {
        return assign(_Ptr, BxStrTraits::length(_Ptr));
    }
};
inline bool operator==(const BxString& _Left, const char* _Right)
{
    return _Left.compare(_Right) == 0;
}
inline bool operator!=(const BxString& _Left, const char* _Right)
{
    return !(_Left == _Right);
}
struct BxException
{
    const char* _m_what;
    int _m_doFree;
    BxException();
    BxException(const BxException& _That);
    virtual ~BxException();
    virtual const char* what() const;
};
struct BxLogicError : public BxException
{
    BxString _Str;
    explicit BxLogicError(const BxString& _Message) : _Str(_Message)
    {}
    virtual ~BxLogicError()
    {}
    virtual const char* what() const
    {
        return _Str._Myptr();
    }
};
struct BxLengthError : public BxLogicError
{
    explicit BxLengthError(const BxString& _Message) : BxLogicError(_Message)
    {}
    virtual ~BxLengthError()
    {}
};

struct GvHeap
{
    void* FUN_00aa3e40(unsigned int _Size);
    void FUN_00aa4060(void* _Ptr);
};
template <class T> inline T* GvHeapAllocate(unsigned int _Count, T*)
{
    if (_Count <= 0)
    {
        _Count = 0;
    }
    else if (((unsigned int)(-1) / _Count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)((GvHeap*)&(*reinterpret_cast<int *>(&::g_memoryManager)))->FUN_00aa3e40(_Count * sizeof(T));
}
template <class T> inline void GvDestroyOne(T* _Ptr)
{
    _Ptr->~T();
}
template <class T> struct GvAlloc
{
    typedef T* pointer;
    GvAlloc() throw()
    {}
    GvAlloc(const GvAlloc<T>&) throw()
    {}
    template <class O> GvAlloc(const GvAlloc<O>&) throw()
    {}
    pointer allocate(unsigned int _Count)
    {
        return GvHeapAllocate(_Count, (pointer)0);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        ((GvHeap*)&(*reinterpret_cast<int *>(&::g_memoryManager)))->FUN_00aa4060(_Ptr);
    }
    void destroy(pointer _Ptr)
    {
        GvDestroyOne(_Ptr);
    }
    void construct(pointer _Ptr, const T& _Val)
    {
        GvConstruct(_Ptr, _Val);
    }
    unsigned int max_size() const throw()
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
struct GvNonscalarTag
{
};
struct GvScalarTag
{
};
struct GvRangeCheckedTag
{
};
template <class T1, class T2> struct GvPtrCatHelper
{
    typedef GvNonscalarTag _Ptr_cat;
};
template <> struct GvPtrCatHelper<char*, char*>
{
    typedef GvScalarTag _Ptr_cat;
};
template <> struct GvPtrCatHelper<unsigned short*, unsigned short*>
{
    typedef GvScalarTag _Ptr_cat;
};
template <class T> struct GvPtrCatHelper<T**, T**>
{
    typedef GvScalarTag _Ptr_cat;
};
template <class T1, class T2> inline typename GvPtrCatHelper<T1, T2>::_Ptr_cat GvPtrCat(T1&, T2&)
{
    typename GvPtrCatHelper<T1, T2>::_Ptr_cat _Cat;
    return _Cat;
}
template <class A> inline void GvDestroyRange(typename A::pointer, typename A::pointer, A&, GvScalarTag)
{}
template <class T, class A>
void GvUninitFillN(T* _First, unsigned int _Count, const T& _Val, A& _Al, GvNonscalarTag, GvRangeCheckedTag);
template <class T, class A> inline void GvUncheckedFillN(T* _First, unsigned int _Count, const T& _Val, A& _Al)
{
    GvUninitFillN(_First, _Count, _Val, _Al, GvPtrCat(_First, _First), GvRangeCheckedTag());
}
template <class A>
inline void GvDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al, GvNonscalarTag)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class A> inline void GvDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al)
{
    GvDestroyRange<A>(_First, _Last, _Al, GvPtrCat(_First, _Last));
}
struct GvInputTag
{
};
struct GvForwardTag : GvInputTag
{
};
struct GvBidiTag : GvForwardTag
{
};
struct GvRandomTag : GvBidiTag
{
};
struct GvUnchangedTag
{
};
template <class I1, class I2> inline GvRandomTag GvIterRandom(const I1&, const I2&)
{
    GvRandomTag _Cat;
    return _Cat;
}
struct GvBaseTag
{
};
template <class T> struct GvConstIterator;
template <class I> struct GvCheckedHelper
{
    typedef GvUnchangedTag _Tag;
    typedef I _Base;
};
template <class T> struct GvCheckedHelper<GvConstIterator<T> >
{
    typedef GvBaseTag _Tag;
    typedef const T* _Base;
};
template <class I, class B> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It, B)
{
    return _It._Checked_iterator_base();
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I, class B> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It, B)
{
    return _It._Checked_iterator_base();
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It)
{
    typename GvCheckedHelper<I>::_Tag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It)
{
    typename GvCheckedHelper<I>::_Tag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
}
template <class O, class D, class T> inline void GvFillN(O _First, D _Count, const T& _Val, GvRangeCheckedTag)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class O, class D, class T, class C>
inline void GvFillN(O _First, D _Count, const T& _Val, C, GvRangeCheckedTag)
{
    GvFillN(_First, _Count, _Val, GvRangeCheckedTag());
}
template <class O, class D, class T>
inline void GvFillN(O _First, D _Count, const T& _Val, GvRandomTag, GvRangeCheckedTag)
{
    O _Last = _First + _Count;
    (void)_Last;
    GvFillN(GvCheckedBase(_First), _Count, _Val, GvRangeCheckedTag());
}
template <class I> inline GvRandomTag GvIterCat(const I&)
{
    GvRandomTag _Cat;
    return _Cat;
}
template <class O, class D, class T> inline void GvUncheckedFillValues(O _First, D _Count, const T& _Val)
{
    GvFillN(_First, _Count, _Val, GvIterCat(_First), GvRangeCheckedTag());
}
template <class T, class A>
inline void GvUninitFillN(T* _First, unsigned int _Count, const T& _Val, A&, GvScalarTag, GvRangeCheckedTag)
{
    GvUncheckedFillValues(_First, _Count, _Val);
}
template <class I, class O, class C>
inline O GvCopyOpt(I _First, I _Last, O _Dest, C, GvNonscalarTag, GvRangeCheckedTag)
{
    for (; _First != _Last; ++_Dest, ++_First)
    {
        *_Dest = *_First;
    }
    return _Dest;
}
template <class I, class O>
inline O GvCopyOpt(I _First, I _Last, O _Dest, GvRandomTag, GvNonscalarTag, GvRangeCheckedTag)
{
    O _Result = _Dest + (_Last - _First);
    GvCopyOpt(_First, _Last, GvCheckedBase(_Dest), GvForwardTag(), GvNonscalarTag(), GvRangeCheckedTag());
    return _Result;
}
template <class I, class O, class C> inline O GvCopyOpt(I _First, I _Last, O _Dest, C, GvScalarTag, GvRangeCheckedTag)
{
    int _Off = _Last - _First;
    O _Result = _Dest + _Off;
    if (_Off > 0)
        FUN_00ec7c6b(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class I, class O> inline O GvUncheckedCopy(I _First, I _Last, O _Dest)
{
    return GvCopyOpt(GvCheckedBase(_First), GvCheckedBase(_Last), _Dest, GvIterRandom(_First, _Dest),
                     GvPtrCat(_First, _Dest), GvRangeCheckedTag());
}
template <class I, class F, class A>
inline F GvUninitCopy(I _First, I _Last, F _Dest, A& _Al, GvNonscalarTag, GvRangeCheckedTag)
{
    F _Next = _Dest;
    try
    {
        for (; _First != _Last; ++_Dest, ++_First)
        {
            _Al.construct(_Dest, *_First);
        }
    }
    catch (...)
    {
        for (; _Next != _Dest; ++_Next)
        {
            _Al.destroy(_Next);
        }
        throw;
    }
    return _Dest;
}
template <class I, class F, class A>
inline F GvUninitCopy(I _First, I _Last, F _Dest, A&, GvScalarTag, GvRangeCheckedTag)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    F _Result = _Dest + _Count;
    if (_Count > 0)
        FUN_00ec7c6b(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return _Result;
}
template <class I, class F, class A> inline F GvUncheckedUninitCopy(I _First, I _Last, F _Dest, A& _Al)
{
    return GvUninitCopy(GvCheckedBase(_First), GvCheckedBase(_Last), _Dest, _Al, GvPtrCat(_First, _Dest),
                        GvRangeCheckedTag());
}
template <class T1, class T2> inline void GvConstruct(T1* _Ptr, const T2& _Val)
{
    void* _Vptr = _Ptr;
    ::new (_Vptr) T1(_Val);
}
struct GvContainer;
struct GvAuxCont
{
    const GvContainer* _Mycontainer;
    GvAuxCont(const GvContainer* _Pcont) : _Mycontainer(_Pcont)
    {}
    const GvContainer* _Getcont() const
    {
        return _Mycontainer;
    }
};
struct GvContainer
{
    GvAuxCont* _Myownedaux;
    GvContainer()
    {}
    GvContainer(const GvContainer&)
    {}
    GvContainer& operator=(const GvContainer&)
    {
        return *this;
    }
    ~GvContainer()
    {}
};
template <class A> struct GvAuxBase : GvContainer
{
    GvAlloc<GvAuxCont> _Alaux;
    explicit GvAuxBase(A _Al) : _Alaux(_Al)
    {
        _Myownedaux = new (_Alaux.allocate(1)) GvAuxCont(this);
    }
    GvAuxBase(const GvAuxBase& _Right) : _Alaux(_Right._Alaux)
    {
        _Myownedaux = new (_Alaux.allocate(1)) GvAuxCont(this);
    }
    ~GvAuxBase()
    {
        _Myownedaux->~GvAuxCont();
        _Alaux.deallocate(_Myownedaux, 1);
    }
};
struct GvIterBase
{
    GvAuxCont* _Myaux;
    GvIterBase() : _Myaux(0)
    {}
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    bool _Same_container(const GvIterBase& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    void _Set_container(const GvContainer* _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const GvContainer* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
};
template <class T> struct GvVector;
template <class T> struct GvConstIterator : GvIterBase
{
    T* _Myptr;
    const T* _Checked_iterator_base() const
    {
        return _Myptr;
    }
    GvConstIterator(T* _Ptr, const GvContainer* _Pvector)
    {
        {
            if (!(_Pvector != 0 && ((GvVector<T>*)_Pvector)->_Myfirst <= _Ptr &&
                  _Ptr <= ((GvVector<T>*)_Pvector)->_Mylast))
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
        }
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    GvConstIterator& operator+=(int _Off)
    {
        {
            if (!this->_Has_container())
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
        }
        {
            if (!(_Myptr + _Off <= ((GvVector<T>*)this->_Getmycont())->_Mylast &&
                  _Myptr + _Off >= ((GvVector<T>*)this->_Getmycont())->_Myfirst))
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
        }
        _Myptr += _Off;
        return *this;
    }
    bool operator==(const GvConstIterator& _Right) const
    {
        {
            if (!(this->_Has_container() && this->_Same_container(_Right)))
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
        }
        do
        {
        } while (0);
        return _Myptr == _Right._Myptr;
    }
    bool operator!=(const GvConstIterator& _Right) const
    {
        return !(*this == _Right);
    }
    int operator-(const GvConstIterator& _Right) const
    {
        {
            if (!(this->_Has_container() && this->_Same_container(_Right)))
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
        }
        return _Myptr - _Right._Myptr;
    }
};
template <class T> struct GvIterator : GvConstIterator<T>
{
    GvIterator(T* _Ptr, const GvContainer* _Pvector) : GvConstIterator<T>(_Ptr, _Pvector)
    {}
    GvIterator& operator+=(int _Off)
    {
        (*(GvConstIterator<T>*)this) += _Off;
        return *this;
    }
    GvIterator operator+(int _Off) const
    {
        GvIterator _Tmp = *this;
        return (_Tmp += _Off);
    }
};
template <class T> struct GvVectorVal : GvAuxBase<GvAlloc<T> >
{
    GvAlloc<T> _Alval;
    GvVectorVal(GvAlloc<T> _Al = GvAlloc<T>()) : GvAuxBase<GvAlloc<T> >(_Al), _Alval(_Al)
    {}
};
template <class T> struct GvVector : GvVectorVal<T>
{
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    GvVector() : GvVectorVal<T>()
    {
        _Buy(0);
    }
    explicit GvVector(unsigned int _Count) : GvVectorVal<T>()
    {
        _Construct_n(_Count, T());
    }
    void _Construct_n(unsigned int _Count, const T& _Val)
    {
        if (_Buy(_Count))
        {
            try
            {
                _Mylast = _Ufill(_Myfirst, _Count, _Val);
            }
            catch (...)
            {
                _Tidy();
                throw;
            }
        }
    }
    GvVector(const GvVector& _Right) : GvVectorVal<T>(_Right._Alval)
    {
        if (_Buy(_Right.size()))
        {
            try
            {
                _Mylast = _Ucopy(_Right.begin(), _Right.end(), _Myfirst);
            }
            catch (...)
            {
                _Tidy();
                throw;
            }
        }
    }
    ~GvVector()
    {
        _Tidy();
    }
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    unsigned int max_size() const
    {
        return this->_Alval.max_size();
    }
    GvIterator<T> begin()
    {
        return GvIterator<T>(_Myfirst, this);
    }
    GvIterator<T> end()
    {
        return GvIterator<T>(_Mylast, this);
    }
    GvConstIterator<T> begin() const
    {
        return GvConstIterator<T>(_Myfirst, this);
    }
    GvConstIterator<T> end() const
    {
        return GvConstIterator<T>(_Mylast, this);
    }
    static void _Xlen()
    {
        throw BxLengthError("vector<T> too long");
    }
    bool _Buy(unsigned int _Capacity)
    {
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
        if (_Capacity == 0)
        {
            return false;
        }
        else if (max_size() < _Capacity)
        {
            _Xlen();
        }
        else
        {
            _Myfirst = this->_Alval.allocate(_Capacity);
            _Mylast = _Myfirst;
            _Myend = _Myfirst + _Capacity;
        }
        return true;
    }
    void _Destroy(T* _First, T* _Last)
    {
        GvDestroyRange(_First, _Last, this->_Alval);
    }
    void _Tidy()
    {
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
    }
    T* _Ufill(T* _Ptr, unsigned int _Count, const T& _Val)
    {
        GvUncheckedFillN(_Ptr, _Count, _Val, this->_Alval);
        return _Ptr + _Count;
    }
    GvIterator<T> _Make_iter(GvConstIterator<T> _Where) const
    {
        return GvIterator<T>(_Where._Myptr, this);
    }
    GvIterator<T> erase(GvConstIterator<T> _First_arg, GvConstIterator<T> _Last_arg)
    {
        GvIterator<T> _First = _Make_iter(_First_arg);
        GvIterator<T> _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            T* _Ptr = GvUncheckedCopy(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return _First;
    }
    void clear()
    {
        erase(begin(), end());
    }
    void resize(unsigned int _Newsize, T _Val)
    {
        if (size() < _Newsize)
            _Insert_n(end(), _Newsize - size(), _Val);
        else if (_Newsize < size())
            erase(begin() + _Newsize, end());
    }
    void resize(unsigned int _Newsize)
    {
        resize(_Newsize, T());
    }
    T& operator[](unsigned int _Pos)
    {
        {
            if (!(_Pos < size()))
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
        }
        return *(_Myfirst + _Pos);
    }
    template <class I> T* _Ucopy(I _First, I _Last, T* _Ptr)
    {
        return GvUncheckedUninitCopy(_First, _Last, _Ptr, this->_Alval);
    }
    GvVector& operator=(const GvVector& _Right)
    {
        if (this != &_Right)
        {
            if (_Right.size() == 0)
            {
                clear();
            }
            else if (_Right.size() <= size())
            {
                T* _Ptr = GvUncheckedCopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
                _Destroy(_Ptr, _Mylast);
                _Mylast = _Myfirst + _Right.size();
            }
            else if (_Right.size() <= capacity())
            {
                T* _Ptr = _Right._Myfirst + size();
                GvUncheckedCopy(_Right._Myfirst, _Ptr, _Myfirst);
                _Mylast = _Ucopy(_Ptr, _Right._Mylast, _Mylast);
            }
            else
            {
                if (_Myfirst != 0)
                {
                    _Destroy(_Myfirst, _Mylast);
                    this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
                }
                if (_Buy(_Right.size()))
                {
                    _Mylast = _Ucopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
                }
            }
        }
        return *this;
    }
    void _Insert_n(GvConstIterator<T> _Where, unsigned int _Count, const T& _Val);
    GvIterator<T> insert(GvConstIterator<T> _Where, const T& _Val)
    {
        unsigned int _Off = size() == 0 ? 0 : _Where - begin();
        _Insert_n(_Where, 1, _Val);
        return begin() + _Off;
    }
    void push_back(const T& _Val)
    {
        if (size() < capacity())
        {
            _Mylast = _Ufill(_Mylast, 1, _Val);
        }
        else
        {
            insert(end(), _Val);
        }
    }
};
struct GvFileHandle;
void FUN_00ac6430(int code, BxString message);
}

struct GvBinaryFile_SV
{
    rdac52::BxString kPath;
    rdac52::BxString kMagic;
    rdac52::GvFileHandle* pFile;
    virtual void v00();
    bool FUN_00ac52b0(void* data, unsigned int size, unsigned int count);
};

// @fnv 0x00ac52b0
bool GvBinaryFile_SV::FUN_00ac52b0(void* data, unsigned int size, unsigned int count)
{
    if (pFile == 0)
    {
        return false;
    }
    if (fread(data, size, count, (FILE*)pFile) != count)
    {
        rdac52::FUN_00ac6430(1, kPath);
        reinterpret_cast<::FUN_00ac5430_cls *>(this)->FUN_00ac5430();
        return false;
    }
    return true;
}

namespace plus2ad4 {
void FUN_00ec7c56();
int FUN_00ec7c66(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
int FUN_00ec7c6b(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
struct BxSecureTag
{
};
struct BxStrTraits
{
    static char* _Copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c66(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static char* _Move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c6b(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static unsigned int length(const char* _First)
    {
        return strlen(_First);
    }
    static int compare(const char* _First1, const char* _First2, unsigned int _Count)
    {
        return memcmp(_First1, _First2, _Count);
    }
    static void assign(char& _Left, const char& _Right)
    {
        _Left = _Right;
    }
};
inline BxSecureTag BxCharTraitsCat()
{
    BxSecureTag _Secure_char_traits;
    return _Secure_char_traits;
}
struct BxTraitsHelper
{
    template <class T>
    static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Copy_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return copy_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
    template <class T>
    static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Move_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return move_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
};
struct BxBadAlloc
{
    const char* pWhat;
    int iDoFree;
    BxBadAlloc(const char* what);
    ~BxBadAlloc();
};
template <class T> inline T* BxAllocate(unsigned int count, T*)
{
    if (count <= 0)
    {
        count = 0;
    }
    else if (((unsigned int)(-1) / count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)::FUN_00401000(count * sizeof(T));
}
template <class T> struct BxAllocT
{
    typedef T* pointer;
    BxAllocT() throw()
    {}
    BxAllocT(const BxAllocT<T>&) throw()
    {}
    pointer allocate(unsigned int _Count)
    {
        return BxAllocate(_Count, (pointer)0);
    }
    pointer allocate(unsigned int _Count, const void*)
    {
        return allocate(_Count);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        ::FUN_00401030(_Ptr);
    }
    unsigned int max_size() const
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
typedef BxAllocT<char> BxCharAlloc;
struct BxStringVal
{
    BxCharAlloc _Alval;
    BxStringVal(BxCharAlloc _Al = BxCharAlloc()) : _Alval(_Al)
    {}
    BxStringVal(const BxStringVal& _Right) : _Alval(_Right._Alval)
    {}
};
struct BxString : public BxStringVal
{
    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    BxString(const char* _Ptr) : BxStringVal()
    {
        _Tidy();
        assign(_Ptr);
    }
    BxString() : BxStringVal()
    {
        _Tidy();
    }
    BxString& operator=(const BxString& _Right)
    {
        return assign(_Right);
    }
    BxString& assign(const BxString& _Right)
    {
        return assign(_Right, 0, ::g_010173f0);
    }
    BxString(const BxString& _Right) : BxStringVal(_Right)
    {
        _Tidy();
        assign(_Right, 0, ::g_010173f0);
    }
    ~BxString()
    {
        _Tidy(true);
    }
    static void _Xlen();
    static void _Xran();
    unsigned int size() const
    {
        return _Mysize;
    }
    char& operator[](unsigned int _Off)
    {
        if (!(_Off <= _Mysize))
        {
            FUN_00ec7c56();
        }
        do
        {
        } while (0);
        return _Myptr()[_Off];
    }
    unsigned int max_size() const
    {
        unsigned int _Num = _Alval.max_size();
        return _Num <= 1 ? 1 : _Num - 1;
    }
    char* _Myptr()
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    const char* _Myptr() const
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    void _Eos(unsigned int _Newsize)
    {
        BxStrTraits::assign(_Myptr()[_Mysize = _Newsize], char());
    }
    BxString& erase(unsigned int _Off = 0, unsigned int _Count = (unsigned int)-1)
    {
        if (_Mysize < _Off)
        {
            _Xran();
        }
        if (_Mysize - _Off < _Count)
        {
            _Count = _Mysize - _Off;
        }
        if (0 < _Count)
        {
            BxTraitsHelper::move_s<BxStrTraits>(_Myptr() + _Off, _Myres - _Off, _Myptr() + _Off + _Count,
                                                _Mysize - _Off - _Count);
            unsigned int _Newsize = _Mysize - _Count;
            _Eos(_Newsize);
        }
        return *this;
    }
    bool _Inside(const char* _Ptr)
    {
        if (_Ptr == 0 || _Ptr < _Myptr() || _Myptr() + _Mysize <= _Ptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void _Tidy(bool _Built = false, unsigned int _Newsize = 0)
    {
        if (!_Built)
        {
        }
        else if (16 <= _Myres)
        {
            char* _Ptr = _Bx._Ptr;
            if (0 < _Newsize)
            {
                BxTraitsHelper::copy_s<BxStrTraits>(_Bx._Buf, 16, _Ptr, _Newsize);
            }
            _Alval.deallocate(_Ptr, _Myres + 1);
        }
        _Myres = 16 - 1;
        _Eos(_Newsize);
    }
    void _Copy(unsigned int _Newsize, unsigned int _Oldlen)
    {
        unsigned int _Newres = _Newsize | 15;
        if (max_size() < _Newres)
        {
            _Newres = _Newsize;
        }
        else if (_Newres / 3 < _Myres / 2 && _Myres <= max_size() - _Myres / 2)
        {
            _Newres = _Myres + _Myres / 2;
        }
        char* _Ptr = 0;
        try
        {
            _Ptr = _Alval.allocate(_Newres + 1);
        }
        catch (...)
        {
            _Newres = _Newsize;
            try
            {
                _Ptr = _Alval.allocate(_Newres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < _Oldlen)
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Ptr, _Newres + 1, _Myptr(), _Oldlen);
        }
        _Tidy(true);
        _Bx._Ptr = _Ptr;
        _Myres = _Newres;
        _Eos(_Oldlen);
    }
    bool _Grow(unsigned int _Newsize, bool _Trim = false)
    {
        if (max_size() < _Newsize)
        {
            _Xlen();
        }
        if (_Myres < _Newsize)
        {
            _Copy(_Newsize, _Mysize);
        }
        else if (_Trim && _Newsize < 16)
        {
            reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, _Newsize < _Mysize ? _Newsize : _Mysize);
        }
        else if (_Newsize == 0)
        {
            _Eos(0);
        }
        return 0 < _Newsize;
    }
    BxString& assign(const BxString& _Right, unsigned int _Roff, unsigned int _Count)
    {
        if (_Right.size() < _Roff)
        {
            _Xran();
        }
        unsigned int _Num = _Right.size() - _Roff;
        if (_Count < _Num)
        {
            _Num = _Count;
        }
        if (this == &_Right)
        {
            erase((unsigned int)(_Roff + _Num)), erase(0, _Roff);
        }
        else if (_Grow(_Num))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Right._Myptr() + _Roff, _Num);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& assign(const char* _Ptr, unsigned int _Count)
    {
        if (_Inside(_Ptr))
        {
            return assign(*this, _Ptr - _Myptr(), _Count);
        }
        if (_Grow(_Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Ptr, _Count);
            _Eos(_Count);
        }
        return *this;
    }
    const char& operator[](unsigned int _Off) const
    {
        if (!(_Off <= _Mysize))
        {
            FUN_00ec7c56();
        }
        return _Myptr()[_Off];
    }
    BxString& append(const BxString& _Right, unsigned int _Roff, unsigned int _Count)
    {
        if (_Right.size() < _Roff)
        {
            _Xran();
        }
        unsigned int _Num = _Right.size() - _Roff;
        if (_Num < _Count)
        {
            _Count = _Num;
        }
        if (::g_010173f0 - _Mysize <= _Count || _Mysize + _Count < _Mysize)
        {
            _Xlen();
        }
        if (0 < _Count && _Grow(_Num = _Mysize + _Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr() + _Mysize, _Myres - _Mysize, _Right._Myptr() + _Roff, _Count);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& append(const char* _Ptr, unsigned int _Count)
    {
        if (_Inside(_Ptr))
        {
            return (*(::plus2ad4::BxString *)&(reinterpret_cast<::StrB *>(this)->FUN_00a0c570((const ::StrB &)(*this), _Ptr - _Myptr(), _Count)));
        }
        if (::g_010173f0 - _Mysize <= _Count)
        {
            _Xlen();
        }
        unsigned int _Num;
        if (0 < _Count && _Grow(_Num = _Mysize + _Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr() + _Mysize, _Myres - _Mysize, _Ptr, _Count);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& append(const char* _Ptr)
    {
        return append(_Ptr, BxStrTraits::length(_Ptr));
    }
    BxString& operator+=(const char* _Ptr)
    {
        return append(_Ptr);
    }
    BxString& append(const BxString& _Right)
    {
        return (*(::plus2ad4::BxString *)&(reinterpret_cast<::StrB *>(this)->FUN_00a0c570((const ::StrB &)(_Right), 0, (unsigned int)-1)));
    }
    BxString& operator+=(const BxString& _Right)
    {
        return append(_Right);
    }
    const char* c_str() const
    {
        return _Myptr();
    }
    int compare(unsigned int _Off, unsigned int _N0, const char* _Ptr, unsigned int _Count) const
    {
        if (_Mysize < _Off)
            _Xran();
        if (_Mysize - _Off < _N0)
            _N0 = _Mysize - _Off;
        unsigned int _Ans = BxStrTraits::compare(_Myptr() + _Off, _Ptr, _N0 < _Count ? _N0 : _Count);
        return _Ans != 0 ? (int)_Ans : _N0 < _Count ? -1 : _N0 == _Count ? 0 : +1;
    }
    int compare(const char* _Ptr) const
    {
        return compare(0, _Mysize, _Ptr, BxStrTraits::length(_Ptr));
    }
    BxString& assign(const char* _Ptr)
    {
        return assign(_Ptr, BxStrTraits::length(_Ptr));
    }
};
inline bool operator==(const BxString& _Left, const char* _Right)
{
    return _Left.compare(_Right) == 0;
}
inline bool operator!=(const BxString& _Left, const char* _Right)
{
    return !(_Left == _Right);
}
struct BxException
{
    const char* _m_what;
    int _m_doFree;
    BxException();
    BxException(const BxException& _That);
    virtual ~BxException();
    virtual const char* what() const;
};
struct BxLogicError : public BxException
{
    BxString _Str;
    explicit BxLogicError(const BxString& _Message) : _Str(_Message)
    {}
    virtual ~BxLogicError()
    {}
    virtual const char* what() const
    {
        return _Str._Myptr();
    }
};
struct BxLengthError : public BxLogicError
{
    explicit BxLengthError(const BxString& _Message) : BxLogicError(_Message)
    {}
    virtual ~BxLengthError()
    {}
};

struct GvHeap
{
    void* FUN_00aa3e40(unsigned int _Size);
    void FUN_00aa4060(void* _Ptr);
};
template <class T> inline T* GvHeapAllocate(unsigned int _Count, T*)
{
    if (_Count <= 0)
    {
        _Count = 0;
    }
    else if (((unsigned int)(-1) / _Count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)((GvHeap*)&(*reinterpret_cast<int *>(&::g_memoryManager)))->FUN_00aa3e40(_Count * sizeof(T));
}
template <class T> inline void GvDestroyOne(T* _Ptr)
{
    _Ptr->~T();
}
template <class T> struct GvAlloc
{
    typedef T* pointer;
    GvAlloc() throw()
    {}
    GvAlloc(const GvAlloc<T>&) throw()
    {}
    template <class O> GvAlloc(const GvAlloc<O>&) throw()
    {}
    pointer allocate(unsigned int _Count)
    {
        return GvHeapAllocate(_Count, (pointer)0);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        ((GvHeap*)&(*reinterpret_cast<int *>(&::g_memoryManager)))->FUN_00aa4060(_Ptr);
    }
    void destroy(pointer _Ptr)
    {
        GvDestroyOne(_Ptr);
    }
    void construct(pointer _Ptr, const T& _Val)
    {
        GvConstruct(_Ptr, _Val);
    }
    unsigned int max_size() const throw()
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
struct GvNonscalarTag
{
};
struct GvScalarTag
{
};
struct GvRangeCheckedTag
{
};
template <class T1, class T2> struct GvPtrCatHelper
{
    typedef GvNonscalarTag _Ptr_cat;
};
template <> struct GvPtrCatHelper<char*, char*>
{
    typedef GvScalarTag _Ptr_cat;
};
template <> struct GvPtrCatHelper<unsigned short*, unsigned short*>
{
    typedef GvScalarTag _Ptr_cat;
};
template <class T> struct GvPtrCatHelper<T**, T**>
{
    typedef GvScalarTag _Ptr_cat;
};
template <class T1, class T2> inline typename GvPtrCatHelper<T1, T2>::_Ptr_cat GvPtrCat(T1&, T2&)
{
    typename GvPtrCatHelper<T1, T2>::_Ptr_cat _Cat;
    return _Cat;
}
template <class A> inline void GvDestroyRange(typename A::pointer, typename A::pointer, A&, GvScalarTag)
{}
template <class T, class A>
void GvUninitFillN(T* _First, unsigned int _Count, const T& _Val, A& _Al, GvNonscalarTag, GvRangeCheckedTag);
template <class T, class A> inline void GvUncheckedFillN(T* _First, unsigned int _Count, const T& _Val, A& _Al)
{
    GvUninitFillN(_First, _Count, _Val, _Al, GvPtrCat(_First, _First), GvRangeCheckedTag());
}
template <class A>
inline void GvDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al, GvNonscalarTag)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class A> inline void GvDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al)
{
    GvDestroyRange<A>(_First, _Last, _Al, GvPtrCat(_First, _Last));
}
struct GvInputTag
{
};
struct GvForwardTag : GvInputTag
{
};
struct GvBidiTag : GvForwardTag
{
};
struct GvRandomTag : GvBidiTag
{
};
struct GvUnchangedTag
{
};
template <class I1, class I2> inline GvRandomTag GvIterRandom(const I1&, const I2&)
{
    GvRandomTag _Cat;
    return _Cat;
}
struct GvBaseTag
{
};
template <class T> struct GvConstIterator;
template <class I> struct GvCheckedHelper
{
    typedef GvUnchangedTag _Tag;
    typedef I _Base;
};
template <class T> struct GvCheckedHelper<GvConstIterator<T> >
{
    typedef GvBaseTag _Tag;
    typedef const T* _Base;
};
template <class I, class B> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It, B)
{
    return _It._Checked_iterator_base();
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I, class B> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It, B)
{
    return _It._Checked_iterator_base();
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It)
{
    typename GvCheckedHelper<I>::_Tag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It)
{
    typename GvCheckedHelper<I>::_Tag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
}
template <class O, class D, class T> inline void GvFillN(O _First, D _Count, const T& _Val, GvRangeCheckedTag)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class O, class D, class T, class C>
inline void GvFillN(O _First, D _Count, const T& _Val, C, GvRangeCheckedTag)
{
    GvFillN(_First, _Count, _Val, GvRangeCheckedTag());
}
template <class O, class D, class T>
inline void GvFillN(O _First, D _Count, const T& _Val, GvRandomTag, GvRangeCheckedTag)
{
    O _Last = _First + _Count;
    (void)_Last;
    GvFillN(GvCheckedBase(_First), _Count, _Val, GvRangeCheckedTag());
}
template <class I> inline GvRandomTag GvIterCat(const I&)
{
    GvRandomTag _Cat;
    return _Cat;
}
template <class O, class D, class T> inline void GvUncheckedFillValues(O _First, D _Count, const T& _Val)
{
    GvFillN(_First, _Count, _Val, GvIterCat(_First), GvRangeCheckedTag());
}
template <class T, class A>
inline void GvUninitFillN(T* _First, unsigned int _Count, const T& _Val, A&, GvScalarTag, GvRangeCheckedTag)
{
    GvUncheckedFillValues(_First, _Count, _Val);
}
template <class I, class O, class C>
inline O GvCopyOpt(I _First, I _Last, O _Dest, C, GvNonscalarTag, GvRangeCheckedTag)
{
    for (; _First != _Last; ++_Dest, ++_First)
    {
        *_Dest = *_First;
    }
    return _Dest;
}
template <class I, class O>
inline O GvCopyOpt(I _First, I _Last, O _Dest, GvRandomTag, GvNonscalarTag, GvRangeCheckedTag)
{
    O _Result = _Dest + (_Last - _First);
    GvCopyOpt(_First, _Last, GvCheckedBase(_Dest), GvForwardTag(), GvNonscalarTag(), GvRangeCheckedTag());
    return _Result;
}
template <class I, class O, class C> inline O GvCopyOpt(I _First, I _Last, O _Dest, C, GvScalarTag, GvRangeCheckedTag)
{
    int _Off = _Last - _First;
    O _Result = _Dest + _Off;
    if (_Off > 0)
        FUN_00ec7c6b(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class I, class O> inline O GvUncheckedCopy(I _First, I _Last, O _Dest)
{
    return GvCopyOpt(GvCheckedBase(_First), GvCheckedBase(_Last), _Dest, GvIterRandom(_First, _Dest),
                     GvPtrCat(_First, _Dest), GvRangeCheckedTag());
}
template <class I, class F, class A>
inline F GvUninitCopy(I _First, I _Last, F _Dest, A& _Al, GvNonscalarTag, GvRangeCheckedTag)
{
    F _Next = _Dest;
    try
    {
        for (; _First != _Last; ++_Dest, ++_First)
        {
            _Al.construct(_Dest, *_First);
        }
    }
    catch (...)
    {
        for (; _Next != _Dest; ++_Next)
        {
            _Al.destroy(_Next);
        }
        throw;
    }
    return _Dest;
}
template <class I, class F, class A>
inline F GvUninitCopy(I _First, I _Last, F _Dest, A&, GvScalarTag, GvRangeCheckedTag)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    F _Result = _Dest + _Count;
    if (_Count > 0)
        FUN_00ec7c6b(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return _Result;
}
template <class I, class F, class A> inline F GvUncheckedUninitCopy(I _First, I _Last, F _Dest, A& _Al)
{
    return GvUninitCopy(GvCheckedBase(_First), GvCheckedBase(_Last), _Dest, _Al, GvPtrCat(_First, _Dest),
                        GvRangeCheckedTag());
}
template <class T1, class T2> inline void GvConstruct(T1* _Ptr, const T2& _Val)
{
    void* _Vptr = _Ptr;
    ::new (_Vptr) T1(_Val);
}
struct GvContainer;
struct GvAuxCont
{
    const GvContainer* _Mycontainer;
    GvAuxCont(const GvContainer* _Pcont) : _Mycontainer(_Pcont)
    {}
    const GvContainer* _Getcont() const
    {
        return _Mycontainer;
    }
};
struct GvContainer
{
    GvAuxCont* _Myownedaux;
    GvContainer()
    {}
    GvContainer(const GvContainer&)
    {}
    GvContainer& operator=(const GvContainer&)
    {
        return *this;
    }
    ~GvContainer()
    {}
};
template <class A> struct GvAuxBase : GvContainer
{
    GvAlloc<GvAuxCont> _Alaux;
    explicit GvAuxBase(A _Al) : _Alaux(_Al)
    {
        _Myownedaux = new (_Alaux.allocate(1)) GvAuxCont(this);
    }
    GvAuxBase(const GvAuxBase& _Right) : _Alaux(_Right._Alaux)
    {
        _Myownedaux = new (_Alaux.allocate(1)) GvAuxCont(this);
    }
    ~GvAuxBase()
    {
        _Myownedaux->~GvAuxCont();
        _Alaux.deallocate(_Myownedaux, 1);
    }
};
struct GvIterBase
{
    GvAuxCont* _Myaux;
    GvIterBase() : _Myaux(0)
    {}
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    bool _Same_container(const GvIterBase& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    void _Set_container(const GvContainer* _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const GvContainer* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
};
template <class T> struct GvVector;
template <class T> struct GvConstIterator : GvIterBase
{
    T* _Myptr;
    const T* _Checked_iterator_base() const
    {
        return _Myptr;
    }
    GvConstIterator(T* _Ptr, const GvContainer* _Pvector)
    {
        {
            if (!(_Pvector != 0 && ((GvVector<T>*)_Pvector)->_Myfirst <= _Ptr &&
                  _Ptr <= ((GvVector<T>*)_Pvector)->_Mylast))
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
        }
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    GvConstIterator& operator+=(int _Off)
    {
        {
            if (!this->_Has_container())
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
        }
        {
            if (!(_Myptr + _Off <= ((GvVector<T>*)this->_Getmycont())->_Mylast &&
                  _Myptr + _Off >= ((GvVector<T>*)this->_Getmycont())->_Myfirst))
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
        }
        _Myptr += _Off;
        return *this;
    }
    bool operator==(const GvConstIterator& _Right) const
    {
        {
            if (!(this->_Has_container() && this->_Same_container(_Right)))
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
        }
        do
        {
        } while (0);
        return _Myptr == _Right._Myptr;
    }
    bool operator!=(const GvConstIterator& _Right) const
    {
        return !(*this == _Right);
    }
    int operator-(const GvConstIterator& _Right) const
    {
        {
            if (!(this->_Has_container() && this->_Same_container(_Right)))
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
        }
        return _Myptr - _Right._Myptr;
    }
};
template <class T> struct GvIterator : GvConstIterator<T>
{
    GvIterator(T* _Ptr, const GvContainer* _Pvector) : GvConstIterator<T>(_Ptr, _Pvector)
    {}
    GvIterator& operator+=(int _Off)
    {
        (*(GvConstIterator<T>*)this) += _Off;
        return *this;
    }
    GvIterator operator+(int _Off) const
    {
        GvIterator _Tmp = *this;
        return (_Tmp += _Off);
    }
};
template <class T> struct GvVectorVal : GvAuxBase<GvAlloc<T> >
{
    GvAlloc<T> _Alval;
    GvVectorVal(GvAlloc<T> _Al = GvAlloc<T>()) : GvAuxBase<GvAlloc<T> >(_Al), _Alval(_Al)
    {}
};
template <class T> struct GvVector : GvVectorVal<T>
{
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    GvVector() : GvVectorVal<T>()
    {
        _Buy(0);
    }
    explicit GvVector(unsigned int _Count) : GvVectorVal<T>()
    {
        _Construct_n(_Count, T());
    }
    void _Construct_n(unsigned int _Count, const T& _Val)
    {
        if (_Buy(_Count))
        {
            try
            {
                _Mylast = _Ufill(_Myfirst, _Count, _Val);
            }
            catch (...)
            {
                _Tidy();
                throw;
            }
        }
    }
    GvVector(const GvVector& _Right) : GvVectorVal<T>(_Right._Alval)
    {
        if (_Buy(_Right.size()))
        {
            try
            {
                _Mylast = _Ucopy(_Right.begin(), _Right.end(), _Myfirst);
            }
            catch (...)
            {
                _Tidy();
                throw;
            }
        }
    }
    ~GvVector()
    {
        _Tidy();
    }
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    unsigned int max_size() const
    {
        return this->_Alval.max_size();
    }
    GvIterator<T> begin()
    {
        return GvIterator<T>(_Myfirst, this);
    }
    GvIterator<T> end()
    {
        return GvIterator<T>(_Mylast, this);
    }
    GvConstIterator<T> begin() const
    {
        return GvConstIterator<T>(_Myfirst, this);
    }
    GvConstIterator<T> end() const
    {
        return GvConstIterator<T>(_Mylast, this);
    }
    static void _Xlen()
    {
        throw BxLengthError("vector<T> too long");
    }
    bool _Buy(unsigned int _Capacity)
    {
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
        if (_Capacity == 0)
        {
            return false;
        }
        else if (max_size() < _Capacity)
        {
            _Xlen();
        }
        else
        {
            _Myfirst = this->_Alval.allocate(_Capacity);
            _Mylast = _Myfirst;
            _Myend = _Myfirst + _Capacity;
        }
        return true;
    }
    void _Destroy(T* _First, T* _Last)
    {
        GvDestroyRange(_First, _Last, this->_Alval);
    }
    void _Tidy()
    {
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
    }
    T* _Ufill(T* _Ptr, unsigned int _Count, const T& _Val)
    {
        GvUncheckedFillN(_Ptr, _Count, _Val, this->_Alval);
        return _Ptr + _Count;
    }
    GvIterator<T> _Make_iter(GvConstIterator<T> _Where) const
    {
        return GvIterator<T>(_Where._Myptr, this);
    }
    GvIterator<T> erase(GvConstIterator<T> _First_arg, GvConstIterator<T> _Last_arg)
    {
        GvIterator<T> _First = _Make_iter(_First_arg);
        GvIterator<T> _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            T* _Ptr = GvUncheckedCopy(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return _First;
    }
    void clear()
    {
        erase(begin(), end());
    }
    void resize(unsigned int _Newsize, T _Val)
    {
        if (size() < _Newsize)
            _Insert_n(end(), _Newsize - size(), _Val);
        else if (_Newsize < size())
            erase(begin() + _Newsize, end());
    }
    void resize(unsigned int _Newsize)
    {
        resize(_Newsize, T());
    }
    T& operator[](unsigned int _Pos)
    {
        {
            if (!(_Pos < size()))
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
        }
        return *(_Myfirst + _Pos);
    }
    template <class I> T* _Ucopy(I _First, I _Last, T* _Ptr)
    {
        return GvUncheckedUninitCopy(_First, _Last, _Ptr, this->_Alval);
    }
    GvVector& operator=(const GvVector& _Right)
    {
        if (this != &_Right)
        {
            if (_Right.size() == 0)
            {
                clear();
            }
            else if (_Right.size() <= size())
            {
                T* _Ptr = GvUncheckedCopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
                _Destroy(_Ptr, _Mylast);
                _Mylast = _Myfirst + _Right.size();
            }
            else if (_Right.size() <= capacity())
            {
                T* _Ptr = _Right._Myfirst + size();
                GvUncheckedCopy(_Right._Myfirst, _Ptr, _Myfirst);
                _Mylast = _Ucopy(_Ptr, _Right._Mylast, _Mylast);
            }
            else
            {
                if (_Myfirst != 0)
                {
                    _Destroy(_Myfirst, _Mylast);
                    this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
                }
                if (_Buy(_Right.size()))
                {
                    _Mylast = _Ucopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
                }
            }
        }
        return *this;
    }
    void _Insert_n(GvConstIterator<T> _Where, unsigned int _Count, const T& _Val);
    GvIterator<T> insert(GvConstIterator<T> _Where, const T& _Val)
    {
        unsigned int _Off = size() == 0 ? 0 : _Where - begin();
        _Insert_n(_Where, 1, _Val);
        return begin() + _Off;
    }
    void push_back(const T& _Val)
    {
        if (size() < capacity())
        {
            _Mylast = _Ufill(_Mylast, 1, _Val);
        }
        else
        {
            insert(end(), _Val);
        }
    }
};
}

// @fnv 0x00ad42e0
plus2ad4::BxString FUN_00ad42e0(const plus2ad4::BxString& _Left, const plus2ad4::BxString& _Right)
{
    return plus2ad4::BxString(_Left) += _Right;
}

namespace input_ctor {
struct DefaultLocale : localeDEB0
{
    DefaultLocale();
};
template <class C> struct InputStreambuf;
struct InputMutex : _MutexDEB0
{
    InputMutex();
};
struct Failure : BxLogicError
{
    explicit Failure(const BxString& message) : BxLogicError(message)
    {}
    virtual ~Failure()
    {}
};
struct StateOperations
{
    virtual ~StateOperations()
    {}
    unsigned int standardStream;
    int state, exceptions, format, precision, width;
    void* array;
    void* callbacks;
    localeDEB0* locale;
    StateOperations()
    {}
    int rdstate() const
    {
        return state;
    }
    void initializeBase()
    {
        locale = 0;
        standardStream = 0;
        exceptions = 0;
        format = 0x201;
        precision = 6;
        width = 0;
        array = 0;
        callbacks = 0;
        reinterpret_cast<::fnv_00ac9ff0::std::ios_base *>(this)->FUN_00ac9ff0(0, false);
        locale = new localeDEB0;
    }
    static void addStandard(StateOperations*);
    void FUN_00ac9ff0(int value, bool reraise)
    {
        state = value & 0x17;
        if ((state & exceptions) == 0)
        {
        }
        else if (reraise)
            throw;
        else if (state & exceptions & 4)
            throw Failure("ios_base::badbit set");
        else if (state & exceptions & 2)
            throw Failure("ios_base::failbit set");
        else
            throw Failure("ios_base::eofbit set");
    }
};
struct InputIos : StateOperations
{
    virtual ~InputIos()
    {}
    InputStreambuf<char>* streambuf;
    void* tied;
    char fill;
    InputIos()
    {}
    localeDEB0 getloc() const
    {
        return *locale;
    }
    char widen(char value) const
    {
        return ParserUseFacet(getloc()).widen(value);
    }
    void FUN_00ad0470(InputStreambuf<char>* buffer, bool standard)
    {
        initializeBase();
        streambuf = buffer;
        tied = 0;
        fill = widen(' ');
        if (streambuf == 0)
            setstate(4);
        if (standard)
            addStandard(this);
        else
            standardStream = 0;
    }
    void clear(int value = 0, bool reraise = false)
    {
        reinterpret_cast<::fnv_00ac9ff0::std::ios_base *>(this)->FUN_00ac9ff0(streambuf == 0 ? value | 4 : value, reraise);
    }
    void setstate(int value, bool reraise = false)
    {
        if (value != 0)
            clear(rdstate() | value, reraise);
    }
};
struct VersionedDataBlock : virtual InputIos
{
    VersionedDataBlock(InputStreambuf<char>* buffer, bool standard = false) : count(0)
    {
        reinterpret_cast<::FNV_ad0470_class *>(this)->FUN_00ad0470((::std::intptr_t)(buffer), standard);
    }
    virtual ~VersionedDataBlock()
    {}
    int count;
};
struct Codec : facetDEB0
{
    virtual bool do_always_noconv() const;
    bool always_noconv() const
    {
        return do_always_noconv();
    }
};
const Codec& UseCodec(const localeDEB0&);
_iobuf_ob1* OpenStream(const char*, int, int);
template <class C> struct InputStreambuf
{
    virtual ~InputStreambuf()
    {
        delete _Plocale;
    }
    InputStreambuf() : _Plocale(new localeDEB0)
    {
        _InitSB();
    }
    InputMutex lock;
    C *_Gfirst, *_Pfirst;
    C **_IGfirst, **_IPfirst;
    C *_Gnext, *_Pnext;
    C **_IGnext, **_IPnext;
    int _Gcount, _Pcount;
    int *_IGcount, *_IPcount;
    localeDEB0* _Plocale;
    localeDEB0 getloc() const
    {
        return *_Plocale;
    }
    void setp(C* first, C* last)
    {
        *_IPfirst = first;
        *_IPnext = first;
        *_IPcount = (int)(last - first);
    }
    void setg(C* first, C* next, C* last)
    {
        *_IGfirst = first;
        *_IGnext = next;
        *_IGcount = (int)(last - next);
    }
    void _InitSB()
    {
        _IGfirst = &_Gfirst;
        _IPfirst = &_Pfirst;
        _IGnext = &_Gnext;
        _IPnext = &_Pnext;
        _IGcount = &_Gcount;
        _IPcount = &_Pcount;
        setp(0, 0);
        setg(0, 0, 0);
    }
    void _InitSB(C** gf, C** gn, int* gc, C** pf, C** pn, int* pc)
    {
        _IGfirst = gf;
        _IPfirst = pf;
        _IGnext = gn;
        _IPnext = pn;
        _IGcount = gc;
        _IPcount = pc;
    }
};
template <class C> struct InputFilebuf : InputStreambuf<C>
{
    InputFilebuf(_iobuf_ob1* _File = 0) : InputStreambuf<C>()
    {
        reinterpret_cast<::S_00acfb90_Class *>(this)->FUN_00acfc10((::std::intptr_t)(_File), (*(int *)&(const ::input_ctor::InputFilebuf<char>::InitKind &)(NewFile)));
    }
    virtual ~InputFilebuf();
    void* codec;
    char putback;
    bool wrote;
    int conversionState;
    bool ownsFile;
    _iobuf_ob1* file;
    enum InitKind
    {
        NewFile,
        OpenFile,
        ClosedFile
    };
    void FUN_00acfc10(_iobuf_ob1* _File, InitKind _Which)
    {
        static int _Stinit;
        ownsFile = _Which == OpenFile;
        wrote = false;
        _InitSB();
        if (_File != 0 && sizeof(char) == 1)
        {
            char** begin = &_File->_base;
            char** next = &_File->_ptr;
            int* readCount = &_File->_cnt;
            int* writeCount = &_File->_cnt;
            _InitSB(begin, next, readCount, begin, next, writeCount);
        }
        file = _File;
        conversionState = _Stinit;
        codec = 0;
    }
    void initializeCodec(Codec* value)
    {
        if (value->always_noconv())
            codec = 0;
        else
        {
            codec = (void*)value;
            _InitSB();
        }
    }
    InputFilebuf* FUN_00acfab0(const char* name, int mode, int prot)
    {
        _iobuf_ob1* opened;
        if (file != 0 || (opened = OpenStream(name, mode, prot)) == 0)
            return 0;
        reinterpret_cast<::S_00acfb90_Class *>(this)->FUN_00acfc10((::std::intptr_t)(opened), (*(int *)&(const ::input_ctor::InputFilebuf<char>::InitKind &)(OpenFile)));
        initializeCodec((Codec*)&UseCodec(getloc()));
        return this;
    }
};
}

class FUN_00acc6c0 : public input_ctor::VersionedDataBlock
{
  public:
    FUN_00acc6c0(const char* filename, int mode, int protection);
    virtual ~FUN_00acc6c0();
    input_ctor::InputFilebuf<char> filebuf;
};

// @fnv 0x00acc6c0
FUN_00acc6c0::FUN_00acc6c0(const char* filename, int mode, int protection) : input_ctor::VersionedDataBlock(&filebuf)
{
    if (filebuf.FUN_00acfab0(filename, mode | 1, protection) == 0)
        setstate(2);
}

#include "generated/data/fallout_shared/tesobject.inc"
#include "generated/data/fallout_shared/tesobject_ob1_nogf_variant.inc"
#include "generated/data/fallout_shared/tesobject_ob1_variant.inc"
