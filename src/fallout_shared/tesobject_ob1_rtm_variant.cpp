
// src/fallout_shared/tesobject_ob1_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout_shared/tesobject.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /Od /Oy- /GS /EHsc /Gy /GF /Ob1 (unit lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton.

#include "fnv/decl/A5D2C0Object.h"
#include "fnv/decl/BSXFlags_shell.h"
#include "fnv/decl/ControllerOwner.h"
#include "fnv/decl/FUN_00407820_shell.h"
#include "fnv/decl/FUN_0040e500_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00477ba0_shell.h"
#include "fnv/decl/FUN_0047cdb0_shell.h"
#include "fnv/decl/FUN_004aad00_shell.h"
#include "fnv/decl/FUN_0050d4a0_shell.h"
#include "fnv/decl/FUN_0050e8b0_shell.h"
#include "fnv/decl/FUN_0050ed30_class.h"
#include "fnv/decl/FUN_005102b0_shell.h"
#include "fnv/decl/FUN_00510360_Class.h"
#include "fnv/decl/FUN_00510380_Class.h"
#include "fnv/decl/FUN_005bb4d0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00929240_Class.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00ac5430_cls.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/LightCreation__LightForm.h"
#include "fnv/decl/MyHost.h"
#include "fnv/decl/TESActorBase.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/Thing.h"
#include "fnv/decl/fnv_0044a730__FUN_0044a730_cls.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0047ce10__OwnerShell.h"
#include "fnv/decl/fnv_0050f9c0__FUN_0050f9c0_shell.h"
#include "fnv/decl/fnv_00567400__FUN_00567400_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00ad8100__FUN_00ad8100_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00448000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00489000.h"
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_0050e000.h"
#include "fnv/symbols_00511000.h"
#include "fnv/symbols_00517000.h"
#include "fnv/symbols_00518000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011df000.h"
#include "fnv/symbols_011f6000.h"
#include "tesobject_decls.h"

