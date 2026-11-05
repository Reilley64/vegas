#include "havok/ErrorDiagnostics.h"

#include <cstdio>
#include <stdexcept>

namespace havok::diagnostics
{
ErrorReference::ErrorReference() : error(havok::base::GetError())
{
    if (!error)
        throw std::logic_error("Havok diagnostic requires initialized base owners");
    error->AddReference();
}
ErrorReference::~ErrorReference() { error->RemoveReference(); }
}

// @fnv 0x00cb1750
void FUN_00cb1750(const char* message)
{
    havok::diagnostics::ErrorReference error;
    // The retained diagnostic stream has a 512-byte buffer.
    char text[512];
    std::snprintf(text, sizeof(text), "%s", message);
    if (error.Get().Message(3, 0x2636fe25, text, ".\\System\\Error\\hkError.cpp", 0x28))
        havok::diagnostics::Breakpoint();
}

// @fnv 0x00cb1660
void ReportReferenceCountError(const havok::base::Reference& object, const char* context)
{
    havok::diagnostics::ErrorReference error;
    char text[512];
    std::snprintf(text, sizeof(text),
        "Reference count error on object %p with ref count of %d in %s.\n"
        " * Are you calling delete instead of removeReference?\n"
        " * Have you called removeReference too many times?\n"
        " * In a multithreaded environment, what is the hkReferencedObject lock mode you use (see setLockMode())?\n"
        " * Is this a valid object?\n"
        " * Do you have more than 32768 references? (unlikely)\n",
        static_cast<const void*>(&object), object.GetReferenceCount(), context);
    if (error.Get().Message(3, 0x2c66f2d8, text, ".\\System\\Error\\hkError.cpp", 0x21))
        havok::diagnostics::Breakpoint();
}
