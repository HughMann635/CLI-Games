#include <stdlib.h>
#include <iostream>
#include <thread>

#include "tictactoe.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using namespace std::this_thread;
using namespace std::chrono;

int gameselected = 0;

int main() {    
    while (4 > 3) {
        system("cls");
        cout << "CLI GAMES\n\n";
        cout << "What game would you like to play? Enter the number corresponding with your game.\n";
        cout << "Tic-Tac-Toe: input 1.";
        cin >> gameselected;
        if (gameselected == 1) {
            gameloop();
        } else {
            cout << "Invalid input. Please re-enter.";
            sleep_for(seconds(1));
        }
    }
}