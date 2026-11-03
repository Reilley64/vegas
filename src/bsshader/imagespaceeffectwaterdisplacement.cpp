#include <cstdint>
#include <cstddef>

// src/bsshader/imagespaceeffectwaterdisplacement.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/imagespaceeffectwaterdisplacement.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include <windows.h>
#include "fnv/decl/BB97550Shader.h"
#include "fnv/decl/BSRenderStateManager.h"
#include "fnv/decl/FUN_004bc320_shell.h"
#include "fnv/decl/FUN_004e7560_shell.h"
#include "fnv/decl/FUN_00a41520_cls.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00a87900_class.h"
#include "fnv/decl/FUN_00ba3770_struct.h"
#include "fnv/decl/FUN_00ba3780_struct.h"
#include "fnv/decl/FUN_00ba3940_cls.h"
#include "fnv/decl/FUN_00ba3b50_t.h"
#include "fnv/decl/FUN_00ba3c70_shell.h"
#include "fnv/decl/H.h"
#include "fnv/decl/H_00ba3840.h"
#include "fnv/decl/H_00ba39a0.h"
#include "fnv/decl/ImageSpaceManagerView.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/decl/NiScreenElementsDataShell.h"
#include "fnv/decl/OwnerStandIn.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00b97000.h"
#include "fnv/symbols_00ba3000.h"
#include "fnv/symbols_01013000.h"
#include "fnv/symbols_01031000.h"
#include "fnv/symbols_01054000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011ad000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_011ff000.h"
#include "fnv/symbols_01200000.h"
struct NiPoint2
{
    float x;
    float y;
    NiPoint2()
    {}
    NiPoint2(float _x, float _y) : x(_x), y(_y)
    {}
};

struct NiPoint4
{
    float x;
    float y;
    float z;
    float w;
};

struct NiMemObject
{
};

struct RenderTargetGroup
{
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void vfn_0018();
    virtual void vfn_001c();
    virtual void vfn_0020();
    virtual void vfn_0024();
    virtual void vfn_0028();
    virtual void vfn_002c();
    virtual void vfn_0030();
    virtual void vfn_0034();
    virtual void vfn_0038();
    virtual void vfn_003c();
    virtual void vfn_0040();
    virtual void vfn_0044();
    virtual void vfn_0048();
    virtual void vfn_004c();
    virtual void vfn_0050();
    virtual void vfn_0054();
    virtual void vfn_0058();
    virtual void vfn_005c();
    virtual void vfn_0060();
    virtual void vfn_0064();
    virtual void vfn_0068();
    virtual void vfn_006c();
    virtual void vfn_0070();
    virtual void vfn_0074();
    virtual void vfn_0078();
    virtual void vfn_007c();
    virtual void vfn_0080();
    virtual void vfn_0084();
    virtual void vfn_0088();
    virtual void vfn_008c();
    virtual void vfn_0090();
    virtual void vfn_0094();
    virtual void vfn_0098();
    virtual void vfn_009c();
    virtual void vfn_00a0();
    virtual void vfn_00a4();
    virtual void vfn_00a8();
    virtual void vfn_00ac();
    virtual void vfn_00b0();
    virtual void* GetView();
};

struct BSRenderedTexture
{
    RenderTargetGroup* GetGroup();
};

struct ImageSpaceTexture
{
    unsigned char flag0;
    unsigned char flag1;
    unsigned char flag2;
    int value4;
    int value8;
    int valueC;

    ImageSpaceTexture() : flag0(0), flag1(0), flag2(0), value4(0), value8(0), valueC(0)
    {}
    ~ImageSpaceTexture();

};

struct Type_00b6b380 : public NiMemObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    Type_00b6b380(void*, int, int, void*);
};

struct NiAccumulator;
struct NiCamera;
struct HolderForAccum
{
    virtual void Dispose();
    virtual void Dispatch(void*, void*, void*, int);
public:
    void SetAccumulatorAt(unsigned int, ::NiAccumulator *, const ::NiCamera *);
};

struct Emitter
{
};

struct NiScreenElementsData : public NiMemObject
{
    virtual void Destroy();
    virtual void Release();
    long m_uiRefCount;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;

    NiScreenElementsData(bool, bool, unsigned short, int, int, int, int, int, int);
    bool SetRectangle(int, float, float, float, float);
public:
    bool SetRectangleBounds(int, unsigned short, float, float, float, float);
};

struct NiScreenElements : public NiMemObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    NiScreenElementsData* m_spTransformData;
    int unkbc;
    int unkc0;

    NiScreenElements(NiScreenElementsData*);
};


template <class T> struct NiPointer
{
    T* m_pObject;
    NiPointer() : m_pObject(0)
    {}
    __forceinline NiPointer(T* p) : m_pObject(p)
    {
        if (m_pObject)
        {
            InterlockedIncrement(&m_pObject->m_uiRefCount);
        }
    }
    __forceinline ~NiPointer()
    {
        if (m_pObject)
        {
            if (InterlockedDecrement(&m_pObject->m_uiRefCount) == 0)
            {
                m_pObject->Release();
            }
        }
    }
    NiPointer& operator=(T* p);
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};

