// fallout_shared/sky/clouds.cpp: Clouds (10 functions)

#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/F940Owner.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_004536e0_Class.h"
#include "fnv/decl/FUN_00476c90_Class.h"
#include "fnv/decl/FUN_0050d100_shell.h"
#include "fnv/decl/FUN_0051b8c0_shell.h"
#include "fnv/decl/FUN_006347a0_Class.h"
#include "fnv/decl/FUN_006347c0_Class.h"
#include "fnv/decl/FUN_00634830_cls.h"
#include "fnv/decl/FUN_00634850_Class.h"
#include "fnv/decl/FUN_00634930_cls.h"
#include "fnv/decl/FUN_008d0600_s.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00bae930_Class.h"
#include "fnv/decl/FUN_00c3a8a0_cls.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/fnv_00633d90__FUN_00633d90_Class.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00644000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_011cc000.h"
#include "fnv/symbols_01200000.h"
#include "clouds_decls.h"

// Loads Clouds.nif, attaches its 3D to parent, adds each geometry child to the cloud node, and sets the layer count.
// @fnv 0x00633ed0
void Clouds::Initialize(NiNode* parent)
{
    reinterpret_cast<::F940Owner *>(this)->CreateSortAdjustNode((::F940Parent *)(parent));
    BSStream stream;
    if (reinterpret_cast<::FUN_00c3a8a0_cls *>(&(stream))->FUN_00c3a8a0((std::uintptr_t)("Meshes\\Sky\\Clouds.nif"), false))
    {
        Model kModel("Meshes\\Sky\\Clouds.nif", &stream, false, false);
        struct LayerBuild
        {
            int layers;
            NiNode* root;
            int children;
        } build;
        build.root = ((::NiNode *)(::fnv_0043b230::FUN_0043b230((const char *)&(kModel))));
        parent->AddObject(m_pRootNode, true);
        build.layers = 0;
        build.children = reinterpret_cast<::FUN_00453470_shell *>((build.root))->FUN_00453470();
        for (int i = 0; i < build.children; ++i)
        {
            if (build.root->GetAt(i)->vfn_18())
            {
                m_pCloudLayerGeometry[i] = (NiGeometry*)build.root->GetAt(i);
                m_pRootNode->AddObject(m_pCloudLayerGeometry[i], true);
                ++build.layers;
            }
        }
        SetCloudCount(build.layers);
    }
}

// @fnv 0x006340e0
void Clouds::SetCloudCount(int count)
{
    if (count > 4)
        count = 4;
    m_usCloudCount = (unsigned short)count;
}

struct FUN_00634870_shell : public Sky
{
    bool FUN_00634870();
};

// @fnv 0x00634870
bool FUN_00634870_shell::FUN_00634870()
{
    return (0 < (*(unsigned int*)((char*)this + 0x118) & 3));
}

struct FUN_00634890_shell : public Sky
{
    SkyTextureManager* GetTextureManager();
};

// @fnv 0x00634890
SkyTextureManager* FUN_00634890_shell::GetTextureManager()
{
    return reinterpret_cast<SkyTextureManager*>(reinterpret_cast<char*>(this) + 0x114);
}

struct FUN_00634900_shell : public SkyShaderProperty
{
    void FUN_00634900(void*);
};

struct NiFixedString_access : public NiFixedString
{
    operator char const*() const;
};

// Assigns the NiFixedString at aFilename to the BSStringT<char> at offset 0x74 of this shader property.
// @fnv 0x00634900
void FUN_00634900_shell::FUN_00634900(void* aFilename)
{
    *(BSStringT<char>*)((char*)this + 0x74) = *(const NiFixedString_access*)aFilename;
}

