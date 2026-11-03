#pragma once

class BaseExtraList;
namespace fnv_00c9bef0 { struct TlsBlock_t; }
struct TlsBlock_t;

// 0x01272000
extern thread_local ::TlsBlock_t g_tlsBlock;
// 0x01272004
namespace fnv_00c9bef0 { extern __declspec(thread) ::fnv_00c9bef0::TlsBlock_t g_tlsBlock; }
// 0x01272008
namespace fnv_anon_extradatalist { extern thread_local ::BaseExtraList *tls_pList; }
// 0x0127200c
extern thread_local int tls_clearCount;
// 0x01272010
extern thread_local char tls_buffer[588];
// 0x01272264
extern __declspec(thread) int DAT_tls_0264;
// 0x01272298
extern __declspec(thread) bool g_tls_0298;
// 0x012722b4
extern unsigned int currentAllocationContext;
// 0x012722bc
extern int DAT_012722bc;
