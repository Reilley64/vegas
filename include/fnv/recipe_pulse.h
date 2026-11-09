#ifndef FNV_RECIPE_PULSE_H
#define FNV_RECIPE_PULSE_H

namespace fnv
{
// Recipe UI's brightness state, advanced by the shared game clock.
struct RecipePulse
{
    float brightness;
    unsigned int lastTime;
    unsigned char decreasing;

    void Advance(float minimum, float maximum);
};
}

#endif
