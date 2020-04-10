#include "value.hpp"

using namespace util;

Value::Value(ValType valtype, std::string second_arg){
    val_type = valtype;
    name = second_arg;
    if(valtype == ValType::Operator){
        if(second_arg == "or"){
            count_op_arg = 2;
            evaluate = [](Value a, Value b){
                return a.get_truthvalue() or b.get_truthvalue();
            };
            evaluate_inv = +[](char truth){
                if(truth){
                    return std::vector<std::vector<char>>{{true, true}, 
                                                            {true, false},
                                                            {false, true}};
                }
                return std::vector<std::vector<char>>{{false, false}};
            };                
        }
        else if(second_arg == "and"){
            count_op_arg = 2;
            evaluate  = [](Value a, Value b){
                return a.get_truthvalue() and b.get_truthvalue();
            };
            
            evaluate_inv = +[](char truth){
                if(truth){
                    return std::vector<std::vector<char>>{{true, true}};
                }
                return std::vector<std::vector<char>>{{false, false},
                                                        {true, false},
                                                        {false, true}};
            }; 
        }
        else if(second_arg == "not"){
            count_op_arg = 1;
            evaluate = [](Value a, Value b){
                return not a.get_truthvalue();
            };
            
            evaluate_inv = +[](char truth){
                return std::vector<std::vector<char>>{{not truth}};
            }; 
            
        }
        else{
            printf("Inserted Operator not known");
        }
        
    }
}
