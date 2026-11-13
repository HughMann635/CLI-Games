#pragma once
#include <stdlib.h>
#include <iostream>
#include <list>
#include <cctype>
#include <thread>
#include <iomanip>
#include <string>

#include "colors.h"

using std::cout;
using std::cin;
using std::string;
using namespace std::this_thread;
using namespace std::chrono;

std::string wordbank[20] = {"zoology", "chaser", "bookkeeper", "atlantic", "disconnect", "twilight", "jumping", "humanoid", "executable", "hyperspeed", "legendary", "patriotic", "portfolio", "unlucky", "magician", "mathematical", "compliance", "jaguar", "switch", "success"};
std::string word = "";
std::string guess = "";
std::string letter = "";
std::list<char> letterlist = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

inline int gameloop_hgmn() {
    word = wordbank[std::rand() % 20];
    while (true) {
        system("cls");
        guess = "";
        letter = "";
        for (int i = 0; i < word.length(); i++) {
            guess.append("_");
        }

        cout << "Guess a letter:";
        while (true) {
            cin >> letter;
            if (!(std::find(letterlist.begin(), letterlist.end(), toupper(letter[0])) != letterlist.end())) {
                cout << "\nThat's not a letter. Try again. ";
            } else break;
        }

        std::cout << guess << "\n\n";
        sleep_for(seconds(2));
    }
    if (letter == "hellothere1223345") return 0;
}