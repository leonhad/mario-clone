#ifndef BUFFER_H
#define BUFFER_H

#include "ioexception.h"

namespace io {

    class Buffer
    {
    protected:
        int m_position;
        int m_capacity;
        int m_limit;
        Buffer(int cap);

    public:
        virtual ~Buffer();
        bool isReadOnly();

        int capacity();
        int position();
        int remaining();
        int limit();
        void limit(int newLimit);
        bool hasRemaining();
        void clear();
        void flip();
        void position(int newPosition);
        void rewind();
    };

}

#endif // BUFFER_H
