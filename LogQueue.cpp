#include "LogQueue.h"
#include "utility.h"



void LogQueue::pushLogs(const std::string& log) {
	std::unique_lock<std::mutex> lock(_MUTEX);
	logsQueue.push(log); // PUSHING A GENERATED LOG INTO THE QUEUE
	taskAdded = 1;       // Preparing to signal consumer threads that a log is updated
	/*taskAdded ? print("Success\n") : print("Fail\n");*/
	std::this_thread::sleep_for(5ms); // pausing after adding task
	_CONDITIONVARIABLE.notify_one(); //NOTIFYING ONE THREAD THAT IT CAN NOW PROCESS DATA 
}
std::queue<std::string> LogQueue::getQueue() {
	return logsQueue;
}
void LogQueue::popLog() {
	//this will be executed on a child thread in main
	//first we lock the resource using RAII (unique_lock)
	std::unique_lock<std::mutex> lock(_MUTEX);

	//WE GOING TO CHECK FOR SIGNAL ie. waiting for notification from the producer thread
	if (!taskAdded) { _CONDITIONVARIABLE.wait(lock); }
	//if we get signal from producer thread, we read the data in the queue and leave
	print("Popping : "+logsQueue.front());
}
LogQueue::LogQueue()
{

}

LogQueue::~LogQueue()
{
}