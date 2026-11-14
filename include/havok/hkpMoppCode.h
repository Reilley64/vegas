// Shared native MOPP code and its owned byte stream.
#ifndef FNV_HAVOK_HKPMOPPCODE_H
#define FNV_HAVOK_HKPMOPPCODE_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#include "hkpMoppCodeCodeInfo.h"
#include <span>
class hkMemoryAllocator;
class hkpMoppCode : public hkReferencedObject
{
  public:
    enum BuildType
    {
        BUILT_WITH_CHUNK_SUBDIVISION = 0,
        BUILT_WITHOUT_CHUNK_SUBDIVISION = 1,
        BUILD_NOT_SET = 2
    };
    hkpMoppCode() noexcept;
    // Materializes source-owned synthetic/builder code bytes, not a file layout.
    hkpMoppCode(const hkpMoppCodeCodeInfo&, std::span<const hkUint8>);
    ~hkpMoppCode() override;
    std::span<const hkUint8> getData() const noexcept { return {m_data.m_data, static_cast<std::size_t>(m_data.m_iElementCount)}; }
    const hkpMoppCodeCodeInfo& getCodeInfo() const noexcept { return m_info; }
    BuildType getBuildType() const noexcept { return static_cast<BuildType>(m_eBuildType); }

    hkpMoppCodeCodeInfo m_info;
    hkArray<hkUint8> m_data;
    hkInt8 m_eBuildType;

  private:
    hkMemoryAllocator* dataAllocator = nullptr;
};
#endif
