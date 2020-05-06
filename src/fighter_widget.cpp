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
    damageWidget = new QFrame();
    QHBoxLayout *damageLayout = new QHBoxLayout();
    damageIcon = new QLabel();
    damageValue = new QLabel();
    damageIcon->setPixmap(QPixmap("image/icons/sword.png"));
    damageLayout->addWidget(damageIcon);
    damageLayout->addWidget(damageValue);
    damageWidget->setLayout(damageLayout);
    damageWidget->setFixedWidth(300);

    HPWidget = new QFrame();
    QHBoxLayout *HPLayout = new QHBoxLayout();
    HPIcon = new QLabel();
    HPValue = new QLabel();
    HPIcon->setPixmap(QPixmap("image/icons/heart.png"));
    HPLayout->addWidget(HPIcon);
    HPLayout->addWidget(HPValue);
    HPWidget->setLayout(HPLayout);
    HPWidget->setFixedWidth(300);

    name = new QLabel();

    illustration = new QLabel();

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(illustration);
    layout->addWidget(name);
    layout->addWidget(HPWidget);
    layout->addWidget(damageWidget);

    setLayout(layout);
    layoutSetUp();
}

void FighterWidget::layoutSetUp()
{
    //Alignements
    illustration->setAlignment(Qt::AlignCenter);
    name->setAlignment(Qt::AlignCenter);
    HPValue->setAlignment(Qt::AlignCenter);
    damageValue->setAlignment(Qt::AlignCenter);

    //Font Size
    QFont font = name->font();
    font.setPointSize(30);
    name->setFont(font);
    HPValue->setFont(font);
    damageValue->setFont(font);

    this->setFixedSize(400, 650);
}

void FighterWidget::printFighter(Fighter fighter)
{
    name->setText(QString::fromStdString(fighter.getName()));
    HPValue->setText(QString::number(fighter.getHP()) + " / " + QString::number(fighter.getMaxHP()));
    damageValue->setText(QString::number(fighter.getDamage()));
    illustration->setPixmap(QPixmap(QString::fromStdString(fighter.getIllustrationPath())));
}
