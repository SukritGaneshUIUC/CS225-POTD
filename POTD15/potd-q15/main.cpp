#include "potd.h"
#include <iostream>
using namespace std;

int main() {
  // Test 1: An empty list
  Node * head = NULL;
  cout << stringList(head) << endl;

  // Test 2: A list with exactly one node
  Node * n1;
  n1->data_ = 100;
  n1->next_ = nullptr;

  cout << stringList(n1) << endl;


  // Test 3: A list with more than one node
  Node * n2;
  Node * n3;
  Node * n4;
  n2->data_ = 40;
  n3->data_ = 100;
  n4->data_ = 200;
  n2->next_ = n3;
  n3->next_ = n4;
  n4->next_ = nullptr;

  cout << stringList(n2) << endl;

  return 0;
}
