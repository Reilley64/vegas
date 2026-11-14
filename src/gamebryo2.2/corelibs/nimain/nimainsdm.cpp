
// src/gamebryo2.2/corelibs/nimain/nimainsdm.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nimainsdm.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdlib>
#include "fnv/decl/A5B660StringTable.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/list_node.h"
#include "fnv/decl/NiExtraDataMapA6F.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/NiShaderConstantMap.h"
#include "fnv/decl/NiTextureEffect.h"
#include "fnv/decl/NiTexturingProperty.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00a5c000.h"
#include "fnv/symbols_00a5f000.h"
#include "fnv/symbols_00a60000.h"
#include "fnv/symbols_00a63000.h"
#include "fnv/symbols_00a66000.h"
#include "fnv/symbols_00a6a000.h"
#include "fnv/symbols_00a6c000.h"
#include "fnv/symbols_00a6f000.h"
#include "fnv/symbols_00a71000.h"
#include "fnv/symbols_00a73000.h"
#include "fnv/symbols_00a74000.h"
#include "fnv/symbols_00a75000.h"
#include "fnv/symbols_00a76000.h"
#include "fnv/symbols_00a7b000.h"
#include "fnv/symbols_00a7c000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a7e000.h"
#include "fnv/symbols_00a7f000.h"
#include "fnv/symbols_00a81000.h"
#include "fnv/symbols_00a84000.h"
#include "fnv/symbols_00a86000.h"
#include "fnv/symbols_00a87000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00a8a000.h"
#include "fnv/symbols_00a8b000.h"
#include "fnv/symbols_00a8f000.h"
#include "fnv/symbols_00a90000.h"
#include "fnv/symbols_00a91000.h"
#include "fnv/symbols_00a92000.h"
#include "fnv/symbols_00a93000.h"
#include "fnv/symbols_00a94000.h"
#include "fnv/symbols_00a95000.h"
#include "fnv/symbols_00a96000.h"
#include "fnv/symbols_00a97000.h"
#include "fnv/symbols_00a98000.h"
#include "fnv/symbols_00a99000.h"
#include "fnv/symbols_00a9a000.h"
#include "fnv/symbols_00a9b000.h"
#include "fnv/symbols_00a9f000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_0109c000.h"
#include "fnv/symbols_0109d000.h"
#include "fnv/symbols_0109e000.h"
#include "fnv/symbols_0109f000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
// @fnv 0x00a8a200
void FUN_00a8a200()
{
    if (!fnv::list::ShutdownStorage())
        std::abort();
}

namespace fnv_00a8a240 {
struct MM
{
};
extern void* DAT_011f6034;
extern void* DAT_011f6038;
// Walks the linked list starting at DAT_011f6034, deallocating each node, then clears DAT_011f6038 and DAT_011f6034.
// @fnv 0x00a8a240
void FreeMemoryList()
{
    void* pCurrent = DAT_011f6034;
    if (pCurrent)
    {
        do
        {
            void* next = *(void**)pCurrent;
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00a8a240::MM *>(&::g_memoryManager))))->FUN_00aa4060(pCurrent);
            pCurrent = next;
        } while (pCurrent);
    }
    *(void* volatile*)&DAT_011f6038 = 0;
    *(void* volatile*)&DAT_011f6034 = 0;
}
}  // namespace fnv_00a8a240

struct NiObject;
struct NiStream
{
public:
    static int RegisterObjectLoader(const char *, NiObject *(*)());
};

struct FUN_00a8f730
{
    static void Release();
};

struct FUN_00a928b0_shell
{
    static void ClearFixedStrings();
};

void __cdecl FUN_00a5cf60();
void __cdecl ReleasePendingTable();
void __cdecl FUN_00a62ae0();
void __cdecl FUN_00a632b0();
void __cdecl ReleaseGlobalStrings();
void __cdecl FUN_00a6f4d0();
void __cdecl ReleaseGlobalHolder();
void __cdecl FreeGlobalAlias();
void __cdecl FUN_00a8f620();
void __cdecl FUN_00a8fcc0();
void __cdecl ResetStreamLinkIDSet();
void __cdecl DestroyGlobalPool();
void __cdecl FUN_00a9a120();
void __cdecl FUN_00a9bb60();

extern char DAT_011f5b80;



