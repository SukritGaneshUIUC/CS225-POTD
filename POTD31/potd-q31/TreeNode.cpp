#include "TreeNode.h"

#include <cmath>

int calculateHeight(TreeNode * current) {
  if (current == NULL) {
    return 0;
  }
  return 1 + fmax(calculateHeight(current->right_), calculateHeight(current->left_));
}

bool isHeightBalanced(TreeNode* root) {
  // your code here
  if (root == NULL) {
    return true;
  } else if (std::abs(calculateHeight(root->right_) - calculateHeight(root->left_)) <= 1) {
    return isHeightBalanced(root->right_) && isHeightBalanced(root->left_);
  } else {
    return false;
  }
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
