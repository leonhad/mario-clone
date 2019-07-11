#include "gamedata.h"
#include "constants.h"

GameData::GameData()
{
    m_numPlayers = 1;

    m_lives[plMario] = 3;
    m_lives [plLuigi] = 3;
    m_coins [plMario] = 0;
    m_coins [plLuigi] = 0;
    m_score [plMario] = 0;
    m_score [plLuigi] = 0;
    m_progress [plMario] = 0;
    m_progress [plLuigi] = 0;
    m_mode [plMario] = mdSmall;
    m_mode [plLuigi] = mdSmall;
}
