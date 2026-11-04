#pragma once

struct NewSequence;
struct OldSequence;
template <class> struct SeqPtr;

// 0x00a349e0
void ConvertOldSequence(::OldSequence *, ::SeqPtr< ::NewSequence> &);
