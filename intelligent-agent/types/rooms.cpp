#include <iostream>
#include <boost/variant.hpp>
#include "rooms.hpp"
using namespace std;

void rooms::set_intial(room room1)
{

    for (int i = 0; i < 5; i++)
    {
        room1[i] = 0;
    }
}
void rooms::set_Wumpus(room room1)
{
    for (int i = 0; i < 5; i++)
    {
        if (i == 4)
            room1[i] = 1;
        else
        {
            room1[i] = 0;
        }
    }
}
void rooms::set_stinch(room room1)
{
    for (int i = 0; i < 5; i++)
    {
        if (i == 1)
            room1[i] = 1;
        else
        {
            room1[i] = 0;
        }
    }
}
void rooms::set_pit(room room1)
{
    for (int i = 0; i < 5; i++)
    {
        if (i == 2)
            room1[i] = 1;
        else
        {
            room1[i] = 0;
        }
    }
}
void rooms::set_breath(room room1)
{
    for (int i = 0; i < 5; i++)
    {
        if (i == 3)
            room1[i] = 1;
        else
        {
            room1[i] = 0;
        }
    }
}
void rooms::set_gold(room room1)
{
    for (int i = 0; i < 5; i++)
    {
        if (i == 0)
            room1[i] = 1;
        else
        {
            room1[i] = 0;
        }
    }
}
void rooms::remove_Wumpus(room room1)
{
    for (int i = 0; i < 5; i++)
    {
        if (i == 4)
            room1[i] = 0;
        else
        {
            room1[i] = 0;
        }
    }
}
void rooms::display(room room1)
{
    cout << "(";
    for (int i = 0; i < 5; i++)
    {
        cout << room1[i];
    }
    cout << ")" << endl;
}
bool rooms::isWumpus(room room1){
return room1[4]==1;
}
bool rooms::isPit(room room1)
{
    return room1[2] == 1;
}
bool rooms::isBreath(room room1)
{
    return room1[3] == 1;
}
bool rooms::isStinch(room room1)
{
    return room1[1] == 1;
}