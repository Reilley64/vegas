// fallout_shared/ragdolldata.cpp: RagDollData, RagDollDataEx, RagDollRefUpdater, RagDollWalker and more (17 functions)

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/Matrix161.h"
#include "fnv/decl/NiPlane.h"
#include "fnv/decl/S_00a592c0_Matrix3.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_00c6b000.h"
#include "ragdolldata_decls.h"

// Returns the negation of operator== for this matrix compared with another matrix.
// @fnv 0x004d9ab0
bool ThreeByThreeMatrix::operator!=(const ThreeByThreeMatrix& matrix) const
{
    return !(*this == matrix);
}

struct CFilter
{
    bool QLinkedGroup();
    void SetLinkedGroup(bool);
    bool QNoCollision();
    void SetCollisionDisabled(bool);
    bool QMoppScaled();
    void SetMoppScaled(bool);
    bool QBipLayer();
    int GetLayer();
    void SetLayer(int);
    int GetBipedPart();
    unsigned int GetPart();
    void SetPart(unsigned int);
    unsigned int GetGroup();
    void SetGroup(unsigned int);
    void Init(int, unsigned int, int);
    void MakeSubShapeFilter();
    void GetViewerStrings(void*);
    void __dflt_ctor_closure();
    unsigned int iFilter;
};
typedef char _sizecheck_CFilter[sizeof(CFilter) == 4 ? 1 : -1];
struct FUN_004d9da0_shell : public CFilter
{
    unsigned int FUN_004d9da0();
};

// @fnv 0x004d9da0
unsigned int FUN_004d9da0_shell::FUN_004d9da0()
{
    return (iFilter >> 8) & 0x1f;
}

struct _dummy_4d9fa0
{
    void FUN_004d9fa0(bool abTF);
};
// Recursively applies stored bone translation and rotation to node and its children, advancing index while bones remain.
// @fnv 0x004d9dc0
bool RagDollData::FindBoneIndex(NiNode* node, unsigned int& ruiIndex)
{
    bool result = true;
    if (node && ruiIndex < count)
    {
        bhkCollisionObject* collision = ((::bhkCollisionObject *)(::FUN_004a8b00((::BGSBodyPart *)(node))));
        if (collision)
        {
            {
                int id = ((int)(reinterpret_cast<::FUN_004d9da0_shell *>((void *)&(const ::bhkFilter &)(((::bhkWorldObject *)(::fnv_006fa820::FUN_006fa820((const char *)(collision))))->FUN_0043b4f0()))->FUN_004d9da0()));
                if (bones[ruiIndex].id != id)
                    return false;
            }
            reinterpret_cast<::FUN_00440460_S *>((node))->FUN_00440460((const ::V3 *)&(bones[ruiIndex].translate));
            ThreeByThreeMatrix rotation;
            reinterpret_cast<::Matrix161 *>(&(rotation))->FUN_00a59540(bones[ruiIndex].rotate.x, bones[ruiIndex].rotate.y, bones[ruiIndex].rotate.z);
            reinterpret_cast<::FUN_0043fa80_s *>((node))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&rotation)));
            reinterpret_cast<::_dummy_4d9fa0 *>((collision))->FUN_004d9fa0(true);
            collision->vfn_b0(1, 0, 0);
            ++ruiIndex;
        }
        NiUpdateData update(0.0f, false, false);
        node->UpdateWorldData(update);
        unsigned int children = node->FUN_0043b480();
        for (unsigned int i = 0; i < children; ++i)
        {
            NiNode* childNode;
            {
                NiAVObject* child = node->GetAt(i);
                childNode = child ? child->IsSceneNode() : 0;
            }
            if (childNode && !FindBoneIndex(childNode, ruiIndex))
                result = false;
            if (ruiIndex >= count)
                break;
        }
    }
    return result;
}

template <int N> struct EndianSizeTag
{
};


struct FUN_004d9280
{
    void __thiscall EndianSwap();
};

// Byte-swaps the six 4-byte words following the object's first word via BSEndian.
// @fnv 0x004d9280
void __thiscall FUN_004d9280::EndianSwap()
{
    ::FUN_00401080((int*)this + 1);
    ::FUN_00401080((int*)this + 2);
    ::FUN_00401080((int*)this + 3);
    ::FUN_00401080((int*)this + 4);
    ::FUN_00401080((int*)this + 5);
    ::FUN_00401080((int*)this + 6);
}

