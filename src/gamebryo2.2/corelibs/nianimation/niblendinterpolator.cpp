// gamebryo2.2/corelibs/nianimation/niblendinterpolator.cpp: NiBlendInterpolator, InterpItem, LoadInterpItem, BlendSerializer and more (19 functions)

#include <cstdint>
#include <new>
#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00a5d430_Class.h"
#include "fnv/decl/FUN_00ba87d0_Class.h"
#include "fnv/decl/NiKeyBasedInterpolator.h"
#include "fnv/decl/Registry.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00a57000.h"
#include "fnv/symbols_00a72000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_01095000.h"
#include "fnv/symbols_01096000.h"
#include "fnv/symbols_011a8000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f6000.h"
#include "niblendinterpolator_types_NiBlendInterpolator.h"
#include "niblendinterpolator_types_NiBlendInterpolator__InterpArrayItem.h"
#include "niblendinterpolator_types_NiCloningProcess.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00a88000.h"

// @fnv 0x00a371f0
NiBlendInterpolator__InterpArrayItem& NiBlendInterpolator__InterpArrayItem::operator=(
    const NiBlendInterpolator__InterpArrayItem& source)
{
    NiInterpolator* previous = m_spControllerInterpolator.m_pObject;
    if (previous != source.m_spControllerInterpolator.m_pObject)
    {
        if (previous && InterlockedDecrement(reinterpret_cast<volatile long*>(&previous->m_uiRefCount)) == 0)
            previous->DeleteThis();
        m_spControllerInterpolator.m_pObject = source.m_spControllerInterpolator.m_pObject;
        if (m_spControllerInterpolator.m_pObject)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&m_spControllerInterpolator.m_pObject->m_uiRefCount));
    }
    m_fWeight = source.m_fWeight;
    m_fNormalizedWeight = source.m_fNormalizedWeight;
    m_cPriority = source.m_cPriority;
    m_fEaseSpinner = source.m_fEaseSpinner;
    m_fLastEvaluationTime = source.m_fLastEvaluationTime;
    return *this;
}

// Finds the first two active interpolator items and normalizes their weights by priority, ease spinner, threshold and flags.
// @fnv 0x00a36bd0
void NiBlendInterpolator::UpdatePriorityData()
{
    NiBlendInterpolator__InterpArrayItem* pFirstItem = 0;
    NiBlendInterpolator__InterpArrayItem* pSecondItem = 0;
    for (unsigned char index = 0; index < m_ucArraySize; ++index)
    {
        if (m_pInterpArray[index].m_spControllerInterpolator.m_pObject)
        {
            if (!pFirstItem)
                pFirstItem = &m_pInterpArray[index];
            else
            {
                pSecondItem = &m_pInterpArray[index];
                break;
            }
        }
    }

    float firstWeight = pFirstItem->m_fWeight * pFirstItem->m_fEaseSpinner;
    float secondWeight = pSecondItem->m_fWeight * pSecondItem->m_fEaseSpinner;
    if (firstWeight == 0.0f && secondWeight == 0.0f)
    {
        pFirstItem->m_fNormalizedWeight = 0.0f;
        pSecondItem->m_fNormalizedWeight = 0.0f;
        return;
    }
    if (pFirstItem->m_cPriority > pSecondItem->m_cPriority)
    {
        if (pFirstItem->m_fEaseSpinner == 1.0f)
        {
            pFirstItem->m_fNormalizedWeight = 1.0f;
            pSecondItem->m_fNormalizedWeight = 0.0f;
            return;
        }
        float remainingEase = 1.0f - pFirstItem->m_fEaseSpinner;
        float inverseWeight = 1.0f / (pFirstItem->m_fEaseSpinner * firstWeight + remainingEase * secondWeight);
        pFirstItem->m_fNormalizedWeight = pFirstItem->m_fEaseSpinner * firstWeight * inverseWeight;
        pSecondItem->m_fNormalizedWeight = remainingEase * secondWeight * inverseWeight;
    }
    else if (pFirstItem->m_cPriority < pSecondItem->m_cPriority)
    {
        if (pSecondItem->m_fEaseSpinner == 1.0f)
        {
            pFirstItem->m_fNormalizedWeight = 0.0f;
            pSecondItem->m_fNormalizedWeight = 1.0f;
            return;
        }
        float remainingEase = 1.0f - pSecondItem->m_fEaseSpinner;
        float inverseWeight = 1.0f / (remainingEase * firstWeight + pSecondItem->m_fEaseSpinner * secondWeight);
        pFirstItem->m_fNormalizedWeight = remainingEase * firstWeight * inverseWeight;
        pSecondItem->m_fNormalizedWeight = pSecondItem->m_fEaseSpinner * secondWeight * inverseWeight;
    }
    else
    {
        float inverseWeight = 1.0f / (firstWeight + secondWeight);
        pFirstItem->m_fNormalizedWeight = firstWeight * inverseWeight;
        pSecondItem->m_fNormalizedWeight = secondWeight * inverseWeight;
    }

    if (m_uiObjectFlags & 2)
    {
        if (pFirstItem->m_fNormalizedWeight >= pSecondItem->m_fNormalizedWeight)
        {
            pFirstItem->m_fNormalizedWeight = 1.0f;
            pSecondItem->m_fNormalizedWeight = 0.0f;
        }
        else
        {
            pFirstItem->m_fNormalizedWeight = 0.0f;
            pSecondItem->m_fNormalizedWeight = 1.0f;
        }
    }
    else if (m_fWeightThreshold > 0.0f)
    {
        bool anyWeightRemoved = false;
        if (pFirstItem->m_fNormalizedWeight < m_fWeightThreshold)
        {
            pFirstItem->m_fNormalizedWeight = 0.0f;
            anyWeightRemoved = true;
        }
        if (pSecondItem->m_fNormalizedWeight < m_fWeightThreshold)
        {
            pSecondItem->m_fNormalizedWeight = 0.0f;
            anyWeightRemoved = true;
        }
        if (anyWeightRemoved)
            pSecondItem->m_fNormalizedWeight = 1.0f;
    }
}

// @fnv 0x00a36970
unsigned char NiBlendInterpolator::AddInterpolatorItem(NiInterpolator* interpolator, float weight, char priority,
                                                       float easeSpinner)
{
    unsigned char index = 0;
    for (; index < m_ucArraySize; ++index)
        if (!m_pInterpArray[index].m_spControllerInterpolator.m_pObject)
            break;
    if (index == m_ucArraySize && !GrowInterpolatorArray())
        return 0xff;

    NiBlendInterpolator__InterpArrayItem& item = m_pInterpArray[index];
    NiInterpolator* previous = item.m_spControllerInterpolator.m_pObject;
    if (previous != interpolator)
    {
        if (previous && InterlockedDecrement(reinterpret_cast<volatile long*>(&previous->m_uiRefCount)) == 0)
            previous->DeleteThis();
        item.m_spControllerInterpolator.m_pObject = interpolator;
        if (interpolator)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&interpolator->m_uiRefCount));
    }
    item.m_fWeight = weight;
    item.m_cPriority = priority;
    item.m_fNormalizedWeight = 0.0f;
    item.m_fEaseSpinner = easeSpinner;
    item.m_fLastEvaluationTime = ::DAT_0109696c;

    if (priority > m_cNextHighPriority)
    {
        if (priority > m_cHighPriority)
        {
            m_cNextHighPriority = m_cHighPriority;
            m_cHighPriority = priority;
        }
        else if (priority != m_cHighPriority)
            m_cNextHighPriority = priority;
    }
    ++m_ucInterpCount;
    if (m_ucInterpCount == 1)
    {
        m_ucSingleIdx = index;
        m_pSingleInterpolator = interpolator;
    }
    else
    {
        m_fSingleInterpolatorTime = ::DAT_0109696c;
        m_ucSingleIdx = 0xff;
        m_pSingleInterpolator = 0;
    }
    m_fHighSumOfWeights = ::DAT_0109696c;
    m_uiObjectFlags |= 4;
    m_fNextHighSumOfWeights = ::DAT_0109696c;
    m_fTrailingValue = ::DAT_0109696c;
    return index;
}

