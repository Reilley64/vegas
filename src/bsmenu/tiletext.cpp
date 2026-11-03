// bsmenu/tiletext.cpp: TileText, FontManager, TextNode, TextTile (4 functions)

#include <cstring>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_009ff600_shell.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a074d0_shell.h"
#include "fnv/decl/FUN_00a07530_shell.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00a5bca0_shell.h"
#include "fnv/decl/Interface.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/TileX.h"
#include "fnv/decl/fnv_005bd5c0__FUN_005bd5c0_shell.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a12880__FontRenderer.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00707000.h"
#include "fnv/symbols_00a30000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01095000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011f3000.h"
#include "tiletext.h"

// @fnv 0x00a0bbd0
int TileText::GetType()
{
    return eText;
}

struct FUN_00a21a10_shell : public TileText
{
    void InitTileText(Tile*, char*, Tile*);
};

struct TileHelper
{
};

// @fnv 0x00a21a10
void FUN_00a21a10_shell::InitTileText(Tile* apParent, char* apName, Tile* apReplacedTile)
{
    reinterpret_cast<::FUN_009ff600_shell *>((((TileHelper*)this)))->InitTile(apParent, (char *)(apName), apReplacedTile);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((TileHelper*)this)))->FUN_00a01350(0xfc4, (char *)(""), true);
    reinterpret_cast<::FUN_00a012d0_t *>((((TileHelper*)this)))->FUN_00a012d0(0xff5, 255.0f, true);
    reinterpret_cast<::FUN_00a012d0_t *>((((TileHelper*)this)))->FUN_00a012d0(0xfb2, 255.0f, true);
    reinterpret_cast<::FUN_00a012d0_t *>((((TileHelper*)this)))->FUN_00a012d0(0xfb3, 255.0f, true);
    reinterpret_cast<::FUN_00a012d0_t *>((((TileHelper*)this)))->FUN_00a012d0(0xfb4, 255.0f, true);
    reinterpret_cast<::FUN_00a012d0_t *>((((TileHelper*)this)))->FUN_00a012d0(0xfa9, 255.0f, true);
    reinterpret_cast<::FUN_00a012d0_t *>((((TileHelper*)this)))->FUN_00a012d0(0xfa3, 1.0f, true);
    reinterpret_cast<::FUN_00a074d0_shell *>((((TileHelper*)this)))->FUN_00a074d0(3);
}

struct FUN_00a225b0_shell : public TileText
{
    Tile* FUN_00a225b0(int, float, char*);
};

struct FUN_00a011f0_shell : public Tile
{
    char* FUN_00a011f0(int);
};
struct TGF
{
};
struct TAN
{
};
// @fnv 0x00a225b0
Tile* FUN_00a225b0_shell::FUN_00a225b0(int aiTrait, float afValue, char* axString)
{
    if (aiTrait == 0xfc4)
    {
        char* strValue = ((FUN_00a011f0_shell*)this)->FUN_00a011f0(0xfc4);
        if (!strValue || (strValue && !std::strcmp(axString, strValue)))
        {
            reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)this)))->FUN_00a07530(2);
            return (Tile*)(void*)this;
        }
    }
    else if (aiTrait == 0xfb7)
    {
        if (reinterpret_cast<::TileListBoxCalls *>((((TGF*)this)))->GetFloat(0xfb7) != afValue)
        {
            reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)this)))->FUN_00a07530(2);
            return (Tile*)(void*)this;
        }
    }
    return 0;
}






struct TextString
{

    char* text;
    unsigned short length, capacity;

    TextString(const char*);
    TextString(const TextString&);

    __forceinline void SetLength(unsigned n)
    {
        length = n <= 65535u ? (unsigned short)n : 65535u;
    }

    __forceinline void SetCapacity(unsigned n)
    {
        capacity = n <= 65535u ? (unsigned short)n : 65535u;
    }

    __forceinline TextString()
    {
        text = 0;
        SetLength(0);
        SetCapacity(0);
    }

    unsigned MaxLength()
    {
        return capacity;
    }

    bool Set(const char*, unsigned);

    ~TextString()
    {
        Set(0, 0);
    }
public:
    bool FUN_004037f0(const char *, unsigned int);
};

struct Color4
{
    float r, g, b, a;
    Color4()
    {
        r = 0.0f;
        g = 0.0f;
        b = 0.0f;
        a = 0.0f;
    }
    Color4(float alpha)
    {
        r = 1.0f;
        g = 1.0f;
        b = 1.0f;
        a = alpha;
    }
    Color4(const float& red, const float& green, const float& blue, float alpha)
    {
        r = red;
        g = green;
        b = blue;
        a = alpha;
    }
};


