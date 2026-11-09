#pragma once

#include <cstddef>
#include <cstdint>
#include <exception>
#include <limits>
#include <memory>
#include <stdexcept>
#include <type_traits>
#include <utility>

class NiRefObject;

namespace fnv::list {

// Canonical MemoryManager-owned storage boundary. Production callers use this
// seam instead of declaring another manager receiver or exposing pool state.
void RefillStorage();
void* AcquireStorage();
void RecycleStorage(void*) noexcept;
bool ShutdownStorage() noexcept;

template <class Payload>
struct Node {
    Node* next = nullptr;
    Node* previous = nullptr;
    Payload* payload = nullptr;
};

static_assert(sizeof(Node<void>) == 3 * sizeof(void*));
static_assert(std::is_standard_layout_v<Node<void>>);

template <class Payload>
Node<Payload>* AcquireNode()
{
    auto* storage = AcquireStorage();
    return std::construct_at(static_cast<Node<Payload>*>(storage));
}

template <class Payload>
void RecycleNode(Node<Payload>* node) noexcept
{
    std::destroy_at(node);
    RecycleStorage(node);
}

bool TryRetainPayload(NiRefObject*) noexcept;
void ReleasePayload(NiRefObject*) noexcept;

class RetainedPayload {
  public:
    RetainedPayload() noexcept = default;
    explicit RetainedPayload(NiRefObject* payload) : payload_(payload)
    {
        if (!TryRetainPayload(payload_))
            throw std::overflow_error("native payload reference count overflow");
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
            RetainedPayload replacement(std::move(other));
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
    RecycleNode(node);
}

inline void PushBack(RetainedNode*& head, RetainedNode*& tail,
                     std::uint32_t& count, NiRefObject* payload)
{
    if (count == std::numeric_limits<std::uint32_t>::max())
        throw std::length_error("native list node count overflow");

    auto* node = AcquireNode<NiRefObject>();
    try {
        if (!TryRetainPayload(payload))
            throw std::overflow_error("native payload reference count overflow");
    } catch (...) {
        RecycleNode(node);
        throw;
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
