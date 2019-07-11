#include "bytebuffer.h"
#include "ioexception.h"
#include <cstdlib>

using namespace io;

ByteBuffer::ByteBuffer(int capacity) : Buffer(capacity)
{
    m_buffer = new uint8_t[capacity];

    m_order = Bits::isBigendian() ? ORDER_BIG_ENDIAN : ORDER_LITTLE_ENDIAN;
    m_native = ORDER_LITTLE_ENDIAN == m_order;
}

ByteBuffer::~ByteBuffer()
{
    delete m_buffer;
}

bool ByteBuffer::hasNext()
{
    return m_position + 1 < m_limit;
}

int ByteBuffer::getNextIndex() {
    if (!hasNext()) {
        throw IOException();
    }
    m_position++;
    return m_position;
}

uint8_t ByteBuffer::get()
{
    return m_buffer[getNextIndex()];
}

uint16_t ByteBuffer::getShort()
{
    if (m_native) {
        int i = getNextIndex();
        if (hasNext()) {
            uint16_t *p = reinterpret_cast<uint16_t*>(m_buffer + i);
            return *p;
        }
        throw IOException();
    } else {
        int i = getNextIndex();
        if (hasNext()) {
            uint16_t *p = reinterpret_cast<uint16_t*>(m_buffer + i);
            return Bits::swap(*p);
        }
        throw IOException();
    }
}

uint32_t ByteBuffer::getInt()
{
    if (m_native) {
        int i = getNextIndex();
        if (hasNext()) {
            uint32_t *p = reinterpret_cast<uint32_t*>(m_buffer + i);
            return *p;
        }
        throw IOException();
    } else {
        int i = getNextIndex();
        if (hasNext()) {
            uint32_t *p = reinterpret_cast<uint32_t*>(m_buffer + i);
            return Bits::swap(*p);
        }
        throw IOException();
    }
}

void ByteBuffer::put(uint8_t value)
{
    if (m_limit < m_capacity && m_position > m_limit)
    m_buffer[getNextIndex()] = value;
}

void ByteBuffer::put(uint16_t value)
{
    if (m_native) {

    } else {

    }
}

void ByteBuffer::put(uint32_t value)
{

}
