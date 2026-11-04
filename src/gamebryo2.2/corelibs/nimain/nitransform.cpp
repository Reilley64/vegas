// gamebryo2.2/corelibs/nimain/nitransform.cpp: NiTransform, Transform3D, TransformSaver (4 functions)
#include "fnv/decl/FUN_00a59a90_cls.h"
#include "fnv/decl/NiPlane.h"
#include "fnv/decl/S_00a59a30_Matrix3.h"
#include "nitransform_decls.h"
// @fnv 0x00a86bf0
void NiTransform::ResetToIdentity()
{
    m_kOrientation.ResetToIdentity();
    m_kTranslation = NiPoint3::ZERO;
    m_fScale = 1.0f;
}
// @fnv 0x00a86c80
void NiTransform::LoadBinary(NiStream& stream)
{
    reinterpret_cast<::S_00a59a30_Matrix3 *>(&(m_kOrientation))->LoadFromStream((::S_00a59a30_Stream &)(stream));
    reinterpret_cast<::NiColor *>(&(m_kTranslation))->LoadBinary(stream);
    stream.input->Read(&m_fScale);
}

struct TransformMatrix
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
};
struct TransformPoint
{
    float x, y, z;
};
struct Transform3D
{
    TransformMatrix rotation;
    TransformPoint translation;
    float scale;
    unsigned int FUN_00a86c30(const Transform3D& other) const;
};
// @fnv 0x00a86c30
unsigned int Transform3D::FUN_00a86c30(const Transform3D& other) const
{
    if (reinterpret_cast<::ThreeByThreeMatrix *>((void *)&(rotation))->operator==((const ::ThreeByThreeMatrix &)(other.rotation)))
    {
        if (!reinterpret_cast<::NiPlane *>((void *)&(translation))->operator==((const ::NiPlane &)(other.translation)))
        {
            if (scale == other.scale)
                return false;
        }
    }
    return true;
}

struct TransformRotationSaver : ThreeByThreeMatrix
{
};

struct TransformTranslationSaver : NiPoint3
{
};

struct TransformBinaryOutput : NiBinaryStream
{
    void SaveScale(const float* value)
    {
        unsigned int componentSize = sizeof(float);
        position += write(this, value, sizeof(float), &componentSize, 1);
    }
};

struct TransformOutputStream : NiStream
{
    TransformBinaryOutput* output;
};

struct TransformSaver : NiTransform
{
    void FUN_00a86cd0(NiStream& stream);
};

// Writes the orientation, translation, and scale of the transform to the given NiStream.
// @fnv 0x00a86cd0
void TransformSaver::FUN_00a86cd0(NiStream& stream)
{
    reinterpret_cast<::FUN_00a59a90_cls *>(&(static_cast<TransformRotationSaver&>(m_kOrientation)))->ReadMatrixFromStream(&stream);
    reinterpret_cast<::NiColor *>(&(static_cast<TransformTranslationSaver&>(m_kTranslation)))->SaveBinary(stream);
    static_cast<TransformOutputStream&>(stream).output->SaveScale(&m_fScale);
}

#include "generated/data/gamebryo2.2/corelibs/nimain/nitransform.inc"
