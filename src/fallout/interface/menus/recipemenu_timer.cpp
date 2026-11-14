#include "GameTimerRecord.h"
#include "fnv/game_timer.h"
#include "fnv/recipe_pulse.h"

// Recipe-menu module ownership, also consumed by frame and spectator timing.
// The complete record is constant-initialized before any dynamic initializer;
// the timer API establishes its epoch once before publishing it to consumers.
constinit GameTimerRecord g_timeGlobal{};

void fnv::RecipePulse::Advance(float minimum, float maximum)
{
    unsigned int now = timer::Time();
    unsigned int elapsed = now - lastTime;
    lastTime = now;
    if (decreasing)
        brightness -= elapsed * 0.25f;
    else
        brightness += elapsed * 0.25f;

    // Preserve the existing max-first clamp, including unordered bounds.
    if (brightness > maximum)
        brightness = maximum;
    else if (brightness < minimum)
        brightness = minimum;
    if (brightness >= maximum)
        decreasing = 1;
    if (brightness <= minimum)
        decreasing = 0;
}
