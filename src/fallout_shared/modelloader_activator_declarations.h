// Declaration-only full xNVSE runtime representation, GameForms.h:1016-1022,1540-1549,2301-2325.
// Requires the reviewed ModelLoader form declarations. No bodies or globals.
#ifndef FNV_MODELLOADER_ACTIVATOR_DECLARATIONS_H
#define FNV_MODELLOADER_ACTIVATOR_DECLARATIONS_H
class TESWaterForm;
class BGSTalkingActivator;
class TESBoundAnimObject : public TESBoundObject
{
  public:
    TESBoundAnimObject();
    ~TESBoundAnimObject();
};
class BGSOpenCloseForm
{
  public:
    virtual void Unk_00(unsigned long arg0, unsigned long arg1);
    virtual void Unk_01(unsigned long arg0, unsigned long arg1);
    virtual bool Unk_02(void);
    BGSOpenCloseForm();
    ~BGSOpenCloseForm();
};
class TESSound;
class TESObjectACTI : public TESBoundAnimObject
{
  public:
    TESObjectACTI();
    ~TESObjectACTI();
    TESFullName fullName;
    TESModelTextureSwap modelTextureSwap;
    TESScriptableForm scriptable;
    BGSDestructibleObjectForm destructible;
    BGSOpenCloseForm openClose;
    TESSound* loopingSound;
    TESSound* activationSound;
    TESSound* radioTemplate;
    TESWaterForm* waterType;
    BGSTalkingActivator* radioStation;
    String activationPrompt;
    void SetActivateSound(TESSound* sound);
public:
    void SetLoopingSound(::TESSound *);
};
#endif
