
// src/fallout_shared/tesproduceform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tesproduceform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


#include <cstring>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005b5000.h"
struct FUN_0048b590_shell
{
    void ClearFields();
};

// Sets the int at offset 4 to 0 and zeroes the 4 bytes at offset 8 of this object.
// @fnv 0x0048b590
void FUN_0048b590_shell::ClearFields()
{
    *(reinterpret_cast<int*>(this) + 1) = 0;
    ::FUN_00403d30(reinterpret_cast<char*>(this) + 8, 0, 4);
}


struct FUN_0048b670_shell
{
    void CopyFromSource(void* src);
};

// Copies 4 bytes from src into this object at offset 8 when src is non-null.
// @fnv 0x0048b670
void FUN_0048b670_shell::CopyFromSource(void* pSource)
{
    if (pSource)
        ::__memcpy((char*)this + 8, pSource, 4);
}

struct RefObj0084e3a0
{
};
struct FUN_0048b5c0_shell
{
    int unk0;
    RefObj0084e3a0* unk4;
    int unk8;
    void FUN_0048b5c0();
};
// @fnv 0x0048b5c0
void FUN_0048b5c0_shell::FUN_0048b5c0()
{
    unsigned int tmp;
    if (unk4 != 0)
    {
        tmp = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((unk4))->FUN_0084e3a0()));
        ::FUN_00485910(0x47494650, tmp);
    }
    ::FUN_004856f0((void *)(0x43504650), &unk8, (void *)(4));
}

class BaseFormComponent
{
  public:
    virtual ~BaseFormComponent();
};
struct TESProduceForm : BaseFormComponent
{
    void FUN_0048b610(BaseFormComponent* apCopyFC);
};
struct TESRaceForm
{
};
struct CombatNode
{
};
// Casts apCopyFC to TESProduceForm, initializes this from its combat node value, then copies the data at offset 8.
// @fnv 0x0048b610
void TESProduceForm::FUN_0048b610(BaseFormComponent* apCopyFC)
{
    TESProduceForm* pCopy = dynamic_cast<TESProduceForm*>(apCopyFC);
    if (!pCopy)
        return;
    reinterpret_cast<::CombatProcedure *>((((TESRaceForm*)this)))->Initialize((::CombatController *)(((std::uintptr_t)(reinterpret_cast<::Callees *>((((CombatNode*)pCopy)))->FUN_00726070()))));
    ((FUN_0048b670_shell*)this)->CopyFromSource((void*)((char*)pCopy + 8));
}

struct ProduceFormData : BaseFormComponent
{
    void* pIngredient;
    unsigned char cProdChance[4];
    bool FUN_0048b6a0(BaseFormComponent* apOther);
};

// Compares production chance bytes and a value from FUN_00726070 against another component, returning true when they differ or the other is not a TESProduceForm.
// @fnv 0x0048b6a0
bool ProduceFormData::FUN_0048b6a0(BaseFormComponent* apOther)
{
    ProduceFormData* pOther = (ProduceFormData*)dynamic_cast<TESProduceForm*>(apOther);
    if (!pOther)
        return true;
    if (((unsigned int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((CombatNode*)this)))->FUN_00726070())) != ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((CombatNode*)pOther)))->FUN_00726070())))
        return true;
    if (memcmp(cProdChance, pOther->cProdChance, 4))
        return true;
    return false;
}

class TESFile;

struct FUN_00485b60_Cls
{
    virtual int v00();
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual int v08();
    virtual int v09();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual int v36();
    virtual int v37();
    virtual int v38();
    virtual int v39();
    virtual int v40();
    virtual int v41();
    virtual int v42();
    virtual int v43();
    virtual int v44();
    virtual int v45();
    virtual int v46();
    virtual int v47();
    virtual int v48();
    virtual int v49();
    virtual int v50();
    virtual int v51();
    virtual int v52();
    virtual int v53();
    virtual int v54();
    virtual int v55();
    virtual int v56();
    virtual int v57();
    virtual int v58();
    virtual int v59();
    virtual int v60();
    virtual int v61();
    virtual int v62();
    virtual int v63();
    virtual int v64();
    virtual int v65();
    virtual int v66();
    virtual int v67();
    virtual int v68();
    virtual int v69();
    virtual int v70();
    virtual int v71();
    virtual int v72();
    virtual int v73();
    virtual int v74();
    virtual int v75();
    virtual int v76();
};

class TESForm;

extern const char DAT_0101d2b4[];
extern const char DAT_0101d2f8[];
extern const char DAT_0101d340[];

class TESFile;
class TESForm
{
  public:
    virtual ~TESForm();
public:
    ::TESFile *GetFile(int);
};

struct IngredientItem : TESForm
{
    int m_04;
};

struct FUN_0048b720_Cls : ProduceFormData
{
    void ResolveIngredient(FUN_00485b60_Cls* apArg);
};

// Resolves pIngredient's form ID through the file, re-looks it up as an IngredientItem, and warns if the lookup fails.
// @fnv 0x0048b720
void FUN_0048b720_Cls::ResolveIngredient(FUN_00485b60_Cls* apArg)
{
    if (pIngredient != 0)
    {
        unsigned int formID = (unsigned int)(std::uintptr_t)pIngredient;
        ::ResolveFormID(&formID, reinterpret_cast<::TESForm *>((apArg))->GetFile(-1));
        pIngredient = dynamic_cast<IngredientItem*>(::FUN_004839c0(formID));
        if (pIngredient == 0)
        {
            if (apArg != 0)
            {
                if (reinterpret_cast<::BGSCameraPath *>((apArg))->HasNameForWarning())
                {
                    ::FUN_005b5e40();
                }
                else
                {
                    ::FUN_005b5e40();
                }
            }
            else
            {
                ::FUN_005b5e40();
            }
        }
    }
}
