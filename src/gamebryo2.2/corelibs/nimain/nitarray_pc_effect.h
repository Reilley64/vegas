// Private PC declarations for the covered NiDynamicEffect revision member.
// NiMemObject, NiRefObject, NiObject, NiFixedString and NiObjectNET retain the
// corresponding supplied canonical class declarations and data layouts.
// NiRefObject inline bodies below are byte-identical supplied dependencies.
// PC-only NiAVObject/DList/transform layouts: JIP-LN-NVSE internal/netimmerse.h
// and internal/Ni_types.h. IncRevisionID name/address: JohnnyGuitar NiDynamicEffect.cpp.
#ifndef FNV_NITARRAY_PC_EFFECT_H
#define FNV_NITARRAY_PC_EFFECT_H

#include <windows.h>
#include <stddef.h>
#ifndef FNV_FORCEINLINE
#define FNV_FORCEINLINE __forceinline
#endif
class NiMemObject
{
  public:
};
class NiRefObject : public NiMemObject
{
  public:
    unsigned int m_uiRefCount;  // +0x4
    virtual ~NiRefObject();
    virtual void DeleteThis();
    FNV_FORCEINLINE void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    FNV_FORCEINLINE void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};
struct NiObject : public NiRefObject
{
  public:
};
class NiFixedString
{
  public:
    char* m_kHandle;  // +0x0
};
class NiTimeController;
class NiExtraData;
struct NiObjectNET : public NiObject
{
  public:
    NiFixedString m_kName;                       // +0x8
    NiPointer<NiTimeController> m_pControllers;  // +0xC
    NiExtraData** m_ppExtraData;                 // +0x10
    unsigned short m_usExtraDataCount;           // +0x14
    unsigned short m_usMaxSize;                  // +0x16
};
struct NiVector3
{
    float x, y, z;
};
struct NiMatrix33
{
    float cr[3][3];
};
class NiTransform
{
  public:
    NiMatrix33 rotate;
    NiVector3 translate;
    float scale;
};
template <class Item> class DList
{
  public:
    struct Node
    {
        Node* next;
        Node* prev;
        Item* data;
    };

  private:
    Node* first;
    Node* last;
    unsigned long count;
};
class NiNode;
class bhkNiCollisionObject;
struct NiBound;
class NiProperty;
class NiAVObject : public NiObjectNET
{
  public:
    NiNode* m_parent;
    bhkNiCollisionObject* m_collisionObject;
    NiBound* m_kWorldBound;
    DList<NiProperty> m_propertyList;
    unsigned long m_flags;
    NiTransform m_transformLocal;
    NiTransform m_transformWorld;
};
class NiDynamicEffect : public NiAVObject
{
  public:
    bool switchState;
    unsigned char effectType;
    long iIndex;
    unsigned long pushCount;
    unsigned long revID;
    DList<NiNode> shadowGenerator;
    DList<NiNode> unaffectedNodes;
    void IncRevisionID();
};
#endif
