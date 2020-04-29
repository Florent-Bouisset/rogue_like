#include "include/boss.h"
#include <vector>
#include <string>
#include "include/stats.h"

using namespace std;

Boss::Boss(){
    this->giveARandomType();
    this->giveStatsFromMap();
}

map<BossType, StatsBoss> Boss::predefinedStats = {
    //{KEY, {string name, int damage, int HP, int HPmax, int goldReward}}
    {COCATRIX, {"Cocatrix", 15, 90, 90, 35, RelicType::ALTERE}},
    {DAME_BLANCHE, {"Dame Blanche", 18, 85, 85, 40, RelicType::ARME_EMPOISONNEE}},
    {GRIFFON_ROYAL, {"Griffon Royal", 22, 75, 75, 48, RelicType::ANANAS}},
    {KATAKAN, {"Katakan", 13, 110, 110, 38, RelicType::VIN_ROUGE}},
    {WYVERN_ROYAL, {"Wyvern Royal", 17, 88, 88, 35, RelicType::ARME_EMPOISONNEE}},
    {FOENARD, {"Foenard", 14, 90, 90, 28, RelicType::JUS_CITRON}},
    {LOUP_GAROU, {"Loup Garou", 16, 80, 80, 33, RelicType::ANANAS}}
};

void Boss::giveARandomType(){
    bossType = BossType(rand() % Boss::predefinedStats.size());
}


// search in the map and get the stats corresponding to the Monster type
void Boss::giveStatsFromMap(){
    if(predefinedStats.find(bossType) != predefinedStats.end()){
        StatsBoss s = predefinedStats.find(bossType)->second;

        //inherited attributes:
        setName(s.name);
        changeDamage(s.damage, ActionType::SET);
        changeMaxHP(s.maxHP, ActionType::SET);
        changeHP(s.HP, ActionType::SET);
        goldReward = s.goldReward;

        //own attribute
        relicReward = s.relicReward;

    }
    else{
        //inherited attributes:
        setName("Monstre inconnu");
        changeDamage(5, ActionType::SET);
        changeMaxHP(30, ActionType::SET);
        changeHP(30, ActionType::SET);
        goldReward = 10;

        //own attribute

        relicReward = RelicType::ALTERE;
    }
}


Relic Boss::getRelicReward(){
    return relicReward;
}
