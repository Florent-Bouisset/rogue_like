#ifndef REWARD_WINDOW_H
#define REWARD_WINDOW_H

class Monster;
class Champion;
class Relic;

#include <QWidget>
#include <QPushButton>
#include <memory>
#include <QLabel>

class RewardWindow : public QWidget
{
public:
    RewardWindow();
    ~RewardWindow();
    void setUp();
    void printRewards(std::shared_ptr<Monster> monster);

protected:
    QLabel *title;
    QLabel *goldReward;
    QLabel *relicReward;
};

#endif