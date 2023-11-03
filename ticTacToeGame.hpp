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

    S string gameState;
    S array<int, 9> gameStateN;

    void gameStateToNumbers()
    {
        for (int i = 0; i < 9; i++)
        {
            switch (gameState[i])
            {
            case 'x':
                gameStateN[i] = 1;
                break;
            case 'o':
                gameStateN[i] = 4;
                break;
            default:
                gameStateN[i] = 0;
                break;
            }
        }
    }

public:
    ticTacToeGame(){};
    ticTacToeGame(S string gameState)
    {
        setGameState(gameState);
    }

    S string getGameState()
    {
        return this->gameState;
    }

    void setGameState(S string gameState)
    {
        this->gameState = gameState;
        S string &x = this->gameState;
        S transform(x.begin(), x.end(), x.begin(), ::tolower);
        gameStateToNumbers();
    }

    void play(int SpaceIndex, char player = '@')
    {
        if (player == '@')
        {
            player = emptySpaces().size() % 2 == 0 ? 'o' : 'x';
        }
        if (tolower(player) == 'x')
        {
            gameState[SpaceIndex] = 'x';
            gameStateN[SpaceIndex] = 1;
        }
        else if (tolower(player) == 'o')
        {
            gameState[SpaceIndex] = 'o';
            gameStateN[SpaceIndex] = 4;
        }
    }

    S vector<int> emptySpaces()
    {
        S vector<int> emptySpaces;
        for (int i = 0; i < 9; i++)
        {
            if (gameStateN[i] == 0)
            {
                emptySpaces.push_back(i);
            }
        }
        return emptySpaces;
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