struct NiUpdateData
{
    float m_fTime;
    bool b1;
    bool b2;
    bool b3;
    bool b4;
    bool b5;
    NiUpdateData(float t = 0.0f) : m_fTime(t), b1(false), b2(false), b3(false), b4(false), b5(false)
    {}
};


struct NiFixedString
{
    const char* m_kHandle;
    __forceinline NiFixedString(const char* s)
    {
        m_kHandle = ::NiGlobalStringTable::AddString(s);
    }
    __forceinline ~NiFixedString()
    {
        if (m_kHandle != (const char*)(*reinterpret_cast<void * *>(&::DAT_0109b220)))
        {
            InterlockedDecrement((volatile long*)(m_kHandle - 8));
        }
    }
    operator const void*() const
    {
        return &m_kHandle;
    }
};

struct Allocator
{
    virtual void Delete0();
    virtual void Delete1();
    virtual void Free(void*);
};

struct ImageSpaceManager
{
};

struct GameObject
{
    int unk00;
    int unk04;
    int unk08;
    HolderForAccum** nodes;
    int unk10;
    int unk14;
    int unk18;
    Emitter** emitters;
    int unk20;
    int unk24;
    int unk28;
    ImageSpaceTexture** assets;
    template <int I> ImageSpaceTexture*& GetAsset()
    {
        return assets[I];
    }
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
    NiPointer<NiScreenElements> widget;
    float time;
    float previous;
    int unk64;
    float accumulated;
    float step;

    void FUN_00ba0900(void* arg1, void* arg2, int arg3, int arg4);
};

extern int DAT_011ffffc;
extern int DAT_011ada08;
extern int DAT_011ada0c;
extern int DAT_011ada18;
extern int DAT_011ada1c;
extern NiPoint2* DAT_011ada04;
extern NiPoint2* DAT_011ada14;
extern NiPoint4 DAT_0120002c;
extern NiPoint4 DAT_0120003c;

static HolderForAccum* GetNode(HolderForAccum* p)
{
    void* d = p ? (void*)((char*)p - 0x6c) : 0;
    return d ? (HolderForAccum*)((char*)d + 0x6c) : 0;
}

struct MemoryManager
{
};

extern const float DAT_011add48[];

class ImageSpaceShaderParam
{
  public:
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
    char unk54;
    char unk55;
    char unk56;
    char unk57;
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

