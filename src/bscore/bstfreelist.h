#ifndef BSTFREELIST_H
#define BSTFREELIST_H

#include "fnv/decl/FUN_006ecc70_Class.h"
#include "fnv/decl/p07__DelStandIn.h"
#include "bstfreelist_decls.h"
template <>
// @fnv 0x009059c0
void BSTFreeList<QueuedMessage>::Elem(BSTFreeListElement<QueuedMessage>*& element)
{
    reinterpret_cast<::p07::DelStandIn *>((element))->FUN_00905ae0();
    reinterpret_cast<::FUN_006ecc70_Class *>(this)->PushFront((int *)&(element));
}
#endif
