
// src/speedtree/leafinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/leafinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_00b3f130_shell.h"
#include "fnv/symbols_01017000.h"
#include <cstring>
#include "fnv/decl/FUN_00b3ed20_cls.h"
#include "fnv/decl/S_00b3ed80.h"
#include "fnv/decl/fnv_00b059e0__FUN_00b06090.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_01030000.h"
#include "fnv/symbols_01170000.h"
#include <string>
#include <vector>
struct NiPoint3
{
    float x;
    float y;
    float z;
};

class Sub14_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;

    void AssignSubstring(const Sub14_cls* src, int zero, int value);
};

class Scratch_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
};


class FUN_00b2e680_cls
{
  public:
    FUN_00b2e680_cls(const FUN_00b2e680_cls& src);

    unsigned char m_b00;
    NiPoint3 m_p04;
    float m_f10;
    Sub14_cls m_s14;
    NiPoint3 m_p30;
    NiPoint3 m_p3c;
    NiPoint3 m_p48;
};

// Copies the fields of src into this, delegating the embedded Sub14_cls member to AssignSubstring with DAT_010173f0.
// @fnv 0x00b2e680
FUN_00b2e680_cls::FUN_00b2e680_cls(const FUN_00b2e680_cls& src)
{
    Scratch_cls scratch;
    unsigned int tail;

    this->m_b00 = src.m_b00;
    this->m_p04 = src.m_p04;
    this->m_f10 = src.m_f10;
    Sub14_cls* sub = &m_s14;
    sub->AssignSubstring(&src.m_s14, 0, (*reinterpret_cast<int *>(&::g_010173f0)));
    this->m_p30 = src.m_p30;
    this->m_p3c = src.m_p3c;
    this->m_p48 = src.m_p48;
}

struct S_00b3cf40_Random
{
    S_00b3cf40_Random();
    ~S_00b3cf40_Random();
};

static const float DAT_01022958 = 10000.0f;

struct S_00b3cf40
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
    int m_uiItemCount;  // 40
    int m_rows;         // 44
    int m_iElementCount;         // 48
    float** m_tables;   // 4C
    float* m_verts;     // 50
    float* m_iSlotIds;  // 54
    void Init(int size);
};

// @fnv 0x00b3cf40
void S_00b3cf40::Init(int size)
{
    m_iElementCount = size;
    m_iSlotIds = new float[m_uiItemCount];
    S_00b3cf40_Random rng;
    for (int iIndex = 0; iIndex < m_uiItemCount; iIndex++)
        m_iSlotIds[iIndex] = reinterpret_cast<::FUN_00b3f130_shell *>(&(rng))->FUN_00b3f130(0.0f, DAT_01022958);

    m_verts = new float[size * 16];
    float* pfVert = m_verts;
    for (int iIndex = 0; iIndex < size * 2; iIndex++)
    {
        *pfVert = 0.0f;
        pfVert++;
        *pfVert = 1.0f;
        pfVert++;
        *pfVert = 1.0f;
        pfVert++;
        *pfVert = 1.0f;
        pfVert++;
        *pfVert = 1.0f;
        pfVert++;
        *pfVert = 0.0f;
        pfVert++;
        *pfVert = 0.0f;
        pfVert++;
        *pfVert = 0.0f;
        pfVert++;
    }

    m_tables = new float*[m_rows];
    int iTableCount = size * 2 * m_uiItemCount * 16;
    for (int iIndex = 0; iIndex < m_rows; iIndex++)
    {
        m_tables[iIndex] = new float[iTableCount];
        for (int jIndex = 0; jIndex < iTableCount; jIndex++)
            m_tables[iIndex][jIndex] = 0.0f;
    }
}

extern const float DAT_010a587c;

struct LeafPoint
{
    float x, y, z;
    LeafPoint()
    {}
    LeafPoint(float value) : x(value), y(value), z(value)
    {}
    LeafPoint(float xx, float yy);
    LeafPoint(float xx, float yy, float zz);
};

struct S00b3d1b0_Str : std::string
{
    S00b3d1b0_Str()
    {}
    S00b3d1b0_Str(const S00b3d1b0_Str& s) : std::string(s)
    {}
};

extern "C" int* __cdecl _errno();

struct S00b3d1b0_ErrBase
{
    void** vtable;
    int unk04;
    int unk08;
    std::string m_str;

    S00b3d1b0_ErrBase(const std::string& str);
};

inline const std::string* ErrorMessage(const std::string& s)
{
    const std::string* p = &s;
    return p;
}

inline std::string SystemError(int code)
{
    return code ? std::string(strerror(*_errno())) : std::string("");
}

struct S00b3d1b0_Err : S00b3d1b0_ErrBase
{
    S00b3d1b0_Err(const std::string& msg, bool code = false)
        : S00b3d1b0_ErrBase(msg + " [" + (code ? std::string(strerror(*_errno())) : std::string("")) + "]")
    {}
    S00b3d1b0_Err(const std::string& msg, int code)
        : S00b3d1b0_ErrBase(std::string(ErrorMessage(msg)->begin(), msg.end()) + " [" +
                            (code ? std::string(strerror(*_errno())) : std::string()) + "]")
    {}
    S00b3d1b0_Err(const S00b3d1b0_Err&);
    ~S00b3d1b0_Err();
};

