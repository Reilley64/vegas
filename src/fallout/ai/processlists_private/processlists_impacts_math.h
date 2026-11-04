// Unit-private PC declarations from public JohnnyGuitarNVSE layout facts.
// are not used because their padded rows do not describe the PC runtime.
#ifndef FNV_PROCESSLISTS_PRIVATE_IMPACTS_MATH_H
#define FNV_PROCESSLISTS_PRIVATE_IMPACTS_MATH_H

#include "processlists_layout_support.h"
#include "processlists_NiPoint3.h"

// Public BSMemObject has allocation operators only and no state or virtuals.
class BSMemObject
{
};

class ThreeByThreeMatrix : public BSMemObject
{
  public:
    ThreeByThreeMatrix();
    float m_afEntries[3][3];
};

class NiTransform
{
  public:
    NiTransform();
    ThreeByThreeMatrix m_kRotate;
    NiPoint3 m_kTranslate;
    float m_fScale;
};

#endif
