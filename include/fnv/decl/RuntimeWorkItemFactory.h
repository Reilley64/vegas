#pragma once

struct RuntimeWorkItem;

struct RuntimeWorkItemFactory {
public:
    // 0x0055a160
    ::RuntimeWorkItem *CreateRuntimeWorkItem();
};
