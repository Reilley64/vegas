#pragma once

namespace DecalClipping { struct Plane; }
namespace DecalClipping { struct Point; }

// 0x0068d820
namespace DecalClipping { int ClipPolygonToPlane(::DecalClipping::Plane *, int, const int *, const ::DecalClipping::Point *, const ::DecalClipping::Point *, int *, ::DecalClipping::Point *, ::DecalClipping::Point *); }