// Removes the interpolator at index, releases it, recomputes high/next-high priorities and single-interpolator state, and invalidates cached weights.
// @fnv 0x00a36a90
void NiBlendInterpolator::RemoveInterpolatorAt(unsigned char index)
{
    NiBlendInterpolator__InterpArrayItem& item = m_pInterpArray[index];
    char priority = item.m_cPriority;
    NiInterpolator* previous = item.m_spControllerInterpolator.m_pObject;
    if (previous)
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&previous->m_uiRefCount)) == 0)
            previous->DeleteThis();
        item.m_spControllerInterpolator.m_pObject = 0;
    }
    if (priority == m_cHighPriority || priority == m_cNextHighPriority)
    {
        m_cNextHighPriority = -128;
        m_cHighPriority = -128;
        for (unsigned char current = 0; current < m_ucArraySize; ++current)
        {
            NiBlendInterpolator__InterpArrayItem& candidate = m_pInterpArray[current];
            if (candidate.m_spControllerInterpolator.m_pObject && candidate.m_cPriority > m_cNextHighPriority)
            {
                if (candidate.m_cPriority > m_cHighPriority)
                {
                    m_cNextHighPriority = m_cHighPriority;
                    m_cHighPriority = candidate.m_cPriority;
                }
                else if (candidate.m_cPriority < m_cHighPriority)
                    m_cNextHighPriority = candidate.m_cPriority;
            }
        }
    }
    --m_ucInterpCount;
    if (m_ucInterpCount == 1)
    {
        if (m_ucArraySize == 2)
            m_ucSingleIdx = !index;
        else
        {
            for (unsigned char current = 0; current < m_ucArraySize; ++current)
                if (m_pInterpArray[current].m_spControllerInterpolator.m_pObject)
                {
                    m_ucSingleIdx = current;
                    break;
                }
        }
        NiBlendInterpolator__InterpArrayItem& single = m_pInterpArray[m_ucSingleIdx];
        m_pSingleInterpolator = single.m_spControllerInterpolator.m_pObject;
        m_fSingleInterpolatorTime = single.m_fLastEvaluationTime;
    }
    else if (m_ucInterpCount == 0)
    {
        m_fSingleInterpolatorTime = ::DAT_0109696c;
        m_cNextHighPriority = -128;
        m_cHighPriority = -128;
        m_ucSingleIdx = 0xff;
        m_pSingleInterpolator = 0;
    }
    m_fHighSumOfWeights = ::DAT_0109696c;
    m_uiObjectFlags |= 4;
    m_fNextHighSumOfWeights = ::DAT_0109696c;
    m_fTrailingValue = ::DAT_0109696c;
}

// @fnv 0x00a36e80
void NiBlendInterpolator::ProcessClone(CloningProcess& aCloneProcess)
{
    reinterpret_cast<::FUN_00a5d430_Class *>(this)->FUN_00a5d430((uintptr_t)&(aCloneProcess));
    NiObject* cloneObject = 0;
    reinterpret_cast<::A54440Hash *>((void *)(aCloneProcess.m_pCloneMap))->FUN_00a53c30(reinterpret_cast<::A54440Manager *>((this)), (::A54440Manager **)&(cloneObject));
    NiBlendInterpolator* clone = static_cast<NiBlendInterpolator*>(cloneObject);
    for (unsigned char index = 0; index < m_ucArraySize; ++index)
    {
        NiInterpolator* interpolator = m_pInterpArray[index].m_spControllerInterpolator.m_pObject;
        if (interpolator)
            interpolator->ProcessClone(aCloneProcess);
    }
    if (m_pSingleInterpolator)
    {
        NiInterpolator* singleClone;
        if (reinterpret_cast<::A54440Hash *>((void *)(aCloneProcess.m_pCloneMap))->FUN_00a53c30((*(::A54440Manager * *)&(m_pSingleInterpolator)), (::A54440Manager **)&(cloneObject)))
            singleClone = static_cast<NiInterpolator*>(cloneObject);
        else
            singleClone = m_pSingleInterpolator;
        clone->m_pSingleInterpolator = singleClone;
    }
}

extern int DAT_0109697c;

class MemoryManager
{
  public:
};


struct InterpArrayItem_Temp
{
    NiPointer<NiObject> m_spControllerInterpolator;
    float f1;
    float f2;
    char c1;
    float f3;
    float f4;
};

// Sets the vtable pointer, destroys each element of the array at offset 0x14, frees it, then calls FUN_00a57010.
// @fnv 0x00a37170
void DestroyInterpolatorArray(NiBlendInterpolator* pThis, int)
{
    *reinterpret_cast<int**>(pThis) = &DAT_0109697c;
    InterpArrayItem_Temp* pArray = *reinterpret_cast<InterpArrayItem_Temp**>(&pThis->m_pInterpArray);
    if (pArray)
    {
        int* pAlloc = reinterpret_cast<int*>(pArray) - 1;
        int count = *pAlloc;
        InterpArrayItem_Temp* pCur = pArray + count;
        while (--count >= 0)
        {
            --pCur;
            pCur->~InterpArrayItem_Temp();
        }
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(pAlloc);
    }
    reinterpret_cast<::NiKeyBasedInterpolator *>((pThis))->FUN_00a57010();
}

struct FUN_00a37260_shell : public NiBlendInterpolator
{
    void UpdateNormalizedWeights();
};


struct InterpArrayItem_Layout
{
    void* m_spControllerInterpolator;  // +0x0
    float m_fWeight;                   // +0x4
    float m_fNormalizedWeight;         // +0x8
    char m_cPriority;                  // +0xC
    char padD[3];
    float m_fEaseSpinner;         // +0x10
    float m_fLastEvaluationTime;  // +0x14
};

struct NiBlendInterpolator_Layout
{
    char pad0[0xC];
    unsigned char m_uiObjectFlags;         // +0xC
    unsigned char m_ucArraySize;    // +0xD
    unsigned char m_ucInterpCount;  // +0xE
    unsigned char m_ucSingleIdx;    // +0xF
    char m_cHighPriority;           // +0x10
    char m_cNextHighPriority;       // +0x11
    char pad12[2];
    InterpArrayItem_Layout* m_pInterpArray;  // +0x14
    NiInterpolator* m_pSingleInterpolator;   // +0x18
    float m_fWeightThreshold;                // +0x1C
    float m_fSingleInterpolatorTime;         // +0x20
    float m_fHighSumOfWeights;               // +0x24
    float m_fNextHighSumOfWeights;           // +0x28
    float m_fTrailingValue;                  // +0x2C
};

