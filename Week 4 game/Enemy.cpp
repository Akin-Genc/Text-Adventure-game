#include "Enemy.hpp"

#include "Player.hpp"

// Constructor with three parameters
Enemy0::Enemy0(const std::string& name, const std::string& description, int healthPoints)
    : name(name), description(description), healthPoints(healthPoints), healthBar(healthPoints), associatedQuest(nullptr) {}

// Constructor with four parameters
Enemy0::Enemy0(const std::string& _name, const std::string& _description, int _healthPoints, Quest* quest)
    : name(_name), description(_description), healthPoints(_healthPoints), healthBar(_healthPoints), associatedQuest(quest) {}

// Attack method
void Enemy0::attack(int damage) {
    healthPoints -= damage;
    healthBar.SetHealth(healthPoints);
    if (!isAlive()) {
        notifyDefeat(); // Notify the associated quest when the enemy is defeated
    }
}

// Check if the enemy is alive
bool Enemy0::isAlive() const {
    return healthPoints > 0;
}

// Display enemy information
void Enemy0::displayInfo() const {
    healthBar.GetHealthBar();
}

// Notify the associated quest when the enemy is defeated
void Enemy0::notifyDefeat() {
    if (associatedQuest != nullptr) {
        associatedQuest->enemyDefeated();
    }
}



int Enemy0::GetHealth() const {
    return healthPoints;
}

std::string Enemy0::GetName() const {
    return name;
}

void Enemy0::TakeDamage(int damage) {
    healthPoints -= damage;
    if (healthPoints < 0) {
        healthPoints = 0;
    }
    // Update the health bar with the new health value
    healthBar.SetHealth(healthPoints);

}

std::string Enemy0::EGetHealthBar() const {
    return healthBar.EGetHealthBar(); // Return the health bar string from the healthBar member
}