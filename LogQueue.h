#pragma once
#include <string>
#include <iostream>
#include <mutex>
#include <ctime>
#include <vector>
#include <condition_variable>

std::mutex _MUTEXLOCK;
std::condition_variable _CONDITION_VARIABLE;


class Log
{
	std::vector<std::string> _IDENTIFIERS;
	std::vector<std::string> _MESSAGES;
public:
	
	Log();
	

	std::string generateLog();
	std::vector<std::string> getIdentifiers();
	std::vector<std::string> getMessages();
};

//this class will have a que and generate logs