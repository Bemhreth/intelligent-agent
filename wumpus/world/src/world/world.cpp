#include "world.hpp"


using namespace world;

void WumpusWorld::initialize_room(){
    // example set up
    for(int i=0; i < 4; i++){
        house.push_back(std::vector<Room>());
        for(int j=0; j < 4; j++){
            house[i].push_back(Room(i, j));
        }
    }

    house[2][0].wumpus = 1;
    house[3][0].stench = 1;
    house[2][1].stench = 1;
    house[1][0].stench = 1;

    house[2][1].glitter = 1;
    house[2][2].pit = 1;
    house[0][1].breeze = 1;
    house[1][2].breeze = 1;
    house[0][3].breeze = 1;

    house[0][2].pit = 1;
    house[1][2].breeze = 1;
    house[2][3].breeze = 1;
    house[2][1].breeze = 1;
    house[3][2].breeze = 1;

    house[3][3].pit = 1;
    house[3][2].breeze = 1;
    house[2][3].breeze = 1;

};

void WumpusWorld::enter(){
    initialize_room();  
};

char WumpusWorld::wumpus_shot(std::pair<int, int> adj){
    printf("wumpus world wumpus shot %d, %d", adj.first, adj.second);
    if(house[adj.first][adj.second].wumpus){
        house[2][0].wumpus = 0;
        house[3][0].stench = 0;
        house[2][1].stench = 0;
        house[1][0].stench = 0;
        return 1;
    }return 0;
}
