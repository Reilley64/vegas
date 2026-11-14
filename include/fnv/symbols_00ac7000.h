#pragma once

namespace fnv_00ac7aa0 {
struct Exclusion;
}

class ParserString;
class ParserStream;
struct FnvInput;
struct FnvMap;
struct ParserPairs;

// 0x00ac7aa0
bool FUN_00ac7aa0(::FnvInput *, ::FnvMap *, const fnv_00ac7aa0::Exclusion *, int);
// 0x00ac7f50
bool FUN_00ac7f50(::ParserStream *, ::ParserPairs *, const ::ParserString *, int);
