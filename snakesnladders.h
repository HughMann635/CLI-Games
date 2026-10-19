#pragma once
#include <stdlib.h>
#include <iostream>
#include <thread>

using std::cout;
using std::cin;
using std::string;
using namespace std::this_thread;
using namespace std::chrono;

//TODO: RENAME VARS!!!
//cuz I cant have multiple of the same obv

int board_snl[100] = {0};

int dice1, dice2;
int pos1 = 0;
int pos2 = 0;

inline int gameloop_snl() {
    pos1 = 0;
    pos2 = 0;

    for (int i = 0; i < 100; i++) board_snl[100] = {0};
    while (true) {
        cout << "It's Player 1's turn now.\n";
        cout << "Rolling...\n";
        sleep_for(seconds(1));
        dice1 = (std::rand() % 6) + 1;
        pos1 += dice1;
        cout << "Player 1 rolled a " << dice1 <<" on their roll.\n";
        sleep_for(seconds(1));
        if (pos1 >= 100) {
            if (pos1 > 100) {
                cout << "You cannot roll past 100! You must reroll until you achieve exactly 100 to win.\n";
                pos1 -= dice1;
                sleep_for(seconds(1));
            } else {
                cout << "They are now on position " << pos1 << " of the board.\n";
                sleep_for(seconds(1));
                cout << "You reached 100 and won! Good job!\n";
                sleep_for(seconds(20));
                return 0;
            }
        }
        cout << "They are now on position " << pos1 << " of the board.\n";
        sleep_for(seconds(1));
        if (board_snl[pos1-1] == 2) board_snl[pos1-1] = 3; 
        else board_snl[pos1-1] = 1;

        cout << "It's Player 2's turn now.\n";
        cout << "Rolling...\n";
        sleep_for(seconds(1));
        dice2 = (std::rand() % 6) + 1;
        pos2 += dice2;
        if (pos2 >= 100) {
            if (pos2 > 100) {
                cout << "You cannot roll past 100! You must reroll until you achieve exactly 100 to win.\n";
                pos1 -= dice1;
                sleep_for(seconds(1));
            } else {
                cout << "They are now on position " << pos2 << " of the board.\n";
                sleep_for(seconds(1));
                cout << "You reached 100 and won! Good job!\n";
                sleep_for(seconds(20));
                return 0;
            }
        }
        cout << "Player 2 rolled a " << dice2 <<" on their roll.\n";
        sleep_for(seconds(1));
        cout << "They are now on position " << pos2 << " of the board.\n";
        sleep_for(seconds(1));
        if (board_snl[pos2-1] == 1) board_snl[pos2-1] = 3;
        else board_snl[pos2-1] = 2;
    }
}