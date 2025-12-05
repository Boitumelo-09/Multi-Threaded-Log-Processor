#include "Log.h"


Log::Log() { std::cout << "Logging..."; }

std::vector<std::string>Log::getIdentifiers() { return _IDENTIFIERS; }
std::vector<std::string>Log::getMessages() { return _MESSAGES; }


std::vector<std::string> _IDENTIFIERS = { "INFO", "WARNING", "ERROR" };
std::vector<std::string> _MESSAGES = {
        "Temperature reading normal",
        "Memory usage high",
        "Sensor disconnected",
        "Battery low",
        "Voltage spike detected"
};

std::string Log::generateLog() {
    return "hey";
}

int main() {
    Log log;
    try
    {
         std::cout <<log.getIdentifiers().size();
         
    }
    catch (...)
    {
        throw;
        return 9;
    }
    
    return 0;
}