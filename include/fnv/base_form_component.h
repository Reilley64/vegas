#ifndef FNV_BASE_FORM_COMPONENT_H
#define FNV_BASE_FORM_COMPONENT_H

// BaseFormComponent: the base of TESForm and of the form components. It has
// no data of its own and four virtual functions, slots 0 to 3 of every form
// vftable.
//
// This is the one shared declaration. build/units.json has no function row
// under this class's name, so every slot is OPEN in docs/shared-tesform.md:
// the count and the order are fixed, the names and parameters are the ones
// the copies already agreed on. The vftable that the constructor row
// installs, in src/generated, holds _purecall in all four slots; the copies
// declared the four as not pure, and so does this header.
class BaseFormComponent
{
  public:
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
};

#endif
