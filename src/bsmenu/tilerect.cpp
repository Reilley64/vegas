#include "global_string_header.h"
#include <cstddef>
// bsmenu/tilerect.cpp: TileRect (2 functions)

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_009ff600_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a074d0_shell.h"
#include "fnv/symbols_00450000.h"
#include "tilerect.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00a5bca0_shell.h"
#include "fnv/decl/Interface.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/UpdateTreeNode.h"
#include "fnv/symbols_00707000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_0109b000.h"

// Initializes the TileRect by calling Tile::Init, then sets a value of 0x0fa3 to 1.0f and calls a method with 3.
// @fnv 0x00a1f370
void TileRect::Init(Tile* parent, const char* name, Tile* replacedChild)
{
    reinterpret_cast<::FUN_009ff600_shell *>(this)->InitTile(parent, (char *)(name), replacedChild);
    reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0x0fa3, 1.0f, true);
    reinterpret_cast<::FUN_00a074d0_shell *>(this)->FUN_00a074d0(3);
}

// @fnv 0x00709960
int TileRect::GetType()
{
    return eRect;
}

// Reconstruction of FUN_00a1f3b0 (0x00a1f3b0, 581 bytes) - a TileX method that
// builds the node for a tile, names it after the tile, tags it and attaches a
// Tile__Extra.  Class/field names the pack does not declare are stand-ins,
// named after their offsets.

                 // the interned empty string shared by NiFixedString
  // interns a string, returns the shared copy


class NiFixedString
{
  public:
    const char* m_pString;
    NiFixedString(const char* pcString)
    {
        if (!pcString)
            m_pString = ::DAT_0109b220;
        else
            m_pString = ::NiGlobalStringTable::AddString(pcString);
    }
    ~NiFixedString()
    {
        if (m_pString == ::DAT_0109b220)
            return;
        volatile long* refCount = &((StringHeader*)m_pString - 1)->refs;
        InterlockedDecrement(refCount);
    }
};

class TileX;

class Tile__Extra;

// Every reference-counted object in the game allocates through this.
class NiMemObject
{
  public:
};

// The scene graph node the tile builds.  Only the members this function touches
// are known; the 55 leading virtuals are the ones this class has before the
// method called at vtable offset 0xdc.
class NiNode : public NiMemObject
{
  public:
    virtual void unknown_vtable_00(), unknown_vtable_04(), unknown_vtable_08(), unknown_vtable_0c();
    virtual void unknown_vtable_10(), unknown_vtable_14(), unknown_vtable_18(), unknown_vtable_1c();
    virtual void unknown_vtable_20(), unknown_vtable_24(), unknown_vtable_28(), unknown_vtable_2c();
    virtual void unknown_vtable_30(), unknown_vtable_34(), unknown_vtable_38(), unknown_vtable_3c();
    virtual void unknown_vtable_40(), unknown_vtable_44(), unknown_vtable_48(), unknown_vtable_4c();
    virtual void unknown_vtable_50(), unknown_vtable_54(), unknown_vtable_58(), unknown_vtable_5c();
    virtual void unknown_vtable_60(), unknown_vtable_64(), unknown_vtable_68(), unknown_vtable_6c();
    virtual void unknown_vtable_70(), unknown_vtable_74(), unknown_vtable_78(), unknown_vtable_7c();
    virtual void unknown_vtable_80(), unknown_vtable_84(), unknown_vtable_88(), unknown_vtable_8c();
    virtual void unknown_vtable_90(), unknown_vtable_94(), unknown_vtable_98(), unknown_vtable_9c();
    virtual void unknown_vtable_a0(), unknown_vtable_a4(), unknown_vtable_a8(), unknown_vtable_ac();
    virtual void unknown_vtable_b0(), unknown_vtable_b4(), unknown_vtable_b8(), unknown_vtable_bc();
    virtual void unknown_vtable_c0(), unknown_vtable_c4(), unknown_vtable_c8(), unknown_vtable_cc();
    virtual void unknown_vtable_d0(), unknown_vtable_d4(), unknown_vtable_d8();
    virtual void unknown_vtable_dc(NiNode* pkChild, int iArg);

