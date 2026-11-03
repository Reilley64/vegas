// include/havok/hkpApplyForcesStep.h - argument wrappers of the integrate-motions step FUN_00d28a30.
#pragma once

namespace ApplyForcesStepPrivate {
struct Motion;

// Pointer passed by value.
template <class T> struct Ref
{
    T* p;
    T* operator->() const
    {
        return p;
    }
    operator T*() const
    {
        return p;
    }
};

// Cursor over the motion pointers of an island.
struct MotionList
{
    Motion** p;
    Motion* operator*() const
    {
        return *p;
    }
    void next()
    {
        ++p;
    }
};
}  // namespace ApplyForcesStepPrivate
