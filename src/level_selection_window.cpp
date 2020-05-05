
#include "include/level_selection_window.h"

#include <memory>
#include <vector>
#include <QBoxLayout>
#include "include/dungeon_room.h"

using namespace std;

LevelSelectionWindow::LevelSelectionWindow()
{
    numberOfProposition = 3;

    title = new QLabel();
    QFont font = title->font();
    font.setPointSize(36);
    title->setFont(font);
    title->setAlignment(Qt::AlignCenter);
    title->setText("Choisissez votre prochain contrat");

    centralWidget = new QFrame();
    centralWidget->setFrameStyle(QFrame::Box | QFrame::Raised);
    centralWidget->setLineWidth(2);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *secondLayout = new QHBoxLayout();
    generateLevelPropositions();

    foreach (DungeonRoom *room, levelPropositions)
    {
        secondLayout->addWidget(room);
    }
    centralWidget->setLayout(secondLayout);
    mainLayout->addWidget(title);
    mainLayout->addWidget(centralWidget);
    setLayout(mainLayout);
}

void LevelSelectionWindow::generateLevelPropositions()
{
    while (levelPropositions.size() != 0)
    {
        levelPropositions.pop_back();
    }

    for (int i = 0; i < numberOfProposition; i++)
    {
        levelPropositions.push_back(DungeonRoom::createRoom());
    }
}