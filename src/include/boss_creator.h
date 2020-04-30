#include "boss.h"


enum BossType{COCATRIX, DAME_BLANCHE, GRIFFON_ROYAL,
    KATAKAN, WYVERN_ROYAL, FOENARD, LOUP_GAROU, BOSS_MAX_VALUE};


struct BossStats
{
    public:
        std::string name;
        int damage;
        int HP;
        int maxHP;
        int goldReward;
        RelicType relicReward;
};


class BossCreator{
    public:
        virtual ~BossCreator(){};
        static Boss* FactoryMethod(BossType type);
        static Boss* FactoryMethod();

    private:

        static std::map<BossType, BossStats> predefinedStats;
        static BossType getARandomBossType();

};