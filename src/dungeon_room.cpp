
#include "include/dungeon_room.h"

#include <memory>
#include <QLabel>
#include <QVBoxLayout>

using namespace std;

DungeonRoom::DungeonRoom()
{
    roomType = RoomType::MONSTER_ROOM;

    roomTitle = new QLabel();
    roomTitle->setText("Monstre inconnu");

    roomAbstract = new QLabel();
    roomAbstract->setText("Pas de description");

    chooseRoom = new QPushButton();
    chooseRoom->setText("Choisir cette salle");
    layoutSetUp();
    connect(chooseRoom, SIGNAL(clicked()), this, SLOT(emitSignal()));
}

DungeonRoom::DungeonRoom(RoomType type, std::string title, std::string abstract)
{
    roomType = type;

    roomTitle = new QLabel();
    roomTitle->setText(QString::fromStdString(title));

    roomAbstract = new QLabel();
    roomAbstract->setText(QString::fromStdString(abstract));

    chooseRoom = new QPushButton();
    chooseRoom->setText("Choisir cette salle");

    layoutSetUp();
    connect(chooseRoom, SIGNAL(clicked()), this, SLOT(emitSignal()));
}

void DungeonRoom::layoutSetUp()
{
    QFont font = roomTitle->font();
    font.setPointSize(18);

    roomTitle->setAlignment(Qt::AlignCenter);
    roomTitle->setFont(font);
    roomTitle->setWordWrap(true);

    roomAbstract->setAlignment(Qt::AlignCenter);
    roomAbstract->setFont(font);
    roomAbstract->setWordWrap(true);

    chooseRoom->setFont(font);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(roomTitle);
    layout->addWidget(roomAbstract);
    layout->addWidget(chooseRoom);
    setLayout(layout);
    setMaximumWidth(300);
}

DungeonRoom *DungeonRoom::createRoom(RoomType type)
{
    switch (type)
    {
    case RoomType::BOSS_ROOM:
        return new DungeonRoom(BOSS_ROOM, "Boss", "Un combat difficile avec beaucoup de récompenses");

    case RoomType::MONSTER_ROOM:
        return new DungeonRoom(MONSTER_ROOM, "Monstre", "Un combat ordinaire avec de faibles récompenses");

    default:
        return new DungeonRoom();
    }
}

DungeonRoom *DungeonRoom::createRoom()
{
    RoomType randomType = static_cast<enum RoomType>(rand() % ROOM_MAX_VALUE);
    return createRoom(randomType);
}

void DungeonRoom::emitSignal()
{

    emit roomSelected(roomType);
}
