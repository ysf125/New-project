#include "ticTacToe.hpp"
#include <iostream>
#define S std::

int main() {

    // testing for ticTacToeGame class
    // 0 1 2 / 1  3  9  / x = 120 
    // 3 4 5 / 27 81 27 / o = 111
    // 6 7 8 / 9  3  1  / - = 45
    try {

        ticTacToeGame game({ 'x', 'o' }); game.play(2);

        S vector<int> x = { 3, 4, 5, 6, 7, 8 };
        S array<char, 9> z = { 'x', 'o', 'x', '-', '-', '-', '-', '-', '-' };
        report y = game.gameReport();
        moves w = game.playersMoves('o');

        if (game.getGameStateC() != z) throw (S string)"constructor or play not working";
        if (game.getEmptySpaces() != x) throw (S string)"getEmptySpaces not working";
        if ((y.win != '-') || (y.xCanWin.size() != 0) || (y.oCanWin.size() != 0)) throw (S string)"gameReport not working";
        if ((w.center != 0) || (w.edges.size() != 1) || (w.corners.size() != 0)) throw (S string)"playersMoves not working";

    }
    catch (S string e) {
        S cout << e << "\n";
    }

    S cout << "\n" << "The testing of the class finished";
    return 0;
}