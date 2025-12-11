#include "utility.h"

void clearScreen() {
    system(CLEAR_COMMAND);
}
void newLine() {
    std::cout << text_t(2, '\n');
}
void pressToContinue() {
    newLine();
    std::cout << horizontalPadding() << "Press Enter To Proceed...";
    std::cin.get();
    clearScreen();
}

void verticalPadding() {
    std::cout << text_t(5, '\n');
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

void printInt(value_t& VALUE) { std::cout << VALUE; }
void printTextAndValue(text_t& text , value_t& VALUE) { std::cout << text <<VALUE<< std::endl; }
void printChar(char_t& chr) { std::cout << chr; }

void incr(value_t& number) { number++; }