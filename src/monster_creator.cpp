#include "include/monster_creator.h"

#include <map>

using namespace std;

map<MonsterType, Stats> MonsterCreator::predefinedStats = {
    //{KEY, {string name, int damage, int HP, int HPmax, int goldReward}}
    {NEKKER, {"Nekker", "image/fighter/monster/nekker.png", 5, 45, 45, 12}},
    {ARAKAS, {"Endrega", "image/fighter/monster/endrega.png", 8, 30, 30, 10}},
    {LOUP, {"Loup", "image/fighter/monster/wolf.png", 6, 42, 42, 10}},
    {GOULE, {"Goule", "image/fighter/monster/ghoul.png", 6, 35, 35, 10}},
    {NOYEUR, {"Noyeur", "image/fighter/monster/drowner.png", 8, 42, 42, 15}},
    {HARPIE, {"Harpie", "image/fighter/monster/harpy.png", 7, 45, 45, 12}},
    {OURS, {"Ours", "image/fighter/monster/bear.png", 10, 45, 45, 20}},
    {SIRENE, {"Sirene", "image/fighter/monster/siren.png", 6, 38, 38, 11}}};

Monster MonsterCreator::FactoryMethod(MonsterType type)
{
    Monster monster = Monster();
    if (predefinedStats.find(type) != predefinedStats.end())
    {
        Stats s = predefinedStats.find(type)->second;

        monster.setName(s.name);
        monster.changeDamage(s.damage, ActionType::SET);
        monster.changeMaxHP(s.maxHP, ActionType::SET);
        monster.changeHP(s.HP, ActionType::SET);
        monster.goldReward = s.goldReward;
        monster.illustrationPath = s.illustrationPath;
    }
    else
    {
        monster.setName("Monstre inconnu");
        monster.changeDamage(5, ActionType::SET);
        monster.changeMaxHP(30, ActionType::SET);
        monster.changeHP(30, ActionType::SET);
        monster.goldReward = 10;
        monster.illustrationPath = "image/fighter/monster/neker.png";
    }
    return monster;
}

Monster MonsterCreator::FactoryMethod()
{
    MonsterType type = getARandomMonsterType();
    return FactoryMethod(type);
}

MonsterType MonsterCreator::getARandomMonsterType()
{
    return static_cast<enum MonsterType>(rand() % MONSTER_MAX_VALUE);
}