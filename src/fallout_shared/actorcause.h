// Authored header for fallout_shared/actorcause.cpp.
#ifndef FNV_ACTORCAUSE_H
#define FNV_ACTORCAUSE_H


#include "fnv/symbols_011d6000.h"
#include "layout_support.h"


class BGSLoadGameBuffer;

class ActorCause
{
  public:
    // Reverts the cause list built since the last completed load-game snapshot.
    static void ClearActorCauseList(BGSLoadGameBuffer* buffer);

  protected:
};


#endif
