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
    void launchGame();
    void loadPlayerProfile();

    CombatWindow *combatWindow;
    RewardWindow *rewardWindow;
public slots:
    void toCombatWindow();
    void toRewardWindow();
    void newCombat();
};

#endif