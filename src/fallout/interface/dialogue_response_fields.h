#pragma once

// The leading fields of a dialogue response, for interface code that reaches responses through stand-in types.
// The names follow the accessors in the pre-VEGAS-11 source.
struct DialogueResponseFields
{
    char* m_pText;
    unsigned short m_usTextLength;
    unsigned short m_usTextCapacity;
    unsigned int flags;
    unsigned int soundID;
    void* unk10;
    void* unk14;
    unsigned int emotion;
    unsigned int emotionValue;
};
