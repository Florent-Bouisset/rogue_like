
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

    //TEST
    testButton = new QPushButton("Generer nouveaux");
    QObject::connect(testButton, SIGNAL(clicked()), this, SLOT(generateLevelPropositions()));

    mainLayout = new QVBoxLayout();
    generateLevelPropositions();

    mainLayout->addWidget(title);
    mainLayout->addWidget(centralWidget);
    mainLayout->addWidget(testButton);
    setLayout(mainLayout);
}

void LevelSelectionWindow::generateLevelPropositions()
{
    //Delete olds widgets

    while (levelPropositions.size() != 0)
    {
        levelPropositions.pop_back();
    }

    //Create new widgets and new widgets to the layout
    delete (secondLayout);
    secondLayout = new QHBoxLayout();

    for (int i = 0; i < numberOfProposition; i++)
    {
        levelPropositions.push_back(DungeonRoom::createRoom());
        secondLayout->addWidget(levelPropositions.at(i));
        connect(levelPropositions.at(i), SIGNAL(roomSelected(RoomType)), this, SLOT(sendLevelSelection(RoomType)));
    }

    //Delete layout and child widget before setting the new layout
    delete (centralWidget->layout());
    qDeleteAll(centralWidget->children());
    centralWidget->setLayout(secondLayout);
}

void LevelSelectionWindow::sendLevelSelection(RoomType type)
{
    emit levelSelected(type);
}