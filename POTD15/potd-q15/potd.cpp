#include "potd.h"
#include <iostream>

using namespace std;

string stringList(Node *head) {
  if (head == nullptr) {
    return "Empty list";
  }

  string s = "";

  Node * current = head;
  int count = 0;

  while (current != nullptr) {
    if (count > 0) {
      s += " -> ";
    }
    s += "Node ";
    s += to_string(count);
    s += ": ";
    s += to_string(current->data_);
    current = current->next_;
    count++;
  }

  return s;
}
