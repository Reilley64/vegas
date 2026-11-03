#pragma once
// The shape collection agent (hkpShapeCollectionAgent, 0x38 bytes on 32-bit): a collision agent that keeps one child
// agent per shape key of body A's shape container that the collision filter accepts. FUN_00d440f0 constructs it.

struct AgentS;
struct CdBodyS;
struct CollisionInputS;
struct ContactMgrS;

struct hkpShapeCollectionAgent
{
    struct KeyAgentPair
    {
        unsigned int m_key;
        AgentS* m_pCollisionAgent;
    };

    virtual void r00();
    virtual void a01();
    virtual void a02();

    unsigned short m_usMemSizeAndFlags;  // +0x04
    unsigned short m_sReferenceCount;    // +0x06
    ContactMgrS* m_pContactManager;      // +0x08
    // hkInplaceArray<KeyAgentPair, 4>
    KeyAgentPair* m_agents;           // +0x0c
    int m_numAgents;                  // +0x10
    int m_agentsCapacityAndFlags;     // +0x14
    KeyAgentPair m_agentStorage[4];   // +0x18

    void FUN_00d436f0(int arg);
};

struct FUN_00d440f0 : hkpShapeCollectionAgent
{
    // 0x00d440f0
    FUN_00d440f0(const ::CdBodyS& bodyA, const ::CdBodyS& bodyB, const ::CollisionInputS& input, ::ContactMgrS* mgr);
};
