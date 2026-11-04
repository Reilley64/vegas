// fallout_shared/screensplatter_decls.h: declares ScreenSplatter, NiNode, ProcessLists, AutoMemContext, GraphicsRenderer and more
#ifndef FNV_SCREENSPLATTER_PRIVATE_H
#define FNV_SCREENSPLATTER_PRIVATE_H


#include <new>
#include <cstddef>
#include "fnv/decl/CamLook.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_004def90_Class.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_005db000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_01189000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011f9000.h"
class FUN_00622c80;

class ScreenSplatter
{
  public:
    static void Init();
    static void Clear();
    static FUN_00622c80* Activate(float time, bool enabled);
};

class NiAVObject;
template <class T> class NiPointer;
template <> class NiPointer<NiAVObject>
{
  public:
    NiAVObject* operator->() const;
    NiPointer& operator=(NiAVObject* object);
};

class NiUpdateData;
class NiAVObject;
class NiNode
{
  public:
public:
    ::NiAVObject *GetAt(unsigned int);
};

class FUN_00622c80
{
  public:
    unsigned char data[0x3b0];
    static void* operator new(std::size_t size);
    static void operator delete(void*);
    FUN_00622c80(float value, unsigned int id);
};

float FUN_00622ba0();
float FUN_00622bb0();

extern unsigned char DAT_011c7834;
extern unsigned int DAT_011c7828;
extern FUN_00622c80* DAT_011cc200;
extern FUN_00622c80* DAT_011cc1fc;

enum MEM_CONTEXT
{
    MEM_CONTEXT_UNKNOWN = 0
};
struct SETTING_VALUE;
class INISettingCollection;
template <class T> class SettingT;
class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag();
};

class AutoMemContext
{
  public:
    unsigned int data;
    AutoMemContext(MEM_CONTEXT context, bool enabled, const char* file, int line);
    ~AutoMemContext();
};

class GraphicsRenderer
{
  public:
    unsigned int GetRenderTargetWidth();
    unsigned int GetRenderTargetHeight();
};
class NiRenderer;

class NiMemObject
{
  public:
};

class FUN_00a712f0 : public NiMemObject
{
  public:
    unsigned char data[0x114];
    FUN_00a712f0();
};

class NiUpdateData
{
  public:
    float value;
    unsigned int first;
    unsigned int second;
    NiUpdateData(float value, bool first, bool second);
};

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3(float x, float y, float z);
    static const NiPoint3 ZERO;
};

class NiFrustum
{
  public:
    float left, right, top, bottom, nearPlane, farPlane;
    bool ortho;
    NiFrustum(bool enabled);
};

struct ScreenSplatterRawData
{
    float value;
    unsigned int first, second;
};
struct ScreenSplatterRawFrustum
{
    float left, right, top, bottom, nearPlane, farPlane;
    bool ortho;
};
struct ScreenSplatterInitLocals
{
    float aspect;
    ScreenSplatterRawFrustum frustum;
    GraphicsRenderer* renderer;
    ScreenSplatterRawData firstData;
    ScreenSplatterRawData secondData;
};

class NiCamera
{
  public:
    void UpdateViewFrustum(const NiFrustum& frustum);
};

class NiExtraData;
class NiFixedString;
class NiAVObject
{
  public:
public:
    ::NiExtraData *GetExtraData(const ::NiFixedString &);
};

class NiFixedString;
class NiFixedString;
class NiExtraData
{
  public:
    void SetName(const NiFixedString& name);
public:
    NiExtraData(const ::NiFixedString &);
};

class NiSortAdjustNode : public NiMemObject
{
  public:
    unsigned char data[0xac];
    NiSortAdjustNode(unsigned int copyMembers);
};

class SettingT_GameSettingCollection_
{
  public:
};

class NiTexture;
class SkyTextureManager
{
  public:
    static void LoadTextureFromPath(NiPointer<NiTexture>* texture, const char* path);
};

extern char DAT_01022ab8;
extern float DAT_01022960;

#endif
