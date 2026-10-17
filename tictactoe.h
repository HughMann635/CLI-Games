#pragma once
#include <stdlib.h>
#include <iostream>
#include <thread>

using std::cout;
using std::cin;
using std::string;
using namespace std::this_thread;
using namespace std::chrono;

int board_ttt[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
inline string move1, move2, l1, l2, n1, n2;
inline int l1n, l2n, m1n, m2n, n1n, n2n;

inline bool properturn, badsyntax, win1, win2 = false;

inline int i = -1;

void printboard_ttt();
bool checkwin_ttt(int player);

inline int gameloop_ttt() {
    for (int i = 0; i < 9; i++) board_ttt[i] = 0;
    while (true) {
        system("cls");
        printboard_ttt();
        if (checkwin_ttt(2)) {
            cout << "Player 2 wins! Good job!";
            sleep_for(seconds(1));
            break;
        }

        cout << "It's Player 1's turn now:";
        while (true) {
            cin >> move1;
            l1 = move1[0];
            n1 = move1[1];
            if (l1 == "A") l1n = 0;
            if (l1 == "B") l1n = 3;
            if (l1 == "C") l1n = 6;
            if (n1 == "1") n1n = 0;
            if (n1 == "2") n1n = 1;
            if (n1 == "3") n1n = 2;
            m1n = l1n + n1n;
            if (move1.size() != 2 || (move1[0] != 'A' && move1[0] != 'B' && move1[0] != 'C') || (move1[1] != '1' && move1[1] != '2' && move1[1] != '3')) {
                cout << "Invalid input. Please re-enter.";
            } else if (board_ttt[m1n] != 0) {
                cout << "Already occupied. Please re-enter.";
            } else break; 
        }
        board_ttt[m1n] = 1;        
        bool sus = true;
        for (int i = 0; i < 9; i++) {
            if (board_ttt[i] == 0) {
                sus = false;
            }
        }
        system("cls");
        printboard_ttt();
        if (checkwin_ttt(1)) {
            cout << "Player 1 wins! Good job!";
            sleep_for(seconds(1));
            break;
        }
        if (sus) { 
            cout << "It's a draw!";
            sleep_for(seconds(1));
            break;
        }

        cout << "It's Player 2's turn now:";
        while (true) {
            cin >> move2;
            l2 = move2[0];
            n2 = move2[1];
            if (l2 == "A") l2n = 0;
            if (l2 == "B") l2n = 3;
            if (l2 == "C") l2n = 6;
            if (n2 == "1") n2n = 0;
            if (n2 == "2") n2n = 1;
            if (n2 == "3") n2n = 2;
            m2n = l2n + n2n;
            if (move2.size() != 2 || (move2[0] != 'A' && move2[0] != 'B' && move2[0] != 'C') || (move2[1] != '1' && move2[1] != '2' && move2[1] != '3')) {
                cout << "Invalid input. Please re-enter.";
            } else if (board_ttt[m2n] != 0) {
                cout << "Already occupied. Please re-enter.";
            } else break; 
        }
        board_ttt[m2n] = 2;
    }
    return 0;
}

void printboard_ttt() {
    string boardtxt[9] = {"", "", "", "", "", "", "", "", ""};
    for (int i = 0; i < 9; i++) {
        switch (board_ttt[i]) {
            case 0: boardtxt[i] = " ";
            break;
            case 1: boardtxt[i] = "X";
            break;
            case 2: boardtxt[i] = "O";
            break;
        }
    }
    cout << "       1       2       3       \n\n";
    cout << "A      " << boardtxt[0] << "   |   " << boardtxt[1] << "   |   " << boardtxt[2] << "       \n";
    cout << "    -------|-------|-------    \n";
    cout << "B      " << boardtxt[3] << "   |   " << boardtxt[4] << "   |   " << boardtxt[5] << "       \n";
    cout << "    -------|-------|-------    \n";
    cout << "C      " << boardtxt[6] << "   |   " << boardtxt[7] << "   |   " << boardtxt[8] << "       \n\n";
}

bool checkwin_ttt(int player) {
    if (board_ttt[0] == player && board_ttt[1] == player && board_ttt[2] == player) return true;
    if (board_ttt[3] == player && board_ttt[4] == player && board_ttt[5] == player) return true;
    if (board_ttt[6] == player && board_ttt[7] == player && board_ttt[8] == player) return true;
    if (board_ttt[0] == player && board_ttt[3] == player && board_ttt[6] == player) return true;
    if (board_ttt[1] == player && board_ttt[4] == player && board_ttt[7] == player) return true;
    if (board_ttt[2] == player && board_ttt[5] == player && board_ttt[8] == player) return true;
    if (board_ttt[0] == player && board_ttt[4] == player && board_ttt[8] == player) return true;
    if (board_ttt[2] == player && board_ttt[4] == player && board_ttt[6] == player) return true;
    return false;
}