// gamebryo2.2/corelibs/nimain/ninode_packet_decls.h: declares NiPropertyState, MemoryManager, NiStream, NiUpdateData, CloningProcess and more
#ifndef NINODE_PACKET_DECLS_H
#define NINODE_PACKET_DECLS_H

#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00a63460_shell.h"
#include "fnv/decl/NiDynamicEffect.h"
#include "fnv/decl/S_00a59e00.h"
#include "fnv/decl/S_00a64670_Foo.h"
#include "fnv/decl/Sphere.h"
#include "fnv/decl/fnv_00a5a170__FUN_00a5a170_cls.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
struct NiObject;
class NiPropertyState
{
  public:
};
class MemoryManager
{
  public:
};
inline void DestroyPropertyState(NiPropertyState* p)
{
    if (p)
    {
        ::fnv_00a89890::ReleaseAllRefs((::fnv_00a89890::ArrStub *)(p));
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(p);
    }
}

struct NiStream
{
  public:
    unsigned char pad[0xD8];
    unsigned int m_uiFormatVersion;
    NiObject* GetLoadedObject();
};

class NiNode;
class NiAVObject;
class NiFixedString;
struct NiUpdateData
{
  public:
    float time;
    bool updateControllers;
    bool forceUpdate;
};
class NiCullingProcess;
struct NiBound;
struct CloningProcess;
struct ShaderBufferRecord;

#include "fnv/ni_pointer.h"
template <class T> class NiTNewInterface
{
};

template <class T, class U> class NiTArray
{
  public:
    unsigned int m_unknown;
    NiAVObject** m_children;
    unsigned short m_usMaxSize;
    unsigned short m_usArraySize;
    unsigned short m_usEffectiveSize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int size);
};

template <class T> class NiTStringPointerMap
{
  public:
    bool GetAt(const char* key, T& value);
};

struct CloningProcess
{
  public:
    NiTStringPointerMap<ShaderBufferRecord*>* m_pCloneMap;
};

class NiAVObject
{
  public:
    unsigned char pad[0x14];
    NiNode* m_pParentNode;
    void* m_spCollisionObject;
    NiBound* m_pkWorldBound;
    unsigned char padFlags[0x0C];
    union
    {
        unsigned int m_uiObjectFlags;
        struct
        {
            unsigned int m_flagPad0 : 13;
            unsigned int m_bFlag13 : 1;
            unsigned int m_flagPad1 : 5;
            unsigned int m_bFlag19 : 1;
            unsigned int m_flagPad2 : 12;
        } m_flags;
    };
    unsigned char pad2[0x68];
    virtual void Slot00();
    virtual void DeleteThis();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual NiAVObject* MakeClone(CloningProcess& process);
    void FUN_00a5ac90(NiAVObject*, CloningProcess&);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void ProcessClone(CloningProcess& process);
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual NiAVObject* GetObjectByName(const NiFixedString& name);
    virtual void Slot40();
    virtual void UpdateDownwardPass(NiUpdateData&, unsigned int);
    void UpdateTimeControllers(NiUpdateData&, bool);
    virtual void UpdateSelectedDownwardPass(NiUpdateData&, unsigned int);
    virtual void UpdateRigidDownwardPass(NiUpdateData&, unsigned int);
    virtual void UpdatePropertiesDownwardPass(NiPropertyState*);
    virtual void Slot45();
    virtual void UpdateWorldData(NiUpdateData& data);
    virtual void UpdateWorldBound();
    virtual void UpdateTransformAndBounds(NiUpdateData& data);
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void OnVisible(NiCullingProcess& culler);
    virtual void Slot54();
    void EnsureWorldBound();
    unsigned char SelectedFlag() const
    {
        return (m_uiObjectFlags >> 1) & 1;
    }
    unsigned char RigidFlag() const
    {
        return (m_uiObjectFlags >> 4) & 1;
    }
    unsigned char TransformFlag() const
    {
        return (m_uiObjectFlags >> 2) & 1;
    }
    unsigned char BoundFlag13() const
    {
        return (m_uiObjectFlags >> 13) & 1;
    }
    unsigned char BoundFlag19() const
    {
        return (m_uiObjectFlags >> 19) & 1;
    }
};

struct NiPoint3
{
  public:
    float x, y, z;
};
struct NiBound
{
  public:
    NiPoint3 m_kCenter;
    float m_fBoundRadius;
    void Set(const NiPoint3& center, float radius)
    {
        m_kCenter = center;
        m_fBoundRadius = radius;
    }
};

inline const NiBound& GetBound(NiAVObject* object)
{
    return object->m_pkWorldBound ? *object->m_pkWorldBound : ::g_defaultBound;
}

class NiNode : public NiAVObject
{
  public:
    void CopyMemberData(NiNode*, CloningProcess&);
    virtual void UpdateDownwardPass(NiUpdateData&, unsigned int);
    virtual void UpdateSelectedDownwardPass(NiUpdateData&, unsigned int);
    virtual void UpdatePropertiesDownwardPass(NiPropertyState*);
    NiTArray<NiPointer<NiAVObject>, NiTNewInterface<NiPointer<NiAVObject> > > m_kChildList;
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual void ProcessClone(CloningProcess& process);
    virtual NiAVObject* GetObjectByName(const NiFixedString& name);
    virtual void OnVisible(NiCullingProcess& culler);
    virtual void AttachChildInAvailableSlot(NiAVObject*, bool);
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void ReplaceNthObject(unsigned int index, NiAVObject* object);
    virtual void UpdateWorldBound();
    virtual void UpdateTransformAndBounds(NiUpdateData& data);
    virtual void UpdateUpwardPass();
};

class NiPointLight
{
  public:
    unsigned char pad[0xC4];
    float value;
    void FUN_0050dd20(float);
};
#endif
