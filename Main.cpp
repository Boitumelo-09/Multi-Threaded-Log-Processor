#include "utility.h"
#include "LogQueue.h"

std::atomic<value_t> _MONITOR{ 0 };
std::atomic<switch_t> _SHUTDOWN = false;

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
  
    
   
    /*std::thread _thread0001(queueObject.popLog());*/
    //this is wrong, threads run callables (functions, lambdas, functors).
    //queueObject.popLog() is a function but it is not direct, so it is a result instead of a callable
    // use a lambda funtion and capture the object by reference then execute inside the thread i.e :

    std::thread _thread0001([&queueObject] {while (!_SHUTDOWN || !queueObject.getQueue().empty()) { queueObject.popLog(); }});
   mainthreadProduction(types, messages, queueObject);

    _thread0001.join();
   
	return 0;
}

text_t generateLog(std::vector<text_t>& head, std::vector<text_t>& messages) {
    
    
    int randomHeadIndex = rand() % head.size();
    int randomMessageIndex = rand() % messages.size();
    return "Log[" + head[randomHeadIndex] + " : " + messages[randomMessageIndex] + "]";
    
}

static void mainthreadProduction(std::vector<text_t>& head, std::vector<text_t>& messages, LogQueue& queueObject) {
    for (size_t i = 0; i < 20; i++)
    {
        text_t randomLog = generateLog(head, messages);
        queueObject.pushLogs(randomLog);
        ++_MONITOR;
       
        if (_MONITOR == 20) {
            _SHUTDOWN = true;
            queueObject.getConditionVariable().notify_all();
        }
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
