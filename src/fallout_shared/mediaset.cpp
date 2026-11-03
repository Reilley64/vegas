// fallout_shared/mediaset.cpp: MediaSet, MediaSetLoad, MediaSetBattle, MediaSetCopy and more (22 functions)

#include "fnv/decl/B408A80String.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_00596030_cls.h"
#include "fnv/decl/FUN_00598020_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/Tile.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00595000.h"
#include "fnv/symbols_00597000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00830000.h"
#include "fnv/symbols_00944000.h"
#include "fnv/symbols_00966000.h"
#include "fnv/symbols_01033000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "mediaset_decls.h"

// @fnv 0x00598a70
void MediaSet::InitItem()
{
    unsigned int formID;
    if (GetInitialized())
        return;

    formID = 0;
    formID = reinterpret_cast<unsigned int>(m_pSound1);
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        m_pSound1 = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if (!m_pSound1)
            ::FUN_005b5e40();
    }

    formID = reinterpret_cast<unsigned int>(m_pSound2);
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        m_pSound2 = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if (!m_pSound2)
            ::FUN_005b5e40();
    }

    SetInitializationState(true);
}

// Calls FUN_00597850 on six members, then zeroes two members.
// @fnv 0x00599bd0
void MediaSet::ClearData()
{
    ::FUN_00597850((::FUN_00597850_Class *)&(m_kMediaSetEntry1));
    ::FUN_00597850((::FUN_00597850_Class *)&(m_kMediaSetEntry2));
    ::FUN_00597850((::FUN_00597850_Class *)&(m_kMediaSetEntry3));
    ::FUN_00597850((::FUN_00597850_Class *)&(m_kMediaSetEntry4));
    ::FUN_00597850((::FUN_00597850_Class *)&(m_kMediaSetEntry5));
    ::FUN_00597850((::FUN_00597850_Class *)&(m_kMediaSetEntry6));
    m_pSound1 = 0;
    m_pSound2 = 0;
}

// @fnv 0x00599b30
void MediaSet::ResetFormData()
{
    ::FUN_00597850((::FUN_00597850_Class *)&(m_kMediaSetEntry1));
    ::FUN_00597850((::FUN_00597850_Class *)&(m_kMediaSetEntry2));
    ::FUN_00597850((::FUN_00597850_Class *)&(m_kMediaSetEntry3));
    ::FUN_00597850((::FUN_00597850_Class *)&(m_kMediaSetEntry4));
    ::FUN_00597850((::FUN_00597850_Class *)&(m_kMediaSetEntry5));
    ::FUN_00597850((::FUN_00597850_Class *)&(m_kMediaSetEntry6));
    m_fMediaParameter1 = 0.0f;
    fSkillValueBonus = 0.0f;
    m_fMediaParameter3 = 0.0f;
    m_fMediaValue = 0.0f;
    m_pSound1 = 0;
    m_pSound2 = 0;
}

// @fnv 0x00597610
MediaSet::MediaSet()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(ENUM_FORM_ID_MSET_ID)));
    Type = static_cast<MEDIASETTYPE>(-1);
    ::FUN_00597850((::FUN_00597850_Class *)&(m_kMediaSetEntry1));
    ::FUN_00597850((::FUN_00597850_Class *)&(m_kMediaSetEntry2));
    ::FUN_00597850((::FUN_00597850_Class *)&(m_kMediaSetEntry3));
    ::FUN_00597850((::FUN_00597850_Class *)&(m_kMediaSetEntry4));
    ::FUN_00597850((::FUN_00597850_Class *)&(m_kMediaSetEntry5));
    ::FUN_00597850((::FUN_00597850_Class *)&(m_kMediaSetEntry6));
    m_fMediaParameter1 = 0.0f;
    fSkillValueBonus = 0.0f;
    m_fMediaParameter3 = 0.0f;
    m_fMediaValue = 0.0f;
    m_pSound1 = 0;
    m_pSound2 = 0;
    DAT_011ca9fc = 0;
    m_uiMediaValue3 = 0;
    m_uiMediaValue2 = 0;
    bEffectFlag = false;
    m_bActorStateFlag = false;
    m_bConditionWasTrue = false;
    m_cMediaState = 0;
}


struct FUN_00597850_Class
{
    BSStringT<char> m_str;
    float m_f08;
    float m_f0c;
};

// Clears the string, then sets m_f08 to runtimeFloatSettingDefault313 and m_f0c to 100.0f.
// @fnv 0x00597850
void __fastcall FUN_00597850(FUN_00597850_Class* pThis)
{
    reinterpret_cast<::TextString *>(&(pThis->m_str))->FUN_004037f0(0, 0);
    pThis->m_f08 = runtimeFloatSettingDefault313;
    pThis->m_f0c = 100.0f;
}

// @fnv 0x007d9ec0
void __fastcall FUN_007d9ec0(BSStringT<char>* apString)
{
    apString->BSStringT<char>::~BSStringT<char>();
}

extern "C" void* __cdecl _alloca(unsigned int);

struct BSStringTChar
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    BSStringTChar(const char* apText);
    ~BSStringTChar();
    BSStringTChar& operator+=(const char* apText);
    bool Set(const BSStringTChar& arString);
};

struct TESFormLoadDataHelper
{
};

struct MediaSetLoad : public MediaSet
{
    bool FUN_00598bc0(TESFile* apFile);
};

