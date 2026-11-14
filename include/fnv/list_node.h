#pragma once

#include <cstddef>
#include <cstdint>
#include <exception>
#include <new>

class NiRefObject;

namespace fnv::list {

// Every node of the common pool is exactly three native pointers.
inline constexpr std::size_t NodeBytes = 3 * sizeof(void*);

// Canonical MemoryManager-owned storage boundary. Storage carries no object
// lifetime: AcquireStorage returns an unoccupied slot and RecycleStorage ends
// whatever trivially destructible occupant remains by reusing its bytes.
// Typed consumers use ConstructNode/AdoptNode/DestroyNode below, or
// RecycleViewedNode for a node another unit began. Only the source's
// type-erased pointer deallocators hand a slot straight to RecycleStorage,
// after their typed caller has released the element.
void RefillStorage();
void* AcquireStorage();
void RecycleStorage(void*) noexcept;
bool ShutdownStorage() noexcept;

// Out-of-line so that this header needs no standard exception or string
// definitions in the many units that only recycle nodes.
[[noreturn]] void ThrowNodeCountOverflow();
[[noreturn]] void ThrowPayloadCountOverflow();

// Begins the lifetime of the caller's complete node type, including a
// nontrivial element, in one pool slot. The slot returns to the pool if the
// node's own construction throws.
template <class NodeType, class... Arguments>
NodeType* ConstructNode(Arguments&&... arguments)
{
    static_assert(sizeof(NodeType) == NodeBytes);
    static_assert(alignof(NodeType) <= alignof(void*));
    void* storage = AcquireStorage();
    try {
        return ::new (storage) NodeType(static_cast<Arguments&&>(arguments)...);
    } catch (...) {
        RecycleStorage(storage);
        throw;
    }
}

// Ends the node's lifetime, running its element's destructor, before the slot
// becomes a free link.
template <class NodeType>
void DestroyNode(NodeType* node) noexcept
{
    static_assert(sizeof(NodeType) == NodeBytes);
    node->~NodeType();
    RecycleStorage(node);
}

// For a unit that recycles a node it did not begin. The unit only views the
// slot through its own three-pointer, trivially destructible layout, so the
// slot is reused as storage and no lifetime of the view type is claimed.
template <class NodeView>
void RecycleViewedNode(NodeView* node) noexcept
{
    static_assert(sizeof(NodeView) == NodeBytes);
    static_assert(__is_trivially_destructible(NodeView));
    RecycleStorage(node);
}

template <class Payload>
struct Node {
    Node* next = nullptr;
    Node* previous = nullptr;
    Payload* payload = nullptr;
};

static_assert(sizeof(Node<void>) == NodeBytes);

// The type-erased allocator entry 0x0043a010 returns a zeroed, trivially
// destructible Node<void>. A typed caller of that entry begins its own node in
// the same slot, which ends the erased node, instead of converting the pointer.
template <class NodeType, class... Arguments>
NodeType* AdoptNode(void* storage, Arguments&&... arguments)
{
    static_assert(sizeof(NodeType) == NodeBytes);
    static_assert(alignof(NodeType) <= alignof(void*));
    try {
        return ::new (storage) NodeType(static_cast<Arguments&&>(arguments)...);
    } catch (...) {
        RecycleStorage(storage);
        throw;
    }
}

template <class Payload>
Node<Payload>* AcquireNode()
{
    return ConstructNode<Node<Payload>>();
}

template <class Payload>
void RecycleNode(Node<Payload>* node) noexcept
{
    DestroyNode(node);
}

bool TryRetainPayload(NiRefObject*) noexcept;
void ReleasePayload(NiRefObject*) noexcept;

class RetainedPayload {
  public:
    RetainedPayload() noexcept = default;
    explicit RetainedPayload(NiRefObject* payload) : payload_(payload)
    {
        if (!TryRetainPayload(payload_))
            ThrowPayloadCountOverflow();
    }
    RetainedPayload(const RetainedPayload& other) : RetainedPayload(other.payload_) {}
    RetainedPayload(RetainedPayload&& other) noexcept : payload_(other.Release()) {}
    RetainedPayload& operator=(const RetainedPayload& other)
    {
        if (payload_ != other.payload_) {
            RetainedPayload replacement(other);
            Swap(replacement);
        }
        return *this;
    }
    RetainedPayload& operator=(RetainedPayload&& other) noexcept
    {
        if (this != &other) {
            RetainedPayload replacement(static_cast<RetainedPayload&&>(other));
            Swap(replacement);
        }
        return *this;
    }
    ~RetainedPayload() { ReleasePayload(payload_); }

