#include "include/main_window.h"

#include "include/monster_creator.h"
#include "include/boss_creator.h"
#include "include/champion.h"

using namespace std;

MainWindow::MainWindow()
{
    setUp();
}

void MainWindow::setUp()
{
    combatWindow = new CombatWindow();
    rewardWindow = new RewardWindow();
    combatWindow->setUp();
    rewardWindow->setUp();
    addWidget(combatWindow);
    addWidget(rewardWindow);

    connect(combatWindow->rewardsButton, SIGNAL(clicked()), this, SLOT(toRewardWindow()));

    //connect(combatWindow->rewardsButton, SIGNAL(clicked()), this, SLOT(newCombat()));
}

void MainWindow::loadPlayerProfile()
{
    shared_ptr<Champion> ch1 = make_shared<Champion>();
    combatWindow->loadAttacker(ch1);
}

void MainWindow::launchGame()
{
    loadPlayerProfile();
    newCombat();
    toCombatWindow();
}

void MainWindow::toRewardWindow()
{
    setCurrentWidget(rewardWindow);
}

void MainWindow::toCombatWindow()
{
    setCurrentWidget(combatWindow);
}

void MainWindow::newCombat()
{
    /*
    Monster mob1 = MonsterCreator::FactoryMethod();
    shared_ptr<Monster> m1 = make_shared<Monster>(mob1);
    */
    Boss bos1 = BossCreator::FactoryMethod();
    shared_ptr<Monster> m1 = make_shared<Boss>(bos1);

    combatWindow->loadDefender(m1);
    rewardWindow->loadMonsterRewards(m1);
    combatWindow->refreshFighters();
}