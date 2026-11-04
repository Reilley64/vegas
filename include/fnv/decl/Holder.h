#pragma once
#include <cstdint>

class FUN_008515f0;
class NiFixedString;
class NiPoint3;
class NiTexture;
class RefObject;
class TESForm;
class TESSound;
struct Big;
struct Item;
struct NiStream;
struct NiTexture;
struct Node;
struct RefObj;
struct ReferenceLightData;
struct Tile;
struct Vec3;

struct Holder {
public:
    // 0x00418250
    ::ReferenceLightData *FUN_00418250();
    // 0x00458700
    ::Holder *FUN_00458700(::Holder *, int);
    // 0x0047c560
    void CallElements();
    // 0x00485680
    void FUN_00485680();
    // 0x004e75d0
    ::Big *CopyBig(::Big *);
    // 0x00592380
    void *FUN_00592380(unsigned int);
    // 0x0059a4c0
    void *Release(unsigned int);
    // 0x005e0490
    ::Holder *FUN_005e0490(unsigned int, unsigned int);
    // 0x005f4c90
    ::Vec3 *GetVec(::Vec3 *);
    // 0x005fc970
    void FUN_005fc970(int, bool);
    // 0x0061ff30
    void FUN_0061ff30(::Node *);
    // 0x00628950
    ::Holder *FUN_00628950(::Holder *, ::Holder *);
    // 0x0065cec0
    intptr_t FUN_0065cec0(unsigned int);
    // 0x006834e0
    void FUN_006834e0(int *);
    // 0x00696ca0
    ::Holder *FUN_00696ca0(::Holder *);
    // 0x0071dd50
    void FUN_0071dd50(const char *);
    // 0x00759850
    void FUN_00759850();
    // 0x007867a0
    void UpdateTileEffects(::Tile *);
    // 0x007e7b30
    void FUN_007e7b30();
    // 0x00851620
    void RemoveAndDelete(::FUN_008515f0 *);
    // 0x0085f010
    void FUN_0085f010(::TESForm *, unsigned short);
    // 0x0085f2b0
    void FUN_0085f2b0(::TESSound *, unsigned short);
    // 0x0087b760
    void FUN_0087b760(float, ::NiPoint3 *);
    // 0x00970a20
    ::Item *FUN_00970a20(void *, int);
    // 0x00999120
    bool IsModifierZero();
    // 0x009c3e10
    void FUN_009c3e10();
    // 0x00a32b80
    void FUN_00a32b80(unsigned int);
    // 0x00a3f930
    void FUN_00a3f930(::RefObj *);
    // 0x00a45bc0
    void FUN_00a45bc0();
    // 0x00a48fb0
    void FUN_00a48fb0();
    // 0x00a57ad0
    bool FUN_00a57ad0(::NiStream &);
    // 0x00a5ba40
    bool FUN_00a5ba40(::NiTexture *);
    // 0x00a5bc40
    bool FUN_00a5bc40(const ::NiFixedString &, ::NiTexture *);
    // 0x00ba38b0
    void FUN_00ba38b0();
    // 0x00c363c0
    void FUN_00c363c0(::Holder *, int);
    // 0x00c6d960
    ::RefObject *GetCurrentObject();
    // 0x00cf57e0
    ::Holder *Destroy(unsigned char);
    // 0x00e6c550
    bool InitFormats();
    // 0x00e88d60
    void FUN_00e88d60();
    // 0x00e8de70
    void ReleaseAll();
};
