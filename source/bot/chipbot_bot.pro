TARGET = "chipbot_bot"
DESTDIR = .
TEMPLATE = app

QT += core network
QT -= gui
CONFIG += thread console c++11
CONFIG -= app_bundle

SOURCES += \
          ./src/main.cpp\
          ./src/server.cpp

HEADERS += \
           ./src/server.h

INCLUDEPATH += .\
           ./src/ \
           ../libcommon/include/ \
           ../common/

LIBS += ../libcommon/libcommon.a
