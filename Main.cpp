#include "utility.h"
#include "LogQueue.h"



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
   
    /*std::thread _thread0001(queueObject.popLog());*/
    //this is wrong, threads run callables (functions, lambdas, functors).
    //queueObject.popLog() is a function but it is not direct, so it is a result instead of a callable
    //we use a lambda funtion and capture the object by reference then execute inside the thread i.e :
    std::thread _thread0001([&queueObject] {queueObject.popLog(); });
    _thread0001.join();
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
    
    
    


    //printing from our queue to check if we really recorded (for practice)
    /*while (!copy.empty()) {
        std::this_thread::sleep_for(500ms);
        std::queue<text_t> copy = queueObject.getQueue();
        print(copy.front());
        copy.pop();
        std::this_thread::sleep_for(500ms);
    }*/
}
