// gamebryo2.2/corelibs/nimain/niextradata_packet.h: declares NiObject, NiFixedString, NiAccumulator, NiExtraData, NiBinaryStream and more

#include <windows.h>
#include "fnv/decl/Cls_a64ea0.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/fnv_00a64df0__FUN_00a64df0_Stream.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_0109d000.h"
#include "fnv/symbols_011f4000.h"
class NiStream;
class NiObject
{
  public:
    NiObject();
    virtual void vfn_00();
    virtual void vfn_04();
    virtual const void* GetRTTI();
    unsigned int refs;
    virtual void LoadBinary(NiStream&);
};
class NiFixedString;
class NiFixedString
{
  public:
    void* handle;
    NiFixedString& operator=(const NiFixedString& rhs)
    {
        if (rhs.handle != (*reinterpret_cast<::NiFixedString *>(&::DAT_0109b220)).handle)
            InterlockedIncrement((long*)((char*)rhs.handle - 8));
        if (handle != (*reinterpret_cast<::NiFixedString *>(&::DAT_0109b220)).handle)
            InterlockedDecrement((long*)((char*)handle - 8));
        handle = rhs.handle;
        return *this;
    }
};
class NiAccumulator
{
  public:
    void* vtable;
    unsigned int refs;
    void* camera;
    void ClearCamera();
};
class __declspec(novtable) NiExtraData : public NiObject
{
  public:
    NiFixedString name;
    void LinkObject(NiStream&);
    void LoadBinary(NiStream&);
    NiExtraData(const NiFixedString&);
};
class NiBinaryStream
{
  public:
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int ReadRaw(void* out, unsigned int n, unsigned int* size)
    {
        return read(this, out, n, size, 1);
    }
    void Read(void* out, unsigned int n)
    {
        unsigned int size = 4;
        position += ReadRaw(out, n, &size);
    }
};
class NiStream
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void RegisterObject(NiObject*);
    char pad[0xd4];
    unsigned int version;
    char pad2[0x170];
    NiBinaryStream* input;
    NiObject* GetLoadedObject();
};
template <class T> void ReadBinaryValue(NiStream&, T*, unsigned int);

inline bool IsExactKindOf(const void* type, NiObject* object)
{
    if (object)
        return object->GetRTTI() == type;
    return false;
}

inline void ReadCount(NiStream& stream, unsigned int& count)
{
    stream.input->Read(&count, 4);
}

class NiMemObject
{
  public:
};
class NiBinaryExtraData : public NiExtraData, public NiMemObject
{
  public:
    unsigned int count;
    unsigned char* data;
    NiBinaryExtraData(unsigned int, unsigned char*) throw();
};