class NiTexture;
struct FUN_009c8680_shell : public SkyShaderProperty
{
    NiTexture* FUN_009c8680();
};
// @fnv 0x00634110
void Clouds::Update(Sky* sky, float time)
{
    reinterpret_cast<::FUN_008d0600_s *>(this)->FUN_008d0600((std::intptr_t)(sky), time);
    TESWeather* m_pWeatherObject = ((::TESWeather *)(reinterpret_cast<::MagicCaster_shell *>((sky))->FUN_0044edb0()));
    TESWeather* m_pPreviousWeather = ((::TESWeather *)(std::uintptr_t)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((sky))->FUN_00825c00()));
    if (!m_pWeatherObject)
        return;
    for (int i = 0; i < ((int)(reinterpret_cast<::FUN_00634830_cls *>(this)->GetOffset58())); ++i)
        if (!m_pCloudLayerGeometry[i])
            return;
    if (((int)(reinterpret_cast<::FUN_00476c90_Class *>((sky))->FUN_00476c90())) == 3 || ((int)(reinterpret_cast<::FUN_00476c90_Class *>((sky))->FUN_00476c90())) == 2)
    {
        for (int i = 0; i < ((int)(reinterpret_cast<::FUN_00634830_cls *>(this)->GetOffset58())); ++i)
        {
            float speed;
            float delta;
            CloudsColorController* controller =
                (!((::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)(((::NiObjectNET *)(reinterpret_cast<::FUN_0050d100_shell *>(((m_pCloudLayerGeometry[i]).operator->()))->FUN_0050d100()))))))
                     ? false
                     : ((int)(reinterpret_cast<::BGSTerrainManager *>((((::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)(((::NiObjectNET *)(reinterpret_cast<::FUN_0050d100_shell *>(((m_pCloudLayerGeometry[i]).operator->()))->FUN_0050d100()))))))))->GetMinLevel())) == 13)
                    ? (CloudsColorController*)((::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)(((::NiObjectNET *)(reinterpret_cast<::FUN_0050d100_shell *>(((m_pCloudLayerGeometry[i]).operator->()))->FUN_0050d100()))))))
                    : 0;
            if (controller)
            {
                NiColor color = (*(::NiColor *)(reinterpret_cast<::FUN_00634850_Class *>(this)->GetPointAt(i)));
                controller->color = RgbaColor(color.r, color.g, color.b, 1.0f);
            }
            speed = reinterpret_cast<::FUN_006347c0_Class *>((m_pWeatherObject))->InterpolateByIndex(i, ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting60))))))->f, 0.0f);
            if (m_pPreviousWeather)
            {
                speed *= ::FUN_006447d0((const char *)(sky));
                speed += (1.0f - ::FUN_006447d0((const char *)(sky))) *
                         reinterpret_cast<::FUN_006347c0_Class *>((m_pPreviousWeather))->InterpolateByIndex(i, ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting60))))))->f, 0.0f);
            }
            delta = reinterpret_cast<::FUN_004536e0_Class *>((sky))->GetFieldCC() * time * speed;
            AddToFloatArray((unsigned short)i, delta);
        }
    }
    if (reinterpret_cast<::FUN_00634870_shell *>((sky))->FUN_00634870() || bForceUpdate)
    {
        bForceUpdate = false;
        if (m_pPreviousWeather)
        {
            for (int i = 0; i < ((int)(reinterpret_cast<::FUN_00634830_cls *>(this)->GetOffset58())); ++i)
            {
                BSStringT<char> path;
                SkyShaderProperty* property = (SkyShaderProperty*)((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>(((m_pCloudLayerGeometry[i]).operator->()))->FUN_00a59d30(3)));
                TESTexture1024* pkTexture = ((::TESTexture1024 *)(reinterpret_cast<::FUN_006347a0_Class *>((m_pWeatherObject))->FUN_006347a0(i)));
                if (pkTexture && pkTexture->GetModelLength())
                {
                    path = pkTexture->vfn_18();
                    path += ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((pkTexture))->FUN_00408da0()));
                    reinterpret_cast<::FUN_00634890_shell *>((sky))->GetTextureManager();
                    SkyTextureManager::LoadTextureFromPath(&m_pCloudLayerTexture[i], path);
                }
                else
                    m_pCloudLayerTexture[i] = 0;
            }
        }
        else if (((int)(reinterpret_cast<::FUN_00476c90_Class *>((sky))->FUN_00476c90())) == 3 || ((int)(reinterpret_cast<::FUN_00476c90_Class *>((sky))->FUN_00476c90())) == 2)
        {
            for (int i = 0; i < ((int)(reinterpret_cast<::FUN_00634830_cls *>(this)->GetOffset58())); ++i)
            {
                BSStringT<char> path;
                SkyShaderProperty* property = (SkyShaderProperty*)((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>(((m_pCloudLayerGeometry[i]).operator->()))->FUN_00a59d30(3)));
                TESTexture1024* pkTexture = ((::TESTexture1024 *)(reinterpret_cast<::FUN_006347a0_Class *>((m_pWeatherObject))->FUN_006347a0(i)));
                if (pkTexture && pkTexture->GetModelLength())
                {
                    path = pkTexture->vfn_18();
                    path += ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((pkTexture))->FUN_00408da0()));
                    NiPointer<NiTexture> loaded = 0;
                    BSShaderManager::GetTexture(path, true, loaded, true, false);
                    NiTexture* raw = loaded;
                    if (raw)
                    {
                        property->SetTexture(raw);
                        reinterpret_cast<::FUN_00634900_shell *>((property))->FUN_00634900((void *)&(const ::NiFixedString &)(NiFixedString(path)));
                        reinterpret_cast<::FUN_0051b8c0_shell *>((property))->FUN_0051b8c0(0.0f);
                    }
                }
            }
        }
    }
    for (int i = 0; i < ((int)(reinterpret_cast<::FUN_00634830_cls *>(this)->GetOffset58())); ++i)
    {
        SkyShaderProperty* property;
        NiProperty* baseProperty = ((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>(((m_pCloudLayerGeometry[i]).operator->()))->FUN_00a59d30(3)));
        property = ((::SkyShaderProperty *)(::FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_012005b8)), (::NiObject *)(baseProperty))));
        if (m_pCloudLayerTexture[i])
        {
            if (property)
            {
                reinterpret_cast<::FUN_00bae930_Class *>((property))->FUN_00bae930((::RefCounted *)(::NiTexture *)(m_pCloudLayerTexture[i]));
                reinterpret_cast<::FUN_0051b8c0_shell *>((property))->FUN_0051b8c0(::FUN_006447d0((const char *)(sky)));
            }
            if (!m_pPreviousWeather)
            {
                property->SetTexture(m_pCloudLayerTexture[i]);
                m_pCloudLayerTexture[i] = 0;
                reinterpret_cast<::FUN_00bae930_Class *>((property))->FUN_00bae930((::RefCounted *)(::NiTexture *)(0));
                reinterpret_cast<::FUN_0051b8c0_shell *>((property))->FUN_0051b8c0(0.0f);
            }
        }
        reinterpret_cast<::TaskQueueInterface *>(((m_pCloudLayerGeometry[i]).operator->()))->QueueActorDisarm(!property || !reinterpret_cast<::FUN_009c8680_shell *>((property))->FUN_009c8680());
    }
}

