#ifndef COMBAT_WINDOW_H
#define COMBAT_WINDOW_H

#include <QMainWindow>
#include "fightergui.h"
#include "fighter.h"

class CombatWindow : public QWidget
{
    Q_OBJECT

public:
    CombatWindow();
    void setUp();
    void loadAttacker(Fighter);
    void loadDefender(Fighter);

private:
    FighterGUI *attacker;
    FighterGUI *defender;
};

#endif