    ImageSpaceShaderParam();
    void CopyParamData(int a1, const float* a2, unsigned int a3);
public:
    void SetShaderConstantVector4(int, float, float, float, float);
public:
    void FUN_00b8a7c0();
public:
    void AllocateShaderConstants(int, int);
};
// @fnv 0x00ba0900
void GameObject::FUN_00ba0900(void* arg1, void* arg2, int arg3, int arg4)
{
    if ((*reinterpret_cast<unsigned char *>(&::fnv_004e8ec0::DAT_011fffed)))
    {
        step = DAT_010313d4;
        float nextTime = time + DAT_011f9410;
        time = nextTime;
        accumulated += nextTime;
    }
    else
    {
        step = DAT_010313d4;
        float nextTime = time + DAT_011f9410;
        time = nextTime;
        accumulated += nextTime;
    }

    ImageSpaceTexture tex54;
    ImageSpaceTexture tex64;
    ImageSpaceTexture tex34;

    reinterpret_cast<::H_00ba3840 *>(&(tex64))->FUN_00ba3840(8);

    reinterpret_cast<::OwnerStandIn *>(&(tex34))->FUN_00ba37a0((::RefBase *)(void *)(new Type_00b6b380(((void *)(reinterpret_cast<::FUN_004bc320_shell *>((((::BSRenderedTexture *)(reinterpret_cast<::FUN_00ba3770_struct *>(&(tex64))->FUN_00ba3770()))))->FUN_004bc320({}))), 0, 1,
                                         ((::BSRenderedTexture *)(reinterpret_cast<::FUN_00ba3770_struct *>((GetAsset<1>()))->FUN_00ba3770()))->GetGroup()->GetView())));

    ImageSpaceTexture tex44;

    if ((*reinterpret_cast<unsigned char *>(&::fnv_004e8510::DAT_011fffec)))
    {
        HolderForAccum* node = GetNode(nodes[0]);
        Emitter* pEmitter = emitters[0];

        node->SetAccumulatorAt(0, (::NiAccumulator *)(void *)(&tex34), (const ::NiCamera *)(0));
        node->SetAccumulatorAt(1, (::NiAccumulator *)(assets[1]), (const ::NiCamera *)(1));
        node->Dispatch(arg1, arg2, pEmitter, 1);

        reinterpret_cast<::FUN_00ba3940_cls *>(&(tex44))->FUN_00ba3940((::FUN_00ba3940_cls *)(assets[1]));
        reinterpret_cast<::FUN_00ba3940_cls *>(&(tex54))->FUN_00ba3940((::FUN_00ba3940_cls *)(void *)(&tex34));
        reinterpret_cast<::FUN_00ba3940_cls *>(&(tex34))->FUN_00ba3940((::FUN_00ba3940_cls *)(void *)(&tex44));
        (*reinterpret_cast<unsigned char *>(&::fnv_004e8510::DAT_011fffec)) = 0;
    }

    if ((*reinterpret_cast<unsigned char *>(&::fnv_004e8ec0::DAT_011fffed)))
    {
        HolderForAccum* node = GetNode(nodes[1]);
        Emitter* pEmitter = emitters[1];

        reinterpret_cast<::ImageSpaceShaderParam *>((pEmitter))->SetShaderConstantVector4(0, time, 0.0f, 0.0f, 0.0f);
        reinterpret_cast<::ImageSpaceShaderParam *>((pEmitter))->SetShaderConstantVector4(1, DAT_011ffff4, 0.0f, 0.0f, 0.0f);
        reinterpret_cast<::ImageSpaceShaderParam *>((pEmitter))->SetShaderConstantVector4(2, (*reinterpret_cast<::NiPoint2 *>(&::fnv_004e8ec0::DAT_01200024)).x, (*reinterpret_cast<::NiPoint2 *>(&::fnv_004e8ec0::DAT_01200024)).y, 0.0f, 0.0f);
        reinterpret_cast<::ImageSpaceShaderParam *>((pEmitter))->SetShaderConstantVector4(4, (*reinterpret_cast<::NiPoint4 *>(&::DAT_01200004)).x, (*reinterpret_cast<::NiPoint4 *>(&::DAT_01200004)).y, (*reinterpret_cast<::NiPoint4 *>(&::DAT_01200004)).z, (*reinterpret_cast<::NiPoint4 *>(&::DAT_01200004)).w);
        reinterpret_cast<::ImageSpaceShaderParam *>((pEmitter))->SetShaderConstantVector4(5, (*reinterpret_cast<::NiPoint4 *>(&::DAT_01200014)).x, (*reinterpret_cast<::NiPoint4 *>(&::DAT_01200014)).y, (*reinterpret_cast<::NiPoint4 *>(&::DAT_01200014)).z, (*reinterpret_cast<::NiPoint4 *>(&::DAT_01200014)).w);

        node->SetAccumulatorAt(0, (::NiAccumulator *)(void *)(&tex34), (const ::NiCamera *)(0));
        node->SetAccumulatorAt(1, (::NiAccumulator *)(assets[1]), (const ::NiCamera *)(0));
        node->Dispatch(arg1, arg2, pEmitter, 1);

        if ((*reinterpret_cast<unsigned char *>(&::fnv_004e8ec0::DAT_011fffed)))
        {
            DAT_011ffffc = 0;
            HolderForAccum* handler = GetNode(nodes[2]);
            Emitter* secondary = emitters[2];
            handler->SetAccumulatorAt(0, (::NiAccumulator *)(void *)(&tex34), (const ::NiCamera *)(0));

            if ((unsigned int)DAT_011ada08 > 0)
            {
                if (!widget.m_pObject)
                {
                    NiPointer<NiScreenElementsData> spScreenData(
                        new NiScreenElementsData(false, false, 1, 1, 1, 4, 1, 2, 1));
                    widget = new NiScreenElements(spScreenData);

                    NiScreenElementsData* localData0 = widget->m_spTransformData;
                    reinterpret_cast<::NiScreenElementsDataShell *>((localData0))->FUN_00a87ae0(4, 0, (const unsigned short *)(0));
                    NiScreenElementsData* localData1 = widget->m_spTransformData;
                    localData1->SetRectangle(0, 0.0f, DAT_01013ea4, 1.0f, DAT_010542a4);
                    reinterpret_cast<::FUN_00a87900_class *>((widget->m_spTransformData))->FUN_00a87900();
                    NiScreenElementsData* localData2 = widget->m_spTransformData;
                    localData2->SetRectangleBounds(0, 0, 0.0f, 0.0f, 1.0f, 1.0f);
                    reinterpret_cast<::FUN_00a5a040_Class *>(((widget).operator->()))->FUN_00a5a040();

                    NiUpdateData kData(0.0f);
                    reinterpret_cast<::FUN_00a59c60_cls *>(((widget).operator->()))->FUN_00a59c60((int)(&kData));

                    ::AssignFixedString((char *)((widget).operator->()), 0, (char **)&(const ::NiFixedString &)(NiFixedString("Partial Screen Trishape")));
                }

                for (int i = 0; i < DAT_011ada08; ++i)
                {
                    NiPoint2* endpoint = &DAT_011ada14[i];
                    DAT_0120002c.x = DAT_011ada04[i].x - DAT_011ada14[i].x;
                    DAT_0120003c.x = DAT_011ada04[i].y - endpoint->y;
                    DAT_0120002c.z = DAT_011ada14[i].x;
                    NiPoint2 tangent;
                    tangent.x = -DAT_0120003c.x;
                    tangent.y = DAT_0120002c.x;
                    reinterpret_cast<::FUN_004e7560_shell *>(&(tangent))->NormalizeXY();
                    DAT_0120002c.y = tangent.x;
                    DAT_0120003c.y = tangent.y;
                    DAT_0120003c.z = endpoint->y;
                    reinterpret_cast<::H *>((secondary))->SetFloat4At(0, DAT_0120002c.x, DAT_0120002c.y, DAT_0120002c.z, DAT_0120002c.w);
                    reinterpret_cast<::H *>((secondary))->SetFloat4At(1, DAT_0120003c.x, DAT_0120003c.y, DAT_0120003c.z, DAT_0120003c.w);
                    handler->Dispatch(widget, arg2, secondary, 1);
                    ++DAT_011ffffc;
                }

                if (DAT_011ada04)
                {
                    Allocator* a = &DAT_011ada00;
                    a->Free(DAT_011ada04);
                    DAT_011ada04 = 0;
                    DAT_011ada0c = 0;
                    DAT_011ada08 = 0;
                }
                if (DAT_011ada14)
                {
                    Allocator* a = &DAT_011ada10;
                    a->Free(DAT_011ada14);
                    DAT_011ada14 = 0;
                    DAT_011ada1c = 0;
                    DAT_011ada18 = 0;
                }
            }
        }
    }

    (*reinterpret_cast<unsigned char *>(&::fnv_004e8ec0::DAT_01200000)) = 0;
    reinterpret_cast<::FUN_00ba3940_cls *>(&(tex44))->FUN_00ba3940((::FUN_00ba3940_cls *)(assets[1]));
    reinterpret_cast<::FUN_00ba3940_cls *>(&(tex54))->FUN_00ba3940((::FUN_00ba3940_cls *)(void *)(&tex34));
    reinterpret_cast<::FUN_00ba3940_cls *>(&(tex34))->FUN_00ba3940((::FUN_00ba3940_cls *)(void *)(&tex44));

    int frames = 0;
    while (time - previous > step)
    {
        previous = previous + step;
        if ((*reinterpret_cast<unsigned char *>(&::fnv_004e8ec0::DAT_011fffed)))
        {
            ++frames;
            HolderForAccum* node = GetNode(nodes[4]);
            Emitter* pEmitter = emitters[4];
            reinterpret_cast<::ImageSpaceShaderParam *>((pEmitter))->SetShaderConstantVector4(0, time, 0.0f, 0.0f, 0.0f);
            reinterpret_cast<::ImageSpaceShaderParam *>((pEmitter))->SetShaderConstantVector4(1, DAT_011ffff4, 0.0f, 0.0f, 0.0f);
            reinterpret_cast<::ImageSpaceShaderParam *>((pEmitter))->SetShaderConstantVector4(2, (*reinterpret_cast<::NiPoint2 *>(&::fnv_004e8ec0::DAT_01200024)).x, (*reinterpret_cast<::NiPoint2 *>(&::fnv_004e8ec0::DAT_01200024)).y, 0.0f, 0.0f);
            reinterpret_cast<::ImageSpaceShaderParam *>((pEmitter))->SetShaderConstantVector4(4, (*reinterpret_cast<::NiPoint4 *>(&::DAT_01200004)).x, (*reinterpret_cast<::NiPoint4 *>(&::DAT_01200004)).y, (*reinterpret_cast<::NiPoint4 *>(&::DAT_01200004)).z, (*reinterpret_cast<::NiPoint4 *>(&::DAT_01200004)).w);
            reinterpret_cast<::ImageSpaceShaderParam *>((pEmitter))->SetShaderConstantVector4(5, (*reinterpret_cast<::NiPoint4 *>(&::DAT_01200014)).x, (*reinterpret_cast<::NiPoint4 *>(&::DAT_01200014)).y, (*reinterpret_cast<::NiPoint4 *>(&::DAT_01200014)).z, (*reinterpret_cast<::NiPoint4 *>(&::DAT_01200014)).w);
            node->SetAccumulatorAt(0, (::NiAccumulator *)(void *)(&tex34), (const ::NiCamera *)(0));
            node->SetAccumulatorAt(1, (::NiAccumulator *)(void *)(&tex54), (const ::NiCamera *)(1));
            node->Dispatch(arg1, arg2, pEmitter, 1);
            (*reinterpret_cast<unsigned char *>(&::fnv_004e8ec0::DAT_01200000)) = 1;
            reinterpret_cast<::FUN_00ba3940_cls *>(&(tex44))->FUN_00ba3940((::FUN_00ba3940_cls *)(void *)(&tex54));
            reinterpret_cast<::FUN_00ba3940_cls *>(&(tex54))->FUN_00ba3940((::FUN_00ba3940_cls *)(void *)(&tex34));
            reinterpret_cast<::FUN_00ba3940_cls *>(&(tex34))->FUN_00ba3940((::FUN_00ba3940_cls *)(void *)(&tex44));
        }
    }

    if (frames % 2 == 0)
    {
        void* renderer = (*reinterpret_cast<void * *>(&::DAT_011f9508));
        ImageSpaceManager* pManager = DAT_011f91ac;
        reinterpret_cast<::BB97550Shader *>((pManager))->FUN_00b97550(0x22, (std::intptr_t)(renderer), (int)(((::BSRenderedTexture *)(reinterpret_cast<::FUN_00ba3770_struct *>(&(tex54))->FUN_00ba3770()))), (int)(((::BSRenderedTexture *)(reinterpret_cast<::FUN_00ba3770_struct *>(&(tex34))->FUN_00ba3770()))), 0, 1);
    }

    if (((void *)(reinterpret_cast<::FUN_00ba3780_struct *>(&(tex64))->FUN_00ba3780())))
    {
        reinterpret_cast<::H_00ba39a0 *>(&(tex64))->FUN_00ba39a0();
    }
}

