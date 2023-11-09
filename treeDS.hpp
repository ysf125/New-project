#ifndef treeDS_hpp
#define treeDS_hpp
#include <iostream>
#include <memory>
#include <vector>
#define S std::

template <typename T>

class TreeNode {
  int depth = 0;

public:
  T data;
  S vector<S shared_ptr<TreeNode>> children;

  TreeNode() {}
  TreeNode(T data) : data(data) {}

  void addChild(T data) {
    S shared_ptr t = S make_shared<TreeNode>(data);
    t->depth = this->depth + 1;
    this->children.push_back(t);
  }

  int getDepth() { return this->depth; }

  S shared_ptr<TreeNode> getTo(S vector<int> steps) {
    S vector<S shared_ptr<TreeNode>> *temp = &this->children;
    for (int i = 0; i < steps.size() - 1; i++) {
      temp = &((*temp)[steps[i]]->children);
    }
    return (*temp)[steps[steps.size() - 1]];
  }
};

#endif