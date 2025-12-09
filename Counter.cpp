#include "Counter.h"


void Counter::increment() { counter.fetch_add(1, std::memory_order_relaxed); }
size_t Counter::getCounter() { return counter.load(std::memory_order_relaxed); }