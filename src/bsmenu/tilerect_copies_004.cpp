
// Provisional build file (plan B2): exact copies of the tilerect recipe for other original addresses.
// Twin_<addr>/FUN_<addr> are placeholder names; the original identities of these functions are unknown.
// inlined from worker header tilerect_decls.h
#ifndef FNV_TILERECT_H
#define FNV_TILERECT_H
#include <cstddef>

#include <windows.h>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a074d0_shell.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00a5bca0_shell.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_0109b000.h"
#include "layout_support.h"

class Tile;
class NiNode;
class NiExtraData;
class NiAVObject;
class NiFixedString;

template <> class NiPointer<NiAVObject>
{
  public:
    NiAVObject* m_pObject;
    NiPointer& operator=(NiAVObject*);
    __forceinline operator NiAVObject*() const
    {
        return m_pObject;
    }
    __forceinline NiAVObject* operator->() const
    {
        return m_pObject;
    }
};

class NiMemObject
{
  public:
    void IncRefCount();
    void DecRefCount();
};

class NiExtraData : public NiMemObject
{
  public:
    virtual void vfn_extra();
    void* m_name;
    unsigned int m_flags;
    void SetName(const NiFixedString&);
};

class NiObjectNET : public NiMemObject
{
  public:
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual void vfn_06();
    virtual void vfn_07();
    virtual void vfn_08();
    virtual void vfn_09();
    virtual void vfn_0a();
    virtual void vfn_0b();
    virtual void vfn_0c();
    virtual void vfn_0d();
    virtual void vfn_0e();
    virtual void vfn_0f();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19();
    virtual void vfn_1a();
    virtual void vfn_1b();
    virtual void vfn_1c();
    virtual void vfn_1d();
    virtual void vfn_1e();
    virtual void vfn_1f();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void vfn_22();
    virtual void vfn_23();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual void vfn_28();
    virtual void vfn_29();
    virtual void vfn_2a();
    virtual void vfn_2b();
    virtual void vfn_2c();
    virtual void vfn_2d();
    virtual void vfn_2e();
    virtual void vfn_2f();
    virtual void vfn_30();
    virtual void vfn_31();
    virtual void vfn_32();
    virtual void vfn_33();
    virtual void vfn_34();
    virtual void vfn_35();
    virtual void vfn_36();
    unsigned char layoutPadding4[0x2C];
};

class NiAVObject : public NiObjectNET
{
  public:
    enum
    {
        APP_CULLED = 1
    };
    unsigned int flags;
    __forceinline void SetBit(unsigned int mask, bool value)
    {
        if (value)
            flags |= mask;
        else
            flags &= ~mask;
    }
    __forceinline void SetAppCulled(bool value)
    {
        SetBit(1, value);
    }
    void SetName(const NiFixedString&);
};

class NiNode : public NiAVObject
{
  public:
    virtual void AddObject(NiNode*, bool);
    unsigned char layoutPadding34[0x70];
};
template <> NiPointer<NiNode>& NiPointer<NiNode>::operator=(NiNode*);

class NiSortAdjustNode : public NiNode
{
  public:
    int sortingMode;
    int layoutPaddingA8;
    NiSortAdjustNode(unsigned int);
};

class Interface
{
  public:
    static NiNode* GetInterfaceNode();
    static void SetInterfaceNodeVisible(bool);
};

class NiGlobalStringTable
{
  public:
    static char* AddString(const char*);
};

class TileListBoxCalls
{
  public:
    float GetFloat(int);
};

class NiFixedString;

class NiFixedString
{
  public:
    char* m_kHandle;
    __forceinline NiFixedString(const char* str)
    {
        if (!str)
            m_kHandle = (*reinterpret_cast<::NiFixedString *>(&::DAT_0109b220)).m_kHandle;
        else
            m_kHandle = NiGlobalStringTable::AddString(str);
    }
    __forceinline ~NiFixedString()
    {
        if (m_kHandle == (*reinterpret_cast<::NiFixedString *>(&::DAT_0109b220)).m_kHandle)
            return;
        volatile long* refs = (volatile long*)(m_kHandle - 8);
        InterlockedDecrement(refs);
    }
};

class Tile
{
  public:
    enum
    {
        eRect = 901
    };
    virtual ~Tile();
    virtual void Init(Tile*, const char*, Tile*);
    virtual int GetType();
    virtual const char* GetTypeName();
    virtual NiNode* CalculateNode();
    virtual Tile* SetTraitValue(int, float, const char*);

    NiNode* GetUnderlyingNode();
    Tile* SetTraitValueAndText(int, float, const char*);

  private:
    unsigned char layoutPadding4[0x1C];

  public:
    const char* StringProvider;
    unsigned int xNameLength;
    Tile* pParent;
    NiPointer<NiAVObject> m_pRenderedNodeEntry;
    unsigned int uiFlags;
    bool m_bFlagAfterUiFlags;
    bool m_bSpeechChallengeFailure;

    class Extra : public NiExtraData
    {
      public:
        Tile* pTile;
        NiNode* pNode;
        Extra(Tile*, NiNode*);
    };
};

class TileRect : public Tile
{
  public:
    virtual ~TileRect();
    virtual void Init(Tile*, const char*, Tile*);
    virtual int GetType();
    virtual const char* GetTypeName();
    virtual NiNode* CalculateNode();
    virtual Tile* SetTraitValue(int, float, const char*);

    __forceinline NiNode* GetAttachModel() const
    {
        unsigned int nameState;
        unsigned int modelState;
        return (NiNode*)m_pRenderedNodeEntry.m_pObject;
    }
    __forceinline NiAVObject* GetExtraDataModel() const
    {
        unsigned int extraState;
        unsigned int updateState;
        return m_pRenderedNodeEntry.m_pObject;
    }
    bool m_bTextureLoaded;
};


#endif

struct Twin_005578e0 : public TileRect
{
    Tile* SetTraitValue(int, float, const char*);
};
// @fnv 0x005578e0
Tile* Twin_005578e0::SetTraitValue(int, float, const char*)
{
    return 0;
}

struct Twin_00a1f600 : public TileRect
{
    Tile* SetTraitValue(int, float, const char*);
};
// @fnv 0x00a1f600
Tile* Twin_00a1f600::SetTraitValue(int, float, const char*)
{
    return 0;
}

struct Twin_00aaa650 : public TileRect
{
    Tile* SetTraitValue(int, float, const char*);
};
// @fnv 0x00aaa650
Tile* Twin_00aaa650::SetTraitValue(int, float, const char*)
{
    return 0;
}
