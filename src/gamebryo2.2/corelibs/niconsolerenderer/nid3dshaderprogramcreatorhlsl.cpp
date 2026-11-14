
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <new>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/DBBCBC0Target.h"
#include "fnv/decl/FUN_00e58780_Class.h"
#include "fnv/decl/FUN_00e587b0_Class.h"
#include "fnv/decl/FUN_00e587c0_Class.h"
#include "fnv/decl/FUN_00e58a20_cls.h"
#include "fnv/decl/FUN_00e58b10_class.h"
#include "fnv/decl/FUN_00e897d0.h"
#include "fnv/decl/FUN_00e96c90_Class.h"
#include "fnv/decl/S.h"
#include "fnv/decl/S_00e89970.h"
#include "fnv/decl/Stand_e58d90.h"
#include "fnv/symbols_00aa0000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00e58000.h"
#include "fnv/symbols_00e93000.h"
#include "fnv/symbols_00e98000.h"
#include "fnv/symbols_00ee6000.h"
#include "fnv/symbols_010f1000.h"
#include "fnv/symbols_0126f000.h"
#include "fnv/symbols_00c85000.h"
class NiD3DPixelShader
{
  public:
    void* DestroyPixelShader(unsigned int flags);
};


// @fnv 0x00be0af0
void* NiD3DPixelShader::DestroyPixelShader(unsigned int flags)
{
    NiD3DPixelShader* p = this;
    static_cast<::S_00e89970 *>(nullptr)->FUN_00e89970();
    if (flags & 1)
        ::FUN_00aa1460(p, 0x30);
    return p;
}

struct COMUnknownInterface;

struct NiD3DVertexShader
{
    void FUN_00be0bd0(COMUnknownInterface* hDecl);
};

// @fnv 0x00be0bd0
void NiD3DVertexShader::FUN_00be0bd0(COMUnknownInterface* hDecl)
{
    *(COMUnknownInterface**)((char*)this + 0x38) = hDecl;
}

namespace fnv_00be0bf0 {
struct NiD3DVertexShader
{
    void FUN_00be0bf0(bool bSoftwareVP);
};

// @fnv 0x00be0bf0
void NiD3DVertexShader::FUN_00be0bf0(bool bSoftwareVP)
{
    *(bool*)((char*)this + 0x2c) = bSoftwareVP;
}
}  // namespace fnv_00be0bf0

struct VTableObj
{
    int m_uiX;
    int m_uiY;
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void Call(int a, int b);
};


struct FUN_00c7b0f0_shell
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    void FUN_00c7b0f0();
};

// @fnv 0x00c7b0f0
void FUN_00c7b0f0_shell::FUN_00c7b0f0()
{
    void* p = reinterpret_cast<void* (*)()>(&::FUN_00c85750)();
    VTableObj* pTarget = *(VTableObj**)((char*)p + 0x10);
    m_kPointB = 0;
    unsigned int uiFlags = m_iThirdValue;
    if (!(uiFlags & 0x80000000))
    {
        int size = (uiFlags & 0x3fffffff) * 4;
        pTarget->Call(m_kPointA, size);
    }
    m_kPointA = 0;
    m_iThirdValue = 0x80000000;
}


// @fnv 0x00e95cc0
void* __cdecl FUN_00e95cc0()
{
    return &(*reinterpret_cast<void * *>(&::g_0126fa40));
}


// @fnv 0x00e95df0
const void* __cdecl FUN_00e95df0()
{
    return &(*reinterpret_cast<const void * *>(&::g_0126fa48));
}

extern void(__cdecl* DAT_fdf3f0)();

// @fnv 0x00ee6e2e
void __cdecl FUN_00ee6e2e()
{
    return DAT_fdf3f0();
}

struct NiD3DShaderProgramCreator;
struct NiD3DShaderProgram
{
    void FUN_00eea540(NiD3DShaderProgramCreator* pkCreator);
};

// @fnv 0x00eea540
void NiD3DShaderProgram::FUN_00eea540(NiD3DShaderProgramCreator* pkCreator)
{
    *reinterpret_cast<uintptr_t*>(this + 0x1c) = reinterpret_cast<uintptr_t>(pkCreator);
}


struct FUN_00be0b70_shell
{
    void* FUN_00be0b70(unsigned int flags);
};

// Calls FUN_00e89b70, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00be0b70
void* FUN_00be0b70_shell::FUN_00be0b70(unsigned int flags)
{
    static_cast<::S *>(nullptr)->FUN_00e89b70();
    if (flags & 1)
        operator delete(this, 0x3c);
    return this;
}


struct NiD3DHLSLPixelShader : NiD3DPixelShader
{
    void* FUN_00e95cd0(unsigned int flags);
};

// Calls FUN_00e96c90, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00e95cd0
void* NiD3DHLSLPixelShader::FUN_00e95cd0(unsigned int flags)
{
    reinterpret_cast<::FUN_00e96c90_Class *>(this)->FUN_00e96c90();
    if (flags & 1)
        operator delete(this, 0x3c);
    return this;
}

namespace fnv_00be0ab0 {
struct NiD3DShaderProgram
{
    char _pad[0x14];
    unsigned int m_uiProgramCodeSize;
    void* m_pProgramCode;
    void SetShaderCode(unsigned int uiSize, void* pvCode);
};

// @fnv 0x00be0ab0
void NiD3DShaderProgram::SetShaderCode(unsigned int uiSize, void* pvCode)
{
    m_uiProgramCodeSize = uiSize;
    m_pProgramCode = pvCode;
}
}  // namespace fnv_00be0ab0

int __cdecl strcpy_s(char*, unsigned int, const char*);
struct FUN_00e95cf0_Holder
{
    void FUN_00e95cf0(const char* pcEntryPoint);
};
// Frees the stored string at offset 0x30 and replaces it with a newly allocated copy of pcEntryPoint, or null if empty.
// @fnv 0x00e95cf0
void FUN_00e95cf0_Holder::FUN_00e95cf0(const char* pcEntryPoint)
{
    char* pcNewEntryPoint;
    unsigned int uiLen;
    if (*(char**)((char*)this + 0x30) != pcEntryPoint)
    {
        ::FUN_00aa10f0(*(char**)((char*)this + 0x30));
        if (pcEntryPoint && pcEntryPoint[0] != 0)
        {
            uiLen = strlen(pcEntryPoint) + 1;
            pcNewEntryPoint = (char*)::FUN_00aa1070(uiLen);
            strcpy_s(pcNewEntryPoint, uiLen, pcEntryPoint);
            *(char**)((char*)this + 0x30) = pcNewEntryPoint;
        }
        else
        {
            *(char**)((char*)this + 0x30) = 0;
        }
    }
}

struct FUN_00e95d60_shell
{
    void FUN_00e95d60(const char* pcShaderTarget);
};
// Frees the stored shader target string and replaces it with a newly allocated copy of pcShaderTarget, unless it is null, empty, or already stored.
// @fnv 0x00e95d60
void FUN_00e95d60_shell::FUN_00e95d60(const char* pcShaderTarget)
{
    char* pcNewShaderTarget;
    unsigned int uiLen;
    if (*(const char**)((char*)this + 0x34) == pcShaderTarget)
        return;
    ::FUN_00aa10f0(*(void**)((char*)this + 0x34));
    if (!pcShaderTarget)
        return;
    if (*pcShaderTarget == 0)
        return;
    uiLen = (unsigned int)strlen(pcShaderTarget) + 1;
    pcNewShaderTarget = (char*)::FUN_00aa1070(uiLen);
    strcpy_s(pcNewShaderTarget, uiLen, pcShaderTarget);
    *(char**)((char*)this + 0x34) = pcNewShaderTarget;
}

