// gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderprogramfactory_packet.h: declares NiD3DShaderProgramFactory, DirectoryEntry

#include <cctype>
#include <cstring>
#include "fnv/symbols_00e93000.h"
#include "fnv/symbols_0126f000.h"
class NiShader;
struct NiD3DShaderProgramCreator;
template <class K, class V> class NiTPointerMap
{
};
template <class B, class V> class NiTStringTemplateMap
{
  public:
    void SetAt(const char*, NiShader*);
};
typedef NiTStringTemplateMap<NiTPointerMap<const char*, NiShader*>, NiShader*> CreatorMap;
class NiD3DShaderProgramFactory
{
  public:
    const char* GetNextName(void*&);
    static bool RegisterCreator(const char*, NiD3DShaderProgramCreator*);
};
struct DirectoryEntry
{
    DirectoryEntry* next;
    unsigned int unused;
    const char* value;
};
