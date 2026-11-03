#pragma once

class TESIdleForm;
class TESSound;

// The data members of DialogueResponse, as its constructor (0x0083d280) fills them. The release build reads the
// emotion and idle fields through folded 4-byte getters: 0x0044ddc0 (+0x8), 0x0084e3a0 (+0xC), 0x009611e0 (+0x18)
// and 0x00441110 (+0x1C).
struct DialogueResponseFields
{
    char *text;
    unsigned short textLength;
    unsigned short textCapacity;
    unsigned int emotionType;
    int emotionValue;
    char *voiceFile;
    unsigned short voiceFileLength;
    unsigned short voiceFileCapacity;
    TESIdleForm *speakerIdle;
    TESIdleForm *listenerIdle;
    TESSound *sound;
    bool useEmotionAnimation;
    unsigned int responseID;
};
