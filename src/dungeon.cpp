
#include "include/dungeon.h"
#include <iostream>

using namespace std;

Dungeon::Dungeon() : champion("Delmak")
{
    roomAchieved = 0;
    nbrOfRoomByLevel = 3;
}


int Dungeon::chooseNextRoom(){
    cout << "Choisissez la prochaine salle !" << endl;
    
    for (int i = 0; i < nbrOfRoomByLevel; i++){
        cout << i << " - " << roomPossibilites.at(i)->roomAbstract() << endl;
    }

    int answer = -1;
    do {
        cin >> answer;
    }
    while((answer < 0) || (answer > nbrOfRoomByLevel - 1));
    
    return answer;
}

void Dungeon::generateNextRooms(){
    int roomNb = nbrOfRoomByLevel;

    while (roomPossibilites.size() != 0){
        roomPossibilites.pop_back();
    }
    for (int i = 0; i < roomNb; i++ ){
        roomPossibilites.push_back(DungeonRoom::createRoom());
    }
}

void Dungeon::play(){
    int chosenRoom;
    while(champion.isAlive()){
        generateNextRooms();
        chosenRoom = chooseNextRoom();
        roomPossibilites.at(chosenRoom)->championInteraction(champion);
    }
}
