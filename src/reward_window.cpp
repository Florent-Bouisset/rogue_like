#include "include/reward_window.h"

#include "QVBoxLayout"
#include <memory>
#include "include/monster.h"
#include "include/boss.h"

using namespace std;

RewardWindow::RewardWindow()
{
}

void RewardWindow::setUp()
{
    QFont largeFont;
    largeFont.setPointSize(30);
    QFont mediumFont;
    mediumFont.setPointSize(24);

    title = new QLabel();
    title->setAlignment(Qt::AlignCenter);
    title->setText("Récompenses");
    title->setFont(largeFont);

    goldReward = new QLabel();
    goldReward->setAlignment(Qt::AlignCenter);
    goldReward->setText("");
    goldReward->setFont(mediumFont);

    relicReward = new QLabel();
    relicReward->setAlignment(Qt::AlignCenter);
    relicReward->setText("");
    relicReward->setFont(mediumFont);

    nextLevel = new QPushButton();
    nextLevel->setText("Choisir le prochain contrat");
    nextLevel->setFont(mediumFont);

    QVBoxLayout *layout = new QVBoxLayout();

    layout->addWidget(title);
    layout->addWidget(goldReward);
    layout->addWidget(relicReward);
    layout->addWidget(nextLevel);
    layout->setAlignment(Qt::AlignCenter);

    setLayout(layout);
}

void RewardWindow::loadMonsterRewards(shared_ptr<Monster> monster)
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
