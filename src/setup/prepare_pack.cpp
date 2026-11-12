#include "setup/prepare_pack.h"

#include "fileformat/format_error.h"
#include "setup/staged_pack.h"

#include <utility>

namespace setup
{

PreparedPack PrepareDataPack(std::vector<std::byte> executable)
{
    std::vector<std::byte> bytes = staged::StagePack(std::move(executable), fileformat::IdentifyOriginal);
    try
    {
        fileformat::ValidatedPack validated = fileformat::ValidatePack(bytes);
        return {std::move(bytes), std::move(validated)};
    }
    catch (const fileformat::FormatError& error)
    {
        throw StagedPackError(std::string("data pack: written: was refused: ") + error.what());
    }
    catch (const fileformat::UnsupportedOriginalError& error)
    {
        throw StagedPackError(std::string("data pack: written: was refused: ") + error.what());
    }
}

} // namespace setup
