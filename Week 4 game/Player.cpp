#include "Player.hpp"

Player::Player(const std::string& name, int health) : Character(name, health), location(nullptr), healthBar(health) {}

void Player::SetLocation(Room* room) {
    location = room;
}

Room* Player::GetLocation() {
    return location;
}

std::string Player::GetHealthBar() const {
    return healthBar.GetHealthBar(); // Delegate to the HealthBar object
}

std::string Player::UpdateHealthBar() {
    healthBar.SetHealth(GetHealth()); // Update the health bar with the player's current health
    return healthBar.GetHealthBar(); // Return the updated health bar string
}

void Player::Pick_up(Item& item) {
    std::cout << "\033[34m" << "You picked up the " << "\033[33m" << item.GetName() << "." << "\033[0m" << std::endl;
}

void Player::look() {
    std::cout << "Player has looked so sym\n";
}

void Player::AddToInventory(const Item& item) {
    inventory.push_back(item);
}

void Player::Move(const std::string& direction) {
    // Get the exit room in the specified direction
    Room* nextRoom = location->GetExit(direction);
    if (nextRoom != nullptr) {
        // Update player's location
        location = nextRoom;
        std::cout << "You move to the " << direction << ".\n";
    }
    else {
        std::cout << "You can't go that way.\n";
    }
}

bool Player::IsAlive() const {
    return GetHealth() > 0;
}

void Player::Attack(Enemy0& enemy) {
    // Check if the player has a weapon equipped
    if (equippedWeapon != nullptr) {
        int damage = equippedWeapon->GetDamage(); // Use the damage value of the equipped weapon
        enemy.TakeDamage(damage);
        std::cout << GetName() << " attacks " << enemy.GetName() << " with " << equippedWeapon->GetName() << " for " << damage << " damage!" << std::endl;
    }
    else {
        // If no weapon is equipped, default to a base damage
        int damage = 10; // Default base damage
        enemy.TakeDamage(damage);
        std::cout << GetName() << " attacks " << enemy.GetName() << " for " << damage << " damage!" << std::endl;
    }
}

void Player::UseItemOnEnemy(Enemy0& enemy, const std::string& itemName) {

    // Find the item in the player's inventory
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->GetName() == itemName) {
            // Apply item's damage to the enemy
            int damage = it->GetDamage(); 
            enemy.TakeDamage(damage);
            std::cout << "You used " << itemName << " on the enemy and dealt " << damage << " damage!" << std::endl;
            // Remove the item from the player's inventory after use
            inventory.erase(it);
            return;
        }
    }
    std::cout << "Item not found in inventory." << std::endl;
}

void Player::DisplayInventory() const {
    std::cout << "\nInventory:\n";
    for (size_t i = 0; i < inventory.size(); ++i) {
        std::cout << i + 1 << ". " << inventory[i].GetName() << ": " << inventory[i].GetDescription() << std::endl;
    }
}

void Player::Attack(Enemy0& enemy, const std::string& move) {
    int damage = 0;

    if (move == "punch") {
        // Calculate damage for punch
        int punchDamage = 10; // Example value, adjust as needed
        damage = punchDamage;

        // Deduct stamina for punch
        int punchStaminaCost = 5; // Example value, adjust as needed
        stamina -= punchStaminaCost;
    }
    else if (move == "kick") {
        // Calculate damage for kick
        int kickDamage = 15; // Example value, adjust as needed
        damage = kickDamage;

        // Deduct stamina for kick
        int kickStaminaCost = 10; // Example value, adjust as needed
        stamina -= kickStaminaCost;
    }

    // Apply damage to the enemy
    enemy.TakeDamage(damage);
}