#include <windows.h>
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Item
{
    virtual void Reserved();
    virtual void Destroy();
    volatile long references;
};

struct Owner
{
    unsigned char unk00[0x4c];
    Item* item;
    void FUN_00a76a60(Item* replacement);
};

// @fnv 0x00a76a60
void Owner::FUN_00a76a60(Item* replacement)
{
    Item* previous = item;
    if (previous != replacement)
    {
        if (previous && InterlockedDecrement(&previous->references) == 0)
            previous->Destroy();
        item = replacement;
        if (replacement)
            InterlockedIncrement(&replacement->references);
    }
}
