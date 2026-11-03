// gamebryo2.2/corelibs/nianimation/niactormanager_packet.h: declares ActorManagerPacket, NiGlobalStringTable, NiFixedString

#include <windows.h>
#include "fnv/symbols_0109b000.h"
class ActorManagerPacket
{
  public:
    static void InitializePoint3();
};
class NiGlobalStringTable
{
  public:
    static char* AddString(const char*);
};
class NiFixedString
{
  public:
    char* m_kHandle;
};
extern char* DAT_011f3ec0;
extern char* DAT_011f3ec4;
