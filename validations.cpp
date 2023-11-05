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

#include "validations.h"

bool validate(char g[10][10], int sNum, int row, int column, char placement)
{
    bool valid = true;

    if (placement == 'U')
    {
        if (row - (sNum - 1) < 0)
        {
            valid = false;
            cout << "The Ship can not overlap each other or be set out of the bound \n";
        }
        else
        {
            for (int i = 0; i < sNum; i++)
            {
                if (g[row - i][column] == '*')
                {
                    valid = false;
                    cout << "The Ship can not overlap each other or be set out of the bound \n";
                }
            }
        }
    }
    if (placement == 'D')
    {
        if (row + (sNum - 1) > 9)
        {
            valid = false;
            cout << "The Ship can not overlap each other or be set out of the bound \n";
        }
        else
        {
            for (int i = 0; i < sNum; i++)
            {
                if (g[row + i][column] == '*')
                {
                    valid = false;
                    cout << "The Ship can not overlap each other or be set out of the bound \n";
                }
            }
        }
    }
    if (placement == 'L')
    {
        if (column - (sNum - 1) < 0)
        {
            valid = false;
            cout << "The Ship can not overlap each other or be set out of the bound \n";
        }
        else
        {
            for (int i = 0; i < sNum; i++)
            {
                if (g[row][column - i] == '*')
                {
                    valid = false;
                    cout << "The Ship can not overlap each other or be set out of the bound \n";
                }
            }
        }
    }
    if (placement == 'R')
    {
        if (column + (sNum - 1) > 9)
        {
            valid = false;
            cout << "The Ship can not overlap each other or be set out of the bound \n";
        }
        else
        {
            for (int i = 0; i < sNum; i++)
            {
                if (g[row][column + i] == '*')
                {
                    valid = false;
                    cout << "The Ship can not overlap each other or be set out of the bound \n";
                }
            }
        }
    }
    return valid;
}


bool validateAI(char aIg[10][10], int sNum, int row, int column, char placement)
{
    bool valid = true;

    if (placement == 'U')
    {
        if (row - (sNum - 1) < 0)
        {
            valid = false;
        }
        else
        {
            for (int i = 0; i < sNum; i++)
            {
                if (aIg[row - i][column] == '*')
                {
                    valid = false;
                }
            }
        }
    }
    if (placement == 'D')
    {
        if (row + (sNum - 1) > 9)
        {
            valid = false;
        }
        else
        {
            for (int i = 0; i < sNum; i++)
            {
                if (aIg[row + i][column] == '*')
                {
                    valid = false;
                }
            }
        }
    }
    if (placement == 'L')
    {
        if (column - (sNum - 1) < 0)
        {
            valid = false;
        }
        else
        {
            for (int i = 0; i < sNum; i++)
            {
                if (aIg[row][column - i] == '*')
                {
                    valid = false;
                }
            }
        }
    }
    if (placement == 'R')
    {
        if (column + (sNum - 1) > 9)
        {
            valid = false;
        }
        else
        {
            for (int i = 0; i < sNum; i++)
            {
                if (aIg[row][column + i] == '*')
                {
                    valid = false;
                }
            }
        }
    }
    return valid;
}

bool playerShotVal(char aIg[10][10], int row, int column)
{
    bool shotVal = true;
    if (aIg[row][column] == 'X')
    {
        cout << "You have already shot here. Please try again.\n\n";
        shotVal = false;
    }
    if (aIg[row][column] == 'O')
    {
        cout << "You have already shot here. Please try again.\n\n";
        shotVal = false;
    }
    return shotVal;
}

bool aIShotVal(char g[10][10], int row, int column)
{
    bool shotVal = true;
    if (g[row][column] == 'X')
    {
        shotVal = false;
    }
    if (g[row][column] == 'O')
    {
        shotVal = false;
    }
    return shotVal;
}