#ifndef NPC_HPP
#define NPC_HPP

#include <iostream>
#include <string>

class NPC {
private:
    enum State { Idle, Aggressive, Fleeing };
    State currentState;
    std::string dialogue;

public:
    NPC(State initialState);
    void update();
    void approach();
    void interactWithPlayer();
    void SetState(State state);
    void SetDialogue(const std::string& newDialogue);
};

#endif // NPC_HPP
