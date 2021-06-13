TARGET = MapEditor
TEMPLATE = app
QT += widgets
DESTDIR = ../../bin
win32:RC_FILE = MapEditor.rc
macx:ICON = MapEditor.icns
RESOURCES += MapEditor.qrc
HEADERS += mapeditorwindow.h
SOURCES += mapeditorwindow.cpp \
    main.cpp
FORMS += mapeditorwindow.ui
