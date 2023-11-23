#include "ticTacToeGame.hpp"
#include "tools.hpp"
#include "treeDS.hpp"
#include <iostream>

#define S std::

int main() {
  // testing for the tree DS
  TreeNode<int> g(11);
  g.addChild(102);              // 0
  g.children[0]->addChild(113); // 0 -> 0
  g.children[0]->addChild(124); // 0 -> 1

  g.addChild(205);              // 1
  g.children[1]->addChild(216); // 1 -> 0
  g.children[1]->addChild(227); // 1 -> 1

  // testing for ticTacToeGame class
  // 0 1 2 / x
  // 3 4 5 / o
  // 6 7 8 / x x x
  

  return 0;
}
