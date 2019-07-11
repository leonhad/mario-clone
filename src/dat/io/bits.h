#ifndef BITS_H
#define BITS_H

#include <stdint.h>

namespace io {

    enum Endianess {
        ORDER_LITTLE_ENDIAN,
        ORDER_BIG_ENDIAN
    };

    class Bits
    {
    public:
        static uint16_t swap(uint16_t x);
        static uint32_t swap(uint32_t x);
        static bool isBigendian();
    };

}

#endif // BITS_H
