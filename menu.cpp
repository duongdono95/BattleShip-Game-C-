/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2023] Media Design School
File Name : Programming–FinalProject–Bach_Duong.zip
Description : Battleship game project - C++
Author : Duong_Bach
Mail : bach.duong@mds.ac.nz
**************************************************************************/

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
    cout << "\n************************************************************\n";
    cout << "                    Debug mode is now " << (debugMode ? "ON" : "OFF") << "." << endl;
    cout << "************************************************************\n";
}