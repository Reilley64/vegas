#pragma once

class BSFileEntry;
class QueuedFile;

class TextureLoader {
public:
    // 0x00443af0
    bool QueueTextureLoad(::BSFileEntry *, int, ::QueuedFile *);
};
