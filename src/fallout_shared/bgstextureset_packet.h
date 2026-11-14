// Unit-local header for fallout_shared/bgstextureset.cpp.
// Class layouts (TESObject through BGSTextureSet) are copied verbatim from
// the PC object is 0xA0 bytes (InitializeNullTextureSet operator new) with 6
// texture slots, a DecalData* at +0x80, flags at +0x84 and 6 file entries at
// +0x88 (ResetFormData/ClearData/Load all loop 6). Real method declarations
#ifndef FNV_BGSTEXTURESET_UNIT_H
#define FNV_BGSTEXTURESET_UNIT_H

#include <new>
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00472840_impl.h"
#include "fnv/decl/TESDataHandler.h"
#include "fnv/decl/TextureLoader.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00593000.h"
#include "fnv/symbols_00af4000.h"
#include "fnv/symbols_00af6000.h"
#include "fnv/symbols_00afd000.h"
#include "fnv/symbols_011c3000.h"
#include "layout_support.h"
#include "BaseFormComponent.h"
#include "TESForm.h"
#include "TESTexture.h"

class NiMemObject
{
  public:
};
struct NiObject : public NiMemObject
{
  public:
    virtual ~NiObject();
    virtual void DeleteThis();
    unsigned int refs;
};

class BGSTextureSet;
class BSFileEntry;
class BSTextureSet;
class DecalData;
class ShortPoint3;
class TESBoundObject__BOUND_DATA;
class TESFormList;
class QueuedFile;

class ShortPoint3
{
  public:
    short x;  // +0x0, 2 bytes
    short y;  // +0x2, 2 bytes
    short z;  // +0x4, 2 bytes
};

class TESBoundObject__BOUND_DATA
{
  public:
    ShortPoint3 m_kBoundMin;  // +0x0, 6 bytes
    ShortPoint3 m_kBoundMax;  // +0x6, 6 bytes
};

class TESObject : public TESForm
{
  public:
    // base TESForm at +0x0, size 24
    TESFormList* m_pOwningList;    // +0x18, 4 bytes
    TESObject* m_pPreviousObject;  // +0x1C, 4 bytes
    TESObject* m_pNextObject;      // +0x20, 4 bytes
};

class TESBoundObject : public TESObject
{
  public:
    // base TESObject at +0x0, size 36
    TESBoundObject__BOUND_DATA TESBoundObjectBounds;  // +0x24, 12 bytes

    TESBoundObject();
};

class BSTextureSet : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    BSTextureSet();
    virtual const char* GetTextureFilePath(int aeTextureType);
};

// TESTexture has a non-trivial constructor/destructor (0x0048e270/0x0048e2e0)
// and a texture-name getter (0x00408da0) not declared in the bundled
// TESTexture.h; declared here on a shim following the accepted
// TESTextureLoader precedent in tescasinochips.h. The texture slots use this
// shim so the constructor emits the array construction iterator.
struct BGSTESTexture : public TESTexture
{
    BGSTESTexture();
    ~BGSTESTexture();
};

// Texture slots on PC (see note above).
class BGSTextureSet : public TESBoundObject, public BSTextureSet
{
  public:
    // base TESBoundObject at +0x0, size 48
    // base BSTextureSet at +0x30, size 8
    BGSTESTexture pTextures[6];  // +0x38, 72 bytes
    DecalData* m_pDecalData;     // +0x80, 4 bytes
    unsigned short iFlags;       // +0x84, 2 bytes
    unsigned char layoutPadding86[2];
    BSFileEntry* m_ppTextureFileEntries[6];  // +0x88, 24 bytes

    BGSTextureSet();
    virtual bool Load(TESFile*);
    void ResetFormData();
    virtual void ClearData();
    virtual const char* GetTextureFilePath(int aeTextureType);
    void LoadTextures(int aePriority, QueuedFile* apQueuedFile, bool abLoad);
    static void InitializeNullTextureSet();

    static BGSTextureSet* s_pNullTextureSet;
};

// DecalData::`scalar deleting destructor' (0x007b3fa0); layout copied
class ImpactDecalData
{
  public:
    float m_fDecalMinWidth;            // +0x0, 4 bytes
    float m_fDecalMaxWidth;            // +0x4, 4 bytes
    float m_fDecalMinHeight;           // +0x8, 4 bytes
    float m_fDecalMaxHeight;           // +0xC, 4 bytes
    float m_fProjectionDepth;          // +0x10, 4 bytes
    float m_fShininess;                // +0x14, 4 bytes
    float m_fParallaxScale;            // +0x18, 4 bytes
    unsigned char m_ucParallaxPasses;  // +0x1C, 1 bytes
    unsigned char cFlags;              // +0x1D, 1 bytes
    unsigned char layoutPadding1E[2];
    unsigned int iColor;  // +0x20, 4 bytes
};
class DecalData
{
  public:
    DecalData();
    bool Load(TESFile*);
    ImpactDecalData Data;  // +0x0, 36 bytes
public:
    void Copy(::DecalData *);
};
struct DecalDataDeleter : public DecalData
{
    void* DeleteThis(int aiFlag);
};

// ModelLoader queue call (0x00443af0) on the global at 0x011c3b3c.
struct ModelLoader
{
};

// Bethesda memset (0x00403d30).

struct TESDataHandlerForms
{
};
class TESDataHandler;

struct TESFileChunkData16
{
};
struct TESTextureLoader
{
};
struct TaskQueueInterface
{
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
#include <string.h>
struct FileNameHash;
struct NiPoint2
{
  public:
    unsigned char last, last2, length, first;
    unsigned int crc;
    NiPoint2();
};
struct FileNameHash
{
  public:
};
enum ArchiveType
{
    ARCHIVE_TEXTURES = 1
};
struct ArchiveManager
{
};
#endif