struct FUN_004d9fc0_shell
{
    unsigned short m_flags;  // +0xc
    void FUN_004d9fc0(bool abSet, unsigned short uFlags);
};
// @fnv 0x004d9fa0
void _dummy_4d9fa0::FUN_004d9fa0(bool abTF)
{
    reinterpret_cast<::FUN_004d9fc0_shell *>(this)->FUN_004d9fc0(abTF, 0x40);
}

// Sets or clears the given flag bits in the 16-bit flags field at offset 0xc of this object.
// @fnv 0x004d9fc0
void FUN_004d9fc0_shell::FUN_004d9fc0(bool abSet, unsigned short uFlags)
{
    if (abSet)
        ((unsigned short*)((char*)this + 0xc))[0] |= uFlags;
    else
        ((unsigned short*)((char*)this + 0xc))[0] &= ~uFlags;
}

// Recursively counts node and its descendants for which FUN_004a8b00 returns true, returning the total count.
// @fnv 0x004da180
unsigned char FUN_004da180(NiNode* node)
{
    unsigned char count = 0;
    if (node)
    {
        if (((::bhkCollisionObject *)(::FUN_004a8b00((::BGSBodyPart *)(node)))))
            ++count;
        unsigned int total = node->FUN_0043b480();
        for (unsigned int i = 0; i < total; ++i)
        {
            NiAVObject* object = node->GetAt(i);
            NiNode* child = object ? object->IsSceneNode() : 0;
            if (child)
                count += FUN_004da180(child);
        }
    }
    return count;
}

namespace fnv_004d94a0 {
struct FUN_004d94a0_shell : public RagDollData
{
    bool LoadRagdollChunk(TESFile*);
};

void* __cdecl operator new(unsigned int);
template <int N> struct EndianSizeTag
{
};
struct FUN_004d9280
{
};
struct FUN_0055a400 : FUN_004d9280
{
    char pad[0x1c];
    FUN_0055a400();
};
struct TESFileAccessor
{
};
// @fnv 0x004d94a0
bool FUN_004d94a0_shell::LoadRagdollChunk(TESFile* apFile)
{
    bool bretval = false;
    if (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0())) == 0x44475258)
    {
        unsigned int isize = reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C();
        *(unsigned char*)this = isize / sizeof(FUN_0055a400);
        if (isize % *(unsigned char*)this == 0)
        {
            *(FUN_0055a400**)((char*)this + 4) = new FUN_0055a400[*(unsigned char*)this];
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(*(FUN_0055a400**)((char*)this + 4)), isize);
            if (reinterpret_cast<::TESFile *>((((TESFileAccessor*)apFile)))->IsEndianConversionRequired())
            {
                for (unsigned int I = 0; I < *(unsigned char*)this; I++)
                    reinterpret_cast<::FUN_004d9280 *>(&((*(FUN_0055a400**)((char*)this + 4))[I]))->EndianSwap();
            }
            bretval = true;
        }
        else
            *(unsigned char*)this = 0;
    }
    if (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0())) == 0x42475258)
    {
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(void *)((char*)this + 8), 0xc);
        if (reinterpret_cast<::TESFile *>((((TESFileAccessor*)apFile)))->IsEndianConversionRequired())
        {
            ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 8));
            ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 0xc));
            ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 0x10));
        }
        bretval = true;
    }
    return bretval;
}
}  // namespace fnv_004d94a0

struct Call_439090
{
    bool operator==(const Call_439090& a) const;
};

int _memcmp(const void*, const void*, unsigned int);

struct FUN_004d9780_shell
{
    unsigned char m_ucValue;
    TransformEntry* m_pTransformEntry;
    bool FUN_004d9780(FUN_004d9780_shell* apCompare);
};

