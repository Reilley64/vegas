// gamebryo2.2/corelibs/niconsolerenderer/niconsolerenderstate_decls.h: declares ShaderPassRenderer

#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00e69000.h"
#include "fnv/symbols_0126f000.h"
struct DepthDevice;
typedef int(* CreateExFunction)(unsigned int, DepthDevice**);
typedef DepthDevice*(* CreateFunction)(unsigned int);
class NiD3DDefaultShader
{
  public:
};
class ShaderPassRenderer
{
  public:
    static unsigned int Create(unsigned int);
};
