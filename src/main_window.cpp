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
    this->addWidget(combatWindow);
    this->addWidget(rewardWindow);

    connect(combatWindow->rewardsButton, SIGNAL(clicked()), this, SLOT(newCombat()));
}

void MainWindow::play()
{

    Monster mob1 = MonsterCreator::FactoryMethod();
    Boss boss1 = BossCreator::FactoryMethod();
    Champion champ = Champion();

    shared_ptr<Monster> b1 = make_shared<Monster>(mob1);
    shared_ptr<Champion> ch1 = make_shared<Champion>(champ);
    connect(combatWindow->rewardsButton, SIGNAL(clicked()), this, SLOT(newCombat()));

    combatWindow->loadDefender(b1);
    combatWindow->loadAttacker(ch1);
}

void MainWindow::toRewardWindow()
{
}

void MainWindow::toCombatWindow()
{
}

void MainWindow::newCombat()
{
    Monster mob1 = MonsterCreator::FactoryMethod();
    shared_ptr<Monster> m1 = make_shared<Monster>(mob1);
    combatWindow->loadDefender(m1);
    combatWindow->refreshFighters();
}