// Recomputes per-item normalized blend weights from weights, ease spinners and priorities, applying the weight threshold and optional single-winner selection.
// @fnv 0x00a37260
void FUN_00a37260_shell::UpdateNormalizedWeights()
{
    NiBlendInterpolator_Layout* pThis = reinterpret_cast<NiBlendInterpolator_Layout*>(this);

    if ((pThis->m_uiObjectFlags & 4) == 0)
    {
        return;
    }

    pThis->m_uiObjectFlags &= ~4;

    if (pThis->m_ucInterpCount == 1)
    {
        pThis->m_pInterpArray[pThis->m_ucSingleIdx].m_fNormalizedWeight = 1.0f;
        return;
    }
    else if (pThis->m_ucInterpCount == 2)
    {
        UpdatePriorityData();
        return;
    }

    unsigned char uc;

    if (pThis->m_fHighSumOfWeights == ::DAT_010241b0)
    {
        pThis->m_fHighSumOfWeights = 0.0f;
        pThis->m_fNextHighSumOfWeights = 0.0f;
        pThis->m_fTrailingValue = 0.0f;
        for (uc = 0; uc < pThis->m_ucArraySize; uc++)
        {
            InterpArrayItem_Layout& kItem = pThis->m_pInterpArray[uc];
            if (kItem.m_spControllerInterpolator != 0)
            {
                float fRealWeight = kItem.m_fWeight * kItem.m_fEaseSpinner;
                if (kItem.m_cPriority == pThis->m_cHighPriority)
                {
                    pThis->m_fHighSumOfWeights += fRealWeight;
                    if (kItem.m_fEaseSpinner > pThis->m_fTrailingValue)
                    {
                        pThis->m_fTrailingValue = kItem.m_fEaseSpinner;
                    }
                }
                else if (kItem.m_cPriority == pThis->m_cNextHighPriority)
                {
                    pThis->m_fNextHighSumOfWeights += fRealWeight;
                }
            }
        }
    }

    float fOneMinusHighEaseSpinner = 1.0f - pThis->m_fTrailingValue;
    float fTotalSumOfWeights = pThis->m_fTrailingValue * pThis->m_fHighSumOfWeights +
                               fOneMinusHighEaseSpinner * pThis->m_fNextHighSumOfWeights;
    float fOneOverTotalSumOfWeights = (fTotalSumOfWeights > 0.0f) ? (1.0f / fTotalSumOfWeights) : 0.0f;

    for (uc = 0; uc < pThis->m_ucArraySize; uc++)
    {
        InterpArrayItem_Layout& kItem = pThis->m_pInterpArray[uc];
        if (kItem.m_spControllerInterpolator != 0)
        {
            if (kItem.m_cPriority == pThis->m_cHighPriority)
            {
                kItem.m_fNormalizedWeight =
                    pThis->m_fTrailingValue * kItem.m_fWeight * kItem.m_fEaseSpinner * fOneOverTotalSumOfWeights;
            }
            else if (kItem.m_cPriority == pThis->m_cNextHighPriority)
            {
                kItem.m_fNormalizedWeight =
                    fOneMinusHighEaseSpinner * kItem.m_fWeight * kItem.m_fEaseSpinner * fOneOverTotalSumOfWeights;
            }
            else
            {
                kItem.m_fNormalizedWeight = 0.0f;
            }
        }
    }

    if (pThis->m_fWeightThreshold > 0.0f)
    {
        float fSumOfNormalizedWeights = 0.0f;
        for (uc = 0; uc < pThis->m_ucArraySize; uc++)
        {
            InterpArrayItem_Layout& kItem = pThis->m_pInterpArray[uc];
            if (kItem.m_spControllerInterpolator != 0 && kItem.m_fNormalizedWeight != 0.0f)
            {
                if (kItem.m_fNormalizedWeight < pThis->m_fWeightThreshold)
                {
                    kItem.m_fNormalizedWeight = 0.0f;
                }
                fSumOfNormalizedWeights += kItem.m_fNormalizedWeight;
            }
        }

        if (fSumOfNormalizedWeights != 1.0f)
        {
            float fOneOverSumOfNormalizedWeights =
                (fSumOfNormalizedWeights > 0.0f) ? (1.0f / fSumOfNormalizedWeights) : 0.0f;

            for (uc = 0; uc < pThis->m_ucArraySize; uc++)
            {
                InterpArrayItem_Layout& kItem = pThis->m_pInterpArray[uc];
                if (kItem.m_fNormalizedWeight != 0.0f)
                {
                    kItem.m_fNormalizedWeight = kItem.m_fNormalizedWeight * fOneOverSumOfNormalizedWeights;
                }
            }
        }
    }

    if ((pThis->m_uiObjectFlags & 2) != 0)
    {
        unsigned char ucHighIndex = 0xFF;
        float fHighest = -1.0f;
        for (uc = 0; uc < pThis->m_ucArraySize; uc++)
        {
            if (pThis->m_pInterpArray[uc].m_fNormalizedWeight > fHighest)
            {
                ucHighIndex = uc;
                fHighest = pThis->m_pInterpArray[uc].m_fNormalizedWeight;
            }
            pThis->m_pInterpArray[uc].m_fNormalizedWeight = 0.0f;
        }

        pThis->m_pInterpArray[ucHighIndex].m_fNormalizedWeight = 1.0f;
    }
}

// @fnv 0x00a36960
const char* const* __cdecl FUN_00a36960()
{
    return &(*reinterpret_cast<const char *const *>(&::g_011f36fc));
}

struct StreamS;
struct InterpS
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual bool RegisterStreamables(StreamS& s);
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void Collapse2();
};
struct ItemS
{
    InterpS* m_spControllerInterpolator;
    int a[5];
};
struct BlendInterpS : InterpS
{
    unsigned char pad4[8];
    unsigned char m_uiObjectFlags;
    unsigned char m_ucArraySize;
    unsigned char m_ucInterpCount;
    unsigned char pad0f[5];
    ItemS* m_pInterpArray;
    InterpS* m_pSingleInterpolator;
};
// @fnv 0x00a36dc0
void CollapseAllInterps(BlendInterpS* self, int)
{
    if (self->m_ucInterpCount == 1)
    {
        self->m_pSingleInterpolator->Collapse2();
        return;
    }
    for (unsigned char uc = 0; uc < self->m_ucArraySize; uc++)
    {
        ItemS* kItem = &self->m_pInterpArray[uc];
        if (kItem->m_spControllerInterpolator)
            kItem->m_spControllerInterpolator->Collapse2();
    }
}

namespace fnv_00a36e10 {
struct InterpS
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual bool IsEqual(InterpS* o);
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void SetActiveTimeRange(float a, float b);
};
struct ItemS
{
    InterpS* m_spControllerInterpolator;
    float f4;
    float f8;
    unsigned char c;
    float f10;
    int tail;
    bool IsEqual(ItemS& kDest);
};
struct BlendInterpS : InterpS
{
    unsigned char pad4[8];
    unsigned char m_uiObjectFlags;
    unsigned char m_ucArraySize;
    unsigned char m_ucInterpCount;
    unsigned char pad0f[5];
    ItemS* m_pInterpArray;
    InterpS* m_pSingleInterpolator;
};
// @fnv 0x00a36e10
void FUN_00a36e10(BlendInterpS* self, int, float m_fStartTime, float m_fMaximumDistance)
{
    if (self->m_ucInterpCount == 1)
    {
        self->m_pSingleInterpolator->SetActiveTimeRange(m_fStartTime, m_fMaximumDistance);
        return;
    }
    for (unsigned char uc = 0; uc < self->m_ucArraySize; uc++)
    {
        ItemS* kItem = &self->m_pInterpArray[uc];
        if (kItem->m_spControllerInterpolator)
            kItem->m_spControllerInterpolator->SetActiveTimeRange(m_fStartTime, m_fMaximumDistance);
    }
}
}  // namespace fnv_00a36e10

