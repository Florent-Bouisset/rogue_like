QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/fighter_widget.cpp \
    src/main.cpp \
    src/fighter.cpp \
    src/monster.cpp \
    src/champion.cpp \
    src/monster_creator.cpp \
    src/boss.cpp \
    src/boss_creator.cpp \
    src/item.cpp \
    src/potion.cpp \
    src/relic.cpp \
    src/article.cpp \
    src/marchand.cpp \
    src/combat_window.cpp \
    src/reward_window.cpp \
    src/main_window.cpp \
    src/level_selection_window.cpp \
    src/dungeon_room.cpp \
    src/dungeon_room_monster.cpp \
    src/dungeon_room_boss.cpp \


HEADERS += \
    src/include/fighter_widget.h \
    src/include/fighter.h \
    src/include/monster.h \
    src/include/champion.h \
    src/include/monster_creator.h \
    src/include/boss.h \
    src/include/boss_creator.h \
    src/include/item.h \
    src/include/potion.h \
    src/include/relic.h \
    src/include/article.h \
    src/include/marchand.h \
    src/include/combat_window.h \
    src/include/reward_window.h \
    src/include/main_window.h \
    src/include/level_selection_window.h \
    src/include/dungeon_room.h \
    src/include/dungeon_room_monster.h \
    src/include/dungeon_room_boss.h

OBJECTS_DIR += obj/

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
