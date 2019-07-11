#ifndef BYTEBUFFER_H
#define BYTEBUFFER_H

#include <stdint.h>
#include "buffer.h"
#include "bits.h"

namespace io {

    class ByteBuffer : Buffer
    {
    private:
        uint8_t *m_buffer;
        Endianess m_order;
        bool m_native;

        bool hasNext();
        int getNextIndex();

    public:
        ByteBuffer(int capacity);
        ~ByteBuffer();

        uint8_t get();
        uint16_t getShort();
        uint32_t getInt();
        void put(uint8_t value);
        void put(uint16_t value);
        void put(uint32_t value);
    };

}

#endif // BYTEBUFFER_H
