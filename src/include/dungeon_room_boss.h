#include "dungeon_room.h"
#include "boss.h"

class DungeonRoomBoss : public DungeonRoom{
    public:
        DungeonRoomBoss();
        std::string roomAbstract();
        void printRoomDescription();
        void championInteraction(Champion& champ);

    private:
        Boss boss;
};