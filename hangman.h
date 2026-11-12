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

std::string wordbank[20] = {"zoology", "chaser", "bookkeeper", "atlantic", "disconnect", "twilight", "jumping", "humanoid", "executable", "hyperspeed", "legendary", "patriotic", "portfolio", "unlucky", "magician", "mathematical", "compliance", "jaguar", "switch", "success"};
std::string word = "";
std::string guess = "";

inline int gameloop_hgmn() {
    word = wordbank[std::rand() % 20];
    guess = "";
    for (int i = 0; i < word.length(); i++) {
        guess.append("_");
    }
    std::cout << guess << "\n";
    std::cout << word;
    sleep_for(seconds(10));
    return 0;
}