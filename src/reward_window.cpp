#include "include/reward_window.h"

#include "QVBoxLayout"
#include <memory>
#include "include/monster.h"
#include "include/boss.h"

using namespace std;

RewardWindow::RewardWindow()
{
    setUp();
}

void RewardWindow::setUp()
{
    QFont largeFont;
    largeFont.setPointSize(30);
    QFont mediumFont;
    mediumFont.setPointSize(24);

    title = new QLabel();
    goldReward = new QLabel();
    relicReward = new QLabel();

    title->setText("Récompenses");
    goldReward->setText("");
    relicReward->setText("");

    title->setFont(largeFont);
    goldReward->setFont(mediumFont);
    relicReward->setFont(mediumFont);

    QVBoxLayout *layout = new QVBoxLayout();

    layout->addWidget(title);
    layout->addWidget(goldReward);
    layout->addWidget(relicReward);

    title->setAlignment(Qt::AlignCenter);
    goldReward->setAlignment(Qt::AlignCenter);
    relicReward->setAlignment(Qt::AlignCenter);
    layout->setAlignment(Qt::AlignCenter);
    setLayout(layout);
}

void RewardWindow::printRewards(shared_ptr<Monster> monster)
{
    Monster *mob = &(*monster);
    if (dynamic_cast<Boss *>(mob))
    {
        Boss *boss = dynamic_cast<Boss *>(mob);
        QString msg = "Vous obtenez la relique " + QString::fromStdString(boss->getRelicReward().getName());
        relicReward->setText(msg);
    }
    goldReward->setText(QString::number(monster->getGoldReward()) + " pièces d'or");
}

RewardWindow::~RewardWindow()
{
    delete title;
    delete goldReward;
    delete relicReward;
}
