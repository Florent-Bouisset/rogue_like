#ifndef COMBAT_WINDOW_H
#define COMBAT_WINDOW_H

#include <QWidget>
#include <QPushButton>

#include "fightergui.h"
#include "fighter.h"
#include "champion.h"
#include "monster.h"
#include "boss.h"

class CombatWindow : public QWidget
{
    Q_OBJECT

public:
    CombatWindow();
    void setUp();
    void loadAttacker(Champion);
    void loadDefender(Monster *);
    void refreshFighters();

public slots:
    void attack();
    virtual void takeReward();

protected:
    Champion attacker;
    Monster *defender;
    FighterGUI *attackerWidget;
    FighterGUI *defenderWidget;

    QPushButton *attackButton;
    QPushButton *rewardsButton;
};

#endif