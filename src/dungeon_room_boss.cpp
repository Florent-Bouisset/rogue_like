#include "include/dungeon_room_boss.h"
#include "include/boss_creator.h"

#include <iostream>

using namespace std;

DungeonRoomBoss::DungeonRoomBoss(){
    boss = BossCreator::FactoryMethod();

}

string DungeonRoomBoss::roomAbstract(){
    return "Une salle de boss avec des recompenses rares";
}



void DungeonRoomBoss::printRoomDescription(){
    cout << "Vous entrez dans une salle .. le boss " << boss.getName() << " apparait ! " << endl;

}

void DungeonRoomBoss::championInteraction(Champion& champ){
    printRoomDescription();
    champ.fightAMonster(boss);
    if(!boss.isAlive()){
        champ.takeRewards(boss);
    }
}