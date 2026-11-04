// fallout/ai/camerashake_decls.h: declares NiFixedString, NiAVObject, NiNode, ModelLoader, FileFinder
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_011c3000.h"
class NiFixedString
{
  public:
    const char* handle;
    NiFixedString(const char*);
    ~NiFixedString();
};
struct NiPoint3;
class NiAVObject
{
  public:
public:
    ::NiPoint3 &FUN_0043c490();
};
class NiNode : public NiAVObject
{
};
class ModelLoader
{
  public:
};
class FileFinder
{
  public:
    enum FILE_LOCATION
    {
        NONE = 0
    };
    static FILE_LOCATION Exist(const char*, char*, unsigned int, unsigned int);
};
extern NiNode* DAT_011dfecc;
