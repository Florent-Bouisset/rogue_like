#include "include/fightergui.h"

#include <string>
#include <QString>
#include <QLayout>
#include <QPixmap>

using namespace std;

FighterGUI::FighterGUI(QWidget *parent) : QWidget(parent)
{
    setUp();
}

void FighterGUI::setUp()
{
    name = new QLabel();
    damage = new QLabel();
    HP = new QLabel();
    illustration = new QLabel();

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(illustration);
    layout->addWidget(name);
    layout->addWidget(HP);
    layout->addWidget(damage);

    setLayout(layout);
}

void FighterGUI::printFighter(Fighter fighter)
{
    name->setText(QString::fromStdString(fighter.getName()));
    HP->setText(QString::number(fighter.getHP()) + " / " + QString::number(fighter.getMaxHP()));
    damage->setText(QString::number(fighter.getDamage()));
    illustration->setPixmap(QPixmap("image/fighter/champion/geralt.png"));
}
