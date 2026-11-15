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
bool in_guess = true;

inline int gameloop_hgmn(int lives) {
    word = wordbank[std::rand() % 20];
    guess = "";
    for (int i = 0; i < word.length(); i++) {
        guess.append("_");
    }
    while (true) {
        system("cls");
        letter = "";
        in_guess = false;

        cout << "Guess a letter: ";
        while (true) {
            cin >> letter;
            if (!(std::find(letterlist.begin(), letterlist.end(), toupper(letter[0])) != letterlist.end()) || letter.length() > 1) {
                cout << "\nThat's not a letter. Try again: ";
            } else if (std::find(faileds.begin(), faileds.end(), tolower(letter[0])) != faileds.end()) {
                cout << "\nYou've already guessed that, and it's not in the word. Try again: ";
            } else if (std::find(guess.begin(), guess.end(), tolower(letter[0])) != guess.end()) {
                cout << "\nYou've already guessed that, and it's in the word. Try again: ";
            } else break;
        }

        for (int i = 0; i < word.length(); i++) {
            if (word[i] == tolower(letter[0])) {
                guess[i] = tolower(letter[0]);
                in_guess = true;
            }
            if (i == word.length()-1 && !in_guess) {
                std::cout << "\nThat letter isn't in the word, unfortunately!\n\nYour progress:    "; 
                faileds += letter[0];
                lives -= 1;
            } else if (i == word.length()-1 && in_guess) {
                std::cout << "\nThat letter appears in the word!\n\nYour progress:    ";
            }
        }

        std::cout << guess << "\n\nLetters that aren't in the word:    ";
        for (int i = 0; i < faileds.length()-1; i++) std::cout << faileds[i] << " , ";
        std::cout << faileds[faileds.length()-1] << "\n\n";
        sleep_for(milliseconds(1500));
        if (guess == word) {
            cout << "Congrats! You guessed the word and won!";
            sleep_for(seconds(2));
            return 0;
        }
        if (lives == 0) {
            cout << "Unfortunately, you ran out of lives and lost.";
            sleep_for(seconds(2));
            return 0;
        }
    }
}