
// src/havok/common/base/reflection/hkclassupdate.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/reflection/hkclassupdate.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/decl/FUN_00cb1930_t.h"
#include "fnv/decl/FUN_00d46f70_cls.h"
#include "fnv/decl/FUN_00d46f80_class.h"
#include "fnv/decl/FUN_00d46fe0_Class.h"
#include "fnv/decl/FnvClassNameNode.h"
#include "fnv/decl/HkClassNode.h"
#include "fnv/decl/Struct_d86920.h"
#include "fnv/decl/TestClass.h"
#include "fnv/decl/fnv_00cb1870__hkMapBaseCB18.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00e04000.h"
#include "fnv/symbols_010d2000.h"
#include "fnv/symbols_0126c000.h"
#include "fnv/symbols_0126e000.h"
struct Allocator;
struct BSAudio
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Allocator* allocator;
};
BSAudio* FUN_00c85750();
struct TypeNode;
struct VisitMap
{
};
struct Member
{
    void* type;
};
struct TypeNode
{
    TypeNode* FUN_00d46d60();
};
// Walks a type node and its members, skipping nodes whose visited flags intersect mask, marking them visited, and invoking callback on each member.
// @fnv 0x00e04af0
void __cdecl VisitTypeMembers(TypeNode* node, VisitMap* visited, unsigned int mask, void(__cdecl* callback)(Member*))
{
    for (;;)
    {
        uintptr_t flags = ((unsigned int)(reinterpret_cast<::FUN_00cb1930_t *>((visited))->LookupHashEntry((intptr_t)(node), 0)));
        if (mask & flags)
            return;
        BSAudio* audio = FUN_00c85750();
        reinterpret_cast<::fnv_00cb1870::hkMapBaseCB18 *>((visited))->FUN_00cb1870((*(::fnv_00cb1870::hkMemoryAllocatorCB18 *)(audio->allocator)), (uintptr_t)(node), flags | mask);
        for (int i = 0; i < reinterpret_cast<::FUN_00d46f70_cls *>((node))->FUN_00d46f70(); ++i)
        {
            Member* member = ((::Member *)(reinterpret_cast<::FUN_00d46f80_class *>((node))->FUN_00d46f80(i)));
            TypeNode* child = ((::TypeNode *)(reinterpret_cast<::Struct_d86920 *>((member))->FUN_00d86920()));
            if (child)
                VisitTypeMembers(child, visited, mask, callback);
            callback(member);
        }
        if (!node->FUN_00d46d60())
            return;
        node = node->FUN_00d46d60();
    }
}

namespace fnv_00e04bb0 {
struct Allocator;
struct BSAudio
{
    int unk00, unk04, unk08, unk0C;
    Allocator* allocator;
};
BSAudio* FUN_00c85750();
struct TypeNode;
struct VisitMap
{
};
struct Member
{
    int unk00;
    void* type;
};
struct TypeNode
{
    TypeNode* FUN_00d46d60();
};
struct Property
{
    int unk00, unk04, unk08, unk0C;
    short unk10;
    unsigned short offset;
};
struct Registry
{
};
extern char DAT_010ea4cc[], DAT_010e5210[];
// Marks a type node as visited, resets an offset field up the ancestor chain, bumps a count, then recurses into member types and the parent node.
// @fnv 0x00e04bb0
void VisitTypeNode(TypeNode* node, VisitMap* visited)
{
    uintptr_t flags = ((unsigned int)(reinterpret_cast<::FUN_00cb1930_t *>((visited))->LookupHashEntry((intptr_t)(node), 0)));
    if (!(flags & 1))
    {
        BSAudio* audio = FUN_00c85750();
        reinterpret_cast<::fnv_00cb1870::hkMapBaseCB18 *>((visited))->FUN_00cb1870((*(::fnv_00cb1870::hkMemoryAllocatorCB18 *)(audio->allocator)), (uintptr_t)(node), flags | 1);
        unsigned int offset = ((::fnv_00e04bb0::Property *)(reinterpret_cast<::FUN_00d46fe0_Class *>(&((*reinterpret_cast<::fnv_00e04bb0::Registry *>(&::g_0126ed90))))->FUN_00d46fe0((const int *)(DAT_010ea4cc))))->offset;
        TypeNode* ancestor = node;
        while (ancestor->FUN_00d46d60())
        {
            *reinterpret_cast<int*>(reinterpret_cast<char*>(ancestor) + offset) = 0;
            ancestor = ancestor->FUN_00d46d60();
        }
        if (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(ancestor) + offset))
        {
            unsigned int countOffset = ((::fnv_00e04bb0::Property *)(reinterpret_cast<::FUN_00d46fe0_Class *>(&((*reinterpret_cast<::fnv_00e04bb0::Registry *>(&::g_0126ed90))))->FUN_00d46fe0((const int *)(DAT_010e5210))))->offset;
            ++*reinterpret_cast<int*>(reinterpret_cast<char*>(ancestor) + countOffset);
        }
        *reinterpret_cast<int*>(reinterpret_cast<char*>(ancestor) + offset) = 0;
        for (int i = 0; i < reinterpret_cast<::FUN_00d46f70_cls *>((node))->FUN_00d46f70(); ++i)
        {
            Member* member = ((::fnv_00e04bb0::Member *)(reinterpret_cast<::FUN_00d46f80_class *>((node))->FUN_00d46f80(i)));
            if (member->type)
                VisitTypeNode(((::fnv_00e04bb0::TypeNode *)(reinterpret_cast<::TestClass *>((member))->FUN_00d86910())), visited);
        }
        if (node->FUN_00d46d60())
            VisitTypeNode(node->FUN_00d46d60(), visited);
    }
}
}  // namespace fnv_00e04bb0

