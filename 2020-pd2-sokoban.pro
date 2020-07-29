#-------------------------------------------------
#
# Project created by QtCreator 2020-03-31T15:43:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2020-pd2-sokoban
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    player.cpp \
    level1.cpp \
    level2.cpp \
    chooselevels.cpp \
    rule.cpp \
    pass1.cpp \
    pass2.cpp

HEADERS += \
        mainwindow.h \
    player.h \
    level1.h \
    level2.h \
    chooselevels.h \
    rule.h \
    pass1.h \
    pass2.h

FORMS += \
        mainwindow.ui \
    level1.ui \
    level2.ui \
    chooselevels.ui \
    pass1.ui \
    pass2.ui \
    rule.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
