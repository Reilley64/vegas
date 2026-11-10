// bsshader/imagespaceeffectvatsscan_decls.h: declares NonActorMagicCaster
#ifndef FNV_IMAGESPACEEFFECTVATSSCAN_DECLS_H
#define FNV_IMAGESPACEEFFECTVATSSCAN_DECLS_H


#include "fnv/decl/BA3760Object.h"
#include "fnv/decl/FUN_00a41520_cls.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01201000.h"
#include "MemoryManager.h"
class ImageSpaceTexture;
struct ImageSpaceEffectParam;
template <> class NiTArray<ImageSpaceTexture*, NiTMallocInterface<ImageSpaceTexture*> >
{
  public:
    virtual ~NiTArray();
    ImageSpaceTexture** m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
};
template <> class NiTArray<ImageSpaceEffectParam*, NiTMallocInterface<ImageSpaceEffectParam*> >
{
  public:
    virtual ~NiTArray();
    ImageSpaceEffectParam** m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
};

#include "imagespaceeffectvatsscan_types_ImageSpaceTexture.h"
#include "imagespaceeffectvatsscan_types_BSShaderManager.h"
#include "imagespaceeffectvatsscan_types_ImageSpaceEffectVATSScan.h"
#include "imagespaceeffectvatsscan_types_ImageSpaceShaderParam.h"

extern float DAT_011ae614;
extern float DAT_011ae618;
extern float DAT_01201f2c;
extern void* DAT_010ba350;

class NonActorMagicCaster
{
  public:
};

#endif
