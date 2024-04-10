#ifndef COMMANDINTERPRETER_HPP
#define COMMANDINTERPRETER_HPP

#include "Player.hpp"
#include <sstream>

class CommandInterpreter {
public:
    CommandInterpreter(Player* player);
    void interpretCommand(const std::string& command);

private:
    Player* player_;
};

#endif // COMMANDINTERPRETER_HPP

  