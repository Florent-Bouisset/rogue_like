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


Boss* BossCreator::FactoryMethod(BossType type){
    Boss* b = new Boss();
    if(predefinedStats.find(type) != predefinedStats.end()){
        BossStats s = predefinedStats.find(type)->second;

        b->setName(s.name);
        b->changeDamage(s.damage, ActionType::SET);
        b->changeMaxHP(s.maxHP, ActionType::SET);
        b->changeHP(s.HP, ActionType::SET);
        b->goldReward = s.goldReward;
        b->relicReward = s.relicReward;
    }
    else{
        b->setName("Monstre inconnu");
        b->changeDamage(5, ActionType::SET);
        b->changeMaxHP(30, ActionType::SET);
        b->changeHP(30, ActionType::SET);
        b->goldReward = 10;
        b->relicReward = RelicType::ALTERE;
    }

    return b;
}