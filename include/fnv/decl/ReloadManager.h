#pragma once

struct ReloadPoint;
struct ReloadScene;

struct ReloadManager {
public:
    // 0x00453dc0
    void AttachScene(::ReloadScene *, ::ReloadPoint *);
};