// @fnv 0x009c8680
NiTexture* FUN_009c8680_shell::FUN_009c8680()
{
    return (NiTexture*)((BSStringT<char>*)((char*)this + 0x70))->operator const char*();
}

struct P3
{
};

struct FUN_00633e00
{
    P3 m;
    void Init();
};

// Initializes the object's m member by setting it to (0, 0, 0).
// @fnv 0x00633e00
void FUN_00633e00::Init()
{
    reinterpret_cast<::FUN_00416870_t *>(&(m))->FUN_00416870(0.0f, 0.0f, 0.0f);
}

struct S_00633dd0
{
    void FUN_00633e30();
    void* DestroyIfFlagged(unsigned int);
};
struct SkyObjectBase633e30
{
    virtual void Slot00();
    NiNode* m_pTreeNode;
    ~SkyObjectBase633e30();
};

struct FUN_00633e30 : SkyObjectBase633e30
{
    NiPointer<NiGeometry> m_clouds[4];
    NiPointer<NiTexture> m_transitionTextures[4];
    ~FUN_00633e30();
};
// Calls FUN_00633e30, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00633dd0
void* S_00633dd0::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00633e30 *>(this)->FUN_00633e30::~FUN_00633e30();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor that calls FUN_00633d90 and FUN_00634930 before returning.
// @fnv 0x00633e30
FUN_00633e30::~FUN_00633e30()
{
    reinterpret_cast<::fnv_00633d90::FUN_00633d90_Class *>(this)->FUN_00633d90();
    reinterpret_cast<::FUN_00634930_cls *>(this)->FUN_00634930();
}
