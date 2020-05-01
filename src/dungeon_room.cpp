
#include "include/dungeon_room.h"


#include "include/dungeon_room_boss.h"
#include "include/dungeon_room_monster.h"

using namespace std;

DungeonRoom::DungeonRoom(){
}

DungeonRoom* DungeonRoom::createRoom(RoomType type){
    switch (type)
    {
    case RoomType::BOSS_ROOM:
        return new DungeonRoomBoss();

    case RoomType::MOSNTER_ROOM:
        return new DungeonRoomMonster();

    default:
        return new DungeonRoomMonster();
    }
}


DungeonRoom* DungeonRoom::createRoom(){
    RoomType randomType = static_cast<enum RoomType> (rand()%ROOM_MAX_VALUE);
    return createRoom(randomType);
}


