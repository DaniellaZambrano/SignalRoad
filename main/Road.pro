#-------------------------------------------------
#
# Project created by QtCreator 2018-05-15T21:13:54
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Road
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ../includ \

SOURCES += main.cpp\
    ../src/Enemy.cpp \
    ../src/Health.cpp \
    ../src/MainWindow.cpp \
    ../src/Player.cpp \
    ../src/BackGround.cpp \
    ../src/Upgrades.cpp \
    ../src/Score.cpp \
    ../src/Buttons.cpp \
    ../src/Sensor.cpp


HEADERS  += \
    ../includ/Enemy.H \
    ../includ/Health.H \
    ../includ/MainWindow.H \
    ../includ/Player.H \
    ../includ/BackGround.H \
    ../includ/Upgrades.H \
    ../includ/Score.H \
    ../includ/Buttons.H \
    ../includ/Sensor.H


RESOURCES += \
    ../media/road.qrc
