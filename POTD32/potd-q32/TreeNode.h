#pragma once

#include <cstddef>
#include <utility>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val_;
    int balance_;
    TreeNode *left_;
    TreeNode *right_;
    TreeNode(int x) {
      left_ = NULL;
      right_ = NULL;
      val_ = x;
      balance_ = 0;
    }
};

int findHeight(TreeNode * root);

bool isHeightBalanced(TreeNode* root);

TreeNode* findLastUnbalanced(TreeNode* root);

// uNodes contains list of unbalanced nodes and their depths
void findUnbalanced(TreeNode* current, std::vector<std::pair<TreeNode*, int>> & uNodes, int currentDepth);

void deleteTree(TreeNode* root);
