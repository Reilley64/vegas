#pragma once

class NiAVObject;
class NiTexture;
class NiTriBasedGeom;
struct FaceGenCoordinates;
template <class> class NiPointer;

class BSFaceGenModel {
public:
    // 0x006530e0
    static ::NiAVObject *GetFaceGenModelNode(::NiAVObject *);
    // 0x0065a760
    bool LoadFaceGenTexture(const char *);
    // 0x0065b410
    bool ApplyTextureCoordinate(::FaceGenCoordinates *, ::NiPointer< ::NiTexture> &, unsigned int);
    // 0x0065bbc0
    bool CloneTriBasedGeom(::NiPointer< ::NiTriBasedGeom> &);
    // 0x0065c2c0
    bool LoadFaceGenTexture();
    // 0x0065c3a0
    void ClearTextureData();
};
