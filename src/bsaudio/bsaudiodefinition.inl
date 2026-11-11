// The bodies of BSAudioDefinition and BSSoundInfo, the classes declared in
// include/fnv/bs_audio_definition.h. bsaudiodefines_h_unit.cpp owns the five
// addresses and is the one unit of the game library that includes this file.
// The host test of the definition compiles it too.

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
