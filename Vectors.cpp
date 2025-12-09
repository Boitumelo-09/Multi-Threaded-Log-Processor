#include "Vectors.h"

const std::vector<text_t> logIdentifiers = { "INFO", "WARNING", "ERROR", "DEBUG", "CRITICAL", "SYSTEM", "NETWORK", "SECURITY" };

const std::vector<text_t> logMessages = { "Temperature reading normal","Memory usage is above expected threshold","Sensor disconnected unexpectedly","Battery level is critically low","Voltage spike detected on main line","Network latency rising","Unauthorized access attempt detected","System clock drift observed","File read/write operation failed","Thread pool reaching maximum load","Cache miss rate increased","Database connection lost","Watchdog timer triggered","Firmware integrity check failed","Power supply unstable","I/O device not responding","Stack usage unusually high","Background process terminated","Packet loss detected","Resource allocation timeout" };

text_t Vectors::generateLog() {
    srand(time(NULL)); // will be in class System

    std::unique_lock<std::mutex> lock(_MUTEX);
    value_t _IDFINDEX = rand() % logIdentifiers.size();
    value_t _MSGINDEX = rand() % logMessages.size();
    _CONDVAR.notify_all();
    return "log : [" + logIdentifiers[_IDFINDEX] + " : " + logMessages[_MSGINDEX] + "]";

    }
