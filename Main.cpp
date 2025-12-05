#include <iostream>
#include <thread>
#include <mutex>
#include <ctime>
#include <vector>
#include <queue>


std::string generateLog(std::vector<std::string>& head, std::vector<std::string>& messages);
int main(void) {
    std::vector<std::string> types = { "INFO", "WARNING", "ERROR" };
    std::vector<std::string> messages = {
        "Temperature reading normal",
        "Memory usage high",
        "Sensor disconnected",
        "Battery low",
        "Voltage spike detected"
    };
    std::string newLog = generateLog(types, messages);

	return 0;
}

std::string generateLog(std::vector<std::string>& head, std::vector<std::string>& messages) {


}