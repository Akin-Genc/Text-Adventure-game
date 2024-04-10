// Item.hpp

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

// Forward declaration of the Enemy0 class
class Enemy0;

class Item {
private:
    std::string name;
    std::string description;
    int damage; // Damage inflicted by the item

public:
    // Constructor
    Item(const std::string& name, const std::string& desc, int dmg = 0);

    // Getter methods
    std::string GetName() const;
    std::string GetDescription() const;
    int GetDamage() const;

    // Interaction method (to be implemented)
    void Interact();

    // Method to set the damage inflicted by the item
    void SetDamage(int dmg);

    // Method to use the item on an enemy
    void UseOnEnemy(Enemy0& enemy);
};

#endif // ITEM_HPP
