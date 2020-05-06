#include "world.hpp"
#include <vector>
using namespace world;

std::vector<int> v ;
int r1,r2,r3,r4,r5,r6,r7,r8,r9,r0;
void WumpusWorld::initialize_room(){
    // example set up
   int m=0;
    
    for(int i=0; i < 4; i++){
        house.push_back(std::vector<Room>());
        for(int j=0; j < 4; j++){
            house[i].push_back(Room(i, j));
        }
    }
    check:
        int c = 0;
         srand(time(0));
        while (c < 10)
        {
            v.insert(v.begin() + c, rand() % 4);
            c++;
    }
    for(int y=0;y<v.size();y+=2){
     if(v.at(y)==0){
         if(v.at(y+1)==0 or v.at(y+1)==1)
         v.clear();
     }
     else if(v.at(y)==2){
         if(v.at(y+1)==0)
         v.clear();
     }
     for (int i = y + 2; i < v.size(); i += 2)
     {
         if (v.at(y) == v.at(i))
         {
             if (v.at(y + 1) == v.at(i + 1))
                 v.clear();
         }
     }
    }
    if(v.empty()){
        goto check;
    }
    else{
    for (auto i = 0; i < 10; i += 2)
    {
        if (m == 0)
        {
            house[v[i]][v[i + 1]].wumpus=1;
            r1=v[i];r2=v[i+1];
        if (i - 1 > -1){
        house[v[i - 1]][v[i + 1]].stench=1;
        r3=v[i-1];r4=v[i+1];
        }
            if (i + 1 < 4){
                house[v[i + 1]][v[i + 1]].stench=1;
                r5=v[i+1];v[i+1];
                }
            if (i > -1 and i < 4){
                house[v[i]][v[i]].stench=1;
                r7=v[i];r8=v[i];
                }
            if (i + 2 < 4){
                house[v[i - 1]][v[i + 2]].stench=1;
                r9=v[i-1];r0=v[i+2];
                }
        }
        else if (m == 1)
        {
            house[v[i]][v[i + 1]].pit=1;
            if (i - 1 > -1)
                house[v[i - 1]][v[i + 1]].breeze=1;
            if (i + 1 < 4)
                house[v[i + 1]][v[i + 1]].breeze=1;
            if (i > -1 and i < 4)
                house[v[i - 1]][v[i]].breeze=1;
            if (i + 2 < 4)
                house[v[i - 1]][v[i + 2]].breeze=1;
        }
        else if (m == 3)
        {
            house[v[i]][v[i + 1]].pit=1;
            if (i - 1 > -1)
                house[v[i - 1]][v[i + 1]].breeze=1;
            if (i + 1 < 4)
                house[v[i + 1]][v[i + 1]].breeze=1;
            if (i > -1 and i < 4)
                house[v[i - 1]][v[i]].breeze=1;
            if (i + 2 < 4)
                house[v[i - 1]][v[i + 2]].breeze=1;
        }
        else if (m == 4)
        {
            house[v[i]][v[i + 1]].pit=1;
            if (i - 1 > -1)
                house[v[i - 1]][v[i + 1]].breeze=1;
            if (i + 1 < 4)
                house[v[i + 1]][v[i + 1]].breeze=1;
            if (i > -1 and i < 4)
                house[v[i - 1]][v[i]].breeze=1;
            if (i + 2 < 4)
                house[v[i - 1]][v[i + 2]].breeze=1;
        }
        else
        {
            house[v[i]][v[i + 1]].glitter=1;
        }
        m++;
    }

    // house[2][0].wumpus = 1;
    // house[3][0].stench = 1;
    // house[2][1].stench = 1;
    // house[1][0].stench = 1;

    // house[2][1].glitter = 1;
    // house[2][2].pit = 1;
    // house[0][1].breeze = 1;
    // house[1][2].breeze = 1;
    // house[0][3].breeze = 1;

    // house[0][2].pit = 1;
    // house[1][2].breeze = 1;
    // house[2][3].breeze = 1;
    // house[2][1].breeze = 1;
    // house[3][2].breeze = 1;

    // house[3][3].pit = 1;
    // house[3][2].breeze = 1;
    // house[2][3].breeze = 1;
    }
};

void WumpusWorld::enter(){
    initialize_room();  
};

char WumpusWorld::wumpus_shot(std::pair<int, int> adj){
    initialize_room();
    printf("wumpus world wumpus shot %d, %d", adj.first, adj.second);
    if(house[adj.first][adj.second].wumpus){
        house[r1][r2].wumpus = 0;
        house[r3][r4].stench = 0;
        house[r5][r6].stench = 0;
        house[r7][r8].stench = 0;
        house[r9][r0].stench = 0;
        return 1;
    }return 0;
}
