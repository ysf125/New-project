#include "ticTacToe.hpp"
#include <iostream>
#define S std::

int main() {

    // some information for thr ticTacToeGame class
    // 0 1 2 / 1  3  9  / x = 120 
    // 3 4 5 / 27 81 27 / o = 111
    // 6 7 8 / 9  3  1  / - = 45

    ticTacToeGame g({ 'x' });
    
    S cout << "\n" << "The program finished executing";
    return 0;
}
