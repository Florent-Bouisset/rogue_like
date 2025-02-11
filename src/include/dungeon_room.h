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
    Q_OBJECT
public:
    DungeonRoom();
    DungeonRoom(RoomType type, std::string title, std::string abstract);

    //Methods
    void layoutSetUp();

    static DungeonRoom *createRoom(RoomType type);
    static DungeonRoom *createRoom();

public slots:
    void emitSignal();

signals:
    void roomSelected(RoomType selected);

private:
    //Attributes
    RoomType roomType;
    QLabel *roomTitle;
    QLabel *roomAbstract;
    QPushButton *chooseRoom;
};

#endif