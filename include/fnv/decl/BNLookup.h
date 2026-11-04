#pragma once

struct BNObject;

struct BNLookup {
public:
    // 0x0048f500
    ::BNObject *FindObjectByNameVariant(::BNObject *, int);
};
