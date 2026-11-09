#include "GameTimerRecord.h"
#include "fnv/game_timer.h"

int main()
{
    fnv::timer::Start(GameTimerTick());
    return 0;
}
