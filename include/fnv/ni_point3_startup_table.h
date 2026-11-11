#pragma once

// The storage of the two startup globals that
// src/gamebryo2.2/corelibs/nimain/console/nipoint3_console.cpp defines, as
// that unit initializes it: 17 ints. The name is historical: the units that
// read the storage treat it as a pixel format record.
// docs/pixel-format-startup-table.md lists those units and what stays open.
struct NiPoint3StartupTable
{
    int data[17];
};

extern NiPoint3StartupTable gNiPoint3StartupSrc;
extern NiPoint3StartupTable gNiPoint3StartupDst;

// Views the storage as a unit's own record. It compiles only for a record
// that covers exactly the 17 ints. Such a record cannot need a stricter
// alignment: 68 is not a multiple of 8.
//
// This is a transitional cast shim that checks the size and nothing else. It
// is not the typed owner of the storage: the owner is NiPoint3StartupTable
// above. That it compiles for a View is not evidence that the storage has
// that View's layout. Each new View needs a row in the census table of
// docs/pixel-format-startup-table.md. The shim retires when the units share
// one NiPixelFormat declaration.
template <class View>
View& NiPoint3StartupTableAs(NiPoint3StartupTable& table)
{
    static_assert(sizeof(View) == sizeof(NiPoint3StartupTable));
    return *reinterpret_cast<View*>(&table);
}
