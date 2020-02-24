#include "Node.h"
#include <iostream>

void sortList(Node **head) {
  // your code here!

  /*
  Selection sort:
  Repeatedly moving the minimum node
  to the beginning
  */

  if ((*head)->getNumNodes() == 0 || (*head)->getNumNodes() == 1) {
    return;
  }


  // Some variables you probably will need
  Node *minNode = NULL;
  Node *minPrev = NULL;

  if (*head == NULL)
      return;

  int minData = (*head)->data_;
  Node *tmp = *head;
  Node *prev = NULL;

  int count = 0;
  while ( tmp != NULL ) {
      // TODO: Find the minimum node
      if (count == 1) {
        prev = *head;
      }
      if (tmp->data_ < minData) {
        minNode = tmp;
        minPrev = prev;
        minData = tmp->data_;
      }
      if (prev != NULL) {
        prev = prev->next_;
      }
      tmp = tmp->next_;

      count++;
  }

  if (minPrev != NULL && minNode != NULL) {
      // TODO: Move the minimum node to the beginning
      // and update head
      minPrev->next_ = minNode->next_;
      minNode->next_ = *head;
      *head = minNode;
  }

  // Recurse on the rest of the list
  sortList(& (*head)->next_);
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
