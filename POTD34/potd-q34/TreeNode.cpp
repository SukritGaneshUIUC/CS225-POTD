#include "TreeNode.h"

TreeNode::RotationType balanceTree(TreeNode*& subroot) {
	// Your code here
  int bal = getHeight(subroot->right_) - getHeight(subroot->left_);
  if (bal < 1) {
    TreeNode * lt = subroot->left_;
    if (leftHeavy(lt)) {
      return TreeNode::right;
    }
    return TreeNode::leftRight;
  } else if (bal > 1) {
    TreeNode * rt = subroot->right_;
    if (rightHeavy(rt)) {
      return TreeNode::left;
    }
    return TreeNode::rightLeft;
  }
  return TreeNode::right;
}
