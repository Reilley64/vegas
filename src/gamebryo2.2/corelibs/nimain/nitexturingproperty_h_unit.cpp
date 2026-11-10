// gamebryo2.2/corelibs/nimain/nitexturingproperty_h_unit.cpp: NiTexturingProperty, AudioLoadTask (1 function)

#include "fnv/decl/S_0060af60.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
class NiTexture;

template <class T> class NiPointer
{
  public:
    T* m_pObject;
};

template <class T> class NiTArray
{
  public:
    T& GetAt(unsigned int index) const;
    void SetAt(unsigned int index, const T& value);
};

class NiTexturingProperty
{
  public:
    enum FilterMode
    {
        FILTERMODE_DEFAULT = 0
    };

    enum ClampMode
    {
        CLAMPMODE_DEFAULT = 0
    };

    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    NiTArray<NiPointer<NiTexture> > m_kTextureSwapList;

    void SetBaseMapFilterMode(FilterMode mode);
    void SetBaseMapClampMode(ClampMode mode);
};

class NiTexture
{
  public:
    virtual void UnkVirtual();

    int unk04;
    int unk08;
    int unk0c;

    typedef NiTexturingProperty::FilterMode FilterMode;
    typedef NiTexturingProperty::ClampMode ClampMode;

    NiTexture();
    void SetClampMode(ClampMode mode);
};

void NiTexturingProperty::SetBaseMapFilterMode(FilterMode mode)
{
    NiPointer<NiTexture> baseTexture;
    baseTexture = m_kTextureSwapList.GetAt(0);

    if (baseTexture.m_pObject == 0)
    {
        baseTexture.m_pObject = new NiTexture;
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(&(m_kTextureSwapList))->SetAt(0, (char *&)(baseTexture));
    }

    reinterpret_cast<::S_0060af60 *>((baseTexture.m_pObject))->FUN_0060af60((*(unsigned short *)&(mode)));
}

void NiTexturingProperty::SetBaseMapClampMode(ClampMode mode)
{
    NiPointer<NiTexture> baseTexture;
    baseTexture = m_kTextureSwapList.GetAt(0);

    if (baseTexture.m_pObject == 0)
    {
        baseTexture.m_pObject = new NiTexture;
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(&(m_kTextureSwapList))->SetAt(0, (char *&)(baseTexture));
    }

    baseTexture.m_pObject->SetClampMode(mode);
}

class AudioLoadTask
{
  public:
    unsigned char GetFileIndex();
};

// @fnv 0x00ae8b80
unsigned char AudioLoadTask::GetFileIndex()
{
    return 2;
}
