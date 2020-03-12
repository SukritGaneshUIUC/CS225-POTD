#include "TreeNode.h"
#include <iostream>

TreeNode * deleteNode(TreeNode* root, int key) {
  // your code here
  TreeNode * head = root;

  TreeNode * current = head;
  TreeNode * prev = current;

  while (current != NULL) {
    if (key == current->val_) {
      // step 1: find inorder successor
      TreeNode * inorderSuccessor = current->right_;
      if (inorderSuccessor == NULL) {  // special case: only left chain (no right inorder)
        prev->left_ = current->left_;
        delete current;
      } else if (inorderSuccessor->left_ == NULL) {  // special case: only right chain (no right-left inorder)
        prev->left_ = inorderSuccessor;
        inorderSuccessor->left_ = current->left_;
        delete current;
        delete inorderSuccessor;
      }
      while (inorderSuccessor->right_ != NULL) {
        inorderSuccessor = inorderSuccessor->right_;
      }

      // step 2: do the removal
      current->val_ = inorderSuccessor->val_;
      delete inorderSuccessor;
    } else if (key < current->val_) {
      prev = current;
      current = current->left_;
    } else if (key > current->val_) {
      prev = current;
      current = current->right_;
    }
  }

  return head;
}

void inorderPrint(TreeNode* node)
{
    if (!node)  return;
    inorderPrint(node->left_);
    std::cout << node->val_ << " ";
    inorderPrint(node->right_);
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
