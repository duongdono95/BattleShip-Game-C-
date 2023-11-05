#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <utility>

using namespace std;

#include "visualizations.h"

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