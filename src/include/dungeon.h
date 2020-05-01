#ifndef DUNGEON_H
#define DUNGEON_H

#include "champion.h"
#include <vector>
#include "dungeon_room.h"


class Dungeon{
    public:

        Dungeon();
        void play();



    private:
        int chooseNextRoom();
        void generateNextRooms();
        int roomAchieved;
        int nbrOfRoomByLevel;
        std::vector<std::unique_ptr<DungeonRoom>> roomPossibilites;
        Champion champion;



};



#endif