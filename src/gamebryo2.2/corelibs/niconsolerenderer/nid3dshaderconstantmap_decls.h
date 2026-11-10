
#include <windows.h>
#include "fnv/symbols_00e87000.h"
#include "fnv/symbols_011f4000.h"
class NiD3DShaderProgram;
class NiGeometry;
class NiSkinInstance;
struct NiGeometryBufferData;
class NiPropertyState;
class NiDynamicEffectState;
class NiTransform;
struct NiBound;
class NiExtraData;
class NiSkinPartition
{
  public:
    class Partition;
};
class Direct3DDeviceInterface
{
  public:
    virtual long vfn_0(unsigned int, const float*, unsigned int);
    virtual long vfn_4(unsigned int, const float*, unsigned int);
    virtual long vfn_8(unsigned int, const float*, unsigned int);
    virtual long vfn_c(unsigned int, const float*, unsigned int);
    virtual long vfn_10(unsigned int, const float*, unsigned int);
    virtual long vfn_14(unsigned int, const float*, unsigned int);
    virtual long vfn_18(unsigned int, const float*, unsigned int);
    virtual long vfn_1c(unsigned int, const float*, unsigned int);
    virtual long vfn_20(unsigned int, const float*, unsigned int);
    virtual long vfn_24(unsigned int, const float*, unsigned int);
    virtual long vfn_28(unsigned int, const float*, unsigned int);
    virtual long vfn_2c(unsigned int, const float*, unsigned int);
    virtual long vfn_30(unsigned int, const float*, unsigned int);
    virtual long vfn_34(unsigned int, const float*, unsigned int);
    virtual long vfn_38(unsigned int, const float*, unsigned int);
    virtual long vfn_3c(unsigned int, const float*, unsigned int);
    virtual long vfn_40(unsigned int, const float*, unsigned int);
    virtual long vfn_44(unsigned int, const float*, unsigned int);
    virtual long vfn_48(unsigned int, const float*, unsigned int);
    virtual long vfn_4c(unsigned int, const float*, unsigned int);
    virtual long vfn_50(unsigned int, const float*, unsigned int);
    virtual long vfn_54(unsigned int, const float*, unsigned int);
    virtual long vfn_58(unsigned int, const float*, unsigned int);
    virtual long vfn_5c(unsigned int, const float*, unsigned int);
    virtual long vfn_60(unsigned int, const float*, unsigned int);
    virtual long vfn_64(unsigned int, const float*, unsigned int);
    virtual long vfn_68(unsigned int, const float*, unsigned int);
    virtual long vfn_6c(unsigned int, const float*, unsigned int);
    virtual long vfn_70(unsigned int, const float*, unsigned int);
    virtual long vfn_74(unsigned int, const float*, unsigned int);
    virtual long vfn_78(unsigned int, const float*, unsigned int);
    virtual long vfn_7c(unsigned int, const float*, unsigned int);
    virtual long vfn_80(unsigned int, const float*, unsigned int);
    virtual long vfn_84(unsigned int, const float*, unsigned int);
    virtual long vfn_88(unsigned int, const float*, unsigned int);
    virtual long vfn_8c(unsigned int, const float*, unsigned int);
    virtual long vfn_90(unsigned int, const float*, unsigned int);
    virtual long vfn_94(unsigned int, const float*, unsigned int);
    virtual long vfn_98(unsigned int, const float*, unsigned int);
    virtual long vfn_9c(unsigned int, const float*, unsigned int);
    virtual long vfn_a0(unsigned int, const float*, unsigned int);
    virtual long vfn_a4(unsigned int, const float*, unsigned int);
    virtual long vfn_a8(unsigned int, const float*, unsigned int);
    virtual long vfn_ac(unsigned int, const float*, unsigned int);
    virtual long vfn_b0(unsigned int, const float*, unsigned int);
    virtual long vfn_b4(unsigned int, const float*, unsigned int);
    virtual long vfn_b8(unsigned int, const float*, unsigned int);
    virtual long vfn_bc(unsigned int, const float*, unsigned int);
    virtual long vfn_c0(unsigned int, const float*, unsigned int);
    virtual long vfn_c4(unsigned int, const float*, unsigned int);
    virtual long vfn_c8(unsigned int, const float*, unsigned int);
    virtual long vfn_cc(unsigned int, const float*, unsigned int);
    virtual long vfn_d0(unsigned int, const float*, unsigned int);
    virtual long vfn_d4(unsigned int, const float*, unsigned int);
    virtual long vfn_d8(unsigned int, const float*, unsigned int);
    virtual long vfn_dc(unsigned int, const float*, unsigned int);
    virtual long vfn_e0(unsigned int, const float*, unsigned int);
    virtual long vfn_e4(unsigned int, const float*, unsigned int);
    virtual long vfn_e8(unsigned int, const float*, unsigned int);
    virtual long vfn_ec(unsigned int, const float*, unsigned int);
    virtual long vfn_f0(unsigned int, const float*, unsigned int);
    virtual long vfn_f4(unsigned int, const float*, unsigned int);
    virtual long vfn_f8(unsigned int, const float*, unsigned int);
    virtual long vfn_fc(unsigned int, const float*, unsigned int);
    virtual long vfn_100(unsigned int, const float*, unsigned int);
    virtual long vfn_104(unsigned int, const float*, unsigned int);
    virtual long vfn_108(unsigned int, const float*, unsigned int);
    virtual long vfn_10c(unsigned int, const float*, unsigned int);
    virtual long vfn_110(unsigned int, const float*, unsigned int);
    virtual long vfn_114(unsigned int, const float*, unsigned int);
    virtual long vfn_118(unsigned int, const float*, unsigned int);
    virtual long vfn_11c(unsigned int, const float*, unsigned int);
    virtual long vfn_120(unsigned int, const float*, unsigned int);
    virtual long vfn_124(unsigned int, const float*, unsigned int);
    virtual long vfn_128(unsigned int, const float*, unsigned int);
    virtual long vfn_12c(unsigned int, const float*, unsigned int);
    virtual long vfn_130(unsigned int, const float*, unsigned int);
    virtual long vfn_134(unsigned int, const float*, unsigned int);
    virtual long vfn_138(unsigned int, const float*, unsigned int);
    virtual long vfn_13c(unsigned int, const float*, unsigned int);
    virtual long vfn_140(unsigned int, const float*, unsigned int);
    virtual long vfn_144(unsigned int, const float*, unsigned int);
    virtual long vfn_148(unsigned int, const float*, unsigned int);
    virtual long vfn_14c(unsigned int, const float*, unsigned int);
    virtual long vfn_150(unsigned int, const float*, unsigned int);
    virtual long vfn_154(unsigned int, const float*, unsigned int);
    virtual long vfn_158(unsigned int, const float*, unsigned int);
    virtual long vfn_15c(unsigned int, const float*, unsigned int);
    virtual long vfn_160(unsigned int, const float*, unsigned int);
    virtual long vfn_164(unsigned int, const float*, unsigned int);
    virtual long vfn_168(unsigned int, const float*, unsigned int);
    virtual long vfn_16c(unsigned int, const float*, unsigned int);
    virtual long vfn_170(unsigned int, const float*, unsigned int);
    virtual long vfn_174(unsigned int, const float*, unsigned int);
    virtual long SetVertexShaderConstantF(unsigned int, const float*, unsigned int);
    virtual long vfn_17c(unsigned int, const float*, unsigned int);
    virtual long vfn_180(unsigned int, const float*, unsigned int);
    virtual long vfn_184(unsigned int, const float*, unsigned int);
    virtual long vfn_188(unsigned int, const float*, unsigned int);
    virtual long vfn_18c(unsigned int, const float*, unsigned int);
    virtual long vfn_190(unsigned int, const float*, unsigned int);
    virtual long vfn_194(unsigned int, const float*, unsigned int);
    virtual long vfn_198(unsigned int, const float*, unsigned int);
    virtual long vfn_19c(unsigned int, const float*, unsigned int);
    virtual long vfn_1a0(unsigned int, const float*, unsigned int);
    virtual long vfn_1a4(unsigned int, const float*, unsigned int);
    virtual long vfn_1a8(unsigned int, const float*, unsigned int);
    virtual long vfn_1ac(unsigned int, const float*, unsigned int);
    virtual long vfn_1b0(unsigned int, const float*, unsigned int);
    virtual long SetPixelShaderConstantF(unsigned int, const float*, unsigned int);
    __forceinline unsigned int UploadVertex(unsigned int index, const float* data, unsigned int count)
    {
        return SetVertexShaderConstantF(index, data, count) < 0;
    }
    __forceinline unsigned int UploadPixel(unsigned int index, const float* data, unsigned int count)
    {
        return SetPixelShaderConstantF(index, data, count) < 0;
    }
};
class NiShaderConstantMapEntry
{
  public:
    virtual void vfn_0();
    __declspec(noalias) __declspec(nothrow) virtual void DeleteThis() throw();
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    __forceinline void DecRefCount()
    {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
    long refs;
    bool enabled;
    char pad[11];
    unsigned int flags, type, index, registers, extra;
    char pad28[8];
    const float* data;
public:
    NiShaderConstantMapEntry();
};
template <class T> class NiPointer
{
  public:
    T* p;
    __forceinline operator T*() const
    {
        return p;
    }
    __declspec(nothrow) __forceinline NiPointer() throw() : p(0)
    {}
    __declspec(nothrow) __forceinline ~NiPointer() throw()
    {
        Release();
    }
    __forceinline void Release()
    {
        if (p)
            p->DecRefCount();
    }
    __declspec(nothrow) __forceinline void operator=(const NiPointer& r) throw()
    {
        T* old = p;
        if (old != r.p)
        {
            if (old)
                old->DecRefCount();
            old = r.p;
            p = old;
            if (old)
                old->IncRefCount();
        }
    }
};
template <class T> class NiTObjectArray
{
  public:
    void* v;
    T* data;
    __forceinline T& GetAt(unsigned int i)
    {
        return data[i];
    }
    unsigned short capacity, size, count, grow;
    __declspec(noalias) __declspec(nothrow) void SetAt(unsigned int, const T& __restrict) throw();
};
class NiShaderConstantMapEntry;
class NiD3DShaderConstantMap
{
  public:
    virtual unsigned int vfn_0();
    virtual unsigned int vfn_4();
    virtual unsigned int vfn_8();
    virtual unsigned int vfn_c();
    virtual unsigned int vfn_10();
    virtual unsigned int vfn_14();
    virtual unsigned int vfn_18();
    virtual unsigned int vfn_1c();
    virtual unsigned int vfn_20();
    virtual unsigned int vfn_24();
    virtual unsigned int vfn_28();
    virtual unsigned int vfn_2c();
    virtual unsigned int vfn_30();
    virtual unsigned int vfn_34();
    virtual unsigned int vfn_38();
    virtual unsigned int vfn_3c();
    virtual unsigned int vfn_40();
    virtual unsigned int vfn_44();
    virtual unsigned int vfn_48();
    virtual unsigned int vfn_4c();
    virtual unsigned int vfn_50();
    virtual unsigned int vfn_54();
    virtual unsigned int vfn_58();
    virtual unsigned int vfn_5c();
    virtual unsigned int vfn_60();
    virtual unsigned int vfn_64();
    virtual unsigned int vfn_68();
    virtual unsigned int vfn_6c();
    virtual unsigned int vfn_70();
    virtual unsigned int vfn_74();
    virtual unsigned int vfn_78();
    virtual unsigned int vfn_7c();
    virtual unsigned int vfn_80();
    virtual unsigned int vfn_84();
    virtual unsigned int vfn_88();
    virtual unsigned int vfn_8c(NiD3DShaderProgram*, NiShaderConstantMapEntry*, NiGeometry*, const NiSkinInstance*,
                                const NiSkinPartition::Partition*, NiGeometryBufferData*, const NiPropertyState*,
                                const NiDynamicEffectState*, const NiTransform&, const NiBound&, unsigned int);
    virtual unsigned int vfn_90(NiD3DShaderProgram*, NiShaderConstantMapEntry*, unsigned int);
    virtual unsigned int vfn_94(NiD3DShaderProgram*, NiShaderConstantMapEntry*, NiGeometry*, const NiSkinInstance*,
                                const NiSkinPartition::Partition*, NiGeometryBufferData*, const NiPropertyState*,
                                const NiDynamicEffectState*, const NiTransform&, const NiBound&, unsigned int, bool,
                                NiExtraData*);
    virtual unsigned int vfn_98(NiD3DShaderProgram*, NiShaderConstantMapEntry*, unsigned int);
    virtual unsigned int vfn_9c(NiD3DShaderProgram*, NiShaderConstantMapEntry*, NiGeometry*, const NiSkinInstance*,
                                const NiPropertyState*, const NiDynamicEffectState*, const NiTransform&, const NiBound&,
                                unsigned int);
    virtual unsigned int vfn_a0();
    virtual unsigned int vfn_a4(NiD3DShaderProgram*, NiShaderConstantMapEntry*, NiGeometry*, const NiSkinInstance*,
                                const NiSkinPartition::Partition*, NiGeometryBufferData*, const NiPropertyState*,
                                const NiDynamicEffectState*, const NiTransform&, const NiBound&, unsigned int);
    char base[8];
    NiTObjectArray<NiPointer<NiShaderConstantMapEntry> > entries, defined;
    bool modified;
    char pad2d[3];
    NiD3DShaderProgram* last;
    unsigned int error;
    Direct3DDeviceInterface* device;
    unsigned int ConfigureShaderConstantMap(NiD3DShaderProgram*, NiGeometry*, const NiSkinInstance*,
                                            const NiSkinPartition::Partition*, NiGeometryBufferData*,
                                            const NiPropertyState*, const NiDynamicEffectState*, const NiTransform&,
                                            const NiBound&, unsigned int, bool);
    void ResetShaderConstantMap();
};
struct NiPoint3
{
  public:
    float x, y, z;
public:
    ::NiPoint3 *ScaleTo(::NiPoint3 *, float);
public:
    static const ::NiPoint3 ZERO;
};
struct ThreeByThreeMatrix
{
  public:
    float m[3][3];
};
