#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QStackedWidget>
#include "combat_window.h"
#include "reward_window.h"

class MainWindow : public QStackedWidget
{
    Q_OBJECT
public:
    MainWindow();
    void setUp();
    void play();
    void toCombatWindow();
    void toRewardWindow();
    CombatWindow *combatWindow;
    RewardWindow *rewardWindow;
public slots:
    void newCombat();
};

#endif