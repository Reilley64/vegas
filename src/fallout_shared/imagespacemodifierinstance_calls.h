// fallout_shared/imagespacemodifierinstance_calls.h: declares NiMemObjectAllocation, TESSound, BSAudio, TES
#ifndef FNV_IMAGESPACEMODIFIERINSTANCE_CALLS_H
#define FNV_IMAGESPACEMODIFIERINSTANCE_CALLS_H

#include <new>
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/ListReader.h"
#include "fnv/decl/TESObjectTREE.h"
#include "fnv/decl/Vec3.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_011de000.h"
#include "NiObject.h"
#include "TESForm.h"
class ImageSpaceModifierInstance;
class NiMemObjectAllocation
{
  public:
};
template <> class NiPointer<ImageSpaceModifierInstance>
{
  public:
    ImageSpaceModifierInstance* m_pObject;
    NiPointer(ImageSpaceModifierInstance* object);
    ~NiPointer();
    operator ImageSpaceModifierInstance*() const;
};
template <> class BSSimpleList<NiPointer<ImageSpaceModifierInstance> >
{
  public:
    NiPointer<ImageSpaceModifierInstance> m_item;
    BSSimpleList* m_pkNext;
    void AddTail(const NiPointer<ImageSpaceModifierInstance>& item);
};
class TESSound : public TESForm
{
};
class SoundPlaybackHandle
{
  public:
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    unsigned char padding[3];
    unsigned int eState;
    ~SoundPlaybackHandle();
};
class BSAudio
{
  public:
    SoundPlaybackHandle GetSoundHandleByFormID(unsigned int formID, unsigned int flags, bool assumeSuccess);
};
class TES
{
  public:
};
extern float DAT_0102d270;
extern float DAT_011c96fc;
#endif
