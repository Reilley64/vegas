// gamebryo2.2/corelibs/nisystem/console/nifilename_packet.h: declares FileNameComponents
#ifndef NIFILENAME_PACKET_H
#define NIFILENAME_PACKET_H

#include "runtime/crt.h"
extern const char DAT_010a47b0[];  // "\\*" search suffix
class FileNameComponents
{
  public:
    char m_acFolderPath[256];
    char m_acDriveLetter[3];
    char m_acExtension[256];
    char m_acBaseName[256];
    char m_acDirectoryComponent[256];
    FileNameComponents(const char*);
    int SetFullPath(const char*);
};
#endif
