#include "Node.h"

void mergeList(Node *first, Node *second) {
  // your code here!
  if (first == nullptr || second == nullptr) {
    return;
  }

  bool list1 = true;
  Node * currentfirst = first;
  Node * currentsecond = second;
  while (currentfirst != nullptr && currentsecond != nullptr) {
    if (list1) {
      Node * temp = currentfirst->next_;
      currentfirst->next_ = currentsecond;
      currentfirst = temp;
    } else if (!list1) {
      Node * temp = currentsecond->next_;
      currentsecond->next_ = currentfirst;
      currentsecond = temp;
    }
    list1 = !list1;
  }
}

Node::Node() {
    numNodes++;
}

Node::Node(const Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
