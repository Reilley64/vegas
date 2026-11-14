#include "havok/hkpMoppBvTreeShape.h"
#include "havok/hkpMoppCode.h"
#include "havok/hkMemoryRouter.h"

#include <cstring>
#include <new>
#include <stdexcept>

hkpMoppCode::hkpMoppCode() noexcept
    : m_info{}, m_data{nullptr, 0, static_cast<int>(0x80000000u)}, m_eBuildType(BUILD_NOT_SET)
{
}

// The code generator materializes a private copy of its byte stream. This
// constructor exposes that same ownership operation without a legacy view.
hkpMoppCode::hkpMoppCode(const hkpMoppCodeCodeInfo& info, std::span<const hkUint8> bytes)
    : hkpMoppCode()
{
    if (bytes.size() > 0x3fffffffu)
        throw std::length_error("MOPP code exceeds native array capacity");
    if (!bytes.empty())
    {
        auto& allocator = hkMemoryRouter::getInstance().heap();
        int capacity = static_cast<int>(bytes.size());
        auto* data = static_cast<hkUint8*>(allocator.bufAlloc(capacity));
        if (!data)
            throw std::bad_alloc();
        if (capacity < static_cast<int>(bytes.size()) || capacity > 0x3fffffff)
        {
            allocator.bufFree(data, capacity);
            throw std::length_error("MOPP allocator returned an invalid capacity");
        }
        std::memcpy(data, bytes.data(), bytes.size());
        m_data = {data, static_cast<int>(bytes.size()), capacity};
        dataAllocator = &allocator;
    }
    m_info = info;
}

hkpMoppCode::~hkpMoppCode()
{
    if ((static_cast<hkUint32>(m_data.m_iCapacityState) & 0x80000000u) == 0)
        dataAllocator->bufFree(m_data.m_data, m_data.m_iCapacityState & 0x3fffffff);
}

// @fnv 0x00d54490
hkMoppBvTreeShapeBase::hkMoppBvTreeShapeBase(hkUint32 type, const hkpMoppCode& code)
    : hkpShape(type), m_bvTreeType(0), m_pMoppCode(&code),
      m_pMoppData(code.getData().data()), m_uiMoppDataSize(static_cast<hkUint32>(code.getData().size())),
      m_kMoppCodeInfo(code.getCodeInfo().m_offset)
{
    code.addReference();
}

hkMoppBvTreeShapeBase::~hkMoppBvTreeShapeBase()
{
    m_pMoppCode->removeReference();
}

// The source base-container destructor owns no resources.
hkpShapeContainer::~hkpShapeContainer() = default;

hkpSingleShapeContainer::hkpSingleShapeContainer(hkpShape* child) : m_pContainedShape(child)
{
    child->addReference();
}

hkpSingleShapeContainer::~hkpSingleShapeContainer()
{
    if (m_pContainedShape)
        m_pContainedShape->removeReference();
}

// The second argument is code, not an integer or an original numerical address.
// The typed base initializer retains it and caches its borrowed query data.
// @fnv 0x00d544f0
hkpMoppBvTreeShape::hkpMoppBvTreeShape(hkpShape* child, const hkpMoppCode& code)
    : hkMoppBvTreeShapeBase(10, code), m_pChildAtom(child)
{
}

// Member destruction releases the child before the base releases the code.
// @fnv 0x00d543e0
hkpMoppBvTreeShape::~hkpMoppBvTreeShape() = default;
