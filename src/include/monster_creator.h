#include "monster.h"

enum MonsterType{NEKKER, ARAKAS, LOUP, CHIEN, NOYEUR, HARPIE,
    OURS, SIRENE};

class MonsterCreator{
    public:
        virtual ~MonsterCreator(){};
        static Monster* FactoryMethod(MonsterType type);

    private:
        static std::map<MonsterType, Stats> predefinedStats;
};

