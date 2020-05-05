#include "include/dungeon_room_boss.h"
#include "include/boss_creator.h"

#include <iostream>

using namespace std;

DungeonRoomBoss::DungeonRoomBoss()
{
    boss = BossCreator::FactoryMethod();

    string roomTitleString = "Boss";
    string roomAbstractString = "Une salle de boss avec des récompenses rares";

    roomTitle->setText(QString::fromStdString(roomTitleString));
    roomAbstract->setText(QString::fromStdString(roomAbstractString));
}

void DungeonRoomBoss::championInteraction(Champion &champ)
{
}