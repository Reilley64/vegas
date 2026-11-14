#ifndef FNV_GAME_TIMER_API_H
#define FNV_GAME_TIMER_API_H

// The global timer is initialized once, before its first consumer. These entry
// points keep timer clients out of unrelated Tile and load-buffer protocols.
namespace fnv::timer
{
void Start(unsigned int startupTick);
unsigned int Time();
unsigned int ElapsedSince(unsigned int timestamp);
unsigned int TimestampFromElapsed(unsigned int elapsed);
float Seconds();
float RealSeconds();
float UnmodifiedSeconds();
bool SecondsAreZero();
void Update();
void Update(unsigned int tick, void (*sleep)(unsigned int));
void Pause();
void Pause(unsigned int tick);
void Resume();
void Resume(unsigned int tick);
void SetFrequency(unsigned int frequency);
void SetUseGlobalMultiplierTarget(bool useTarget);
void SetMultiplier(float multiplier, bool immediate);
void RestoreMultiplier();
}

#endif
