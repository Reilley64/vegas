#include "fnv/second_window_check.h"

fnv::startup::SecondWindowOutcome fnv::startup::CheckSecondWindow(const fileformat::MainWindowClass& windowClass,
                                                                  FindWindowFunction findWindow,
                                                                  SetForegroundFunction setForeground)
{
    void* const window = findWindow(windowClass.className.data());
    if (window == nullptr)
        return SecondWindowOutcome::Continue;
    setForeground(window);
    return SecondWindowOutcome::AlreadyOpen;
}
