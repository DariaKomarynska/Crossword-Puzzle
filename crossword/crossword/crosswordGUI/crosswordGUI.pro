QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../Board.cpp \
    ../Crossword.cpp \
    ../Dictionary.cpp \
    ../Field.cpp \
    ../Game.cpp \
    ../Player.cpp \
    ../crosswordErrors.cpp \
    addcrosswordwindow.cpp \
    addplayer.cpp \
    gamewindow.cpp \
    main.cpp \
    menuwindow.cpp \
    scoreboardwindow.cpp \
    selectcrossword.cpp \
    selectplayer.cpp \
    startwindow.cpp

HEADERS += \
    ../Board.h \
    ../Crossword.h \
    ../Dictionary.h \
    ../Field.h \
    ../Game.h \
    ../Player.h \
    addcrosswordwindow.h \
    addplayer.h \
    gamewindow.h \
    menuwindow.h \
    scoreboardwindow.h \
    selectcrossword.h \
    selectplayer.h \
    startwindow.h

FORMS += \
    addcrosswordwindow.ui \
    addplayer.ui \
    gamewindow.ui \
    menuwindow.ui \
    scoreboardwindow.ui \
    selectcrossword.ui \
    selectplayer.ui \
    startwindow.ui

TRANSLATIONS += \
    crosswordGUI_en_150.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../build-crosswordGUI-Desktop_Qt_6_1_0_MinGW_64_bit-Debug/userData.csv
