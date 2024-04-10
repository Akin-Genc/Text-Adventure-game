#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Item.hpp"
#include "Quest.hpp"
#include "Enemy.hpp" // Include Enemy header

enum class PlayerAction {
    Attack,
    UseItem,
    Run
};

class Player; // Forward declaration

class Room {
public:
    Room(const std::string& desc);

    void AddItem(const Item& item);
    void RemoveItem(const std::string& itemName);
    void AddEnemy(const Enemy0& enemy); // Updated to Enemy0

    void AddExit(const std::string& direction, Room* room);
    std::string GetDescription() const;
    const std::vector<Item>& GetItems() const;
    void SetDescription(const std::string& desc);
    Room* GetExit(const std::string& direction) const;
    void InteractWithItem(const std::string& itemName); // New function to interact with items
    std::string GetOppositeDirection(const std::string& direction) const;
    std::vector<Quest>& GetQuests();

    void StartBattle(Player& player, Enemy0& enemy);
    void DisplayBattleStatus(const Player& player, const Enemy0& enemy) const;
    PlayerAction PromptPlayerAction(const Player& player) const;
    void UseItem(Player& player, Enemy0& enemy);
    bool CanEscape() const;
    int generateDamage();
    void LookInForestRoom(Player& player, bool isInForestRoom);

private:
    std::string description;
    std::vector<Item> items;
    std::vector<Enemy0> enemies; // Updated to Enemy0
    bool questCompleted;
    std::map<std::string, Room*> exits;
    std::vector<Quest> quests;
};

#endif // ROOM_HPP


