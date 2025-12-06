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
typedef std::string text_t;
void clearScreen();
void newLine();
void pressToContinue();
void clearBuffer();

text_t horizontalPadding();

void verticalPadding();
void exitProgram();

void print(text_t text);
#endif
