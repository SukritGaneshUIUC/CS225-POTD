#include "TreeNode.h"

#include <cstddef>
#include <iostream>
#include <cmath>
using namespace std;

int findHeight(TreeNode * current) {
  if (current == NULL) {
    return 0;
  }
  return 1 + max(findHeight(current->left_), findHeight(current->right_));
}

TreeNode::TreeNode() : left_(NULL), right_(NULL) { }

int TreeNode::getHeight() {
  return findHeight(this) - 1;
}
