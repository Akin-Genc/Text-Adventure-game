#include "Charater.hpp"
#include "Player.hpp"

Character::Character(const std::string& name, int health) : name(name), health(health) {

}

void Character::TakeDamage(int damage) {
    health -= damage;

    if (0 > health) {
    
        health = 0;
    }

   
}

const std::string& Character::GetName() const {
    return name;
}

int Character::GetHealth() const {
    return health;
}


void Character::AddItem(const Item& item) {
    inventory.push_back(item);
}

void Character::RemoveItem(const std::string& itemName) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->GetName() == itemName) {
            inventory.erase(it);
            return;
        }
    }
}

const std::vector<Item>& Character::GetInventory() const {
    return inventory;
}
