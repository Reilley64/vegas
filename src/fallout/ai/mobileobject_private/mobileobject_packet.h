// fallout/ai/mobileobject_private/mobileobject_packet.h: declares ExtraDismemberedLimbs, bhkCharacterController, MobileObjectRemovalState

#include "fnv/decl/C70CharacterController.h"
#include "fnv/decl/FUN_004303e0_Class.h"
#include "fnv/decl/FUN_00c6ffc0_Class.h"
#include "fnv/symbols_00553000.h"
#include "../../../../include/ExtraDataList.h"
class ExtraDismemberedLimbs
{
  public:
};
class bhkCharacterController
{
  public:
    float& GetVectorElement(int);
};
bhkCharacterController* CopyCharacterControllerVector(bhkCharacterController*, const NiPoint3&);

#pragma pack(push, 1)
struct MobileObjectRemovalState
{
    unsigned char padding0, padding1, padding2;
    bool removed;
    bhkCharacterController* controller;
};
#pragma pack(pop)
