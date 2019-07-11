#ifndef _DAT_H
#define _DAT_H

#include <vector>
#include <string>
#include "obj.h"

using namespace std;

namespace dat {
#define DAT_MAJOR_VERSION 1
#define DAT_MINOR_VERSION 0

    typedef vector<Object *> arqtype;
    typedef vector<string> files;

    struct crc_byte {
        uint8_t llow;
        uint8_t lhigh;
        uint8_t hlow;
        uint8_t hhigh;
    };

    struct size_long {
        uint32_t low;
        uint32_t high;
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

    struct size_byte {
        uint8_t lllow;
        uint8_t llhigh;
        uint8_t lhlow;
        uint8_t lhhigh;

        uint8_t hllow;
        uint8_t hlhigh;
        uint8_t hhlow;
        uint8_t hhhigh;
    };

    union SIZE {
        size_byte b;
        size_long l;
        uint64_t value;
    };

    /*
        * tamanho	descricao
        * 2			filemagic EFDD
        * 1			versao maior
        * 1			versao menor
        * 4			crc32
        * 4			arquivos internos
        * --- arquivos x n
        */
    class Dat {
    protected:
        string filename;
        uint32_t crc;
        uint8_t majorVersion;
        uint8_t minorVersion;
        arqtype arqs;

    public:
        Dat(string filename);
        Dat();
        ~Dat();

        uint32_t getCRC();
        uint8_t getMajorVersion();
        uint8_t getMinorVersion();
        Object *getObject(string name);
        files fileList();

        void setMajorVersion(uint8_t majorVersion);
        void setMinorVersion(uint8_t minorVersion);

        void addObject(Object *object);
        void removeObject(string name);

        void clear();

        void save();
        void save(string filename);
        void open();

    protected:
        void calcCRC();
    };
}

#endif
