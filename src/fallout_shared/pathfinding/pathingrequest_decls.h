#ifndef PATHINGREQUEST_DECLS_H
#define PATHINGREQUEST_DECLS_H

#include "fnv/decl/FUN_006dc910_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/NiPtr.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0104e000.h"
#include "fnv/symbols_011de000.h"
class Actor;
class BGSLoadFormBuffer;
class TESForm;
class TESObjectREFR;
class TESPackage;
class PlayerCharacter;
class BGSLoadFormBufferView
{
  public:
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
};
class Calendar
{
  public:
};
class MobileObject
{
  public:
};
class BGSLoadFormBuffer
{
  public:
    virtual unsigned char GetVersion();
};
class PathingLocationLoadView
{
  public:
    virtual void vfn_0();
    virtual void LoadGame(BGSLoadFormBuffer*);
};
class PathingAvoidanceNode
{
  public:
};
template <class T, unsigned int N> class BSSimpleArray;
class PathingAvoidNodeArray
{
  public:
    char data[24];
    PathingAvoidNodeArray();
    ~PathingAvoidNodeArray();
    PathingAvoidNodeArray* Destroy(unsigned int);
    void FUN_006e3960();
    void FUN_006e39d0();

    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
extern unsigned char DAT_0106d1d8;
extern unsigned char DAT_0106d1e4;
class PathingAvoidNodeArrayDestructionView
{
  public:
};
class PathingAvoidPointerView
{
  public:
};

class FUN_006e4080 : public PathingRequest
{
  public:
    char extra[60];
    FUN_006e4080();
};
class PathingRequestClosePoint : public PathingRequest
{
  public:
    char extra[8];
    PathingRequestClosePoint();
};
class PathingRequestFlee : public PathingRequest
{
  public:
    char extra[4];
    PathingRequestFlee();
};
class PathingRequestCoveredMove : public PathingRequest
{
  public:
    char extra[44];
    PathingRequestCoveredMove();
};
class PathingRequestLOS : public PathingRequest
{
  public:
    char extra[40];
    PathingRequestLOS();
};
class PathingRequestOptimalLocation : public PathingRequest
{
  public:
    char extra[16];
    PathingRequestOptimalLocation();
};
class FUN_006e4a50 : public PathingRequest
{
  public:
    char extra[92];
    FUN_006e4a50();
};
#endif
