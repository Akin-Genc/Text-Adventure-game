#include "Quest.hpp"

Quest::Quest() : status(NotStarted), enemiesDefeated(0) {}

Quest::Quest(std::string& name, std::string& description)
    : status(NotStarted), title(name), enemiesDefeated(0) {
    objectives.push_back({ description, false });
}

void Quest::start() {
    // Set the quest status to in progress
    status = InProgress;

    // Display a message indicating the quest has started
    std::cout << "Quest '" << title << "' started.\n";

    // Add objectives to the quest
    objectives.push_back({ "Find the diamond in the forest", false });  // 1 quest
    objectives.push_back({ "Defeat enemies", false }); // 2 quest
    objectives.push_back({ "Use the key to open the treasure chest", false }); // 3 quest

    // Display the list of objectives
    std::cout << "Objectives:\n";
    for (size_t i = 0; i < objectives.size(); ++i) {
        std::cout << i + 1 << ". " << objectives[i].description << std::endl;
    }
}

void Quest::update() {
    if (status == InProgress) {
        // Check if all objectives are completed
        if (isObjectiveCompleted()) {
            std::cout << "Objectives completed!\n";
            complete();
        }
        else {
            std::cout << "Keep working on the objectives!\n";
        }
    }
    else {
        std::cout << "Quest '" << title << "' cannot be updated as it has not been started.\n";
    }
}

void Quest::complete() {
    status = Completed;
    std::cout << "Quest '" << title << "' completed!\n";
}

void Quest::enemyDefeated() {
    ++enemiesDefeated;
}

bool Quest::isObjectiveCompleted() const {
    // Check if all objectives and the required number of enemies are defeated
    return std::all_of(objectives.begin(), objectives.end(), [](const Objective& obj) { return obj.completed; }) &&
        enemiesDefeated >= 5; // Change the number as needed
}

 
