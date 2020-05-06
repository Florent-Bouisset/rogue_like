#include "include/main_window.h"

#include "include/monster_creator.h"
#include "include/boss_creator.h"
#include "include/champion.h"
#include "include/defeat_window.h"

using namespace std;

MainWindow::MainWindow()
{
    setUp();
}

void MainWindow::setUp()
{
    combatWindow = new CombatWindow();
    rewardWindow = new RewardWindow();
    levelSelectionWindow = new LevelSelectionWindow();
    defeatWindow = new DefeatWindow();

    combatWindow->setUp();
    rewardWindow->setUp();
    addWidget(combatWindow);
    addWidget(rewardWindow);
    addWidget(levelSelectionWindow);
    addWidget(defeatWindow);

    connect(combatWindow, SIGNAL(championIsDead()), this, SLOT(toDefeatWindow()));
    connect(combatWindow->rewardsButton, SIGNAL(clicked()), this, SLOT(toRewardWindow()));
    connect(rewardWindow->nextLevel, SIGNAL(clicked()), this, SLOT(toLevelSelectionWindow()));
    connect(levelSelectionWindow, SIGNAL(levelSelected(RoomType)), this, SLOT(loadNextLevel(RoomType)));
}

void MainWindow::loadPlayerProfile()
{
    shared_ptr<Champion> ch1 = make_shared<Champion>();
    combatWindow->loadAttacker(ch1);
}

void MainWindow::launchGame()
{
    loadPlayerProfile();
    toLevelSelectionWindow();
}

void MainWindow::toRewardWindow()
{
    setCurrentWidget(rewardWindow);
}

void MainWindow::toDefeatWindow()
{
    setCurrentWidget(defeatWindow);
}

void MainWindow::toCombatWindow()
{
    setCurrentWidget(combatWindow);
}

void MainWindow::toLevelSelectionWindow()
{
    setCurrentWidget(levelSelectionWindow);
}

void MainWindow::loadABoss()
{
    Boss boss = BossCreator::FactoryMethod();
    shared_ptr<Monster> ptr_boss = make_shared<Boss>(boss);

    combatWindow->loadDefender(ptr_boss);
    rewardWindow->loadMonsterRewards(ptr_boss);
    combatWindow->refreshFighters();
}

void MainWindow::loadAMonster()
{
    Monster monster = MonsterCreator::FactoryMethod();
    shared_ptr<Monster> ptr_monster = make_shared<Monster>(monster);

    combatWindow->loadDefender(ptr_monster);
    rewardWindow->loadMonsterRewards(ptr_monster);
    combatWindow->refreshFighters();
}

void MainWindow::loadNextLevel(RoomType type)
{
    switch (type)
    {
    case RoomType::MONSTER_ROOM:
        loadAMonster();
        toCombatWindow();
        break;

    case RoomType::BOSS_ROOM:
        loadABoss();
        toCombatWindow();
        break;

    default:
        loadAMonster();
        toCombatWindow();
        break;
    }
}