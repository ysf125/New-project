#include "ticTacToe.hpp"
#include <iostream>
#define S std::

int main() {

    // testing for ticTacToeGame class
    // 0 1 2 / 1 3 2
    // 3 4 5 / 4 5 4 
    // 6 7 8 / 2 3 1

    ticTacToeGame g({ 'x' });

    S cout << "\n" << "The program finished executing";
    return 0;
}
