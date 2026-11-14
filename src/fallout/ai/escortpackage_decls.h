// fallout/ai/escortpackage_decls.h: declares EscortActorPackageData
#ifndef ESCORTPACKAGE_DECLS_H
#define ESCORTPACKAGE_DECLS_H

#include "fnv/decl/ActorPackageData.h"
#include "fnv/symbols_01068000.h"
class Actor;
class EscortActorPackageData
{
  public:
    EscortActorPackageData();
    void** m_ppVirtualMethodTable;
    Actor* pActor;
};
#endif