namespace fnv_00a36f80 {
struct StreamS;
struct InterpS
{
    virtual void v0();
    bool FUN_00a81fe0(StreamS& s);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual bool RegisterStreamables(StreamS& s);
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void Collapse2();
};
struct ItemS
{
    InterpS* m_spControllerInterpolator;
    int a[5];
};
struct BlendInterpS : InterpS
{
    unsigned char pad4[8];
    unsigned char m_uiObjectFlags;
    unsigned char m_ucArraySize;
    unsigned char m_ucInterpCount;
    unsigned char pad0f[5];
    ItemS* m_pInterpArray;
    InterpS* m_pSingleInterpolator;
};
// Registers the base streamables, then registers each item's interpolator when the flag bit is clear; returns false if the base call fails.
// @fnv 0x00a36f80
bool FUN_00a36f80(BlendInterpS* self, int, StreamS& kStream)
{
    if (!self->FUN_00a81fe0(kStream))
        return false;
    if (!(self->m_uiObjectFlags & 1))
    {
        for (unsigned char uc = 0; uc < self->m_ucArraySize; uc++)
        {
            ItemS* kItem = &self->m_pInterpArray[uc];
            if (kItem->m_spControllerInterpolator)
                kItem->m_spControllerInterpolator->RegisterStreamables(kStream);
        }
    }
    return true;
}
}  // namespace fnv_00a36f80

namespace fnv_00a36fd0 {
struct ObjS;
struct InterpS
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual bool IsEqual(ObjS* o);
};
struct ItemS
{
    InterpS* m_spControllerInterpolator;
    float f4;
    float f8;
    unsigned char c;
    float f10;
    int tail;
    bool Equals(ItemS& o);
};
struct BlendS
{
    void* vptr;
    unsigned char pad4[8];
    unsigned char m_uiObjectFlags;
    unsigned char m_ucArraySize;
    unsigned char m_ucInterpCount;
    unsigned char m_ucSingleIdx;
    char m_cHighPriority;
    char m_cNextHighPriority;
    unsigned char pad12[2];
    ItemS* m_pInterpArray;
    InterpS* m_pSingleInterpolator;
    float m_fWeightThreshold;
    float m_fSingleInterpolatorTime;
};
// @fnv 0x00a36fd0
bool FUN_00a36fd0(BlendS* self, int, ObjS* pkObject)
{
    if (!reinterpret_cast<::FUN_00ba87d0_Class *>((self))->FUN_00ba87d0((::NiObj_s *)(pkObject)))
        return false;
    BlendS* pkDest = (BlendS*)pkObject;
    if (self->m_ucArraySize != pkDest->m_ucArraySize)
        return false;
    for (unsigned char us = 0; us < self->m_ucArraySize; us++)
    {
        if (!self->m_pInterpArray[us].Equals(pkDest->m_pInterpArray[us]))
            return false;
    }
    if (self->m_uiObjectFlags != pkDest->m_uiObjectFlags)
        return false;
    if (self->m_fWeightThreshold != pkDest->m_fWeightThreshold)
        return false;
    if (self->m_ucInterpCount != pkDest->m_ucInterpCount)
        return false;
    if (self->m_ucSingleIdx != pkDest->m_ucSingleIdx)
        return false;
    if (self->m_pSingleInterpolator && !self->m_pSingleInterpolator->IsEqual((ObjS*)pkDest->m_pSingleInterpolator))
        return false;
    if (self->m_pSingleInterpolator != pkDest->m_pSingleInterpolator)
        return false;
    if (self->m_fSingleInterpolatorTime != pkDest->m_fSingleInterpolatorTime)
        return false;
    if (self->m_cHighPriority != pkDest->m_cHighPriority || self->m_cNextHighPriority != pkDest->m_cNextHighPriority)
        return false;
    return true;
}
}  // namespace fnv_00a36fd0

struct FUN_00a370a0_obj
{
    int field0;
};
// @fnv 0x00a370a0
FUN_00a370a0_obj* FUN_00a370a0(FUN_00a370a0_obj* self, int)
{
    self->field0 = 0;
    return self;
}

class FUN_00a36f10_cls;

class EqPeer
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual bool v23(EqPeer* other);
};

class FUN_00a36f10_cls
{
  public:
    EqPeer* m_pPeer;
    float m_fCoefficientA;
    float m_fB;
    unsigned char m_ucC;
    float m_fD;
    bool Equals(FUN_00a36f10_cls* other);
};

// Compares peer pointers (both null or equal via v23) and the four value fields against another instance, returning true only if all match.
// @fnv 0x00a36f10
bool FUN_00a36f10_cls::Equals(FUN_00a36f10_cls* other)
{
    if (m_pPeer != 0 && other->m_pPeer == 0)
        return false;
    if (m_pPeer == 0 && other->m_pPeer != 0)
        return false;
    if (m_pPeer != 0 && !m_pPeer->v23(other->m_pPeer))
        return false;
    if (m_fCoefficientA != other->m_fCoefficientA)
        return false;
    if (m_fB != other->m_fB)
        return false;
    if (m_ucC != other->m_ucC)
        return false;
    if (m_fD != other->m_fD)
        return false;
    return true;
}

struct ObjectWriter;
typedef unsigned int(__cdecl* WriteItemFn)(ObjectWriter*, const void*, unsigned int, unsigned int*, unsigned int);
struct ObjectWriter
{
    void* interfacePtr;
    unsigned int totalBytes;
    void* auxPtr;
    WriteItemFn write;
};
struct StreamS
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void WriteInterpolator(void* p);
};
struct InterpItem
{
    void* interpolator;
    float weight;
    float normalizedWeight;
    char priority;
    char unk0d, unk0e, unk0f;
    float easeSpinner;
    float updateTime;
    void WriteToStream(StreamS* stream);
};
// Writes the interpolator, weight, normalizedWeight, priority and easeSpinner to the stream via its writer, accumulating byte counts.
// @fnv 0x00a378d0
void InterpItem::WriteToStream(StreamS* stream)
{
    stream->WriteInterpolator(interpolator);
    ObjectWriter* writer = *reinterpret_cast<ObjectWriter**>(reinterpret_cast<char*>(stream) + 0x250);
    {
        unsigned int bytes = 4;
        writer->totalBytes += writer->write(writer, &weight, 4, &bytes, 1);
    }
    writer = *reinterpret_cast<ObjectWriter**>(reinterpret_cast<char*>(stream) + 0x250);
    {
        unsigned int bytes = 4;
        writer->totalBytes += writer->write(writer, &normalizedWeight, 4, &bytes, 1);
    }
    writer = *reinterpret_cast<ObjectWriter**>(reinterpret_cast<char*>(stream) + 0x250);
    {
        unsigned int bytes = 1;
        writer->totalBytes += writer->write(writer, &priority, 1, &bytes, 1);
    }
    writer = *reinterpret_cast<ObjectWriter**>(reinterpret_cast<char*>(stream) + 0x250);
    {
        unsigned int bytes = 4;
        writer->totalBytes += writer->write(writer, &easeSpinner, 4, &bytes, 1);
    }
}

