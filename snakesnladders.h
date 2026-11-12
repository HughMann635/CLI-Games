#pragma once
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <iomanip>
#include <string>

#include "colors.h"

using std::cout;
using std::cin;
using std::string;
using namespace std::this_thread;
using namespace std::chrono;

//TODO: RENAME VARS!!!
//cuz I cant have multiple of the same obv

int board_snl[101] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int dice1, dice2;
int pos1 = 0;
int pos2 = 0;
int ladderlist[5][2];
int snakeslist[7][2];
int travelpoints[12][2];

void printboard_snl(int travelpoints[12][2]) {
    cout << "\n";
    for (int i = 10; i > 0; i--) {
        cout << "  ";
        if (i % 2 == 0) {
            for (int j = 10; j > 0; j--) {
                if (board_snl[(i-1)*10+j] == 1) cout << blue << "-1-" << base;
                else if (board_snl[(i-1)*10+j] == 2) cout << red << "-2-" << base;
                else if (board_snl[(i-1)*10+j] == 3) cout << purple << "1-2" << base;
                else { 
                    for (int k = 0; k < 12; k++) {
                        if (travelpoints[k][0] == (i-1)*10+j || travelpoints[k][1] == (i-1)*10+j) cout << tpcolors[k];
                    }
                    cout << std::setw(3) << std::setfill('0') << std::to_string((i-1)*10+j) << base; 
                }
                if (j != 1) cout << " | ";
            }
        } else {
            for (int j = 0; j < 10; j++) {
                if (board_snl[(i-1)*10+j+1] == 1) cout << blue << "-1-" << base;
                else if (board_snl[(i-1)*10+j+1] == 2) cout << red << "-2-" << base;
                else if (board_snl[(i-1)*10+j+1] == 3) cout << purple << "1-2" << base;
                else { 
                    for (int k = 0; k < 12; k++) {
                        if (travelpoints[k][0] == (i-1)*10+j+1 || travelpoints[k][1] == (i-1)*10+j+1) cout << tpcolors[k];
                    }
                    cout << std::setw(3) << std::setfill('0') << std::to_string((i-1)*10+j+1) << base; 
                }
                if (j != 9) cout << " | ";
            }
        }
        if (i != 1) cout << "\n -----------------------------------------------------------\n";
    }
    cout << "\n\n";
}

