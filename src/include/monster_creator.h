#include "monster.h"

enum MonsterType{NEKKER, ARAKAS, LOUP, CHIEN, NOYEUR, HARPIE,
    OURS, SIRENE};

struct Stats
{
    public:
        std::string name;
        int damage;
        int HP;
        int maxHP;
        int goldReward;
};

class MonsterCreator{
    public:
        virtual ~MonsterCreator(){};
        static Monster* FactoryMethod(MonsterType type);

    private:
        static std::map<MonsterType, Stats> predefinedStats;
};

