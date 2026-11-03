// fallout_shared/packageschedule.cpp: PackedByteIntRecord, DurationData (9 functions)

#include "fnv/decl/Calendar.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_005407b0_Class.h"
#include "fnv/decl/FUN_0060ce80_Obj.h"
#include "fnv/decl/FUN_00678cc0_shell.h"
#include "fnv/decl/FUN_00678ce0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "layout_support.h"

class PackedByteIntRecord
{
  public:
    char m_cByte0;
    char m_cByte1;
    char m_cByte2;
    char m_cLastByteBeforePayloadItem;
    int m_iPayloadInteger;
    void* Endian();
};

// @fnv 0x0087eaa0
void* PackedByteIntRecord::Endian()
{
    return (void*)((char*)this + 0x40);
}

struct DurationData
{
    int GetStartMonth();
    void SetStartMonth(int);
    int GetStartDayOfWeek();
    void SetStartDayOfWeek(int);
    char GetStartDate();
    void SetStartDate(char);
    char GetStartTime();
    void SetStartTime(char);
    int GetDuration();
    void SetDuration(int);
    void Copy(DurationData*);
    bool Compare(DurationData*);
    void Save();
    char* GetDayOfWeekName();
    char* GetMonthName();
    void* __vecDelDtor(unsigned int);
    PackedByteIntRecord m_kScheduleData;
public:
    int FUN_00678ca0();
};
typedef char _sizecheck_PackageSchedule[sizeof(DurationData) == 8 ? 1 : -1];
struct FUN_0067fcb0_shell : public DurationData
{
    void ResetSchedule(PackedByteIntRecord*);
};

// @fnv 0x0067fcb0
DurationData* __fastcall ResetSchedule(DurationData* pThis)
{
    pThis->m_kScheduleData.m_cByte0 = -1;
    pThis->m_kScheduleData.m_cByte1 = -1;
    pThis->m_kScheduleData.m_cByte2 = 0;
    pThis->m_kScheduleData.m_cLastByteBeforePayloadItem = -1;
    pThis->m_kScheduleData.m_iPayloadInteger = 0;
    return pThis;
}

namespace fnv_0067fd40 {
struct DurationData
{
    int GetStartMonth();
    void SetStartMonth(int);
    int GetStartDayOfWeek();
    void SetStartDayOfWeek(int);
    char GetStartDate();
    void SetStartDate(char);
    char GetStartTime();
    void SetStartTime(char);
    int GetDuration();
    void SetDuration(int);
    void Copy(DurationData*);
    bool Compare(DurationData*);
    void Save();
    char* GetDayOfWeekName();
    char* GetMonthName();
    void* __vecDelDtor(unsigned int);
    PackedByteIntRecord m_kScheduleData;
};
typedef char _sizecheck_PackageSchedule[sizeof(DurationData) == 8 ? 1 : -1];
struct FUN_0067fd40_shell : public DurationData
{
    void FUN_0067fd40(DurationData*);
};

// Copies the start month, day of week, date, time and duration from apCopy into this schedule when apCopy is non-null.
// @fnv 0x0067fd40
void FUN_0067fd40_shell::FUN_0067fd40(DurationData* apCopy)
{
    if (apCopy)
    {
        SetStartMonth(reinterpret_cast<::FUN_00678cc0_shell *>((apCopy))->GetSecondByte());
        reinterpret_cast<::FUN_005407b0_Class *>(this)->FUN_005407b0(reinterpret_cast<::DurationData *>((apCopy))->FUN_00678ca0());
        SetStartDate(reinterpret_cast<::FUN_00678ce0_shell *>((apCopy))->FUN_00678ce0());
        SetStartTime(reinterpret_cast<::Calendar *>((apCopy))->GetGameHour());
        reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(((int)(reinterpret_cast<::Callees *>((apCopy))->FUN_00726070()))));
    }
}
}  // namespace fnv_0067fd40

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CombatCoverPointData
{
    void Copy(void*);
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    bool IsHideCover();
    bool IsCrouchCover();
    bool IsStandCover();
    bool IsLedgeCover();
    bool IsValidCover();
    unsigned char GetCoverHeight();
    bool IsReserved();
    void SetReserved(bool);
    bool IsDirty();
    void SetDirty(bool);
    void* __vecDelDtor(unsigned int);
    bool m_bDataDirty;
    bool bReserved;
    unsigned char m_ucCoverHeight;
    char _pad_3[1];
    int iLocation;
    char m_cCoverData[12];
    char CombatCoverPoint[84];
    unsigned int m_uiCoverFlags;
    unsigned int m_uiLocationFlags;
    char m_cTrailingData[6];
    char _pad_76[2];
};
typedef char _sizecheck_CombatCoverLocation[sizeof(CombatCoverPointData) == 120 ? 1 : -1];
struct FUN_0067fdb0_shell : public CombatCoverPointData
{
    void FUN_0067fdb0(bool);
};

