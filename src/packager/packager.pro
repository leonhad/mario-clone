TARGET = Packager
TEMPLATE = app
QT += widgets
DESTDIR = ../../bin
win32:RC_FILE = Packager.rc
macx:ICON = Packager.icns
RESOURCES += Packager.qrc
SOURCES += main.cpp \
    packagerwindow.cpp \
    objectproperties.cpp
HEADERS += packagerwindow.h \
    objectproperties.h
FORMS += packagerwindow.ui \
    objectproperties.ui
