// gamebryo2.2/corelibs/nianimation/niposdata_decls.h: declares AnimationKey, NiObject, NiPosData, NiBinaryStream, NiStream
#ifndef NIPOSDATA_DECLS_H
#define NIPOSDATA_DECLS_H

#include "NiAnimationKeyTables.h"
#include "fnv/symbols_011f3000.h"
struct NiStream;
class PositionKeyInterpolator;
class AnimationKey
{
  public:
    enum KeyType
    {
        NOINTERP,
        LINKEY,
        BEZKEY,
        TCBKEY,
        EULERKEY,
        STEPKEY,
        NUMKEYTYPES
    };
};
struct NiObject
{
  public:
    virtual void LoadBinary(NiStream&);
    unsigned int refs;
};
class NiPosData : public NiObject
{
  public:
    unsigned int m_uiNumKeys;
    PositionKeyInterpolator* m_pKeyArray;
    AnimationKey::KeyType m_eRequestType;
    unsigned char m_ucKeyDataSize;
    void SetColorKeys(PositionKeyInterpolator*, unsigned int, AnimationKey::KeyType);
    virtual void LoadBinary(NiStream&);
};
class NiBinaryStream
{
  public:
    void* vtable;
    unsigned int position;
    unsigned int (*read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* data, unsigned int bytes)
    {
        unsigned int size = 4;
        position += read(this, data, bytes, &size, 1);
    }
};
struct NiStream
{
  public:
    unsigned char padding[0x24c];
    NiBinaryStream* input;
    AnimationKey::KeyType ReadType()
    {
        unsigned int raw;
        input->Read(&raw, 4);
        return (AnimationKey::KeyType)raw;
    }
};
inline unsigned char GetPosKeySize(AnimationKey::KeyType type)
{
    return NiAnimationKeyTables::g_keySizes[NiAnimationKeyTables::Index(1, 0) + type];
}
typedef PositionKeyInterpolator* (*CreatePosKeys)(NiStream&, unsigned int);
typedef void (*FillPosKeys)(PositionKeyInterpolator*, unsigned int, unsigned char);
inline CreatePosKeys GetCreatePosKeys(AnimationKey::KeyType type)
{
    return NiAnimationKeyTables::Get<PositionKeyInterpolator *(*)(NiStream &, unsigned int)>(NiAnimationKeyTables::kAt011f3db0, NiAnimationKeyTables::Index(1, 0) + type);
}
inline FillPosKeys GetFillPosKeys(AnimationKey::KeyType type)
{
    return NiAnimationKeyTables::Get<void (*)(PositionKeyInterpolator*, unsigned int, unsigned char)>(NiAnimationKeyTables::kAt011f3780, NiAnimationKeyTables::Index(1, 0) + type);
}
#endif
