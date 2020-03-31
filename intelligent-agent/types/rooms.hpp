#include <iostream>
typedef int room[4];

class rooms
{

public:
    void rooms::set_intial(room room1);
    void rooms::set_Wumpus(room room1);
    void rooms::set_stinch(room room1);
    void rooms::set_pit(room room1);
    void rooms::set_breath(room room1);
    void rooms::set_gold(room room1);
    void rooms::remove_Wumpus(room room1);
    void rooms::display(room room1);
    bool rooms::isWumpus(room room1);
    bool rooms::isPit(room room1);
    bool rooms::isBreath(room room1);
    bool rooms::isStinch(room room1);
};
