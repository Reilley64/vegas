// gamebryo2.2/corelibs/nimain/niintegersextradata_decls.h: declares NiExtraData, NiIntegerStreamEntry, NiIntegerStreamArray, NiIntegersExtraData
#ifndef NIINTEGERSEXTRADATA_DECLS_H
#define NIINTEGERSEXTRADATA_DECLS_H

class NiStream;
template <class T> void ReadBinaryValue(NiStream&, T&);
class NiStream;
class NiExtraData
{
  public:
    unsigned int baseData[3];
    void LoadBinary(NiStream&);
public:
    void LinkObject(::NiStream &);
};
struct NiIntegerStreamEntry
{
    unsigned int fields[3];
};
struct NiIntegerStreamArray
{
};
class NiIntegersExtraData : public NiExtraData
{
  public:
    NiIntegerStreamArray entries;
    void LoadBinary(NiStream&);
};
#endif