// @fnv 0x004d9780
bool FUN_004d9780_shell::FUN_004d9780(FUN_004d9780_shell* apCompare)
{
    if (!apCompare)
        return true;
    if (m_ucValue != apCompare->m_ucValue)
        return true;
    if (reinterpret_cast<::NiPlane *>((void *)&(const ::Call_439090 &)(*(Call_439090*)((char*)this + 8)))->operator==((const ::NiPlane &)(*(Call_439090*)((char*)apCompare + 8))))
        return true;
    if (m_ucValue && _memcmp(m_pTransformEntry, apCompare->m_pTransformEntry, m_ucValue * 0x1c))
        return true;
    return false;
}

extern unsigned int _data_011c16bc;

struct DoorTeleportLoadData
{
    unsigned int data[7];

    DoorTeleportLoadData();
};

struct FUN_004d9670_shell
{
    struct Data
    {
        unsigned int value0;
        unsigned int value1;
        unsigned int value2;
    };

    unsigned char count;
    DoorTeleportLoadData* items;
    Data data;

    void FUN_004d9670(const FUN_004d9670_shell* source);
};

// Copies count, data and the items array from source into this object, reallocating the items buffer.
// @fnv 0x004d9670
void FUN_004d9670_shell::FUN_004d9670(const FUN_004d9670_shell* source)
{
    if (source)
    {
        DoorTeleportLoadData* oldItems = items;
        ::FUN_00401030(oldItems);

        count = source->count;
        data = source->data;

        items = new DoorTeleportLoadData[count];

        __memcpy(items, source->items, count * sizeof(DoorTeleportLoadData));
    }
}

struct FUN_004d93c0_bone
{
    signed char unk00;
    float translate[3];
    float rotate[3];
};

struct FUN_004d93c0_name
{
    unsigned int m_00;
    unsigned int m_04;
};

struct FUN_004d93c0_cls
{
    unsigned char m_uiItemCount;
    FUN_004d93c0_bone* m_kBones;
    FUN_004d93c0_name m_name;
    void FUN_004d93c0();
};


// @fnv 0x004d93c0
void FUN_004d93c0_cls::FUN_004d93c0()
{
    if (m_uiItemCount != 0)
    {
        if (((bool)(::FUN_00401500())))
        {
            for (unsigned int i = 0; i < m_uiItemCount; i++)
            {
                reinterpret_cast<::FUN_004d9280 *>(&(m_kBones[i]))->EndianSwap();
            }
        }
        ::AppendChunk(0x44475258, m_kBones, m_uiItemCount * 28);
        if (((bool)(::FUN_00401500())))
        {
            for (unsigned int uiSwapIndex = 0; uiSwapIndex < m_uiItemCount; uiSwapIndex++)
            {
                reinterpret_cast<::FUN_004d9280 *>(&(m_kBones[uiSwapIndex]))->EndianSwap();
            }
        }
    }
    if (reinterpret_cast<::NiPlane *>(&(m_name))->operator==((*(const ::NiPlane *)((*reinterpret_cast<char (*)[]>((void *)&::NiPoint3::ZERO))))))
    {
        ::FUN_00485710((void *)(0x42475258), &m_name, (void *)(3));
    }
}

class RagDollRefStandIn
{
  public:
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual bool IsActor();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual NiAVObject* Get3D();
};

class RagDollDataEx : public RagDollData
{
  public:
    bool FUN_004d9800(RagDollRefStandIn* apRef);
};

class TESObjectREFR
{
  public:
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
    virtual bool IsDynamicHavok();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17c();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual void vf1a0();
    virtual void vf1a4();
    virtual void vf1a8();
    virtual void vf1ac();
    virtual void vf1b0();
    virtual void vf1b4();
    virtual void vf1b8();
    virtual void vf1bc();
    virtual void vf1c0();
    virtual void vf1c4();
    virtual void vf1c8();
    virtual void vf1cc();
    virtual void vf1d0();
    virtual void vf1d4();
    virtual void vf1d8();
    virtual void vf1dc();
    virtual void vf1e0();
    virtual void vf1e4();
    virtual void vf1e8();
    virtual void vf1ec();
    virtual void vf1f0();
    virtual NiPoint3* GetPos();
    ThreeByThreeMatrix GetRotation();
};

class NiAVObjectEx : public NiAVObject
{
  public:
};

struct NiPoint3Cmp
{
};

struct NiMatrix3Cmp
{
};


struct RagDollRefUpdater
{
    bool bEnabled;
    bool FUN_004d9910(TESObjectREFR* apRef);
};

