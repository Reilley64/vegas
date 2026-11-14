// fallout_shared/tesimagespace.cpp: TESImageSpace, ImageSpaceCopyEntry (7 functions)

#include "fnv/decl/B8AD00Header.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "tesimagespace.h"
#include <malloc.h>
#include <string.h>

// Zeroes out the Data member of the TESImageSpace form using memset.
// @fnv 0x0052b410
void TESImageSpace::ResetFormData()
{
    memset(&Data, 0, sizeof(Data));
}

// Reads a TESImageSpace record from file, handling EDID, OBND and DNAM chunks, and returns false if the form type is not 0x53.
// @fnv 0x0052b440
bool TESImageSpace::Load(TESFile* file)
{
    unsigned char formType;
    int chunk;
    ImageSpaceModifierParameterData data;
    formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (formType != 0x53)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    while ((chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunk)
        {
        case 0x44494445:  // EDID
        {
            char* buffer = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(buffer), 0x200);
            SetEditorID_AtRuntime(buffer);
            break;
        }
        case 0x444E424F:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x4D414E44:  // DNAM
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&data), sizeof(data));
            if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() < sizeof(data))
            {
                memcpy_s(&Data, 0x3C, &data, 0x38);
                Data.m_afFirstParameterSet[14] = 1.0f;
                memcpy_s(&Data.m_afSecondParameterSet, 0x5C, &data.m_afFirstParameterSet[14], 0x5C);
            }
            else
            {
                memcpy_s(&Data, sizeof(data), &data, sizeof(data));
            }
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::B8AD00Header *>(&(Data))->SwapEndian();
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct Base5a
{
    virtual ~Base5a();
};
struct FUN_0052b3b0 : public Base5a
{
    virtual void ClearData();
    ~FUN_0052b3b0();
};
// @fnv 0x0052b3b0
FUN_0052b3b0::~FUN_0052b3b0()
{
    ClearData();
}

struct FUN_004855a0
{
};
struct FUN_00485680
{
};
struct FUN_0052b630_obj : ::TESImageSpace
{
    void FUN_004855a0();
    void FUN_00485680();
    void FUN_0052b630();
};
// @fnv 0x0052b630
void FUN_0052b630_obj::FUN_0052b630()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::B8AD00Header *>(((&this->Data)))->SwapEndian();
    ::AppendChunk(0x4d414e44, (char*)&this->Data, 0x98);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::B8AD00Header *>(((&this->Data)))->SwapEndian();
    reinterpret_cast<::Holder *>(this)->FUN_00485680();
}

struct FUN_0052b700_shell : public TESImageSpace
{
    bool FUN_0052b700(TESForm*);
};

// @fnv 0x0052b700
bool FUN_0052b700_shell::FUN_0052b700(TESForm* apCompare)
{
    TESImageSpace* pcomp = dynamic_cast<TESImageSpace*>(apCompare);
    if (!pcomp)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270((TESForm*)pcomp))
        return true;
    if (memcmp((char*)&this->Data, (char*)&pcomp->Data, 0x98))
        return true;
    return false;
}

struct FUN_0052b380_shell : public FUN_0052b3b0
{
    void* DestroyAndDeallocate(unsigned int flags);
};
// Runs the base destructor, then frees this object with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0052b380
void* FUN_0052b380_shell::DestroyAndDeallocate(unsigned int flags)
{
    FUN_0052b3b0::~FUN_0052b3b0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct ImageSpaceCopyEntry : public ::TESImageSpace
{
    void FUN_0052b6a0(::TESForm* apCopy);
};
// Copies the TESImageSpace data from apCopy into this entry after calling FUN_004851b0.
// @fnv 0x0052b6a0
void ImageSpaceCopyEntry::FUN_0052b6a0(::TESForm* apCopy)
{
    ::TESImageSpace* pcopy = dynamic_cast< ::TESImageSpace*>(apCopy);
    if (!pcopy)
        return;
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(pcopy);
    ::memcpy(&Data, &pcopy->Data, sizeof(Data));
}
