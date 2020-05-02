#ifndef FIGHTERGUI_H
#define FIGHTERGUI_H

#include <QWidget>
#include <QLabel>
#include "fighter.h"
#include <QPixmap>

class FighterGUI : public QWidget
{
    Q_OBJECT
public:
    explicit FighterGUI(QWidget *parent = nullptr);

    void printFighter(Fighter fighter);

protected:
    void setUp();
    QLabel *HP;
    QLabel *damage;
    QLabel *name;
    QLabel *illustration;

signals:
};

#endif // FIGHTERGUI_H
