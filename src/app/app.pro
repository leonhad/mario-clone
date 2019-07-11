TARGET = Mario
QT += widgets
TEMPLATE = app
DESTDIR = ../../bin
SOURCES += main.cpp \
    mainwindow.cpp \
    buffers.cpp \
    gamedata.cpp \
    configdata.cpp \
    constants.cpp \
    game.cpp
HEADERS += mainwindow.h \
    buffers.h \
    constants.h \
    gamedata.h \
    configdata.h \
    game.h
FORMS += mainwindow.ui
TRANSLATIONS = Mario_pt.ts \
    Mario_pt_BR.ts \
    Mario_en.ts
RESOURCES += Mario.qrc
win32::RC_FILE = Mario.rc
macx::ICON = Mario.icns
