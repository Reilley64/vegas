// Gives a call that writes its result through a reference argument a scratch object to write to.
#pragma once

// The default-argument temporary lives until the end of the full expression that contains the call,
// so the returned reference may be used within that expression.
template <class T> T& ResultSlot(T&& slot = T()) { return slot; }
