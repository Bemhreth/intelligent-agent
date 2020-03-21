# Intelligent Agent Desciption

## Useful Pseudo codes
```
Program evaluation
Given not (p imp q)  
Convert it into postfix :  p q impnot
Algorithm:
Start iterating from the first index 
If pointer on operad:
            Push to the stack
        If pointer on operator:
            Pop from the stack values the operator can take
            result = apply operator on values
            Push result
              Increment pointer 
    
Semantic tableaux implementation:
Algorithm
Start iterating from the last index
Push the given truth_value into the stack
If pointer on operator:
    Pop truth_value from the stack
    [truth_values] = Call operator_inv(truth_value)
    Push truth_values to the stack
If the pointer on operand:
    pop truth_value from the stack
Map operand to truth_value -> map[p] = True

```

## Definitions

- __Intelligent Agent__:  an agent that perceives and acts on the environment 
- __Agent function__: a procedure that maps a perception to an action 
- __agent program__: the actual implementation of the agent function
- __Percept history__: it’s the complete history that the agent perceived 

### Types of Agents:

- __Simple reflex agent__ detects a perception and sends action. For every perception, it has an action mapped to it.
- __Model-based reflex agent__
  - __Model__: It’s the general knowledge of things and rules of the environment 
  - __Agent’s internal state__: It’s the representation of the current state-based on percept history and previous actions 
  - __Deductive system__: the agent function must contain a deductive mechanizable procedure. It is the system that uses the model and the agent’s internal state

> The model needs to recorded. Every time agent perceives the internal state record should change

- __Learning agent__: a learning agent that can extract knowledge or model from the environment. It can find a new axiom from the environment.

# Wumpus World Game

It has :

1. one room of rumpus
2. 3 rooms of pits
3. 1 room of Gold

> __Goal__:  find the gold and shoot the wumpus while avoiding being eaten by the Wumpus and falling into the pits

### Model

- Rooms adjacent to rumpus stitch
- Rooms adjacent to pits breeze 
- Rooms with Gold glitter
- The agent has one arrow
- If you shoot at the wumpus, Wumpus dies
- If wumpus an agent are in the same room rumpus will kill the agent 
- One wumpus, 3pits and 1 gold are instantiated randomly, position 1, 2 and 2, 1 are empty
the start position of the agent is 1,1

#### Actuators 
- move forward 
- turn left 
- turn right 
- shoot


#### Sensors 
- stink
- glitter
- breeze 
- bump 
- scream

#### State variables 

- Pij is true if there is a pit in the room
- Bij is true if an agent perceives a breeze in a room ij
- Wij is true is there’s a rumpus in-room ij
- Sij is true if an agent perceives stench from ij
- Vij is true room ij is visited 
- Gij if there is gold in-room ij
- Okij is true if room ij is OK to visit


### Sample agent program

Model-Based Reflex Agent  - returns an action
persistent states :
state: agent’s internal perception
Model: a general description of the world
Rules: a set of condition action and rules

#### Procedures 
1. agent perceives
2. If there is a stench, there is wumpus around, etc.
3. Call Rule_match(state, model) which maps state to action

> For instance, if there is wumpus at agent, Rule_match returns shoot 

### _Rule_match function_
```
# Survival is a high priority

for each adjacent room:
    if (Wumpus is in the room)
        return shoot
    if(there is Gold in rooms)
        return go to room
    if(room is okay)
        add to Okay rooms
ok rooms.pop()
returns goto ok_rooms
```
> Are Ok rooms only the visited rooms?

- How to prove there is a wumpus in the room model?
> Using contradiction, try to prove there is no Wumpus in the room, or all the adjacent rooms doesn’t stink

- All visited rooms’ state is the premise, whereas the conclusion is there is no wumpus in the room
__Steps__ :
  - Take all percept history and state
  - Take the state of the premises
  - Substitute the conclusion by the value from the model
  - Construct the semantic tableaux or evaluate 


