#include "AutoMemContext.h"
#include "fnv/tls.h"
// bsmenu/tileimage.cpp: TileImage, FileFinder, BGSTextureSet, NiNode and more (7 functions)

#include "global_string_header.h"
#include <windows.h>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_004bc320_shell.h"
#include "fnv/decl/FUN_009ff600_shell.h"
#include "fnv/decl/FUN_00a00f30_shell.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a074d0_shell.h"
#include "fnv/decl/FUN_00a07530_shell.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00a5bca0_shell.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/NiSourceTexture.h"
#include "fnv/decl/TextureFileEntrySetter.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/TileX.h"
#include "fnv/decl/UpdateTreeNode.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00707000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a61000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00b55000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f8000.h"
#include "fnv/symbols_01272000.h"
#include "tileimage_private.h"
#include <cstdlib>
#include "fnv/decl/FUN_0044a970_Cls.h"
#include "fnv/decl/S_00a0c7c0_List.h"
#include "fnv/decl/StrA.h"
#include "fnv/decl/StringQ.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/fnv_0044a730__FUN_0044a730_cls.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00a1f000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_011f3000.h"
#include "tileimage_private_decl_tileimage.h"

// @fnv 0x00a20580
Tile* TileImage::SetTraitValue(int trait, float value, const char* text)
{
    if ((trait == 0xfa1 || trait == 0xfa2) && !(uiFlags & 1))
        reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(1);
    else if ((trait == 0xfb1 || trait == 0xfb0) && !(uiFlags & 16))
        reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(16);
    else if (trait == 0xfcc && ((::Tile::Value *)(reinterpret_cast<::FUN_00a00f30_shell *>(this)->FUN_00a00f30(0xff9))))
        reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(16);
    return 0;
}

// @fnv 0x0078cdf0
void TileImage::UpdateTileImage()
{
    reinterpret_cast<::FUN_004bc320_shell *>(((*reinterpret_cast<::TextureReceiver **>(&g_011ded3c))))->FUN_004bc320({});
}

// @fnv 0x00a1f6e0
void TileImage::Init(Tile* parent, const char* name, Tile* root)
{
    int unused[2];
    reinterpret_cast<::FUN_009ff600_shell *>(this)->InitTile(parent, (char *)(name), root);
    reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xff5, 255.0f, true);
    reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xfb2, 255.0f, true);
    reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xfb3, 255.0f, true);
    reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xfb4, 255.0f, true);
    reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xfa9, 255.0f, true);
    reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xfad, 1.0f, true);
    reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xfa3, 1.0f, true);
    reinterpret_cast<::FUN_00a074d0_shell *>(this)->FUN_00a074d0(3);
    fScale = 1.0f;
    spTexture = (NiTexture*)0;
    m_bTextureLoaded = false;
}

// Allocates a BSShaderTextureSet and copies each non-empty texture path from textures into it, prefixed with Data\Textures\.
// @fnv 0x00592d20
BSShaderTextureSet* BGSTextureSet::BuildShaderTextureSet()
{
    BSShaderTextureSet* result = new BSShaderTextureSet;
    for (int i = 0; i < 6; ++i)
    {
        const char* path = textures.GetTexturePath(i);
        if (path && *path)
        {
            char szFullPath[260];
            TaskQueueInterface::CopyStringToBuffer(szFullPath, 260, "Data\\Textures\\");
            strcat_s(szFullPath, 260, path);
            result->SetTexturePath(i, szFullPath);
        }
    }
    return result;
}

