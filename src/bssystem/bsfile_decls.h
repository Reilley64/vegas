// bssystem/bsfile_decls.h: declares MemoryManager, NiFile, BSFile
#ifndef FNV_BSFILE_PRIVATE_DECLS_H
#define FNV_BSFILE_PRIVATE_DECLS_H

#include <cstdio>
#include "runtime/crt.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_011f6000.h"
class _iobuf;
class MemoryManager
{
  public:
};

class NiFile
{
  private:
    unsigned char fieldAt4[4];

  public:
    void* readHandler;
    void* writeHandler;

  public:
    unsigned int bufferSize;
    unsigned int bufferPosition;
    unsigned int bufferEnd;
    unsigned int field1c;

  public:
    void* m_pBuffer;
    _iobuf* m_pFile;

  public:
    unsigned int openMode;

  public:
    bool m_bGood;

  public:
    struct
    {
        unsigned char prefix[0x17];
        char pFileName[0x30];
    } pathStorage;

  public:
  protected:
    bool Flush();

  public:
    virtual ~NiFile();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual bool Open(bool, bool);
    unsigned int FileRead(void*, unsigned int);
};


class BSFile : public NiFile
{
  public:
    unsigned char fields74[0xdc];
    unsigned int fileOffsetAt150;
    unsigned int fileSizeAt154;
    unsigned char fields158[0x10];
    unsigned int fileValueAt168;
    virtual ~BSFile();
    void Close();
    void SetEndianSwap(bool doSwap);
    virtual bool Open(bool, bool);
    bool Write();
    unsigned int Read(void*, unsigned int);
    bool AttachFileStream(bool, bool);
    unsigned int GetFilePosition();
    unsigned int GetBufferValue();
    unsigned int GetFileSize();
};

#endif
