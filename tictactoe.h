#pragma once
#include <stdlib.h>
#include <iostream>
#include <thread>

using namespace std;

int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
inline string move1, move2, l1, l2, n1, n2;
inline int l1n, l2n, m1n, m2n, n1n, n2n;

inline bool properturn, badsyntax, win1, win2 = false;

inline int i = -1;

void printboard();
void checkwin();

inline int gameloop() {
    board[9] = {0};
    bool draw = true;
    bool g = true;
    while (!win1 && !win2) {
        system("cls");
        printboard();
        g = true;
        cout << "It's Player 1's turn now:";
        while (true) {
            cin >> move1;
            if (move1.size() != 2 || (move1[0] != 'A' && move1[0] != 'B' && move1[0] != 'C') || (move1[1] != '1' && move1[1] != '2' && move1[1] != '3')) {
                cout << "Invalid input. Please re-enter.";
            } else break; 
        }
        l1 = move1[0];
        n1 = move1[1];
        if (l1 == "A") l1n = 0;
        if (l1 == "B") l1n = 3;
        if (l1 == "C") l1n = 6;
        if (n1 == "1") n1n = 0;
        if (n1 == "2") n1n = 1;
        if (n1 == "3") n1n = 2;
        m1n = l1n + n1n;
        board[m1n] = 1;
        
        system("cls");
        printboard();
        cout << "It's Player 2's turn now:";
        while (true) {
            cin >> move2;
            if (move2.size() != 2 || (move2[0] != 'A' && move2[0] != 'B' && move2[0] != 'C') || (move2[1] != '1' && move2[1] != '2' && move2[1] != '3')) {
                cout << "Invalid input. Please re-enter.";
            } else break; 
        }
        l2 = move2[0];
        n2 = move2[1];
        if (l2 == "A") l2n = 0;
        if (l2 == "B") l2n = 3;
        if (l2 == "C") l2n = 6;
        if (n2 == "1") n2n = 0;
        if (n2 == "2") n2n = 1;
        if (n2 == "3") n2n = 2;
        m2n = l2n + n2n;
        board[m2n] = 2;
    }
    return 0;
}

void printboard() {
    string boardtxt[9] = {"", "", "", "", "", "", "", "", ""};
    for (int i = 0; i < 9; i++) {
        switch (board[i]) {
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