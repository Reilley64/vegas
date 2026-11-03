
// src/fallout_shared/multiboundmarkerdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/multiboundmarkerdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_00439f50_class.h"
#include "fnv/decl/FUN_00439f90_shell.h"
#include "fnv/decl/FUN_00a5c240_shell.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/NiPlane.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/fnv_00569880__FUN_00569880_cls.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_011f4000.h"
struct NiRTTI;
class NiProperty
{
  public:
    const NiRTTI* GetRTTI() const;
};

// @fnv 0x00439280
const NiRTTI* NiProperty::GetRTTI() const
{
    return (const NiRTTI*)&(*reinterpret_cast<const char *const *>(&::g_011f4420));
}

namespace fnv_00439290 {
struct NiProperty
{
    ~NiProperty();
    static void operator delete(void* p, unsigned int size);
    void* DestroyAndFree(unsigned int flags);
};

// Destructs the NiProperty and, when flags has bit 0 set, frees the 24-byte object; returns this.
// @fnv 0x00439290
void* NiProperty::DestroyAndFree(unsigned int flags)
{
    this->NiProperty::~NiProperty();
    if (flags & 1)
        ::FUN_00aa1460(this, 24);
    return this;
}
}  // namespace fnv_00439290

struct FUN_004392c0_shell
{
    void FUN_004392c0(void);
public:
    void FUN_00439320();
};


// @fnv 0x004392c0
void FUN_004392c0_shell::FUN_004392c0(void)
{
    reinterpret_cast<::FUN_00a5c240_shell *>((this))->DestroyFogProperty();
}

struct GlobalObjectO2_00a7b610;

struct FUN_004392e0_shell
{
    GlobalObjectO2_00a7b610* GetGlobalObject();
};

// @fnv 0x004392e0
GlobalObjectO2_00a7b610* FUN_004392e0_shell::GetGlobalObject()
{
    return &::g_011f4408;
}

extern "C" void __cdecl FUN_00439320();

struct NiAlphaProperty
{
    virtual void FUN_00439320();
    void* FUN_004392f0(unsigned int flags);
};

// @fnv 0x004392f0
void* NiAlphaProperty::FUN_004392f0(unsigned int flags)
{
    reinterpret_cast<::FUN_004392c0_shell *>((this))->FUN_00439320();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x1c);
    return this;
}

struct Call_439090_tgt
{
};
struct FUN_00439060_shell
{
    bool FUN_00439060(void* arg);
};
// @fnv 0x00439060
bool FUN_00439060_shell::FUN_00439060(void* arg)
{
    if (!arg)
        return true;
    if (reinterpret_cast<::NiPlane *>((((Call_439090_tgt*)this)))->operator==((*(const ::NiPlane *)(arg))))
        return true;
    return false;
}

struct NiPoint3
{
    float x, y, z;
    NiPoint3();
};

struct ThreeByThreeMatrix
{
    float m[3][3];
};

struct BoundRef
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const NiPoint3& GetBoundCenter();

    ThreeByThreeMatrix FUN_0056fa00();
};

struct CellRect
{
    int iLeft;
    int iTop;
    int iRight;
    int iBottom;
};


