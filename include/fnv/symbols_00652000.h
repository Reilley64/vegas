#pragma once

class CoordArray;
class FaceGenCoordArray;
namespace fnv_00652900 { template <class> struct FaceGenMatrix; }
struct FG652_Actor;
struct FG652_Mat;
struct MatrixProxy;

// 0x00652040
namespace fnv_00652040 { bool FUN_00652040(int); }
// 0x00652140
void FUN_00652140();
// 0x00652160
namespace fnv_00652160 { bool FUN_00652160(); }
// 0x00652190
namespace fnv_00652190 { void FUN_00652190(); }
// 0x006521b0
namespace fnv_006521b0 { unsigned int FUN_006521b0(int, int); }
// 0x00652230
float GetMorphCoordinateValue(char *, unsigned int, unsigned int, unsigned int);
// 0x00652320
void FUN_00652320(::FG652_Mat *, int, int, int, float);
// 0x00652440
float FUN_00652440(int, int, int);
// 0x00652470
void FUN_00652470(int, int, int, float);
// 0x00652510
void FUN_00652510(::FG652_Actor *);
// 0x00652900
namespace fnv_00652900 { bool FUN_00652900(const fnv_00652900::FaceGenMatrix<float> (*)[2], fnv_00652900::FaceGenMatrix<float> (*)[2]); }
// 0x006529a0
namespace fnv_006529a0 { void FUN_006529a0(FaceGenCoordArray (*)[2], FaceGenCoordArray (*)[2], bool, bool); }
// 0x00652af0
void FUN_00652af0(CoordArray (*)[2], CoordArray (*)[2], CoordArray (*)[2], bool, float);
// 0x00652e00
void FUN_00652e00(MatrixProxy (*)[2], MatrixProxy (*)[2], MatrixProxy (*)[2], bool);
// 0x00652fc0
void FUN_00652fc0(float, int, int);