struct S00b3d1b0_Name : S00b3d1b0_Str
{
    S00b3d1b0_Name()
    {}
    S00b3d1b0_Name(S00b3d1b0_Str s) : S00b3d1b0_Str(s)
    {}
    S00b3d1b0_Name FUN_00b09f90();
};

struct S00b3d1b0_Src
{
    int ReadToken()
    {
        return reinterpret_cast<::S_00b3ed80 *>(this)->GetNextElement();
    }
    LeafPoint GetVector3();
    S00b3d1b0_Str FUN_00b3ee40();
};

struct S00b3d1b0_Leaf
{
    char m_iWordAt00;
    LeafPoint m_iWordAt04;
    float m_10;
    S00b3d1b0_Name m_14;
    LeafPoint m_30;
    LeafPoint m_3c;
    LeafPoint m_48;

    S00b3d1b0_Leaf()
        : m_iWordAt00(false), m_iWordAt04(DAT_01030ff0), m_10(::DAT_0101df44), m_30(::fnv_00c88020::DAT_01016248, 1.0f, 0.0f),
          m_3c(DAT_010a587c, DAT_010a587c, 0.0f), m_48(::DAT_01017b78, ::DAT_01017b78, 0.0f)
    {}
};

struct S00b3d1b0_Obj
{
    char m_iWordAt00;
    float m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    std::vector<S00b3d1b0_Leaf> m_10;
    float m_28;
    float m_2c;
    float m_30;
    int m_34;

    void FUN_00b3d1b0(S00b3d1b0_Src* src);
};

// @fnv 0x00b3d1b0
void S00b3d1b0_Obj::FUN_00b3d1b0(S00b3d1b0_Src* src)
{
    int aTag = src->ReadToken();
    int count;
    int i;
    do
    {
        switch (aTag)
        {
        case 3000:
            m_2c = reinterpret_cast<::FUN_00b3ed20_cls *>((src))->FUN_00b3ed20();
            break;
        case 3001:
            m_34 = reinterpret_cast<::S_00b3ed80 *>((src))->GetNextElement();
            break;
        case 3002:
            m_30 = reinterpret_cast<::FUN_00b3ed20_cls *>((src))->FUN_00b3ed20();
            break;
        case 3003:
            reinterpret_cast<::fnv_00b059e0::FUN_00b06090 *>((src))->FUN_00b06180();
            break;
        case 3004:
            reinterpret_cast<::FUN_00b3ed20_cls *>((src))->FUN_00b3ed20();
            break;
        case 3009:
            m_iWordAt00 = ((char)(reinterpret_cast<::fnv_00b059e0::FUN_00b06090 *>((src))->FUN_00b06180()));
            break;
        case 3010:
            m_iWordAt04 = reinterpret_cast<::FUN_00b3ed20_cls *>((src))->FUN_00b3ed20();
            break;
        case 3005:
            reinterpret_cast<::FUN_00b3ed20_cls *>((src))->FUN_00b3ed20();
            break;
        case 3006:
            reinterpret_cast<::fnv_00b059e0::FUN_00b06090 *>((src))->FUN_00b06180();
            break;
        case 3007:
            m_28 = reinterpret_cast<::FUN_00b3ed20_cls *>((src))->FUN_00b3ed20();
            break;
        case 3008:
            m_iThirdValue = reinterpret_cast<::S_00b3ed80 *>((src))->GetNextElement();
            break;
        case 1009: {
            aTag = src->ReadToken();
            count = reinterpret_cast<::S_00b3ed80 *>((src))->GetNextElement();
            m_10.clear();
            m_10.resize(count);
            for (i = 0; i < count; ++i)
            {
                S00b3d1b0_Leaf leaf;
                aTag = src->ReadToken();
                aTag = src->ReadToken();
                do
                {
                    switch (aTag)
                    {
                    case 4000:
                        leaf.m_iWordAt00 = ((char)(reinterpret_cast<::fnv_00b059e0::FUN_00b06090 *>((src))->FUN_00b06180()));
                        break;
                    case 4001:
                        leaf.m_iWordAt04 = src->GetVector3();
                        break;
                    case 4002:
                        leaf.m_10 = reinterpret_cast<::FUN_00b3ed20_cls *>((src))->FUN_00b3ed20();
                        break;
                    case 4003:
                        leaf.m_14 = src->FUN_00b3ee40();
                        leaf.m_14 = leaf.m_14.FUN_00b09f90();
                        break;
                    case 4004:
                        leaf.m_30 = src->GetVector3();
                        break;
                    case 4005:
                        leaf.m_3c = src->GetVector3();
                        break;
                    case 4006:
                        leaf.m_48 = src->GetVector3();
                        break;
                    case 4007:
                        reinterpret_cast<::FUN_00b3ed20_cls *>((src))->FUN_00b3ed20();
                        break;
                    default:
                        throw S00b3d1b0_Err("malformed single leaf information", false);
                    }
                    aTag = src->ReadToken();
                } while (aTag != 1008);
                m_10[i] = leaf;
            }
            aTag = src->ReadToken();
            break;
        }
        default:
            throw S00b3d1b0_Err("malformed general leaf information", (int)0);
        }
        aTag = src->ReadToken();
    } while (aTag != 1005);
}
