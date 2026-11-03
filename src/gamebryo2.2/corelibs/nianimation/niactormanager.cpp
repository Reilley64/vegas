// gamebryo2.2/corelibs/nianimation/niactormanager.cpp: ActorManagerPacket (2 functions)

#include "fnv/decl/Dtor00a2dd70.h"
#include "fnv/symbols_0109b000.h"
#include "niactormanager_packet.h"
// Assigns the interned strings "end" and "start" to DAT_011f3ec0 and DAT_011f3ec4, releasing the previous references when they differ.
// @fnv 0x00a421c0
void ActorManagerPacket::InitializePoint3()
{
    char* old = DAT_011f3ec0;
    if (old != "end")
    {
        DAT_011f3ec0 = NiGlobalStringTable::AddString("end");
        if (old != (*reinterpret_cast<::NiFixedString *>(&::DAT_0109b220)).m_kHandle)
            InterlockedDecrement((long*)(old - 8));
    }
    old = DAT_011f3ec4;
    if (old != "start")
    {
        DAT_011f3ec4 = NiGlobalStringTable::AddString("start");
        if (old != (*reinterpret_cast<::NiFixedString *>(&::DAT_0109b220)).m_kHandle)
            InterlockedDecrement((long*)(old - 8));
    }
}

struct NodeA2
{
    NodeA2* m_next;
};
extern int DAT_011f3e7c;
extern int DAT_011f3e80;
// Walks the list at DAT_011f3e7c, calls FUN_00a2dd70(3) on each node, then zeroes DAT_011f3e80 and DAT_011f3e7c.
// @fnv 0x00a2de40
void ClearNodeList()
{
    NodeA2* pNode = *(NodeA2**)&DAT_011f3e7c;
    while (pNode)
    {
        NodeA2* next = pNode->m_next;
        reinterpret_cast<::Dtor00a2dd70 *>((pNode))->FUN_00a2dd70(3);
        pNode = next;
    }
    *(volatile int*)&DAT_011f3e80 = 0;
    *(volatile int*)&DAT_011f3e7c = 0;
}
