// havok/physics/constraintsolver/solve/hkpsolver.cpp: free functions (5 functions)

#include <xmmintrin.h>
#include "fnv/symbols_011b9000.h"
#include "fnv_asm_helpers.h"
// src/havok/physics/constraintsolver/solve/hkpsolver.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/solve/hkpsolver.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00d921d0
int __cdecl FUN_00d921d0(const signed char* index)
{
    return DAT_011b9434[*index];
}



// Adds the lowest single-precision float of b to that of a and stores the result in out.
// @fnv 0x00c6cce0
extern "C" void __cdecl AddScalarFloat(__m128* pResult, const __m128* pLeft, const __m128* pRight)
{
    *pResult = _mm_add_ss(*pLeft, *pRight);
}

// @fnv 0x00d921c0
char* __cdecl FUN_00d921c0(char* dst, const char* src)
{
    *dst = *src;
    return dst;
}


// @fnv 0x00c6ccc0
extern "C" void __cdecl SubtractScalarFloat(__m128* pResult, const __m128* pLeft, const __m128* pRight)
{
    *pResult = _mm_sub_ss(*pLeft, *pRight);
}

// FUN_00d892d0: single-ret __cdecl void function. Body is empty; the claimed
// 17-byte extent is 15 int3 padding bytes plus the next function's ret.
// @fnv 0x00d892d0
void FUN_00d892d0()
{
}

// Moved from hkpsolver_gs_nogs_ctx_variant.cpp (VEGAS-15).
#include "fnv/decl/FUN_00c7f750_shell.h"
#include "fnv/symbols_00891000.h"
#include "fnv/symbols_00d89000.h"
#include "fnv/symbols_00d8a000.h"
#include "fnv/symbols_00d92000.h"
#include "fnv/symbols_00df2000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01269000.h"

#include <math.h>
#include "fnv/symbols_simd.h"

