
// modelloader_ctx_variant.cpp: context variant of src/fallout_shared/modelloader.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include <cstring>
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/FUN_0043caa0_shell.h"
#include "fnv/decl/FUN_0043caf0_shell.h"
#include "fnv/decl/FUN_0043cc60_shell.h"
#include "fnv/decl/FUN_0043e810_shell.h"
#include "fnv/decl/FUN_00442550_shell.h"
#include "fnv/decl/FUN_00448a20_class.h"
#include "fnv/decl/FUN_00448a60_struct.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00496cd0_cls.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00c3cff0_shell.h"
#include "fnv/decl/FUN_00c3d440_cls.h"
#include "fnv/decl/Loader_S.h"
#include "fnv/decl/ObjectC3.h"
#include "fnv/decl/ParentByteQuery.h"
#include "fnv/decl/RecursiveModelLoader.h"
#include "fnv/decl/ThisS.h"
#include "fnv/decl/fnv_00440ba0__FUN_00440ba0_shell.h"
#include "fnv/decl/fnv_004414f0__FUN_004414f0.h"
#include "fnv/decl/fnv_004446a0__FUN_004446a0_shell.h"
#include "fnv/decl/fnv_0062a100__FUN_0062a100_shell.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_00448000.h"
#include "fnv/symbols_00449000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00657000.h"
#include "fnv/symbols_00a5f000.h"
#include "fnv/symbols_00a61000.h"
#include "fnv/symbols_00af6000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_01202000.h"
#include "modelloader_verified_packet.h"


class AutoMemContext
{
    int unk00;

  public:
    AutoMemContext(int, bool, const char*, int);
    ~AutoMemContext();
};

class NiFixedString
{
  public:
    const char* m_str;
    NiFixedString(const char*);
    ~NiFixedString();
};

class H_A100
{
  public:
};

class FUN_0043c3b0_This
{
  public:
    int FUN_0043c3b0();
};

class FUN_0043e480_shell
{
  public:
    void FUN_0043e480(bool);
};

class FUN_0043c3d0_shell
{
  public:
    bool FUN_0043c3d0();
};

class TextureNode
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
};

class MyFileEntry
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual const char* vfn_18();
};

int FUN_0043c410();
void FUN_0043c3f0(unsigned int);
class CQueuedTexture
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    const char* unk28;
    void* unk2c;
    NiPointer<NiNode> unk30;
    int unk34;


    void FUN_0043c150();
};

// @fnv 0x0043c150
void CQueuedTexture::FUN_0043c150()
{
    AutoMemContext memContext(this->unk18, true,
                              "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 695);

    if (((void *)(reinterpret_cast<::BGSMessageInitAccess *>((this))->GetIconFormID())))
    {
        GetNodePointer((NiNode*)((void *)(reinterpret_cast<::BGSMessageInitAccess *>((this))->GetIconFormID())), this->unk30);
    }
    else if (((const char *)(reinterpret_cast<::FUN_0045cd60_shell *>((this))->FUN_0045cd60())))
    {
        ::FindTextureByPath(((const char *)(reinterpret_cast<::FUN_0045cd60_shell *>((this))->FUN_0045cd60())), (::NiTexture **)&(this->unk30));
    }

    if (this->unk30)
    {
        ((FUN_0043e480_shell*)(void*)this)->FUN_0043e480(true);
        if (reinterpret_cast<::ParentByteQuery *>((((TextureNode*)(void*)(NiNode*)this->unk30)))->FUN_0043c430() == 3 &&
            !((FUN_0043c3d0_shell*)(void*)this)->FUN_0043c3d0())
        {
            ((TextureNode*)(void*)(NiNode*)this->unk30)->vfn_8c();
        }
        return;
    }

    MyFileEntry* fileEntry = ((::MyFileEntry *)(reinterpret_cast<::FUN_00c3cff0_shell *>((this))->FUN_00c3cff0(1, 2)));
    if (fileEntry)
    {
        int tlsVal;
        const char* path = fileEntry->vfn_18();
        tlsVal = FUN_0043c410();
        if (((FUN_0043c3d0_shell*)(void*)this)->FUN_0043c3d0())
        {
            FUN_0043c3f0(1);
        }
        if (strstr(path, "_e.dd"))
        {
            this->unk30 = ((::NiNode *)(::fnv_00a61040::FUN_00a61040((char **)&(const ::NiFixedString &)(NiFixedString(path)), (int)(fileEntry), FUN_0043c4b0(), (int *)(void *)(&DAT_011a9598))));
        }
        else
        {
            this->unk30 = ((::NiNode *)(::FUN_00a5fe30((int)(fileEntry), path, (const int *)(void *)(&DAT_011a9598), 1)));
        }
        FUN_0043c3f0(tlsVal);
    }
    else if (((void *)(reinterpret_cast<::BGSMessageInitAccess *>((this))->GetIconFormID())))
    {
        ::FUN_005b5e40();
    }
    else if (((const char *)(reinterpret_cast<::FUN_0045cd60_shell *>((this))->FUN_0045cd60())))
    {
        ::FUN_005b5e40();
    }
}
