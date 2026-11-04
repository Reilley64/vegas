#pragma once

class NiFixedString {
public:
    // 0x00438170
    NiFixedString(const char *);
    // 0x0048af40
    NiFixedString(const ::NiFixedString &);
    // 0x0048af70
    int IsNotEmpty() const;
    // 0x004b9900
    void *FUN_004b9900(unsigned int);
    // 0x00761760
    void FUN_00761760(int *, unsigned int);
    // 0x00a2e750
    ::NiFixedString &operator=(const char *);
};
