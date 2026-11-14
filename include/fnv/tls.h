#ifndef FNV_TLS_H
#define FNV_TLS_H

class BaseExtraList;
class BSExtraData;
class NiAVObject;
class Script;
struct ScriptLocals;
class ScriptLocalVariable;
class ScriptReferencedObject;
class TESForm;
class TESObjectREFR;

// The game module's thread-local data. The original keeps it in one .tls
// section that the loader copies for every thread, and its code reads the
// copy as one block (the TEB TLS pointer indexed by the module's TLS index).
// The comments give each field's offset in that 32-bit block; on x64 the
// pointers widen and the later offsets move.
struct TlsBlock_t
{
    unsigned char crtTlsStart[8];                 // 0x000 the CRT's _tls_start byte and alignment
    BaseExtraList* extraDataCacheList;            // 0x008 list whose extra data extraDataCache holds
    int extraDataCacheClearCount;                 // 0x00c
    BSExtraData* extraDataCache[0x93];            // 0x010 indexed by extra data type
    bool loadTexturesDegraded;                    // 0x25c
    bool flag25d;                                 // 0x25d read by 0x00551680, set by 0x005516a0
    unsigned char pad25e[2];                      // 0x25e
    NiAVObject* loading3D;                        // 0x260 set with loading3DRef by 0x00441780
    TESObjectREFR* loading3DRef;                  // 0x264
    bool conditionFunctionDebug;                  // 0x268 condition and script functions log their results
    unsigned char pad269[3];                      // 0x269
    TESForm* conditionTarget;                     // 0x26c compared by the condition function at 0x005a3460
    ScriptLocalVariable* lastLocalVariable;       // 0x270 script local variable lookup cache
    unsigned int lastLocalVariableId;             // 0x274
    ScriptLocals* lastLocalVariableLocals;        // 0x278
    ScriptReferencedObject* lastRefObject;        // 0x27c script referenced object lookup cache
    unsigned int lastRefObjectIndex;              // 0x280
    ScriptLocals* lastRefObjectLocals;            // 0x284
    Script* lastRefObjectScript;                  // 0x288
    unsigned int activateDepth;                   // 0x28c nesting of the Activate script function
    int scriptCommandDepth;                       // 0x290 nesting of the script function at 0x005d8cf0, at most 5
    unsigned int threadFlags;                     // 0x294 bit 0 data handler, bit 1 save/load, bit 2 extra data changes
    bool flag298;                                 // 0x298 set by 0x00869190
    unsigned char pad299[3];                      // 0x299
    unsigned int textureLoadMethod;               // 0x29c
    float timeControllerLastScaledTime;           // 0x2a0 NiTimeController scaled time cache
    unsigned int timeControllerLastCycleType;     // 0x2a4
    float timeControllerLastTime;                 // 0x2a8
    float timeControllerLastLoKeyTime;            // 0x2ac
    float timeControllerLastHiKeyTime;            // 0x2b0
    int memoryContext;                            // 0x2b4 allocation context the memory manager files new blocks under
    unsigned int messageWarningDisableCount;      // 0x2b8 MessageHandler warnings stay queued while non-zero
    unsigned int renderThreadIndex;               // 0x2bc selects this thread's shader accumulator and renderer
    int collisionUpdateMode;                      // 0x2c0 read by the collision objects' node updates
    unsigned char crtTlsEnd;                      // 0x2c4 the CRT's _tls_end byte
};

extern thread_local TlsBlock_t g_tlsBlock;

#endif
