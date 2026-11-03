// gamebryo2.2/corelibs/nimain/nifixedstring_facegen.h: declares NiMemObject, TESRecipe, NiAVObject, FaceGenImageView, FaceGenColor and more
#ifndef FNV_NIFIXEDSTRING_FACEGEN_H
#define FNV_NIFIXEDSTRING_FACEGEN_H

#include <cstring>
#include "fnv/decl/FGOwner.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_0061cc40_shell.h"
#include "fnv/decl/FUN_00629ab0_shell.h"
#include "fnv/decl/FUN_0064db50_class.h"
#include "fnv/decl/FUN_0065cc70_Holder.h"
#include "fnv/decl/FUN_0065cea0_class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/_Dummy_0044a170.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00604000.h"
#include "fnv/symbols_00652000.h"
#include "fnv/symbols_00aaf000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_011aa000.h"
class NiTexture;
template <class T> class NiPointer
{
  public:
    T* pointer;
    NiPointer(T*);
    ~NiPointer();
    operator T*() const;
    NiPointer& operator=(T*);
};
template <class T> class BSStringT
{
  public:
    T* text;
    unsigned short length, capacity;
    const T* String();
};
class NiMemObject
{
  public:
    static void* operator new(size_t);
    static void operator delete(void*, size_t);
};
namespace ActorValue { enum Index; }
class TESRecipe
{
  public:
public:
    void SetRequiredSkill(::ActorValue::Index);
};
class NiNode;
class NiAVObject
{
  public:
};
class FaceGenImage;
struct FaceGenImageView
{
    float* pixels;
    unsigned int stride;
    FaceGenImageView();
    float* FUN_0064dbd0();
};
struct FaceGenColor
{
    float r, g, b, a;
};
struct FaceGenModeParameters
{
    int weight;
    unsigned int stride;
};
struct FaceGenChannelData
{
    int scale;
    const signed char* row;
};
struct FaceGenOutputData
{
    float multiplier;
    float* output;
};
class FaceGenImage : public NiMemObject
{
  public:
    unsigned char data[44];
    FaceGenImage(unsigned int);
};
class NiTexture
{
  public:
    NiTexture* FUN_0064ceb0(float, float, float, void*);
};
struct TextureChannel
{
    unsigned char data[24];
};
struct TextureRow
{
    float scale;
    unsigned int width, height, rowPadding;
    TextureChannel rows[3];
};
struct TextureBasis
{
    unsigned char data[24];
};
struct FaceGenTextureFile
{
    ~FaceGenTextureFile();
    static void operator delete(void*);
    unsigned int flags;
    TextureBasis basis[2];
};
struct FaceGenCoordinateValue
{
    const float* values;
    unsigned int stride;
};
struct FaceGenCoordinateBasis
{
    unsigned char data[32];
    FaceGenCoordinateValue FUN_0060b370(unsigned int, unsigned int);
};
struct FaceGenCoordinates
{
    unsigned char data[64];
    FaceGenCoordinateBasis basis[2];
};
struct BSFaceGenTexture
{
    BSStringT<char> m_kEGTFileName;
    FaceGenTextureFile* m_pTextureData;
};
class BSFaceGenModel
{
  public:
    void* vtable;
    unsigned int refCount;
    void* m_pGeometryModel;
    BSFaceGenTexture* m_kTextureSlots;
    bool ApplyTextureCoordinate(FaceGenCoordinates*, NiPointer<NiTexture>&, unsigned int);
    void ClearTextureData();
};
struct BSFaceGenManager
{
    static FaceGenCoordinates* GetFaceGenCoordinates();
};
FaceGenTextureFile* FUN_00659780(const char*);
extern float DAT_01065b9c;
extern float DAT_01065b98;
struct NiPoint3StartupTable;
void* __cdecl operator new[](size_t);
void __cdecl operator delete[](void*);
#endif
