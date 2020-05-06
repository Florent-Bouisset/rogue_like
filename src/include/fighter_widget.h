#ifndef FIGHTER_WIDGET_H
#define FIGHTER_WIDGET_H

#include <QWidget>
#include <QLabel>
#include "fighter.h"
#include <QPixmap>

class FighterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FighterWidget(QWidget *parent = nullptr);

    void printFighter(Fighter fighter);

protected:
    //Methods
    void setUp();
    void layoutSetUp();

    //Attributes
    QFrame *HPWidget;
    QLabel *HPValue;
    QLabel *HPIcon;

    QFrame *damageWidget;
    QLabel *damageValue;
    QLabel *damageIcon;

    QLabel *name;
    QLabel *illustration;
};

#endif
