#ifndef VALUE_H
#define VALUE_H

#include <iostream>
#include <string>
#include <bits/stdc++.h>

enum class ValType{
    Operator,
    Operand,
};

class Value{

    private:
    
        char truth_value; 

    public:
    
        std::string name;
        
        ValType val_type;
        // how many arguments does this operator need
        // might be removed later since it's not needed
        int count_op_arg;
        // lambda function for to evaluate logical operators 
        std::function<char(Value, Value)> evaluate;
        // lambda function for to evaluate the inverse of logical operators       
        std::function<std::vector<std::vector<char>>(char)> evaluate_inv;
        //  truth_value getter and setter methods for operands 

        Value(ValType valtype, std::string second_arg);

        char set_truth_value(char value){truth_value = value;};
        char get_truthvalue() const{return truth_value;};
        
    
        friend char operator==(const Value &left, const Value &right){
            return not(left.get_truthvalue() xor right.get_truthvalue());
        };
        friend char operator<(const Value &left, const Value &right){
            return left.get_truthvalue();
        };

};
 
#endif
