#include "Node.h"
#include <iostream>

/** Create a new node and add it to the list, while keeping the list sorted.
*/
Node *insertSorted(Node *first, int data) {
    if (first == NULL) {
      Node * h = new Node;
      h->data_ = data;
      h->next_ = NULL;
      // std::cout << "added: " << data << std::endl;
      return h;
    }

    if (data < first->data_) {
      Node * h = new Node;
      h->data_ = data;
      h->next_ = first;
      // std::cout << "added: " << data << std::endl;
      return h;
    }

    Node * current = first;
    Node * previous = NULL;
    while (current != NULL) {
      if (data == current->data_) {
        return first;
      }
      if (data < current->data_) {
        Node * h = new Node;
        h->data_ = data;
        h->next_ = current;
        previous->next_ = h;
        // std::cout << "added: " << data << std::endl;
        return first;
      }
      previous = current;
      current = current->next_;
    }

    Node * h = new Node;
    h->data_ = data;
    h->next_ = NULL;
    previous->next_ = h;
    // std::cout << "added: " << data << std::endl;
    return first;
}

/** Creates a new list (containing new nodes, allocated on the heap)
	that contains the set union of the values in both lists.
*/
Node *listUnion(Node *first, Node *second) {
    Node *out = NULL;

    while (first != NULL) {
        // your code here
        // hint: call insertSorted and update l1
        out = insertSorted(out, first->data_);
        first = first->next_;
    }

    while (second != NULL) {
        // your code here
        out = insertSorted(out, second->data_);
        second = second->next_;
    }

    return out;
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