// Reads a MediaSet record from the file, handling EDID, OBND, FULL, type, name, attenuation, percent, sound and float chunks, then returns true.
// @fnv 0x00598bc0
bool MediaSetLoad::FUN_00598bc0(TESFile* apFile)
{
    unsigned int itempint = 0;
    int chunkid;

    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(apFile));
    SetInitializationState(false);

    while ((chunkid = (int)((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0()))) != 0)
    {
        switch (chunkid)
        {
        case 'DIDE': {
            char* pMessage = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(pMessage), 0x200);
            SetEditorID_AtRuntime(pMessage);
            break;
        }
        case 'DNBO':
            readOBNDSubRecord(apFile);
            break;
        case 'LLUF':
            ::ReadFullName(this, apFile);
            break;
        case '1MAN':
            apFile->GetChunkData(&itempint);
            Type = (MEDIASETTYPE)itempint;
            break;
        case '2MAN':
        case '3MAN':
        case '4MAN':
        case '5MAN':
        case '6MAN':
        case '7MAN': {
            char* pMessage = 0;
            float tF = 0.0f;
            unsigned int cSize = reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C();
            if (cSize)
            {
                pMessage = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(pMessage), 0);
                BSStringTChar stemp("Data\\Music\\");
                stemp += pMessage;
                switch (chunkid)
                {
                case '2MAN':
                    ((BSStringTChar*)&m_kMediaSetEntry1.Name)->Set(stemp);
                    break;
                case '3MAN':
                    ((BSStringTChar*)&m_kMediaSetEntry2.Name)->Set(stemp);
                    break;
                case '4MAN':
                    ((BSStringTChar*)&m_kMediaSetEntry3.Name)->Set(stemp);
                    break;
                case '5MAN':
                    ((BSStringTChar*)&m_kMediaSetEntry4.Name)->Set(stemp);
                    break;
                case '6MAN':
                    ((BSStringTChar*)&m_kMediaSetEntry5.Name)->Set(stemp);
                    break;
                case '7MAN':
                    ((BSStringTChar*)&m_kMediaSetEntry6.Name)->Set(stemp);
                    break;
                }
            }
            break;
        }
        case '8MAN':
        case '9MAN':
        case '0MAN':
        case 'MANA':
        case 'MANB':
        case 'MANC': {
            float tF = 0.0f;
            apFile->GetChunkData((unsigned int*)&tF);
            switch (chunkid)
            {
            case '8MAN':
                m_kMediaSetEntry1.Attenuation = tF;
                break;
            case '9MAN':
                m_kMediaSetEntry2.Attenuation = tF;
                break;
            case '0MAN':
                m_kMediaSetEntry3.Attenuation = tF;
                break;
            case 'MANA':
                m_kMediaSetEntry4.Attenuation = tF;
                break;
            case 'MANB':
                m_kMediaSetEntry5.Attenuation = tF;
                break;
            case 'MANC':
                m_kMediaSetEntry6.Attenuation = tF;
                break;
            }
            break;
        }
        case 'MANJ':
        case 'MANK':
        case 'MANL':
        case 'MANM':
        case 'MANN':
        case 'MANO': {
            float tF = 0.0f;
            apFile->GetChunkData((unsigned int*)&tF);
            switch (chunkid)
            {
            case 'MANJ':
                m_kMediaSetEntry1.Percent = tF;
                break;
            case 'MANK':
                m_kMediaSetEntry2.Percent = tF;
                break;
            case 'MANL':
                m_kMediaSetEntry3.Percent = tF;
                break;
            case 'MANM':
                m_kMediaSetEntry4.Percent = tF;
                break;
            case 'MANN':
                m_kMediaSetEntry5.Percent = tF;
                break;
            case 'MANO':
                m_kMediaSetEntry6.Percent = tF;
                break;
            }
            break;
        }
        case 'MANP':
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>((((TESFormLoadDataHelper*)this)))->FUN_004861f0(apFile, &m_cMediaFlag, 1);
            break;
        case 'MAND':
        case 'MANE':
        case 'MANF':
        case 'MANG': {
            float tF = 0.0f;
            apFile->GetChunkData((unsigned int*)&tF);
            switch (chunkid)
            {
            case 'MAND':
                m_fMediaParameter1 = tF;
                break;
            case 'MANE':
                fSkillValueBonus = tF;
                break;
            case 'MANF':
                m_fMediaParameter3 = tF;
                break;
            case 'MANG':
                m_fMediaValue = tF;
                break;
            }
            break;
        }
        case 'MANH':
        case 'MANI': {
            unsigned int itempint = 0;
            apFile->GetChunkData(&itempint);
            switch (chunkid)
            {
            case 'MANH':
                m_pSound1 = (TESSound*)itempint;
                break;
            case 'MANI':
                m_pSound2 = (TESSound*)itempint;
                break;
            }
            break;
        }
        }
        if (!apFile->NextChunk())
            break;
    }
    return true;
}

