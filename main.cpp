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

#include "menu.h"
#include "randomFunctions.h"
#include "userInputs.h"
#include "validations.h"
#include "visualizations.h"

struct Ship {
    // TF: Variable Type
    string name;
    int size{ 0 };
    vector<pair<int, int>> coordinates; // Pairs of row and column where the ship is placed
    int hits{ 0 }; // Number of times the ship has been hit
};

void computeGrid(char[10][10], char[10][10]);
void displayGrid(char[10][10], char[10][10], bool);
string shipName(int, int);
void placeShips(char grid[10][10], int shipSize, int row, int column, char direction, vector<Ship>& fleet, string shipName);

void aIShoot(char[10][10], int, int, vector<Ship>& playerFleet);
void playerShoot(char[10][10], int, int, vector<Ship>& aiFleet);

int shotRow();
int shotColumn();
// TF: Default Parameter
void playGame(bool debugMode = false);

vector<Ship> playerFleet;
vector<Ship> aiFleet;

// TF: Reference
bool isShipSunk(const Ship& ship) {
    // TF: Relational Operator
    return ship.hits >= ship.size;
}
// TF: Variable Type
int playerShots = 0;
int playerHits = 0;
int playerMisses = 0;
int aiShots = 0;
int aiHits = 0;
int aiMisses = 0;

// TF: Default Parameter
void playGame(bool debugMode) {
    int option;
    bool exitGame = false;
    // TF: Pointer Initialised
    int* ptrOption = new int;
    // TF: Array
    char g[10][10], aIg[10][10];
    char placement, rplacement, randShip;
    int row, rrow, column, rcolumn, counter = 0, sNum = 5, shipCount = 17, aIShipCount = 17, gameState, hits = 0, aIHits = 0;
    string sName;

    // TF: Dynamic Memory
    int* temp = new int(0); // Dynamically allocate memory for an integer, initialized to 0
    delete temp;
    temp = nullptr;

    while (!exitGame) {
        // TF: Iteration Structure
        showMainMenu();
        // TF: Pointer Dereferenced
        cin >> *ptrOption;
        option = *ptrOption;
        // TF: Conditional Statement
        switch (option) {
        case 1:
        {
            // reset the game
            playerFleet.clear();
            aiFleet.clear();
            aIShipCount = 17;
            shipCount = 17;
            playerShots = 0;
            playerHits = 0;
            playerMisses = 0;
            aiShots = 0;
            aiHits = 0;
            aiMisses = 0;
            computeGrid(g, aIg);
            displayGrid(g, aIg, debugMode);

            randShip = chooseRand();
            // TF: Constant
            const int shipSizes[] = { 5, 4, 3, 3, 2 };

            // TF: Conditional Statement
            if (randShip == 'Y')
            {
                sNum = 5;
                // TF: Arithmetic Operator
                sName = shipName(sNum, counter + 1);
                // TF: Iteration Structure
                for (int i = 0; i < 5; i++)
                {
                    sNum = shipSizes[i];
                    sName = shipName(sNum, i + 1);
                    do
                    {
                        row = randR();
                        column = randC();
                        placement = randD();
                        // TF: Logical Operator
                    } while (!validate(g, sNum, row, column, placement));
                    placeShips(g, sNum, row, column, placement, playerFleet, shipName(sNum, counter));

                    do
                    {
                        rrow = randR();
                        rcolumn = randC();
                        rplacement = randD();
                    } while (!validateAI(aIg, sNum, rrow, rcolumn, rplacement));
                    placeShips(aIg, sNum, rrow, rcolumn, rplacement, aiFleet, shipName(sNum, counter));
                    counter++;
                }
                displayGrid(g, aIg, debugMode);
            }
            else
            {
                for (int i = 0; i < 5; i++)
                {
                    sNum = shipSizes[i];
                    sName = shipName(sNum, i + 1);
                    do
                    {
                        row = askRow(sName);
                        column = askColumn(sName);
                        placement = askDirection(sName);
                    } while (!validate(g, sNum, row, column, placement));
                    placeShips(g, sNum, row, column, placement, playerFleet, shipName(sNum, counter));

                    do
                    {
                        rrow = randR();
                        rcolumn = randC();
                        rplacement = randD();
                    } while (!validateAI(aIg, sNum, rrow, rcolumn, rplacement));
                    placeShips(aIg, sNum, rrow, rcolumn, rplacement, aiFleet, shipName(sNum, counter));

                    displayGrid(g, aIg, debugMode);
                    counter++;

                    if (sName == "Patrol Boat")
                    {
                        sNum += 1;
                        counter += 1;
                    }
                    sNum--;
                }
            }

            while (aIShipCount != 0 && shipCount != 0)
            {
                aIShipCount = 17;
                shipCount = 17;
                hits = 0;
                aIHits = 0;
                do
                {
                    row = shotRow();
                    column = shotColumn();
                } while (!playerShotVal(aIg, row, column));
                playerShoot(aIg, row, column, aiFleet);

                for (int r = 0; r < 10; r++)
                {
                    for (int c = 0; c < 10; c++)
                    {
                        if (aIg[r][c] == 'X')
                        {
                            hits++;
                        }
                    }
                }

                do
                {
                    rrow = randR();
                    rcolumn = randC();
                } while (!aIShotVal(g, rrow, rcolumn));
                aIShoot(g, rrow, rcolumn, playerFleet);

                for (int r = 0; r < 10; r++)
                {
                    for (int c = 0; c < 10; c++)
                    {
                        if (g[r][c] == 'X')
                        {
                            aIHits++;
                        }
                    }
                }
                aIShipCount = aIShipCount - hits;
                shipCount = shipCount - aIHits;
                displayGrid(g, aIg, debugMode);
            }
            if (shipCount == 0)
            {
                cout << "********************************************\n";
                cout << "              You Lost The Game!!!";
                cout << "********************************************\n";
                displayAIWin();
            }
            if (aIShipCount == 0)
            {
                cout << "********************************************\n";
                cout << "              You Won The Game\n!!!";
                cout << "********************************************\n";
                displayHumanWin();
            }
            cout << "-----------------------------------------\n";
            cout << "Game Statistics:\n";
            cout << "-----------------------------------------\n";
            cout << "Player Shots: " << playerShots << "\n";
            cout << "Player Hits: " << playerHits << "\n";
            cout << "Player Misses: " << playerMisses << "\n";
            cout << "-----------------------------------------\n";
            cout << "AI Shots: " << aiShots << "\n";
            cout << "AI Hits: " << aiHits << "\n";
            cout << "AI Misses: " << aiMisses << "\n";
            break;
        }
            case 2:
                toggleDebugMode(debugMode);
                break;
            case 3:
                exitGame = true;
                cout << "Exiting game..." << endl;
                break;
            default:
                cout << "Invalid option, please try again." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
        }
        
    }
    delete ptrOption;
}




