#include "include/combat_window.h"

#include <QBoxLayout>
#include "include/reward_window.h"

using namespace std;

CombatWindow::CombatWindow()
{
}

void CombatWindow::setUp()
{
    attackerWidget = new FighterWidget();
    defenderWidget = new FighterWidget();

    attackButton = new QPushButton("Attaquer");
    rewardsButton = new QPushButton("Réclamer sa prime");

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(attackerWidget);
    layout->addWidget(attackButton);
    layout->addWidget(rewardsButton);
    layout->addWidget(defenderWidget);
    rewardsButton->setDisabled(true);
    connect(attackButton, SIGNAL(clicked()), this, SLOT(attack()));
    connect(rewardsButton, SIGNAL(clicked()), this, SLOT(takeReward()));
    setLayout(layout);
}

void CombatWindow::loadAttacker(shared_ptr<Champion> champion)
{
    attacker = champion;
    attackerWidget->printFighter(*attacker);
}

void CombatWindow::loadDefender(shared_ptr<Monster> monster)
{
    defender = monster;
    defenderWidget->printFighter(*defender);
}

void CombatWindow::refreshFighters()
{
    attackerWidget->printFighter(*attacker);
    defenderWidget->printFighter(*defender);
}

void CombatWindow::attack()
{
    attacker->fightForOneTurn(*defender);
    refreshFighters();
    if (attacker->isDead())
    {
        //TODO Game Over
    }
    if (defender->isDead())
    {
        //TODO Go to rewards
        rewardsButton->setDisabled(false);
    }
}

void CombatWindow::takeReward()
{
    attacker->takeRewards(defender);
    rewardsButton->setDisabled(true);
    RewardWindow *reward = new RewardWindow();
    reward->printRewards(defender);
    reward->show();
}