// bsmain/bsmultiboundsphere.cpp: BSMultiBoundSphere (1 function)


class BSMultiBoundSphere
{
  public:
    float GetRadius() const;

  private:
    unsigned char _pad[0x18];
    float m_fSphereRadius;
};


// @fnv 0x004a7bd0
float BSMultiBoundSphere::GetRadius() const
{
    return m_fSphereRadius;
}
