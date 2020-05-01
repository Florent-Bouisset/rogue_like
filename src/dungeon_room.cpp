
#include "include/dungeon_room.h"

#include <memory>
#include "include/dungeon_room_boss.h"
#include "include/dungeon_room_monster.h"

using namespace std;

DungeonRoom::DungeonRoom(){
}

unique_ptr<DungeonRoom> DungeonRoom::createRoom(RoomType type){
    switch (type)
    {
    case RoomType::BOSS_ROOM:
        return  make_unique<DungeonRoomBoss>();

    case RoomType::MONSTER_ROOM:
        return make_unique<DungeonRoomMonster>();

    default:
        return make_unique<DungeonRoomMonster>();
    }
}


unique_ptr<DungeonRoom> DungeonRoom::createRoom(){
    RoomType randomType = static_cast<enum RoomType> (rand()%ROOM_MAX_VALUE);
    return createRoom(randomType);
}


