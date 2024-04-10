
#ifndef CHARATER_HPP
#define CHARATER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Item.hpp"
// Include Item header

class Character {
private:
    std::string name;
    int health;
    std::vector<Item> inventory;



public:
    Character(const std::string& name, int health);
    virtual void TakeDamage(int damage);
    const std::string& GetName() const;
    int GetHealth() const;
    void AddItem(const Item& item);
    void RemoveItem(const std::string& itemName);
    const std::vector<Item>& GetInventory() const;
   

};


#endif 
