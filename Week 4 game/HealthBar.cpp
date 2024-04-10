
#include "HealthBar.hpp"

HealthBar::HealthBar(int initialHealth) : health(initialHealth) {}

std::string HealthBar::GetHealthBar() const {
   
    int maxLength = 100; // Choose the length of the health bar
    int filledBlocks = (health * maxLength) / 100;
    int emptyBlocks = maxLength - filledBlocks;

    std::string healthBar = "\033[34m[";
    for (int i = 0; i < filledBlocks; ++i) {
        healthBar += "\033[32m#";
    }
    for (int i = 0; i < emptyBlocks; ++i) {
        healthBar += "\033[31m#";
    }
    healthBar += "\033[34m]\033[0m";

    return healthBar;
}

void HealthBar::SetHealth(int newHealth) {
    health = newHealth;
}

 
std::string HealthBar::EGetHealthBar() const {

    int maxLength = 100; // Choose the length of the health bar
    int filledBlocks = (health * maxLength) / 50;
    int emptyBlocks = maxLength - filledBlocks;

    std::string healthBar = "\033[34m["; // Purple color
    for (int i = 0; i < filledBlocks; ++i) {
        healthBar += "\033[35m#"; // Green color for filled blocks
    }
    for (int i = 0; i < emptyBlocks; ++i) {
        healthBar += "\033[31m#"; // Red color for empty blocks
    }
    healthBar += "\033[35m]\033[0m"; // Purple color

    return healthBar;
}


void HealthBar::ESetHealth(int newHealth) {
    health = newHealth;
}



