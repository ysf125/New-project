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
    S map<int, int> ratings;
    S array<int, 9> gameStateN;
    S vector<int> emptySpaces;

    template <typename T>

    ticTacToeGame(S array<T, 9> gameStateN) {
        for (int i = 0 ; i < 9 ; i++) {
            // I'm working here now
            // I'm thinking that we can use ascii to fix this
        }
    }

    float ratingGameState(S array<int, 9> gameStateN, char AIPlayerChar, int depth) {
        float rating = 0;
        ticTacToeGame game(gameStateN);
        // getting the rating
        if (game.getEmptySpaces().size()) {

        } else {

        }
        // recursion time beby!

        return rating;
    }

    int makeKey(S array<int, 9> gameStateN) {
        int key = 0;
        S array<int,9> map = {1, 2, 1, 2, 3, 2, 1, 2, 1};
        for (int i = 0 ; i < 9 ; i++) {
            key += gameStateN[i] + map[i];
        }
        return key;
    }

  public:
    ticTacToeGame() {
        for (int i = 0; i < 9; i++) {
            play(i, ' ');
        }
    }
    ticTacToeGame(S array<char, 9> gameStateC) {
        for (int i = 0; i < 9; i++) {
            play(i, gameStateC[i]);
        }
    }

    S array<char, 9> getGameState() {
        S array<char, 9> gameStateC;
        for (int i = 0 ; i < 9 ; i++) {
            switch (gameStateN[i]) {
            case 1 :
                gameStateC[i] = 'x';
                break;
            case 4 :
                gameStateC[i] = 'o';
                break;
            default :
                gameStateC[i] = '-';
                break;
            }
        }
        return gameStateC;
    }

    S vector<int> getEmptySpaces() {
        return this->emptySpaces;
    }

    void play(int SpaceIndex, char player = 'a') {
        switch (tolower(player)) {
        case 'a':
            gameStateN[SpaceIndex] = emptySpaces.size() % 2 == 0 ? 4 : 1;
            break;
        case 'x':
            gameStateN[SpaceIndex] = 1;
            break;
        case 'o':
            gameStateN[SpaceIndex] = 4;
            break;
        default:
            gameStateN[SpaceIndex] = 0;
            emptySpaces.push_back(SpaceIndex);
            break;
        }
    }

    report gameReport() {
        report returnVal;
        S array<int, 16> patterns = {0, 1, 3, 1, 6, 1, 0, 3, 1, 3, 2, 3, 0, 4, 2, 2};
        for (int i = 0; i < 8; i++) {
            int empty, x = 0, o = 0;
            for (int y = 0; y < 3; y++) {
                int point = (patterns[(i * 2) + 1] * y) + (patterns[i * 2]);
                switch (gameStateN[point]) {
                case 1:
                    x += 1;
                    break;
                case 4:
                    o += 1;
                    break;
                default:
                    empty = point;
                    break;
                }
            }
            if (x == 3 || o == 3) {
                returnVal.win = x == 3 ? 'x' : 'o';
            } else if (x == 2 && o == 0) {
                returnVal.xCanWin.push_back(empty);
            } else if (o == 2 && x == 0) {
                returnVal.oCanWin.push_back(empty);
            }
        }
        return returnVal;
    }

    int AI(char player, int depth = 7) {
        int AImove = 0, bestMoveRating = 0;
        if (9 - emptySpaces.size() <= 1) {
            if (!(gameStateN[0] == 1) || !(gameStateN[0] == 4)) {
                AImove = 0;
            } else {
                AImove = 4;
            }
        } else {
            if (AIActivated == false) {
                AIActivated = true;

            }

        }
        return AImove;
    }
};

#endif
