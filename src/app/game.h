#ifndef GAME_H
#define GAME_H

#include "buffers.h"
#include "configdata.h"

class Game
{
public:
    Game();
    ~Game();

    void start();

private:
    Buffers *m_buffers;
    ConfigData *m_configData;
};

#endif // GAME_H
