#include "monster.h"
#include <map>

enum MonsterType{NEKKER, ARAKAS, LOUP, CHIEN, NOYEUR, HARPIE,
    OURS, SIRENE, MONSTER_MAX_VALUE};

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
        static Monster FactoryMethod(MonsterType type);
        static Monster FactoryMethod();

    private:
        static std::map<MonsterType, Stats> predefinedStats;
        static MonsterType getARandomMonsterType();
};

