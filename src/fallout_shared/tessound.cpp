// fallout_shared/tessound.cpp: TESSound (4 functions)

#include "fnv/decl/Data5E35.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "tessound.h"
#include <malloc.h>

const char kTESSoundFileLabel[] = "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESSound.cpp";

// Source line of the default-objects context in the original PC file (0x559).
enum
{
    kGenerateDefaultObjectsSourceLine = 0x559
};

// @fnv 0x005e2ef0
void TESSound::ResetFormData()
{
    data.iFlags = 0;
    data.iMax = 0;
    data.iMin = 0;
    data.m_cPitchAdjustment = 0;
    data.m_uiFrequency = 0;
    data.m_ucUnused = 0;
    data.m_aucAttenuationBytes = 0;
    data.m_auiAttenuationCurve[0] = 100;
    data.m_auiAttenuationCurve[1] = 50;
    data.m_auiAttenuationCurve[2] = 20;
    data.m_auiAttenuationCurve[3] = 5;
    data.m_auiAttenuationCurve[4] = 0;
    data.m_uiReverbAttenuation = 80;
    data.m_uiTrailingValue1 = 0;
    data.m_uiTrailingValue2 = 0;
    data.iPriority = 128;
}

// @fnv 0x005e3600
void TESSound::InitializeMagicSystem()
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TES_DEFAULT_OBJECTS, true, kTESSoundFileLabel,
                           kGenerateDefaultObjectsSourceLine);
}

// @fnv 0x005e2b70
TESSound::TESSound()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(ENUM_FORM_ID_SOUN_ID)));
    m_cSoundFlag = 0;
    ResetFormData();
}

// Loads a SOUN record: reads the header, then handles EDID, OBND, FNAM, RNAM, SNDD, SNDX, ANAM, GNAM and HNAM chunks, converting endianness where required.
// @fnv 0x005e3160
bool TESSound::Load(TESFile* file)
{
    if (reinterpret_cast<::FUN_00472660_shell *>((static_cast<TESFileFormInt*>(file)))->FUN_00472660() != ENUM_FORM_ID_SOUN_ID)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    int iChunkID;
    while ((iChunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (iChunkID)
        {
        case 0x44494445:  // EDID
        {
            char* pChunkBuffer = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pChunkBuffer), 0x200);
            SetEditorID_AtRuntime(pChunkBuffer);
            break;
        }
        case 0x444E424F:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x4D414E46:  // FNAM
        {
            char* pChunkBuffer = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pChunkBuffer), 0);
            SetSoundFile(pChunkBuffer);
            break;
        }
        case 0x4D414E52:  // RNAM
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(file, &m_cSoundFlag, sizeof(m_cSoundFlag));
            break;
        case 0x44444E53:  // SNDD
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(file, &data, sizeof(data));
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::TESSound__SOUND_DATA *>(&(data))->SwapEndian();
            break;
        case 0x58444E53:  // SNDX
        {
            TESSound__SOUND_DATA2 oldSoundData;
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(file, &oldSoundData, sizeof(oldSoundData));
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::Data5E35 *>(&(oldSoundData))->FUN_005e3510();
            data.iMin = oldSoundData.iMin;
            data.iMax = oldSoundData.iMax;
            data.m_cPitchAdjustment = oldSoundData.m_cPitchAdjustment;
            data.iFlags = oldSoundData.iFlags;
            data.m_uiFrequency = oldSoundData.m_uiFrequency;
            data.m_aucAttenuationBytes = oldSoundData.m_aucAttenuationBytes;
            break;
        }
        case 0x4D414E41:  // ANAM
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(file, data.m_auiAttenuationCurve, sizeof(data.m_auiAttenuationCurve));
            if (file->IsEndianConversionRequired())
            {
                ::FUN_00407a90((short *)(unsigned short *)(&data.m_auiAttenuationCurve[0]));
                ::FUN_00407a90((short *)(unsigned short *)(&data.m_auiAttenuationCurve[1]));
                ::FUN_00407a90((short *)(unsigned short *)(&data.m_auiAttenuationCurve[2]));
                ::FUN_00407a90((short *)(unsigned short *)(&data.m_auiAttenuationCurve[3]));
                ::FUN_00407a90((short *)(unsigned short *)(&data.m_auiAttenuationCurve[4]));
            }
            if (data.m_auiAttenuationCurve[0] == 100 && data.m_auiAttenuationCurve[1] == 75 &&
                data.m_auiAttenuationCurve[2] == 50 && data.m_auiAttenuationCurve[3] == 25 &&
                data.m_auiAttenuationCurve[4] == 0)
            {
                data.m_auiAttenuationCurve[0] = 100;
                data.m_auiAttenuationCurve[1] = 50;
                data.m_auiAttenuationCurve[2] = 20;
                data.m_auiAttenuationCurve[3] = 5;
                data.m_auiAttenuationCurve[4] = 0;
            }
            break;
        case 0x4D414E47:  // GNAM
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(file, &data.m_uiReverbAttenuation, sizeof(data.m_uiReverbAttenuation));
            break;
        case 0x4D414E48:  // HNAM
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(file, &data.iPriority, sizeof(data.iPriority));
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}