struct FUN_00598000_shell
{
    int __thiscall FUN_00598000();
};
// Selects an incidental media layer for the controller based on scale and layer percentages, then starts or stops playback and updates cached state.
// @fnv 0x00597a60
bool MediaSet::UpdateLayerLocation(unsigned int time, bool force, MediaLocationController* controller)
{
    bool bReturn;
    bool bPlaying = ::FUN_00830750((*(unsigned long *)&(const ::MEDIATYPE &)(MEDIA_INCIDENTAL)), false);
    bReturn = true;
    char cLayer = 0;
    if (force)
    {
        return false;
    }
    else
    {
        bool a;  // Restart after the previous incidental reaches its fade window.
        unsigned int fMinPercent = ((unsigned int)(::FUN_00830970((*(int *)&(const ::MEDIATYPE &)(MEDIA_INCIDENTAL)))));
        a = false;
        if (m_uiMediaValue3 && fMinPercent && time > m_uiMediaValue3 + fMinPercent - m_fMediaParameter3 * 1000.0)
        {
            FalloutAudioMedia::FadeOutMedia(static_cast<int>(m_fMediaParameter3 * 1000.0), MEDIA_INCIDENTAL);
            m_uiMediaValue3 = time;
            if (!reinterpret_cast<::FUN_00598000_shell *>((controller))->FUN_00598000())
                a = true;
            else
                return false;
        }
        float fNormalizedPosition = reinterpret_cast<TESObjectREFR*>(controller)->GetScale() * 100.0;
        float m_uiPlaybackFlags = 1000.0f;  // Lowest eligible layer percentage.
        if (((bool)(reinterpret_cast<::FUN_00598020_Class *>((controller))->GetByteAtOffset55())))
        {
            if ((m_cMediaFlag & 1) && m_kMediaSetEntry1.Percent > fNormalizedPosition &&
                m_kMediaSetEntry1.Percent < m_uiPlaybackFlags)
            {
                cLayer = 1;
                m_uiPlaybackFlags =
                    m_kMediaSetEntry1.Percent > m_uiPlaybackFlags ? m_uiPlaybackFlags : m_kMediaSetEntry1.Percent;
            }
            if ((m_cMediaFlag & 2) && m_kMediaSetEntry2.Percent > fNormalizedPosition &&
                m_kMediaSetEntry2.Percent < m_uiPlaybackFlags)
            {
                cLayer = 2;
                m_uiPlaybackFlags =
                    m_kMediaSetEntry2.Percent > m_uiPlaybackFlags ? m_uiPlaybackFlags : m_kMediaSetEntry2.Percent;
            }
            if ((m_cMediaFlag & 4) && m_kMediaSetEntry3.Percent > fNormalizedPosition &&
                m_kMediaSetEntry3.Percent < m_uiPlaybackFlags)
            {
                cLayer = 3;
                m_uiPlaybackFlags =
                    m_kMediaSetEntry3.Percent > m_uiPlaybackFlags ? m_uiPlaybackFlags : m_kMediaSetEntry3.Percent;
            }
        }
        else
        {
            if ((m_cMediaFlag & 8) && m_kMediaSetEntry4.Percent > fNormalizedPosition &&
                m_kMediaSetEntry4.Percent < m_uiPlaybackFlags)
            {
                cLayer = 1;
                m_uiPlaybackFlags =
                    m_kMediaSetEntry4.Percent > m_uiPlaybackFlags ? m_uiPlaybackFlags : m_kMediaSetEntry4.Percent;
            }
            if ((m_cMediaFlag & 16) && m_kMediaSetEntry5.Percent > fNormalizedPosition &&
                m_kMediaSetEntry5.Percent < m_uiPlaybackFlags)
            {
                cLayer = 2;
                m_uiPlaybackFlags =
                    m_kMediaSetEntry5.Percent > m_uiPlaybackFlags ? m_uiPlaybackFlags : m_kMediaSetEntry5.Percent;
            }
            if ((m_cMediaFlag & 32) && m_kMediaSetEntry6.Percent > fNormalizedPosition &&
                m_kMediaSetEntry6.Percent < m_uiPlaybackFlags)
            {
                cLayer = 3;
                m_uiPlaybackFlags =
                    m_kMediaSetEntry6.Percent > m_uiPlaybackFlags ? m_uiPlaybackFlags : m_kMediaSetEntry6.Percent;
            }
        }
        if (!(bPlaying && m_bActorStateFlag == force && m_bConditionWasTrue == ((bool)(reinterpret_cast<::FUN_00598020_Class *>((controller))->GetByteAtOffset55())) &&
              m_cMediaState == cLayer) &&
                DAT_011dd37c < time ||
            a)
        {
            MediaSetEntry* pLayer = 0;
            if (((bool)(reinterpret_cast<::FUN_00598020_Class *>((controller))->GetByteAtOffset55())))
            {
                switch (cLayer)
                {
                case 1:
                    pLayer = &m_kMediaSetEntry1;
                    break;
                case 2:
                    pLayer = &m_kMediaSetEntry2;
                    break;
                case 3:
                    pLayer = &m_kMediaSetEntry3;
                }
            }
            else
            {
                switch (cLayer)
                {
                case 1:
                    pLayer = &m_kMediaSetEntry4;
                    break;
                case 2:
                    pLayer = &m_kMediaSetEntry5;
                    break;
                case 3:
                    pLayer = &m_kMediaSetEntry6;
                }
            }
            if (pLayer)
            {
                DAT_011dd37c = static_cast<unsigned int>(time + m_fMediaParameter1 * 1000.0);
                unsigned int uiElapsedMilliseconds = 0;
                if (((unsigned int)(::fnv_00830a20::FUN_00830a20((*(unsigned long *)&(const ::MEDIATYPE &)(MEDIA_INCIDENTAL))))) && !a)
                    uiElapsedMilliseconds = time - ((unsigned int)(::fnv_00830a20::FUN_00830a20((*(unsigned long *)&(const ::MEDIATYPE &)(MEDIA_INCIDENTAL)))));
                ::fnv_008300c0::PlayAudioMedia(
                    (*(int *)&(const ::MEDIATYPE &)(MEDIA_INCIDENTAL)),
                    reinterpret_cast<const char*>(reinterpret_cast<const NiPointer<NiNode>*>(pLayer)->operator->()),
                    static_cast<unsigned int>(m_fMediaParameter3 * 1000.0), !reinterpret_cast<::FUN_00598000_shell *>((controller))->FUN_00598000(), true,
                    pLayer->Attenuation, uiElapsedMilliseconds);
                FalloutAudioMedia::EndMediaUpdate();
                m_uiMediaValue3 = time;
            }
            else
            {
                if (bPlaying)
                    FalloutAudioMedia::FadeOutMedia(static_cast<int>(m_fMediaParameter3 * 1000.0), MEDIA_INCIDENTAL);
                bReturn = false;
            }
            m_bActorStateFlag = force;
            m_bConditionWasTrue = ((bool)(reinterpret_cast<::FUN_00598020_Class *>((controller))->GetByteAtOffset55()));
            m_cMediaState = cLayer;
        }
    }
    return bReturn;
}