struct ID3DXConstantTable
{
    virtual void QueryInterface();
    virtual void AddRef();
    virtual void Release();
};
struct HlslPixelShaderStandIn
{
    char _pad[0x38];
    ID3DXConstantTable* m_pShaderConstantTable;
    void AssignTable(ID3DXConstantTable* pkTable);
};
// Releases the current table and stores pkTable, calling AddRef on it when it differs from the stored one.
// @fnv 0x00e95dc0
void HlslPixelShaderStandIn::AssignTable(ID3DXConstantTable* pkTable)
{
    if (m_pShaderConstantTable != pkTable)
    {
        if (m_pShaderConstantTable)
            m_pShaderConstantTable->Release();
        m_pShaderConstantTable = pkTable;
        if (pkTable)
            pkTable->AddRef();
    }
}

struct NiD3DHLSLVertexShader
{
    void* DestroyVertexShader(unsigned int);
};
// @fnv 0x00e95e00
void* NiD3DHLSLVertexShader::DestroyVertexShader(unsigned int flags)
{
    reinterpret_cast<::S *>(this)->FUN_00e971d0();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x48);
    return this;
}

namespace fnv_00e95e20 {
struct NiD3DHLSLVertexShader
{
    char _pad[0x3c];
    char* m_pcShaderEntryPoint;
    void FUN_00e95e20(const char* pcEntryPoint);
};
// Replaces the stored entry-point string with a copy of pcEntryPoint, freeing the old one and clearing it when the input is null or empty.
// @fnv 0x00e95e20
void NiD3DHLSLVertexShader::FUN_00e95e20(const char* pcEntryPoint)
{
    char* pcNewEntryPoint;
    unsigned int uiLen;
    if (m_pcShaderEntryPoint != pcEntryPoint)
    {
        ::FUN_00aa10f0(m_pcShaderEntryPoint);
        if (pcEntryPoint && *pcEntryPoint)
        {
            uiLen = strlen(pcEntryPoint);
            pcNewEntryPoint = (char*)::FUN_00aa1070(uiLen + 1);
            fnv::crt::strcpy_s(pcNewEntryPoint, uiLen + 1, pcEntryPoint);
            m_pcShaderEntryPoint = pcNewEntryPoint;
        }
        else
        {
            m_pcShaderEntryPoint = 0;
        }
    }
}
}  // namespace fnv_00e95e20

namespace fnv_00e95e80 {
struct NiD3DHLSLVertexShader
{
    char _pad[0x40];
    char* m_pcShaderProfile;
    void FUN_00e95e80(const char* pcShaderTarget);
};
// Frees the stored shader target string and, if a non-empty target is given, allocates and copies it into the field.
// @fnv 0x00e95e80
void NiD3DHLSLVertexShader::FUN_00e95e80(const char* pcShaderTarget)
{
    if (m_pcShaderProfile != pcShaderTarget)
    {
        ::FUN_00aa10f0(m_pcShaderProfile);
        if (pcShaderTarget && pcShaderTarget[0] != 0)
        {
            char* pcNewShaderTarget;
            unsigned int uiLen;
            uiLen = strlen(pcShaderTarget) + 1;
            pcNewShaderTarget = (char*)::FUN_00aa1070(uiLen);
            fnv::crt::strcpy_s(pcNewShaderTarget, uiLen, pcShaderTarget);
            m_pcShaderProfile = pcNewShaderTarget;
        }
    }
}
}  // namespace fnv_00e95e80

namespace fnv_00e95ef0 {
struct ID3DXConstantTable
{
    virtual int QueryInterface();
    virtual int AddRef();
    virtual int Release();
};
struct NiD3DHLSLVertexShader : NiD3DVertexShader
{
    void SetShaderTable(ID3DXConstantTable* pkTable);
};
// Replaces the COM-style table pointer at offset 0x44, releasing the old one and AddRef-ing the new one when it differs.
// @fnv 0x00e95ef0
void NiD3DHLSLVertexShader::SetShaderTable(ID3DXConstantTable* pkTable)
{
    ID3DXConstantTable* pkOld = *(ID3DXConstantTable**)((char*)this + 0x44);
    if (pkOld != pkTable)
    {
        if (pkOld)
            pkOld->Release();
        *(ID3DXConstantTable**)((char*)this + 0x44) = pkTable;
        if (pkTable)
            pkTable->AddRef();
    }
}
}  // namespace fnv_00e95ef0

struct ID3DXBuffer
{
    virtual long QueryInterface(const void* riid, void** ppv);
    virtual unsigned long AddRef();
    virtual unsigned long Release();
    virtual void* GetBufferPointer();
    virtual unsigned long GetBufferSize();
};
extern "C" long D3DXCompileShader(const char* pSrcData, unsigned int SrcDataLen, const void* pDefines,
                                            void* pInclude, const char* pFunctionName, const char* pProfile,
                                            unsigned long Flags, ID3DXBuffer** ppShader, ID3DXBuffer** ppErrorMsgs,
                                            ID3DXConstantTable** ppConstantTable);
int __cdecl strcpy_s(char*, unsigned int, char*);
inline void NiMemcpy(void* pvDest, const void* pvSrc, unsigned int ItemUpdateArray)
{
    std::memmove(pvDest, pvSrc, ItemUpdateArray);
}

struct NiD3DShaderProgramCreatorHLSL
{
    void* m_vtbl;
    unsigned int m_uiCompileFlags;
    bool CompileShaderFromMemory(const void* pvBuffer, unsigned int uiBufferSize, const char* pcEntryPoint,
                                 const char* pcShaderTarget, void*& pvCode, unsigned int& uiCodeSize,
                                 ID3DXConstantTable*& pkConstantTable, bool bRecoverable);
};

// Compiles HLSL from a memory buffer via D3DXCompileShader, copies the resulting code into pvCode/uiCodeSize, and logs errors on failure.
// @fnv 0x00e964a0
bool NiD3DShaderProgramCreatorHLSL::CompileShaderFromMemory(const void* apSourceData, unsigned int auiSourceSize,
                                                            const char* pcEntryPoint, const char* pcShaderTarget,
                                                            void*& pvCode, unsigned int& uiCodeSize,
                                                            ID3DXConstantTable*& pkConstantTable, bool bRecoverable)
{
    pvCode = 0;
    uiCodeSize = 0;
    if (apSourceData == 0 || auiSourceSize == 0)
    {
        ::FUN_00aa0020(1, bRecoverable, "Invalid shader buffer\n");
        return false;
    }

    ID3DXBuffer* pkErrors;
    ID3DXBuffer* pkCode;
    long m_kResult = D3DXCompileShader((const char*)apSourceData, auiSourceSize, 0, 0, pcEntryPoint, pcShaderTarget,
                                       m_uiCompileFlags | DAT_0126fa24, &pkCode, &pkErrors, &pkConstantTable);
    if (m_kResult < 0)
    {
        char* pcErrorText = 0;
        if (pkErrors)
        {
            void* pvErrorData = pkErrors->GetBufferPointer();
            if (pvErrorData)
            {
                unsigned int uiLen = pkErrors->GetBufferSize();
                pcErrorText = (char*)::FUN_00aa1070(uiLen);
                strcpy_s(pcErrorText, uiLen, (char*)pvErrorData);
                ::FUN_00aa0020(1, bRecoverable, "Failed to assemble shader %s from memory\nError: %s\n", pcEntryPoint,
                             pcErrorText);
            }
            pkErrors->Release();
        }
        else
        {
            ::FUN_00aa0020(1, bRecoverable, "Failed to assemble shader %s from memory\nError: NONE REPORTED\n",
                         pcEntryPoint);
        }
        ::FUN_00aa10f0(pcErrorText);
        if (pkCode)
            pkCode->Release();
        return false;
    }

    uiCodeSize = pkCode->GetBufferSize();
    pvCode = ::FUN_00aa1070(uiCodeSize);
    NiMemcpy(pvCode, pkCode->GetBufferPointer(), uiCodeSize);
    pkCode->Release();
    if (pkErrors)
        pkErrors->Release();
    return true;
}

