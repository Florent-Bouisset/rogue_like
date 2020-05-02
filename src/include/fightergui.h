#ifndef FIGHTERGUI_H
#define FIGHTERGUI_H

#include <QWidget>
#include <QLabel>
#include <string>

class FighterGUI : public QWidget
{
    Q_OBJECT
public:
    explicit FighterGUI(QWidget *parent = nullptr);

protected:
    void setUp();
    QLabel *HP;
    QLabel *damage;
    QLabel *name;

    void setHP(int HP, int maxHP);
    void setDamage(int dmg);
    void setName(std::string p_name);

signals:
};

#endif // FIGHTERGUI_H