    NiRefObject* Get() const noexcept { return payload_; }
    explicit operator bool() const noexcept { return payload_ != nullptr; }
    NiRefObject* Release() noexcept
    {
        auto* payload = payload_;
        payload_ = nullptr;
        return payload;
    }
    void Swap(RetainedPayload& other) noexcept
    {
        auto* payload = payload_;
        payload_ = other.payload_;
        other.payload_ = payload;
    }

  private:
    NiRefObject* payload_ = nullptr;
};

using RetainedNode = Node<NiRefObject>;

inline void Retire(RetainedNode* node) noexcept
{
    auto* payload = node->payload;
    node->payload = nullptr;
    ReleasePayload(payload);
    // The removal receivers are entered from units that began the node under
    // their own layout-identical type.
    RecycleViewedNode(node);
}

inline void PushBack(RetainedNode*& head, RetainedNode*& tail,
                     std::uint32_t& count, NiRefObject* payload)
{
    if (count == UINT32_MAX)
        ThrowNodeCountOverflow();

    auto* node = AcquireNode<NiRefObject>();
    if (!TryRetainPayload(payload)) {
        RecycleNode(node);
        ThrowPayloadCountOverflow();
    }

    node->payload = payload;
    node->previous = tail;
    if (tail)
        tail->next = node;
    else
        head = node;
    tail = node;
    ++count;
}

inline RetainedPayload Remove(RetainedNode*& head, RetainedNode*& tail,
                              std::uint32_t& count, RetainedNode*& position)
{
    auto* node = position;
    if (!node)
        return {};
    if (!count)
        std::terminate();

    // Establish the result's ownership before unlinking or retiring the
    // list's reference. Overflow leaves every link and count unchanged.
    RetainedPayload result(node->payload);
    position = node->next;

    if (node->previous)
        node->previous->next = node->next;
    else
        head = node->next;
    if (node->next)
        node->next->previous = node->previous;
    else
        tail = node->previous;

    Retire(node);
    --count;
    return result;
}

inline RetainedPayload PopFront(RetainedNode*& head, RetainedNode*& tail,
                                std::uint32_t& count)
{
    auto* position = head;
    return Remove(head, tail, count, position);
}

inline RetainedPayload PopBack(RetainedNode*& head, RetainedNode*& tail,
                               std::uint32_t& count)
{
    auto* position = tail;
    return Remove(head, tail, count, position);
}

inline void Clear(RetainedNode*& head, RetainedNode*& tail,
                  std::uint32_t& count) noexcept
{
    while (head) {
        auto* node = head;
        head = node->next;
        Retire(node);
    }
    tail = nullptr;
    count = 0;
}

class RetainedList {
  public:
    RetainedList() noexcept = default;
    RetainedList(const RetainedList&) = delete;
    RetainedList& operator=(const RetainedList&) = delete;
    ~RetainedList() { Clear(); }

    RetainedNode* head = nullptr;
    RetainedNode* tail = nullptr;
    std::uint32_t count = 0;

    bool Empty() const noexcept { return count == 0; }
    void PushBack(NiRefObject* payload) { fnv::list::PushBack(head, tail, count, payload); }
    RetainedPayload PopFront() { return fnv::list::PopFront(head, tail, count); }
    RetainedPayload PopBack() { return fnv::list::PopBack(head, tail, count); }
    RetainedPayload Remove(RetainedNode*& position)
    {
        return fnv::list::Remove(head, tail, count, position);
    }
    void Clear() noexcept { fnv::list::Clear(head, tail, count); }
};

} // namespace fnv::list
