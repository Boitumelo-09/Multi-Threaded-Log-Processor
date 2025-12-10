#pragma once
#include "utility.h"

class Vectors
{
	
	static const  std::vector<text_t> logIdentifiers;
	static const  std::vector<text_t> logMessages;
	std::mutex _MUTEX;
	std::condition_variable _CONDVAR;

public :
	text_t generateLog();
   
};

