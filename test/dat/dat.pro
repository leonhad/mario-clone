QT -= gui core
TEMPLATE = app
TARGET = dattest
DESTDIR=../../bin
LIBS += -L../../lib

mac: {
    CONFIG -= app_bundle
    QMAKE_LFLAGS += -F../../lib
    LIBS += -framework dat
} else {
    INCLUDEPATH = ../../src/dat/dat
}
unix: {
    LIBS += -ldat
}
win32: {
    LIBS += -ldat1
}

SOURCES = test.cpp

QMAKE_CXXFLAGS_RELEASE += -fno-inline

QMAKE_RPATHDIR += ../../lib
