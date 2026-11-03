#pragma once

struct LocalEdge;
struct LocalMeshPtr;

struct LocalConnector {
public:
    // 0x006c4390
    bool ConnectEdges(::LocalMeshPtr &, const ::LocalEdge &, ::LocalMeshPtr &, const ::LocalEdge &);
};
