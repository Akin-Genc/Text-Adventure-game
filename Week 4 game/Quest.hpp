
#ifndef QUEST_HPP
#define QUEST_HPP

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

struct Objective {
    std::string description;
    bool completed;
};

enum QuestStatus {
    NotStarted,
    InProgress,
    Completed
};

class Quest {
public: // Remove the private specifier
    std::string title;
    QuestStatus status;
    std::vector<Objective> objectives;
    int enemiesDefeated; // Number of enemies defeated

public: // Move public methods below
    Quest();
    Quest(std::string& name, std::string& description);
    void start();
    void update();
    void complete();
     // Method to handle enemy defeat
    void enemyDefeated();
    bool isObjectiveCompleted() const;
};

#endif // QUEST_HPP

