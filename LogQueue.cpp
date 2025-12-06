#include "LogQueue.h"



void LogQueue::pushLogs(const std::string& log) {
	std::unique_lock<std::mutex> lock(_MUTEX);
	logsQueue.push(log);

}

LogQueue::LogQueue()
{

}

LogQueue::~LogQueue()
{
}