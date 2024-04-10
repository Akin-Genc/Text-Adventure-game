#include "Player.hpp"
#include "Command.hpp"
#include <sstream> 


CommandInterpreter::CommandInterpreter(Player* player) : player_(player) {}

void CommandInterpreter::interpretCommand(const std::string& command) {
    std::istringstream iss(command);
    std::string action;
    iss >> action;

    if (action == "PickUp" || action == "Pick" || action == "pick") {
        if (player_->GetLocation()->GetItems().empty()) {
            std::cout << "There are no items to pick up in this room.\n";
        }
        else {
            Item itemToPickUp = player_->GetLocation()->GetItems()[0];
            player_->Pick_up(itemToPickUp);
            player_->AddToInventory(itemToPickUp);
            player_->GetLocation()->RemoveItem(itemToPickUp.GetName());
        }
    }
    else if (action == "Look" || action == "look") {
        player_->look();
    }
    else if (action == "Attack" || action == "attack") {
        std::cout << "You are attacking the NPC.\n";
        // You might want to call a function on the NPC object to handle the attack
    }
    else if (action == "Talk" || action == "talk") {
        std::cout << "You are talking to the NPC.\n";
        // You might want to call a function on the NPC object to handle the conversation
    }
    else {
        std::cout << "Unknown command.\n";
    }
}
   