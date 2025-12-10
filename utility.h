// THIS IS A CUSTOM HEADER FILE
// IT IS FOR PERSONAL USE
// ANYONE CAN USE IT AND MODIFY


#pragma once

#ifndef UTILITY_H
#define UTILITY_H

// HEADER FILE INCLUSIONS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
#include <thread>
#include <atomic>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <limits>
#include <cstdlib>


// HEADER DECLARATIONS

using std::string;
using namespace std::chrono_literals;


// TYPEDEF ALIASES
typedef std::thread ATHREAD_t;
typedef std::string text_t;
typedef int value_t;
typedef bool switch_t;


// MACROS
#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

//UTILITY FUNTIONS
 
    // -SYSTEM FLOW AND DESIGN
void clearScreen();
void newLine();
void pressToContinue();
void clearBuffer();
text_t horizontalPadding();
void verticalPadding();
void exitProgram();


    // - CUSTOM USER DEFINED
void print(text_t text);
void print(value_t VALUE);
void print(text_t text, value_t VALUE);
void incr(value_t& number);


#endif

//NOTES
//
//
// THE SEED OF <CTIME> SHOULD BE CASTED TO IUNSIGNED INT AND DECLARED IN THE SYSTEMS/MAIN FUNTION
// i.e srand(static_cast<unsigned int>(time(NULL))); => copy and paste for your seed.
