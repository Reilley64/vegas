// fallout_shared/tesweightform.cpp: TESWeightForm, Modifier, WeightComparison (6 functions)

#include "fnv/decl/FUN_0048ee50_Class.h"
#include "fnv/decl/FUN_004f5d90_shell.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/symbols_00402000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_011de000.h"
#include "tesweightform_decls.h"

// @fnv 0x0048ebc0
float TESWeightForm::GetWeightForForm(TESForm* form, bool useFormWeight)
{
    TESWeightForm* weightForm = 0;
    float weight = 0.0f;

    if (form)
    {
        switch (((TESBoundObject*)form)->GetFormType())
        {
        case 0x1d: {
            TESForm* form1d = form;
            weightForm = (TESWeightForm*)(form1d ? (char*)form1d + 0x84 : 0);
            break;
        }
        case 0x2f: {
            TESForm* form2f = form;
            weightForm = (TESWeightForm*)(form2f ? (char*)form2f + 0x94 : 0);
            break;
        }
        case 0x28: {
            TESForm* form28 = form;
            weightForm = (TESWeightForm*)(form28 ? (char*)form28 + 0x8c : 0);
            break;
        }
        case 0x1f:
        case 0x2e:
        case 0x32:
        case 0x67: {
            TESForm* form1f = form;
            weightForm = (TESWeightForm*)(form1f ? (char*)form1f + 0x7c : 0);
            break;
        }
        case 0x1b: {
            TESForm* form1b = form;
            weightForm = (TESWeightForm*)(form1b ? (char*)form1b + 0x74 : 0);
            break;
        }
        case 0x1a: {
            TESForm* form1a = form;
            weightForm = (TESWeightForm*)(form1a ? (char*)form1a + 0x60 : 0);
            break;
        }
        case 0x19: {
            TESForm* form19 = form;
            weightForm = (TESWeightForm*)(form19 ? (char*)form19 + 0x8c : 0);
            break;
        }
        case 0x18: {
            TESForm* form18 = form;
            weightForm = (TESWeightForm*)(form18 ? (char*)form18 + 0x60 : 0);
            break;
        }
        case 0x1e: {
            TESForm* form1e = form;
            weightForm = (TESWeightForm*)(form1e ? (char*)form1e + 0x84 : 0);
            break;
        }
        case 0x29: {
            TESForm* form29 = form;
            if (useFormWeight)
                weight = reinterpret_cast<::FUN_0048ee50_Class *>((form29))->GetFieldB8Float();
            break;
        }
        }
    }

    if (weight != 0.0)
        return weight;
    else if (weightForm)
        return reinterpret_cast<::TimeoutTimer *>((((ActiveEffect*)weightForm)))->FUN_006b9130();
    else
        return -1.0f;
}

struct BaseFormComponent
{
    virtual ~BaseFormComponent();
};
struct Modifier
{
    void SetWeight(BaseFormComponent*);
};

extern int DAT_0101a4c4;

// Runs the BaseFormComponent constructor, installs the vtable pointer from DAT_0101a4c4, calls FUN_008c6060, and returns pThis.
// @fnv 0x0048eac0
void* FUN_0048eac0(void* pThis)
{
    ::FUN_00402d30((int *)(((BaseFormComponent*)pThis)));
    *(int**)pThis = &DAT_0101a4c4;
    reinterpret_cast<::TimeoutTimer *>((pThis))->FUN_00910b10();
    return pThis;
}

extern int DAT_0101a4c4;

struct Date
{
    Date();
    ~Date();
};

struct FUN_0048eaf0 : Date
{
    ~FUN_0048eaf0();
};

// @fnv 0x0048eaf0
FUN_0048eaf0::~FUN_0048eaf0()
{
    *reinterpret_cast<std::intptr_t*>(this) = reinterpret_cast<std::intptr_t>(&DAT_0101a4c4);
}

class PC7d;
struct S00517380
{
    void FUN_00517380(std::intptr_t, PC7d*);
};
// If a1 is non-zero and a2 is the player, calls FUN_00709470 with (1, a1, 0, 0, 1, 0) then FUN_0047a560(a1, a2, 0).
// @fnv 0x00517380
void S00517380::FUN_00517380(std::intptr_t a1, PC7d* a2)
{
    if (a1 != 0 && a2 == (*reinterpret_cast<::PC7d * *>(&::_g_thePlayer)))
    {
        ::FUN_00709470(1, a1, 0, 0, 1);
        ::FUN_0047a560((::TESObjectREFR *)(a1), (::TESObjectREFR *)(a2), (::BGSOpenCloseForm *)(0));
    }
}

// Casts the component to TESWeightForm and, if valid, sets the value to its weight via GetWeightForForm.
// @fnv 0x0048eb10
void Modifier::SetWeight(BaseFormComponent* component)
{
    TESWeightForm* weightForm = dynamic_cast<TESWeightForm*>(component);
    if (!weightForm)
        return;
    reinterpret_cast<::FUN_004f5d90_shell *>(this)->FUN_004f5d90(reinterpret_cast<::TimeoutTimer *>((void *)(weightForm))->FUN_006b9130());
}

struct WeightComparison : TESWeightForm
{
    bool FUN_0048eb60(BaseFormComponent* component);
};
// Returns true if the other form is not a TESWeightForm or its weight differs from this form's weight.
// @fnv 0x0048eb60
bool WeightComparison::FUN_0048eb60(BaseFormComponent* component)
{
    TESWeightForm* other = dynamic_cast<TESWeightForm*>(component);
    if (!other)
        return true;
    if (reinterpret_cast<::TimeoutTimer *>((void *)this)->FUN_006b9130() != reinterpret_cast<::TimeoutTimer *>((void *)(other))->FUN_006b9130())
        return true;
    return false;
}
