// fallout_shared/facegen/bsfacegenmanager_decls.h: declares FaceGenCoordinates, BSFaceGenManager, BGSTextureModel, TESRace, TESForm and more

#include <cstring>
#include "fnv/decl/FR2MatrixVTCData.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0119b000.h"
struct FaceGenCoordinates
{
    char data[0x60];
};
class BSFaceGenModelMap;
template <class T> class BSStringT;
class BSFaceGenManager
{
  public:
    char pad[8];
    FaceGenCoordinates coords;
    char rest[0x1194 - 8 - 0x60];
    BSFaceGenModelMap* cache;
    static BSFaceGenManager* GetFaceGenManager();
    static FaceGenCoordinates* GetFaceGenCoordinates();
    static BSFaceGenModelMap* GetModelMap();
    static void NormalizeFaceGenValues(float*, unsigned int);
    static void InitializeFaceGenCoordinates(FaceGenCoordinates*);
    static char* BuildFaceGenPartPath(char*, int);
    static void ApplyFaceGenValues(float*, unsigned int, bool);
    static const char* BuildFaceGenModelPath(BSStringT<char>&, const char*);
};
extern BSFaceGenManager* DAT_011d59e8;
void FUN_006519f0();
struct BGSTextureModel
{
    char data[24];
};
class TESRace
{
  public:
    char pad[0x3c8];
    BGSTextureModel models[2];
    BGSTextureModel* GetBodyTextureModel(int);
};
enum ENUM_FORM_ID
{
    NPC_FORM = 42
};
enum SEX
{
    SEX_NONE = -1,
    SEX_MALE = 0,
    SEX_FEMALE = 1
};
class TESForm
{
  public:
    ENUM_FORM_ID GetFormType() const;
};
class TESActorBaseData
{
  public:
    char data[0x20];
    bool GetFlag(unsigned int) const;
};
class TESActorBase : public TESForm
{
  public:
    char pad[0x30];
    TESActorBaseData base;
    SEX GetSex() const;
};
class FaceGenCoordArray
{
  public:
    char data[0x20];
    void resize(unsigned int, bool);
};
template <class T> class NiPointer
{
  public:
    T* p;
    ~NiPointer();
};
class NiTexture;
class FaceGenPaletteBase
{
  public:
    char pad[0x2c];
    ~FaceGenPaletteBase();
};
class FaceGenPaletteEntry : public FaceGenPaletteBase
{
  public:
    NiPointer<NiTexture> first, second;
    ~FaceGenPaletteEntry();
};

extern const char DAT_0104aad0[];
