#ifndef FNV_MODEL_LOADER_MATRIX_VALUE_H
#define FNV_MODEL_LOADER_MATRIX_VALUE_H

// FUN_00aade20: the matrix value of the model loader's arrays. A float
// vector, a column count, a row count and a name string.
//
// This is the one declaration of the class whose default constructor
// build/units.json gives to src/fallout_shared/modelloader.cpp at 0x00aade20.
// A unit that gives that constructor storage includes this header, so the
// storage has the size the constructor is compiled for.
//
// The header has no body. src/fallout_shared/modelloader.cpp defines the
// members that have one. Only the constructor of FUN_00aade20 has a function
// row under its own name. The other members are the ones the class and its
// parts had in that unit. A member declared inline here is defined inline
// there; the iterator's operator!= is defined there out of line; the float
// vector's constructor and destructor and ~FUN_00aade20() have no definition.
// docs/model-loader-matrix-constructor.md has what is and is not established
// about this layout.

template <class T> struct Aade20CharTraits;

template <class T> class Aade20Allocator
{
  public:
    inline Aade20Allocator() throw();
    inline Aade20Allocator(const Aade20Allocator&) throw();
    inline void deallocate(T* pointer, unsigned int);
};

template <class T, class Alloc> class Aade20StringAllocator
{
  protected:
    Alloc allocation;
    inline Aade20StringAllocator(Alloc value = Alloc());
};

// The name string: sixteen characters inside the object, or a pointer to
// longer text. The two counts keep the 32-bit width of the original release.
template <class T, class Traits, class Alloc> class Aade20BasicString : public Aade20StringAllocator<T, Alloc>
{
    union Storage
    {
        T buffer[16];
        T* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;

  protected:
    inline T* data();
    inline void setLength(unsigned int count);
    inline void _Tidy(bool built = false, unsigned int remaining = 0);

  public:
    inline Aade20BasicString();
    inline ~Aade20BasicString();
};

class Aade20FloatVector;

// The float vector's iterator: the owner word and the element pointer.
struct Aade20ConstIterator
{
    const void* owner;
    float* value;
    inline Aade20ConstIterator(float* p, const Aade20FloatVector* vector);
    bool operator!=(const Aade20ConstIterator&) const;
};

struct Aade20Iterator : Aade20ConstIterator
{
    inline Aade20Iterator(float* p, const Aade20FloatVector* vector);
};

class Aade20FloatVector
{
  public:
    void* auxiliary;
    unsigned int allocatorAuxiliary;
    unsigned int allocatorElements;
    float* first;
    float* last;
    float* end;
    // Declared and not defined: no archive member defines either.
    Aade20FloatVector();
    ~Aade20FloatVector();
    inline Aade20Iterator begin();
    inline Aade20Iterator finish();
    inline Aade20Iterator makeIterator(Aade20ConstIterator) const;
    inline Aade20Iterator erase(Aade20ConstIterator, Aade20ConstIterator);
    inline void clear();
};

struct Aade20Matrix : Aade20FloatVector
{
    unsigned int columns, rows;
    inline Aade20Matrix();
};

struct FUN_00aade20 : Aade20Matrix
{
    Aade20BasicString<char, Aade20CharTraits<char>, Aade20Allocator<char> > text;
    FUN_00aade20(); // 0x00aade20
    // Declared, as the staging unit's own copy of the class declared it, and
    // defined nowhere. The recipe has no row under this name.
    ~FUN_00aade20();
};

// The sizes the windows-x64 compiler gives these declarations.
static_assert(sizeof(void*) != 8 || (sizeof(Aade20ConstIterator) == 0x10 && sizeof(Aade20FloatVector) == 0x28));
static_assert(sizeof(void*) != 8 || (sizeof(Aade20Matrix) == 0x30 && sizeof(FUN_00aade20) == 0x50));
static_assert(sizeof(void*) != 8 || alignof(FUN_00aade20) == 8);

#endif
