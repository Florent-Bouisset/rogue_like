#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "include/champion.h"
#include "include/monster.h"
#include "include/boss.h"
#include "include/monster_creator.h"
#include "include/boss_creator.h"


using namespace std;

int main(){
    srand(time(NULL));


    //TEST
    /*
    Champion guerrier = Champion("Delmak");
    Monster mob1 = Monster();
    Boss boss1 = Boss();

    cout << mob1.getName() <<endl;
    cout << boss1.getName() <<endl;
    //guerrier.fightAMonster(mob1);
    guerrier.fightAMonster(boss1);
    guerrier.takeRewards(boss1);
    guerrier.printInfos();
    */

    Monster* mob2 = MonsterCreator::FactoryMethod(NEKKER);
    Monster* mob3 = MonsterCreator::FactoryMethod(ARAKAS);
    mob2->printHealth();
    mob3->printHealth();

    Boss* boss2 = BossCreator::FactoryMethod(COCATRIX);
    Boss* boss3 = BossCreator::FactoryMethod(DAME_BLANCHE);

    boss2->printHealth();
    boss3->printHealth();



    //FIN TEST
    return 0;
}