#include "setup/prepare_pack.h"

#include "setup/staged_pack.h"

#include <utility>

namespace setup
{

PreparedPack PrepareDataPack(std::vector<std::byte> executable)
{
    return staged::CheckWrittenPack(staged::StagePack(std::move(executable), fileformat::IdentifyOriginal));
}

} // namespace setup
