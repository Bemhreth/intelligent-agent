#include <iostream>
#include <cmath>
#include <vector>
#include "rooms.hpp"
// #include "worlds.hpp"
using namespace std;


// void worlds::worlds(room world[3][3])
int main()
{
    room world[3][3];
    int c = 0, m = 0;
    srand(time(0));
    vector<int> v;
    rooms r;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            r.set_intial(world[i][j]);
        }
    }
    while (c < 10)
    {
        v.insert(v.begin() + c,rand() % 4);
        c++;
    }
    for (auto i = 0; i < 10; i += 2)
    {
             if (m == 0)
        {
            r.set_Wumpus(world[v[i]][v[i + 1]]);
            if (i - 1 > -1)
                r.set_stinch(world[v[i - 1]][v[i + 1]]);
            if (i + 1 < 4)
                r.set_stinch(world[v[i + 1]][v[i + 1]]);
            if (i > -1 and i < 4)
                r.set_stinch(world[v[i]][v[i]]);
            if (i + 2 < 4)
                r.set_stinch(world[v[i - 1]][v[i + 2]]);
        }
        else if (m == 1)
        {
            r.set_pit(world[v[i]][v[i + 1]]);
            if (i - 1 > -1)
                r.set_breath(world[v[i - 1]][v[i + 1]]);
            if (i + 1 < 4)
                r.set_breath(world[v[i + 1]][v[i + 1]]);
            if (i > -1 and i < 4)
                r.set_breath(world[v[i - 1]][v[i]]);
            if (i + 2 < 4)
                r.set_breath(world[v[i - 1]][v[i + 2]]);
        }
        else if (m == 3)
        {
            r.set_pit(world[v[i]][v[i + 1]]);
            if (i - 1 > -1)
                r.set_breath(world[v[i - 1]][v[i + 1]]);
            if (i + 1 < 4)
                r.set_breath(world[v[i + 1]][v[i + 1]]);
            if (i > -1 and i < 4)
                r.set_breath(world[v[i - 1]][v[i]]);
            if (i + 2 < 4)
                r.set_breath(world[v[i - 1]][v[i + 2]]);
        }
        else if (m == 4)
        {
            r.set_pit(world[v[i]][v[i + 1]]);
            if (i - 1 > -1)
                r.set_breath(world[v[i - 1]][v[i + 1]]);
            if (i + 1 < 4)
                r.set_breath(world[v[i + 1]][v[i + 1]]);
            if (i > -1 and i < 4)
                r.set_breath(world[v[i - 1]][v[i]]);
            if (i + 2 < 4)
                r.set_breath(world[v[i - 1]][v[i + 2]]);
        }
        else
        {
            r.set_gold(world[v[i]][v[i + 1]]);
        }
        m++;
    }
    if(r.isWumpus(world[1][1])){
        r.remove_Wumpus(world[1][1]);
        r.remove_stinch(world[1][2]);
        r.remove_stinch(world[2][1]);
    }
     else if(r.isPit(world[1][1])){
        r.remove_pit(world[1][1]);
        r.remove_breath(world[1][2]);
        r.remove_breath(world[2][1]);
    }
    else if(r.isBreath(world[1][1])){
        r.remove_breath(world[1][1]);
        if(r.isPit(world[1][2])){
            r.remove_pit(world[1][2]);
            r.remove_breath(world[2][2]);
            r.remove_breath(world[1][3]);
        }
        else if(r.isPit(world[2][1])){
            r.remove_breath(world[3][1]);
            r.remove_breath(world[2][2]);
        }
    }
     else if(r.isStinch(world[1][1])){
        r.remove_stinch(world[1][1]);
        if(r.isWumpus(world[1][2])){
            r.remove_Wumpus(world[1][2]);
            r.remove_stinch(world[2][2]);
            r.remove_stinch(world[1][3]);
        }
        else if(r.isWumpus(world[2][1])){
            r.remove_stinch(world[3][1]);
            r.remove_stinch(world[2][2]);
        }
    }
    else if(r.isGold(world[1][1])){
        r.remove_gold(world[1][1]);
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            r.display(world[i][j]);
        }
        cout<<endl;
    }
return 0;
}
