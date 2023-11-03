#include <iostream>
#include "treeDS.hpp"
#include "ticTacToeGame.hpp"
#define S std::

int main()
{   
    TreeNode<int> g(11);
    g.addChild(102);                 // 0 
    g.children[0]->addChild(113);    // 0 -> 0
    g.children[0]->addChild(124);    // 0 -> 1
    
    g.addChild(205);                 // 1
    g.children[1]->addChild(216);    // 1 -> 0
    g.children[1]->addChild(227);    // 1 -> 1

    // 0 1 2
    // 3 4 5
    // 6 7 8
    
    // 0 -> 1 3 4
    // 2 -> 2 3 
    // 3 -> 1 
    // 4 -> 3 

    ticTacToeGame hh("xXx0OO--o");

    
    return 0;
}
