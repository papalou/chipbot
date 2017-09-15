TARGET = "chipbot_bot"
DESTDIR = .
TEMPLATE = app

QT += core
QT -= gui
CONFIG += thread console c++11
CONFIG -= app_bundle

SOURCES += \
	./src/main.cpp

INCLUDEPATH += .\
                ./src/ \
                ../libcommon/include/

LIBS += ../libcommon/libcommon.a
