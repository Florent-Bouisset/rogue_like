#include "include/monster.h"
#include <stdlib.h>                     //rand()
#include <map>


using namespace std;


Monster::Monster(){
    this->changeMaxHP(50, ActionType::ADDITION);
    this->changeHP(50, ActionType::ADDITION);
    this->goldReward = 12;
    this->giveARandomType();
    this->giveANameFromMap();
}

map<MonsterType, std::string> Monster::names = {
    {NEKKER, "Nekker"},
    {ARAKAS, "Arakas"},
    {LOUP, "Loup"},
    {CHIEN, "Chien"},
    {NOYEUR, "Noyeur"},
    {HARPIE, "Ours"},
    {SIRENE, "Sirene"}
};


// search in the map and get the name corresponding to the Monster type
void Monster::giveANameFromMap(){
    if(names.find(monsterType) != names.end()){
        setName(names.find(monsterType)->second);
    }
    else{
        setName("Monstre inconnu");
    }
}

/**
 * give a type to the monster, could be a wolf, or a Spider, etc...
 * the number of type depend on the map size called names
 * */

void Monster::giveARandomType(){
    monsterType = MonsterType(rand() % names.size());
}



int Monster::getGoldReward(){
    return goldReward;
}