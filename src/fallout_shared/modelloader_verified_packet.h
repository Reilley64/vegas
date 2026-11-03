// fallout_shared/modelloader_verified_packet.h: declares QueuedReference, QueuedCharacter, QueuedPlayer, NiRenderer, LocationDescriptor and more
#ifndef FNV_MODELLOADER_VERIFIED_PACKET_H
#define FNV_MODELLOADER_VERIFIED_PACKET_H


#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/FUN_00496cd0_cls.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00c3d440_cls.h"
#include "fnv/decl/ObjectC3.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_00448000.h"
#include "fnv/symbols_00449000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_00657000.h"
#include "fnv/symbols_00af6000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_01202000.h"
class QueuedReference
{
  public:
    void Attach();
    void FUN_00441b80();
    void FUN_004414f0();
};

class QueuedCharacter : public QueuedReference
{
  public:
    void Attach();
};

class QueuedPlayer : public QueuedCharacter
{
  public:
    void Attach();
};

class BSFileEntry;
class Archive;
class TESObjectREFR;
class QueuedFile;
class BGSPerkEntry;
class CountingSemaphore;
class BSStream;
class NiNode;
struct NiPoint3;

class NiRenderer
{
  public:
    static NiRenderer* ms_pRenderer;
    char _pdbpad_1[7];
    char m_spAccum_pad7_pad7[4];
    void* m_pCamera;
    void* m_pActiveRenderTargetGroup;
    char m_acRendererDataB[4];
    char _pdbpad_18[104];
    char m_acRendererDataC[128];
    char m_acRendererDataD[128];
    char m_acRendererDataE[128];
    int m_iRendererState;
    unsigned int m_uiRendererFlags;
    bool m_bRendererFlagA;
    bool m_bRendererFlagB;
    char _pdbpad_20a[118];
};

enum ARCHIVE_TYPE
{
    ARCHIVE_TYPE_DEFAULT = 0
};

enum IO_TASK_PRIORITY
{
    IO_TASK_PRIORITY_DEFAULT = 0
};

class LocationDescriptor
{
  public:
};

class ArchiveManager
{
  public:
};

class Archive : public ArchiveManager
{
};

class QueuedTexture : public LocationDescriptor
{
  public:
    unsigned char GetFileIndex();
};

class BGSTerrainChunkLoadTask : public LocationDescriptor
{
  public:
    unsigned char GetFileIndex();
};

template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    T& GetItem();
    BSSimpleList<T>* GetNext();
    void RemoveHead();
};

class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
public:
    static ::TaskQueueInterface *GetSingleton();
};

class ModelLoader
{
  public:
    bool EnqueueFile(const char*, IO_TASK_PRIORITY, QueuedFile*);
    void QueueFileList(BSSimpleList<const char*>*, IO_TASK_PRIORITY, QueuedFile*, const char*);
    void ProcessQueuedFile();
    static void UpdateLoadingStatusCallback();
    void UpdateReferenceNode(TESObjectREFR*, NiNode*);
    void FUN_004431d0();
    void FUN_00443220();
};

template <class T> class NiPointer
{
  public:
    NiPointer(T*);
    operator T*() const;
    NiPointer<T>& operator=(T*);
    ~NiPointer();
};

class Model
{
  public:
    void* owned;
    char prefix[8];
    NiPointer<NiNode> node;
    Model(const char*, BSStream*, bool, bool);
    ~Model();
};

class CountingSemaphore
{
  public:
    void Signal();
};

struct QueueKFListLocals
{
    void* deletePointer;
    const char* pathToQueue;
    char path[260];
};

extern int __cdecl strcat_s(char*, unsigned int, const char*);

class InventoryStackRecord;
struct RefObj;
class IOTask
{
  public:
    static unsigned char GetPriorityFromKey(__int64& key);
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30(BSSimpleList<InventoryStackRecord*>*);
    IO_TASK_PRIORITY FUN_0043cc60();
public:
    void FUN_00c3c7e0(::RefObj *);
};
class QueuedFile : public IOTask
{
public:
    void SetParent(::QueuedFile *);
};
class QueuedModel : public QueuedFile
{
  public:
    void GenerateKey();
    void DispatchToManager();
    void OnChildCompletion();
};
class QueuedKF : public QueuedFile
{
  public:
    void DispatchToManager();
};
class QueuedHead : public QueuedFile
{
  public:
    void DispatchToManager();
    void OnChildCompletion();
};
class QueuedAnimIdle : public QueuedFile
{
  public:
    void OnChildCompletion();
    void ProcessLoadedAnimIdle();
};
class IOManager
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48(IOTask*);
public:
    void SubmitTask();
};
class TESNPC;
class BSFaceGenModelMap;
class BSFaceGenManager
{
  public:
public:
    static ::BSFaceGenModelMap *GetModelMap();
};
class TESSpellList
{
  public:
};
class SoundPlaybackHandle;
template <class K, class V> class NiTPointerMap
{
  public:
    bool IsEmpty();
};
class KFModel;
class AnimIdle
{
  public:
};
class NiFixedString;
class NiExtraData
{
  public:
};
class NiAVObject
{
  public:
    NiExtraData* GetExtraData(const NiFixedString&);
    NiNode* GetParent();
    NiPoint3& FUN_0043c490();
    int FUN_0043c470();
    NiNode* GetParentNode();
};
class NiAVObject;
class NiNode : public NiAVObject
{
public:
    ::NiAVObject *GetAt(unsigned int);
};
class ExtraRadioData;
class TESModel;
class TESObjectREFR
{
  public:
public:
    ::ExtraRadioData *GetExtraRadioData();
public:
    ::TESModel *GetTESModel();
};
const NiFixedString& FUN_00448a80();

#include "modelloader_added_types.h"

#include "modelloader_selector_same_tu_types.h"
#include "modelloader_addon_declarations.h"
#include "modelloader_package_declarations.h"
#include "modelloader_weapon_declarations.h"
#include "modelloader_activator_declarations.h"
#endif
