#include "LogQueue.h"



void LogQueue::pushLogs(const std::string& log) {
	std::unique_lock<std::mutex> lock(_MUTEX);
	logsQueue.push(log); // PUSHING A GENERATED LOG INTO THE QUEUE
	taskAdded = 1;       // Preparing to signal consumer threads that a log is updated

	std::this_thread::sleep_for(3000ms); // pausing after adding task
	_CONDITIONVARIABLE.notify_one(); //NOTIFYING ONE THREAD THAT IT CAN NOW PROCESS DATA 
}

LogQueue::LogQueue()
{

}

LogQueue::~LogQueue()
{
}