// @fnv 0x00439940
bool __cdecl BoundIntersectsCell(BoundRef* pRef, int m_iGridPositionX, int m_iGridCoordinateY)
{
    if (pRef && reinterpret_cast<::FUN_00439f90_shell *>((pRef))->FUN_00439f90())
    {
        CellRect kRectWork;
        kRectWork.iLeft = m_iGridPositionX << 12;
        kRectWork.iRight = kRectWork.iLeft + 0x1000;
        kRectWork.iBottom = m_iGridCoordinateY << 12;
        kRectWork.iTop = kRectWork.iBottom + 0x1000;

        NiPoint3 akCornersY[8];
        NiPoint3 kXY;
        NiPoint3 kY_;
        NiPoint3 kZ6;
        NiPoint3 kExtentLoc = (*(const ::NiPoint3 *)(reinterpret_cast<::fnv_00569880::FUN_00569880_cls *>((pRef))->FUN_00569880()));
        NiPoint3 kCenterZ = pRef->GetBoundCenter();
        ThreeByThreeMatrix kRot9 = pRef->FUN_0056fa00();
        reinterpret_cast<::FUN_00439f50_class *>((void *)&(kRot9))->FUN_00439f50(0, (::NiPoint3 *)&(kXY));
        reinterpret_cast<::MyPoint439180 *>(&(kXY))->FUN_00439180(kExtentLoc.x);
        reinterpret_cast<::FUN_00439f50_class *>((void *)&(kRot9))->FUN_00439f50(1, (::NiPoint3 *)&(kY_));
        reinterpret_cast<::MyPoint439180 *>(&(kY_))->FUN_00439180(kExtentLoc.y);
        reinterpret_cast<::FUN_00439f50_class *>((void *)&(kRot9))->FUN_00439f50(2, (::NiPoint3 *)&(kZ6));
        reinterpret_cast<::MyPoint439180 *>(&(kZ6))->FUN_00439180(kExtentLoc.z);

        akCornersY[0] = (*(::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)(void *)&(const ::NiPoint3 &)((*(::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)(void *)&(const ::NiPoint3 &)((*(::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)&(kCenterZ))->ProjectileLaunched((::NiPoint3 *)&(kXY), {})))))->ProjectileLaunched((::NiPoint3 *)&(kY_), {})))))->ProjectileLaunched((::NiPoint3 *)&(kZ6), {})));
        akCornersY[1] = (*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(void *)&(const ::NiPoint3 &)((*(::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)(void *)&(const ::NiPoint3 &)((*(::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)&(kCenterZ))->ProjectileLaunched((::NiPoint3 *)&(kXY), {})))))->ProjectileLaunched((::NiPoint3 *)&(kY_), {})))))->FUN_00439ef0((::NiPoint3 *)&(kZ6), *(const ::NiPoint3 *)nullptr)));
        akCornersY[2] = (*(::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)(void *)&(const ::NiPoint3 &)((*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(void *)&(const ::NiPoint3 &)((*(::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)&(kCenterZ))->ProjectileLaunched((::NiPoint3 *)&(kXY), {})))))->FUN_00439ef0((::NiPoint3 *)&(kY_), *(const ::NiPoint3 *)nullptr)))))->ProjectileLaunched((::NiPoint3 *)&(kZ6), {})));
        akCornersY[3] = (*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(void *)&(const ::NiPoint3 &)((*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(void *)&(const ::NiPoint3 &)((*(::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)&(kCenterZ))->ProjectileLaunched((::NiPoint3 *)&(kXY), {})))))->FUN_00439ef0((::NiPoint3 *)&(kY_), *(const ::NiPoint3 *)nullptr)))))->FUN_00439ef0((::NiPoint3 *)&(kZ6), *(const ::NiPoint3 *)nullptr)));
        akCornersY[4] = (*(::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)(void *)&(const ::NiPoint3 &)((*(::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)(void *)&(const ::NiPoint3 &)((*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(kCenterZ))->FUN_00439ef0((::NiPoint3 *)&(kXY), *(const ::NiPoint3 *)nullptr)))))->ProjectileLaunched((::NiPoint3 *)&(kY_), {})))))->ProjectileLaunched((::NiPoint3 *)&(kZ6), {})));
        akCornersY[5] = (*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(void *)&(const ::NiPoint3 &)((*(::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)(void *)&(const ::NiPoint3 &)((*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(kCenterZ))->FUN_00439ef0((::NiPoint3 *)&(kXY), *(const ::NiPoint3 *)nullptr)))))->ProjectileLaunched((::NiPoint3 *)&(kY_), {})))))->FUN_00439ef0((::NiPoint3 *)&(kZ6), *(const ::NiPoint3 *)nullptr)));
        akCornersY[6] = (*(::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)(void *)&(const ::NiPoint3 &)((*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(void *)&(const ::NiPoint3 &)((*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(kCenterZ))->FUN_00439ef0((::NiPoint3 *)&(kXY), *(const ::NiPoint3 *)nullptr)))))->FUN_00439ef0((::NiPoint3 *)&(kY_), *(const ::NiPoint3 *)nullptr)))))->ProjectileLaunched((::NiPoint3 *)&(kZ6), {})));
        akCornersY[7] = (*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(void *)&(const ::NiPoint3 &)((*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(void *)&(const ::NiPoint3 &)((*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(kCenterZ))->FUN_00439ef0((::NiPoint3 *)&(kXY), *(const ::NiPoint3 *)nullptr)))))->FUN_00439ef0((::NiPoint3 *)&(kY_), *(const ::NiPoint3 *)nullptr)))))->FUN_00439ef0((::NiPoint3 *)&(kZ6), *(const ::NiPoint3 *)nullptr)));

        char aacFaces_2[8][4] = {{0, 1, 2, 4}, {3, 1, 2, 7}, {5, 1, 4, 7}, {6, 2, 4, 7}};
        NiPoint3 kKIntersect;
        for (int i = 0; i < 4; i++)
        {
            NiPoint3 kStart = akCornersY[aacFaces_2[i][0]];
            for (int j = 1; j < 4; j++)
            {
                NiPoint3 kEnd = akCornersY[aacFaces_2[i][j]];
                if (::FUN_004b1e80((const ::tagRECT *)(::CellRect *)(&kRectWork), &kStart, &kEnd, &kKIntersect))
                    return true;
            }
        }
    }
    return false;
}
