#include<iostream>
#include <world/room.hpp>
#include <world/world.hpp>
#include<util/functions_header.hpp>

int main (){
    world::Room rr(2, 3);
    world::WumpusWorld ww;
    ww.initialize_room();
    std::vector<std::vector<util::Value>> premise_conclusion;
    util::sematic_tabulax(premise_conclusion);
}