#include "AutoMemContext.h"

// NavMeshInfoMap: bounding-box verification and loaded-info initialization.
// NavMeshBounds, BSSimpleArray 16, NiTPointerMap 16) with layout asserts.

#include <cstdint>
#include <stddef.h>
#include <malloc.h>
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_006b4b50_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_009a3000.h"
class TESFile;
class TESObjectREFR;
class NavMesh;
enum MEM_CONTEXT
{
    MEM_CONTEXT_NAVMESH = 46
};
enum ENUM_FORM_ID
{
    ENUM_FORM_ID_NAVMESHINFOMAP = 56
};
template <int N> struct EndianSizeTag
{
    char value;
};
class MemoryManager
{
  public:
};
using ::AutoMemContext;

#define NULL 0


class NavMeshBounds
{
  public:
    unsigned char data[56];
};

class NavMeshInfo;
template <class T, unsigned int Growth> class BSSimpleArray
{
  public:
    void** m_ppVirtualMethodTable;             // +0x0
    T* pBuffer;                  // +0x4
    unsigned int iSize;          // +0x8
    unsigned int SimpleArrayStorage;  // +0xC
    BSSimpleArray();
    ~BSSimpleArray();
    T& operator[](unsigned int index);
    unsigned int Add(T& item);
    unsigned int GetSize();
    T& GetAt(int iIndex);
    template <unsigned int Other> void CopyTo(BSSimpleArray<T, Other>*);
    template <class U> unsigned int Find(U&, unsigned int, bool(__cdecl*)(U&, U&));
};

struct NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    static const NiPoint3 ZERO;
};
class NavMeshInfo
{
  public:
    unsigned int m_uiNavMeshID;                   // +0x0
    unsigned int m_uiParentSpaceID;               // +0x4
    unsigned int uiFlags;                         // +0x8
    int m_uiPathingFlags;                         // +0xC
    NiPoint3 m_kNavMeshPosition;                  // +0x10
    void* m_pParentSpace;                         // +0x1C
    float m_fStoredValue;                         // +0x20
    BSSimpleArray<NavMeshInfo*, 1024> adjacent;   // +0x24
    BSSimpleArray<NavMeshInfo*, 1024> preferred;  // +0x34
    BSSimpleArray<TESObjectREFR*, 1024> doors;    // +0x44
    void* m_pLocationNavMesh;                     // +0x54
    NavMeshBounds* pBounds;                       // +0x58
    NavMeshInfo();
    ~NavMeshInfo();
    void LoadSerializedData(char*, TESFile*, int);
    bool AcquireNavMesh(struct NavMeshPtr&);
    void CopyTo(NavMeshInfo*);
    void SetNavMesh(NavMesh*);
    void ReleaseNavMesh();
};

template <class K, class V> class NiTMapItem
{
  public:
    NiTMapItem<K, V>* m_pkNext;
    K m_key;
    V m_val;
};

template <class K, class V> class NiTPointerMap
{
  public:
    void** m_ppVirtualMethodTable;                    // +0x0
    unsigned int m_uiHashSize;          // +0x4
    NiTMapItem<K, V>** m_ppkHashTable;  // +0x8
    struct MapEntryCount
    {
        unsigned int m_uiCount;
    } m_kItemCount;  // +0xC
    NiTPointerMap(unsigned int uiHashSize);
    ~NiTPointerMap();
    bool RemoveAt(unsigned int key);
    bool GetAt(unsigned int key, V& val) const;
    template <class U> bool GetAt(unsigned int key, U& val) const;
    void SetAt(unsigned int key, void* val);
    void* GetFirstPos();
    void GetNext(void*& pPos, unsigned int& uiKey, void*& val);
};

typedef BSSimpleArray<NavMeshInfo*, 1024> NavMeshInfoArray;

typedef NiTPointerMap<unsigned int, void*> CellKeyMap;

struct OuterPair
{
    void* pInnerMapRaw;
    unsigned int uiOuterKey;
};

struct InnerCounts
{
    unsigned int uiIndex;
    unsigned int uiValid;
};

class TESFile;
template <class> class NiTLargePrimitiveArray;
class TESForm
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual ~TESForm();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void readOBNDSubRecord(TESFile*);
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual bool SetEditorID_AtRuntime(const char*);
    unsigned char data[20];
    TESForm();
public:
    ::TESFile *GetFile(int);
public:
    static ::NiTLargePrimitiveArray< ::TESForm *> *ms_pAllForms;
};

class NavMeshInfoMap : public TESForm
{
  public:
    bool m_bNavMeshInfoArraysValid;  // +0x18
    unsigned char pad19[3];
    NiTPointerMap<unsigned int, NavMeshInfo*> m_kNavMeshInfosByFormID;  // +0x1C
    NiTPointerMap<unsigned int, NiTPointerMap<unsigned int, NavMeshInfoArray*>*>
        m_kNavMeshInfoArraysByWorldspace;  // +0x2C
    bool m_bKeepNavMeshLoaded;             // +0x3C
    unsigned char pad3D[3];
    NavMeshInfoMap();
    bool Load(TESFile*);
    NavMeshInfo* FUN_00693d70(std::uintptr_t);
    bool ValidateNavMeshInfoArrays();
    void InitItem();
    void InsertNavMeshInfo(NavMeshInfo* info);
};


class TESFile
{
  public:
    bool IsEndianConversionRequired();
    bool NextChunk();
public:
    bool IsMasterFile();
};
class TESObjectREFR : public TESForm
{
};
template <class T> class NiPointer
{
  public:
    T* m_pObject;
};
struct NavMeshPtr : public NiPointer<NavMesh>
{
  public:
    NavMeshPtr();
    ~NavMeshPtr();
};
typedef BSSimpleArray<TESObjectREFR*, 1024> NavMeshDoorArray;

class TESObjectCELL;
class TESWorldSpace : public TESForm
{
  public:
    bool GetSmallWorld();
public:
    ::TESObjectCELL *GetCellByKey(unsigned int);
};
unsigned int FUN_006b7b30(NavMeshInfo*);

// Keep the accepted InitItem spelling while recovering the vector member.
#define approxZ m_kNavMeshPosition.z