// @fnv 0x00598000
int __thiscall FUN_00598000_shell::FUN_00598000()
{
    return (*(int*)((char*)this + 0x6c) >> 4) & 3;
}

struct FUN_00597880_shell
{
    void FUN_005978b0();
    void* FUN_00597880(unsigned int);
};
struct UnnamedStr
{
    int _00;
    int _04;
    void __thiscall AssignFromString(const UnnamedStr&);
};
struct FUN_00599780
{
    UnnamedStr _00;
    float _08;
    float _0c;
    FUN_00599780(const FUN_00599780&);
};
// Copy-constructs from that: copies the embedded UnnamedStr via AssignFromString and copies the two floats _08 and _0c.
// @fnv 0x00599780
FUN_00599780::FUN_00599780(const FUN_00599780& that)
{
    _00.AssignFromString(that._00);
    _08 = that._08;
    _0c = that._0c;
}

struct GO
{
    operator unsigned int() const;
};

struct S7010 : GO
{
};

struct DoorPart30
{
};

struct FUN_004855a0
{
};

struct FUN_00485680
{
};

struct FUN_00485e00_shell
{
    void FUN_00485e00();
};

struct FUN_005991b0_shell
{
    void FUN_005991b0();
};


// @fnv 0x005991b0
void FUN_005991b0_shell::FUN_005991b0()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<FUN_004855a0*>(this)))->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((reinterpret_cast<DoorPart30*>(reinterpret_cast<char*>(this) + 0x18)))->FUN_00487010();

    ::FUN_00485910(0x314d414e, *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x44));

    if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x48)))->FUN_004048e0())) > 0)
    {
        ::FUN_004856f0((void *)(0x324d414e),
                     reinterpret_cast<void*>(static_cast<unsigned int>(
                         *reinterpret_cast<GO*>(reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x48)))),
                     (void *)(((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x48)))->FUN_004048e0())) + 1));
    }

    if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x58)))->FUN_004048e0())) > 0)
    {
        ::FUN_004856f0((void *)(0x334d414e),
                     reinterpret_cast<void*>(static_cast<unsigned int>(
                         *reinterpret_cast<GO*>(reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x58)))),
                     (void *)(((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x58)))->FUN_004048e0())) + 1));
    }

    if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x68)))->FUN_004048e0())) > 0)
    {
        ::FUN_004856f0((void *)(0x344d414e),
                     reinterpret_cast<void*>(static_cast<unsigned int>(
                         *reinterpret_cast<GO*>(reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x68)))),
                     (void *)(((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x68)))->FUN_004048e0())) + 1));
    }

    if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x78)))->FUN_004048e0())) > 0)
    {
        ::FUN_004856f0((void *)(0x354d414e),
                     reinterpret_cast<void*>(static_cast<unsigned int>(
                         *reinterpret_cast<GO*>(reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x78)))),
                     (void *)(((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x78)))->FUN_004048e0())) + 1));
    }

    if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x88)))->FUN_004048e0())) > 0)
    {
        ::FUN_004856f0((void *)(0x364d414e),
                     reinterpret_cast<void*>(static_cast<unsigned int>(
                         *reinterpret_cast<GO*>(reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x88)))),
                     (void *)(((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x88)))->FUN_004048e0())) + 1));
    }

    if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x98)))->FUN_004048e0())) > 0)
    {
        ::FUN_004856f0((void *)(0x374d414e),
                     reinterpret_cast<void*>(static_cast<unsigned int>(
                         *reinterpret_cast<GO*>(reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x98)))),
                     (void *)(((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x98)))->FUN_004048e0())) + 1));
    }

    ::FUN_00485910(0x384d414e, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x50));
    ::FUN_00485910(0x394d414e, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x60));
    ::FUN_00485910(0x304d414e, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x70));
    ::FUN_00485910(0x4d414e41, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x80));
    ::FUN_00485910(0x4d414e42, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x90));
    ::FUN_00485910(0x4d414e43, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xa0));
    ::FUN_00485910(0x4d414e4a, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x54));
    ::FUN_00485910(0x4d414e4b, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x64));
    ::FUN_00485910(0x4d414e4c, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x74));
    ::FUN_00485910(0x4d414e4d, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x84));
    ::FUN_00485910(0x4d414e4e, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x94));
    ::FUN_00485910(0x4d414e4f, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xa4));

    FUN_004858f0(0x4d414e50, *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0xa8));

    ::FUN_00485910(0x4d414e44, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xac));
    ::FUN_00485910(0x4d414e45, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xb0));
    ::FUN_00485910(0x4d414e46, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xb4));
    ::FUN_00485910(0x4d414e47, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xb8));

    if (*reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0xbc))
    {
        ::FUN_00485910(0x4d414e48,
                      ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESSound*>(*reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0xbc))))->FUN_0084e3a0())));
    }

    if (*reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0xc0))
    {
        ::FUN_00485910(0x4d414e49,
                      ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESSound*>(*reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0xc0))))->FUN_0084e3a0())));
    }

    reinterpret_cast<FUN_00485e00_shell*>(this)->FUN_00485e00();
    reinterpret_cast<::Holder *>((reinterpret_cast<FUN_00485680*>(this)))->FUN_00485680();
}

