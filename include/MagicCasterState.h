#ifndef FNV_MAGICCASTERSTATE_H
#define FNV_MAGICCASTERSTATE_H

enum MagicCaster__State
{
    MagicCaster__State_NO_SPELL = 0,
    MagicCaster__State_AIM = 1,
    MagicCaster__State_CAST = 2,
    MagicCaster__State_RELEASE = 3,
    MagicCaster__State_FIND_TARGETS = 4,
    MagicCaster__State_ERR_SPELL_DISABLED = 5,
    MagicCaster__State_ERR_ALREADY_CASTING = 6,
    MagicCaster__State_ERR_CANNOT_CAST = 7,
};

#endif
