QT -= gui core
TARGET = dat
TEMPLATE = lib
DESTDIR = ../../../lib
DLLDESTDIR = ../../../bin
DEFINES += DAT_LIBRARY

SOURCES += crc.cpp \
    #dat.cpp \
    obj.cpp

HEADERS += crc.h \
    #dat.h \
    obj.h

QMAKE_CXXFLAGS_RELEASE += -fno-inline
VERSION = 1.0

win32: {
    RC_FILE = dat_resource.rc
}
mac: { 
    CONFIG += lib_bundle
    FRAMEWORK_HEADERS.version = Versions
    FRAMEWORK_HEADERS.files = crc.h  dat.h  obj.h
    FRAMEWORK_HEADERS.path = Headers
    QMAKE_BUNDLE_DATA += FRAMEWORK_HEADERS
}
OTHER_FILES += file_format.txt
