#pragma once

struct VFForm;
struct VFTopicInfo;

struct VFDialogue {
public:
    // 0x00616fa0
    bool BuildVoiceFilePath(::VFForm *, void *, void *, ::VFTopicInfo *, char *);
};
