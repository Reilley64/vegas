#pragma once

#include <cstdint>

struct Body;
struct Buffers;
struct ChainInstance;
struct ConstIter;
struct Form;
struct Listener;
struct Node;
struct StrArr;
struct Value;
struct hkVector4;

struct Obj {
public:
    // 0x00613b60
    void FUN_00613b60(int, int, const char *);
    // 0x0095ea30
    void ApplyFormPayload(::Form *, int);
    // 0x00a7bd60
    void AppendTriListInfo(::StrArr *);
    // 0x00b32de0
    void FUN_00b32de0(unsigned int, ::Value);
    // 0x00b34450
    void FUN_00b34450(::ConstIter, unsigned int, const ::Value &);
    // 0x00c85810
    bool FUN_00c85810(::Obj *);
    // 0x00cb23e0
    void FUN_00cb23e0(intptr_t);
    // 0x00d05190
    int ForwardWithZero(int, int);
    // 0x00dbe790
    void WriteVarint(long long);
    // 0x00de6390
    void FireChainConstraints(::ChainInstance *, ::Listener *, int, int);
    // 0x00de8090
    void FireMotionEvent(::Body *, ::Listener *, int, int);
    // 0x00dfaf80
    void SetEntries(const ::hkVector4 *, const ::hkVector4 *, const ::hkVector4 *);
    // 0x00e09970
    void FUN_00e09970(::Node *, int *, float *);
    // 0x00e42b00
    void ComputeBufferLayout(char *, int, ::Buffers *) const;
    // 0x00ee82b0
    void FUN_00ee82b0();
};
