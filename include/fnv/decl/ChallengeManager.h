#pragma once

class TESForm;
enum CHALLENGE_TYPE;

class ChallengeManager {
public:
    // 0x005f5880
    static void CheckCompletedChallenges();
    // 0x005f5950
    static bool UpdateChallengeProgress(::CHALLENGE_TYPE, int, ::TESForm *, ::TESForm *, unsigned short, unsigned short, unsigned short);
};
