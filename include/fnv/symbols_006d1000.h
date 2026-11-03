#pragma once

namespace fnv_006d1f80 { struct RequestOps; }
namespace fnv_006d1f80 { struct SolutionOps; }
struct P048Request;
struct P048Solution;
struct PFRequest;
struct PFSolution;
struct RequestView;
struct SolutionView;

// 0x006d12a0
bool InitSolutionEndpoints(::PFRequest *, ::PFSolution *);
// 0x006d1600
void FUN_006d1600();
// 0x006d1660
bool FUN_006d1660(::RequestView *, ::SolutionView *);
// 0x006d1c60
bool FUN_006d1c60(::P048Request *, ::P048Solution *);
// 0x006d1f80
namespace fnv_006d1f80 { bool BuildPathBetweenLocations(::fnv_006d1f80::RequestOps *, ::fnv_006d1f80::SolutionOps *); }
