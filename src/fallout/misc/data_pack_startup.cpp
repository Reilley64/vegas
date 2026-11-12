#include "fnv/data_pack_startup.h"

#include "fileformat/format_error.h"
#include "fileformat/original_identity.h"
#include "fileformat/pack_open.h"
#include "fileformat/pack_validation.h"
#include "fnv/single_instance_strings.h"

fnv::startup::DataPackLoad fnv::startup::LoadDataPack(const std::filesystem::path& executableFolder)
{
    const std::string name = dataPackFileName;
    try
    {
        const fileformat::ValidatedPack pack = fileformat::OpenAndValidatePack(executableFolder / dataPackFileName);
        PublishSingleInstanceStrings(pack);
        return std::cref(PublishedSingleInstanceStrings());
    }
    catch (const fileformat::PackOpenError& error)
    {
        if (error.Problem() == fileformat::PackOpenProblem::Missing)
            return name + " is missing beside the executable: " + error.what() + "\n";
        return name + " beside the executable cannot be read: " + error.what() + "\n";
    }
    catch (const fileformat::FormatError& error)
    {
        return name + " beside the executable is not a valid data pack: " + error.what() + "\n";
    }
    catch (const fileformat::UnsupportedOriginalError& error)
    {
        return name + " beside the executable was not prepared from a supported original release: " + error.what() +
               "\n";
    }
}
