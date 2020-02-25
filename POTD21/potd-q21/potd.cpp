#include "potd.h"

#include <iostream>

// Your code here!
double sum(vector<double>::iterator start, vector<double>::iterator end) {
  double s = 0;
  for (auto it = start; it != end; it++) {
    s += *it;
  }
  return s;
}

/** Returns an iterator that points to the element with the largest value between start and end. */
vector<double>::iterator max_iter(vector<double>::iterator start, vector<double>::iterator end) {
  double max = *start;
  vector<double>::iterator maxIter = start;
  for (auto it = start; it != end; it++) {
    if (max < *it) {
      max = *it;
      maxIter = it;
    }
  }
  return maxIter;
}

/** Sort, in descending order, part of an array between start to end.
	Hint: use max_iter.
*/
void sort_vector(vector<double>::iterator start, vector<double>::iterator end) {
  for (auto it = start; it != end; it++) {
    vector<double>::iterator curMax = max_iter(it, end);
    double temp = *curMax;
    *curMax = *it;
    *it = temp;
  }
}