struct EulerMatrix
{
};
struct AVObjectLocal
{
};

struct RagDollWalker
{
    unsigned char count;
    TransformEntry* bones;
    bool CollectBoneTransforms(NiNode* apNode, unsigned int& arIndex, bool abSet);
};

// @fnv 0x004d9bd0
bool RagDollWalker::CollectBoneTransforms(NiNode* apNode, unsigned int& arIndex, bool abSet)
{
    bool bResult2 = true;
    if (apNode && arIndex < count)
    {
        bhkCollisionObject* pCollision = ((::bhkCollisionObject *)(::FUN_004a8b00((::BGSBodyPart *)(apNode))));
        if (pCollision)
        {
            if (abSet)
            {
                bones[arIndex].id = ((int)(reinterpret_cast<::FUN_004d9da0_shell *>((void *)&(const ::bhkFilter &)(((::bhkWorldObject *)(::fnv_006fa820::FUN_006fa820((const char *)(pCollision))))->FUN_0043b4f0()))->FUN_004d9da0()));
            }
            else if (bones[arIndex].id != ((int)(reinterpret_cast<::FUN_004d9da0_shell *>((void *)&(const ::bhkFilter &)(((::bhkWorldObject *)(::fnv_006fa820::FUN_006fa820((const char *)(pCollision))))->FUN_0043b4f0()))->FUN_004d9da0())))
            {
                return false;
            }
            bones[arIndex].translate = reinterpret_cast<::NiAVObject *>((((AVObjectLocal*)apNode)))->FUN_0043c490();
            reinterpret_cast<::S_00a592c0_Matrix3 *>((((::EulerMatrix *)(::FUN_006a9540((char *)(((AVObjectLocal*)apNode)))))))->DecomposeToEulerAngles(bones[arIndex].rotate.x, bones[arIndex].rotate.y, bones[arIndex].rotate.z);
            arIndex++;
        }
        unsigned int uiCount5 = apNode->FUN_0043b480();
        for (unsigned int i3 = 0; i3 < uiCount5; i3++)
        {
            NiAVObject* pChild2 = apNode->GetAt(i3);
            NiNode* pChildNode = pChild2 ? pChild2->IsSceneNode() : 0;
            if (pChildNode)
            {
                if (!CollectBoneTransforms(pChildNode, arIndex, abSet))
                {
                    bResult2 = false;
                }
            }
            if (arIndex >= count)
            {
                break;
            }
        }
    }
    return bResult2;
}

struct VisualNode;
struct VisualObject
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual VisualNode* IsSceneNode();
};
struct SceneInput
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual bool FUN_0100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual struct VisualObject* FUN_01d0();
};
struct NamedLink;
struct VisualNode
{
};
struct Controller;
struct NamedLink
{
};
struct Controller
{
};
struct LocalRagdollTransform
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    void FUN_004da340(SceneInput* source);
};
// @fnv 0x004da340
void LocalRagdollTransform::FUN_004da340(SceneInput* source)
{
    VisualObject* pObject = source && source->FUN_0100() ? source->FUN_01d0() : 0;
    VisualNode* node = pObject ? pObject->IsSceneNode() : 0;
    if (node != 0)
    {
        NamedLink* link = ((::NamedLink *)(reinterpret_cast<::S_FUN_0045bc00 *>((node))->FUN_0045bc00(0)));
        if (link != 0)
        {
            reinterpret_cast<::S_00a592c0_Matrix3 *>((((::Controller *)(::FUN_006a9540((char *)(link))))))->DecomposeToEulerAngles(*(float *)nullptr, *(float *)nullptr, *(float *)nullptr);
        }
    }
}


struct FUN_004da230_node : public NiNode
{
};

struct FUN_004da230_intermediate
{
    virtual void vfn_0();
    virtual void vfn_1();
    virtual void vfn_2();
    virtual FUN_004da230_node* GetNode();
};

