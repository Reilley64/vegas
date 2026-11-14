#pragma once
// The gsk agents' data. Offsets are the 32-bit release's. FUN_00dabf10 (hkpgskbaseagent.cpp) builds the base agent.

#include <xmmintrin.h>

struct GskNode;

struct hkpGskCache
{
    unsigned short m_vertices[4];  // +0x0
    unsigned char m_dimA;          // +0x8
    unsigned char m_dimB;          // +0x9
    unsigned char m_maxDimA;       // +0xa
    unsigned char m_gskFlags;      // +0xb
};

struct hkpGskManifold
{
    struct ContactPoint
    {
        unsigned char m_dimA;
        unsigned char m_dimB;
        unsigned short m_id;  // +0x2
        unsigned char m_vert[4];
    };

    unsigned char m_numVertsA;         // +0x0
    unsigned char m_numVertsB;         // +0x1
    unsigned char m_numContactPoints;  // +0x2
    unsigned char m_reserved;          // +0x3
    ContactPoint m_contactPoints[4];   // +0x4
    unsigned short m_vertexIds[16];    // +0x24
};

// hkpGskBaseAgent, 0x30 bytes on 32-bit.
struct __declspec(align(16)) hkpGskBaseAgent
{
    const void* m_vtable;              // +0x00
    unsigned short m_memSizeAndFlags;  // +0x04
    short m_referenceCount;            // +0x06
    void* m_contactMgr;                // +0x08
    hkpGskCache m_cache;               // +0x0c
    float m_timeOfSeparatingNormal;    // +0x18
    float m_allowedPenetration;        // +0x1c
    __m128 m_separatingNormal;         // +0x20, w is the separating distance
};

// hkpGskfAgent, 0x80 bytes on 32-bit.
struct hkpGskfAgent : hkpGskBaseAgent
{
    hkpGskManifold m_manifold;  // +0x30

    // 0x00dacbd0
    hkpGskfAgent(GskNode* bodyA, GskNode* bodyB, void* contactMgr);

    void FUN_00dacb20(unsigned short id);
    void AddPotential(unsigned short value);
};
