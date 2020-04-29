#include "include/monster.h"
#include <stdlib.h>                     //rand()
#include <map>


using namespace std;


Monster::Monster(){
    this->giveARandomType();
    this->giveStatsFromMap();
}

map<MonsterType, Stats> Monster::predefinedStats = {
    //{KEY, {string name, int damage, int HP, int HPmax, int goldReward}}
    {NEKKER, {"Nekker", 5, 45, 45, 12}},
    {ARAKAS, {"Arakas", 8, 30, 30, 10}},
    {LOUP, {"Loup", 6, 42, 42, 10}},
    {CHIEN, {"Chien", 4, 35, 35, 8}},
    {NOYEUR, {"Noyeur", 8, 42, 42, 15}},
    {HARPIE, {"Harpie", 7, 45, 45, 12}},
    {OURS, {"Ours", 10, 45, 45, 20}},
    {SIRENE,{"Sirene", 6, 38, 38, 11}}
};

// search in the map and get the stats corresponding to the Monster type
void Monster::giveStatsFromMap(){
    if(predefinedStats.find(monsterType) != predefinedStats.end()){
        Stats s = predefinedStats.find(monsterType)->second;

        //inherited attributes:
        setName(s.name);
        changeDamage(s.damage, ActionType::SET);
        changeMaxHP(s.maxHP, ActionType::SET);
        changeHP(s.HP, ActionType::SET);

        //own attribute
        goldReward = s.goldReward;
    }
    else{
        //inherited attributes:
        setName("Monstre inconnu");
        changeDamage(5, ActionType::SET);
        changeMaxHP(30, ActionType::SET);
        changeHP(30, ActionType::SET);

        //own attribute
        goldReward = 10;
    }
}


/**
 * give a type to the monster, could be a wolf, or a Spider, etc...
 * the number of type depend on the map size called predefinedStats
 * */

void Monster::giveARandomType(){
    monsterType = MonsterType(rand() % predefinedStats.size());
}

int Monster::getGoldReward(){
    return goldReward;
}