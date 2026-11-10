// gamebryo2.2/corelibs/nimain/nirefobject_lifetime.cpp: NiRefObject lifetime
// and the retained-list payload protocol built on its native count.
//
// This unit needs only the object declaration, so host builds link the same
// object count, destructor, deletion and retain/release bodies as the Windows
// archive. The destructor is the class's first virtual definition and
// therefore also supplies its run-time type identity where that identity has
// one owner.

#include "fnv/list_node.h"
#include "fnv/ni_ref_object.h"

#include <stdexcept>

// Sole definition. docs/native-data-ownership.md records the retirement of
// the legacy duplicate.
unsigned int NiRefObject::ms_lObjectCount;

NiRefObject::~NiRefObject()
{
    NiAtomicSubtract(ms_lObjectCount);
}

// @fnv 0x00cfcc20
void NiRefObject::DeleteThis()
{
    delete this;
}

bool fnv::list::TryRetainPayload(NiRefObject* payload) noexcept
{
    return !payload || payload->TryIncRefCount();
}

void fnv::list::ReleasePayload(NiRefObject* payload) noexcept
{
    if (payload)
        payload->DecRefCount();
}

void fnv::list::ThrowPayloadCountOverflow()
{
    throw std::overflow_error("native payload reference count overflow");
}
