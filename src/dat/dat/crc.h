#ifndef _CRC_H
#define _CRC_H

#include <stdint.h>

namespace dat {
    struct crc_byte {
        uint8_t llow;
        uint8_t lhigh;
        uint8_t hlow;
        uint8_t hhigh;
    };

    struct crc_int {
        uint16_t low;
        uint16_t high;
    };

    union CRC {
        crc_byte b;
        crc_int i;
        uint32_t value;
    };

    class Crc {
    public:
        static bool stringCrc32(uint8_t *string, uint32_t &crc32);
        static bool crc32(uint8_t *string, uint32_t tamanho, uint32_t &crc32);
    };
}

#endif
