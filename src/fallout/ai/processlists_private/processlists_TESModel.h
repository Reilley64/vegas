// fallout/ai/processlists_private/processlists_TESModel.h: declares FileEntryList, TESModel
#ifndef PROCESSLISTS_PRIVATE_TESMODEL_H
#define PROCESSLISTS_PRIVATE_TESMODEL_H

#include "processlists_BaseFormComponent.h"
class BSFileEntry;
class TESModelTextureSwap;
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;
    BSFileEntry** m_ppFileEntries;
};
class TESModel : public BaseFormComponent
{
  public:
    TESModel();
    virtual ~TESModel();
    virtual const char* GetModelFilePath() const;
    virtual void SetModelFilePath(const char* path);
    virtual TESModelTextureSwap* GetAsModelMaterialSwap() const;
    BSStringT<char> m_kModelFilePath;
    FileEntryList m_pTextureSwapData;
    unsigned char cFlags;
};
#endif
