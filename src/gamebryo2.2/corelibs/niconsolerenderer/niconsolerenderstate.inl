#include <windows.h>
#include "fnv/decl/FUN_00a62660_cls.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011f4000.h"
#include "niconsolerenderstate_decls.h"
class NiFixedString { public: int value; };
class NiTexture { public:  };
class NiExtraData : public NiTexture {};
class NiAVObject {
public:
 char pad[16];
 NiExtraData** data;
 unsigned short count;
 NiExtraData* GetExtraData(const NiFixedString& key);
};
// @fnv 0x00a5bdd0
NiExtraData* NiAVObject::GetExtraData(const NiFixedString& key) {
 if (key.value == (*reinterpret_cast<::NiFixedString *>(&::DAT_0109b220)).value) return 0;
 EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&(*reinterpret_cast<char *>(&::DAT_011f4380))));
 short low = 0;
 short high = count - 1;
 short mid;
 while (low <= high) {
  mid = (high + low) >> 1;
  int diff = key.value;
  diff -= (*(const ::NiFixedString *)&(reinterpret_cast<::FUN_00a62660_cls *>((data[mid]))->FUN_00a62660())).value;
  if (diff == 0) {
   LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&(*reinterpret_cast<char *>(&::DAT_011f4380))));
   return data[mid];
  }
  if (diff > 0) low = mid + 1;
  else high = mid - 1;
 }
 LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&(*reinterpret_cast<char *>(&::DAT_011f4380))));
 return 0;
}