struct FUN_00be09e0_shell
{
    char m_auiShapeKeys[0x10];
    char* m_pkShaderProgramName;
    void FUN_00be09e0(const char* pszName);
};

extern const char $SG3295[];

// @fnv 0x00be09e0
void FUN_00be09e0_shell::FUN_00be09e0(const char* pszName)
{
    if (!pszName || strcmp(pszName, $SG3295) == 0)
    {
        ::FUN_00aa10f0(m_pkShaderProgramName);
        m_pkShaderProgramName = 0;
        return;
    }

    unsigned int uiNewLen = strlen(pszName) + 1;

    if (m_pkShaderProgramName)
    {
        unsigned int uiOldLen = strlen(m_pkShaderProgramName);
        if (uiOldLen < uiNewLen)
        {
            ::FUN_00aa10f0(m_pkShaderProgramName);
            m_pkShaderProgramName = 0;
        }
    }

    if (!m_pkShaderProgramName)
    {
        m_pkShaderProgramName = (char*)::FUN_00aa1070(uiNewLen);
    }

    fnv::crt::strcpy_s(m_pkShaderProgramName, uiNewLen, pszName);
}


struct FUN_00be0920_shell
{
    void* m_vtbl;
    unsigned int m_uiValue1;
    unsigned int m_uiType;
    char* m_pcName;
    void FUN_00be0920(const char* pszName);
};

// Stores a copy of pszName in m_pcName, reallocating the buffer when the new name is longer, or frees it when the name is empty.
// @fnv 0x00be0920
void FUN_00be0920_shell::FUN_00be0920(const char* pszName)
{
    if (!pszName || strcmp(pszName, "") == 0)
    {
        ::FUN_00aa10f0(m_pcName);
        m_pcName = 0;
    }
    else
    {
        unsigned int uiNewLen = strlen(pszName) + 1;

        if (m_pcName)
        {
            if (strlen(m_pcName) < uiNewLen)
            {
                ::FUN_00aa10f0(m_pcName);
                m_pcName = 0;
            }
        }

        if (!m_pcName)
            m_pcName = static_cast<char*>(::FUN_00aa1070(uiNewLen));

        fnv::crt::strcpy_s(m_pcName, uiNewLen, pszName);
    }
}

struct FUN_00be0ba0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    unsigned int unk30;

    void FUN_00be0ba0(unsigned int value);
};

// @fnv 0x00be0ba0
void FUN_00be0ba0_Class::FUN_00be0ba0(unsigned int value)
{
    unk30 = value;
}

struct S_00e58ea0_Gen
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void InitFloatArray(int a, int b, float c);
};

struct S_00e58ea0_Arr
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void InitFloatArray(int a, int b, float c);
};

struct S_00e58ea0_cls
{
    int unk00;
    S_00e58ea0_Gen* FUN_00e58ea0(S_00e58ea0_Gen* a1, S_00e58ea0_Gen* a2);
};

struct IUnk_e95
{
    virtual long QueryInterface();
    virtual unsigned long AddRef();
    virtual unsigned long Release();
};

struct Shader_e95
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void* GetCode();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void SetShader(void* p);
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void SetShaderInterface(IUnk_e95* p);
};

long FUN_00ee6e40(void* pvCode, IUnk_e95** ppTable);

struct FUN_00e95c40_cls
{
    bool AttachShaderFromCode(Shader_e95* pkShader);
};

// @fnv 0x00e95c40
bool FUN_00e95c40_cls::AttachShaderFromCode(Shader_e95* pkShader)
{
    void* pvCode = pkShader->GetCode();
    if (!pvCode)
        return false;
    void* pvShader = ((void *)(::FUN_00e988d0((void *)(pvCode))));
    if (!pvShader)
        return false;
    pkShader->SetShader(pvShader);
    IUnk_e95* pkTable;
    if (FUN_00ee6e40(pvCode, &pkTable) >= 0)
        pkShader->SetShaderInterface(pkTable);
    if (pkTable)
        pkTable->Release();
    return true;
}


struct NiD3DRenderer;
extern "C" const char* D3DXGetPixelShaderProfile(void* pDevice);

class HLSLCreator;

class NiD3DShaderProgramBase
{
  public:
    NiD3DShaderProgramBase(NiD3DRenderer* pkRenderer, int iType) throw();
    virtual void DeleteThis(bool b);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
};

class NiD3DPixelShaderStandIn : public NiD3DShaderProgramBase
{
  public:
    NiD3DPixelShaderStandIn(NiD3DRenderer* pkRenderer) throw() : NiD3DShaderProgramBase(pkRenderer, 0)
    {
        m_bIsInitialized = false;
        m_uiPassCount = 0;
        m_uiProgramCodeSize = 0;
        m_pProgramCode = 0;
    }
    bool m_bIsInitialized;
    unsigned int m_uiPassCount;
    unsigned int m_uiProgramCodeSize;
    void* m_pProgramCode;
};

class NiD3DHLSLPixelShaderStandIn : public NiD3DPixelShaderStandIn
{
  public:
    NiD3DHLSLPixelShaderStandIn(NiD3DRenderer* pkRenderer) throw() : NiD3DPixelShaderStandIn(pkRenderer)
    {
        m_pcShaderEntryPoint = 0;
        m_pcShaderProfile = 0;
        m_pShaderConstantTable = 0;
    }
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void SetName(const char* pcName);
    virtual void v22();
    virtual void SetShaderProgramFile(const char* pcFile);
    virtual void v24();
    virtual void v25();
    virtual void SetProgramCode(unsigned int uiSize, void* pvCode);
    virtual void v27();
    virtual void SetCreator(HLSLCreator* pkCreator);
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void SetPassCount(unsigned int ItemUpdateArray);
    virtual void v33();
    virtual void SetD3DPixelShader(void* hShader);
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void SetSoftwareVertexProcessing(unsigned int b);
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void SetEntryPoint(const char* pcEntryPoint);
    virtual void v43();
    virtual void SetPixelShaderTarget(const char* pcShaderTarget);
    virtual void v45();
    virtual void SetShaderInterface(ID3DXConstantTable* pkTable);
    const char* m_pcShaderEntryPoint;
    const char* m_pcShaderProfile;
    ID3DXConstantTable* m_pShaderConstantTable;
};

