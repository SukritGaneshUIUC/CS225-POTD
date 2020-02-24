#include "potd.h"
#include <iostream>

void insertSorted(Node **head, Node *insert) {
  Node * current = *head;
  // your code here!
  int count = 0;
  while (current != nullptr) {
    if (current->data_ >= insert->data_) {
      break;
    }
    count++;
    current = current->next_;
  }

  if (count == 0) {
    insert->next_ = *head;
    *head = insert;
    return;
  }

  current = *head;
  for (int i = 0; i < count - 1; i++) {
    current = current->next_;
  }

  insert->next_ = current->next_;
  current->next_ = insert;
}
