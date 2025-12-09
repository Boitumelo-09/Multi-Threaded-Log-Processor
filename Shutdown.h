#pragma once
#include "utility.h"
class Shutdown
{
	std::atomic<switch_t> shutdownFlag{ false };
public: 
	void setShutdownState();
	switch_t getShutdownState();
};

