#ifndef FNV_BSTIMER_H
#define FNV_BSTIMER_H

// Native scalar timer state, not an image-layout or polymorphic receiver view.
// Value initialization defines all fields, including the unscaled delta.
struct GameTimerRecord
{
    unsigned char m_ucFirstTimerByte{};
    float m_fFirstTimerValue{};
    float m_fSecondTimerValue{};
    float fTimeSinceScaleStart{};
    float m_fFourthTimerValue{};
    unsigned int m_uiFirstTimerValue{};
    unsigned int m_uiSecondTimerValue{};
    bool m_bFirstTimerFlag{};
    bool m_bSecondTimerFlag{};

    // Reinitialization intentionally preserves the last unscaled delta.
    void Init(unsigned int tick);
    void Update();
    void Update(unsigned int tick, void (*sleep)(unsigned int));
    void Enable();
    void Resume(unsigned int tick);
    void FUN_00aa50a0();
    void Pause(unsigned int tick);
    void SetFrequency(unsigned int frequency);
    void SetMultiplier(float multiplier, bool immediate);
};

unsigned int GameTimerTick();
void GameTimerSleep(unsigned int milliseconds);
extern GameTimerRecord g_timeGlobal;

#endif
