#include "Node.h"
#include <unordered_set>
#include <iostream>

using namespace std;

Node *listSymmetricDifference(Node *first, Node *second) {
  // your code here
  if (first == NULL && second == NULL) {
    return NULL;
  }

  // create the sets
  std::unordered_set<int> list1Set;
  std::unordered_set<int> list2Set;
  std::unordered_set<int> unionSet;
  Node * firstCurrent = first;
  Node * secondCurrent = second;
  std::cout << "got here" << std::endl;
  while (firstCurrent != NULL) {
    list1Set.insert(firstCurrent->data_);
    unionSet.insert(firstCurrent->data_);
    firstCurrent = firstCurrent->next_;
  }
  std::cout << list1Set.size() << std::endl;
  while (secondCurrent != NULL) {
    list2Set.insert(secondCurrent->data_);
    unionSet.insert(secondCurrent->data_);
    secondCurrent = secondCurrent->next_;
  }
  std::cout << list2Set.size() << std::endl;

  std::cout << unionSet.size() << std::endl;


  Node * head = NULL;
  Node * current = head;
  for (auto it = unionSet.begin(); it != unionSet.end(); it++) {
    if (!(list1Set.find(*it) != list1Set.end() && list2Set.find(*it) != list2Set.end())) {
      if (current == NULL) {
        current = new Node;
        current->data_ = *it;
        current->next_ = NULL;
        head = current;
      } else {
        current->next_ = new Node;
        current = current->next_;
        current->data_ = *it;
        current->next_ = NULL;
      }
    }
  }

  return head;
}

Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
