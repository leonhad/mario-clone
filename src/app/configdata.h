#ifndef CONFIGDATA_H
#define CONFIGDATA_H

#include "constants.h"
#include "gamedata.h"
#include "buffers.h"

class ConfigData
{
public:
    ConfigData();
    ~ConfigData();

    bool m_sound;
    bool m_sline;
    bool m_useJS;
    GameData *m_games[MAX_SAVE - 1];
    //JSDat: JoyRec;

    void save();

private:
    int m_gameNumber;
};

#endif // CONFIGDATA_H
