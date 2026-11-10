#pragma once

class FGRoot;
class NiAVObject;
class NiExtraData;
struct NiObject;
namespace fnv_00653120 { class NiNode; }
namespace fnv_00653340 { class NiAVObject; }
namespace fnv_00653340 { struct NiPoint3; }
namespace fnv_00653470 { class NiGeometry; }
namespace fnv_00653520 { struct StrMem; }
namespace fnv_00653620 { template <class> struct BSStringT; }
namespace fnv_006536d0 { struct StrMem; }
namespace fnv_00653880 { template <class> struct BSStringT; }
namespace fnv_00653c40 { template <class> struct BSStringT; }
struct BSStr;
struct Calendar;
struct NiRTTI;

// 0x00653000
void FUN_00653000(float, ::Calendar *, bool);
// 0x00653120
namespace fnv_00653120 { ::fnv_00653120::NiNode *GetNodeFromGeometry(void *); }
// 0x00653230
void *FUN_00653230(void *);
// 0x00653270
::NiObject *FUN_00653270(const ::NiRTTI *, ::NiObject *);
// 0x00653300
void *FUN_00653300(void *);
// 0x00653340
namespace fnv_00653340 { void FUN_00653340(::fnv_00653340::NiAVObject *, ::fnv_00653340::NiPoint3 *); }
// 0x00653430
::NiExtraData *GetExtraDataIfPresent(::NiAVObject *);
// 0x00653460
namespace fnv_00653460 { void *FUN_00653460(); }
// 0x00653470
namespace fnv_00653470 { void FUN_00653470(::fnv_00653470::NiGeometry *, float); }
// 0x00653520
namespace fnv_00653520 { const char *BuildEgmFilename(::fnv_00653520::StrMem *, const char *, int); }
// 0x00653620
namespace fnv_00653620 { const char *GetModelNifFilename(::fnv_00653620::BSStringT<char> &, const char *); }
// 0x006536d0
namespace fnv_006536d0 { const char *BuildTriPathAndSet(::fnv_006536d0::StrMem *, const char *, int); }
// 0x006537d0
const char *GetModelEgtFilename(::BSStr *, const char *);
// 0x00653880
namespace fnv_00653880 { const char *FUN_00653880(::fnv_00653880::BSStringT<char> &, int, unsigned char, const char *); }
// 0x00653a10
const char *FUN_00653a10(::BSStr *, const char *);
// 0x00653c40
namespace fnv_00653c40 { const char *BuildModelFilename(::fnv_00653c40::BSStringT<char> &, const char *); }
// 0x00653cf0
int FUN_00653cf0(int);
// 0x00653e50
void FUN_00653e50(::FGRoot *, int);
