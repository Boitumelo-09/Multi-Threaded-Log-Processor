#pragma once
#include "utility.h"
#include "Counter.h"
#include "Shutdown.h"

class LogQueue
{
	std::mutex _MUTEX;
	std::queue<std::string> logsQueue;
	std::condition_variable _CONDITIONVARIABLE;
	Counter& counter;
	Shutdown& shutdown;
public:
	LogQueue();
	~LogQueue();
	void pushLogs(const std::string& log);
	void popLog();
};

