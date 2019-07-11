#include <iostream>
#include <crc.h>
#include <obj.h>
#include <cstdlib>
#include <cstdio>
#include <string.h>

using namespace std;
using namespace dat;

int main() {
    bool result;
    uint32_t crc;

    /// CRC Calc Test
    result = Crc::crc32((uint8_t *)"Teste de string", 15, crc);
    if (!result || crc != 0xeca1a478) {
        fprintf(stderr, "TEST: Invalid CRC: %x\n", crc);
    } else {
        printf("TEST: Valid CRC\n");
    }

    /// CRC Union Test
    CRC teste;
    teste.value = 0;
    teste.b.hlow = 1;
    if (teste.value == 65536 && sizeof(uint64_t) == 8) {
        printf("TEST: Right endian\n");
    } else {
        printf("TEST: Wrong endian\n");
    }

    const char *value = "Teste de arquivo objeto";
    Object *obj = new Object("test");
    obj->setType(OBJ_SCRIPT);
    obj->setData((uint8_t *)value, strlen(value));
    obj->save("test.obj");


    /*
    Dat *dat = new Dat();

    Object *obj = new Object("test");
    obj->setSize(24);
    obj->setType(OBJ_FILE);
    obj->setData("Teste de arquivo objeto");
    dat->addObject(obj);

    obj = new Object("test2");
    obj->setSize(30);
    obj->setType(OBJ_FILE);
    obj->setData("Teste de arquivo objeto 12345");
    dat->addObject(obj);

    dat->save("test.dat");
    printf("TEST: Arquivo teste.dat salvo\n");

    printf("TEST: Carregando arquivo teste.dat\n");
    dat = new Dat("teste.dat");
    delete dat;
    */
    return EXIT_SUCCESS;
}