struct FUN_004da230_param
{
    virtual void vfn_0();
    virtual void vfn_1();
    virtual void vfn_2();
    virtual void vfn_3();
    virtual void vfn_4();
    virtual void vfn_5();
    virtual void vfn_6();
    virtual void vfn_7();
    virtual void vfn_8();
    virtual void vfn_9();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void vfn_22();
    virtual void vfn_23();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual void vfn_28();
    virtual void vfn_29();
    virtual void vfn_30();
    virtual void vfn_31();
    virtual void vfn_32();
    virtual void vfn_33();
    virtual void vfn_34();
    virtual void vfn_35();
    virtual void vfn_36();
    virtual void vfn_37();
    virtual void vfn_38();
    virtual void vfn_39();
    virtual void vfn_40();
    virtual void vfn_41();
    virtual void vfn_42();
    virtual void vfn_43();
    virtual void vfn_44();
    virtual void vfn_45();
    virtual void vfn_46();
    virtual void vfn_47();
    virtual void vfn_48();
    virtual void vfn_49();
    virtual void vfn_50();
    virtual void vfn_51();
    virtual void vfn_52();
    virtual void vfn_53();
    virtual void vfn_54();
    virtual void vfn_55();
    virtual void vfn_56();
    virtual void vfn_57();
    virtual void vfn_58();
    virtual void vfn_59();
    virtual void vfn_60();
    virtual void vfn_61();
    virtual void vfn_62();
    virtual void vfn_63();
    virtual bool IsReady();
    virtual void vfn_65();
    virtual void vfn_66();
    virtual void vfn_67();
    virtual void vfn_68();
    virtual void vfn_69();
    virtual void vfn_70();
    virtual void vfn_71();
    virtual void vfn_72();
    virtual void vfn_73();
    virtual void vfn_74();
    virtual void vfn_75();
    virtual void vfn_76();
    virtual void vfn_77();
    virtual void vfn_78();
    virtual void vfn_79();
    virtual void vfn_80();
    virtual void vfn_81();
    virtual void vfn_82();
    virtual void vfn_83();
    virtual void vfn_84();
    virtual void vfn_85();
    virtual void vfn_86();
    virtual void vfn_87();
    virtual void vfn_88();
    virtual void vfn_89();
    virtual void vfn_90();
    virtual void vfn_91();
    virtual void vfn_92();
    virtual void vfn_93();
    virtual void vfn_94();
    virtual void vfn_95();
    virtual void vfn_96();
    virtual void vfn_97();
    virtual void vfn_98();
    virtual void vfn_99();
    virtual void vfn_100();
    virtual void vfn_101();
    virtual void vfn_102();
    virtual void vfn_103();
    virtual void vfn_104();
    virtual void vfn_105();
    virtual void vfn_106();
    virtual void vfn_107();
    virtual void vfn_108();
    virtual void vfn_109();
    virtual void vfn_110();
    virtual void vfn_111();
    virtual void vfn_112();
    virtual void vfn_113();
    virtual void vfn_114();
    virtual void vfn_115();
    virtual FUN_004da230_intermediate* GetContainer();
};

struct FUN_004da230_shell
{
    unsigned int unk00;
    unsigned int unk04;
    NiPoint3 position;
    void UpdateNodeFromPosition(FUN_004da230_param* object);
};
// @fnv 0x004d9910
bool RagDollRefUpdater::FUN_004d9910(TESObjectREFR* apRef)
{
    unsigned int ItemUpdateArray = 0;
    bool bResult = true;
    if (apRef && ((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((apRef))->FUN_0043fcd0())) && bEnabled)
    {
        NiAVObjectEx* p3D2 = (NiAVObjectEx*)((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((apRef))->FUN_0043fcd0()));
        NiNode* pNode4 = p3D2 ? p3D2->IsSceneNode() : 0;
        if (apRef->IsDynamicHavok())
            reinterpret_cast<::FUN_004da230_shell *>(this)->UpdateNodeFromPosition((::FUN_004da230_param *)(apRef));
        bResult = reinterpret_cast<::RagDollData *>(this)->FindBoneIndex(pNode4, ItemUpdateArray);
        if (p3D2)
        {
            if (reinterpret_cast<::NiPlane *>((void *)&(((NiPoint3Cmp&)reinterpret_cast<::NiAVObject *>((p3D2))->FUN_0043c490())))->operator==((const ::NiPlane &)(*apRef->GetPos())) ||
                reinterpret_cast<::ThreeByThreeMatrix *>((void *)&(((NiMatrix3Cmp&)(*(::ThreeByThreeMatrix *)(::FUN_006a9540((char *)(p3D2)))))))->operator!=(apRef->GetRotation()))
            {
                reinterpret_cast<::FUN_00440460_S *>((p3D2))->FUN_00440460((const ::V3 *)&(*apRef->GetPos()));
                reinterpret_cast<::FUN_0043fa80_s *>((p3D2))->FUN_0043fa80(apRef->GetRotation());
                ::FUN_00c6bd00((::TreeNode_cls *)(p3D2), true);
                NiUpdateData kData6(0.0f, false, false);
                reinterpret_cast<::FUN_00a59c60_cls *>((p3D2))->FUN_00a59c60((int)&(kData6));
            }
        }
        if (!bResult)
            ::FUN_00c6a350((::NiAVObject *)(pNode4), 1, 1, 0, 1);
    }
    return ItemUpdateArray == bEnabled && bResult;
}

