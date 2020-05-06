#ifndef COMBAT_WINDOW_H
#define COMBAT_WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <memory>
#include "fighter_widget.h"
#include "fighter.h"
#include "champion.h"
#include "monster.h"

class CombatWindow : public QWidget
{
    Q_OBJECT

public:
    CombatWindow();
    void setUp();
    void loadAttacker(std::shared_ptr<Champion>);
    void loadDefender(std::shared_ptr<Monster>);
    void refreshFighters();
    QPushButton *rewardsButton;

signals:
    void championIsDead();

public slots:
    void attack();
    virtual void takeReward();

protected:
    std::shared_ptr<Champion> attacker;
    std::shared_ptr<Monster> defender;
    FighterWidget *attackerWidget;
    FighterWidget *defenderWidget;

    QPushButton *attackButton;
};

#endif