// @fnv 0x0067fdb0
void FUN_0067fdb0_shell::FUN_0067fdb0(bool abValue)
{
    bReserved = abValue;
}

struct QuestData
{
};


struct FUN_0067fec0_shell
{
    void Save();
};

// @fnv 0x0067fec0
void FUN_0067fec0_shell::Save()
{
    if (::FUN_00401500())
        reinterpret_cast<::FUN_0060ce80_Obj *>((reinterpret_cast<QuestData*>(this)))->FUN_0060ce80();
    ::AppendChunk(0x54445350, this, 8);
    if (::FUN_00401500())
        reinterpret_cast<::FUN_0060ce80_Obj *>((reinterpret_cast<QuestData*>(this)))->FUN_0060ce80();
}

struct FUN_0067fcf0_shell : PackedByteIntRecord
{
    FUN_0067fcf0_shell* AssignFrom(const FUN_0067fcf0_shell& other);
};
// Copies five fields from other into this and returns this.
// @fnv 0x0067fcf0
FUN_0067fcf0_shell* FUN_0067fcf0_shell::AssignFrom(const FUN_0067fcf0_shell& other)
{
    m_cByte0 = other.m_cByte0;
    m_cByte1 = other.m_cByte1;
    m_cByte2 = other.m_cByte2;
    m_cLastByteBeforePayloadItem = other.m_cLastByteBeforePayloadItem;
    m_iPayloadInteger = other.m_iPayloadInteger;
    return this;
}

struct FUN_0067fdd0_shell : PackedByteIntRecord
{
    void SetByteValue(unsigned char value);
};

// @fnv 0x0067fdd0
void FUN_0067fdd0_shell::SetByteValue(unsigned char value)
{
    m_cByte2 = value;
}

struct FUN_0067fdf0_shell
{
    void SetByteAtOffset3(unsigned char param_2);
};

// @fnv 0x0067fdf0
void FUN_0067fdf0_shell::SetByteAtOffset3(unsigned char aucValue)
{
    *(unsigned char*)((char*)this + 3) = aucValue;
}

namespace fnv_0067fe10 {
struct BoundHolder
{
};
struct DurationData : BoundHolder
{
    char FUN_0067fe10(DurationData* other);
};
// Returns 1 if other is null or any of five compared values differ, otherwise returns 0.
// @fnv 0x0067fe10
char DurationData::FUN_0067fe10(DurationData* other)
{
    if (!other)
        return 1;
    if (reinterpret_cast<::FUN_00678cc0_shell *>(this)->GetSecondByte() != reinterpret_cast<::FUN_00678cc0_shell *>((other))->GetSecondByte())
        return 1;
    if (reinterpret_cast<::DurationData *>(this)->FUN_00678ca0() != reinterpret_cast<::DurationData *>((other))->FUN_00678ca0())
        return 1;
    if (reinterpret_cast<::FUN_00678ce0_shell *>(this)->FUN_00678ce0() != reinterpret_cast<::FUN_00678ce0_shell *>((other))->FUN_00678ce0())
        return 1;
    if (reinterpret_cast<::Calendar *>(this)->GetGameHour() != reinterpret_cast<::Calendar *>((other))->GetGameHour())
        return 1;
    if (((int)(reinterpret_cast<::Callees *>(this)->FUN_00726070())) != ((int)(reinterpret_cast<::Callees *>((other))->FUN_00726070())))
        return 1;
    return 0;
}
}  // namespace fnv_0067fe10
