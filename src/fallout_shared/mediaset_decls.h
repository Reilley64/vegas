// fallout_shared/mediaset_decls.h: declares TESFullName, TESFormInitFlag, TESBoundObject, TESSound, MediaLocationController and more
#ifndef FNV_MEDIASET_DECLS_H
#define FNV_MEDIASET_DECLS_H


#include "fnv/decl/FUN_00598020_Class.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00597000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00830000.h"
#include "layout_support.h"
#include "mediaset_form.h"
// Unit-local full-name declaration includes its external lifetime methods.
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> m_kName;
    TESFullName();
    ~TESFullName();
};

class TESFormInitFlag : public TESForm
{
  public:
};

class TESBoundObject : public TESForm
{
};

class TESSound : public TESBoundObject
{
};

class MediaLocationController
{
  public:
};
class TESObjectREFR
{
  public:
    float GetScale();
};
template <class T> class NiPointer
{
  public:
    T* operator->() const;
};
enum MEDIATYPE
{
    MEDIA_INCIDENTAL = 2
};
class FalloutAudioMedia
{
  public:
    static void FadeOutMedia(int, MEDIATYPE);
    static void EndMediaUpdate();
};
extern unsigned int DAT_011dd37c;

class MediaSet : public TESForm, public TESFullName
{
  public:
    class MediaSetEntry
    {
      public:
        BSStringT<char> Name;
        float Attenuation;
        float Percent;
        MediaSetEntry();
        ~MediaSetEntry();
    };

    enum MEDIASETTYPE
    {
        BATTLE = 0,
        LAYER_LOCATION = 1,
        LAYER_DUNGEON = 2,
        INCIDENTAL = 3,
        SETTYPE_COUNT = 4
    };

    unsigned int m_uiMediaValue1;
    unsigned int m_uiMediaValue2;
    unsigned int m_uiMediaValue3;
    bool bEffectFlag;
    bool m_bActorStateFlag;
    bool m_bCountWasNonzero;
    bool m_bConditionWasTrue;
    char m_cMediaState;
    TESFullName m_kFullName;
    MEDIASETTYPE Type;
    MediaSetEntry m_kMediaSetEntry1;
    MediaSetEntry m_kMediaSetEntry2;
    MediaSetEntry m_kMediaSetEntry3;
    MediaSetEntry m_kMediaSetEntry4;
    MediaSetEntry m_kMediaSetEntry5;
    MediaSetEntry m_kMediaSetEntry6;
    char m_cMediaFlag;
    float m_fMediaParameter1;
    float fSkillValueBonus;
    float m_fMediaParameter3;
    float m_fMediaValue;
    TESSound* m_pSound1;
    TESSound* m_pSound2;

    virtual void InitItem();
    MediaSet();
    void ClearData();
    void ResetFormData();
    bool UpdateLayerLocation(unsigned int, bool, MediaLocationController*);
    bool UpdateBattleState(bool, unsigned int, int);
    bool Update(unsigned int auiTime, bool abForce, MediaLocationController* apController);
};


extern unsigned int DAT_011ca9fc;


#endif
