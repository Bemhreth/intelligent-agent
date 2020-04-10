#ifndef WUMPUS_H
#define WUMPUS_H

#include <iostream>
#include <string>
#include "room.hpp"
#include <vector>

namespace world {

    class WumpusWorld{
        
        public: 
            std::vector<std::vector<Room> > house;

            void  initialize_room();

            void enter();

            char wumpus_shot(std::pair<int, int> adj);

    };
    
};
 
#endif
