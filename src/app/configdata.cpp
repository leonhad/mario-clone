#include "configdata.h"
#include <QFile>

ConfigData::ConfigData()
{
    int loop;

    QFile file(configFileName);

    //if new
    if (!file.exists()) {
        for (loop = 0; loop < MAX_SAVE; loop++) {
            m_games[loop] = new GameData;
        }
        m_sline = true;
        m_sound = true;
        m_useJS = false;
    } else {
        if (!file.open(QFile::ReadOnly | QFile::Text)) {
            // erro;
        }
    }
    m_gameNumber = -1;
}

ConfigData::~ConfigData()
{
    save();

    int loop;

    for (loop = 0; loop < MAX_SAVE; loop++) {
        if (m_games[loop]) {
            delete m_games[loop];
        }
    }
}

void ConfigData::save()
{

}