struct S_5978b0_Form
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    virtual ~S_5978b0_Form();
};

struct FUN_005978b0 : public S_5978b0_Form, public TESFullName
{
    unsigned int m_uiMediaValue1;
    unsigned int m_uiMediaValue2;
    unsigned int m_uiMediaValue3;
    bool bEffectFlag;
    bool m_bActorStateFlag;
    bool m_bCountWasNonzero;
    bool m_bConditionWasTrue;
    char m_cMediaState;
    TESFullName m_kFullName;
    int Type;
    MediaSet::MediaSetEntry m_kMediaSetEntry1;
    MediaSet::MediaSetEntry m_kMediaSetEntry2;
    MediaSet::MediaSetEntry m_kMediaSetEntry3;
    MediaSet::MediaSetEntry m_kMediaSetEntry4;
    MediaSet::MediaSetEntry m_kMediaSetEntry5;
    MediaSet::MediaSetEntry m_kMediaSetEntry6;
    ~FUN_005978b0();
};
// Calls FUN_005978b0, then deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x00597880
void* FUN_00597880_shell::FUN_00597880(unsigned int flags)
{
    reinterpret_cast<::FUN_005978b0 *>((this))->FUN_005978b0::~FUN_005978b0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x005978b0
FUN_005978b0::~FUN_005978b0()
{}

class Sky
{
  public:
};

class TES
{
  public:
};

struct SoundPlaybackHandle
{
    unsigned int uiSoundID;
    unsigned int unk04;
    unsigned int unk08;
    ~SoundPlaybackHandle();
};

class BSAudio
{
  public:
    SoundPlaybackHandle GetSoundHandleByFormID(unsigned int auiFormID, unsigned int auiFlags, unsigned int auiUnk);
};


struct MediaSetBattle : public MediaSet
{
    bool UpdateBattleMusic(unsigned int auiTime);
};

// @fnv 0x00598890
bool MediaSetBattle::UpdateBattleMusic(unsigned int auiTime)
{
    if (auiTime <= DAT_011ca9fc)
    {
        return true;
    }
    Sky* pWeatherSky = ((::Sky *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->GetBaseTexture()));
    bool m_bConditionWasTrue = pWeatherSky ? (::FUN_00595ea0((char *)(pWeatherSky)) <= ::GetFieldEC((const char *)(pWeatherSky)) &&
                                              ::GetFieldEC((const char *)(pWeatherSky)) <= reinterpret_cast<::FUN_00596030_cls *>((pWeatherSky))->FUN_00596030())
                                           : true;
    if (m_bConditionWasTrue)
    {
        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::SoundPlaybackHandle &)(::FUN_00453a70()->GetSoundHandleByFormID(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pSound1))->FUN_0084e3a0())), 0x901, 0)))->FUN_00ad8830({});
        DAT_011ca9fc =
            GetRandomNumberInRange((int)(m_fMediaParameter1 * 1000.0), (int)(m_fMediaParameter3 * 1000.0)) + auiTime;
    }
    else
    {
        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::SoundPlaybackHandle &)(::FUN_00453a70()->GetSoundHandleByFormID(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pSound2))->FUN_0084e3a0())), 0x901, 0)))->FUN_00ad8830({});
        DAT_011ca9fc =
            GetRandomNumberInRange((int)(fSkillValueBonus * 1000.0), (int)(m_fMediaValue * 1000.0)) + auiTime;
    }
    return true;
}

struct MediaLayerData
{
    BSStringT<char> Name;
    float Attenuation;
    float Percent;
    MediaLayerData(const MediaLayerData& arOther);
    ~MediaLayerData();
};

struct MediaSetBaseCopy
{
};

struct MediaSetCopy : public MediaSet
{
    void FUN_00599550(TESForm* apForm);
};