struct LoadBinStream;
typedef unsigned int(__cdecl* LoadBinReadFn)(LoadBinStream*, void*, unsigned int, unsigned int*, unsigned int);
struct LoadBinStream
{
    void* vtbl;
    unsigned int m_uiStreamFlags;
    LoadBinReadFn m_pfnRead;
    unsigned int BinaryRead(void* buf, unsigned int total, unsigned int* sizes, unsigned int count)
    {
        unsigned int read = m_pfnRead(this, buf, total, sizes, count);
        m_uiStreamFlags += read;
        return read;
    }
};

struct LoadStream
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    unsigned int m_uiNifVersion;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    LoadBinStream* m_pUnderlyingStream;
};

template <class T> inline void LoadStreamBinary(LoadBinStream* s, T& val)
{
    unsigned int size = sizeof(T);
    s->BinaryRead(&val, size, &size, 1);
}

struct LoadInterpItem
{
    NiInterpolator* m_spControllerInterpolator;
    float m_fWeight;
    float m_fNormalizedWeight;
    char m_cPriority;
    char unk0d, unk0e, unk0f;
    float m_fEaseSpinner;
    float m_fLastEvaluationTime;
    void LoadFromStream(LoadStream* stream);
};

struct InterpolatorRegistry;
class NiBinaryStream;
class NiTexture;
class NiObject;
class NiStream
{
  public:
    unsigned int m_header0;
    unsigned int m_header4;
    unsigned short m_pRayCursor;
    unsigned short m_uiBufferCapacity;
    unsigned short m_unusedC;
    unsigned short m_growth;
    void AppendValue(const unsigned int& value)
    {
        unsigned int index = m_uiBufferCapacity;
        unsigned int capacity = m_pRayCursor;
        if (index >= capacity)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(index + m_growth);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(index, (*(char * *)(&value)));
    }
public:
    ::NiObject *DeserializeObject();
public:
    bool Load(char *, int);
    bool Load(::NiBinaryStream *);
    bool Save(::NiBinaryStream *);
    void GetTexture(const char *, ::NiPointer< ::NiTexture> &);
    ::NiObject *GetLoadedObject();
    ::NiObjectGroup *GetObjectGroup(unsigned int);
    bool Save(char *&, int &);
    bool GetLastLoadedFilePath(char *, unsigned int);
    void SetStreamPath(const char *);
    void ClearTopLevelObjects();
    void SetLinkIDCount(unsigned int);
    static int RegisterObjectLoader(const char *, NiObject *(*)());
    static void RegisterPostProcess(void (*)(NiStream &, NiObject *));
    void InsertObject(::NiObject *);
};
// @fnv 0x00a377b0
void LoadInterpItem::LoadFromStream(LoadStream* stream)
{
    NiInterpolator* pInterpolator = (NiInterpolator*)reinterpret_cast<::NiStream *>((stream))->DeserializeObject();
    if (m_spControllerInterpolator != pInterpolator)
    {
        if (m_spControllerInterpolator)
            m_spControllerInterpolator->DecRefCount();
        m_spControllerInterpolator = pInterpolator;
        if (pInterpolator)
            pInterpolator->IncRefCount();
    }
    LoadStreamBinary(stream->m_pUnderlyingStream, m_fWeight);
    LoadStreamBinary(stream->m_pUnderlyingStream, m_fNormalizedWeight);
    if (stream->m_uiNifVersion < 0x0a01006e)
    {
        int priority;
        LoadStreamBinary(stream->m_pUnderlyingStream, priority);
        if (priority == 0x80000000)
            m_cPriority = (char)0x80;
        else
            m_cPriority = (char)priority;
    }
    else
    {
        LoadStreamBinary(stream->m_pUnderlyingStream, m_cPriority);
    }
    LoadStreamBinary(stream->m_pUnderlyingStream, m_fEaseSpinner);
}
struct LinkedInterpolator
{
    unsigned int m_pHeadNode;
    unsigned int m_iSecondInteger;
    void* m_object;
};
extern "C" char UNK_01096b68, UNK_01096b54, UNK_01096b40;
extern "C" char UNK_01096b2c, UNK_01096b1c, UNK_01096b08;
extern "C" char UNK_01096af4, UNK_01096adc, UNK_01096ac4;
extern "C" char UNK_01096ab4, UNK_01096aa4;
extern "C" char UNK_01096a98, UNK_01096a8c;
extern "C" char UNK_01096a78, UNK_01096a68;
struct ViewerBool
{
    bool flag;
};
union ViewerValue
{
    uintptr_t value;
    ViewerBool boolean;
};
struct InterpolatorRegistry
{
};
class BlendSerializer : public NiBlendInterpolator
{
  public:
    void FUN_00a38080(NiStream* stream);
};
// Appends viewer strings for the blend interpolator's fields and, for each array entry with a linked interpolator, its priority, weights and interpolator strings.
// @fnv 0x00a38080
void BlendSerializer::FUN_00a38080(NiStream* stream)
{
    ::FUN_00a570b0((::NiTPrimitiveArray<char *, ::NiTMallocInterface<char *>> *)(this));
    uintptr_t uiValue;
    {
        ViewerValue temp;
        temp.value = ((uintptr_t)(::FUN_00a7d330((const char *)((*reinterpret_cast<void * *>(&::g_011f36fc))))));
        stream->AppendValue(temp.value);
        temp.value = ((uintptr_t)(::FUN_00a7d410((const char *)(const void *)(&UNK_01096b68), this->m_ucArraySize)));
        stream->AppendValue(temp.value);
        temp.value = ((uintptr_t)(::FUN_00a7d410((const char *)(const void *)(&UNK_01096b54), DAT_011a83ff)));
        stream->AppendValue(temp.value);
        temp.boolean.flag = (this->m_uiObjectFlags & 1) != 0;
        temp.value = ((uintptr_t)(::FUN_00a7d370((const char *)(const void *)(&UNK_01096b40), (*(bool *)&(const ::ViewerBool &)(temp.boolean)))));
        stream->AppendValue(temp.value);
        temp.value = ((uintptr_t)(::FUN_00a7d550((const char *)(const void *)(&UNK_01096b2c), this->m_fWeightThreshold)));
        stream->AppendValue(temp.value);
        temp.value = ((uintptr_t)(::FUN_00a7d4d0((const char *)(const void *)(&UNK_01096b1c), this->m_cHighPriority)));
        stream->AppendValue(temp.value);
        temp.value = ((uintptr_t)(::FUN_00a7d4d0((const char *)(const void *)(&UNK_01096b08), this->m_cNextHighPriority)));
        stream->AppendValue(temp.value);
        temp.value = ((uintptr_t)(::FUN_00a7d550((const char *)(const void *)(&UNK_01096af4), this->m_fHighSumOfWeights)));
        stream->AppendValue(temp.value);
        temp.value = ((uintptr_t)(::FUN_00a7d550((const char *)(const void *)(&UNK_01096adc), this->m_fNextHighSumOfWeights)));
        stream->AppendValue(temp.value);
        temp.boolean.flag = ((this->m_uiObjectFlags >> 1) & 1) != 0;
        temp.value = ((uintptr_t)(::FUN_00a7d370((const char *)(const void *)(&UNK_01096ac4), (*(bool *)&(const ::ViewerBool &)(temp.boolean)))));
        stream->AppendValue(temp.value);
        temp.value = ((uintptr_t)(::FUN_00a7d410((const char *)(const void *)(&UNK_01096ab4), this->m_ucInterpCount)));
        stream->AppendValue(temp.value);
        temp.value = ((uintptr_t)(::FUN_00a7d410((const char *)(const void *)(&UNK_01096aa4), this->m_ucSingleIdx)));
        stream->AppendValue(temp.value);
    }
    for (unsigned int index = 0; index < this->m_ucArraySize; ++index)
    {
        if (this->m_pInterpArray[index].m_spControllerInterpolator.m_pObject && (*reinterpret_cast<::InterpolatorRegistry * *>(&::DAT_011f36f4)))
        {
            LinkedInterpolator* linked =
                ((::LinkedInterpolator *)(reinterpret_cast<::Registry *>(((*reinterpret_cast<::InterpolatorRegistry * *>(&::DAT_011f36f4))))->FindItemByBindingId((intptr_t)(this->m_pInterpArray[index].m_spControllerInterpolator.m_pObject), 1)));
            if (!linked && (*reinterpret_cast<::InterpolatorRegistry * *>(&::DAT_011f36f8)))
            {
                NiInterpolator* retryInterpolator = this->m_pInterpArray[index].m_spControllerInterpolator.m_pObject;
                linked = ((::LinkedInterpolator *)(reinterpret_cast<::Registry *>(((*reinterpret_cast<::InterpolatorRegistry * *>(&::DAT_011f36f8))))->FindItemByBindingId((intptr_t)(retryInterpolator), 1)));
            }
            if (linked)
            {
                void* linkedObject = linked->m_object;
                uiValue = ((uintptr_t)(::fnv_00a7d5e0::FUN_00a7d5e0((const char *)(const void *)(&(*reinterpret_cast<char *>((void *)&::g_011f36dc_arg0))), (const char *)(linkedObject))));
                stream->AppendValue(uiValue);
                uiValue = ((uintptr_t)(::FUN_00a7d410((const char *)(const void *)(&UNK_01096a98), (unsigned char)this->m_pInterpArray[index].m_cPriority)));
                stream->AppendValue(uiValue);
                uiValue = ((uintptr_t)(::FUN_00a7d550((const char *)(const void *)(&UNK_01096a8c), this->m_pInterpArray[index].m_fWeight)));
                stream->AppendValue(uiValue);
                uiValue = ((uintptr_t)(::FUN_00a7d550((const char *)(const void *)(&UNK_01096a78), this->m_pInterpArray[index].m_fNormalizedWeight)));
                stream->AppendValue(uiValue);
                uiValue = ((uintptr_t)(::FUN_00a7d550((const char *)(const void *)(&UNK_01096a68), this->m_pInterpArray[index].m_fEaseSpinner)));
                stream->AppendValue(uiValue);
                NiInterpolator* finalInterpolator = this->m_pInterpArray[index].m_spControllerInterpolator.m_pObject;
                ::FUN_00a570b0((::NiTPrimitiveArray<char *, ::NiTMallocInterface<char *>> *)(finalInterpolator));
            }
        }
    }
}

