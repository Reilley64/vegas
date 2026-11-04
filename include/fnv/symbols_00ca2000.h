#pragma once

struct AttachmentList;
struct NodeList;
struct hkaSkeleton;

// 0x00ca21c0
::hkaSkeleton *BuildRigFromNodes(::NodeList *, ::NodeList *, ::AttachmentList *);
