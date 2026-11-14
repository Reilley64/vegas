// gamebryo2.2/corelibs/nimain/nitristripsdata_forwarders.h: declares NiLinesData, NiPSysData
#ifndef FNV_NITRISTRIPSDATA_FORWARDERS_H
#define FNV_NITRISTRIPSDATA_FORWARDERS_H
struct NiStream;
class NiLinesData
{
  public:
    bool RegisterStreamables(NiStream&);
    void LinkObject(NiStream&);
};
struct NiPSysData
{
  public:
    bool RegisterStreamables(NiStream&);
    void LinkObject(NiStream&);
};
#endif
