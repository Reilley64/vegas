
// Fallout: New Vegas - original source reconstruction.
// Compiled translation unit for the bsaudiodefines.h header unit.
//
// The original build compiled bsaudio/bsaudiodefines.h inside an audio
// translation unit. This translation unit plays that role for the matcher
// build: it includes the header unit and references the covered functions
// so the compiler emits their bodies the same way the original
// translation unit did.
//
// Compiler: MSVC9 SP1 15.00.30729.01, flags /Od /Oy- /GS /EHsc /Gy
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045cee0_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/SndStack70.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00c45000.h"
#include "bsaudiodefines.h"

// @fnv 0x00ae8770
BSAudioDefinition::BSAudioDefinition()
{
    Name[0] = 0;
    FileName[0] = 0;
    pName = Name;
    pFileName = FileName;
    fFirstValue = 0.0f;
    fSecondValue = 0.0f;
    Location = NiPoint3::ZERO;
    uiSoundFlags = 0;
    m_fMinimumDistance = 0.0f;
    m_fMaximumDistance = 0.0f;
    m_uiSoundParameterA = 0;
    m_uiSoundParameterB = 0;
    m_uiSoundParameter6 = 0;
}

// @fnv 0x00ae8830
BSAudioDefinition::~BSAudioDefinition()
{
    pName = 0;
    pFileName = 0;
    fFirstValue = 0.0f;
    fSecondValue = 0.0f;
    uiSoundFlags = 0;
    m_fMinimumDistance = 0.0f;
    m_fMaximumDistance = 0.0f;
    m_uiSoundParameterA = 0;
    m_uiSoundParameterB = 0;
    m_uiSoundParameter6 = 0;
}

// @fnv 0x00ae88c0
BSAudioDefinition& BSAudioDefinition::operator=(const BSAudioDefinition& aCopy)
{
    Name[0] = 0;
    FileName[0] = 0;
    if (aCopy.pName)
    {
        char* pSrcName = aCopy.pName;
        char* pDstName = pName;
        strcpy(pDstName, pSrcName);
    }
    if (aCopy.pFileName)
    {
        char* pDstFile = aCopy.pFileName;
        char* pSrcFile = pFileName;
        strcpy(pSrcFile, pDstFile);
    }
    fFirstValue = aCopy.fFirstValue;
    fSecondValue = aCopy.fSecondValue;
    Location = aCopy.Location;
    uiSoundFlags = aCopy.uiSoundFlags;
    m_fMinimumDistance = aCopy.m_fMinimumDistance;
    m_fMaximumDistance = aCopy.m_fMaximumDistance;
    m_uiSoundParameterA = aCopy.m_uiSoundParameterA;
    m_uiSoundParameterB = aCopy.m_uiSoundParameterB;
    m_uiSoundParameter6 = aCopy.m_uiSoundParameter6;
    return *this;
}

// @fnv 0x00ae8a40
BSSoundInfo::BSSoundInfo(BSSoundInfo* aCopy)
{
    m_uiSoundID = aCopy->m_uiSoundID;
    m_fSoundVolume = aCopy->m_fSoundVolume;
    m_fFadeDuration = aCopy->m_fFadeDuration;
    m_uiValueAt0C = aCopy->m_uiValueAt0C;
    m_uiPlaybackFlags = aCopy->m_uiPlaybackFlags;
    m_bValueAt14 = aCopy->m_bValueAt14;
    m_kAudioDefinition = aCopy->m_kAudioDefinition;
}

// @fnv 0x00ae8af0
BSSoundInfo::~BSSoundInfo()
{
    m_uiSoundID = 0;
    m_fSoundVolume = 0.0f;
    m_fFadeDuration = 0.0f;
    m_uiValueAt0C = 0;
    m_uiPlaybackFlags = 0;
    m_bValueAt14 = false;
}

typedef NiTPointerListBase<NiTPointerAllocator<unsigned int>, SoundMessageRecord*> BSSoundMessageList;

void BSAudioDefinesEmitCoveredFunctions()
{
    // Qualified calls: keep the inline bodies in this object file.
    BSAudioDefinition kDebug;
    kDebug = kDebug;
    BSSoundInfo* pInfo = 0;
    BSSoundInfo kCopy(pInfo);
    pInfo->~BSSoundInfo();
    BSSoundMessageList* pList = 0;
    reinterpret_cast<::SndStack70 *>((pList))->FUN_00ae7f90();
}

#include "generated/data/bsaudio/bsaudiodefines_h_unit.inc"
