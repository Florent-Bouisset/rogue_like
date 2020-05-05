#include "include/dungeon_room_monster.h"

#include "include/monster_creator.h"
#include <iostream>

using namespace std;

DungeonRoomMonster::DungeonRoomMonster()
{
    monster = MonsterCreator::FactoryMethod();

    string roomTitleString = "Monstre commun";
    string roomAbstractString = "Une salle de monstre avec des petites recompenses";

    roomTitle->setText(QString::fromStdString(roomTitleString));
    roomAbstract->setText(QString::fromStdString(roomAbstractString));
}

void DungeonRoomMonster::championInteraction(Champion &champ)
{
}