class HLSLCreator : public NiD3DShaderProgramCreatorHLSL
{
  public:
    NiD3DHLSLPixelShaderStandIn* FUN_00e967d0(const void* pvBuffer, unsigned int uiBufferSize, const char* pcShaderName,
                                              const char* pcEntryPoint, const char* pcShaderTarget, void* pvHandle,
                                              uintptr_t auiGroupKey, unsigned int bSoftwareVP, bool bRecoverable);
};

// Compiles the shader source, creates the pixel shader handle, fills a new NiD3DHLSLPixelShaderStandIn with it and returns it, or returns 0 on failure.
// @fnv 0x00e967d0
NiD3DHLSLPixelShaderStandIn* HLSLCreator::FUN_00e967d0(const void* pvBuffer, unsigned int uiBufferSize,
                                                       const char* pcShaderName, const char* pcEntryPoint,
                                                       const char* pcShaderTarget, void* pvHandle,
                                                       uintptr_t auiGroupKey, unsigned int bSoftwareVP,
                                                       bool bRecoverable)
{
    NiD3DHLSLPixelShaderStandIn* pkShader = new NiD3DHLSLPixelShaderStandIn((*reinterpret_cast<::NiD3DRenderer * *>(&::DAT_0126fa2c)));
    if (!pkShader)
        return 0;

    unsigned int uiCodeSize = 0;
    void* pvCode = 0;
    ID3DXConstantTable* pkConstantTable = 0;

    if (pcEntryPoint == 0)
        pcEntryPoint = "main";
    if (pcShaderTarget == 0)
        pcShaderTarget = D3DXGetPixelShaderProfile(::g_0126fa28);

    if (!CompileShaderFromMemory(pvBuffer, uiBufferSize, pcEntryPoint, pcShaderTarget, pvCode, uiCodeSize,
                                 pkConstantTable, bRecoverable))
    {
        pkShader->DeleteThis(true);
        return 0;
    }

    void* hShader = ::CreateVertexShaderChecked(pvCode, (void *)(&pvHandle), auiGroupKey, 0, 0, bSoftwareVP);
    if (hShader == 0)
    {
        ::FUN_00aa0020(1, bRecoverable, "Failed CreateVertexShader call on %s\n", pcShaderName);
        pkShader->DeleteThis(true);
        return 0;
    }

    pkShader->SetName(pcShaderName);
    pkShader->SetShaderProgramFile(0);
    pkShader->SetProgramCode(uiCodeSize, pvCode);
    pkShader->SetCreator(this);
    pkShader->SetD3DPixelShader(hShader);
    pkShader->SetPassCount(auiGroupKey);
    pkShader->SetSoftwareVertexProcessing(bSoftwareVP);
    pkShader->SetEntryPoint(pcEntryPoint);
    pkShader->SetPixelShaderTarget(pcShaderTarget);
    pkShader->SetShaderInterface(pkConstantTable);

    if (pkConstantTable)
        pkConstantTable->Release();

    return pkShader;
}

struct MatResult
{
    bool m_ok;
    MatResult()
    {}
};

struct MatrixNm
{
    float* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int m_numRows;
    int m_numCols;

    MatrixNm(int numRows, int numCols);
    void Release();
    int GetNumRows() const;
    int GetNumCols() const;
};


// Solves each column of x against b by copying it into single-column matrices, calling SolveVector, and writing the result back.
// @fnv 0x00e590f0
MatResult __cdecl SolveMatrixColumns(void* solver, MatrixNm& x, MatrixNm& b, intptr_t maxIter, float tolerance)
{
    MatResult result;
    MatrixNm xColumn(x.GetNumRows(), 1);
    MatrixNm bColumn(b.GetNumRows(), 1);
    for (int col = 0; col < x.GetNumCols(); col++)
    {
        int row;
        for (row = 0; row < x.GetNumRows(); row++)
        {
            *((float *)(reinterpret_cast<::FUN_00e587b0_Class *>(&(xColumn))->FUN_00e587b0(row))) = *((float *)(reinterpret_cast<::FUN_00e58780_Class *>(&(x))->GetElementPtr(row, col)));
            float fValue = reinterpret_cast<::FUN_00e587c0_Class *>(&(b))->GetFloatAt(row, col);
            *((float *)(reinterpret_cast<::FUN_00e587b0_Class *>(&(bColumn))->FUN_00e587b0(row))) = fValue;
        }
        if (!(*(::MatResult *)(::ConjugateGradientSolve((bool *)(solver), (::SolverMatrix *)&(xColumn), (::SolverVector *)&(bColumn), (::SolverVector *)(maxIter), tolerance, {}))).m_ok)
        {
            result.m_ok = false;
            reinterpret_cast<::FUN_00c7b0f0_shell *>(&(bColumn))->FUN_00c7b0f0();
            reinterpret_cast<::FUN_00c7b0f0_shell *>(&(xColumn))->FUN_00c7b0f0();
            return result;
        }
        for (row = 0; row < x.GetNumRows(); row++)
        {
            *((float *)(reinterpret_cast<::FUN_00e58780_Class *>(&(x))->GetElementPtr(row, col))) = *((float *)(reinterpret_cast<::FUN_00e587b0_Class *>(&(xColumn))->FUN_00e587b0(row)));
        }
    }
    result.m_ok = true;
    reinterpret_cast<::FUN_00c7b0f0_shell *>(&(bColumn))->FUN_00c7b0f0();
    reinterpret_cast<::FUN_00c7b0f0_shell *>(&(xColumn))->FUN_00c7b0f0();
    return result;
}

extern "C" long D3DXCompileShaderFromFileA(const char* pSrcFile, const void* pDefines, void* pInclude,
                                                     const char* pFunctionName, const char* pProfile,
                                                     unsigned long Flags, ID3DXBuffer** ppShader,
                                                     ID3DXBuffer** ppErrorMsgs, ID3DXConstantTable** ppConstantTable);

struct HLSLFileCreator : NiD3DShaderProgramCreatorHLSL
{
    bool CompileShaderFromFile(const char* pcFileName, const char* pcEntryPoint, const char* pcShaderTarget,
                               void*& pvCode, unsigned int& uiCodeSize, ID3DXConstantTable*& pkConstantTable,
                               bool bRecoverable);
};

// Finds the shader file, compiles it with D3DXCompileShaderFromFileA, copies the compiled code into pvCode and reports errors on failure.
// @fnv 0x00e962a0
bool HLSLFileCreator::CompileShaderFromFile(const char* pcFileName, const char* pcEntryPoint,
                                            const char* pcShaderTarget, void*& pvCode, unsigned int& uiCodeSize,
                                            ID3DXConstantTable*& pkConstantTable, bool bRecoverable)
{
    pvCode = 0;
    uiCodeSize = 0;

    if (!pcFileName || pcFileName[0] == '\0')
    {
        ::FUN_00aa0020(1, bRecoverable, "Invalid shader file name\n");
        return false;
    }

    char acPath[260];
    if (!::FindShaderProgramFile(pcFileName, acPath, 260))
    {
        ::FUN_00aa0020(1, bRecoverable, "Failed to find shader program file %s\n", pcFileName);
        return false;
    }

    ID3DXBuffer* pkErrors;
    ID3DXBuffer* pkShader;
    long hr = D3DXCompileShaderFromFileA(acPath, 0, 0, pcEntryPoint, pcShaderTarget, m_uiCompileFlags | DAT_0126fa24,
                                         &pkShader, &pkErrors, &pkConstantTable);
    if (hr < 0)
    {
        char* pcError = 0;
        if (pkErrors)
        {
            void* pvError = pkErrors->GetBufferPointer();
            if (pvError)
            {
                unsigned int uiLen = pkErrors->GetBufferSize();
                pcError = (char*)::FUN_00aa1070(uiLen);
                strcpy_s(pcError, uiLen, (char*)pvError);
                ::FUN_00aa0020(1, bRecoverable, "Failed to compile shader %s in file %s\nError: %s\n", pcEntryPoint,
                             pcFileName, pcError);
            }
            pkErrors->Release();
        }
        else
        {
            ::FUN_00aa0020(1, bRecoverable, "Failed to compile shader %s in file %s\nError: NONE REPORTED\n",
                         pcEntryPoint, pcFileName);
        }
        ::FUN_00aa10f0(pcError);
        if (pkShader)
            pkShader->Release();
        return false;
    }

    uiCodeSize = pkShader->GetBufferSize();
    pvCode = ::FUN_00aa1070(uiCodeSize);
    NiMemcpy(pvCode, pkShader->GetBufferPointer(), uiCodeSize);
    pkShader->Release();
    if (pkErrors)
        pkErrors->Release();
    return true;
}

