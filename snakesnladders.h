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

int dice;
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
        dice = (std::rand() % 6) + 1;
        pos1 += dice;
        cout << "Player 1 rolled a" << dice <<"on their roll.";
        sleep_for(seconds(1));
        cout << "They are now on position" << pos1 << "of the board.";
        sleep_for(seconds(1));

        cout << "It's Player 2's turn now.\n";
        cout << "Rolling...\n";
        sleep_for(seconds(1));
        dice = (std::rand() % 6) + 1;
        pos2 += dice;
        cout << "Player 2 rolled a" << dice <<"on their roll.";
        sleep_for(seconds(1));
        cout << "They are now on position" << pos1 << "of the board.";
        sleep_for(seconds(1));
        cout << "They are now on position" << pos1 << "of the board.";
        sleep_for(seconds(1));
    }
}