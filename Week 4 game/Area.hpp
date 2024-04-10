#ifndef AREA_HPP
#define AREA_HPP

#include <map>
#include <string>
#include "Room.hpp"
#include "Quest.hpp"


class Area {
public:
    void LoadLocationsFromFile(const std::string& filename);
    void AddRoom(const std::string& name, Room* room);
    Room* GetRoom(const std::string& name);
    void ConnectRooms(const std::string& room1Name, const std::string& room2Name, const std::string& direction);

private:
    std::map<std::string, Room*> rooms;
    
};

#endif // AREA_HPP

