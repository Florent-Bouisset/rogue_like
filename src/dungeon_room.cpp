
#include "include/dungeon_room.h"

#include <memory>
#include "include/dungeon_room_boss.h"
#include "include/dungeon_room_monster.h"
#include <QLabel>
#include <QVBoxLayout>

using namespace std;

DungeonRoom::DungeonRoom()
{
    roomTitle = new QLabel();
    roomTitle->setAlignment(Qt::AlignCenter);
    QFont font = roomTitle->font();
    font.setPointSize(18);
    roomTitle->setFont(font);
    roomTitle->setWordWrap(true);

    roomAbstract = new QLabel();
    roomAbstract->setAlignment(Qt::AlignCenter);
    roomAbstract->setFont(font);
    roomAbstract->setWordWrap(true);

    chooseRoom = new QPushButton();
    chooseRoom->setText("Choisir cette salle");
    chooseRoom->setFont(font);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(roomTitle);
    layout->addWidget(roomAbstract);
    layout->addWidget(chooseRoom);
    setLayout(layout);
    setMaximumWidth(300);
}

void DungeonRoom::setUp()
{
}

DungeonRoom *DungeonRoom::createRoom(RoomType type)
{
    switch (type)
    {
    case RoomType::BOSS_ROOM:
        return new DungeonRoomBoss();

    case RoomType::MONSTER_ROOM:
        return new DungeonRoomMonster();

    default:
        return new DungeonRoomMonster();
    }
}

DungeonRoom *DungeonRoom::createRoom()
{
    RoomType randomType = static_cast<enum RoomType>(rand() % ROOM_MAX_VALUE);
    return createRoom(randomType);
}
