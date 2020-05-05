#ifndef LEVEL_SELECTION_WINDOW_H
#define LEVEL_SELECTION_WINDOW_H

#include <QWidget>
#include <QLabel>
#include <vector>
#include <memory>
#include "dungeon_room.h"

class LevelSelectionWindow : public QWidget
{
public:
    LevelSelectionWindow();
    std::vector<DungeonRoom *> levelPropositions;
    void generateLevelPropositions();

    int numberOfProposition;
    QLabel *title;
    QFrame *centralWidget;
};

#endif
