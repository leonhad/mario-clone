#include "ioexception.h"

using namespace io;

IOException::IOException() : runtime_error("I/O Internal Error")
{
}

IOException::IOException(const std::string &message) : runtime_error(message)
{
}
