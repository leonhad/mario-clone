#include "buffers.h"

Buffers::Buffers()
{
    m_quitGame = false;
    m_beeperSound = false;

    m_data = new GameData;
}

Buffers::~Buffers()
{
    delete m_data;
}

void Buffers::beeperOn()
{
    m_beeperSound = true;
}

void Buffers::beeperOff()
{
    m_beeperSound = false;
}

void Buffers::initLevelScore()
{
    m_levelScore = 0;
}

void Buffers::addScore(long n)
{
    m_levelScore += n;
}

GameData *Buffers::gameData()
{
    return m_data;
}

bool Buffers::quitGame()
{
    return m_quitGame;
}