struct FnvCpu_FUN_00be0aa0_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    int value;
    int FUN_00be0aa0();
};
// @fnv 0x00be0aa0
int FnvCpu_FUN_00be0aa0_CpuObject::FUN_00be0aa0()
{
    return value;
}

// 0x00be0be0  mov al,[ecx+0x2c]; ret
struct C00be0be0
{
    char pad00[0x2c];
    unsigned char m2c;
    unsigned char FUN_00be0be0();
};

// @fnv 0x00be0be0
unsigned char C00be0be0::FUN_00be0be0()
{
    return m2c;
}

struct FnvCpu_FUN_00e09630_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    int value;
    int FUN_00e09630();
};
// @fnv 0x00e09630
int FnvCpu_FUN_00e09630_CpuObject::FUN_00e09630()
{
    return value;
}

struct FUN_00e587a0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;

    int FUN_00e587a0();
};

// @fnv 0x00e587a0
int FUN_00e587a0_Class::FUN_00e587a0()
{
    return this->unk10;
}

struct FUN_00e95d50_StandIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    unsigned int unk34;

    unsigned int FUN_00e95d50();
};

// @fnv 0x00e95d50
unsigned int FUN_00e95d50_StandIn::FUN_00e95d50()
{
    return unk34;
}

struct FnvCpu_FUN_00e95ee0_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    int value;
    int FUN_00e95ee0();
};
// @fnv 0x00e95ee0
int FnvCpu_FUN_00e95ee0_CpuObject::FUN_00e95ee0()
{
    return value;
}


struct HLSLCreator_b10814
{
    int unk00;
    NiD3DHLSLPixelShaderStandIn* FUN_00e95f20(void* pvBuffer, unsigned int uiCodeSize, const char* pcShaderName,
                                              const char* pcEntryPoint, const char* pcShaderTarget, const char* pcName,
                                              uintptr_t auiGroupKey, unsigned int bSoftwareVP, bool bRecoverable);
};

// @fnv 0x00e95f20
NiD3DHLSLPixelShaderStandIn* HLSLCreator_b10814::FUN_00e95f20(void* pvBuffer, unsigned int uiCodeSize,
                                                              const char* pcShaderName, const char* pcEntryPoint,
                                                              const char* pcShaderTarget, const char* pcName,
                                                              uintptr_t auiPassCount, unsigned int bSoftwareVP,
                                                              bool bRecoverable)
{
    NiD3DHLSLPixelShaderStandIn* pkShader = new NiD3DHLSLPixelShaderStandIn((NiD3DRenderer*)::DAT_0126fa2c);
    if (pkShader == 0)
    {
        return 0;
    }

    ID3DXConstantTable* pkConstantTable = 0;
    if (FUN_00ee6e40(((ID3DXBuffer*)pvBuffer)->GetBufferPointer(), (IUnk_e95**)&pkConstantTable) < 0)
    {
        return 0;
    }

    if (pcEntryPoint == 0)
    {
        pcEntryPoint = "main";
    }
    if (pcShaderTarget == 0)
    {
        pcShaderTarget = reinterpret_cast<const char*(*)(void*)>(&FUN_00ee6e2e)(g_0126fa28);
    }

    void* pvHandle = ::CreateVertexShaderChecked(((ID3DXBuffer*)pvBuffer)->GetBufferPointer(), (void*)&pcName,
                                                     auiPassCount, 0, 0, bSoftwareVP);
    if (pvHandle == 0)
    {
        ::FUN_00aa0020(1, bRecoverable, "Failed CreateVertexShader call on %s\n", pcShaderName);
        pkShader->DeleteThis(true);
        return 0;
    }

    void* pvCode = FUN_00aa1070(uiCodeSize);
    unsigned int uiSize = ((ID3DXBuffer*)pvBuffer)->GetBufferSize();
    void* pBytecodeData = ((ID3DXBuffer*)pvBuffer)->GetBufferPointer();
    std::memmove(pvCode, pBytecodeData, uiSize);

    pkShader->SetName(pcShaderName);
    pkShader->SetShaderProgramFile(0);
    pkShader->SetProgramCode(uiCodeSize, pvCode);
    pkShader->SetCreator((HLSLCreator*)this);
    pkShader->SetD3DPixelShader(pvHandle);
    pkShader->SetPassCount(auiPassCount);
    pkShader->SetSoftwareVertexProcessing(bSoftwareVP);
    pkShader->SetEntryPoint(pcEntryPoint);
    pkShader->SetPixelShaderTarget(pcShaderTarget);
    pkShader->SetShaderInterface(pkConstantTable);
    if (pkConstantTable != 0)
    {
        pkConstantTable->Release();
    }
    return pkShader;
}

struct NiMemObject
{
};
const char* FUN_00ee6e28(void* pkDevice);

struct HLSLPixelShader96 : NiMemObject
{
    virtual void DeleteThis(bool bFree);
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void SetName(const char* pcName);
    virtual void v22();
    virtual void SetShaderProgramFile(const char* pcFile);
    virtual void v24();
    virtual void v25();
    virtual void SetProgramCode(unsigned int uiSize, void* pvCode);
    virtual void v27();
    virtual void SetCreator(void* pkCreator);
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void SetD3DPixelShader(void* hShader);
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void SetEntryPoint(const char* pcEntryPoint);
    virtual void v37();
    virtual void SetPixelShaderTarget(const char* pcShaderTarget);
    virtual void v39();
    virtual void SetShaderInterface(ID3DXConstantTable* pkTable);


    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    void* m_pD3DPixelShader;
    const char* m_pcShaderEntryPoint;
    const char* m_pcShaderProfile;
    ID3DXConstantTable* m_pShaderConstantTable;
};

// the vtable at 0x010f10f4 has no symbol, so the inlined constructor stores it by hand
struct HLSLPixelShaderCtor96 : NiMemObject
{
    HLSLPixelShaderCtor96(void* pkRenderer) throw()
    {
        new ((void *)(((HLSLPixelShader96*)this))) ::FUN_00e897d0((intptr_t)(pkRenderer), 2);
        ((HLSLPixelShader96*)this)->m_pD3DPixelShader = 0;
        *(void**)this = &(*reinterpret_cast<void * *>(&::DAT_010f10f4));
        ((HLSLPixelShader96*)this)->m_pcShaderEntryPoint = 0;
        ((HLSLPixelShader96*)this)->m_pcShaderProfile = 0;
        ((HLSLPixelShader96*)this)->m_pShaderConstantTable = 0;
    }
    int m_kNextStreamField[15];
};

