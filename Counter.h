#pragma once
#include <atomic>
#include "utility.h"


class Counter
{
	std::atomic<size_t> counter{ 0 };
public:
	void increment();
	size_t getCounter();
};

