#include "include/boss_creator.h"

#include <map>

using namespace std;


map<BossType, BossStats> BossCreator::predefinedStats = {
    //{KEY, {string name, int damage, int HP, int HPmax, int goldReward}}
    {COCATRIX, {"Cocatrix", 15, 90, 90, 35, RelicType::ALTERE}},
    {DAME_BLANCHE, {"Dame Blanche", 18, 85, 85, 40, RelicType::ARME_EMPOISONNEE}},
    {GRIFFON_ROYAL, {"Griffon Royal", 22, 75, 75, 48, RelicType::ANANAS}},
    {KATAKAN, {"Katakan", 13, 110, 110, 38, RelicType::VIN_ROUGE}},
    {WYVERN_ROYAL, {"Wyvern Royal", 17, 88, 88, 35, RelicType::ARME_EMPOISONNEE}},
    {FOENARD, {"Foenard", 14, 90, 90, 28, RelicType::JUS_CITRON}},
    {LOUP_GAROU, {"Loup Garou", 16, 80, 80, 33, RelicType::ANANAS}}
};


Boss BossCreator::FactoryMethod(BossType type){
    Boss boss = Boss();
    if(predefinedStats.find(type) != predefinedStats.end()){
        BossStats s = predefinedStats.find(type)->second;

        boss.setName(s.name);
        boss.changeDamage(s.damage, ActionType::SET);
        boss.changeMaxHP(s.maxHP, ActionType::SET);
        boss.changeHP(s.HP, ActionType::SET);
        boss.goldReward = s.goldReward;
        boss.relicReward = s.relicReward;
    }
    else{
        boss.setName("Monstre inconnu");
        boss.changeDamage(5, ActionType::SET);
        boss.changeMaxHP(30, ActionType::SET);
        boss.changeHP(30, ActionType::SET);
        boss.goldReward = 10;
        boss.relicReward = RelicType::ALTERE;
    }
    return boss;
}


Boss BossCreator::FactoryMethod(){
    BossType type = getARandomBossType();
    return FactoryMethod(type);
}


BossType BossCreator::getARandomBossType(){
    return static_cast<enum BossType>(rand()% BOSS_MAX_VALUE);
}