struct TextParams
{

    int font, alignment;
    Color4 color;
    unsigned char flags;

    int width, height, lines, maxLines, lineCount, unknown;

    bool multibyte;

    TextString text;

    __forceinline TextParams(Color4 initialColor = Color4(DAT_01095268, DAT_01095264, DAT_01095260, 1.0f))
        : color(), text()
    {

        font = 0;
        alignment = 1;
        (void)Color4(initialColor);
        flags = 10;
        width = 0x7fffffff;
        height = 0x7fffffff;
        lines = 0;
        lineCount = 0;
        unknown = 0;
        multibyte = false;
    }
};

struct TextNode;
struct TileExtra;

struct Font
{

    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34;

    float* height;

    float GetHeight() const
    {
        return height ? *height : 0.0f;
    }

    void SetHeight(float value)
    {
        if (height)
            *height = value;
    }

};

struct FontManager
{
    Font* fonts[8];
    bool multibyte;
    static FontManager* Get();
    Font* GetFont(int index)
    {
        return fonts[index];
    }
    bool CreateTextRun(TextString, TextParams*, TextNode*);
};


inline FontManager* FontManager::Get()
{
    return (*reinterpret_cast<::FontManager * *>(&::DAT_011f33f8));
}

int __cdecl FUN_0040b460(void*);

struct TextNode
{

    virtual void unkV00();

    virtual void unkV01();

    virtual void unkV02();

    virtual void unkV03();

    virtual void unkV04();

    virtual void unkV05();

    virtual void unkV06();

    virtual void unkV07();

    virtual void unkV08();

    virtual void unkV09();

    virtual void unkV0A();

    virtual void unkV0B();

    virtual void unkV0C();

    virtual void unkV0D();

    virtual void unkV0E();

    virtual void unkV0F();

    virtual void unkV10();

    virtual void unkV11();

    virtual void unkV12();

    virtual void unkV13();

    virtual void unkV14();

    virtual void unkV15();

    virtual void unkV16();

    virtual void unkV17();

    virtual void unkV18();

    virtual void unkV19();

    virtual void unkV1A();

    virtual void unkV1B();

    virtual void unkV1C();

    virtual void unkV1D();

    virtual void unkV1E();

    virtual void unkV1F();

    virtual void unkV20();

    virtual void unkV21();

    virtual void unkV22();

    virtual void unkV23();

    virtual void unkV24();

    virtual void unkV25();

    virtual void unkV26();

    virtual void unkV27();

    virtual void unkV28();

    virtual void unkV29();

    virtual void unkV2A();

    virtual void unkV2B();

    virtual void unkV2C();

    virtual void unkV2D();

    virtual void unkV2E();

    virtual void unkV2F();

    virtual void unkV30();

    virtual void unkV31();

    virtual void unkV32();

    virtual void unkV33();

    virtual void unkV34();

    virtual void unkV35();

    virtual void unkV36();

    virtual void AddObject(TextNode*, bool);

    int unk04;

    int unk08;

    int unk0C;

    int unk10;

    unsigned short extraCount, extraCapacity;

    int unk18;

    int unk1C;

    int unk20;

    int unk24;

    int unk28;

    int unk2C;

    int unk30;

    int unk34;

    int unk38;

    int unk3C;

    int unk40;

    int unk44;

    int unk48;

    int unk4C;

    int unk50;

    int unk54;

    struct Point
    {
        float x, y, z;
        Point()
        {}
        Point(float px, float py, float pz)
        {
            x = px;
            y = py;
            z = pz;
        }
    } position;

    const Point& GetPosition() const
    {
        return position;
    }

    void SetPosition(const Point& p)
    {
        position = p;
    }

    void DecRefCount()
    {
        if (!((int)(::WaitForSingleObjectEx((long *)(void *)(&unk04)))))
            unkV01();
    }
    int IncRefCount()
    {
        return FUN_0040b460(&unk04);
    }

    bool SetExtraDataName(TileExtra*);
    bool FUN_00a5ba40(TileExtra*);

    void SetFlag(unsigned mask, bool enabled)
    {
        if (enabled)
            unk30 |= mask;
        else
            unk30 &= ~mask;
    }

    void SetCulled(bool hide)
    {
        SetFlag(1, hide);
    }
};

struct NewTextNode
{

    int unk00;

    int unk04;

    int unk08;

    int unk0C;

