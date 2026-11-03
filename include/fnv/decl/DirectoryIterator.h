#pragma once

enum BSSystemFile__ErrorCode;

class DirectoryIterator {
public:
    // 0x00b00720
    ::BSSystemFile__ErrorCode NextEntry(bool &);
};
