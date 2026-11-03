#pragma once

struct S72_Model;

struct S72_Renderer {
public:
    // 0x00e72980
    bool BuildAndRegisterNodes(unsigned int, ::S72_Model *, unsigned short, unsigned short, unsigned int, unsigned int, unsigned short, void *);
};
