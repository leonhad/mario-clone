#ifndef BUFFERS_H
#define BUFFERS_H

#include "gamedata.h"
#include "constants.h"
#include <QString>

class Buffers
{
private:
    bool m_quitGame;
    bool m_beeperSound;
    long m_levelScore;
    int m_player;
    GameData *m_data;
    QString WorldNumber[3];

public:
    Buffers();
    ~Buffers();

    //void readWorld (void *Map, WorldBuffer *W, void *Opt);
    void Swap();

    void beeperOn();
    void beeperOff();
    void beep (unsigned int Freq);

    void initLevelScore();
    void addScore (long n);

    GameData *gameData();
    bool quitGame();
};

#endif // BUFFERS_H
