#include "ticTacToe.hpp"
#include <iostream>
#define S std::

int main() {

    // testing for ticTacToeGame class
    // 0 1 2 / 1  3  9  / x = 120 
    // 3 4 5 / 27 81 27 / o = 111
    // 6 7 8 / 9  3  1  / - = 45

    ticTacToeGame g({ 'x', 'x' });

    
    S cout << "\n" << "The testing of the class finished";
    return 0;
}