// @fnv 0x00a8a280
void __cdecl FUN_00a8a280()
{
    if (DAT_011f5b80)
    {
        DAT_011f5b80 = 0;

        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f4aac_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f4a30_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5f74_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f4408_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5f6c_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5d20_arg0);
        ::fnv_00a63520::FUN_00a63520("NiAutoNormalParticles");
        ::fnv_00a63520::FUN_00a63520("NiAutoNormalParticlesData");
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f4aa0_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f4ab8_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5f5c_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5f54_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f4a18_arg0);
        ::fnv_00a63520::FUN_00a63520("NiClusterAccumulator");
        ::fnv_00a63520::FUN_00a63520("NiCollisionSwitch");
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5b68_arg0);

        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f4a04_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f4a68_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5f48_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f4a80_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5f40_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5b60_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5f34_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5f2c_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5f24_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5f1c_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f4a48_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5b88_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f4a5c_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f4428_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5c08_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5f14_arg0);

        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5f0c_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5f64_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5ef0_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&DAT_0109f0a0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f4a90_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f4a98_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5ef8_arg0);
        ::fnv_00a63520::FUN_00a63520("NiRotatingParticles");
        ::fnv_00a63520::FUN_00a63520("NiRotatingParticlesData");
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5ee8_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5ee0_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5ae0_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5b24_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5b2c_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5b1c_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5ed8_arg0);

        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5b48_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5b50_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f444c_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5ecc_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5ec4_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f4a0c_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f4a38_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5ebc_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5eb4_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5eac_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5e94_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f49a4_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f4a40_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f4a88_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5af4_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f4a20_arg0);

        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f4a70_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5e8c_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5e84_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f4430_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5b78_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5e5c_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5e54_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5e64_arg0);
        ::fnv_00a63520::FUN_00a63520((char const*)&g_011f5e6c_arg0);

        ::fnv_00a9fda0::DestroyPairArrays();
        FUN_00a928b0_shell::ClearFixedStrings();
        FUN_00a5cf60();
        FUN_00a9a120();
        ReleaseGlobalHolder();
        FUN_00a9bb60();
        ::fnv_00a81590::FUN_00a81590();
        FUN_00a6f4d0();
        ReleaseGlobalStrings();
        FUN_00a8f620();
        ::fnv_00a76b30::FUN_00a76b30();
        FUN_00a632b0();
        FUN_00a62ae0();
        DestroyGlobalPool();
        ReleasePendingTable();
        FreeGlobalAlias();
        FUN_00a8f730::Release();
        FUN_00a8fcc0();
        ResetStreamLinkIDSet();
        FUN_00a8a200();
        ::fnv_00a8a240::FreeMemoryList();
        ::A5B660StringTable::FUN_00a5b660();
    }
}

