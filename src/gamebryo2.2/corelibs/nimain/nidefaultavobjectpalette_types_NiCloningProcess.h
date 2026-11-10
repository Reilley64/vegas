// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NICLONINGPROCESS_H
#define FNV_NICLONINGPROCESS_H

#include "layout_support.h"
#include "NiObject.h"
#include "layout_support.h"
struct ShaderBufferRecord;
template <class T> class NiTStringPointerMap;
struct CloningProcess;
enum NiObjectNET__CopyType
{
    NiObjectNET__CopyType_COPY_NONE = 0,
    NiObjectNET__CopyType_COPY_EXACT = 1,
    NiObjectNET__CopyType_COPY_UNIQUE = 2
};
struct CloningProcess
{
  public:
    NiTStringPointerMap<ShaderBufferRecord*>* m_pCloneMap;  // +0x0, 4 bytes
    NiTPointerMap<NiObject*, bool>* m_pProcessMap;          // +0x4, 4 bytes
    NiObjectNET__CopyType m_eCloneCopyMode;                 // +0x8, 4 bytes
    char m_bExactType;                                      // +0xC, 1 bytes
    unsigned char layoutPaddingD[3];
    // void __cdecl CloningProcess::*(unsigned int)
    // void __cdecl CloningProcess::*()
    // void __cdecl CloningProcess::*()
    // void* __cdecl CloningProcess::*(unsigned int)
};
#endif
