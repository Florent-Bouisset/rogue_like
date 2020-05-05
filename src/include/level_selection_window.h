#ifndef LEVEL_SELECTION_WINDOW_H
#define LEVEL_SELECTION_WINDOW_H

#include <QWidget>
#include <QLabel>
#include <QBoxLayout>
#include <vector>
#include <memory>
#include "dungeon_room.h"

class LevelSelectionWindow : public QWidget
{
    Q_OBJECT
public:
    LevelSelectionWindow();
    std::vector<DungeonRoom *> levelPropositions;
    int numberOfProposition;
    QLabel *title;
    QFrame *centralWidget;
    QPushButton *testButton;
    QVBoxLayout *mainLayout;
    QHBoxLayout *secondLayout;

signals:
    void levelSelected(RoomType);

public slots:
    void generateLevelPropositions();
    void sendLevelSelection(RoomType type);
};

#endif
