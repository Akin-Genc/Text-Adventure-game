#include "Room.hpp"
#include "Charater.hpp"
#include "NPC.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include <iostream>


Room::Room(const std::string& desc) : description(desc) {}

// Method to add an item to the room
void Room::AddItem(const Item& item) {
    items.push_back(item);
}

// Method to remove an item from the room
void Room::RemoveItem(const std::string& itemName) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->GetName() == itemName) {
            items.erase(it);
            break;
        }
    }
}

// Method to add an enemy to the room
void Room::AddEnemy(const Enemy0& enemy) {
    enemies.push_back(enemy);
}

// Method to add an exit to the room
void Room::AddExit(const std::string& direction, Room* room) {
    exits[direction] = room;
}

// Method to get the room description
std::string Room::GetDescription() const {
    return description;
}

// Method to get the items in the room
const std::vector<Item>& Room::GetItems() const {
    return items;
}

// Method to set the room description
void Room::SetDescription(const std::string& desc) {
    description = desc;
}

// Method to get the exit in a specific direction
Room* Room::GetExit(const std::string& direction) const {
    auto it = exits.find(direction);
    if (it != exits.end()) {
        return it->second;
    }
    return nullptr;
}

// Method to interact with an item in the room
void Room::InteractWithItem(const std::string& itemName) {
    // Implementation depends on your game logic
}

// Method to get the opposite direction of a given direction
std::string Room::GetOppositeDirection(const std::string& direction) const {
    if (direction == "north") return "south";
    if (direction == "south") return "north";
    if (direction == "east") return "west";
    if (direction == "west") return "east";
    return "";
}

// Method to get the quests in the room
std::vector<Quest>& Room::GetQuests() {
    return quests;
}

int getRandomNumber(int min, int max) {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate a random number between min and max
    return rand() % (max - min + 1) + min;
}

void Room::StartBattle(Player& player, Enemy0& enemy) {
    std::cout << "An enemy " << enemy.GetName() << " appears!\n";

    bool playerTurn = true; // Flag to track whose turn it is

    while (player.IsAlive() && enemy.isAlive()) {
        DisplayBattleStatus(player, enemy);

        // Determine whose turn it is
        if (playerTurn) {
            PlayerAction action = PromptPlayerAction(player);
            switch (action) {
            case PlayerAction::Attack:
                player.Attack(enemy);
                std::cout << "You attacked the enemy!\n";
                std::cout << "Enemy Health: " << enemy.EGetHealthBar() << std::endl; // Update enemy health bar
                break;
            case PlayerAction::UseItem:
                UseItem(player, enemy);
                break;
            case PlayerAction::Run:
                if (CanEscape()) {
                    std::cout << "You successfully escaped!\n";
                    return;
                }
                else {
                    std::cout << "You failed to escape!\n";
                }
                break;
            }
        }
        else {
            // Enemy's turn
            std::cout << "The enemy attacks you!\n";

            // Calculate the chance for the player to dodge (e.g., 20%)
            int dodgeChance = 20; // Adjust as needed

            // Generate a random number between 1 and 100
            int randomNumber = getRandomNumber(1, 100);

            // Check if the random number is within the dodge chance range
            if (randomNumber <= dodgeChance) {
                // Player successfully dodges the enemy's attack
                std::cout << "You dodge the enemy's attack!\n";
            }
            else {
                // Player fails to dodge and takes damage
                std::cout << "You failed to dodge the enemy's attack!\n";
                // Apply damage to the player
            }
        }

        // Toggle turn
        playerTurn = !playerTurn;
    }

    // Check battle outcome
    if (player.IsAlive()) {
        std::cout << "You defeated the enemy!\n";
    }
    else {
        std::cout << "You were defeated by the enemy!\n";
    }
}

void Room::DisplayBattleStatus(const Player& player, const Enemy0& enemy) const {
    std::cout << "Player Health: " << player.GetHealthBar() << std::endl;
    std::cout << "Enemy Health: " << enemy.EGetHealthBar() << std::endl;

}


