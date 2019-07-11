#ifndef _DATOBJ_H
#define _DATOBJ_H

#include <stdint.h>
#include <string>

using namespace std;

namespace dat {

    // TODO rever
    enum OBJ_TYPE {
        OBJ_OTHER = 1,
        OBJ_IMAGE,
        OBJ_BIN_CONFIG,
        OBJ_INI_CONFIG,
        OBJ_SCRIPT,
        OBJ_MAP,
        OBJ_SPRITE
    };

    class Object {
    protected:
        string name;
        uint32_t size;
        uint8_t *data;
        uint8_t type;
        uint8_t version;

    public:
        Object();
        Object(string filename);
        ~Object();

        uint8_t *getData();
        const string getName();
        uint32_t getSize();
        uint8_t getType();
        void setData(uint8_t *data, uint32_t size);
        void setName(string name);
        void setType(uint8_t type);
        void save(string filename);
    };

}

#endif
