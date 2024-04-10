#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>
#include "HealthBar.hpp"  // Include HealthBar header
#include "Item.hpp"
#include "Charater.hpp"

class Quest; // Forward declaration

class Enemy0 {
private:
    std::string name;
    std::string description;
    int healthPoints;
    HealthBar healthBar;

    // Pointer to the quest this enemy is associated with
    Quest* associatedQuest;

public:
    Enemy0(const std::string& name, const std::string& description, int healthPoints);
    Enemy0(const std::string& _name, const std::string& _description, int _healthPoints, Quest* quest);

    void attack(int damage);
    bool isAlive() const;
    void displayInfo() const;
    // Notify the associated quest when the enemy is defeated
    void notifyDefeat();
    std::string EGetHealthBar() const;
    int GetHealth() const;
    std::string GetName() const;
    void TakeDamage(int damage);
   
};

#endif // ENEMY0_HPP