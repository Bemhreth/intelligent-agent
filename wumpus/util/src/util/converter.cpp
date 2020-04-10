#include "functions_header.hpp"

namespace util{

    std::vector<Value> get_operands(std::string sense, 
                world::Room room, std::vector<std::vector<world::Room>> myhouse){

    std::vector<Value> operands;
    auto str = [](int x, int y, std::string sense) {
        return sense + std::to_string(x) + std::to_string(y);
    };
    
    int x = room.get_x();
    int y = room.get_y();

    if(x > 0 and (not myhouse[x-1][y].visited)){
        //    x-1, y

        operands.push_back(Value(ValType::Operand, str(x-1, y, sense)));

    } 
        if(x < 3 and (not myhouse[x+1][y].visited)){
        //    x+1, y
        operands.push_back(Value(ValType::Operand, str(x+1, y, sense)));
    } 

    if(y > 0 and (not myhouse[x][y-1].visited)){
        //    x, y-1
        operands.push_back(Value(ValType::Operand,  str(x, y-1, sense)));
    }
    if(y < 3 and (not myhouse[x][y+1].visited)){
        //    x, y+1
        operands.push_back(Value(ValType::Operand,  str(x, y+1, sense)));
    } 
    return operands;
    };

    std::vector<std::vector<Value>>  convert_to_value(world::Room room, 
                        std::vector<std::vector<world::Room>> myhouse, char wumpus_alive){

        std::vector<std::vector<Value>> result_list;
        std::vector<Value> result;
        std::string issue;
        std::vector<char> status{room.breeze, room.stench};
        int i =0;
        int count;
        if(wumpus_alive) count = 2;
        else count = 1;


        while(i < count) {
            if(i == 0) issue = "pit";
            else issue = "wumpus";
            
            std::vector<Value> operands = get_operands(issue, room, myhouse);
    
            for(int i=0; i<operands.size(); i++){
            if(i > 1){
                result.push_back(Value(ValType::Operator, "or"));
            }

            result.push_back(operands[i]);

            }
            if(operands.size() > 1) result.push_back(Value(ValType::Operator, "or"));
            if(not status[i]) result.push_back(Value(ValType::Operator, "not"));

            result_list.push_back(result);
            result.clear();
            i++;
        }
        return result_list;
    };
};
