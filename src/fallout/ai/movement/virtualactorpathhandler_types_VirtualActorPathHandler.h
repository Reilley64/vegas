// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_VIRTUALACTORPATHHANDLER_DECLS_H
#define FNV_VIRTUALACTORPATHHANDLER_DECLS_H

#include "fnv/decl/FUN_009dfe40_cls.h"
#include "layout_support.h"
#include "Actor.h"
#include "layout_support.h"
class ActorPathHandler;
class PathingRequest;
class PathingSolution;
class BGSLoadFormBuffer;
class VirtualActorPathHandler;
class ActorPathHandler
{
  public:
    void** m_ppVirtualMethodTable;                                      // +0x0, 4 bytes
    Actor* pActor;                                        // +0x4, 4 bytes
    ActorMover* m_pActorMover;                            // +0x8, 4 bytes
    PathingRef<PathingSolution> pCurrentPathingSolution;  // +0xC, 4 bytes
    PathingRef<PathingRequest> m_pPathingRequest;         // +0x10, 4 bytes
    // ActorPathHandler
    // ActorPathHandler& __cdecl ActorPathHandler::*(const ActorPathHandler&)
};
class VirtualActorPathHandler : public ActorPathHandler
{
  public:
    VirtualActorPathHandler(Actor*, ActorMover*, NiPointer<PathingSolution>&, PathingRequest*);
    void SetInitialPathState();
    void LoadGame(BGSLoadFormBuffer*);
    int Init(float, float);
    // base ActorPathHandler at +0x0, size 20
    unsigned int m_uiPathPointIndex;  // +0x14, 4 bytes
    float m_fPathValue16;             // +0x18, 4 bytes
    float m_fPathValue2;              // +0x1C, 4 bytes
    // VirtualActorPathHandler
    // void __cdecl VirtualActorPathHandler::*()
    // ActorPathHandler::PATH_HANDLER_RESULT __cdecl VirtualActorPathHandler::*(float, float)
    // ActorPathHandler::PATH_HANDLER_RESULT __cdecl VirtualActorPathHandler::*(float)
    // ActorPathHandler::PATH_HANDLER_RESULT __cdecl VirtualActorPathHandler::*(float)
    // float __cdecl VirtualActorPathHandler::*()
    // float __cdecl VirtualActorPathHandler::*()
    // NiPoint3 __cdecl VirtualActorPathHandler::*()
    // bool __cdecl VirtualActorPathHandler::*(unsigned int, NiPoint3&)
    // float __cdecl VirtualActorPathHandler::*()
    // NiPoint3 __cdecl VirtualActorPathHandler::*(float)
    // unsigned int __cdecl VirtualActorPathHandler::*()
    // bool __cdecl VirtualActorPathHandler::*()
    // unsigned int __cdecl VirtualActorPathHandler::*()
    // bool __cdecl VirtualActorPathHandler::*(NiPoint3&)
    // void __cdecl VirtualActorPathHandler::*()
    // void __cdecl VirtualActorPathHandler::*(IDebugText*, DEBUGTEXT_LOCATION, DEBUGTEXT_JUSTIFY)
    // int __cdecl VirtualActorPathHandler::*(NiPoint3&)
    // void __cdecl VirtualActorPathHandler::*(BGSSaveFormBuffer*)
    // void __cdecl VirtualActorPathHandler::*(BGSLoadFormBuffer*)
    // void __cdecl VirtualActorPathHandler::*(BGSLoadFormBuffer*)
    // VirtualActorPathHandler& __cdecl VirtualActorPathHandler::*(const VirtualActorPathHandler&)
};
#endif
