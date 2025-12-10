#include "LogQueue.h"


LogQueue::LogQueue(Shutdown& s,Counter& c) : shutdown(s) , counter(c){ }
LogQueue::~LogQueue() {

	{
		std::unique_lock<std::mutex> lock(_MUTEX);
		shutdown.setShutdownState();
		
	}
       _CONDITIONVARIABLE.notify_all();
	{
		std::unique_lock<std::mutex> lock(_MUTEX);
		while (!logsQueue.empty()) { logsQueue.pop(); }
		
	}
    
}

void LogQueue::pushGeneratedLogs(const text_t& log) {
	while (!shutdown.getShutdownState())
	{

	}
}
void popGeneratedLogs();




