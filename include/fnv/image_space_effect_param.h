#ifndef FNV_IMAGE_SPACE_EFFECT_PARAM_H
#define FNV_IMAGE_SPACE_EFFECT_PARAM_H

// ImageSpaceEffectParam: four floats and the constructor that stores them.
//
// This is the one shared declaration of the class that build/units.json
// names at 0x00414430. It declares the one member that has a function row
// under the class's name with a body in its owning unit. The header has no
// body: src/bsshader/imagespaceeffectparam_h_unit.cpp defines the
// constructor and is the only unit that may.
//
// Units use these four floats as a colour. Other four-float classes, such as
// a rectangle and a rotation, share the folded constructor address, and
// other classes are declared under this name too. Read
// docs/shared-image-space-effect-param.md before moving a unit onto this
// header.
struct ImageSpaceEffectParam
{
  public:
    float r, g, b, a;
    ImageSpaceEffectParam(float red, float green, float blue, float alpha); // 0x00414430
};

#endif
