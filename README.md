# Week 2 report 

## Description

- First we created a  __Value__ class. A wrapper class for both operands and operators 
- The class contains lambda functions for the operators that does logical operations
  - for instance the lambda function for OR(that is instance of Value class) takes two operands(instances of VALUE class) 
  and does `or` operation.
  Similarly for inverse operation, we use this lambda function. It takes truth value and returns all possible truth table combinations
  ``` c++
    evaluate_inv = +[](char truth){
                  if(truth){
                      return std::vector<std::vector<char>>{{true, true}};
                  }
                  return std::vector<std::vector<char>>{{false, false},
                                                          {true, false},
                                                          {false, true}};
              }; 
  
  ```
  
- Using that __Value__ class, we implemented the semantic tabuleaux function
  ```c++
  char sematic_tabulax(std::vector<std::vector<Value>> premise_conclusion);
  // returns true when the statement is valid, and false otherwise
  ```
  
  The test can be found in the test directory, with the `CMakeLists.txt` file
  
  Next steps:

- We have discussed our approach, and will continue to implement the `agent`,  `model classes`, and the `RuleMatch()` function as discuss in class.
- We will use semantic tabuleax and other helper function to determine and update the next position of the agent. 
