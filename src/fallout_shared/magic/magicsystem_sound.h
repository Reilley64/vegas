#include "AutoMemContext.h"
// Unit-local PC header for fallout_shared/tessound.cpp.
// TESSound below is the PC layout inferred from codegen:
//   +0x00..0x2F first base (TESBoundAnimObject, 48 bytes)
//   +0x30..0x3B second base (TESSoundFile: vtable + BSString, 12 bytes)
//   +0x3C..0x43 filename BSString member (8 bytes)
//   +0x68 m_cSoundFlag
#ifndef FNV_MAGICSYSTEM_SOUND_H
#define FNV_MAGICSYSTEM_SOUND_H

#include "fnv/decl/Data5E35.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "layout_support.h"
#include "TESForm.h"
// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESSOUND_SOUND_DATA_H
#define FNV_TESSOUND_SOUND_DATA_H
class TESSound__SOUND_DATA;
class TESSound__SOUND_DATA
{
  public:
    unsigned char iMin;                       // +0x0, 1 bytes
    unsigned char iMax;                       // +0x1, 1 bytes
    char m_cPitchAdjustment;                  // +0x2, 1 bytes
    unsigned char m_ucUnused;                 // +0x3, 1 bytes
    unsigned int iFlags;                      // +0x4, 4 bytes
    unsigned short m_uiFrequency;             // +0x8, 2 bytes
    unsigned short m_aucAttenuationBytes;     // +0xA, 2 bytes
    unsigned short m_auiAttenuationCurve[5];  // +0xC, 10 bytes
    unsigned short m_uiReverbAttenuation;     // +0x16, 2 bytes
    unsigned int iPriority;                   // +0x18, 4 bytes
    unsigned int m_uiTrailingValue1;          // +0x1C, 4 bytes
    unsigned int m_uiTrailingValue2;          // +0x20, 4 bytes
public:
    void SwapEndian();
};
#endif
// Unit-local copy of the 12-byte legacy SNDX sound header (first fields of
// it, then copies the fields into data.
class TESSound__SOUND_DATA2
{
  public:
    unsigned char iMin;                    // +0x0
    unsigned char iMax;                    // +0x1
    char m_cPitchAdjustment;               // +0x2
    unsigned char m_ucUnused;              // +0x3
    unsigned int iFlags;                   // +0x4
    unsigned short m_uiFrequency;          // +0x8
    unsigned short m_aucAttenuationBytes;  // +0xA
};
// Unit-local scaffolding for the TESSound bases. TESBoundAnimObject derives
// from TESForm through TESObject/TESBoundObject on PC; the intermediate
// members live in the padding below. Only sizes, polymorphism and the
// constructor matter for this unit's codegen.
// ReadTypedData is the canonical TESForm::ReadTypedData(TESFile*, void*, unsigned short)
// chunk reader; it is declared on the scaffold base because the task closure
// TESForm.h does not declare it.
class TESBoundAnimObject : public TESForm
{
  public:
    virtual ~TESBoundAnimObject();
    unsigned char layoutPadding18[0x18];
    TESBoundAnimObject();
};
// TESSoundFile is vtable + sound-path string (12 bytes); its constructor
// builds the string, matching the observed subobject construction.
// SetSoundFile is the real filename virtual called by the FNAM chunk handler
// through the second vtable (slot 4, first new virtual after the four
// BaseFormComponent slots).
class TESSoundFile : public BaseFormComponent
{
  public:
    virtual void SetSoundFile(const char* fileName);
    virtual ~TESSoundFile();
    BSStringT<char> m_kSoundFile;  // +0x4
    TESSoundFile();
};
class TESSound : public TESBoundAnimObject, public TESSoundFile
{
  public:
    BSStringT<char> cFileName;  // +0x3C, second filename string
    TESSound__SOUND_DATA data;  // +0x44, 36 bytes
    char m_cSoundFlag;          // +0x68, 1 byte
    unsigned char layoutPadding69[3];
    TESSound();
    void ResetFormData();
    static void InitializeMagicSystem();
    bool Load(TESFile* file);
};
// Canonical AutoMemContext declaration (decomp/include/AutoMemContext.h),
// repeated here because the task include closure does not bundle it.
using ::AutoMemContext;
#endif