// @fnv 0x00d8d030
typedef float hkReal;
typedef __m128 HkQuad;
typedef signed char hkInt8;
typedef unsigned char hkUint8;
typedef short hkInt16;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned __int64 hkUint64;
typedef uintptr_t hkUlong;
typedef intptr_t hkLong;
typedef int HkBool32;
class HkBool{public:inline HkBool(){}inline HkBool(bool b){m_cBooleanValue=static_cast<char>(b);}inline operator bool()const{return m_cBooleanValue!=0;}inline HkBool&operator=(bool e){m_cBooleanValue=static_cast<char>(e);return*this;}inline HkBool operator==(bool e)const{return static_cast<int>(m_cBooleanValue)==static_cast<int>(e);}inline HkBool operator!=(bool e)const{return static_cast<int>(m_cBooleanValue)!=static_cast<int>(e);}private:char m_cBooleanValue;};
class HkHalf{public:inline HkHalf(){}private:hkInt16 m_uiFilterValue;};
template<typename ENUM,typename STORAGE>class HkEnum{public:HkEnum(){}HkEnum(ENUM e){m_kStorage=static_cast<STORAGE>(e);}operator ENUM()const{return static_cast<ENUM>(m_kStorage);}void operator=(ENUM e){m_kStorage=static_cast<STORAGE>(e);}HkBool operator==(ENUM e)const{return m_kStorage==static_cast<STORAGE>(e);}HkBool operator!=(ENUM e)const{return m_kStorage!=static_cast<STORAGE>(e);}private:STORAGE m_kStorage;};
template<typename TYPE>class HkPad{public:__forceinline HkPad(){}__forceinline HkPad(TYPE e):m_kStorage(e){}__forceinline void operator=(TYPE e){m_kStorage=e;}__forceinline TYPE val()const{return m_kStorage;}__forceinline operator TYPE()const{return val();}private:TYPE m_kStorage;};
template<typename TYPE>__forceinline TYPE*__cdecl addOffset(TYPE*base,hkLong offset){return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base)+offset);}
template<typename TYPE>__forceinline const TYPE*__cdecl addOffsetC(const TYPE*base,hkLong offset){return reinterpret_cast<const TYPE*>(reinterpret_cast<const char*>(base)+offset);}
template<typename TYPE>__forceinline TYPE*__cdecl selectPtr(int select,TYPE*pairA,TYPE*pairB){hkUlong ua=hkUlong(pairA);hkUlong ub=hkUlong(pairB);return reinterpret_cast<TYPE*>(ua^((ua^ub)&(-select)));}
class FUN_005dbf20{public:FUN_005dbf20(const HkQuad&x):m_vValue(x){}FUN_005dbf20(hkReal x){m_vValue=_mm_load_ss(&x);}FUN_005dbf20(){}operator hkReal()const{hkReal s;_mm_store_ss(&s,m_vValue);return s;}__forceinline HkQuad broadcast()const{return _mm_shuffle_ps(m_vValue,m_vValue,0);}__forceinline const HkQuad&getQuad()const{return m_vValue;}__forceinline void setProduct(const FUN_005dbf20&a,const FUN_005dbf20&b){m_vValue=_mm_mul_ss(a.m_vValue,b.m_vValue);}private:HkQuad m_vValue;};
typedef FUN_005dbf20 HkSimd;
typedef const HkSimd&HkSimdP;
__forceinline void hkSimdSetMax(HkSimdP a,HkSimdP b,HkSimd&result){result=HkSimd(_mm_max_ps(a.getQuad(),b.getQuad()));}
__forceinline void hkSimdSetMin(HkSimdP a,HkSimdP b,HkSimd&result){result=HkSimd(_mm_min_ps(a.getQuad(),b.getQuad()));}
__forceinline void hkSimdStore(HkSimdP a,float*f){_mm_store_ss(f,a.getQuad());}
inline HkSimd __cdecl operator*(HkSimdP r,HkSimdP s){return _mm_mul_ss(s.getQuad(),r.getQuad());}
inline HkSimd __cdecl operator-(HkSimdP r,HkSimdP s){return _mm_sub_ss(r.getQuad(),s.getQuad());}
inline HkSimd __cdecl operator+(HkSimdP r,HkSimdP s){return _mm_add_ss(r.getQuad(),s.getQuad());}
inline HkSimd __cdecl operator/(HkSimdP r,HkSimdP s){return _mm_div_ss(r.getQuad(),s.getQuad());}
inline HkSimd __cdecl operator-(HkSimdP r){return _mm_sub_ss(DAT_010c7160,r.getQuad());}
class HkVec4;
typedef const HkVec4&HkVecP;
class HkCmp{public:enum Mask{MASK_NONE=0,MASK_X=1,MASK_Y=2,MASK_XY=3,MASK_Z=4,MASK_XZ=5,MASK_YZ=6,MASK_XYZ=7,MASK_W=8,MASK_XW=9,MASK_YW=10,MASK_XYW=11,MASK_ZW=12,MASK_XZW=13,MASK_YZW=14,MASK_XYZW=15};__forceinline HkBool32 allAreSet(Mask m)const{return(_mm_movemask_ps(m_uiMask)&m)==m;}__forceinline int GetLaneMask()const{return _mm_movemask_ps(m_uiMask);}private:HkQuad m_uiMask;friend class HkVec4;};
class HkMat3;
class HkVec4{public:__forceinline void multiplyQuad(const HkQuad&value){m_vComponents=_mm_mul_ps(m_vComponents,value);}__forceinline void operator=(HkVecP v);__forceinline void operator=(const HkQuad&v);__forceinline void setAll3(hkReal x);__forceinline void setZero4();__forceinline void add4(HkVecP a);__forceinline void add3clobberW(HkVecP a);__forceinline void setAdd4(HkVecP a,HkVecP b);__forceinline void sub3clobberW(HkVecP a);__forceinline void setSub4(HkVecP a,HkVecP b);__forceinline void mul4(HkVecP a);__forceinline void setMul4(HkVecP a,HkVecP b);__forceinline void mul4(HkSimdP a);__forceinline void setMul4(HkSimdP r,HkVecP a);__forceinline void addMul4(HkSimdP r,HkVecP a);__forceinline void subMul4(HkSimdP r,HkVecP a);__forceinline HkCmp compareLessThan4(HkVecP a)const;__forceinline HkCmp compareEqual4(HkVecP a)const;__forceinline HkCmp compareLessThanEqual4(HkVecP a)const;__forceinline void setAbs4(HkVecP v);__forceinline HkSimd dot3(HkVecP a)const;__forceinline HkSimd horizontalAdd3()const;__forceinline HkSimd lengthInverse3()const;__forceinline HkSimd normalizeWithLength3();__forceinline hkReal&operator()(int i);__forceinline const hkReal&operator()(int i)const;__forceinline HkSimd getSimdAt(int i)const;__forceinline void setBroadcast(HkVecP v,int i);__forceinline void sB3W(HkVecP v,int i);__forceinline static HkVecP __cdecl getZero();__forceinline HkSimd s3(int i)const{switch(i){case 0:return m_vComponents;case 1:return _mm_shuffle_ps(m_vComponents,m_vComponents,0xff);case 2:return _mm_shuffle_ps(m_vComponents,m_vComponents,0xff);case 3:default:return _mm_shuffle_ps(m_vComponents,m_vComponents,0xff);}}private:HkQuad m_vComponents;public:operator HkQuad()const{return m_vComponents;}};
inline void HkVec4::operator=(HkVecP v){m_vComponents=v.m_vComponents;}inline void HkVec4::operator=(const HkQuad&v){m_vComponents=v;}inline void HkVec4::setAll3(hkReal a){m_vComponents=_mm_set_ps1(a);}inline void HkVec4::setZero4(){m_vComponents=_mm_setzero_ps();}inline void HkVec4::add4(HkVecP v){m_vComponents=_mm_add_ps(m_vComponents,v.m_vComponents);}inline void HkVec4::add3clobberW(HkVecP v){m_vComponents=_mm_add_ps(m_vComponents,v.m_vComponents);}inline void HkVec4::setAdd4(HkVecP v0,HkVecP v1){m_vComponents=_mm_add_ps(v0.m_vComponents,v1.m_vComponents);}inline void HkVec4::sub3clobberW(HkVecP v){m_vComponents=_mm_sub_ps(m_vComponents,v.m_vComponents);}inline void HkVec4::setSub4(HkVecP v0,HkVecP v1){m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);}inline void HkVec4::mul4(HkVecP v){m_vComponents=_mm_mul_ps(m_vComponents,v.m_vComponents);}inline void HkVec4::setMul4(HkVecP a,HkVecP b){m_vComponents=_mm_mul_ps(a.m_vComponents,b.m_vComponents);}inline void HkVec4::mul4(HkSimdP s){m_vComponents=_mm_mul_ps(s.broadcast(),m_vComponents);}inline void HkVec4::setMul4(HkSimdP r,HkVecP v1){m_vComponents=_mm_mul_ps(r.broadcast(),v1.m_vComponents);}inline void HkVec4::addMul4(HkSimdP r,HkVecP v1){m_vComponents=_mm_add_ps(m_vComponents,_mm_mul_ps(r.broadcast(),v1.m_vComponents));}inline void HkVec4::subMul4(HkSimdP r,HkVecP v1){m_vComponents=_mm_sub_ps(m_vComponents,_mm_mul_ps(r.broadcast(),v1.m_vComponents));}inline HkCmp HkVec4::compareLessThan4(HkVecP a)const{HkCmp m;m.m_uiMask=_mm_cmplt_ps(m_vComponents,a.m_vComponents);return m;}inline HkCmp HkVec4::compareEqual4(HkVecP a)const{HkCmp m;m.m_uiMask=_mm_cmpeq_ps(m_vComponents,a.m_vComponents);return m;}inline HkCmp HkVec4::compareLessThanEqual4(HkVecP a)const{HkCmp m;m.m_uiMask=_mm_cmple_ps(m_vComponents,a.m_vComponents);return m;}inline void HkVec4::setAbs4(HkVecP v){m_vComponents=_mm_and_ps(v.m_vComponents,DAT_01017d10);}inline HkSimd HkVec4::dot3(HkVecP a)const{HkQuad x2=_mm_mul_ps(m_vComponents,a.m_vComponents);HkQuad xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,0x55),x2);return _mm_add_ss(_mm_shuffle_ps(x2,x2,0xaa),xySum);}inline HkSimd HkVec4::horizontalAdd3()const{HkQuad xySum=_mm_add_ss(_mm_shuffle_ps(m_vComponents,m_vComponents,0x55),m_vComponents);return _mm_add_ss(_mm_shuffle_ps(m_vComponents,m_vComponents,0xaa),xySum);}inline HkSimd HkVec4::lengthInverse3()const{const HkQuad half=_mm_set_ss(0.5f);const HkQuad three=_mm_set_ss(3.0f);const HkQuad zero=_mm_set_ss(0.0f);const HkQuad len2=this->dot3(*this).getQuad();const HkQuad len2EqualsZero=_mm_cmpeq_ss(len2,zero);const HkQuad approx=_mm_rsqrt_ss(len2);const HkQuad refined=_mm_mul_ss(_mm_mul_ss(half,approx),_mm_sub_ss(three,_mm_mul_ss(_mm_mul_ss(len2,approx),approx)));return _mm_andnot_ps(len2EqualsZero,refined);}inline HkSimd HkVec4::normalizeWithLength3(){HkQuad len2=this->dot3(*this).getQuad();HkQuad lenInv=lengthInverse3().broadcast();m_vComponents=_mm_mul_ps(lenInv,m_vComponents);return _mm_mul_ss(len2,lenInv);}inline hkReal&HkVec4::operator()(int a){return reinterpret_cast<hkReal*>(&m_vComponents)[a];}inline const hkReal&HkVec4::operator()(int a)const{return reinterpret_cast<const hkReal*>(&m_vComponents)[a];}inline HkSimd HkVec4::getSimdAt(int i)const{switch(i){case 0:return m_vComponents;case 1:return _mm_shuffle_ps(m_vComponents,m_vComponents,0x55);case 2:return _mm_shuffle_ps(m_vComponents,m_vComponents,0xaa);case 3:default:return _mm_shuffle_ps(m_vComponents,m_vComponents,0xff);}}inline void HkVec4::setBroadcast(HkVecP v,int i){if(i==0){m_vComponents=_mm_shuffle_ps(v.m_vComponents,v.m_vComponents,0x00);}else if(i==1){m_vComponents=_mm_shuffle_ps(v.m_vComponents,v.m_vComponents,0x55);}else if(i==2){m_vComponents=_mm_shuffle_ps(v.m_vComponents,v.m_vComponents,0xaa);}else if(i==3){m_vComponents=_mm_shuffle_ps(v.m_vComponents,v.m_vComponents,0xff);}}inline void HkVec4::sB3W(HkVecP v,int i){setBroadcast(v,i);}inline HkVecP __cdecl HkVec4::getZero(){return (*reinterpret_cast<::HkVec4 *>(&::DAT_01267e30));}class HkMat3{public:__forceinline HkVec4&getColumn(int i);__forceinline HkVecP getColumn(int i)const;protected:HkVec4 m_kColumn0;HkVec4 m_kColumn1;HkVec4 m_kColumn2;};
inline HkVec4&HkMat3::getColumn(int x){return(&m_kColumn0)[x];}
inline HkVecP HkMat3::getColumn(int x)const{return(&m_kColumn0)[x];}
class HkRot:public HkMat3{};
class HkXform{public:__forceinline static const HkXform&__cdecl GetIdentityTransform();__forceinline HkVecP getColumn(int i)const;protected:HkRot m_rotation;HkVec4 m_vTranslation;};
const HkXform&__cdecl HkXform::GetIdentityTransform(){return (*reinterpret_cast<::HkXform *>(&::DAT_01268370));}
HkVecP HkXform::getColumn(int x)const{return m_rotation.getColumn(x);}
namespace HkMath{inline hkReal __cdecl sqrt(hkReal r){return::sqrtf(r);}inline hkReal __cdecl sqrtInverse(hkReal r){return 1.0f/HkMath::sqrt(r);}inline hkReal __cdecl fabs(hkReal r){return::fabsf(r);}template<typename T>inline T __cdecl min2(T x,T y){return x<y?x:y;}}
namespace HkVecUtil{__forceinline void reserveRegisters(hkUint32 registerMask);__forceinline void releaseRegisters(hkUint32 registerMask);}
__forceinline void HkVecUtil::reserveRegisters(hkUint32 registerMask){}
__forceinline void HkVecUtil::releaseRegisters(hkUint32 registerMask){}
class SResults;
class SAccum{public:enum RigidBodyType{HK_RIGID_BODY,HK_KEYFRAMED_RIGID_BODY,HK_NO_GRAVITY_RIGID_BODY,HK_END};HkEnum<RigidBodyType,hkUint8>m_type;hkUint32 m_uiDeactivationClass;hkReal m_fGravityFactor;HkVec4 linVel;HkVec4 angVel;HkVec4 invMass;__forceinline void massProduct(HkSimdP r,HkVec4&out)const{out.setMul4(r,invMass);}__forceinline void addAngularProduct(HkVecP value){angVel.add3clobberW(value);}__forceinline void slowAngularVelocity(HkSimdP factor){angVel.mul4(factor);}__forceinline void addCenterVelocity(HkVecP delta){linVel.add4(delta);}HkVec4&getSumLinearVel(){return getScratch0();}HkVec4&getSumAngularVel(){return getScratch1();}HkVecP getSumLinearVel()const{return getScratch0();}HkVecP getSumAngularVel()const{return getScratch1();}HkVec4&getScratch0(){return m_vCenterOfMass;}HkVec4&getScratch1(){return m_kCoreFromWorldMatrix.getColumn(0);}HkVecP getScratch0()const{return m_vCenterOfMass;}HkVecP getScratch1()const{return m_kCoreFromWorldMatrix.getColumn(0);}public:HkVec4 m_vCenterOfMass;HkRot m_kCoreFromWorldMatrix;};
struct SInfo{struct FloatAndHalfRecord{float m_fFirstFloat;float m_fSecondFloat;float m_fThirdValue;float m_fFourthFloat;float m_afFloatPair[2];HkHalf m_ahHalfPair[2];};__declspec(align(16))float m_iCachedVertexCount;float m_fTau;float m_fMotorDamping;float m_fPostDampingParameter;HkVec4 m_kGravity;HkVec4 m_kSecondSolverVector;HkVec4 m_kTimeStep;HkVec4 GetTimeStepFactor;float m_fFirstTrailingParameter;float m_fSecondTrailingParameter;float m_fThirdTrailingParameter;float m_fFourthTrailingParameter;float m_fContactRestingVelocity;FloatAndHalfRecord m_kDeactivationClassInfo[6];float m_fTimeStep;float m_fInverseDeltaTime;int m_iToiEventCount;int m_iMicroStepCount;float m_fInverseMicroStepCount;float m_fInverseStepCount;HkBool m_bForceCoherentConstraintOrderingInSolver;hkUint8 m_ucDeactivationInactiveFrameSelectFlags[2];hkUint8 m_ucDeactivationIntegrateCounter;float m_fMaxConstraintViolationSquared;};
struct SMotor{hkReal m_fMinimumForce;hkReal m_fMaximumForce;hkReal m_fVelocity;hkReal m_fTau;hkReal m_fMotorDamping;};
struct SElem{union{hkReal impulse;hkReal usedFactor;hkReal m_fAccumulatedMotorRhs;};};
class Jac2A{public:HkVec4 m_kAngularVelocity[2];__forceinline hkReal getInvJacDiag()const{return m_kAngularVelocity[0](3);}__forceinline HkSimd getInvJacDiagSr()const{return m_kAngularVelocity[0].getSimdAt(3);}__forceinline hkReal getAngularRhs()const{return m_kAngularVelocity[1](3);}__forceinline HkSimd getAngularRhsSr()const{return m_kAngularVelocity[1].getSimdAt(3);}__forceinline HkSimd a3()const{return m_kAngularVelocity[1].s3(3);}};
class Jac1L2A{public:HkVec4 m_kLinearJacobian;HkVec4 m_kAngularVelocity[2];__forceinline const hkReal&getRHS()const{return m_kLinearJacobian(3);}__forceinline const HkSimd getRhsSr()const{return m_kLinearJacobian.getSimdAt(3);}__forceinline hkReal getInvJacDiag()const{return m_kAngularVelocity[0](3);}__forceinline HkSimd getInvJacDiagSr()const{return m_kAngularVelocity[0].getSimdAt(3);}__forceinline hkReal getUserValue()const{return m_kAngularVelocity[1](3);}__forceinline HkSimd getUserValueSr()const{return m_kAngularVelocity[1].getSimdAt(3);}};
class Jac2L2A{public:HkVec4 m_kTranslationalVelocity[2];HkVec4 m_kAngularVelocity[2];__forceinline HkSimd getRhsSr()const{return m_kTranslationalVelocity[0].getSimdAt(3);}__forceinline HkSimd getInvJacDiagSr()const{return m_kAngularVelocity[0].getSimdAt(3);}};
class JacDouble{public:Jac1L2A m_kFirstFrictionJacobian;Jac1L2A m_kSecondFrictionJacobian;};
class JacTriple{public:Jac1L2A m_kFirstFrictionJacobian;Jac1L2A m_kSecondFrictionJacobian;Jac2A m_kAngularJacobian;};
class JSchema{public:enum SolverSchemaType{SCHEMA_TYPE_END=0,SCHEMA_TYPE_HEADER,SCHEMA_TYPE_GOTO,SCHEMA_TYPE_SHIFT_SOLVER_RESULTS_POINTER,SCHEMA_TYPE_SIMPLE_BEGIN,SCHEMA_TYPE_1D_BILATERAL,SCHEMA_TYPE_1D_BILATERAL_WITH_IMPULSE_LIMIT,SCHEMA_TYPE_1D_BILATERAL_USER_TAU,SCHEMA_TYPE_1D_LINEAR_LIMITS,SCHEMA_TYPE_1D_FRICTION,SCHEMA_TYPE_1D_LINEAR_MOTOR,SCHEMA_TYPE_1D_PULLEY,SCHEMA_TYPE_1D_ANGULAR,SCHEMA_TYPE_1D_ANGULAR_LIMITS,SCHEMA_TYPE_1D_ANGULAR_FRICTION,SCHEMA_TYPE_1D_ANGULAR_MOTOR,SCHEMA_TYPE_SINGLE_CONTACT,SCHEMA_TYPE_SINGLE_CONTACT_WITH_ACCESSOR_CHECK,SCHEMA_TYPE_SINGLE_LIMIT_CONTACT,SCHEMA_TYPE_SINGLE_LIMIT_CONTACT_WITH_ACCESSOR_CHECK,SCHEMA_TYPE_PAIR_CONTACT,SCHEMA_TYPE_PAIR_CONTACT_WITH_ACCESSOR_CHECK,SCHEMA_TYPE_2D_FRICTION,SCHEMA_TYPE_3D_FRICTION,SCHEMA_TYPE_2D_ROLLING_FRICTION,SCHEMA_TYPE_SET_MASS,SCHEMA_TYPE_ADD_VELOCITY,SCHEMA_TYPE_SET_CENTER_OF_MASS,SCHEMA_TYPE_SIMPLE_END,SCHEMA_TYPE_STIFF_SPRING_CHAIN,SCHEMA_TYPE_BALL_SOCKET_CHAIN,SCHEMA_TYPE_POWERED_CHAIN,SCHEMA_TYPE_MAX};typedef HkEnum<SolverSchemaType,hkInt8>JointSchemaType;static inline JointSchemaType __cdecl FUN_00d921c0(const JSchema*schema){return*reinterpret_cast<const JointSchemaType*>(addOffsetC(schema,0));}static inline int __cdecl FUN_00d921d0(const JSchema*schema){JointSchemaType type=(*(::HkEnum< ::JSchema::SolverSchemaType, signed char> *)(::FUN_00d921c0((char *)(schema), {})));const int numSolverElemTemps=DAT_011b9434[type];return numSolverElemTemps;}};
class SConstraint;
class JsHeader{public:hkUint8 m_ucHeaderByte;hkUint8 m_ucSecondHeaderByte;hkUint16 m_usHeaderWord;hkUint16 m_usBodyAAccumulatorIndex;hkUint16 m_usBodyBAccumulatorIndex;SResults*m_solverResultInMainMemory;SConstraint*m_pConstraintChainInstance;__forceinline SAccum*getBodyA(SAccum*accums)const{return addOffset(accums,m_usBodyAAccumulatorIndex*sizeof(SAccum));}__forceinline SAccum*getBodyB(SAccum*accums)const{return addOffset(accums,m_usBodyBAccumulatorIndex*sizeof(SAccum));}};
class JsGoto{public:hkUint32 m_ucHeaderByte;hkUint32 m_offset;hkUint32 m_padding1_0;hkUint32 m_padding1_1;};
class JsShift{public:hkUint32 m_uiSolverResultPointerOffset;hkUint8 m_ucSolverResultCount;hkUint32 m_padding2_0;hkUint32 m_padding2_1;};
class JsBil{public:Jac1L2A m_pJacobian;};
class JsBilTau{public:Jac1L2A m_pJacobian;hkReal m_fTau;hkReal m_fMotorDamping;hkReal m_padding_0;hkReal m_uiSolverResultPointerOffset;};
class JsLinLim{public:Jac1L2A m_pJacobian;hkReal m_fLowerLimit;hkReal m_fUpperLimit;hkReal m_padding_0;hkReal m_uiSolverResultPointerOffset;};
class JsFric{public:Jac1L2A m_pJacobian;hkReal m_usFlags;hkReal m_padding_0;hkReal m_uiSolverResultPointerOffset;hkReal m_padding_2;};
class JsLinMot{public:Jac1L2A m_pJacobian;SMotor m_kMotorInfo;hkReal m_padding_0;hkReal m_uiSolverResultPointerOffset;hkReal m_padding_2;};
class JsPulley{public:Jac2L2A m_pJacobian;};
class JsAng{public:Jac2A m_pJacobian;};
class JsAngLim{public:Jac2A m_pJacobian;hkReal m_fLowerLimit;hkReal m_fUpperLimit;hkReal m_fTau;hkReal m_ucUnknownByte;};
class JsAngFric{public:Jac2A m_pJacobian;hkReal m_usFlags;hkReal m_padding_0;hkReal m_uiSolverResultPointerOffset;hkReal m_padding_2;};
class JsAngMot{public:Jac2A m_pJacobian;SMotor m_kMotorInfo;hkReal m_padding_0;hkReal m_uiSolverResultPointerOffset;hkReal m_padding_2;};
class JsContact{public:Jac1L2A m_pJacobian;};
class JsPair{public:JacDouble m_pJacobian;hkReal m_fOffDiagonal;hkReal m_padding_0;hkReal m_uiSolverResultPointerOffset;hkReal m_padding_2;};
class JsFric2{public:JacDouble m_pJacobian;hkReal m_fOffDiagonal;hkReal m_usFlags;SResults*m_pSolverResults;hkReal m_fValueAfterSolverResults;};
class JsFric3{public:JacTriple m_pJacobian;hkReal m_fOffDiagonal;hkReal m_usFlags;hkReal m_fAngularImpulseFactor;SResults*m_pSolverResults;};
class JsRoll{public:Jac2A m_kFirstFrictionJacobian;Jac2A m_kSecondFrictionJacobian;hkReal m_usFlags;SResults*m_pSolverResults;HkHalf m_hRollingFrictionValue;HkHalf m_usHeaderWord;hkUint32 m_uiRollingFrictionData;};
class JsMass{public:HkVec4 m_vInverseMassA;HkVec4 m_vInverseMassB;};
class JsAddVel{public:HkVec4 m_vVelocityChange;int m_iBodyIndex;hkUint32 m_padding_0;hkUint32 m_uiSolverResultPointerOffset;hkUint32 m_padding_2;};
class JsCom{public:HkMat3 m_kAngularToLinearVelocityMatrixA;HkMat3 m_kAngularToLinearVelocityMatrixB;};
class JsSpring{public:hkUint16 m_ucUnknownByte;hkUint16 m_iConstraintCount;hkUint32 m_iElementCount;hkReal m_fTau;hkReal m_fMotorDamping;};
class JsBall{public:hkUint16 m_ucUnknownByte;hkUint16 m_iConstraintCount;hkUint32 m_iElementCount;hkReal m_fTau;hkReal m_fMotorDamping;};
class JsPowered{public:hkUint32 m_uiChainHeaderValue;hkUint16 m_iConstraintCount;union{hkUint8*m_pConstraintData;hkUint64 m_usHeaderWord;};hkUint32 m_iElementCount;hkReal m_fPoweredChainParameter;hkReal m_fTau;hkReal m_fMotorDamping;};
__declspec(noinline)HkSimd __cdecl AddScalarFloat(HkSimdP a,HkSimdP b){return _mm_add_ss(a.getQuad(),b.getQuad());}
namespace SolverNs{struct SolverStepInfo{HkPad<int>m_iStep;HkPad<hkReal>m_fStepFactor;};}
extern"C"{}
extern const HkQuad DAT_010d3da0;
void hkDebugPrintfAccumulators(int step,const SInfo&info,SAccum*accumulators,SAccum*accumulatorsEnd){}
static void createSolverDebugOstream(){}
namespace SolverNs {
__forceinline void loadFixedRegisters(){}
__forceinline void loadVelocityAccumulators(const SAccum&mA,const SAccum&mB){HkVecUtil::reserveRegisters(0xffff0000);}
inline void __cdecl storeVelocityAccumulators(SAccum&mA,SAccum&mB){HkVecUtil::releaseRegisters(0xffff0000);}
__forceinline void prefetchVelocityAccumulators(SAccum&mA,SAccum&mB){}
__forceinline void storeDelayedResult(SElem*delayedResult){}
__forceinline HkSimd getLinearDv0UserTauWithCustomRhs(const Jac1L2A&jac,const SAccum&mA,const SAccum&mB,const SInfo&info,hkReal tau,hkReal damping,hkReal customRhs){HkVec4 vel4;{HkVec4 linVelA;linVelA.setSub4(mA.linVel,mA.getSumLinearVel());HkVec4 angVelA;angVelA.setSub4(mA.angVel,mA.getSumAngularVel());HkVec4 linVelB;linVelB.setSub4(mB.linVel,mB.getSumLinearVel());HkVec4 angVelB;angVelB.setSub4(mB.angVel,mB.getSumAngularVel());HkVec4 c;c.setSub4(linVelA,linVelB);HkVec4 a;a.setMul4(angVelA,jac.m_kAngularVelocity[0]);HkVec4 b;b.setMul4(angVelB,jac.m_kAngularVelocity[1]);c.mul4(jac.m_kLinearJacobian);a.add4(b);vel4.setAdd4(a,c);}HkVec4 svel4;{HkVec4 linVelA=mA.getSumLinearVel();HkVec4 angVelA=mA.getSumAngularVel();HkVec4 linVelB=mB.getSumLinearVel();HkVec4 angVelB=mB.getSumAngularVel();HkVec4 c;c.setSub4(linVelA,linVelB);HkVec4 a;a.setMul4(angVelA,jac.m_kAngularVelocity[0]);HkVec4 b;b.setMul4(angVelB,jac.m_kAngularVelocity[1]);c.mul4(jac.m_kLinearJacobian);a.add4(b);svel4.setAdd4(a,c);}svel4.mul4(info.GetTimeStepFactor(0)*tau);vel4.mul4(damping);HkVec4 rhsUpdate;rhsUpdate.setAdd4(svel4,vel4);hkReal ru=rhsUpdate.horizontalAdd3();return customRhs*tau-ru;}
__forceinline HkSimd getLinearDv0UserTau(const Jac1L2A&jac,const SAccum&mA,const SAccum&mB,const SInfo&info,hkReal tau,hkReal damping){return getLinearDv0UserTauWithCustomRhs(jac,mA,mB,info,tau,damping,jac.getRHS());}
__forceinline HkSimd getAngularDv0UserTauWithCustomRhs(const Jac2A&jac,const SAccum&mA,const SAccum&mB,const SInfo&info,hkReal tau,hkReal damping,hkReal customAngularRhs){HkVec4 vel4;{HkVec4 angVelA;angVelA.setSub4(mA.angVel,mA.getSumAngularVel());HkVec4 angVelB;angVelB.setSub4(mB.angVel,mB.getSumAngularVel());HkVec4 a;a.setMul4(angVelA,jac.m_kAngularVelocity[0]);HkVec4 b;b.setMul4(angVelB,jac.m_kAngularVelocity[1]);vel4.setAdd4(a,b);}HkVec4 svel4;{HkVec4 angVelA=mA.getSumAngularVel();HkVec4 angVelB=mB.getSumAngularVel();HkVec4 a;a.setMul4(angVelA,jac.m_kAngularVelocity[0]);HkVec4 b;b.setMul4(angVelB,jac.m_kAngularVelocity[1]);svel4.setAdd4(a,b);}svel4.mul4(info.GetTimeStepFactor(0)*tau);vel4.mul4(damping);HkVec4 rhsUpdate;rhsUpdate.setAdd4(svel4,vel4);hkReal ru=rhsUpdate.horizontalAdd3();hkReal dv=customAngularRhs*tau-ru;return dv;}
__forceinline HkSimd getAngularDv0UserTau(const Jac2A&jac,const SAccum&mA,const SAccum&mB,const SInfo&info,hkReal tau,hkReal damping){return getAngularDv0UserTauWithCustomRhs(jac,mA,mB,info,tau,damping,jac.getAngularRhs());}
__forceinline void applyImpulse(HkSimdP imp,const Jac1L2A&jac,SAccum&mA,SAccum&mB,SElem&sr){HkVec4 impA;impA.setMul4(imp,mA.invMass);HkVec4 impB;impB.setMul4(imp,mB.invMass);HkVec4 lA;lA.sB3W(impA,3);HkVec4 nB;nB.sB3W(impB,3);lA.mul4(jac.m_kLinearJacobian);nB.mul4(jac.m_kLinearJacobian);mA.linVel.add3clobberW(lA);mB.linVel.sub3clobberW(nB);impA.mul4(jac.m_kAngularVelocity[0]);impB.mul4(jac.m_kAngularVelocity[1]);HkSimd s=sr.impulse;mA.addAngularProduct(impA);mB.angVel.add3clobberW(impB);const HkSimd total=s+imp;hkSimdStore(total,&sr.impulse);}
__forceinline void aF(HkSimdP imp,const Jac1L2A&jac,SAccum&mA,SAccum&mB,SElem&sr){HkVec4 impA;impA.setMul4(imp,mA.invMass);HkVec4 impB;impB.setMul4(imp,mB.invMass);HkVec4 lA;lA.sB3W(impA,3);HkVec4 nB;nB.sB3W(impB,3);lA.mul4(jac.m_kLinearJacobian);nB.mul4(jac.m_kLinearJacobian);mA.linVel.add3clobberW(lA);mB.linVel.sub3clobberW(nB);impA.mul4(jac.m_kAngularVelocity[0]);impB.mul4(jac.m_kAngularVelocity[1]);HkSimd s=sr.impulse;mA.angVel.add3clobberW(impA);mB.angVel.add3clobberW(impB);const HkSimd total=s+imp;hkSimdStore(total,&sr.impulse);}
__forceinline void aF0(HkSimdP imp,const Jac1L2A&jac,SAccum&mA,SAccum&mB,SElem&sr){aF(imp,jac,mA,mB,sr);}
__forceinline void ApplyAngularImpulseToBodies(HkSimdP imp,const Jac2A&jac,SAccum&mA,SAccum&mB,SElem&sr){HkVec4 impA;impA=_mm_mul_ps(imp.broadcast(),reinterpret_cast<const HkQuad&>(mA.invMass));HkVec4 impB;impB.setMul4(imp,mB.invMass);impA.mul4(jac.m_kAngularVelocity[0]);impB.mul4(jac.m_kAngularVelocity[1]);HkSimd s=sr.impulse;mA.angVel.add3clobberW(impA);mB.angVel.add3clobberW(impB);s=s+imp;hkSimdStore(s,&sr.impulse);}
__forceinline HkSimd getLinearDv0(const Jac1L2A&jac,const SAccum&mA,const SAccum&mB,const SInfo&info){HkVec4 c;c.setSub4(mA.linVel,mB.linVel);HkVec4 a;a.setMul4(mA.angVel,jac.m_kAngularVelocity[0]);HkVec4 b;b.setMul4(mB.angVel,jac.m_kAngularVelocity[1]);c.mul4(jac.m_kLinearJacobian);a.add4(b);a.add4(c);const HkSimd vel=a.horizontalAdd3();return jac.getRhsSr()-vel;}
__forceinline void applyImpulse0(HkSimdP imp,const Jac1L2A&jac,SAccum&mA,SAccum&mB,SElem&sr){applyImpulse(imp,jac,mA,mB,sr);}
__forceinline void lateLower(HkSimdP imp,const Jac1L2A&jac,SAccum&mA,SAccum&mB,SElem&sr){HkVec4 impA;impA.setMul4(imp,mA.invMass);HkVec4 impB;impB.setMul4(imp,mB.invMass);HkVec4 lA;lA.sB3W(impA,3);HkVec4 nB;nB.sB3W(impB,3);lA.mul4(jac.m_kLinearJacobian);nB.mul4(jac.m_kLinearJacobian);mA.linVel.add3clobberW(lA);mB.linVel.sub3clobberW(nB);impA.mul4(jac.m_kAngularVelocity[0]);impB.mul4(jac.m_kAngularVelocity[1]);HkSimd s=sr.impulse;mA.angVel.add3clobberW(impA);mB.angVel.add3clobberW(impB);s=s+imp;hkSimdStore(s,&sr.impulse);}
__forceinline void lateLower0(HkSimdP imp,const Jac1L2A&jac,SAccum&a,SAccum&b,SElem&r){lateLower(imp,jac,a,b,r);}
__forceinline void lateUpper(HkSimdP imp,const Jac1L2A&jac,SAccum&mA,SAccum&mB,SElem&sr){HkVec4 impA;impA.setMul4(imp,mA.invMass);HkVec4 impB;impB.setMul4(imp,mB.invMass);HkVec4 lA;lA.sB3W(impA,3);HkVec4 nB;nB.sB3W(impB,3);lA.mul4(jac.m_kLinearJacobian);nB.mul4(jac.m_kLinearJacobian);mA.linVel.add3clobberW(lA);mB.linVel.sub3clobberW(nB);impA.mul4(jac.m_kAngularVelocity[0]);impB.mul4(jac.m_kAngularVelocity[1]);HkSimd s=sr.impulse;HkVecP oldAngular=mA.angVel;mA.angVel.setAdd4(oldAngular,impA);mB.angVel.add3clobberW(impB);s=s+imp;hkSimdStore(s,&sr.impulse);}
__forceinline void lateUpper0(HkSimdP imp,const Jac1L2A&jac,SAccum&a,SAccum&b,SElem&r){lateUpper(imp,jac,a,b,r);}
__forceinline void solve1dLinLimits(const SInfo&info,const SolverStepInfo&temp,const JsLinLim&schema,SAccum&mA,SAccum&mB,SElem*sr,SElem*&delayedResult){hkReal dv=getLinearDv0(schema.m_pJacobian,mA,mB,info);hkReal negAppliedImpulse=-sr->impulse;{hkReal impulse=dv-schema.m_fLowerLimit;impulse=schema.m_pJacobian.getInvJacDiag()*impulse;if(impulse>negAppliedImpulse){lateLower0(impulse,schema.m_pJacobian,mA,mB,*sr);}}{hkReal impulse=dv-schema.m_fUpperLimit;impulse=schema.m_pJacobian.getInvJacDiag()*impulse;if(negAppliedImpulse>impulse){lateUpper0(impulse,schema.m_pJacobian,mA,mB,*sr);}}}
__forceinline HkSimd getAngularDv0(const Jac2A&jac,const SAccum&mA,const SAccum&mB,const SInfo&info){HkVec4 a;a.setMul4(mA.angVel,jac.m_kAngularVelocity[0]);HkVec4 b;b.setMul4(mB.angVel,jac.m_kAngularVelocity[1]);a.add4(b);const HkSimd vel=a.horizontalAdd3();const HkSimd dv=jac.getAngularRhsSr()-vel;return dv;}
__forceinline HkSimd getSimpleAngularDv(const Jac2A&jac,const SAccum&mA,const SAccum&mB,const SInfo&info){HkVec4 a;a.setMul4(mA.angVel,jac.m_kAngularVelocity[0]);HkVec4 b;b.setMul4(mB.angVel,jac.m_kAngularVelocity[1]);a.add4(b);const HkSimd vel=a.horizontalAdd3();return jac.getAngularRhsSr()-vel;}
__forceinline void applyAngularImpulse0(HkSimdP imp,const Jac2A&jac,SAccum&mA,SAccum&mB,SElem&sr){ApplyAngularImpulseToBodies(imp,jac,mA,mB,sr);}
__forceinline void solve1dAngLimits(const SInfo&info,const SolverStepInfo&temp,const JsAngLim&schema,SAccum&mA,SAccum&mB,SElem*sr,SElem*&delayedResult){hkReal dv=getAngularDv0UserTau(schema.m_pJacobian,mA,mB,info,schema.m_fTau,info.m_fMotorDamping);hkReal negAppliedImpulse=-sr->impulse;{hkReal impulse=dv-schema.m_fLowerLimit;impulse=schema.m_pJacobian.getInvJacDiag()*impulse;if(impulse>negAppliedImpulse){applyAngularImpulse0(impulse,schema.m_pJacobian,mA,mB,*sr);return;}}{hkReal impulse=dv-schema.m_fUpperLimit;impulse=schema.m_pJacobian.getInvJacDiag()*impulse;if(negAppliedImpulse>impulse){applyAngularImpulse0(impulse,schema.m_pJacobian,mA,mB,*sr);}}}
__forceinline void addImpulseQuad(HkQuad&dst,const HkQuad&src){dst=_mm_add_ps(dst,src);}
__forceinline void latePlain(HkSimdP imp,const Jac1L2A&jac,SAccum&mA,SAccum&mB,SElem&sr){HkVec4 impB;impB.setMul4(imp,mB.invMass);HkVec4 impA;impA.setMul4(imp,mA.invMass);HkVec4 lA;lA.sB3W(impA,3);HkVec4 nB;nB.sB3W(impB,3);lA.mul4(jac.m_kLinearJacobian);nB.mul4(jac.m_kLinearJacobian);mA.linVel.add3clobberW(lA);mB.linVel.sub3clobberW(nB);HkVec4&angularB=mB.angVel;impA.mul4(jac.m_kAngularVelocity[0]);impB.mul4(jac.m_kAngularVelocity[1]);HkSimd s=sr.impulse;addImpulseQuad(reinterpret_cast<HkQuad&>(mA.angVel),reinterpret_cast<const HkQuad&>(impA));angularB.add3clobberW(impB);s=s+imp;hkSimdStore(s,&sr.impulse);}
__forceinline void latePlain0(HkSimdP imp,const Jac1L2A&jac,SAccum&a,SAccum&b,SElem&r){latePlain(imp,jac,a,b,r);}
__forceinline void solve1dBilateral(const SInfo&info,const SolverStepInfo&temp,const JsBil&schema,SAccum&mA,SAccum&mB,SElem*sr){const HkSimd vel=getLinearDv0(schema.m_pJacobian,mA,mB,info);const HkSimd impulse=schema.m_pJacobian.getInvJacDiagSr()*vel;latePlain0(impulse,schema.m_pJacobian,mA,mB,*sr);}
__forceinline void lateCap(HkSimdP imp,const Jac1L2A&jac,SAccum&mA,SAccum&mB,SElem&sr){HkVec4 impA;impA.setMul4(imp,mA.invMass);HkVec4 impB;impB.setMul4(imp,mB.invMass);HkVec4 lA;lA.sB3W(impA,3);HkVec4 nB;nB.sB3W(impB,3);lA.mul4(jac.m_kLinearJacobian);nB.mul4(jac.m_kLinearJacobian);mA.linVel.add3clobberW(lA);mB.linVel.sub3clobberW(nB);impA.mul4(jac.m_kAngularVelocity[0]);impB.mul4(jac.m_kAngularVelocity[1]);HkSimd s=sr.impulse;mA.angVel.add3clobberW(impA);mB.angVel.add3clobberW(impB);s=s+imp;hkSimdStore(s,&sr.impulse);}
__forceinline void lateCap0(HkSimdP imp,const Jac1L2A&jac,SAccum&a,SAccum&b,SElem&r){lateCap(imp,jac,a,b,r);}
__forceinline void solve1dBilateralWithImpulseLimit(const SInfo&info,const SolverStepInfo&temp,const JsBil&schema,SAccum&mA,SAccum&mB,SElem*sr){HkSimd vel=getLinearDv0(schema.m_pJacobian,mA,mB,info);HkSimd impulse=schema.m_pJacobian.getInvJacDiagSr()*vel;HkSimd impulseApplied=sr->impulse;HkSimd maxImpulse=schema.m_pJacobian.getUserValueSr();HkSimd minImpulse=-maxImpulse;maxImpulse=maxImpulse-impulseApplied;minImpulse=minImpulse-impulseApplied;hkSimdSetMax(minImpulse,impulse,impulse);hkSimdSetMin(maxImpulse,impulse,impulse);lateCap0(impulse,schema.m_pJacobian,mA,mB,*sr);}
__forceinline void solve1dBilateralUserTau(const SInfo&info,const SolverStepInfo&temp,const JsBilTau&schema,SAccum&mA,SAccum&mB,SElem*sr,SElem*&delayedResult){HkSimd dv=getLinearDv0UserTau(schema.m_pJacobian,mA,mB,info,schema.m_fTau,schema.m_fMotorDamping);HkSimd impulse=schema.m_pJacobian.getInvJacDiagSr()*dv;applyImpulse0(impulse,schema.m_pJacobian,mA,mB,*sr);}
__forceinline void solve1dAngular(const SInfo&info,const SolverStepInfo&temp,const JsAng&schema,SAccum&mA,SAccum&mB,SElem*sr,SElem*&delayedResult){HkSimd dv=getSimpleAngularDv(schema.m_pJacobian,mA,mB,info);HkSimd impulse=schema.m_pJacobian.getInvJacDiagSr()*dv;applyAngularImpulse0(impulse,schema.m_pJacobian,mA,mB,*sr);}
__forceinline void localImpulse(HkSimdP imp,const Jac1L2A&jac,SAccum&mA,SAccum&mB,SElem&sr){HkVec4 impA;impA.setMul4(imp,mA.invMass);HkVec4 impB;impB.setMul4(imp,mB.invMass);HkVec4 lA;lA.sB3W(impA,3);HkVec4 nB;nB.sB3W(impB,3);lA.mul4(jac.m_kLinearJacobian);nB.mul4(jac.m_kLinearJacobian);mA.linVel.add3clobberW(lA);mB.linVel.sub3clobberW(nB);impA.mul4(jac.m_kAngularVelocity[0]);impB.mul4(jac.m_kAngularVelocity[1]);HkSimd s=sr.impulse;mA.angVel.add3clobberW(impA);mB.angVel.add3clobberW(impB);s=s+imp;hkSimdStore(s,&sr.impulse);}
__forceinline void SolveSingleContact(const SInfo&info,const SolverStepInfo&temp,const JsContact&schema,SAccum&mA,SAccum&mB,SElem*sr,SElem*&delayedResult){{const HkSimd dv=getLinearDv0(schema.m_pJacobian,mA,mB,info);HkSimd impulse=schema.m_pJacobian.getInvJacDiagSr()*dv;HkSimd negPreviousImpulse=-HkSimd(sr->impulse);hkSimdSetMax(negPreviousImpulse,impulse,impulse);localImpulse(impulse,schema.m_pJacobian,mA,mB,*sr);}}
__forceinline void boundedAdd(HkQuad&a,const HkQuad&b){a=_mm_add_ps(a,b);}
__forceinline void boundedImpulse(HkSimdP imp,const Jac1L2A&jac,SAccum&mA,SAccum&mB,SElem&sr){HkVec4 impA;impA.setMul4(imp,mA.invMass);HkVec4 impB;impB.setMul4(imp,mB.invMass);HkVec4 lA;lA.sB3W(impA,3);HkVec4 nB;nB.sB3W(impB,3);lA.mul4(jac.m_kLinearJacobian);nB.mul4(jac.m_kLinearJacobian);mA.linVel.add3clobberW(lA);mB.linVel.sub3clobberW(nB);impA.mul4(jac.m_kAngularVelocity[0]);impB.mul4(jac.m_kAngularVelocity[1]);HkSimd s=sr.impulse;boundedAdd(reinterpret_cast<HkQuad&>(mA.angVel),reinterpret_cast<const HkSimd&>(impA).getQuad());mB.angVel.add3clobberW(impB);s=s+imp;hkSimdStore(s,&sr.impulse);}
__forceinline void solveSingleLimitContact(const SInfo&info,const SolverStepInfo&temp,const JsContact&schema,SAccum&mA,SAccum&mB,SElem*sr,SElem*&delayedResult){const HkSimd dv=getLinearDv0(schema.m_pJacobian,mA,mB,info);{HkSimd impulse=schema.m_pJacobian.getInvJacDiagSr()*dv;HkSimd maxImpulse=schema.m_pJacobian.getUserValueSr();HkSimd impulseApplied=sr->impulse;HkSimd negImpApplied=-impulseApplied;maxImpulse=maxImpulse-impulseApplied;hkSimdSetMax(negImpApplied,impulse,impulse);hkSimdSetMin(maxImpulse,impulse,impulse);boundedImpulse(impulse,schema.m_pJacobian,mA,mB,*sr);}}
__forceinline HkSimd getDv2Lin2Ang(const Jac2L2A&jac,const SAccum&mA,const SAccum&mB,const SInfo&info){HkVec4 lA;lA.setMul4(mA.linVel,jac.m_kTranslationalVelocity[0]);HkVec4 lB;lB.setMul4(mB.linVel,jac.m_kTranslationalVelocity[1]);HkVec4 a;a.setMul4(mA.angVel,jac.m_kAngularVelocity[0]);HkVec4 b;b.setMul4(mB.angVel,jac.m_kAngularVelocity[1]);HkVec4 c;c.setSub4(lA,lB);a.add4(b);a.add4(c);HkSimd vel=a.horizontalAdd3();HkSimd dv=jac.getRhsSr()-vel;return dv;}
__forceinline void applyImpulse2Lin2Ang(HkSimdP imp,const Jac2L2A&jac,SAccum&mA,SAccum&mB,SElem&sr){HkVec4 impA;impA.setMul4(imp,mA.invMass);HkVec4 impB;impB.setMul4(imp,mB.invMass);HkVec4 lA;lA.sB3W(impA,3);HkVec4 lB;lB.sB3W(impB,3);HkVecP directionA=jac.m_kTranslationalVelocity[0];HkVecP directionB=jac.m_kTranslationalVelocity[1];lA.setMul4(directionA,lA);lB.setMul4(directionB,lB);mA.linVel.add3clobberW(lA);mB.linVel.sub3clobberW(lB);impA.mul4(jac.m_kAngularVelocity[0]);impB.mul4(jac.m_kAngularVelocity[1]);HkSimd s=sr.impulse;mA.angVel.add3clobberW(impA);mB.angVel.setAdd4(impB,mB.angVel);s=::AddScalarFloat(s,imp);hkSimdStore(s,&sr.impulse);}
__forceinline void solvePulley(const SInfo&info,const JsPulley&schema,SAccum&mA,SAccum&mB,SElem*sr,SElem*&delayedResult){const HkSimd dv=getDv2Lin2Ang(schema.m_pJacobian,mA,mB,info);{HkSimd diagonal=schema.m_pJacobian.getInvJacDiagSr();HkSimd impulse;::FUN_00891060((::Vec4Dst *)(__m128 *)(&const_cast<HkQuad&>(impulse.getQuad())),(::Vec4Src *)(&dv.getQuad()),(::Vec4Src *)(&diagonal.getQuad()));applyImpulse2Lin2Ang(impulse,schema.m_pJacobian,mA,mB,*sr);}}
__forceinline void getDv01(const Jac1L2A*jac,const SAccum&mA,const SAccum&mB,const SInfo&info,HkVec4&velOut){velOut(0)=getLinearDv0(jac[0],mA,mB,info);velOut(1)=getLinearDv0(jac[1],mA,mB,info);}
__forceinline void applyImpulse1(HkSimdP imp,const Jac1L2A&jac,SAccum&mA,SAccum&mB,SElem&sr){applyImpulse(imp,jac,mA,mB,sr);}
__forceinline void applyImpulse01(hkReal imp0,HkSimdP imp1,const Jac1L2A*jacs,SAccum&mA,SAccum&mB,SElem*srs){applyImpulse0(imp0,jacs[0],mA,mB,srs[0]);applyImpulse(imp1,jacs[1],mA,mB,srs[1]);}
__forceinline hkReal getLinearDvSecondPair(const Jac1L2A&jac,const SAccum&mA,const SAccum&mB,const SInfo&info){HkVec4 c;c.setSub4(mA.linVel,mB.linVel);HkVec4 a;a.setMul4(mA.angVel,jac.m_kAngularVelocity[0]);HkVec4 b;b.setMul4(mB.angVel,jac.m_kAngularVelocity[1]);c.mul4(jac.m_kLinearJacobian);a.add4(b);a.add4(c);const HkSimd vel=a.horizontalAdd3();return jac.getRhsSr()-vel;}
__forceinline void getDvSecondPair(const Jac1L2A*jac,const SAccum&mA,const SAccum&mB,const SInfo&info,HkVec4&velOut){velOut(0)=getLinearDvSecondPair(jac[0],mA,mB,info);velOut(1)=getLinearDvSecondPair(jac[1],mA,mB,info);}
__forceinline void pairChain(HkSimdP imp,const Jac1L2A&jac,SAccum&mA,SAccum&mB,SElem&sr,HkVec4&aLinear){HkVec4 impA;impA.setMul4(imp,mA.invMass);HkVec4 impB;impB.setMul4(imp,mB.invMass);HkVec4 lA;lA.sB3W(impA,3);HkVec4 nB;nB.sB3W(impB,3);lA.mul4(jac.m_kLinearJacobian);nB.mul4(jac.m_kLinearJacobian);aLinear.add3clobberW(lA);mB.linVel.sub3clobberW(nB);impA.mul4(jac.m_kAngularVelocity[0]);impB.mul4(jac.m_kAngularVelocity[1]);HkSimd s=sr.impulse;mA.addAngularProduct(impA);mB.angVel.add3clobberW(impB);const HkSimd total=s+imp;hkSimdStore(total,&sr.impulse);}
__forceinline void pairChain0(HkSimdP imp,const Jac1L2A&jac,SAccum&mA,SAccum&mB,SElem&sr){pairChain(imp,jac,mA,mB,sr,mA.linVel);}
__forceinline void pairSum(HkQuad&a,const HkQuad&b){a=_mm_add_ps(a,b);}
__forceinline void pairTail(HkSimdP imp,const Jac1L2A&jac,SAccum&mA,SAccum&mB,SElem&sr){HkVec4 impA;impA.setMul4(imp,mA.invMass);HkVec4 impB;impB.setMul4(imp,mB.invMass);HkVec4 lA;lA.sB3W(impA,3);HkVec4 nB;nB.sB3W(impB,3);lA.mul4(jac.m_kLinearJacobian);nB.mul4(jac.m_kLinearJacobian);mA.linVel.add3clobberW(lA);mB.linVel.sub3clobberW(nB);impA.mul4(jac.m_kAngularVelocity[0]);impB.mul4(jac.m_kAngularVelocity[1]);HkSimd s=sr.impulse;mA.addAngularProduct(impA);pairSum(reinterpret_cast<HkQuad&>(mB.angVel),reinterpret_cast<const HkQuad&>(impB));const HkSimd total=s+imp;hkSimdStore(total,&sr.impulse);}
__forceinline void pairTailStep(HkSimdP impulse,const Jac1L2A&jac,SAccum&a,SAccum&b,SElem&sr){pairTail(impulse,jac,a,b,sr);}
__forceinline void pairChain01(hkReal imp0,HkSimdP imp1,const Jac1L2A*jacs,SAccum&mA,SAccum&mB,SElem*srs){pairChain0(imp0,jacs[0],mA,mB,srs[0]);pairTailStep(imp1,jacs[1],mA,mB,srs[1]);}
__forceinline void solveSecondPair(const SInfo&info,const JsPair&schema,SAccum&mA,SAccum&mB,SElem*sr,SElem*&delayedResult){HkVec4 dv4;getDvSecondPair(&schema.m_pJacobian.m_kFirstFrictionJacobian,mA,mB,info,dv4);const hkReal dv0=dv4(0);const hkReal dv1=dv4(1);const hkReal imp0=schema.m_pJacobian.m_kFirstFrictionJacobian.getUserValue()*dv0+dv1*schema.m_fOffDiagonal;const hkReal imp1=schema.m_pJacobian.m_kSecondFrictionJacobian.getUserValue()*dv1+dv0*schema.m_fOffDiagonal;if(imp0>-sr[0].impulse){if(imp1>-sr[1].impulse){pairChain01(imp0,imp1,&schema.m_pJacobian.m_kFirstFrictionJacobian,mA,mB,sr);}else{checkImp0:HkSimd imp01=schema.m_pJacobian.m_kFirstFrictionJacobian.getInvJacDiagSr()*HkSimd(dv4(0));hkSimdSetMax(-HkSimd(sr[0].impulse),imp01,imp01);pairChain0(imp01,schema.m_pJacobian.m_kFirstFrictionJacobian,mA,mB,sr[0]);}}else{const hkReal imp10=schema.m_pJacobian.m_kSecondFrictionJacobian.getInvJacDiag()*dv1;if(imp10<=-sr[1].impulse){goto checkImp0;}pairTailStep(imp10,schema.m_pJacobian.m_kSecondFrictionJacobian,mA,mB,sr[1]);}}
__forceinline HkVec4 pairVectorSum(HkVecP a,HkVecP b){HkVec4 sum;sum.setAdd4(a,b);return sum;}
__forceinline void firstPairKernel(HkSimdP imp,const Jac1L2A&jac,SAccum&mA,SAccum&mB,SElem&sr){HkVec4 impA;impA=_mm_mul_ps(HkQuad(mA.invMass),imp.broadcast());HkVec4 impB;impB=_mm_mul_ps(HkQuad(mB.invMass),imp.broadcast());HkVec4 lA;lA.sB3W(impA,3);HkVec4 nB;nB.sB3W(impB,3);lA.mul4(jac.m_kLinearJacobian);nB.mul4(jac.m_kLinearJacobian);mA.linVel.add3clobberW(lA);mB.linVel.sub3clobberW(nB);impA.mul4(jac.m_kAngularVelocity[0]);impB.mul4(jac.m_kAngularVelocity[1]);HkSimd s=sr.impulse;mA.angVel=pairVectorSum(mA.angVel,impA);mB.angVel=pairVectorSum(mB.angVel,impB);s=s+imp;hkSimdStore(s,&sr.impulse);}
__forceinline void firstPairImpulse1(HkSimdP imp,const Jac1L2A&jac,SAccum&mA,SAccum&mB,SElem&sr){firstPairKernel(imp,jac,mA,mB,sr);}
__forceinline void firstPairBoth(hkReal imp0,HkSimdP imp1,const Jac1L2A*jacs,SAccum&mA,SAccum&mB,SElem*srs){applyImpulse0(imp0,jacs[0],mA,mB,srs[0]);firstPairImpulse1(imp1,jacs[1],mA,mB,srs[1]);}
__forceinline HkVec4 fallbackSum(HkVecP a,HkVecP b){HkVec4 r;r.setAdd4(a,b);return r;}
__forceinline void fallbackSumKernel(HkSimdP imp,const Jac1L2A&jac,SAccum&mA,SAccum&mB,SElem&sr){HkVec4 impB;impB=_mm_mul_ps(HkQuad(mB.invMass),imp.broadcast());HkVec4 impA;impA=_mm_mul_ps(HkQuad(mA.invMass),imp.broadcast());HkVec4 lA;lA.sB3W(impA,3);HkVec4 nB;nB.sB3W(impB,3);lA.mul4(jac.m_kLinearJacobian);nB.mul4(jac.m_kLinearJacobian);mA.linVel.add3clobberW(lA);mB.linVel.sub3clobberW(nB);impA.setMul4(impA,jac.m_kAngularVelocity[0]);impB.mul4(jac.m_kAngularVelocity[1]);HkSimd s=sr.impulse;mA.angVel=fallbackSum(mA.angVel,impA);mB.angVel=fallbackSum(mB.angVel,impB);s=s+imp;hkSimdStore(s,&sr.impulse);}
__forceinline void solvePairContact(const SInfo&info,const JsPair&schema,SAccum&mA,SAccum&mB,SElem*sr,SElem*&delayedResult){HkVec4 dv4;getDv01(&schema.m_pJacobian.m_kFirstFrictionJacobian,mA,mB,info,dv4);const hkReal dv0=dv4(0);const hkReal dv1=dv4(1);const hkReal imp0=schema.m_pJacobian.m_kFirstFrictionJacobian.getUserValue()*dv0+dv1*schema.m_fOffDiagonal;const hkReal imp1=schema.m_pJacobian.m_kSecondFrictionJacobian.getUserValue()*dv1+dv0*schema.m_fOffDiagonal;if(imp0>-sr[0].impulse){if(imp1>-sr[1].impulse){firstPairBoth(imp0,imp1,&schema.m_pJacobian.m_kFirstFrictionJacobian,mA,mB,sr);}else{checkImp0:HkSimd imp01;imp01.setProduct(HkSimd(dv4(0)),schema.m_pJacobian.m_kFirstFrictionJacobian.getInvJacDiagSr());hkSimdSetMax(-HkSimd(sr[0].impulse),imp01,imp01);fallbackSumKernel(imp01,schema.m_pJacobian.m_kFirstFrictionJacobian,mA,mB,sr[0]);}}else{const hkReal imp10=schema.m_pJacobian.m_kSecondFrictionJacobian.getInvJacDiag()*dv1;if(imp10<=-sr[1].impulse){goto checkImp0;}firstPairImpulse1(imp10,schema.m_pJacobian.m_kSecondFrictionJacobian,mA,mB,sr[1]);}}
__forceinline HkSimd getAngularDv0R(const Jac2A&jac,const SAccum&mA,const SAccum&mB,const SInfo&info){HkVec4 a;a.setMul4(mA.angVel,jac.m_kAngularVelocity[0]);HkVec4 b;b.setMul4(mB.angVel,jac.m_kAngularVelocity[1]);a.add4(b);const HkSimd vel=a.horizontalAdd3();const HkSimd dv=jac.a3()-vel;return dv;}
__forceinline void getDv012(const JacTriple*jac,const SAccum&mA,const SAccum&mB,const SInfo&info,HkVec4&velOut){velOut(0)=getLinearDv0(jac->m_kFirstFrictionJacobian,mA,mB,info);velOut(1)=getLinearDv0(jac->m_kSecondFrictionJacobian,mA,mB,info);velOut(2)=getAngularDv0R(jac->m_kAngularJacobian,mA,mB,info);}
__forceinline void solve3dFriction(const SInfo&info,const JsFric3&schema,SAccum&mA,SAccum&mB,SElem*sr,SElem*&delayedResult){HkVec4 vel4;getDv012(&schema.m_pJacobian,mA,mB,info,vel4);const hkReal dv0=vel4(0);const hkReal dv1=vel4(1);const hkReal dva=vel4(2);hkReal angularImp=schema.m_pJacobian.m_kAngularJacobian.getInvJacDiag()*dva;const hkReal maxSquared=schema.m_usFlags*schema.m_usFlags;hkReal imp0=schema.m_pJacobian.m_kFirstFrictionJacobian.getUserValue()*dv0+dv1*schema.m_fOffDiagonal;hkReal imp1=schema.m_pJacobian.m_kSecondFrictionJacobian.getUserValue()*dv1+dv0*schema.m_fOffDiagonal;hkReal impSquared=imp0*imp0+imp1*imp1+angularImp*angularImp;if(impSquared>maxSquared){hkReal factor=HkMath::sqrtInverse(impSquared)*schema.m_usFlags;imp0*=factor;imp1*=factor;angularImp*=factor;sr[3].usedFactor=factor;}else{sr[3].usedFactor=1.0f;}angularImp*=schema.m_fAngularImpulseFactor;applyImpulse01(imp0,imp1,&schema.m_pJacobian.m_kFirstFrictionJacobian,mA,mB,sr);applyAngularImpulse0(angularImp,schema.m_pJacobian.m_kAngularJacobian,mA,mB,sr[2]);}
__forceinline void selectedImpulse(HkSimdP imp,const Jac1L2A&jac,SAccum&mA,SAccum&mB,SElem&sr){HkVec4 impA;impA.setMul4(imp,mA.invMass);HkVec4 impB;impB.setMul4(imp,mB.invMass);HkVec4 lA;lA.sB3W(impA,3);HkVec4 nB;nB.sB3W(impB,3);lA.mul4(jac.m_kLinearJacobian);nB.mul4(jac.m_kLinearJacobian);mA.linVel.add3clobberW(lA);mB.linVel.sub3clobberW(nB);impA.mul4(jac.m_kAngularVelocity[0]);impB.mul4(jac.m_kAngularVelocity[1]);HkSimd s=sr.impulse;addImpulseQuad(reinterpret_cast<HkQuad&>(mA.angVel),reinterpret_cast<const HkSimd&>(impA).getQuad());addImpulseQuad(reinterpret_cast<HkQuad&>(mB.angVel),reinterpret_cast<const HkSimd&>(impB).getQuad());s=s+imp;hkSimdStore(s,&sr.impulse);}
__forceinline void fricMassKernel(const HkSimd&__restrict imp,const Jac1L2A&jac,SAccum&mA,SAccum&mB,SElem&sr){HkVec4 impA;impA.setMul4(imp,mA.invMass);HkVec4 impB;impB.setMul4(imp,mB.invMass);HkVec4 lA;lA.sB3W(impA,3);HkVec4 nB;nB.sB3W(impB,3);lA.mul4(jac.m_kLinearJacobian);nB.mul4(jac.m_kLinearJacobian);mA.linVel.add3clobberW(lA);mB.linVel.sub3clobberW(nB);impA.mul4(jac.m_kAngularVelocity[0]);impB.mul4(jac.m_kAngularVelocity[1]);HkSimd s=sr.impulse;mA.angVel.add3clobberW(impA);addImpulseQuad(reinterpret_cast<HkQuad&>(mB.angVel),reinterpret_cast<const HkSimd&>(impB).getQuad());const HkSimd total=s+imp;hkSimdStore(total,&sr.impulse);}
__forceinline void fricMassStep(HkSimdP imp,const Jac1L2A&jac,SAccum&mA,SAccum&mB,SElem&sr){fricMassKernel(imp,jac,mA,mB,sr);}
__forceinline void fricMassBoth(hkReal first,HkSimdP second,const Jac1L2A*rows,SAccum&a,SAccum&b,SElem*results){fricMassStep(first,rows[0],a,b,results[0]);selectedImpulse(second,rows[1],a,b,results[1]);}
__forceinline void solve2dFriction(const SInfo&info,const JsFric2&schema,SAccum&mA,SAccum&mB,SElem*sr,SElem*&delayedResult){HkVec4 vel4;getDv01(&schema.m_pJacobian.m_kFirstFrictionJacobian,mA,mB,info,vel4);const hkReal dv0=vel4(0);const hkReal dv1=vel4(1);hkReal imp0=0.0f;hkReal imp1=0.0f;const hkReal maxImpulseReg=schema.m_usFlags;const hkReal maxSquared=maxImpulseReg*maxImpulseReg;imp0=schema.m_pJacobian.m_kFirstFrictionJacobian.getUserValue()*dv0+dv1*schema.m_fOffDiagonal;imp1=schema.m_pJacobian.m_kSecondFrictionJacobian.getUserValue()*dv1+dv0*schema.m_fOffDiagonal;const hkReal impSquared=imp0*imp0+imp1*imp1;if(impSquared>maxSquared){hkReal factor=HkMath::sqrt(maxSquared/impSquared);imp0*=factor;imp1*=factor;sr[2].usedFactor=factor;}else{sr[2].usedFactor=1.0f;}fricMassBoth(imp0,imp1,&schema.m_pJacobian.m_kFirstFrictionJacobian,mA,mB,sr);}
__forceinline void rollingApply(HkSimdP imp,const Jac2A&jac,SAccum&mA,SAccum&mB,SElem&sr){HkVec4 impA;impA.setMul4(imp,mA.invMass);HkVec4 impB;impB.setMul4(imp,mB.invMass);impA.setMul4(jac.m_kAngularVelocity[0],impA);impB.setMul4(jac.m_kAngularVelocity[1],impB);HkSimd s=sr.impulse;mA.angVel.add3clobberW(impA);mB.angVel.add3clobberW(impB);s=s+imp;hkSimdStore(s,&sr.impulse);}
__forceinline HkSimd freshAngular(const Jac2A&jac,const SAccum&mA,const SAccum&mB,const SInfo&info){HkVec4 b;b=jac.m_kAngularVelocity[1];HkVec4 a;a.setMul4(mA.angVel,jac.m_kAngularVelocity[0]);b.mul4(mB.angVel);a.add4(b);const HkSimd vel=a.horizontalAdd3();const HkSimd dv=jac.a3()-vel;return dv;}
__forceinline HkSimd residualOther(const Jac2A&jac,const SAccum&mA,const SAccum&mB,const SInfo&info,HkVecP row0,HkVecP row1){HkVec4 a;a.setMul4(mA.angVel,row0);HkVec4 b;b.setMul4(mB.angVel,row1);a.add4(b);const HkSimd vel=a.horizontalAdd3();const HkSimd dv=jac.getAngularRhsSr()-vel;return dv;}
__forceinline void solve2dRollingFriction(const SInfo&info,const JsRoll&schema,SAccum&mA,SAccum&mB,SElem*sr){const Jac2A&jac0=schema.m_kFirstFrictionJacobian;const Jac2A&jac1=schema.m_kSecondFrictionJacobian;const hkReal dv0=residualOther(jac0,mA,mB,info,jac0.m_kAngularVelocity[0],jac0.m_kAngularVelocity[1]);const hkReal dv1=freshAngular(jac1,mA,mB,info);const hkReal maxImpulseReg=schema.m_usFlags;const hkReal maxSquared=maxImpulseReg*maxImpulseReg;hkReal imp0=jac0.getInvJacDiag()*dv0;hkReal imp1=jac1.getInvJacDiag()*dv1;const hkReal impSquared=imp0*imp0+imp1*imp1;if(impSquared>maxSquared){hkReal factor=HkMath::sqrt(maxSquared/impSquared);imp0*=factor;imp1*=factor;sr[2].usedFactor=factor;}else{sr[2].usedFactor=1.0f;}ApplyAngularImpulseToBodies(imp0,jac0,mA,mB,sr[0]);rollingApply(imp1,jac1,mA,mB,sr[1]);}
__forceinline void solve1dFriction(const SInfo&info,const SolverStepInfo&temp,const JsFric&schema,SAccum&mA,SAccum&mB,SElem*sr,SElem*&delayedResult){const hkReal dv0=getLinearDv0(schema.m_pJacobian,mA,mB,info);hkReal imp0=schema.m_pJacobian.getInvJacDiag()*dv0;hkReal fimp0=HkMath::fabs(imp0);if(fimp0>schema.m_usFlags){hkReal factor=schema.m_usFlags/fimp0;imp0*=factor;sr[1].usedFactor=factor;}else{sr[1].usedFactor=1.0f;}aF0(imp0,schema.m_pJacobian,mA,mB,sr[0]);}
__forceinline void solve1dAngFriction(const SInfo&info,const SolverStepInfo&temp,const JsAngFric&schema,SAccum&mA,SAccum&mB,SElem*sr,SElem*&delayedResult){const hkReal dv0=getAngularDv0(schema.m_pJacobian,mA,mB,info);hkReal imp0=schema.m_pJacobian.getInvJacDiag()*dv0;hkReal fimp0=HkMath::fabs(imp0);if(fimp0>schema.m_usFlags){hkReal factor=schema.m_usFlags/fimp0;imp0*=factor;sr[1].usedFactor=factor;}else{sr[1].usedFactor=1.0f;}ApplyAngularImpulseToBodies(imp0,schema.m_pJacobian,mA,mB,sr[0]);}
__forceinline void solve1dAngularMotor(const SInfo&info,const SolverStepInfo&temp,const JsAngMot&schema,SAccum&mA,SAccum&mB,SElem*sr,SElem*&delayedResult){const SMotor&motorInfo=schema.m_kMotorInfo;sr[2].m_fAccumulatedMotorRhs=temp.m_fStepFactor*motorInfo.m_fVelocity+sr[2].m_fAccumulatedMotorRhs;const hkReal customAngularRhs=schema.m_pJacobian.getAngularRhs()+sr[2].m_fAccumulatedMotorRhs;const hkReal dv0=getAngularDv0UserTauWithCustomRhs(schema.m_pJacobian,mA,mB,info,motorInfo.m_fTau,motorInfo.m_fMotorDamping,customAngularRhs);hkReal impulse=schema.m_pJacobian.getInvJacDiag()*dv0;if(impulse>motorInfo.m_fMinimumForce){sr[1].usedFactor=motorInfo.m_fMinimumForce/impulse;impulse=motorInfo.m_fMinimumForce;}else if(motorInfo.m_fMaximumForce>impulse){sr[1].usedFactor=motorInfo.m_fMaximumForce/impulse;impulse=motorInfo.m_fMaximumForce;}else{sr[1].usedFactor=1.0f;}applyAngularImpulse0(impulse,schema.m_pJacobian,mA,mB,sr[0]);}
__forceinline void motorKernel(HkSimdP imp,const Jac1L2A&jac,SAccum&mA,SAccum&mB,SElem&sr){HkVec4 impA;mA.massProduct(imp,impA);HkVec4 impB;mB.massProduct(imp,impB);HkVec4 lA;lA.sB3W(impA,3);HkVec4 nB;nB.sB3W(impB,3);lA.mul4(jac.m_kLinearJacobian);nB.mul4(jac.m_kLinearJacobian);mA.linVel.add3clobberW(lA);mB.linVel.sub3clobberW(nB);_ReadBarrier();impA.mul4(jac.m_kAngularVelocity[0]);impB.mul4(jac.m_kAngularVelocity[1]);HkSimd s=sr.impulse;mA.angVel.add3clobberW(impA);mB.angVel.add3clobberW(impB);s=::AddScalarFloat(s,imp);hkSimdStore(s,&sr.impulse);}
__forceinline void motorKernel0(HkSimdP imp,const Jac1L2A&jac,SAccum&a,SAccum&b,SElem&r){motorKernel(imp,jac,a,b,r);}
__forceinline void solve1dLinearMotor(const SInfo&info,const SolverStepInfo&temp,const JsLinMot&schema,SAccum&mA,SAccum&mB,SElem*sr,SElem*&delayedResult){const SMotor&motorInfo=schema.m_kMotorInfo;sr[2].m_fAccumulatedMotorRhs=temp.m_fStepFactor*motorInfo.m_fVelocity+sr[2].m_fAccumulatedMotorRhs;const hkReal customRhs=schema.m_pJacobian.getRHS()+sr[2].m_fAccumulatedMotorRhs;const hkReal dv0=getLinearDv0UserTauWithCustomRhs(schema.m_pJacobian,mA,mB,info,motorInfo.m_fTau,motorInfo.m_fMotorDamping,customRhs);hkReal impulse=schema.m_pJacobian.getInvJacDiag()*dv0;if(impulse>motorInfo.m_fMinimumForce){sr[1].usedFactor=motorInfo.m_fMinimumForce/impulse;impulse=motorInfo.m_fMinimumForce;}else if(motorInfo.m_fMaximumForce>impulse){sr[1].usedFactor=motorInfo.m_fMaximumForce/impulse;impulse=motorInfo.m_fMaximumForce;}else{sr[1].usedFactor=1.0f;}motorKernel0(impulse,schema.m_pJacobian,mA,mB,sr[0]);}
__forceinline int stepJacobian(const SInfo&info,SolverStepInfo&temp,const JSchema*schemas,SAccum*accums,SElem*srIn){const JSchema*com=schemas;SElem*sr=srIn;SAccum*mA;SAccum*mB;int schemaType=(*(::HkEnum< ::JSchema::SolverSchemaType, signed char> *)(::FUN_00d921c0((char *)(com), {})));if(schemaType==JSchema::SCHEMA_TYPE_END){return 0;}SElem*delayedResult=0;goto headerNoStoreVelocity;while(1){schemaType=(*(::HkEnum< ::JSchema::SolverSchemaType, signed char> *)(::FUN_00d921c0((char *)(com), {})));switch(schemaType){case JSchema::SCHEMA_TYPE_HEADER:header:{{const JsHeader*sc=(const JsHeader*)(com);prefetchVelocityAccumulators(*sc->getBodyA(accums),*sc->getBodyB(accums));}storeVelocityAccumulators(*mA,*mB);headerNoStoreVelocity:const JsHeader*sc;sc=(const JsHeader*)(com);mA=sc->getBodyA(accums);mB=sc->getBodyB(accums);loadVelocityAccumulators(*mA,*mB);com=(const JSchema*)addOffsetC(sc,sizeof(*sc));break;}case JSchema::SCHEMA_TYPE_SHIFT_SOLVER_RESULTS_POINTER:{const JsShift*sc=(const JsShift*)(com);com=addOffsetC(com,sizeof(*sc));break;}case JSchema::SCHEMA_TYPE_SINGLE_CONTACT:case JSchema::SCHEMA_TYPE_SINGLE_CONTACT_WITH_ACCESSOR_CHECK:case_SCHEMA_TYPE_SINGLE_CONTACT:{const JsContact*sc=(const JsContact*)(com);SolveSingleContact(info,temp,*sc,*mA,*mB,sr,delayedResult);sr=sr+::FUN_00d921d0((const signed char *)(const ::JSchema *)((const JSchema*)sc));int comtype=(*(::HkEnum< ::JSchema::SolverSchemaType, signed char> *)(::FUN_00d921c0((char *)((const JSchema*)(sc+1)), {})));com=(const JSchema*)(sc+1);if(comtype==JSchema::SCHEMA_TYPE_SINGLE_CONTACT)goto case_SCHEMA_TYPE_SINGLE_CONTACT;}break;case JSchema::SCHEMA_TYPE_SINGLE_LIMIT_CONTACT:case JSchema::SCHEMA_TYPE_SINGLE_LIMIT_CONTACT_WITH_ACCESSOR_CHECK:case_SCHEMA_TYPE_SINGLE_LIMIT_CONTACT:{const JsContact*sc=(const JsContact*)(com);solveSingleLimitContact(info,temp,*sc,*mA,*mB,sr,delayedResult);sr=sr+::FUN_00d921d0((const signed char *)(com));int comtype=(*(::HkEnum< ::JSchema::SolverSchemaType, signed char> *)(::FUN_00d921c0((char *)((const JSchema*)(sc+1)), {})));com=(const JSchema*)addOffsetC(sc,sizeof(*sc));if(comtype==JSchema::SCHEMA_TYPE_SINGLE_LIMIT_CONTACT)goto case_SCHEMA_TYPE_SINGLE_LIMIT_CONTACT;}break;case JSchema::SCHEMA_TYPE_PAIR_CONTACT:case JSchema::SCHEMA_TYPE_PAIR_CONTACT_WITH_ACCESSOR_CHECK:{{const JsPair*sc=(const JsPair*)(com);solvePairContact(info,*sc,*mA,*mB,sr,delayedResult);sr=sr+2;com=addOffsetC(com,sizeof(*sc));}if((*(::HkEnum< ::JSchema::SolverSchemaType, signed char> *)(::FUN_00d921c0((char *)(com), {})))!=JSchema::SCHEMA_TYPE_PAIR_CONTACT){continue;}{const JsPair*sc=(const JsPair*)(com);solveSecondPair(info,*sc,*mA,*mB,sr,delayedResult);sr=sr+2;com=addOffsetC(com,sizeof(*sc));}if((*(::HkEnum< ::JSchema::SolverSchemaType, signed char> *)(::FUN_00d921c0((char *)(com), {})))!=JSchema::SCHEMA_TYPE_3D_FRICTION){break;}goto friction3d;}case JSchema::SCHEMA_TYPE_3D_FRICTION:friction3d:{const JsFric3*sc=(const JsFric3*)(com);solve3dFriction(info,*sc,*mA,*mB,sr,delayedResult);sr=sr+4;int comtype=(*(::HkEnum< ::JSchema::SolverSchemaType, signed char> *)(::FUN_00d921c0((char *)((const JSchema*)(sc+1)), {})));com=addOffsetC(com,sizeof(*sc));if(comtype==JSchema::SCHEMA_TYPE_HEADER){goto header;}break;}case JSchema::SCHEMA_TYPE_2D_FRICTION:friction2d:{const JsFric2*sc=(const JsFric2*)(com);solve2dFriction(info,*sc,*mA,*mB,sr,delayedResult);sr=sr+3;int comtype=(*(::HkEnum< ::JSchema::SolverSchemaType, signed char> *)(::FUN_00d921c0((char *)((const JSchema*)(sc+1)), {})));com=(const JSchema*)addOffsetC(sc,sizeof(*sc));if(comtype==JSchema::SCHEMA_TYPE_HEADER){goto header;}break;}case JSchema::SCHEMA_TYPE_2D_ROLLING_FRICTION:{const JsRoll*schema=(const JsRoll*)(com);solve2dRollingFriction(info,*schema,*mA,*mB,sr);sr=sr+::FUN_00d921d0((const signed char *)(com));int comtype=(*(::HkEnum< ::JSchema::SolverSchemaType, signed char> *)(::FUN_00d921c0((char *)((const JSchema*)(schema+1)), {})));com=(const JSchema*)(schema+1);if(comtype==JSchema::SCHEMA_TYPE_3D_FRICTION){goto friction3d;}if(comtype==JSchema::SCHEMA_TYPE_2D_FRICTION){goto friction2d;}break;}case JSchema::SCHEMA_TYPE_1D_ANGULAR_FRICTION:case_SCHEMA_TYPE_1D_ANGULAR_FRICTION:{const JsAngFric*sc=(const JsAngFric*)(com);solve1dAngFriction(info,temp,*sc,*mA,*mB,sr,delayedResult);sr=sr+::FUN_00d921d0((const signed char *)(com));int comtype=(*(::HkEnum< ::JSchema::SolverSchemaType, signed char> *)(::FUN_00d921c0((char *)((const JSchema*)(sc+1)), {})));com=(const JSchema*)addOffsetC(sc,sizeof(*sc));if(comtype==JSchema::SCHEMA_TYPE_1D_ANGULAR_FRICTION)goto case_SCHEMA_TYPE_1D_ANGULAR_FRICTION;}break;case JSchema::SCHEMA_TYPE_1D_ANGULAR_LIMITS:case_SCHEMA_TYPE_1D_ANGULAR_LIMITS:{const JsAngLim*sc=(const JsAngLim*)(com);solve1dAngLimits(info,temp,*sc,*mA,*mB,sr,delayedResult);sr=sr+::FUN_00d921d0((const signed char *)(com));int comtype=(*(::HkEnum< ::JSchema::SolverSchemaType, signed char> *)(::FUN_00d921c0((char *)((const JSchema*)(sc+1)), {})));com=addOffsetC(com,sizeof(*sc));if(comtype==JSchema::SCHEMA_TYPE_1D_ANGULAR_LIMITS)goto case_SCHEMA_TYPE_1D_ANGULAR_LIMITS;}break;case JSchema::SCHEMA_TYPE_1D_ANGULAR_MOTOR:case_SCHEMA_TYPE_1D_ANGULAR_MOTOR:{const JsAngMot*sc=(const JsAngMot*)(com);solve1dAngularMotor(info,temp,*sc,*mA,*mB,sr,delayedResult);sr=sr+::FUN_00d921d0((const signed char *)(com));int comtype=(*(::HkEnum< ::JSchema::SolverSchemaType, signed char> *)(::FUN_00d921c0((char *)((const JSchema*)(sc+1)), {})));com=addOffsetC(com,sizeof(*sc));if(comtype==JSchema::SCHEMA_TYPE_1D_ANGULAR_MOTOR)goto case_SCHEMA_TYPE_1D_ANGULAR_MOTOR;}break;case JSchema::SCHEMA_TYPE_1D_ANGULAR:case_SCHEMA_TYPE_1D_ANGULAR:{const JsAng*sc=(const JsAng*)(com);solve1dAngular(info,temp,*sc,*mA,*mB,sr,delayedResult);sr=sr+::FUN_00d921d0((const signed char *)(com));int comtype=(*(::HkEnum< ::JSchema::SolverSchemaType, signed char> *)(::FUN_00d921c0((char *)((const JSchema*)(sc+1)), {})));com=addOffsetC(com,sizeof(*sc));if(comtype==JSchema::SCHEMA_TYPE_1D_ANGULAR)goto case_SCHEMA_TYPE_1D_ANGULAR;}break;case JSchema::SCHEMA_TYPE_1D_BILATERAL:case_SCHEMA_TYPE_1D_BILATERAL:{const JsBil*sc=(const JsBil*)(com);solve1dBilateral(info,temp,*sc,*mA,*mB,sr);sr=sr+::FUN_00d921d0((const signed char *)(com));int comtype=(*(::HkEnum< ::JSchema::SolverSchemaType, signed char> *)(::FUN_00d921c0((char *)((const JSchema*)(sc+1)), {})));com=(const JSchema*)addOffsetC(sc,sizeof(*sc));if(comtype==JSchema::SCHEMA_TYPE_1D_BILATERAL)goto case_SCHEMA_TYPE_1D_BILATERAL;}break;case JSchema::SCHEMA_TYPE_1D_BILATERAL_WITH_IMPULSE_LIMIT:case_SCHEMA_TYPE_1D_BILATERAL_WITH_IMPULSE_LIMIT:{const JsBil*sc=(const JsBil*)(com);solve1dBilateralWithImpulseLimit(info,temp,*sc,*mA,*mB,sr);sr=sr+::FUN_00d921d0((const signed char *)(com));int comtype=(*(::HkEnum< ::JSchema::SolverSchemaType, signed char> *)(::FUN_00d921c0((char *)((const JSchema*)(sc+1)), {})));com=addOffsetC(com,sizeof(*sc));if(comtype==JSchema::SCHEMA_TYPE_1D_BILATERAL_WITH_IMPULSE_LIMIT)goto case_SCHEMA_TYPE_1D_BILATERAL_WITH_IMPULSE_LIMIT;}break;case JSchema::SCHEMA_TYPE_1D_BILATERAL_USER_TAU:case_SCHEMA_TYPE_1D_BILATERAL_USER_TAU:{const JsBilTau*sc=(const JsBilTau*)(com);solve1dBilateralUserTau(info,temp,*sc,*mA,*mB,sr,delayedResult);sr=sr+::FUN_00d921d0((const signed char *)(com));int comtype=(*(::HkEnum< ::JSchema::SolverSchemaType, signed char> *)(::FUN_00d921c0((char *)((const JSchema*)(sc+1)), {})));com=addOffsetC(com,sizeof(*sc));if(comtype==JSchema::SCHEMA_TYPE_1D_BILATERAL_USER_TAU)goto case_SCHEMA_TYPE_1D_BILATERAL_USER_TAU;}break;case JSchema::SCHEMA_TYPE_1D_FRICTION:case_SCHEMA_TYPE_1D_FRICTION:{const JsFric*sc=(const JsFric*)(com);solve1dFriction(info,temp,*sc,*mA,*mB,sr,delayedResult);sr=sr+::FUN_00d921d0((const signed char *)(com));int comtype=(*(::HkEnum< ::JSchema::SolverSchemaType, signed char> *)(::FUN_00d921c0((char *)((const JSchema*)(sc+1)), {})));com=(const JSchema*)addOffsetC(sc,sizeof(*sc));if(comtype==JSchema::SCHEMA_TYPE_1D_FRICTION)goto case_SCHEMA_TYPE_1D_FRICTION;}break;case JSchema::SCHEMA_TYPE_1D_LINEAR_LIMITS:case_SCHEMA_TYPE_1D_LINEAR_LIMITS:{const JsLinLim*sc=(const JsLinLim*)(com);solve1dLinLimits(info,temp,*sc,*mA,*mB,sr,delayedResult);sr=sr+::FUN_00d921d0((const signed char *)(com));int comtype=(*(::HkEnum< ::JSchema::SolverSchemaType, signed char> *)(::FUN_00d921c0((char *)((const JSchema*)(sc+1)), {})));com=addOffsetC(com,sizeof(*sc));if(comtype==JSchema::SCHEMA_TYPE_1D_LINEAR_LIMITS)goto case_SCHEMA_TYPE_1D_LINEAR_LIMITS;}break;case JSchema::SCHEMA_TYPE_1D_LINEAR_MOTOR:case_SCHEMA_TYPE_1D_LINEAR_MOTOR:{const JsLinMot*sc=(const JsLinMot*)(com);solve1dLinearMotor(info,temp,*sc,*mA,*mB,sr,delayedResult);sr=sr+::FUN_00d921d0((const signed char *)(com));int comtype=(*(::HkEnum< ::JSchema::SolverSchemaType, signed char> *)(::FUN_00d921c0((char *)((const JSchema*)(sc+1)), {})));com=addOffsetC(com,sizeof(*sc));if(comtype==JSchema::SCHEMA_TYPE_1D_LINEAR_MOTOR)goto case_SCHEMA_TYPE_1D_LINEAR_MOTOR;}break;case JSchema::SCHEMA_TYPE_1D_PULLEY:{const JsPulley*sc=(const JsPulley*)(com);solvePulley(info,*sc,*mA,*mB,sr,delayedResult);sr=sr+1;com=addOffsetC(com,sizeof(*sc));break;}case JSchema::SCHEMA_TYPE_SET_MASS:{const JsMass*sc=(const JsMass*)(com);storeVelocityAccumulators(*mA,*mB);mA->invMass=sc->m_vInverseMassA;mB->invMass=sc->m_vInverseMassB;com=addOffsetC(com,sizeof(*sc));loadVelocityAccumulators(*mA,*mB);break;}case JSchema::SCHEMA_TYPE_ADD_VELOCITY:{const JsAddVel*sc=(const JsAddVel*)(com);storeVelocityAccumulators(*mA,*mB);int bodyIndex=sc->m_iBodyIndex;SAccum*accum=selectPtr(bodyIndex,mA,mB);HkSimd f=info.m_kTimeStep(0)*temp.m_iStep;HkVec4 integratedVel;integratedVel.setMul4(f,sc->m_vVelocityChange);accum->linVel.add4(sc->m_vVelocityChange);accum->linVel.add4(integratedVel);accum->getSumLinearVel().add4(integratedVel);com=addOffsetC(com,sizeof(*sc));loadVelocityAccumulators(*mA,*mB);break;}case JSchema::SCHEMA_TYPE_SET_CENTER_OF_MASS:{const JsCom*sc=(const JsCom*)(com);storeVelocityAccumulators(*mA,*mB);HkVec4 deltaVelA;reinterpret_cast<::FUN_00c7f750_shell *>(&(deltaVelA))->FUN_00c7f750((float *)&(sc->m_kAngularToLinearVelocityMatrixA),(float *)&(mA->angVel));HkVec4 deltaVelB;reinterpret_cast<::FUN_00c7f750_shell *>(&(deltaVelB))->FUN_00c7f750((float *)&(sc->m_kAngularToLinearVelocityMatrixB),(float *)&(mB->angVel));HkVec4 deltaSumVelA;reinterpret_cast<::FUN_00c7f750_shell *>(&(deltaSumVelA))->FUN_00c7f750((float *)&(sc->m_kAngularToLinearVelocityMatrixA),(float *)&(mA->getSumAngularVel()));HkVec4 deltaSumVelB;reinterpret_cast<::FUN_00c7f750_shell *>(&(deltaSumVelB))->FUN_00c7f750((float *)&(sc->m_kAngularToLinearVelocityMatrixB),(float *)&(mB->getSumAngularVel()));mA->addCenterVelocity(deltaVelA);mA->getSumLinearVel().add4(deltaSumVelA);mB->linVel.add4(deltaVelB);mB->getSumLinearVel().add4(deltaSumVelB);com=addOffsetC(com,sizeof(*sc));loadVelocityAccumulators(*mA,*mB);break;}case JSchema::SCHEMA_TYPE_GOTO:{const JsGoto*sc=(const JsGoto*)(com);com=addOffsetC(com,sc->m_offset);break;}case JSchema::SCHEMA_TYPE_END:{storeDelayedResult(delayedResult);storeVelocityAccumulators(*mA,*mB);return 0;}case JSchema::SCHEMA_TYPE_STIFF_SPRING_CHAIN:{storeVelocityAccumulators(*mA,*mB);const JsSpring*chain=(const JsSpring*)(com);::FUN_00d893a0(&info,&temp,accums,(::ProbeHeader *)(chain),(float *)(sr));sr=sr+chain->m_iConstraintCount;com=addOffsetC(com,chain->m_iElementCount);loadFixedRegisters();loadVelocityAccumulators(*mA,*mB);break;}case JSchema::SCHEMA_TYPE_BALL_SOCKET_CHAIN:{storeVelocityAccumulators(*mA,*mB);const JsBall*chain=(const JsBall*)(com);::FUN_00d89690((const ::hkpSolverInfoQ &)(info),(const ::hkSolverQ::SolverStepInfo &)(temp),(::hkpVelocityAccumulatorQ *)(accums),(::hkpJacobianBallSocketChainSchemaQ *)(chain),(::hkpSolverElemTempQ *)(sr));sr=sr+3*chain->m_iConstraintCount;com=addOffsetC(com,((const JsBall*)com)->m_iElementCount);loadFixedRegisters();loadVelocityAccumulators(*mA,*mB);break;}case JSchema::SCHEMA_TYPE_POWERED_CHAIN:{storeVelocityAccumulators(*mA,*mB);const JsPowered*chain=(const JsPowered*)(com);::FUN_00d8a3a0((const ::PoweredChainSettings &)(info),(const ::PoweredChainSolver::PoweredChainStepTemp &)(temp),(::PoweredChainAccumulator *)(accums),(::PoweredChainSchema *)(chain),(::PoweredChainResult *)(sr));sr=sr+6*((const JsPowered*)com)->m_iConstraintCount;com=addOffsetC(com,((const JsPowered*)com)->m_iElementCount);loadFixedRegisters();loadVelocityAccumulators(*mA,*mB);break;}default:{fnv_Breakpoint();return 0;}}}return 0;}
__forceinline void integrateVelocityAccumulator(const SInfo&info,SAccum*m){const SInfo::FloatAndHalfRecord&di=info.m_kDeactivationClassInfo[m->m_uiDeactivationClass];HkVec4 absLin;absLin.setAbs4(m->linVel);HkVec4 absAng;absAng.setAbs4(m->angVel);HkVec4 scaledVel;scaledVel.setMul4(di.m_fFirstFloat,absLin);scaledVel.addMul4(di.m_fSecondFloat,absAng);HkVec4 one;one.setAll3(info.m_iCachedVertexCount);{HkVecP maxVel=reinterpret_cast<HkVecP>(DAT_010d3da0);int mask=absLin.compareLessThan4(maxVel).GetLaneMask()&absAng.compareLessThan4(maxVel).GetLaneMask();mask&=m->linVel.compareEqual4(m->linVel).GetLaneMask()&m->angVel.compareEqual4(m->angVel).GetLaneMask();if((mask&HkCmp::MASK_XYZ)!=HkCmp::MASK_XYZ){m->linVel=HkXform::GetIdentityTransform().getColumn(0);m->angVel=HkXform::GetIdentityTransform().getColumn(0);}}if(scaledVel.compareLessThanEqual4(one).allAreSet(HkCmp::MASK_XYZ)){HkVec4 relativeSleepVel3;relativeSleepVel3.setAll3(di.m_fFourthFloat);if(scaledVel.compareLessThanEqual4(relativeSleepVel3).allAreSet(HkCmp::MASK_XYZ)){m->angVel.setZero4();m->linVel.setZero4();}else if(1){m->slowAngularVelocity(di.m_fThirdValue);m->linVel.mul4(di.m_fThirdValue);}else{HkVec4 linDir=m->linVel;hkReal ldrag=linDir.normalizeWithLength3();if(ldrag>0.25f){ldrag=HkMath::min2(ldrag,0.001f);m->linVel.subMul4(ldrag,linDir);}else{m->linVel.setZero4();}HkVec4 angDir=m->angVel;hkReal adrag=angDir.normalizeWithLength3();if(adrag>0.25f){adrag=HkMath::min2(adrag,0.01f);m->angVel.subMul4(adrag,angDir);}else{m->angVel.setZero4();}}}}
__forceinline void scaleHotSums(HkVec4&linear,HkVec4&angular,HkVecP factor){linear.multiplyQuad(reinterpret_cast<const HkQuad&>(factor));angular.multiplyQuad(reinterpret_cast<const HkQuad&>(factor));}
__forceinline void updateSumVelocities(const SInfo&info,HkVecP velocityField,bool useFinalFactor,HkVecP sumVelFactor,SAccum*m){HkVec4 vel2;HkSimd factor=m->m_fGravityFactor;vel2.setMul4(factor,velocityField);HkVec4 linVel;linVel.setSub4(m->linVel,m->getSumLinearVel());HkVec4 angVel;angVel.setSub4(m->angVel,m->getSumAngularVel());m->getSumLinearVel().addMul4(info.m_kTimeStep.getSimdAt(0),linVel);m->getSumAngularVel().addMul4(info.m_kTimeStep.getSimdAt(0),angVel);if(!useFinalFactor){linVel.add4(m->getSumLinearVel());angVel.add4(m->getSumAngularVel());linVel.add4(vel2);}else{scaleHotSums(m->getSumLinearVel(),m->getSumAngularVel(),sumVelFactor);}m->linVel=linVel;m->angVel=angVel;}
__forceinline void addColdSum(HkVec4&delta,HkVecP sum){delta=_mm_add_ps(HkQuad(sum),HkQuad(delta));}
__forceinline void updateColdSums(const SInfo&info,HkVecP velocityField,bool useFinalFactor,HkVecP sumVelFactor,SAccum*m){HkVec4 vel2;HkSimd factor=m->m_fGravityFactor;vel2.setMul4(factor,velocityField);HkVec4 linVel;linVel.setSub4(m->linVel,m->getSumLinearVel());HkVec4 angVel;angVel.setSub4(m->angVel,m->getSumAngularVel());m->getSumLinearVel().addMul4(info.m_kTimeStep.getSimdAt(0),linVel);m->getSumAngularVel().addMul4(info.m_kTimeStep.getSimdAt(0),angVel);if(!useFinalFactor){addColdSum(linVel,m->getSumLinearVel());addColdSum(angVel,m->getSumAngularVel());linVel.add4(vel2);}else{m->getSumLinearVel().mul4(sumVelFactor);m->getSumAngularVel().mul4(sumVelFactor);}m->linVel=linVel;m->angVel=angVel;}
__forceinline void integrateVelocities(const SInfo&info,HkVecP velocityField,bool useFinalFactor,HkVecP sumVelFactor,SAccum*acc,SAccum*accEnd){if(!accEnd){accEnd=reinterpret_cast<SAccum*>(hkUlong(-1));}while(acc<accEnd){switch(acc->m_type){case SAccum::HK_NO_GRAVITY_RIGID_BODY:{integrateVelocityAccumulator(info,acc);}case SAccum::HK_KEYFRAMED_RIGID_BODY:{updateColdSums(info,HkVec4::getZero(),useFinalFactor,sumVelFactor,acc);acc++;break;}case SAccum::HK_RIGID_BODY:{do{integrateVelocityAccumulator(info,acc);updateSumVelocities(info,velocityField,useFinalFactor,sumVelFactor,acc);acc++;}while(acc->m_type==SAccum::HK_RIGID_BODY&&acc<accEnd);break;}case SAccum::HK_END:{return;}default:{}}}}
__forceinline void applyVelField(const SInfo&info,HkVecP glovalVelField,SAccum*acc,SAccum*accEnd){if(!accEnd){accEnd=reinterpret_cast<SAccum*>(hkUlong(-1));}while(acc<accEnd){switch(acc->m_type){case SAccum::HK_KEYFRAMED_RIGID_BODY:case SAccum::HK_NO_GRAVITY_RIGID_BODY:{acc->getSumLinearVel().setZero4();acc->getSumAngularVel().setZero4();acc++;break;}case SAccum::HK_RIGID_BODY:{do{HkSimd factor=acc->m_fGravityFactor;acc->getSumLinearVel().setZero4();acc->getSumAngularVel().setZero4();acc->linVel.addMul4(factor,glovalVelField);acc++;}while(acc->m_type==SAccum::HK_RIGID_BODY&&acc<accEnd);break;}case SAccum::HK_END:{return;}default:{fnv_Breakpoint();}}}}
__forceinline void solve(const SInfo&info,const JSchema*schemas,SAccum*accumulators,SElem*elemTemp){loadFixedRegisters();HkVec4 gravity=info.m_kGravity;applyVelField(info,gravity,accumulators,0);SolverStepInfo temp;HkVec4 sumVelFactor;sumVelFactor.setAll3(info.m_fInverseStepCount*info.GetTimeStepFactor(0));for(int i=0;i<info.m_iToiEventCount;i++){temp.m_iStep=i;temp.m_fStepFactor=1.0f;int microStep=info.m_iMicroStepCount;do{hkDebugPrintfAccumulators(i,info,accumulators,0);stepJacobian(info,temp,schemas,accumulators,elemTemp);temp.m_fStepFactor=0.0f;}while(--microStep>0);bool isLast=false;if(i==info.m_iToiEventCount-1){isLast=true;hkDebugPrintfAccumulators(98,info,accumulators,0);}integrateVelocities(info,gravity,isLast,sumVelFactor,accumulators,0);if(i==info.m_iToiEventCount-1){hkDebugPrintfAccumulators(99,info,accumulators,0);}}}
}
extern"C"HkBool32 __cdecl FUN_00d8d030(const SInfo&info,JSchema*schemas,SAccum*accumulators,SElem*temp){createSolverDebugOstream();if(!DAT_01269204){::ValidateHavokKeyCode((bool *)(::HkBool *)(&DAT_01269204));if(!DAT_01269204){return 0;}}SolverNs::solve(info,schemas,accumulators,temp);return 1;}

