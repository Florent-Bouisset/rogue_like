#include "include/fightergui.h"
#include <string>
#include <QString>
#include <QLayout>

using namespace std;

FighterGUI::FighterGUI(QWidget *parent) : QWidget(parent)
{
    setUp();
    setName("je usis heureux ça marche!!");
    setDamage(15);
    setHP(10, 15);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(name);
    layout->addWidget(HP);
    layout->addWidget(damage);

    setLayout(layout);
}

void FighterGUI::setUp()
{
    name = new QLabel();
    damage = new QLabel();
    HP = new QLabel();
}

void FighterGUI::setName(string p_name)
{
    name->setText(QString::fromStdString(p_name));
}

void FighterGUI::setDamage(int p_damage)
{
    damage->setText(QString::number(p_damage));
}

void FighterGUI::setHP(int p_HP, int p_maxHP)
{
    HP->setText(QString::number(p_HP) + " / " + QString::number(p_maxHP));
}
