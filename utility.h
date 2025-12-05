#pragma once

#include<string>
#include <vector>
#include <ctime>
#include <thread>
#ifndef UTILITY_H
#define UTILITY_H


#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif
void clearScreen();
void newLine();
void pressToContinue();
void clearBuffer();
std::string horizontalPadding();
typedef std::string text_t;
void verticalPadding();
void exitProgram();

#endif