class NiNode;
struct Interface
{
    static float __cdecl GetInterfaceFloat();
public:
    static ::NiNode *GetInterfaceNode();
public:
    static float GetFirstInterfaceFloat();
public:
    static float UpdateInterfaceState();
};
struct NiGlobalStringTable
{
    static char* __cdecl AddString(const char*);
    static void DecRef(long* p)
    {
        InterlockedDecrement(p);
    }
};
struct FileFinder;
struct FileFinder
{
    int GetFileLocation(char*, char*, unsigned int, unsigned int);
    static FileFinder* GetSingleton()
    {
        return ::g_fileFinder;
    }
};
namespace L {
struct Setting
{
    void* vtbl;
    char* m_pString;
    char* GetString()
    {
        char* r;
        if (this)
            r = m_pString;
        else
            r = 0;
        return r;
    }
};
struct NiFixedString
{
    char* m_kHandle;
    NiFixedString(const char* s)
    {
        if (s == 0)
            m_kHandle = ::DAT_0109b220;
        else
            m_kHandle = NiGlobalStringTable::AddString(s);
    }
    ~NiFixedString()
    {
        if (m_kHandle == ::DAT_0109b220)
            return;
        NiGlobalStringTable::DecRef(&((StringHeader*)m_kHandle - 1)->refs);
    }
};
struct NiTexture
{
    virtual void S0();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct NiTexturePtr
{
    NiTexture* m_pObject;
    NiTexturePtr(NiTexture* p = 0)
    {
        m_pObject = p;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiTexturePtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    bool operator==(const NiTexture* p) const
    {
        return m_pObject == p;
    }
};
}

// Builds a Data\Textures\ path from apFilename, looks up the texture, and falls back to a default setting string if not found.
// @fnv 0x00a1f7d0
void ResolveTexturePath(const char* apFilename, float* afScale, float afZoom, char* axOut)
{
    if (!apFilename || !*apFilename || *apFilename == ' ')
        return;
    float aspect = Interface::GetInterfaceFloat();
    *afScale = 1.0f;
    fnv::crt::strcpy_s(axOut, 260, "Data\\Textures\\");
    fnv::crt::strcat_s(axOut, 260, apFilename);
    L::NiTexturePtr sptex;
    L::NiFixedString path(axOut);
    ::FindTextureByPath(path.m_kHandle, (::NiTexture **)(::L::NiTexturePtr *)(&sptex));
    if (sptex == 0)
    {
        if (!FileFinder::GetSingleton()->GetFileLocation(axOut, axOut, 6, 0xffffffff))
        {
            if (*afScale != 1.0)
            {
                fnv::crt::strcpy_s(axOut, 260, "Data\\Textures\\");
                fnv::crt::strcat_s(axOut, 260, apFilename);
                if (FileFinder::GetSingleton()->GetFileLocation(axOut, 0, 6, 0xffffffff))
                    *afScale = 1.0f;
                else
                    fnv::crt::strcpy_s(axOut, 260, ((L::Setting*)&g_011d33f0)->GetString());
            }
            else
            {
                fnv::crt::strcpy_s(axOut, 260, ((L::Setting*)&g_011d33f0)->GetString());
            }
        }
    }
}

namespace fnv_00a1fa20 {
struct NiFixedString
{
    bool Exists();
    unsigned int GetLength();
    unsigned int GetRefCount();
    bool Equals(char*);
    bool EqualsNoCase(char*);
    bool Contains(char*);
    bool HasSuffix(char*);
    unsigned int QHandle();
    void Init();
    void* __vecDelDtor(unsigned int);
    char* m_kHandle;
};
struct BooleanFlagObject
{
    void* __vecDelDtor(unsigned int);
    bool m_bFlag;
};
using ::AutoMemContext;

struct NiGlobalStringTable
{
    static long* GetRealBufferStart(char* const& h)
    {
        return &((StringHeader*)h - 1)->refs;
    }
    static long NiAtomicSubtract(long& v)
    {
        return InterlockedDecrement(&v);
    }
    static void DecRefCount(char*& h)
    {
        if (h == ::DAT_0109b220)
            return;
        NiAtomicSubtract(GetRealBufferStart(h)[0]);
    }
};
struct OMFixedString : public NiFixedString
{
    OMFixedString(const char* pc)
    {
        if (pc == 0)
            m_kHandle = ::DAT_0109b220;
        else
            m_kHandle = ::NiGlobalStringTable::AddString(pc);
    }
    ~OMFixedString()
    {
        NiGlobalStringTable::DecRefCount(m_kHandle);
    }
    OMFixedString& operator=(const char* pc)
    {
        if (m_kHandle != pc)
        {
            char* kHandle = m_kHandle;
            m_kHandle = ::NiGlobalStringTable::AddString(pc);
            NiGlobalStringTable::DecRefCount(kHandle);
        }
        return *this;
    }
};
class OMTex
{
  public:
    virtual void V0();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
class NiSourceTexture
{
  public:
};
class BSFileEntry;
struct TextureFileEntrySetter
{
};
struct Interface
{
};
struct GO
{
    OMTex* m_pObject;
    void operator=(void* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = (OMTex*)pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
    }
};
struct Helper62d0
{
    OMTex* m_pObject;
    void* operator=(const void* ptr)
    {
        if (m_pObject != ((const Helper62d0*)ptr)->m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = ((const Helper62d0*)ptr)->m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return this;
    }
};
class FileFinder;
class FileFinder
{
  public:
    enum FILE_LOCATION
    {
        FL_NONE
    };
    FILE_LOCATION GetFileLocation(char*, char*, unsigned int, unsigned int);
    static FileFinder* GetSingleton()
    {
        return (*reinterpret_cast<::fnv_00a1fa20::FileFinder * *>(&::g_fileFinder));
    }
};
void __cdecl ResolveTexturePath(const char*, float&, float, char*);
class OMTexPtr
{
  public:
    OMTex* m_pObject;
    ~OMTexPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    operator OMTex*() const
    {
        return m_pObject;
    }
};
struct OMMemContext
{
    int m_eMemoryContext;
    static int GetCurrent()
    {
        return ::g_tlsBlock.memoryContext;
    }
    static void SetCurrent(int i)
    {
        ::g_tlsBlock.memoryContext = i;
    }
    OMMemContext(int iNew)
    {
        m_eMemoryContext = GetCurrent();
        SetCurrent(iNew);
    }
    ~OMMemContext()
    {
        SetCurrent(m_eMemoryContext);
    }
};
// @fnv 0x00a1fa20
void __cdecl LoadTextureForFile(const char* apFilename, float& afScale, OMTexPtr& aspTexture, float afZoom,
                                OMTexPtr apDataImage)
{
    if (!apDataImage)
    {
        char acTexturePath[1024];
        acTexturePath[0] = 0;
        std::memset(acTexturePath + 1, 0, 0x3ff);
        ResolveTexturePath(apFilename, afScale, afZoom, acTexturePath);
        if (acTexturePath[0])
        {
            OMFixedString path(acTexturePath);
            ::FindTextureByPath(path.m_kHandle, (::NiTexture **)&(aspTexture));
            if (!aspTexture && FileFinder::GetSingleton()->GetFileLocation(acTexturePath, 0, 0, 0xffffffff))
            {
                path = acTexturePath;
                OMMemContext tempMemContext(0xd);
                ((GO*)&aspTexture)->operator=(((::fnv_00a1fa20::NiSourceTexture *)(::NiSourceTexture::Create((const ::NiFixedString &)(path), (::NiTexture__FormatPrefs &)((*reinterpret_cast<::NiTexture::TextureFormatPreferences *>(&::DAT_011a9598))), true, false))));
                if (aspTexture)
                {
                    if (!std::strstr((char *)(acTexturePath), "oading\\load_"))
                        ::TextureFileEntrySetter::SetTexture((NiTexture*)(OMTex*)aspTexture, (const ::BSFileEntry *)(const ::fnv_00a1fa20::BSFileEntry *)(0));
                }
                else
                {
                    ::FUN_0040fbe0();
                }
            }
        }
    }
    else
    {
        ((Helper62d0*)&aspTexture)->operator=(&apDataImage);
    }
    return;
}
}  // namespace fnv_00a1fa20

namespace ImageNodeBuild {
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    inline NiPointer(T* object = 0)
    {
        m_pObject = object;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    __forceinline ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    inline void Release()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    inline bool operator!() const
    {
        return m_pObject == 0;
    }
    NiPointer<T>& operator=(T*);
    NiPointer<T>& operator=(const NiPointer<T>&);
    inline operator T*() const
    {
        return m_pObject;
    }
    inline T* operator->() const
    {
        return m_pObject;
    }
};


struct NiObject
{
    virtual void OnObject();
    virtual void DeleteThis();
    long referenceCount;
    void IncRefCount()
    {
        InterlockedIncrement(&referenceCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&referenceCount) == 0)
            DeleteThis();
    }
};

struct GeometryData
{
    void FUN_00a67050(int);
};
struct NiNode;
struct PropertyList
{
    void* head;
    void* tail;
    unsigned int count;
    void FUN_00439fd0(const NiPointer<NiNode>&);
};
struct NiNode : NiObject
{
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
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
    virtual int GetPropertyType();
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
    virtual void AttachChildInAvailableSlot(NiNode*, bool);
    void AssignFixedString(const L::NiFixedString&);
    void FUN_00439410(NiNode*);
    GeometryData* GetGeometryData()
    {
        return geometryData;
    }
    void SetExtraBuffer(void* buffer)
    {
        m_pExtraBuffer = buffer;
    }
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    PropertyList properties;
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
    GeometryData* geometryData;
    unsigned int unk0bc;
    void* m_pExtraBuffer;
};
inline void NiNode::FUN_00439410(NiNode* property)
{
    if (property->GetPropertyType() < 7)
    {
        NiPointer<NiNode> heldProperty(property);
        properties.FUN_00439fd0(heldProperty);
    }
}
class TileShaderProperty : public NiObject
{
};
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* object)
{
    if (m_pObject != object)
    {
        if (m_pObject)
            m_pObject->DecRefCount();
        m_pObject = object;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    return *this;
}
struct TraitArray
{
    void* vtable;
    void* buffer;
    unsigned int size;
    unsigned int reserved;
};
struct StringValue
{
    char* pString;
    unsigned short length;
    unsigned short maxLength;
};
struct GameAllocator
{
};
struct NiPoint3
{
    float x, y, z;
    NiPoint3()
    {}
    NiPoint3(float vx, float vy, float vz) : x(vx), y(vy), z(vz)
    {}
};
struct NiUV
{
    float u, v_r;
    NiUV()
    {}
    NiUV(float x, float y) : u(x), v_r(y)
    {}
};
extern void* __cdecl FUN_00aa13e0(unsigned int);
extern unsigned int __cdecl FUN_00ec62c0();
extern void __cdecl FUN_00a5b690_(const char*);
struct FUN_00c5cf30
{
    static __forceinline void* operator new(size_t)
    {
        return FUN_00aa13e0(0xd4);
    }
    FUN_00c5cf30(int, NiPoint3*, NiPoint3*, int, NiUV*, int, int, int, unsigned short*, int, int, unsigned int);
};
struct FUN_00a74410
{
    static __forceinline void* operator new(size_t)
    {
        return FUN_00aa13e0(0xc4);
    }
    FUN_00a74410(int, NiPoint3*, NiPoint3*, int, NiUV*, int, int, int, unsigned short*);
};
static __forceinline unsigned int GeometryTime()
{
    ::Interface::GetFirstInterfaceFloat();
    ::Interface::UpdateInterfaceState();
    return FUN_00ec62c0();
}
struct FUN_00bb7c30
{
    static __forceinline void* operator new(size_t)
    {
        return FUN_00aa13e0(0xb0);
    }
    FUN_00bb7c30(int);
};
struct FUN_00a5ecb0
{
    static __forceinline void* operator new(size_t)
    {
        return FUN_00aa13e0(0xac);
    }
    FUN_00a5ecb0(int);
};
extern char DAT_010954cc[];
struct FUN_00a7b2e0 : NiObject
{
    char* name;
    FUN_00a7b2e0();
    ~FUN_00a7b2e0();
    void AssignFixedString(const L::NiFixedString&);
};
struct FUN_00a1f610 : FUN_00a7b2e0
{
    void* tile;
    NiNode* node;
    static __forceinline void* operator new(size_t)
    {
        return FUN_00aa13e0(0x14);
    }
    FUN_00a1f610(void* owner, NiNode* model) : tile(owner), node(model)
    {
        AssignFixedString(L::NiFixedString(DAT_010954cc));
    }
};
extern void* __cdecl FUN_00a5b690(const char*);
extern char kGeometryName[];
static __forceinline void GD(NiNode* n)
{
    n->GetGeometryData()->FUN_00a67050(0);
}
static __forceinline NiNode* AsN(NiNode* p)
{
    return p;
}

struct TileImageShim
{
    void* vtable;
    NiTPointerList<Tile*> m_kChildTileList;
    BSSimpleArray<Tile::Value*, 8> m_kValues;
    BSStringT<char> StringProvider;
    Tile* pParent;
    NiPointer<NiNode> m_pRenderedNodeEntry;
    unsigned int uiFlags;
    bool m_bFlagAfterUiFlags;
    bool m_bSpeechChallengeFailure;
    float fScale;
    NiPointer<NiTexture> spTexture;
    NiPointer<TileShaderProperty> m_spShaderProperty;
    bool m_bTextureLoaded;
    NiNode* FUN_00a1fd50();
};
// Builds a quad geometry object, attaches it beneath a node returned by FUN_00a089c0() or a fallback, and returns the containing node.
// @fnv 0x00a1fd50
NiNode* TileImageShim::FUN_00a1fd50()
{
    NiNode* cnt_lgft;
    cnt_lgft = ((::ImageNodeBuild::NiNode *)(reinterpret_cast<::TileX *>(this)->GetNiNode()));
    NiPointer<NiNode> ptr_k;

    NiPoint3* vertices_nriq;
    vertices_nriq = new NiPoint3[4];
    void* s_xx;
    s_xx = 0;
    NiUV* extraBuffer_tjnslw;
    extraBuffer_tjnslw = new NiUV[4];
    unsigned short* indices_tyg;
    indices_tyg = static_cast<unsigned short*>(::FUN_00aa1070(6 * sizeof(unsigned short)));
    NiPoint3* previous_zphzqj;
    previous_zphzqj = 0;

    vertices_nriq[0] = NiPoint3(0.0f, 0.0f, 0.0f);
    vertices_nriq[1] = NiPoint3(0.0f, 0.0f, -1.0f);
    vertices_nriq[2] = NiPoint3(1.0f, 0.0f, 0.0f);
    vertices_nriq[3] = NiPoint3(1.0f, 0.0f, -1.0f);
    indices_tyg[0] = 0;
    indices_tyg[1] = 1;
    indices_tyg[2] = 2;
    indices_tyg[3] = 2;
    indices_tyg[4] = 1;
    indices_tyg[5] = 3;

    extraBuffer_tjnslw[0] = NiUV(0.0f, 0.0f);
    extraBuffer_tjnslw[1] = NiUV(0.0f, 1.0f);
    extraBuffer_tjnslw[2] = NiUV(1.0f, 0.0f);
    extraBuffer_tjnslw[3] = NiUV(1.0f, 1.0f);

    if (reinterpret_cast<::FUN_00a01230_shell *>(this)->IsTraitNonZero(0xfae))
    {
        ptr_k =
            (NiNode*)new FUN_00c5cf30(4, vertices_nriq, previous_zphzqj, 0, extraBuffer_tjnslw, 1, 0, 2, indices_tyg, 0,
                                      0, (((void)(::Interface::GetFirstInterfaceFloat())), ::Interface::UpdateInterfaceState(), FUN_00ec62c0()));
        m_bTextureLoaded = true;
    }
    else
    {
        ptr_k =
            (NiNode*)new FUN_00a74410(4, vertices_nriq, previous_zphzqj, 0, extraBuffer_tjnslw, 1, 0, 2, indices_tyg);
        m_bTextureLoaded = false;
    }

    ::AssignFixedString((char *)((ptr_k).operator->()), 0, (char **)&(const ::L::NiFixedString &)(L::NiFixedString(kGeometryName)));
    GD(ptr_k);

    m_spShaderProperty = (TileShaderProperty*)(new FUN_00bb7c30(0));
    reinterpret_cast<::FUN_00439410_cls *>(((ptr_k).operator->()))->FUN_00439410((::ArgObject *)(::ImageNodeBuild::NiNode *)((NiNode*)(TileShaderProperty*)m_spShaderProperty));

    void* v_r;
    void* kIter_bw;
    kIter_bw = ((void *)(::FUN_00b55560(0x20)));
    v_r = kIter_bw;
    ptr_k->SetExtraBuffer(v_r);

    m_pRenderedNodeEntry = (NiNode*)(new FUN_00a5ecb0(0));
    m_pRenderedNodeEntry->AttachChildInAvailableSlot(ptr_k, true);
    if (0 == cnt_lgft)
        cnt_lgft = (NiNode*)((void *)(::Interface::GetInterfaceNode()));
    cnt_lgft->AttachChildInAvailableSlot(m_pRenderedNodeEntry, true);

    ::AssignFixedString((char *)((m_pRenderedNodeEntry).operator->()), 0, (char **)&(const ::L::NiFixedString &)(L::NiFixedString(StringProvider.pString)));
    ::AttachFaceGenAnimationData((::NiAVObject *)(void *)(ptr_k));
    reinterpret_cast<::FUN_00a5a040_Class *>(((m_pRenderedNodeEntry).operator->()))->FUN_00a5a040();
    ::fnv_00707930::FUN_00707930(1);

    reinterpret_cast<::FUN_00a5bca0_shell *>(((m_pRenderedNodeEntry).operator->()))->SetExtraDataName((::NiExtraData *)(void *)(new FUN_00a1f610(this, (NiNode*)m_pRenderedNodeEntry)));

    reinterpret_cast<::UpdateTreeNode *>(this)->FUN_00a037e0(0xfad, reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfad), {});
    if (reinterpret_cast<::FUN_00a01230_shell *>(this)->IsTraitNonZero(0xfae))
        reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(0x100);
    reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(0x3d);
    return (NiNode*)m_pRenderedNodeEntry;
}

}




inline unsigned int BSStringLength(const char* p)
{
    return strlen(p);
}

inline unsigned int BSStringCapacityMaximum(unsigned int a, unsigned int b)
{
    return a > b ? a : b;
}

template <class CharT> struct GameString
{
    char* text;
    unsigned short length, capacity;
    unsigned int MaxLength() const
    {
        return capacity;
    }
    void SetLength(unsigned int n)
    {
        length = n <= 65535 ? (unsigned short)n : 65535;
    }
    void SetCapacity(unsigned int n)
    {
        capacity = n <= 65535 ? (unsigned short)n : 65535;
    }
    GameString() : text(0)
    {
        SetLength(0);
        SetCapacity(0);
    }
    bool Set(const char* source, unsigned int requested)
    {
        unsigned int count = source ? BSStringLength(source) : 0;
        unsigned int reserve = ::FUN_00403940(count, requested);
        unsigned int copySize = count + 1;
        unsigned int allocationSize = reserve + 1;
        if (reserve <= MaxLength())
        {
            if (reserve)
            {
                if (source)
                    memcpy(text, source, copySize);
                else
                    *text = 0;
            }
            else
            {
                if (text)
                    delete text;
                text = 0;
                reserve = 0;
                SetCapacity(reserve);
            }
        }
        else
        {
            char* old = text;
            text = new char[allocationSize];
            if (source)
                memcpy(text, source, copySize);
            else
                *text = 0;
            if (old)
                delete old;
            SetCapacity(reserve);
        }
        SetLength(count);
        return count != 0;
    }
    const char* c_str() const
    {
        return text;
    }
};

typedef GameString<char> AtlasString;

struct MemoryManager
{
};

struct AtlasRect
{
    float left, right, top, bottom;
    AtlasRect() : left(0), right(0), top(0), bottom(0)
    {}
};

struct AtlasEntry
{
    AtlasString definition, image, texture;
    AtlasRect rect;
    AtlasEntry()
    {}
};

struct AtlasNode
{
    AtlasEntry* entry;
    AtlasNode* next;
    AtlasNode(AtlasEntry* const& value) : entry(value), next(0)
    {}
    void AddToHead(AtlasEntry** value)
    {
        if (!*value)
            return;
        if (entry)
        {
            AtlasNode* node = new AtlasNode(entry);
            node->next = next;
            next = node;
            entry = *value;
        }
        else
            entry = *value;
    }
    AtlasEntry* Get() const
    {
        return entry;
    }
};

struct AtlasFile
{
    virtual ~AtlasFile();
    virtual void S1();
    virtual void S2();
    virtual void S3();
    virtual void S4();
    virtual void S5();
    virtual void S6();
    virtual void S7();
    virtual bool Seek(int, int);
    virtual void S9();
    virtual void S10();
    virtual void S11();
    virtual void S12();
    virtual unsigned int ReadLine(char*, unsigned int, int);
};

AtlasFile* FUN_00afdf00(const char*, int, unsigned int);



extern "C" int __cdecl memcpy_s(void*, size_t, const void*, size_t);

extern "C" int __cdecl memmove_s(void*, size_t, const void*, size_t);

namespace std {
template <class E> struct char_traits;
template <> struct char_traits<char>
{
    typedef char char_type;
    static bool eq(const char& _Left, const char& _Right)
    {
        return _Left == _Right;
    }
    static void assign(char& _Left, const char& _Right)
    {
        _Left = _Right;
    }
    static size_t length(const char* _First)
    {
        return ::strlen(_First);
    }
    static int compare(const char* _First1, const char* _First2, size_t _Count)
    {
        return ::memcmp(_First1, _First2, _Count);
    }
    static char* _Copy_s(char* _First1, size_t _Size_in_bytes, const char* _First2, size_t _Count)
    {
        ::memcpy_s(_First1, _Size_in_bytes, _First2, _Count);
        return _First1;
    }
    static char* _Move_s(char* _First1, size_t _Size_in_bytes, const char* _First2, size_t _Count)
    {
        ::memmove_s(_First1, _Size_in_bytes, _First2, _Count);
        return _First1;
    }
};
struct _Secure_char_traits_tag
{
};
template <class T> inline _Secure_char_traits_tag _Char_traits_cat()
{
    _Secure_char_traits_tag _Secure;
    return _Secure;
}
namespace _Traits_helper {
template <class T>
inline typename T::char_type* copy_s(typename T::char_type* _First1, size_t _Size, const typename T::char_type* _First2,
                                     size_t _Count, _Secure_char_traits_tag)
{
    return T::_Copy_s(_First1, _Size, _First2, _Count);
}
template <class T>
inline typename T::char_type* copy_s(typename T::char_type* _First1, size_t _Size, const typename T::char_type* _First2,
                                     size_t _Count)
{
    return copy_s<T>(_First1, _Size, _First2, _Count, _Char_traits_cat<T>());
}
template <class T>
inline typename T::char_type* move_s(typename T::char_type* _First1, size_t _Size, const typename T::char_type* _First2,
                                     size_t _Count, _Secure_char_traits_tag)
{
    return T::_Move_s(_First1, _Size, _First2, _Count);
}
template <class T>
inline typename T::char_type* move_s(typename T::char_type* _First1, size_t _Size, const typename T::char_type* _First2,
                                     size_t _Count)
{
    return move_s<T>(_First1, _Size, _First2, _Count, _Char_traits_cat<T>());
}
}
template <class T> struct _Allocator_base
{
    typedef T value_type;
};
template <class T> class allocator : public _Allocator_base<T>
{
  public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef size_t size_type;
    typedef int difference_type;
    template <class U> struct rebind
    {
        typedef allocator<U> other;
    };
    allocator() throw()
    {}
    allocator(const allocator&) throw()
    {}
    void deallocate(pointer _Ptr, size_type)
    {
        ::FUN_00401030(_Ptr);
    }
    pointer allocate(size_type _Count)
    {
        return (pointer)::FUN_00401000(_Count * sizeof(T));
    }
    size_t max_size() const throw()
    {
        size_t _Count = (size_t)-1 / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
class _Container_base_secure
{
};
class _String_base : public _Container_base_secure
{
  public:
    static void _Xran();
    static void _Xlen();
};
template <class T, class A> class _String_val : public _String_base
{
  protected:
    typedef typename A::template rebind<T>::other _Alty;
    _String_val(_Alty _Al = _Alty()) : _Alval(_Al)
    {}

  public:
    _String_val(const _String_val& _Right) : _Alval(_Right._Alval)
    {}

  protected:
    _Alty _Alval;
};
template <class _Elem, class _Traits = char_traits<_Elem>, class _Ax = allocator<_Elem> >
class basic_string : public _String_val<_Elem, _Ax>
{
  public:
    typedef basic_string<_Elem, _Traits, _Ax> _Myt;
    typedef _String_val<_Elem, _Ax> _Mybase;
    typedef typename _Mybase::_Alty _Alloc;
    typedef typename _Alloc::size_type size_type;
    typedef typename _Alloc::difference_type _Dift;
    typedef _Dift difference_type;
    typedef typename _Alloc::pointer _Tptr;
    typedef typename _Alloc::const_pointer _Ctptr;
    typedef _Tptr pointer;
    typedef _Ctptr const_pointer;
    typedef typename _Alloc::reference _Reft;
    typedef _Reft reference;
    typedef typename _Alloc::const_reference const_reference;
    typedef typename _Alloc::value_type value_type;
    basic_string() : _Mybase()
    {
        _Tidy();
    }
    basic_string(const _Myt& _Right, size_type _Roff, size_type _Count, const _Alloc& _Al) : _Mybase(_Al)
    {
        _Tidy();
        assign(_Right, _Roff, _Count);
    }
    basic_string(const _Myt& _Right) : _Mybase(_Right)
    {
        _Tidy();
        assign(_Right, 0, npos);
    }
    ~basic_string()
    {
        _Tidy(true);
    }
    typedef _Traits traits_type;
    typedef _Alloc allocator_type;
    static const size_type npos;
    _Myt& operator=(const _Myt& _Right)
    {
        return (assign(_Right));
    }
    _Myt& append(const _Myt& _Right, size_type _Roff, size_type _Count)
    {
        if (_Right.size() < _Roff)
            _String_base::_Xran();
        size_type _Num = _Right.size() - _Roff;
        if (_Num < _Count)
            _Count = _Num;
        if (::g_010173f0 - _Mysize <= _Count || _Mysize + _Count < _Mysize)
            _String_base::_Xlen();
        if (0 < _Count && _Grow(_Num = _Mysize + _Count))
        {
            _Traits_helper::copy_s<_Traits>(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Mysize, _Myres - _Mysize, _Right._Myptr() + _Roff, _Count);
            _Eos(_Num);
        }
        return (*this);
    }
    _Myt& FUN_00a0c430(const _Elem* _Ptr, size_type _Count)
    {
        if (_Inside(_Ptr))
            return (append(*this, _Ptr - reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970(), _Count));
        if (::g_010173f0 - _Mysize <= _Count || _Mysize + _Count < _Mysize)
            _String_base::_Xlen();
        size_type _Num;
        if (0 < _Count && _Grow(_Num = _Mysize + _Count))
        {
            _Traits_helper::copy_s<_Traits>(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Mysize, _Myres - _Mysize, _Ptr, _Count);
            _Eos(_Num);
        }
        return (*this);
    }
    _Myt& append(const _Elem* _Ptr)
    {
        ;
        return ((*(::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char>> *)&(reinterpret_cast<::StrA *>(this)->FUN_00a0c430(_Ptr, _Traits::length(_Ptr)))));
    }
    _Myt& assign(const _Myt& _Right)
    {
        return (assign(_Right, 0, ::g_010173f0));
    }
    _Myt& assign(const _Myt& _Right, size_type _Roff, size_type _Count)
    {
        if (_Right.size() < _Roff)
            _String_base::_Xran();
        size_type _Num = _Right.size() - _Roff;
        if (_Count < _Num)
            _Num = _Count;
        if (this == &_Right)
            erase((size_type)(_Roff + _Num)), erase(0, _Roff);
        else if (_Grow(_Num))
        {
            _Traits_helper::copy_s<_Traits>(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970(), _Myres, _Right._Myptr() + _Roff, _Num);
            _Eos(_Num);
        }
        return (*this);
    }
    _Myt& assign(const _Elem* _Ptr, size_type _Count)
    {
        if (_Inside(_Ptr))
            return (assign(*this, _Ptr - reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970(), _Count));
        if (_Grow(_Count))
        {
            _Traits_helper::copy_s<_Traits>(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970(), _Myres, _Ptr, _Count);
            _Eos(_Count);
        }
        return (*this);
    }
    _Myt& assign(const _Elem* _Ptr)
    {
        ;
        return (assign(_Ptr, _Traits::length(_Ptr)));
    }
    _Myt& erase(size_type _Off = 0, size_type _Count = ::g_010173f0)
    {
        if (_Mysize < _Off)
            _String_base::_Xran();
        if (_Mysize - _Off < _Count)
            _Count = _Mysize - _Off;
        if (0 < _Count)
        {
            _Traits_helper::move_s<_Traits>(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Off, _Myres - _Off, reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Off + _Count,
                                            _Mysize - _Off - _Count);
            size_type _Newsize = _Mysize - _Count;
            _Eos(_Newsize);
        }
        return (*this);
    }
    const _Elem* c_str() const
    {
        return (_Myptr());
    }
    size_type size() const
    {
        return (_Mysize);
    }
    size_type max_size() const
    {
        size_type _Num = _Mybase::_Alval.max_size();
        return (_Num <= 1 ? 1 : _Num - 1);
    }
    size_type FUN_00a0c300(const _Elem* _Ptr, size_type _Off, size_type _Count) const
    {
        if (_Count == 0)
            return (_Off < _Mysize ? _Off : _Mysize);
        if (_Count <= _Mysize)
        {
            const _Elem* _Uptr = _Myptr() + (_Off < _Mysize - _Count ? _Off : _Mysize - _Count);
            for (;; --_Uptr)
                if (_Traits::eq(*_Uptr, *_Ptr) && _Traits::compare(_Uptr, _Ptr, _Count) == 0)
                    return (_Uptr - _Myptr());
                else if (_Uptr == _Myptr())
                    break;
        }
        return (::g_010173f0);
    }
    size_type find_last_of(_Elem _Ch, size_type _Off = ::g_010173f0) const
    {
        return (reinterpret_cast<::StringQ *>((void *)this)->FUN_00a0c300((const _Elem*)&_Ch, _Off, 1));
    }
    _Myt Substr(size_type _Off = 0, size_type _Count = npos) const
    {
        return (_Myt(*this, _Off, _Count, get_allocator()));
    }
    allocator_type get_allocator() const
    {
        return (_Mybase::_Alval);
    }
    enum
    {
        _BUF_SIZE = 16 / sizeof(_Elem) < 1 ? 1 : 16 / sizeof(_Elem)
    };

  public:
    enum
    {
        _ALLOC_MASK = sizeof(_Elem) <= 1   ? 15
                      : sizeof(_Elem) <= 2 ? 7
                      : sizeof(_Elem) <= 4 ? 3
                      : sizeof(_Elem) <= 8 ? 1
                                           : 0
    };
    void _Copy(size_type _Newsize, size_type _Oldlen)
    {
        size_type _Newres = _Newsize | _ALLOC_MASK;
        if (max_size() < _Newres)
            _Newres = _Newsize;
        else if (_Newres / 3 < _Myres / 2 && _Myres <= max_size() - _Myres / 2)
            _Newres = _Myres + _Myres / 2;
        _Elem* _Ptr = 0;
        try
        {
            _Ptr = _Mybase::_Alval.allocate(_Newres + 1);
        }
        catch (...)
        {
            _Newres = _Newsize;
            try
            {
                _Ptr = _Mybase::_Alval.allocate(_Newres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < _Oldlen)
            _Traits_helper::copy_s<_Traits>(_Ptr, _Newres + 1, reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970(), _Oldlen);
        _Tidy(true);
        _Bx._Ptr = _Ptr;
        _Myres = _Newres;
        _Eos(_Oldlen);
    }
    void _Eos(size_type _Newsize)
    {
        _Traits::assign(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970()[_Mysize = _Newsize], _Elem());
    }
    bool _Grow(size_type _Newsize, bool _Trim = false)
    {
        if (max_size() < _Newsize)
            _String_base::_Xlen();
        if (_Myres < _Newsize)
            _Copy(_Newsize, _Mysize);
        else if (_Trim && _Newsize < _BUF_SIZE)
            reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, _Newsize < _Mysize ? _Newsize : _Mysize);
        else if (_Newsize == 0)
            _Eos(0);
        return (0 < _Newsize);
    }
    bool _Inside(const _Elem* _Ptr)
    {
        if (_Ptr == 0 || _Ptr < reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() || reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970() + _Mysize <= _Ptr)
            return (false);
        else
            return (true);
    }
    void _Tidy(bool _Built = false, size_type _Newsize = 0)
    {
        if (!_Built)
            ;
        else if (_BUF_SIZE <= _Myres)
        {
            _Elem* _Ptr = _Bx._Ptr;
            if (0 < _Newsize)
                _Traits_helper::copy_s<_Traits>(_Bx._Buf, _BUF_SIZE, _Ptr, _Newsize);
            _Mybase::_Alval.deallocate(_Ptr, _Myres + 1);
        }
        _Myres = _BUF_SIZE - 1;
        _Eos(_Newsize);
    }
    union _Bxty
    {
        _Elem _Buf[_BUF_SIZE];
        _Elem* _Ptr;
    } _Bx;
    _Elem* _Myptr()
    {
        return (_BUF_SIZE <= _Myres ? _Bx._Ptr : _Bx._Buf);
    }
    const _Elem* _Myptr() const
    {
        return (_BUF_SIZE <= _Myres ? _Bx._Ptr : _Bx._Buf);
    }
    size_type _Mysize;
    size_type _Myres;
};
typedef basic_string<char> string;
}

typedef std::string AtlasPath;

// @fnv 0x00a06dd0
void FUN_00a06dd0(const char* definition, const char* image, AtlasString* texture, float* bounds)
{
    char line5[1024];
    char filename9[260];
    fnv::crt::strcpy_s(filename9, 260, "Data\\Textures\\");
    AtlasFile* fileA = 0;
    if (definition && image && (texture || bounds))
    {
        const char* slashTmp = strrchr(image, '\\');
        bool foundImage = false;
        bool foundDefinition4 = false;
        fnv::crt::strcat_s(filename9, 260, definition);
        image = slashTmp ? slashTmp + 1 : image;
        for (AtlasNode* nodeB = &(*reinterpret_cast<::AtlasNode *>(&::fnv_00a00a30::DAT_011f3350)); nodeB && nodeB->entry; nodeB = nodeB->next)
        {
            if (!strcmp(nodeB->Get()->definition.c_str(), definition))
                foundDefinition4 = true;
            if (!strcmp(nodeB->entry->image.c_str(), image))
            {
                if (texture)
                    reinterpret_cast<::TextString *>((texture))->FUN_004037f0(nodeB->entry->texture.c_str(), 0);
                if (bounds)
                {
                    bounds[0] = nodeB->entry->rect.left;
                    bounds[3] = nodeB->entry->rect.bottom;
                    bounds[2] = nodeB->entry->rect.top;
                    bounds[1] = nodeB->entry->rect.right;
                }
                foundImage = true;
            }
        }
        if (foundImage || (!foundImage && foundDefinition4))
        {
        }
        else
        {
            fileA = FUN_00afdf00(filename9, 0, 0x4000);
            if (fileA && fileA->Seek(0, 0))
            {
                while (fileA->ReadLine(line5, 1024, 10))
                {
                    AtlasPath str;
                    AtlasEntry* entry5 = 0;
                    strtok(line5, " ,\t");
                    if (line5[0] == '#' || line5[0] == '\n' || line5[0] == '\t' || line5[0] == '\r' || line5[0] == ' ')
                        continue;
                    entry5 = new AtlasEntry;
                    reinterpret_cast<::TextString *>(&(entry5->definition))->FUN_004037f0(definition, 0);
                    reinterpret_cast<::TextString *>(&(entry5->image))->FUN_004037f0(line5, 0);
                    str.assign(definition);
                    str = str.Substr(0, str.find_last_of('\\') + 1);
                    str.append(strtok(0, " ,\t"));
                    reinterpret_cast<::TextString *>(&(entry5->texture))->FUN_004037f0(str.c_str(), 0);
                    for (int i3 = 0; i3 < 2; i3++)
                        strtok(0, " ,\t");
                    entry5->rect.left = (float)::std::atof(strtok(0, " ,\t"));
                    entry5->rect.top = (float)::std::atof(strtok(0, " ,\t"));
                    strtok(0, " ,");
                    entry5->rect.right = (float)::std::atof(strtok(0, " ,\t"));
                    entry5->rect.bottom = (float)::std::atof(strtok(0, " ,\t"));
                    entry5->rect.right += entry5->rect.left;
                    entry5->rect.bottom += entry5->rect.top;
                    if (!strcmp(entry5->image.c_str(), image))
                    {
                        if (texture)
                            reinterpret_cast<::TextString *>((texture))->FUN_004037f0(entry5->texture.c_str(), 0);
                        if (bounds)
                        {
                            bounds[0] = entry5->rect.left;
                            bounds[3] = entry5->rect.bottom;
                            bounds[2] = entry5->rect.top;
                            bounds[1] = entry5->rect.right;
                        }
                    }
                    reinterpret_cast<::S_00a0c7c0_List *>(&((*reinterpret_cast<::AtlasNode *>(&::fnv_00a00a30::DAT_011f3350))))->AddToHead((void **)(::AtlasEntry **)(&entry5));
                }
            }
            delete fileA;
        }
    }
}

#include "generated/data/bsmenu/tileimage.inc"
