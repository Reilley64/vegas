#ifndef FNV_BS_SIMPLE_ARRAY_USHORT_H
#define FNV_BS_SIMPLE_ARRAY_USHORT_H

// BSSimpleArray<unsigned short, 1024>: the array of 16-bit indices that the
// navmesh code keeps in its grid cells and records.
//
// This is the one shared declaration of the class. The constructor at
// 0x006917d0 stores the table at 0x0106abe4. Its four entries are the
// virtual functions below, in this order; the comment of each gives its slot
// and the address the table holds. The header has no body:
// docs/navmesh-index-array-constructor.md says which unit defines each member.
template <class T, unsigned int N> class BSSimpleArray;

template <> class BSSimpleArray<unsigned short, 1024>
{
  public:
    BSSimpleArray(); // 0x006917d0
    // Slot 0 holds the compiler's vector deleting destructor, standing for
    // 0x0069d9a0, which destroys through this destructor.
    virtual ~BSSimpleArray(); // 0x00691800
    virtual void* AllocateDoubleSizedBuffer(int count); // slot 1, 0x00691870
    virtual void FreeBuffer(void* p); // slot 2, 0x006db090
    // The return type of slot 3 is open. The receiver 0x005ef6a0
    // (FUN_005ef6a0Class::SetOrReplace) assigns its result as void*; on x64
    // that works only because the body tail-jumps to Reallocate, which leaves
    // rax set. Returning void* (with the key and row respelled) is owed
    // before VEGAS-65 closes.
    virtual void FUN_006918a0(void* p, int aiSize); // slot 3, 0x006918a0

    unsigned short* buffer;
    unsigned int size;
    unsigned int reserved;
};

#if defined(_WIN64)
// The table pointer at 0, then the buffer at 8 and the two counts at 16 and
// 20, as the declared types give them.
static_assert(sizeof(BSSimpleArray<unsigned short, 1024>) == 24);
static_assert(alignof(BSSimpleArray<unsigned short, 1024>) == 8);
#endif

#endif
