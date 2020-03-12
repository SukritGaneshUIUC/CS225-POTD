#include "TreeNode.h"

#include <cmath>

int findHeight(TreeNode * root) {
  if (root == NULL) {
    return 0;
  }
  return 1 + fmax(findHeight(root->left_), findHeight(root->right_));
}

bool isHeightBalanced(TreeNode* root) {
  // your code here
  if (root == NULL) {
    return true;
  } else if (std::abs(findHeight(root->right_) - findHeight(root->left_)) <= 1) {
    return isHeightBalanced(root->right_) && isHeightBalanced(root->left_);
  } else {
    return false;
  }
}

TreeNode* findLastUnbalanced(TreeNode* root) {
  // your code here
  std::vector<std::pair<TreeNode*, int>> unbalancedNodes;
  findUnbalanced(root, unbalancedNodes, 0);
  if (unbalancedNodes.size() == 0) {
    return NULL;
  }
  // find node with greatest depth
  int maxDepth = 0;
  TreeNode * deepestNode = root;
  for (std::pair<TreeNode*, int> p: unbalancedNodes) {
    if (p.second > maxDepth) {
      maxDepth = p.second;
      deepestNode = p.first;
    }
  }
  return deepestNode;
}

void findUnbalanced(TreeNode* current, std::vector<std::pair<TreeNode*, int>> & uNodes, int currentDepth) {
  if (current == NULL) {
    return;
  } else if (std::abs(findHeight(current->right_) - findHeight(current->left_)) > 1) {
    uNodes.push_back(std::make_pair(current, currentDepth));
  }
  findUnbalanced(current->left_, uNodes, currentDepth + 1);
  findUnbalanced(current->right_, uNodes, currentDepth + 1);
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