struct SBBinaryStream
{
    void* pVtable;
    unsigned int m_uiStreamFlags;
    void* pUnk08;
    unsigned int(__cdecl* m_pfnWrite)(SBBinaryStream* apThis, const void* apvBuffer, unsigned int auiBytes,
                                      unsigned int* apuiComponentSizes, unsigned int auiNumComponents);

    unsigned int BinaryWrite(const void* apvBuffer, unsigned int auiSize)
    {
        unsigned int uiSize = auiSize;
        unsigned int uiBytesWritten = m_pfnWrite(this, apvBuffer, auiSize, &uiSize, 1);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};

struct SBStream
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void SaveLinkID(const void* apObject);
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    SBBinaryStream* m_pBackingStream;
};

template <class T> inline void SBStreamSaveBinary(SBStream& arStream, const T& arValue)
{
    arStream.m_pBackingStream->BinaryWrite(&arValue, sizeof(T));
}

struct SBEntry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;

};

struct SBBase
{
    void* pVtable;
    int unk04;
    int unk08;

};

struct SBObject : SBBase
{
    unsigned char m_ucFlags;
    unsigned char m_ucEntryCount;
    unsigned char m_ucByte0E;
    unsigned char m_ucByte0F;
    unsigned char m_ucByte10;
    unsigned char m_ucByte11;
    SBEntry* m_pkEntryArray;
    void* m_pkLinked;
    int m_iValue1C;
    int m_iValue20;
    int m_iValue24;
    int m_iValue28;
    int m_iValue2C;

    void FUN_00a37ec0(SBStream& arStream);
};

// Serializes the base fields, then unless flag bit 1 is set writes the extra bytes and values, each entry, and the link ID.
// @fnv 0x00a37ec0
void SBObject::FUN_00a37ec0(SBStream& arStream)
{
    ::FUN_00a724d0();
    SBStreamSaveBinary(arStream, m_ucFlags);
    SBStreamSaveBinary(arStream, m_ucEntryCount);
    SBStreamSaveBinary(arStream, m_iValue1C);
    if (m_ucFlags & 1)
        return;

    SBStreamSaveBinary(arStream, m_ucByte0E);
    SBStreamSaveBinary(arStream, m_ucByte0F);
    SBStreamSaveBinary(arStream, m_ucByte10);
    SBStreamSaveBinary(arStream, m_ucByte11);
    SBStreamSaveBinary(arStream, m_iValue20);
    SBStreamSaveBinary(arStream, m_iValue24);
    SBStreamSaveBinary(arStream, m_iValue28);
    SBStreamSaveBinary(arStream, m_iValue2C);
    for (unsigned char i = 0; i < m_ucEntryCount; i++)
        reinterpret_cast<::InterpItem *>(&(m_pkEntryArray[i]))->WriteToStream((::StreamS *)&(arStream));
    arStream.SaveLinkID(m_pkLinked);
}

// The engine replaces the global deallocation function with a sized variant;
// this is the routine the original's deleting destructor calls with the size
// of the object it is releasing.

// Stand-in for NiBlendInterpolator (48 bytes, virtual destructor in vftable
// slot 0).  The real class is the engine's blend interpolator: it owns an
// array of interpolator entries and a single interpolator, and it carries a
// handful of flag bytes.
struct FUN_00a37670_NiBlendInterpolator
{
    virtual __declspec(noinline) ~FUN_00a37670_NiBlendInterpolator();
    int unk04;                      // NiObject
    float m_fLastTime;              // NiInterpolator
    unsigned char m_uiObjectFlags;         // +12
    unsigned char m_ucArraySize;    // +13
    unsigned char m_ucInterpCount;  // +14
    unsigned char m_ucSingleIdx;    // +15
    char m_cHighPriority;           // +16
    char m_cNextHighPriority;       // +17
    unsigned char unk18;
    unsigned char unk19;
    void* m_pInterpArray;             // +20
    void* m_pSingleInterpolator;      // +24
    float m_fWeightThreshold;         // +28
    float m_fSingleInterpolatorTime;  // +32
    float m_fHighSumOfWeights;        // +36
    float m_fNextHighSumOfWeights;    // +40
    float m_fTrailingValue;           // +44
};

// Clears m_pInterpArray and m_pSingleInterpolator, then sets m_ucInterpCount to zero.
// @fnv 0x00a37670
FUN_00a37670_NiBlendInterpolator::~FUN_00a37670_NiBlendInterpolator()
{
    // The real destructor walks the interpolator array and releases every
    // interpolator it holds, then drops the single interpolator.
    m_pInterpArray = 0;
    m_pSingleInterpolator = 0;
    m_ucInterpCount = 0;
}


