#include "buffer.h"
#include "ioexception.h"

using namespace io;

Buffer::Buffer(int cap)
{
    this->m_position = 0;
    this->m_capacity = cap;
    this->m_limit = 0;
}

Buffer::~Buffer() {
}

int Buffer::capacity()
{
    return m_capacity;
}

int Buffer::position()
{
    return m_position;
}

void Buffer::position(int newPosition)
{
    if (newPosition >= m_limit || newPosition < 0) {
        throw IOException("Invalid position.");
    }
    m_position = newPosition;
}

int Buffer::limit()
{
    return m_limit;
}

void Buffer::limit(int newLimit)
{
    //if ((newLimit > capacity) || (newLimit < 0))
    //    throw new IllegalArgumentException();
    m_limit = newLimit;
    if (m_position > m_limit) m_position = m_limit;
}

void Buffer::clear()
{
    m_position = 0;
    m_limit = m_capacity;
}

void Buffer::flip()
{
    m_limit = m_position;
    m_position = 0;
}

void Buffer::rewind()
{
    m_position = 0;
}

int Buffer::remaining()
{
    return m_limit - m_position;
}

bool Buffer::hasRemaining()
{
    return m_position < m_limit;
}
