
#include "include/dungeon.h"
#include <iostream>

using namespace std;

Dungeon::Dungeon() : champion("Delmak")
{
    roomAchieved = 0;
}


int Dungeon::chooseNextRoom(){
    cout << "Choisissez la prochaine salle !" << endl;
    cout << " 1 - Monstre" << endl;
    cout << " 2 - Boss" << endl;
    cout << " 3 - Marchand" <<endl;

    int answer = -1;
    do {
        cin >> answer;
    }
    while((answer < 0) || (answer > 2));

    return answer;
}

void Dungeon::generateNextRooms(){
    int roomNb = 3;

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