struct TextureManager
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
    ImageSpaceTexture* unk40;
    ImageSpaceTexture* unk44;
    ImageSpaceTexture* unk48;
    ImageSpaceTexture* unk4C;
    ImageSpaceTexture* unk50;
    ImageSpaceTexture* unk54;
    ImageSpaceTexture* unk58;
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
    ImageSpaceTexture* unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    ImageSpaceTexture* unk104;
};

struct EffectInitData
{
    int unk00;
    int unk04;
    TextureManager* unk08;
};

template <class T> class NiTPrimitiveArray
{
  public:
    __declspec(noalias) void SetAt(unsigned int uiIndex, const T& element);
};

struct ImageSpaceEffect
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    NiTPrimitiveArray<ImageSpaceShaderParam*> m_params;

    void SetTextureArraySize(int count);

    void InitFromEffectInitData(EffectInitData* initData, int unused);
};

// Initializes the effect's texture array and shader parameters from the TextureManager fields in initData.
// @fnv 0x00ba4940
void ImageSpaceEffect::InitFromEffectInitData(EffectInitData* initData, int unused)
{
    SetTextureArraySize(11);

    ImageSpaceShaderParam* param = new ImageSpaceShaderParam();
    param->AllocateShaderConstants(0, 0x18);
    param->unk55 = 0;
    param->CopyParamData(3, DAT_011add48, 0x40);
    ImageSpaceTexture* texture = initData->unk08->unk104;
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(0, (::ImageSpaceEffect *)(texture), (::ImageSpaceEffectParam *)(param), 2);
    reinterpret_cast<::FUN_00a41520_cls *>(&(m_params))->FUN_00ba3aa0(0, (::KeyPair **)&(const ::ImageSpaceShaderParam *const &)(+param));
    ::SetEffectParamAt((char *)this, 0, 1, 1, {});

    reinterpret_cast<::FUN_00a41520_cls *>(&(m_params))->FUN_00ba3aa0(1, (::KeyPair **)&(const ::ImageSpaceShaderParam *const &)(0));
    reinterpret_cast<::FUN_00ba3b50_t *>(this)->SetArrayEntry(1, 2, 3, 0, 0);
    ImageSpaceTexture* texture1 = initData->unk08->unk40;
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(1, (::ImageSpaceEffect *)(texture1), (::ImageSpaceEffectParam *)(::ImageSpaceShaderParam *)(0), 2);

    reinterpret_cast<::FUN_00a41520_cls *>(&(m_params))->FUN_00ba3aa0(2, (::KeyPair **)&(const ::ImageSpaceShaderParam *const &)(0));
    reinterpret_cast<::FUN_00ba3b50_t *>(this)->SetArrayEntry(2, 2, 3, 0, 0);
    ImageSpaceTexture* texture2 = initData->unk08->unk44;
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(2, (::ImageSpaceEffect *)(texture2), (::ImageSpaceEffectParam *)(::ImageSpaceShaderParam *)(0), 2);

    reinterpret_cast<::FUN_00a41520_cls *>(&(m_params))->FUN_00ba3aa0(3, (::KeyPair **)&(const ::ImageSpaceShaderParam *const &)(0));
    reinterpret_cast<::FUN_00ba3b50_t *>(this)->SetArrayEntry(3, 2, 3, 0, 0);
    ImageSpaceTexture* texture3 = initData->unk08->unk48;
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(3, (::ImageSpaceEffect *)(texture3), (::ImageSpaceEffectParam *)(::ImageSpaceShaderParam *)(0), 2);

    reinterpret_cast<::FUN_00a41520_cls *>(&(m_params))->FUN_00ba3aa0(4, (::KeyPair **)&(const ::ImageSpaceShaderParam *const &)(0));
    reinterpret_cast<::FUN_00ba3b50_t *>(this)->SetArrayEntry(4, 2, 3, 0, 0);
    ImageSpaceTexture* texture4 = initData->unk08->unk4C;
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(4, (::ImageSpaceEffect *)(texture4), (::ImageSpaceEffectParam *)(::ImageSpaceShaderParam *)(0), 2);

    reinterpret_cast<::FUN_00a41520_cls *>(&(m_params))->FUN_00ba3aa0(5, (::KeyPair **)&(const ::ImageSpaceShaderParam *const &)(0));
    reinterpret_cast<::FUN_00ba3b50_t *>(this)->SetArrayEntry(5, 2, 3, 0, 0);
    ImageSpaceTexture* texture5 = initData->unk08->unk50;
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(5, (::ImageSpaceEffect *)(texture5), (::ImageSpaceEffectParam *)(::ImageSpaceShaderParam *)(0), 2);

    reinterpret_cast<::FUN_00a41520_cls *>(&(m_params))->FUN_00ba3aa0(6, (::KeyPair **)&(const ::ImageSpaceShaderParam *const &)(0));
    reinterpret_cast<::FUN_00ba3b50_t *>(this)->SetArrayEntry(6, 2, 3, 0, 0);
    ImageSpaceTexture* texture6 = initData->unk08->unk54;
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(6, (::ImageSpaceEffect *)(texture6), (::ImageSpaceEffectParam *)(::ImageSpaceShaderParam *)(0), 2);

    reinterpret_cast<::FUN_00a41520_cls *>(&(m_params))->FUN_00ba3aa0(7, (::KeyPair **)&(const ::ImageSpaceShaderParam *const &)(0));
    reinterpret_cast<::FUN_00ba3b50_t *>(this)->SetArrayEntry(7, 2, 3, 0, 0);
    ImageSpaceTexture* texture7 = initData->unk08->unk58;
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(7, (::ImageSpaceEffect *)(texture7), (::ImageSpaceEffectParam *)(::ImageSpaceShaderParam *)(0), 2);

    param = new ImageSpaceShaderParam();
    param->AllocateShaderConstants(0, 0x18);
    param->CopyParamData(3, DAT_011add48, 0x40);
    ImageSpaceTexture* texture8 = initData->unk08->unk104;
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(8, (::ImageSpaceEffect *)(texture8), (::ImageSpaceEffectParam *)(param), 0);
    reinterpret_cast<::FUN_00a41520_cls *>(&(m_params))->FUN_00ba3aa0(8, (::KeyPair **)&(const ::ImageSpaceShaderParam *const &)(+param));
    ::SetEffectParamAt((char *)this, 8, 2, 1, {});

    param = new ImageSpaceShaderParam();
    param->AllocateShaderConstants(0, 0x18);
    param->CopyParamData(3, DAT_011add48, 0x40);
    ImageSpaceTexture* texture9 = initData->unk08->unk104;
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(9, (::ImageSpaceEffect *)(texture9), (::ImageSpaceEffectParam *)(param), 0);
    reinterpret_cast<::FUN_00a41520_cls *>(&(m_params))->FUN_00ba3aa0(9, (::KeyPair **)&(const ::ImageSpaceShaderParam *const &)(+param));
    ::SetEffectParamAt((char *)this, 9, 2, 1, {});

    param = new ImageSpaceShaderParam();
    param->AllocateShaderConstants(0, 0x18);
    ImageSpaceTexture* texture10 = initData->unk08->unk88;
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(10, (::ImageSpaceEffect *)(texture10), (::ImageSpaceEffectParam *)(param), 0);
    reinterpret_cast<::FUN_00a41520_cls *>(&(m_params))->FUN_00ba3aa0(10, (::KeyPair **)&(const ::ImageSpaceShaderParam *const &)(+param));
    ::SetEffectParamAt((char *)this, 10, 1, 0, {});
}

