// Item.cpp

#include "Item.hpp"
#include "Enemy.hpp" // Include Enemy0 header

// Constructor implementation
Item::Item(const std::string& name, const std::string& desc, int dmg) : name(name), description(desc), damage(dmg) {}

// Getter methods implementation
std::string Item::GetName() const {
    return name;
}

std::string Item::GetDescription() const {
    return description;
}

int Item::GetDamage() const {
    return damage;
}

// Method to set the damage inflicted by the item
void Item::SetDamage(int dmg) {
    damage = dmg;
}

// Method to use the item on an enemy
void Item::UseOnEnemy(Enemy0& enemy) {
    // Apply item's damage to the enemy
    enemy.TakeDamage(damage);
}
