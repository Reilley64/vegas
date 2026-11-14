// fallout/interface/interface_rebase_PC_NiAVObject.h: declares BSMemObject, NiTransform, NiAVObject
#ifndef FNV_INTERFACE_REBASE_IFNV_EARLY_FOLDED_PC_NIAVOBJECT_DECLARATION_H
#define FNV_INTERFACE_REBASE_IFNV_EARLY_FOLDED_PC_NIAVOBJECT_DECLARATION_H
#include "fnv/decl/TaskQueueInterface.h"
#include "interface_rebase_NiObjectNET.h"
#include "interface_rebase_NiPoint3.h"
#include "interface_rebase_NiProperty.h"
class NiCullingProcess;
class NiNode;
class NiCamera;
class NiCollisionObject;
class NiPropertyState;
struct NiRenderer;
class NiDynamicEffectState;
struct NiUpdateData;
class FourComponentFloatVector;
class BSMemObject
{
};
struct ThreeByThreeMatrix : public BSMemObject
{
  public:
    float m_afEntries[3][3];
};
class NiTransform
{
  public:
    ThreeByThreeMatrix m_kRotate;
    NiPoint3 m_kTranslate;
    float m_fScale;
};
template <class T> class NiTPointerList : public NiTPointerListBase<NiTPointerAllocator<unsigned int>, T>
{
};
class NiAVObject : public NiObjectNET
{
  public:
    virtual ~NiAVObject();
    virtual void UpdateControllers(NiUpdateData& arData);
    virtual void ApplyTransform(const ThreeByThreeMatrix& arRotation, const NiPoint3& arPosition, bool abOnLeft);
    virtual void SetMaterialNeedsUpdate(bool abNeedsUpdate);
    virtual void SetDefaultMaterialNeedsUpdateFlag(bool abNeedsUpdate);
    virtual NiAVObject* GetObjectByName(const NiFixedString& arName) const;
    virtual void SetSelectiveUpdateFlags(bool& arSelectiveUpdate, bool abSelectiveUpdateTransforms, bool& arRigid);
    virtual void UpdateDownwardPass(NiUpdateData& arData, unsigned int auiFlags);
    virtual void UpdateSelectedDownwardPass(NiUpdateData& arData, unsigned int auiFlags);
    virtual void UpdateRigidDownwardPass(NiUpdateData& arData, unsigned int auiFlags);
    virtual void UpdatePropertiesDownwardPass(NiPropertyState* apParentState);
    virtual void UpdateEffectsDownward(NiDynamicEffectState* apEffectState);
    virtual void UpdateWorldData(NiUpdateData& arData);
    virtual void UpdateWorldBound();
    virtual void UpdateTransformAndBounds(NiUpdateData& arData);
    virtual void PreAttachUpdate(NiNode* apEventualParent, NiUpdateData& arData);
    virtual void PreAttachUpdateProperties(NiNode* apEventualParent);
    virtual void FinalizeAttachUpdate(NiNode* apEventualParent);
    virtual void CompleteAttachUpdate();
    virtual void OnVisible(NiCullingProcess& arCuller);
    virtual void PurgeRendererData(NiRenderer* apRenderer);
    NiNode* m_pParentNode;
    NiPointer<NiCollisionObject> m_spCollisionObject;
    FourComponentFloatVector* m_kWorldBound;
    NiTPointerList<NiPointer<NiProperty> > SceneGraphObject;
    unsigned int m_uiObjectFlags;
    NiTransform m_kLocalTransform;
    NiTransform m_kWorldSpaceTransform;
};
#endif