namespace fnv_00ba04c0 {
class MemoryManager
{
  public:
};
class MemObj
{
  public:
};
class ImageSpaceEffectParam : public MemObj
{
};
class ImageSpaceShaderParam : public ImageSpaceEffectParam
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    char m_54;
    char m_55;
    char m_56;
    char m_57;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    ImageSpaceShaderParam();
};
struct Sub
{
    int f000;
    int f004;
    int f008;
    int f00c;
    int f010;
    int f014;
    int f018;
    int f01c;
    int f020;
    int f024;
    int f028;
    int f02c;
    int f030;
    int f034;
    int f038;
    int f03c;
    int f040;
    int f044;
    int f048;
    int f04c;
    int f050;
    int f054;
    int f058;
    int f05c;
    int f060;
    int f064;
    int f068;
    int f06c;
    int f070;
    int f074;
    int f078;
    int f07c;
    int f080;
    int f084;
    int f088;
    int f08c;
    int f090;
    int f094;
    int f098;
    int f09c;
    int f0a0;
    int f0a4;
    int f0a8;
    int f0ac;
    int f0b0;
    int f0b4;
    int f0b8;
    int f0bc;
    int f0c0;
    int f0c4;
    int f0c8;
    int f0cc;
    int f0d0;
    int f0d4;
    int f0d8;
    int f0dc;
    int f0e0;
    int f0e4;
    int f0e8;
    int f0ec;
    int f0f0;
    int f0f4;
    int f0f8;
    int f0fc;
    int f100;
    int f104;
    int f108;
    int f10c;
    int f110;
    int f114;
    int f118;
    int f11c;
    int f120;
    int f124;
    int f128;
    int f12c;
    int f130;
    int f134;
    int f138;
    int f13c;
    int f140;
    int f144;
    int f148;
    int f14c;
    int f150;
    int f154;
    int f158;
    int f15c;
    int f160;
    int f164;
    int f168;
    int f16c;
    int f170;
    int f174;
    int f178;
    int f17c;
    int f180;
    int f184;
    int f188;
    int f18c;
    int f190;
    int f194;
    int f198;
    int f19c;
    int f1a0;
    int f1a4;
    int f1a8;
    int f1ac;
    int f1b0;
    int f1b4;
    int f1b8;
    int f1bc;
    int f1c0;
    int f1c4;
};
struct Src
{
    int m_00;
    int m_04;
    Sub* m_08;
};
class Arr18
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};
class Arr28
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};
class ImageSpaceEffect
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    Arr18 m_18;
    Arr28 m_28;
    void InitFromConfig(Src* config, int unused);
};
// Initializes nine ImageSpaceShaderParam entries with values from config->m_08 fields f1a4 through f1c4, setting texture array size to 9.
// @fnv 0x00ba04c0
void ImageSpaceEffect::InitFromConfig(Src* config, int unused)
{
    reinterpret_cast<::ImageSpaceEffect *>(this)->SetTextureArraySize(9);
    reinterpret_cast<::FUN_00a41520_cls *>(&(m_28))->FUN_00a90180(2);
    {
        ImageSpaceShaderParam* param;
        param = new ImageSpaceShaderParam;
        reinterpret_cast<::ImageSpaceShaderParam *>((param))->AllocateShaderConstants(2, 6);
        param->m_55 = 0;
        reinterpret_cast<::ImageSpaceShaderParam *>((param))->FUN_00b8a7c0();
        reinterpret_cast<::FUN_00a41520_cls *>(&(m_18))->FUN_00ba3aa0(0, (::KeyPair **)&(param));
        int value = config->m_08->f1a4;
        reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(0, (::ImageSpaceEffect *)(value), (::ImageSpaceEffectParam *)(param), 0);
    }
    {
        ImageSpaceShaderParam* param;
        param = new ImageSpaceShaderParam;
        reinterpret_cast<::ImageSpaceShaderParam *>((param))->AllocateShaderConstants(2, 6);
        param->m_55 = 0;
        reinterpret_cast<::ImageSpaceShaderParam *>((param))->FUN_00b8a7c0();
        reinterpret_cast<::FUN_00a41520_cls *>(&(m_18))->FUN_00ba3aa0(1, (::KeyPair **)&(param));
        int value = config->m_08->f1a8;
        reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(1, (::ImageSpaceEffect *)(value), (::ImageSpaceEffectParam *)(param), 0);
    }
    {
        ImageSpaceShaderParam* param;
        param = new ImageSpaceShaderParam;
        reinterpret_cast<::ImageSpaceShaderParam *>((param))->AllocateShaderConstants(2, 6);
        param->m_55 = 0;

        reinterpret_cast<::FUN_00a41520_cls *>(&(m_18))->FUN_00ba3aa0(2, (::KeyPair **)&(param));
        int value = config->m_08->f1ac;
        reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(2, (::ImageSpaceEffect *)(value), (::ImageSpaceEffectParam *)(param), 0);
    }
    {
        ImageSpaceShaderParam* param;
        param = new ImageSpaceShaderParam;
        reinterpret_cast<::ImageSpaceShaderParam *>((param))->AllocateShaderConstants(2, 6);
        param->m_55 = 0;

        reinterpret_cast<::FUN_00a41520_cls *>(&(m_18))->FUN_00ba3aa0(3, (::KeyPair **)&(param));
        int value = config->m_08->f1b0;
        reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(3, (::ImageSpaceEffect *)(value), (::ImageSpaceEffectParam *)(param), 0);
    }
    {
        ImageSpaceShaderParam* param;
        param = new ImageSpaceShaderParam;
        reinterpret_cast<::ImageSpaceShaderParam *>((param))->AllocateShaderConstants(2, 6);
        param->m_55 = 0;

        reinterpret_cast<::FUN_00a41520_cls *>(&(m_18))->FUN_00ba3aa0(4, (::KeyPair **)&(param));
        int value = config->m_08->f1b4;
        reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(4, (::ImageSpaceEffect *)(value), (::ImageSpaceEffectParam *)(param), 0);
    }
    {
        ImageSpaceShaderParam* param;
        param = new ImageSpaceShaderParam;
        reinterpret_cast<::ImageSpaceShaderParam *>((param))->AllocateShaderConstants(2, 6);
        param->m_55 = 0;

        reinterpret_cast<::FUN_00a41520_cls *>(&(m_18))->FUN_00ba3aa0(5, (::KeyPair **)&(param));
        int value = config->m_08->f1b8;
        reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(5, (::ImageSpaceEffect *)(value), (::ImageSpaceEffectParam *)(param), 0);
    }
    {
        ImageSpaceShaderParam* param;
        param = new ImageSpaceShaderParam;
        reinterpret_cast<::ImageSpaceShaderParam *>((param))->AllocateShaderConstants(2, 6);
        param->m_55 = 0;
        reinterpret_cast<::ImageSpaceShaderParam *>((param))->FUN_00b8a7c0();
        reinterpret_cast<::FUN_00a41520_cls *>(&(m_18))->FUN_00ba3aa0(6, (::KeyPair **)&(param));
        int value = config->m_08->f1bc;
        reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(6, (::ImageSpaceEffect *)(value), (::ImageSpaceEffectParam *)(param), 0);
    }
    {
        ImageSpaceShaderParam* param;
        param = new ImageSpaceShaderParam;
        reinterpret_cast<::ImageSpaceShaderParam *>((param))->AllocateShaderConstants(2, 6);
        param->m_55 = 0;
        reinterpret_cast<::ImageSpaceShaderParam *>((param))->FUN_00b8a7c0();
        reinterpret_cast<::FUN_00a41520_cls *>(&(m_18))->FUN_00ba3aa0(7, (::KeyPair **)&(param));
        int value = config->m_08->f1c0;
        reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(7, (::ImageSpaceEffect *)(value), (::ImageSpaceEffectParam *)(param), 0);
    }
    {
        ImageSpaceShaderParam* param;
        param = new ImageSpaceShaderParam;
        reinterpret_cast<::ImageSpaceShaderParam *>((param))->AllocateShaderConstants(2, 6);
        param->m_55 = 0;
        reinterpret_cast<::ImageSpaceShaderParam *>((param))->FUN_00b8a7c0();
        reinterpret_cast<::FUN_00a41520_cls *>(&(m_18))->FUN_00ba3aa0(8, (::KeyPair **)&(param));
        int value = config->m_08->f1c4;
        reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(8, (::ImageSpaceEffect *)(value), (::ImageSpaceEffectParam *)(param), 0);
    }
}
}  // namespace fnv_00ba04c0

