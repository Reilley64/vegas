#pragma once

class hkpSphereShape;

namespace havok
{
// Constructs a shared native sphere with one owned reference. The caller
// releases it with removeReference(); its supplying heap must outlive it.
// Only a declaration is needed by legacy callers that publish the pointer.
[[nodiscard]] hkpSphereShape* createSphere(float radius);
}
