#pragma once

class ActiveEffect;
template <class> class BSSimpleList;

class NonActorMagicTarget {
public:
    // 0x007d6bb0
    ::BSSimpleList< ::ActiveEffect *> *GetActiveEffectList();
};
