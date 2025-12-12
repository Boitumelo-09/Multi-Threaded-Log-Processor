#include "utility.h"

void clearScreen() {
    system(CLEAR_COMMAND);
}
void newLine(value_t lines) {
    std::cout << text_t(lines, '\n');
}
void pressToContinue() {
    newLine(2);
    text_t padding = horizontalPadding() + "Press Enter To Proceed...";
    printMessage(padding , 50);
    std::cin.get();
    clearScreen();
}

void verticalPadding() {
    std::cout << text_t(3, '\n');
}
text_t horizontalPadding() {
    return  std::string(5, '\t');
}
void exitProgram() {
    clearScreen();
    verticalPadding();
    std::cout << horizontalPadding() << "Exiting System...";
    pressToContinue();
    clearScreen();
    verticalPadding();
    std::cout << horizontalPadding() << "Thank You For Visiting...";
    verticalPadding();
    exit(0);
}
void clearBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

void print(text_t& text) { std::cout << text << std::endl; }
void printMessage(text_t& message,value_t time) {
    text_t stringArray = message;
    std::lock_guard<std::mutex> _lock(_mtx);
    for (auto i : stringArray) {
        printChar(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
    }
    newLine(1);
    _cvrbl.notify_all();
}
void printInt(value_t& VALUE) { std::cout << VALUE; }
void printTextAndValue(text_t& text , value_t& VALUE) { std::cout << text <<VALUE<< std::endl; }
void printChar(char_t& chr) { std::cout << chr; }

void incr(value_t& number) { number++; }