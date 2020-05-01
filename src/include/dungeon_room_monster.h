#ifndef DUNGEON_ROOM_MONSTER_H
#define DUNGEON_ROOM_MONSTER_H

#include "dungeon_room.h"
#include "monster.h"

class DungeonRoomMonster : public DungeonRoom{
    public:
        DungeonRoomMonster();
        void printRoomDescription();
        void championInteraction(Champion& champ);

    private:
        Monster monster;
};



#endif