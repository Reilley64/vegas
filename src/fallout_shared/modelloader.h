
#include "fnv/decl/FUN_0044a8d0_Class.h"
#include "fnv/decl/FUN_0044a970_Cls.h"
#include "fnv/symbols_0044c000.h"
#include "modelloader_decls.h"
// @fnv 0x00712380
unsigned char QueuedFileLoad::GetFileIndex()
{
    return fileIndex;
}
// @fnv 0x0043fdf0
void QueuedReference::ProcessLoadedAnimIdle()
{
    vfn_3c();
}
template <>
// @fnv 0x0044a7f0
std::basic_string<char, std::char_traits<char>, std::allocator<char> >& std::basic_string<
    char, std::char_traits<char>, std::allocator<char> >::assign(const char* source, unsigned int count)
{
    if (_Inside(source))
        return assign(*this, source - reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970(), count);
    if (reinterpret_cast<::FUN_0044a8d0_Class *>(this)->FUN_0044a8d0(count, false))
    {
        ::FUN_0044ccd0(reinterpret_cast<::FUN_0044a970_Cls *>(this)->FUN_0044a970(), capacity, source, count);
        _Eos(count);
    }
    return *this;
}
