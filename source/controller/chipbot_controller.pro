TARGET = "chipbot_controller"
TEMPLATE = app
DESTDIR = .

QT += gui core widgets
CONFIG += qt thread debug

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        src/main.cpp \
        src/forms/main_window.cpp \
        src/forms/dialog_config_menu.cpp

HEADERS += \
        src/forms/main_window.h \
        src/forms/dialog_config_menu.h

FORMS += \
        forms/main_window.ui \
        forms/dialog_config_menu.ui

INCLUDEPATH += .\
               ./src/\
               ./src/forms\
               ../libcommon/include/

LIBS += ../libcommon/libcommon.a

