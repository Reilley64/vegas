// include/havok/hkpCollisionDispatcher.h - the collision dispatcher's agent tables (hkpCollisionDispatcher).
#ifndef FNV_HAVOK_HKPCOLLISIONDISPATCHER_H
#define FNV_HAVOK_HKPCOLLISIONDISPATCHER_H

struct IntegerPair;
struct CollisionAgentEntry;

// Offsets are the 32-bit release's.
struct hkpCollisionDispatcher
{
    // The agent2 functions of one agent type (20 bytes).
    struct AgentFuncs
    {
        void* m_createFunc;            // +0x0
        void* m_getPenetrationsFunc;   // +0x4
        void* m_getClosestPointsFunc;  // +0x8
        void* m_linearCastFunc;        // +0xc
        unsigned char m_isFlipped;     // +0x10
        unsigned char m_isPredictive;  // +0x11
    };

    // The agent3 functions of one agent type.
    struct alignas(16) Agent3Funcs
    {
        void* m_createFunc;                  // +0x0
        void* m_destroyFunc;                 // +0x4
        void* m_cleanupFunc;                 // +0x8
        void* m_removePointFunc;             // +0xc
        void* m_commitPotentialFunc;         // +0x10
        void* m_createZombieFunc;            // +0x14
        void* m_updateFilterFunc;            // +0x18
        void* m_calcStatisticsFunc;          // +0x1c
        void* m_invalidateTimFunc;           // +0x20
        void* m_warpTimeFunc;                // +0x24
        void* m_sepNormalFunc;               // +0x28
        void* m_processFunc;                 // +0x2c
        unsigned char m_isPredictive;        // +0x30
        unsigned char m_ignoreSymmetricVersion; // +0x31
        unsigned char m_reusePreviousEntry;  // +0x32
    };

    enum Symmetric
    {
        IS_SYMMETRIC,
        IS_NOT_SYMMETRIC,
        IS_NOT_SYMMETRIC_AND_FLIPPED
    };

    // One agent3 table entry (80 bytes).
    struct Agent3FuncsIntern : Agent3Funcs
    {
        alignas(16) int m_symmetric;  // +0x40, a Symmetric
    };

    // One collision quality (0x40 bytes).
    struct alignas(16) CollisionQualityInfo
    {
        float m_minimumCollisionSeparation;  // +0x0
        float m_maximumExtraSeparation;      // +0x4
        float m_minimumExtraSeparation;      // +0x8
        float m_timeOfImpactSeparation;      // +0xc
        int m_qualityInfoValue10;            // +0x10
        unsigned int m_14;
        float m_18[9];
        unsigned short m_valueAt3C;          // +0x3c
        unsigned char m_3e;
        unsigned char m_3f;
    };

    const void* m_vtable;                                   // +0x0
    unsigned short m_memSizeAndFlags;                       // +0x4
    unsigned short m_referenceCount;                        // +0x6
    void* m_08;                                             // +0x8
    void* m_contactMgrFactory[8][8];                        // +0xc
    int m_10c;                                              // +0x10c
    unsigned int m_hasAlternateType[32];                    // +0x110
    int m_numAgent2Types;                                   // +0x190
    alignas(16) signed char m_agent2Types[32][32];          // +0x1a0
    signed char m_agent2TypesPred[32][32];                  // +0x5a0
    AgentFuncs m_agent2Func[64];                            // +0x9a0
    int m_numAgent3Types;                                   // +0xea0
    alignas(16) signed char m_agent3Types[32][32];          // +0xeb0
    signed char m_agent3TypesPred[32][32];                  // +0x12b0
    Agent3FuncsIntern m_agent3Func[16];                     // +0x16b0
    signed char m_collisionQualityTable[10][10];            // +0x1bb0
    CollisionQualityInfo m_collisionQualityInfo[8];         // +0x1c20
    unsigned char m_enableDeprecatedFeature;                // +0x1e20
    unsigned char m_1e21;
    unsigned char m_1e22;
    unsigned char m_debugWarnings;                          // +0x1e23
    IntegerPair* m_shapeInheritance;                        // +0x1e24
    int m_numShapeInheritance;                              // +0x1e28
    int m_shapeInheritanceCapacity;                         // +0x1e2c
    CollisionAgentEntry (*m_debugAgent2Table)[32];          // +0x1e30
    CollisionAgentEntry (*m_debugAgent2TablePred)[32];      // +0x1e34
    CollisionAgentEntry (*m_debugAgent3Table)[32];          // +0x1e38
    CollisionAgentEntry (*m_debugAgent3TablePred)[32];      // +0x1e3c

    unsigned int hasAlternateType(int type, int alternateType) const
    {
        return m_hasAlternateType[type] & (1u << alternateType);
    }

    void RegisterAgentType(signed char (*table)[32], signed char agentType, int typeA, int typeB, signed char origA,
                           signed char origB, CollisionAgentEntry (*entries)[32], int depth);
};

#endif
