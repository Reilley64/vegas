#pragma once

struct FormatPrefsQ;
struct NiDX9RendererQ;
struct NiFileQ;

struct NiDX9SourceTextureDataQ {
public:
    // 0x00e68a80
    bool LoadFromFilename(const char *, ::NiDX9RendererQ *, const ::FormatPrefsQ &, ::NiFileQ *);
};
