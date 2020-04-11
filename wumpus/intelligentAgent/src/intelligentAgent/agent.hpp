#ifndef AGENT_H
#define AGENT_H
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <world/world.hpp>
#include <world/room.hpp>
#include <util/functions_header.hpp>
#include <util/value.hpp>


namespace agent {

    class Agent{

        // private:
        //     Room (*myhouse)[4];
    // create world
        public:

            int cur_x;
            int cur_y;
            std::vector<std::vector<world::Room>> myhouse;
            std::vector<std::vector<util::Value>> knowledge_base;
            std::stack<std::pair<int, int>> okay_rooms;
            world::WumpusWorld wumpusworld;

            Agent(){
                cur_x = 0;
                cur_y = 0;
                // WumpusWorld wumpusworld;
                wumpusworld.enter();
                myhouse = wumpusworld.house;
            };
            char proof(std::vector<std::vector<util::Value>> knowledge_base, std::string crsis, char logic);
            void update_position();
            void string_value_list(std::vector<std::vector<util::Value>> premise);
            void play();
            std::vector<std::pair<int, int>> adjecent_rooms(int x, int y);
            world::Room current_room(){
                // printf("X positon %d \n", myhouse[cur_x][cur_y].get_x());
            return myhouse[cur_x][cur_y];};
    };  

};

#endif
