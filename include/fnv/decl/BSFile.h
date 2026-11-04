#pragma once

class BSFile {
public:
    // 0x00afb5f0
    bool AttachFileStream(bool, bool);
    // 0x00aff240
    ~BSFile();
    // 0x00aff300
    bool Open(bool, bool);
    // 0x00aff990
    void SetEndianSwap(bool);
    // 0x00affc60
    bool Write();
    // 0x00affd10
    void Close();
    // 0x00b00650
    unsigned int Read(void *, unsigned int);
};
