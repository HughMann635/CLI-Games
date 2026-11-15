#include <stdlib.h>
#include <iostream>
#include <thread>

#include "tictactoe.h"
#include "snakesnladders.h"
#include "hangman.h"
#include "colors.h"

using std::cout;
using std::cin;
using std::string;
using namespace std::this_thread;
using namespace std::chrono;

string gameselected = "";

int main() {    
    while (4 > 3) {
        system("cls");
        cout << "CLI GAMES\n\n";
        cout << "What game would you like to play? Enter the number corresponding with your game.\n";
        cout << red << "Tic-Tac-Toe: input 1.\n";
        cout << green << "Snakes and Ladders: input 2.\n";
        cout << blue << "Hangman: input 3.\n";
        cout << base << "Type 1R for the rules for Tic-Tac-Toe, 2R for the rules for Snakes and Ladders, or 3R for the rules for Hangman.\n";
        cout << "Enter here: ";
        std::string lives_hgmn = "0";
        cin >> gameselected;
        if (gameselected == "1") {
            gameloop_ttt();
        } else if (gameselected == "2") {
            gameloop_snl();
        } else if (gameselected == "3") {
            cout << "\nWhat difficulty mode would you like to play on?\n1) Easy: 9 lives\n2) Normal: 6 lives\n3) Hard: 4 lives\n4) Impossible: 2 lives\nType the corresponding number: "; 
            while (true) {
                cin >> lives_hgmn;
                if (lives_hgmn == "1") { 
                    gameloop_hgmn(9); 
                    break; 
                } else if (lives_hgmn == "2") { 
                    gameloop_hgmn(6); 
                    break; 
                } else if (lives_hgmn == "3") { 
                    gameloop_hgmn(4); 
                    break; 
                } else if (lives_hgmn == "4") { 
                    gameloop_hgmn(2); 
                    break; 
                } else cout << "Invalid input. Please re-enter: ";
            }
        } else if (gameselected == "1R") {
            cout << "\n\nTic-Tac-Toe is a game played on a 3x3 grid.\n\nThe goal is to fill a row, column, or diagonal with your symbol before your opponent.\n\nOne player uses X to fill in the grid, the other player uses O.\n\nAs of right now, only PvP is supported. Bots may come soon!\n\n";
            sleep_for(seconds(10));
        } else if (gameselected == "2R") {
            cout << "\n\nIn Snakes and Ladders, you try to reach the 100th square on a board before your opponent!\n\nRoll a 6-sided die, and that determines how many squares you advance.\n\nThere are ladders, which take you up, and snakes, which bring you down, scattered across the board.\n\nNote that you must achieve exactly 100 to win. You cannot roll above a 100!\n\n(This game has very little strategy involved, so the version here is uninteractive and essentially a glorified coin flip.)\n\n";
            sleep_for(seconds(10));
        } else if (gameselected == "3R") {
            cout << "\n\nIn Hangman, you guess letters to try to discover a mystery word before your lives run out!\n\nHere, you have varying lives depending on your difficulty, ranging from 9 lives all the way to just 2.\n\nThis version of Hangman pulls words from a set of 20.\n\n";
            sleep_for(seconds(10));
        } else {
            cout << "Invalid input. Please re-enter.";
            sleep_for(seconds(1));
        }
    }
}