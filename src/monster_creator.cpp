#include "include/monster_creator.h"

#include <map>

using namespace std;

map<MonsterType, Stats> MonsterCreator::predefinedStats = {
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

Monster MonsterCreator::FactoryMethod(MonsterType type){
    Monster monster = Monster();
    if(predefinedStats.find(type) != predefinedStats.end()){
        Stats s = predefinedStats.find(type)->second;

        monster.setName(s.name);
        monster.changeDamage(s.damage, ActionType::SET);
        monster.changeMaxHP(s.maxHP, ActionType::SET);
        monster.changeHP(s.HP, ActionType::SET);
        monster.goldReward = s.goldReward;
    }
    else{
        monster.setName("Monstre inconnu");
        monster.changeDamage(5, ActionType::SET);
        monster.changeMaxHP(30, ActionType::SET);
        monster.changeHP(30, ActionType::SET);
        monster.goldReward = 10;
    }
    return monster;
}

Monster MonsterCreator::FactoryMethod(){
    MonsterType type = getARandomMonsterType();
    return FactoryMethod(type);
}



MonsterType MonsterCreator::getARandomMonsterType(){
    return static_cast<enum MonsterType> (rand()%MONSTER_MAX_VALUE);

}