#pragma once

class ParserString;
class ParserStream;
struct FnvInput;
struct FnvMap;
struct FnvString;
struct ParserPairs;

// 0x00ac7aa0
bool FUN_00ac7aa0(::FnvInput *, ::FnvMap *, ::FnvString *, int);
// 0x00ac7f50
bool FUN_00ac7f50(::ParserStream *, ::ParserPairs *, const ::ParserString *, int);
