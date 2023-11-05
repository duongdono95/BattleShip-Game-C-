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

#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <utility>

using namespace std;

#include "userInputs.h"

int askRow(string sName)
{
    int row;
    cout << "Choose a row for your " << sName << "(Eg: 1 A): ";
    cin >> row;
    cout << endl;
    while (row < 1 || row > 10)
    {
        cout << "Try Again (Number Letter - Eg: 1 A): ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> row;
        cout << endl;
    }
    row = row - 1;
    return row;
}


int askColumn(string sName)
{
    int column;
    char letter;
    cout << "Choose a column for your " << sName << "(Eg : A) : ";
    cin >> letter;
    while (letter < 64 || letter > 74)
    {
        cout << endl;
        cout << "Try Again (Letter - Eg: A) : ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> letter;
    }
    column = letter - 65;
    cout << endl;
    return column;
}


char askDirection(string sName)
{
    char placement;
    cout << "Which way do you want your ship to face (U - Up, D - Down, L - Left, R - Right): ";
    cin >> placement;
    cout << endl;
    while (placement != 'U' && placement != 'D' && placement != 'L' && placement != 'R')
    {
        cout << endl;
        cout << "Try Again (Only U or D or L or R): ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> placement;
    }
    return placement;
}
