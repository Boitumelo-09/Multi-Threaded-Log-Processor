#include "utility.h"
#include "LogQueue.h"


text_t generateLog(std::vector<text_t>& head, std::vector<text_t>& messages);


int main(void) {
    
    std::vector<text_t> types = { "INFO", "WARNING", "ERROR" };
    std::vector<text_t> messages = {
        "Temperature reading normal",
        "Memory usage high",
        "Sensor disconnected",
        "Battery low",
        "Voltage spike detected"
    };
    
  // PUSHING 20 RANDOMLY GENERATED LOGS
    for (size_t i = 0; i < 19; i++)
    {
        text_t randomLog = generateLog(types, messages);
        
    }
   print("generating");
	return 0;
}

text_t generateLog(std::vector<text_t>& head, std::vector<text_t>& messages) {
    srand(time(NULL));
    
    int randomHeadIndex = rand() % head.size();
    int randomMessageIndex = rand() % messages.size();
    return "Log[" + head[randomHeadIndex] + " : " + messages[randomMessageIndex] + "]";
    
}

   