struct PixelShaderCreatorHLSL : NiD3DShaderProgramCreatorHLSL
{
    HLSLPixelShader96* FUN_00e96b10(const void* pvBuffer, unsigned int uiBufferSize, const char* pcShaderName,
                                    const char* pcEntryPoint, const char* pcShaderTarget, bool bRecoverable);
};

// @fnv 0x00e96b10
HLSLPixelShader96* PixelShaderCreatorHLSL::FUN_00e96b10(const void* pvSourceBuffer, unsigned int uiSourceSize,
                                                        const char* pcShaderName, const char* pcEntryPoint,
                                                        const char* pcShaderTarget, bool bRecoverable)
{
    HLSLPixelShader96* pkPixelShader = (HLSLPixelShader96*)new HLSLPixelShaderCtor96(DAT_0126fa2c);
    if (!pkPixelShader)
        return 0;

    unsigned int uiCodeSize = 0;
    void* pvCode = 0;
    ID3DXConstantTable* pkConstantTable = 0;
    if (!pcEntryPoint)
        pcEntryPoint = "main";
    if (!pcShaderTarget)
        pcShaderTarget = FUN_00ee6e28(::g_0126fa28);

    if (!CompileShaderFromMemory(pvSourceBuffer, uiSourceSize, pcEntryPoint, pcShaderTarget, pvCode, uiCodeSize,
                                 pkConstantTable, bRecoverable))
    {
        pkPixelShader->DeleteThis(true);
        return 0;
    }

    void* hShader = ((void *)(::FUN_00e988d0((void *)(pvCode))));
    if (!hShader)
    {
        ::FUN_00aa0020(1, bRecoverable, "Failed CreatePixelShader call on %s\n", pcShaderName);
        pkPixelShader->DeleteThis(true);
        return 0;
    }

    pkPixelShader->SetName(pcShaderName);
    pkPixelShader->SetShaderProgramFile(0);
    pkPixelShader->SetProgramCode(uiCodeSize, pvCode);
    pkPixelShader->SetCreator(this);
    pkPixelShader->SetD3DPixelShader(hShader);
    pkPixelShader->SetEntryPoint(pcEntryPoint);
    pkPixelShader->SetPixelShaderTarget(pcShaderTarget);
    pkPixelShader->SetShaderInterface(pkConstantTable);
    if (pkConstantTable)
        pkConstantTable->Release();
    return pkPixelShader;
}

struct SolverVector
{
    void* data;
    int size;
    int capacity;
    int rows;
    int columns;
    int FUN_00cc0760();
    void CopyFrom(SolverVector* other);
};
struct SolverMatrix
{
};
// Runs up to count iterations, returning true when the squared residual is below tolerance squared at an iteration check.
// @fnv 0x00e58f10
bool* ConjugateGradientSolve(bool* abConverged, SolverMatrix* matrix, SolverVector* apInitialGuess, SolverVector* apRhs,
                             int aiMaxIterations, float tolerance)
{
    int size = apInitialGuess->FUN_00cc0760();
    SolverVector temp;
    SolverVector pResidual, p, pMatVec, x;
    ::FUN_00e58e80((intptr_t)(apRhs), (intptr_t)(&pResidual), (::E58E80Object *)(::SolverVector *)(((::SolverVector *)(reinterpret_cast<::S_00e58ea0_cls *>((matrix))->FUN_00e58ea0((::S_00e58ea0_Gen *)(::SolverVector *)(&temp), (::S_00e58ea0_Gen *)(apInitialGuess))))), *(const ::E87E0Matrix *)nullptr);
    reinterpret_cast<::FUN_00c7b0f0_shell *>(&(temp))->FUN_00c7b0f0();
    p.CopyFrom(&pResidual);
    reinterpret_cast<::Stand_e58d90 *>(&(pMatVec))->InitArray(size, 1);
    reinterpret_cast<::Stand_e58d90 *>(&(x))->InitArray(reinterpret_cast<::DBBCBC0Target *>((matrix))->FUN_00dbbc00(), 1);
    float fResidualNormSq = ::DotProduct((::CE588A0Vector *)(::SolverVector *)(&pResidual), (::CE588A0Vector *)(::SolverVector *)(&pResidual));
    float fToleranceSq = tolerance * tolerance;
    int i = 0;
    if (aiMaxIterations > 0)
        do
        {
            if (fResidualNormSq < fToleranceSq)
            {
                *abConverged = true;
                goto done;
            }
            reinterpret_cast<::FUN_00e58b10_class *>((matrix))->FUN_00e58b10((intptr_t)(&pMatVec), (intptr_t)(&p), (intptr_t)(&x));
            {
                float fStepSize = (float)((double)fResidualNormSq / ::DotProduct((::CE588A0Vector *)(::SolverVector *)(&p), (::CE588A0Vector *)(::SolverVector *)(&pMatVec)));
                ::FUN_00e58960((::FUN_00e587b0_Class *)(apInitialGuess), &fStepSize, (::FUN_00e58880_Class *)(::SolverVector *)(&p));
                ++i;
                if (i % 50 == 0)
                {
                    ::FUN_00e589a0((::FUN_00e587b0_Class *)(::SolverVector *)(&pResidual), (::FUN_00e58880_Class *)(apRhs));
                    reinterpret_cast<::FUN_00e58a20_cls *>((matrix))->FUN_00e58a20((::SampleField *volatile)(&pResidual), (::SampleField *)(apInitialGuess), (::SampleField *)(::SolverVector *)(&x));
                    ::fnv_00e589e0::NegateElements((::fnv_00e589e0::FUN_00e587b0_Class *)(::SolverVector *)(&pResidual));
                }
                else
                {
                    fStepSize = -fStepSize;
                    ::FUN_00e58960((::FUN_00e587b0_Class *)(::SolverVector *)(&pResidual), &fStepSize, (::FUN_00e58880_Class *)(::SolverVector *)(&pMatVec));
                }
            }
            float fPrevResidualNormSq = fResidualNormSq;
            fResidualNormSq = ::DotProduct((::CE588A0Vector *)(::SolverVector *)(&pResidual), (::CE588A0Vector *)(::SolverVector *)(&pResidual));
            float beta = fResidualNormSq / fPrevResidualNormSq;
            ::FUN_00e58900((::E589Destination *)(::SolverVector *)(&p), (::E589Values *)(::SolverVector *)(&pResidual), &beta, (::E589ScaledValues *)(::SolverVector *)(&p));
        } while (i < aiMaxIterations);
    *abConverged = false;
done:
    reinterpret_cast<::FUN_00c7b0f0_shell *>(&(x))->FUN_00c7b0f0();
    reinterpret_cast<::FUN_00c7b0f0_shell *>(&(pMatVec))->FUN_00c7b0f0();
    reinterpret_cast<::FUN_00c7b0f0_shell *>(&(p))->FUN_00c7b0f0();
    reinterpret_cast<::FUN_00c7b0f0_shell *>(&(pResidual))->FUN_00c7b0f0();
    return abConverged;
}

struct ConstTableE95
{
    virtual long QueryInterface(void* riid, void** ppv);
    virtual unsigned long AddRef();
    virtual unsigned long Release();
};

