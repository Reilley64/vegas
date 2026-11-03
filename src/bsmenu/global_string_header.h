#pragma once

// The header the global string table keeps in front of each string.
struct StringHeader
{
    long refs;
    unsigned int length;
};