void computeGrid(char g[10][10], char aIg[10][10])
{
    for (int r = 0; r < 10; r++)
    {
        for (int c = 0; c < 10; c++)
        {
            g[r][c] = ' ';
        }
    }
    for (int r = 0; r < 10; r++)
    {
        for (int c = 0; c < 10; c++)
        {
            aIg[r][c] = ' ';
        }
    }
}

void displayGrid(char g[10][10], char aIg[10][10], bool debugMode)
{
    cout << endl;
    cout << "      A   B   C   D   E   F   G   H   I   J";
    cout << "            A   B   C   D   E   F   G   H   I   J" << endl;
    for (int r = 0; r < 10; r++)
    {
        cout << "    +---+---+---+---+---+---+---+---+---+---+";
        cout << "        +---+---+---+---+---+---+---+---+---+---+" << endl;
        cout << right << setw(2) << r + 1 << " ";
        for (int c1 = 0; c1 < 10; c1++)
        {
            cout << " | " << g[r][c1];
        }
        cout << " |     " << right << setw(2) << r + 1;
        for (int c2 = 0; c2 < 10; c2++)
        {
            if (debugMode || aIg[r][c2] == 'X' || aIg[r][c2] == 'O') {
                cout << " | " << aIg[r][c2];
            }
            else {
                cout << " | " << ' '; // Hide the boat placement with space
            }
        }
        cout << " |" << endl;
    }
    cout << "    +---+---+---+---+---+---+---+---+---+---+";
    cout << "        +---+---+---+---+---+---+---+---+---+---+" << endl;
}