class ShaderSrcE95
{
  public:
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual void vfn_06();
    virtual void vfn_07();
    virtual void vfn_08();
    virtual void vfn_09();
    virtual void vfn_0A();
    virtual void vfn_0B();
    virtual void vfn_0C();
    virtual void vfn_0D();
    virtual void vfn_0E();
    virtual void vfn_0F();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void* GetCode();
    virtual void vfn_1A();
    virtual void vfn_1B();
    virtual void vfn_1C();
    virtual void vfn_1D();
    virtual void vfn_1E();
    virtual uintptr_t GetCodeSize();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void SetD3DPixelShader(void* pvHandle);
    virtual unsigned int GetShaderVersion();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual void vfn_28();
    virtual void vfn_29();
    virtual void vfn_2A();
    virtual void vfn_2B();
    virtual void vfn_2C();
    virtual void vfn_2D();
    virtual void SetShaderInterface(ConstTableE95* pkTable);
};

long FUN_00ee6e40(void* pvCode, ConstTableE95** ppkTable);

class ShaderMgrE95
{
  public:
    bool FUN_00e95ba0(ShaderSrcE95* pkShader);
};

// Creates a shader handle from pkShader's code and version, stores it and an optional interface, and returns success.
// @fnv 0x00e95ba0
bool ShaderMgrE95::FUN_00e95ba0(ShaderSrcE95* pkShader)
{
    void* pvCode = pkShader->GetCode();
    if (!pvCode)
        return false;

    unsigned int uiVersion = pkShader->GetShaderVersion();
    void* pvHandle = ::CreateVertexShaderChecked(pvCode, (void *)(&uiVersion), pkShader->GetCodeSize(), 0, 0, 0);
    if (!pvHandle)
        return false;

    pkShader->SetD3DPixelShader(pvHandle);

    ConstTableE95* pkTable;
    if (FUN_00ee6e40(pvCode, &pkTable) >= 0)
        pkShader->SetShaderInterface(pkTable);
    if (pkTable)
        pkTable->Release();
    return true;
}

extern "C" void _ReadWriteBarrier();
struct S00e96610_CT
{
    virtual long QueryInterface(const void* riid, void** ppv);
    virtual unsigned long AddRef();
    virtual unsigned long Release();
};
struct D3DDeviceStandIn;
const char* FUN_00ee6e2e(void* pDevice);


struct S00e96610_Creator;
struct ShaderTargetName
{
    const char* value;
    ShaderTargetName(const char* name) : value(name)
    {}
};
inline void S00e96610_DefaultTarget(const char*& pcTarget)
{
    if (!pcTarget)
        pcTarget = FUN_00ee6e2e(::g_0126fa28);
}

struct S00e96610_VSBase
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    S00e96610_VSBase(void* pkRenderer, void* hDecl) throw();
    virtual ~S00e96610_VSBase();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void SetName(const char* pcName);
    virtual void v22();
    virtual void HasMaster(const char* pcFileName);
    virtual void v24();
    virtual void v25();
    virtual void SetProgramCode(unsigned int uiSize, void* pvCode);
    virtual void v27();
    virtual void SetCreator(S00e96610_Creator* pkCreator);
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void SetShaderUsage(unsigned int uiUsage);
    virtual void v33();
    virtual void SetD3DPixelShader(void* hShader);
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void SetSoftwareVP(unsigned int bSoftwareVP);
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void SetEntryPoint(const char* pcEntryPoint);
    virtual void v43();
    virtual void SetPixelShaderTarget(const char* pcShaderTarget);
    virtual void v45();
    virtual void SetShaderInterface(S00e96610_CT* pkTable);
};

struct S00e96610_VSMid : S00e96610_VSBase
{
    bool m_b2C;
    int m_i30;
    int m_i34;
    int m_i38;
    S00e96610_VSMid(void* pkRenderer) : S00e96610_VSBase(pkRenderer, 0), m_b2C(false), m_i30(0), m_i34(0), m_i38(0)
    {}
};

struct S00e96610_VS : S00e96610_VSMid
{
    int m_i3C;
    int m_i40;
    int m_i44;
    S00e96610_VS(void* pkRenderer) : S00e96610_VSMid(pkRenderer)
    {
        m_i3C = 0;
        m_i40 = 0;
        m_i44 = 0;
    }
    virtual ~S00e96610_VS();
};

struct S00e96610_Creator
{
    void* m_vtbl;
    S00e96610_VS* FUN_00e96610(const char* pcFileName, const char* pcShaderName, const char* pcEntryPoint,
                               ShaderTargetName pcShaderTarget, void* hDecl, uintptr_t uiUsage,
                               unsigned int bSoftwareVP, bool bRecoverable);
};

// Compiles a vertex shader from pcFileName and creates a D3D vertex shader, returning a configured S00e96610_VS or null on failure.
// @fnv 0x00e96610
S00e96610_VS* S00e96610_Creator::FUN_00e96610(const char* pcFileName, const char* pcShaderName,
                                              const char* pcEntryPoint, ShaderTargetName pcShaderTarget, void* hDecl,
                                              uintptr_t uiUsage, unsigned int bSoftwareVP, bool bRecoverable)
{
    S00e96610_VS* pkShader = new S00e96610_VS(DAT_0126fa2c);
    if (!pkShader)
        return 0;

    unsigned int uiCodeSize = 0;
    void* pvCode = 0;
    S00e96610_CT* pkConstantTable = 0;

    if (!pcEntryPoint)
        pcEntryPoint = "main";
    S00e96610_DefaultTarget(pcShaderTarget.value);
    _ReadWriteBarrier();

    if (!reinterpret_cast<::HLSLFileCreator *>(this)->CompileShaderFromFile(pcFileName, pcEntryPoint, pcShaderTarget.value, pvCode, uiCodeSize, (::ID3DXConstantTable *&)(pkConstantTable),
                               bRecoverable))
    {
        delete pkShader;
        return 0;
    }

    void* hShader = ::CreateVertexShaderChecked(pvCode, (void *)(&hDecl), uiUsage, 0, 0, bSoftwareVP);
    if (!hShader)
    {
        ::FUN_00aa0020(1, bRecoverable, "Failed CreateVertexShader call on %s\n", pcShaderName);
        delete pkShader;
        return 0;
    }

    pkShader->SetName(pcShaderName);
    pkShader->HasMaster(pcFileName);
    pkShader->SetProgramCode(uiCodeSize, pvCode);
    pkShader->SetCreator(this);
    pkShader->SetD3DPixelShader(hShader);
    pkShader->SetShaderUsage(uiUsage);
    pkShader->SetSoftwareVP(bSoftwareVP);
    pkShader->SetEntryPoint(pcEntryPoint);
    pkShader->SetPixelShaderTarget(pcShaderTarget.value);
    pkShader->SetShaderInterface(pkConstantTable);

    if (pkConstantTable)
        pkConstantTable->Release();

    return pkShader;
}

struct ShaderArgs
{
    const char* pcFileName;
    const char* pcShaderName;
};
class ShaderProgram96 : public NiMemObject
{
  public:
    ShaderProgram96(void* pkRenderer, int eType) throw();
    virtual ~ShaderProgram96();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
};

class PixelShader96 : public ShaderProgram96
{
  public:
    PixelShader96(void* pkRenderer) throw() : ShaderProgram96(pkRenderer, 2)
    {
        m_pD3DPixelShader = 0;
    }
    virtual ~PixelShader96();
    void* m_pD3DPixelShader;
};

