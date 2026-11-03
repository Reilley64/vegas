
// src/havok/common/base/reflection/hkclassenum_decl_variant_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/base/reflection/hkclassenum_decl_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/reflection/hkclassenum_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00db7600: the skeleton of src/havok/common/base/reflection/hkclassenum.cpp
// with declarations corrected to what the original code does (hkBase.h: typedef char hkBool; -> class hkBool { public: __forceinline hkBool() {} _; hkClassEnum.h: hkClassEnum += void FUN_00db7600(class hkStreamWriter* writer) const;). Move the function to its real unit once
// that unit declares it this way.
// src/havok/common/base/reflection/hkclassenum.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/reflection/hkclassenum.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/ClassMember_d869.h"
#include "fnv/decl/FUN_00d46cf0_C.h"
#include "fnv/decl/FUN_00d607b0_class.h"
#include "fnv/decl/hkOArchive_2.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_00d86000.h"
#include "havok/hkClassEnum_decl_hkclassenum.h"
struct hkCustomAttributes
{
};
struct FUN_00db76a0_Class
{
    void* GetAttribute(void* arg);
};
struct FUN_00db7860
{
    int m_00;
    int m_04;
    int m_08;
    ~FUN_00db7860() throw();
};
struct FUN_00db7870 : public FUN_00db7860
{
    FUN_00db7870(int n) throw();
};
struct hkObjDB76
{
    void FUN_00db76c0();
};

class hkReferencedObject : public hkBaseObject
{
  public:
    unsigned short memSizeAndFlags;
    short referenceCount;
};
class hkStreamWriter;
class hkOArchive : public hkReferencedObject
{
  public:
    hkStreamWriter* writer;
    hkBool byteSwap;
    hkOArchive(hkStreamWriter*, hkBool);
    virtual ~hkOArchive();
};
class hkClassEnumItem
{
  public:
    int value;
    const char* name;
};
// @fnv 0x00db7600
void hkClassEnum::FUN_00db7600(hkStreamWriter* writer) const
{
    hkOArchive archive(writer, false);
    const char* name = m_name;
    reinterpret_cast<::FUN_00d607b0_class *>(&(archive))->FUN_00d607b0((int)(name));
    int count = m_items.m_iElementCount;
    for (int i = 0; i < count; ++i)
    {
        const hkClassEnumItem& item = m_items.m_data[i];
        const char* itemName = item.name;
        reinterpret_cast<::FUN_00d607b0_class *>(&(archive))->FUN_00d607b0((int)(itemName));
        reinterpret_cast<::hkOArchive_2 *>(&(archive))->WriteInt(item.value);
    }
    reinterpret_cast<::hkOArchive_2 *>(&(archive))->WriteInt(count);
}
