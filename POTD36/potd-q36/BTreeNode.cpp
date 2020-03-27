#include <vector>
#include "BTreeNode.h"


std::vector<int> traverse(BTreeNode* root) {
    // your code here
    std::vector<int> v;
    traverse(root, v);
    return v;
}

void traverse(BTreeNode * current, std::vector<int> & traversalVector) {
	if (current == NULL) {
		// do nothing
	}

	// if leaf node, just push everything
	if (current->children_.empty()) {
		for (int i: current->elements_) {
			traversalVector.push_back(i);
		}
		return;
	}

	// must alternate between children and trees
	// there is 1 more child than keys
	int keyIndex = 0;
	traverse(current->children_.at(0), traversalVector);
	while (keyIndex < current->elements_.size()) {
		traversalVector.push_back(current->elements_.at(keyIndex));

		traverse(current->children_.at(keyIndex+1), traversalVector);
		keyIndex++;
	}
	
}