PlayerAction Room::PromptPlayerAction(const Player& player) const {
    int choice;
    std::cout << "Choose an action:\n";
    std::cout << "1. Attack\n";
    std::cout << "2. Use Item\n";
    std::cout << "3. Run\n";
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Choose attack move:\n";
        std::cout << "a. Punch\n";
        std::cout << "b. Kick\n";
        char attackChoice;
        std::cin >> attackChoice;
        std::string move;
        int damage = 0;

        if (attackChoice == 'a') {
            move = "punch";
            // Calculate damage for punch
            int punchDamage = 10; // Example value, adjust as needed
            damage = punchDamage;

            // Deduct stamina for punch
            int punchStaminaCost = 5; // Example value, adjust as needed

        }
        else if (attackChoice == 'b') {
            move = "kick";
            // Calculate damage for kick
            int kickDamage = 15; // Example value, adjust as needed
            damage = kickDamage;

            // Deduct stamina for kick
            int kickStaminaCost = 10; // Example value, adjust as needed

        }
        // Player attacks the enemy, dealing damage
        Enemy0 enemy("Ottom Soldier", "A formidable Ottom soldier guarding the ancient ruins", 50); // Create enemy based on room description

        // Now you can call the TakeDamage method on the enemy object
        enemy.TakeDamage(damage);

        // Check if the enemy is still alive
        if (enemy.isAlive()) {
            // Enemy survived the attack, you can display its updated health bar
            std::cout << "Enemy's Health Bar: " << enemy.EGetHealthBar() << std::endl;
        }
        else {
            // Enemy was defeated
            std::cout << "Enemy defeated!" << std::endl;

        
        }
    }

        if (choice == 2) {
            // Display player's inventory
            player.DisplayInventory();
            std::cout << "Enter the number of the item you want to use: ";
            std::cin >> choice;

            // Perform input validation
            if (choice > 0 && choice <= player.GetInventory().size()) {
                // Get the selected item from the inventory
                const Item& selectedItem = player.GetInventory()[choice - 1];

                // Apply the item's effects on the enemy
                int damage = selectedItem.GetDamage();

                std::cout << "You used " << selectedItem.GetName() << " on the enemy and dealt " << damage << " damage!\n";



                return PlayerAction::UseItem;
            }
            else {
                std::cout << "Invalid item selection.\n";
                return PromptPlayerAction(player); // Prompt again after invalid selection
            }
        }


        else if (choice == 3) {
            // Check if the player can escape
            if (CanEscape()) {
                std::cout << "You successfully escaped!\n";
                std::cout << "Quest failed!\n"; // Display quest failed message
                return PlayerAction::Run;
            }
            else {
                std::cout << "You failed to escape!\n";
                return PromptPlayerAction(player); // Prompt again after failure to escape
            }
        }

        return static_cast<PlayerAction>(choice);
    }




void Room::UseItem(Player& player, Enemy0& enemy) {
    // Check if the player's inventory is empty
    if (player.GetInventory().empty()) {
        std::cout << "Your inventory is empty. No items to use.\n";
        return;
    }

    
    // Display the player's inventory and prompt for item selection
    std::cout << "Inventory:\n";
    int itemCount = 1;
    for (const Item& item : player.GetInventory()) {
        std::cout << itemCount << ". " << item.GetName() << " - Attack Damage: " << item.GetDamage() << std::endl;
        itemCount++;
        
    }
    std::cout << "Enter the number of the item you want to use: ";
    int choice;
    std::cin >> choice;

    // Perform input validation
    if (choice <= 0 || choice > player.GetInventory().size()) {
        std::cout << "Invalid item selection.\n";
        return;
    }

    // Get the selected item from the inventory
    const Item& selectedItem = player.GetInventory()[choice - 1];

    // Apply the item's effects on the enemy
    int damage = selectedItem.GetDamage();
    enemy.TakeDamage(damage);
    std::cout << "You used " << selectedItem.GetName() << " on the enemy and dealt " << damage << " damage!\n";

}

 bool Room::CanEscape() const {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random number between 0 and 1
    int chance = std::rand() % 2; // 0 or 1

    // Return true if the random number is 0 (50% chance of success)
    return chance == 0;
}
 

 void Room::LookInForestRoom(Player& player, bool isInForestRoom) {
     // Check if the room is the forest room
     if (isInForestRoom) {
         // Check if the player has already completed the quest
         if (!questCompleted) {
             // Display options for finding the diamond
             std::cout << "You are in the forest. You see something shining in the distance.\n";
             std::cout << "1. Approach it\n";
             std::cout << "2. Leave it\n";

             int choice;
             std::cin >> choice;

             if (choice == 1) {
                 // Implement logic for approaching the shining object
                 std::cout << "You cautiously approach the shining object...\n";
                 std::cout << "You find a beautiful diamond hidden in the foliage!\n";
                 std::cout << "Next to the diamond, you also find a sharp sword!\n";
                 std::cout << "Do you want to pick up the diamond? (yes/no): ";

                 std::string pickupChoice;
                 std::cin >> pickupChoice;

                 if (pickupChoice == "yes") {
                     // Add the diamond to the player's inventory
                     player.AddItem(Item("Diamond", "A sparkling diamond", 1));
                     // Add a sword to the player's inventory
                     player.AddItem(Item("Sword", "A sharp sword", 15));

                     std::cout << "You pick up the diamond and add it to your inventory.\n";
                     std::cout << "You also find a sharp sword and add it to your inventory.\n";

                     // Mark the quest as completed
                     questCompleted = true;
                 }
                 else {
                     std::cout << "You decide to leave the shining object for now.\n";
                 }
             }
             else if (choice == 2) {
                 // Optionally, handle the case where the player decides not to approach the object
                 std::cout << "You decide to leave the shining object for now.\n";
             }
             else {
                 std::cout << "Invalid choice.\n";
                 // Optionally, handle invalid choices
             }
         }
         else {
             // Player has already completed the quest
             std::cout << "You have already found the diamond and the sword.\n";
             std::cout << "You don't see anything special here.\n";
         }
     }
     else {
         // Implement default behavior for other rooms
         std::cout << "You don't see anything special here.\n";
     }
 }