void __cdecl FUN_00e04a60(void* data);
void __cdecl UpdateStateFlags(void* data);

extern void* g_E04D30Last;

// Stand-in for the file-static FUN_00e04cc0: its body here is a placeholder; only its
// existence as a static function (which MSVC calls with the argument in eax) matters.
static __declspec(noinline) void E04D30Finish(void* registry)
{
    g_E04D30Last = registry;
}

// Registers context handlers by level: at level 1 runs VisitTypeNode and records registry, and below 4/5 registers size-2 and size-8 handlers.
// @fnv 0x00e04d30
void __cdecl RegisterContextHandlers(void* registry, void* context, int level)
{
    if (level == 1)
    {
        ::fnv_00e04bb0::VisitTypeNode((::fnv_00e04bb0::TypeNode *)(registry), (::fnv_00e04bb0::VisitMap *)(context));
        E04D30Finish(registry);
    }
    if (level < 4)
        ::VisitTypeMembers((::TypeNode *)(registry), (::VisitMap *)(context), 2, (void (*)(Member *))(FUN_00e04a60));
    if (level < 5)
        ::VisitTypeMembers((::TypeNode *)(registry), (::VisitMap *)(context), 8, (void (*)(Member *))(UpdateStateFlags));
}

struct TraverseNode
{
};
struct TypeDefinition
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned short unk10;
    unsigned short fieldOffset;
};
struct TypeRegistry
{
};

// Marks the node visited and, when its name matches DAT_010d27bc, writes 0x19 at the selected member offset.
// @fnv 0x00e04cc0
static __declspec(noinline) void __cdecl FUN_00e04cc0(TraverseNode* node, VisitMap* visited)
{
    uintptr_t flags = ((unsigned int)(reinterpret_cast<::FUN_00cb1930_t *>((visited))->LookupHashEntry((intptr_t)(reinterpret_cast<TypeNode*>(node)), 0)));
    if ((flags & 4) == 0)
    {
        BSAudio* audio = FUN_00c85750();
        reinterpret_cast<::fnv_00cb1870::hkMapBaseCB18 *>((visited))->FUN_00cb1870((*(::fnv_00cb1870::hkMemoryAllocatorCB18 *)(audio->allocator)), (uintptr_t)(reinterpret_cast<TypeNode*>(node)), flags | 4);
        if (::fnv_00cb0fa0::FUN_00cb0fa0(reinterpret_cast<::FnvClassNameNode *>((node))->FUN_00d46d40(), ::g_0126908c_arg0) == 0)
        {
            char* member = ((char *)(reinterpret_cast<::FUN_00d46f80_class *>((void *)(node))->FUN_00d46f80(2)));
            TypeDefinition* type = ((::TypeDefinition *)(reinterpret_cast<::HkClassNode *>(&((*reinterpret_cast<::TypeRegistry *>(&::g_0126ca58))))->FUN_00d46f20(4)));
            member[type->fieldOffset] = 0x19;
        }
    }
}

void CallTraversal(TraverseNode* node, VisitMap* visited)
{
    FUN_00e04cc0(node, visited);
}

struct ParentNodeView : TypeNode
{
    const char* name;
    TypeNode* parent;

    TypeNode* FUN_00d46d60();
};

// @fnv 0x00d46d60
TypeNode* ParentNodeView::FUN_00d46d60()
{
    return parent;
}

#include "generated/data/havok/common/base/reflection/hkclassupdate.inc"
