// fallout_shared/screencustomsplatter_decls.h: declares PortalEntry, BSPortal, ScreenCustomSplatter, NiPoint3, NiUpdateData and more
#ifndef SCREENCUSTOMSPLATTER_DECLS_H
#define SCREENCUSTOMSPLATTER_DECLS_H

#include <new>
#include "fnv/decl/CamLook.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_004def90_Class.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00c5dea0_Class.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_01189000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011f9000.h"
union SETTING_VALUE;
class PortalEntry
{
  public:
};
template <class T> class PortalArray
{
  public:
    T* data;
    unsigned short capacity;
    unsigned short count;
};
class BSPortal
{
  public:
    char pad[0xa0];
    PortalArray<PortalEntry*> entries;
    ~BSPortal();
};
class ScreenCustomSplatter
{
  public:
    static void Clear();
    static void Init();
};
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3(float, float, float);
    static const NiPoint3 ZERO;
};
class NiUpdateData
{
  public:
    float time;
    bool a, b;
    unsigned short pad1;
    unsigned int pad2;
    NiUpdateData(float, bool, bool);
};
class NiFrustum
{
  public:
    float left, right, top, bottom, nearPlane, farPlane;
    bool ortho;
    unsigned char pad1;
    unsigned short pad2;
    NiFrustum(bool);
};
class NiMemObject
{
  public:
};
class NiExtraData;
class NiFixedString;
class NiAVObject : public NiMemObject
{
  public:
public:
    ::NiExtraData *GetExtraData(const ::NiFixedString &);
};
class NiAVObject;
class NiNode : public NiAVObject
{
  public:
    char bytes[0xac];
    NiNode(unsigned short);
public:
    ::NiAVObject *GetAt(unsigned int);
};
class NiCamera : public NiAVObject
{
  public:
    void UpdateViewFrustum(const NiFrustum&);
};
// Unidentified PC camera constructor at 0x00a712f0.
class FUN_00a712f0 : public NiCamera
{
  public:
    char bytes[0x114];
    FUN_00a712f0();
};
class NiTexture;
template <class T> class NiPointer
{
  public:
    T* p;
    T* operator->() const;
    NiPointer<T>& operator=(T*);
};
class SettingT_GameSettingCollection_
{
  public:
};
class SkyTextureManager
{
  public:
    static void LoadTextureFromPath(NiPointer<NiTexture>*, const char*);
};
extern unsigned int DAT_011c77dc;
extern unsigned char DAT_011c77e9;
extern float DAT_011c77ec;

enum MEM_CONTEXT
{
    MEM_CONTEXT_SCREEN = 7
};
class AutoMemContext
{
  public:
    int state;
    AutoMemContext(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext();
};
union SETTING_VALUE
{
    bool b;
    float f;
};
class INISettingCollection;
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Bool();
};
class NiRenderer;
class GraphicsRenderer
{
  public:
    unsigned int GetRenderTargetWidth();
    unsigned int GetRenderTargetHeight();
};
extern float DAT_01022960;

#endif
