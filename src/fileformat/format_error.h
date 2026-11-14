#ifndef VEGAS_FILEFORMAT_FORMAT_ERROR_H
#define VEGAS_FILEFORMAT_FORMAT_ERROR_H

#include <stdexcept>

namespace fileformat
{

// Thrown when bytes don't hold the format they are read as. The message names
// the format and the field.
class FormatError : public std::runtime_error
{
  public:
    using std::runtime_error::runtime_error;
};

} // namespace fileformat

#endif
