// bsmenu/font_types.h: declares NiRect_float_, ButtonIcon, Font, FontManager
#ifndef FNV_FONT_PRIVATE_TYPES_H
#define FNV_FONT_PRIVATE_TYPES_H

#include <stddef.h>
class FontData;
class NiTexturingProperty;
class NiTriShape;
struct NiPoint3;
struct RgbaColor;
class FontCharacterInfo;
#include "fnv/ni_pointer.h"
#include "fnv/bs_string.h"
template <class T, unsigned int Growth> class BSSimpleArray
{
  public:
    void** m_ppVirtualMethodTable;
    T* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
};
class NiRect_float_
{
  public:
    float m_fMinimumU;
    float m_fMaximumU;
    float m_fMinimumV;
    float m_fMaximumV;
};
class ButtonIcon
{
  public:
    float m_fGlyphWidthInPixels;
    float m_fHorizontalOffset;
    float m_fGlyphVerticalOffset;
    float m_fHorizontalSpacing;
    NiRect_float_ m_kTextureCoordinates;
};
class Font
{
  public:
    unsigned short BackgroundTask;
    char* m_pFile;
    int m_iFontNumber;
    NiPointer<NiTexturingProperty> m_kTextureSlots[8];
    float m_fLineHeight;
    float m_fDrop;
    int m_iOverlap;
    FontData* m_pFontData;
    BSStringT<char> m_kIconTexturePath;
    BSSimpleArray<ButtonIcon, 1024> m_kButtonIcons;
    static void MapCharacter(unsigned char& character);
    void AddCharacterToShape(FontCharacterInfo* letter, int index, NiTriShape* shape, NiPoint3& position,
                             const RgbaColor* color);
};
class FontManager
{
  public:
    Font* pFont[8];
    bool m_bUseNewFonts;
    static FontManager* pInstance;
    static FontManager* Instance();
    float GetFontPadding(int font);
};
typedef BSSimpleArray<ButtonIcon, 1024> FontButtonIconArray;
#endif
