#pragma once
#include "utility.h"
#include "Counter.h"
#include "Shutdown.h"

class LogQueue
{
	std::mutex _MUTEX;
	std::queue<std::string> logsQueue;
	std::condition_variable _CONDITIONVARIABLE;
	std::condition_variable _logRegContrlVrbl;

	Counter& counter;
	Shutdown& shutdown;
public:
	LogQueue(Shutdown& s, Counter& c);
	~LogQueue();
	void pushGeneratedLogs(const text_t& log);
	void popGeneratedLogs();
	void showLogRegistration();
};
