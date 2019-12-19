TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG += qt

#TARGET = dungeon_crawler

HEADERS += \
    game.h \
    menuinterface.h \
    testingsettings.h \
    testing.h \
    character.h \
    dungeon.h \
    room.h \
    wall.h \
    door.h \
    basicdungeon.h \
    magicaldungeon.h \
    commondungeon.h \
    creatures.h \
    items.h

SOURCES += \
    main.cpp \
    game.cpp \
    menuinterface.cpp \
    testing.cpp \
    character.cpp \
    dungeon.cpp \
    room.cpp \
    wall.cpp \
    door.cpp \
    basicdungeon.cpp \
    magicaldungeon.cpp \
    commondungeon.cpp \
    creatures.cpp \
    items.cpp

INCLUDEPATH +=

#DEFINES = 

DISTFILES += \
    README.md \
    input_script.txt

