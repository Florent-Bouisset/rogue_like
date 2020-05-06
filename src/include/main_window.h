#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QStackedWidget>
#include "combat_window.h"
#include "reward_window.h"
#include "defeat_window.h"
#include "level_selection_window.h"

class MainWindow : public QStackedWidget
{
    Q_OBJECT
public:
    MainWindow();
    void setUp();
    void launchGame();
    void loadPlayerProfile();
    void loadABoss();
    void loadAMonster();

    CombatWindow *combatWindow;
    RewardWindow *rewardWindow;
    LevelSelectionWindow *levelSelectionWindow;
    DefeatWindow *defeatWindow;

public slots:
    void loadNextLevel(RoomType);
    void toDefeatWindow();
    void toCombatWindow();
    void toRewardWindow();
    void toLevelSelectionWindow();
};

#endif