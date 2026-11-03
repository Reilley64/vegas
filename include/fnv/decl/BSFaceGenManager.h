#pragma once

class BSFaceGenModelMap;
struct FaceGenCoordinates;

class BSFaceGenManager {
public:
    // 0x00651b30
    static ::BSFaceGenManager *GetFaceGenManager();
    // 0x00652110
    static ::BSFaceGenModelMap *GetModelMap();
    // 0x006521e0
    static ::FaceGenCoordinates *GetFaceGenCoordinates();
    // 0x006521f0
    static void InitializeFaceGenCoordinates(::FaceGenCoordinates *);
    // 0x00653dc0
    static void ApplyFaceGenValues(float *, unsigned int, bool);
    // 0x00657820
    static char *BuildFaceGenPartPath(char *, int);
};
