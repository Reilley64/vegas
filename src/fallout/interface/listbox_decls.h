// fallout/interface/listbox_decls.h: declares ListBox_int_
#ifndef FNV_LISTBOX_DECLS_H
#define FNV_LISTBOX_DECLS_H

#include "fnv/decl/ListOwner.h"
class Tile;
class ListBox_int_
{
  public:
};
struct SoundPlaybackHandle
{
  public:
    unsigned int soundID;
    unsigned char success;
    unsigned int state;
    SoundPlaybackHandle& operator=(const SoundPlaybackHandle& other);
};
#endif
