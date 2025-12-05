#include <iostream>
#include <thread>



int main(void) {

	std::thread _thread01([](int num) {std::cout << "Inside thread : " << num; }, 1);
	_thread01.join();

	return 0;
}