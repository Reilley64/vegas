// src/unmapped/debugtextscriptprofiler.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/debug/debugtextpages/debugtextscriptprofiler.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_0049fa20_List.h"
struct Node
{
    Node* m_pkNext;
    Node* m_pkPrev;
    unsigned int m_element;
};
struct ScriptPool
{
    void* FUN_0049fa80();
};
struct ScriptList : ScriptPool
{
    void FUN_0076b660(unsigned int* element);
};
// Stores the value pointed to by element into the node obtained from FUN_0049fa80, then passes the node to FUN_0049fa20.
// @fnv 0x0076b660
void ScriptList::FUN_0076b660(unsigned int* puiElement)
{
    Node* node = static_cast<Node*>(this->FUN_0049fa80());
    node->m_element = *puiElement;
    reinterpret_cast<::FUN_0049fa20_List *>(this)->FUN_0049fa20((::FUN_0049fa20_Node *)(node));
}