    int unk10;

    int unk14;

    int unk18;

    int unk1C;

    int unk20;

    int unk24;

    int unk28;

    int unk2C;

    int unk30;

    int unk34;

    int unk38;

    int unk3C;

    int unk40;

    int unk44;

    int unk48;

    int unk4C;

    int unk50;

    int unk54;

    int unk58;

    int unk5C;

    int unk60;

    int unk64;

    int unk68;

    int unk6C;

    int unk70;

    int unk74;

    int unk78;

    int unk7C;

    int unk80;

    int unk84;

    int unk88;

    int unk8C;

    int unk90;

    int unk94;

    int unk98;

    int unk9C;

    int unkA0;

    int unkA4;

    int unkA8;

    NewTextNode(unsigned);
    static void* operator new(unsigned);
    static void operator delete(void*);
};

struct NodePtr
{

    TextNode* value;

    NodePtr& operator=(TextNode* object)
    {
        if (value != object)
        {
            if (value)
                value->DecRefCount();
            value = object;
            if (value)
                value->IncRefCount();
        }
        return *this;
    }

    operator TextNode*() const
    {
        return value;
    }

    TextNode* operator->() const
    {
        return value;
    }
};

struct NameHeader
{
    long references;
    unsigned length;
};
extern void* DAT_01094cfc[];
struct NameString
{
    char* value;
    NameString(const char* text)
    {
        value = text ? ::NiGlobalStringTable::AddString(text) : DAT_0109b220;
    }
    ~NameString()
    {
        if (value != DAT_0109b220)
        {
            NameHeader* header = (NameHeader*)value - 1;
            InterlockedDecrement(&header->references);
        }
    }
};
struct TypeInfo
{
    const char* name;
};
struct TileExtra
{
    void* vtable;
    int references;
    char* name;
    Tile* tile;
    TextNode* node;
    const NameString& FUN_00a62660() const;
    const TypeInfo* GetTypeInfo() const;
    void FUN_00a7b2e0();
    void AssignFixedString(const NameString&);
    TileExtra(Tile* owner, TextNode* object)
    {
        FUN_00a7b2e0();
        vtable = DAT_01094cfc;
        tile = owner;
        node = object;
        NameString extraName("Tileptr");
        AssignFixedString(extraName);
    }
    static void* operator new(unsigned);
    static void operator delete(void*);
};

const char* __cdecl FUN_00ec7750(const char*, const char*);
char* __cdecl CopyFilePath(char*, unsigned, const char*, unsigned);
int __cdecl FUN_00ec6bd2(char*, unsigned, const char*);
inline bool TextNode::SetExtraDataName(TileExtra* extra)
{
    if (!extra)
        return false;
    if (!extra->FUN_00a62660().value)
    {
        const char* typeName = extra->GetTypeInfo()->name;
        if (typeName && FUN_0044a670(typeName))
        {
            char suffix[6];
            ::NiSprintf(suffix, 6, "ED%03d", extraCount);
            const char* marker = FUN_00ec7750(typeName, "ExtraData");
            char* newName = (char*)FUN_00aa1070(
                ((marker > typeName ? (unsigned)(marker - typeName) : 0) + FUN_0044a670(suffix) + 1));
            CopyFilePath(newName, ((marker > typeName ? (unsigned)(marker - typeName) : 0) + FUN_0044a670(suffix) + 1),
                         typeName, marker > typeName ? (unsigned)(marker - typeName) : 0);
            FUN_00ec6bd2(newName, ((marker > typeName ? (unsigned)(marker - typeName) : 0) + FUN_0044a670(suffix) + 1),
                         suffix);
            {
                NameString assignedName(newName);
                extra->AssignFixedString(assignedName);
            }
            FUN_00aa10f0(newName);
        }
    }
    return FUN_00a5ba40(extra);
}




inline int ClampFont(int number)
{
    return number > 1 ? number : 1;
}

inline float ParseFloatValue(const int& value)
{

    const int number = value;

    return (float)number;
}

struct TextTile
{

    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28;

    NodePtr node;

    int unk30, unk34, unk38;

    TextNode::Point position;

    bool multibyte;

    void SetPosition(const TextNode::Point& p)
    {
        position = p;
    }



    TextNode* BuildTextNode();
};

