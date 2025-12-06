#include "LogQueue.h"
#include "utility.h"



void LogQueue::pushLogs(const std::string& log) {
	std::unique_lock<std::mutex> lock(_MUTEX);
	logsQueue.push(log); // PUSHING A GENERATED LOG INTO THE QUEUE
	taskAdded = 1;       // Preparing to signal consumer threads that a log is updated
	taskAdded ? print("Success\n") : print("Fail\n");
	//std::this_thread::sleep_for(1000ms); // pausing after adding task
	_CONDITIONVARIABLE.notify_one(); //NOTIFYING ONE THREAD THAT IT CAN NOW PROCESS DATA 
}
std::queue<std::string> LogQueue::getQueue() {
	return logsQueue;
}
LogQueue::LogQueue()
{

}

LogQueue::~LogQueue()
{
}