// Moved from hkpsolver_gs_nogs_variant.cpp (VEGAS-15).
#include <new>
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/symbols_00df0000.h"
// src/havok/physics/constraintsolver/solve/hkpsolver.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/solve/hkpsolver.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
int __cdecl FUN_00d921d0(const signed char* index);
char* __cdecl FUN_00d921c0(char* dst, const char* src);
extern __m128 DAT_010c7160;
typedef __m128 hkQuadReal;
class VectorComponentValue
{
public:
    __forceinline VectorComponentValue(const hkQuadReal& x) : m_vValue(x) {}
    __forceinline VectorComponentValue(hkReal x) { m_vValue = _mm_load_ss(&x); }
    __forceinline VectorComponentValue() {}
    __forceinline operator hkReal() const
    {
        hkReal s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline hkQuadReal broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
    __forceinline const hkQuadReal& getQuad() const { return m_vValue; }
    hkQuadReal m_vValue;
};
typedef const VectorComponentValue& hkSimdRealParameter;
__forceinline void hkSimdReal_setMax(hkSimdRealParameter a, hkSimdRealParameter b, VectorComponentValue& result)
{
    result = VectorComponentValue(_mm_max_ps(a.getQuad(), b.getQuad()));
}
__forceinline void hkSimdReal_setMin(hkSimdRealParameter a, hkSimdRealParameter b, VectorComponentValue& result)
{
    result = VectorComponentValue(_mm_min_ps(a.getQuad(), b.getQuad()));
}
__forceinline void hkSimdReal_store(hkSimdRealParameter a, float* f)
{
    _mm_store_ss(f, a.getQuad());
}
__forceinline VectorComponentValue operator*(hkSimdRealParameter r, hkSimdRealParameter s) { return _mm_mul_ss(r.getQuad(), s.getQuad()); }
__forceinline VectorComponentValue operator-(hkSimdRealParameter r, hkSimdRealParameter s) { return _mm_sub_ss(r.getQuad(), s.getQuad()); }
__forceinline VectorComponentValue operator+(hkSimdRealParameter r, hkSimdRealParameter s) { return _mm_add_ss(r.getQuad(), s.getQuad()); }
__forceinline VectorComponentValue operator-(hkSimdRealParameter r) { return _mm_sub_ss(DAT_010c7160, r.getQuad()); }
VectorComponentValue __cdecl SubtractScalarFloat(hkSimdRealParameter r, hkSimdRealParameter s);
__declspec(noinline) VectorComponentValue __cdecl AddScalarFloat(hkSimdRealParameter r, hkSimdRealParameter s) { return _mm_add_ss(r.getQuad(),s.getQuad()); }
class hkMatrix3;
struct hkVector4
{
public:
    __forceinline void commitIncrement(hkVector4& dest) const { dest.add4(*this); }
    __forceinline operator hkQuadReal() const { return m_vComponents; }
    __forceinline void operator=(const hkQuadReal& q) { m_vComponents = q; }
    __forceinline void operator=(const hkVector4& v) { m_vComponents = v.m_vComponents; }
    __forceinline void add4(const hkVector4& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    __forceinline void add3clobberW(const hkVector4& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void sub3clobberW(const hkVector4& v) { m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void mul4(const hkVector4& v) { m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b) { m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void mul4(hkSimdRealParameter s) { m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents); }
    __forceinline void setMul4(hkSimdRealParameter r, const hkVector4& v) { m_vComponents = _mm_mul_ps(r.broadcast(), v.m_vComponents); }
    __forceinline VectorComponentValue horizontalAdd3() const
    {
        hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0x55), m_vComponents);
        return _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa), xySum);
    }
    __forceinline hkReal& operator()(int a) { return reinterpret_cast<hkReal*>(&m_vComponents)[a]; }
    __forceinline const hkReal& operator()(int a) const { return reinterpret_cast<const hkReal*>(&m_vComponents)[a]; }
    __forceinline VectorComponentValue getSimdAtE(int i) const
    {
        switch (i)
        {
        case 0: return m_vComponents;
        case 1: return _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55);
        case 2: return (hkQuadReal)DAT_010c7160;
        case 3:
        default: return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        }
    }
    __forceinline VectorComponentValue getSimdAt(int i) const
    {
        switch (i)
        {
        case 0: return m_vComponents;
        case 1: return _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55);
        case 2: return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa);
        case 3:
        default: return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        }
    }
    __forceinline void setBroadcast(const hkVector4& v, int i)
    {
        if (i == 0) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
        else if (i == 1) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
        else if (i == 2) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
        else if (i == 3) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
    }
    __forceinline void setBroadcast3clobberW(const hkVector4& v, int i) { setBroadcast(v, i); }
    __forceinline void SetRotatedVector(const hkMatrix3& a, const hkVector4& b) { reinterpret_cast<::FUN_00c7f750_shell *>(this)->FUN_00c7f750((float *)&(a), (float *)&(b)); }
    hkQuadReal m_vComponents;
};
class hkMatrix3 { public: hkVector4 m_kColumn0, m_kColumn1, m_kColumn2; };
template <class TYPE> class ValueWrapper
{
public:
    __forceinline ValueWrapper() {}
    __forceinline ValueWrapper(TYPE e) : m_kStorage(e) {}
    __forceinline void operator=(TYPE e) { m_kStorage = e; }
    __forceinline TYPE val() const { return m_kStorage; }
    __forceinline TYPE operator->() const { return m_kStorage; }
    __forceinline operator TYPE() const { return val(); }
private:
    TYPE m_kStorage;
};
struct ConstraintSolverInfo
{
    float unk00, m_fTau, m_fMotorDamping, m_fPostDampingParameter;
    hkVector4 unk10, unk20;
    hkVector4 m_kGravity;
    hkVector4 m_kTimeStep;
};
struct FloatRecord { float m_fAccumulatedImpulse; };
class QuantizedBoundsData
{
public:
    int unk00;
    __forceinline const hkVector4& getSumLinearVel() const { return m_sumLinearVel; }
    __forceinline hkVector4& getSumLinearVel() { return m_sumLinearVel; }
    __forceinline const hkVector4& getSumAngularVel() const { return m_sumAngularVel; }
    hkVector4 m_vLinearVelocity;
    hkVector4 m_vAngularVelocity;
    hkVector4 m_vInverseInertiaAndMass;
    hkVector4 m_sumLinearVel;
    hkVector4 m_sumAngularVel;
    hkVector4 unk60;
    hkVector4 unk70;
};
template <class T> __forceinline T* hkSelect(int i, T* a, T* b)
{
    uintptr_t ua = reinterpret_cast<uintptr_t>(a);
    uintptr_t ub = reinterpret_cast<uintptr_t>(b);
    return reinterpret_cast<T*>(ua ^ ((ua ^ ub) & (-i)));
}
struct SolverStepInfo
{
    ValueWrapper<int> m_intStep;
    ValueWrapper<hkReal> m_stepFactor;
};
enum SolverSchemaType
{
    SCHEMA_TYPE_END = 0,
    SCHEMA_TYPE_HEADER = 1,
    SCHEMA_TYPE_GOTO = 2,
    SCHEMA_TYPE_NOP = 3,
    SCHEMA_TYPE_1D_BILATERAL = 5,
    SCHEMA_TYPE_1D_BILATERAL_WITH_IMPULSE_LIMIT = 6,
    SCHEMA_TYPE_1D_BILATERAL_USER_TAU = 7,
    SCHEMA_TYPE_1D_LINEAR_LIMITS = 8,
    SCHEMA_TYPE_1D_FRICTION = 9,
    SCHEMA_TYPE_1D_LINEAR_MOTOR = 10,
    SCHEMA_TYPE_1D_PULLEY = 11,
    SCHEMA_TYPE_1D_ANGULAR = 12,
    SCHEMA_TYPE_1D_ANGULAR_LIMITS = 13,
    SCHEMA_TYPE_1D_ANGULAR_FRICTION = 14,
    SCHEMA_TYPE_1D_ANGULAR_MOTOR = 15,
    SCHEMA_TYPE_SINGLE_CONTACT = 16,
    SCHEMA_TYPE_SINGLE_CONTACT2 = 17,
    SCHEMA_TYPE_SINGLE_LIMIT_CONTACT = 18,
    SCHEMA_TYPE_SINGLE_LIMIT_CONTACT2 = 19,
    SCHEMA_TYPE_PAIR_CONTACT = 20,
    SCHEMA_TYPE_PAIR_CONTACT2 = 21,
    SCHEMA_TYPE_2D_FRICTION = 22,
    SCHEMA_TYPE_3D_FRICTION = 23,
    SCHEMA_TYPE_2D_ROLLING_FRICTION = 24,
    SCHEMA_TYPE_SET_MASS = 25,
    SCHEMA_TYPE_ADD_VELOCITY = 26,
    SCHEMA_TYPE_SET_CENTER_OF_MASS = 27,
    SCHEMA_TYPE_STIFF_SPRING_CHAIN = 29,
    SCHEMA_TYPE_BALL_SOCKET_CHAIN = 30,
    SCHEMA_TYPE_POWERED_CHAIN = 31
};
class hkBool
{
public:
    __forceinline hkBool(bool b) { m_cBooleanValue = (char)b; }
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
    char m_cBooleanValue;
};
template <class E, class S> class hkEnum
{
public:
    __forceinline hkEnum() {}
    __forceinline hkEnum(E e) { m_kStorage = (S)e; }
    __forceinline void operator=(E e) { m_kStorage = (S)e; }
    __forceinline hkBool operator==(E e) const { return m_kStorage == (S)e; }
    __forceinline operator E() const { return (E)m_kStorage; }
    __forceinline hkBool operator!=(E e) const { return m_kStorage != (S)e; }
    S m_kStorage;
};
typedef hkEnum<SolverSchemaType, signed char> SchemaEnum;
class SolverSchemaHeader
{
public:
    SchemaEnum m_type;
};
template <class T> __forceinline const T* hkAddByteOffsetConst(const T* base, long offset)
{
    return reinterpret_cast<const T*>(reinterpret_cast<const char*>(base) + offset);
}
__forceinline SchemaEnum getType(const SolverSchemaHeader* s) { return *reinterpret_cast<const SchemaEnum*>(hkAddByteOffsetConst(s, 0)); }
__forceinline int getNumSolverElemTemps(const SolverSchemaHeader* s)
{
    const int numSolverElemTemps = DAT_011b9434[(SolverSchemaType)getType(s)];
    return numSolverElemTemps;
}
SchemaEnum __cdecl FUN_00d921c0(const SolverSchemaHeader* s);
class __declspec(align(16)) ConstraintHeaderSchema : public SolverSchemaHeader
{
public:
    __forceinline QuantizedBoundsData* getBodyA(QuantizedBoundsData* base) const
    {
        return reinterpret_cast<QuantizedBoundsData*>(reinterpret_cast<char*>(base) + ((int)m_pBodyA << 7));
    }
    __forceinline QuantizedBoundsData* getBodyB(QuantizedBoundsData* base) const
    {
        return reinterpret_cast<QuantizedBoundsData*>(reinterpret_cast<char*>(base) + ((int)m_pBodyB << 7));
    }
    unsigned char unk01;
    unsigned short m_numTemps;
    unsigned short m_pBodyA;
    unsigned short m_pBodyB;
};
class SchemaJump : public SolverSchemaHeader
{
public:
    int m_offset;
};
class ConstraintJacobian
{
public:
    __forceinline const hkReal& getRHS() const { return m_kLinearJacobian(3); }
    __forceinline const VectorComponentValue getRhsSr() const { return m_kLinearJacobian.getSimdAt(3); }
    __forceinline const VectorComponentValue getRhsSrE() const { return m_kLinearJacobian.getSimdAtE(3); }
    __forceinline hkReal getInvJacDiag() const { return m_kAngularVelocity[0](3); }
    __forceinline VectorComponentValue getInvJacDiagSr() const { return m_kAngularVelocity[0].getSimdAt(3); }
    __forceinline hkReal getUserValue() const { return m_kAngularVelocity[1](3); }
    __forceinline VectorComponentValue getUserValueSr() const { return m_kAngularVelocity[1].getSimdAt(3); }
    hkVector4 m_kLinearJacobian;
    hkVector4 m_kAngularVelocity[2];
};
class AngularJacobianElement
{
public:
    __forceinline hkReal getAngularRhs() const { return m_kAngularVelocity[1](3); }
    __forceinline VectorComponentValue getAngularRhsSr() const { return m_kAngularVelocity[1].getSimdAt(3); }
    __forceinline hkReal getInvJacDiag() const { return m_kAngularVelocity[0](3); }
    __forceinline VectorComponentValue getInvJacDiagSr() const { return m_kAngularVelocity[0].getSimdAt(3); }
    hkVector4 m_kAngularVelocity[2];
};
class JacobianElement
{
public:
    __forceinline VectorComponentValue getRhsSr() const { return m_kTranslationalVelocity[0].getSimdAt(3); }
    __forceinline VectorComponentValue getInvJacDiagSr() const { return m_kAngularVelocity[0].getSimdAt(3); }
    hkVector4 m_kTranslationalVelocity[2];
    hkVector4 m_kAngularVelocity[2];
};
class JacobianPair { public: ConstraintJacobian m_kFirstFrictionJacobian, m_kSecondFrictionJacobian; hkReal m_offDiag; };
class Friction3DSchema { public: ConstraintJacobian m_kFirstFrictionJacobian, m_kSecondFrictionJacobian; AngularJacobianElement m_kAngularVelocity; hkReal m_offDiag, m_maxFrictionImpulse, m_angularFactor; };
class TwoAxisFrictionInfo { public: ConstraintJacobian m_kFirstFrictionJacobian, m_kSecondFrictionJacobian; hkReal m_offDiag, m_maxFrictionImpulse; };
class Friction2DSchema { public: AngularJacobianElement m_kFirstFrictionJacobian, m_kSecondFrictionJacobian; hkReal m_maxFrictionImpulse; };
class JacobianPointerSchema : public ConstraintJacobian {};
class JacobianDataHolder : public ConstraintJacobian {};
class LinearSoftConstraintAtom : public ConstraintJacobian { public: hkReal m_userTau, m_userDamping; };
class FrictionImpulseLimitAtom : public ConstraintJacobian { public: hkReal m_maxFrictionImpulse; };
class LinearDistanceLimitAtom : public ConstraintJacobian { public: hkReal m_minLimit, m_maxLimit; };
struct hkpMotorInfo { hkReal m_minImpulse, m_usFlags, m_fVelocity, m_fTau, m_fMotorDamping; };
class MotorSolverSchema : public ConstraintJacobian { public: hkpMotorInfo m_pMotor; };
class JacobianHolder : public AngularJacobianElement {};
class FrictionImpulseLimitedJacobian : public AngularJacobianElement { public: hkReal m_maxFrictionImpulse; };
class AngularLimitJacobian : public AngularJacobianElement { public: hkReal m_minLimit, m_maxLimit, m_userTau; };
class MotorInfoRecord : public AngularJacobianElement { public: hkpMotorInfo m_pMotor; };
class SingleJacobianSchema : public JacobianElement {};
class SetInverseMassSchema { public: hkVector4 m_invMassA, m_invMassB; };
class AddVelocitySchema { public: hkVector4 m_fVelocity; int m_iBodyIndex; };
class hkpJacobianSetComSchema { public: hkMatrix3 m_angularA, m_angularB; };
class hkpStiffChainSchema : public SolverSchemaHeader { public: unsigned char unk01; unsigned short m_iConstraintCount; int m_sizeOfNext; };
class hkpBallChainSchema : public SolverSchemaHeader { public: unsigned char unk01; unsigned short m_iConstraintCount; int m_sizeOfNext; };
class hkpPoweredChainSchema : public SolverSchemaHeader { public: unsigned char flags; unsigned short m_numTemps, m_pBodyA, m_pBodyB; int unk08, unk0c, m_nextOffset; };
struct FloatRecord;
__forceinline void storeDelayedResult(FloatRecord*) {}
__forceinline void prefetchVelocityAccumulators(QuantizedBoundsData& a, QuantizedBoundsData& b) {}
__forceinline void reserveRegisters(unsigned int) {}
__forceinline void loadVelocityAccumulators(const QuantizedBoundsData& a, const QuantizedBoundsData& b) { reserveRegisters(0xFFFF0000); }
__forceinline void releaseRegisters(unsigned int) {}
__forceinline void storeVelocityAccumulators(QuantizedBoundsData& a, QuantizedBoundsData& b) { releaseRegisters(0xFFFF0000); }
__forceinline hkReal hkMath_fabs(hkReal r) { return fabsf(r); }
__forceinline hkReal hkMath_sqrt(hkReal r) { return sqrtf(r); }
__forceinline hkReal hkMath_sqrtInverse(hkReal r) { return 1.0f / hkMath_sqrt(r); }
__forceinline VectorComponentValue getLinearDv0(const ConstraintJacobian& jac, const QuantizedBoundsData& mA, const QuantizedBoundsData& mB, const ConstraintSolverInfo& info)
{
    hkVector4 a; a.setSub4(mA.m_vLinearVelocity, mB.m_vLinearVelocity);
    hkVector4 b; b.setMul4(mA.m_vAngularVelocity, jac.m_kAngularVelocity[0]);
    hkVector4 c; c.setMul4(mB.m_vAngularVelocity, jac.m_kAngularVelocity[1]);
    a.mul4(jac.m_kLinearJacobian);
    b.add4(c);
    b.add4(a);
    const VectorComponentValue vel = b.horizontalAdd3();
    const VectorComponentValue dv = jac.getRhsSr() - vel;
    return dv;
}
__forceinline VectorComponentValue getAngularDv0(const AngularJacobianElement& jac, const QuantizedBoundsData& mA, const QuantizedBoundsData& mB, const ConstraintSolverInfo& info)
{
    hkVector4 a; a.setMul4(mA.m_vAngularVelocity, jac.m_kAngularVelocity[0]);
    hkVector4 b; b.setMul4(mB.m_vAngularVelocity, jac.m_kAngularVelocity[1]);
    a.add4(b);
    const VectorComponentValue vel = a.horizontalAdd3();
    const VectorComponentValue dv = jac.getAngularRhsSr() - vel;
    return dv;
}
__forceinline VectorComponentValue getLinearDv0UserTauWithCustomRhs(const ConstraintJacobian& jac, const QuantizedBoundsData& mA, const QuantizedBoundsData& mB, const ConstraintSolverInfo& info, hkReal tau, hkReal damping, hkReal customRhs)
{
    hkVector4 vel4;
    {
        hkVector4 linVelA; linVelA.setSub4(mA.m_vLinearVelocity, mA.getSumLinearVel());
        hkVector4 angVelA; angVelA.setSub4(mA.m_vAngularVelocity, mA.getSumAngularVel());
        hkVector4 linVelB; linVelB.setSub4(mB.m_vLinearVelocity, mB.getSumLinearVel());
        hkVector4 angVelB; angVelB.setSub4(mB.m_vAngularVelocity, mB.getSumAngularVel());
        hkVector4 a; a.setSub4(linVelA, linVelB);
        hkVector4 b; b.setMul4(angVelA, jac.m_kAngularVelocity[0]);
        hkVector4 c; c.setMul4(angVelB, jac.m_kAngularVelocity[1]);
        a.mul4(jac.m_kLinearJacobian);
        b.add4(c);
        vel4.setAdd4(b, a);
    }
    hkVector4 svel4;
    {
        hkVector4 linVelA = mA.getSumLinearVel();
        hkVector4 angVelA = mA.getSumAngularVel();
        hkVector4 linVelB = mB.getSumLinearVel();
        hkVector4 angVelB = mB.getSumAngularVel();
        hkVector4 a; a.setSub4(linVelA, linVelB);
        hkVector4 b; b.setMul4(angVelA, jac.m_kAngularVelocity[0]);
        hkVector4 c; c.setMul4(angVelB, jac.m_kAngularVelocity[1]);
        a.mul4(jac.m_kLinearJacobian);
        b.add4(c);
        svel4.setAdd4(b, a);
    }
    const hkReal ru = info.m_kTimeStep(0) * tau;
    svel4.mul4(ru);
    vel4.mul4(damping);
    hkVector4 dv; dv.setAdd4(svel4, vel4);
    const hkReal rhsUpdate = dv.horizontalAdd3();
    return customRhs * tau - rhsUpdate;
}
__forceinline VectorComponentValue getLinearDv0UserTau(const ConstraintJacobian& jac, const QuantizedBoundsData& mA, const QuantizedBoundsData& mB, const ConstraintSolverInfo& info, hkReal tau, hkReal damping)
{
    return getLinearDv0UserTauWithCustomRhs(jac, mA, mB, info, tau, damping, jac.getRHS());
}
__forceinline VectorComponentValue getAngularDv0UserTauWithCustomRhs(const AngularJacobianElement& jac, const QuantizedBoundsData& mA, const QuantizedBoundsData& mB, const ConstraintSolverInfo& info, hkReal tau, hkReal damping, hkReal customAngularRhs)
{
    hkVector4 vel4;
    {
        hkVector4 angVelA; angVelA.setSub4(mA.m_vAngularVelocity, mA.getSumAngularVel());
        hkVector4 angVelB; angVelB.setSub4(mB.m_vAngularVelocity, mB.getSumAngularVel());
        hkVector4 a; a.setMul4(angVelA, jac.m_kAngularVelocity[0]);
        hkVector4 b; b.setMul4(angVelB, jac.m_kAngularVelocity[1]);
        vel4.setAdd4(a, b);
    }
    hkVector4 svel4;
    {
        hkVector4 angVelA = mA.getSumAngularVel();
        hkVector4 angVelB = mB.getSumAngularVel();
        hkVector4 a; a.setMul4(angVelA, jac.m_kAngularVelocity[0]);
        hkVector4 b; b.setMul4(angVelB, jac.m_kAngularVelocity[1]);
        svel4.setAdd4(a, b);
    }
    const hkReal ru = info.m_kTimeStep(0) * tau;
    svel4.mul4(ru);
    vel4.mul4(damping);
    hkVector4 dv; dv.setAdd4(svel4, vel4);
    const hkReal rhsUpdate = dv.horizontalAdd3();
    return customAngularRhs * tau - rhsUpdate;
}
__forceinline VectorComponentValue getAngularDv0UserTau(const AngularJacobianElement& jac, const QuantizedBoundsData& mA, const QuantizedBoundsData& mB, const ConstraintSolverInfo& info, hkReal tau, hkReal damping)
{
    return getAngularDv0UserTauWithCustomRhs(jac, mA, mB, info, tau, damping, jac.getAngularRhs());
}
__forceinline void applyImpulse(hkSimdRealParameter imp, const ConstraintJacobian& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr)
{
    hkVector4 impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    hkVector4 impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    hkVector4 impLinA; impLinA.setBroadcast3clobberW(impA, 3);
    hkVector4 negImpLinB; negImpLinB.setBroadcast3clobberW(impB, 3);
    impLinA.mul4(jac.m_kLinearJacobian);
    negImpLinB.mul4(jac.m_kLinearJacobian);
    mA.m_vLinearVelocity.add3clobberW(impLinA);
    mB.m_vLinearVelocity.sub3clobberW(negImpLinB);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    VectorComponentValue s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    hkSimdReal_store(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void applyImpulseX(hkSimdRealParameter imp, const ConstraintJacobian& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr)
{
    hkVector4 impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    hkVector4 impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    hkVector4 impLinA; impLinA.setBroadcast3clobberW(impA, 3);
    hkVector4 negImpLinB; negImpLinB.setBroadcast3clobberW(impB, 3);
    impLinA.mul4(jac.m_kLinearJacobian);
    negImpLinB.mul4(jac.m_kLinearJacobian);
    mA.m_vLinearVelocity.add3clobberW(impLinA);
    mB.m_vLinearVelocity.sub3clobberW(negImpLinB);
    hkVector4& oA = mA.m_vAngularVelocity;
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    VectorComponentValue s = sr.m_fAccumulatedImpulse;
    oA.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    _mm_store_ss(&sr.m_fAccumulatedImpulse, s.m_vValue);
}
__forceinline void applyImpulse0X(hkSimdRealParameter imp, const ConstraintJacobian& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr)
{
    applyImpulseX(imp, jac, mA, mB, sr);
}
__forceinline void applyImpulse0(hkSimdRealParameter imp, const ConstraintJacobian& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr)
{
    applyImpulse(imp, jac, mA, mB, sr);
}
__forceinline void applyImpulse1(hkSimdRealParameter imp, const ConstraintJacobian& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr)
{
    applyImpulse(imp, jac, mA, mB, sr);
}
__forceinline void applyImpulse01(hkSimdRealParameter imp0, hkSimdRealParameter imp1, const ConstraintJacobian* jacs, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* srs)
{
    applyImpulse0(imp0, jacs[0], mA, mB, *srs);
    applyImpulse1(imp1, jacs[1], mA, mB, srs[1]);
}
__forceinline void ApplyAngularImpulseToBodies(hkSimdRealParameter imp, const AngularJacobianElement& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr)
{
    hkVector4 impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    hkVector4 impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    VectorComponentValue s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    hkSimdReal_store(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void applyAngularImpulseSwappedMul(hkSimdRealParameter imp, const AngularJacobianElement& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr)
{
    hkVector4 impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    hkVector4 impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    impB.mul4(jac.m_kAngularVelocity[1]);
    impA.mul4(jac.m_kAngularVelocity[0]);
    VectorComponentValue s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    hkSimdReal_store(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void applyAngularImpulse0(hkSimdRealParameter imp, const AngularJacobianElement& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr)
{
    ApplyAngularImpulseToBodies(imp, jac, mA, mB, sr);
}
__forceinline void getDv01(const ConstraintJacobian* jac, const QuantizedBoundsData& mA, const QuantizedBoundsData& mB, const ConstraintSolverInfo& info, hkVector4& velOut)
{
    velOut(0) = getLinearDv0(jac[0], mA, mB, info);
    velOut(1) = getLinearDv0(jac[1], mA, mB, info);
}
__forceinline void getDv012(const Friction3DSchema* jac, const QuantizedBoundsData& mA, const QuantizedBoundsData& mB, const ConstraintSolverInfo& info, hkVector4& velOut)
{
    velOut(0) = getLinearDv0(jac->m_kFirstFrictionJacobian, mA, mB, info);
    velOut(1) = getLinearDv0(jac->m_kSecondFrictionJacobian, mA, mB, info);
    velOut(2) = getAngularDv0(jac->m_kAngularVelocity, mA, mB, info);
}
__forceinline void SolveSingleContact(const ConstraintSolverInfo& info, const JacobianPointerSchema& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    {
        VectorComponentValue dv = getLinearDv0(schema, mA, mB, info);
        VectorComponentValue impulse = dv * schema.getInvJacDiagSr();
        VectorComponentValue negPreviousImpulse = VectorComponentValue(DAT_010c7160) - VectorComponentValue(sr->m_fAccumulatedImpulse);
        hkSimdReal_setMax(negPreviousImpulse, impulse, impulse);
        applyImpulse0(impulse, schema, mA, mB, *sr);
    }
}
__forceinline void solveSingleLimitContact(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const JacobianPointerSchema& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    VectorComponentValue dv = getLinearDv0(schema, mA, mB, info);
    {
        VectorComponentValue impulse = dv * schema.getInvJacDiagSr();
        VectorComponentValue maxImpulse = schema.getUserValueSr();
        VectorComponentValue impulseApplied = sr->m_fAccumulatedImpulse;
        VectorComponentValue negImpApplied = VectorComponentValue(DAT_010c7160) - impulseApplied;
        maxImpulse = maxImpulse - impulseApplied;
        hkSimdReal_setMax(negImpApplied, impulse, impulse);
        hkSimdReal_setMin(maxImpulse, impulse, impulse);
        applyImpulse0(impulse, schema, mA, mB, *sr);
    }
}
__forceinline void solvePairContact(const ConstraintSolverInfo& info, const JacobianPair& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr)
{
    hkVector4 dv4;
    getDv01(&schema.m_kFirstFrictionJacobian, mA, mB, info, dv4);
    const hkReal dv0 = dv4(0);
    const hkReal dv1 = dv4(1);
    hkReal imp0 = schema.m_kFirstFrictionJacobian.getUserValue() * dv0 + dv1 * schema.m_offDiag;
    hkReal imp1 = schema.m_kSecondFrictionJacobian.getUserValue() * dv1 + dv0 * schema.m_offDiag;
    if (imp0 > -sr[0].m_fAccumulatedImpulse)
    {
        if (imp1 > -sr[1].m_fAccumulatedImpulse)
        {
            applyImpulse01(imp0, imp1, &schema.m_kFirstFrictionJacobian, mA, mB, sr);
        }
        else
        {
checkImp0:
            VectorComponentValue imp01 = VectorComponentValue(dv4(0)) * schema.m_kFirstFrictionJacobian.getInvJacDiagSr();
            VectorComponentValue negImp = VectorComponentValue(DAT_010c7160) - VectorComponentValue(sr[0].m_fAccumulatedImpulse);
            hkSimdReal_setMax(negImp, imp01, imp01);
            applyImpulse0(imp01, schema.m_kFirstFrictionJacobian, mA, mB, *sr);
        }
    }
    else
    {
        hkReal imp10 = schema.m_kSecondFrictionJacobian.getInvJacDiag() * dv1;
        if (imp10 <= -sr[1].m_fAccumulatedImpulse)
        {
            goto checkImp0;
        }
        applyImpulse1(imp10, schema.m_kSecondFrictionJacobian, mA, mB, sr[1]);
    }
}
__forceinline VectorComponentValue getLinearDv0B(const ConstraintJacobian& jac, const QuantizedBoundsData& mA, const QuantizedBoundsData& mB, const ConstraintSolverInfo& info)
{
    hkQuadReal d = _mm_sub_ps(mA.m_vLinearVelocity.m_vComponents, mB.m_vLinearVelocity.m_vComponents);
    hkQuadReal bq = _mm_mul_ps(mA.m_vAngularVelocity.m_vComponents, jac.m_kAngularVelocity[0].m_vComponents);
    hkQuadReal cq = _mm_mul_ps(mB.m_vAngularVelocity.m_vComponents, jac.m_kAngularVelocity[1].m_vComponents);
    hkQuadReal m = _mm_mul_ps(_mm_load_ps((const float*)&jac.m_kLinearJacobian), d);
    hkVector4 b; b.m_vComponents = _mm_add_ps(_mm_add_ps(bq, cq), m);
    return jac.getRhsSrE() - b.horizontalAdd3();
}
__forceinline void getDv01B(const ConstraintJacobian* jac, const QuantizedBoundsData& mA, const QuantizedBoundsData& mB, const ConstraintSolverInfo& info, hkVector4& velOut)
{
    velOut(0) = getLinearDv0(jac[0], mA, mB, info);
    velOut(1) = getLinearDv0B(jac[1], mA, mB, info);
}
__forceinline void solvePairContactB(const ConstraintSolverInfo& info, const JacobianPair& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr)
{
    hkVector4 dv4;
    getDv01B(&schema.m_kFirstFrictionJacobian, mA, mB, info, dv4);
    const hkReal dv0 = dv4(0);
    const hkReal dv1 = dv4(1);
    hkReal imp0 = schema.m_kFirstFrictionJacobian.getUserValue() * dv0 + dv1 * schema.m_offDiag;
    hkReal imp1 = schema.m_kSecondFrictionJacobian.getUserValue() * dv1 + dv0 * schema.m_offDiag;
    if (imp0 > -sr[0].m_fAccumulatedImpulse)
    {
        if (imp1 > -sr[1].m_fAccumulatedImpulse)
        {
            applyImpulse01(imp0, imp1, &schema.m_kFirstFrictionJacobian, mA, mB, sr);
        }
        else
        {
checkImp0:
            VectorComponentValue imp01 = VectorComponentValue(dv4(0)) * schema.m_kFirstFrictionJacobian.getInvJacDiagSr();
            VectorComponentValue negImp = VectorComponentValue(DAT_010c7160) - VectorComponentValue(sr[0].m_fAccumulatedImpulse);
            hkSimdReal_setMax(negImp, imp01, imp01);
            applyImpulse0(imp01, schema.m_kFirstFrictionJacobian, mA, mB, *sr);
        }
    }
    else
    {
        hkReal imp10 = schema.m_kSecondFrictionJacobian.getInvJacDiag() * dv1;
        if (imp10 <= -sr[1].m_fAccumulatedImpulse)
        {
            goto checkImp0;
        }
        applyImpulse1(imp10, schema.m_kSecondFrictionJacobian, mA, mB, sr[1]);
    }
}
__forceinline void solve3dFriction(const ConstraintSolverInfo& info, const Friction3DSchema& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr)
{
    hkVector4 vel4;
    getDv012(&schema, mA, mB, info, vel4);
    const hkReal dv0 = vel4(0);
    const hkReal dv1 = vel4(1);
    const hkReal dva = vel4(2);
    hkReal angularImp = schema.m_kAngularVelocity.getInvJacDiag() * dva;
    const hkReal maxSquared = schema.m_maxFrictionImpulse * schema.m_maxFrictionImpulse;
    hkReal imp0 = schema.m_kFirstFrictionJacobian.getUserValue() * dv0 + dv1 * schema.m_offDiag;
    hkReal imp1 = schema.m_kSecondFrictionJacobian.getUserValue() * dv1 + dv0 * schema.m_offDiag;
    const hkReal impSquared = imp0 * imp0 + imp1 * imp1 + angularImp * angularImp;
    if (impSquared > maxSquared)
    {
        const hkReal factor = hkMath_sqrtInverse(impSquared) * schema.m_maxFrictionImpulse;
        imp0 *= factor;
        imp1 *= factor;
        angularImp *= factor;
        sr[3].m_fAccumulatedImpulse = factor;
    }
    else
    {
        sr[3].m_fAccumulatedImpulse = 1.0f;
    }
    angularImp *= schema.m_angularFactor;
    applyImpulse01(imp0, imp1, &schema.m_kFirstFrictionJacobian, mA, mB, sr);
    applyAngularImpulse0(angularImp, schema.m_kAngularVelocity, mA, mB, sr[2]);
}
__forceinline void solve2dFriction(const ConstraintSolverInfo& info, const TwoAxisFrictionInfo& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr)
{
    hkVector4 vel4;
    getDv01(&schema.m_kFirstFrictionJacobian, mA, mB, info, vel4);
    const hkReal dv0 = vel4(0);
    const hkReal dv1 = vel4(1);
    const hkReal maxImpulseReg = schema.m_maxFrictionImpulse;
    const hkReal maxSquared = maxImpulseReg * maxImpulseReg;
    hkReal imp0 = schema.m_kFirstFrictionJacobian.getUserValue() * dv0 + dv1 * schema.m_offDiag;
    hkReal imp1 = schema.m_kSecondFrictionJacobian.getUserValue() * dv1 + dv0 * schema.m_offDiag;
    const hkReal impSquared = imp0 * imp0 + imp1 * imp1;
    if (impSquared > maxSquared)
    {
        const hkReal factor = hkMath_sqrt(maxSquared / impSquared);
        imp0 *= factor;
        imp1 *= factor;
        sr[2].m_fAccumulatedImpulse = factor;
    }
    else
    {
        sr[2].m_fAccumulatedImpulse = 1.0f;
    }
    applyImpulse01(imp0, imp1, &schema.m_kFirstFrictionJacobian, mA, mB, sr);
}
__forceinline void rollingFields(hkSimdRealParameter imp, const AngularJacobianElement& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr, hkVector4& field0, const hkVector4& field2)
{
    hkVector4 impA; impA.setMul4(imp, field2);
    hkVector4 impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    VectorComponentValue s = sr.m_fAccumulatedImpulse;
    field0.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    hkSimdReal_store(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void rollingSecond(hkSimdRealParameter imp, const hkVector4& angularA, const hkVector4& angularB, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr, const hkVector4& field0, const hkVector4& field1, hkVector4& outputA)
{
    hkVector4 impA; impA.setMul4(imp, field0);
    hkVector4 impB; impB.setMul4(imp, field1);
    impA.mul4(angularA);
    impB.mul4(angularB);
    VectorComponentValue s = sr.m_fAccumulatedImpulse;
    hkVector4& oA = outputA;
    oA.m_vComponents = _mm_add_ps(oA.m_vComponents, impA.m_vComponents);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    hkSimdReal_store(s, &sr.m_fAccumulatedImpulse);
}

__forceinline void solve2dRollingFriction(const ConstraintSolverInfo& info, const Friction2DSchema& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    const AngularJacobianElement& jac0 = schema.m_kFirstFrictionJacobian;
    const hkReal dv0 = getAngularDv0(jac0, mA, mB, info);
    const AngularJacobianElement& jac1 = schema.m_kSecondFrictionJacobian;
    const hkReal dv1 = getAngularDv0(jac1, mA, mB, info);
    const hkReal maxImpulseReg = schema.m_maxFrictionImpulse;
    const hkReal maxSquared = maxImpulseReg * maxImpulseReg;
    hkReal imp0 = jac0.getInvJacDiag() * dv0;
    hkReal imp1 = jac1.getInvJacDiag() * dv1;
    const hkReal impSquared = imp0 * imp0 + imp1 * imp1;
    if (impSquared > maxSquared)
    {
        const hkReal factor = hkMath_sqrt(maxSquared / impSquared);
        imp0 *= factor;
        imp1 *= factor;
        sr[2].m_fAccumulatedImpulse = factor;
    }
    else
    {
        sr[2].m_fAccumulatedImpulse = 1.0f;
    }
    rollingFields(imp0, jac0, mA, mB, sr[0], mA.m_vAngularVelocity, mA.m_vInverseInertiaAndMass);
    applyAngularImpulse0(imp1, jac1, mA, mB, sr[1]);
}
__forceinline void solve1dAngFriction(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const FrictionImpulseLimitedJacobian& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr)
{
    const hkReal dv0 = getAngularDv0(schema, mA, mB, info);
    hkReal imp0 = schema.getInvJacDiag() * dv0;
    const hkReal fimp0 = hkMath_fabs(imp0);
    if (fimp0 > schema.m_maxFrictionImpulse)
    {
        const hkReal factor = schema.m_maxFrictionImpulse / fimp0;
        imp0 *= factor;
        sr[1].m_fAccumulatedImpulse = factor;
    }
    else
    {
        sr[1].m_fAccumulatedImpulse = 1.0f;
    }
    applyAngularImpulse0(imp0, schema, mA, mB, *sr);
}
__forceinline void lowerApplication(hkSimdRealParameter imp, const AngularJacobianElement& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr, const hkVector4& massA, const hkVector4& massB)
{
    hkVector4 impA; impA.setMul4(imp, massA);
    hkVector4 impB; impB.setMul4(imp, massB);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    VectorComponentValue s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    hkSimdReal_store(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void regionApplication(hkSimdRealParameter imp, const AngularJacobianElement& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr, const hkVector4& massA, const hkVector4& massB, const hkVector4& axisA, const hkVector4& axisB);
__forceinline void nativeApplication(hkSimdRealParameter imp, const AngularJacobianElement& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr);
__forceinline void solve1dAngLimits(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const AngularLimitJacobian& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    const hkReal dv = getAngularDv0UserTau(schema, mA, mB, info, schema.m_userTau, info.m_fMotorDamping);
    const hkReal negAppliedImpulse = -sr->m_fAccumulatedImpulse;
    {
        hkReal impulse = dv - schema.m_minLimit;
        impulse = schema.getInvJacDiag() * impulse;
        if (impulse > negAppliedImpulse)
        {
            rollingFields(impulse, schema, mA, mB, *sr, mA.m_vAngularVelocity, mA.m_vInverseInertiaAndMass);
            return;
        }
    }
    {
        hkReal impulse = dv - schema.m_maxLimit;
        impulse = schema.getInvJacDiag() * impulse;
        if (impulse < negAppliedImpulse)
        {
            regionApplication(impulse, schema, mA, mB, *sr, mA.m_vInverseInertiaAndMass, mB.m_vInverseInertiaAndMass, schema.m_kAngularVelocity[0], schema.m_kAngularVelocity[1]);
        }
    }
}
__forceinline void regionApplication(hkSimdRealParameter imp, const AngularJacobianElement& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr, const hkVector4& massA, const hkVector4& massB, const hkVector4& axisA, const hkVector4& axisB)
{
    hkVector4 impA; impA.setMul4(imp, massA);
    hkVector4 impB; impB.setMul4(imp, massB);
    impA.mul4(axisA);
    impB.mul4(axisB);
    VectorComponentValue s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    hkSimdReal_store(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void solve1dAngularMotor(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const MotorInfoRecord& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    const hkpMotorInfo& motorInfo = schema.m_pMotor;
    sr[2].m_fAccumulatedImpulse = temp.m_stepFactor * motorInfo.m_fVelocity + sr[2].m_fAccumulatedImpulse;
    const hkReal customAngularRhs = schema.getAngularRhs() + sr[2].m_fAccumulatedImpulse;
    const hkReal dv0 = getAngularDv0UserTauWithCustomRhs(schema, mA, mB, info, motorInfo.m_fTau, motorInfo.m_fMotorDamping, customAngularRhs);
    hkReal impulse = schema.getInvJacDiag() * dv0;
    if (impulse > motorInfo.m_minImpulse)
    {
        sr[1].m_fAccumulatedImpulse = motorInfo.m_minImpulse / impulse;
        impulse = motorInfo.m_minImpulse;
    }
    else if (impulse < motorInfo.m_usFlags)
    {
        sr[1].m_fAccumulatedImpulse = motorInfo.m_usFlags / impulse;
        impulse = motorInfo.m_usFlags;
    }
    else
    {
        sr[1].m_fAccumulatedImpulse = 1.0f;
    }
    applyAngularImpulse0(impulse, schema, mA, mB, *sr);
}
__forceinline void nativeApplication(hkSimdRealParameter imp, const AngularJacobianElement& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr)
{
    hkVector4 impA; impA = _mm_mul_ps(imp.broadcast(), mA.m_vInverseInertiaAndMass);
    hkVector4 impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    impB.mul4(jac.m_kAngularVelocity[1]);
    impA.mul4(jac.m_kAngularVelocity[0]);
    VectorComponentValue s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    hkSimdReal_store(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void solve1dAngular(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const JacobianHolder& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    VectorComponentValue dv = getAngularDv0(schema, mA, mB, info);
    VectorComponentValue impulse = dv * schema.getInvJacDiagSr();
    nativeApplication(impulse, schema, mA, mB, *sr);
}
__forceinline void applyImpulseG(hkSimdRealParameter imp, const ConstraintJacobian& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr, const hkVector4& massA)
{
    hkVector4 impA; impA = massA; impA.mul4(imp);
    hkVector4 impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    hkVector4 impLinA; impLinA.setBroadcast3clobberW(impA, 3);
    hkVector4 negImpLinB; negImpLinB.setBroadcast3clobberW(impB, 3);
    impLinA.setMul4(jac.m_kLinearJacobian, impLinA);
    negImpLinB.mul4(jac.m_kLinearJacobian);
    mA.m_vLinearVelocity.add3clobberW(impLinA);
    mB.m_vLinearVelocity.sub3clobberW(negImpLinB);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    VectorComponentValue s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    hkSimdReal_store(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void solve1dBilateral(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const JacobianDataHolder& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    VectorComponentValue vel = getLinearDv0(schema, mA, mB, info);
    VectorComponentValue impulse = vel * schema.getInvJacDiagSr();
    applyImpulseG(impulse, schema, mA, mB, *sr, mA.m_vInverseInertiaAndMass);
}
__forceinline void linearApplication(hkSimdRealParameter imp, const ConstraintJacobian& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr, hkVector4& linearA)
{
    hkVector4 impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    hkVector4 impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    hkVector4 impLinA; impLinA.setBroadcast3clobberW(impA, 3);
    hkVector4 negImpLinB; negImpLinB.setBroadcast3clobberW(impB, 3);
    impLinA.mul4(jac.m_kLinearJacobian);
    negImpLinB.mul4(jac.m_kLinearJacobian);
    linearA.add3clobberW(impLinA);
    mB.m_vLinearVelocity.sub3clobberW(negImpLinB);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    VectorComponentValue s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    hkSimdReal_store(s, &sr.m_fAccumulatedImpulse);
}
__forceinline VectorComponentValue fieldProjection(const ConstraintJacobian& jac, const QuantizedBoundsData& mA, const QuantizedBoundsData& mB, const ConstraintSolverInfo& info, const hkVector4& linearA)
{
    hkVector4 a; a.setSub4(linearA, mB.m_vLinearVelocity);
    hkVector4 b; b.setMul4(mA.m_vAngularVelocity, jac.m_kAngularVelocity[0]);
    hkVector4 c; c.setMul4(mB.m_vAngularVelocity, jac.m_kAngularVelocity[1]);
    a.mul4(jac.m_kLinearJacobian);
    b.add4(c);
    b.add4(a);
    const VectorComponentValue vel = b.horizontalAdd3();
    const VectorComponentValue dv = jac.getRhsSr() - vel;
    return dv;
}
__forceinline void solve1dBilateralWithImpulseLimit(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const JacobianDataHolder& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    VectorComponentValue vel = getLinearDv0(schema, mA, mB, info);
    VectorComponentValue impulse = vel * schema.getInvJacDiagSr();
    VectorComponentValue impulseApplied = sr->m_fAccumulatedImpulse;
    VectorComponentValue maxImpulse = schema.getUserValueSr();
    VectorComponentValue minImpulse = -maxImpulse;
    maxImpulse = maxImpulse - impulseApplied;
    minImpulse = minImpulse - impulseApplied;
    hkSimdReal_setMax(minImpulse, impulse, impulse);
    hkSimdReal_setMin(maxImpulse, impulse, impulse);
    applyImpulse0(impulse, schema, mA, mB, *sr);
}
__forceinline void solve1dBilateralUserTau(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const LinearSoftConstraintAtom& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    VectorComponentValue dv = getLinearDv0UserTau(schema, mA, mB, info, schema.m_userTau, schema.m_userDamping);
    VectorComponentValue impulse = dv * schema.getInvJacDiagSr();
    applyImpulse0(impulse, schema, mA, mB, *sr);
}
__forceinline void solve1dFriction(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const FrictionImpulseLimitAtom& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    const hkReal dv0 = getLinearDv0(schema, mA, mB, info);
    hkReal imp0 = schema.getInvJacDiag() * dv0;
    const hkReal fimp0 = hkMath_fabs(imp0);
    if (fimp0 > schema.m_maxFrictionImpulse)
    {
        const hkReal factor = schema.m_maxFrictionImpulse / fimp0;
        imp0 *= factor;
        sr[1].m_fAccumulatedImpulse = factor;
    }
    else
    {
        sr[1].m_fAccumulatedImpulse = 1.0f;
    }
    applyImpulse0(imp0, schema, mA, mB, *sr);
}
__forceinline void solve1dLinLimits(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const LinearDistanceLimitAtom& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    const hkReal dv = getLinearDv0(schema, mA, mB, info);
    const hkReal negAppliedImpulse = -sr->m_fAccumulatedImpulse;
    {
        hkReal impulse = dv - schema.m_minLimit;
        impulse = schema.getInvJacDiag() * impulse;
        if (impulse > negAppliedImpulse)
        {
            applyImpulse0(impulse, schema, mA, mB, *sr);
        }
    }
    {
        hkReal impulse = dv - schema.m_maxLimit;
        impulse = schema.getInvJacDiag() * impulse;
        if (impulse < negAppliedImpulse)
        {
            applyImpulse0(impulse, schema, mA, mB, *sr);
        }
    }
}
__forceinline void solve1dLinearMotor(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const MotorSolverSchema& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    const hkpMotorInfo& motorInfo = schema.m_pMotor;
    sr[2].m_fAccumulatedImpulse = temp.m_stepFactor * motorInfo.m_fVelocity + sr[2].m_fAccumulatedImpulse;
    const hkReal customRhs = schema.getRHS() + sr[2].m_fAccumulatedImpulse;
    const hkReal dv0 = getLinearDv0UserTauWithCustomRhs(schema, mA, mB, info, motorInfo.m_fTau, motorInfo.m_fMotorDamping, customRhs);
    hkReal impulse = schema.getInvJacDiag() * dv0;
    if (impulse > motorInfo.m_minImpulse)
    {
        sr[1].m_fAccumulatedImpulse = motorInfo.m_minImpulse / impulse;
        impulse = motorInfo.m_minImpulse;
    }
    else if (impulse < motorInfo.m_usFlags)
    {
        sr[1].m_fAccumulatedImpulse = motorInfo.m_usFlags / impulse;
        impulse = motorInfo.m_usFlags;
    }
    else
    {
        sr[1].m_fAccumulatedImpulse = 1.0f;
    }
    applyImpulse0(impulse, schema, mA, mB, *sr);
}
__forceinline VectorComponentValue getDv2Lin2Ang(const JacobianElement& jac, const QuantizedBoundsData& mA, const QuantizedBoundsData& mB, const ConstraintSolverInfo& info)
{
    hkVector4 lA; lA.setMul4(mA.m_vLinearVelocity, jac.m_kTranslationalVelocity[0]);
    hkVector4 lB; lB.setMul4(mB.m_vLinearVelocity, jac.m_kTranslationalVelocity[1]);
    hkVector4 a; a.setMul4(mA.m_vAngularVelocity, jac.m_kAngularVelocity[0]);
    hkVector4 b; b.setMul4(mB.m_vAngularVelocity, jac.m_kAngularVelocity[1]);
    hkVector4 c; c.setSub4(lA, lB);
    a.add4(b);
    a.add4(c);
    const VectorComponentValue vel = a.horizontalAdd3();
    const VectorComponentValue dv = SubtractScalarFloat(jac.getRhsSr(), vel);
    return dv;
}
__forceinline void applyImpulse2Lin2Ang(hkSimdRealParameter imp, const JacobianElement& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr)
{
    hkVector4 impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    hkVector4 impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    hkVector4 impLinA; impLinA.setBroadcast3clobberW(impA, 3);
    hkVector4 impLinB; impLinB.setBroadcast3clobberW(impB, 3);
    impLinA.mul4(jac.m_kTranslationalVelocity[0]);
    impLinB.mul4(jac.m_kTranslationalVelocity[1]);
    mA.m_vLinearVelocity.add3clobberW(impLinA);
    mB.m_vLinearVelocity.sub3clobberW(impLinB);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    VectorComponentValue s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    VectorComponentValue sum; sum=AddScalarFloat(s,imp); s=sum;
    hkSimdReal_store(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void solvePulley(const ConstraintSolverInfo& info, const SingleJacobianSchema& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    VectorComponentValue dv = getDv2Lin2Ang(schema, mA, mB, info);
    {
        VectorComponentValue impulse = (*(::VectorComponentValue *)(::FUN_00891060((::Vec4Dst *)&(dv), (::Vec4Src *)&(const ::VectorComponentValue &)(schema.getInvJacDiagSr()), {})));
        applyImpulse2Lin2Ang(impulse, schema, mA, mB, sr[0]);
    }
}
__forceinline int stepJacobian(const ConstraintSolverInfo& info, SolverStepInfo& temp, const SolverSchemaHeader* schemas, QuantizedBoundsData* accums, FloatRecord* srIn)
{
    const SolverSchemaHeader* com = schemas;
    FloatRecord* sr = srIn;
    SolverSchemaType schemaType = getType(com);
    if (schemaType == SCHEMA_TYPE_END)
    {
        return 0;
    }
    QuantizedBoundsData* mA;
    QuantizedBoundsData* mB;
    FloatRecord* delayedResult = 0;
    goto headerNoStoreVelocity;
    while (1)
    {
        schemaType = getType(com);
        switch (schemaType)
        {
        case SCHEMA_TYPE_HEADER:
header:
            {
                const ConstraintHeaderSchema* sc = reinterpret_cast<const ConstraintHeaderSchema*>(com);
                prefetchVelocityAccumulators(*sc->getBodyA(accums), *sc->getBodyB(accums));
                storeVelocityAccumulators(*mA, *mB);
headerNoStoreVelocity:
                {
                    const ConstraintHeaderSchema* sc = reinterpret_cast<const ConstraintHeaderSchema*>(com);
                    mA = sc->getBodyA(accums);
                    mB = sc->getBodyB(accums);
                    loadVelocityAccumulators(*mA, *mB);
                    com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                }
                break;
            }
        case SCHEMA_TYPE_NOP:
            {
                const ConstraintHeaderSchema* sc = reinterpret_cast<const ConstraintHeaderSchema*>(com);
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                break;
            }
        case SCHEMA_TYPE_SINGLE_CONTACT:
        case SCHEMA_TYPE_SINGLE_CONTACT2:
case_SINGLE_CONTACT:
            {
                const JacobianPointerSchema* sc = reinterpret_cast<const JacobianPointerSchema*>(com);
                SolveSingleContact(info, *sc, *mA, *mB, sr, delayedResult);
                sr += getNumSolverElemTemps(com);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_SINGLE_CONTACT) goto case_SINGLE_CONTACT;
                break;
            }
        case SCHEMA_TYPE_SINGLE_LIMIT_CONTACT:
        case SCHEMA_TYPE_SINGLE_LIMIT_CONTACT2:
case_SINGLE_LIMIT_CONTACT:
            {
                const JacobianPointerSchema* sc = reinterpret_cast<const JacobianPointerSchema*>(com);
                solveSingleLimitContact(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += getNumSolverElemTemps(com);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_SINGLE_LIMIT_CONTACT) goto case_SINGLE_LIMIT_CONTACT;
                break;
            }
        case SCHEMA_TYPE_PAIR_CONTACT:
        case SCHEMA_TYPE_PAIR_CONTACT2:
            {
                const JacobianPair* sc = reinterpret_cast<const JacobianPair*>(com);
                solvePairContact(info, *sc, *mA, *mB, sr);
                sr += 2;
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(getType(com) != SCHEMA_TYPE_PAIR_CONTACT))->FUN_005609f0()) continue;
            }
            {
                const JacobianPair* sc = reinterpret_cast<const JacobianPair*>(com);
                solvePairContactB(info, *sc, *mA, *mB, sr);
                sr += 2;
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(getType(com) != SCHEMA_TYPE_3D_FRICTION))->FUN_005609f0()) break;
            }
        case SCHEMA_TYPE_3D_FRICTION:
friction3d:
            {
                const Friction3DSchema* sc = reinterpret_cast<const Friction3DSchema*>(com);
                solve3dFriction(info, *sc, *mA, *mB, sr);
                sr += 4;
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_HEADER) goto header;
                break;
            }
        case SCHEMA_TYPE_2D_FRICTION:
friction2d:
            {
                const TwoAxisFrictionInfo* sc = reinterpret_cast<const TwoAxisFrictionInfo*>(com);
                solve2dFriction(info, *sc, *mA, *mB, sr);
                sr += 3;
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_HEADER) goto header;
                break;
            }
        case SCHEMA_TYPE_2D_ROLLING_FRICTION:
            {
                const Friction2DSchema* schema = reinterpret_cast<const Friction2DSchema*>(com);
                solve2dRollingFriction(info, *schema, *mA, *mB, sr, delayedResult);
                sr += FUN_00d921d0(&com->m_type.m_kStorage);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(schema + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(schema + 1);
                if (comtype == SCHEMA_TYPE_3D_FRICTION) goto friction3d;
                if (comtype == SCHEMA_TYPE_2D_FRICTION) goto friction2d;
                break;
            }
        case SCHEMA_TYPE_1D_ANGULAR_FRICTION:
case_1D_ANGULAR_FRICTION:
            {
                const FrictionImpulseLimitedJacobian* sc = reinterpret_cast<const FrictionImpulseLimitedJacobian*>(com);
                solve1dAngFriction(info, temp, *sc, *mA, *mB, sr);
                sr += FUN_00d921d0(&com->m_type.m_kStorage);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_ANGULAR_FRICTION) goto case_1D_ANGULAR_FRICTION;
                break;
            }
        case SCHEMA_TYPE_1D_ANGULAR_LIMITS:
case_1D_ANGULAR_LIMITS:
            {
                const AngularLimitJacobian* sc = reinterpret_cast<const AngularLimitJacobian*>(com);
                solve1dAngLimits(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += FUN_00d921d0(&com->m_type.m_kStorage);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_ANGULAR_LIMITS) goto case_1D_ANGULAR_LIMITS;
                break;
            }
        case SCHEMA_TYPE_1D_ANGULAR_MOTOR:
case_1D_ANGULAR_MOTOR:
            {
                const MotorInfoRecord* sc = reinterpret_cast<const MotorInfoRecord*>(com);
                solve1dAngularMotor(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += FUN_00d921d0(&com->m_type.m_kStorage);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_ANGULAR_MOTOR) goto case_1D_ANGULAR_MOTOR;
                break;
            }
        case SCHEMA_TYPE_1D_ANGULAR:
case_1D_ANGULAR:
            {
                const JacobianHolder* sc = reinterpret_cast<const JacobianHolder*>(com);
                solve1dAngular(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += FUN_00d921d0(&com->m_type.m_kStorage);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_ANGULAR) goto case_1D_ANGULAR;
                break;
            }
        case SCHEMA_TYPE_1D_BILATERAL:
case_1D_BILATERAL:
            {
                const JacobianDataHolder* sc = reinterpret_cast<const JacobianDataHolder*>(com);
                solve1dBilateral(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += FUN_00d921d0(&com->m_type.m_kStorage);
                const SolverSchemaType comtype = FUN_00d921c0(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_BILATERAL) goto case_1D_BILATERAL;
                break;
            }
        case SCHEMA_TYPE_1D_BILATERAL_WITH_IMPULSE_LIMIT:
case_1D_BILATERAL_WITH_IMPULSE_LIMIT:
            {
                const JacobianDataHolder* sc = reinterpret_cast<const JacobianDataHolder*>(com);
                solve1dBilateralWithImpulseLimit(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += FUN_00d921d0(&com->m_type.m_kStorage);
                const SolverSchemaType comtype = FUN_00d921c0(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_BILATERAL_WITH_IMPULSE_LIMIT) goto case_1D_BILATERAL_WITH_IMPULSE_LIMIT;
                break;
            }
        case SCHEMA_TYPE_1D_BILATERAL_USER_TAU:
case_1D_BILATERAL_USER_TAU:
            {
                const LinearSoftConstraintAtom* sc = reinterpret_cast<const LinearSoftConstraintAtom*>(com);
                solve1dBilateralUserTau(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += FUN_00d921d0(&com->m_type.m_kStorage);
                const SolverSchemaType comtype = FUN_00d921c0(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_BILATERAL_USER_TAU) goto case_1D_BILATERAL_USER_TAU;
                break;
            }
        case SCHEMA_TYPE_1D_FRICTION:
case_1D_FRICTION:
            {
                const FrictionImpulseLimitAtom* sc = reinterpret_cast<const FrictionImpulseLimitAtom*>(com);
                solve1dFriction(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += FUN_00d921d0(&com->m_type.m_kStorage);
                const SolverSchemaType comtype = FUN_00d921c0(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_FRICTION) goto case_1D_FRICTION;
                break;
            }
        case SCHEMA_TYPE_1D_LINEAR_LIMITS:
case_1D_LINEAR_LIMITS:
            {
                const LinearDistanceLimitAtom* sc = reinterpret_cast<const LinearDistanceLimitAtom*>(com);
                solve1dLinLimits(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += FUN_00d921d0(&com->m_type.m_kStorage);
                const SolverSchemaType comtype = FUN_00d921c0(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_LINEAR_LIMITS) goto case_1D_LINEAR_LIMITS;
                break;
            }
        case SCHEMA_TYPE_1D_LINEAR_MOTOR:
case_1D_LINEAR_MOTOR:
            {
                const MotorSolverSchema* sc = reinterpret_cast<const MotorSolverSchema*>(com);
                solve1dLinearMotor(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += FUN_00d921d0(&com->m_type.m_kStorage);
                const SolverSchemaType comtype = FUN_00d921c0(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_LINEAR_MOTOR) goto case_1D_LINEAR_MOTOR;
                break;
            }
        case SCHEMA_TYPE_1D_PULLEY:
            {
                const SingleJacobianSchema* sc = reinterpret_cast<const SingleJacobianSchema*>(com);
                solvePulley(info, *sc, *mA, *mB, sr, delayedResult);
                sr += 1;
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                break;
            }
        case SCHEMA_TYPE_SET_MASS:
            {
                const SetInverseMassSchema* sc = reinterpret_cast<const SetInverseMassSchema*>(com);
                storeVelocityAccumulators(*mA, *mB);
                mA->m_vInverseInertiaAndMass = sc->m_invMassA;
                mB->m_vInverseInertiaAndMass = sc->m_invMassB;
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                loadVelocityAccumulators(*mA, *mB);
                break;
            }
        case SCHEMA_TYPE_ADD_VELOCITY:
            {
                const AddVelocitySchema* sc = reinterpret_cast<const AddVelocitySchema*>(com);
                storeVelocityAccumulators(*mA, *mB);
                const int bodyIndex = sc->m_iBodyIndex;
                QuantizedBoundsData* accum = hkSelect(bodyIndex, mA, mB);
                const hkReal f = info.m_kGravity(0) * hkReal(int(temp.m_intStep));
                VectorComponentValue fs;
                new ((void *)&(fs)) ::FUN_005dbf20(f);
                hkVector4 integratedVel; integratedVel.setMul4(fs, sc->m_fVelocity);
                sc->m_fVelocity.commitIncrement(accum->m_vLinearVelocity);
                accum->m_vLinearVelocity.add4(integratedVel);
                accum->getSumLinearVel().add4(integratedVel);
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                loadVelocityAccumulators(*mA, *mB);
                break;
            }
        case SCHEMA_TYPE_SET_CENTER_OF_MASS:
            {
                const hkpJacobianSetComSchema* sc = reinterpret_cast<const hkpJacobianSetComSchema*>(com);
                storeVelocityAccumulators(*mA, *mB);
                hkVector4 deltaVelA; reinterpret_cast<::FUN_00c7f750_shell *>(&(deltaVelA))->FUN_00c7f750((float *)&(sc->m_angularA), (float *)&(mA->m_vAngularVelocity));
                hkVector4 deltaVelB; reinterpret_cast<::FUN_00c7f750_shell *>(&(deltaVelB))->FUN_00c7f750((float *)&(sc->m_angularB), (float *)&(mB->m_vAngularVelocity));
                hkVector4 deltaSumVelA; reinterpret_cast<::FUN_00c7f750_shell *>(&(deltaSumVelA))->FUN_00c7f750((float *)&(sc->m_angularA), (float *)&(mA->getSumAngularVel()));
                hkVector4 deltaSumVelB; reinterpret_cast<::FUN_00c7f750_shell *>(&(deltaSumVelB))->FUN_00c7f750((float *)&(sc->m_angularB), (float *)&(mB->getSumAngularVel()));
                mA->m_vLinearVelocity.add4(deltaVelA);
                mA->getSumLinearVel().add4(deltaSumVelA);
                mB->m_vLinearVelocity.add4(deltaVelB);
                mB->getSumLinearVel().add4(deltaSumVelB);
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                loadVelocityAccumulators(*mA, *mB);
                break;
            }
        case SCHEMA_TYPE_GOTO:
            {
                const SchemaJump* sc = reinterpret_cast<const SchemaJump*>(com);
                com = hkAddByteOffsetConst(com, sc->m_offset);
                break;
            }
        case SCHEMA_TYPE_END:
            storeDelayedResult(delayedResult);
            storeVelocityAccumulators(*mA, *mB);
            return 0;
        case SCHEMA_TYPE_STIFF_SPRING_CHAIN:
            {
                const hkpStiffChainSchema* chain = reinterpret_cast<const hkpStiffChainSchema*>(com);
                ::FUN_00d893a0(&info, &temp, accums, (::ProbeHeader *)(chain), (float *)(sr));
                sr += chain->m_iConstraintCount;
                com = hkAddByteOffsetConst(com, chain->m_sizeOfNext);
                break;
            }
        case SCHEMA_TYPE_BALL_SOCKET_CHAIN:
            {
                const hkpBallChainSchema* chain = reinterpret_cast<const hkpBallChainSchema*>(com);
                ::FUN_00d89690((*(const ::hkpSolverInfoQ *)(&info)), (*(const ::hkSolverQ::SolverStepInfo *)(&temp)), (::hkpVelocityAccumulatorQ *)(accums), (::hkpJacobianBallSocketChainSchemaQ *)(chain), (::hkpSolverElemTempQ *)(sr));
                sr += 3 * chain->m_iConstraintCount;
                com = hkAddByteOffsetConst(com, chain->m_sizeOfNext);
                break;
            }
        case SCHEMA_TYPE_POWERED_CHAIN:
            {
                const hkpPoweredChainSchema* chain = reinterpret_cast<const hkpPoweredChainSchema*>(com);
                ::FUN_00d8a3a0((*(const ::PoweredChainSettings *)(&info)), (*(const ::PoweredChainSolver::PoweredChainStepTemp *)(&temp)), (::PoweredChainAccumulator *)(accums), (::PoweredChainSchema *)(chain), (::PoweredChainResult *)(sr));
                sr += 6 * chain->m_pBodyA;
                com = hkAddByteOffsetConst(com, chain->m_nextOffset);
                break;
            }
        default:
            fnv_Breakpoint();
            return 0;
        }
    }
}
// @fnv 0x00d8aac0
extern "C" void __cdecl FUN_00d8aac0(const ConstraintSolverInfo& info, const SolverSchemaHeader* schemas, QuantizedBoundsData* accumulators, FloatRecord* elemTemp)
{
    SolverNs::loadFixedRegisters();
    SolverStepInfo temp;
    temp.m_intStep = 0;
    temp.m_stepFactor = 0.0f;
    stepJacobian(info, temp, schemas, accumulators, elemTemp);
}

class Scalar {
    union { __m128 q; float components[4]; };
public:
    Scalar() {}
    Scalar(const __m128& v):q(v) {}
    Scalar(float v):q(_mm_load_ss(&v)) {}
    operator float() const { float v; _mm_store_ss(&v,q); return v; }
    __forceinline __m128 broadcast() const { return _mm_shuffle_ps(q,q,0); }
    __forceinline const __m128& get() const { return q; }
};
inline Scalar operator+(const Scalar& a,const Scalar& b) {return _mm_add_ss(a.get(),b.get());}
inline void storeScalar(const Scalar& a,float* p) {_mm_store_ss(p,a.get());}
class Vec {
    union { __m128 q; float components[4]; };
public:
    __forceinline __m128 get() const {return q;}
    __forceinline void set(__m128 v) {q=v;}
    __forceinline void operator=(const Vec& v) {q=v.q;}
    __forceinline void setSub4(const Vec& a,const Vec& b) {q=_mm_sub_ps(a.q,b.q);}
    __forceinline void setAdd4(const Vec& a,const Vec& b) {q=_mm_add_ps(a.q,b.q);}
    __forceinline void setMul4(const Vec& a,const Vec& b) {q=_mm_mul_ps(a.q,b.q);}
    __forceinline void setMul4(const Scalar& a,const Vec& b) {q=_mm_mul_ps(a.broadcast(),b.q);}
    __forceinline void add4(const Vec& b) {q=_mm_add_ps(q,b.q);}
    __forceinline void mul4(const Vec& b) {q=_mm_mul_ps(q,b.q);}
    __forceinline void mul4(const Scalar& b) {q=_mm_mul_ps(b.broadcast(),q);}
    __forceinline void add3clobberW(const Vec& b) {q=_mm_add_ps(q,b.q);}
    __forceinline void sub3clobberW(const Vec& b) {q=_mm_sub_ps(q,b.q);}
    __forceinline void setBroadcast3clobberW(const Vec& b,int component) {q=_mm_shuffle_ps(b.q,b.q,0xff);}
    __forceinline const float& operator()(int component) const {return q[component];}
    __forceinline Scalar horizontalAdd3() const {
        __m128 xy=_mm_add_ss(_mm_shuffle_ps(q,q,0x55),q);
        return _mm_add_ss(_mm_shuffle_ps(q,q,0xaa),xy);
    }
};

struct ProbeBody { Vec reserved, linear, angular, mass, baseLinear, baseAngular; };
struct ProbeRow { Vec axis, angularA, angularB; };
struct ProbeCoeff { float lower, diagonal, upper; };
struct ProbeSettings { Vec a,b,c,d; float scale; };
struct ProbeHeader {
    unsigned short type, count; int flags; float strength, damping;
    ProbeRow* rows() { return (ProbeRow*)(this+1); }
    ProbeCoeff* coefficients() { return (ProbeCoeff*)(rows()+count); }
    float* values() { return &(coefficients()+count)->diagonal; }
    int* offsets() { return (int*)(values()+count); }
};
inline const ProbeSettings* settingsAt(const void* p) {return static_cast<const ProbeSettings*>(p);}
static __forceinline Scalar calculateRhs(const ProbeRow& row, const ProbeBody& a, const ProbeBody& b, const ProbeSettings& settings, float strength, float damping, float rhs) {
    Vec relative;
    {
        Vec linA; linA.setSub4(a.linear,a.baseLinear);
        Vec angA; angA.setSub4(a.angular,a.baseAngular);
        Vec linB; linB.setSub4(b.linear,b.baseLinear);
        Vec angB; angB.setSub4(b.angular,b.baseAngular);
        Vec delta; delta.setSub4(linA,linB);
        Vec termA; termA.setMul4(angA,row.angularA);
        Vec termB; termB.setMul4(angB,row.angularB);
        delta.mul4(row.axis);
        termA.add4(termB);
        relative.setAdd4(termA,delta);
    }
    Vec baseline;
    {
        Vec linA = a.baseLinear;
        Vec angA = a.baseAngular;
        Vec linB = b.baseLinear;
        Vec angB = b.baseAngular;
        Vec delta; delta.setSub4(linA,linB);
        Vec termA; termA.setMul4(angA,row.angularA);
        Vec termB; termB.setMul4(angB,row.angularB);
        delta.mul4(row.axis);
        termA.add4(termB);
        baseline.setAdd4(termA,delta);
    }
    baseline.mul4(settings.scale*strength);
    relative.mul4(damping);
    Vec total; total.setAdd4(baseline,relative);
    float reduction=total.horizontalAdd3();
    float result=rhs*strength-reduction;
    return result;
}
static __forceinline void applyDirect(float value,const ProbeRow* row,ProbeBody* a,ProbeBody* b,float* output) {
__m128 scalar=_mm_load_ss(&value);
__m128 factor=_mm_shuffle_ps(scalar,scalar,0);
__m128 massA=_mm_mul_ps(a->mass.get(),factor);
__m128 massB=_mm_mul_ps(b->mass.get(),factor);
Vec linA; linA.set(_mm_shuffle_ps(massA,massA,0xff));
Vec linB; linB.set(_mm_shuffle_ps(massB,massB,0xff));
linA.mul4(row->axis);
linB.mul4(row->axis);
a->linear.add3clobberW(linA);
b->linear.sub3clobberW(linB);
__m128 angA=_mm_mul_ps(row->angularA.get(),massA);
angA=_mm_add_ps(angA,a->angular.get());
__m128 angB=_mm_mul_ps(row->angularB.get(),massB);
a->angular.set(angA);
b->angular.set(_mm_add_ps(angB,b->angular.get()));
__m128 oldOutput=_mm_load_ss(output);
_mm_store_ss(output,_mm_add_ss(oldOutput,scalar));
}
// @fnv 0x00d893a0
void __cdecl FUN_00d893a0(const void* settingsAddress, void* unused, void* bodyBase, ProbeHeader* header, float* output)
{
    ProbeRow* rowData;
    long count;
    int* indices;
    float* values;
    ProbeCoeff* coeff;
    (void)rowData;
    (void)count;
    (void)indices;
    (void)values;
    (void)coeff;
    char* bodies = static_cast<char*>(bodyBase);
    count = header->count;
    rowData = header->rows();
    indices = header->offsets();
    coeff = header->coefficients();
    values = header->values();
    values[-1] = 0.0f;
    for (int i=0; i<count; ++i) {
        ProbeBody* a = (ProbeBody*)(bodies+indices[i]);
        ProbeBody* b = (ProbeBody*)(bodies+indices[i+1]);
        Scalar rhs=calculateRhs(rowData[i],*a,*b,*settingsAt(settingsAddress),header->strength,header->damping,rowData[i].axis(3));
        values[i]=(float(rhs)-values[i-1]*coeff[i].lower)/coeff[i].diagonal;
    }
    float impulse=0.0f;
    for (int i=count-1; i>=0; --i) {
        impulse=values[i]-coeff[i].upper*impulse;
        ProbeBody* __restrict a = (ProbeBody*)(bodies+indices[i]);
        ProbeBody* b = (ProbeBody*)(bodies+indices[i+1]);
        applyDirect(impulse,rowData+i,a,b,output+i);
    }
}






class hkSimdRealQ {
public:
    hkSimdRealQ(const __m128& x) : m_vValue(x) {}
    hkSimdRealQ(float x) { m_vValue = _mm_load_ss(&x); }
    hkSimdRealQ() {}
    operator float() const { float s; _mm_store_ss(&s, m_vValue); return s; }
    __forceinline __m128 broadcast() const { return _mm_shuffle_ps(getQuad(), getQuad(), 0); }
    __forceinline __m128 getQuad() const { return m_vValue; }
private:
    __m128 m_vValue;
};
typedef const hkSimdRealQ& hkSimdRealParameterQ;
inline hkSimdRealQ operator+(hkSimdRealParameterQ r, hkSimdRealParameterQ s) { return _mm_add_ss(r.getQuad(), s.getQuad()); }
__forceinline void hkSimdReal_storeQ(hkSimdRealParameterQ a, float* p) { _mm_store_ss(p, a.getQuad()); }

class hkMatrix3Q;
class hkVector4Q {
public:
    __forceinline void operator=(const __m128& v) { m_vComponents = v; }
    __forceinline float& operator()(int i) { return reinterpret_cast<float*>(&m_vComponents)[i]; }
    __forceinline const float& operator()(int i) const { return reinterpret_cast<const float*>(&m_vComponents)[i]; }
    __forceinline void setZero4() { m_vComponents = _mm_setzero_ps(); }
    __forceinline void add4(const hkVector4Q& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    __forceinline void add3clobberW(const hkVector4Q& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setAdd4(const hkVector4Q& a, const hkVector4Q& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void sub3clobberW(const hkVector4Q& v) { m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setSub4(const hkVector4Q& a, const hkVector4Q& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void mul4(const hkVector4Q& v) { m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setMul4(const hkVector4Q& a, const hkVector4Q& b) { m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void mul4(hkSimdRealParameterQ s) { m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents); }
    __forceinline void setMul4(hkSimdRealParameterQ r, const hkVector4Q& v) { m_vComponents = _mm_mul_ps(r.broadcast(), v.m_vComponents); }
    __forceinline void setBroadcast(const hkVector4Q& v, int i) {
        if (i == 0) { m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0); }
        else if (i == 1) { m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 85); }
        else if (i == 2) { m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 170); }
        else if (i == 3) { m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 255); }
    }
    __forceinline void setBroadcast3clobberW(const hkVector4Q& v, int i) { setBroadcast(v, i); }
    __forceinline hkSimdRealQ horizontalAdd3() const {
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 85), m_vComponents);
        return _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 170), xySum);
    }
    __forceinline hkSimdRealQ getSimdAt(int i) const {
        switch (i) {
        case 0: return m_vComponents;
        case 1: return _mm_shuffle_ps(m_vComponents, m_vComponents, 85);
        case 2: return _mm_shuffle_ps(m_vComponents, m_vComponents, 170);
        case 3:
        default: return _mm_shuffle_ps(m_vComponents, m_vComponents, 255);
        }
    }
    __forceinline void _setMul3(const hkMatrix3Q& a, const hkVector4Q& b);
    __m128 m_vComponents;
};
class hkMatrix3Q {
public:
    __forceinline const hkVector4Q& getColumn(int i) const { return (&m_kColumn0)[i]; }
    hkVector4Q m_kColumn0, m_kColumn1, m_kColumn2;
};
__forceinline void hkVector4Q::_setMul3(const hkMatrix3Q& a, const hkVector4Q& b) {
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0);
    const __m128 r0 = _mm_mul_ps(a.getColumn(0).m_vComponents, b0);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 85);
    const __m128 r1 = _mm_mul_ps(a.getColumn(1).m_vComponents, b1);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 170);
    const __m128 r2 = _mm_mul_ps(a.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

template <class T> __forceinline T* hkAddByteOffsetQ(T* base, long offset) { return reinterpret_cast<T*>(reinterpret_cast<char*>(base) + offset); }

class hkpVelocityAccumulatorQ {
public:
    __forceinline const hkVector4Q& getScratch0() const { return m_vCenterOfMass; }
    __forceinline const hkVector4Q& getScratch1() const { return m_kCoreFromWorldMatrix.getColumn(0); }
    __forceinline const hkVector4Q& getSumLinearVel() const { return getScratch0(); }
    __forceinline const hkVector4Q& getSumAngularVel() const { return getScratch1(); }
    unsigned char m_type;
    unsigned int m_uiDeactivationClass;
    float m_fGravityFactor;
    hkVector4Q m_vLinearVelocity;
    hkVector4Q m_vAngularVelocity;
    hkVector4Q m_vInverseInertiaAndMass;
    hkVector4Q m_vCenterOfMass;
    hkMatrix3Q m_kCoreFromWorldMatrix;
};
class hkpVelocityAccumulatorOffsetQ {
public:
    __forceinline hkpVelocityAccumulatorQ& getAccumulator(hkpVelocityAccumulatorQ* base) { return *hkAddByteOffsetQ(base, m_offset); }
    int m_offset;
};
class hkp1Lin2AngJacobianQ {
public:
    __forceinline const float& getRHS() const { return m_kLinearJacobian(3); }
    hkVector4Q m_kLinearJacobian;
    hkVector4Q m_kAngularVelocity[2];
};
struct hkpConstraintChainMatrixTripleQ { hkMatrix3Q m_lower, m_kMiddle, m_upper; };
struct hkpJacobianBallSocketChainSchemaQ {
    __forceinline static hkp1Lin2AngJacobianQ* getJacobians(hkpJacobianBallSocketChainSchemaQ* s) { return reinterpret_cast<hkp1Lin2AngJacobianQ*>(s + 1); }
    __forceinline hkpConstraintChainMatrixTripleQ* getMatrixBuffer() { return reinterpret_cast<hkpConstraintChainMatrixTripleQ*>(hkAddByteOffsetQ(getJacobians(this), m_iConstraintCount * 3 * sizeof(hkp1Lin2AngJacobianQ))); }
    __forceinline hkVector4Q* getTempBuffer() { return reinterpret_cast<hkVector4Q*>(hkAddByteOffsetQ(getMatrixBuffer(), m_iConstraintCount * sizeof(hkpConstraintChainMatrixTripleQ))); }
    __forceinline hkpVelocityAccumulatorOffsetQ* getAccumulatorOffsetsBase() { return reinterpret_cast<hkpVelocityAccumulatorOffsetQ*>(hkAddByteOffsetQ(getTempBuffer(), (m_iConstraintCount + 1) * sizeof(hkVector4Q))); }
    short m_schemaType;
    unsigned short m_iConstraintCount;
    int m_iElementCount;
    float m_fTau;
    float m_fMotorDamping;
};
struct hkpSolverInfoQ { int u00,u04,u08,u0c,u10,u14,u18,u1c,u20,u24,u28,u2c,u30,u34,u38,u3c; hkVector4Q GetTimeStepFactor; };
struct hkpSolverElemTempQ { union { float m_fAccumulatedImpulse; float m_fSecondUnionFloat; float m_fAccumulatedMotorRhs; }; };

namespace hkVector4UtilQ { __forceinline void reserveRegisters(unsigned int) {} __forceinline void releaseRegisters(unsigned int) {} }
namespace hkSolverQ {
__forceinline void loadVelocityAccumulators(const hkpVelocityAccumulatorQ&, const hkpVelocityAccumulatorQ&) { hkVector4UtilQ::reserveRegisters(0xffff0000); }
__forceinline void storeVelocityAccumulators(hkpVelocityAccumulatorQ&, hkpVelocityAccumulatorQ&) { hkVector4UtilQ::releaseRegisters(0xffff0000); }
__forceinline void popVelocityAccumulators() { hkVector4UtilQ::releaseRegisters(0xffff0000); }
struct SolverStepInfo { int m_unused; };

static __forceinline hkSimdRealQ getLinearDv0UserTauWithCustomRhs(const hkp1Lin2AngJacobianQ& jac, const hkpVelocityAccumulatorQ& mA, const hkpVelocityAccumulatorQ& mB, const hkpSolverInfoQ& info, float tau, float damping, float customRhs)
{
    hkVector4Q vel4;
    {
        hkVector4Q linVelA; linVelA.setSub4(mA.m_vLinearVelocity, mA.getSumLinearVel());
        hkVector4Q angVelA; angVelA.setSub4(mA.m_vAngularVelocity, mA.getSumAngularVel());
        hkVector4Q linVelB; linVelB.setSub4(mB.m_vLinearVelocity, mB.getSumLinearVel());
        hkVector4Q angVelB; angVelB.setSub4(mB.m_vAngularVelocity, mB.getSumAngularVel());
        hkVector4Q c; c.setSub4(linVelA, linVelB);
        hkVector4Q a; a.setMul4(angVelA, jac.m_kAngularVelocity[0]);
        hkVector4Q b; b.setMul4(angVelB, jac.m_kAngularVelocity[1]);
        c.mul4(jac.m_kLinearJacobian);
        a.add4(b);
        vel4.setAdd4(a, c);
    }
    hkVector4Q svel4;
    {
        hkVector4Q linVelA = mA.getSumLinearVel();
        hkVector4Q angVelA = mA.getSumAngularVel();
        hkVector4Q linVelB = mB.getSumLinearVel();
        hkVector4Q angVelB = mB.getSumAngularVel();
        hkVector4Q c; c.setSub4(linVelA, linVelB);
        hkVector4Q a; a.setMul4(angVelA, jac.m_kAngularVelocity[0]);
        hkVector4Q b; b.setMul4(angVelB, jac.m_kAngularVelocity[1]);
        c.mul4(jac.m_kLinearJacobian);
        a.add4(b);
        svel4.setAdd4(a, c);
    }
    svel4.mul4(info.GetTimeStepFactor(0) * tau);
    vel4.mul4(damping);
    hkVector4Q rhsUpdate; rhsUpdate.setAdd4(svel4, vel4);
    float ru = rhsUpdate.horizontalAdd3();
    float dv = customRhs * tau - ru;
    return dv;
}
static __forceinline hkSimdRealQ getLinearDv0UserTau(const hkp1Lin2AngJacobianQ& jac, const hkpVelocityAccumulatorQ& mA, const hkpVelocityAccumulatorQ& mB, const hkpSolverInfoQ& info, float tau, float damping)
{
    return getLinearDv0UserTauWithCustomRhs(jac, mA, mB, info, tau, damping, jac.getRHS());
}
static __forceinline void applyImpulse(hkSimdRealParameterQ imp, const hkp1Lin2AngJacobianQ& jac, hkpVelocityAccumulatorQ& mA, hkpVelocityAccumulatorQ& mB, hkpSolverElemTempQ& sr)
{
    hkVector4Q impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    hkVector4Q impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    hkVector4Q impLinA; impLinA.setBroadcast3clobberW(impA, 3);
    hkVector4Q negImpLinB; negImpLinB.setBroadcast3clobberW(impB, 3);
    impLinA.mul4(jac.m_kLinearJacobian);
    negImpLinB.mul4(jac.m_kLinearJacobian);
    mA.m_vLinearVelocity.add3clobberW(impLinA);
    mB.m_vLinearVelocity.sub3clobberW(negImpLinB);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    hkSimdRealQ s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    hkSimdReal_storeQ(s, &sr.m_fAccumulatedImpulse);
}
}

// @fnv 0x00d89690
void __cdecl FUN_00d89690(const hkpSolverInfoQ& info, const hkSolverQ::SolverStepInfo& temp, hkpVelocityAccumulatorQ* accums, hkpJacobianBallSocketChainSchemaQ* chain, hkpSolverElemTempQ* sr)
{
    int numConstraints = chain->m_iConstraintCount;
    hkp1Lin2AngJacobianQ* j = hkpJacobianBallSocketChainSchemaQ::getJacobians(chain);
    hkpVelocityAccumulatorOffsetQ* va = chain->getAccumulatorOffsetsBase();
    hkpConstraintChainMatrixTripleQ* triple = chain->getMatrixBuffer();
    hkVector4Q* g = chain->getTempBuffer() + 1;
    g[-1].setZero4();
    {
        for (int gi = 0; gi < numConstraints; j += 3, gi++)
        {
            hkpVelocityAccumulatorQ* __restrict raA = &va[gi].getAccumulator(accums);
            hkpVelocityAccumulatorQ* __restrict raB = &va[gi + 1].getAccumulator(accums);
            hkSolverQ::loadVelocityAccumulators(*raA, *raB);
            hkVector4Q dv;
            dv(0) = hkSolverQ::getLinearDv0UserTau(j[0], *raA, *raB, info, chain->m_fTau, chain->m_fMotorDamping);
            dv(1) = hkSolverQ::getLinearDv0UserTau(j[1], *raA, *raB, info, chain->m_fTau, chain->m_fMotorDamping);
            dv(2) = hkSolverQ::getLinearDv0UserTau(j[2], *raA, *raB, info, chain->m_fTau, chain->m_fMotorDamping);
            dv(3) = 0.0f;
            hkSolverQ::popVelocityAccumulators();
            hkVector4Q tmp;
            tmp._setMul3(triple[gi].m_lower, g[gi - 1]);
            tmp.setSub4(dv, tmp);
            g[gi]._setMul3(triple[gi].m_kMiddle, tmp);
        }
    }
    {
        hkVector4Q imp; imp.setZero4();
        j = hkpJacobianBallSocketChainSchemaQ::getJacobians(chain);
        for (int gi = numConstraints - 1; gi >= 0; gi--)
        {
            hkpVelocityAccumulatorQ* __restrict raA = &va[gi].getAccumulator(accums);
            hkpVelocityAccumulatorQ* __restrict raB = &va[gi + 1].getAccumulator(accums);
            int jIdx = gi * 3;
            hkVector4Q tmp;
            tmp._setMul3(triple[gi].m_upper, imp);
            imp.setSub4(g[gi], tmp);
            hkSolverQ::loadVelocityAccumulators(*raA, *raB);
            hkSolverQ::applyImpulse(imp.getSimdAt(0), j[jIdx], *raA, *raB, sr[jIdx]);
            hkSolverQ::applyImpulse(imp.getSimdAt(1), j[jIdx + 1], *raA, *raB, sr[jIdx + 1]);
            hkSolverQ::applyImpulse(imp.getSimdAt(2), j[jIdx + 2], *raA, *raB, sr[jIdx + 2]);
            hkSolverQ::storeVelocityAccumulators(*raA, *raB);
        }
    }
}


template <class TYPE> class PoweredChainCell {
public:
    __forceinline PoweredChainCell() {}
    __forceinline PoweredChainCell(TYPE e) : m_kStorage(e) {}
    __forceinline void operator=(TYPE e) { m_kStorage = e; }
    __forceinline TYPE val() const { return m_kStorage; }
    __forceinline TYPE operator->() const { return m_kStorage; }
    __forceinline operator TYPE() const { return m_kStorage; }
private:
    TYPE m_kStorage;
};


class PoweredChainScalar {
public:
    PoweredChainScalar(const hkQuadReal& x) : m_vValue(x) {}
    PoweredChainScalar(hkReal x) { m_vValue = _mm_load_ss(&x); }
    PoweredChainScalar() {}
    operator hkReal() const { hkReal s; _mm_store_ss(&s, m_vValue); return s; }
    __forceinline hkQuadReal broadcast() const { return _mm_shuffle_ps(getQuad(), getQuad(), 0); }
    __forceinline hkQuadReal getQuad() const { return m_vValue; }
private:
    hkQuadReal m_vValue;
};
typedef const PoweredChainScalar& PoweredChainScalarParameter;
inline PoweredChainScalar operator+(PoweredChainScalarParameter r, PoweredChainScalarParameter s) { return _mm_add_ss(r.getQuad(), s.getQuad()); }
__forceinline void poweredChainStoreScalar(PoweredChainScalarParameter a, hkReal* p) { _mm_store_ss(p, a.getQuad()); }

class PoweredChainMatrix3;
class PoweredChainVector4 {
public:
    __forceinline void operator=(const hkQuadReal& v) { m_vComponents = v; }
    __forceinline hkReal& operator()(int i) { return reinterpret_cast<hkReal*>(&m_vComponents)[i]; }
    __forceinline const hkReal& operator()(int i) const { return reinterpret_cast<const hkReal*>(&m_vComponents)[i]; }
    __forceinline void setZero4() { m_vComponents = _mm_setzero_ps(); }
    __forceinline void add4(const PoweredChainVector4& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    __forceinline void add3clobberW(const PoweredChainVector4& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setAdd4(const PoweredChainVector4& a, const PoweredChainVector4& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void sub3clobberW(const PoweredChainVector4& v) { m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setSub4(const PoweredChainVector4& a, const PoweredChainVector4& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void mul4(const PoweredChainVector4& v) { m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setMul4(const PoweredChainVector4& a, const PoweredChainVector4& b) { m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void mul4(PoweredChainScalarParameter s) { m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents); }
    __forceinline void setMul4(PoweredChainScalarParameter r, const PoweredChainVector4& v) { m_vComponents = _mm_mul_ps(r.broadcast(), v.m_vComponents); }
    __forceinline void setBroadcast(const PoweredChainVector4& v, int i) {
        if (i == 0) { m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0); }
        else if (i == 1) { m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 85); }
        else if (i == 2) { m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 170); }
        else if (i == 3) { m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 255); }
    }
    __forceinline void setBroadcast3clobberW(const PoweredChainVector4& v, int i) { setBroadcast(v, i); }
    __forceinline PoweredChainScalar horizontalAdd3() const {
        hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 85), m_vComponents);
        return _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 170), xySum);
    }
    __forceinline PoweredChainScalar getSimdAt(int i) const {
        switch (i) {
        case 0: return m_vComponents;
        case 1: return _mm_shuffle_ps(m_vComponents, m_vComponents, 85);
        case 2: return _mm_shuffle_ps(m_vComponents, m_vComponents, 170);
        case 3:
        default: return _mm_shuffle_ps(m_vComponents, m_vComponents, 255);
        }
    }
    __forceinline void _setMul3(const PoweredChainMatrix3& a, const PoweredChainVector4& b);
    hkQuadReal m_vComponents;
};
class PoweredChainMatrix3 {
public:
    __forceinline const PoweredChainVector4& getColumn(int i) const { return (&m_kColumn0)[i]; }
    PoweredChainVector4 m_kColumn0, m_kColumn1, m_kColumn2;
};
__forceinline void PoweredChainVector4::_setMul3(const PoweredChainMatrix3& a, const PoweredChainVector4& b) {
    const hkQuadReal b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0);
    const hkQuadReal r0 = _mm_mul_ps(a.getColumn(0).m_vComponents, b0);
    const hkQuadReal b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 85);
    const hkQuadReal r1 = _mm_mul_ps(a.getColumn(1).m_vComponents, b1);
    const hkQuadReal b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 170);
    const hkQuadReal r2 = _mm_mul_ps(a.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

template <class T> __forceinline T* poweredChainAddByteOffset(T* base, long offset) { return reinterpret_cast<T*>(reinterpret_cast<char*>(base) + offset); }

class PoweredChainAccumulator {
public:
    __forceinline const PoweredChainVector4& getScratch0() const { return m_vCenterOfMass; }
    __forceinline const PoweredChainVector4& getScratch1() const { return m_kCoreFromWorldMatrix.getColumn(0); }
    __forceinline const PoweredChainVector4& getSumLinearVel() const { return getScratch0(); }
    __forceinline const PoweredChainVector4& getSumAngularVel() const { return getScratch1(); }
    unsigned char m_type;
    unsigned int m_uiDeactivationClass;
    hkReal m_fGravityFactor;
    PoweredChainVector4 m_vLinearVelocity;
    PoweredChainVector4 m_vAngularVelocity;
    PoweredChainVector4 m_vInverseInertiaAndMass;
    PoweredChainVector4 m_vCenterOfMass;
    PoweredChainMatrix3 m_kCoreFromWorldMatrix;
};
class PoweredChainAccumulatorOffset {
public:
    __forceinline PoweredChainAccumulator& getAccumulator(PoweredChainAccumulator* base) { return *poweredChainAddByteOffset(base, m_offset); }
    int m_offset;
};
class PoweredChainLinearRow {
public:
    __forceinline const hkReal& getRHS() const { return m_kLinearJacobian(3); }
    PoweredChainVector4 m_kLinearJacobian;
    PoweredChainVector4 m_kAngularVelocity[2];
};
class PoweredChainAngularRow {
public:
    __forceinline void setAngularRhs(hkReal v) { m_kAngularVelocity[1](3) = v; }
    __forceinline hkReal getAngularRhs() const { return m_kAngularVelocity[1](3); }
    PoweredChainVector4 m_kAngularVelocity[2];
};
class PoweredChainMatrix6 {
public:
    PoweredChainMatrix3 m_iUnknownValue2[2][2];
};
class PoweredChainVector8 {
public:
    __forceinline void setZero8() { m_vLinearConstraint.setZero4(); m_vAngularConstraint.setZero4(); }
    __forceinline void setSub8(const PoweredChainVector8& a, const PoweredChainVector8& b) { m_vLinearConstraint.setSub4(a.m_vLinearConstraint, b.m_vLinearConstraint); m_vAngularConstraint.setSub4(a.m_vAngularConstraint, b.m_vAngularConstraint); }
    __forceinline void _setMul6(const PoweredChainMatrix6& a, const PoweredChainVector8& b)
    {
        PoweredChainVector4 tmp[2];
        tmp[0]._setMul3(a.m_iUnknownValue2[0][0], b.m_vLinearConstraint);
        m_vLinearConstraint._setMul3(a.m_iUnknownValue2[0][1], b.m_vAngularConstraint);
        tmp[1]._setMul3(a.m_iUnknownValue2[1][0], b.m_vLinearConstraint);
        m_vAngularConstraint._setMul3(a.m_iUnknownValue2[1][1], b.m_vAngularConstraint);
        m_vLinearConstraint.add4(tmp[0]);
        m_vAngularConstraint.add4(tmp[1]);
    }
    PoweredChainVector4 m_vLinearConstraint;
    PoweredChainVector4 m_vAngularConstraint;
};
struct PoweredChainMatrixTriple { PoweredChainMatrix6 m_lower, m_kMiddle, m_upper, m_gTranspose, m_gLower; };
struct PoweredChainMotorAxis { hkReal m_fMinimumForce; hkReal m_fMaximumForce; hkReal m_fVelocity; hkReal m_fTau; hkReal m_fMotorDamping; };
struct PoweredChainMotor {
    __forceinline int GetReferenceTimeStep(int idx) const { return (m_ucReferenceTimeSteps >> (2 * idx)) & 3; }
    unsigned char m_ucReferenceTimeSteps;
    PoweredChainMotorAxis m_kAngularMotors[3];
};
struct PoweredChainSettings { int u00,u04,u08,u0c,u10,u14,u18,u1c,u20,u24,u28,u2c,u30,u34,u38,u3c; PoweredChainVector4 GetTimeStepFactor; };
struct PoweredChainResult { union { hkReal m_fAccumulatedImpulse; hkReal m_fSecondUnionFloat; hkReal m_fAccumulatedMotorRhs; }; };

namespace PoweredChainVectorUtil { __forceinline void reserveRegisters(unsigned int) {} __forceinline void releaseRegisters(unsigned int) {} }
namespace PoweredChainSolver {
__forceinline void loadVelocityAccumulators(const PoweredChainAccumulator&, const PoweredChainAccumulator&) { PoweredChainVectorUtil::reserveRegisters(0xffff0000); }
__forceinline void storeVelocityAccumulators(PoweredChainAccumulator&, PoweredChainAccumulator&) { PoweredChainVectorUtil::releaseRegisters(0xffff0000); }
__forceinline void popVelocityAccumulators() { PoweredChainVectorUtil::releaseRegisters(0xffff0000); }
struct PoweredChainStepTemp { PoweredChainCell<int> m_unused; PoweredChainCell<hkReal> m_velocityScale; };

static __forceinline PoweredChainScalar getLinearDv0UserTauWithCustomRhs(const PoweredChainLinearRow& jac, const PoweredChainAccumulator& mA, const PoweredChainAccumulator& mB, const PoweredChainSettings& info, hkReal tau, hkReal damping, hkReal customRhs)
{
    PoweredChainVector4 vel4;
    {
        PoweredChainVector4 linVelA; linVelA.setSub4(mA.m_vLinearVelocity, mA.getSumLinearVel());
        PoweredChainVector4 angVelA; angVelA.setSub4(mA.m_vAngularVelocity, mA.getSumAngularVel());
        PoweredChainVector4 linVelB; linVelB.setSub4(mB.m_vLinearVelocity, mB.getSumLinearVel());
        PoweredChainVector4 angVelB; angVelB.setSub4(mB.m_vAngularVelocity, mB.getSumAngularVel());
        PoweredChainVector4 c; c.setSub4(linVelA, linVelB);
        PoweredChainVector4 a; a.setMul4(angVelA, jac.m_kAngularVelocity[0]);
        PoweredChainVector4 b; b.setMul4(angVelB, jac.m_kAngularVelocity[1]);
        c.mul4(jac.m_kLinearJacobian);
        a.add4(b);
        vel4.setAdd4(a, c);
    }
    PoweredChainVector4 svel4;
    {
        PoweredChainVector4 linVelA = mA.getSumLinearVel();
        PoweredChainVector4 angVelA = mA.getSumAngularVel();
        PoweredChainVector4 linVelB = mB.getSumLinearVel();
        PoweredChainVector4 angVelB = mB.getSumAngularVel();
        PoweredChainVector4 c; c.setSub4(linVelA, linVelB);
        PoweredChainVector4 a; a.setMul4(angVelA, jac.m_kAngularVelocity[0]);
        PoweredChainVector4 b; b.setMul4(angVelB, jac.m_kAngularVelocity[1]);
        c.mul4(jac.m_kLinearJacobian);
        a.add4(b);
        svel4.setAdd4(a, c);
    }
    svel4.mul4(info.GetTimeStepFactor(0) * tau);
    vel4.mul4(damping);
    PoweredChainVector4 rhsUpdate; rhsUpdate.setAdd4(svel4, vel4);
    hkReal ru = rhsUpdate.horizontalAdd3();
    hkReal dv = customRhs * tau - ru;
    return dv;
}
static __forceinline PoweredChainScalar getLinearDv0UserTau(const PoweredChainLinearRow& jac, const PoweredChainAccumulator& mA, const PoweredChainAccumulator& mB, const PoweredChainSettings& info, hkReal tau, hkReal damping)
{
    return getLinearDv0UserTauWithCustomRhs(jac, mA, mB, info, tau, damping, jac.getRHS());
}
static __forceinline void applyImpulse(PoweredChainScalarParameter imp, const PoweredChainLinearRow& jac, PoweredChainAccumulator& mA, PoweredChainAccumulator& mB, PoweredChainResult& sr)
{
    PoweredChainVector4 impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    PoweredChainVector4 impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    PoweredChainVector4 impLinA; impLinA.setBroadcast3clobberW(impA, 3);
    PoweredChainVector4 negImpLinB; negImpLinB.setBroadcast3clobberW(impB, 3);
    impLinA.mul4(jac.m_kLinearJacobian);
    negImpLinB.mul4(jac.m_kLinearJacobian);
    mA.m_vLinearVelocity.add3clobberW(impLinA);
    mB.m_vLinearVelocity.sub3clobberW(negImpLinB);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    PoweredChainScalar s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    poweredChainStoreScalar(s, &sr.m_fAccumulatedImpulse);
}
static __forceinline void ApplyAngularImpulseToBodies(PoweredChainScalarParameter imp, const PoweredChainAngularRow& jac, PoweredChainAccumulator& mA, PoweredChainAccumulator& mB, PoweredChainResult& sr)
{
    PoweredChainVector4 impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    PoweredChainVector4 impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    PoweredChainScalar s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    poweredChainStoreScalar(s, &sr.m_fAccumulatedImpulse);
}
}

struct PoweredChainSchema {
    __forceinline static PoweredChainLinearRow* getLinearJacobians(PoweredChainSchema* s) { return reinterpret_cast<PoweredChainLinearRow*>(s + 1); }
    __forceinline static PoweredChainAngularRow* getAngularJacobians(PoweredChainSchema* s, int n) { return reinterpret_cast<PoweredChainAngularRow*>(getLinearJacobians(s) + n * 3); }
    __forceinline PoweredChainMatrixTriple* getMatrixBuffer() { return reinterpret_cast<PoweredChainMatrixTriple*>(poweredChainAddByteOffset(getAngularJacobians(this, m_iConstraintCount), m_iConstraintCount * 3 * sizeof(PoweredChainAngularRow))); }
    __forceinline PoweredChainVector8* getTempBuffer() { return reinterpret_cast<PoweredChainVector8*>(poweredChainAddByteOffset(getMatrixBuffer(), m_iConstraintCount * sizeof(PoweredChainMatrixTriple))); }
    __forceinline PoweredChainVector8* getVelocityBuffer() { return getTempBuffer() + m_iConstraintCount + 1; }
    __forceinline PoweredChainAccumulatorOffset* getAccumulatorOffsetsBase() { return reinterpret_cast<PoweredChainAccumulatorOffset*>(getVelocityBuffer() + m_iConstraintCount); }
    __forceinline PoweredChainMotor* getChildConstraintStatusBase() { return reinterpret_cast<PoweredChainMotor*>(getAccumulatorOffsetsBase() + m_iConstraintCount + 1); }
    int m_schemaType;
    unsigned short m_iConstraintCount;
    short m_unk06;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    hkReal m_fTau;
    hkReal m_fMotorDamping;
};
struct PoweredChainContext {
    __forceinline PoweredChainContext(const PoweredChainSettings& info) : m_pSolverInfo(info) {}
    const PoweredChainSettings& m_pSolverInfo;
    PoweredChainCell<int> m_iConstraintCount;
    PoweredChainCell<hkReal> m_fTau;
    PoweredChainCell<hkReal> m_fMotorDamping;
    PoweredChainCell<PoweredChainLinearRow*> m_jacobians;
    PoweredChainCell<PoweredChainAngularRow*> m_angularJacobians;
    PoweredChainCell<PoweredChainAccumulatorOffset*> m_accumulatorOffsets;
    PoweredChainCell<PoweredChainAccumulator*> m_pVelocityAccumulatorA;
    PoweredChainCell<PoweredChainMatrixTriple*> m_kMatrices;
    PoweredChainCell<PoweredChainMotor*> m_kAngularMotors;
    PoweredChainCell<PoweredChainVector8*> m_tempBuffer;
    PoweredChainCell<PoweredChainVector8*> m_velocities;
};
void __cdecl FUN_00df11a0(const PoweredChainContext& info, PoweredChainVector8* temp);
void __cdecl FUN_00df1430(const PoweredChainContext& info, int& link, int& axis, hkReal& impulse, PoweredChainMotor* motors);
void __cdecl FUN_00df1260(const PoweredChainContext& info, int& link, int& axis, hkReal& impulse, PoweredChainMotor* motors);
void __cdecl FUN_00df1060(int link, int axis, const PoweredChainContext& info, PoweredChainVector8* velocities);

// @fnv 0x00d8a3a0
void __cdecl FUN_00d8a3a0(const PoweredChainSettings& info, const PoweredChainSolver::PoweredChainStepTemp& temp, PoweredChainAccumulator* accums, PoweredChainSchema* schema, PoweredChainResult* sr)
{
    PoweredChainContext chainInfo(info);
    chainInfo.m_iConstraintCount = schema->m_iConstraintCount;
    chainInfo.m_fTau = schema->m_fTau;
    chainInfo.m_fMotorDamping = schema->m_fMotorDamping;
    chainInfo.m_jacobians = PoweredChainSchema::getLinearJacobians(schema);
    chainInfo.m_angularJacobians = PoweredChainSchema::getAngularJacobians(schema, schema->m_iConstraintCount);
    chainInfo.m_accumulatorOffsets = schema->getAccumulatorOffsetsBase();
    chainInfo.m_pVelocityAccumulatorA = accums;
    chainInfo.m_kMatrices = schema->getMatrixBuffer();
    chainInfo.m_kAngularMotors = schema->getChildConstraintStatusBase();
    chainInfo.m_tempBuffer = schema->getTempBuffer();
    chainInfo.m_velocities = schema->getVelocityBuffer();

    {
        PoweredChainAngularRow* jac = chainInfo.m_angularJacobians;
        for (int i = 0; i < chainInfo.m_iConstraintCount; i++)
        {
            for (int a = 0; a < 3; a++)
            {
                hkReal rhs = jac->getAngularRhs();
                rhs += chainInfo.m_kAngularMotors.val()[i].m_kAngularMotors[a].m_fVelocity * temp.m_velocityScale;
                jac->setAngularRhs(rhs);
                jac++;
            }
        }
    }

    ::FUN_00df0d30((const ::ConstraintSolverState &)(chainInfo), (::VelocityPair *)(::PoweredChainVector8 *)(chainInfo.m_velocities));

    for (int i = 0; i < chainInfo.m_iConstraintCount; i++)
    {
        for (int a = 0; a < 3; a++)
        {
            if (chainInfo.m_kAngularMotors.val()[i].GetReferenceTimeStep(a) == 2)
            {
                PoweredChainVector8& v = chainInfo.m_velocities.val()[i];
                v.m_vAngularConstraint(a) = 0.0f;
            }
            else if (chainInfo.m_kAngularMotors.val()[i].GetReferenceTimeStep(a) != 0)
            {
                ::CopyChannelValue(i, a, (::FUN_00df0810_Source *)(chainInfo.m_kAngularMotors.val()), (::FUN_00df0810_Dest *)(::PoweredChainVector8 *)(chainInfo.m_velocities));
            }
        }
    }

    while (true)
    {
        FUN_00df11a0(chainInfo, chainInfo.m_tempBuffer);
        int link = -1;
        int axis = -1;
        hkReal impulse = 0.0f;
        FUN_00df1430(chainInfo, link, axis, impulse, chainInfo.m_kAngularMotors);
        if (link >= 0)
        {
            ::FUN_00df2040(link, chainInfo.m_iConstraintCount, (const char *)(::PoweredChainMotor *)(chainInfo.m_kAngularMotors), (char *)(::PoweredChainMatrixTriple *)(chainInfo.m_kMatrices));
            FUN_00df1060(link, axis, chainInfo, chainInfo.m_velocities);
        }
        else
        {
            break;
        }
    }
    while (true)
    {
        FUN_00df11a0(chainInfo, chainInfo.m_tempBuffer);
        int link = -1;
        int axis = -1;
        hkReal impulse = 0.0f;
        FUN_00df1260(chainInfo, link, axis, impulse, chainInfo.m_kAngularMotors);
        if (link >= 0)
        {
            ::FUN_00df2040(link, chainInfo.m_iConstraintCount, (const char *)(::PoweredChainMotor *)(chainInfo.m_kAngularMotors), (char *)(::PoweredChainMatrixTriple *)(chainInfo.m_kMatrices));
            ::CopyChannelValue(link, axis, (::FUN_00df0810_Source *)(chainInfo.m_kAngularMotors.val()), (::FUN_00df0810_Dest *)(::PoweredChainVector8 *)(chainInfo.m_velocities));
        }
        else
        {
            break;
        }
    }

    {
        PoweredChainVector8* g = chainInfo.m_tempBuffer.val() + 1;
        PoweredChainVector8 imp; imp.setZero8();
        for (int i = chainInfo.m_iConstraintCount - 1; i >= 0; i--)
        {
            int jIdx = i * 3;
            int srIdx = i * 6;
            PoweredChainVector8 tmp;
            tmp._setMul6(chainInfo.m_kMatrices.val()[i].m_upper, imp);
            imp.setSub8(g[i], tmp);
            PoweredChainAccumulator* __restrict raA = &chainInfo.m_accumulatorOffsets.val()[i].getAccumulator(accums);
            PoweredChainAccumulator* __restrict raB = &chainInfo.m_accumulatorOffsets.val()[i + 1].getAccumulator(accums);
            PoweredChainSolver::loadVelocityAccumulators(*raA, *raB);
            PoweredChainSolver::applyImpulse(imp.m_vLinearConstraint.getSimdAt(0), chainInfo.m_jacobians.val()[jIdx], *raA, *raB, sr[srIdx]);
            PoweredChainSolver::applyImpulse(imp.m_vLinearConstraint.getSimdAt(1), chainInfo.m_jacobians.val()[jIdx + 1], *raA, *raB, sr[srIdx + 1]);
            PoweredChainSolver::applyImpulse(imp.m_vLinearConstraint.getSimdAt(2), chainInfo.m_jacobians.val()[jIdx + 2], *raA, *raB, sr[srIdx + 2]);
            PoweredChainSolver::ApplyAngularImpulseToBodies(imp.m_vAngularConstraint.getSimdAt(0), chainInfo.m_angularJacobians.val()[jIdx], *raA, *raB, sr[srIdx + 3]);
            PoweredChainSolver::ApplyAngularImpulseToBodies(imp.m_vAngularConstraint.getSimdAt(1), chainInfo.m_angularJacobians.val()[jIdx + 1], *raA, *raB, sr[srIdx + 4]);
            PoweredChainSolver::ApplyAngularImpulseToBodies(imp.m_vAngularConstraint.getSimdAt(2), chainInfo.m_angularJacobians.val()[jIdx + 2], *raA, *raB, sr[srIdx + 5]);
            PoweredChainSolver::storeVelocityAccumulators(*raA, *raB);
        }
    }
}

namespace ConstraintStepImplementation {

extern __m128 DAT_010c7160;
typedef float ConstraintStepReal;
typedef __m128 ConstraintStepQuad;
class ConstraintStepScalar
{
public:
    __forceinline ConstraintStepScalar(const ConstraintStepQuad& x) : m_vValue(x) {}
    __forceinline ConstraintStepScalar(ConstraintStepReal x) { m_vValue = _mm_load_ss(&x); }
    __forceinline ConstraintStepScalar() {}
    __forceinline operator ConstraintStepReal() const
    {
        ConstraintStepReal s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline ConstraintStepQuad broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
    __forceinline const ConstraintStepQuad& getQuad() const { return m_vValue; }
    ConstraintStepQuad m_vValue;
};
typedef const ConstraintStepScalar& ConstraintStepScalarParameter;
__forceinline void constraintStepSetMax(ConstraintStepScalarParameter a, ConstraintStepScalarParameter b, ConstraintStepScalar& result)
{
    result = ConstraintStepScalar(_mm_max_ps(a.getQuad(), b.getQuad()));
}
__forceinline void constraintStepSetMin(ConstraintStepScalarParameter a, ConstraintStepScalarParameter b, ConstraintStepScalar& result)
{
    result = ConstraintStepScalar(_mm_min_ps(a.getQuad(), b.getQuad()));
}
__forceinline void constraintStepStore(ConstraintStepScalarParameter a, float* f)
{
    _mm_store_ss(f, a.getQuad());
}
__forceinline ConstraintStepScalar operator*(ConstraintStepScalarParameter r, ConstraintStepScalarParameter s) { return _mm_mul_ss(r.getQuad(), s.getQuad()); }
__forceinline ConstraintStepScalar operator-(ConstraintStepScalarParameter r, ConstraintStepScalarParameter s) { return _mm_sub_ss(r.getQuad(), s.getQuad()); }
__forceinline ConstraintStepScalar operator+(ConstraintStepScalarParameter r, ConstraintStepScalarParameter s) { return _mm_add_ss(r.getQuad(), s.getQuad()); }
__forceinline ConstraintStepScalar operator-(ConstraintStepScalarParameter r) { return _mm_sub_ss(DAT_010c7160, r.getQuad()); }
ConstraintStepScalar __cdecl SubtractScalarFloat(ConstraintStepScalarParameter r, ConstraintStepScalarParameter s);
__declspec(noinline) ConstraintStepScalar __cdecl AddScalarFloat(ConstraintStepScalarParameter r, ConstraintStepScalarParameter s) { return _mm_add_ss(r.getQuad(),s.getQuad()); }
class ConstraintStepMatrix;
class ConstraintStepVector
{
public:
    __forceinline void commitIncrement(ConstraintStepVector& dest) const { dest.add4(*this); }
    __forceinline operator ConstraintStepQuad() const { return m_vComponents; }
    __forceinline void operator=(const ConstraintStepQuad& q) { m_vComponents = q; }
    __forceinline void operator=(const ConstraintStepVector& v) { m_vComponents = v.m_vComponents; }
    __forceinline void add4(const ConstraintStepVector& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    __forceinline void add3clobberW(const ConstraintStepVector& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setAdd4(const ConstraintStepVector& a, const ConstraintStepVector& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void sub3clobberW(const ConstraintStepVector& v) { m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setSub4(const ConstraintStepVector& a, const ConstraintStepVector& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void mul4(const ConstraintStepVector& v) { m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setMul4(const ConstraintStepVector& a, const ConstraintStepVector& b) { m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void mul4(ConstraintStepScalarParameter s) { m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents); }
    __forceinline void setMul4(ConstraintStepScalarParameter r, const ConstraintStepVector& v) { m_vComponents = _mm_mul_ps(r.broadcast(), v.m_vComponents); }
    __forceinline ConstraintStepScalar horizontalAdd3() const
    {
        ConstraintStepQuad xySum = _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0x55), m_vComponents);
        return _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa), xySum);
    }
    __forceinline ConstraintStepReal& operator()(int a) { return reinterpret_cast<ConstraintStepReal*>(&m_vComponents)[a]; }
    __forceinline const ConstraintStepReal& operator()(int a) const { return reinterpret_cast<const ConstraintStepReal*>(&m_vComponents)[a]; }
    __forceinline ConstraintStepScalar getSimdAt(int i) const
    {
        switch (i)
        {
        case 0: return m_vComponents;
        case 1: return _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55);
        case 2: return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa);
        case 3:
        default: return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        }
    }
    __forceinline void setBroadcast(const ConstraintStepVector& v, int i)
    {
        if (i == 0) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
        else if (i == 1) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
        else if (i == 2) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
        else if (i == 3) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
    }
    __forceinline void setBroadcast3clobberW(const ConstraintStepVector& v, int i) { setBroadcast(v, i); }
    __forceinline void SetRotatedVector(const ConstraintStepMatrix& a, const ConstraintStepVector& b) { reinterpret_cast<::FUN_00c7f750_shell *>(this)->FUN_00c7f750((float *)&(a), (float *)&(b)); }
    ConstraintStepQuad m_vComponents;
};
class ConstraintStepMatrix { public: ConstraintStepVector m_kColumn0, m_kColumn1, m_kColumn2; };
template <class TYPE> class ValueWrapper
{
public:
    __forceinline ValueWrapper() {}
    __forceinline ValueWrapper(TYPE e) : m_kStorage(e) {}
    __forceinline void operator=(TYPE e) { m_kStorage = e; }
    __forceinline TYPE val() const { return m_kStorage; }
    __forceinline TYPE operator->() const { return m_kStorage; }
    __forceinline operator TYPE() const { return val(); }
private:
    TYPE m_kStorage;
};
struct ConstraintSolverInfo
{
    float unk00, m_fTau, m_fMotorDamping, m_fPostDampingParameter;
    ConstraintStepVector unk10, unk20;
    ConstraintStepVector m_kGravity;
    ConstraintStepVector m_kTimeStep;
};
struct FloatRecord { float m_fAccumulatedImpulse; };
class ConstraintStepAccumulator
{
public:
    int unk00;
    __forceinline const ConstraintStepVector& getSumLinearVel() const { return m_sumLinearVel; }
    __forceinline ConstraintStepVector& getSumLinearVel() { return m_sumLinearVel; }
    __forceinline const ConstraintStepVector& getSumAngularVel() const { return m_sumAngularVel; }
    ConstraintStepVector m_vLinearVelocity;
    ConstraintStepVector m_vAngularVelocity;
    ConstraintStepVector m_vInverseInertiaAndMass;
    ConstraintStepVector m_sumLinearVel;
    ConstraintStepVector m_sumAngularVel;
    ConstraintStepVector unk60;
    ConstraintStepVector unk70;
};
template <class T> __forceinline T* hkSelect(int i, T* a, T* b)
{
    uintptr_t ua = reinterpret_cast<uintptr_t>(a);
    uintptr_t ub = reinterpret_cast<uintptr_t>(b);
    return reinterpret_cast<T*>(ua ^ ((ua ^ ub) & (-i)));
}
struct SolverStepInfo
{
    ValueWrapper<int> m_intStep;
    ValueWrapper<ConstraintStepReal> m_stepFactor;
};
enum SolverSchemaType
{
    SCHEMA_TYPE_END = 0,
    SCHEMA_TYPE_HEADER = 1,
    SCHEMA_TYPE_GOTO = 2,
    SCHEMA_TYPE_NOP = 3,
    SCHEMA_TYPE_1D_BILATERAL = 5,
    SCHEMA_TYPE_1D_BILATERAL_WITH_IMPULSE_LIMIT = 6,
    SCHEMA_TYPE_1D_BILATERAL_USER_TAU = 7,
    SCHEMA_TYPE_1D_LINEAR_LIMITS = 8,
    SCHEMA_TYPE_1D_FRICTION = 9,
    SCHEMA_TYPE_1D_LINEAR_MOTOR = 10,
    SCHEMA_TYPE_1D_PULLEY = 11,
    SCHEMA_TYPE_1D_ANGULAR = 12,
    SCHEMA_TYPE_1D_ANGULAR_LIMITS = 13,
    SCHEMA_TYPE_1D_ANGULAR_FRICTION = 14,
    SCHEMA_TYPE_1D_ANGULAR_MOTOR = 15,
    SCHEMA_TYPE_SINGLE_CONTACT = 16,
    SCHEMA_TYPE_SINGLE_CONTACT2 = 17,
    SCHEMA_TYPE_SINGLE_LIMIT_CONTACT = 18,
    SCHEMA_TYPE_SINGLE_LIMIT_CONTACT2 = 19,
    SCHEMA_TYPE_PAIR_CONTACT = 20,
    SCHEMA_TYPE_PAIR_CONTACT2 = 21,
    SCHEMA_TYPE_2D_FRICTION = 22,
    SCHEMA_TYPE_3D_FRICTION = 23,
    SCHEMA_TYPE_2D_ROLLING_FRICTION = 24,
    SCHEMA_TYPE_SET_MASS = 25,
    SCHEMA_TYPE_ADD_VELOCITY = 26,
    SCHEMA_TYPE_SET_CENTER_OF_MASS = 27,
    SCHEMA_TYPE_STIFF_SPRING_CHAIN = 29,
    SCHEMA_TYPE_BALL_SOCKET_CHAIN = 30,
    SCHEMA_TYPE_POWERED_CHAIN = 31
};
class hkBool
{
public:
    __forceinline hkBool(bool b) { m_cBooleanValue = (char)b; }
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
    char m_cBooleanValue;
};
template <class E, class S> class hkEnum
{
public:
    __forceinline hkEnum() {}
    __forceinline hkEnum(E e) { m_kStorage = (S)e; }
    __forceinline void operator=(E e) { m_kStorage = (S)e; }
    __forceinline hkBool operator==(E e) const { return m_kStorage == (S)e; }
    __forceinline operator E() const { return (E)m_kStorage; }
    __forceinline hkBool operator!=(E e) const { return m_kStorage != (S)e; }
    S m_kStorage;
};
typedef hkEnum<SolverSchemaType, signed char> SchemaEnum;
class SolverSchemaHeader
{
public:
    SchemaEnum m_type;
};
template <class T> __forceinline const T* hkAddByteOffsetConst(const T* base, long offset)
{
    return reinterpret_cast<const T*>(reinterpret_cast<const char*>(base) + offset);
}
__forceinline SchemaEnum getType(const SolverSchemaHeader* s) { return *reinterpret_cast<const SchemaEnum*>(hkAddByteOffsetConst(s, 0)); }
__forceinline int getNumSolverElemTemps(const SolverSchemaHeader* s)
{
    const int numSolverElemTemps = DAT_011b9434[(SolverSchemaType)getType(s)];
    return numSolverElemTemps;
}
SchemaEnum __cdecl FUN_00d921c0(const SolverSchemaHeader* s);
class __declspec(align(16)) ConstraintHeaderSchema : public SolverSchemaHeader
{
public:
    __forceinline ConstraintStepAccumulator* getBodyA(ConstraintStepAccumulator* base) const
    {
        return reinterpret_cast<ConstraintStepAccumulator*>(reinterpret_cast<char*>(base) + ((int)m_pBodyA << 7));
    }
    __forceinline ConstraintStepAccumulator* getBodyB(ConstraintStepAccumulator* base) const
    {
        return reinterpret_cast<ConstraintStepAccumulator*>(reinterpret_cast<char*>(base) + ((int)m_pBodyB << 7));
    }
    unsigned char unk01;
    unsigned short m_numTemps;
    unsigned short m_pBodyA;
    unsigned short m_pBodyB;
};
class SchemaJump : public SolverSchemaHeader
{
public:
    int m_offset;
};
class ConstraintJacobian
{
public:
    __forceinline const ConstraintStepReal& getRHS() const { return m_kLinearJacobian(3); }
    __forceinline const ConstraintStepScalar getRhsSr() const { return m_kLinearJacobian.getSimdAt(3); }
    __forceinline ConstraintStepReal getInvJacDiag() const { return m_kAngularVelocity[0](3); }
    __forceinline ConstraintStepScalar getInvJacDiagSr() const { return m_kAngularVelocity[0].getSimdAt(3); }
    __forceinline ConstraintStepReal getUserValue() const { return m_kAngularVelocity[1](3); }
    __forceinline ConstraintStepScalar getUserValueSr() const { return m_kAngularVelocity[1].getSimdAt(3); }
    ConstraintStepVector m_kLinearJacobian;
    ConstraintStepVector m_kAngularVelocity[2];
};
class AngularJacobianElement
{
public:
    __forceinline ConstraintStepReal getAngularRhs() const { return m_kAngularVelocity[1](3); }
    __forceinline ConstraintStepScalar getAngularRhsSr() const { return m_kAngularVelocity[1].getSimdAt(3); }
    __forceinline ConstraintStepReal getInvJacDiag() const { return m_kAngularVelocity[0](3); }
    __forceinline ConstraintStepScalar getInvJacDiagSr() const { return m_kAngularVelocity[0].getSimdAt(3); }
    ConstraintStepVector m_kAngularVelocity[2];
};
class JacobianElement
{
public:
    __forceinline ConstraintStepScalar getRhsSr() const { return m_kTranslationalVelocity[0].getSimdAt(3); }
    __forceinline ConstraintStepScalar getInvJacDiagSr() const { return m_kAngularVelocity[0].getSimdAt(3); }
    ConstraintStepVector m_kTranslationalVelocity[2];
    ConstraintStepVector m_kAngularVelocity[2];
};
class JacobianPair { public: ConstraintJacobian m_kFirstFrictionJacobian, m_kSecondFrictionJacobian; ConstraintStepReal m_offDiag; };
class Friction3DSchema { public: ConstraintJacobian m_kFirstFrictionJacobian, m_kSecondFrictionJacobian; AngularJacobianElement m_kAngularVelocity; ConstraintStepReal m_offDiag, m_maxFrictionImpulse, m_angularFactor; };
class TwoAxisFrictionInfo { public: ConstraintJacobian m_kFirstFrictionJacobian, m_kSecondFrictionJacobian; ConstraintStepReal m_offDiag, m_maxFrictionImpulse; };
class Friction2DSchema { public: AngularJacobianElement m_kFirstFrictionJacobian, m_kSecondFrictionJacobian; ConstraintStepReal m_maxFrictionImpulse; };
class JacobianPointerSchema : public ConstraintJacobian {};
class JacobianDataHolder : public ConstraintJacobian {};
class LinearSoftConstraintAtom : public ConstraintJacobian { public: ConstraintStepReal m_userTau, m_userDamping; };
class FrictionImpulseLimitAtom : public ConstraintJacobian { public: ConstraintStepReal m_maxFrictionImpulse; };
class LinearDistanceLimitAtom : public ConstraintJacobian { public: ConstraintStepReal m_minLimit, m_maxLimit; };
struct hkpMotorInfo { ConstraintStepReal m_minImpulse, m_usFlags, m_fVelocity, m_fTau, m_fMotorDamping; };
class MotorSolverSchema : public ConstraintJacobian { public: hkpMotorInfo m_pMotor; };
class JacobianHolder : public AngularJacobianElement {};
class FrictionImpulseLimitedJacobian : public AngularJacobianElement { public: ConstraintStepReal m_maxFrictionImpulse; };
class AngularLimitJacobian : public AngularJacobianElement { public: ConstraintStepReal m_minLimit, m_maxLimit, m_userTau; };
class MotorInfoRecord : public AngularJacobianElement { public: hkpMotorInfo m_pMotor; };
class SingleJacobianSchema : public JacobianElement {};
class SetInverseMassSchema { public: ConstraintStepVector m_invMassA, m_invMassB; };
class AddVelocitySchema { public: ConstraintStepVector m_fVelocity; int m_iBodyIndex; };
class hkpJacobianSetComSchema { public: ConstraintStepMatrix m_angularA, m_angularB; };
class hkpStiffChainSchema : public SolverSchemaHeader { public: unsigned char unk01; unsigned short m_iConstraintCount; int m_sizeOfNext; };
class hkpBallChainSchema : public SolverSchemaHeader { public: unsigned char unk01; unsigned short m_iConstraintCount; int m_sizeOfNext; };
class hkpPoweredChainSchema : public SolverSchemaHeader { public: unsigned char flags; unsigned short m_numTemps, m_pBodyA, m_pBodyB; int unk08, unk0c, m_nextOffset; };
__forceinline void loadFixedRegisters() {}
struct FloatRecord;
__forceinline void storeDelayedResult(FloatRecord*) {}
__forceinline void prefetchVelocityAccumulators(ConstraintStepAccumulator& a, ConstraintStepAccumulator& b) {}
__forceinline void reserveRegisters(unsigned int) {}
__forceinline void loadVelocityAccumulators(const ConstraintStepAccumulator& a, const ConstraintStepAccumulator& b) { reserveRegisters(0xFFFF0000); }
__forceinline void releaseRegisters(unsigned int) {}
__forceinline void storeVelocityAccumulators(ConstraintStepAccumulator& a, ConstraintStepAccumulator& b) { releaseRegisters(0xFFFF0000); }
__forceinline ConstraintStepReal hkMath_fabs(ConstraintStepReal r) { return fabsf(r); }
__forceinline ConstraintStepReal hkMath_sqrt(ConstraintStepReal r) { return sqrtf(r); }
__forceinline ConstraintStepReal hkMath_sqrtInverse(ConstraintStepReal r) { return 1.0f / hkMath_sqrt(r); }
__forceinline ConstraintStepScalar getLinearDv0(const ConstraintJacobian& jac, const ConstraintStepAccumulator& mA, const ConstraintStepAccumulator& mB, const ConstraintSolverInfo& info)
{
    ConstraintStepVector a; a.setSub4(mA.m_vLinearVelocity, mB.m_vLinearVelocity);
    ConstraintStepVector b; b.setMul4(mA.m_vAngularVelocity, jac.m_kAngularVelocity[0]);
    ConstraintStepVector c; c.setMul4(mB.m_vAngularVelocity, jac.m_kAngularVelocity[1]);
    a.mul4(jac.m_kLinearJacobian);
    b.add4(c);
    b.add4(a);
    const ConstraintStepScalar vel = b.horizontalAdd3();
    const ConstraintStepScalar dv = jac.getRhsSr() - vel;
    return dv;
}
__forceinline ConstraintStepScalar getAngularDv0(const AngularJacobianElement& jac, const ConstraintStepAccumulator& mA, const ConstraintStepAccumulator& mB)
{
    ConstraintStepVector a; a.setMul4(mA.m_vAngularVelocity, jac.m_kAngularVelocity[0]);
    ConstraintStepVector b; b.setMul4(mB.m_vAngularVelocity, jac.m_kAngularVelocity[1]);
    a.add4(b);
    const ConstraintStepScalar vel = a.horizontalAdd3();
    const ConstraintStepScalar dv = jac.getAngularRhsSr() - vel;
    return dv;
}
__forceinline ConstraintStepScalar getLinearDv0UserTauWithCustomRhs(const ConstraintJacobian& jac, const ConstraintStepAccumulator& mA, const ConstraintStepAccumulator& mB, const ConstraintSolverInfo& info, ConstraintStepReal tau, ConstraintStepReal damping, ConstraintStepReal customRhs)
{
    ConstraintStepVector vel4;
    {
        ConstraintStepVector linVelA; linVelA.setSub4(mA.m_vLinearVelocity, mA.getSumLinearVel());
        ConstraintStepVector angVelA; angVelA.setSub4(mA.m_vAngularVelocity, mA.getSumAngularVel());
        ConstraintStepVector linVelB; linVelB.setSub4(mB.m_vLinearVelocity, mB.getSumLinearVel());
        ConstraintStepVector angVelB; angVelB.setSub4(mB.m_vAngularVelocity, mB.getSumAngularVel());
        ConstraintStepVector a; a.setSub4(linVelA, linVelB);
        ConstraintStepVector b; b.setMul4(angVelA, jac.m_kAngularVelocity[0]);
        ConstraintStepVector c; c.setMul4(angVelB, jac.m_kAngularVelocity[1]);
        a.mul4(jac.m_kLinearJacobian);
        b.add4(c);
        vel4.setAdd4(b, a);
    }
    ConstraintStepVector svel4;
    {
        ConstraintStepVector linVelA = mA.getSumLinearVel();
        ConstraintStepVector angVelA = mA.getSumAngularVel();
        ConstraintStepVector linVelB = mB.getSumLinearVel();
        ConstraintStepVector angVelB = mB.getSumAngularVel();
        ConstraintStepVector a; a.setSub4(linVelA, linVelB);
        ConstraintStepVector b; b.setMul4(angVelA, jac.m_kAngularVelocity[0]);
        ConstraintStepVector c; c.setMul4(angVelB, jac.m_kAngularVelocity[1]);
        a.mul4(jac.m_kLinearJacobian);
        b.add4(c);
        svel4.setAdd4(b, a);
    }
    const ConstraintStepReal ru = info.m_kTimeStep(0) * tau;
    svel4.mul4(ru);
    vel4.mul4(damping);
    ConstraintStepVector dv; dv.setAdd4(svel4, vel4);
    const ConstraintStepReal rhsUpdate = dv.horizontalAdd3();
    return customRhs * tau - rhsUpdate;
}
__forceinline ConstraintStepScalar getLinearDv0UserTau(const ConstraintJacobian& jac, const ConstraintStepAccumulator& mA, const ConstraintStepAccumulator& mB, const ConstraintSolverInfo& info, ConstraintStepReal tau, ConstraintStepReal damping)
{
    return getLinearDv0UserTauWithCustomRhs(jac, mA, mB, info, tau, damping, jac.getRHS());
}
__forceinline ConstraintStepScalar getAngularDv0UserTauWithCustomRhs(const AngularJacobianElement& jac, const ConstraintStepAccumulator& mA, const ConstraintStepAccumulator& mB, const ConstraintSolverInfo& info, ConstraintStepReal tau, ConstraintStepReal damping, ConstraintStepReal customAngularRhs)
{
    ConstraintStepVector vel4;
    {
        ConstraintStepVector angVelA; angVelA.setSub4(mA.m_vAngularVelocity, mA.getSumAngularVel());
        ConstraintStepVector angVelB; angVelB.setSub4(mB.m_vAngularVelocity, mB.getSumAngularVel());
        ConstraintStepVector a; a.setMul4(angVelA, jac.m_kAngularVelocity[0]);
        ConstraintStepVector b; b.setMul4(angVelB, jac.m_kAngularVelocity[1]);
        vel4.setAdd4(a, b);
    }
    ConstraintStepVector svel4;
    {
        ConstraintStepVector angVelA = mA.getSumAngularVel();
        ConstraintStepVector angVelB = mB.getSumAngularVel();
        ConstraintStepVector a; a.setMul4(angVelA, jac.m_kAngularVelocity[0]);
        ConstraintStepVector b; b.setMul4(angVelB, jac.m_kAngularVelocity[1]);
        svel4.setAdd4(a, b);
    }
    const ConstraintStepReal ru = info.m_kTimeStep(0) * tau;
    svel4.mul4(ru);
    vel4.mul4(damping);
    ConstraintStepVector dv; dv.setAdd4(svel4, vel4);
    const ConstraintStepReal rhsUpdate = dv.horizontalAdd3();
    return customAngularRhs * tau - rhsUpdate;
}
__forceinline ConstraintStepScalar getAngularDv0UserTau(const AngularJacobianElement& jac, const ConstraintStepAccumulator& mA, const ConstraintStepAccumulator& mB, const ConstraintSolverInfo& info, ConstraintStepReal tau, ConstraintStepReal damping)
{
    return getAngularDv0UserTauWithCustomRhs(jac, mA, mB, info, tau, damping, jac.getAngularRhs());
}
__forceinline void applyImpulse(ConstraintStepScalarParameter imp, const ConstraintJacobian& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr)
{
    ConstraintStepVector impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    ConstraintStepVector impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    ConstraintStepVector impLinA; impLinA.setBroadcast3clobberW(impA, 3);
    ConstraintStepVector negImpLinB; negImpLinB.setBroadcast3clobberW(impB, 3);
    impLinA.mul4(jac.m_kLinearJacobian);
    negImpLinB.mul4(jac.m_kLinearJacobian);
    mA.m_vLinearVelocity.add3clobberW(impLinA);
    mB.m_vLinearVelocity.sub3clobberW(negImpLinB);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    ConstraintStepScalar s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    constraintStepStore(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void applyImpulse0(ConstraintStepScalarParameter imp, const ConstraintJacobian& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr)
{
    applyImpulse(imp, jac, mA, mB, sr);
}
__forceinline void applyImpulse1(ConstraintStepScalarParameter imp, const ConstraintJacobian& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr)
{
    applyImpulse(imp, jac, mA, mB, sr);
}
__forceinline void applyImpulse01(ConstraintStepScalarParameter imp0, ConstraintStepScalarParameter imp1, const ConstraintJacobian* jacs, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* srs)
{
    applyImpulse0(imp0, jacs[0], mA, mB, *srs);
    applyImpulse1(imp1, jacs[1], mA, mB, srs[1]);
}
__forceinline void ApplyAngularImpulseToBodies(ConstraintStepScalarParameter imp, const AngularJacobianElement& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr)
{
    ConstraintStepVector impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    ConstraintStepVector impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    ConstraintStepScalar s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    constraintStepStore(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void applyAngularImpulseSwappedMul(ConstraintStepScalarParameter imp, const AngularJacobianElement& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr)
{
    ConstraintStepVector impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    ConstraintStepVector impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    impB.mul4(jac.m_kAngularVelocity[1]);
    impA.mul4(jac.m_kAngularVelocity[0]);
    ConstraintStepScalar s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    constraintStepStore(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void applyAngularImpulse0(ConstraintStepScalarParameter imp, const AngularJacobianElement& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr)
{
    ApplyAngularImpulseToBodies(imp, jac, mA, mB, sr);
}
__forceinline void getDv01(const ConstraintJacobian* jac, const ConstraintStepAccumulator& mA, const ConstraintStepAccumulator& mB, const ConstraintSolverInfo& info, ConstraintStepVector& velOut)
{
    velOut(0) = getLinearDv0(jac[0], mA, mB, info);
    velOut(1) = getLinearDv0(jac[1], mA, mB, info);
}
__forceinline void getDv012(const Friction3DSchema* jac, const ConstraintStepAccumulator& mA, const ConstraintStepAccumulator& mB, const ConstraintSolverInfo& info, ConstraintStepVector& velOut)
{
    velOut(0) = getLinearDv0(jac->m_kFirstFrictionJacobian, mA, mB, info);
    velOut(1) = getLinearDv0(jac->m_kSecondFrictionJacobian, mA, mB, info);
    velOut(2) = getAngularDv0(jac->m_kAngularVelocity, mA, mB);
}
__forceinline void SolveSingleContact(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const JacobianPointerSchema& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    {
        ConstraintStepScalar dv = getLinearDv0(schema, mA, mB, info);
        ConstraintStepScalar impulse = dv * schema.getInvJacDiagSr();
        ConstraintStepScalar negPreviousImpulse = ConstraintStepScalar(DAT_010c7160) - ConstraintStepScalar(sr->m_fAccumulatedImpulse);
        constraintStepSetMax(negPreviousImpulse, impulse, impulse);
        applyImpulse0(impulse, schema, mA, mB, *sr);
    }
}
__forceinline void solveSingleLimitContact(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const JacobianPointerSchema& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    ConstraintStepScalar dv = getLinearDv0(schema, mA, mB, info);
    {
        ConstraintStepScalar impulse = dv * schema.getInvJacDiagSr();
        ConstraintStepScalar maxImpulse = schema.getUserValueSr();
        ConstraintStepScalar impulseApplied = sr->m_fAccumulatedImpulse;
        ConstraintStepScalar negImpApplied = ConstraintStepScalar(DAT_010c7160) - impulseApplied;
        maxImpulse = maxImpulse - impulseApplied;
        constraintStepSetMax(negImpApplied, impulse, impulse);
        constraintStepSetMin(maxImpulse, impulse, impulse);
        applyImpulse0(impulse, schema, mA, mB, *sr);
    }
}
__forceinline void solvePairContact(const ConstraintSolverInfo& info, const JacobianPair& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr)
{
    ConstraintStepVector dv4;
    getDv01(&schema.m_kFirstFrictionJacobian, mA, mB, info, dv4);
    const ConstraintStepReal dv0 = dv4(0);
    const ConstraintStepReal dv1 = dv4(1);
    ConstraintStepReal imp0 = schema.m_kFirstFrictionJacobian.getUserValue() * dv0 + dv1 * schema.m_offDiag;
    ConstraintStepReal imp1 = schema.m_kSecondFrictionJacobian.getUserValue() * dv1 + dv0 * schema.m_offDiag;
    if (imp0 > -sr[0].m_fAccumulatedImpulse)
    {
        if (imp1 > -sr[1].m_fAccumulatedImpulse)
        {
            applyImpulse01(imp0, imp1, &schema.m_kFirstFrictionJacobian, mA, mB, sr);
        }
        else
        {
checkImp0:
            ConstraintStepScalar imp01 = ConstraintStepScalar(dv4(0)) * schema.m_kFirstFrictionJacobian.getInvJacDiagSr();
            ConstraintStepScalar negImp = ConstraintStepScalar(DAT_010c7160) - ConstraintStepScalar(sr[0].m_fAccumulatedImpulse);
            constraintStepSetMax(negImp, imp01, imp01);
            applyImpulse0(imp01, schema.m_kFirstFrictionJacobian, mA, mB, *sr);
        }
    }
    else
    {
        ConstraintStepReal imp10 = schema.m_kSecondFrictionJacobian.getInvJacDiag() * dv1;
        if (imp10 <= -sr[1].m_fAccumulatedImpulse)
        {
            goto checkImp0;
        }
        applyImpulse1(imp10, schema.m_kSecondFrictionJacobian, mA, mB, sr[1]);
    }
}
__forceinline void solve3dFriction(const ConstraintSolverInfo& info, const Friction3DSchema& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr)
{
    ConstraintStepVector vel4;
    getDv012(&schema, mA, mB, info, vel4);
    const ConstraintStepReal dv0 = vel4(0);
    const ConstraintStepReal dv1 = vel4(1);
    const ConstraintStepReal dva = vel4(2);
    ConstraintStepReal angularImp = schema.m_kAngularVelocity.getInvJacDiag() * dva;
    const ConstraintStepReal maxSquared = schema.m_maxFrictionImpulse * schema.m_maxFrictionImpulse;
    ConstraintStepReal imp0 = schema.m_kFirstFrictionJacobian.getUserValue() * dv0 + dv1 * schema.m_offDiag;
    ConstraintStepReal imp1 = schema.m_kSecondFrictionJacobian.getUserValue() * dv1 + dv0 * schema.m_offDiag;
    const ConstraintStepReal impSquared = imp0 * imp0 + imp1 * imp1 + angularImp * angularImp;
    if (impSquared > maxSquared)
    {
        const ConstraintStepReal factor = hkMath_sqrtInverse(impSquared) * schema.m_maxFrictionImpulse;
        imp0 *= factor;
        imp1 *= factor;
        angularImp *= factor;
        sr[3].m_fAccumulatedImpulse = factor;
    }
    else
    {
        sr[3].m_fAccumulatedImpulse = 1.0f;
    }
    angularImp *= schema.m_angularFactor;
    applyImpulse01(imp0, imp1, &schema.m_kFirstFrictionJacobian, mA, mB, sr);
    applyAngularImpulse0(angularImp, schema.m_kAngularVelocity, mA, mB, sr[2]);
}
__forceinline void solve2dFriction(const ConstraintSolverInfo& info, const TwoAxisFrictionInfo& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr)
{
    ConstraintStepVector vel4;
    getDv01(&schema.m_kFirstFrictionJacobian, mA, mB, info, vel4);
    const ConstraintStepReal dv0 = vel4(0);
    const ConstraintStepReal dv1 = vel4(1);
    const ConstraintStepReal maxImpulseReg = schema.m_maxFrictionImpulse;
    const ConstraintStepReal maxSquared = maxImpulseReg * maxImpulseReg;
    ConstraintStepReal imp0 = schema.m_kFirstFrictionJacobian.getUserValue() * dv0 + dv1 * schema.m_offDiag;
    ConstraintStepReal imp1 = schema.m_kSecondFrictionJacobian.getUserValue() * dv1 + dv0 * schema.m_offDiag;
    const ConstraintStepReal impSquared = imp0 * imp0 + imp1 * imp1;
    if (impSquared > maxSquared)
    {
        const ConstraintStepReal factor = hkMath_sqrt(maxSquared / impSquared);
        imp0 *= factor;
        imp1 *= factor;
        sr[2].m_fAccumulatedImpulse = factor;
    }
    else
    {
        sr[2].m_fAccumulatedImpulse = 1.0f;
    }
    applyImpulse01(imp0, imp1, &schema.m_kFirstFrictionJacobian, mA, mB, sr);
}
__forceinline void rollingFields(ConstraintStepScalarParameter imp, const AngularJacobianElement& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr, ConstraintStepQuad& field0, const ConstraintStepVector& field2)
{
    ConstraintStepVector impA; impA.setMul4(imp, field2);
    ConstraintStepVector impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    ConstraintStepScalar s = sr.m_fAccumulatedImpulse;
    field0=_mm_add_ps(impA.m_vComponents,field0);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    constraintStepStore(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void solve2dRollingFriction( const Friction2DSchema& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr)
{
    const AngularJacobianElement& jac0 = schema.m_kFirstFrictionJacobian;
    const AngularJacobianElement& jac1 = schema.m_kSecondFrictionJacobian;
    const ConstraintStepReal dv0 = getAngularDv0(jac0, mA, mB);
    const ConstraintStepReal dv1 = getAngularDv0(jac1, mA, mB);
    const ConstraintStepReal maxImpulseReg = schema.m_maxFrictionImpulse;
    const ConstraintStepReal maxSquared = maxImpulseReg * maxImpulseReg;
    ConstraintStepReal imp0 = jac0.getInvJacDiag() * dv0;
    ConstraintStepReal imp1 = jac1.getInvJacDiag() * dv1;
    const ConstraintStepReal impSquared = imp0 * imp0 + imp1 * imp1;
    if (impSquared > maxSquared)
    {
        const ConstraintStepReal factor = hkMath_sqrt(maxSquared / impSquared);
        imp0 *= factor;
        imp1 *= factor;
        sr[2].m_fAccumulatedImpulse = factor;
    }
    else
    {
        sr[2].m_fAccumulatedImpulse = 1.0f;
    }
    rollingFields(imp0, jac0, mA, mB, sr[0], mA.m_vAngularVelocity.m_vComponents, mA.m_vInverseInertiaAndMass);
    applyAngularImpulse0(imp1, jac1, mA, mB, sr[1]);
}
__forceinline void solve1dAngFriction(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const FrictionImpulseLimitedJacobian& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr)
{
    const ConstraintStepReal dv0 = getAngularDv0(schema, mA, mB);
    ConstraintStepReal imp0 = schema.getInvJacDiag() * dv0;
    const ConstraintStepReal fimp0 = hkMath_fabs(imp0);
    if (fimp0 > schema.m_maxFrictionImpulse)
    {
        const ConstraintStepReal factor = schema.m_maxFrictionImpulse / fimp0;
        imp0 *= factor;
        sr[1].m_fAccumulatedImpulse = factor;
    }
    else
    {
        sr[1].m_fAccumulatedImpulse = 1.0f;
    }
    applyAngularImpulse0(imp0, schema, mA, mB, *sr);
}
__forceinline void lowerApplication(ConstraintStepScalarParameter imp, const AngularJacobianElement& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr, const ConstraintStepVector& massA, const ConstraintStepVector& massB)
{
    ConstraintStepVector impA; impA.setMul4(imp, massA);
    ConstraintStepVector impB; impB.setMul4(imp, massB);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    ConstraintStepScalar s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    constraintStepStore(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void solve1dAngLimits(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const AngularLimitJacobian& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    const ConstraintStepReal dv = getAngularDv0UserTau(schema, mA, mB, info, schema.m_userTau, info.m_fMotorDamping);
    const ConstraintStepReal negAppliedImpulse = -sr->m_fAccumulatedImpulse;
    {
        ConstraintStepReal impulse = dv - schema.m_minLimit;
        impulse = schema.getInvJacDiag() * impulse;
        if (impulse > negAppliedImpulse)
        {
            applyAngularImpulse0(impulse, schema, mA, mB, *sr);
            return;
        }
    }
    {
        ConstraintStepReal impulse = dv - schema.m_maxLimit;
        impulse = schema.getInvJacDiag() * impulse;
        if (impulse < negAppliedImpulse)
        {
            lowerApplication(impulse, schema, mA, mB, *sr, mA.m_vInverseInertiaAndMass, mB.m_vInverseInertiaAndMass);
        }
    }
}
__forceinline void regionApplication(ConstraintStepScalarParameter imp, const AngularJacobianElement& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr, const ConstraintStepVector& massA, const ConstraintStepVector& massB, const ConstraintStepVector& axisA, const ConstraintStepVector& axisB)
{
    ConstraintStepVector impA; impA.setMul4(imp, massA);
    ConstraintStepVector impB; impB.setMul4(imp, massB);
    impA.mul4(axisA);
    impB.mul4(axisB);
    ConstraintStepScalar s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    constraintStepStore(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void solve1dAngularMotor(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const MotorInfoRecord& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    const hkpMotorInfo& motorInfo = schema.m_pMotor;
    sr[2].m_fAccumulatedImpulse = temp.m_stepFactor * motorInfo.m_fVelocity + sr[2].m_fAccumulatedImpulse;
    const ConstraintStepReal customAngularRhs = schema.getAngularRhs() + sr[2].m_fAccumulatedImpulse;
    const ConstraintStepReal dv0 = getAngularDv0UserTauWithCustomRhs(schema, mA, mB, info, motorInfo.m_fTau, motorInfo.m_fMotorDamping, customAngularRhs);
    ConstraintStepReal impulse = schema.getInvJacDiag() * dv0;
    if (impulse > motorInfo.m_minImpulse)
    {
        sr[1].m_fAccumulatedImpulse = motorInfo.m_minImpulse / impulse;
        impulse = motorInfo.m_minImpulse;
    }
    else if (impulse < motorInfo.m_usFlags)
    {
        sr[1].m_fAccumulatedImpulse = motorInfo.m_usFlags / impulse;
        impulse = motorInfo.m_usFlags;
    }
    else
    {
        sr[1].m_fAccumulatedImpulse = 1.0f;
    }
    regionApplication(impulse, schema, mA, mB, *sr, mA.m_vInverseInertiaAndMass, mB.m_vInverseInertiaAndMass, schema.m_kAngularVelocity[0], schema.m_kAngularVelocity[1]);
}
__forceinline void nativeApplication(ConstraintStepScalarParameter imp, const AngularJacobianElement& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr)
{
    ConstraintStepVector impA; impA = _mm_mul_ps(imp.broadcast(), mA.m_vInverseInertiaAndMass);
    ConstraintStepVector impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    impB.mul4(jac.m_kAngularVelocity[1]);
    impA.mul4(jac.m_kAngularVelocity[0]);
    ConstraintStepScalar s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    constraintStepStore(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void solve1dAngular(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const JacobianHolder& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    ConstraintStepScalar dv = getAngularDv0(schema, mA, mB);
    ConstraintStepScalar impulse = dv * schema.getInvJacDiagSr();
    nativeApplication(impulse, schema, mA, mB, *sr);
}

__forceinline ConstraintStepScalar getLinearDv0B(const ConstraintJacobian& jac, const ConstraintStepAccumulator& mA, const ConstraintStepAccumulator& mB)
{
    ConstraintStepVector a; a.setSub4(mA.m_vLinearVelocity, mB.m_vLinearVelocity);
    ConstraintStepVector b; b.setMul4(mA.m_vAngularVelocity, jac.m_kAngularVelocity[0]);
    ConstraintStepVector c; c.setMul4(mB.m_vAngularVelocity, jac.m_kAngularVelocity[1]);
    a.mul4(jac.m_kLinearJacobian);
    b.add4(c);
    b.add4(a);
    const ConstraintStepScalar vel = b.horizontalAdd3();
    const ConstraintStepScalar dv = jac.getRhsSr() - vel;
    return dv;
}
__forceinline ConstraintStepScalar addB(ConstraintStepScalarParameter r, ConstraintStepScalarParameter t, const FloatRecord& sr)
{
    return _mm_add_ss(r.getQuad(), t.getQuad());
}
__forceinline void applyImpulseB(ConstraintStepScalarParameter imp, const ConstraintJacobian& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr)
{
    ConstraintStepVector impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    ConstraintStepVector impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    ConstraintStepVector impLinA; impLinA.setBroadcast3clobberW(impA, 3);
    ConstraintStepVector negImpLinB; negImpLinB.setBroadcast3clobberW(impB, 3);
    impLinA.mul4(jac.m_kLinearJacobian);
    negImpLinB.mul4(jac.m_kLinearJacobian);
    mA.m_vLinearVelocity.add3clobberW(impLinA);
    mB.m_vLinearVelocity.sub3clobberW(negImpLinB);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    ConstraintStepScalar s = sr.m_fAccumulatedImpulse;
    impA.commitIncrement(mA.m_vAngularVelocity);
    impB.commitIncrement(mB.m_vAngularVelocity);
    s = addB(s, imp, sr);
    constraintStepStore(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void applyImpulseB0(ConstraintStepScalarParameter imp, const ConstraintJacobian& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr)
{
    applyImpulseB(imp, jac, mA, mB, sr);
}

__forceinline void solve1dBilateral(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const JacobianDataHolder& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    ConstraintStepScalar vel = getLinearDv0B(schema, mA, mB);
    ConstraintStepScalar impulse = vel * schema.getInvJacDiagSr();
    applyImpulseB0(impulse, schema, mA, mB, *sr);
}
__forceinline void linearApplication(ConstraintStepScalarParameter imp, const ConstraintJacobian& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr, ConstraintStepVector& linearA)
{
    ConstraintStepVector impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    ConstraintStepVector impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    ConstraintStepVector impLinA; impLinA.setBroadcast3clobberW(impA, 3);
    ConstraintStepVector negImpLinB; negImpLinB.setBroadcast3clobberW(impB, 3);
    impLinA.mul4(jac.m_kLinearJacobian);
    negImpLinB.mul4(jac.m_kLinearJacobian);
    linearA.add3clobberW(impLinA);
    mB.m_vLinearVelocity.sub3clobberW(negImpLinB);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    ConstraintStepScalar s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    constraintStepStore(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void solve1dBilateralWithImpulseLimit(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const JacobianDataHolder& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    ConstraintStepScalar vel = getLinearDv0(schema, mA, mB, info);
    ConstraintStepScalar impulse = vel * schema.getInvJacDiagSr();
    ConstraintStepScalar impulseApplied = sr->m_fAccumulatedImpulse;
    ConstraintStepScalar maxImpulse = schema.getUserValueSr();
    ConstraintStepScalar minImpulse = -maxImpulse;
    maxImpulse = maxImpulse - impulseApplied;
    minImpulse = minImpulse - impulseApplied;
    constraintStepSetMax(minImpulse, impulse, impulse);
    constraintStepSetMin(maxImpulse, impulse, impulse);
    linearApplication(impulse, schema, mA, mB, *sr, mA.m_vLinearVelocity);
}
__forceinline void solve1dBilateralUserTau(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const LinearSoftConstraintAtom& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    ConstraintStepScalar dv = getLinearDv0UserTau(schema, mA, mB, info, schema.m_userTau, schema.m_userDamping);
    ConstraintStepScalar impulse = dv * schema.getInvJacDiagSr();
    applyImpulse0(impulse, schema, mA, mB, *sr);
}
__forceinline void solve1dFriction(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const FrictionImpulseLimitAtom& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    const ConstraintStepReal dv0 = getLinearDv0(schema, mA, mB, info);
    ConstraintStepReal imp0 = schema.getInvJacDiag() * dv0;
    const ConstraintStepReal fimp0 = hkMath_fabs(imp0);
    if (fimp0 > schema.m_maxFrictionImpulse)
    {
        const ConstraintStepReal factor = schema.m_maxFrictionImpulse / fimp0;
        imp0 *= factor;
        sr[1].m_fAccumulatedImpulse = factor;
    }
    else
    {
        sr[1].m_fAccumulatedImpulse = 1.0f;
    }
    applyImpulse0(imp0, schema, mA, mB, *sr);
}
__forceinline void solve1dLinLimits(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const LinearDistanceLimitAtom& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    const ConstraintStepReal dv = getLinearDv0(schema, mA, mB, info);
    const ConstraintStepReal negAppliedImpulse = -sr->m_fAccumulatedImpulse;
    {
        ConstraintStepReal impulse = dv - schema.m_minLimit;
        impulse = schema.getInvJacDiag() * impulse;
        if (impulse > negAppliedImpulse)
        {
            applyImpulse0(impulse, schema, mA, mB, *sr);
        }
    }
    {
        ConstraintStepReal impulse = dv - schema.m_maxLimit;
        impulse = schema.getInvJacDiag() * impulse;
        if (impulse < negAppliedImpulse)
        {
            applyImpulse0(impulse, schema, mA, mB, *sr);
        }
    }
}
__forceinline void solve1dLinearMotor(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const MotorSolverSchema& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    const hkpMotorInfo& motorInfo = schema.m_pMotor;
    sr[2].m_fAccumulatedImpulse = temp.m_stepFactor * motorInfo.m_fVelocity + sr[2].m_fAccumulatedImpulse;
    const ConstraintStepReal customRhs = schema.getRHS() + sr[2].m_fAccumulatedImpulse;
    const ConstraintStepReal dv0 = getLinearDv0UserTauWithCustomRhs(schema, mA, mB, info, motorInfo.m_fTau, motorInfo.m_fMotorDamping, customRhs);
    ConstraintStepReal impulse = schema.getInvJacDiag() * dv0;
    if (impulse > motorInfo.m_minImpulse)
    {
        sr[1].m_fAccumulatedImpulse = motorInfo.m_minImpulse / impulse;
        impulse = motorInfo.m_minImpulse;
    }
    else if (impulse < motorInfo.m_usFlags)
    {
        sr[1].m_fAccumulatedImpulse = motorInfo.m_usFlags / impulse;
        impulse = motorInfo.m_usFlags;
    }
    else
    {
        sr[1].m_fAccumulatedImpulse = 1.0f;
    }
    applyImpulse0(impulse, schema, mA, mB, *sr);
}
__forceinline ConstraintStepScalar getDv2Lin2Ang(const JacobianElement& jac, const ConstraintStepAccumulator& mA, const ConstraintStepAccumulator& mB, const ConstraintSolverInfo& info)
{
    ConstraintStepVector lA; lA.setMul4(mA.m_vLinearVelocity, jac.m_kTranslationalVelocity[0]);
    ConstraintStepVector lB; lB.setMul4(mB.m_vLinearVelocity, jac.m_kTranslationalVelocity[1]);
    ConstraintStepVector a; a.setMul4(mA.m_vAngularVelocity, jac.m_kAngularVelocity[0]);
    ConstraintStepVector b; b.setMul4(mB.m_vAngularVelocity, jac.m_kAngularVelocity[1]);
    ConstraintStepVector c; c.setSub4(lA, lB);
    a.add4(b);
    a.add4(c);
    const ConstraintStepScalar vel = a.horizontalAdd3();
    const ConstraintStepScalar dv = SubtractScalarFloat(jac.getRhsSr(), vel);
    return dv;
}
__forceinline void applyImpulse2Lin2Ang(ConstraintStepScalarParameter imp, const JacobianElement& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr)
{
    ConstraintStepVector impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    ConstraintStepVector impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    ConstraintStepVector impLinA; impLinA.setBroadcast3clobberW(impA, 3);
    ConstraintStepVector impLinB; impLinB.setBroadcast3clobberW(impB, 3);
    impLinA.mul4(jac.m_kTranslationalVelocity[0]);
    impLinB.mul4(jac.m_kTranslationalVelocity[1]);
    mA.m_vLinearVelocity.add3clobberW(impLinA);
    mB.m_vLinearVelocity.sub3clobberW(impLinB);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    ConstraintStepScalar s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    ConstraintStepScalar sum; sum=AddScalarFloat(s,imp); s=sum;
    constraintStepStore(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void solvePulley(const ConstraintSolverInfo& info, const SingleJacobianSchema& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    ConstraintStepScalar dv = getDv2Lin2Ang(schema, mA, mB, info);
    {
        ConstraintStepScalar impulse = (*(::ConstraintStepImplementation::ConstraintStepScalar *)(::FUN_00891060((::Vec4Dst *)&(dv), (::Vec4Src *)&(const ::ConstraintStepImplementation::ConstraintStepScalar &)(schema.getInvJacDiagSr()), {})));
        applyImpulse2Lin2Ang(impulse, schema, mA, mB, sr[0]);
    }
}
__forceinline int stepJacobian(const ConstraintSolverInfo& info, SolverStepInfo& temp, const SolverSchemaHeader* schemas, ConstraintStepAccumulator* accums, FloatRecord* srIn)
{
    const SolverSchemaHeader* com = schemas;
    FloatRecord* sr = srIn;
    SolverSchemaType schemaType = getType(com);
    if (schemaType == SCHEMA_TYPE_END)
    {
        return 0;
    }
    ConstraintStepAccumulator* mA;
    ConstraintStepAccumulator* mB;
    FloatRecord* delayedResult = 0;
    goto headerNoStoreVelocity;
    while (1)
    {
        schemaType = getType(com);
        switch (schemaType)
        {
        case SCHEMA_TYPE_HEADER:
header:
            {
                const ConstraintHeaderSchema* sc = reinterpret_cast<const ConstraintHeaderSchema*>(com);
                prefetchVelocityAccumulators(*sc->getBodyA(accums), *sc->getBodyB(accums));
                storeVelocityAccumulators(*mA, *mB);
headerNoStoreVelocity:
                {
                    const ConstraintHeaderSchema* sc = reinterpret_cast<const ConstraintHeaderSchema*>(com);
                    mA = sc->getBodyA(accums);
                    mB = sc->getBodyB(accums);

                    com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                }
                break;
            }
        case SCHEMA_TYPE_NOP:
            {
                const ConstraintHeaderSchema* sc = reinterpret_cast<const ConstraintHeaderSchema*>(com);
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                break;
            }
        case SCHEMA_TYPE_SINGLE_CONTACT:
        case SCHEMA_TYPE_SINGLE_CONTACT2:
case_SINGLE_CONTACT:
            {
                const JacobianPointerSchema* sc = reinterpret_cast<const JacobianPointerSchema*>(com);
                SolveSingleContact(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += getNumSolverElemTemps(com);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_SINGLE_CONTACT) goto case_SINGLE_CONTACT;
                break;
            }
        case SCHEMA_TYPE_SINGLE_LIMIT_CONTACT:
        case SCHEMA_TYPE_SINGLE_LIMIT_CONTACT2:
case_SINGLE_LIMIT_CONTACT:
            {
                const JacobianPointerSchema* sc = reinterpret_cast<const JacobianPointerSchema*>(com);
                solveSingleLimitContact(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += getNumSolverElemTemps(com);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_SINGLE_LIMIT_CONTACT) goto case_SINGLE_LIMIT_CONTACT;
                break;
            }
        case SCHEMA_TYPE_PAIR_CONTACT:
        case SCHEMA_TYPE_PAIR_CONTACT2:
            {
                const JacobianPair* sc = reinterpret_cast<const JacobianPair*>(com);
                solvePairContact(info, *sc, *mA, *mB, sr);
                sr += 2;
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (getType(com) != SCHEMA_TYPE_PAIR_CONTACT) continue;
            }
            {
                const JacobianPair* sc = reinterpret_cast<const JacobianPair*>(com);
                solvePairContact(info, *sc, *mA, *mB, sr);
                sr += 2;
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (getType(com) != SCHEMA_TYPE_3D_FRICTION) break;
            }
        case SCHEMA_TYPE_3D_FRICTION:
friction3d:
            {
                const Friction3DSchema* sc = reinterpret_cast<const Friction3DSchema*>(com);
                solve3dFriction(info, *sc, *mA, *mB, sr);
                sr += 4;
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_HEADER) goto header;
                break;
            }
        case SCHEMA_TYPE_2D_FRICTION:
friction2d:
            {
                const TwoAxisFrictionInfo* sc = reinterpret_cast<const TwoAxisFrictionInfo*>(com);
                solve2dFriction(info, *sc, *mA, *mB, sr);
                sr += 3;
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_HEADER) goto header;
                break;
            }
        case SCHEMA_TYPE_2D_ROLLING_FRICTION:
            {
                const Friction2DSchema* schema = reinterpret_cast<const Friction2DSchema*>(com);
                solve2dRollingFriction( *schema, *mA, *mB, sr);
                sr += FUN_00d921d0(&com->m_type.m_kStorage);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(schema + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(schema + 1);
                if (comtype == SCHEMA_TYPE_3D_FRICTION) goto friction3d;
                if (comtype == SCHEMA_TYPE_2D_FRICTION) goto friction2d;
                break;
            }
        case SCHEMA_TYPE_1D_ANGULAR_FRICTION:
case_1D_ANGULAR_FRICTION:
            {
                const FrictionImpulseLimitedJacobian* sc = reinterpret_cast<const FrictionImpulseLimitedJacobian*>(com);
                solve1dAngFriction(info, temp, *sc, *mA, *mB, sr);
                sr += FUN_00d921d0(&com->m_type.m_kStorage);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_ANGULAR_FRICTION) goto case_1D_ANGULAR_FRICTION;
                break;
            }
        case SCHEMA_TYPE_1D_ANGULAR_LIMITS:
case_1D_ANGULAR_LIMITS:
            {
                const AngularLimitJacobian* sc = reinterpret_cast<const AngularLimitJacobian*>(com);
                solve1dAngLimits(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += FUN_00d921d0(&com->m_type.m_kStorage);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_ANGULAR_LIMITS) goto case_1D_ANGULAR_LIMITS;
                break;
            }
        case SCHEMA_TYPE_1D_ANGULAR_MOTOR:
case_1D_ANGULAR_MOTOR:
            {
                const MotorInfoRecord* sc = reinterpret_cast<const MotorInfoRecord*>(com);
                solve1dAngularMotor(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += FUN_00d921d0(&com->m_type.m_kStorage);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_ANGULAR_MOTOR) goto case_1D_ANGULAR_MOTOR;
                break;
            }
        case SCHEMA_TYPE_1D_ANGULAR:
case_1D_ANGULAR:
            {
                const JacobianHolder* sc = reinterpret_cast<const JacobianHolder*>(com);
                solve1dAngular(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += FUN_00d921d0(&com->m_type.m_kStorage);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_ANGULAR) goto case_1D_ANGULAR;
                break;
            }
        case SCHEMA_TYPE_1D_BILATERAL:
case_1D_BILATERAL:
            {
                const JacobianDataHolder* sc = reinterpret_cast<const JacobianDataHolder*>(com);
                solve1dBilateral(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += FUN_00d921d0(&com->m_type.m_kStorage);
                const SolverSchemaType comtype = FUN_00d921c0(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_BILATERAL) goto case_1D_BILATERAL;
                break;
            }
        case SCHEMA_TYPE_1D_BILATERAL_WITH_IMPULSE_LIMIT:
case_1D_BILATERAL_WITH_IMPULSE_LIMIT:
            {
                const JacobianDataHolder* sc = reinterpret_cast<const JacobianDataHolder*>(com);
                solve1dBilateralWithImpulseLimit(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += FUN_00d921d0(&com->m_type.m_kStorage);
                const SolverSchemaType comtype = FUN_00d921c0(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_BILATERAL_WITH_IMPULSE_LIMIT) goto case_1D_BILATERAL_WITH_IMPULSE_LIMIT;
                break;
            }
        case SCHEMA_TYPE_1D_BILATERAL_USER_TAU:
case_1D_BILATERAL_USER_TAU:
            {
                const LinearSoftConstraintAtom* sc = reinterpret_cast<const LinearSoftConstraintAtom*>(com);
                solve1dBilateralUserTau(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += FUN_00d921d0(&com->m_type.m_kStorage);
                const SolverSchemaType comtype = FUN_00d921c0(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_BILATERAL_USER_TAU) goto case_1D_BILATERAL_USER_TAU;
                break;
            }
        case SCHEMA_TYPE_1D_FRICTION:
case_1D_FRICTION:
            {
                const FrictionImpulseLimitAtom* sc = reinterpret_cast<const FrictionImpulseLimitAtom*>(com);
                solve1dFriction(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += FUN_00d921d0(&com->m_type.m_kStorage);
                const SolverSchemaType comtype = FUN_00d921c0(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_FRICTION) goto case_1D_FRICTION;
                break;
            }
        case SCHEMA_TYPE_1D_LINEAR_LIMITS:
case_1D_LINEAR_LIMITS:
            {
                const LinearDistanceLimitAtom* sc = reinterpret_cast<const LinearDistanceLimitAtom*>(com);
                solve1dLinLimits(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += FUN_00d921d0(&com->m_type.m_kStorage);
                const SolverSchemaType comtype = FUN_00d921c0(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_LINEAR_LIMITS) goto case_1D_LINEAR_LIMITS;
                break;
            }
        case SCHEMA_TYPE_1D_LINEAR_MOTOR:
case_1D_LINEAR_MOTOR:
            {
                const MotorSolverSchema* sc = reinterpret_cast<const MotorSolverSchema*>(com);
                solve1dLinearMotor(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += FUN_00d921d0(&com->m_type.m_kStorage);
                const SolverSchemaType comtype = FUN_00d921c0(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_LINEAR_MOTOR) goto case_1D_LINEAR_MOTOR;
                break;
            }
        case SCHEMA_TYPE_1D_PULLEY:
            {
                const SingleJacobianSchema* sc = reinterpret_cast<const SingleJacobianSchema*>(com);
                solvePulley(info, *sc, *mA, *mB, sr, delayedResult);
                sr += 1;
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                break;
            }
        case SCHEMA_TYPE_SET_MASS:
            {
                const SetInverseMassSchema* sc = reinterpret_cast<const SetInverseMassSchema*>(com);
                storeVelocityAccumulators(*mA, *mB);
                mA->m_vInverseInertiaAndMass = sc->m_invMassA;
                mB->m_vInverseInertiaAndMass = sc->m_invMassB;
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                loadVelocityAccumulators(*mA, *mB);
                break;
            }
        case SCHEMA_TYPE_ADD_VELOCITY:
            {
                const AddVelocitySchema* sc = reinterpret_cast<const AddVelocitySchema*>(com);
                storeVelocityAccumulators(*mA, *mB);
                const int bodyIndex = sc->m_iBodyIndex;
                ConstraintStepAccumulator* accum = hkSelect(bodyIndex, mA, mB);
                const ConstraintStepReal f = info.m_kGravity(0) * ConstraintStepReal(int(temp.m_intStep));
                ConstraintStepScalar fs;
                new ((void *)&(fs)) ::FUN_005dbf20(f);
                ConstraintStepVector integratedVel; integratedVel.setMul4(fs, sc->m_fVelocity);
                sc->m_fVelocity.commitIncrement(accum->m_vLinearVelocity);
                accum->m_vLinearVelocity.add4(integratedVel);
                accum->getSumLinearVel().add4(integratedVel);
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                loadVelocityAccumulators(*mA, *mB);
                break;
            }
        case SCHEMA_TYPE_SET_CENTER_OF_MASS:
            {
                const hkpJacobianSetComSchema* sc = reinterpret_cast<const hkpJacobianSetComSchema*>(com);
                storeVelocityAccumulators(*mA, *mB);
                ConstraintStepVector deltaVelA; reinterpret_cast<::FUN_00c7f750_shell *>(&(deltaVelA))->FUN_00c7f750((float *)&(sc->m_angularA), (float *)&(mA->m_vAngularVelocity));
                ConstraintStepVector deltaVelB; reinterpret_cast<::FUN_00c7f750_shell *>(&(deltaVelB))->FUN_00c7f750((float *)&(sc->m_angularB), (float *)&(mB->m_vAngularVelocity));
                ConstraintStepVector deltaSumVelA; reinterpret_cast<::FUN_00c7f750_shell *>(&(deltaSumVelA))->FUN_00c7f750((float *)&(sc->m_angularA), (float *)&(mA->getSumAngularVel()));
                ConstraintStepVector deltaSumVelB; reinterpret_cast<::FUN_00c7f750_shell *>(&(deltaSumVelB))->FUN_00c7f750((float *)&(sc->m_angularB), (float *)&(mB->getSumAngularVel()));
                mA->m_vLinearVelocity.add4(deltaVelA);
                mA->getSumLinearVel().add4(deltaSumVelA);
                mB->m_vLinearVelocity.add4(deltaVelB);
                mB->getSumLinearVel().add4(deltaSumVelB);
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                loadVelocityAccumulators(*mA, *mB);
                break;
            }
        case SCHEMA_TYPE_GOTO:
            {
                const SchemaJump* sc = reinterpret_cast<const SchemaJump*>(com);
                com = hkAddByteOffsetConst(com, sc->m_offset);
                break;
            }
        case SCHEMA_TYPE_END:
            storeDelayedResult(delayedResult);
            storeVelocityAccumulators(*mA, *mB);
            return 0;
        case SCHEMA_TYPE_STIFF_SPRING_CHAIN:
            {
                const hkpStiffChainSchema* chain = reinterpret_cast<const hkpStiffChainSchema*>(com);
                ::FUN_00d893a0(&info, &temp, accums, (::ProbeHeader *)(chain), (float *)(sr));
                sr += chain->m_iConstraintCount;
                com = hkAddByteOffsetConst(com, chain->m_sizeOfNext);
                break;
            }
        case SCHEMA_TYPE_BALL_SOCKET_CHAIN:
            {
                const hkpBallChainSchema* chain = reinterpret_cast<const hkpBallChainSchema*>(com);
                ::FUN_00d89690((*(const ::hkpSolverInfoQ *)(&info)), (*(const ::hkSolverQ::SolverStepInfo *)(&temp)), (::hkpVelocityAccumulatorQ *)(accums), (::hkpJacobianBallSocketChainSchemaQ *)(chain), (::hkpSolverElemTempQ *)(sr));
                sr += 3 * chain->m_iConstraintCount;
                com = hkAddByteOffsetConst(com, chain->m_sizeOfNext);
                break;
            }
        case SCHEMA_TYPE_POWERED_CHAIN:
            {
                const hkpPoweredChainSchema* chain = reinterpret_cast<const hkpPoweredChainSchema*>(com);
                ::FUN_00d8a3a0((*(const ::PoweredChainSettings *)(&info)), (*(const ::PoweredChainSolver::PoweredChainStepTemp *)(&temp)), (::PoweredChainAccumulator *)(accums), (::PoweredChainSchema *)(chain), (::PoweredChainResult *)(sr));
                sr += 6 * chain->m_pBodyA;
                com = hkAddByteOffsetConst(com, chain->m_nextOffset);
                break;
            }
        default:
            fnv_Breakpoint();
            return 0;
        }
    }
}
// @fnv 0x00d8fb70
int __cdecl FUN_00d8fb70(const ConstraintSolverInfo& info, int currentSolverStep, int currentSolverMicroStep, const SolverSchemaHeader* schemas, ConstraintStepAccumulator* accumulators, FloatRecord* elemTemp)
{
    if (!DAT_01269204)
    {
        ::ValidateHavokKeyCode((bool *)(unsigned char *)(&DAT_01269204));
        if (!DAT_01269204) return 0;
    }

    SolverStepInfo temp;
    temp.m_intStep = currentSolverStep;
    temp.m_stepFactor = currentSolverMicroStep ? 0.0f : 1.0f;
    stepJacobian(info, temp, schemas, accumulators, elemTemp);
    return 1;
}

}

// Moved from hkpsolver_od_noo2_variant.cpp (VEGAS-15).
#include "fnv/decl/FUN_004a3c90.h"
#include "fnv/decl/Vec3.h"


struct Vec4Src
{
};

struct Vec4Dst
{
};

// @fnv 0x00891060
Vec4Dst* __cdecl FUN_00891060(Vec4Dst* out, Vec4Src* b, Vec4Src* a)
{
    new ((void *)(out)) ::FUN_004a3c90((const ::FUN_004a3c90 &)((const __m128 &)(_mm_mul_ss(*((__m128 *)(new ((void *)(b)) ::Vec3())), *((__m128 *)(new ((void *)(a)) ::Vec3()))))));
    return out;
}

// Moved from hkpsolver_rtm_variant.cpp (VEGAS-15).


struct SpawnedVec4 {
    unsigned int m_uiX;
    unsigned int m_uiY;
    unsigned int m_uiZ;
    unsigned int m_w;
};

struct SpawnedOwner {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    SpawnedVec4 m_vec10;
};

struct ZeroVec { __m128 q; __forceinline void clear() { q = _mm_setzero_ps(); } };
struct SpawnedElem {
    unsigned char m_type;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned int unk04;
    float m_fl08;
    unsigned int unk0C;
    __m128 m_vec10;
    __m128 unk20;
    __m128 unk30;
    ZeroVec m_v40;
    ZeroVec m_v50;
    __m128 unk60;
    __m128 unk70;
};

struct BeginArg { SpawnedElem* p; BeginArg(SpawnedElem* q):p(q){} };
// @fnv 0x00d89ed0
void __cdecl FUN_00d89ed0(SpawnedOwner* owner, BeginArg begin, SpawnedElem* limit)
{
    SpawnedVec4 scale = owner->m_vec10;
    SpawnedElem* p = begin.p;
    uintptr_t end = reinterpret_cast<uintptr_t>(limit);
    if (end == 0) end = UINTPTR_MAX;
    if (reinterpret_cast<uintptr_t>(p) >= end) return;
    for (;;) {
        switch (p->m_type) {
        case 1:
        case 2:
            p->m_v40.clear();
            p->m_v50.clear();
            ++p;
            break;
        case 0:
        {
            do {
                __m128 f = _mm_load_ss(&p->m_fl08);
                p->m_v40.clear();
                p->m_v50.clear();
                _ReadWriteBarrier();
                __m128 b = _mm_shuffle_ps(f, f, 0);
                p->m_vec10 = _mm_add_ps(_mm_mul_ps(b, *(const __m128*)&scale), p->m_vec10);
                ++p;
            } while (p->m_type == 0 && reinterpret_cast<uintptr_t>(p) < end);
            break;
        }
        case 3:
            return;
        default:
            __debugbreak();
            break;
        }
        if (reinterpret_cast<uintptr_t>(p) >= end) return;
    }
}

struct __declspec(align(16)) Step_PlainQuad {
 float x,y,z,w;
 __forceinline operator __m128() const { return *(const __m128*)this; }
 __forceinline void operator=(const __m128& v) { *(__m128*)this = v; }
 __forceinline void operator=(const Step_PlainQuad& v) { *(__m128*)this = *(const __m128*)&v; }
};
class Step_SimdReal {
public:
    __forceinline Step_SimdReal(const __m128& x) { m_vValue=x; }
    __forceinline Step_SimdReal(float x) { m_vValue = _mm_load_ss(&x); }
    __forceinline Step_SimdReal() {}
    __forceinline operator float() const { float s; _mm_store_ss(&s, m_vValue); return s; }
    __forceinline __m128 broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
    __forceinline const __m128& getQuad() const { return *(const __m128*)&m_vValue; }
private:
    Step_PlainQuad m_vValue;
};
typedef const Step_SimdReal& Step_SimdRealParameter;
class Step_Comparison {
public:
    enum Mask { MASK_XYZ = 7 };
    __forceinline int allAreSet(Mask m) const { return (_mm_movemask_ps(m_uiMask) & m) == m; }
    __forceinline int GetLaneMask() const { return _mm_movemask_ps(m_uiMask); }
    Step_PlainQuad m_uiMask;
};
class Step_Vector4 {
public:
    __forceinline void operator=(const Step_Vector4& v) { m_vComponents = v.m_vComponents; }
    __forceinline void setAll3(float a) { m_vComponents = _mm_set_ps1(a); }
    __forceinline void setZero4() { m_vComponents = _mm_setzero_ps(); }
    __forceinline void add4(const Step_Vector4& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setSub4(const Step_Vector4& v0, const Step_Vector4& v1) { m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents); }
    __forceinline void mul4(const Step_Vector4& v) { m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents); }
    __forceinline void mul4(Step_SimdRealParameter s) { m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents); }
    __forceinline void setMul4(Step_SimdRealParameter r, const Step_Vector4& v1) { m_vComponents = _mm_mul_ps(r.broadcast(), v1.m_vComponents); }
    __forceinline void addMul4(Step_SimdRealParameter r, const Step_Vector4& v1) { m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents)); }
    __forceinline void setAbs4(const Step_Vector4& v) { m_vComponents = _mm_and_ps(v.m_vComponents, ::DAT_01017d10); }
    __forceinline Step_Comparison compareLessThan4(const Step_Vector4& a) const { Step_Comparison m; m.m_uiMask = _mm_cmplt_ps(m_vComponents, a.m_vComponents); return m; }
    __forceinline Step_Comparison compareEqual4(const Step_Vector4& a) const { Step_Comparison m; m.m_uiMask = _mm_cmpeq_ps(m_vComponents, a.m_vComponents); return m; }
    __forceinline Step_Comparison compareLessThanEqual4(const Step_Vector4& a) const { Step_Comparison m; m.m_uiMask = _mm_cmple_ps(m_vComponents, a.m_vComponents); return m; }
    __forceinline Step_SimdReal getSimdAt(int i) const { switch (i) { case 0: return static_cast<__m128>(m_vComponents); case 1: return _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55); case 2: return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa); default: return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff); } }
    __forceinline void subMul4(Step_SimdRealParameter r, const Step_Vector4& v1) { m_vComponents = _mm_sub_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents)); }
    __forceinline Step_SimdReal dot3(const Step_Vector4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline Step_SimdReal lengthInverse3() const
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 len2 = this->dot3(*this).getQuad();
        const __m128 len2EqualsZero = _mm_cmpeq_ss(len2, zero);
        const __m128 approx = _mm_rsqrt_ss(len2);
        const __m128 refined = _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
        return _mm_andnot_ps(len2EqualsZero, refined);
    }
    __forceinline Step_SimdReal normalizeWithLength3()
    {
        __m128 len2 = this->dot3(*this).getQuad();
        __m128 lenInv = lengthInverse3().broadcast();
        m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
        return _mm_mul_ss(len2, lenInv);
    }
    __forceinline float& operator()(int i) { return ((float*)&m_vComponents)[i]; }
    __forceinline const float& operator()(int i) const { return ((const float*)&m_vComponents)[i]; }
    __forceinline static const Step_Vector4& getZero();
    Step_PlainQuad m_vComponents;
};
__forceinline const Step_Vector4& Step_Vector4::getZero() { return (*reinterpret_cast<::Step_Vector4 *>(&::DAT_01267e30)); }
class Step_Matrix3 {
public:
    Step_Vector4 m_kColumn0, m_kColumn1, m_kColumn2;
    __forceinline Step_Vector4& getColumn(int x) { return (&m_kColumn0)[x]; }
    __forceinline const Step_Vector4& getColumn(int x) const { return (&m_kColumn0)[x]; }
};
class Step_Rotation : public Step_Matrix3 {
};
class Step_Transform {
public:
    Step_Rotation m_rotation;
    Step_Vector4 m_vTranslation;
    __forceinline const Step_Vector4& getColumn(int x) const { return m_rotation.getColumn(x); }
    __forceinline static const Step_Transform& GetIdentityTransform();
};
__forceinline const Step_Transform& Step_Transform::GetIdentityTransform() { return (*reinterpret_cast<::Step_Transform *>(&::DAT_01268370)); }
class Step_Bool {
public:
    __forceinline Step_Bool() {}
    __forceinline Step_Bool(bool b) { m_cBooleanValue = static_cast<char>(b); }
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
    __forceinline Step_Bool& operator=(bool e) { m_cBooleanValue = static_cast<char>(e); return *this; }
private:
    char m_cBooleanValue;
};
class Step_Accumulator {
public:
    enum Type { HK_RIGID_BODY, HK_KEYFRAMED_RIGID_BODY, HK_NO_GRAVITY_RIGID_BODY, HK_END };
    class TypeEnum {
    public:
        __forceinline operator Type() const { return static_cast<Type>(m_kStorage); }
        __forceinline Step_Bool operator==(Type e) const { return m_kStorage == static_cast<unsigned char>(e); }
    private:
        unsigned char m_kStorage;
    };
    TypeEnum m_type;
    unsigned int m_uiDeactivationClass;
    float m_fGravityFactor;
    int unk0c;
    Step_Vector4 m_vLinearVelocity;
    Step_Vector4 m_vAngularVelocity;
    Step_Vector4 m_vInverseInertiaAndMass;
    Step_Vector4 m_vCenterOfMass;
    Step_Rotation m_kCoreFromWorldMatrix;
    __forceinline Step_Vector4& getScratch0() { return m_vCenterOfMass; }
    __forceinline Step_Vector4& getScratch1() { return m_kCoreFromWorldMatrix.getColumn(0); }
    __forceinline Step_Vector4& getSumLinearVel() { return getScratch0(); }
    __forceinline Step_Vector4& getSumAngularVel() { return getScratch1(); }
};
struct Step_SolverInfo {
    struct FloatAndHalfRecord {
        float m_fFirstFloat;
        float m_fSecondFloat;
        float m_fThirdValue;
        float m_fFourthFloat;
        float m_maxDistSqrd0;
        float m_maxDistSqrd1;
        short m_maxRotSqrd0;
        short m_maxRotSqrd1;
    };
    float m_iCachedVertexCount;
    float m_fTau;
    float m_fMotorDamping;
    float m_fPostDampingParameter;
    Step_Vector4 m_kGravity;
    Step_Vector4 m_kSecondSolverVector;
    Step_Vector4 m_kTimeStep;
    Step_Vector4 GetTimeStepFactor;
    float m_fFirstTrailingParameter;
    float m_fSecondTrailingParameter;
    float m_fThirdTrailingParameter;
    float m_fFourthTrailingParameter;
    float m_fContactRestingVelocity;
    FloatAndHalfRecord m_kDeactivationClassInfo[6];
    float m_fTimeStep;
    float m_fInverseDeltaTime;
    int m_iToiEventCount;
    int m_iMicroStepCount;
    float m_fInverseMicroStepCount;
    float m_fInverseStepCount;
};
__forceinline float Step_min2(float x, float y) { return x < y ? x : y; }
__forceinline Step_Comparison eqRaw(__m128 x) { Step_Comparison r; r.m_uiMask=_mm_cmpeq_ps(x,x); return r; }
__forceinline Step_Comparison ltRaw(__m128 x,__m128 lim) { Step_Comparison r; r.m_uiMask=_mm_cmplt_ps(x,lim); return r; }

template<bool top> static __forceinline void Step_integrateVelocityAccumulator(const Step_SolverInfo& info, Step_Accumulator* accu)
{
    const Step_SolverInfo::FloatAndHalfRecord& di = info.m_kDeactivationClassInfo[accu->m_uiDeactivationClass];
    Step_Vector4 absLinVel; absLinVel.setAbs4(accu->m_vLinearVelocity);
    Step_Vector4 absAngVel; absAngVel.setAbs4(accu->m_vAngularVelocity);
    Step_Vector4 sum;
    sum.setMul4(di.m_fFirstFloat, absLinVel);
    sum.addMul4(di.m_fSecondFloat, absAngVel);
    Step_Vector4 one; one.setAll3(info.m_iCachedVertexCount);
    const Step_Vector4& maxVel = *(const Step_Vector4*)&(*reinterpret_cast<const unsigned int (*)[4]>((void *)&::DAT_010d3da0));
    int mask;
    if(top) {
    __m128 angCopy=accu->m_vAngularVelocity.m_vComponents;
mask=(int)((unsigned char)(eqRaw(angCopy).GetLaneMask()) & (unsigned char)(ltRaw(absAngVel.m_vComponents,maxVel.m_vComponents).GetLaneMask()) & (unsigned char)(accu->m_vLinearVelocity.compareEqual4(accu->m_vLinearVelocity).GetLaneMask()) & (short)(ltRaw(absLinVel.m_vComponents,maxVel.m_vComponents).GetLaneMask()));
    } else {
    mask = absLinVel.compareLessThan4(maxVel).GetLaneMask() & absAngVel.compareLessThan4(maxVel).GetLaneMask();
    mask &= accu->m_vLinearVelocity.compareEqual4(accu->m_vLinearVelocity).GetLaneMask() & accu->m_vAngularVelocity.compareEqual4(accu->m_vAngularVelocity).GetLaneMask();
    }
    if ((mask & 7) != 7)
    {
        accu->m_vLinearVelocity = Step_Transform::GetIdentityTransform().getColumn(0);
        accu->m_vAngularVelocity = Step_Transform::GetIdentityTransform().getColumn(0);
    }
    if (sum.compareLessThanEqual4(one).allAreSet(Step_Comparison::MASK_XYZ))
    {
        Step_Vector4 threshold; threshold.setAll3(di.m_fFourthFloat);
        if (sum.compareLessThanEqual4(threshold).allAreSet(Step_Comparison::MASK_XYZ))
        {
            accu->m_vAngularVelocity.setZero4();
            accu->m_vLinearVelocity.setZero4();
            return;
        }
        else if (1)
        {
            accu->m_vAngularVelocity.mul4(di.m_fThirdValue);
            accu->m_vLinearVelocity.mul4(di.m_fThirdValue);
        }
        else
        {
            Step_Vector4 linNorm = accu->m_vLinearVelocity;
            float linLen = linNorm.normalizeWithLength3();
            if (linLen > 1.1920929e-07)
            {
                linLen = Step_min2(0.001f, linLen);
                accu->m_vLinearVelocity.subMul4(linLen, linNorm);
            }
            else
            {
                accu->m_vLinearVelocity.setZero4();
            }
            Step_Vector4 angNorm = accu->m_vAngularVelocity;
            float angLen = angNorm.normalizeWithLength3();
            if (angLen > 1.1920929e-07)
            {
                angLen = Step_min2(0.01f, angLen);
                accu->m_vAngularVelocity.subMul4(angLen, angNorm);
            }
            else
            {
                accu->m_vAngularVelocity.setZero4();
            }
        }
    }
}
static __forceinline void Step_updateSumVelocities(const Step_SolverInfo& info, const Step_Vector4& gravityPerStep, bool lastStep, const Step_Vector4& damping, Step_Accumulator* accu)
{
    Step_SimdReal gravityFactor = accu->m_fGravityFactor;
    Step_Vector4 gravityVel; gravityVel.setMul4(gravityFactor, gravityPerStep);
    Step_Vector4 linVel; linVel.setSub4(accu->m_vLinearVelocity, accu->getSumLinearVel());
    Step_Vector4 angVel; angVel.setSub4(accu->m_vAngularVelocity, accu->getSumAngularVel());
    accu->getSumLinearVel().addMul4(info.m_kTimeStep.getSimdAt(0), linVel);
    accu->getSumAngularVel().addMul4(info.m_kTimeStep.getSimdAt(0), angVel);
    if (!lastStep)
    {
        linVel.add4(accu->getSumLinearVel());
        angVel.add4(accu->getSumAngularVel());
        linVel.add4(gravityVel);
    }
    else
    {
        accu->getSumLinearVel().mul4(damping);
        accu->getSumAngularVel().mul4(damping);
    }
    accu->m_vLinearVelocity = linVel;
    accu->m_vAngularVelocity = angVel;
}
static __forceinline void Step_integrateVelocities(const Step_SolverInfo& info, const Step_Vector4& gravityPerStep, bool lastStep, const Step_Vector4& damping, Step_Accumulator* accu, Step_Accumulator* accuEnd)
{
    if (!accuEnd)
    {
        accuEnd = (Step_Accumulator*)-1;
    }
    while (accu < accuEnd)
    {
        switch (accu->m_type)
        {
        case Step_Accumulator::HK_NO_GRAVITY_RIGID_BODY:
            Step_integrateVelocityAccumulator<true>(info, accu);
        case Step_Accumulator::HK_KEYFRAMED_RIGID_BODY:
            Step_updateSumVelocities(info, Step_Vector4::getZero(), lastStep, damping, accu);
            accu++;
            break;
        case Step_Accumulator::HK_RIGID_BODY:
            do
            {
                Step_integrateVelocityAccumulator<false>(info, accu);
                Step_updateSumVelocities(info, gravityPerStep, lastStep, damping, accu);
                accu++;
            } while (accu->m_type == Step_Accumulator::HK_RIGID_BODY && accu < accuEnd);
            break;
        case Step_Accumulator::HK_END:
            return;
        }
    }
}
static void Step_debugPrintfAccumulators(int mode, const Step_SolverInfo& info, Step_Accumulator* accumulators, Step_Accumulator* accumulatorsEnd)
{
}
struct Step_InArg { Step_Accumulator* value; Step_InArg() {} };
struct Step_OutArg { Step_Bool* value; Step_OutArg() {} };
// @fnv 0x00d89f80
extern "C" __declspec(noinline) int __cdecl FUN_00d89f80(
    const Step_SolverInfo& info,
    int currentSolverStep,
    Step_InArg inputArg,
    Step_Accumulator* end,
    Step_OutArg outputArg)
{
 Step_Vector4 gravityPerStep=info.m_kGravity;
 Step_Vector4 damping; damping.setAll3(info.m_fInverseStepCount*info.GetTimeStepFactor(0));
 bool lastStep=false;
 {
  Step_Bool& out=*outputArg.value;
  out=false;
  int n=info.m_iToiEventCount-1;
  if(currentSolverStep>=n) { lastStep=true; out=true; }
 }
 Step_Accumulator* p=inputArg.value;
 Step_integrateVelocities(info,gravityPerStep,lastStep,damping,p,end);
 return 1;
}
#include "generated/data/havok/physics/constraintsolver/solve/hkpsolver.inc"
