
#include "randomFunctions.h"
#include <iostream>

using namespace std;

char chooseRand()
{
    char randShip;
    cout << "Would you like to place random ships(Y/N)? ";
    cin >> randShip;
    while (randShip != 'Y' && randShip != 'N')
    {
        cout << endl;
        cout << "Try Again: ";
        cin >> randShip;
    }
    if (randShip == 'N')
    {
        cout << endl << endl;
    }
    return randShip;
}

int randR()
{
    int row;
    row = (rand() % 10);
    return row;
}


int randC()
{
    int column;
    column = (rand() % 10);
    return column;
}


int randD()
{
    char placement;
    int redo;

    redo = (rand() % 4);

    if (redo == 0)
    {
        placement = 'U';
    }
    if (redo == 1)
    {
        placement = 'D';
    }
    if (redo == 2)
    {
        placement = 'L';
    }
    if (redo == 3)
    {
        placement = 'R';
    }
    return placement;
}