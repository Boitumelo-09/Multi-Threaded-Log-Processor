#include "utility.h"
#include "LogQueue.h"


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
    
    LogQueue logQueue;
    for (int i = 0; i < 20; ++i) {
        text_t newLog = generateLog(types, messages);
        logQueue.pushTask([newLog] {
            // Worker will process this log
            std::cout << "Processing: " << log << std::endl;
            });
        std::this_thread::sleep_for(2000ms);
    }


	return 0;
}

text_t generateLog(std::vector<text_t>& head, std::vector<text_t>& messages) {
    srand(time(NULL));
    
    int randomHeadIndex = rand() % head.size();
    int randomMessageIndex = rand() % messages.size();
    return "Log[" + head[randomHeadIndex] + " : " + messages[randomMessageIndex] + "]";
}

   
