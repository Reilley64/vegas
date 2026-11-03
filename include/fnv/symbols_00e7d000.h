#pragma once

class AdditionalDepthData;
class Ni2DBufferStub;
class NiDX9AdditionalDepthStencilBufferData;
class SwapChainBufferData;
struct AdditionalDepthDevice;
struct D3DDevice_e7d850;
struct DeviceE7D6B0;
struct PresentParamsE7D6B0;

// 0x00e7d390
::AdditionalDepthData *CreateDepthBufferData(::AdditionalDepthDevice *, void *, int, int, ::Ni2DBufferStub **);
// 0x00e7d6b0
::SwapChainBufferData *FUN_00e7d6b0(::DeviceE7D6B0 *, ::PresentParamsE7D6B0 *, ::Ni2DBufferStub **);
// 0x00e7d850
::NiDX9AdditionalDepthStencilBufferData *FUN_00e7d850(::D3DDevice_e7d850 *, ::Ni2DBufferStub *&);
// 0x00e7dd50
void FUN_00e7dd50(int);
// 0x00e7df90
bool FUN_00e7df90(int, float *);
