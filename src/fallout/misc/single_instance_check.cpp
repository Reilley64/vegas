#include "fnv/single_instance_check.h"

fnv::startup::SingleInstanceOutcome fnv::startup::CheckSingleInstance(const fileformat::SingleInstanceStrings& strings,
                                                                      unsigned long createMutexError,
                                                                      RemoteSessionQuery isRemoteSession,
                                                                      MessageBoxFunction showMessage)
{
    if (createMutexError == mutexAlreadyExistsError)
    {
        showMessage(strings.firstMessageText.data(), strings.messageCaption.data(), singleInstanceMessageType);
        return SingleInstanceOutcome::AlreadyRunning;
    }
    if (isRemoteSession())
    {
        showMessage(strings.secondMessageText.data(), strings.messageCaption.data(), singleInstanceMessageType);
        return SingleInstanceOutcome::RemoteSession;
    }
    return SingleInstanceOutcome::Continue;
}
