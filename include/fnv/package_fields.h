#pragma once

class LocationDescriptor;

// The TESPackage data member that package code reads through the folded 4-byte getter at 0x0055b980
// (BGSMessageInitAccess::GetIconFormID, +0x2c): the package location.
struct TESPackageFields
{
    char pad00[0x2c];
    LocationDescriptor *location;
};
