#include "include/fighter_widget.h"

#include <string>
#include <QString>
#include <QLayout>
#include <QPixmap>

using namespace std;

FighterWidget::FighterWidget(QWidget *parent) : QWidget(parent)
{
    setUp();
}

void FighterWidget::setUp()
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
    layoutSetUp();
}

void FighterWidget::layoutSetUp()
{
    //Alignements
    illustration->setAlignment(Qt::AlignCenter);
    name->setAlignment(Qt::AlignCenter);
    HP->setAlignment(Qt::AlignCenter);
    damage->setAlignment(Qt::AlignCenter);

    //Font Size
    QFont font = name->font();
    font.setPointSize(30);
    name->setFont(font);
    HP->setFont(font);
    damage->setFont(font);

    this->setFixedSize(350, 600);
}

void FighterWidget::printFighter(Fighter fighter)
{
    name->setText(QString::fromStdString(fighter.getName()));
    HP->setText(QString::number(fighter.getHP()) + " / " + QString::number(fighter.getMaxHP()));
    damage->setText(QString::number(fighter.getDamage()));
    illustration->setPixmap(QPixmap(QString::fromStdString(fighter.getIllustrationPath())));
}
