#include <iostream>
#include <thread>
#include <mutex>
#include <ctime>
#include <vector>
#include <queue>

typedef std::string text_t;
text_t generateLog(std::vector<text_t>& head, std::vector<text_t>& messages);
void print(text_t);

int main(void) {
    std::vector<text_t> types = { "INFO", "WARNING", "ERROR" };
    std::vector<text_t> messages = {
        "Temperature reading normal",
        "Memory usage high",
        "Sensor disconnected",
        "Battery low",
        "Voltage spike detected"
    };
    text_t newLog = generateLog(types, messages);
    print(newLog);
	return 0;
}

text_t generateLog(std::vector<text_t>& head, std::vector<text_t>& messages) {
    srand(time(NULL));
    
    int randomHeadIndex = rand() % head.size();
    int randomMessageIndex = rand() % messages.size();
    return "Log[" + head[randomHeadIndex] + " : " + messages[randomMessageIndex] + "]";
}
void print(text_t text) {std::cout << text<<std::endl;}
   
