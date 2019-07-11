#ifndef GAMEDATA_H
#define GAMEDATA_H

class GameData
{
public:
    GameData();

    int m_numPlayers;
    int m_progress[2];
    int m_lives[2];
    int m_coins[2];
    long m_score[2];
    int m_mode[2];
};

#endif // GAMEDATA_H