void __cdecl operator delete(void* _Ptr) throw();
inline void* operator new(unsigned int, void* _Where) throw()
{
    return _Where;
}
inline void operator delete(void*, void*) throw()
{}
namespace skac53 {
void FUN_00ec7c56();
extern "C" unsigned int __cdecl strlen(const char* _Str);
extern "C" int __cdecl memcmp(const void* _Buf1, const void* _Buf2, unsigned int _Size);
int FUN_00ec7c66(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
int FUN_00ec7c6b(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
struct BxSecureTag
{
};
struct BxStrTraits
{
    static char* _Copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c66(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static char* _Move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c6b(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static unsigned int length(const char* _First)
    {
        return strlen(_First);
    }
    static int compare(const char* _First1, const char* _First2, unsigned int _Count)
    {
        return memcmp(_First1, _First2, _Count);
    }
    static void assign(char& _Left, const char& _Right)
    {
        _Left = _Right;
    }
};
inline BxSecureTag BxCharTraitsCat()
{
    BxSecureTag _Secure_char_traits;
    return _Secure_char_traits;
}
struct BxTraitsHelper
{
    template <class T>
    static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Copy_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return copy_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
    template <class T>
    static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Move_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return move_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
};
struct BxBadAlloc
{
    const char* pWhat;
    int iDoFree;
    BxBadAlloc(const char* what);
    ~BxBadAlloc();
};
template <class T> inline T* BxAllocate(unsigned int count, T*)
{
    if (count <= 0)
    {
        count = 0;
    }
    else if (((unsigned int)(-1) / count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)::FUN_00401000(count * sizeof(T));
}
template <class T> struct BxAllocT
{
    typedef T* pointer;
    BxAllocT() throw()
    {}
    BxAllocT(const BxAllocT<T>&) throw()
    {}
    pointer allocate(unsigned int _Count)
    {
        return BxAllocate(_Count, (pointer)0);
    }
    pointer allocate(unsigned int _Count, const void*)
    {
        return allocate(_Count);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        ::FUN_00401030 delete(_Ptr);
    }
    unsigned int max_size() const
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
typedef BxAllocT<char> BxCharAlloc;
struct BxStringVal
{
    BxCharAlloc _Alval;
    BxStringVal(BxCharAlloc _Al = BxCharAlloc()) : _Alval(_Al)
    {}
    BxStringVal(const BxStringVal& _Right) : _Alval(_Right._Alval)
    {}
};
struct BxString : public BxStringVal
{
    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    BxString(const char* _Ptr) : BxStringVal()
    {
        _Tidy();
        assign(_Ptr);
    }
    BxString() : BxStringVal()
    {
        _Tidy();
    }
    BxString& operator=(const BxString& _Right)
    {
        return assign(_Right);
    }
    BxString& assign(const BxString& _Right)
    {
        return assign(_Right, 0, (*reinterpret_cast<int *>(&::g_010173f0)));
    }
    BxString(const BxString& _Right) : BxStringVal(_Right)
    {
        _Tidy();
        assign(_Right, 0, (*reinterpret_cast<int *>(&::g_010173f0)));
    }
    ~BxString()
    {
        _Tidy(true);
    }
    static void _Xlen();
    static void _Xran();
    unsigned int size() const
    {
        return _Mysize;
    }
    char& operator[](unsigned int _Off)
    {
        if (!(_Off <= _Mysize))
        {
            FUN_00ec7c56();
        }
        do
        {
        } while (0);
        return _Myptr()[_Off];
    }
    unsigned int max_size() const
    {
        unsigned int _Num = _Alval.max_size();
        return _Num <= 1 ? 1 : _Num - 1;
    }
    char* _Myptr()
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    const char* _Myptr() const
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    void _Eos(unsigned int _Newsize)
    {
        BxStrTraits::assign(_Myptr()[_Mysize = _Newsize], char());
    }
    BxString& erase(unsigned int _Off = 0, unsigned int _Count = (unsigned int)-1)
    {
        if (_Mysize < _Off)
        {
            _Xran();
        }
        if (_Mysize - _Off < _Count)
        {
            _Count = _Mysize - _Off;
        }
        if (0 < _Count)
        {
            BxTraitsHelper::move_s<BxStrTraits>(_Myptr() + _Off, _Myres - _Off, _Myptr() + _Off + _Count,
                                                _Mysize - _Off - _Count);
            unsigned int _Newsize = _Mysize - _Count;
            _Eos(_Newsize);
        }
        return *this;
    }
    bool _Inside(const char* _Ptr)
    {
        if (_Ptr == 0 || _Ptr < _Myptr() || _Myptr() + _Mysize <= _Ptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void _Tidy(bool _Built = false, unsigned int _Newsize = 0)
    {
        if (!_Built)
        {
        }
        else if (16 <= _Myres)
        {
            char* _Ptr = _Bx._Ptr;
            if (0 < _Newsize)
            {
                BxTraitsHelper::copy_s<BxStrTraits>(_Bx._Buf, 16, _Ptr, _Newsize);
            }
            _Alval.deallocate(_Ptr, _Myres + 1);
        }
        _Myres = 16 - 1;
        _Eos(_Newsize);
    }
    void _Copy(unsigned int _Newsize, unsigned int _Oldlen)
    {
        unsigned int _Newres = _Newsize | 15;
        if (max_size() < _Newres)
        {
            _Newres = _Newsize;
        }
        else if (_Newres / 3 < _Myres / 2 && _Myres <= max_size() - _Myres / 2)
        {
            _Newres = _Myres + _Myres / 2;
        }
        char* _Ptr = 0;
        try
        {
            _Ptr = _Alval.allocate(_Newres + 1);
        }
        catch (...)
        {
            _Newres = _Newsize;
            try
            {
                _Ptr = _Alval.allocate(_Newres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < _Oldlen)
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Ptr, _Newres + 1, _Myptr(), _Oldlen);
        }
        _Tidy(true);
        _Bx._Ptr = _Ptr;
        _Myres = _Newres;
        _Eos(_Oldlen);
    }
    bool _Grow(unsigned int _Newsize, bool _Trim = false)
    {
        if (max_size() < _Newsize)
        {
            _Xlen();
        }
        if (_Myres < _Newsize)
        {
            _Copy(_Newsize, _Mysize);
        }
        else if (_Trim && _Newsize < 16)
        {
            reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, _Newsize < _Mysize ? _Newsize : _Mysize);
        }
        else if (_Newsize == 0)
        {
            _Eos(0);
        }
        return 0 < _Newsize;
    }
    BxString& assign(const BxString& _Right, unsigned int _Roff, unsigned int _Count)
    {
        if (_Right.size() < _Roff)
        {
            _Xran();
        }
        unsigned int _Num = _Right.size() - _Roff;
        if (_Count < _Num)
        {
            _Num = _Count;
        }
        if (this == &_Right)
        {
            erase((unsigned int)(_Roff + _Num)), erase(0, _Roff);
        }
        else if (_Grow(_Num))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Right._Myptr() + _Roff, _Num);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& assign(const char* _Ptr, unsigned int _Count)
    {
        if (_Inside(_Ptr))
        {
            return assign(*this, _Ptr - _Myptr(), _Count);
        }
        if (_Grow(_Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Ptr, _Count);
            _Eos(_Count);
        }
        return *this;
    }
    const char& operator[](unsigned int _Off) const
    {
        if (!(_Off <= _Mysize))
        {
            FUN_00ec7c56();
        }
        return _Myptr()[_Off];
    }
    BxString& append(const BxString& _Right, unsigned int _Roff, unsigned int _Count)
    {
        if (_Right.size() < _Roff)
        {
            _Xran();
        }
        unsigned int _Num = _Right.size() - _Roff;
        if (_Num < _Count)
        {
            _Count = _Num;
        }
        if ((*reinterpret_cast<int *>(&::g_010173f0)) - _Mysize <= _Count || _Mysize + _Count < _Mysize)
        {
            _Xlen();
        }
        if (0 < _Count && _Grow(_Num = _Mysize + _Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr() + _Mysize, _Myres - _Mysize, _Right._Myptr() + _Roff, _Count);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& append(const char* _Ptr, unsigned int _Count)
    {
        if (_Inside(_Ptr))
        {
            return append(*this, _Ptr - _Myptr(), _Count);
        }
        if ((*reinterpret_cast<int *>(&::g_010173f0)) - _Mysize <= _Count)
        {
            _Xlen();
        }
        unsigned int _Num;
        if (0 < _Count && _Grow(_Num = _Mysize + _Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr() + _Mysize, _Myres - _Mysize, _Ptr, _Count);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& append(const char* _Ptr)
    {
        return append(_Ptr, BxStrTraits::length(_Ptr));
    }
    BxString& operator+=(const char* _Ptr)
    {
        return append(_Ptr);
    }
    const char* c_str() const
    {
        return _Myptr();
    }
    int compare(unsigned int _Off, unsigned int _N0, const char* _Ptr, unsigned int _Count) const
    {
        if (_Mysize < _Off)
            _Xran();
        if (_Mysize - _Off < _N0)
            _N0 = _Mysize - _Off;
        unsigned int _Ans = BxStrTraits::compare(_Myptr() + _Off, _Ptr, _N0 < _Count ? _N0 : _Count);
        return _Ans != 0 ? (int)_Ans : _N0 < _Count ? -1 : _N0 == _Count ? 0 : +1;
    }
    int compare(const char* _Ptr) const
    {
        return compare(0, _Mysize, _Ptr, BxStrTraits::length(_Ptr));
    }
    BxString& assign(const char* _Ptr)
    {
        return assign(_Ptr, BxStrTraits::length(_Ptr));
    }
};
inline bool operator==(const BxString& _Left, const char* _Right)
{
    return _Left.compare(_Right) == 0;
}
inline bool operator!=(const BxString& _Left, const char* _Right)
{
    return !(_Left == _Right);
}
struct GvFileHandle;
extern "C" int __cdecl fseek(GvFileHandle* _File, long _Offset, int _Origin);
void FUN_00ac6430(int code, BxString message);
}

struct SeekBinaryFile
{
    skac53::BxString kPath;
    skac53::BxString kMagic;
    skac53::GvFileHandle* pFile;
    virtual void v00();
    __declspec(noinline) bool FUN_00ac53a0(long offset);
};

// @fnv 0x00ac53a0
bool SeekBinaryFile::FUN_00ac53a0(long offset)
{
    if (pFile == 0)
    {
        return false;
    }
    if (skac53::fseek(pFile, offset, 0) != 0)
    {
        skac53::FUN_00ac6430(7, kPath);
        reinterpret_cast<::FUN_00ac5430_cls *>(this)->FUN_00ac5430();
        return false;
    }
    return true;
}
