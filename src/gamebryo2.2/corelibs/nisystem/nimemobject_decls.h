// gamebryo2.2/corelibs/nisystem/nimemobject_decls.h: declares NiPoint2, SNAEntry, NiObject, NiFixedString, NiProperty
#include "fnv/decl/FUN_00633ba0_Class.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
class Flag512Receiver
{
  public:
    void SetFlag512(bool enabled);
};
class NiPoint2
{
  public:
    float x, y;
    NiPoint2(float a, float b);
};
class SNAEntry
{
  public:
    static void* operator new[](size_t size);
};

// Declarations for the constructor/getter span.
class NiObject
{
  public:
    unsigned int words[2];
    NiObject();
};
class NiFixedString
{
  public:
    const char* value;
};
extern unsigned char DAT_0109b244[];
class NiProperty : public NiObject
{
  public:
    NiFixedString name;
    void* controller;
    void* extraData;
    unsigned short extraDataSize, extraDataCapacity;
    NiProperty();
};
