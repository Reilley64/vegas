// fallout_shared/settings/xgamesetting.cpp: GameSettingCollection, StrArr (9 functions)

#include <cstring>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00404b70.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00462e80_shell.h"
#include "fnv/decl/FUN_00471870_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f8960_shell.h"
#include "fnv/decl/FUN_004f8a30_shell2.h"
#include "fnv/decl/FUN_004f8a60_class.h"
#include "fnv/decl/FUN_00c4c920_class.h"
#include "fnv/decl/SettingS.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TESOffsetWorker.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00a7d000.h"
#include "xgamesetting_decls.h"

// Reads a DATA chunk from the current TESFile and stores its payload into the setting according to the setting's type.
// @fnv 0x004f8860
bool GameSettingCollection::ReadSetting(Setting& setting)
{
    bool result = false;
    if (((::TESFile *)(reinterpret_cast<::FUN_004f8960_shell *>(this)->FUN_004f8960())))
    {
        TESFile* file = ((::TESFile *)(reinterpret_cast<::FUN_004f8960_shell *>(this)->FUN_004f8960()));
        file->NextChunk();
        if (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) == 0x41544144)
        {
            switch (setting.FUN_004f8940())
            {
            case 3:
                result = file->GetChunkData(&setting.uValue.u);
                break;
            case 5:
                result = file->GetChunkData(&setting.uValue.u);
                break;
            case 6:
                char* buffer = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
                result = reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(buffer), 0);
                reinterpret_cast<::SettingS *>(&(setting))->FUN_00c33170(buffer);
                break;
            }
        }
    }
    return result;
}

// Reads a setting from the file by key, returning whether a matching setting was found and read, then closes the file.
// @fnv 0x004f89c0
bool GameSettingCollection::ReadSetting(TESFile* file, const char* key)
{
    bool result = false;
    reinterpret_cast<::FUN_004f8a60_class *>(this)->SetField108((int)(file));
    {
        Setting* setting = ((::Setting *)(reinterpret_cast<::FUN_004f8a30_shell2 *>(this)->FUN_004f8a30((int)(((const char *)(::FUN_00464f30((int)(key))))))));
        if (setting)
            result = ReadSetting(*setting);
    }
    Close();
    return result;
}

// @fnv 0x004f89a0
bool GameSettingCollection::Close()
{
    pFile = 0;
    return true;
}

struct S_0060ba10
{
    char pad[0xa];
    unsigned short s;
    void FUN_0060bd90(unsigned short, int);
    void FUN_0096a610(int a);
};
// @fnv 0x0096a610
void S_0060ba10::FUN_0096a610(int a)
{
    FUN_0060bd90(s, a);
}

struct FUN_004f8980_shell
{
    virtual bool FUN_004f8980(bool);
};

// @fnv 0x004f8980
bool FUN_004f8980_shell::FUN_004f8980(bool)
{
    return *(int*)((char*)this + 0x108) != 0;
}

struct S00404b40
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00404b70, frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00404b40
void* S00404b40::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00404b70 *>(this)->FUN_00404b71();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct NiTPrimitiveArray_unsigned_int_
{
};
struct Base00404fd0
{
    unsigned int FUN_00404fd0(NiTPrimitiveArray_unsigned_int_*);
};
struct Holder004f8800 : Base00404fd0
{
    unsigned int AddGameSettingsStrings(NiTPrimitiveArray_unsigned_int_*);
};
// Adds "GameSettings" and "Total GameSettings" strings to apStrings and returns the count from FUN_00404fd0.
// @fnv 0x004f8800
unsigned int Holder004f8800::AddGameSettingsStrings(NiTPrimitiveArray_unsigned_int_* apStrings)
{
    unsigned int I;
    reinterpret_cast<::S_0060ba10 *>((apStrings))->FUN_0096a610((int)&(const unsigned int &)((unsigned int)::FUN_00a7d330("GameSettings")));
    I = FUN_00404fd0(apStrings);
    reinterpret_cast<::S_0060ba10 *>((apStrings))->FUN_0096a610((int)&(const unsigned int &)((unsigned int)FUN_00a7d510("Total GameSettings", I)));
    return I;
}

struct StrArr
{
    unsigned char _pad0[8];
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short _pad1;
    unsigned short m_usGrowBy;
    unsigned int FUN_00c4c8d0(char*&);
};
struct Pad12
{
    int a;
    int b;
    int c;
};
// Appends element to the array, growing it by m_usGrowBy if full, and returns the index it was stored at.
// @fnv 0x00c4c8d0
unsigned int StrArr::FUN_00c4c8d0(char*& element)
{
    Pad12 pad;
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::FUN_00c4c920_class *>(this)->FUN_00c4c920(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, element);
        return uiIndex;
    }
}


// @fnv 0x00c4bd20
int __cdecl FUN_00c4bd20(Setting* setting)
{
    int res = 0;
    char* dst;
    const char* n = setting->pKey;
    const char* p = n;
    if (p)
    {
        dst = std::strstr((char *)(p), "_:");
        if (dst)
        {
            dst += 2;
        }
    }
    else
    {
        res = 0;
    }
    return res;
}
