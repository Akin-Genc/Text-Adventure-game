#include "NPC.hpp"
#include <cstdlib> // For random number generation
#include <ctime>   // For seeding the random number generator

NPC::NPC(State initialState) : currentState(initialState) {
    // Constructor implementation
    dialogue = "Hello, I am an NPC.";
}

void NPC::update() {
    // Implement state-based behavior
    switch (currentState) {
    case Idle:
        std::cout << "NPC is idling.\n";
        break;
    case Aggressive:
        std::cout << "NPC is aggressive!\n";
        break;
    case Fleeing:
        std::cout << "NPC is fleeing!\n";
        break;
    }
}

void NPC::approach() {
    std::cout << "NPC approaches the player.\n";
}

void NPC::interactWithPlayer() {
    // Generate a random number to determine the dialogue
    int randomNum = rand() % 3; // Change 3 to the number of dialogue options you have

    // Assign dialogue based on the random number
    switch (randomNum) {
    case 0:
        dialogue = "I'm not sure what you're talking about.";
        break;
    case 1:
        dialogue = "Interesting...";
        break;
    case 2:
        dialogue = "I don't have time for this.";
        break;
    }

    // Display NPC's dialogue
    std::cout << "NPC: " << dialogue << std::endl;

    // Player responds
    std::string playerResponse;
    std::cout << "Player: ";
    std::getline(std::cin, playerResponse);

    // Change NPC's state based on player response
    if (playerResponse == "Attack") {
        currentState = Aggressive;
        dialogue = "You dare challenge me? Prepare to fight!";
    }
    else if (playerResponse == "Flee") {
        currentState = Fleeing;
        dialogue = "I must run!";
    }
    else {
        dialogue = "Hmm, interesting.";
    }
}

void NPC::SetState(State state) {
    currentState = state;
}

void NPC::SetDialogue(const std::string& newDialogue) {
    dialogue = newDialogue;
}

