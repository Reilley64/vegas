#pragma once

// The data members of hkpCdBody, for code that reaches collision bodies through stand-in types. The folded 4-byte
// getter at 0x00726070 (BSSimpleList::GetNext) returns `uiShapeKey` when called on a body.
struct HavokCdBodyFields
{
    const void* pShape;
    unsigned int uiShapeKey;
    const void* pMotion;
    const void* pParent;
};
