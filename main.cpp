#include "ticTacToe.hpp"
#include <iostream>
#define S std::

int main() {

    // testing for ticTacToeGame class
    // 0 1 2 / 1 2 1
    // 3 4 5 / 2 3 2
    // 6 7 8 / 1 2 1

    ticTacToeGame g({ 'x' });

    S cout << "The program finished executing" << "\n";
    return 0;
}
