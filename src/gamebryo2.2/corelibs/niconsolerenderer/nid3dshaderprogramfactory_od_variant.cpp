
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_00e93e00_Obj.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00e92000.h"
#include "fnv/symbols_00e93000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_0126f000.h"
#include "nid3dshaderprogramfactory_packet.h"
struct Program;
struct Program
{
    virtual void Destroy(int);
};
void DestroyProgram();
struct Nd
{
    Nd* next;
    int b;
    int data;
};
struct Lst
{
    int a;
    int b;
    Nd* head;
};
struct FUN_00e93f30_shell
{
    void* DestroyShaderProgramFactory(unsigned int flags);
};
struct ShaderBufferRecord;
struct NiTStringPointerMap_00e93060
{
};
struct NiD3DShaderProgramFactory_00e93060
{
    int m_auiShapeKeys[6];
    NiTStringPointerMap_00e93060* m_pShaderBufferMap;
    ShaderBufferRecord* FUN_00e93060(const char* pcShaderName);
};
struct P03MM
{
};
extern "C" void* __cdecl _fnv_zlib_memset(void* dst, int value, unsigned int size);
extern int DAT_010f0eb0;
extern int DAT_010f0f50;

struct RecursiveSpinLock
{
public:
    void FUN_0040fba0();
};
template <class T> struct PoolAllocatorBase
{
    struct LinkedListEntry
    {
        LinkedListEntry* m_pkNext;
        int m_iData;
    };
    static LinkedListEntry* ms_pFreeList;
};
struct FUN_0045cee0_shell
{
    void FUN_0045cee0(void*);
};
// @fnv 0x0045cee0
void FUN_0045cee0_shell::FUN_0045cee0(void* pkItem)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::RecursiveSpinLock *>(&::g_011c5f80))))->FUN_0040fbf0((char *)(0));
    PoolAllocatorBase<unsigned int>::LinkedListEntry* pkNode =
        (PoolAllocatorBase<unsigned int>::LinkedListEntry*)pkItem;
    pkNode->m_iData = 0;
    pkNode->m_pkNext = (*reinterpret_cast<::PoolAllocatorBase<unsigned int>::LinkedListEntry * *>(&::DAT_011c5f58));
    (*reinterpret_cast<::PoolAllocatorBase<unsigned int>::LinkedListEntry * *>(&::DAT_011c5f58)) = pkNode;
    reinterpret_cast<::RecursiveSpinLock *>(&((*reinterpret_cast<::RecursiveSpinLock *>(&::g_011c5f80))))->FUN_0040fba0();
}
