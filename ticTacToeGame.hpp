#ifndef ticTacToeGame_hpp
#define ticTacToeGame_hpp
#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include "treeDS.hpp"
#define S std::

struct report
{
    char win;
    S vector<int> xcanWin;
    S vector<int> ocanWin;
};

class ticTacToeGame
{

    S array<char, 9> gameState;
    S array<int, 9> gameStateN;
    S vector<int> emptySpaces;

public:
    ticTacToeGame()
    {
        for (int i = 0; i < 9; i++)
        {
            play(i, '-');
        }
    }
    ticTacToeGame(S array<char, 9> gameState)
    {
        for (int i = 0; i < 9; i++)
        {
            play(i, gameState[i]);
        }
    }

    S array<char, 9> getGameState()
    {
        return this->gameState;
    }

    S vector<int> getEmptySpaces()
    {
        return this->emptySpaces;
    }

    void play(int SpaceIndex, char player = '`')
    {
        if (player == '`')
        {
            if (emptySpaces.size() % 2 == 0)
            {
                play(SpaceIndex, 'o');
            }
            else
            {
                play(SpaceIndex, 'x');
            }
        }
        else if (tolower(player) == 'x')
        {
            gameState[SpaceIndex] = 'x';
            gameStateN[SpaceIndex] = 1;
        }
        else if (tolower(player) == 'o')
        {
            gameState[SpaceIndex] = 'o';
            gameStateN[SpaceIndex] = 4;
        }
        else
        {
            gameState[SpaceIndex] = player;
            gameStateN[SpaceIndex] = 0;
            emptySpaces.push_back(SpaceIndex);
        }
    }

    report gameReport()
    {
        report returnVal;
        int P[16] = {0, 1, 3, 1, 6, 1};

        for (int i = 0; i < 3; i++) // we will edit that i to 8 later
        {
            int temp = 0;
            for (int x = 0; x < 3; x++)
            {
                int point = (P[(i * 2) + 1] * x) + (P[i * 2]);
            }
            // here we will make an if statement
        }

        return returnVal;
    }
};

#endif