    NiNode(unsigned short usArg);
    ~NiNode();
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&unknown_04);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((volatile long*)&unknown_04) == 0)
            unknown_vtable_04();
    }
    void SetName(const NiFixedString& kName);
    static const unsigned int APP_CULLED_MASK = 1;
    void SetHidden(bool hidden, unsigned int mask)
    {
        if (hidden)
            unknown_30 |= mask;
        else
            unknown_30 &= ~mask;
    }

    unsigned int unknown_04, unknown_08, unknown_0c, unknown_10, unknown_14, unknown_18, unknown_1c;
    unsigned int unknown_20, unknown_24, unknown_28, unknown_2c;
    unsigned int unknown_30;  // flags word: bit 0 is set/cleared below
    unsigned int unknown_34, unknown_38, unknown_3c, unknown_40, unknown_44, unknown_48, unknown_4c;
    unsigned int unknown_50, unknown_54, unknown_58, unknown_5c, unknown_60, unknown_64, unknown_68;
    unsigned int unknown_6c, unknown_70, unknown_74, unknown_78, unknown_7c, unknown_80, unknown_84;
    unsigned int unknown_88, unknown_8c, unknown_90, unknown_94, unknown_98, unknown_9c, unknown_a0;
    unsigned int unknown_a4, unknown_a8;
};

template <> inline NiPointer<NiNode>& NiPointer<NiNode>::operator=(NiNode* object)
{
    if (m_pObject != object)
    {
        NiNode* oldObject = m_pObject;
        m_pObject = object;
        if (m_pObject)
            m_pObject->IncRefCount();
        if (oldObject)
            oldObject->DecRefCount();
    }
    return *this;
}

// The extra data the tile hangs on its node.
extern const char DAT_010954cc[];

class NiExtraData : public NiMemObject
{
  public:
    virtual ~NiExtraData();
    unsigned int unknown_04;
    const char* unknown_08;
    NiExtraData();
    void SetName(const NiFixedString& name);
};

class Tile__Extra : public NiExtraData
{
  public:
    TileX* tile;
    NiNode* node;
    Tile__Extra(TileX* pkTile, NiNode* pkNode) : tile(pkTile), node(pkNode)
    {
        SetName(NiFixedString(DAT_010954cc));
    }
    ~Tile__Extra();
};

// The tile this function belongs to.
class TileX
{
  public:
    void* table_00;
    unsigned int unknown_04, unknown_08, unknown_0c, unknown_10, unknown_14, unknown_18, unknown_1c;
    const char* unknown_20;  // the tile's name
    unsigned int unknown_24, unknown_28;
    NiPointer<NiNode> unknown_2c;  // the node this tile builds
    unsigned int unknown_30, unknown_34;

    NiNode* GetNiNode();
    NiNode* FUN_00a1f3b0();
};

// @fnv 0x00a1f3b0
NiNode* TileX::FUN_00a1f3b0()
{
    NiNode* pkParent = GetNiNode();
    unknown_2c = new NiNode(0);
    if (pkParent == 0)
        pkParent = ::Interface::GetInterfaceNode();
    pkParent->unknown_vtable_dc(unknown_2c, 1);
    ::AssignFixedString((char *)((unknown_2c).operator->()), 0, (char **)&(const ::NiFixedString &)(NiFixedString(unknown_20)));
    unknown_2c->SetHidden(!reinterpret_cast<::FUN_00a01230_shell *>(this)->IsTraitNonZero(0xfa3), 1);
    reinterpret_cast<::FUN_00a5a040_Class *>(((unknown_2c).operator->()))->FUN_00a5a040();
    ::fnv_00707930::FUN_00707930(1);
    reinterpret_cast<::FUN_00a5bca0_shell *>(((unknown_2c).operator->()))->SetExtraDataName((::NiExtraData *)(::Tile__Extra *)(new Tile__Extra(this, unknown_2c)));
    reinterpret_cast<::UpdateTreeNode *>(this)->FUN_00a037e0(0xfa1, reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfa1), {});
    reinterpret_cast<::UpdateTreeNode *>(this)->FUN_00a037e0(0xfa2, reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfa2), {});
    return unknown_2c;
}
#include "generated/data/bsmenu/tilerect_ob1_variant.inc"
