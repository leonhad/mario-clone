#include "obj.h"
#include "crc.h"
#include <fstream>
#include <cstdlib>

using namespace std;

namespace dat {

    Object::Object() : version(1)
    {
    }

    Object::Object(string filename)
    {
        // FIXME load the file
        //this->name = name;
        //this->data = NULL;
    }

    Object::~Object()
    {
        if (data) delete data;
    }

    void Object::setData(uint8_t *data, uint32_t size)
    {
        this->data = data;
        this->size = size;
    }

    uint8_t *Object::getData()
    {
        return data;
    }

    uint32_t Object::getSize()
    {
        return size;
    }

    const string Object::getName()
    {
        return name;
    }

    uint8_t Object::getType()
    {
        return type;
    }

    void Object::setName(string name)
    {
        this->name = name;
    }

    void Object::setType(uint8_t type)
    {
        this->type = type;
    }

    void Object::save(string filename)
    {
        fstream fileout(filename.c_str(), ios::out);
        if (fileout.is_open()) {
            // File magic
            fileout.put(0xEF);
            fileout.put(0xDE);

            // File version
            fileout.put(version);

            // File type
            fileout.put(type);

            uint32_t crc = 0;
            Crc::crc32(data, size, crc);

            CRC crcValue;

            // CRC value
            crcValue.value = crc;
            fileout.put(crcValue.b.llow);
            fileout.put(crcValue.b.lhigh);
            fileout.put(crcValue.b.hlow);
            fileout.put(crcValue.b.hhigh);

            fileout.put(name.length());
            fileout << name;

            // Use CRC structure to write the file size
            crcValue.value = size;
            fileout.put(crcValue.b.llow);
            fileout.put(crcValue.b.lhigh);
            fileout.put(crcValue.b.hlow);
            fileout.put(crcValue.b.hhigh);

            const uint8_t *ptr = data;
            for (uint32_t loop = 0; loop < size; loop++) {
                fileout.put(*ptr);
                ptr++;
            }

            fileout.close();
        } else {
            throw string("Error opening output file!");
        }
    }
}
