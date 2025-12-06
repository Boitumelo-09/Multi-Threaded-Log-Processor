#include "utility.h"
#include "LogQueue.h"
#include <cassert>


text_t generateLog(std::vector<text_t>& head, std::vector<text_t>& messages);
static void mainthreadProduction(std::vector<text_t>& head, std::vector<text_t>& messages, LogQueue& queueObject);

int main(void) {
    srand(time(NULL));
    std::vector<text_t> types = { "INFO", "WARNING", "ERROR" };
    std::vector<text_t> messages = {
        "Temperature reading normal",
        "Memory usage high",
        "Sensor disconnected",
        "Battery low",
        "Voltage spike detected"
    };
    LogQueue queueObject;
  
    mainthreadProduction(types, messages, queueObject);
   


	return 0;
}

text_t generateLog(std::vector<text_t>& head, std::vector<text_t>& messages) {
    
    
    int randomHeadIndex = rand() % head.size();
    int randomMessageIndex = rand() % messages.size();
    return "Log[" + head[randomHeadIndex] + " : " + messages[randomMessageIndex] + "]";
    
}

static void mainthreadProduction(std::vector<text_t>& head, std::vector<text_t>& messages, LogQueue& queueObject) {
    for (size_t i = 0; i < 19; i++)
    {
        text_t randomLog = generateLog(head, messages);
        queueObject.pushLogs(randomLog);
       
    }
    
    std::this_thread::sleep_for(500ms);
    std::queue<text_t> copy = queueObject.getQueue();
    //printing from our queue to check if we really recorded
    while (!copy.empty()) {
        print(copy.front());
        copy.pop();
    }
}
