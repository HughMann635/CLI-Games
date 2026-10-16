#pragma once
#include <stdlib.h>
#include <iostream>
#include <thread>

using namespace std;

inline string move1, move2, l1, l2, n1, n2;
inline int l1n, l2n, m1n, m2n, n1n, n2n;

inline bool properturn, badsyntax, win1, win2 = false;

inline int i = -1;

void printboard();
void checkwin();

inline int gameloop() {
    system("cls");
    int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    bool draw = true;
    bool g = true;
    while (!win1 && !win2) {
        g = true;
        cout << "It's Player 1's turn now:";
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
        board[m1n] = 1;
        cout << "It's Player 2's turn now:";
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
        board[m2n] = 2;
    }
    return 0;
}