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

	{
		std::unique_lock<std::mutex>lock(_MUTEX);
		logsQueue.push(log);

		counter.increment();

		if (counter.getCounter() >= 20) {
			shutdown.setShutdownState();
			_CONDITIONVARIABLE.notify_all();
			return;
		}
	}
		_CONDITIONVARIABLE.notify_one(); //notifying one thread that we're there's data loaded
}
void LogQueue::popGeneratedLogs() {
	{

		std::unique_lock<std::mutex>lock(_MUTEX);
		_CONDITIONVARIABLE.wait(lock, [&] {return shutdown.getShutdownState() || counter.getCounter() > 0; });

		if (!logsQueue.empty())
		{
			printMessage(logsQueue.front(), 50);
			
			logsQueue.pop();
		}
		
	}
}




