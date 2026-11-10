#ifndef FNV_BS_SIMPLE_LIST_H
#define FNV_BS_SIMPLE_LIST_H

// BSSimpleList: the engine's singly linked list. The head node is part of the
// list object and holds the first item, so an empty list is a head whose item
// and next pointer are both null.
//
// This is the one shared declaration of the template. It declares the ten
// members that src/bscore/bssimplelist_h_unit.cpp owns in build/units.json.
// That unit defines them (bssimplelist.inl) and emits them for each element
// type; no other unit defines a body. The original linker folded the bodies
// of every pointer list into the one address given beside each member.
// docs/shared-simple-list.md has the rule for moving a unit onto this header.
template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
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
};

#endif
