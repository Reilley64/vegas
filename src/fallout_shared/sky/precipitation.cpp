// fallout_shared/sky/precipitation.cpp: Precipitation, PrecipS (6 functions)

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/QueueHelper.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_00637890__ParticleMgr.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_01202000.h"
#include "precipitation_decls.h"
// @fnv 0x00636c40
void Precipitation::Load(const char* path)
{
    if (m_pPrecipitationNode)
    {
        pParent->RemoveObject(m_pPrecipitationNode);
        m_pPreviousNode = m_pPrecipitationNode;
        pParent->AddObject(m_pPreviousNode, true);
        m_pPrecipitationNode = 0;
    }
    if (path && *path)
    {
        NiNode* model = reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((g_modelLoader))->FUN_00447080((char *)(path), (*(int *)&(const ::ENUM_LOD_MULT &)(ENUM_LOD_MULT_Default)), true, false, false, false);
        if (model)
        {
            bool bIsSnow = FUN_00404dc0(path, DAT_0104ed9c) == 0;
            NiUpdateData kUpdateData(0.0f, false, false);
            model->UpdateDownwardPass(kUpdateData, 0);
            m_pPrecipitationNode = reinterpret_cast<NiNode*>(new NiSortAdjustNode(0));
            fEmissionRate = 0.0f;
            for (unsigned int index = 0; index < ((unsigned int)(reinterpret_cast<::FUN_00453470_shell *>((model))->FUN_00453470())); ++index)
            {
                NiAVObject* m_pShaderGeometry = model->GetAt(index)->vfn_000c();
                SkyShaderProperty* pShaderProperty =
                    m_pShaderGeometry ? ((::SkyShaderProperty *)(::FUN_00653270(&(*reinterpret_cast<const ::NiRTTI *>(&::g_012024e0)), (::NiObject *)(::NiProperty *)(((::NiProperty *)(reinterpret_cast<::S_FUN_0045bc00 *>((m_pShaderGeometry))->FUN_0045bc00(false))))))) : 0;
                if (!pShaderProperty)
                    continue;
                NiAVObject* precipParticle = ((::NiAVObject *)(reinterpret_cast<::fnv_00637890::ParticleMgr *>(this)->CreateParticleShape((::fnv_00637890::Obj *)(pShaderProperty), (int)(((::NiAVObject *)(::FUN_00461130((int)(pParent))))), {})));
                if (precipParticle)
                    static_cast<NiNode*>(m_pPrecipitationNode)->AddObject(precipParticle, true);
            }
            pParent->AddObject(m_pPrecipitationNode, true);
            reinterpret_cast<::FUN_00a5a040_Class *>((static_cast<NiNode*>(m_pPrecipitationNode)))->FUN_00a5a040();
        }
    }
}

struct FUN_00636bb0_shell
{
    void FUN_00636bb0();
};

NiAVObject* __cdecl FUN_0054f4f0(void);

// @fnv 0x00636bb0
void FUN_00636bb0_shell::FUN_00636bb0()
{
    *(NiAVObject**)((char*)this + 0xc) = FUN_0054f4f0();
}

struct NodeS
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void RemoveChild(void*);
};
struct Flt
{
    void* p;
    operator unsigned int() const;
};
struct NP : Flt
{
    NP& operator=(void*);
};
struct PrecipS
{
    char pad[4];
    NP m_pPrecipitationNode;
    NP m_pPreviousNode;
    NodeS* pParent;
    void RemoveChildren();
};
// @fnv 0x00637800
void PrecipS::RemoveChildren()
{
    if (m_pPreviousNode.Flt::operator unsigned int())
    {
        pParent->RemoveChild((void*)m_pPreviousNode.Flt::operator unsigned int());
        m_pPreviousNode.NP::operator=(0);
    }
    if (m_pPrecipitationNode.Flt::operator unsigned int())
    {
        pParent->RemoveChild((void*)m_pPrecipitationNode.Flt::operator unsigned int());
        m_pPrecipitationNode.NP::operator=(0);
    }
}

struct Cls636af0
{
    void FUN_00636b20();
    void* DestroyIfFlagged(unsigned int);
};
struct PrecipQueuedObject
{
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void* vfn_0014(int a0, int a1, int a2, int a3, int a4, int a5);

    int FUN_0048cee0();
};

struct PrecipPointerHelper
{
};

struct PrecipManager
{
};


struct FUN_00636bd0_cls
{
    void** m_ppVirtualMethodTable;
    void* m_pPrecipitationNode;
    void* m_pPreviousNode;
    void* pParent;
    float fEmissionRate;
    const void* m_pPrecipitationData;

    void QueuePrecipitationObject(PrecipQueuedObject* object);
};

// @fnv 0x00636bd0
void FUN_00636bd0_cls::QueuePrecipitationObject(PrecipQueuedObject* object)
{
    if (::FUN_00559450((int *)(((PrecipPointerHelper*)&m_pPreviousNode))))
        return;

    if (object != 0 && object->FUN_0048cee0() != 0)
    {
        reinterpret_cast<::QueueHelper *>(((*reinterpret_cast<::PrecipManager * *>(&::g_modelLoader))))->FUN_00444040((int)(object->vfn_0014(0, 0, 0, 0, 0, 0)), {}, {}, {}, {}, {}, {});
        m_pPrecipitationData = object;
    }
    else
        reinterpret_cast<::Precipitation *>(this)->Load((const char *)(void *)(0));
}

// Destructor: release both handles and clear the cached pointer before the handle members are destroyed.

class B20Handle
{
  public:
    ~B20Handle();
    void Reset(void* pvObject);

    void* m_pvObject;
};

class FUN_00636b20
{
  public:
    virtual ~FUN_00636b20();

    B20Handle m_kFirst;
    B20Handle m_kSecond;
    int unk0C;
    int unk10;
    void* m_pvCached;
};
// Calls FUN_00636b20, then deallocates this if flags has bit 1 set, and returns this.
// @fnv 0x00636af0
void* Cls636af0::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00636b20 *>(this)->FUN_00636b20::~FUN_00636b20();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Resets both B20Handle members to null and clears m_pvCached.
// @fnv 0x00636b20
FUN_00636b20::~FUN_00636b20()
{
    m_kFirst.Reset(0);
    m_kSecond.Reset(0);
    m_pvCached = 0;
}

int FUN_00404dc0(const char*, const char*);

#include "generated/data/fallout_shared/sky/precipitation.inc"
