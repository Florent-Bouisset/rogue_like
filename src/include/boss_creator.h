#include "boss.h"
#include "enum.h"

enum BossType{COCATRIX, DAME_BLANCHE, GRIFFON_ROYAL,
    KATAKAN, WYVERN_ROYAL, FOENARD, LOUP_GAROU};

class BossCreator{
    public:
        virtual ~BossCreator(){};
        static Boss* FactoryMethod(BossType type);

    private:
        static std::map<BossType, StatsBoss> predefinedStats;
};