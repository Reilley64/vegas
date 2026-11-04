
// src/havok/common/scenedata/scene/hkxsceneclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/scene/hkxsceneclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include "fnv/decl/Scene.h"
struct Allocator
{
    virtual void Allocate();
    virtual void Reallocate();
    virtual void Free(void* object, unsigned int size);
};
struct AudioManager
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    Allocator* allocator;
};
struct AudioObject
{
    void* vtable;
    unsigned short allocationSize;
    AudioObject* Release(unsigned int flags);
};
// Calls ClearScene, then if flags has bit 0 set frees this through the AudioManager allocator using allocationSize, and returns this.
// @fnv 0x00e01ca0
AudioObject* AudioObject::Release(unsigned int flags)
{
    reinterpret_cast<::Scene *>(this)->ClearScene();
    if (flags & 1)
    {
        AudioManager* manager = static_cast<AudioManager*>(::FUN_00c85750());
        manager->allocator->Free(this, allocationSize);
    }
    return this;
}
