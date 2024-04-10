#include "Area.hpp"
#include "Room.hpp"
#include "Quest.hpp"
#include "item.hpp"
#include "Enemy.hpp"
#include <fstream>
#include <iostream>
#include <sstream>


void Area::LoadLocationsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, description, north, south, east, west, itemsStr, questStr, enemyName, enemyDescription;
        int enemyHealth;
        std::getline(ss, name, ':');
        std::getline(ss, description, ':');
        std::getline(ss, north, ':');
        std::getline(ss, south, ':');
        std::getline(ss, east, ':');
        std::getline(ss, west, ':');
        std::getline(ss, itemsStr, ':');
        std::getline(ss, questStr, ':');
        std::getline(ss, enemyName, ':');
        std::getline(ss, enemyDescription, ':');
        ss >> enemyHealth;

        Room* room = new Room(description);
        AddRoom(name, room);
        if (north != "-") ConnectRooms(name, north, "north");
        if (south != "-") ConnectRooms(name, south, "south");
        if (east != "-") ConnectRooms(name, east, "east");
        if (west != "-") ConnectRooms(name, west, "west");

        // Parse items and add them to the room
        std::istringstream itemsStream(itemsStr);
        std::string itemName;
        while (std::getline(itemsStream, itemName, ',')) {
            // Split item name and description if necessary
            std::string itemDesc;
            std::size_t pos = itemName.find('|');
            if (pos != std::string::npos) {
                itemDesc = itemName.substr(pos + 1);
                itemName = itemName.substr(0, pos);
            }
            room->AddItem(Item(itemName, itemDesc));
        }

        // Parse quest and add it to the room
        std::istringstream questStream(questStr);
        std::string questName, questDescription;
        std::getline(questStream, questName, '|');
        std::getline(questStream, questDescription);

        if (!questName.empty()) {
            room->GetQuests().push_back(Quest(questName, questDescription));
            std::cout << "Quest added to room '" << name << "': " << questName << " - " << questDescription << std::endl;
        }

        // Add enemy to the room
        if (!enemyName.empty()) {
            room->AddEnemy(Enemy0(enemyName, enemyDescription, enemyHealth));
            std::cout << "Enemy added to room '" << name << "': " << enemyName << " - " << enemyDescription << " - " << enemyHealth << std::endl;
        }
         


    }
    file.close();
}



     

void Area::AddRoom(const std::string& name, Room* room) {
    rooms[name] = room;
}

Room* Area::GetRoom(const std::string& name) {
    return rooms[name];
}

void Area::ConnectRooms(const std::string& room1Name, const std::string& room2Name, const std::string& direction) {
    Room* room1 = GetRoom(room1Name);
    Room* room2 = GetRoom(room2Name);
    if (room1 && room2) {
        room1->AddExit(direction, room2);
        // Manually specify the opposite direction
        if (direction == "north") {
            room2->AddExit("south", room1);
        }
        else if (direction == "south") {
            room2->AddExit("north", room1);
        }
        else if (direction == "east") {
            room2->AddExit("west", room1);
        }
        else if (direction == "west") {
            room2->AddExit("east", room1);
        }
    }
}
