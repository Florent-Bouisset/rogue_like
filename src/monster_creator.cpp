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

Monster* MonsterCreator::FactoryMethod(MonsterType type){
    Monster* m = new Monster();
    if(predefinedStats.find(type) != predefinedStats.end()){
        Stats s = predefinedStats.find(type)->second;

        m->setName(s.name);
        m->changeDamage(s.damage, ActionType::SET);
        m->changeMaxHP(s.maxHP, ActionType::SET);
        m->changeHP(s.HP, ActionType::SET);
        m->goldReward = s.goldReward;
    }
    else{
        m->setName("Monstre inconnu");
        m->changeDamage(5, ActionType::SET);
        m->changeMaxHP(30, ActionType::SET);
        m->changeHP(30, ActionType::SET);
        m->goldReward = 10;
    }

    return m;
}