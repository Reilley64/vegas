#ifndef FNV_SIMPLE_LIST_NODE_VIEW_H
#define FNV_SIMPLE_LIST_NODE_VIEW_H

// A BSSimpleList node of a pointer-sized item, for code that reaches nodes
// through other stand-in types. The item comes first, so BSSimpleList::GetItem
// (0x006815c0) returns the node address.
struct SimpleListNodeView
{
    void* m_item;
    SimpleListNodeView* m_pkNext;
};

#endif