struct S_00a370b0_Class
{
    int* unk00;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    unsigned char m_uiObjectFlags;
    unsigned char m_ucArraySize;
    unsigned char m_ucInterpCount;
    unsigned char m_ucSingleIdx;
    unsigned char m_cHighPriority;
    unsigned char m_cNextHighPriority;
    unsigned char unk12;
    unsigned char unk13;
    void* m_pInterpArray;
    void* m_pSingleInterpolator;
    float m_fWeightThreshold;
    float m_fSingleInterpolatorTime;
    float m_fHighSumOfWeights;
    float m_fNextHighSumOfWeights;
    float m_fTrailingValue;

    S_00a370b0_Class* FUN_00a370b0(bool bFlags, float fWeightThreshold, unsigned char volatile ucArraySize);
};

struct S_00a370b0_Allocator
{
};

extern int DAT_0109697c;

struct BlendItem
{
    void* m_spControllerInterpolator;
    float m_fWeight;
    float m_fNormalizedWeight;
    char m_cPriority;
    float m_fEaseSpinner;
    float m_fLastEvaluationTime;
    BlendItem() throw();
    ~BlendItem() throw();
};

// @fnv 0x00a370b0
S_00a370b0_Class* S_00a370b0_Class::FUN_00a370b0(bool bFlags, float fWeightThreshold,
                                                            unsigned char volatile ucArraySize)
{
    unsigned int nCount;
    unsigned int nSize;

    new ((void *)this) ::NiInterpolator();
    unsigned char arraySize = ucArraySize;

    m_fWeightThreshold = fWeightThreshold;
    m_fSingleInterpolatorTime = DAT_0109696c;
    m_fHighSumOfWeights = DAT_0109696c;
    m_cHighPriority = (char)0x80;
    m_fNextHighSumOfWeights = DAT_0109696c;
    m_cNextHighPriority = (char)0x80;
    m_fTrailingValue = DAT_0109696c;
    unk00 = &DAT_0109697c;
    m_ucArraySize = arraySize;
    m_ucInterpCount = 0;
    m_ucSingleIdx = 0xff;
    m_pInterpArray = 0;
    m_pSingleInterpolator = 0;
    m_uiObjectFlags = bFlags ? 1 : 0;
    if (arraySize > 0)
        m_pInterpArray = new BlendItem[arraySize];
    return this;
}


class MemoryManagerAllocHelper
{
  public:
};


struct CloneInterpItem
{
    NiInterpolator* m_spControllerInterpolator;
    float m_fWeight;
    float m_fNormalizedWeight;
    char m_cPriority;
    char unk0d, unk0e, unk0f;
    float m_fEaseSpinner;
    float m_fLastEvaluationTime;

    CloneInterpItem();
    ~CloneInterpItem();
};

struct BlendCopy : NiBlendInterpolator
{
    void FUN_00a37510(NiBlendInterpolator* destination, CloningProcess* process);
};

// @fnv 0x00a37510
void BlendCopy::FUN_00a37510(NiBlendInterpolator* destination, CloningProcess* process)
{
    ::FUN_00aa1000();
    destination->m_uiObjectFlags = m_uiObjectFlags;
    destination->m_ucArraySize = m_ucArraySize;
    destination->m_pInterpArray = (NiBlendInterpolator__InterpArrayItem*)new CloneInterpItem[m_ucArraySize];
    destination->m_fWeightThreshold = m_fWeightThreshold;

    if ((m_uiObjectFlags & 1) == 0)
    {
        for (unsigned char i = 0; i < m_ucArraySize; ++i)
        {
            CloneInterpItem& sourceItem = ((CloneInterpItem*)m_pInterpArray)[i];
            CloneInterpItem& destinationItem = ((CloneInterpItem*)destination->m_pInterpArray)[i];
            if (sourceItem.m_spControllerInterpolator)
            {
                NiInterpolator* cloned =
                    static_cast<NiInterpolator*>(sourceItem.m_spControllerInterpolator->MakeClone(*process));
                if (destinationItem.m_spControllerInterpolator != cloned)
                {
                    if (destinationItem.m_spControllerInterpolator)
                        destinationItem.m_spControllerInterpolator->DecRefCount();
                    destinationItem.m_spControllerInterpolator = cloned;
                    if (cloned)
                        cloned->IncRefCount();
                }
            }
            destinationItem.m_fWeight = sourceItem.m_fWeight;
            destinationItem.m_fNormalizedWeight = sourceItem.m_fNormalizedWeight;
            destinationItem.m_cPriority = sourceItem.m_cPriority;
            destinationItem.m_fEaseSpinner = sourceItem.m_fEaseSpinner;
            destinationItem.m_fLastEvaluationTime = sourceItem.m_fLastEvaluationTime;
        }

        destination->m_ucInterpCount = m_ucInterpCount;
        destination->m_ucSingleIdx = m_ucSingleIdx;
        destination->m_fSingleInterpolatorTime = m_fSingleInterpolatorTime;
        destination->m_cHighPriority = m_cHighPriority;
        destination->m_cNextHighPriority = m_cNextHighPriority;
    }
}


struct MM
{
};

class FUN_00a370a0 : public NiBlendInterpolator__InterpArrayItem
{
  public:
    __declspec(nothrow) FUN_00a370a0();
};

class NiBlendInterpolatorW : public NiBlendInterpolator
{
  public:
    bool FUN_00a37690();
};

// @fnv 0x00a37690
bool NiBlendInterpolatorW::FUN_00a37690()
{
    if (::DAT_011a83ff == 0)
        return false;

    unsigned char ucNewArraySize = m_ucArraySize + ::DAT_011a83ff;
    if (ucNewArraySize < 4)
        ucNewArraySize = 4;

    class FUN_00a370a0* pkNewInterpArray = new class FUN_00a370a0[ucNewArraySize];
    for (unsigned char uc = 0; uc < m_ucArraySize; uc++)
    {
        *(NiBlendInterpolator__InterpArrayItem*)&pkNewInterpArray[uc] = m_pInterpArray[uc];
    }
    delete[] (class FUN_00a370a0*)m_pInterpArray;

    m_pInterpArray = pkNewInterpArray;
    m_ucArraySize = ucNewArraySize;

    return true;
}

namespace fnv_00a37980 {
struct Stream100;
struct Memory100
{
};

struct FUN_00a370a0
{
    void* interpolator;
    float weight, normalizedWeight;
    char priority, unk0d, unk0e, unk0f;
    float easeSpinner, updateTime;
    __declspec(nothrow) FUN_00a370a0();
    ~FUN_00a370a0()
    {}
};

typedef struct FUN_00a370a0 Item100;

struct Binary100
{
    void* vtbl;
    unsigned int pos;
    unsigned int(__cdecl* read)(Binary100*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* d, unsigned int n)
    {
        unsigned int component = n;
        pos += read(this, d, n, &component, 1);
    }
};

struct Stream100
{

    unsigned int unk000;

    unsigned int unk004;

    unsigned int unk008;

    unsigned int unk00c;

    unsigned int unk010;

    unsigned int unk014;

    unsigned int unk018;

    unsigned int unk01c;

    unsigned int unk020;

    unsigned int unk024;

    unsigned int unk028;

    unsigned int unk02c;

    unsigned int unk030;

    unsigned int unk034;

    unsigned int unk038;

    unsigned int unk03c;

    unsigned int unk040;

    unsigned int unk044;