inline int gameloop_snl() {
    pos1 = 0;
    pos2 = 0;
    for (int i = 0; i < 12; i++) {
        travelpoints[i][0] = -1;
        travelpoints[i][1] = -1;
    }
    for (int i = 0; i < 5; i++) {
        while (true) {
            ladderlist[i][0] = std::rand() % 85;
            ladderlist[i][1] = ladderlist[i][0] + std::rand() % 35;
            bool ladderdupe = false;
            for (int j = 0; j < 12; j++) {
                if (travelpoints[j][0] == ladderlist[i][0] || travelpoints[j][1] == ladderlist[i][1] || travelpoints[j][1] == ladderlist[i][0] || travelpoints[j][0] == ladderlist[i][1]) {
                    ladderdupe = true;
                    break;
                }
            }
            if (ladderlist[i][0] + ladderlist[i][1] < 95 && !ladderdupe) { 
                travelpoints[i][0] = ladderlist[i][0];
                travelpoints[i][1] = ladderlist[i][1];
                break;
            }
        }
    }
    for (int i = 0; i < 7; i++) {
        while (true) {
            snakeslist[i][0] = std::rand() % 88 + 10;
            snakeslist[i][1] = snakeslist[i][0] - std::rand() % 45;
            bool snakesdupe = false;
            for (int j = 0; j < 12; j++) {
                if (travelpoints[j][0] == snakeslist[i][0] || travelpoints[j][1] == snakeslist[i][1] || travelpoints[j][1] == snakeslist[i][0] || travelpoints[j][0] == snakeslist[i][1]) {
                    snakesdupe = true;
                    break;
                }
            }
            if (snakeslist[i][0] - snakeslist[i][1] > 5 && !snakesdupe) { 
                travelpoints[i+5][0] = snakeslist[i][0];
                travelpoints[i+5][1] = snakeslist[i][1];
                break;
            }
        }
    }
    while (true) {
        system("cls");
        
        printboard_snl(travelpoints);
        
        std::cout << "LADDERS --- All the greens and blues on the board\n\n";
        for (int i = 0; i < 5; i++) {
            std::cout << tpcolors[i] << i+1 << ". " << travelpoints[i][0] << " -> " << travelpoints[i][1] << base;
            if (i == 4) cout << "\n";
            else cout << "    ";
        }
        std::cout << "\nSNAKES --- All the reds and purples on the board\n\n";
        for (int i = 0; i < 7; i++) {
            std::cout << tpcolors[i+5] << i+1 << ". " << travelpoints[i+5][0] << " -> " << travelpoints[i+5][1] << base;
            if (i == 6) cout << "\n";
            else cout << "    ";
        }

        for (int i = 0; i < 100; i++) board_snl[i] = {0};
        
        //player 1 turn
        
        cout << "\nIt's Player 1's turn now.\n";
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
                cout << "Player 1 reached 100 and won! Good job!\n";
                sleep_for(seconds(2));
                return 0;
            }
        }
        for (int i = 0; i < 5; i++) {
            if (travelpoints[i][0] == pos1) {
                pos1 = travelpoints[i][1];
                cout << "Player 1 landed on a ladder! Nice! They climb up from " << travelpoints[i][0] << " to " << travelpoints[i][1] << ".";
            }
        }
        for (int i = 0; i < 7; i++) {
            if (travelpoints[i+5][0] == pos1) {
                cout << "Uh oh! Player 1 landed on a snake! They slide down from " << travelpoints[i+5][0] << " to " << travelpoints[i+5][1] << ".";
            }
        }
        cout << "They are now on position " << pos1 << " of the board.\n\n";
        sleep_for(seconds(1));
        if (board_snl[pos1] == 2) board_snl[pos1] = 3; 
        else board_snl[pos1] = 1;

        //player 2 turn

        cout << "It's Player 2's turn now.\n";
        cout << "Rolling...\n";
        sleep_for(seconds(1));
        dice2 = (std::rand() % 6) + 1;
        pos2 += dice2;
        cout << "Player 2 rolled a " << dice2 <<" on their roll.\n";
        sleep_for(seconds(1));
        if (pos2 >= 100) {
            if (pos2 > 100) {
                cout << "You cannot roll past 100! You must reroll until you achieve exactly 100 to win.\n";
                pos2 -= dice2;
                sleep_for(seconds(1));
            } else {
                cout << "They are now on position " << pos2 << " of the board.\n";
                sleep_for(seconds(1));
                cout << "Player 2 reached 100 and won! Good job!\n";
                sleep_for(seconds(2));
                return 0;
            }
        }
        for (int i = 0; i < 5; i++) {
            if (travelpoints[i][0] == pos2) {
                pos2 = travelpoints[i][1];
                cout << "Player 2 landed on a ladder! Nice! They climb up from " << travelpoints[i][0] << " to " << travelpoints[i][1] << ".";
            }
        }
        for (int i = 0; i < 7; i++) {
            if (travelpoints[i+5][0] == pos2) {
                pos2 = travelpoints[i][1];
                cout << "Uh oh! Player 2 landed on a snake! They slide down from " << travelpoints[i+5][0] << " to " << travelpoints[i+5][1] << ".";
            }
        }
        cout << "They are now on position " << pos2 << " of the board.\n\n";
        sleep_for(seconds(1));
        if (board_snl[pos2] == 1) board_snl[pos2] = 3;
        else board_snl[pos2] = 2;
    }
}