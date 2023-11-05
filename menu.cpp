// menu.cpp
#include "menu.h"
#include "visualizations.h"
#include <iostream>

using namespace std;


void showMainMenu() {
    intro();
    cout << "1. Play Game" << endl;
    cout << "2. Toggle On/Off Debug Mode" << endl;
    cout << "3. Exit" << endl;
    cout << "Select an option: ";

}

void toggleDebugMode(bool& debugMode) {
    debugMode = !debugMode;
    cout << "Debug mode is now " << (debugMode ? "ON" : "OFF") << "." << endl;
}