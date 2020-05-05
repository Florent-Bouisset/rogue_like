#ifndef DUNGEON_ROOM_BOSS_H
#define DUNGEON_ROOM_BOSS_H

#include "dungeon_room.h"
#include "boss.h"

class DungeonRoomBoss : public DungeonRoom
{
public:
    DungeonRoomBoss();
    void championInteraction(Champion &champ);

private:
    Boss boss;
};

#endif