#pragma once

struct A5FC10Stub;
struct NiObject;
struct NiSourceCubeMap;
struct SpawnedCubeShell;

// 0x00a60070
::A5FC10Stub *CreateA5FC10Stub();
// 0x00a60f30
::NiSourceCubeMap *CreateNiSourceCubeMap();
// 0x00a60f60
::SpawnedCubeShell *CreateSpawnedCubeShell(char **, ::NiObject *, unsigned int *);
