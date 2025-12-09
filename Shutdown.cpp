#include "Shutdown.h"

void Shutdown::setShutdownState() { shutdownFlag = true; }
switch_t Shutdown::getShutdownState() { return shutdownFlag.load(std::memory_order_relaxed); }
