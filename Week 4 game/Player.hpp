#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Charater.hpp" // Include Character header
#include "Room.hpp"      // Include Room header
#include "HealthBar.hpp"
#include "Enemy.hpp"      // Include Enemy header
#include <vector>
#include <string>

class Player : public Character {
private:
    Room* location;
    HealthBar healthBar; // Declare healthBar member variable
    std::vector<Item> inventory;
    Item* equippedWeapon;
    int stamina;
public:
    Player(const std::string& name, int health);
    void SetLocation(Room* room);
    Room* GetLocation();
    std::string GetHealthBar() const;
    std::string UpdateHealthBar();
    void Pick_up(Item& item);
    void look();
    void AddToInventory(const Item& item);
    void Move(const std::string& direction);
    bool IsAlive() const;
    void Attack(Enemy0& enemy);
    void UseItemOnEnemy(Enemy0& enemy, const std::string& itemName);
    void DisplayInventory() const;
    void Attack(Enemy0& enemy, const std::string& move);
};

#endif // PLAYER_HPP

 