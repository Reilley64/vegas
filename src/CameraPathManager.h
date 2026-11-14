// CameraPathManager.h: declares NiFormArray, CameraPathManager
#ifndef FNV_CAMERA_PATH_MANAGER_H
#define FNV_CAMERA_PATH_MANAGER_H

#include "bgscamerapathmanager_BGSCameraPath.h"
// the supplied disassembly and public community declaration facts.
class NiFormArray : public NiTLargePrimitiveArray<TESForm*>
{
  public:
    void SetFormAtIndex(unsigned int index, TESForm* form);
};
template <class T> class NiTPrimitiveArray : public NiTArray<T, NiTMallocInterface<T> >
{
  public:
    NiTPrimitiveArray(unsigned int maxSize, unsigned int growBy);
    virtual ~NiTPrimitiveArray();
};
class CameraPathManager
{
  public:
    NiFormArray m_kCameraPathArray;
    NiTPrimitiveArray<BGSCameraPath*> m_kCameraPathList;
    void InitializeCameraPaths();
    static BGSCameraPath* GetTextureResourcePath();
    void UpdateCameraPaths();

  protected:
    static BGSCameraPath* ms_pDefaultCameraPath;
};
#endif
