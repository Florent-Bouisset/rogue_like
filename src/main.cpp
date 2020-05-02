#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "include/champion.h"
#include "include/monster.h"
#include "include/boss.h"
#include "include/monster_creator.h"
#include "include/boss_creator.h"
#include "include/dungeon.h"
#include "include/marchand.h"

#include "include/fightergui.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    srand(static_cast<unsigned int>(time(nullptr)));

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
    /*

    //TEST 2
    Monster mob2 = MonsterCreator::FactoryMethod(NEKKER);
    Monster mob3 = MonsterCreator::FactoryMethod(ARAKAS);
    mob2.printHealth();
    mob3.printHealth();

    Boss boss2 = BossCreator::FactoryMethod(COCATRIX);
    Boss boss3 = BossCreator::FactoryMethod(); // Random factory

    boss2.printHealth();
    boss3.printHealth();
    */
    //FIN TEST

    //Dungeon myDungeon = Dungeon();
    //myDungeon.play();

    //TEST 3

    /*
    Champion champ = Champion("Del");
    champ.changeHP(50, SOUSTRACT);

    champ.printInfos();

    Merchant m = Merchant();
    m.init();

    Article article = Article::createArticle();
    champ.buyArticle(article);

    champ.printInfos();
    */
    Monster mob1 = MonsterCreator::FactoryMethod();
    Boss boss1 = BossCreator::FactoryMethod();
    Champion champ = Champion("Delmak");

    QApplication a(argc, argv);
    FighterGUI figtherWidget;
    figtherWidget.printFighter(champ);
    figtherWidget.show();
    return a.exec();
}