class HLSLPixelShaderObj : public PixelShader96
{
  public:
    HLSLPixelShaderObj(void* pkRenderer) throw() : PixelShader96(pkRenderer)
    {
        m_pcShaderEntryPoint = 0;
        m_pcShaderProfile = 0;
        m_pShaderConstantTable = 0;
    }
    virtual ~HLSLPixelShaderObj();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void SetName(const char* pcName);
    virtual void v22();
    virtual void SetShaderProgramFile(const char* pcFile);
    virtual void v24();
    virtual void v25();
    virtual void SetProgramCode(unsigned int uiSize, void* pvCode);
    virtual void v27();
    virtual void SetCreator(void* pkCreator);
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void SetD3DPixelShader(void* hShader);
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void SetEntryPoint(const char* pcEntryPoint);
    virtual void v37();
    virtual void SetPixelShaderTarget(const char* pcShaderTarget);
    virtual void v39();
    virtual void SetShaderInterface(ID3DXConstantTable* pkTable);

    const char* m_pcShaderEntryPoint;
    const char* m_pcShaderProfile;
    ID3DXConstantTable* m_pShaderConstantTable;
};

struct HLSLFileShaderCreator : NiD3DShaderProgramCreatorHLSL
{
    HLSLPixelShaderObj* FUN_00e96990(ShaderArgs args, const char* pcEntryPoint, const char* pcShaderTarget,
                                     bool bRecoverable);
};

// Creates an HLSLPixelShaderObj by compiling a shader file and configuring the new object with the compiled code and metadata.
// @fnv 0x00e96990
HLSLPixelShaderObj* HLSLFileShaderCreator::FUN_00e96990(ShaderArgs args, const char* pcEntryPoint,
                                                        const char* pcShaderTarget, bool bRecoverable)
{
    HLSLPixelShaderObj* pkPixelShader = new HLSLPixelShaderObj(DAT_0126fa2c);
    if (!pkPixelShader)
        return 0;

    unsigned int uiCodeSize = 0;
    void* pvCode = 0;
    ID3DXConstantTable* pkConstantTable = 0;

    if (!pcEntryPoint)
        pcEntryPoint = "main";
    if (!pcShaderTarget)
        pcShaderTarget = FUN_00ee6e28(::g_0126fa28);

    if (!reinterpret_cast<::HLSLFileCreator *>(this)->CompileShaderFromFile(args.pcFileName, pcEntryPoint, pcShaderTarget, pvCode, uiCodeSize, pkConstantTable,
                               bRecoverable))
    {
        delete pkPixelShader;
        return 0;
    }
    void* hShader = ((void *)(::FUN_00e988d0((void *)(pvCode))));
    if (!hShader)
    {
        ::FUN_00aa0020(1, bRecoverable, "Failed CreatePixelShader call on %s\n", args.pcShaderName);
        delete pkPixelShader;
        return 0;
    }
    pkPixelShader->SetName(args.pcShaderName);
    pkPixelShader->SetShaderProgramFile(args.pcFileName);
    pkPixelShader->SetProgramCode(uiCodeSize, pvCode);
    pkPixelShader->SetCreator(this);
    pkPixelShader->SetD3DPixelShader(hShader);
    pkPixelShader->SetEntryPoint(pcEntryPoint);
    pkPixelShader->SetPixelShaderTarget(pcShaderTarget);
    pkPixelShader->SetShaderInterface(pkConstantTable);
    if (pkConstantTable)
        pkConstantTable->Release();
    return pkPixelShader;
}

struct Dummy_00cc0760
{
    int unk00, unk04, unk08;
    int rows;
    int FUN_00cc0760();
};
// @fnv 0x00e58ea0
S_00e58ea0_Gen* S_00e58ea0_cls::FUN_00e58ea0(S_00e58ea0_Gen* a1, S_00e58ea0_Gen* a2)
{
    a1->InitFloatArray(reinterpret_cast<::Dummy_00cc0760 *>((a2))->FUN_00cc0760(), reinterpret_cast<::FUN_00e587a0_Class *>((a2))->FUN_00e587a0(), 0.0f);
    S_00e58ea0_Arr tmpArr;
    tmpArr.InitFloatArray(reinterpret_cast<::DBBCBC0Target *>(this)->FUN_00dbbc00(), reinterpret_cast<::FUN_00e587a0_Class *>((a2))->FUN_00e587a0(), 0.0f);
    reinterpret_cast<::FUN_00e58a20_cls *>(this)->FUN_00e58a20((::SampleField *volatile)(a1), (::SampleField *)(a2), (::SampleField *)(::S_00e58ea0_Arr *)(&tmpArr));
    reinterpret_cast<::FUN_00c7b0f0_shell *>(&(tmpArr))->FUN_00c7b0f0();
    return a1;
}
// @fnv 0x00cc0760
int Dummy_00cc0760::FUN_00cc0760()
{
    return rows;
}

extern "C" long D3DXGetShaderConstantTable(const unsigned long*, ID3DXConstantTable**);

struct BufferPixelShaderCreator : HLSLFileShaderCreator
{
    HLSLPixelShaderObj* FUN_00e96100(ID3DXBuffer* code, unsigned int codeSize, const char* name, const char* entryPoint,
                                     const char* target, bool recoverable);
};

// @fnv 0x00e96100
HLSLPixelShaderObj* BufferPixelShaderCreator::FUN_00e96100(ID3DXBuffer* code, unsigned int codeSize, const char* name,
                                                           const char* entryPoint, const char* target, bool recoverable)
{
    HLSLPixelShaderObj* shader = new HLSLPixelShaderObj(DAT_0126fa2c);
    if (!shader)
        return 0;

    ID3DXConstantTable* constants = 0;
    if (D3DXGetShaderConstantTable((const unsigned long*)code->GetBufferPointer(), &constants) < 0)
        return 0;

    if (!entryPoint)
        entryPoint = "main";
    if (!target)
        target = FUN_00ee6e28(::g_0126fa28);

    void* handle = ((void *)(::FUN_00e988d0((void *)(code->GetBufferPointer()))));
    if (!handle)
    {
        ::FUN_00aa0020(1, recoverable, "Failed CreatePixelShader call on %s\n", name);
        delete shader;
        return 0;
    }

    void* copy = ::FUN_00aa1070(codeSize);
    NiMemcpy(copy, code->GetBufferPointer(), code->GetBufferSize());

    shader->SetName(name);
    shader->SetShaderProgramFile(0);
    shader->SetProgramCode(codeSize, copy);
    shader->SetCreator(this);
    shader->SetD3DPixelShader(handle);
    shader->SetEntryPoint(entryPoint);
    shader->SetPixelShaderTarget(target);
    shader->SetShaderInterface(constants);
    if (constants)
        constants->Release();
    return shader;
}

void* __cdecl FUN_00e95cc0();
const void* __cdecl FUN_00e95df0();

struct ID3DXConstantTable;
struct NiD3DHLSLPixelShader_od
{
    char m_auiShapeKeys[0x48];
    ID3DXConstantTable* m_pShaderConstantTable;
    ID3DXConstantTable* FUN_00b18300();
};

// @fnv 0x00b18300
ID3DXConstantTable* NiD3DHLSLPixelShader_od::FUN_00b18300()
{
    return m_pShaderConstantTable;
}
#include "generated/data/gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderprogramcreatorhlsl.inc"
