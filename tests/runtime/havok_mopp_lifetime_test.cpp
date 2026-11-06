#include "check.h"
#include "havok/hkpSphereShape.h"
#include "havok/hkpMoppBvTreeShape.h"
#include "havok/hkpMoppCode.h"
#include "havok/hkMemorySystem.h"
#include "havok/hkpBallGun.h"

#include <array>
#include <stdexcept>
#include <thread>
#include <vector>

namespace
{
int InUse(hkMemoryAllocator& allocator)
{
    hkMemoryAllocator::MemoryStatistics statistics;
    allocator.getMemoryStatistics(statistics);
    return statistics.inUse;
}

hkpShape* ThrowBeforeConstruction()
{
    throw std::runtime_error("constructor argument failed");
}

void SharedOwners(Checks& checks, hkSystemMemoryAllocator& heap)
{
    const std::array<hkUint8, 5> bytes{0x11, 0x42, 0x08, 0x91, 0x00};
    auto input = bytes;
    const hkpMoppCodeCodeInfo info{{1.25f, -2.5f, 3.75f, 16.0f}};
    auto* code = new hkpMoppCode(info, input);
    input.fill(0xff);
    auto* child = new hkpSphereShape(2.5f);
    auto* first = new hkpMoppBvTreeShape(child, *code);
    auto* second = new hkpMoppBvTreeShape(child, *code);
    checks.Equal("fresh MOPP type", 10u, first->getType());
    checks.Equal("real sphere construction", 1u, child->getType());
    checks.Equal("borrowed child publication", true, child == first->getChild());
    checks.Equal("borrowed code publication", true, code == &first->getMoppCode());
    checks.Equal("cached code points at retained code", true, code->getData().data() == first->getMoppData().data());
    checks.Equal("cached code extent", bytes.size(), first->getMoppData().size());
    checks.Equal("copied code info", 16.0f, first->getMoppCodeInfo().w);
    checks.Equal("code default build kind", int(hkpMoppCode::BUILD_NOT_SET), int(code->getBuildType()));

    child->removeReference();
    code->removeReference();
    first->removeReference();
    // Neither caller references nor the first wrapper keep these alive now.
    checks.Equal("second owner retains child", 2.5f,
                 static_cast<const hkpSphereShape*>(second->getChild())->getRadius());
    for (std::size_t i = 0; i < bytes.size(); ++i)
        checks.Equal("second owner retains code bytes", bytes[i], second->getMoppData()[i]);
    checks.Equal("second owner retains code identity", true, code == &second->getMoppCode());
    second->removeReference();
    checks.Equal("last wrapper balances all heap cleanup", 0, InUse(heap));
}

void BulletShapeProducer(Checks& checks, hkSystemMemoryAllocator& heap)
{
    hkpBallGun gun{};
    gun.m_fBulletRadius = 2.25f;
    hkpShape* first = gun.createBulletShape();
    checks.Equal("production bullet sphere type", 1u, first->getType());
    checks.Equal("production bullet radius", 2.25f,
                 static_cast<const hkpSphereShape*>(first)->getRadius());
    gun.m_fBulletRadius = 0.5f;
    auto* independent = gun.createBulletShape();
    auto* code = new hkpMoppCode;
    auto* wrapper = new hkpMoppBvTreeShape(first, *code);
    first->removeReference();
    code->removeReference();
    checks.Equal("wrapper retains production bullet identity", true, first == wrapper->getChild());
    checks.Equal("wrapper retains production bullet radius", 2.25f,
                 static_cast<const hkpSphereShape*>(wrapper->getChild())->getRadius());
    wrapper->removeReference();
    checks.Equal("independent production bullet remains live", 0.5f, independent->getRadius());
    checks.Equal("independent production bullet is still allocated", true, InUse(heap) > 0);
    independent->removeReference();
    checks.Equal("production bullet allocation and release balance", 0, InUse(heap));
}

void NestedAndIndependent(Checks& checks, hkSystemMemoryAllocator& heap)
{
    auto* code = new hkpMoppCode;
    auto* leaf = new hkpSphereShape(4.0f);
    auto* inner = new hkpMoppBvTreeShape(leaf, *code);
    auto* outer = new hkpMoppBvTreeShape(inner, *code);
    auto* independent = new hkpSphereShape(7.0f);
    leaf->removeReference();
    inner->removeReference();
    code->removeReference();
    checks.Equal("nested wrapper preserves exact child", true, inner == outer->getChild());
    checks.Equal("nested wrapper retains its leaf", true, leaf == inner->getChild());
    checks.Equal("default code is empty", true, outer->getMoppData().empty());
    outer->removeReference();
    checks.Equal("independent shape remains usable", 7.0f, independent->getRadius());
    checks.Equal("independent shape still allocated", true, InUse(heap) > 0);
    independent->removeReference();
    checks.Equal("nested graph cleanup balanced", 0, InUse(heap));
}

void BorrowedAndFailure(Checks& checks, hkSystemMemoryAllocator& heap)
{
    const std::array<hkUint8, 3> bytes{3, 5, 8};
    {
        hkpSphereShape child(1.0f);
        hkpMoppCode code({}, bytes);
        {
            hkpMoppBvTreeShape wrapper(&child, code);
            wrapper.addReference();
            wrapper.removeReference();
            checks.Equal("stack wrapper remains usable", true, &child == wrapper.getChild());
            checks.Equal("stack code is copied", bytes[2], wrapper.getMoppData()[2]);
        }
        checks.Equal("borrowed stack child remains live", 1.0f, child.getRadius());
        checks.Equal("borrowed stack code remains live", bytes.size(), code.getData().size());
        const int before = InUse(heap);
        bool threw = false;
        try
        {
            new hkpMoppBvTreeShape(ThrowBeforeConstruction(), code);
        }
        catch (const std::runtime_error&)
        {
            threw = true;
        }
        checks.Equal("argument exception propagated", true, threw);
        checks.Equal("failed new returns object allocation", before, InUse(heap));
        // A later allocation must not consume a failed construction's record.
        auto* later = new hkpSphereShape(9.0f);
        later->removeReference();
        checks.Equal("later allocation cleanup balanced", before, InUse(heap));
    }
    checks.Equal("stack code stream released on scope exit", 0, InUse(heap));
}

void ContainerAndAllocationFailure(Checks& checks, hkSystemMemoryAllocator& heap, hkMemoryRouter& router)
{
    auto* child = new hkpSphereShape(3.0f);
    auto* container = new hkpSingleShapeContainer(child);
    child->removeReference();
    checks.Equal("standalone container retains child", true, child == container->getChild());
    checks.Equal("retained child is usable", 3.0f,
                 static_cast<const hkpSphereShape*>(container->getChild())->getRadius());
    delete static_cast<hkpShapeContainer*>(container);
    checks.Equal("virtual container cleanup releases child", 0, InUse(heap));

    // Use the real bounded production allocator, not a fake allocation provider.
    hkNativeSolverAllocator bounded(heap);
    checks.Equal("bounded heap initialized", true, bounded.Initialize(256));
    router.m_heap = &bounded;
    const std::array<hkUint8, 512> bytes{};
    bool threw = false;
    try
    {
        new hkpMoppCode({}, bytes);
    }
    catch (const std::bad_alloc&)
    {
        threw = true;
    }
    checks.Equal("code allocation failure propagated", true, threw);
    checks.Equal("failed code construction returned object block", 0, InUse(bounded));
    hkMemoryAllocator::MemoryStatistics statistics;
    bounded.getMemoryStatistics(statistics);
    checks.Equal("failure occurred after an object allocation", true, statistics.peakInUse > 0);
    router.m_heap = &heap;
    bounded.Release();
    checks.Equal("bounded arena cleanup balanced", 0, InUse(heap));
}

void CrossRouterAndThread(Checks& checks, hkSystemMemoryAllocator& firstHeap,
                          hkSystemMemoryAllocator& secondHeap, hkMemoryRouter& first,
                          hkMemoryRouter& second)
{
    const std::array<hkUint8, 4> bytes{1, 2, 3, 4};
    auto* code = new hkpMoppCode({}, bytes);
    auto* child = new hkpSphereShape(6.0f);
    auto* wrapper = new hkpMoppBvTreeShape(child, *code);
    code->removeReference();
    child->removeReference();
    std::vector<std::thread> threads;
    for (int i = 0; i < 4; ++i)
        threads.emplace_back([wrapper] {
            for (int n = 0; n < 10000; ++n)
            {
                wrapper->addReference();
                wrapper->removeReference();
            }
        });
    for (auto& thread : threads)
        thread.join();
    checks.Equal("concurrent owners preserve child", true, child == wrapper->getChild());
    SetThreadLocalValue(&second);
    wrapper->removeReference();
    checks.Equal("release returns blocks to supplying heap", 0, InUse(firstHeap));
    checks.Equal("release does not charge current heap", 0, InUse(secondHeap));
    SetThreadLocalValue(&first);
    auto* otherCode = new hkpMoppCode({}, bytes);
    auto* otherChild = new hkpSphereShape(8.0f);
    auto* detachedRelease = new hkpMoppBvTreeShape(otherChild, *otherCode);
    otherCode->removeReference();
    otherChild->removeReference();
    std::thread([detachedRelease] { detachedRelease->removeReference(); }).join();
    checks.Equal("final release without a published router", 0, InUse(firstHeap));
}
}

int main()
{
    Checks checks("Havok MOPP lifetime");
    havok::native_memory::AlignedAllocator backing;
    hkSystemMemoryAllocator heap(backing), otherHeap(backing);
    hkMemoryRouter router, otherRouter;
    router.m_heap = &heap;
    otherRouter.m_heap = &otherHeap;
    SetThreadLocalValue(&router);
    SharedOwners(checks, heap);
    BulletShapeProducer(checks, heap);
    NestedAndIndependent(checks, heap);
    BorrowedAndFailure(checks, heap);
    ContainerAndAllocationFailure(checks, heap, router);
    CrossRouterAndThread(checks, heap, otherHeap, router, otherRouter);
    SetThreadLocalValue(nullptr);
    return checks.ExitCode();
}