struct TextValue
{
    char* text;
    unsigned short length;
    unsigned short capacity;
    ~TextValue();
};
struct StringRecord
{
    TextValue name;
    float first;
    float second;
    void SetValues(TextValue value, float firstValue, float secondValue);
};
// Copies Type, six layer entries and several scalar fields from another MediaSet, then calls CopyBase.
// @fnv 0x00599550
void MediaSetCopy::FUN_00599550(TESForm* apForm)
{
    MediaSet* pOther = dynamic_cast<MediaSet*>(apForm);
    if (!pOther)
        return;
    Type = pOther->Type;
    reinterpret_cast<::StringRecord *>((((MediaLayerData*)&m_kMediaSetEntry1)))->SetValues((*(::TextValue *)&(const ::MediaLayerData &)(*(MediaLayerData*)&pOther->m_kMediaSetEntry1)), {}, {});
    reinterpret_cast<::StringRecord *>((((MediaLayerData*)&m_kMediaSetEntry2)))->SetValues((*(::TextValue *)&(const ::MediaLayerData &)(*(MediaLayerData*)&pOther->m_kMediaSetEntry2)), {}, {});
    reinterpret_cast<::StringRecord *>((((MediaLayerData*)&m_kMediaSetEntry3)))->SetValues((*(::TextValue *)&(const ::MediaLayerData &)(*(MediaLayerData*)&pOther->m_kMediaSetEntry3)), {}, {});
    reinterpret_cast<::StringRecord *>((((MediaLayerData*)&m_kMediaSetEntry4)))->SetValues((*(::TextValue *)&(const ::MediaLayerData &)(*(MediaLayerData*)&pOther->m_kMediaSetEntry4)), {}, {});
    reinterpret_cast<::StringRecord *>((((MediaLayerData*)&m_kMediaSetEntry5)))->SetValues((*(::TextValue *)&(const ::MediaLayerData &)(*(MediaLayerData*)&pOther->m_kMediaSetEntry5)), {}, {});
    reinterpret_cast<::StringRecord *>((((MediaLayerData*)&m_kMediaSetEntry6)))->SetValues((*(::TextValue *)&(const ::MediaLayerData &)(*(MediaLayerData*)&pOther->m_kMediaSetEntry6)), {}, {});
    m_cMediaFlag = pOther->m_cMediaFlag;
    m_fMediaParameter1 = pOther->m_fMediaParameter1;
    fSkillValueBonus = pOther->fSkillValueBonus;
    m_fMediaParameter3 = pOther->m_fMediaParameter3;
    m_fMediaValue = pOther->m_fMediaValue;
    m_pSound1 = pOther->m_pSound1;
    m_pSound2 = pOther->m_pSound2;
    reinterpret_cast<::FormCloneOperation *>((((MediaSetBaseCopy*)this)))->FUN_004851b0(pOther);
}
// @fnv 0x00599700
void StringRecord::SetValues(TextValue aTextValue, float afFirst, float afSecond)
{
    reinterpret_cast<::TextString *>(this)->FUN_004037f0((const char *)(::TextValue *)(((::TextValue *)(::FUN_00559450((int *)&(aTextValue))))), {});
    first = afFirst;
    second = afSecond;
}

struct LayerInfo
{
    BSStringT<char> Name;
    float Attenuation;
    float Percent;

    bool __thiscall FUN_00599a50(LayerInfo other);
};
// @fnv 0x00599a50
bool LayerInfo::FUN_00599a50(LayerInfo other)
{
    if (Attenuation != other.Attenuation)
        return true;
    if (Percent != other.Percent)
        return true;
    if (reinterpret_cast<::B408A80String *>(this)->FUN_00408a80(((const char *)(::FUN_00559450((int *)&(other)))), {}))
        return false;
    return true;
}

struct FUN_00483630_holder
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    virtual ~FUN_00483630_holder();
};

struct FUN_00599d00 : public FUN_00483630_holder, public TESFullName
{
    virtual ~FUN_00599d00();
};

// Destructor for a TESFullName-derived holder object; the body is empty.
// @fnv 0x00599d00
FUN_00599d00::~FUN_00599d00()
{}

struct Ctrl598060
{
};
struct SoundForm598060
{
};
struct BSSoundHandleEx
{
    int v0;
    int v1;
    int v2;
    BSSoundHandleEx();
    ~BSSoundHandleEx();
};
struct BSAudio598060
{
    BSSoundHandleEx FUN_00ad73b0(int, int);
};
extern unsigned int DAT_011ca9fc;

struct This598060
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int m_2c;
    unsigned char m_30;
    unsigned char m_31;
    unsigned char m_32;
    unsigned char unk33;
    char m_34;
    unsigned char unk35;
    unsigned char unk36;
    unsigned char unk37;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    FUN_00597850_Class m_48;
    FUN_00597850_Class m_58;
    FUN_00597850_Class m_68;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    float m_ac;
    int unkb0;
    float m_b4;
    int unkb8;
    SoundForm598060* m_bc;
    SoundForm598060* m_c0;
    bool UpdateSoundState(unsigned int, bool, Ctrl598060*);
};
// @fnv 0x00597990
bool MediaSet::Update(unsigned int time, bool force, MediaLocationController* controller)
{
    if (controller)
    {
        switch (Type)
        {
        case LAYER_LOCATION:
            return UpdateLayerLocation(time, force, controller);
            break;
        case LAYER_DUNGEON:
            return reinterpret_cast<::This598060 *>(this)->UpdateSoundState(time, force, (::Ctrl598060 *)(controller));
            break;
        case BATTLE:
            return UpdateBattleState(force, time, 4);
        }
    }
    else if (!controller && Type == INCIDENTAL)
    {
        if (DAT_011ca9fc > time)
            return true;
        reinterpret_cast<::MediaSetBattle *>(this)->UpdateBattleMusic(time);
    }
    else if (!controller && Type == BATTLE)
    {
        return UpdateBattleState(force, time, 4);
    }
    return false;
}

