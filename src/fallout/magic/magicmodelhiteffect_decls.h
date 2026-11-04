// fallout/magic/magicmodelhiteffect_decls.h: declares NiAVObject, NiObjectNET, EffectSetting, TimeGlobal, PlayerCharacter and more
#ifndef FNV_MAGICMODELHITEFFECT_DECLS_H
#define FNV_MAGICMODELHITEFFECT_DECLS_H

#include "fnv/decl/FUN_00445300_shell.h"
#include "fnv/decl/FUN_004eaf60_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_0047a520__Fn47a520.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_00a328b0__SeqExt.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_0081e000.h"
#include "fnv/symbols_00c4b000.h"
#include "fnv/symbols_0103b000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f6000.h"
#include "layout_support.h"
#include "magichiteffect_classes.h"
struct NiRTTI;
class NiProperty;
class SkyShaderProperty;
class NiTimeController;
class NiControllerSequence;
class NiNode;
class NiUpdateData;
struct NiPoint3;
class NiAVObject
{
  public:
    void Update(NiUpdateData&);
public:
    ::NiPoint3 &FUN_0043c490();
};
class NiObjectNET
{
  public:
};
class EffectSetting
{
  public:
};
class EffectSetting;
class ActiveEffect
{
  public:
public:
    ::EffectSetting *GetEffectSetting() const;
};
class TimeGlobal
{
  public:
};
class PlayerCharacter
{
  public:
};
class NiFixedString
{
  public:
    const char* m_kHandle;
    NiFixedString(const char*);
    ~NiFixedString();
};
class NiUpdateData
{
  public:
    float time;
    unsigned int flags;
    void* data;
    NiUpdateData(float, bool, bool);
};
// NiControllerSequence: PC vftable 36 slots = NiObject's 35 + Deactivate (v8C). The NiObject slots v08..v88 are
// declared here for the same reason as in magichiteffect_classes.h (canonical NiObject.h lacks them).
class NiControllerSequence : public NiObject
{
  public:
    virtual const NiRTTI* GetRTTI();                                     // v08
    virtual NiNode* IsSceneNode();                                       // v0C
    virtual BSFadeNode* IsFadeNode();                                    // v10
    virtual BSMultiBoundNode* IsMultiBoundNode();                        // v14
    virtual NiGeometry* IsGeometry();                                    // v18
    virtual NiTriBasedGeom* IsTriBasedGeom();                            // v1C
    virtual NiTriStrips* IsTriStrips();                                  // v20
    virtual NiTriShape* IsTriShape();                                    // v24
    virtual BSSegmentedTriShape* IsSegmentedTriShape();                  // v28
    virtual BSResizableTriShape* IsResizableTriShape();                  // v2C
    virtual NiParticles* IsParticlesGeom();                              // v30
    virtual NiLines* IsLineGeometry();                                   // v34
    virtual bhkNiCollisionObject* IsBhkNiCollisionObject();              // v38
    virtual bhkBlendCollisionObject* IsBhkBlendCollisionObject();        // v3C
    virtual bhkRigidBody* IsBhkRigidBody();                              // v40
    virtual bhkLimitedHingeConstraint* IsBhkLimitedHingeConstraint();    // v44
    virtual NiObject* MakeClone(CloningProcess& arCloning);              // v48
    virtual void LoadBinary(NiStream& arStream);                         // v4C
    virtual void LinkObject(NiStream& arStream);                         // v50
    virtual bool RegisterStreamables(NiStream& arStream);                // v54
    virtual void SaveBinary(NiStream& arStream);                         // v58
    virtual bool IsEqual(NiObject* apObject);                            // v5C
    virtual void GetViewerStrings(NiTPrimitiveArray<char*>* apStrings);  // v60
    virtual void AddViewerStrings(NiTPrimitiveArray<char*>* apStrings);  // v64
    virtual void ProcessClone(CloningProcess& arCloning);                // v68
    virtual void PostLinkObject(NiStream& arStream);                     // v6C
    virtual bool StreamCanSkip();                                        // v70
    virtual const NiRTTI* GetStreamableRTTI();                           // v74
    virtual void SetObjectBound(FourComponentFloatVector* apBound);      // v78
    virtual unsigned int GetBlockAllocationSize();                       // v7C
    virtual NiObjectGroup* GetGroup();                                   // v80
    virtual void SetGroup(NiObjectGroup* apGroup);                       // v84
    virtual NiControllerManager* IsNiControllerManager();                // v88
    virtual bool Deactivate(float afEaseOutTime, bool abTransition);     // v8C
};
class NiControllerManager
{
  public:
    void DeactivateAllSequences(float);
    bool ActivateControllerSequence(NiControllerSequence*, int, bool, float, float, NiControllerSequence*);
};
class ModelLoader
{
  public:
};
template <> class NiPointer<NiAVObject>
{
  public:
    NiAVObject* m_pObject;
    NiPointer<NiAVObject>& operator=(NiAVObject*);
};
template <> class NiPointer<NiNode>
{
  public:
    NiNode* m_pObject;
    NiNode* operator->() const;
};
#endif
