#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>


namespace world {

    class Room{

        private:
            int x, y;
        public:
            char wumpus;
            char stench;
            char pit;
            char breeze;
            char glitter;
            char agent;
            char visited;
            Room(int x_, int y_){
                x = x_;
                y = y_;
                wumpus = 0;
                stench = 0;
                pit = 0;
                breeze = 0;
                glitter = 0;
                agent = 0;
                visited = 0;
                
            }
            int get_x(){return x;};
            int get_y(){return y;};
            // void set_x(int value){x = value;};
            // void set_y(int value){y = value;};
    };

}  
 
#endif
