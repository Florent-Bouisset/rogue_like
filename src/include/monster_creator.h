#include "monster.h"
#include <map>

enum MonsterType
{
    NEKKER,
    ARAKAS,
    LOUP,
    GOULE,
    NOYEUR,
    HARPIE,
    OURS,
    SIRENE,
    MONSTER_MAX_VALUE
};

struct Stats
{
public:
    std::string name;
    std::string illustrationPath;
    int damage;
    int HP;
    int maxHP;
    int goldReward;
};

class MonsterCreator
{
public:
    virtual ~MonsterCreator(){};
    static Monster FactoryMethod(MonsterType type);
    static Monster FactoryMethod();

private:
    static std::map<MonsterType, Stats> predefinedStats;
    static MonsterType getARandomMonsterType();
};
