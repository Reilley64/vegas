
#include "fnv/decl/FUN_004a51d0_shell.h"
#include "fnv/decl/FUN_004f0000_shell.h"
#include "fnv/decl/ListStandIn.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_00559000.h"
#include "niavobject_types.h"

// @fnv 0x004eff50
void NiAVObject::UpdateTimeControllers(NiUpdateData& data, bool updateProperties)
{
    NiTimeController* controller;
    if (updateProperties && reinterpret_cast<::FUN_004f0000_shell *>((void *)this)->FUN_004f0000()) {
        NiTListIterator position = (*(void **)&(SceneGraphObject));
        while (position) {
            NiProperty* property = (*(::NiPointer< ::NiProperty> *)(reinterpret_cast<::ListStandIn *>(&(SceneGraphObject))->FUN_0057cbe0((int **)&(position))));
            if (property && ((::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)(property)))))
                property->Update(data);
        }
    }
    for (controller = ((::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)this))); controller; controller = ((::NiTimeController *)(::fnv_004a8a90::FUN_004a8a90((char *)(controller)))))
        controller->Update(data);
}

// @fnv 0x005467e0
void NiAVObject::EnsureWorldBound()
{
    if (!m_kWorldBound) {
        SetObjectBound(new FourComponentFloatVector(0x100, 0));
        reinterpret_cast<::FUN_004a51d0_shell *>((m_kWorldBound))->FUN_004a51d0((void *)&(NiPoint3::ZERO), 0.0f);
    }
}
