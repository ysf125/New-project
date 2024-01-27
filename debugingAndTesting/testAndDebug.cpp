#include "ticTacToeTestAndDebug.hpp"
#include <iostream>
#define S std::

int main() {

    // testing for ticTacToeGame class
    // 0 1 2 / 1  3  9  / x = 120 / x - o
    // 3 4 5 / 27 81 27 / o = 111 / x
    // 6 7 8 / 9  3  1  / - = 45  / o

    ticTacToeGame x({'x', '-', 'o', 'x'});

    int bestAIMove = x.AI('o');
    S cout << bestAIMove << "\n"; 

    S cout << "\n" << "testing and debuging has finished";
    return 0;
}