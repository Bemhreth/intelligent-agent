#include "functions_header.hpp"

// function takes a list of premise and conclusion and proves if the statement 
//  valid or not
namespace util {

    char sematic_tabulax(std::vector<std::vector<Value>> premise_conclusion){
        std::vector<std::map<std::string, char>> prev_map{{}};
        std::vector<std::vector<std::map<std::string, char>>> curr_map;
        std::vector<std::map<std::string, char>> next_map;
        std::vector<std::vector<std::stack<char>>> truth_val_stacks;

        for(int i=0; i<premise_conclusion.size(); i++){
            // clear the vector and intialize a stack inside it
            truth_val_stacks.clear();
            truth_val_stacks.push_back(std::vector<std::stack<char>>());
            truth_val_stacks[0].push_back(std::stack<char>());
            // For the premises true is push to the stack and false for the conclusion
            // in this case it's the last value in the vector
            if(i < premise_conclusion.size()-1) truth_val_stacks[0][0].push(true);
            else truth_val_stacks[0][0].push(false);
            // Iterating for each Value instances in each premise 
            // Given in the from of p V q == p q V. 
            // p q and V are all instances of Value class
            for(auto iterator = premise_conclusion[i].rbegin(); 
                iterator != premise_conclusion[i].rend(); iterator++){

                auto value = *iterator;
                if(value.val_type == ValType::Operator){
                    std::vector<std::vector<std::vector<char>>> combinations;
                    for(auto truth_vector: truth_val_stacks)
                        for(auto truth_stack: truth_vector){ 
                            combinations.push_back(value.evaluate_inv(truth_stack.top()));
                            truth_stack.pop();
                        }
                    
                    for (auto first=0; first < combinations.size(); first++) {
                        if( first >= truth_val_stacks.size())
                            truth_val_stacks.push_back(std::vector<std::stack<char>>());
                        for (auto j=0; j < combinations[first].size(); j++)
                            for(auto&& truth: combinations[first][j]){
                                if(j >= truth_val_stacks[first].size()) {
                                    truth_val_stacks[first].push_back(std::stack<char>());  
                                } truth_val_stacks[first][j].push(truth);
                            }    
                    }                               
                }
                else {
                    for(auto k=0; k < truth_val_stacks.size(); k++){
                        if(truth_val_stacks.size() != curr_map.size()){
                            for(auto z=0; z < truth_val_stacks[k].size(); z++){
                                if(z >= curr_map.size()) 
                                    curr_map.push_back(std::vector<std::map<std::string, char>>());
                                char truth_eval = truth_val_stacks[k][z].top();
                                truth_val_stacks[k][z].pop();
                                if(z >= curr_map[k].size()) 
                                    curr_map[z].push_back(std::map<std::string, char>());
                                curr_map[z][k].insert({value.name, truth_eval});
                            }
                        }else {
                            std::map<std::string, char> dup = curr_map[k][0];
                            for(auto z=0; z < truth_val_stacks[k].size(); z++){  
                                char truth_eval = truth_val_stacks[k][z].top();
                                truth_val_stacks[k][z].pop();
                                if(z >= curr_map[k].size()) curr_map[k].push_back(dup);
                                curr_map[k][z].insert({value.name, truth_eval});
                            }
                        }
                    
                    }
                    //   auto a = curr_map;
                    //     printf("\n\n\n i = %d \n", i);
                    //     for(auto d: a) {
                    //         for(auto b: d){
                    //             for(auto c: b){
                    //                 printf("%s=%d,  ", c.first.c_str(), c.second);
                    //             }
                    //             printf("\n");
                    //         }
                    //         printf("\n");
                    //     }
                    //     printf("\n\n");
            
                }

            }
        std::vector<std::map<std::string, char>> curr_map_temp; 
        for(auto a: curr_map){
            for (auto b: a){
                if(b.size() > 0) curr_map_temp.push_back(b);
            }
        }
        // for(auto a: curr_map_temp){
        //     for(auto b: a){
        //         printf("%s=%d, ", b.first.c_str(), b.second);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
        // Compare maps of logical values 
        char insert = true;
        for(auto curr: curr_map_temp){ 
            for(auto prev: prev_map){
                auto temp = curr;
                for(auto element: prev){
                        auto check = temp.insert(element);  
                    if(!check.second and \
                        check.first->second != element.second){
                            insert = false;
                            break;
                        }
                }
                if(insert){
                    next_map.push_back(temp);              
                }insert = true;
            }
        }       
        prev_map = next_map;
        next_map.clear();

        curr_map.clear(); 
        curr_map_temp.clear(); 
        }
        return prev_map.empty();
    };
};
