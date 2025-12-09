#pragma once
#include "utility.h"
#include "Counter.h"
#include "Shutdown.h"

class Vectors
{
	
	static const std::vector<text_t> logIdentifiers;
	static const  std::vector<text_t> logMessages;
	std::mutex _MUTEX;
	std::condition_variable _CONDVAR;
	Counter& counter;
	Shutdown& shutdown;

public :
	text_t generateLog(std::vector<text_t> logIdentifiers, std::vector<text_t> logMessages);
	text_t generateLog();
   
       
};

