#include "System.h"

void System::run() {
	srand(static_cast<unsigned int>(time(NULL)));

	
	print(horizontalPadding());
	for (auto i : { 'S','y','s','t','e','m',' ','i','s',' ','R','u','n','n','i','n','g' }) {
		std::cout << i;
		std::this_thread::sleep_for(50ms);
	}
	pressToContinue();
}

