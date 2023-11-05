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

#include "visualizations.h"

// TF: Class
class GameVisual {
private:
    string message;

public:
    // TF: Constructor
    GameVisual(const string& msg) : message(msg) {
        cout << "BattleShip Game created By Duong Dono: " << message << endl;
    }

    // TF: Destructor
    ~GameVisual() {
        cout << "Game destroyed." << endl;
    }

    // TF: Copy Constructor
    GameVisual(const GameVisual& other) : message(other.message) {
        cout << "BattleShip Game copied with message: " << message << endl;
    }

    // TF: Access Specifier
    void showMessage() const {
        cout << "The message is: " << message << endl;
    }
};

void createVisualInstance() {
    // TF: Class Instance
    GameVisual visual("Have a greate time !!!");
    visual.showMessage();
    // TF: Copy Constructor
    GameVisual visualCopy = visual;
    visualCopy.showMessage();
}

void intro()
{
    cout << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "#####    #   ##### ##### #     ##### ##### #   # ##### #####" << endl;
    cout << "#   #   # #    #     #   #     #     #     #   #   #   #   #" << endl;
    cout << "####   #   #   #     #   #     ##### ##### #####   #   #####" << endl;
    cout << "#   #  #####   #     #   #     #         # #   #   #   #    " << endl;
    cout << "#####  #   #   #     #   ##### ##### ##### #   # ##### #    " << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << endl;
    cout << "\n";
}

void playerSucessfulHit() {
    cout << "                * * * * * * * * * * * * * * *  * " << endl;
    cout << "                *     _____   ____   _____     * " << endl;
    cout << "                *    |     | |    | |     |    * " << endl;
    cout << "                *    |__|__| |____| |__|__|    * " << endl;
    cout << "                *   HIT! AI ship's got damaged * " << endl;
    cout << "                * * * * * * * * * * * * * * *  *" << endl;
}
void aiSucessfulHit() {
    cout << "                * * * * * * * * * * * * * * * * * * * " << endl;
    cout << "                *         _____   ____   _____      * " << endl;
    cout << "                *        |     | |    | |     |     * " << endl;
    cout << "                *        |__|__| |____| |__|__|     * " << endl;
    cout << "                *   HIT! Player's ship got damaged! * " << endl;
    cout << "                * * * * * * * * * * * * * * * * * * *" << endl;

}

void displayHumanWin() {
    cout << "\n  PLAYER WINS!" << endl;
    cout << "     \\O/ __(YAY !!) " << endl;
    cout << "      | \ " << endl;
    cout << "     / \\\ " << endl;
    cout << "  ^^^^^^^^^" << endl;
}

void displayAIWin() {
    cout << "\n   AI Victory!\n";
    cout << "   /-------\\\n";
    cout << "  | o   o |<-- AI's Eyes\n";
    cout << "   \\_____/   Better luck next time!\n";
}

void displaySunkShip() {
    cout << "   |    |  " << endl;
    cout << "  \\____/ " << endl;
    cout << "  \\______/ " << endl;
    cout << "   \\____/ " << endl;
    cout << "   ~~~~~ " << endl;
}

