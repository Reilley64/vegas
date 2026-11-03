
// src/bsshader/bsshadermanager_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsshader/bsshadermanager.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include <windows.h>
#include <cmath>
#include <cstring>
#include "fnv/decl/FUN_0046e8e0_This.h"
#include "fnv/decl/FUN_0046eb00_Class.h"
#include "fnv/decl/FUN_0046eb20_Class.h"
#include "fnv/decl/FUN_0046ebd0_Class.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00ba3780_struct.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/fnv_0046eb40__FUN_0046eb40_Class.h"
#include "fnv/decl/fnv_0046eb60__FUN_0046eb60_Class.h"
#include "fnv/decl/fnv_0046eb80__FUN_0046eb80_Class.h"
#include "fnv/decl/fnv_0046eba0__FUN_0046eba0_class.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_00a60000.h"
#include "fnv/symbols_00a61000.h"
#include "fnv/symbols_00b4f000.h"
#include "fnv/symbols_00b54000.h"
#include "fnv/symbols_00b55000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f8000.h"
#include "fnv/symbols_011f9000.h"
#include "bsshadermanager_decls.h"
#include <stddef.h>
extern "C" int __cdecl strcpy_s(char*, size_t, const char*);
extern "C" int __cdecl _strnicmp(const char*, const char*, size_t);
class NiRTTI;
class NiRenderer;
class BSFileEntry;
class BSFogProperty;
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    __forceinline void DecRefCount()
    {
        if (!InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)))
            DeleteThis();
    }
};
class NiObject : public NiRefObject
{
  public:
    NiObject* DynamicCast(const NiRTTI*);
};
class NiFixedString
{
  public:
    char* m_kHandle;
    NiFixedString(const char*);
    ~NiFixedString();
};
class NiTextureRendererData
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
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
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual unsigned int vfn_98();
};
class NiTexture : public NiObject
{
  public:
    unsigned char objectNET[16];
    struct TextureFormatPreferences
    {
        unsigned int m_ePreferredPixelLayout, m_eAlphaFormat, m_eMipFlag;
    } m_kTextureFormatPreferences;
    NiTextureRendererData* m_pTextureRendererData;
    NiTexture* m_pkPrev;
    NiTexture* m_pkNext;
};
template <class T> class NiPointer;
template <> class NiPointer<NiTexture>
{
  public:
    NiTexture* m_pObject;
    NiPointer();
    ~NiPointer();
    NiPointer& operator=(NiTexture*);
    __forceinline void Reset()
    {
        if (m_pObject)
        {
            m_pObject->DecRefCount();
            m_pObject = 0;
        }
    }
};
class NiFixedString;
class NiTexture__FormatPrefs;
class NiSourceTexture : public NiTexture
{
  public:
    void* m_spPixelData;
    const char* m_pcFileName;
public:
    static ::NiSourceTexture *Create(const ::NiFixedString &, ::NiTexture__FormatPrefs &, bool, bool);
};
class FileFinder
{
  public:
    enum FILE_LOCATION
    {
        FILE_NOT_FOUND = 0
    };
    FILE_LOCATION GetFileLocation(char*, char*, unsigned int, unsigned int);
};
class TextureFileEntrySetter
{
  public:
    static void SetTexture(NiTexture*, const BSFileEntry*);
};
class NiAVObject
{
  public:
};
class ShadowSceneNode
{
  public:
    void SetFogPropertyForIndex(BSFogProperty*);
};
class BSShaderManager
{
  public:
    enum eObjectType
    {
        OBJECT_0 = 0,
        OBJECT_1 = 1
    };
    static void GetTexture(const char*, bool, NiPointer<NiTexture>&, bool, bool);
    static void BuildTexturePath(char*, const char*, const char*, bool);
    static void SetFOV(float);
    static char* GetRenderModeName();
    static void SetRenderMode(unsigned int);
    static void UpdateObjectTypeRecurse(NiAVObject*, bool, bool);
    static void SetObjectTypeRecursively(NiAVObject*, eObjectType, bool, bool);
    static void SetFogPropertyForIndex(int, BSFogProperty*);
};
extern const double DAT_010ad6d8;
extern float DAT_011adcc8;
extern void (*DAT_011f9f38)(), (*DAT_011f9f3c)();
class SkyShaderProperty
{
  public:
    unsigned char propertyData[0x70];
    NiPointer<NiTexture> m_spTexture;
    void SetTexture(NiTexture*);
};
#pragma intrinsic(sin, cos)
// The shipped setter was built without optimization.
#pragma optimize("", off)
#pragma optimize("", on)
struct ImageSpaceTexture
{
};
struct ImageSpaceManager
{
    char data[0x204];
    ImageSpaceTexture m_texture;
};
struct PropHelper
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void* vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void* vfn_18();
    char _pad[0x9C];
    void** m_children;
    unsigned short _pad2;
    unsigned short m_uiItemCount;
};
struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};
extern float DAT_011f95f4;
extern float DAT_011f95f8;
extern float DAT_011f95fc;
extern float DAT_011f9600;
void __cdecl SetRectCenterAndHalfExtents(tagRECT* apLoadedRect);

