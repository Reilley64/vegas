#pragma once

struct OutputBuffer;

struct SceneList {
public:
    // 0x00cc2120
    void WriteSceneList(::OutputBuffer *, void *);
};
