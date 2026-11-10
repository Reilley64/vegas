// fallout/ai/processlists_private/processlists_TESObject.h: declares TESObject
#ifndef PROCESSLISTS_PRIVATE_TESOBJECT_H
#define PROCESSLISTS_PRIVATE_TESOBJECT_H

#include "processlists_TESForm.h"
class NiAVObject;
struct TESWaterForm;
class TESFormList;
class BipedAnim;
class TESObject : public TESForm
{
  public:
    TESObject();
    virtual ~TESObject();
    virtual NiAVObject* GetModel3D();
    virtual bool IsBoundAnimObject() const;
    virtual TESWaterForm* GetAssociatedWaterForm() const;
    virtual bool IsAutoCalculated() const;
    virtual void SetPlayable(bool value);
    virtual NiNode* Get3DObject(TESObjectREFR* requester, bool abFirstPerson);
    virtual void Destroy3DModel(TESObjectREFR* requester);
    virtual bool HasLoaded3D() const;
    virtual bool IsModelValid() const;
    virtual void UpdateModel3D();
    virtual bool IsBoundItem();
    virtual bool ReplaceModelBip(BipedAnim* biped);
    virtual void Set3D(NiAVObject* object, bool debugPrint);
    virtual unsigned int AcquireReference();
    virtual unsigned int DecRef();
    virtual NiNode* Create3DForReference(TESObjectREFR* reference);
    TESFormList* pList;
    TESObject* pPrev;
    TESObject* pNext;
};
#endif
