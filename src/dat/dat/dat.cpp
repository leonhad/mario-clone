#include "dat.h"
#include "crc.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

namespace dat {
    Dat::Dat(string filename)
    {
        this->filename = filename;
        Dat();
        open();
    }

    Dat::Dat()
    {
        majorVersion = DAT_MAJOR_VERSION;
        minorVersion = DAT_MINOR_VERSION;
    }

    Dat::~Dat()
    {
        clear();
    }

    uint32_t Dat::getCRC()
    {
        if (!crc) calcCRC();
        return crc;
    }

    void Dat::calcCRC()
    {
        Object *file = NULL;
        crc = 0;

        arqtype::iterator i = arqs.begin();
        while(i != arqs.end()) {
            file = *i;
            Crc::crc32(file->getData(), file->getSize(), crc);
            i++;
        }
    }

    uint8_t Dat::getMajorVersion()
    {
        return majorVersion;
    }

    uint8_t Dat::getMinorVersion()
    {
        return minorVersion;
    }

    Object *Dat::getObject(string name)
    {
        arqtype::iterator i = arqs.begin();
        while(i != arqs.end()) {
            if ((*i)->getName() == name) {
                return *i;
            }
            i++;
        }
        return NULL;
    }

    files Dat::fileList()
    {
        files list;
        arqtype::iterator i = arqs.begin();
        while(i != arqs.end()) {
            list.push_back((*i)->getName());
            i++;
        }
        return list;
    }

    void Dat::setMajorVersion(uint8_t majorVersion)
    {
        if (majorVersion <= DAT_MAJOR_VERSION)
            this->majorVersion = majorVersion;
    }

    void Dat::setMinorVersion(uint8_t minorVersion)
    {
        if (majorVersion >= DAT_MAJOR_VERSION && minorVersion > DAT_MINOR_VERSION)
            return;
        else
            this->minorVersion = minorVersion;
    }

    void Dat::addObject(Object *obj)
    {
        arqs.push_back(obj);
    }

    void Dat::removeObject(string name)
    {
        arqtype::iterator i = arqs.begin();
        while(i != arqs.end()) {
            if ((*i)->getName() == name) {
                Object *obj = *i;
                arqs.erase(i);
                delete obj;
                break;
            }
            i++;
        }
    }

    void Dat::clear()
    {
        Object *arquivo;
        arqtype::iterator i = arqs.begin();
        while(i != arqs.end()) {
            arquivo = *i;
            delete arquivo;
            i++;
        }
        arqs.clear();
    }

    void Dat::save(string filename)
    {
        this->filename = filename;
        save();
    }

    struct filedesc {
        string name;
        SIZE locate;
        CRC tamanho;
        OBJ_TYPE tipo;
    };

    typedef vector<filedesc> FILEDESC;

    void Dat::open()
    {
        char token;
        CRC crcCalc;
        CRC fileCount;
        CRC tamanho;
        OBJ_TYPE tipo;
        FILEDESC descritores;
        uint8_t filemagic_high;
        uint8_t filemagic_low;

        crcCalc.value = 0;
        fileCount.value = 0;
        tamanho.value = 0;
        tipo = OBJ_FILE;

        clear();

        filebuf filebuffer;
        if (filebuffer.open(filename.c_str(), ios_base::in) == NULL)
            return;
        istream filein(&filebuffer);

        try {
            /// filemagic
            filein.get(token);
            filemagic_high = token;
            filein.get(token);
            filemagic_low = token;

            // verifica o tipo do arquivo
            if (filemagic_high != 0xEF || filemagic_low != 0xDD) {
                return;
            }

            /// versao
            majorVersion = filein.get();
            minorVersion = filein.get();

            // versao incompativel
            if (majorVersion >= DAT_MAJOR_VERSION && minorVersion > DAT_MINOR_VERSION) {
                return;
            }

            /// CRC - verificar mais tarde
            filein.get(token);
            crcCalc.b.hhigh = token;
            filein.get(token);
            crcCalc.b.hlow = token;
            filein.get(token);
            crcCalc.b.lhigh = token;
            filein.get(token);
            crcCalc.b.llow = token;

            // Quantidade de Itens
            filein.get(token);
            fileCount.b.hhigh = token;
            filein.get(token);
            fileCount.b.hlow = token;
            filein.get(token);
            fileCount.b.lhigh = token;
            filein.get(token);
            fileCount.b.llow = token;

#ifdef DEBUG
            cout << "DAT: " << filename.c_str() << " contém " << fileCount.value << " entradas" << endl;
#endif

            /// Descritor de arquivo
            for (uint32_t loop = 0; loop < fileCount.value; loop++) {
                filedesc desc;
                SIZE localizacao;

                /// localizacao
                filein.get(token);
                localizacao.b.hhhigh = token;
                filein.get(token);
                localizacao.b.hhlow = token;
                filein.get(token);
                localizacao.b.hlhigh = token;
                filein.get(token);
                localizacao.b.hllow = token;
                filein.get(token);
                localizacao.b.lhhigh = token;
                filein.get(token);
                localizacao.b.lhlow = token;
                filein.get(token);
                localizacao.b.llhigh = token;
                filein.get(token);
                localizacao.b.lllow = token;
                desc.locate = localizacao;

                /// tamanho
                filein.get(token);
                tamanho.b.hhigh = token;
                filein.get(token);
                tamanho.b.hlow = token;
                filein.get(token);
                tamanho.b.lhigh = token;
                filein.get(token);
                tamanho.b.llow = token;
                desc.tamanho = tamanho;

                /// tipo
                filein.get(token);
                tipo = (OBJ_TYPE)token;
                desc.tipo = tipo;

                for (uint8_t nome = 0; nome < 24; nome++) {
                    filein.get(token);
                    desc.name += token;
                }
                descritores.push_back(desc);

            }

            FILEDESC::iterator d = descritores.begin();
            while(d != descritores.end() && !filein.eof()) {
                filedesc desc = *d;
                Object *arq = new Object(desc.name.c_str());
                arq->setSize(desc.tamanho.value);
                arq->setType(desc.tipo);
                char *file = new char[desc.tamanho.value];
                for (uint32_t loop = 0; loop < desc.tamanho.value; loop++) {
                    filein.get(token);
                    file[loop] = token;
                    if (filein.eof()) {
                        break;
                    }
                }
                arq->setData(file);
                arqs.push_back(arq);
                d++;
            }

#ifdef DEBUG
            arqtype::iterator i = arqs.begin();
            while(i != arqs.end()) {
                Arquivo *arq = *i;
                cout << "DAT: nome: " << arq->getNome() << " tamanho: " << arq->getTamanho();
                if (arq->getTipo() == ARQUIVO) {
                    cout << " tipo: ARQUIVO" << endl;
                } else if (arq->getTipo() == IMAGEM) {
                    cout << " tipo: IMAGEM" << endl;
                } else if (arq->getTipo() == CONFIG) {
                    cout << " tipo: CONFIG" << endl;
                } else if (arq->getTipo() == SCRIPT) {
                    cout << " tipo: SCRIPT" << endl;
                }
                cout << "DAT: dados: " << arq->getArquivo() << endl;
                i++;
            }
#endif
        } catch(...) {
            printf("DAT: erro inesperado ao carregar o arquivo");
        }

        filebuffer.close();
    }

