#include "bits.h"

using namespace io;

uint16_t Bits::swap(uint16_t x)
{
    return (uint16_t)((x << 8) | (x >> 8));
}

uint32_t Bits::swap(uint32_t x)
{
    return ((x << 24) |
            ((x & 0x0000ff00) <<  8) |
            ((x & 0x00ff0000) >> 8) |
            (x >> 24));
}

bool Bits::isBigendian()
{
    const int i = 1;
    return (*(char*)&i) == 0;
}
