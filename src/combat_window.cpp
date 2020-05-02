#include "include/combat_window.h"

#include <QBoxLayout>

using namespace std;

CombatWindow::CombatWindow()
{
}

void CombatWindow::setUp()
{
    attacker = new FighterGUI();
    defender = new FighterGUI();
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(attacker);
    layout->addWidget(defender);
    setLayout(layout);
}

void CombatWindow::loadAttacker(Fighter fighter)
{
    attacker->printFighter(fighter);
}

void CombatWindow::loadDefender(Fighter fighter)
{
    defender->printFighter(fighter);
}