    void Dat::save()
    {
        filebuf filebuffer;
        Object *file;
        SIZE localizacao;
        char tipo;
        CRC crcCalc;
        CRC fileCount;
        CRC tamanho;

        fileCount.value = (uint32_t)arqs.size();
        crcCalc.value = getCRC();

        if (filebuffer.open(filename.c_str(), ios_base::out) == NULL)
            return;
        ostream fileout(&filebuffer);

        try {
            /// Write header
            // tamanho	descricao
            // 2		filemagic EFDD
            // 1		versao maior
            // 1		versao menor
            // 4		crc32             (maior -> menor)
            // 4		arquivos internos (maior -> menor)

            // FileMagic
            fileout.put((uint8_t)0xEF);
            fileout.put((uint8_t)0xDD);

            // Versão
            fileout.put(majorVersion);
            fileout.put(minorVersion);

            // CRC
            fileout.put(crcCalc.b.hhigh);
            fileout.put(crcCalc.b.hlow);
            fileout.put(crcCalc.b.lhigh);
            fileout.put(crcCalc.b.llow);

            // Quantidade de Itens
            fileout.put(fileCount.b.hhigh);
            fileout.put(fileCount.b.hlow);
            fileout.put(fileCount.b.lhigh);
            fileout.put(fileCount.b.llow);

            // Descritor x n
            // tamanho	descricao
            // 8		localizacao
            // 4		tamanho
            // 1		tipo
            // 24		nome

            // tamanho do header + descritor * numero de itens;
            localizacao.value = 12 + 37 * arqs.size();
            arqtype::iterator i = arqs.begin();
            while(i != arqs.end()) {
                file = *i;
                /// localizacao
                fileout.put(localizacao.b.hhhigh);
                fileout.put(localizacao.b.hhlow);
                fileout.put(localizacao.b.hlhigh);
                fileout.put(localizacao.b.hllow);
                fileout.put(localizacao.b.lhhigh);
                fileout.put(localizacao.b.lhlow);
                fileout.put(localizacao.b.llhigh);
                fileout.put(localizacao.b.lllow);

                /// tamanho
                tamanho.value = file->getSize();
                fileout.put(tamanho.b.hhigh);
                fileout.put(tamanho.b.hlow);
                fileout.put(tamanho.b.lhigh);
                fileout.put(tamanho.b.llow);

                /// tipo
                tipo = (char)file->getType();
                fileout.put(tipo);

                string nome = file->getName();
                if (nome.size() > 24) {
                    nome = nome.substr(0, 24);
                } else {
                    nome.append(repeteEspaco(24 - (uint8_t)nome.size()));
                }
                fileout << nome;

                localizacao.value += file->getSize();
                i++;
            }

            // grava os arquivos
            i = arqs.begin();
            while(i != arqs.end()) {
                file = *i;
                const char *ptr = file->getData();
                for (uint32_t loop = 0; loop < file->getSize(); loop++) {
                    fileout.put(*ptr);
                    ptr++;
                }
                i++;
            }
        } catch(...) {
            throw string("DAT: erro inesperado ao gravar o arquivo");
        }
        // fecha o arquivo
        filebuffer.close();
    }
}
