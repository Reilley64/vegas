#pragma once

#include "havok/PackfileLoad.h"
namespace havok::serialize { class ClassNameRegistry; }
class ObjectResource;

// Actual heap-loader entry. Policy supplies the version/layout/deprecated
// capability already required by the retained stream loader.
ObjectResource* FUN_00d48840(havok::serialize::LoadStream*, const havok::serialize::LoadFormat&,
    havok::serialize::LoadError*, const havok::serialize::ClassNameRegistry*,
    const havok::serialize::TypeRegistry*, const havok::serialize::LoadPolicy&) noexcept;
extern havok::serialize::LoadStream* volatile inputSource;
extern havok::serialize::LoadFormat* volatile formatSource;
extern havok::serialize::LoadError* volatile errorSource;
extern const havok::serialize::ClassNameRegistry* volatile classSource;
extern const havok::serialize::TypeRegistry* volatile typeSource;
extern ObjectResource* volatile outputSink;
void CallHeapLoader();
