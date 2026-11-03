// Own header for fallout/ai/actorvaluecache.cpp.
// ActorValueCacheEntry / ActorValueStore layouts copied verbatim from the task's
// canonical and must not be #included. Method declarations added; they do not
// affect layout. ActorValue::Index comes from layout_support.h.
#ifndef FNV_SRC_FALLOUT_AI_ACTORVALUECACHE_H
#define FNV_SRC_FALLOUT_AI_ACTORVALUECACHE_H

#include "layout_support.h"
class ActorValueStore;
class ActorValueCacheEntry;
class ActorValueCacheEntry
{
  public:
    bool m_bIsDirty;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    float fValue;  // +0x4, 4 bytes
};
class ActorValueStore
{
  public:
    ActorValueStore();
    void ResetCacheValues();
    void FUN_008c6f00(ActorValue::Index avIndex, float value);
    void InvalidateValue(ActorValue::Index avIndex);

  private:
    void InvalidateDependentValues(ActorValue::Index avIndex);

  public:
    ActorValueCacheEntry Cache[77];  // +0x0, 616 bytes
};
namespace ActorValue {
ActorValue::Index* GetDependentActorValueIndices(ActorValue::Index avIndex, int& count);
}
#endif
