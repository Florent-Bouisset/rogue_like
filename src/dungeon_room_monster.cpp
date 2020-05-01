#include "include/dungeon_room_monster.h"

#include "include/monster_creator.h"
#include <iostream>

using namespace std;


DungeonRoomMonster::DungeonRoomMonster(){
    monster = MonsterCreator::FactoryMethod();
}

void DungeonRoomMonster::printRoomDescription(){
    cout << "Vous entrez dans une salle banale .. un "<< monster.getName() << " apparait !" << endl;
}

void DungeonRoomMonster::championInteraction(Champion& champ){
    printRoomDescription();
    champ.fightAMonster(monster);
    if(!monster.isAlive()){
        champ.takeRewards(monster);
    }
}