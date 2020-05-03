#include "include/combat_window.h"

#include <QBoxLayout>

using namespace std;

CombatWindow::CombatWindow()
{
}

void CombatWindow::setUp()
{
    attackerWidget = new FighterGUI();
    defenderWidget = new FighterGUI();

    attackButton = new QPushButton("Attaquer");
    rewardsButton = new QPushButton("Réclamer sa prime");

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(attackerWidget);
    layout->addWidget(attackButton);
    layout->addWidget(rewardsButton);
    layout->addWidget(defenderWidget);
    rewardsButton->setDisabled(true);
    connect(attackButton, SIGNAL(released()), this, SLOT(attack()));
    connect(rewardsButton, SIGNAL(released()), this, SLOT(takeReward()));
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
    refreshFighters();
}