#include <iostream>
#include <vector>
#include <map>
#include "Room.hpp"       // Include Room header
#include "Item.hpp"       // Include Item header
#include "Charater.hpp"   // Include Character header
#include "Player.hpp"     // Include Player header
#include "Area.hpp"       // Include Area header
#include "Command.hpp"
#include "NPC.hpp"
#include "Quest.hpp"
#include "Enemy.hpp"
#include "StartScreen.hpp"
#include <Windows.h>

#pragma comment(lib, "winmm.lib")


 

int main() {

   
    // Play the music file "Desert.wav"
    PlaySound(TEXT("Desert.wav"), NULL, SND_FILENAME | SND_ASYNC);

    // Wait for some time to let the music play (replace this with your game logic)
  

  
    StartScreen startScreen;
    startScreen.Display();

    // Get user input from the start screen
    char userInput = startScreen.GetInput();

    // Check the user's choice
    if (userInput == 'S' || userInput == 's') {


        // Load game map from file
        Area gameArea;
        gameArea.LoadLocationsFromFile("game_map.txt");

        Room* startRoom = gameArea.GetRoom("Desert Oasis");

        // Check if the start room was found
        if (startRoom != nullptr) {
            // Create a player and set its location to the start room
            Player player("A", 100);
            player.SetLocation(startRoom);

            CommandInterpreter commandInterpreter(&player);

            // Game loop
            while (player.GetHealth() > 0) {
                // Display current location and player's health
                std::cout << "\nCurrent Location: " << player.GetLocation()->GetDescription() << std::endl;
                std::cout << "Player's Health: " << player.GetHealthBar() << std::endl;

                player.DisplayInventory();

                // Display items in the room
                std::cout << "\nItems in the room:" << std::endl;
                for (const Item& item : player.GetLocation()->GetItems()) {
                    std::cout << item.GetName() << ": " << item.GetDescription() << std::endl;
                }

                // Display options
                std::cout << "\nOptions:" << std::endl;
                std::cout << "1. Look around" << std::endl;
                std::cout << "2. Move to another room" << std::endl;
                std::cout << "3. Enter a command" << std::endl;
                std::cout << "4. Check quest status" << std::endl;
                std::cout << "5. Quit" << std::endl;

                // Get user choice
                int choice; // Declare a variable to store the user's choice
                std::cout << "\nEnter your choice: "; // Prompt the user to enter their choice
                std::cin >> choice; // Read the user's choice from the standard input

                // Clear any error flags on the input stream and ignore any remaining characters in the input buffer
                std::cin.clear(); // Clear any error flags
                while (std::cin.get() != '\n'); // Keep reading characters until a newline character is encountered, effectively clearing the input buffer

                if (choice == 1) {
                    player.GetLocation()->LookInForestRoom(player, player.GetLocation() == startRoom);
                }

                else if (choice == 2) {
                    std::cout << "Enter the direction (north, south, east, west): ";
                    std::string direction;
                    std::cin >> direction;
                    Room* nextRoom = player.GetLocation()->GetExit(direction);
                    if (nextRoom != nullptr) {
                        player.SetLocation(nextRoom);
                        std::cout << "\nYou move to the next room." << std::endl;
                    }
                    else {
                        std::cout << "\nYou can't go that way." << std::endl;
                    }
                }
                else if (choice == 3) {
                    std::cout << "\nEnter a command: ";
                    std::string userCommand;
                    std::getline(std::cin, userCommand);
                    commandInterpreter.interpretCommand(userCommand);
                }


                if (choice == 4) {
                    Room* currentRoom = player.GetLocation();
                    
                    // Check if the current room has any quests
                    const std::vector<Quest>& quests = currentRoom->GetQuests();
                    if (!quests.empty()) {
                        // Display available quests
                        std::cout << "\nAvailable quests in this room:" << std::endl;
                        for (const Quest& quest : quests) {
                            std::cout << "- " << quest.title << std::endl;
                        }

                        std::cout << "\nDo you want to start a quest? (yes/no): ";
                        std::string startChoice;
                        std::cin >> startChoice;
                        if (startChoice == "yes") {
                            // Start each available quest
                            for (const Quest& quest : quests) {
                                if (quest.title == "Confront the Ottom Soldier and emerge victorious with the Scimitar and Key.") {
                                    // Initiate the battle with the Ottom Soldier
                                    Enemy0 ottomSoldier("Ottom Soldier", "A formidable Ottom soldier guarding the ancient ruins", 50);
                                     PlaySound(TEXT("Battle.wav"), NULL, SND_FILENAME | SND_ASYNC);
                                    currentRoom->StartBattle(player, ottomSoldier);
                                    // Update the quest status based on battle result
                               
                                    // Update the quest status based on battle result
                                    if (player.GetHealth() > 0) {
                                        std::cout << "Quest 'Confront the Ottom Soldier and emerge victorious with the Scimitar and Key.' completed!" << std::endl;
                                        // Mark the quest as completed
                                        // You might need to implement a function to mark quests as completed
                                        // Once completed, activate the function to look for the diamond
                                        PlaySound(TEXT("Desert.wav"), NULL, SND_FILENAME | SND_ASYNC);
                                    }
                                    else {
                                        std::cout << "Quest 'Confront the Ottom Soldier and emerge victorious with the Scimitar and Key.' failed!" << std::endl;
                                        // Handle quest failure if needed
                                    }
                                }
                                else {
                                    // Start other quests here if needed
                                    Quest& start();
                                    std::cout << "Quest '" << quest.title << "' started." << std::endl;
                                }
                            }
                        }
                        else {
                            std::cout << "\nQuest not started." << std::endl;
                        }
                    }
                    else {
                        std::cout << "\nNo quest available in this room." << std::endl;
                    }

                }

                else if (choice == 5) {
                    std::cout << "\nGoodbye!" << std::endl;
                    return 0;
                }
                else {
                    std::cout << "\nInvalid choice. Try again." << std::endl;
                }
            }
        }
        else if (userInput == 'Q' || userInput == 'q') {
            // Quit the game
            std::cout << "Quitting the game...\n";
        }
        else {
            std::cout << "Invalid input! Please press 'S' to start or 'Q' to quit.\n";
        }

        return 0;
    }
}


