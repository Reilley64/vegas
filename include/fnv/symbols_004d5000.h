#pragma once

class BGSTerrainManager;
class LipSyncAnimation;
class NiBinaryStream;
class NiNode;
class Stream;
struct BGSSaveGameBuffer;
template <class> class BSStringT;
template <class> class NiPointer;

// 0x004d52d0
::BGSTerrainManager *LoadBGSTerrainManager(const ::NiPointer< ::NiNode> &);
// 0x004d5350
::LipSyncAnimation *ReadAnimationFromStream(::Stream *);
// 0x004d5570
void *ReadBufFromMemory(char *, unsigned int);
// 0x004d5880
bool FUN_004d5880(::NiBinaryStream *, char *, unsigned int);
// 0x004d5ad0
bool BuildLipPath(::BSStringT<char> &);
// 0x004d5c80
namespace fnv_004d5c80 { void *InitNameTable(void *); }
// 0x004d5eb0
int FindMiscStatIndex(const char *);
// 0x004d5f20
void CopyIntArrayToObjects(int *);
// 0x004d5f60
void CopyEntrySecondFields(int *);
// 0x004d5fa0
void SaveMiscStats(::BGSSaveGameBuffer *);
