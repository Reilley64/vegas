// fallout_shared/region system/tesregiondatalandscape_decls.h: declares TESFile, TESTexture, TESRegionData, TESRegionDataLandscape

#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/TESFullName.h"
void* __cdecl operator new(unsigned int) throw();
void __cdecl operator delete(void*);
class TESFile
{
  public:
};
class TESTexture
{
  public:
    virtual ~TESTexture();
    TESTexture();
    static void ReadTextureData(TESTexture*, TESFile*);
    char data[8];
};
class TESRegionData
{
  public:
    TESRegionData();
    virtual ~TESRegionData();
    char data[4];
};
class TESRegionDataLandscape : public TESRegionData
{
  public:
    TESRegionDataLandscape();
    virtual ~TESRegionDataLandscape();
    bool ReadLandscapeData(TESFile*);
    TESTexture* m_pLandscapeTexture;
};
