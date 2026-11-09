#include "GameTimerRecord.h"
#include "fnv/decl/FUN_00aa50f0_Class.h"
#include "fnv/game_timer.h"
#include "fnv/recipe_pulse.h"

#include <array>
#include <atomic>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <thread>
#include <type_traits>
#include <vector>

extern float DAT_011ac3a0;
extern float DAT_011ac3a4;
extern float DAT_011ac3ac;
void FUN_00aa4e40();

namespace
{
void Check(bool condition, const char* name)
{
    if (!condition)
    {
        std::fprintf(stderr, "game timer: %s\n", name);
        std::abort();
    }
}
void Near(float actual, float expected, const char* name)
{
    Check(std::fabs(actual - expected) < 0.00001f, name);
}
unsigned int slept;
void RecordSleep(unsigned int milliseconds) { slept += milliseconds; }

void InitialFields(const GameTimerRecord& timer, unsigned int tick)
{
    Check(timer.m_ucFirstTimerByte == 0, "initial pause depth");
    Near(timer.m_fFirstTimerValue, 0, "initial interval");
    Near(timer.m_fSecondTimerValue, 0, "initial fractional remainder");
    Near(timer.fTimeSinceScaleStart, 0, "initial scaled delta");
    Near(timer.m_fFourthTimerValue, 0, "initial unscaled delta");
    Check(timer.m_uiFirstTimerValue == 0, "initial elapsed time");
    Check(timer.m_uiSecondTimerValue == tick, "initial epoch");
    Check(!timer.m_bFirstTimerFlag && !timer.m_bSecondTimerFlag, "initial policy/zero flags");
}

void ConcurrentStartup(bool lazy)
{
    std::atomic<bool> go{false};
    std::vector<std::thread> threads;
    for (int i = 0; i < 16; ++i)
        threads.emplace_back([&] {
            while (!go.load(std::memory_order_acquire)) {}
            if (!lazy)
                fnv::timer::Start(1000);
            Check(fnv::timer::Time() == 0, "concurrent first time");
            Near(fnv::timer::Seconds(), 0, "concurrent first seconds");
            Near(fnv::timer::RealSeconds(), 0, "concurrent first unscaled seconds");
        });
    go.store(true, std::memory_order_release);
    for (auto& thread : threads)
        thread.join();
    InitialFields(g_timeGlobal, lazy ? g_timeGlobal.m_uiSecondTimerValue : 1000);
    const auto epoch = g_timeGlobal.m_uiSecondTimerValue;
    fnv::timer::Start(epoch + 999);
    Check(g_timeGlobal.m_uiSecondTimerValue == epoch, "second startup does not reset epoch");
}

void UpdateAndPause()
{
    GameTimerRecord timer{};
    InitialFields(timer, 0);
    timer.Init(1000);
    InitialFields(timer, 1000);
    timer.Update(1020, RecordSleep);
    Check(timer.m_uiFirstTimerValue == 20, "elapsed ticks");
    Near(timer.fTimeSinceScaleStart, 0.020f, "variable delta");
    Check(slept == 0, "ordinary delta does not sleep");
    timer.Update(1020, RecordSleep);
    Check(timer.m_bSecondTimerFlag && slept == 9, "zero delta fallback/sleep");
    Near(timer.m_fFourthTimerValue, 0.010f, "zero delta minimum");
    timer.Update(1029, RecordSleep);
    Check(!timer.m_bSecondTimerFlag && slept == 10, "nonzero below minimum");
    timer.Update(1039, RecordSleep);
    Check(slept == 10, "minimum boundary does not sleep");
    timer.Update(1205, RecordSleep);
    Near(timer.m_fFourthTimerValue, 0.166f, "upper boundary");
    timer.Update(1505, RecordSleep);
    Near(timer.m_fFourthTimerValue, 0.166f, "large delta clamp");
    Check(timer.m_uiFirstTimerValue == 505, "clamp does not replace elapsed timestamp");

    timer.Pause(1510);
    const auto pausedTime = timer.m_uiFirstTimerValue;
    const auto pausedEpoch = timer.m_uiSecondTimerValue;
    timer.Pause(1600);
    Check(timer.m_ucFirstTimerByte == 2 && timer.m_uiFirstTimerValue == pausedTime &&
          timer.m_uiSecondTimerValue == pausedEpoch, "nested pause leaves baselines alone");
    timer.Update(1700, RecordSleep);
    Near(timer.fTimeSinceScaleStart, 0, "paused scaled delta");
    Near(timer.m_fFourthTimerValue, 0.166f, "paused update preserves unscaled delta");
    timer.Resume(1800);
    Check(timer.m_ucFirstTimerByte == 1 && timer.m_uiFirstTimerValue == pausedTime,
          "inner resume leaves baseline alone");
    timer.Resume(1900);
    Check(timer.m_ucFirstTimerByte == 0 && timer.m_uiFirstTimerValue == 895 &&
          timer.m_uiSecondTimerValue == 1390, "outer resume excludes paused time");
    timer.Update(1920, RecordSleep);
    // Resume preserves the source's timestamp-complement protocol exactly.
    Check(timer.m_uiFirstTimerValue == 530, "post-resume elapsed timestamp");
    const auto time = timer.m_uiFirstTimerValue;
    timer.Resume(2000);
    Check(timer.m_ucFirstTimerByte == 0 && timer.m_uiFirstTimerValue == time,
          "unmatched resume is a no-op");

    timer.m_fFourthTimerValue = 0.75f;
    timer.Init(0xfffffff0u);
    Near(timer.m_fFourthTimerValue, 0.75f, "explicit Init preserves fourth float");
    timer.Update(4, RecordSleep);
    Check(timer.m_uiFirstTimerValue == 20, "unsigned tick wrap");
    Near(timer.fTimeSinceScaleStart, 0.020f, "wrapped tick delta");

    FUN_00aa50f0_Class constructed{};
    constructed.m_fFourthTimerValue = 0.5f;
    constructed.FUN_00aa50f0(77);
    Check(constructed.m_uiSecondTimerValue == 77, "legacy initialization entry uses actual native record");
    Near(constructed.m_fFourthTimerValue, 0.5f, "legacy partial Init preserves fourth float");
}

void IntervalAndScale()
{
    GameTimerRecord timer{};
    timer.Init(0);
    timer.SetFrequency(60);
    Near(timer.m_fFirstTimerValue, 1000.0f / 60, "frequency supplier");
    timer.Update(1234, RecordSleep);
    Check(timer.m_uiFirstTimerValue == 16, "fixed interval whole ticks");
    Near(timer.m_fSecondTimerValue, 2.0f / 3, "fixed interval fraction");
    timer.Update(9999, RecordSleep);
    Check(timer.m_uiFirstTimerValue == 33, "fixed interval accumulates remainder");
    Near(timer.m_fFourthTimerValue, 1.0f / 60, "fixed interval ignores wall-clock delta");
    timer.SetMultiplier(2.0f, false);
    Near(timer.fTimeSinceScaleStart, 1.0f / 30, "immediate local-policy rescale");
    Near(timer.m_fFourthTimerValue, 1.0f / 60, "scale leaves unscaled delta intact");
    timer.m_bFirstTimerFlag = true;
    timer.SetMultiplier(3.0f, false);
    Near(DAT_011ac3a0, 2, "target policy defers multiplier");
    Near(DAT_011ac3a4, 3, "target multiplier");
    FUN_00aa4e40();
    Near(DAT_011ac3a0, 2.2f, "gradual multiplier step");
    timer.SetMultiplier(2.21f, false);
    FUN_00aa4e40();
    Near(DAT_011ac3a0, 2.21f, "increasing target does not overshoot");
    timer.SetMultiplier(1.0f, true);
    Near(DAT_011ac3a0, 1, "immediate target restoration");
    timer.SetMultiplier(0.99f, false);
    FUN_00aa4e40();
    Near(DAT_011ac3a0, 0.99f, "decreasing target does not overshoot");
    timer.SetMultiplier(1.0f, true);
    timer.SetFrequency(0);
    Check(timer.m_fFirstTimerValue == 0, "zero frequency selects variable interval");
    Check(DAT_011ac3ac == 0.1f, "real production multiplier supplier");
}

void SharedConsumers()
{
    namespace clock = fnv::timer;
    clock::SetFrequency(0);
    const auto epoch = g_timeGlobal.m_uiSecondTimerValue;
    clock::Update(epoch + 100, RecordSleep);
    Check(clock::Time() == 100, "shared frame time");
    Near(clock::Seconds(), 0.1f, "shared frame seconds");
    clock::Start(epoch + 8000);
    Check(clock::Time() == 100, "startup does not reset running timer");

    fnv::RecipePulse pulse{10.0f, clock::Time(), 0};
    clock::Update(epoch + 120, RecordSleep);
    pulse.Advance(0, 20);
    Near(pulse.brightness, 15, "recipe reads shared frame time");
    clock::Update(epoch + 160, RecordSleep);
    pulse.Advance(0, 20);
    Near(pulse.brightness, 20, "recipe upper clamp");
    Check(pulse.decreasing == 1, "recipe reverses at upper bound");
    clock::Update(epoch + 260, RecordSleep);
    pulse.Advance(0, 20);
    Near(pulse.brightness, 0, "recipe lower clamp");
    Check(pulse.decreasing == 0, "recipe reverses at lower bound");

    unsigned int timestamp = 250;
    const unsigned int elapsed = clock::ElapsedSince(timestamp);
    std::array<unsigned char, 4> publicSaveBytes{};
    std::memcpy(publicSaveBytes.data(), &elapsed, sizeof elapsed);
    clock::Update(epoch + 300, RecordSleep);
    unsigned int loadedElapsed{};
    std::memcpy(&loadedElapsed, publicSaveBytes.data(), sizeof loadedElapsed);
    const auto restored = clock::TimestampFromElapsed(loadedElapsed);
    Check(loadedElapsed == 10 && restored == 290, "spectator four-byte elapsed-time restore across epochs");
    Check(clock::ElapsedSince(restored) == loadedElapsed, "restored spectator age");
    Check(clock::TimestampFromElapsed(400) == 0xffffff9cu, "spectator timestamp subtraction wraps");

    clock::SetUseGlobalMultiplierTarget(false);
    clock::SetMultiplier(2.0f, false);
    Near(clock::UnmodifiedSeconds(), 0.040f, "unmodified-seconds receiver is a timer, not a Tile");
    clock::Pause(epoch + 310);
    clock::Pause(epoch + 311);
    clock::Update(epoch + 400, RecordSleep);
    Near(clock::Seconds(), 0, "shared paused delta");
    Near(clock::UnmodifiedSeconds(), 0, "unmodified seconds preserves paused policy");
    Near(clock::RealSeconds(), 0.040f, "last real seconds survives paused update");
    clock::Resume(epoch + 410);
    clock::Resume(epoch + 420);
    clock::SetMultiplier(1.0f, false);
}
}

int main(int argc, char** argv)
{
    static_assert(sizeof(unsigned int) == 4);
    static_assert(std::is_standard_layout_v<GameTimerRecord>);
    static_assert(sizeof(GameTimerRecord) == 32);
    static_assert(offsetof(GameTimerRecord, m_fFourthTimerValue) == 16);
    if (argc == 2 && std::strcmp(argv[1], "--update-start") == 0)
    {
        // A first update must not sample a later startup epoch and underflow.
        fnv::timer::Update(1000, RecordSleep);
        Check(g_timeGlobal.m_uiSecondTimerValue == 1000 && fnv::timer::Time() == 0,
              "first-update startup uses the supplied tick");
        Near(fnv::timer::Seconds(), 0.010f, "first-update minimum, not a wrapped maximum");
        return 0;
    }
    const bool lazy = argc == 2 && std::strcmp(argv[1], "--lazy-start") == 0;
    ConcurrentStartup(lazy);
    UpdateAndPause();
    IntervalAndScale();
    SharedConsumers();
}
