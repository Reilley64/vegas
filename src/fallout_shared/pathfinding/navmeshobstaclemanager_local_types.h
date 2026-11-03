#ifndef NAVMESHOBSTACLEMANAGER_LOCAL_TYPES_H
#define NAVMESHOBSTACLEMANAGER_LOCAL_TYPES_H
// Unit-local container/smart-pointer templates (see navmeshobstaclemanager_decls.h). Included before the canonical
template <class T, unsigned int N> class BSSimpleArray
{
  public:
    void** m_ppVirtualMethodTable;
    T* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
    unsigned int Add(T&);
    unsigned int GetSize();
    void Clear(bool);
    void Remove(unsigned int, bool);
    template <class U> unsigned int Find(U&, unsigned int, bool (*)(U&, U&));
};
template <class T, class A> class NiTArray
{
  public:
    T& GetAt(unsigned int);
};
template <class K, class V> class NiTPointerMap
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    void** m_ppHashTable;
    unsigned int m_uiCount;
    void RemoveAll();
};
template <class T> class NiPointer
{
  public:
    T* p[1];
    NiPointer(T*);
    ~NiPointer();
    operator T*() const;
    NiPointer(const NiPointer&);
};
template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    bool IsEmpty();
    T& GetItem();
    BSSimpleList* GetNext();
    void RemoveAll();
    void Remove(const T&);
    bool IsInList(T&);
    void AddTail(const T&);
    void AddHead(T&);
};
#endif