struct Vector3
{
    float x;
    float y;
    float z;
};
extern char DAT_011f5b80;
extern float DAT_011f4294;
void __cdecl FUN_00a5b630();
void __cdecl FUN_00a5cef0();
void __cdecl FUN_00a9a090();
void __cdecl FUN_00a759e0();
void __cdecl FUN_00a81520();
void __cdecl FUN_00a9ba80();
void __cdecl FUN_00a6f450();
void __cdecl CreateCullingProperty();
void __cdecl CreateImageConverter();
void __cdecl FUN_00a91290();
void __cdecl FUN_00a62110();
void __cdecl FUN_00a7e930();
void __cdecl FUN_00a8fd80();
void __cdecl CreateSdmDerived();
void __cdecl FUN_00a74da0();
extern const char DAT_0109f1e4;
extern const char DAT_0109f1c8;
extern const char DAT_0109f190;
extern const char DAT_0109b0f8;
extern const char DAT_0109f07c;
extern const char DAT_0109f064;
// Runs one-time initialization guarded by DAT_011f5b80: calls setup routines, resets DAT_011f4294/DAT_011f4288, and registers many handlers via FUN_00a64900.
// @fnv 0x00a89cc0
void __cdecl InitializeGameSystems()
{
    if (DAT_011f5b80 == 0)
    {
        DAT_011f5b80 = 1;
        FUN_00a5b630();
        ::fnv_00a813c0::InitTrigTables();
        ::NiShaderConstantMap::InitializePoint3();
        ::NiTextureEffect::InitializePoint3();
        FUN_00a5cef0();
        FUN_00a9a090();
        FUN_00a759e0();
        FUN_00a29680();
        FUN_00a81520();
        FUN_00a9ba80();
        FUN_00a6f450();
        ::NiTexturingProperty::InitializePoint3();
        CreateCullingProperty();
        DAT_011f4294 = 0.0f;
        (*reinterpret_cast<::Vector3 *>(&::g_defaultBound)) = (*reinterpret_cast<::Vector3 *>((void *)&::NiPoint3::ZERO));
        CreateImageConverter();
        ::fnv_00a660a0::FUN_00a660a0();
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f4aac_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a7f740)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f4a30_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a73e20)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5f74_arg0))), (NiObject *(*)())(((void (&)())::CreateNiAlphaAccumulator)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f4408_arg0))), (NiObject *(*)())(((void (&)())::CreateNiAlphaProperty)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5f6c_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a9b330)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5d20_arg0))), (NiObject *(*)())(((void (&)())::CreateProperty)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&DAT_0109f1e4), (NiObject *(*)())(((void (&)())::FUN_00a9b150)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&DAT_0109f1c8), (NiObject *(*)())(((void (&)())::FUN_00a96600)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f4aa0_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a7e770)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f4ab8_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a7f8e0)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5f5c_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a9af90)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5f54_arg0))), (NiObject *(*)())(((void (&)())::CreateNiParticleObject)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f4a18_arg0))), (NiObject *(*)())(((void (&)())::fnv_00a71430::FUN_00a71430)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&DAT_0109f190), (NiObject *(*)())(((void (&)())::CreateNiAlphaAccumulator)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&DAT_0109b0f8), (NiObject *(*)())(((void (&)())::FUN_00a5f030)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5b68_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a89490)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f4a04_arg0))), (NiObject *(*)())(((void (&)())::NiExtraDataMapA6F::FUN_00a6f000)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f4a68_arg0))), (NiObject *(*)())(((void (&)())::CreateNiDirectionalLight)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5f48_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a9a640)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f4a80_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a7b380)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5f40_arg0))), (NiObject *(*)())(((void (&)())::fnv_00a9a480::FUN_00a9a480)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5b60_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a89190)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5f34_arg0))), (NiObject *(*)())(((void (&)())::CreateNiFogProperty)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5f2c_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a99cd0)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5f24_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a99a10)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5f1c_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a99710)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f4a48_arg0))), (NiObject *(*)())(((void (&)())::CreateSceneFactoryObject)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5b88_arg0))), (NiObject *(*)())(((void (&)())::CreateNiPairHolder)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f4a5c_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a756d0)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f4428_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a5f030)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5c08_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a8b220)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5f14_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a98e70)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5f0c_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a98d30)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5f64_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a9b150)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5ef0_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a96600)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&DAT_0109f0a0), (NiObject *(*)())(((void (&)())::fnv_00a982d0::FUN_00a982d0)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f4a90_arg0))), (NiObject *(*)())(((void (&)())::CreateSpawnedPixelData)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f4a98_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a7d6e0)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5ef8_arg0))), (NiObject *(*)())(((void (&)())::CreateRangeLODData)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&DAT_0109f07c), (NiObject *(*)())(((void (&)())::FUN_00a9b150)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&DAT_0109f064), (NiObject *(*)())(((void (&)())::CreateObj_a96)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5ee8_arg0))), (NiObject *(*)())(((void (&)())::AllocateAndConstruct)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5b48_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a877a0)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5b50_arg0))), (NiObject *(*)())(((void (&)())::CreateBA87920Object)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5ee0_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a958b0)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5ae0_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a814e0)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5b24_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a84d30)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5b2c_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a866f0)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f49d8_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a6c8a0)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5b1c_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a81fb0)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5ed8_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a952a0)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f444c_arg0))), (NiObject *(*)())(((void (&)())::CreateA5FC10Stub)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f4454_arg0))), (NiObject *(*)())(((void (&)())::CreateNiSourceCubeMap)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5ecc_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a95160)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5ec4_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a94e20)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f4a0c_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a6f410)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f4a38_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a74230)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5ebc_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a94930)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5eb4_arg0))), (NiObject *(*)())(((void (&)())::CreateSwitchNode)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5eac_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a93870)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5e94_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a929b0)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f49a4_arg0))), (NiObject *(*)())(((void (&)())::CreateTexturingProperty)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f4a40_arg0))), (NiObject *(*)())(((void (&)())::fnv_00a744d0::CreateNiTriShapeX)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5b40_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a87140)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f4a88_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a7b790)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5af4_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a81760)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f4a20_arg0))), (NiObject *(*)())(((void (&)())::CreateNiTriStrips)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f4a70_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a75ec0)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5e8c_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a923f0)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5e84_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a91fe0)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f4430_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a5f280)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5b78_arg0))), (NiObject *(*)())(((void (&)())::CreateNiExtraData)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5e6c_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a91ee0)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5e5c_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a8ff80)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5e54_arg0))), (NiObject *(*)())(((void (&)())::FUN_00a90b20)));
        ::NiStream::RegisterObjectLoader((const char *)(const void *)(&(*reinterpret_cast<const char *>((void *)&::g_011f5e64_arg0))), (NiObject *(*)())(((void (&)())::fnv_00a8ffc0::FUN_00a8ffc0)));
        FUN_00a91290();
        FUN_00a62110();
        FUN_00a7e930();
        FUN_00a29680();
        FUN_00a8fd80();
        CreateSdmDerived();
        FUN_00a74da0();
    }
}

#include "generated/data/gamebryo2.2/corelibs/nimain/nimainsdm.inc"
