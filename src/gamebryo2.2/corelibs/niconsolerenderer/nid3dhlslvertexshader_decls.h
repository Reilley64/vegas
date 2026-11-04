#ifndef NID3DHLSLVERTEXSHADER_DECLS_H
#define NID3DHLSLVERTEXSHADER_DECLS_H
#include "fnv/symbols_00aa1000.h"
class NiD3DShaderProgramCreatorObj;
template <class T> class NiTArray
{
  public:
    virtual ~NiTArray();
    T* m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
    static T* Allocate(unsigned int count)
    {
        return (T*)::FUN_00aa1070(count * sizeof(T));
    }
    NiTArray(unsigned int size, unsigned short grow) : m_usMaxSize(size), m_usGrowBy(grow)
    {
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
            m_pBase = Allocate(m_usMaxSize);
        else
            m_pBase = 0;
    }
};
template <class T> class NiTPrimitiveArray : public NiTArray<T>
{
  public:
    virtual ~NiTPrimitiveArray();
    NiTPrimitiveArray(unsigned int size, unsigned short grow);
};
#endif
