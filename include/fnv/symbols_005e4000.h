#pragma once

class PartNode;
namespace fnv_005e4890 { class TreeNode; }
struct AVObj_S;

// 0x005e4730
void AddNodeEntries(unsigned int, ::PartNode *);
// 0x005e4890
namespace fnv_005e4890 { void ApplyKeyToLeafNodes(unsigned int, ::fnv_005e4890::TreeNode *); }
// 0x005e4970
void SetPartitionVisibility(int, ::AVObj_S *);
