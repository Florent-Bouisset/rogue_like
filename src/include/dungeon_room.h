#ifndef DUNGEON_ROOM_H
#define DUNGEON_ROOM_H

#include "champion.h"
#include <memory>
#include <QWidget>
#include <QLabel>
#include <QPushButton>

enum RoomType
{
    BOSS_ROOM,
    MONSTER_ROOM,
    ROOM_MAX_VALUE
};

class DungeonRoom : public QWidget
{
public:
    DungeonRoom();
    DungeonRoom(RoomType type, std::string title, std::string abstract);

    //Methods
    void layoutSetUp();

    static DungeonRoom *createRoom(RoomType type);
    static DungeonRoom *createRoom();

    //Attributes
    RoomType roomType;
    QLabel *roomTitle;
    QLabel *roomAbstract;
    QPushButton *chooseRoom;
};

#endif