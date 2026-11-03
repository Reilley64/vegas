#pragma once

class BSBatchRenderer {
public:
    // 0x00b98ae0
    bool FindBucketIndex(unsigned int, int &);
    // 0x00b9a090
    bool FindPassBucket(unsigned int &, int &, bool &);
    // 0x00b9aec0
    void ReleaseGeometryGroups();
};
