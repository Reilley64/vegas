
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkppointtopathdrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkppointtopathdrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <xmmintrin.h>
#include "fnv/decl/CpuObject.h"
#include "fnv/decl/DE44C0Object.h"
#include "fnv/decl/FUN_00de4530Owner.h"
#include "fnv/decl/FUN_00dee820_Class.h"
#include "fnv/symbols_00cab000.h"
#include "fnv/symbols_01016000.h"

struct hkTransform;

struct hkVector4
{
    __m128 m_vComponents;
    hkVector4()
    {}
    hkVector4(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void FUN_00c7f640(const hkTransform& t, const hkVector4& v);
};

struct hkTransform
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4 m_vTranslation;
    void FUN_00cb2240(const hkTransform& a, const hkTransform& b);
};

struct hkMemoryAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct NineIntegerRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocator* m_pStreamAllocator;
    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
static inline NineIntegerRecord* getMemoryRouter() { return static_cast<NineIntegerRecord*>(::FUN_00c85750()); }

struct hkVector4Array
{
    hkVector4* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkVector4Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    void ClearAndRelease(hkMemoryAllocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(hkVector4));
    }
};

struct PointSource
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void getPoints(hkVector4Array& points);
};

struct BoneTransformData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    PointSource* m_kPoints;
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
    hkTransform m_kMotionTransform;
};

struct ExtraData
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
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    hkVector4 m_endPoint;
};

struct Input
{
    int unk00;
    int unk04;
    int unk08;
    BoneTransformData* m_scene;
    int unk10;
    ExtraData* m_extra;
};

struct LineDrawer
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void drawLine(const hkVector4& a, const hkVector4& b, int color, int id, int tag);
};


struct Processor
{
};

struct Viewer
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
    hkVector4 m_endPoint;
    hkVector4 m_vContactPosition;
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
    int unkb8;
    int unkbc;
    Processor m_processor;

    void FUN_00de47e0(Input* input, hkTransform* transform, hkTransform* extra);
    void FUN_00de7020(Input* input, LineDrawer* drawer, int id, int tag);
};

// Runs several viewer update steps, then draws lines between consecutive points of the scene's point source, transformed to world space, using drawer.
// @fnv 0x00de7020
void Viewer::FUN_00de7020(Input* input, LineDrawer* drawer, int id, int tag)
{
    BoneTransformData* scene = input->m_scene;
    hkTransform localTransform;
    hkTransform worldTransform;
    hkTransform extraTransform;

    reinterpret_cast<::CpuObject *>(&(m_processor))->FUN_00e10a10((drawer));
    FUN_00de47e0(input, &localTransform, &extraTransform);
    m_vContactPosition = localTransform.m_vTranslation;
    reinterpret_cast<::FUN_00dee820_Class *>((scene))->FUN_00dee820((unsigned int)(&input->m_extra->m_endPoint), (::FUN_00c7f640_Class *)(::hkVector4 *)(&m_endPoint));
    reinterpret_cast<::FUN_00de4530Owner *>(this)->FUN_00de4530(id, tag);
    reinterpret_cast<::DE44C0Object *>(this)->FUN_00de44c0(id, tag);

    if (scene->m_kPoints)
    {
        worldTransform.FUN_00cb2240(localTransform, scene->m_kMotionTransform);
        PointSource* source = scene->m_kPoints;
        if (source)
        {
            hkVector4Array points;
            source->getPoints(points);
            int numPoints = points.m_iElementCount;
            for (int i = 1; i < numPoints; i++)
            {
                hkVector4 a;
                hkVector4 b;
                hkVector4 p = points.m_data[i];
                a.FUN_00c7f640(worldTransform, p);
                p = points.m_data[i - 1];
                b.FUN_00c7f640(worldTransform, p);
                drawer->drawLine(a, b, ((int)(::PackColorBigEndian(0.0f, DAT_0101622c, 1.0f, 1.0f))), id, tag);
            }
            points.ClearAndRelease(getMemoryRouter()->heap());
        }
    }
}
