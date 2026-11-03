#ifndef BSFACEGENMORPHDATA_DECLS_H
#define BSFACEGENMORPHDATA_DECLS_H

#include <cstring>
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_0065cc30_class.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005dd000.h"
#include "fnv/symbols_0065c000.h"
#include "fnv/symbols_00661000.h"
#include "fnv/symbols_00662000.h"
extern const char DAT_01065e40[];
extern const char DAT_01065dd0[];
extern const char DAT_01065d60[];
extern const char DAT_01065ce8[];
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3(float, float, float);
};
class BGSPerkEntry;
template <class T> class BSSimpleList;
template <> class BSSimpleList<BGSPerkEntry*>
{
  public:
};
class BSFaceGenMorph
{
  public:
    virtual ~BSFaceGenMorph();
    unsigned int data[2];
};
class BSFaceGenMorphDifferential : public BSFaceGenMorph
{
  public:
    BSFaceGenMorphDifferential(unsigned int);
};
class BSFaceGenMorphStatistical : public BSFaceGenMorph
{
  public:
    unsigned int extra;
    BSFaceGenMorphStatistical(unsigned int, unsigned int);
};
template <class T> class FaceGenMatrix
{
  public:
    T* FUN_006578b0(unsigned int) const;
    unsigned int FUN_00662820();
    unsigned int data[4];
};
class MorphName
{
  public:
    unsigned int data[7];
};
class FaceGenTriData;
class DifferentialEntry : public MorphName
{
  public:
    unsigned int vertexData;
};
class StatisticalEntry : public MorphName
{
  public:
    unsigned int columns;
    FaceGenMatrix<float> matrix;
};
class DifferentialArray
{
  public:
    DifferentialEntry* FUN_00662860(unsigned int);
    unsigned int pad[3];
    char* first;
    char* last;
    char* end;
};
class StatisticalArray
{
  public:
    StatisticalEntry* FUN_00662890(unsigned int);
    unsigned int data[6];
};
class FaceGenTriData
{
  public:
    unsigned char prefix[0xc0];
    DifferentialArray differential;
    StatisticalArray statistical;
    NiPoint3& FUN_0065c720(unsigned int);
};
class BSFaceGenMorphData
{
  public:
    BSFaceGenMorphData();
    virtual ~BSFaceGenMorphData();
    unsigned int ref;
};
class BSFaceGenMorphDataHead : public BSFaceGenMorphData
{
  public:
    BSFaceGenMorph** expressions;
    BSFaceGenMorph** modifiers;
    BSFaceGenMorph** phonemes;
    BSFaceGenMorph** custom;
    BSFaceGenMorphDataHead(FaceGenTriData*);
    virtual ~BSFaceGenMorphDataHead();
};
#endif
