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
    cout << "Hit enter to proceed.";
    cin >> "";
}