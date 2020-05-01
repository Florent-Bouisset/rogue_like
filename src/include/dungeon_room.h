#ifndef DUNGEON_ROOM_H
#define DUNGEON_ROOM_H

#include "champion.h"

enum RoomType{BOSS_ROOM, MOSNTER_ROOM, ROOM_MAX_VALUE};

class DungeonRoom{
    public:
        DungeonRoom();
        virtual std::string roomAbstract() = 0;
        virtual void printRoomDescription() = 0;
        virtual void championInteraction(Champion& champ) = 0;
        static DungeonRoom* createRoom(RoomType type);
        static DungeonRoom* createRoom();

};


#endif