// @fnv 0x00598060
bool This598060::UpdateSoundState(unsigned int auiTime, bool abEnabled, Ctrl598060* apCtrl)
{
    bool flagDTmp;
    bool retVal;
    unsigned int local7;
    bool b2;
    bool b4;
    FUN_00597850_Class* ptrLocal;
    int local4;
    b2 = FUN_00830750(3, true);
    retVal = true;
    b4 = reinterpret_cast<::TESObjectREFR *>((apCtrl))->GetScale() < 100.0;
    if (this->m_31 == 0 && abEnabled)
    {
        DAT_011dd37c = 0;
    }
    local7 = FUN_008308c0(2);
    flagDTmp = false;
    if (this->m_2c != 0 && local7 != 0)
    {
        if ((double)auiTime > (double)(unsigned int)(this->m_2c + local7) - this->m_b4 * 1000.0)
        {
            ::FalloutAudioMedia::FadeOutMedia((int)(this->m_b4 * 1000.0), (::MEDIATYPE)(2));
            this->m_2c = auiTime;
            if (reinterpret_cast<::FUN_00598000_shell *>((apCtrl))->FUN_00598000() == 0)
            {
                flagDTmp = true;
            }
            else
            {
                return false;
            }
        }
    }
    if (!((b2 && this->m_31 == abEnabled && this->m_32 == reinterpret_cast<::Tile *>((apCtrl))->GetSpeechChallengeFailure() &&
           ((char)this->m_34 == (char)b4 || (char)this->m_34 != 0)) ||
          DAT_011dd37c >= auiTime) ||
        flagDTmp)
    {
    body:
        ptrLocal = 0;
        if (abEnabled)
        {
            if (this->m_bc != 0 && !this->m_30)
            {
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(((::BSAudio598060 *)(::FUN_00453a70()))->FUN_00ad73b0((int)((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this->m_bc))->FUN_0084e3a0())), 0x901)))->FUN_00ad8830(false);
            }
            ptrLocal = &this->m_48;
            this->m_30 = 1;
        }
        else if (reinterpret_cast<::Tile *>((apCtrl))->GetSpeechChallengeFailure())
        {
            if (this->m_30 && this->m_c0 != 0)
            {
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(((::BSAudio598060 *)(::FUN_00453a70()))->FUN_00ad73b0((int)((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this->m_c0))->FUN_0084e3a0())), 0x901)))->FUN_00ad8830(false);
            }
            ptrLocal = &this->m_68;
            this->m_30 = 0;
        }
        else
        {
            if (this->m_30 && this->m_c0 != 0)
            {
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(((::BSAudio598060 *)(::FUN_00453a70()))->FUN_00ad73b0((int)((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this->m_c0))->FUN_0084e3a0())), 0x901)))->FUN_00ad8830(false);
            }
            ptrLocal = &this->m_58;
            this->m_30 = 0;
        }
        if (ptrLocal != 0)
        {
            DAT_011dd37c = auiTime;
            if (!abEnabled)
            {
                DAT_011dd37c = (unsigned int)(this->m_ac * 1000.0 + (double)DAT_011dd37c);
            }
            local4 = 0;
            if (((unsigned int)(::fnv_00830a20::FUN_00830a20((*(unsigned long *)&(const ::MEDIATYPE &)((MEDIATYPE)3))))) != 0 && !flagDTmp)
            {
                local4 = auiTime - ((unsigned int)(::fnv_00830a20::FUN_00830a20((*(unsigned long *)&(const ::MEDIATYPE &)((MEDIATYPE)3)))));
            }
            if (ptrLocal == &this->m_48)
            {
                ::fnv_008300c0::PlayAudioMedia(3, ((const char *)(::FUN_00559450((int *)&(ptrLocal->m_str)))), 1000, true, true, ptrLocal->m_f08, (unsigned int)local4);
            }
            else
            {
                ::fnv_008300c0::PlayAudioMedia(3, ((const char *)(::FUN_00559450((int *)&(ptrLocal->m_str)))), (unsigned int)(this->m_b4 * 1000.0), true, true,
                               ptrLocal->m_f08, (unsigned int)local4);
            }
            ::FalloutAudioMedia::EndMediaUpdate();
        }
        else
        {
            ::FalloutAudioMedia::FadeOutMedia((int)(this->m_b4 * 1000.0), (::MEDIATYPE)(3));
            retVal = false;
        }
        this->m_31 = abEnabled;
        this->m_32 = reinterpret_cast<::Tile *>((apCtrl))->GetSpeechChallengeFailure();
        this->m_34 = b4;
    }
    else
    {
        if ((char)b4 == 0)
        {
            if (auiTime > DAT_011ca9fc)
            {
                if (this->m_30 == 0)
                {
                    if (b2)
                    {
                        ::FalloutAudioMedia::FadeOutMedia((int)(this->m_b4 * 1000.0), (::MEDIATYPE)(3));
                    }
                    retVal = false;
                }
            }
        }
    }
    return retVal;
}