// @fnv 0x004da230
void FUN_004da230_shell::UpdateNodeFromPosition(FUN_004da230_param* object)
{
    if (reinterpret_cast<::NiPlane *>((void *)&(const ::Call_439090 &)(reinterpret_cast<Call_439090&>(position)))->operator==((const ::NiPlane &)(reinterpret_cast<Call_439090&>(::NiPoint3::ZERO))))
    {
        FUN_004da230_intermediate* pContainer;
        FUN_004da230_node* pNode;

        pContainer = (object != 0 && object->IsReady()) ? object->GetContainer() : 0;
        pNode = (pContainer != 0) ? pContainer->GetNode() : 0;

        if (pNode != 0)
        {
            NiNode* node = ((::NiNode *)(reinterpret_cast<::S_FUN_0045bc00 *>((pNode))->FUN_0045bc00(0)));
            if (node != 0)
            {
                ThreeByThreeMatrix rotation;
                reinterpret_cast<::Matrix161 *>(&(rotation))->FUN_00a59540(position.x, position.y, position.z);
                reinterpret_cast<::FUN_0043fa80_s *>((node))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&rotation)));
                NiUpdateData update(0.0f, false, false);
                node->UpdateWorldData(update);
            }
        }
    }
}

unsigned char FUN_004da180(NiNode* node);

struct RagDollBoneInit : public TransformEntry
{
    RagDollBoneInit();
};

class RagDollDataInit : public RagDollData
{
  public:
    void InitFromRef(RagDollRefStandIn* apRef);
};
// @fnv 0x004d9800
bool RagDollDataEx::FUN_004d9800(RagDollRefStandIn* apRef)
{
    unsigned int uiIndex = 0;
    bool bResultTmp = true;
    if (apRef && apRef->Get3D())
    {
        NiAVObject* p3D = apRef->Get3D();
        NiNode* pNode2 = p3D ? p3D->IsSceneNode() : 0;
        if (apRef->IsActor())
            reinterpret_cast<::LocalRagdollTransform *>(this)->FUN_004da340((::SceneInput *)(apRef));
        if (!count)
            reinterpret_cast<::RagDollDataInit *>(this)->InitFromRef(apRef);
        if (count)
            bResultTmp = reinterpret_cast<::RagDollWalker *>(this)->CollectBoneTransforms(pNode2, uiIndex, 0);
        if (!bResultTmp)
            reinterpret_cast<::RagDollDataInit *>(this)->InitFromRef(apRef);
    }
    return uiIndex == count && bResultTmp;
}

// Initializes ragdoll bone data from a reference's 3D node, collecting bone transforms and warning on failure.
// @fnv 0x004da010
void RagDollDataInit::InitFromRef(RagDollRefStandIn* apRef)
{
    count = 0;
    delete[] bones;
    if (apRef && apRef->Get3D())
    {
        NiAVObject* pObj = apRef->Get3D();
        NiNode* pNode = pObj ? pObj->IsSceneNode() : 0;
        count = FUN_004da180(pNode);
        if (count)
        {
            bones = new RagDollBoneInit[count];
            unsigned int uiIndex = 0;
            if (!((RagDollWalker*)this)->CollectBoneTransforms(pNode, uiIndex, true))
                ::FUN_005b5e40();
        }
    }
}
