#include <iostream>
typedef int room[4];

class rooms
{
public:
    void remove_pit(room room1);
    void remove_stinch(room room1);
    void remove_gold(room room1);
    void remove_breath(room room1);
    void set_intial(room room1);
    void set_Wumpus(room room1);
    void set_stinch(room room1);
    void set_pit(room room1);
    void set_breath(room room1);
    void set_gold(room room1);
    void remove_Wumpus(room room1);
    void display(room room1);
    bool isWumpus(room room1);
    bool isPit(room room1);
    bool isBreath(room room1);
    bool isStinch(room room1);
    bool isGold(room room1);
};
