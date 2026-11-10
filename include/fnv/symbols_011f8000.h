#pragma once

class ArchivePtr;
class FileFinder;
struct GlobalObject_00b3f100;
struct Vector3D;
namespace fnv_00af6540 { struct Archive; }
namespace fnv_00af6540 { template <class> class NiPointer; }
namespace fnv_00b07db0 { class WindMatricesB07; }
namespace leafwind { struct Matrix4f; }
struct ArchiveArray;
struct BranchConfigList;
struct BranchLeaves;
struct BranchManager;
struct BranchTransform;
struct S00b37660_Cache;
struct State;

// 0x011f804c
extern unsigned int g_uiMatchFlags;
// 0x011f8050
extern char DAT_011f8050[];
// 0x011f8154
extern bool DAT_011f8154;
// 0x011f8158
extern char *DAT_011f8158;
// 0x011f815c
extern char *DAT_011f815c;
// 0x011f8160
namespace fnv_00af56d0 { extern "C" extern int DAT_011f8160; }
// 0x011f8164
extern unsigned int DAT_011f8164;
// 0x011f8168
extern ::ArchiveArray *DAT_011f8168;
// 0x011f816c
extern ::ArchiveArray *DAT_011f816c;
// 0x011f8170
namespace fnv_00af5480 { extern char g_kCS_11f8170[]; }
// 0x011f8190
extern ArchivePtr DAT_011f8190[2][9];
// 0x011f81b4
namespace archive_master_lookup { extern fnv_00af6540::NiPointer<fnv_00af6540::Archive> DAT_011f81b4[9]; }
// 0x011f81dc
extern "C" extern ::FileFinder *g_fileFinder;
// 0x011f8b79
extern unsigned char DAT_011f8b79;
// 0x011f8bf4
extern ::State *DAT_011f8bf4;
// 0x011f8bfc
namespace fnv_00b2af80 { extern int DAT_011f8bfc; }
// 0x011f8c00
extern ::BranchManager *DAT_011f8c00;
// 0x011f8c04
extern bool DAT_011f8c04;
// 0x011f8c05
extern ::GlobalObject_00b3f100 g_011f8c05;
// 0x011f8c14
extern float runtimeInitializationFloat4160;
// 0x011f8c30
extern float runtimeInitializationFloat4161;
// 0x011f8c40
extern ::BranchTransform DAT_011f8c40;
// 0x011f8c50
extern ::BranchConfigList DAT_011f8c50;
// 0x011f8c80
extern ::BranchLeaves DAT_011f8c80;
// 0x011f8c9c
extern float runtimeInitializationFloat4164;
// 0x011f8d08
extern ::Vector3D DAT_011f8d08;
// 0x011f8d80
extern float DAT_011f8d80;
// 0x011f8d84
namespace fnv_00b07db0 { extern ::fnv_00b07db0::WindMatricesB07 g_kWindMatricesB07; }
// 0x011f8d88
namespace leafwind { extern ::leafwind::Matrix4f *DAT_011f8d88; }
// 0x011f8e2c
extern ::S00b37660_Cache DAT_011f8e2c;
// 0x011f8e9c
extern int DAT_011f8e9c;
