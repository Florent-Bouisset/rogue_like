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
#include "include/combat_window.h"
#include "include/fighter_widget.h"
#include "include/reward_window.h"
#include "include/main_window.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    srand(static_cast<unsigned int>(time(nullptr)));

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

    /* TEST 5
    Monster mob1 = MonsterCreator::FactoryMethod();
    Boss boss1 = BossCreator::FactoryMethod();
    Champion champ = Champion();

    //Smart pointers
    shared_ptr<Monster> b1 = make_shared<Boss>(boss1);
    shared_ptr<Champion> ch1 = make_shared<Champion>(champ);

    QApplication a(argc, argv);

    CombatWindow combat;

    combat.setUp();
    combat.loadDefender(b1);
    combat.loadAttacker(ch1);

    combat.show();

    */
    /* TEST 6
    Boss b = BossCreator::FactoryMethod();
    shared_ptr<Monster> b1 = make_shared<Boss>(b);

    Monster m = MonsterCreator::FactoryMethod();
    shared_ptr<Monster> m1 = make_shared<Monster>(m);

    QApplication a(argc, argv);
    RewardWindow reward;
    reward.printRewards(b1);
    reward.show();
    */
    /* TEST 7
    QApplication a(argc, argv);
    Monster mob1 = MonsterCreator::FactoryMethod();
    Boss boss1 = BossCreator::FactoryMethod();
    Champion champ = Champion();

    shared_ptr<Monster> b1 = make_shared<Boss>(boss1);
    shared_ptr<Champion> ch1 = make_shared<Champion>(champ);
    CombatWindow combat;

    combat.setUp();
    combat.loadDefender(b1);
    combat.loadAttacker(ch1);

    combat.show();

    */

    //TEST 8
    QApplication a(argc, argv);
    MainWindow mainwindow;
    mainwindow.show();
    mainwindow.play();

    return a.exec();
}