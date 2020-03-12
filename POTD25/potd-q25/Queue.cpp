#include "Queue.h"

Queue::Queue() {
  pointer = 0;
  theSize = 0;
}

// `int size()` - returns the number of elements in the stack (0 if empty)
int Queue::size() const {
  return theSize;
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Queue::isEmpty() const {
  return theSize == 0;
}

// `void enqueue(int val)` - enqueue an item to the queue in O(1) time
void Queue::enqueue(int value) {
  theVector.push_back(value);
  theSize++;
}

// `int dequeue()` - removes an item off the queue and returns the value in O(1) time
int Queue::dequeue() {
  int r = theVector.at(pointer);
  pointer++;
  theSize--;
  return r;
}
