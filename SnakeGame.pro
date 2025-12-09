QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SnakeGame
TEMPLATE = app

SOURCES += main.cpp \
    mainwindow.cpp \
    snake.cpp \
    gameboard.cpp

HEADERS  += mainwindow.h \
    snake.h \
    gameboard.h

FORMS    += mainwindow.ui