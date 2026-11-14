#pragma once

struct IDirect3DDevice9;

// NiDX9Renderer as far as the game code reads it directly: the Direct3D device. The release build reads it through
// the folded 4-byte getter at 0x004dc020.
struct NiDX9RendererView
{
    char pad00[0x288];
    IDirect3DDevice9* m_pkD3DDevice9;
};