struct TGProperty;
struct TGGeometry;
struct TGTextureInfo;

struct TGRTTI
{
    int unk00;
};

struct TGAVObject
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int IsSceneNode();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual int IsGeometry();
};

struct TGNode : TGAVObject
{
    unsigned int GetArrayCount();
};

struct TGGeometry : TGAVObject
{
};

struct TGTexturingProperty
{
};


struct TGGatherer
{
    void FUN_0046e910(TGAVObject* apObject, int aiArg);
};

// @fnv 0x0046e910
void TGGatherer::FUN_0046e910(TGAVObject* apObject, int aiArg)
{
    if (apObject)
    {
        if (apObject->IsGeometry())
        {
            TGGeometry* pGeom = (TGGeometry*)apObject;
            TGProperty* pAlpha6 = ((::TGProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((pGeom))->FUN_00a59d30(3)));
            TGTexturingProperty* pTexProp2 = ((::TGTexturingProperty *)(::FUN_00653270((const ::NiRTTI *)(const ::TGRTTI *)(&(*reinterpret_cast<::TGRTTI *>(&::g_011f49a4))), (::NiObject *)(::TGProperty *)(((::TGProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((pGeom))->FUN_00a59d30(5)))))));
            if (pTexProp2)
            {
                reinterpret_cast<::FUN_0046e8e0_This *>(this)->FUN_0046e8e0((::KFModel *)(::TGTextureInfo *)(((::TGTextureInfo *)(reinterpret_cast<::FUN_0046eb20_Class *>((pTexProp2))->GetElementAt2()))), {}, {}, {}, {});
                reinterpret_cast<::FUN_0046e8e0_This *>(this)->FUN_0046e8e0((::KFModel *)(::TGTextureInfo *)(((::TGTextureInfo *)(reinterpret_cast<::fnv_0046eb80::FUN_0046eb80_Class *>((pTexProp2))->GetEntryAt5()))), {}, {}, {}, {});
                reinterpret_cast<::FUN_0046e8e0_This *>(this)->FUN_0046e8e0((::KFModel *)(::TGTextureInfo *)(((::TGTextureInfo *)(reinterpret_cast<::fnv_0046eb60::FUN_0046eb60_Class *>((pTexProp2))->FUN_0046eb60()))), {}, {}, {}, {});
                reinterpret_cast<::FUN_0046e8e0_This *>(this)->FUN_0046e8e0((::KFModel *)(::TGTextureInfo *)(((::TGTextureInfo *)(reinterpret_cast<::fnv_0046eb40::FUN_0046eb40_Class *>((pTexProp2))->FUN_0046eb40()))), {}, {}, {}, {});
                reinterpret_cast<::FUN_0046e8e0_This *>(this)->FUN_0046e8e0((::KFModel *)(::TGTextureInfo *)(((::TGTextureInfo *)(reinterpret_cast<::FUN_0046eb00_Class *>((pTexProp2))->GetSecondElement()))), {}, {}, {}, {});
                for (unsigned int i = 0; i < reinterpret_cast<::FUN_0046ebd0_Class *>((pTexProp2))->FUN_0046ebd0(); i++)
                    reinterpret_cast<::FUN_0046e8e0_This *>(this)->FUN_0046e8e0((::KFModel *)(::TGTextureInfo *)(((::TGTextureInfo *)(reinterpret_cast<::fnv_0046eba0::FUN_0046eba0_class *>((pTexProp2))->GetElementAtOffset(i)))), {}, {}, {}, {});
            }
        }
        else if (apObject && apObject->IsSceneNode())
        {
            TGNode* pNode = (TGNode*)apObject;
            unsigned int uiCount5 = pNode->GetArrayCount();
            for (unsigned int j2 = 0; j2 < uiCount5; j2++)
            {
                TGAVObject* pChild2 = ((::TGAVObject *)(reinterpret_cast<::NiNode *>((pNode))->GetAt(j2)));
                if (pChild2)
                    FUN_0046e910(pChild2, aiArg);
            }
        }
    }
}
