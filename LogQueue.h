#pragma once
#include <string>
#include <iostream>
#include <mutex>
#include <ctime>
#include <chrono>
#include <condition_variable>
#include <queue>

using namespace std::chrono_literals;



class LogQueue
{
public:
	LogQueue();
	~LogQueue();
	std::queue<std::string> getQueue();
	void pushLogs(const std::string& log);
	void popLog();
	std::condition_variable& getConditionVariable();
private:
	std::mutex _MUTEX;
	std::queue<std::string> logsQueue;
	std::condition_variable _CONDITIONVARIABLE;
	bool taskAdded = 0;
};

