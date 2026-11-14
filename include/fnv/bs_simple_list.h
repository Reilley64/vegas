#ifndef FNV_BS_SIMPLE_LIST_H
#define FNV_BS_SIMPLE_LIST_H

// BSSimpleList: the engine's singly linked list. The head node is part of the
// list object and holds the first item, so an empty list is a head whose item
// and next pointer are both null.
//
// This is the one shared declaration of the template. It declares the members
// that build/units.json gives an address under the template's name. The
// header has no body: each member is defined and emitted, once per element
// type, by the unit that owns its address. The original linker folded the
// bodies of every pointer list into the one address given beside each member.
// docs/shared-simple-list.md has the rule for moving a unit onto this header.
template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    // Owned by src/bscore/bssimplelist_h_unit.cpp (bssimplelist.inl).
    BSSimpleList();          // 0x0096a2d0
    BSSimpleList(T& item);   // 0x00470440
    ~BSSimpleList();         // 0x0046ffb0
    T& GetItem();            // 0x006815c0
    BSSimpleList<T>* GetNext(); // 0x00726070
    bool IsEmpty();          // 0x008256d0
    void AddTail(T& item);   // 0x00905820
    void AddHead(T& item);   // 0x005ae3d0
    void RemoveHead();       // 0x0063f7b0
    void RemoveAll();        // 0x00470470
    // Owned by src/fallout_shared/tesform.cpp.
    void SetItem(const T& item); // 0x00726c60
    // Owned by src/fallout/interface/interfacemanager.cpp.
    unsigned int ItemsInList();  // 0x005ae380
};

#endif
