#include "System.h"

Shutdown* _shutdown = new Shutdown();
Counter* _counter = new Counter();
Vectors* vectorObjectContainer = new Vectors();
LogQueue queueObjectContainer(*_shutdown, *_counter);


void  System::run() {
	srand(static_cast<unsigned int>(time(NULL)));

	for (auto i : { 'S','y','s','t','e','m',' ','i','s',' ','R','u','n','n','i','n','g','.','.','.'}) {
		
		printChar(i);
		std::this_thread::sleep_for(50ms);
	}
	pressToContinue();

	ATHREAD_t threadS001([&] {
		 while (!_shutdown->getShutdownState()) {
			text_t newLog = vectorObjectContainer->generateLog();
			queueObjectContainer.pushGeneratedLogs(newLog);
			std::this_thread::sleep_for(1000ms);
		}
		});
	ATHREAD_t threadS002([&] {
		verticalPadding();
		text_t headerMessage = (horizontalPadding() + "Registered Logs...");
		printMessage(headerMessage,50);
		while (!_shutdown->getShutdownState())
		{
			queueObjectContainer.popGeneratedLogs();
		}
		pressToContinue();
		});
	ATHREAD_t threadS003([&] {
		
		
			queueObjectContainer.showLogRegistration();
		
		});
	
	threadS001.join();
	threadS002.join();
	threadS003.join();
	
	
}