void placeShips(char grid[10][10], int sNum, int row, int column, char placement, vector<Ship>& fleet, string shipName) {
    Ship ship;
    ship.name = shipName;
    ship.size = sNum;
    ship.hits = 0;

    for (int i = 0; i < sNum; ++i) {
        int currentRow = row, currentColumn = column;

        if (placement == 'U') {
            currentRow -= i;
        }
        else if (placement == 'D') {
            currentRow += i;
        }
        else if (placement == 'L') {
            currentColumn -= i;
        }
        else if (placement == 'R') {
            currentColumn += i;
        }

        ship.coordinates.push_back(make_pair(currentRow, currentColumn));
        grid[currentRow][currentColumn] = '*';
    }

    fleet.push_back(ship);
}


string shipName(int sNum, int counter) {
    switch (sNum) {
    case 5: return "Aircraft Carrier";
    case 4: return "Battleship";
    case 3:
        if (counter == 1 || counter == 3) return "Destroyer";
        if (counter == 2 || counter == 4) return "Submarine";
        break;
    case 2: return "Patrol Boat";
    }
    return ""; // Return an empty string if no valid name is found
}


int getShipIndex(const vector<Ship>& fleet, int row, int column) {
    for (int i = 0; i < static_cast<int>(fleet.size()); ++i) {
        for (const auto& coord : fleet[i].coordinates) {
            if (coord.first == row && coord.second == column) {
                return i;
            }
        }
    }
    return -1; // Return -1 if no ship is at the coordinate
}
void playerShoot(char aIg[10][10], int row, int column, vector<Ship>& aiFleet) {
    
    int index = getShipIndex(aiFleet, row, column);
    if (index != -1) { // If a ship is at the coordinate
        Ship& ship = aiFleet[index];
        ship.hits++;
        aIg[row][column] = 'X'; // Mark with 'X' regardless because it's a hit
        if (isShipSunk(ship)) {
            displaySunkShip();
            cout << "You have sunk the enemy's " << ship.name << "!\n";
        }
        else {
            playerSucessfulHit();
            cout << "You have hit the enemy's " << ship.name << "!\n";
        }
        
        playerHits++;
    }
    else {
        aIg[row][column] = 'O'; // Mark with 'O' only if it's a miss
        cout << "You Have Missed.\n";
        playerMisses++;
    }
    playerShots++;
}


void aIShoot(char g[10][10], int row, int column, vector<Ship>& playerFleet) {
    cout << endl;
    int index = getShipIndex(playerFleet, row, column);
    if (index != -1) {
        Ship& ship = playerFleet[index];
        ship.hits++;
        g[row][column] = 'X';
        aiSucessfulHit();
        cout << "Your " << ship.name << " has been hit!\n";
        if (isShipSunk(ship)) {
            displaySunkShip();
            cout << "Your " << ship.name << " has been sunk!\n";
        }

        aiHits++;
    }
    else {
        if (g[row][column] == ' ') {
            g[row][column] = 'O';
            cout << "The Enemy Has Missed.\n";
        }
        else {
            cout << "The Enemy Has Shot The Same Place.\n";
        }
        aiMisses++;
    }
    aiShots++;
}


int shotRow()
{
    int row;
    cout << "Which row would you like to hit (Eg: 1 A): ";
    cin >> row;
    cout << endl;
    while (row < 1 || row > 10)
    {
        cout << "Try Again (Number Letter - Eg: 1 A) : ";
        cin.clear();               // Clear the fail state
        cin.ignore(1000, '\n');
        cin >> row;
        cout << endl;
    }
    row = row - 1;
    return row;
}


int shotColumn()
{
    int column;
    char letter;
    cout << "Which column would you like to hit (Eg: A): ";
    cin >> letter;
    cout << endl;
    while (letter < 64 || letter > 74)
    {
        cout << "Try Again (Letter - Eg: A): ";
        cin.clear();               // Clear the fail state
        cin.ignore(1000, '\n');
        cin >> letter;
        cout << endl;
    }
    column = letter - 65;
    return column;
}

int main()
{
    // TF: Pseudo Random Number
    srand(static_cast<unsigned int>(time(0)));
    playGame();
    // Wait for user input to continue
    cout << "Press enter to start the game...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

