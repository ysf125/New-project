#include "ticTacToeGame.hpp"
#include "treeDS.hpp"
#include <chrono>
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
  // 0 1 2 / o   x
  // 3 4 5 /   
  // 6 7 8 / x   o 

  ticTacToeGame hh({'x', '-', '-', 'o', '-', '-', 'x', 'x', 'x'});
  
  // report x = hh.gameReport();
  // S cout << x.win << "\n";

  // S cout << "o :" << "\n";
  // for (int z : x.ocanWin) {
  //   S cout << z << " ";
  // }

  // S cout << "\n" << "x :" << "\n";

  // for (int z : x.xcanWin) {
  //   S cout << z << " ";
  // }
  // measuring execution time   
  // auto start = std::chrono::system_clock::now();
  // auto end = S chrono::system_clock::now();
  // S cout << "\n" << S chrono::duration_cast<S chrono::microseconds>(end - start).count() ;
  // S cout << "\n" << S chrono::duration_cast<S chrono::milliseconds>(end - start).count() ;

  return 0;
}
