#ifndef ticTacToeClass_hpp
#define ticTacToeClass_hpp

#include <array>
#include <ctype.h>
#include <map>
#include <vector>
#include "tools.hpp"
#define S std::

struct report {
    char win = ' ';
    S vector<int> xCanWin;
    S vector<int> oCanWin;
};

class ticTacToeGame {

private:
    bool AIActivated = false;
    S map<int, float> ratings;
    S array<int, 9> gameStateN;
    S vector<int> emptySpaces;

    template <typename T>

    ticTacToeGame(S array<T, 9> gameStateN) { for (int i = 0; i < 9; i++) play(i, (char)gameStateN[i]); }

    float ratingGameState(ticTacToeGame game, char AIC, S map<int, float>& ratings) {
        float rating = 0;
        int ID = createID(game.gameStateN);
        // getting the rating
        if (ratings.contains(ID)) rating = ratings[ID];
        else {
            report reportForGS = game.gameReport();
            int winR = 0, AICanWinR = 0;
            char playerC = AIC == 'x' ? 'o' : 'x';
            float depth = 9 - game.emptySpaces.size();

            if (AIC == reportForGS.win) winR = 5;
            else if (playerC == reportForGS.win) winR = -5;
            if (AIC == 'x') AICanWinR = reportForGS.xCanWin.size() + (-reportForGS.oCanWin.size());
            else if (AIC == 'o') AICanWinR = reportForGS.oCanWin.size() + (-reportForGS.xCanWin.size());
            rating = (10 - depth) * 10 / 100 * (winR + AICanWinR);
        }
        //recursion time beby!
        if (game.emptySpaces.size() == 0) return rating;
        else {
            for (int i = 0; i < game.emptySpaces.size(); i++) {
                ticTacToeGame temp = game;
                temp.play(game.emptySpaces[i]);
                rating += game.ratingGameState(temp, AIC, ratings);
                if (!ratings.contains(ID)) ratings[ID] = rating;
            }
        }
    }

    int createID(S array<int, 9> gameStateN) {
        int key = 0;
        S array<int, 9> map = { 1, 2, 1, 2, 3, 2, 1, 2, 1 };
        for (int i = 0; i < 9; i++) key += gameStateN[i] + map[i];
        return key;
    }

public:
    ticTacToeGame() { for (int i = 0; i < 9; i++) play(i, ' '); }

    ticTacToeGame(S array<char, 9> gameStateC) { for (int i = 0; i < 9; i++) play(i, gameStateC[i]); }

    S array<char, 9> getGameStateC() {
        S array<char, 9> gameStateC;
        for (int i = 0; i < 9; i++) {
            gameStateC[i] = (char)gameStateN[i];
        }
        return gameStateC;
    }

    S vector<int> getEmptySpaces() {
        return emptySpaces;
    }

    void play(int SpaceIndex, char player = 'a') {
        switch (tolower(player)) {
        case 'a': gameStateN[SpaceIndex] = emptySpaces.size() % 2 == 1 ? 120 : 111; break;
        case 'x': gameStateN[SpaceIndex] = 120; break;
        case 'o': gameStateN[SpaceIndex] = 111; break;
        default:
            gameStateN[SpaceIndex] = 95;
            emptySpaces.push_back(SpaceIndex);
            break;
        }
    }

    report gameReport() {
        report returnVal;
        S array<int, 16> patterns = { 0, 1, 3, 1, 6, 1, 0, 3, 1, 3, 2, 3, 0, 4, 2, 2 };
        for (int i = 0; i < 8; i++) {
            int empty, x = 0, o = 0;
            for (int y = 0; y < 3; y++) {
                int point = (patterns[(i * 2) + 1] * y) + (patterns[i * 2]);
                switch (gameStateN[point]) {
                case 120: x += 1; break;
                case 111: o += 1; break;
                default: empty = point; break;
                }
            }
            if (x == 3 || o == 3) returnVal.win = x == 3 ? 'x' : 'o';
            else if (x == 2 && o == 0) returnVal.xCanWin.push_back(empty);
            else if (o == 2 && x == 0) returnVal.oCanWin.push_back(empty);
        }
        return returnVal;
    }

    int AI(char AIC) {
        int AImove = 0, bestMoveRating = 0;
        // first two moves
        if (9 - emptySpaces.size() <= 1) {
            if (!(gameStateN[0] == 120) || !(gameStateN[0] == 111)) AImove = 0;
            else AImove = 4;
        }
        else {
            if (AIActivated == false) {
                AIActivated = true;

            }

        }
        return AImove;
    }
};

#endif
