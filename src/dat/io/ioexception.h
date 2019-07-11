#ifndef IOEXCEPTION_H
#define IOEXCEPTION_H

#include <stdexcept>

namespace io {

    class IOException : public std::runtime_error
    {
    public:
        IOException();
        IOException(const std::string &message);
    };

}

#endif // IOEXCEPTION_H
