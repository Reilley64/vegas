#include "GameTimerRecord.h"
#include "fnv/game_timer.h"
#include "fnv/memory/process_startup.h"

int main()
{
    if (!fnv::memory::StartProcessMemory())
        return 1;
    fnv::timer::Start(GameTimerTick());
    return 0;
}
