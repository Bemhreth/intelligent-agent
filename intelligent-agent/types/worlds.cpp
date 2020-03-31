#include <iostream>
#include <cmath>
#include <vector>
#include "rooms.hpp"
using namespace std;

int main()
{
    int c = 0, m = 0;
    srand(time(0));
    vector<int> v;
    rooms r;
    room world[3][3];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            r.set_intial(world[i][j]);
        }
    }
    while (c < 10)
    {
        int f = rand() % 4;

        v.insert(v.begin() + c, f);
        c++;
    }
    for (auto i = 0; i < 10; i += 2)
    {
        int ch;
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
    return 0;
}
