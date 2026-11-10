// fallout_shared/pathfinding/pathinglocation_templates.h: declares NiPoint3

#include "fnv/decl/TESCombatStyle.h"
struct NiPoint3
{
  public:
    float x, y, z;
};
class SandboxProcedureData;
class TESLoadScreen;
template <class T, unsigned int Growth> class BSSimpleArray
{
  public:
    void** m_ppVirtualMethodTable;
    T* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    unsigned int GetSize();
    T& GetAt(int);
    void CopyTo(BSSimpleArray*);
    void Clear(bool);
    unsigned int Add(T&);
    void UpdateEntryValue(unsigned int, unsigned int);
};
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    T* operator->() const;
};
