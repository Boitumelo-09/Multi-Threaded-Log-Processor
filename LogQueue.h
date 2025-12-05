#pragma once
#include <string>
#include <iostream>
#include <mutex>
#include <ctime>
#include <chrono>
#include <condition_variable>
#include <queue>

using namespace std::chrono_literals;

//this class will have a que THAT STORES THE GENERATED LOGS

class LogQueue
{
public:
	LogQueue();
	~LogQueue();
	void pushLogs(std::string& log);
private:
	std::mutex _MUTEX;
	std::queue<std::string> logs;
	std::condition_variable _CONDITIONVARIABLE;
};