// Creates a TextNode using tile text and settings, adds it to a node, and attaches a TileExtra.
// @fnv 0x00a21af0
TextNode* TextTile::BuildTextNode()
{

    // Locals retain the MSVC stack ordering.

    // kFirst: parent node; countVal: pixel height; maximumX: pixel width.

    // entry: font index; index: line count; kPos: depth; scale: alpha.

    // maximumTmp: maximum lines; oldStateVal: saved font height.

    TextNode* kFirst = ((::TextNode *)(reinterpret_cast<::TileX *>(this)->GetNiNode()));

    float unknown;

    float x = reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfa1);

    float kPos = -reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfa2);

    int maximumX = (int)reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfba);

    int countVal = (int)reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfbb);

    int maximumTmp = (int)reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfbc);

    int offsetTmp = (int)reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xff7);

    int kIndex = (int)reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfb7);

    int entry = ClampFont((int)reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfb9)) - 1;

    FontManager* data = (*reinterpret_cast<::FontManager * *>(&::DAT_011f33f8));

    Font* fontA = data ? ((::Font *)(reinterpret_cast<::fnv_005bd5c0::FUN_005bd5c0_shell *>((data))->FUN_005bd5c0(entry))) : 0;

    int index = (int)reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfbd);

    bool allowedX = reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfbe) > 0.0;

    float scale = reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfa9);

    unknown = reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xff5);

    Color4 colorX(scale != 0.0 ? scale / 255.0 : 0.0);

    if (!fontA || !fontA->height)
        return 0;

    TextString current(" ");

    const char* text;

    text = reinterpret_cast<::FUN_00a011f0_shell *>(this)->FUN_00a011f0(0xfc4);

    if (text && *text)
        reinterpret_cast<::TextString *>(&(current))->FUN_004037f0(text, 0);

    if (maximumX < 1)
        maximumX = (int)::Interface::UpdateInterfaceState();

    if (maximumTmp < 1)
        maximumTmp = 0x7fffffff;

    int oldStateVal = (int)fontA->GetHeight();

    fontA->SetHeight((float)(oldStateVal + offsetTmp));

    if (allowedX || (*reinterpret_cast<::FontManager * *>(&::DAT_011f33f8))->multibyte)
    {

        node = (TextNode*)new NewTextNode(0);

        TextParams params;

        params.font = entry;

        params.width = maximumX ? maximumX : 0x7fffffff;

        params.alignment = kIndex;
        params.color = colorX;

        params.height = countVal ? countVal : 0x7fffffff;

        params.lines = index;
        params.maxLines = maximumTmp;
        params.multibyte = allowedX;

        if (!FontManager::Get()->CreateTextRun(current, &params, node))
            return 0;

        maximumX = params.width;
        countVal = params.height;

        reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xfd5, ParseFloatValue(params.lineCount), true);

        multibyte = params.multibyte;
    }
    else
    {

        TextNode* first = 0;
        TextNode* second = 0;

        node = (TextNode*)new NewTextNode(0);

        reinterpret_cast<::fnv_00a12880::FontRenderer *>((fontA))->FUN_00a12880((int *)&(current), &maximumX, &countVal, 0, maximumTmp, kIndex, 10, (int)(&colorX), (::fnv_00a12880::ShapeView **)(::TextNode **)(&first), (::fnv_00a12880::ShapeView **)(::TextNode **)(&second));

        SetPosition(first->GetPosition());

        first->SetPosition(TextNode::Point(x, (float)(reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfad) * -0.00800000037997961), kPos));

        ((TextNode*)node)->AddObject(first, true);

        if (second)
        {

            second->SetPosition(TextNode::Point(x, (float)(reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfad) * -0.00800000037997961), kPos));

            ((TextNode*)node)->AddObject(second, true);
        }
    }

    fontA->SetHeight((float)oldStateVal);

    reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xfb1, ParseFloatValue(maximumX), true);

    reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xfb0, ParseFloatValue(countVal), true);

    reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(9);

    if (reinterpret_cast<::FUN_00a01230_shell *>(this)->IsTraitNonZero(0xfae))
        reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(0x100);

    if (!kFirst)
        kFirst = ((::TextNode *)(::Interface::GetInterfaceNode()));

    kFirst->AddObject(node, true);

    node->SetCulled(!reinterpret_cast<::FUN_00a01230_shell *>(this)->IsTraitNonZero(0xfa3));

    reinterpret_cast<::FUN_00a5a040_Class *>(((node).operator->()))->FUN_00a5a040();

    ::fnv_00707930::FUN_00707930(1);

    reinterpret_cast<::FUN_00a5bca0_shell *>(((node).operator->()))->SetExtraDataName((::NiExtraData *)(::TileExtra *)(new TileExtra((Tile*)this, node)));

    return node;
}
