#pragma once
#include <stdlib.h>
#include <iostream>
#include <thread>

using namespace std;

inline int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

inline string move1, move2, l1, l2, n1, n2;
inline int l1n, l2n, m1n, m2n, n1n, n2n;

inline int i = -1;
inline bool properturn, badsyntax, w1, w2 = false;
inline bool draw = true;

void printboard();
void checkwin();

inline int gameloop() {
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
    cout << l1n+n1n;
    return 0;
}