#include <math.h>
extern float DAT_012003d0;
extern int DAT_011ff9f0;


// Image-space effects share this virtual render interface (slot 4).
struct DrawOwner384
{
    virtual void v0();
    // The final argument is a boolean forwarded to each sub-effect.
    virtual void Draw(void* a1, void* a2, void* a3, bool a4);
    virtual void v2();
    virtual void v3();
    virtual void Begin(void* a3);
    virtual void End();
    virtual void v6();
    virtual void Bind(void* a3);
    int unk04;
    int unk08;
    DrawOwner384** m_parts;
    int unk10;
    int unk14;
    int unk18;
    void** m_data;
};

// Begins a draw pass, iterates over m_parts to recursively draw, and ends the pass.
// @fnv 0x00ba4d20
void DrawOwner384::Draw(void* apArg1, void* apArg2, void* a3, bool abFlag)
{
    Begin(a3);
    float t = (float)ceil(DAT_012003d0);
    int n = (int)t;
    if (DAT_012003d4 != (*reinterpret_cast<float *>(&::DAT_011a9490)) || DAT_012003d8 != DAT_011a9494 || DAT_012003dc != DAT_011a9498)
    {
        if (DAT_012003cc && DAT_011f94a9 && n < 2)
            n = 2;
    }
    for (int i = 0; i < 8; i++)
    {
        if (i < 1 || i == n)
        {
            reinterpret_cast<::ImageSpaceManagerView *>(this)->SetEffectParams(i);
            Bind(a3);
            m_parts[i]->Draw(apArg1, apArg2, m_data[i], abFlag);
        }
    }
    int iFinalIndex;
    if (DAT_012003d0 < 1.0f)
    {
        reinterpret_cast<::ImageSpaceManagerView *>(this)->SetEffectParams(10);
        Bind(a3);
        m_parts[10]->Draw(apArg1, apArg2, m_data[10], abFlag);
        if (DAT_012003d0 < 1.0f)
        {
            iFinalIndex = 9;
            ::BSRenderStateManager::SetDepthBufferEnabled(1, (::BSRENDERSTATE_LOCK)(1));
            AddToTwoCounters(6, 7, 0);
        }
        else
        {
            iFinalIndex = 8;
        }
    }
    else
    {
        iFinalIndex = 8;
    }
    reinterpret_cast<::ImageSpaceManagerView *>(this)->SetEffectParams(iFinalIndex);
    Bind(a3);
    m_parts[iFinalIndex]->Draw(apArg1, apArg2, m_data[iFinalIndex], abFlag);
    if (DAT_012003d0 < 1.0f)
    {
        DAT_011ff9f0--;
        ::BSRenderStateManager::SetDepthBufferEnabled(0, (::BSRENDERSTATE_LOCK)(0));
    }
    End();
}

#include "generated/data/bsshader/imagespaceeffectwaterdisplacement.inc"
