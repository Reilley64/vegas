// bsshader/imagespacetexture.cpp: free functions (1 function)

#include "fnv/decl/BA3760Object.h"
#include "fnv/decl/H_00ba39a0.h"
#include "fnv/decl/Holder00ba37f0.h"
#include "fnv/decl/Manager.h"
#include "fnv/symbols_011f9000.h"
#include "imagespacetexture_decls.h"

struct EnchantmentItem;
struct TESForm;
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
struct TESEnchantableForm : public BaseFormComponent
{
    virtual int GetCastingType();
    void SetCastingType(int);
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    void InitItem(TESForm*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static EnchantmentItem* FindFormEnchantment(TESForm*);
    EnchantmentItem* FindFormEnchantment();
    void SetFormEnchanting(EnchantmentItem*);
    static unsigned short GetFormEnchantmentAmount(TESForm*);
    unsigned short GetFormEnchantmentAmount();
    void SetFormEnchantmentAmount(unsigned short);
    EnchantmentItem* m_pEnchantment;
    unsigned short m_usEnchantmentAmount;
    char _pad_a[2];
    int m_eCastingType;
};
struct FUN_0041fd00_shell : public TESEnchantableForm
{
    void FUN_0041fd00(int);
};

// @fnv 0x0041fd00
void FUN_0041fd00_shell::FUN_0041fd00(int aeCastingType)
{
    m_eCastingType = aeCastingType;
}
