QT -= core \
    gui
TARGET = io
TEMPLATE = lib
DESTDIR = ../../../lib
DLLDESTDIR = ../../../bin
DEFINES += IO_LIBRARY
SOURCES += buffer.cpp \
    bytebuffer.cpp \
    bits.cpp \
    ioexception.cpp
HEADERS += buffer.h \
    bytebuffer.h \
    bits.h \
    ioexception.h
QMAKE_CXXFLAGS_RELEASE += -fno-inline
VERSION = 1.0
