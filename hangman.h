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
std::string faileds = "";

inline int gameloop_hgmn() {
    word = wordbank[std::rand() % 20];
    guess = "";
    for (int i = 0; i < word.length(); i++) {
        guess.append("_");
    }
    while (true) {
        system("cls");
        letter = "";

        cout << "Guess a letter:";
        while (true) {
            cin >> letter;
            if (!(std::find(letterlist.begin(), letterlist.end(), toupper(letter[0])) != letterlist.end()) || letter.length() > 1) {
                cout << "\nThat's not a letter. Try again. ";
            } else break;
        }

        for (int i = 0; i < word.length(); i++) {
            if (word[i] == letter[0]) {
                guess[i] = letter[0];
                break;
            }
            if (i == word.length()-1) faileds.append(std::to_string(letter[0]));
        }

        std::cout << guess << "\n\n";
        std::cout << faileds << "\n";
        sleep_for(seconds(2));
        if (guess == word) {
            cout << "Congrats! You guessed the word!";
            sleep_for(seconds(2));
            return 0;
        }
    }
}