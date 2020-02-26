#include "Node.h"
#include <unordered_set>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

Node *listIntersection(Node *first, Node *second) {
  // your code here
  // std::unordered_set<int> intersectionSet;
  if (first == NULL || second == NULL) {
    return NULL;
  }

  std::vector<int> gotVals;
  std::vector<int> alreadyInt;
  Node * head = new Node;
  head->next_ = NULL;
  Node * current = head;
  Node * prev = NULL;

  // first list
  Node * currentFirst = first;
  while (currentFirst != NULL) {
    // std::unordered_set<int>::iterator getVal = intersectionSet.find(currentFirst->data_);
    // std::cout << "at: " << currentFirst->data_ << std::endl;
    if (std::find(gotVals.begin(), gotVals.end(), currentFirst->data_) != gotVals.end() && std::find(alreadyInt.begin(), alreadyInt.end(), currentFirst->data_) == alreadyInt.end()) {
      // std::cout << "to add: " << currentFirst->data_ << std::endl;
      current->data_ = currentFirst->data_;
      current->next_ = new Node;
      prev = current;
      current = current->next_;
      gotVals.push_back(currentFirst->data_);
      alreadyInt.push_back(currentFirst->data_);
    } else {
      gotVals.push_back(currentFirst->data_);
      // intersectionSet.insert(currentFirst->data_);
    }
    currentFirst = currentFirst->next_;
  }

  // second list
  Node * currentSecond = second;
  while (currentSecond != NULL) {
    // std::unordered_set<int>::iterator getVal = intersectionSet.find(currentSecond->data_);
    // std::cout << "at: " << currentSecond->data_ << std::endl;
    if (std::find(gotVals.begin(), gotVals.end(), currentSecond->data_) != gotVals.end() && std::find(alreadyInt.begin(), alreadyInt.end(), currentSecond->data_) == alreadyInt.end()) {
      // std::cout << "to add: " << currentSecond->data_ << std::endl;
      current->data_ = currentSecond->data_;
      current->next_ = new Node;
      prev = current;
      current = current->next_;
      alreadyInt.push_back(currentSecond->data_);
      gotVals.push_back(currentSecond->data_);
    } else {
      gotVals.push_back(currentSecond->data_);
      // intersectionSet.insert(currentSecond->data_);
    }
    currentSecond = currentSecond->next_;
  }

  // no intersection - just a head
  if (head->next_ == NULL) {
    delete head;
    return NULL;
  }

  delete prev->next_;
  prev->next_ = NULL;

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
