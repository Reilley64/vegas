#pragma once

enum DB7570Result;

class DB7570Map {
public:
    // 0x00db7570
    ::DB7570Result Lookup(unsigned int, unsigned int &) const;
};
