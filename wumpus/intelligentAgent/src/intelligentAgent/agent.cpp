#include "agent.hpp"


using namespace agent;

void Agent::update_position(){

    myhouse[cur_x][cur_y].agent = 1;
    myhouse[cur_x][cur_y].visited = 1;
    // printf("update position garrrr %d\n", myhouse[cur_x][cur_y].get_x());

};

void Agent::string_value_list(std::vector<std::vector<util::Value>> premise){
    printf("\nPrinting the premises and conclusion, the last element is postfix of the conclusion\n");
    for (auto a: premise){
        for(auto b: a){
            printf("%s, ", b.name.c_str());
        }
        printf("\n");
    }
    printf("\n\n");
};

char Agent::proof(std::vector<std::vector<util::Value>> knowledge_base,
                                         std::string crisis, char logic){
    auto a = current_room().get_x();
    std::vector<util::Value> conclusion_wumpus;

    if(logic){

        conclusion_wumpus.push_back(util::Value(util::ValType::Operand, crisis));
        conclusion_wumpus.push_back(util::Value(util::ValType::Operator, "not"));
    
    } else {

        conclusion_wumpus.push_back(util::Value(util::ValType::Operand, crisis));
    }
    auto premise_conclusion = knowledge_base;
    premise_conclusion.push_back(conclusion_wumpus);
    string_value_list(premise_conclusion);

    return sematic_tabulax(premise_conclusion);

};

std::vector<std::pair<int, int>> Agent::adjecent_rooms(int x, int y){

    std::vector<std::pair<int, int>> adj_rooms;

    int i = 0;
    if(x > 0){
        //    x-1, y
        adj_rooms.push_back(std::pair<int, int>(x-1, y));
    }
    if(x < 3){
        //    x+1, y
        adj_rooms.push_back(std::pair<int, int>(x+1, y));
    } 
    if(y > 0){
        //    x, y-1
        adj_rooms.push_back(std::pair<int, int>(x, y-1));
    }
    if(y < 3){
        //    x, y+1
        adj_rooms.push_back(std::pair<int, int>(x, y+1));
    } 
    return adj_rooms;
    
}

void Agent::play(){
    char no_wumpus, gold_in_room, wumpus_in_room, 
            pit_in_room,room_okay, no_pit, wumpus_alive=1;
    
    std::vector<std::vector<util::Value>> value_list;
    int stop = 0;
    auto str = [](std::string crisis, std::pair<int, int> adj){
        return crisis + std::to_string(adj.first) + std::to_string(adj.second);
    };
    std::vector<std::pair<int, int>> adj_rooms;

    // return;
    while(stop < 7){

        update_position();


        auto cur_room = this->current_room();

        if(cur_room.glitter){
            printf("\n******* Found the Gold, Taking the Gold!!!!*********\n");
            return;
        }
        // printf("\n\ncurrent room x = %d y = %d\n\n", cur_room.x, cur_room.y);
        value_list = util::convert_to_value(cur_room, myhouse, wumpus_alive);

        for(auto value: value_list){
            knowledge_base.push_back(value);
        }

        value_list.clear();

        // printf("size : %d\n", knowledge_base.size());
        
        // proofing 
        printf("\nCurrently at x = %d, y=%d \n", cur_x, cur_y);
        adj_rooms = adjecent_rooms(cur_x, cur_y);
          
        // printf("also here %d", cur_x);
        // iterate for each adjecent non visited rooms
        for (auto adj: adj_rooms) {
            // printf("here = %d, %d\n", adj_rooms.size(), myhouse[adj.first][adj.second].visited);
            if(myhouse[adj.first][adj.second].visited){
                 okay_rooms.push(adj);
            }
            else {
                printf("\nAdjecent room at x=%d and y=%d\n", adj.first, adj.second);
                auto str_wumpus = str("wumpus", adj);   
                auto str_pit = str("pit", adj);

                // printf("x=%d, y=%d\n", adj.first, adj.second);
                
                if(wumpus_alive){
                    no_wumpus = proof(knowledge_base, str_wumpus, 1);
                    wumpus_in_room = proof(knowledge_base,str_wumpus, 0); 
                } else{
                    no_wumpus = 1;
                    wumpus_in_room = 0;
                }           
                printf("no_wumpus %d, wumpus %d \n", no_wumpus, wumpus_in_room);

                no_pit = proof(knowledge_base, str_pit, 1);
                pit_in_room = proof(knowledge_base, str_pit, 0);
                printf("no_pit %d, pit %d \n", no_pit, pit_in_room);
                
                
                

                // there is a wumpus there kill him
                // update the knowledge base as that is no wumpus 
                // add it to okay rooms
                // add shoot to the WumpusWorld class
                // no need to proof the existance of wumpus in a room after this
                if(wumpus_in_room){

                    printf("wumpus is in room");
                    char scream = wumpusworld.wumpus_shot(adj);
                    printf("\nscream=%d\n", scream);
                    if(scream){
                        printf("\nWumpus Shot!\n");
                        okay_rooms.push(adj);
                        // no_wumpus = 1;
                        // knowledge_base.push_back(std::vector<Value>{
                        // Value(ValType::Operand, str_wumpus),
                        // Value(ValType::Operator, "not")});
                        wumpus_alive = 0;

                    }else{
                        printf("\nSomething went wrong!\n");
                        return;
                    }
                    
                }
                //  there is a pit there update the knowledge base 
                else if(pit_in_room){
                    printf("\npit in the room\n");
                    knowledge_base.push_back(std::vector<util::Value>{
                        util::Value(util::ValType::Operand, str_pit)});  
                }
            
                // okay room
                // add to okay rooms stack
                // update the knowledge base 
                if(no_pit and no_wumpus){
                    okay_rooms.push(adj);
                    if(wumpus_alive) knowledge_base.push_back(std::vector<util::Value>{
                        util::Value(util::ValType::Operand, str_wumpus),
                        util::Value(util::ValType::Operator, "not")});
                    knowledge_base.push_back(std::vector<util::Value>{
                        util::Value(util::ValType::Operand, str_pit),
                        util::Value(util::ValType::Operator, "not")});   
                    printf("\n****This adjecent room is okay room****");
                }
                
                printf("\n\n");     
            }
        }

        adj_rooms.clear();

        std::pair<int, int> room;
        do{
            room = okay_rooms.top();
            okay_rooms.pop();
            // printf("Going to x=%d y=%d", room.first , room.second);
            // go to that room, only for the UI or change position
        }while(myhouse[room.first][room.second].visited);
       
        // // 
        myhouse[cur_x][cur_y].agent = 0;
        printf("Going to x=%d y=%d", room.first , room.second);
        cur_x = room.first;
        cur_y = room.second; 
        update_position(); 
        printf("\n*****************************************\n");
        printf("Going to next unvisited room at x=%d, y=%d", cur_x, cur_y); 
        printf("\n*****************************************\n");
        stop++;
    }
};