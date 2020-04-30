#include "boss.h"

enum BossType{COCATRIX, DAME_BLANCHE, GRIFFON_ROYAL,
    KATAKAN, WYVERN_ROYAL, FOENARD, LOUP_GAROU};

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

    private:
        static std::map<BossType, BossStats> predefinedStats;
};