    unsigned int unk048;

    unsigned int unk04c;

    unsigned int unk050;

    unsigned int unk054;

    unsigned int unk058;

    unsigned int unk05c;

    unsigned int unk060;

    unsigned int unk064;

    unsigned int unk068;

    unsigned int unk06c;

    unsigned int unk070;

    unsigned int unk074;

    unsigned int unk078;

    unsigned int unk07c;

    unsigned int unk080;

    unsigned int unk084;

    unsigned int unk088;

    unsigned int unk08c;

    unsigned int unk090;

    unsigned int unk094;

    unsigned int unk098;

    unsigned int unk09c;

    unsigned int unk0a0;

    unsigned int unk0a4;

    unsigned int unk0a8;

    unsigned int unk0ac;

    unsigned int unk0b0;

    unsigned int unk0b4;

    unsigned int unk0b8;

    unsigned int unk0bc;

    unsigned int unk0c0;

    unsigned int unk0c4;

    unsigned int unk0c8;

    unsigned int unk0cc;

    unsigned int unk0d0;

    unsigned int unk0d4;

    unsigned int version;

    unsigned int unk0dc;

    unsigned int unk0e0;

    unsigned int unk0e4;

    unsigned int unk0e8;

    unsigned int unk0ec;

    unsigned int unk0f0;

    unsigned int unk0f4;

    unsigned int unk0f8;

    unsigned int unk0fc;

    unsigned int unk100;

    unsigned int unk104;

    unsigned int unk108;

    unsigned int unk10c;

    unsigned int unk110;

    unsigned int unk114;

    unsigned int unk118;

    unsigned int unk11c;

    unsigned int unk120;

    unsigned int unk124;

    unsigned int unk128;

    unsigned int unk12c;

    unsigned int unk130;

    unsigned int unk134;

    unsigned int unk138;

    unsigned int unk13c;

    unsigned int unk140;

    unsigned int unk144;

    unsigned int unk148;

    unsigned int unk14c;

    unsigned int unk150;

    unsigned int unk154;

    unsigned int unk158;

    unsigned int unk15c;

    unsigned int unk160;

    unsigned int unk164;

    unsigned int unk168;

    unsigned int unk16c;

    unsigned int unk170;

    unsigned int unk174;

    unsigned int unk178;

    unsigned int unk17c;

    unsigned int unk180;

    unsigned int unk184;

    unsigned int unk188;

    unsigned int unk18c;

    unsigned int unk190;

    unsigned int unk194;

    unsigned int unk198;

    unsigned int unk19c;

    unsigned int unk1a0;

    unsigned int unk1a4;

    unsigned int unk1a8;

    unsigned int unk1ac;

    unsigned int unk1b0;

    unsigned int unk1b4;

    unsigned int unk1b8;

    unsigned int unk1bc;

    unsigned int unk1c0;

    unsigned int unk1c4;

    unsigned int unk1c8;

    unsigned int unk1cc;

    unsigned int unk1d0;

    unsigned int unk1d4;

    unsigned int unk1d8;

    unsigned int unk1dc;

    unsigned int unk1e0;

    unsigned int unk1e4;

    unsigned int unk1e8;

    unsigned int unk1ec;

    unsigned int unk1f0;

    unsigned int unk1f4;

    unsigned int unk1f8;

    unsigned int unk1fc;

    unsigned int unk200;

    unsigned int unk204;

    unsigned int unk208;

    unsigned int unk20c;

    unsigned int unk210;

    unsigned int unk214;

    unsigned int unk218;

    unsigned int unk21c;

    unsigned int unk220;

    unsigned int unk224;

    unsigned int unk228;

    unsigned int unk22c;

    unsigned int unk230;

    unsigned int unk234;

    unsigned int unk238;

    unsigned int unk23c;

    unsigned int unk240;

    unsigned int unk244;

    unsigned int unk248;

    Binary100* binary;
};

struct Blend100
{
    int unk00, unk04, unk08;
    unsigned char flags, size, count, single;
    signed char high, next;
    short unk12;
    Item100* array;
    void* singleInterpolator;
    float weightThreshold, singleTime, highSum, nextSum, highEase;
    void FUN_00a37980(Stream100&);
};

// @fnv 0x00a37980
void Blend100::FUN_00a37980(Stream100& stream)
{

    reinterpret_cast<::FUN_00a88a40_shell *>(this)->FUN_00a88a40((::NiStream &)stream);

    if (stream.version >= 0x0a010070)
    {
        stream.binary->Read(&flags, 1);
        flags &= ~4;
    }

    if (stream.version < 0x0a01006e)
    {
        unsigned short oldSize, oldCount;
        stream.binary->Read(&oldSize, 2);
        size = oldSize;
        stream.binary->Read(&oldCount, 2);
    }

    else
        stream.binary->Read(&size, 1);

    array = new Item100[size];

    if (stream.version < 0x0a010070)
    {

        for (unsigned char i = 0; i < size; ++i)
            reinterpret_cast<::LoadInterpItem *>(&(array[i]))->LoadFromStream((::LoadStream *)&(stream));

        bool managerControlled;
        stream.binary->Read(&managerControlled, 1);
        if (managerControlled)
            flags |= 1;
        else
            flags &= ~1;

        stream.binary->Read(&weightThreshold, 4);

        bool onlyHighest;
        stream.binary->Read(&onlyHighest, 1);
        if (onlyHighest)
            flags |= 2;
        else
            flags &= ~2;

        if (stream.version < 0x0a01006e)
        {
            unsigned short oldCount, oldSingle;
            stream.binary->Read(&oldCount, 2);
            count = oldCount;
            stream.binary->Read(&oldSingle, 2);
            single = oldSingle;
        }

        else
        {
            stream.binary->Read(&count, 1);
            stream.binary->Read(&single, 1);
        }

        if (stream.version >= 0x0a01006c)
        {
            singleInterpolator = ((void *)(reinterpret_cast<::NiStream *>(&(stream))->DeserializeObject()));
            stream.binary->Read(&singleTime, 4);
        }

        if (stream.version < 0x0a01006e)
        {
            int oldHigh, oldNext;
            stream.binary->Read(&oldHigh, 4);
            if (oldHigh == (-2147483647 - 1))
                high = -128;
            else
                high = oldHigh;
            stream.binary->Read(&oldNext, 4);
            if (oldNext == (-2147483647 - 1))
                next = -128;
            else
                next = oldNext;
        }

        else
        {
            stream.binary->Read(&high, 1);
            stream.binary->Read(&next, 1);
        }
    }
    else
    {

        stream.binary->Read(&weightThreshold, 4);

        if (!(flags & 1))
        {
            stream.binary->Read(&count, 1);
            stream.binary->Read(&single, 1);
            stream.binary->Read(&high, 1);
            stream.binary->Read(&next, 1);
            stream.binary->Read(&singleTime, 4);
            stream.binary->Read(&highSum, 4);
            stream.binary->Read(&nextSum, 4);
            stream.binary->Read(&highEase, 4);

            for (unsigned char i = 0; i < size; ++i)
                reinterpret_cast<::LoadInterpItem *>(&(array[i]))->LoadFromStream((::LoadStream *)&(stream));

            singleInterpolator = ((void *)(reinterpret_cast<::NiStream *>(&(stream))->DeserializeObject()));
        }
    }
}
}  // namespace fnv_00a37980
#include "generated/data/gamebryo2.2/corelibs/nianimation/niblendinterpolator.inc"
