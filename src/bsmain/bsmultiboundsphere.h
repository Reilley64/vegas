// bsmain/bsmultiboundsphere.h: declares BSMultiBoundSphere
#ifndef FNV_BSMULTIBOUNDSHERE_H
#define FNV_BSMULTIBOUNDSHERE_H



class BSMultiBoundSphere
{
  public:
    float GetRadius() const;

  private:
    unsigned char _pad[0x18];
    float m_fSphereRadius;
};


#endif
