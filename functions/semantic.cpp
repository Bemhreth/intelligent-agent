#include "func_headers.h"

// function takes a list of premise and conclusion and proves if the statement 
//  valid or not
char sematic_tabulax(std::vector<std::vector<Value>> premise_conclusion){
    std::vector<std::map<std::string, char>> prev_map{{}};
    std::vector<std::map<std::string, char>> curr_map;
    std::vector<std::map<std::string, char>> next_map;
    std::vector<std::stack<char>> truth_val_stacks;

    for(int i=0; i<premise_conclusion.size(); i++){
        // clear the vector and intialize a stack inside it
        truth_val_stacks.clear();
        truth_val_stacks.push_back(std::stack<char>());
        // For the premises true is push to the stack and false for the conclusion
        // in this case it's the last value in the vector
        if(i < premise_conclusion.size()-1) truth_val_stacks[0].push(true);
        else truth_val_stacks[0].push(false);
        // Iterating for each Value instances in each premise 
        // Given in the from of p V q == p q V. 
        // p q and V are all instances of Value class
        for(auto iterator = premise_conclusion[i].rbegin(); 
        iterator != premise_conclusion[i].rend(); iterator++){
            auto value = *iterator;
            if(value.val_type == ValType::Operator){
                std::vector<std::vector<std::vector<char>>> combinations;
                for(auto truth_stack: truth_val_stacks){ 
                    combinations.push_back(value.evaluate_inv(truth_stack.top()));
                    truth_stack.pop();
                }
                
                for (auto&& first_stage: combinations) 
                    for (auto j=0; j < first_stage.size(); j++)
                        for(auto&& truth: first_stage[j]){
                            if(j >= truth_val_stacks.size()) {
                                truth_val_stacks.push_back(std::stack<char>());  
                            } truth_val_stacks[j].push(truth);
                        }                                   
            }
            else {

                for(auto k=0; k < truth_val_stacks.size(); k++){
                    char truth_eval = truth_val_stacks[k].top();
                    truth_val_stacks[k].pop();
                    if(k >= curr_map.size()) curr_map.push_back(std::map<std::string, char>());
                    curr_map[k].insert({value.name, truth_eval});
                }
            }

        }
    // Compared maps of logical values 
    char insert = true;
    for(auto curr: curr_map){ 
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
    }
    return prev_map.empty();
}
