// fallout_shared/magic/spellitem_decls.h: declares SpellItem
#ifndef SPELLITEM_DECLS_H
#define SPELLITEM_DECLS_H

#include "fnv/magic/flag_byte.h"

class SpellItem
{
  public:
    void ResetFormData();

  private:
    unsigned char formData[0x34];
    unsigned int spellType;
    int cost;
    unsigned int level;
    fnv::magic::FlagByte flags;
public:
    void ClearData();
};
#endif
