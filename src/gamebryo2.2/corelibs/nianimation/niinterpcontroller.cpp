// gamebryo2.2/corelibs/nianimation/niinterpcontroller.cpp: NiInterpController, NiInterpControllerTriple, NiInterpControllerFlagCheck, BaseWrap (5 functions)

#include "fnv/decl/NiTimeController_Luna.h"
#include "fnv/decl/TCController.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_011f3000.h"
#include "niinterpcontroller_decls.h"
// @fnv 0x00a2f910
void NiInterpController::LoadBinary(NiStream& stream)
{
    reinterpret_cast<::NiTimeController_Luna *>(this)->FUN_00a6d5e0(stream);
    if (stream.version >= 0x0a010068 && stream.version < 0x0a01006d)
    {
        bool value;
        stream.input->Read(&value, 1);
        if (value)
            flags |= 0x20;
        else
            flags &= ~0x20;
    }
}
// @fnv 0x00c9a6b0
void NiInterpController::LinkObject(NiStream& stream)
{
    NiTimeController::LinkObject(stream);
}
// @fnv 0x00c9a6c0
void NiInterpControllerTriple::ResetTriple()
{
    f0 = -1.0f;
    float v = 0.0f / g_d100;
    f1 = v;
    f2 = v;
}

class NiInterpControllerFlagCheck : public NiInterpController
{
  public:
    void ResetIfFlagClear();
};

// @fnv 0x00a2f8f0
void NiInterpControllerFlagCheck::ResetIfFlagClear()
{
    unsigned char value = *(unsigned char*)&this->flags;
    for (int i = 0; i < 5; ++i)
        value = (unsigned char)(value >> 1);
    if (!(value & 1))
    {
        *(float*)((char*)this + 0x14) = 0.0f;
        *(float*)((char*)this + 0x18) = 0.0f;
    }
}

struct StrArr
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short unk08;
    unsigned short unk0a;
    unsigned short unk0c;
    unsigned short unk0e;
};
struct BaseCall
{
    unsigned int unk00;
    unsigned int unk04;
};
struct BaseWrap : BaseCall
{
    unsigned char flags;
    void WriteManagerControlledFlag(StrArr*);
};
// Calls the base writer, then appends a string and an "IsManagerControlled" entry derived from bit 5 of flags to the stream.
// @fnv 0x00a2f980
void BaseWrap::WriteManagerControlledFlag(StrArr* stream)
{
    reinterpret_cast<::TCController *>(this)->FUN_00a6d830((::NiViewerStringsArray *)(stream));
    char* value = FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_011f36b4)));
    unsigned int index = stream->unk0a;
    if (index >= stream->unk08)
    {
        reinterpret_cast<::ViewerStrings *>((stream))->SetSize(stream->unk0e + index);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((stream))->SetAt(index, (*(char * *)(&value)));
    *(unsigned char*)&value = (flags >> 5) & 1;
    value = ::FUN_00a7d370("IsManagerControlled", *(int*)&value);
    index = stream->unk0a;
    if (index >= stream->unk08)
    {
        reinterpret_cast<::ViewerStrings *>((stream))->SetSize(stream->unk0e + index);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((stream))->SetAt(index, (*(char * *)(&value)));
}
