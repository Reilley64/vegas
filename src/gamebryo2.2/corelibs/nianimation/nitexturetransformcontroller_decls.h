#ifndef FNV_NITEXTURETRANSFORMCONTROLLER_DECLS_H
#define FNV_NITEXTURETRANSFORMCONTROLLER_DECLS_H


#include "fnv/symbols_00a30000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01096000.h"
#include "fnv/symbols_011f6000.h"
#include "MemoryManager.h"

class NiUpdateData;
class NiTexturingProperty__Map;

class NiObjectNET;
class NiInterpolator
{
  public:
    void IncRefCount();
    void DecRefCount();
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1C();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2C();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3C();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4C();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5C();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6C();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7C();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual bool Update(float time, NiObjectNET* target, const void* updateData);
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual bool Unk_27(float time, NiObjectNET* target, float& value);
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31(float, float);
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual bool Unk_35();
    virtual void Unk_36();
};


class BSFrustumFOVController
{
  public:
    void CopyMemberData();
};


struct TextureShaderMaps
{
    unsigned int pad;
    NiTexturingProperty__Map** data;
    unsigned short capacity, size;
    NiTexturingProperty__Map* Get(unsigned int i)
    {
        return i < size ? data[i] : 0;
    }
};
struct TexturePropertyLayout
{
    char pad[0x20];
    NiTexturingProperty__Map** maps;
    unsigned short capacity, size;
    unsigned int pad28;
    TextureShaderMaps* shaders;
    NiTexturingProperty__Map* GetGeometryShaderObject(unsigned int i)
    {
        return shaders ? shaders->Get(i) : 0;
    }
};
class NiUpdateData
{
  public:
    float fTime;
};
class NiPoint2
{
  public:
    float x, y;
    NiPoint2()
    {}
    NiPoint2(float a, float b) : x(a), y(b)
    {}
};
class TextureMapTransform
{
  public:
    NiPoint2 translate;
    float rotate;
    NiPoint2 scale;
    char pad[52];
    static void* operator new(unsigned int, void* p) throw()
    {
        return p;
    }
    TextureMapTransform(const NiPoint2&, float, const NiPoint2&, const NiPoint2&, int) throw();
};
class NiTexturingProperty__Map
{
  public:
    char pad[12];
    TextureMapTransform* transform;
};
#endif
