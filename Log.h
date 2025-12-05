#pragma once
#include <string>
#include <iostream>
#include <mutex>
#include <queue>
#include <condition_variable>

std::mutex _MUTEXLOCK;
std::condition_variable _CONDITION_VARIABLE;


class Log
{
	std::queue<std::string> logQueue;
public:
	Log();
	~Log();

	std::string generateLog();
		
};

//this class will have a que and generate logs