// Authored layout header for fallout/interface/menuconsole.cpp.
//
// The NiTList<BSStringT<char>> machinery and the ConsoleManager body layout below
// assert. The member-function declarations (ConsoleManager/Init/Instance,
// pInstance) and the minimal ScriptCompiler declaration are the only additions
// needed to compile this unit; they do not change the layout.
#ifndef FNV_MENUCONSOLE_IDLE_H
#define FNV_MENUCONSOLE_IDLE_H

#include "fnv/decl/ConsoleText.h"
#include "fnv/decl/FUN_007b52d0_cls.h"
#include "fnv/decl/S71df20.h"
#include "menuconsole_support.h"

class DFALL_NiTListItem_BSStringT_char_____;
class ConsoleManager;
class NiTList_BSStringT_char___;
class NiTListBase_DFALL_NiTListItem_BSStringT_char______BSStringT_char___;
class NiTListBase_DFALL_NiTListItem_BSStringT_char______BSStringT_char_____AntiBloatAllocator;
class NiTListItem_BSStringT_char___;
class NiTPointerListBase_DFALL_NiTListItem_BSStringT_char______BSStringT_char___;

// ScriptCompiler is only referenced here through a pointer and a single
// `new ScriptCompiler` allocation; its full declaration lives outside this
// unit, so only the size-1 shape and the default constructor are declared.
class ScriptCompiler
{
  public:
    ScriptCompiler();
};

class DFALL_NiTListItem_BSStringT_char_____
{
  public:
    // void* __cdecl DFALL<NiTListItem<BSStringT<char> > >::*()
    // void __cdecl DFALL<NiTListItem<BSStringT<char> > >::*(void*)
};
class NiTListBase_DFALL_NiTListItem_BSStringT_char______BSStringT_char_____AntiBloatAllocator
    : public DFALL_NiTListItem_BSStringT_char_____
{
  public:
    // base DFALL<NiTListItem<BSStringT<char> > > at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
class NiTListBase_DFALL_NiTListItem_BSStringT_char______BSStringT_char___
{
  public:
    BSStringT<char>& AddEight(void*);
    BSStringT<char> PopFront();
    NiTListItem_BSStringT_char___* m_pkHead;  // +0x0, 4 bytes
    NiTListItem_BSStringT_char___* m_pkTail;  // +0x4, 4 bytes
    NiTListBase_DFALL_NiTListItem_BSStringT_char______BSStringT_char_____AntiBloatAllocator
        m_kItemCount;  // +0x8, 4 bytes
    // unsigned int __cdecl NiTListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*()
    // bool __cdecl NiTListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*()
    // void* __cdecl NiTListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*()
    // void* __cdecl NiTListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*()
    // void* __cdecl NiTListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(void*)
    // void* __cdecl NiTListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(void*)
    // void __cdecl NiTListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(void*, void*)
    // void __cdecl NiTListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(void*, void*)
    // NiTListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >
    // void __cdecl NiTListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*()
    // void __cdecl NiTListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(NiTListItem<BSStringT<char> >*)
    // void __cdecl NiTListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(NiTListItem<BSStringT<char> >*)
    // void* __cdecl NiTListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(void*, NiTListItem<BSStringT<char> >*)
    // void* __cdecl NiTListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(void*, NiTListItem<BSStringT<char> >*)
    // NiTListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >& __cdecl NiTListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(const NiTListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >&)
    // void* __cdecl NiTListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(unsigned int)
};
class NiTPointerListBase_DFALL_NiTListItem_BSStringT_char______BSStringT_char___
    : public NiTListBase_DFALL_NiTListItem_BSStringT_char______BSStringT_char___
{
  public:
    // base NiTListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> > at +0x0, size 12
    // void __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*()
    // void __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(const BSStringT<char>&)
    // void __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(const BSStringT<char>&)
    // void* __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(void*, const BSStringT<char>&)
    // void* __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(void*, const BSStringT<char>&)
    // const BSStringT<char>& __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*()
    // const BSStringT<char>& __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*()
    // const BSStringT<char>& __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(void*)
    // const BSStringT<char>& __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(void*&)
    // const BSStringT<char>& __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(void*&)
    // BSStringT<char> __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*()
    // BSStringT<char> __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*()
    // BSStringT<char> __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(const BSStringT<char>&)
    // BSStringT<char> __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(void*&)
    // void* __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(const BSStringT<char>&, void*)
    // void __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*()
    // void __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(int __cdecl (void*, void*)*)
    // NiTListItem<BSStringT<char> >* __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*()
    // void __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(NiTListItem<BSStringT<char> >*)
    // NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >
    // NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >& __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(const NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >&)
    // void* __cdecl NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> >::*(unsigned int)
};
class NiTList_BSStringT_char___ : public NiTPointerListBase_DFALL_NiTListItem_BSStringT_char______BSStringT_char___
{
  public:
    // base NiTPointerListBase<DFALL<NiTListItem<BSStringT<char> > >,BSStringT<char> > at +0x0, size 12
    // NiTList<BSStringT<char> >
    // void __cdecl NiTList<BSStringT<char> >::*()
    // NiTList<BSStringT<char> >& __cdecl NiTList<BSStringT<char> >::*(const NiTList<BSStringT<char> >&)
    // void* __cdecl NiTList<BSStringT<char> >::*(unsigned int)
};
class ConsoleManager
{
  public:
    ScriptCompiler* m_pScriptCompiler;            // +0x0, 4 bytes
    NiTList_BSStringT_char___ m_kOutputLines;     // +0x4, 12 bytes
    NiTList_BSStringT_char___ m_kCommandHistory;  // +0x10, 12 bytes
    int m_iCommandHistoryPosition;                // +0x1C, 4 bytes
    int m_iScrollPosition;                        // +0x20, 4 bytes
    int m_iOutputLineCount;                       // +0x24, 4 bytes
    bool m_bVisible;                              // +0x28, 1 bytes
    unsigned char layoutPadding29[3];
    int iConsoleLineSpacing;  // +0x2C, 4 bytes
    int m_iConsoleX;          // +0x30, 4 bytes
    int m_iConsoleY;          // +0x34, 4 bytes
    char cVisible;            // +0x38, 1 bytes
    bool bIsActive;           // +0x39, 1 bytes
    bool m_bRecordingBatch;   // +0x3A, 1 bytes
    unsigned char layoutPadding3B[1];
    int m_iBatchCommandCount;           // +0x3C, 4 bytes
    char m_aacCommandHistory[20][100];  // +0x40, 2000 bytes
    char m_acOutputFilename[260];       // +0x810, 260 bytes

    bool Idle(int);
    void ResetOutputState();
    static ConsoleManager* Instance(bool bCreate);

  private:
    // Singleton storage; the constructor is private like the rest of the
    ConsoleManager();
    void Init();
    static ConsoleManager* pInstance;
};
#endif