namespace fnv_00598550 {
struct BSSoundHandleEx
{
    unsigned int uiSoundID;
    unsigned int uiState;
    unsigned int uiFlags;
    ~BSSoundHandleEx();
};
struct DungeonAudio
{
    BSSoundHandleEx FUN_00ad73b0(unsigned int, unsigned int, unsigned int);
};
struct DungeonController
{
};
struct DungeonMediaSet : MediaSet
{
    bool UpdatePlayback(bool active, unsigned int time, int mediaType);
};
// Starts, refreshes or fades the media set's audio based on active, time and mediaType, updating DAT_011ca9fc and the playing flag.
// @fnv 0x00598550
bool DungeonMediaSet::UpdatePlayback(bool active, unsigned int time, int mediaType)
{
    bool changed;
    if (active)
    {
        changed = false;
        bool playing = ::FUN_00830750(mediaType, false);
        if (!playing && !bEffectFlag)
        {
            if (m_pSound1 && !bEffectFlag)
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_00598550::BSSoundHandleEx &)(((DungeonAudio*)::FUN_00453a70())->FUN_00ad73b0(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pSound1))->FUN_0084e3a0())), 0x901, 0)))->FUN_00ad8830({});
            DAT_011ca9fc = time - 1;
            bEffectFlag = true;
            ::fnv_008300c0::PlayAudioMedia((*(int *)&(const ::MEDIATYPE &)((MEDIATYPE)mediaType)), ((const char *)(::FUN_00559450((int *)&(m_kMediaSetEntry1.Name)))),
                                         (unsigned int)(fSkillValueBonus * 1000.0), true, true,
                                         m_kMediaSetEntry1.Attenuation, 0);
            FalloutAudioMedia::EndMediaUpdate();
            ::FUN_008305e0();
        }
        if (time > DAT_011ca9fc + m_fMediaParameter1)
        {
            ::ResetThreadFlags();
            bEffectFlag = true;
        }
        unsigned int length = ::FUN_008308c0(mediaType);
        if (length && time > DAT_011ca9fc + length - 1000)
        {
            ::fnv_008300c0::PlayAudioMedia((*(int *)&(const ::MEDIATYPE &)((MEDIATYPE)mediaType)), ((const char *)(::FUN_00559450((int *)&(m_kMediaSetEntry1.Name)))),
                                         (unsigned int)(fSkillValueBonus * 1000.0), true, true,
                                         m_kMediaSetEntry1.Attenuation, 0);
            FalloutAudioMedia::EndMediaUpdate();
            DAT_011ca9fc = time;
        }
    }
    else
    {
        bool fading = false;
        if (::FUN_00830750(mediaType, false) && bEffectFlag)
        {
            fading = true;
            ::FalloutAudioMedia::FadeOutMedia((int)(fSkillValueBonus * 1000.0), (::MEDIATYPE)(mediaType));
        }
        if (fading)
        {
            if (m_pSound2)
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_00598550::BSSoundHandleEx &)(((DungeonAudio*)::FUN_00453a70())->FUN_00ad73b0(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pSound2))->FUN_0084e3a0())), 0x901, 0)))->FUN_00ad8830({});
            DAT_011ca9fc = time + m_fMediaParameter3 * 1000.0;
            if ((*reinterpret_cast<::fnv_00598550::DungeonController * *>(&::DAT_011dd374)))
                reinterpret_cast<::TESRecipe *>(((*reinterpret_cast<::fnv_00598550::DungeonController * *>(&::DAT_011dd374))))->SetRequiredSkill((::ActorValue::Index)(DAT_011ca9fc));
            bEffectFlag = false;
        }
    }
    return active;
}
}  // namespace fnv_00598550

struct MediaLayerCompare
{
};
struct MediaFormCompare
{
};
struct MediaSetCompare : MediaSet
{
    bool IsDifferentFrom(TESForm* form);
};

// Compares this MediaSet with form cast to MediaSet: returns true if any layer, scalar field or base comparison differs.
// @fnv 0x005997c0
bool MediaSetCompare::IsDifferentFrom(TESForm* form)
{
    MediaSet* other = dynamic_cast<MediaSet*>(form);
    if (!other)
        return true;
    if (other->Type != Type)
        return true;
    if (reinterpret_cast<::LayerInfo *>((reinterpret_cast<MediaLayerCompare*>(&m_kMediaSetEntry1)))->FUN_00599a50((*(::LayerInfo *)&(const ::MediaLayerData &)(*reinterpret_cast<MediaLayerData*>(&other->m_kMediaSetEntry1)))))
        return true;
    if (reinterpret_cast<::LayerInfo *>((reinterpret_cast<MediaLayerCompare*>(&m_kMediaSetEntry2)))->FUN_00599a50((*(::LayerInfo *)&(const ::MediaLayerData &)(*reinterpret_cast<MediaLayerData*>(&other->m_kMediaSetEntry2)))))
        return true;
    if (reinterpret_cast<::LayerInfo *>((reinterpret_cast<MediaLayerCompare*>(&m_kMediaSetEntry3)))->FUN_00599a50((*(::LayerInfo *)&(const ::MediaLayerData &)(*reinterpret_cast<MediaLayerData*>(&other->m_kMediaSetEntry3)))))
        return true;
    if (reinterpret_cast<::LayerInfo *>((reinterpret_cast<MediaLayerCompare*>(&m_kMediaSetEntry4)))->FUN_00599a50((*(::LayerInfo *)&(const ::MediaLayerData &)(*reinterpret_cast<MediaLayerData*>(&other->m_kMediaSetEntry4)))))
        return true;
    if (reinterpret_cast<::LayerInfo *>((reinterpret_cast<MediaLayerCompare*>(&m_kMediaSetEntry5)))->FUN_00599a50((*(::LayerInfo *)&(const ::MediaLayerData &)(*reinterpret_cast<MediaLayerData*>(&other->m_kMediaSetEntry5)))))
        return true;
    if (reinterpret_cast<::LayerInfo *>((reinterpret_cast<MediaLayerCompare*>(&m_kMediaSetEntry6)))->FUN_00599a50((*(::LayerInfo *)&(const ::MediaLayerData &)(*reinterpret_cast<MediaLayerData*>(&other->m_kMediaSetEntry6)))))
        return true;
    if (m_cMediaFlag != other->m_cMediaFlag)
        return true;
    if (m_fMediaParameter1 != other->m_fMediaParameter1)
        return true;
    if (fSkillValueBonus != other->fSkillValueBonus)
        return true;
    if (m_fMediaParameter3 != other->m_fMediaParameter3)
        return true;
    if (m_fMediaValue != other->m_fMediaValue)
        return true;
    if (m_pSound1 != other->m_pSound1)
        return true;
    if (m_pSound2 != other->m_pSound2)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((reinterpret_cast<MediaFormCompare*>(this)))->FUN_00485270(other))
        return true;
    return false;
}
