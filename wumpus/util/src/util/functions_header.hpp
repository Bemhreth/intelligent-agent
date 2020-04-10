#ifndef FUNC_H
#define FUNC_H

#include "value.hpp"
#include <world/room.hpp>
#include <bits/stdc++.h>
#include <vector>
#include <string>

namespace util{

char sematic_tabulax(std::vector<std::vector<Value>> premise_conclusion);

std::vector<Value> get_operands(std::string sense, 
            world::Room room, std::vector<std::vector<world::Room>> myhouse);

std::vector<std::vector<Value>>  convert_to_value(world::Room room, 
            std::vector<std::vector<world::Room>> myhouse, char wumpus_alive);
}

#endif
