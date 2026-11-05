#include "SandboxProcedureData.h"

// @fnv 0x009f6500
SandboxProcedureData::SandboxProcedureData() noexcept
    : pTarget(nullptr), eProcedure(SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_NONE),
      m_iActivityState(0), m_iProcedureData(0)
{}
