// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_007adc60_shell
{
    char pad00[0xec];
    unsigned int dwFlags;
    void FUN_007adc60(int aIndex, bool aSet);
};

// Sets or clears bit aIndex in dwFlags, according to aSet.
// @fnv 0x007adc60
void FUN_007adc60_shell::FUN_007adc60(int aIndex, bool aSet)
{
    if (aSet)
        dwFlags |= (1 << aIndex);
    else
        dwFlags &= ~(1 << aIndex);
}
