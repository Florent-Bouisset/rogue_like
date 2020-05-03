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
    QLabel *HP;
    QLabel *damage;
    QLabel *name;
    QLabel *illustration;

signals:
};

#endif
